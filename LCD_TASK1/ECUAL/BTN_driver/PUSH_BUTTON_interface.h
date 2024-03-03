
/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< PUSH_BUTTON_interface.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author: Nada Ehab 
 *  layer : MECUAL
 *  SW:PUSH_BUTTON  
 */


#ifndef PUSH_BUTTON_INTERFACE_H_
#define PUSH_BUTTON_INTERFACE_H_

typedef enum 
{
	B_ON,
	B_OFF
}B_STATE;


/* ERROR STATE*/
typedef enum BTN_ERROR
{
	B_OK,
	B_NOTOK
}B_errorstate;


/******************FUNCTION DECLARATION*******************/
B_errorstate BUTTON_init        (uint8_t BUTTON_pinnum, uint8_t BUTTON_port);
B_errorstate BUTTON_on          (uint8_t BUTTON_pinnum, uint8_t BUTTON_port);
B_errorstate BUTTON_off         (uint8_t BUTTON_pinnum, uint8_t BUTTON_port);
B_errorstate BTN_PULL_UP        (uint8_t BUTTON_pinnum, uint8_t BUTTON_port);
B_STATE      BUTTON_Read_State  (uint8_t BUTTON_pinnum, uint8_t BUTTON_port);









#endif
