#include "stm32f10x.h"                  // Device header
#include "PWM.h"

//电机初始化
void Motor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure1;
	GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出模式
	GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure1);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure2;
	GPIO_InitStructure2.GPIO_Mode = GPIO_Mode_Out_PP;//推挽输出模式
	GPIO_InitStructure2.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6;
	GPIO_InitStructure2.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure2);
	
	PWM_Init();
}

//设置左前电机速度
void Motor_SetLeft1Speed(int8_t Speed)
{
	if (Speed >0)							//正转
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_4);	//PA4置高电平
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);	//PA5置低电平，设置方向为正转
		PWM_SetCompare1(Speed);				//PWM设置为速度值
	}
	else if(Speed==0)						//停止
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_4);	//PA4置高电平
		GPIO_SetBits(GPIOA, GPIO_Pin_5);	//PA5置高电平，停止
		PWM_SetCompare1(Speed);
	}
	else									//反转
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_4);	//PA4置低电平
		GPIO_SetBits(GPIOA, GPIO_Pin_5);	//PA5置高电平，设置方向为反转
		PWM_SetCompare1(-Speed);
	}
}

//设置左后电机速度
void Motor_SetLeft2Speed(int8_t Speed)
{
	if (Speed >0)							//正转
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_6);	//PA6置高电平
		GPIO_ResetBits(GPIOA, GPIO_Pin_7);	//PA7置低电平，设置方向为正转
		PWM_SetCompare2(Speed);				//PWM设置为速度值
	}
	else if(Speed==0)						//停止
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_6);	//PA6置高电平
		GPIO_SetBits(GPIOA, GPIO_Pin_7);	//PA7置高电平，停止
		PWM_SetCompare2(Speed);
	}
	else									//反转
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_6);	//PA6置低电平
		GPIO_SetBits(GPIOA, GPIO_Pin_7);	//PA7置高电平，设置方向为反转
		PWM_SetCompare2(-Speed);
	}
}

//设置右前电机速度
void Motor_SetRight1Speed(int8_t Speed)
{
	if (Speed >0)							//正转
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_3);	//PB3置高电平
		GPIO_ResetBits(GPIOB, GPIO_Pin_4);	//PB4置低电平，设置方向为正转
		PWM_SetCompare3(Speed);				//PWM设置为速度值
	}
	else if(Speed==0)						//停止
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_3);	//PB3置高电平
		GPIO_SetBits(GPIOB, GPIO_Pin_4);	//PB4置高电平，停止
		PWM_SetCompare3(Speed);
	}
	else									//反转
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_3);	//PB3置低电平
		GPIO_SetBits(GPIOB, GPIO_Pin_4);	//PB4置高电平，设置方向为反转
		PWM_SetCompare3(-Speed);
	}
}

//设置右后电机速度
void Motor_SetRght2Speed(int8_t Speed)
{
	if (Speed >0)							//正转
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_5);	//PB5置高电平
		GPIO_ResetBits(GPIOB, GPIO_Pin_6);	//PB6置低电平，设置方向为正转
		PWM_SetCompare4(Speed);				//PWM设置为速度值
	}
	else if(Speed==0)						//停止
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_5);	//PB5置高电平
		GPIO_SetBits(GPIOB, GPIO_Pin_6);	//PB6置高电平，停止
		PWM_SetCompare4(Speed);
	}
	else									//反转
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_5);	//PB5置低电平
		GPIO_SetBits(GPIOB, GPIO_Pin_6);	//PB6置高电平，设置方向为反转
		PWM_SetCompare4(-Speed);
	}
}
