
/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  DIO_interface.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author: Nada Ehab 
 *  layer : MCAL
 *  SW:DIO/GPIO      
 */
/************************************************************************/
#include "../.././LIB/STD_types.h"
#include "../.././LIB/STD_MATHS.h"
/************************************************************************/

#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*define PIN direction*/
#define DIO_PIN_OUTPUT 1
#define DIO_PIN_INTPUT 0


/*define port*/
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

/*define PIN*/
#define DIO_PIN0  0
#define DIO_PIN1  1
#define DIO_PIN2  2
#define DIO_PIN3  3
#define DIO_PIN4  4
#define DIO_PIN5  5
#define DIO_PIN6  6
#define DIO_PIN7  7

/*define pin_value*/
#define DIO_PINVAL_HIGH 1
#define DIO_PINVAL_LOW  0

/* ERROR STATE*/
typedef enum
{
	DIO_OK,
	DIO_NOTOK
}D_errorstate;

/*define PORT direction*/
#define DIO_PORT_OUTPUT 0xFF
#define DIO_PORT_INTPUT 0

/*define PORT_value*/
#define DIO_PORTVAL_HIGH 0xFF
#define DIO_PORTVAL_LOW  0

/******************FUNCTION DECLARATION*******************/
D_errorstate   DIO_voidSetPinDirection (uint8_t port ,uint8_t pinNum, uint8_t direction);
D_errorstate   DIO_voidSetPinValue     (uint8_t port ,uint8_t pinNum, uint8_t value    );
D_errorstate   DIO_voidGetPinValue     (uint8_t port ,uint8_t pinNum, uint8_t *PtrDta  );
D_errorstate   DIO_voidTogglePin       (uint8_t port ,uint8_t pinNum, uint8_t *PtrDta  );

D_errorstate   DIO_voidSetPortDirection(uint8_t port, uint8_t direction                );
D_errorstate   DIO_voidSetPortValue     (uint8_t port , uint8_t value                  );















#endif
