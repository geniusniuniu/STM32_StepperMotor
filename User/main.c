#include "stm32f10x.h"                  // Device header
#include "Motor.h"
#include "delay.h"
#include "LED.h"

int main(void)
{	
	Motor_Init();
    LED_Init();
//	Timer3_Init();
//	TIM_SetAutoreload(TIM3, 100-1);
//	TIM_ARRPreloadConfig(TIM3, ENABLE);
//	TIM_PrescalerConfig(TIM3,360-1,TIM_PSCReloadMode_Update);
	while (1)
	{		
        Motor_Run(0, 5, 1000,4);
//        GPIO_SetBits(GPIOC,GPIO_Pin_13);
        Delay_ms(1000);
        Motor_Run(1, 5, 800 ,4);
//        GPIO_ResetBits(GPIOC,GPIO_Pin_13);
        Delay_ms(1000);
	}
}




