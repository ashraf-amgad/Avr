/******************************************
 * I2C_prog.c
 *
 * Created: 9/28/2019 6:29:47 PM
 *  Author: Louda
 ******************************************/ 
 #include "I2C_int.h"
 
 
 void I2C_voidinit(void)
 {
     I2C_TWSR  = 0x00;			// Pre_Scaler to 0
     I2C_TWBR  = 0x02;
    
     #if (I2C_MODE_MASTER_SLAVE == I2C_MODE_MASTER)
        I2C_TWCR |= ( (1<<I2C_TWCR_TWEN) | (1<<I2C_TWCR_TWIE));
    #else
        I2C_TWCR = I2C_MODE_SLAVE_ADDRESS;
        I2C_TWCR |= (1<<I2C_TWCR_TWINT) | (1<<I2C_TWCR_TWEN) | (1<<I2C_TWCR_TWEA);
    #endif
     
 } 
 
 
 void I2C_voidStart(void)
 {
     I2C_TWCR |= ( (1<<I2C_TWCR_TWINT) | (1<<I2C_TWCR_TWSTART) | (1<<I2C_TWCR_TWEN));
     while ( (I2C_TWCR & (1<<I2C_TWCR_TWINT) ) == 0);
 }
 
 
void I2C_voidSendData(u8 Data)
{
     I2C_TWDR = Data;
	 
     #if (I2C_MODE_MASTER_SLAVE == I2C_MODE_SlAVE)
		I2C_TWCR |= ( (1<<I2C_TWCR_TWINT) | (1<<I2C_TWCR_TWEA) | (1<<I2C_TWCR_TWEN));
 	#else
 		I2C_TWCR |= ( (1<<I2C_TWCR_TWINT) | (1<<I2C_TWCR_TWEN));
 	#endif  
	
	 while ( (I2C_TWCR & (1<<I2C_TWCR_TWINT) ) == 0);         
}
 

 u8 I2C_u8RecieveData(void)
 {
     u8 temp_data=0;
	 
	 #if (I2C_MODE_MASTER_SLAVE == I2C_MODE_SlAVE)
		I2C_TWCR |= ( (1<<I2C_TWCR_TWINT) | (1<<I2C_TWCR_TWEA) | (1<<I2C_TWCR_TWEN));
 	#else
 		I2C_TWCR |= ( (1<<I2C_TWCR_TWINT) | (1<<I2C_TWCR_TWEN));
 	#endif
        
     while ( (I2C_TWCR & (1<<I2C_TWCR_TWINT) ) == 0);
     temp_data = I2C_TWDR;
         
    return temp_data;
 }
 
 
void I2C_voidStop(void)
{
     I2C_TWCR |= ( (1<<I2C_TWCR_TWINT) | (1<<I2C_TWCR_TWEN) | (1<<I2C_TWCR_TWSTOP));
}
 
 
void I2C_voidListen(void)
{
     while ( (I2C_TWCR & (1<<I2C_TWCR_TWINT) ) == 0);
}
 
 
void I2C_voidSetupSend(u8 data)
{
     I2C_TWDR = data;
     I2C_TWCR |= ( (1<<I2C_TWCR_TWINT) | (1<<I2C_TWCR_TWEN) );
     while ( (I2C_TWCR & (1<<I2C_TWCR_TWINT) ) == 0);
}
 
 
 
void I2C_voidSendAddress(u8 Address , u8 read_write)
{
	 u8 temp_address=0;
	 
	 if (read_write == I2C_MODE_WRITE)
		 temp_address = ((Address<<1) | 0x00);					// set bit 0 of address you want to send to 1 (read mode).
	 else
		temp_address  =  ((Address<<1) | 0x01);					// set bit 0 of address you want to send to 1 (read mode).
     
	 I2C_voidSetupSend(temp_address);
}
 