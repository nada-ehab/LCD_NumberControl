
/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  CLCD.PROGRAM.C  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author: Nada Ehab 
 *  layer: MCAL
 *  SWC:CLCD
 */ 

/***********************************************************************************************/
#include "../.././LIB/STD_types.h"
#include "../.././LIB/STD_MATHS.h""

#include "../.././MCAL/DIO driver/DIO_config.h"
#include "../.././MCAL/DIO driver/DIO_private.h"
#include "../.././MCAL/DIO driver/DIO_config.h"

#include "LCD_interface.h"
#include "LCD_config.h"
#include "LCD_private.h"

#include <util/delay.h>
/***********************************************************************************************/

void CLCD_init_lcd       (void)
{
	//#if CLCD == 4  
	
	_delay_ms(50);  //delay for more than 30ms (VDD rises to 4.5v)
	
	DIO_voidSetPinDirection(CLCD_DATA_PORT , LCD_PIN_4  , DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(CLCD_DATA_PORT , LCD_PIN_5  , DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(CLCD_DATA_PORT , LCD_PIN_6  , DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(CLCD_DATA_PORT , LCD_PIN_7  , DIO_PIN_OUTPUT);
	
	DIO_voidSetPinDirection(CLCD_CONTROL_PORT , CLCD_RS , DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(CLCD_CONTROL_PORT , CLCD_RW , DIO_PIN_OUTPUT);
	DIO_voidSetPinDirection(CLCD_CONTROL_PORT , CLCD_EN , DIO_PIN_OUTPUT);
	
	send_command(LCD_functionReset);
	_delay_ms(1);
	
	send_command(LCD_functionSet2);
	send_command(LCD_FunctionSet3);
	_delay_ms(1);
	
	send_command(LCD_functionSet2);
	send_command(LCD_FunctionSet3);
	_delay_ms(1);
	
	send_command(0x00);
	send_command(LCD_Displaycontrol);
	_delay_ms(1);
	
	
	send_command(0x00);
	CLCD_ClearScreen ();
	
	
	send_command(0x00);
	send_command(LCD_EntryModeSet);
	_delay_ms(1);	
}



void send_command  (uint8_t get_command)
{
	 DIO_voidSetPortValue(CLCD_CONTROL_PORT,get_command);
	 DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RS,DIO_PINVAL_LOW);
	 DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RW,DIO_PINVAL_LOW);
	 
	 SendFallingEdge ();
}


void send_data     (uint8_t get_data)
{
	
	DIO_voidSetPortValue(CLCD_CONTROL_PORT,get_data);
	DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RS,DIO_PINVAL_HIGH);
	DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_RW,DIO_PINVAL_LOW);
	
	SendFallingEdge ();
}


static void SendFallingEdge (void)
{
	DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_EN,DIO_PINVAL_HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CLCD_CONTROL_PORT,CLCD_EN,DIO_PINVAL_LOW);
	_delay_ms(1);
} 

void CLCD_ClearScreen    (void)
{
	
	send_command(LCD_Displayclear);
	_delay_ms(2);
}

void CLCD_voidSendString  ( const uint8_t * Copy_u8ptrString ){

	uint8_t LOC_u8Iterator = 0 ;

	while( Copy_u8ptrString[LOC_u8Iterator] != '\0' ){

		send_data ( Copy_u8ptrString[LOC_u8Iterator] );
		LOC_u8Iterator++ ;

	}

}


LCD_SendIntegarNumber(uint16_t IntegerNumber)
{
	#if   CLCD_MODE==4
	uint16_t NumberString[16];
	snprintf(NumberString,17,"%d",IntegerNumber);
	CLCD_voidSendString(NumberString);
	
	#endif
}