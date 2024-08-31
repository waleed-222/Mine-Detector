/*
 * ULTRASONIC_int.h
 *
 *  Created on: Nov 25, 2022
 *      Author: hp
 */

#ifndef ULTRASONIC_ULTRASONIC_INT_H_
#define ULTRASONIC_ULTRASONIC_INT_H_
				// ----- Ultrasonic Drivers ----- //
void Ultrasonic_vInit();
u64 ReadUS(u8 x);


				// ----- Ultrasonic Definitions ----- //
#define  _ULTRASONIC_LEFT_TRIGGER 0
#define  _ULTRASONIC_MIDDLE_TRIGGER 1
#define  _ULTRASONIC_RIGHT_TRIGGER 2
#define Left_Ultrasonic 0
#define Middle_Ultrasonic 1
#define Right_Ultrasonic 2
#define CENTER 1
#define RIGHT 2
#define LEFT 0


#endif /* ULTRASONIC_ULTRASONIC_INT_H_ */
