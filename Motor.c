#include "stm32f10x.h"                  // Device header
#include "PWM.h"

//�����ʼ��
void Motor_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure1;
	GPIO_InitStructure1.GPIO_Mode = GPIO_Mode_Out_PP;//�������ģʽ
	GPIO_InitStructure1.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure1.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure1);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure2;
	GPIO_InitStructure2.GPIO_Mode = GPIO_Mode_Out_PP;//�������ģʽ
	GPIO_InitStructure2.GPIO_Pin = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6;
	GPIO_InitStructure2.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure2);
	
	PWM_Init();
}

//������ǰ����ٶ�
void Motor_SetLeft1Speed(int8_t Speed)
{
	if (Speed >0)							//��ת
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_4);	//PA4�øߵ�ƽ
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);	//PA5�õ͵�ƽ�����÷���Ϊ��ת
		PWM_SetCompare1(Speed);				//PWM����Ϊ�ٶ�ֵ
	}
	else if(Speed==0)						//ֹͣ
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_4);	//PA4�øߵ�ƽ
		GPIO_SetBits(GPIOA, GPIO_Pin_5);	//PA5�øߵ�ƽ��ֹͣ
		PWM_SetCompare1(Speed);
	}
	else									//��ת
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_4);	//PA4�õ͵�ƽ
		GPIO_SetBits(GPIOA, GPIO_Pin_5);	//PA5�øߵ�ƽ�����÷���Ϊ��ת
		PWM_SetCompare1(-Speed);
	}
}

//����������ٶ�
void Motor_SetLeft2Speed(int8_t Speed)
{
	if (Speed >0)							//��ת
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_6);	//PA6�øߵ�ƽ
		GPIO_ResetBits(GPIOA, GPIO_Pin_7);	//PA7�õ͵�ƽ�����÷���Ϊ��ת
		PWM_SetCompare2(Speed);				//PWM����Ϊ�ٶ�ֵ
	}
	else if(Speed==0)						//ֹͣ
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_6);	//PA6�øߵ�ƽ
		GPIO_SetBits(GPIOA, GPIO_Pin_7);	//PA7�øߵ�ƽ��ֹͣ
		PWM_SetCompare2(Speed);
	}
	else									//��ת
	{
		GPIO_ResetBits(GPIOA, GPIO_Pin_6);	//PA6�õ͵�ƽ
		GPIO_SetBits(GPIOA, GPIO_Pin_7);	//PA7�øߵ�ƽ�����÷���Ϊ��ת
		PWM_SetCompare2(-Speed);
	}
}

//������ǰ����ٶ�
void Motor_SetRight1Speed(int8_t Speed)
{
	if (Speed >0)							//��ת
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_3);	//PB3�øߵ�ƽ
		GPIO_ResetBits(GPIOB, GPIO_Pin_4);	//PB4�õ͵�ƽ�����÷���Ϊ��ת
		PWM_SetCompare3(Speed);				//PWM����Ϊ�ٶ�ֵ
	}
	else if(Speed==0)						//ֹͣ
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_3);	//PB3�øߵ�ƽ
		GPIO_SetBits(GPIOB, GPIO_Pin_4);	//PB4�øߵ�ƽ��ֹͣ
		PWM_SetCompare3(Speed);
	}
	else									//��ת
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_3);	//PB3�õ͵�ƽ
		GPIO_SetBits(GPIOB, GPIO_Pin_4);	//PB4�øߵ�ƽ�����÷���Ϊ��ת
		PWM_SetCompare3(-Speed);
	}
}

//�����Һ����ٶ�
void Motor_SetRght2Speed(int8_t Speed)
{
	if (Speed >0)							//��ת
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_5);	//PB5�øߵ�ƽ
		GPIO_ResetBits(GPIOB, GPIO_Pin_6);	//PB6�õ͵�ƽ�����÷���Ϊ��ת
		PWM_SetCompare4(Speed);				//PWM����Ϊ�ٶ�ֵ
	}
	else if(Speed==0)						//ֹͣ
	{
		GPIO_SetBits(GPIOB, GPIO_Pin_5);	//PB5�øߵ�ƽ
		GPIO_SetBits(GPIOB, GPIO_Pin_6);	//PB6�øߵ�ƽ��ֹͣ
		PWM_SetCompare4(Speed);
	}
	else									//��ת
	{
		GPIO_ResetBits(GPIOB, GPIO_Pin_5);	//PB5�õ͵�ƽ
		GPIO_SetBits(GPIOB, GPIO_Pin_6);	//PB6�øߵ�ƽ�����÷���Ϊ��ת
		PWM_SetCompare4(-Speed);
	}
}
