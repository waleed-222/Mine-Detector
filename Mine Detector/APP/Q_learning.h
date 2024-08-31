/*
 * Q_learn.h
 *
 *  Created on: Nov 26, 2022
 *      Author: hp
 */

#ifndef Q_LEARNING_H_
#define Q_LEARNING_H_

#include <stdlib.h>


				// ----- QLearning Definitions ----- //
#define ACTIONS 4 // forward, left, right, rotate
#define STATES2 8 // the readings of the three ultrasonics 000 (no obstacles) to 111 (obstacles in each ultrasonic)
#define ALPHA 0.1f // the learning rate
#define GAMMA 0.5f // discount factor




				// ----- QLearning Functions ----- //
f32 Q_random();
f32 decay(f32 value);

struct max_val{
	f32 _max;
	f32 _max_ind;
};

f32 Q_max(f32 n1,f32 n2);
u32 getState();
void update2(u32 state, u32 next_s, u32 action, u32 state_reward);
void train3();
void test2();
void train2();



#endif /* Q_LEARNING_H_ */
