#ifndef __MOTOR_H
#define __MOTOR_H

#define CW   0      //À≥ ±’Î
#define CCW  1

#define IN3(x) GPIO_WriteBit(GPIOA,GPIO_Pin_3,(BitAction)(x))
#define IN4(x) GPIO_WriteBit(GPIOA,GPIO_Pin_4,(BitAction)(x))
#define IN5(x) GPIO_WriteBit(GPIOA,GPIO_Pin_5,(BitAction)(x))
#define IN6(x) GPIO_WriteBit(GPIOA,GPIO_Pin_6,(BitAction)(x))

void Motor_Init(void);
void Motor_Run(u8 Dir, u8 Circle_Num, u16 Speed, int Micro_Step);

#endif
