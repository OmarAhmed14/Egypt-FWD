#ifndef DIO_REGISTERS_H_
#define DIO_REGISTERS_H_


#define PORTA_DATA   *((volatile u32*)(0x40004000))

#define PORTB_DATA   *((volatile u32*)(0x40005000))

#define PORTC_DATA   *((volatile u32*)(0x40006000))

#define PORTD_DATA   *((volatile u32*)(0x40007000))

#define PORTE_DATA   *((volatile u32*)(0x40024000))

#define PORTF_DATA   *((volatile u32*)(0x40025000))

/*-------------------------------------------------------------------------------------------------*/

#define PORTA_DIR   *((volatile u32*)(0x40004400))
																				
#define PORTB_DIR   *((volatile u32*)(0x40005400))
																				
#define PORTC_DIR   *((volatile u32*)(0x40006400))
																					
#define PORTD_DIR   *((volatile u32*)(0x40007400))
																				
#define PORTE_DIR   *((volatile u32*)(0x40024400))
																					
#define PORTF_DIR   *((volatile u32*)(0x40025400))

/*-------------------------------------------------------------------------------------------------*/

#define PORTA_DEN   *((volatile u32*)(0x4000451C))
																						 
#define PORTB_DEN   *((volatile u32*)(0x4000551C))
																						 
#define PORTC_DEN   *((volatile u32*)(0x4000651C))
																						 
#define PORTD_DEN   *((volatile u32*)(0x4000751C))
																						 
#define PORTE_DEN   *((volatile u32*)(0x4002451C))
																						 
#define PORTF_DEN   *((volatile u32*)(0x4002551C))

/*-------------------------------------------------------------------------------------------------*/

#define PORTA_PUR   *((volatile u32*)(0x40004510))
							
#define PORTB_PUR   *((volatile u32*)(0x40005510))
						
#define PORTC_PUR   *((volatile u32*)(0x40006510))
				
#define PORTD_PUR   *((volatile u32*)(0x40007510))
				
#define PORTE_PUR   *((volatile u32*)(0x40024510))
						
#define PORTF_PUR   *((volatile u32*)(0x40025510))

/*-------------------------------------------------------------------------------------------------*/

#define PORTA_CR   *((volatile u32*)(0x40004524))
							
#define PORTB_CR   *((volatile u32*)(0x40005524))
							
#define PORTC_CR   *((volatile u32*)(0x40006524))
							
#define PORTD_CR   *((volatile u32*)(0x40007524))
							
#define PORTE_CR   *((volatile u32*)(0x40024524))
							
#define PORTF_CR   *((volatile u32*)(0x40025524))

/*-------------------------------------------------------------------------------------------------*/

#define PORTA_LOCK   *((volatile u32*)(0x40004520))
							
#define PORTB_LOCK   *((volatile u32*)(0x40005520))
							
#define PORTC_LOCK   *((volatile u32*)(0x40006520))
					
#define PORTD_LOCK   *((volatile u32*)(0x40007520))
							
#define PORTE_LOCK   *((volatile u32*)(0x40024520))
							
#define PORTF_LOCK   *((volatile u32*)(0x40025520))

/*-------------------------------------------------------------------------------------------------*/

#define PORTA_GPIOIS   *((volatile u32*)(0x40004404))
																								
#define PORTB_GPIOIS   *((volatile u32*)(0x40005404))
						
#define PORTC_GPIOIS   *((volatile u32*)(0x40006404))
						
#define PORTD_GPIOIS   *((volatile u32*)(0x40007404))
							
#define PORTE_GPIOIS   *((volatile u32*)(0x40024404))
							
#define PORTF_GPIOIS   *((volatile u32*)(0x40025404))

/*-------------------------------------------------------------------------------------------------*/

#define PORTA_GPIOIM   *((volatile u32*)(0x40004410))
					
#define PORTB_GPIOIM   *((volatile u32*)(0x40005410))
							
#define PORTC_GPIOIM   *((volatile u32*)(0x40006410))
									
#define PORTD_GPIOIM   *((volatile u32*)(0x40007410))
								
#define PORTE_GPIOIM   *((volatile u32*)(0x40024410))
								
#define PORTF_GPIOIM   *((volatile u32*)(0x40025410))

/*-------------------------------------------------------------------------------------------------*/

#define PORTA_GPIOICR   *((volatile u32*)(0x4000441C))
									
#define PORTB_GPIOICR   *((volatile u32*)(0x4000541C))
									
#define PORTC_GPIOICR   *((volatile u32*)(0x4000641C))
									
#define PORTD_GPIOICR   *((volatile u32*)(0x4000741C))
									
#define PORTE_GPIOICR   *((volatile u32*)(0x4002441C))
									
#define PORTF_GPIOICR   *((volatile u32*)(0x4002541C))

/*-------------------------------------------------------------------------------------------------*/

#define PORTA_GPIOIEV   *((volatile u32*)(0x4000440C))
								
#define PORTB_GPIOIEV   *((volatile u32*)(0x4000540C))
									
#define PORTC_GPIOIEV   *((volatile u32*)(0x4000640C))
									
#define PORTD_GPIOIEV   *((volatile u32*)(0x4000740C))
								
#define PORTE_GPIOIEV   *((volatile u32*)(0x4002440C))
								
#define PORTF_GPIOIEV   *((volatile u32*)(0x4002540C))

/*-------------------------------------------------------------------------------------------------*/

#endif