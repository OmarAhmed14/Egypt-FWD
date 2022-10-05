/*
 * TIMER_Registers.h
 *
 *  Created on: Sep 16, 2022
 *      Author: Omar Ahmed
 */

#ifndef TIMER_REGISTERS_H_
#define TIMER_REGISTERS_H_

#define TCCR0       *((volatile u8*)0x53)
#define TCCR0_WGM01     3
#define TCCR0_WGM00     6

#define TCNT0        *((volatile u8*)0x52)

#define OCR0         *((volatile u8*)0x5C)

#define TIMSK        *((volatile u8*)0x59)
#define TIMSK_OCIE0      1

#define TIFR         *((volatile u8*)0x58)
#define TIFR_OCF0        1

#define NULL             0

#endif /* TIMER_REGISTERS_H_ */
