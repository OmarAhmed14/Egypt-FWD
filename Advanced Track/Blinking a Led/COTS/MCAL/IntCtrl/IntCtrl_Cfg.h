#ifndef INTCTRL_CFG_H_
#define INTCTRL_CFG_H_ 

/*Select Base Priority*/

void IntCtrl_BasePriority(void);

/*Groupping*/

#define Group_xxx   1
#define Group_xxy   2
#define Group_xyy   3
#define Group_yyy   4


/*Choosing Groupping for All interrupts*/
#define Selected_Group      Group_xyy

/*Number of Enable Interrupts*/

#define Number_Enabled_Interrupts   1

/*Interrupts (Vecror Table)*/

typedef enum
{
	GPIO_A,
	GPIO_B,
	GPIO_C,
	GPIO_D,
	GPIO_E,
	UART0,
	UART1,
	SSI0,
	I2C0,
	PWM0_Fault,
	PWM0_Generator0,
	PWM0_Generator1,
	PWM0_Generator2,
	QEI0,
	ADC0_Sequence0,
	ADC0_Sequence1,
	ADC0_Sequence2,
	ADC0_Sequence3,
	Watchdog_Timers0_and_1,
	_16_32_Bit_Timer0A,
	_16_32_Bit_Timer0B,
	_16_32_Bit_Timer1A,
	_16_32_Bit_Timer1B,
	_16_32_Bit_Timer2A,
	_16_32_Bit_Timer2B,
	Analog_Comparator0,
	Analog_Comparator1,
	System_Control=28,
	Flash_Memory_Control_and_EEPROM_Control,
	GPIO_F,
}INTERRUPTS;

typedef struct 
{
	INTERRUPTS Interrupt;
	u32 Group;
	u32 SubGroup;
}NVIC_Enabled_Interrupt;

#endif
