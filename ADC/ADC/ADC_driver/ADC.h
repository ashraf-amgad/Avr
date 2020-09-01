/*
 * ADC_int.h
 *
 * Created: 9/27/2019 2:32:09 PM
 *  Author: Louda
 */ 


#ifndef ADC_INT_H_
#define ADC_INT_H_

#include "../Dio_driver/Dio.h"
#include "../Dio_driver/types.h"
#include "../Dio_driver/utils.h"
#include "ADC_cfg.h"



#define OFF				0
#define ON				1

#define ADC_DIV2		2
#define ADC_DIV4		3
#define ADC_DIV8		4
#define ADC_DIV16		5
#define ADC_DIV32		6
#define ADC_DIV64		7
#define ADC_DIV128		8

#define ADC_CH_0		9
#define ADC_CH_1		10
#define ADC_CH_2		11
#define ADC_CH_3		12
#define ADC_CH_4		13
#define ADC_CH_5		14
#define ADC_CH_6		15
#define ADC_CH_7		16


#define ADC_EXTERNAL_AREF	17
#define ADC_INTERNAL_AVCC	18			// using AVCC pin as VREF but you should use capacitor on pin AREF  //  AVCC with external capacitor at AREF pin
#define ADC_INTENAL_AREF	19			// Internal 2.56V Voltage Reference with external capacitor at AREF pin


#define  ADC_PORT			DIO_PORTA

#define ADC_ADMUX		(*(volatile u8*)(0x27))
#define ADC_ADCSRA		(*(volatile u8*)(0x26))
#define ADC_ADCH		(*(volatile u8*)(0x25))
#define ADC_ADCL		(*(volatile u8*)(0x24))
#define ADC_SFIOR		(*(volatile u8*)(0x50))


#define ADC_ADMUX_MUX0		0
#define ADC_ADMUX_MUX1		1
#define ADC_ADMUX_MUX2		2
#define ADC_ADMUX_MUX3		3
#define ADC_ADMUX_MUX4		4
#define ADC_ADMUX_ADLAR		5
#define ADC_ADMUX_REFS0		6
#define ADC_ADMUX_REFS1		7


#define ADC_ADCSRA_ADPS0	0
#define ADC_ADCSRA_ADPS1	1
#define ADC_ADCSRA_ADPS2	2
#define ADC_ADCSRA_ADIE		3
#define ADC_ADCSRA_ADIF		4
#define ADC_ADCSRA_ADATE	5
#define ADC_ADCSRA_ADSC		6
#define ADC_ADCSRA_ADEN		7





void ADC_Init(void);
void ADC_StartConv(void);
void ADC_WaitConv(void);
void ADC_SetGlobalInt(void);
u16 ADC_GetData_16t(void);
u8 ADC_GetData_8t(void);
f32 ADC_Adc2Volt(u16 adc_value , u8 Adc_Volt_Ref);
void ADC_SetupISR(u8 ADC_CHANNAL ,void (*ADC_INT_FUN)() );





#endif /* ADC_INT_H_ */