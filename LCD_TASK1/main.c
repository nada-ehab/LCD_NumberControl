/*
 * main.c
 *
 * Created: 2/13/2024 2:34:06 PM
 *  Author: HomePC
 */ 

#include <xc.h>

#include <util/delay.h>

#include "LIB/STD_MATHS.h"
#include "LIB/STD_types.h"

#include "ECUAL/LCD_driver/LCD_interface.h"
#include "ECUAL/LCD_driver/LCD_config.h"
#include "ECUAL/LCD_driver/LCD_private.h"

#include "ECUAL/BTN_driver/PUSH_BUTTON_config.h"
#include "ECUAL/BTN_driver/PUSH_BUTTON_interface.h"
#include "ECUAL/BTN_driver/PUSH_BUTTON_private.h"

#include "MCAL/EXTI driver/EXTI_config.h"
#include "MCAL/EXTI driver/EXTI_interface.h"
#include "MCAL/EXTI driver/EXTI_private.h"


void Counter_INCREASING(void);
void Counter_DECREASING (void);

/************************************************************************/

static uint8_t Counter = 0;
static void APPINIT(void)
{
   // CLCD_init_lcd ();
	EXTI_INIT (LINE0,RISING_EDGE);
	EXTI_INIT (LINE1,RISING_EDGE);
	BUTTON_init(DIO_PIN2,PORTD); //init BTN1
	BUTTON_init(DIO_PIN3,PORTD); //init BTN2
	
}

/************************************************************************/


int main(void)
{
	APPINIT();
	EXTI_ENABLE_GLOBALINT();
	EXTI_voidSetCallBack(Counter_INCREASING , LINE0);
	EXTI_voidSetCallBack  (Counter_DECREASING , LINE1);
	
	
	while(1)
	{
		
	}
}


void Counter_INCREASING(void)
{
	 
	uint8_t BTN2_STATE = BUTTON_Read_State(DIO_PIN3,PORTD);
	
	if( BTN2_STATE == B_ON   && Counter <= 9)
	{
		Counter++;
		//CLCD_ClearScreen ();
		//LCD_SendIntegarNumber(Counter + 48);
		
	}
}


void Counter_DECREASING (void)
{
	unsigned char BTN2_STATE = BUTTON_Read_State(DIO_PIN3,PORTD);
	if( BTN2_STATE == B_OFF && ( Counter <= 9) && Counter > 0)
	{
		
		Counter--;
		//CLCD_ClearScreen ();
		//LCD_SendIntegarNumber(Counter + 48);
	}
}
