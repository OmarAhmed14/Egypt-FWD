#ifndef MCU_CFG_H_
#define MCU_CFG_H_

#define NULL     0

/*PLL State*/
#define ENABLE    0
#define DISABLE   1

/*Clock Source*/
#define MOSC      0
#define PIOSC     1

/*Number of clocks in array*/
#define NUM_CLOCKS    2

/*Number of Peripherals i want to clock*/
#define NUM_PERIPHERALS_CLOCKED      3

/*Clocks*/
#define MCU_CLOCK_0   0
#define MCU_CLOCK_1   1

/*Selected_Clock*/
#define Selected_Clock   MCU_CLOCK_1 

/*Freq*/
typedef enum 
{
	F80MHZ=0b0000100,
	F66MHZ=0b0000101,
	F50MHZ=0b0000111,
}Freq_50_To_80;

/*CLOCK CONFIG*/
typedef struct 
{
	u8 Clock_Source;
	u8 PLL;
	u8 Freq_MHZ;     
}Mcu_ConfigType;

const Mcu_ConfigType System_clocks[NUM_CLOCKS] =
{
	             /*CLOCKSOURCE     PLL      FEQ_MHZ*/
	/*MCU_CLOCK_0*/ {PIOSC,       ENABLE,      30},
    /*MCU_CLOCK_1*/ {PIOSC,       ENABLE,      50}
 };

typedef enum 
{ 
	Locked,
	UnLocked,
}Mcu_PllStatusType;

typedef enum 
{
	EXT,
	POR,
	BOR,
	WDT00,
	SW,
	WDT11,
	MOSCFAIL=16,
}Mcu_RawResetType;

typedef enum 
{
	WDT,
	TIMER,
	GPIO,
	DMA,
	HIP=5,
	UART,
	SSI,
	I2C,
	USB=10,
	CAN=13,
	ADC,
	ACMP,
	PWM,
	QEI,
	EEPROM=22,
	WTIMER,

}MCU_Peripherals;

typedef enum 
{
		WDT0,
		WDR1,
	/*-------------*/
		TIMER0=0,
		TIMER1,
		TIMER2,
		TIMER3,
		TIMER4,
		TIMER5,
	/*-------------*/
		GPIOA=0,
		GPIOB,
		GPIOC,
		GPIOD,
		GPIOE,
		GPIOF,
	/*-------------*/
		DMA0=0,
	/*-------------*/
		HIB0=0,
	/*-------------*/
		UART0=0,
		UART1,
		UART2,
		UART3,
		UART4,
		UART5,
		UART6,
		UART7,
	/*-------------*/
		SSI0=0,
		SSI1,
		SSI2,
		SSI3,
	/*------------*/
		I2C0=0,
		I2C1,
		I2C2,
		I2C3,
	/*------------*/
		USB0=0,
	/*------------*/
		CAN0=0,
		CAN1,
	/*------------*/
		ADC0=0,
		ADC1,
	/*------------*/
		ACMP0=0,
	/*------------*/
		PWM0=0,
		PWM1,
	/*------------*/
		QEI0=0,
		QEI1,
	/*------------*/
		EEPROM0=0,
	/*------------*/
		TIMERW0=0,
		TIMERW1,
		TIMERW2,
		TIMERW3,
		TIMERW4,
		TIMERW5,
}Module_Number;

typedef struct
{
	MCU_Peripherals peripheral;
	Module_Number Moduke_Clocked;

}CLOCKED_PERIPHERAL;

const CLOCKED_PERIPHERAL MCU_Clocked_Peripherals[NUM_PERIPHERALS_CLOCKED] = 
{
	{GPIO , GPIOF} ,
	{TIMER , TIMER0},
	{CAN , CAN0},
	{EEPROM,EEPROM0}
};

#endif 
