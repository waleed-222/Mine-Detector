/*
 * EXTINT_reg.h
 *
 *  Created on: Aug 29, 2022
 *      Author: hp
 */

#ifndef MCAL_EXI_EXI_REG_H_
#define MCAL_EXI_EXI_REG_H_

#define MCUCR *((u8*)0x55)
#define MCUCSR *(( u8*)0x54)
#define GICR *((u8*)0x5B)
#define GIFR *((volatile u8*)0x5A)

/*MCUCR*/
#define ISC00   0
#define ISC01   1
#define ISC10   2
#define ISC11   3

/*From 4 to 7 not used in this driver*/

/*MCUCSR*/
#define ISC2    6

/*From 0 to 5 and 7 not used in this driver */

/*GICR*/
#define INT2    5
#define INT0    6
#define INT1    7

/*From 0 to 4 not used in this driver*/


/*GIFR*/
#define INTF2   5
#define INTF0   6
#define INTF1   7

/*From 0 to 4 not used in this driver*/


#endif /* MCAL_EXI_EXI_REG_H_ */
