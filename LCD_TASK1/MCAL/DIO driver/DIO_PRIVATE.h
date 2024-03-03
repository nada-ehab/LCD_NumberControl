
/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  DIO_PRIVATE.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author: Nada Ehab 
 *  layer : MCAL
 *  SW:DIO/GPIO      
 */

#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/********************************register definition ********************************/



/* Group A  */
#define PORTA   *((volatile uint8_t*)0x3B)
#define DDRA    *((volatile uint8_t*)0x3A)
#define PINA    *((volatile uint8_t*)0x39)

/* Group B  */
#define PORTB   *((volatile uint8_t*)0x38)
#define DDRB    *((volatile uint8_t*)0x37)
#define PINB    *((volatile uint8_t*)0x36)

/* Group C  */
#define PORTC   *((volatile uint8_t*)0x35)
#define DDRC    *((volatile uint8_t*)0x34)
#define PINC    *((volatile uint8_t*)0x33)

/* Group D  */
#define PORTD   *((volatile uint8_t*)0x32)
#define DDRD    *((volatile uint8_t*)0x31)
#define PIND    *((volatile uint8_t*)0x30)






#endif