/*
 * SERVO_int.h
 *
 *  Created on: Nov 26, 2022
 *      Author: hp
 */

#ifndef HAL_SERVO_SERVO_INT_H_
#define HAL_SERVO_SERVO_INT_H_

#define LEFT 120
#define RIGHT 0
#define CENTER 60

void SERVO_vInit(void);
void SERVO_vRotate180_Back(void);
void SERVO0_vAngle(u8 A_u8Angle);
void SERVO1_vAngle(u8 A_u8Angle);

#endif /* HAL_SERVO_SERVO_INT_H_ */
