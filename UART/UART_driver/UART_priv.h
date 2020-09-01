/*
 * UART_priv.h
 *
 * Created: 9/25/2019 12:07:49 PM
 *  Author: Louda
 */ 


#ifndef UART_PRIV_H_
#define UART_PRIV_H_

#define UART_UDR	(*(volatile u8*)(0x2C))
#define UART_UCSRA	(*(volatile u8*)(0x2B))
#define UART_UCSRB	(*(volatile u8*)(0x2A))
#define UART_UCSRC	(*(volatile u8*)(0x40))
#define UART_UBRRH	(*(volatile u8*)(0x40))
#define UART_UBRRL	(*(volatile u8*)(0x29))




#if	(UART_USART == 1)
	#if		(UART_U2X_EN == 0)
		#define UART_UBRR  (F_OSC/16/BAUD_RATE)
		
	#elif	(UART_U2X_EN == 1)
		#define UART_UBRR  ((F_OSC/8/BAUD_RATE)-1)
	#endif

#else
	#define UART_UBRR  ((F_OSC/2/BAUD_RATE)-1)
#endif



#endif /* UART_PRIV_H_ */