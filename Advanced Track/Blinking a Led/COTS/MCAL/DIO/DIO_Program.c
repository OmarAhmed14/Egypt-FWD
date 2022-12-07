#include "Std_Types.h"
#include "Bit_Math.h"
#include "DIO_Interface.h"
#include "DIO_Registers.h"

static volatile u32* reg =0;

u8 DIO_READChannel (u8 DIO_PORT, u8 DIO_PIN)
{
	switch (DIO_PORT)
	{
	case DIO_PORTA:
		Set_Bit_BitBandingAlias(&PORTA_DEN,DIO_PIN);
		reg=(&PORTA_DATA + ((1<<(DIO_PIN+2))/4)); 
		return Get_Bit(*reg,DIO_PIN);
		break;
	case DIO_PORTB:
		Set_Bit_BitBandingAlias(&PORTB_DEN,DIO_PIN);
		reg=(&PORTB_DATA + ((1<<(DIO_PIN+2))/4)); 
		return Get_Bit(*reg,DIO_PIN);
		break;
	case DIO_PORTC:
		Set_Bit_BitBandingAlias(&PORTC_DEN,DIO_PIN);
		reg=(&PORTC_DATA + ((1<<(DIO_PIN+2))/4)); 
		return Get_Bit(*reg,DIO_PIN);
		break;
	case DIO_PORTD:
		Set_Bit_BitBandingAlias(&PORTD_DEN,DIO_PIN);
		reg=(&PORTD_DATA + ((1<<(DIO_PIN+2))/4)); 
		return Get_Bit(*reg,DIO_PIN);
		break;
	case DIO_PORTE:
		Set_Bit_BitBandingAlias(&PORTE_DEN,DIO_PIN);
		reg=(&PORTE_DATA + ((1<<(DIO_PIN+2))/4)); 
		return Get_Bit(*reg,DIO_PIN);
		break;
	case DIO_PORTF:
		Set_Bit_BitBandingAlias(&PORTF_DEN,DIO_PIN);
		reg=(&PORTF_DATA + ((1<<(DIO_PIN+2))/4)); 
		return Get_Bit(*reg,DIO_PIN);
		break;
	default:
		break;
	}
}

void DIO_WriteChannel(u8 DIO_PORT, u8 DIO_PIN, u8 TypeLevel)
{
	switch (DIO_PORT)
	{
	case DIO_PORTA:
		Set_Bit_BitBandingAlias(&PORTA_DEN,DIO_PIN);
		reg=(&PORTA_DATA + ((1<<(DIO_PIN+2))/4)); 
		if (TypeLevel==HIGH)
			Set_Bit_BitBandingAlias(reg,DIO_PIN);
		else
			Clear_Bit_BitBandingAlias(reg,DIO_PIN);
		break;
	case DIO_PORTB:
		Set_Bit_BitBandingAlias(&PORTB_DEN,DIO_PIN);
		reg=(&PORTB_DATA + ((1<<(DIO_PIN+2))/4)); 
		if (TypeLevel==HIGH)
			Set_Bit_BitBandingAlias(reg,DIO_PIN);
		else
			Clear_Bit_BitBandingAlias(reg,DIO_PIN);
		break;
	case DIO_PORTC:
		Set_Bit_BitBandingAlias(&PORTC_DEN,DIO_PIN);
		reg=(&PORTC_DATA + ((1<<(DIO_PIN+2))/4)); 
		if (TypeLevel==HIGH)
			Set_Bit_BitBandingAlias(reg,DIO_PIN);
		else
			Clear_Bit_BitBandingAlias(reg,DIO_PIN);
		break;
	case DIO_PORTD:
		Set_Bit_BitBandingAlias(&PORTD_DEN,DIO_PIN);
		reg=(&PORTA_DATA + ((1<<(DIO_PIN+2))/4)); 
		if (TypeLevel==HIGH)
			Set_Bit_BitBandingAlias(reg,DIO_PIN);
		else
			Clear_Bit_BitBandingAlias(reg,DIO_PIN);
		break;
	case DIO_PORTE:
		Set_Bit_BitBandingAlias(&PORTE_DEN,DIO_PIN);
		reg=(&PORTE_DATA + ((1<<(DIO_PIN+2))/4)); 
		if (TypeLevel==HIGH)
			Set_Bit_BitBandingAlias(reg,DIO_PIN);
		else
			Clear_Bit_BitBandingAlias(reg,DIO_PIN);
		break;
	case DIO_PORTF:
		Set_Bit_BitBandingAlias(&PORTF_DEN,DIO_PIN);
		reg=(&PORTF_DATA + ((1<<(DIO_PIN+2))/4)); 
		if (TypeLevel==HIGH)
			Set_Bit_BitBandingAlias(reg,DIO_PIN);
		else
			Clear_Bit_BitBandingAlias(reg,DIO_PIN);
		break;
	default:
		break;
	}
}

