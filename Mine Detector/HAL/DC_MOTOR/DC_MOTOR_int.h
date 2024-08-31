/*
 * DC_MOTOR_int.h
 *
 *  Created on: Dec 8, 2022
 *      Author: hp
 */

#ifndef DC_MOTOR_DC_MOTOR_INT_H_
#define DC_MOTOR_DC_MOTOR_INT_H_

void DC_MOTOR_vInt();
void forward();
void Rotate();
void left();
void right();
void DC_MOTOR_Control(u8 A_u8Motor_Port,u8 A_u8Motor_Pin, u8 A_u8Value);
void stop();

#endif /* DC_MOTOR_DC_MOTOR_INT_H_ */
