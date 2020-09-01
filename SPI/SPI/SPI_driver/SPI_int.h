/*
 * SPI_int.h
 *
 * Created: 9/25/2019 7:01:56 PM
 *  Author: Louda
 */ 


#ifndef SPI_INT_H_
#define SPI_INT_H_


#include "SPI_priv.h"
#include "SPI_types.h"
#include "SPI_confg.h"


void SPI_voidinit(void);
void SPI_voidTransData(u8 data);
u8 SPI_voidRecieveData(void);
void SPI_voidSetGlobalInt(void);
void SPI_voidIntSetup(void (*SPI_INT_FUNC)(void) );

#define SPI_SS		4
#define SPI_MOSI	5
#define SPI_MISO	6
#define SPI_CLK		7


#define SPI_SPCR_CLKRATE_0	0
#define SPI_SPCR_CLKRATE_1	1
#define SPI_SPCR_CLKPHA		2
#define SPI_SPCR_CLKPOl		3
#define SPI_SPCR_MSTR		4
#define SPI_SPCR_DORD		5
#define SPI_SPCR_SPE		6
#define SPI_SPCR_SPIE		7

#define SPI_SPSR_SPIF		7
#define SPI_SPSR_WCOL		6
#define SPI__SPSR_SPI2X		0



#endif /* SPI_INT_H_ */