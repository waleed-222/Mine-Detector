/*
 * Q_learning.c
 *
 *  Created on: Nov 26, 2022
 *      Author: hp
 */


#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"




#include "../MCAL/DIO/DIO_int.h"

#include "../HAL/DC_MOTOR/DC_MOTOR_int.h"
#include "../HAL/ULTRASONIC/ULTRASONIC_int.h"


#include "Q_learning.h"

#include <stdbool.h>
#include <stdlib.h>
#include <util/delay.h>

#include <util/delay.h>
//episodes :number of times our car learn
//decay: updating q learning states in each episodes
//epsilon:selects the action with the highest estimated reward most of the time to have a balance between exploration and exploitation.
u32 episodes = 200, currentState = 0, nextState = 0, actionID = 0;
f32 reward;
f32 epsilon = 1.0;
f32 new_Q, Old_Q, max_Q;


f32 Q2[STATES2][ACTIONS] = {
		{0.0, 0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0, 0.0},
		{0.0, 0.0, 0.0, 0.0}
};
f32 rewards2[STATES2][ACTIONS]={
		{10.0, 2.0, 2.0, -10},
		{-2.0, 10.0,-10.0, -10.0},
		{-10.0, 10.0, 10.0, -2.0},
		{-10.0, 10.0, -10.0, -2.0},
		{2.0, -10.0, 10.0, -10.0},
		{10.0, -10.0, -10.0, -2.0},
		{-10.0, -10.0, 10.0, -2.0},
		{-10.0, -10.0, -10.0, 10.0}
};



f32 Q_random(){
	return (f32)(((rand()%100))/100.0);
}

f32 decay(f32 value){
	return (value*0.99);
}

f32 Q_max(f32 n1,f32 n2){
	if(n1 >= n2)
		return n1;
	return n2;
}

struct max_val getMax(u32 next_s){
	struct max_val x={-10000,-1};
	for (u32 i = 0; i < ACTIONS; ++i) {
		x._max = Q_max(x._max, Q2[next_s][i]);
		if(x._max == Q2[next_s][i])
			x._max_ind=i;
	}
	return x;
}

u32 getState() // read the three ultrasonics
{

	u32 R = ReadUS(RIGHT);
	_delay_ms(1);
	u32 L = ReadUS(LEFT);
	_delay_ms(1);
	u32 M = ReadUS(CENTER);

	if ((L>15) && (M>20) && (R>15)) //000
		return 0;
	else if ((L>15) && (M>20) && (R<=15))
		return 1;
	else if ((L>15) && (M<=20) && (R>15))
		return 2;
	else if ((L>15) && (M<=20) && (R<=15))
		return 3;
	else if ((L<=15) && (M>20) && (R>15))
		return 4;
	else if ((L<=15) && (M>20) && (R<=15))
		return 5;
	else if ((L<=15) && (M<=20) && (R>15))
		return 6;
	else if ((L<=15) && (M<=20) && (R<=15)) //111
		return 7;
	else
		return -1;
}

void update2(u32 state, u32 next_s, u32 action, u32 state_reward){
	Old_Q = Q2[state][action];
	max_Q = getMax(next_s)._max;
	new_Q = ((1.0f - ALPHA)*Old_Q + ALPHA*(state_reward + GAMMA*max_Q));
	Q2[state][action] = new_Q;
}

void train2(){
	u32 ultra,r;

	for (u32 i = 0; i < episodes; i++) {
		ultra = 1000;
		while(1)
		{
			forward();// make the robot move forward for each episode
			ultra = ReadUS(CENTER);//get read of center ultrasonic
			if( ultra <= 20)
			{
				stop();
				nextState = (currentState + 1) % STATES2 ;
				right();
				break;
			}
			r=ReadUS(RIGHT);
			if(r<=20)
			{
				Rotate();
			}
		}

		f32 prob = Q_random();
		if(prob <= epsilon){
			actionID = rand() % ACTIONS;
		}
		else
			actionID = getMax(currentState)._max_ind;
		reward = rewards2[currentState][actionID];
		update2(currentState, nextState, actionID, reward);
		currentState = nextState;
		epsilon = decay(epsilon);
		_delay_ms(100);
	}

}

void train3(){ //interacting with the actual environment given to the robot



	for (u32 i = 0; i < episodes; i++) {
		forward();// make the robot move forward for each episode
		do{
			currentState = getState(); // read the current state
		} while (currentState == 0); //move till an obstacle is detected

		f32 prob = Q_random(); //getting a probability for the explore/exploit action

		if(prob <= epsilon) //explore
			actionID = rand() % ACTIONS;
		else //exploit
			actionID = getMax(currentState)._max_ind;

		switch (actionID) //take the action
		{
		case 0 : forward(); break;
		case 1 : left(); break;
		case 2 : right(); break;
		case 3 : Rotate(); break;
		}

		nextState = getState(); // reading the new state
		_delay_ms(200); //delay to make sure the action is taken successfully
		stop();//stop the robot
		reward = rewards2[currentState][actionID]; //getting the reward
		update2(currentState, nextState, actionID, reward); //updating q table
		epsilon = decay(epsilon); // decay the epsilon (more toward exploiting)
		_delay_ms(500);
	}

}


void test2()
{
	while(1)
	{
		//while(getState() == 0) Forward(); can be used with train 3

		actionID = getMax(getState())._max_ind;

		if(actionID == 0){ //forward
			forward();
		}
		else if(actionID == 1){ // left
			left();
		}
		else if(actionID == 2){ // right
			right();
		}
		else if(actionID == 3) // rotate
		{
			Rotate();
		}
		else
		{
			//not a case
			stop();
			_delay_ms(3000);
		}
	}
}
