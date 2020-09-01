/*
 * DIO_int.h
 *
 * Created: 9/11/2019 9:18:22 AM
 *  Author: Louda
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "types.h"
#include "utils.h"
#include "Dio_cfg.h"




#define HIGH		1
#define LOW			0

#define IN			0
#define OUT			1



#define conc(x7 ,x6 ,x5 ,x4 ,x3 ,x2 ,x1 ,x0)           conchelper(x7 ,x6 ,x5 ,x4 ,x3 ,x2 ,x1 ,x0)
#define conchelper(x7 ,x6 ,x5 ,x4 ,x3 ,x2 ,x1 ,x0)     0b##x7##x6##x5##x4##x3##x2##x1##x0


#define DIO_PORTA_INITDIR         conc(PORTA_PIN7_INITDIR ,PORTA_PIN6_INITDIR ,PORTA_PIN5_INITDIR ,PORTA_PIN4_INITDIR ,PORTA_PIN3_INITDIR ,PORTA_PIN2_INITDIR ,PORTA_PIN1_INITDIR ,PORTA_PIN0_INITDIR)
#define DIO_PORTB_INITDIR         conc(PORTB_PIN7_INITDIR ,PORTB_PIN6_INITDIR ,PORTB_PIN5_INITDIR ,PORTB_PIN4_INITDIR ,PORTB_PIN3_INITDIR ,PORTB_PIN2_INITDIR ,PORTB_PIN1_INITDIR ,PORTB_PIN0_INITDIR)
#define DIO_PORTC_INITDIR         conc(PORTC_PIN7_INITDIR ,PORTC_PIN6_INITDIR ,PORTC_PIN5_INITDIR ,PORTC_PIN4_INITDIR ,PORTC_PIN3_INITDIR ,PORTC_PIN2_INITDIR ,PORTC_PIN1_INITDIR ,PORTC_PIN0_INITDIR)
#define DIO_PORTD_INITDIR         conc(PORTD_PIN7_INITDIR ,PORTD_PIN6_INITDIR ,PORTD_PIN5_INITDIR ,PORTD_PIN4_INITDIR ,PORTD_PIN3_INITDIR ,PORTD_PIN2_INITDIR ,PORTD_PIN1_INITDIR ,PORTD_PIN0_INITDIR)

#define DIO_PORTA_INITVAL         conc(PORTA_PIN7_INITVAL ,PORTA_PIN6_INITVAL ,PORTA_PIN5_INITVAL ,PORTA_PIN4_INITVAL ,PORTA_PIN3_INITVAL ,PORTA_PIN2_INITVAL ,PORTA_PIN1_INITVAL ,PORTA_PIN0_INITVAL)
#define DIO_PORTB_INITVAL         conc(PORTB_PIN7_INITVAL ,PORTB_PIN6_INITVAL ,PORTB_PIN5_INITVAL ,PORTB_PIN4_INITVAL ,PORTB_PIN3_INITVAL ,PORTB_PIN2_INITVAL ,PORTB_PIN1_INITVAL ,PORTB_PIN0_INITVAL)
#define DIO_PORTC_INITVAL         conc(PORTC_PIN7_INITVAL ,PORTC_PIN6_INITVAL ,PORTC_PIN5_INITVAL ,PORTC_PIN4_INITVAL ,PORTC_PIN3_INITVAL ,PORTC_PIN2_INITVAL ,PORTC_PIN1_INITVAL ,PORTC_PIN0_INITVAL)
#define DIO_PORTD_INITVAL         conc(PORTD_PIN7_INITVAL ,PORTD_PIN6_INITVAL ,PORTD_PIN5_INITVAL ,PORTD_PIN4_INITVAL ,PORTD_PIN3_INITVAL ,PORTD_PIN2_INITVAL ,PORTD_PIN1_INITVAL ,PORTD_PIN0_INITVAL)




#define  DIO_PORTA     (*(volatile u8*)(0x3B))
#define  DIO_DDRA      (*(volatile u8*)(0x3A))
#define  DIO_PINA      (*(volatile u8*)(0x39))

#define  DIO_PORTB     (*(volatile u8*)(0x38))
#define  DIO_DDRB      (*(volatile u8*)(0x37))
#define  DIO_PINB      (*(volatile u8*)(0x36))



#define  DIO_PORTC     (*(volatile u8*)(0x35))
#define  DIO_DDRC      (*(volatile u8*)(0x34))
#define  DIO_PINC      (*(volatile u8*)(0x33))



#define  DIO_PORTD     (*(volatile u8*)(0x32))
#define  DIO_DDRD      (*(volatile u8*)(0x31))
#define  DIO_PIND      (*(volatile u8*)(0x30))



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





void Dio_Init(void);
u8 Dio_ReadPinVal(u8 pin_num);
u8 Dio_ReadPinDir(u8 pin_num);
void Dio_SetPin(u8 pin_num);
void Dio_ClrPin(u8 pin_num);
void Dio_TogPin(u8 pin_num);
void Dio_SetPinDir(u8 pin_num);
void Dio_ClrPinDir(u8 pin_num);	


#endif /* DIO_H_ */