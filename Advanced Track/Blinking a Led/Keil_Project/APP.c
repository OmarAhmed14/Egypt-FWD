#include "Std_Types.h"
#include "Bit_Math.h"

#include "GPTM_Interface.h"
#include "GPTM_CFG.h"

#include "IntCtrl_Cfg.h"
#include "IntCtrl_Interface.h"

#include "DIO_Interface.h"

#include "APP.h"

extern u8 on,off;

void APP_Init(void)
{
	/*Handler Function*/
	CallBackFn(&APP_ISR);
	
	/*Buttons >> INPUT*/
	DIO_DirectionChannel(DIO_PORTF,PIN0,INPUT_PIN);
	DIO_DirectionChannel(DIO_PORTF,PIN4,INPUT_PIN);
	
	/*PULLuP for Buttons*/
	DIO_PULLUP_PIN(DIO_PORTF,PIN0);
	DIO_PULLUP_PIN(DIO_PORTF,PIN4);
	
	/*LED >> OUTPUT*/
	DIO_DirectionChannel(DIO_PORTF,PIN1,OUTPUT_PIN);
	
	/*Enable interrupt for GPIOF*/
	IntCtrl_Init();
	
	/*Enable interrupt for PIN0 abd PIN4*/
	DIO_ENInterrupt(DIO_PORTF,PIN0,EDGE_EVENT,FALLING_EDGE_LOW_LEVEL);
	DIO_ENInterrupt(DIO_PORTF,PIN4,EDGE_EVENT,FALLING_EDGE_LOW_LEVEL);
}

void APP_Start(u8 OFF_TIME , u8 ON_TIME)
{
	DIO_WriteChannel(DIO_PORTF, PIN1, HIGH);
	GPTM_delay_sec(ON_TIME);
	DIO_WriteChannel(DIO_PORTF, PIN1, LOW);
	GPTM_delay_sec(OFF_TIME);
}

void APP_ISR(void)
{
	on=0,off=0;
	
	/*Delay 1 sec*/
	GPTM_delay_sec(1);
	
	/*set on time*/	
	while (DIO_READChannel(DIO_PORTF,PIN4))
	{
		if (!DIO_READChannel(DIO_PORTF,PIN0))
		{
			on++;
			GPTM_delay_sec(1);           // Delay 1 sec
			GPTM_delay_millisec(500);   //Delay 500 ms
		}
	}
	
	/*Delay 0.5 sec*/
	GPTM_delay_millisec(500);
	
	/*Set off time*/
	while (DIO_READChannel(DIO_PORTF,PIN4))
	{
		if (!DIO_READChannel(DIO_PORTF,PIN0))
		{
			off++;
			GPTM_delay_sec(1);          // Delay 1 sec
			GPTM_delay_millisec(200);   //Delay 200 ms
		}
	}
}