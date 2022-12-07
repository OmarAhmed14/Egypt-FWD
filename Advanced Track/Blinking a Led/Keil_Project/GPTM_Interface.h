#ifndef GPTM_INTERFACE_H_
#define GPTM_INTERFACE_H_

void GPTM_Init(void);

void TIMER0A_Handler(void);

void GPTM_delay_sec (u8 delay_Sec);

void GPTM_delay_millisec (u8 delay_ms);

#endif