u8 DIO_ReadPort(u8 DIO_PORT)
{
	switch (DIO_PORT)
	{
	case DIO_PORTA:
		reg= (&PORTA_DATA + (0x3FC)/4);
		return (*reg);
		break;
	case DIO_PORTB:
		reg= (&PORTB_DATA + (0x3FC)/4);
		return (*reg);
		break;
	case DIO_PORTC:
		reg= (&PORTC_DATA + (0x3FC)/4);
		return (*reg);
		break;
	case DIO_PORTD:
		reg= (&PORTD_DATA + (0x3FC)/4);
		return (*reg);
		break;
	case DIO_PORTE:
		reg= (&PORTE_DATA + (0x3FC)/4);
		return (*reg);
		break;
	case DIO_PORTF:
		reg= (&PORTF_DATA + (0x3FC)/4);
		return (*reg);
		break;
	default:
		break;
	}
}

void Dio_WritePort(u8 DIO_PORT, u8 DIO_PORTVALUE)
{
	switch (DIO_PORT)
	{
	case DIO_PORTA:
		reg= (&PORTA_DATA + (0x3FC)/4);
		PORTA_DEN= 0xFF;
		*reg= DIO_PORTVALUE;
		break;
	case DIO_PORTB:
		reg= (&PORTB_DATA + (0x3FC)/4);
		PORTB_DEN= 0xFF;
		*reg= DIO_PORTVALUE;
		break;
	case DIO_PORTC:
		reg= (&PORTC_DATA + (0x3FC)/4);
		PORTC_DEN= 0xFF;
		*reg= DIO_PORTVALUE;
		break;
	case DIO_PORTD:
		reg= (&PORTD_DATA + (0x3FC)/4);
		PORTD_DEN= 0xFF;
		*reg= DIO_PORTVALUE;
		break;
	case DIO_PORTE:
		reg= (&PORTE_DATA + (0x3FC)/4);
		PORTE_DEN= 0xFF;
		*reg= DIO_PORTVALUE;
		break;
	case DIO_PORTF:
		reg= (&PORTF_DATA + (0x3FC)/4);
		PORTF_DEN= 0xFF;
		*reg= DIO_PORTVALUE;
		break;
	default:
		break;
	}
}

void DIO_DirectionPort(u8 DIO_PORT, u8 DIO_PORTDirection)
{
	switch (DIO_PORT)
	{
	case DIO_PORTA:
		PORTA_DIR= DIO_PORTDirection;
		break;
	case DIO_PORTB:
		PORTB_DIR= DIO_PORTDirection;
		break;
	case DIO_PORTC:
		PORTC_DIR= DIO_PORTDirection;
		break;
	case DIO_PORTD:
		PORTD_DIR= DIO_PORTDirection;
		break;
	case DIO_PORTE:
		PORTE_DIR= DIO_PORTDirection;
		break;
	case DIO_PORTF:
		PORTF_DIR= DIO_PORTDirection;
		break;
	default:
		break;
	}
}

void DIO_DirectionChannel(u8 DIO_PORT, u8 DIO_PIN, u8 DIO_PINDirection)
{
	if (DIO_PINDirection == OUTPUT_PIN)
	{
		switch (DIO_PORT)
		{
		case DIO_PORTA:
			Set_Bit_BitBandingAlias(&PORTA_DIR,DIO_PIN);
			break;
		case DIO_PORTB:
			Set_Bit_BitBandingAlias(&PORTB_DIR,DIO_PIN);
			break;
		case DIO_PORTC:
			Set_Bit_BitBandingAlias(&PORTC_DIR,DIO_PIN);
			break;
		case DIO_PORTD:
			Set_Bit_BitBandingAlias(&PORTD_DIR,DIO_PIN);
			break;
		case DIO_PORTE:
			Set_Bit_BitBandingAlias(&PORTE_DIR,DIO_PIN);
			break;
		case DIO_PORTF:
			Set_Bit_BitBandingAlias(&PORTF_DIR,DIO_PIN);
			break;
		default:
			break;
		}
	}
		else
		{
			switch (DIO_PORT)
			{
			case DIO_PORTA:
				Clear_Bit_BitBandingAlias(&PORTA_DIR,DIO_PIN);
				break;
			case DIO_PORTB:
				Clear_Bit_BitBandingAlias(&PORTB_DIR,DIO_PIN);
				break;
			case DIO_PORTC:
				Clear_Bit_BitBandingAlias(&PORTC_DIR,DIO_PIN);
				break;
			case DIO_PORTD:
				Clear_Bit_BitBandingAlias(&PORTD_DIR,DIO_PIN);
				break;
			case DIO_PORTE:
				Clear_Bit_BitBandingAlias(&PORTE_DIR,DIO_PIN);
				break;
			case DIO_PORTF:
				Clear_Bit_BitBandingAlias(&PORTF_DIR,DIO_PIN);
				break;
			default:
				break;
			}
	}
}


