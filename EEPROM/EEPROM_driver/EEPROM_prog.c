/*
 * EEPROM_prog.c
 *
 * Created: 9/24/2019 12:37:53 PM
 *  Author: Louda
 */ 

#include "EEPROM_int.h"


void EEPROM_voidinit(void)
{
	
}


void EEPROM_voidWriteData(u8 data , u16 address)
{
	
	while(EEPROM_CONTROL_REG & (1<<EEPROM_WRITE_ENABLE) );
	
	EEPROM_DATA_REG = data;
	
	EEPROM_ADDRESS_REG_LOW  = (u8)(address);
	EEPROM_ADDRESS_REG_HIGH = (u8)(address >> 8);
	
	EEPROM_CONTROL_REG = EEPROM_INIT_WRITING;
	EEPROM_CONTROL_REG = EEPROM_WRITING_ENABLE;
}


u8 EEPROM_u8ReadData(u16 address)
{
	
	while(EEPROM_CONTROL_REG & (1<<EEPROM_WRITE_ENABLE) );
	
	EEPROM_ADDRESS_REG_LOW  = (u8)(address);
	EEPROM_ADDRESS_REG_HIGH = (u8)(address >> 8);
	
	EEPROM_CONTROL_REG = EEPROM_READING_ENALBLE;
	
	return EEPROM_DATA_REG;
}


void EEPROM_voidWriteStr(u8* str , u16 address)
{
	u8 i=0;
	
	while(str[i] != '\0')
	{
		EEPROM_voidWriteData(str[i] ,address);
		address++;
		i++;
	}
	
}


void EEPROM_voidWriteArray(u8* Array ,u8 Array_Size ,u16 address)
{
	u8 i=0;
	
	while( i<Array_Size )
	{
		EEPROM_voidWriteData (Array[i] ,address);
		address++;
		i++;
	}
}
