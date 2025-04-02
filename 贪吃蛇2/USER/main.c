/*
项目名称：基于STM32的贪吃蛇
项目原作者：B站@小夸克克
项目应用者：科技小宅神
芯片平台：STM32F103C8T6
完成时间：2022/04/25

硬件连接：

	OLED_IIC:
		SCL:PB12
		SDA:PB13

	KEY:
		UP:		PA3(上)
		DOWM:	PA4(下)
		LEFT:	PA1(左)
		RIGHT:	PA2(右)
*/


#include "stm32f10x.h"
#include "oled.h"
#include "delay.h"
#include "snake.h"
#include "keyscan_exit.h"
#include "led.h"
#include "timer.h"
#include "bmp.h"


int  main()
{	
	delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //设置NVIC中断分组2:2位抢占优先级，2位响应优先级
	LED_Init();
	OLED_Init();
	TIM3_Int_Init(1999,7199);//500ms
	EXTIX_Init();
	GUI_Init();//界面初始化
	OLED_ShowPicture(0,0,128,8,BMP2);//开头动画
	delay_ms(1863);
	while(1)
	{
		Get_Command();
		Show_Score();
		GUI_Refresh(map);//刷新地图
		if(GameOver())
		{
			OLED_Clear();
			OLED_ShowPicture(0,0,128,8,BMP);
		}
	}
}






