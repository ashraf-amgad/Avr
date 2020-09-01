/*
 * DIO_utils.h
 *
 * Created: 9/11/2019 8:56:41 AM
 *  Author: Louda
 */ 


#ifndef DIO_UTILS_H_
#define DIO_UTILS_H_


#define Set_Bit(reg,bit_num)		    (reg |= (1<<bit_num) )
#define Clr_Bit(reg,bit_num)			(reg &= (~(1<<bit_num)) )
#define Tog_Bit(reg,bit_num)			(reg ^= (1<<bit_num) )
#define Get_Bit(reg,bit_num)			( (reg>>bit_num) & 0x01 )
#define Set_Port(reg,val)				(reg = val)
   
#endif /* DIO_UTILS_H_ */