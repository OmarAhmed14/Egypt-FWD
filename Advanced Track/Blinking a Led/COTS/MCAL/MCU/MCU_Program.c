#include "Std_Types.h"
#include "Bit_Math.h"

#include "MCU_Cfg.h"
#include "MCU_Interface.h"
#include "MCU_Registers.h"


static const Mcu_ConfigType *GlobalPtr_UserData=NULL;

void MCU_Init(void)
{
	GlobalPtr_UserData=System_clocks;
}

Mcu_PllStatusType Mcu_GetPllStatus(void)
{
	if (Get_Bit(PLLSTAT,0)==0x1)
		return Locked;
	else
		return UnLocked;
}

void Mcu_InitClock(void)
{
	MCU_Init();
	u8 SYSD=4;
	/*The RCC2 register fields override the RCC register fields*/
	Set_Bit(RCC2,USERCC2);
	
	/*Init Clock Source*/
	RCC2=(RCC2&0xFFFFFF8F)|(GlobalPtr_UserData[Selected_Clock].Clock_Source<<4);

	if (GlobalPtr_UserData[Selected_Clock].PLL==ENABLE)
	{
	/*PLL ENABLED*/
	RCC2=(RCC2&0xFFFFDFFF)|(GlobalPtr_UserData[Selected_Clock].PLL<<13);
	
	/*Wait until PLL Will be Locked*/
	//while (Mcu_GetPllStatus()==UnLocked){}
	
	/*Not DIV400 */
	Set_Bit(RCC2,DIV400);
	
	/*Enable PLL OUTPUT 400*/
	Clear_Bit(RCC2,Bybass);
	
	/*Freq setting*/
	if (GlobalPtr_UserData[Selected_Clock].Freq_MHZ <50)
	{
		for (u8 Counter=9; Counter<=128;Counter++)
		{
		if ((400/Counter)==GlobalPtr_UserData[Selected_Clock].Freq_MHZ)
		{
			if (Counter%2==0)
				Set_Bit(RCC2,SYSDIV2LSB);
		
			else 
				Clear_Bit(RCC2,SYSDIV2LSB);
			
			RCC2=(RCC2&0xE07FFFFF)|(SYSD<<SYSDIV2);
			break;
		}
		else
			if (Counter%2==0)
				SYSD++;
		}
	}
		else
		{
		switch (GlobalPtr_UserData[Selected_Clock].Freq_MHZ)
		  {
			case 80:
			RCC2=(RCC2&0xE03FFFFF)|(F80MHZ<<SYSDIV2LSB);
			break;
			case 66:
			RCC2=(RCC2&0xE03FFFFF)|(F66MHZ<<SYSDIV2LSB);
			break;
			case 50:
			RCC2=(RCC2&0xE03FFFFF)|(F50MHZ<<SYSDIV2LSB);
			break;
			default:
			break;
			}
		}
	}
	else
	{
		/*PLL is Disabled*/
	}
	
}

Mcu_RawResetType Mcu_GetResetRawValue(void)
{
	/*CLEAR SW STATE BIT*/
	Clear_Bit(RESC,SW);
	
	/*Knowing Types of Reset which comes*/

	if (Get_Bit(RESC,EXT))
		return EXT;
	else if (Get_Bit(RESC,POR))
		return POR;
	else if (Get_Bit(RESC,BOR))
		return BOR;
	else if (Get_Bit(RESC,WDT00))
		return WDT00;
	else if (Get_Bit(RESC,SW))
		return SW;
	else if (Get_Bit(RESC,WDT11))
		return WDT11;
	else if (Get_Bit(RESC,MOSCFAIL))
		return MOSCFAIL;
}

void Mcu_PerformReset(void)  /*TRIGGER SW RESET*/
{
	/*CLEAR SW STATE BIT*/
	Clear_Bit(RESC,SW);
	
	/*SW RESET to All MC (Peripherals + CORE)*/
	APINT=0x05FAFFF4; /* SYSTEM RESET + VECTKEY*/
}

void MCU_CLOCK_PERIPHERALS (void)
{
	for (u8 i=0; i< NUM_PERIPHERALS_CLOCKED;i++)
	{
		u32* Reg= (MCU_Clocked_Peripherals[i].peripheral) + (RCGCx_Base);
		
		u8 Bit = MCU_Clocked_Peripherals[i].Moduke_Clocked;
		
		Set_Bit(*Reg,Bit);
	}

}
