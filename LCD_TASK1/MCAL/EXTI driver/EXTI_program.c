
/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  EXTI_PRIVATE.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author: Nada Ehab 
 *  layer : MCAL
 *  SW:EXTI      
 */

#include  "../.././LIB/STD_types.h"
#include  "../.././LIB/STD_MATHS.h"

#include "EXTI_config.h"
#include "EXTI_interface.h"
#include "EXTI_private.h"
/*************************************************************************************/
/*global function carries the address of ISR function*/

void (*EXTI_CallBack[3]) (void) = { NULL } ; 

/*************************************************************************************/

void EXTI_INIT               (EXT_LINE IntLine , SENSE_MODE IntMode  )
{
	 switch(IntLine)
	 {
		 case LINE0:
		 switch(IntMode)
		 {
			 case FALLING_EDGE:
			 set_bit  (EXTI_MCUCR , 1);
			 clear_bit(EXTI_MCUCR , 0);
			 
			 case RISING_EDGE:
			 set_bit  (EXTI_MCUCR , 1);
			 set_bit  (EXTI_MCUCR , 0);
			 
			 case LOW_LEVEL:
			 clear_bit  (EXTI_MCUCR , 0);
			 clear_bit  (EXTI_MCUCR , 0);
			 
			 case ON_CHANGE:
			 set_bit  (EXTI_MCUCR , 0);
			 clear_bit(EXTI_MCUCR , 1);
		 }
		 
		 case LINE1:
		 switch(IntMode)
		 {
			 case FALLING_EDGE:
			 set_bit  (EXTI_MCUCR , 3);
			 clear_bit(EXTI_MCUCR , 2);
			 
			 case RISING_EDGE:
			 set_bit  (EXTI_MCUCR , 3);
			 set_bit  (EXTI_MCUCR , 2);
			 
			 case LOW_LEVEL:
			 clear_bit  (EXTI_MCUCR , 3);
			 clear_bit  (EXTI_MCUCR , 2);
			 
			 case ON_CHANGE:
			 set_bit  (EXTI_MCUCR , 2);
			 clear_bit(EXTI_MCUCR , 3);
		 }
		 
		 
	 }
	
	
}

void EXTI_ENABLE_GLOBALINT   (void                                   )
{
	
	set_bit(SREG ,SREG_BIT_I);
	
}


void EXTI_DISABLE_GLOBALINT  (void                                   )
{
	clear_bit(SREG ,SREG_BIT_I);
}


void EXTI_ENABLE_CONTORLINT  (EXT_LINE IntLine                       )
{
	set_bit(EXT_GICR , IntLine);
	
}

void EXTI_DISABLE_CONTORLINT (EXT_LINE IntLine                       )
{
	clear_bit(EXT_GICR , IntLine);
}

void EXTI_CLR_FLAG           (EXT_LINE IntLine                       )
{
	clear_bit(EXTI_GIFR , IntLine);
}

/*************************************************************************************/
void EXTI_voidSetCallBack( void (*Copy_pvoidCallBack)(void) , uint8_t Copy_u8EXTILine ){

	if( Copy_pvoidCallBack != NULL ){

		EXTI_CallBack[Copy_u8EXTILine] = Copy_pvoidCallBack ;

	}

}


/* ISR --> Implementation */
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{

	if( EXTI_CallBack[0] != NULL ){

		EXTI_CallBack[0](); 
		EXTI_CLR_FLAG( LINE0 );

	}

}

void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{

	if( EXTI_CallBack[1] != NULL ){

		EXTI_CallBack[1]();
		EXTI_CLR_FLAG( LINE1 );

	}

}