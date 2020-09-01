/*
 * I2C_priv.h
 *
 * Created: 9/28/2019 6:30:36 PM
 *  Author: Louda
 */ 


#ifndef I2C_PRIV_H_
#define I2C_PRIV_H_


#define	I2C_TWBR		(*(volatile u8*)(0x20))
#define	I2C_TWSR		(*(volatile u8*)(0x21))
#define	I2C_TWAR		(*(volatile u8*)(0x22))
#define	I2C_TWDR		(*(volatile u8*)(0x23))
#define	I2C_TWCR		(*(volatile u8*)(0x56))


#ifndef DIO_DDRC
	#define DIO_DDRC		(*(volatile u8*)(0x34))
#endif 

#ifndef DIO_PORTC
	#define DIO_PORTC		(*(volatile u8*)(0x35))
#endif 


#endif /* I2C_PRIV_H_ */