

#include "timer_driver/timer.h"
#include "Dio_driver/Dio.h"


 void ToggleLED(void)
 {
 	DIO_PORTA ^= (0x01);
 }





int main(void)
{
	Dio_Init();
	Timer_Init();
	
	Timer_EnableInterrupt(TIMER_TIMSK_OCIE0);
    Timer_SetCompareMatch_ISR(TIMER_0 ,ToggleLED);
	Timer_LoadOCR(TIMER_0 ,125);
	//Pwm_SetDutyCycle(TIMER_0 ,1);
	Pwm_Volt2DutyCycle(TIMER_2 ,1.2);
	
    asm("sei");
	
    while(1);
 
}
