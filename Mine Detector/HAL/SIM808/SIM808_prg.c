/*
 * SIM808_prg.c
 *
 *  Created on: Dec 3, 2022
 *      Author: hp
 */


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/TIMER0/millis.h"

#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/GIE/GIE_int.h"

#include "../../MCAL/UART/UART_int.h"
#include "../../MCAL/EXI/EXI_int.h"

#include <stdbool.h>
#include <util/delay.h>
#include <stdio.h>

#include "SIM808_pri.h"
#include "SIM808_int.h"

#include "stdlib.h"


#define DEBUG true

u8 response[50] = "";
u8 data[50];

u8 state,timegps;
f32 latitude,longitude;
u8 G_u8Latitude[10],G_u8Longitude[10];

void SIM808_vInit()
{
	UART_vInit();
	UART_vSend_String((u8*)"AT\r");
	_delay_ms(1000);
	UART_vSend_String((u8*)"AT+CGNSPWR=1\r");/*To turn on GNSS power in Simcom modules*/
	_delay_ms(1000);


}

void SIM808_vSendLocation()
{
	/*return state, time, latitude and longitude*/
	UART_vSend_String((u8*)"AT+CGNSINF\r");
	Get_loaction();

	UART_vSend_String((u8*)"AT+CMGF=1\r");
	_delay_ms(1000);
	UART_vSend_String((u8*)"AT+CMGS=\"01127153963\"\r"); /*send sms command at message mode*/
	UART_vSend_String((u8*)"http://maps.google.com/maps?q=loc:");
	sprintf(G_u8Latitude,"%f",latitude);
	UART_vSend_String(G_u8Latitude);
	UART_vSend_String((u8*)",");
	sprintf(G_u8Longitude,"%f",longitude);
	UART_vSend_String (G_u8Longitude);
	_delay_ms(200);
	UART_vSendData(26); // End AT command with a ^Z, ASCII code 26
	_delay_ms(20000);



}



void Get_loaction(void )
{

	int i = 0,j=0,s=0;
	u8 received[255];
	UART_vSend_String((u8*)"AT+CGNSINF");
	UART_vGet_String(received);

	while (received[j]!='\0')
	{
		if (received[j] == ',')
		{
			i++;
			while(i>2&&i<5)
			{
				data[s]=received[j];
				j++;
				s++;
				if(i==3)
				{
					if(received[j]==',')
					{	s=0;
					i++;
					data[s]=0;
					}
					else if(received[j]=='.')
					{
						/*do nothing*/
					}
					else
						longitude=longitude*10+data[s];
				}
				else if(received[j]==','&&i==4)
				{
					if(received[j]==',')
					{	s=0;
					i++;
					data[s]=0;
					}
					else if(received[j]=='.')
					{
						/*do nothing*/
					}
					else
						latitude= latitude*10+data[s];
				}
			}


		}
		else if(i>4)
			break;
		else
		{

			j++;
		}

	}





}
