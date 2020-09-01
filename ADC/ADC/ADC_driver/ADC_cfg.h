/*
 * ADC_confg.h
 *
 * Created: 9/27/2019 2:32:21 PM
 *  Author: Louda
 */ 


#ifndef ADC_CONFG_H_
#define ADC_CONFG_H_



#define DIVISION_FACTOR		ADC_DIV8			// you can use the following eqation to determine your proper division_factor  ( ( F_CPU / 150,000 ) )
#define LEFT_AJUSTED_ON		ON					//  LEFT_AJUSTED_ON = 1 then we use it 		
#define ADC_MAX_VOLT_REF	ADC_EXTERNAL_AREF		// this option is for user to define which VREF he'd like




#endif /* ADC_CONFG_H_ */