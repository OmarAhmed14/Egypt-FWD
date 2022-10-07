/*
 * INT0_Program.c
 *
 *  Created on: Sep 16, 2022
 *      Author: Omar Ahmed
 */

#include "..\..\LIB\Std_Types.h"
#include "..\..\LIB\Bit_Math.h"

#include "INT0_Registers.h"
#include "INT0_Interface.h"


void (*INT0_CallBack)(void)=NULL;

void INT_voidGlobalInterrupt()
{
	/*Set in bit 7 in status register one to enable global interrupt*/
	Set_Bit(SREG,SREG_I);
}

void INT0_voidInit()
{
	/*interrupt on Falling Edge (Interrupt Request)*/
	Clear_Bit(MCUCR,MCUCR_ISC00);
	Set_Bit(MCUCR,MCUCR_ISC01);

}

void INT0_voidEnable()
{
	/*INT0 Enable*/
	Set_Bit(GICR,GICR_INT0);
}

void INT0_voidDisable()
{
	/*INT0 Disable*/
	Clear_Bit(GICR,GICR_INT0);
}

void INT0_voidCallBack(void (*Local_voidINT0)(void))
{
	INT0_CallBack= Local_voidINT0;
}

void __vector_1(void)__attribute__((signal));
void __vector_1(void)
{
	INT0_CallBack();
}
