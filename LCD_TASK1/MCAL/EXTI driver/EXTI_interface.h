
/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  EXTI_PRIVATE.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author: Nada Ehab 
 *  layer : MCAL
 *  SW:EXTI      
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

/********************************************************************************/
/*******EXTINT_LINES**************/
typedef enum
{
	LINE2=5,
	LINE0, LINE1
}EXT_LINE;

/*******SENSE_MODE**************/
typedef enum
{
	RISING_EDGE=0
	,FALLING_EDGE,
	LOW_LEVEL,ON_CHANGE
	
}SENSE_MODE;

/********************************************************************************/

void EXTI_INIT               (EXT_LINE IntLine , SENSE_MODE IntMode  );

void EXTI_ENABLE_GLOBALINT   (void                                   );

void EXTI_DISABLE_GLOBALINT  (void                                   );

void EXTI_ENABLE_CONTORLINT  (EXT_LINE IntLine                       );

void EXTI_DISABLE_CONTORLINT (EXT_LINE IntLine                       );

void EXTI_CLR_FLAG           (EXT_LINE IntLine                       );



#endif