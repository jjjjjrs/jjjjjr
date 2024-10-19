#include "stm32f10x.h"                  // Device header
#include "Motor.h"

void Car_Init()
{
	Motor_Init();
}

void Go_Ahead()
{
	Motor_SetLeft1Speed(65);
	Motor_SetLeft2Speed(65);
	Motor_SetRight1Speed(65);
	Motor_SetRight2Speed(65);
}

void Go_Back()
{
	Motor_SetLeft1Speed(-65);
	Motor_SetLeft2Speed(-65);
	Motor_SetRight1Speed(-65);
	Motor_SetRight2Speed(-65);
}

void Turn_Left()
{
	Motor_SetLeft1Speed(0);
	Motor_SetLeft2Speed(0);
	Motor_SetRight1Speed(65);
	Motor_SetRight2Speed(65);
}

void Turn_Right()
{
	Motor_SetLeft1Speed(65);
	Motor_SetLeft2Speed(65);
	Motor_SetRight1Speed(0);
	Motor_SetRight2Speed(0);
}

void Self_Left()
{
	Motor_SetLeft1Speed(-65);
	Motor_SetLeft2Speed(-65);
	Motor_SetRight1Speed(65);
	Motor_SetRight2Speed(65);
}

void Self_Right()
{
	Motor_SetLeft1Speed(65);
	Motor_SetLeft2Speed(65);
	Motor_SetRight1Speed(-65);
	Motor_SetRight2Speed(-65);
}

void Car_Stop()
{
	Motor_SetLeft1Speed(0);
	Motor_SetLeft2Speed(0);
	Motor_SetRight1Speed(0);
	Motor_SetRight2Speed(0);
}
