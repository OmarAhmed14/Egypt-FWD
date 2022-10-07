/*
 * BUTTON.C
 *
 *  Created on: Oct 5, 2022
 *      Author: user
 */

#include "..\..\LIB\Std_Types.h"
#include "..\..\LIB\Bit_Math.h"

#include "..\..\MCAL\DIO\DIO_Interface.h"
#include "..\..\MCAL\DIO\DIO_CONFIG.h"

#include "BUTTON.h"

u8 BUTTON_voidPressed_NOT (u8 Copy_u8PORT,u8 Copy_u8PIN)
{
	u8 Returned;
	switch (Copy_u8PORT)
		{
		case DIO_PORTA:
			Returned=DIO_voidReadvaluePin(DIO_PORTA,Copy_u8PIN);
			break;
		case DIO_PORTB:
			Returned=DIO_voidReadvaluePin(DIO_PORTB,Copy_u8PIN);
			break;
		case DIO_PORTC:
			Returned=DIO_voidReadvaluePin(DIO_PORTC,Copy_u8PIN);
			break;
		case DIO_PORTD:
			Returned=DIO_voidReadvaluePin(DIO_PORTD,Copy_u8PIN);
			break;

		default:
			break;
		}
	return Returned;
}
