/*
 * EXTINT_pri.h
 *
 *  Created on: Aug 29, 2022
 *      Author: hp
 */

#ifndef MCAL_EXI_EXI_PRI_H_
#define MCAL_EXI_EXI_PRI_H_

#define INT0_LOW_LEVEL 0
#define INT0_ANY_CHANGE 1
#define INT0_FALLING_EDGE 2
#define INT0_RISING_EDGE  3

#define INT1_LOW_LEVEL 0
#define INT1_ANY_CHANGE 1
#define INT1_FALLING_EDGE 2
#define INT1_RISING_EDGE  3

#define INT2_FALLING_EDGE 0
#define INT2_RISING_EDGE  1

/*Compiler attributes*/

/*number 1 for external interrupt 0 in vector table*/
void __vector_1 (void) __attribute__((signal));

/*number 2 for external interrupt 1 in vector table*/
void __vector_2 (void) __attribute__((signal));

/*number 3 for external interrupt 2 in vector table*/
void __vector_3 (void) __attribute__((signal));
#endif /* MCAL_EXI_EXI_PRI_H_ */
