#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_Interface.h"

#include "IntCtrl_Cfg.h"
#include "IntCtrl_Interface.h"

#include "GPTM_Interface.h"
#include "GPTM_CFG.h"

void LED_Blinking (void);

u8 flag;

int main ()
{	
	flag=0;
	IntCtrl_Init();
	GPTM_CallBackFn(&LED_Blinking);
	DIO_DirectionChannel(DIO_PORTF,PIN1,OUTPUT_PIN);
	GPTM_Init();
	
	while (1)
	{
		/*No thing here to save Power*/
	}
}

/*******************ISR To Toggle LED every 1 sec*********************/

void LED_Blinking (void)
{
	if (!flag)
	{
		DIO_WriteChannel(DIO_PORTF,PIN1,HIGH);
		flag=1;
	}
	else
	{
		DIO_WriteChannel(DIO_PORTF,PIN1,LOW);
		flag=0;
	}
}
