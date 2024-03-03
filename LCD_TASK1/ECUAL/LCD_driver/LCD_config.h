/*
*
 *  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  CLCD_config.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author: Nada Ehab 
 *  layer : MECUAL
 *  SW:CLCD   
 */


#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#include "../.././MCAL/DIO driver/DIO_config.h"
#include "../.././MCAL/DIO driver/DIO_interface.h"



/**********************************CLCD MODE**************************************/

#define CLCD_MODE  4



/*******************************************************************************/

/***********************LCD PORTS**********************************************/
/*   16 PINS ->8 PINS for data  (extracted from MC)  */
 /*options for these pins*/
                                                     
/*     PORTA
       PORTB
       PORTC
       PORTD
*/

#define CLCD_DATA_PORT      PORTA  //8PINS
#define CLCD_CONTROL_PORT   PORTC  //RS,RW,EN

/*******************************************************************************/

/*CONROL PINS*/

#define  CLCD_RS      DIO_PIN0  
#define  CLCD_RW      DIO_PIN1 
#define  CLCD_EN      DIO_PIN2   

/*******************************************************************************/



	   
#endif