
/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< PUSH_BUTTON_program.c  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author: Nada Ehab 
 *  layer : ECUAL
 *  SW:PUSH_BUTTON  
 */

#include "../.././MCAL/DIO driver/DIO_config.h"
#include "../.././MCAL/DIO driver/DIO_interface.h"
#include "../.././MCAL/DIO driver/DIO_private.h"

#include "../../LIB/STD_Types.h"
#include "../../LIB/STD_MATHS.h"

#include "PUSH_BUTTON_config.h"
#include "PUSH_BUTTON_interface.h"
#include "PUSH_BUTTON_private.h"

B_errorstate BUTTON_init     (uint8_t BUTTON_pinnum, uint8_t BUTTON_port)
{
	if(DIO_voidSetPinDirection(BUTTON_port , BUTTON_pinnum, DIO_PIN_INTPUT ))
	{
		return B_OK;
	}
	else
	{
		return B_NOTOK;
	}
}

B_errorstate BUTTON_on       (uint8_t BUTTON_pinnum, uint8_t BUTTON_port)
{
	BUTTON_init(BUTTON_pinnum,BUTTON_port);
	if(DIO_voidSetPinValue(BUTTON_port , BUTTON_pinnum , DIO_PINVAL_HIGH))  return B_OK;
	return B_NOTOK;
}
B_errorstate BUTTON_off      (uint8_t BUTTON_pinnum, uint8_t BUTTON_port)
{
	BUTTON_init(BUTTON_pinnum,BUTTON_port);
	if(DIO_voidSetPinValue(BUTTON_port , BUTTON_pinnum , DIO_PINVAL_LOW))  return B_OK;
	return B_NOTOK;
}

B_errorstate BTN_PULL_UP     (uint8_t BUTTON_pinnum, uint8_t BUTTON_port)
{
	BUTTON_init(BUTTON_pinnum,BUTTON_port);
	switch(BUTTON_port)
	{
		case DIO_PORTA:set_bit(PORTA,BUTTON_pinnum); break;
		case DIO_PORTB:set_bit(PORTB,BUTTON_pinnum); break;
		case DIO_PORTC:set_bit(PORTC,BUTTON_pinnum); break;
		case DIO_PORTD:set_bit(PORTD,BUTTON_pinnum); break;
	}
	return B_OK;
	
}

B_STATE BUTTON_Read_State  (uint8_t BUTTON_pinnum, uint8_t BUTTON_port)
{
	uint8_t *pin_valueL = DIO_PINVAL_HIGH;
	uint8_t *pin_valueH = DIO_PINVAL_LOW;
	if(DIO_voidGetPinValue(BUTTON_port,BUTTON_pinnum , pin_valueL))
	{
		BUTTON_on(BUTTON_pinnum , BUTTON_port);
		return B_ON;
	}
	else if(DIO_voidGetPinValue(BUTTON_port,BUTTON_pinnum , pin_valueH))
	{
		BUTTON_off(BUTTON_pinnum , BUTTON_port);
	return B_OFF;
	}
	
}