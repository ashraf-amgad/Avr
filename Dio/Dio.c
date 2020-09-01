/*
 * DIO_prog.c
 *
 * Created: 9/11/2019 8:57:53 AM
 *  Author: Louda
 */ 

#include "Dio.h"



void Dio_Init(void)
{
	DIO_DDRA = DIO_PORTA_INITDIR;
	DIO_DDRB = DIO_PORTB_INITDIR;
	DIO_DDRC = DIO_PORTC_INITDIR;
	DIO_DDRD = DIO_PORTD_INITDIR;	
	
	DIO_PORTA = DIO_PORTA_INITVAL;
	DIO_PORTB = DIO_PORTB_INITVAL;
	DIO_PORTC = DIO_PORTC_INITVAL;
	DIO_PORTD = DIO_PORTD_INITVAL;
}




u8 Dio_ReadPinVal(u8 pin_num)
{
	u8 temp_pin_Val = 0x00;
	
	if(pin_num < 8)
	{
		temp_pin_Val =  Get_Bit(DIO_PINA , (pin_num) );
		return ( temp_pin_Val );
	}
	else if(pin_num < 16)
	{
		temp_pin_Val =  Get_Bit(DIO_PINB , (pin_num-8) );
		return ( temp_pin_Val );
	}
	
	else if(temp_pin_Val < 24)
	{
		temp_pin_Val =  Get_Bit(DIO_PINC , (pin_num-16) );
		return ( temp_pin_Val );
	}
	else if(pin_num < 32)
	{
		temp_pin_Val =  Get_Bit(DIO_PIND , (pin_num-24) );
		return ( temp_pin_Val );
	}
	
	else
	return -1;
}

/*************************************************/

u8 Dio_ReadPinDir(u8 pin_num)
{
	u8 temp_pin_dir = 0x00;
	
	if(pin_num < 8)
	{
		temp_pin_dir =  Get_Bit(DIO_DDRA , (pin_num) );
		return ( temp_pin_dir );
		
	}
	else if(pin_num < 16)
	{
		temp_pin_dir =  Get_Bit(DIO_DDRB , (pin_num-8) );
		return ( temp_pin_dir );
		
	}
	
	else if(pin_num < 24)
	{
		temp_pin_dir =  Get_Bit(DIO_DDRC , (pin_num-16) );
		return ( temp_pin_dir );
		
	}
	else if(pin_num < 32)
	{
		temp_pin_dir =  Get_Bit(DIO_DDRD , (pin_num-24) );
		return ( temp_pin_dir );
		
	}
		 
	else
		return -1;
}

/*************************************************/

void Dio_SetPin(u8 pin_num)
{
	if(pin_num < 8)
	{
		Set_Bit(DIO_PORTA , (pin_num) );
	}
	
	else if(pin_num < 16)
	{
		Set_Bit(DIO_PORTB , (pin_num-8) );
	}
	
	else if(pin_num < 24)
	{
		Set_Bit(DIO_PORTC , (pin_num-16) );
	}	  
	
	else if(pin_num < 32)
	{
		Set_Bit(DIO_PORTD , (pin_num-24) );
	}
	
	else
		return ;
	
}

/*************************************************/
void Dio_SetPinDir(u8 pin_num)
{
	if(pin_num < 8)
	{
		Set_Bit(DIO_DDRA , (pin_num) );
	}
	
	else if(pin_num < 16)
	{
		Set_Bit(DIO_DDRB , (pin_num-8) );
	}
	
	else if(pin_num < 24)
	{
		Set_Bit(DIO_DDRC , (pin_num-16) );
	}
	
	else if(pin_num < 32)
	{
		Set_Bit(DIO_DDRD , (pin_num-24) );
	}
	
	else
	return ;
	
}

/*************************************************/

void Dio_ClrPin(u8 pin_num)
{
	if(pin_num < 8)
	{
		Clr_Bit(DIO_PORTA , (pin_num) );
	}
	
	else if(pin_num < 16)
	{
		Clr_Bit(DIO_PORTB , (pin_num-8) );
	}
	
	else if(pin_num < 24)
	{
		Clr_Bit(DIO_PORTC , (pin_num-16) );
	}
	
	else if(pin_num < 32)
	{
		Clr_Bit(DIO_PORTD , (pin_num-24) );
	}
	
	else
		return ;
		
}

/*************************************************/

void Dio_ClrPinDir(u8 pin_num)
{
	if(pin_num < 8)
	{
		Clr_Bit(DIO_DDRA , (pin_num) );
	}
	
	else if(pin_num < 16)
	{
		Clr_Bit(DIO_DDRB , (pin_num-8) );
	}
	
	else if(pin_num < 24)
	{
		Clr_Bit(DIO_DDRC , (pin_num-16) );
	}
	
	else if(pin_num < 32)
	{
		Clr_Bit(DIO_DDRD , (pin_num-24) );
	}
	
	else
	return ;
	
}

/*************************************************/

void Dio_TogPin(u8 pin_num)
{
	if(pin_num < 8)
	{
		Tog_Bit(DIO_PORTA , (pin_num) ); 
	}
	
	if(pin_num < 16)
	{
		Tog_Bit(DIO_PORTB , (pin_num-8) );
	}
	
	if(pin_num < 24)
	{
		Tog_Bit(DIO_PORTC , (pin_num-16) );
	}
	
	if(pin_num < 32)
	{
		Tog_Bit(DIO_PORTD , (pin_num-24) );
	}
	
	else
		return ;
		
}

/*************************************************/
