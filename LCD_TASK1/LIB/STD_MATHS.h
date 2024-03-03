/*
 *  <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<  STD_MATHS.h  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author: Nada Ehab 
 *  layer: UTILITIES
 */ 

#ifndef STD_MATHS_H_
#define STD_MATHS_H_


/*functions like macro*/

#define clear_bit(reg,bit_position)  reg&=(~(1<<bit_position))

#define set_bit(reg,bit_position)  reg|=( 1<<bit_position)

#define toggle_bit(reg,bit_position)  reg^=(1<<bit_position)

#define GET_BIT(reg,bit_position)  (reg &(1<<bit_position))>>bit_position




#endif