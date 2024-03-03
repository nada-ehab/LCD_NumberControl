
/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  EXTI_PRIVATE.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author: Nada Ehab 
 *  layer : MCAL
 *  SW:EXTI      
 */

/*************************************************************************************/
#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_


#define EXT_GICR     *((volatile uint8_t *)0x5B)
#define EXTI_GIFR    *((volatile uint8_t *)0x5A)
#define EXTI_MCUCR   *((volatile uint8_t *)0x55)
#define EXTI_MCUCSR  *((volatile uint8_t *)0x54)
#define SREG         *((volatile uint8_t *)0x5F)





#endif