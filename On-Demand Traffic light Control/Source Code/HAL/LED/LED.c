/*
 * LED.c
 *
 *  Created on: Oct 5, 2022
 *      Author: user
 */

#include "..\..\LIB\Std_Types.h"
#include "..\..\LIB\Bit_Math.h"

#include "..\..\MCAL\DIO\DIO_Interface.h"
#include "..\..\MCAL\DIO\DIO_CONFIG.h"

#include "LED.h"

void LED_voidON_OFF (u8 Copy_u8PORT,u8 Copy_u8PIN,u8 ON_OFF)
{
	switch (Copy_u8PORT)
	{
	case DIO_PORTA:
		DIO_voidSetvaluePin(DIO_PORTA,Copy_u8PIN,ON_OFF);
		break;
	case DIO_PORTB:
		DIO_voidSetvaluePin(DIO_PORTB,Copy_u8PIN,ON_OFF);
		break;
	case DIO_PORTC:
		DIO_voidSetvaluePin(DIO_PORTC,Copy_u8PIN,ON_OFF);
		break;
	case DIO_PORTD:
		DIO_voidSetvaluePin(DIO_PORTD,Copy_u8PIN,ON_OFF);
		break;

	default:
		break;
	}
}

