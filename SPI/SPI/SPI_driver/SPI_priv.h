/*
 * SPI_priv.h
 *
 * Created: 9/25/2019 7:02:07 PM
 *  Author: Louda
 */ 


#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_

#define SPI_SPCR	(*(volatile u8*)(0x2D))
#define SPI_SPSR	(*(volatile u8*)(0x2E))
#define SPI_SPDR	(*(volatile u8*)(0x2F))


#ifndef DIO_PORTA
	#define DIO_PORTA   (*(volatile u8*)(0x3B))
#endif


#ifndef DIO_DDRB
	#define DIO_DDRB   (*(volatile u8*)(0x37))
#endif

#ifndef DIO_PORTB
	#define DIO_PORTB   (*(volatile u8*)(0x38))
#endif

#ifndef DIO_OUTPUT
	#define DIO_OUTPUT   1
#endif

#ifndef DIO_INPUT
	#define DIO_INPUT   0
#endif


#endif /* SPI_PRIV_H_ */