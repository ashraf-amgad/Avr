/*
 * UART_int.h
 *
 * Created: 9/25/2019 12:07:19 PM
 *  Author: Louda
 */ 


#ifndef UART_INT_H_
#define UART_INT_H_

#include "DIO_driver/DIO_int.h"
#include "types.h"
#include "UART_priv.h"
#include "UART_confg.h"
#include <avr/interrupt.h>


void UART_voidInit(void);
void UART_voidTransmitChar(u8 ch);
u8 UART_u8ReceiveChar(void);
void UART_voidTransmitStr(u8* str);
void UART_voidReceiveStr(u8* buffer);
void SetGlobalInt(void);
void UART_voidTxISR( void (*Tx_ISR)(void) );
void UART_voidRxISR( void (*Rx_ISR)(void) );
// void UART_UDRE_vect (void) __attribute__ ( (signal) );
// void UART_RXC_vect  (void) __attribute__ ( (signal) );


#define UART_UCSRA_MPCM			0
#define UART_UCSRA_U2X			1
#define UART_UCSRA_PE			2
#define UART_UCSRA_DOR			3
#define UART_UCSRA_FE			4
#define UART_UCSRA_UDRE			5
#define UART_UCSRA_TXC			6
#define UART_UCSRA_RXC			7


#define UART_UCSRB_TXDB8		0
#define UART_UCSRB_RXDB8		1
#define UART_UCSRB_UCSZ2		2
#define UART_UCSRB_TXE			3
#define UART_UCSRB_RXE			4
#define UART_UCSRB_UDREIE		5
#define UART_UCSRB_TXCIE		6
#define UART_UCSRB_RXCIE		7

#define UART_UCSRC_UCPOL		0
#define UART_UCSRC_UCSZ0		1
#define UART_UCSRC_UCSZ1		2
#define UART_UCSRC_USBSEL		3
#define UART_UCSRC_UPM0			4
#define UART_UCSRC_UPM1			5
#define UART_UCSRC_UMSEL		6
#define UART_UCSRC_URSEL		7


#define UART_ENABLE		1
#define UART_DISABLE	0

#define UART_INIT			1
#define UART_UNINIT			0

#define UART_Data_Size_5_BITS		5
#define UART_Data_Size_6_BITS		6
#define UART_Data_Size_7_BITS		7
#define UART_Data_Size_8_BITS		8
/*#define UART_Data_Size_9_BITS		9*/

#define UART_1_STOP_BIT			1
#define UART_2_STOP_BIT			2

#define UART_EVEN_PARITY		0
#define UART_ODD_PARITY			1
#define UART_DISABLE_PARITY		2



#endif /* UART_INT_H_ */