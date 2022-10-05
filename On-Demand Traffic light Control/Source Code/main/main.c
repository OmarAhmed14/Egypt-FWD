/*
 * main.c
 *
 *  Created on: Sep 16, 2022
 *      Author: Omar Ahmed
 */

//#include "..\App\App.h"

#include "..\LIB\Std_Types.h"
#include "..\LIB\Bit_Math.h"

#include "..\MCAL\DIO\DIO_CONFIG.h"
#include "..\MCAL\DIO\DIO_Interface.h"

#include "..\MCAL\TIMER\TIMER_Interface.h"

int main (void)
{
	TIMER_voidInit(); // initialization for timer

	DIO_voidSetDirectionPin(DIO_PORTD,PIN0,OUTPUT);   // OUTPUT Direction

	while (1)
	{
		//AppStart();
			DIO_voidSetvaluePin(DIO_PORTD,PIN0,HIGH);   // LED ON PORTD PIN0
			Timer_voidDelayms(5000);                    // delay 5 sec
			DIO_voidSetvaluePin(DIO_PORTD,PIN0,LOW);    // LED OFF PORTD PIN0
			Timer_voidDelayms(10000);                   // delay 10 sec
			DIO_voidSetvaluePin(DIO_PORTD,PIN0,HIGH);   // LED ON PORTD PIN0
			Timer_voidDelayms(15000);                   // delay 15 sec
			DIO_voidSetvaluePin(DIO_PORTD,PIN0,LOW);    // LED OFF PORTD PIN0
			Timer_voidDelayms(20000);                   // delay 20 sec
	}
	return 0;
}
