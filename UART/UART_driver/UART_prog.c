/*
 * UART_prog.c
 *
 * Created: 9/25/2019 12:06:58 PM
 *  Author: Louda
 */ 
#include "UART_int.h"


void (*Tx_ISR_fptr)(void) = '\0';
void (*Rx_ISR_fptr)(void) = '\0';


void UART_voidInit(void)
{
	DIO_voidInit();
	
	DIO_voidSetPinDir(UART_TX_PIN);
	DIO_voidClrPinDir(UART_RX_PIN);
	
	
	UART_UBRRL = (u8)UART_UBRR;
	UART_UBRRH = (u8)(UART_UBRR >> 8);
	
	UART_UCSRB &= ~(1<<UART_UCSRB_UCSZ2);			// 8_bit mode
	UART_UCSRC &= ~(1<<UART_UCSRC_UMSEL);			// Async mode
	
	
	#if (UART_TX_INIT == UART_INIT)
		UART_UCSRB |= (1<<UART_UCSRB_TXE);	
	#endif
	
	#if (UART_RX_INIT == UART_INIT)
		UART_UCSRB |= (1<<UART_UCSRB_RXE);
	#endif
	
	
	#if (UART_TX_INT_INIT == UART_INIT)
		UART_UCSRB |= (1<<UART_UCSRB_TXCIE);
	#endif
	
	#if (UART_RX_INT_INIT == UART_INIT)
		UART_UCSRB |= (1<<UART_UCSRB_RXCIE);
	#endif
	
	#if (UART_TX_DATA_REG_EMPTY_INT_INIT == UART_INIT)
		UART_UCSRB |= (1<<UART_UCSRB_UDREIE);
	#endif
	
	#if (UART_DATA_SIZE == UART_Data_Size_5_BITS)
		UART_UCSRC &= ~(1<<UART_UCSRC_UCSZ0);
		UART_UCSRC &= ~(1<<UART_UCSRC_UCSZ1);
		UART_UCSRB &= ~(1<<UART_UCSRB_UCSZ2);
		
	#elif (UART_DATA_SIZE == UART_Data_Size_6_BITS)
		UART_UCSRC |= (1<<UART_UCSRC_UCSZ0);
		UART_UCSRC &= ~(1<<UART_UCSRC_UCSZ1);
		UART_UCSRB &= ~(1<<UART_UCSRB_UCSZ2);
		
		
	#elif (UART_DATA_SIZE == UART_Data_Size_7_BITS)
		UART_UCSRC &= ~(1<<UART_UCSRC_UCSZ0);
		UART_UCSRC |= (1<<UART_UCSRC_UCSZ1);
		UART_UCSRB &= ~(1<<UART_UCSRB_UCSZ2);
		
	#else			// (UART_DATA_SIZE == UART_Data_Size_8_BITS)
		UART_UCSRC |= (1<<UART_UCSRC_UCSZ0);
		UART_UCSRC |= (1<<UART_UCSRC_UCSZ1);
		UART_UCSRB &= ~(1<<UART_UCSRB_UCSZ2);

	#endif	
			
			
			
	#if (UART_PARITY == UART_DISABLE_PARITY)
		UART_UCSRC &= ~(1<<UART_UCSRC_UPM0);
		UART_UCSRC &= ~(1<<UART_UCSRC_UPM1);
		
	#elif (UART_PARITY == UART_EVEN_PARITY)
		UART_UCSRC &= ~(1<<UART_UCSRC_UPM0);
		UART_UCSRC |= (1<<UART_UCSRC_UPM1);
	
	#elif (UART_PARITY == UART_ODD_PARITY)
		UART_UCSRC |= (1<<UART_UCSRC_UPM0);
		UART_UCSRC |= (1<<UART_UCSRC_UPM1);
	#endif		
			
			
	#if (UART_STOP_BITS_SIZE == UART_1_STOP_BIT)
		UART_UCSRC &= ~(1<<UART_UCSRC_USBSEL);
		
	#elif (UART_STOP_BITS_SIZE == UART_2_STOP_BIT)
	UART_UCSRC |= (1<<UART_UCSRC_USBSEL);
	#endif		
			
}

void UART_voidTransmitChar(u8 ch)
{
	while( (UART_UCSRA & (1<<UART_UCSRA_UDRE)) == 0);		// wait empty buffer
	UART_UDR = ch;
}


u8 UART_u8ReceiveChar(void)
{
	while( !(UART_UCSRA & (1<<UART_UCSRA_RXC)) );		
	return UART_UDR;
}


void UART_voidTransmitStr(u8* str)
{	
	u8 i=0;
	
	while( str[i] != '\0')
	{
		UART_voidTransmitChar(str[i]);
		i++;
	}		
}


void UART_voidReceiveStr(u8* buffer)
{
	u8 i=0;
	
	while (buffer[i-1] != '\r')			// != new line ---- != enter key
	{
		buffer[i] = UART_u8ReceiveChar();
		i++;
	}
	buffer[i] = '\0';
	
} 

void SetGlobalInt(void)
{
	asm ("sei");
}



void UART_voidTxISR( void (*Tx_ISR)(void) )
{
	Tx_ISR_fptr = Tx_ISR;
}

void UART_voidRxISR( void (*Rx_ISR)(void) )
{
	Rx_ISR_fptr = Rx_ISR;
}


  
ISR (USART_UDRE_vect)
{
	Tx_ISR_fptr();
}

ISR (USART_RXC_vect)
{
	Rx_ISR_fptr();
}

// void UART_UDRE_vect(void)
// {
// 	Tx_ISR_fptr();
// }
// 
// void UART_RXC_vect(void)
// {
// 	Rx_ISR_fptr();
// }