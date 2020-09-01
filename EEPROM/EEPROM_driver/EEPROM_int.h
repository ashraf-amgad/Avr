/*
 * EEPROM_int.h
 *
 * Created: 9/24/2019 12:38:45 PM
 *  Author: Louda
 */ 


#ifndef EEPROM_INT_H_
#define EEPROM_INT_H_

#include "EEPROM_conf.h"
#include "EEPROM_types.h"
#include "EEPROM_priv.h"

void EEPROM_voidinit(void);
void EEPROM_voidWriteData(u8 data , u16 address);
u8 EEPROM_u8ReadData(u16 address);
void EEPROM_voidWriteStr(u8* str , u16 address);
void EEPROM_voidWriteArray(u8* Array ,u8 Array_Size ,u16 address);


#endif /* EEPROM_INT_H_ */