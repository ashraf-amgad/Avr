/*
 * EEPROM_priv.h
 *
 * Created: 9/24/2019 12:38:29 PM
 *  Author: Louda
 */ 


#ifndef EEPROM_PRIV_H_
#define EEPROM_PRIV_H_


#define EEPROM_ADDRESS_REG_HIGH			(*(volatile u8*)(0x3F))
#define EEPROM_ADDRESS_REG_LOW			(*(volatile u8*)(0x3E))
#define EEPROM_DATA_REG					(*(volatile u8*)(0x3D))
#define EEPROM_CONTROL_REG				(*(volatile u8*)(0x3C))
#define DIO_PORTA						(*(volatile u8*)(0x3B))
#define DIO_DDRA						(*(volatile u8*)(0x3A))

#define EEPROM_INIT_WRITING						(0x04)
#define EEPROM_WRITING_ENABLE					(0x06)
#define EEPROM_READING_ENALBLE					(0x01)



#endif /* EEPROM_PRIV_H_ */