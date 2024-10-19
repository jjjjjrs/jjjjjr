#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "PWM.h"
#include "Motor.h"
#include "CAR.h"
#include "Serial.h"
#include "Track.h"
#include "HW.h"

uint16_t Data1;

int main(void)
{ 
	Car_Init();
	Serial_Init();
	Motor_Init();
	Track_Init();
	HW_Init();
	HW_GetDataleft();
	HW_GetDataright();

	while (1)
	{
		if (Serial_GetRxFlag() == 1)
		{
			Data1=Serial_GetRxData();
			if(Data1==0x30)Car_Stop();
			if(Data1==0x31)Go_Ahead();
			if(Data1==0x32)Go_Back();
			if(Data1==0x33)Turn_Left();
			if(Data1==0x34)Turn_Right();
			if(Data1==0x35)Self_Left();
			if(Data1==0x36)Self_Right();
			if(Data1==0x37)Track();
			if(Data1==0x38)HWBZ();
		}	
	}
}
