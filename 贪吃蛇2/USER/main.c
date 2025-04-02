/*
��Ŀ���ƣ�����STM32��̰����
��Ŀԭ���ߣ�Bվ@С��˿�
��ĿӦ���ߣ��Ƽ�Сլ��
оƬƽ̨��STM32F103C8T6
���ʱ�䣺2022/04/25

Ӳ�����ӣ�

	OLED_IIC:
		SCL:PB12
		SDA:PB13

	KEY:
		UP:		PA3(��)
		DOWM:	PA4(��)
		LEFT:	PA1(��)
		RIGHT:	PA2(��)
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
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2); //����NVIC�жϷ���2:2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	LED_Init();
	OLED_Init();
	TIM3_Int_Init(1999,7199);//500ms
	EXTIX_Init();
	GUI_Init();//�����ʼ��
	OLED_ShowPicture(0,0,128,8,BMP2);//��ͷ����
	delay_ms(1863);
	while(1)
	{
		Get_Command();
		Show_Score();
		GUI_Refresh(map);//ˢ�µ�ͼ
		if(GameOver())
		{
			OLED_Clear();
			OLED_ShowPicture(0,0,128,8,BMP);
		}
	}
}