void DIO_PULLUP_PIN (u8 DIO_PORT, u8 DIO_PIN)
{
	switch (DIO_PORT)
	{
	case DIO_PORTA:
		PORTA_LOCK =0x4C4F434B;
		Set_Bit_BitBandingAlias(&PORTA_CR,DIO_PIN);
		Set_Bit_BitBandingAlias(&PORTA_DEN,DIO_PIN);
		Set_Bit_BitBandingAlias(&PORTA_PUR,DIO_PIN);
		break;
	case DIO_PORTB:
		PORTB_LOCK =0x4C4F434B;
		Set_Bit_BitBandingAlias(&PORTB_CR,DIO_PIN);
		Set_Bit_BitBandingAlias(&PORTB_DEN,DIO_PIN);
		Set_Bit_BitBandingAlias(&PORTB_PUR,DIO_PIN);
		break;                           
	case DIO_PORTC:  
		PORTC_LOCK =0x4C4F434B;
		Set_Bit_BitBandingAlias(&PORTC_CR,DIO_PIN);	
		Set_Bit_BitBandingAlias(&PORTC_DEN,DIO_PIN);		
		Set_Bit_BitBandingAlias(&PORTC_PUR,DIO_PIN);
		break;                           
	case DIO_PORTD: 
		PORTD_LOCK =0x4C4F434B;
		Set_Bit_BitBandingAlias(&PORTD_CR,DIO_PIN);			
		Set_Bit_BitBandingAlias(&PORTD_DEN,DIO_PIN);
		Set_Bit_BitBandingAlias(&PORTD_PUR,DIO_PIN);
		break;                           
	case DIO_PORTE:  
		PORTE_LOCK =0x4C4F434B;
		Set_Bit_BitBandingAlias(&PORTE_CR,DIO_PIN);
		Set_Bit_BitBandingAlias(&PORTE_DEN,DIO_PIN);		
		Set_Bit_BitBandingAlias(&PORTE_PUR,DIO_PIN);
		break;                           
	case DIO_PORTF:  
		PORTF_LOCK =0x4C4F434B;			
		Set_Bit_BitBandingAlias(&PORTF_CR,DIO_PIN);
		Set_Bit_BitBandingAlias(&PORTF_DEN,DIO_PIN);
		Set_Bit_BitBandingAlias(&PORTF_PUR,DIO_PIN);
		break;
	default:
		break;
	}
}

