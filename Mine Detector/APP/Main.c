/*
 * Main.c
 *
 *  Created on: Nov 25, 2022
 *      Author: hp
 */
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"

#include "../MCAL/DIO/DIO_int.h"
#include "../MCAL/EXI/EXI_int.h"
#include "../MCAL/GIE/GIE_int.h"
#include "../MCAL/UART/UART_int.h"

#include "../HAL/ULTRASONIC/ULTRASONIC_int.h"

#include "../HAL/DC_MOTOR/DC_MOTOR_int.h"
#include "../HAL/SIM808/SIM808_int.h"

#include "Q_learning.h"


#include <util/delay.h>
#include <math.h>


void Send_vLocation(void);

int main(void)
{

	EXI_vInitInt1();
	Reg_func1(Send_vLocation);
	DC_MOTOR_vInt();
	Ultrasonic_vInit();
	SIM808_vInit();
	GIE_vEnableGlobalInterrupt();
	train2();			// train the robot
	test2();			// infinite loop anyway




	while (1)
	{


	}
}



void Send_vLocation(void)
{
	SIM808_vSendLocation();
}











