/*
 * TIMER_Program.c
 *
 *  Created on: Sep 16, 2022
 *      Author: Omar Ahmed
 */

#include "..\..\LIB\Std_Types.h"
#include "..\..\LIB\Bit_Math.h"

#include "TIMER_Registers.h"
#include "TIMER_Interface.h"


void TIMER_voidInit(void)
{
	/*Select CTC Mode*/
	Set_Bit(TCCR0,TCCR0_WGM01);
	Clear_Bit(TCCR0,TCCR0_WGM00);

	/*Select Prescaler CLK/8*/
	TCCR0 &= (0b11111000);
	TCCR0 |= (0b00000010);

	/*set Max Value for timer*/
	OCR0 = 200;
}

void Timer_voidDelayms (u32 Copy_Delayu32ms)
{
	u32 Local_u32Counter; /*Local variable to counts number of Captures*/

	/*Select CTC Mode*/
	Set_Bit(TCCR0,TCCR0_WGM01);
	Clear_Bit(TCCR0,TCCR0_WGM00);

	/*set Max Value for timer*/
	OCR0 = 200;

	/*Clear flag*/
	Set_Bit(TIFR,TIFR_OCF0);

	/*Select Prescaler CLK/8*/
	TCCR0 &= (0b11111000);
	TCCR0 |= (0b00000010);

	for (Local_u32Counter=1;Local_u32Counter<=5*Copy_Delayu32ms;Local_u32Counter++)
	{
		while (Get_Bit(TIFR,TIFR_OCF0)!=1); /*Polling for the flag*/
		Set_Bit(TIFR,TIFR_OCF0);            /*Clear flag*/
	}
}



