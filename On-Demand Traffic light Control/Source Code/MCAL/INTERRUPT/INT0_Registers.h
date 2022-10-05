/*
 * INT0_Registers.h
 *
 *  Created on: Sep 16, 2022
 *      Author: Omar Ahmed
 */

#ifndef INT0_REGISTERS_H_
#define INT0_REGISTERS_H_

#define MCUCR     *((volatile u8*)0x55)
#define MCUCR_ISC00      0
#define MCUCR_ISC01      1

#define GICR       *((volatile u8*)0x5B)
#define GICR_INT0        6

/*Status Register*/
#define SREG        *((volatile u8*)0x5F)
#define SREG_I           7

#endif /* INT0_REGISTERS_H_ */
