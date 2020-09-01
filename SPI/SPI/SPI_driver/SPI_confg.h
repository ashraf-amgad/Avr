/*
 * SPI_confg.h
 *
 * Created: 9/25/2019 7:02:21 PM
 *  Author: Louda
 */ 


#ifndef SPI_CONFG_H_
#define SPI_CONFG_H_
	
#define SPI_MASTER								0
#define SPI_SLAVE								1
#define SPI_MODE_MASTER_SLAVE					SPI_MASTER
	
#define SPI_CLKRATE_F_4							0
#define SPI_CLKRATE_F_16						1
#define SPI_CLKRATE_F_64						2
#define SPI_CLKRATE_F_128						3
#define SPI_CLKRATE_F_2_DOUBLE_SPEED			4
#define SPI_CLKRATE_F_8_DOUBLE_SPEED			5
#define SPI_CLKRATE_F_32_DOUBLE_SPEED			6
#define SPI_CLKRATE_F_64_DOUBLE_SPEED			7
#define SPI_MODE_CLKRATE						SPI_CLKRATE_F_128

#define SPI_LEAST_BITS_FIRST					0
#define SPI_MOST_BITS_FIRST						1
#define SPI_MODE_DATA_ORDER						SPI_LEAST_BITS_FIRST


#define SPI_INT_EN								1
#define SPI_INT_DISABLE							0
#define SPI_MODE_INT_EN							SPI_INT_EN

/**************************************************************************************
 * for the coming config please see the configuration of SPI debug module on Proteus. *
 * and also revise data sheet.
***************************************************************************************/

#define SPI_CLK_IDLE_STATE_LOW					0
#define SPI_CLK_IDLE_STATE_HIGH					1
#define SPI_MODE_CLK_IDL_STATE					SPI_CLK_IDLE_STATE_HIGH

#define SPI_SAMPLE_EDGE_IDLE_ACTIVE					0
#define SPI_SAMPLE_EDGE_ACTIVE_IDLE					1
#define SPI_MODE_SAMPLE_EDGE					SPI_SAMPLE_EDGE_IDLE_ACTIVE		


#endif /* SPI_CONFG_H_ */