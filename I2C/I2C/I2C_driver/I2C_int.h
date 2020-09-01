/*
 * I2C_int.h
 *
 * Created: 9/28/2019 6:30:21 PM
 *  Author: Louda
 */ 


#ifndef I2C_INT_H_
#define I2C_INT_H_

#include "I2C_confg.h"
#include "I2C_priv.h"
#include "I2C_types.h"

void I2C_voidinit(void);
void I2C_voidStart(void);
void I2C_voidSendData(u8 Data);
u8 I2C_u8RecieveData(void);
void I2C_voidStop(void);
void I2C_voidListen(void);
void I2C_voidSetupSend(u8 data);
void I2C_voidSendAddress(u8 Address , u8 read_write);
  




#define I2C_TWCR_TWIE				0
//#define I2C_TWCR_RESERVED			1
#define I2C_TWCR_TWEN				2
#define I2C_TWCR_TWWC				3
#define I2C_TWCR_TWSTOP				4
#define I2C_TWCR_TWSTART			5
#define I2C_TWCR_TWEA				6
#define I2C_TWCR_TWINT				7

#define I2C_TWSR_TWPS0				0
#define I2C_TWSR_TWPS1				1

#endif /* I2C_INT_H_ */