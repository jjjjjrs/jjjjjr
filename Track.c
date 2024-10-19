#include "stm32f10x.h"                  // Device header
#include "Car.h"
#include "Serial.h"

extern uint16_t Data1;

void Track_Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode =GPIO_Mode_IN_FLOATING ;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 | GPIO_Pin_8| GPIO_Pin_9| GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

//´Ó×óµ½ÓÒ1 2 3 4
uint16_t Track_GetData1(void)
{
	uint16_t tempData1;
	tempData1 = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_7);
	return tempData1;
}

uint16_t Track_GetData2(void)
{
	uint16_t tempData2;
	tempData2 = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_8);
	return tempData2;
}

uint16_t Track_GetData3(void)
{
	uint16_t tempData3;
	tempData3 = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9);
	return tempData3;
}

uint16_t Track_GetData4(void)
{
	uint16_t tempData4;
	tempData4 = GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_15);
	return tempData4;
}

void Track(void)
{
	while (1)
	{
		
		if(Track_GetData1()==0&&
			 Track_GetData2()==0&&
			 Track_GetData3()==0&&
			 Track_GetData4()==0)
		{
			Go_Ahead();
		}
		else if(Track_GetData1()==1&&
						Track_GetData2()==1&&
						Track_GetData3()==1&&
						Track_GetData4()==1)
		{
			Car_Stop();
		}
		else if(Track_GetData1()==0&&
						Track_GetData2()==0&&
						Track_GetData3()==1&&
						Track_GetData4()==1)
		{
			Self_Right();
		}
		else if(Track_GetData1()==0&&
						Track_GetData2()==0&&
						Track_GetData3()==0&&
						Track_GetData4()==1)
		{
			Turn_Right();
		}
		else if(Track_GetData1()==0&&
						Track_GetData2()==0&&
						Track_GetData3()==1&&
						Track_GetData4()==0)
		{
			Turn_Right();
		}
		else if(Track_GetData1()==1&&
						Track_GetData2()==1&&
						Track_GetData3()==0&&
						Track_GetData4()==0)
		{
			Self_Left();
		}
		else if(Track_GetData1()==1&&
						Track_GetData2()==0&&
						Track_GetData3()==0&&
						Track_GetData4()==0)
		{
			Turn_Left();
		}
		else if(Track_GetData1()==0&&
						Track_GetData2()==1&&
						Track_GetData3()==0&&
						Track_GetData4()==0)
		{
			Turn_Left();
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
