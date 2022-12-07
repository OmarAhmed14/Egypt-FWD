#include "Std_Types.h"
#include "Bit_Math.h"

#include "GPTM_Interface.h"
#include "GPTM_Registers.h"
#include "GPTM_CFG.h"

#include "DIO_Interface.h"

void GPTM_Init(void)
{
	/*Disable for timer*/
	Clear_Bit(GPTMCTL,GPTMCTL_TAEN);

	/*32 or 64 bit timer*/
	GPTMCFG=(GPTMCFG&0xFFFFFFF8)| _32_64_Bit_Timer;

	/*Perpdic Mode*/
	GPTMTAMR=(GPTMTAMR&0xFFFFFFFC)| Periodic_Mode;

	/*Direction of counts >>> Up*/
	GPTMTAMR=(GPTMTAMR&0xFFFFFFEF)| DOWN;

	/*Enable interrupt*/
	Set_Bit(GPTMIMR,GPTMIMR_TATOIM);

	/*Load Value*/
	GPTMTAILR=0x2FAF080;

	/*Stalling for debugging*/
	//Set_Bit(GPTMCTL,GPTMCTL_TASTALL);

	/*Enable Timer*/
	Set_Bit(GPTMCTL,GPTMCTL_TAEN);
}

void GPTM_delay_sec (u8 delay_Sec)
{
	 u8 Counts=0;
	
	/*Disable for timer*/
	Clear_Bit(GPTMCTL,GPTMCTL_TAEN);

	/*32 or 64 bit timer*/
	GPTMCFG=(GPTMCFG&0xFFFFFFF8)| _32_64_Bit_Timer;

	/*Perpdic Mode*/
	GPTMTAMR=(GPTMTAMR&0xFFFFFFFC)| Periodic_Mode;

	/*Direction of counts >>> Up*/
	GPTMTAMR=(GPTMTAMR&0xFFFFFFEF)| DOWN;

	/*Load Value*/    /*for 1 sec*/
	GPTMTAILR=0x2FAF080;

	/*Stalling for debugging*/
	Set_Bit(GPTMCTL,GPTMCTL_TASTALL);

	/*Enable Timer*/
	Set_Bit(GPTMCTL,GPTMCTL_TAEN);
	
	while(Counts!=delay_Sec)
	{
		while (!Get_Bit(GPTMRIS,GPTMRIS_TATORIS));
		Set_Bit(GPTMICR,GPTMICR_TATOCINT);
		Counts++;
	}
}

void GPTM_delay_millisec (u8 delay_ms)
{
	u8 Counts=0;
	
	/*Disable for timer*/
	Clear_Bit(GPTMCTL,GPTMCTL_TAEN);

	/*32 or 64 bit timer*/
	GPTMCFG=(GPTMCFG&0xFFFFFFF8)| _32_64_Bit_Timer;

	/*Perpdic Mode*/
	GPTMTAMR=(GPTMTAMR&0xFFFFFFFC)| Periodic_Mode;

	/*Direction of counts >>> Up*/
	GPTMTAMR=(GPTMTAMR&0xFFFFFFEF)| DOWN;

	/*Load Value*/    /*for 1 ms*/
	GPTMTAILR=0xC350;

	/*Stalling for debugging*/
	Set_Bit(GPTMCTL,GPTMCTL_TASTALL);

	/*Enable Timer*/
	Set_Bit(GPTMCTL,GPTMCTL_TAEN);
	
	while(Counts!=delay_ms)
	{
		while (!Get_Bit(GPTMRIS,GPTMRIS_TATORIS));
		Set_Bit(GPTMICR,GPTMICR_TATOCINT);
		Counts++;
	}
}

void TIMER0A_Handler(void)
{
	DIO_DirectionChannel(DIO_PORTF,PIN1,OUTPUT_PIN);
	DIO_WriteChannel(DIO_PORTF,PIN1,HIGH);
}