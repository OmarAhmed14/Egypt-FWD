#ifndef BIT_MATH_H
#define BIT_MATH_H

#define Set_Bit(reg,bit) (reg|=(1<<bit))
#define Get_Bit(reg,bit) ((reg>>bit) & 1)
#define Clear_Bit(reg,bit) (reg&=~(1<<bit))
#define Toggle_Bit(reg,bit) (reg^=(1<<bit))

/*Peripheral BitBanding Memory*/
#define Set_Bit_BitBandingAlias(Bit_Band_region_reg,bit)   (*((unsigned int volatile*)(0x42000000+4*((((unsigned int*)Bit_Band_region_reg-(unsigned int*)0x40000000))*32+bit))))=1
#define Clear_Bit_BitBandingAlias(Bit_Band_region_reg,bit) (*((unsigned int volatile*)(0x42000000+4*((((unsigned int*)Bit_Band_region_reg-(unsigned int*)0x40000000))*32+bit))))=0

#endif
