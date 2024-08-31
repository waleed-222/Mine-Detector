#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "../../MCAL/DIO/DIO_reg.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/TIMER2/TIMER2_int.h"
#include "../../MCAL/EXI/EXI_int.h"
#include "../../MCAL/GIE/GIE_int.h"
#include "../../MCAL/UART/UART_int.h"
#include "ULTRASONIC_cfg.h"
#include "ULTRASONIC_int.h"
#include <stdlib.h>
#include <string.h>

#define  F_CPU 8000000UL
#include <util/delay.h>

// ----- Ultrasonic Initialization Configuration ----- //
void Ultrasonic_vInit()
{
	// Pins Direction
	DIO_vPinDir(ULTRASONIC_TRIGER_PORT_C,ULTRASONIC_TRIGER_PIN_C,DIR_OUTPUT);
	DIO_vPinDir(ULTRASONIC_TRIGER_PORT_L,ULTRASONIC_TRIGER_PIN_L,DIR_OUTPUT);
	DIO_vPinDir(ULTRASONIC_TRIGER_PORT_R,ULTRASONIC_TRIGER_PIN_R,DIR_OUTPUT);

}


// ----- Ultrasonic Distance Measurement ----- //
u64 ReadUS(u8 x)
{
	u64 count = 0;					// Time Counts Variable
	u64 distance = 0;				// Distance Between Ultrasonic & Obstacle
	//choose which Us who will receive  the trigger
	if(x == 0){

		DIO_vSetPinVal(ULTRASONIC_TRIGER_PORT_L,ULTRASONIC_TRIGER_PIN_L,VAL_HIGH);
		_delay_us(10);

		DIO_vSetPinVal(ULTRASONIC_TRIGER_PORT_L,ULTRASONIC_TRIGER_PIN_L,VAL_LOW);

		//wait till the one of ECHO arrived
		while(DIO_u8GetPinVal(ULTRASONIC_ECHO_PORT_L,ULTRASONIC_ECHO_PIN_L)==0);

		//calculate the ECHO time
		while(DIO_u8GetPinVal(ULTRASONIC_ECHO_PORT_L,ULTRASONIC_ECHO_PIN_L)==1)
		{
			// Converting The Counts To Microseconds Variable
			_delay_us(1);
			count++;

		}

	}
	else if(x == 1){

		DIO_vSetPinVal(ULTRASONIC_TRIGER_PORT_C,ULTRASONIC_TRIGER_PIN_C,VAL_HIGH);
		_delay_us(10);
		DIO_vSetPinVal(ULTRASONIC_TRIGER_PORT_C,ULTRASONIC_TRIGER_PIN_C,VAL_LOW);

		//wait till the one of ECHO arrived
		while(DIO_u8GetPinVal(ULTRASONIC_ECHO_PORT_C,ULTRASONIC_ECHO_PIN_C)==0);

		//calculate the ECHO time
		while(DIO_u8GetPinVal(ULTRASONIC_ECHO_PORT_C,ULTRASONIC_ECHO_PIN_C)==1)
		{
			// Converting The Counts To Microseconds Variable
			_delay_us(1);
			count++;
		}

	}
	else if (x ==2){

		DIO_vSetPinVal(ULTRASONIC_TRIGER_PORT_R,ULTRASONIC_TRIGER_PIN_R,VAL_HIGH);
		_delay_us(10);
		DIO_vSetPinVal(ULTRASONIC_TRIGER_PORT_R,ULTRASONIC_TRIGER_PIN_R,VAL_LOW);

		//wait till the one of ECHO arrived
		while(DIO_u8GetPinVal(ULTRASONIC_ECHO_PORT_R,ULTRASONIC_ECHO_PIN_R)==0);

		//calculate the ECHO time
		while(DIO_u8GetPinVal(ULTRASONIC_ECHO_PORT_R,ULTRASONIC_ECHO_PIN_R)==1)
		{
			// Converting The Counts To Microseconds Variable
			_delay_us(1);
			count++;
		}
	}

	distance=count/9; // Distance Equation.
	return distance;
}
