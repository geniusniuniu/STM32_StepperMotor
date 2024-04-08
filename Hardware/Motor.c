#include "stm32f10x.h"
#include "motor.h"
#include "delay.h"

/*
使用定时器翻转引脚
Timer3
PA6->DIR;PA5->PWM;
Timer2
PA4->DIR;PA3->PWM;
*/


void Motor_Init(void)
{
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
  GPIO_InitTypeDef  GPIO_InitStructure;
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6|GPIO_Pin_5|GPIO_Pin_4|GPIO_Pin_3;  
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
  GPIO_SetBits(GPIOA, GPIO_Pin_6 |GPIO_Pin_5 | GPIO_Pin_4| GPIO_Pin_3);	

}


//使用while循环翻转GPIO口
//GPIO_Pin_3 ->  Dir
//GPIO_Pin_4 ->  Pulse
//方向，圈数，速度，细分数。
void Motor_Run(u8 Dir, u8 Circle_Num, u16 Speed, int Micro_Step)
{
    int i = 0;
    int Circle_Pulse = 720/(1.8/Micro_Step);    //电平翻转两次是一个脉冲
    if(Dir == CW)
        GPIO_SetBits(GPIOA,GPIO_Pin_3);
    else
       GPIO_ResetBits(GPIOA,GPIO_Pin_3); 
    
    for(i=0; i<=(Circle_Num * Circle_Pulse); i++)
    {
        Delay_us(Speed);        //时间间隔越小速度越快？？？？？？
        GPIOA->ODR ^= GPIO_Pin_4;  
    }
}




















