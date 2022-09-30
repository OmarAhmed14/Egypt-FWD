/*
 * App.c
 *
 *  Created on: Sep 16, 2022
 *      Author: Omar Ahmed
 */

#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_CONFIG.h"
#include "DIO_Interface.h"

#include "INT0_Interface.h"

#include "TIMER_Interface.h"

#include "App.h"

u8 Flag,STATE;

void AppInit(void)
{
	/*Interrupt initialization*/
	INT_voidGlobalInterrupt();
	INT0_voidInit();
	INT0_voidEnable();
	INT0_voidCallBack(&ISR_Pedestrian);

	/*Traffic Light LEDS*/
	DIO_voidSetDirectionPin(DIO_PORTA,PIN1,OUTPUT);
	DIO_voidSetDirectionPin(DIO_PORTA,PIN0,OUTPUT);
	DIO_voidSetDirectionPin(DIO_PORTA,PIN2,OUTPUT);
	DIO_voidSetDirectionPin(DIO_PORTC,PIN0,OUTPUT);
	DIO_voidSetDirectionPin(DIO_PORTC,PIN1,OUTPUT);
	DIO_voidSetDirectionPin(DIO_PORTC,PIN2,OUTPUT);

	/*pedestrian Button*/
	DIO_voidSetDirectionPin(DIO_PORTD,PIN2,INPUT);
	DIO_voidPullUPPin(DIO_PORTD,PIN2);

	/*pedestrian Red LED*/
	DIO_voidSetvaluePin(DIO_PORTC,PIN0,HIGH);

}

void AppStart(void)
{
	STATE=0;
	/* Car Red LED */
	Flag = STATE_ONE;
	DIO_voidSetvaluePin(DIO_PORTA,PIN0,HIGH);
	Timer_voidDelayms(5000);
	DIO_voidSetvaluePin(DIO_PORTA,PIN0,LOW);


	/*Car Yellow LED */
	for (u8 Counter=0;Counter<10;Counter++)
	{
		Flag = STATE_THREE;
		Toggle_Bit(STATE,0);
		DIO_voidSetvaluePin(DIO_PORTA,PIN1,STATE);
		Timer_voidDelayms(500);
	}
	DIO_voidSetvaluePin(DIO_PORTA,PIN1,LOW);
	STATE=0;

	/*Car Green LED*/
	Flag = STATE_TWO;
	DIO_voidSetvaluePin(DIO_PORTA,PIN2,HIGH);
	Timer_voidDelayms(5000);
	DIO_voidSetvaluePin(DIO_PORTA,PIN2,LOW);

	/*Car Yellow LED */
	for (u8 Counter=0;Counter<10;Counter++)
	{
		Flag = STATE_THREE;
		Toggle_Bit(STATE,0);
		DIO_voidSetvaluePin(DIO_PORTA,PIN1,STATE);
		Timer_voidDelayms(500);
	}
	DIO_voidSetvaluePin(DIO_PORTA,PIN1,LOW);
}

void ISR_Pedestrian (void)
{
	Timer_voidDelayms(250);
	if (DIO_voidReadvaluePin(DIO_PORTD,PIN2)){
	INT0_voidDisable();
	switch (Flag)
	{
	case STATE_ONE:
		DIO_voidSetvaluePin(DIO_PORTC,PIN0,LOW);
		DIO_voidSetvaluePin(DIO_PORTC,PIN2,HIGH);
		Timer_voidDelayms(5000);
		break;

		default:
			DIO_voidSetvaluePin(DIO_PORTC,PIN0,HIGH); // PED RED ON
			DIO_voidSetvaluePin(DIO_PORTA,PIN2,LOW);  // CAR GREEN OFF
			STATE=0;
			/*Car and pedestrian Yellow LED */
			for (u8 Counter=0;Counter<10;Counter++)
			{
				Toggle_Bit(STATE,0);
				DIO_voidSetvaluePin(DIO_PORTA,PIN1,STATE);
				DIO_voidSetvaluePin(DIO_PORTC,PIN1,STATE);
				Timer_voidDelayms(500);
			}
			DIO_voidSetvaluePin(DIO_PORTC,PIN0,LOW);
			DIO_voidSetvaluePin(DIO_PORTA,PIN0,HIGH);
			DIO_voidSetvaluePin(DIO_PORTC,PIN2,HIGH);
			Timer_voidDelayms(5000);
			DIO_voidSetvaluePin(DIO_PORTA,PIN0,LOW);
			break;
		}
	DIO_voidSetvaluePin(DIO_PORTA,PIN0,LOW);
	STATE=0;
	/*Car and pedestrian Yellow LED */
	for (u8 Counter=0;Counter<10;Counter++)
	{
		Toggle_Bit(STATE,0);
		DIO_voidSetvaluePin(DIO_PORTA,PIN1,STATE);
		DIO_voidSetvaluePin(DIO_PORTC,PIN1,STATE);
		Timer_voidDelayms(500);
	}
	DIO_voidSetvaluePin(DIO_PORTC,PIN2,LOW);
	DIO_voidSetvaluePin(DIO_PORTA,PIN2,HIGH);
	DIO_voidSetvaluePin(DIO_PORTC,PIN0,HIGH);
	Timer_voidDelayms(5000);
	DIO_voidSetvaluePin(DIO_PORTA,PIN2,LOW);
	INT0_voidEnable();}
	else
	{}
}
