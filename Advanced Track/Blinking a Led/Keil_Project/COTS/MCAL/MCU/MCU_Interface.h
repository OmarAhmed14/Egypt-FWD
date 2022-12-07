#ifndef MCU_INTERFACE_H_
#define MCU_INTERFACE_H_

void MCU_Init(void);

Mcu_PllStatusType Mcu_GetPllStatus(void);

void Mcu_InitClock(void);

Mcu_RawResetType Mcu_GetResetRawValue(void);

void Mcu_PerformReset(void);

void MCU_CLOCK_PERIPHERALS (void);

#endif 