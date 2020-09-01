/*
 * UART_confg.h
 *
 * Created: 9/25/2019 12:07:35 PM
 *  Author: Louda
 */ 


#ifndef UART_CONFG_H_
#define UART_CONFG_H_


#ifndef F_CPU
	#define F_CPU	1000000UL
#endif

#define F_OSC			F_CPU
#define BAUD_RATE		19200


#define UART_DATA_SIZE				UART_Data_Size_8_BITS

#define UART_STOP_BITS_SIZE			UART_1_STOP_BIT

#define UART_PARITY					UART_DISABLE_PARITY



#define UART_RX_INIT		UART_INIT
#define UART_TX_INIT		UART_INIT

#define UART_RX_INT_INIT					UART_INIT
#define UART_TX_INT_INIT					UART_INIT
#define UART_TX_DATA_REG_EMPTY_INT_INIT		UART_INIT

#define UART_RX_PIN			DIO_PORTD_PIN0	
#define UART_TX_PIN			DIO_PORTD_PIN1



#endif /* UART_CONFG_H_ */