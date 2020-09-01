/*
 * UART_driver.c
 *
 * Created: 9/25/2019 12:05:13 PM
 *  Author: Louda
 */ 


#include "UART_driver/UART_int.h"
#include <util/delay.h>


u8 str[100] = "--> Please Enter Your test code :- ";


void ISR0 (void)
{
	UART_voidTransmitChar(13);
	UART_voidTransmitStr(str);
}

void ISR1 (void)
{
	DIO_PORTA = UART_u8ReceiveChar();
}


int main(void)
{
	
	
	
	UART_voidInit();
	
  	 UART_voidTxISR( ISR0 );
	 UART_voidRxISR( ISR1 );
	 
 	SetGlobalInt(); 	
		
    while(1)
    {	
		
    }
}


