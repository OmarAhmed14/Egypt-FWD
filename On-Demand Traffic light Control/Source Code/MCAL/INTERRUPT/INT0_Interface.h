/*
 * INT0_Interface.h
 *
 *  Created on: Sep 16, 2022
 *      Author: Omar Ahmed
 */

#ifndef INT0_INTERFACE_H_
#define INT0_INTERFACE_H_

#define NULL   0

void INT_voidGlobalInterrupt();

void INT0_voidInit();

void INT0_voidEnable();

void INT0_voidDisable();

void INT0_voidCallBack(void (*Local_voidINT0)(void));

#endif /* INT0_INTERFACE_H_ */
