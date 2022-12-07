#ifndef MCU_REGISTERS_H_
#define MCU_REGISTERS_H_

#define APINT        (*((volatile u32*)0xE000ED0C))

#define RCC2         (*((volatile u32*)0x400FE070))
#define USERCC2            31
#define DIV400             30
#define SYSDIV2LSB         22
#define Bybass             11
#define SYSDIV2            23

#define PLLSTAT      (*((volatile u32*)0x400FE168))

#define RCGCGPIO     (*((volatile u32*)0x400FE608))

#define RESC         (*((volatile u32*)0x400FE05C))

#define RCGCx_Base      ((volatile u32*)0x400FE600)


#endif
