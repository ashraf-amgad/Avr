/*
 * I2C_driver.c
 *
 * Created: 9/28/2019 6:28:45 PM
 *  Author: Louda
 */ 

#include "I2C_driver/I2C_int.h"
#include <avr/delay.h>

int main(void)
{
	u8 i=0;
	
	I2C_voidinit();
	I2C_voidStart();
	I2C_voidSendAddress(I2C_SLAVE_0_ADDRESS ,I2C_MODE_WRITE);
	
    while(1)
    {
 		I2C_voidSendData(i);
 		i++;
 		if(i == 9)
 			I2C_voidStop();
    }
}