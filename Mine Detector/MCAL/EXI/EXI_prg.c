/*
 * EXI_prg.c
 *
 *  Created on: Aug 30, 2022
 *      Author: hp
 */
#include "../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"

#include"../DIO/DIO_int.h"
#include "EXI_reg.h"
#include "EXI_pri.h"
#include "EXI_cfg.h"
#include "EXI_int.h"


static void (*G_ISR_ptr0)(void);
static void (*G_ISR_ptr1)(void);
static void (*G_ISR_ptr2)(void);

void __vector_1 (void)
{
	G_ISR_ptr0();


}
void __vector_2 (void)
{
	G_ISR_ptr1();

}
void __vector_3 (void)
{
	G_ISR_ptr2();

}

void EXI_vInitInt0()
{
	DIO_vPinDir(INT0_PORT,INT0_PIN,DIR_INPUT);
	DIO_vSetPinVal(INT0_PORT,INT0_PIN,VAL_HIGH);
	SET_BIT(GICR,INT0); //enable INT0

#if (INT0_MODE==INT0_FALLING_EDGE)
	CLR_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
#elif (INT0_MODE==INT0_RISING_EDGE)
	SET_BIT(MCUCR,ISC00);
	SET_BIT(MCUCR,ISC01);
#elif (INT1_MODE==INT0_ANY_CHANGE)
	SET_BIT(MCUCR,ISC00);
	CLR_BIT(MCUCR,ISC01);
#endif


}
void EXI_vInitInt1()
{
	DIO_vPinDir(INT1_PORT,INT1_PIN,DIR_INPUT);
	DIO_vSetPinVal(INT1_PORT,INT1_PIN,VAL_HIGH);
	SET_BIT(GICR,INT1); //enable INT1
#if (INT1_MODE==INT1_FALLING_EDGE)
	CLR_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
#elif (INT1_MODE==INT1_RISING_EDGE)
	SET_BIT(MCUCR,ISC10);
	SET_BIT(MCUCR,ISC11);
#elif (INT1_MODE==INT1_ANY_CHANGE)
	SET_BIT(MCUCR,ISC10);
	CLR_BIT(MCUCR,ISC11);
#endif


}
void EXI_vInitInt2()
{
	DIO_vPinDir(INT2_PORT,INT2_PIN,DIR_INPUT);
	DIO_vSetPinVal(INT2_PORT,INT2_PIN,VAL_HIGH);
	SET_BIT(GICR,INT2); //enable INT2

#if (INT2_MODE==INT2_FALLING_EDGE)
	CLR_BIT(MCUCSR,ISC2);

#elif
	SET_BIT(MCUCSR,ISC2);

#endif


}

void Reg_func0(void(*Isr_ptr)(void))
{
	G_ISR_ptr0=Isr_ptr;
}

void Reg_func1(void(*Isr_ptr)(void))
{
	G_ISR_ptr1=Isr_ptr;
}

void Reg_func2(void(*Isr_ptr)(void))
{
	G_ISR_ptr2=Isr_ptr;
}
