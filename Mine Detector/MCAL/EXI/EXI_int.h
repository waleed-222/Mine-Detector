/*
 * EXTINT_int.h
 *
 *  Created on: Aug 29, 2022
 *      Author: hp
 */

#ifndef MCAL_EXI_EXI_INT_H_
#define MCAL_EXI_EXI_INT_H_

#define DISALE_EXT 0
#define ENABLE_EXI 1

void EXI_vInitInt0();
void EXI_vInitInt1();
void EXI_vInitInt2();
void Reg_func0(void(*Isr_ptr)(void));
void Reg_func1(void(*Isr_ptr)(void));
void Reg_func2(void(*Isr_ptr)(void));

#endif /* MCAL_EXI_EXI_INT_H_ */
