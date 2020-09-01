/*
 * SPI_prog.c
 *
 * Created: 9/25/2019 7:01:46 PM
 *  Author: Louda
 */ 

#include "SPI_int.h"
#include <avr/interrupt.h>

static volatile void(*fptr)(void);

void SPI_voidinit(void)
{
	
	#if (SPI_MODE_CLK_IDL_STATE == SPI_CLK_IDLE_STATE_LOW)
		SPCR &= ~(1<<SPI_SPCR_CLKPOl);
	#else											//	(SPI_MODE_CLK_IDL_STATE == SPI_CLK_IDLE_STATE_LOW)
		SPCR |= (1<<SPI_SPCR_CLKPOl);
	#endif
		
		/***********************************************/
		
	#if (SPI_MODE_SAMPLE_EDGE == SPI_SAMPLE_EDGE_IDLE_ACTIVE)
		SPCR &= ~(1<<SPI_SPCR_CLKPHA);
	#else											//	(SPI_MODE_SAMPLE_EDGE == SPI_SAMPLE_EDGE_ACTIVE_IDLE)
		SPCR |= (1<<SPI_SPCR_CLKPOl);
	#endif
	
		/***********************************************/
		
 	#if (SPI_MODE_INT_EN == SPI_INT_EN)
 		SPI_SPCR |= (1<<SPI_SPCR_SPIE);
 						
 	#else										// (SPI_MODE_INT_EN == SPI_INT_DISABLE)
 		SPI_SPCR &= ~(1<<SPI_SPCR_SPIE);	
 	#endif
 		
		/***********************************************/
		 
		
	#if (SPI_MODE_MASTER_SLAVE == SPI_MASTER)
		DIO_DDRB |= (1<<SPI_SS);	
		DIO_DDRB |= (1<<SPI_MOSI);
		DIO_DDRB &= ~(1<<SPI_MISO);
		DIO_DDRB |= (1<<SPI_CLK);	
				
		SPI_SPCR |= (1<<SPI_SPCR_MSTR);
   	#else							
		DIO_DDRB &= ~(1<<SPI_SS);	
		DIO_DDRB &= ~(1<<SPI_MOSI);
		DIO_DDRB |= (1<<SPI_MISO);
		DIO_DDRB &= ~(1<<SPI_CLK);
		
		SPI_SPCR &= ~(1<<SPI_SPCR_MSTR); 
	#endif	
	
	/***********************************************/
	
	#if   (SPI_MODE_CLKRATE == SPI_CLKRATE_F_4)
		SPI_SPCR &= ~(1<<SPI_SPCR_CLKRATE_0); 
		SPI_SPCR &= ~(1<<SPI_SPCR_CLKRATE_1); 
		SPI_SPSR &= ~(1<<SPI__SPSR_SPI2X); 
	
	#elif (SPI_MODE_CLKRATE == SPI_CLKRATE_F_16)
		SPI_SPCR |= (1<<SPI_SPCR_CLKRATE_0); 
		SPI_SPCR &= ~(1<<SPI_SPCR_CLKRATE_1); 
		SPI_SPSR &= ~(1<<SPI__SPSR_SPI2X); 
	
	#elif (SPI_MODE_CLKRATE == SPI_CLKRATE_F_64)
		SPI_SPCR &= ~(1<<SPI_SPCR_CLKRATE_0); 
		SPI_SPCR |= (1<<SPI_SPCR_CLKRATE_1); 
		SPI_SPSR &= ~(1<<SPI__SPSR_SPI2X); 
	
	#elif (SPI_MODE_CLKRATE == SPI_CLKRATE_F_128)
		SPI_SPCR |= (1<<SPI_SPCR_CLKRATE_0); 
		SPI_SPCR |= (1<<SPI_SPCR_CLKRATE_1); 
		SPI_SPSR &= ~(1<<SPI__SPSR_SPI2X); 
	
	#elif (SPI_MODE_CLKRATE == SPI_CLKRATE_F_2_DOUBLE_SPEED)
		SPI_SPCR &= ~(1<<SPI_SPCR_CLKRATE_0); 
		SPI_SPCR &= ~(1<<SPI_SPCR_CLKRATE_1); 
		SPI_SPSR |= (1<<SPI__SPSR_SPI2X); 
	
	#elif (SPI_MODE_CLKRATE == SPI_CLKRATE_F_8_DOUBLE_SPEED)
		SPI_SPCR |= (1<<SPI_SPCR_CLKRATE_0); 
		SPI_SPCR &= ~(1<<SPI_SPCR_CLKRATE_1); 
		SPI_SPSR |= (1<<SPI__SPSR_SPI2X); 
	
	#elif (SPI_MODE_CLKRATE == SPI_CLKRATE_F_32_DOUBLE_SPEED)
		SPI_SPCR &= ~(1<<SPI_SPCR_CLKRATE_0); 
		SPI_SPCR |= (1<<SPI_SPCR_CLKRATE_1); 
		SPI_SPSR |= (1<<SPI__SPSR_SPI2X);
	
	#else										// (SPI_MODE_CLKRATE == SPI_CLKRATE_F_64_DOUBLE_SPEED)
		SPI_SPCR |= (1<<SPI_SPCR_CLKRATE_0); 
		SPI_SPCR |= (1<<SPI_SPCR_CLKRATE_1); 
		SPI_SPSR |= (1<<SPI__SPSR_SPI2X); 
	#endif
	
	/***********************************************/
	
	#if (SPI_MODE_DATA_ORDER == SPI_LEAST_BITS_FIRST)
		SPI_SPCR |= (1<<SPI_SPCR_DORD);
	
	#else						// (SPI_MODE_DATA_ORDER == SPI_MOST_BITS_FIRST)
		SPI_SPCR &= ~(1<<SPI_SPCR_DORD);
	#endif 
	
	/***********************************************
		you should enable SPI in the last step 
i found an error with master pin that it's cleared by default if i enable spi then set master pin  
	***********************************************/
	SPI_SPCR |= (1<<SPI_SPCR_SPE);			
}

void SPI_voidTransData(u8 data)
{
	 SPI_SPDR = data;
	 
	 #if ( SPI_MODE_INT_EN == SPI_INT_DISABLE )
		 while(! (SPI_SPSR & (1<<SPI_SPSR_SPIF)) );
	#endif
}


u8 SPI_voidRecieveData(void)
{
	 while(! (SPI_SPSR & (1<<SPI_SPSR_SPIF)) );
	return SPI_SPDR;
}

void SPI_voidSetGlobalInt(void)
{
	asm ("sei");
}

void SPI_voidIntSetup(void (*SPI_INT_FUNC)(void) )
{
	fptr = SPI_INT_FUNC;
}

ISR(SPI_STC_vect)
{
	fptr();
}