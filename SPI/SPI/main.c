/*
 * SPI_driver.c
 *
 * Created: 9/25/2019 7:00:55 PM
 *  Author: Louda
 */ 

#include "SPI_driver/SPI_int.h"
#include <util/delay.h>



void SPI_test_int(void)
{
	u8 i=0;
	DIO_PORTB ^= 0x01;
}


int main(void)
{
	DIO_DDRB  |=  0x01;
	DIO_PORTB &= ~(0x01);
	u8 i=0;
	
	SPI_voidinit();
	SPI_voidIntSetup(SPI_test_int);
	SPI_voidSetGlobalInt();
 
    while(1)
    { 
		SPI_voidTransData(i);
		i++;
		_delay_ms(1000);
    }
	
	return 0;
}

