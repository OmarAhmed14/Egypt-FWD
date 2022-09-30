/*
 * DIO_Interface.h
 *
 *  Created on: Sep 16, 2022
 *      Author: Omar Ahmed
 */

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

void DIO_voidSetDirectionPin(u8 Copy_u8PORT , u8 Copy_u8Pin , u8 Copy_u8Direction);

void DIO_voidSetvaluePin(u8 Copy_u8PORT , u8 Copy_u8Pin, u8 Copy_u8Value);

void DIO_voidPullUPPin(u8 Copy_u8PORT , u8 Copy_u8Pin);

u8 DIO_voidReadvaluePin(u8 Copy_u8PORT , u8 Copy_u8Pin);



#endif /* DIO_INTERFACE_H_ */
