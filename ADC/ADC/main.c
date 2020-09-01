/*
 * ADC_driver.c
 *
 * Created: 9/27/2019 2:31:02 PM
 *  Author: Louda
 */ 

#include "ADC_driver/ADC.h"



void ADC_CH0_func (void)
{
 	u8 temp = ADC_GetData_8t();
 	DIO_PORTB = temp;
	
	/*ADC_voidWaitConv();*/
}


void ADC_CH1_func (void)
{
 	u8 temp = ADC_GetData_8t();
 	DIO_PORTD = temp;
	
	/*ADC_voidWaitConv();*/
}


int main(void)
{
	Dio_Init();
	
	ADC_Init();
	ADC_SetupISR(ADC_CH_0 ,ADC_CH0_func);
	ADC_SetupISR(ADC_CH_1 ,ADC_CH1_func);
	ADC_Adc2Volt(512 ,5);
	ADC_SetGlobalInt();
	ADC_StartConv();
	
    while(1);
	
}