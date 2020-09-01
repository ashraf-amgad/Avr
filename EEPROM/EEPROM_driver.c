/*
 * EEPROM_driver.c
 *
 * Created: 9/24/2019 12:19:10 PM
 *  Author: Louda
 */ 

#include "EEPROM_driver/EEPROM_int.h"
#include <util/delay.h>

int main(void)
{
	DIO_DDRA = 0xFF;
	
	u8*  data    = "ASHRAF";
	u16 address = 0x0000;
	
	u8 ARR[10] = {0,1,2,3,4,5,6,7,8,9};
	
		EEPROM_voidWriteArray(ARR ,10 ,address);
		
		
		u8 i=0;
		address=0;
		
		while(i<0x10)
		{
			DIO_PORTA = EEPROM_u8ReadData(address);
			_delay_ms(5000);
			address++;
			i++;
		}		
}