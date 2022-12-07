#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#define LOW       0
#define HIGH      1

#define DIO_PORTA    0
#define DIO_PORTB    1
#define DIO_PORTC    2
#define DIO_PORTD    3
#define DIO_PORTE    4
#define DIO_PORTF    5

#define PIN0         0
#define PIN1         1
#define PIN2         2
#define PIN3         3
#define PIN4         4
#define PIN5         5
#define PIN6         6
#define PIN7         7

#define INPUT_PIN       0
#define OUTPUT_PIN      1

#define INPUT_PORT    0x00
#define OUTPUT_PORT   0xFF

typedef enum
{
	EDGE_EVENT,
	LEVEL_EVENT,
}EVENT;

typedef enum 
{
	FALLING_EDGE_LOW_LEVEL,
	RISING_EDGE_HIGH_LEVEL,
}EVENT_TYPE;

u8 DIO_READChannel(u8 DIO_PORT, u8 DIO_PIN);

void DIO_WriteChannel(u8 DIO_PORT, u8 DIO_PIN, u8 TypeLevel);

u8 DIO_ReadPort(u8 DIO_PORT);

void Dio_WritePort(u8 DIO_PORT, u8 DIO_PORTVALUE);

void DIO_DirectionPort(u8 DIO_PORT, u8 DIO_PORTDirection);

void DIO_DirectionChannel(u8 DIO_PORT, u8 DIO_PIN, u8 DIO_PINDirection);

void DIO_PULLUP_PIN (u8 DIO_PORT, u8 DIO_PIN);

void DIO_ENInterrupt(u8 DIO_PORT, u8 DIO_PIN, EVENT Event, EVENT_TYPE Event_Type);

void GPIOF_Handler (void);

#endif