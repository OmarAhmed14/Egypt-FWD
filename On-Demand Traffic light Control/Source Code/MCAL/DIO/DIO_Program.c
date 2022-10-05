/*
 * DIO_Program.c
 *
 *  Created on: Sep 16, 2022
 *      Author: Omar Ahmed
 */

#include "..\..\LIB\Std_Types.h"
#include "..\..\LIB\Bit_Math.h"

#include "DIO_Registers.h"
#include "DIO_CONFIG.h"
#include "DIO_Interface.h"

void DIO_voidSetDirectionPin(u8 Copy_u8PORT , u8 Copy_u8Pin , u8 Copy_u8Direction)
{
	if (Copy_u8Direction == OUTPUT)
	{
		switch (Copy_u8PORT)
		{
		case DIO_PORTA:
			Set_Bit(DDRA,Copy_u8Pin);
			break;

		case DIO_PORTB:
			Set_Bit(DDRB,Copy_u8Pin);
			break;

		case DIO_PORTC:
			Set_Bit(DDRC,Copy_u8Pin);
			break;

		case DIO_PORTD:
			Set_Bit(DDRD,Copy_u8Pin);
			break;

		default:
			break;
		}
	}
		else if (Copy_u8Direction == INPUT)
		{
			switch (Copy_u8PORT)
			{
			case DIO_PORTA:
				Clear_Bit(DDRA,Copy_u8Pin);
				break;

			case DIO_PORTB:
				Clear_Bit(DDRB,Copy_u8Pin);
				break;

			case DIO_PORTC:
				Clear_Bit(DDRC,Copy_u8Pin);
				break;

			case DIO_PORTD:
				Clear_Bit(DDRD,Copy_u8Pin);
				break;

			default:
				break;
			 }
		}
}

void DIO_voidSetvaluePin(u8 Copy_u8PORT , u8 Copy_u8Pin, u8 Copy_u8Value)
{
	if (Copy_u8Value == HIGH)
		{
			switch (Copy_u8PORT)
			{
			case DIO_PORTA:
				Set_Bit(PORTA,Copy_u8Pin);
				break;

			case DIO_PORTB:
				Set_Bit(PORTB,Copy_u8Pin);
				break;

			case DIO_PORTC:
				Set_Bit(PORTC,Copy_u8Pin);
				break;

			case DIO_PORTD:
				Set_Bit(PORTD,Copy_u8Pin);
				break;

			default:
				break;
			}
		}
			else if (Copy_u8Value == LOW)
			{
				switch (Copy_u8PORT)
				{
				case DIO_PORTA:
					Clear_Bit(PORTA,Copy_u8Pin);
					break;

				case DIO_PORTB:
					Clear_Bit(PORTB,Copy_u8Pin);
					break;

				case DIO_PORTC:
					Clear_Bit(PORTC,Copy_u8Pin);
					break;

				case DIO_PORTD:
					Clear_Bit(PORTD,Copy_u8Pin);
					break;

				default:
					break;
				 }
			}
}

void DIO_voidPullUPPin(u8 Copy_u8PORT , u8 Copy_u8Pin)
{
	switch (Copy_u8PORT)
	{
	case DIO_PORTA:
		Clear_Bit(DDRA,Copy_u8Pin);
		Set_Bit(PINA,Copy_u8Pin);
		break;

	case DIO_PORTB:
		Clear_Bit(DDRB,Copy_u8Pin);
		Set_Bit(PINB,Copy_u8Pin);
		break;

	case DIO_PORTC:
		Clear_Bit(DDRC,Copy_u8Pin);
		Set_Bit(PINC,Copy_u8Pin);
		break;

	case DIO_PORTD:
		Clear_Bit(DDRD,Copy_u8Pin);
		Set_Bit(PIND,Copy_u8Pin);
		break;

	default:
		break;
	}
}

u8 DIO_voidReadvaluePin(u8 Copy_u8PORT , u8 Copy_u8Pin)
{
	u8 Local_u8Value;
	switch (Copy_u8PORT)
	{
	case DIO_PORTA:
		Local_u8Value= Get_Bit(PINA,Copy_u8Pin);
		break;

		case DIO_PORTB:
			Local_u8Value= Get_Bit(PINB,Copy_u8Pin);
			break;

		case DIO_PORTC:
			Local_u8Value= Get_Bit(PINC,Copy_u8Pin);
			break;

		case DIO_PORTD:
			Local_u8Value= Get_Bit(PIND,Copy_u8Pin);
			break;

		default:
			break;
	}
	return Local_u8Value;
}

