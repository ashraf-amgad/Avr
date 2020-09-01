/*
 * I2C_confg.h
 *
 * Created: 9/28/2019 6:30:07 PM
 *  Author: Louda
 */ 


#ifndef I2C_CONFG_H_
#define I2C_CONFG_H_

// i didn't use it but i configured it to use in the near future.
#define I2C_TWSR_MASK					  (0xF8)

#define I2C_MODE_WRITE						0
#define I2C_MODE_READ						1

#define I2C_MODE_MASTER						1
#define I2C_MODE_SlAVE						0				
#define I2C_MODE_MASTER_SLAVE			I2C_MODE_MASTER

#define I2C_SLAVE_0_ADDRESS				   (0x01)

//  0x22 is just an example
#if (I2C_MODE_MASTER_SLAVE == I2C_MODE_SlAVE)
	#define I2C_MODE_SLAVE_ADDRESS				  (0x22)	
#endif 
		



#endif /* I2C_CONFG_H_ */