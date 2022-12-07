#ifndef INTRCTRL_REGISTERS_H_
#define INTRCTRL_REGISTERS_H_


#define APINT             (*((volatile u32*)0xE000ED0C))  // to select config of group and subgroup priorty

#define NVIC_PRI0         ((volatile u32*)0xE000E400)       // to Select Priority

#define NVIC_EN0          ((volatile u32*)0xE000E100)   // to Enable Interrupts

#endif
