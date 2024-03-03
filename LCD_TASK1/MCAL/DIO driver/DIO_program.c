
/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  DIO_program.c >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author: Nada Ehab 
 *  layer : MCAL
 *  SW:DIO/GPIO      
 */

#include "../../LIB/STD_types.h"
#include "../../LIB/STD_MATHS.h"

#include "DIO_config.h"
#include "DIO_interface.h"
#include "DIO_PRIVATE.h"

/*********PIN FUNCTIONS********************/

D_errorstate   DIO_voidSetPinDirection(uint8_t port ,uint8_t pinNum, uint8_t direction)
{
	D_errorstate local_state = DIO_OK;
	if( (port>3) || (pinNum>7) )
	{
		
		if(direction == DIO_PIN_OUTPUT)                         //1- check if the direction the user entered is output or input
		{                                                       // 2- if output then check what port and set the pin number (bit position)
			switch (port)
			{
				case DIO_PORTA: set_bit(DDRA,pinNum); break;
				case DIO_PORTB: set_bit(DDRB,pinNum); break;
				case DIO_PORTC: set_bit(DDRC,pinNum); break;
				case DIO_PORTD: set_bit(DDRD,pinNum); break;
			}
			
		}
		else if(direction == DIO_PIN_INTPUT)
		{
			switch (port)
			{
				case DIO_PORTA: clear_bit(DDRA,pinNum); break;
				case DIO_PORTB: clear_bit(DDRB,pinNum); break;
				case DIO_PORTC: clear_bit(DDRC,pinNum); break;
				case DIO_PORTD: clear_bit(DDRD,pinNum); break;
			}
		}
		else
		{
			local_state= DIO_NOTOK;
		}
		
	}
	else
	{
		local_state= DIO_NOTOK;
	}
	
	return local_state;
}

D_errorstate   DIO_voidSetPinValue    (uint8_t port ,uint8_t pinNum, uint8_t value    ) //output DDRA=1
{
	D_errorstate local_state = DIO_OK;
	
	if((port>3) || (pinNum>7))
	{
		
		if(value == DIO_PINVAL_HIGH)
		{
			switch(port)
			{
				
				case DIO_PORTA: set_bit(PORTA,pinNum); break;
				case DIO_PORTB: set_bit(PORTB,pinNum); break;
				case DIO_PORTC: set_bit(PORTC,pinNum); break;
				case DIO_PORTD: set_bit(PORTD,pinNum); break;
			}
		}
		else if(value == DIO_PIN_INTPUT)
		{
			switch (port)
			{
				case DIO_PORTA: clear_bit(PORTA,pinNum); break;
				case DIO_PORTB: clear_bit(PORTB,pinNum); break;
				case DIO_PORTC: clear_bit(PORTC,pinNum); break;
				case DIO_PORTD: clear_bit(PORTD,pinNum); break;
			}
		}
		else
		{
			local_state = DIO_NOTOK;
		}
	}
	else
	{
		local_state = DIO_NOTOK;
	}
	
	return local_state;
}

D_errorstate DIO_voidGetPinValue    (uint8_t port ,uint8_t pinNum, uint8_t *PtrDta    )
{
	D_errorstate RETURN_VAL= DIO_OK;
	if((port>3) || (pinNum>7))
	{
		
		switch (port)
		{
			case DIO_PORTA: *PtrDta= GET_BIT(PINA,pinNum); break;
			case DIO_PORTB: *PtrDta= GET_BIT(PINB,pinNum); break;
			case DIO_PORTC: *PtrDta= GET_BIT(PINC,pinNum); break;
			case DIO_PORTD: *PtrDta= GET_BIT(PIND,pinNum); break;
		}
	}
	else
	{
		RETURN_VAL = DIO_NOTOK;
	}
	return RETURN_VAL;
	
}

D_errorstate   DIO_voidTogglePin      (uint8_t port ,uint8_t pinNum, uint8_t *PtrDta  )
{
	D_errorstate RETURN_VAL= DIO_OK;
	if((port>3) || (pinNum>7))
	{
		
		switch (port)
		{
			case DIO_PORTA: *PtrDta= toggle_bit(PORTA,pinNum); break;
			case DIO_PORTB: *PtrDta= toggle_bit(PORTB,pinNum); break;
			case DIO_PORTC: *PtrDta= toggle_bit(PORTC,pinNum); break;
			case DIO_PORTD: *PtrDta= toggle_bit(PORTD,pinNum); break;
		}
	}
	else
	{
		RETURN_VAL = DIO_NOTOK;
	}
	return RETURN_VAL;
	
}

/*******PORT FUNCTIONS********************/

D_errorstate   DIO_voidSetPortDirection(uint8_t port, uint8_t direction                )
{
	D_errorstate RETURN_VAL= DIO_OK;
	if( (port>=DIO_PORTA) && (direction != (0||1)) )
	{
		switch(port)
		{
			case DIO_PORTA : DDRA == direction;
			case DIO_PORTB : DDRB == direction;
			case DIO_PORTC : DDRC == direction;
			case DIO_PORTD : DDRD == direction;
		}
	}
	else
	{
		RETURN_VAL = DIO_NOTOK;
	}
	
	
	return RETURN_VAL;
}


D_errorstate   DIO_voidSetPortValue     (uint8_t port , uint8_t value                   )
{
	
	D_errorstate RETURN_VAL= DIO_OK;
	if( port>=DIO_PORTA)
	{
		switch(port)
		{
			case DIO_PORTA : PINA == value;
			case DIO_PORTB : PINB == value;
			case DIO_PORTC : PINC == value;
			case DIO_PORTD : PIND == value;
		}
	}
	else
	{
		RETURN_VAL = DIO_NOTOK;
	}
	
	
	return RETURN_VAL;
}








