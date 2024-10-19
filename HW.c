#include "stm32f10x.h"                  // Device header
#include "Car.h"
#include "Serial.h"
#include "Delay.h"

extern uint16_t Data1;

void HW_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode =GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11| GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

uint16_t HW_GetDatamiddle(void)
{
	uint16_t tempDatamiddle;
	tempDatamiddle = !GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_10);
	return tempDatamiddle;
}

uint16_t HW_GetDataleft(void)
{
	uint16_t tempDataleft;
	tempDataleft = !GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_14);
	return tempDataleft;
}

uint16_t HW_GetDataright(void)
{
	uint16_t tempDataright;
	tempDataright = !GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_11);
	return tempDataright;
}
void HWBZ(void)
{
	HW_Init();
	while(1)
	{
		if(HW_GetDataleft()==0&&
		   HW_GetDataright()==0&&
		   HW_GetDatamiddle()==0)
		{	
			Go_Ahead();
		}
		else if(HW_GetDataleft()==0&&
				HW_GetDataright()==0&&
				HW_GetDatamiddle()==1)
		{
			Self_Right();
		}
		else if(HW_GetDataleft()==1&&
				HW_GetDataright()==0&&
				HW_GetDatamiddle()==1)
		{
			Self_Right();
		}
		else if(HW_GetDataleft()==0&&
				HW_GetDataright()==1&&
				HW_GetDatamiddle()==1)
		{
			Self_Left();
		}
		else if(HW_GetDataleft()==1&&
				HW_GetDataright()==0&&
				HW_GetDatamiddle()==0)
		{
			Turn_Right();
		}
		else if(HW_GetDataleft()==0&&
				HW_GetDataright()==1&&
				HW_GetDatamiddle()==0)
		{
			Turn_Left();
		}
		else if(HW_GetDataleft()==1&&
				HW_GetDataright()==1&&
				HW_GetDatamiddle()==1)
		{
			Car_Stop();
		}
		if(Serial_GetRxFlag() == 1)
		{
			Data1=Serial_GetRxData();
			if(Data1==0x48)
			{
				Car_Stop();
				break;
			}
		}
	}
}