void DIO_ENInterrupt(u8 DIO_PORT, u8 DIO_PIN, EVENT Event, EVENT_TYPE Event_Type)
{
		switch (DIO_PORT)
	{
	case DIO_PORTA:
		/*masking for pin*/
		Clear_Bit_BitBandingAlias(PORTA_GPIOIM,DIO_PIN);
		/*CONFIG Event TYPE*/
		if (Event==EDGE_EVENT)
			Clear_Bit_BitBandingAlias(PORTA_GPIOIS,DIO_PIN);
		else
			Set_Bit_BitBandingAlias(PORTA_GPIOIS,DIO_PIN);
		/*CONFIG Falling, rising edge or high, low level*/
		if (Event_Type==FALLING_EDGE_LOW_LEVEL)
			Clear_Bit_BitBandingAlias(PORTA_GPIOIEV,DIO_PIN);
		else
			Set_Bit_BitBandingAlias(PORTA_GPIOIEV,DIO_PIN);
		/*Clear Flag*/
		Set_Bit_BitBandingAlias(PORTA_GPIOICR,DIO_PIN);
		/*un masking interrupt*/
		Set_Bit_BitBandingAlias(PORTA_GPIOIM,DIO_PIN);
		break;
	case DIO_PORTB:
		/*masking for pin*/
		Clear_Bit_BitBandingAlias(PORTB_GPIOIM,DIO_PIN);
		/*CONFIG Event TYPE*/
		if (Event==EDGE_EVENT)
			Clear_Bit_BitBandingAlias(PORTB_GPIOIS,DIO_PIN);
		else
			Set_Bit_BitBandingAlias(PORTB_GPIOIS,DIO_PIN);
		/*CONFIG Falling, rising edge or high, low level*/
		if (Event_Type==FALLING_EDGE_LOW_LEVEL)
			Clear_Bit_BitBandingAlias(PORTB_GPIOIEV,DIO_PIN);
		else
			Set_Bit_BitBandingAlias(PORTB_GPIOIEV,DIO_PIN);
		/*Clear Flag*/
		Set_Bit_BitBandingAlias(PORTB_GPIOICR,DIO_PIN);
		/*un masking interrupt*/
		Set_Bit_BitBandingAlias(PORTB_GPIOIM,DIO_PIN);
		break;
	case DIO_PORTC:
		/*masking for pin*/
		Clear_Bit_BitBandingAlias(PORTC_GPIOIM,DIO_PIN);
		/*CONFIG Event TYPE*/
		if (Event==EDGE_EVENT)
			Clear_Bit_BitBandingAlias(PORTC_GPIOIS,DIO_PIN);
		else
			Set_Bit_BitBandingAlias(PORTC_GPIOIS,DIO_PIN);
		/*CONFIG Falling, rising edge or high, low level*/
		if (Event_Type==FALLING_EDGE_LOW_LEVEL)
			Clear_Bit_BitBandingAlias(PORTC_GPIOIEV,DIO_PIN);
		else
			Set_Bit_BitBandingAlias(PORTC_GPIOIEV,DIO_PIN);
		/*Clear Flag*/
		Set_Bit_BitBandingAlias(PORTC_GPIOICR,DIO_PIN);
		/*un masking interrupt*/
		Set_Bit_BitBandingAlias(PORTC_GPIOIM,DIO_PIN);
		break;
	case DIO_PORTD:
		/*masking for pin*/
		Clear_Bit_BitBandingAlias(PORTD_GPIOIM,DIO_PIN);
		/*CONFIG Event TYPE*/
		if (Event==EDGE_EVENT)
			Clear_Bit_BitBandingAlias(PORTD_GPIOIS,DIO_PIN);
		else
			Set_Bit_BitBandingAlias(PORTD_GPIOIS,DIO_PIN);
		/*CONFIG Falling, rising edge or high, low level*/
		if (Event_Type==FALLING_EDGE_LOW_LEVEL)
			Clear_Bit_BitBandingAlias(PORTD_GPIOIEV,DIO_PIN);
		else
			Set_Bit_BitBandingAlias(PORTD_GPIOIEV,DIO_PIN);
		/*Clear Flag*/
		Set_Bit_BitBandingAlias(PORTD_GPIOICR,DIO_PIN);
		/*un masking interrupt*/
		Set_Bit_BitBandingAlias(PORTD_GPIOIM,DIO_PIN);		
		break;
	case DIO_PORTE:
		/*masking for pin*/
		Clear_Bit_BitBandingAlias(PORTE_GPIOIM,DIO_PIN);
		/*CONFIG Event TYPE*/
		if (Event==EDGE_EVENT)
			Clear_Bit_BitBandingAlias(PORTE_GPIOIS,DIO_PIN);
		else
			Set_Bit_BitBandingAlias(PORTE_GPIOIS,DIO_PIN);
		/*CONFIG Falling, rising edge or high, low level*/
		if (Event_Type==FALLING_EDGE_LOW_LEVEL)
			Clear_Bit_BitBandingAlias(PORTE_GPIOIEV,DIO_PIN);
		else
			Set_Bit_BitBandingAlias(PORTE_GPIOIEV,DIO_PIN);
		/*Clear Flag*/
		Set_Bit_BitBandingAlias(PORTE_GPIOICR,DIO_PIN);
		/*un masking interrupt*/
		Set_Bit_BitBandingAlias(PORTE_GPIOIM,DIO_PIN);
		break;
	case DIO_PORTF:
		/*masking for pin*/
		Clear_Bit_BitBandingAlias(&PORTF_GPIOIM,DIO_PIN);
		/*CONFIG Event TYPE*/
		if (Event==EDGE_EVENT)
			Clear_Bit_BitBandingAlias(&PORTF_GPIOIS,DIO_PIN);
		else
			Set_Bit_BitBandingAlias(&PORTF_GPIOIS,DIO_PIN);
		/*CONFIG Falling, rising edge or high, low level*/
		if (Event_Type==FALLING_EDGE_LOW_LEVEL)
			Clear_Bit_BitBandingAlias(&PORTF_GPIOIEV,DIO_PIN);
		else
			Set_Bit_BitBandingAlias(&PORTF_GPIOIEV,DIO_PIN);
		/*Clear Flag*/
		Set_Bit_BitBandingAlias(&PORTF_GPIOICR,DIO_PIN);
		/*un masking interrupt*/
		Set_Bit_BitBandingAlias(&PORTF_GPIOIM,DIO_PIN);
		break;
	default:
		break;
	}
}

void GPIOF_Handler (void)
{
	DIO_WriteChannel(DIO_PORTF,PIN1,HIGH);
}