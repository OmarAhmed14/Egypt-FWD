#include "Std_Types.h"
#include "IntCtrl_Cfg.h"

/*Enter Interrupts What YOu want to Enable Them*/

const NVIC_Enabled_Interrupt Enabled_Interrupts_0_31[Number_Enabled_Interrupts]={{_16_32_Bit_Timer0A ,        1          ,3}};



/*Select Base Priotity (7 Levels priority)*/

/* 
             ..Choices..
0x00 ---> All unmasked								
0x20 ---> All 1 to 7 is masked   
0x40 ---> All 2 to 7 is masked
0x60 ---> All 3 to 7 is masked
0x80 ---> All 4 to 7 is masked
0xA0 ---> All 5 to 7 is masked
0xC0 ---> 6 and 7 is masked
0xE0 ---> only 7 is masked

*/
void IntCtrl_BasePriority()
{
	__asm ("mov R0, #0x00");   // Put Hex Number in this Line
	__asm ("MSR BASEPRI, R0");
}
