/*
 * DIO_int.h
 *
 * Created: 9/11/2019 9:18:22 AM
 *  Author: Louda
 */ 


#ifndef DIO_INT_H_
#define DIO_INT_H_

#include "DIO_priv.h"
#include "types.h"
#include "DIO_utils.h"
#include "DIO_conf.h"


void DIO_voidInit(void);
u8 DIO_u8ReadPinVal(u8 pin_num);
u8 DIO_u8ReadPinDir(u8 pin_num);
void DIO_voidSetPin(u8 pin_num);
void DIO_voidClrPin(u8 pin_num);
void DIO_voidTogPin(u8 pin_num);
void DIO_voidSetPinDir(u8 pin_num);
void DIO_voidClrPinDir(u8 pin_num);
#define  DIO_voidSetPort(reg,val)		(reg = val)		




#define DIO_PORTA_PIN0     0
#define DIO_PORTA_PIN1     1
#define DIO_PORTA_PIN2     2
#define DIO_PORTA_PIN3     3
#define DIO_PORTA_PIN4     4
#define DIO_PORTA_PIN5     5
#define DIO_PORTA_PIN6     6
#define DIO_PORTA_PIN7     7

#define DIO_PORTB_PIN0     8
#define DIO_PORTB_PIN1     9
#define DIO_PORTB_PIN2    10
#define DIO_PORTB_PIN3    11
#define DIO_PORTB_PIN4    12
#define DIO_PORTB_PIN5    13
#define DIO_PORTB_PIN6    14
#define DIO_PORTB_PIN7    15

#define DIO_PORTC_PIN0    16
#define DIO_PORTC_PIN1    17
#define DIO_PORTC_PIN2    18
#define DIO_PORTC_PIN3    19
#define DIO_PORTC_PIN4    20
#define DIO_PORTC_PIN5    21
#define DIO_PORTC_PIN6    22
#define DIO_PORTC_PIN7    23

#define DIO_PORTD_PIN0    24
#define DIO_PORTD_PIN1    25
#define DIO_PORTD_PIN2    26
#define DIO_PORTD_PIN3    27
#define DIO_PORTD_PIN4    28
#define DIO_PORTD_PIN5    29
#define DIO_PORTD_PIN6    30
#define DIO_PORTD_PIN7    31



#endif /* DIO_INT_H_ */