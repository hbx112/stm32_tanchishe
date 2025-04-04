#include "stm32f10x.h"
#include "key.h"
#include "sys.h" 
#include "delay.h"

void KEY_Init(void) //IO初始化
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);//使能PORTA,PORTE时钟
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_1|GPIO_Pin_2|GPIO_Pin_3|GPIO_Pin_4;//KEY0-KEY1
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
 	GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化GPIOE4,3
}

//int Key_Scan(int flag)
//{
//  int num;
//  switch(flag)
//  {
//	  case 1 :num= 1;break;
//	  case 2 :num= 2;break;
//	  case 3 :num= 3;break;
//	  case 4 :num= 4;break;
//	  default:num= 0;break;
//  }
//  return num;
//}

//按键处理函数
//返回按键值
//mode:0,不支持连续按;1,支持连续按;
//0，没有任何按键按下
//1，KEY0按下
//2，KEY1按下

//4，KEY3按下 WK_UP
//注意此函数有响应优先级,KEY0>KEY1>KEY3!!
u8 KEY_Scan(u8 mode)
{	 
	static u8 key_up=1;//按键按松开标志
	if(mode)key_up=1;  //支持连按		  
	if(key_up&&(KEY1==0||KEY2==0||KEY3==0||KEY4==0))
	{
		delay_ms(10);//去抖动 
		key_up=0;
		if(KEY1==0)return RIGHT;
		else if(KEY2==0)return LEFT;
		else if(KEY3==0)return DOWN;
		else if(KEY4==0)return UP;		
	}else if(KEY1==1&&KEY2==1&&KEY3==1||KEY4==1)key_up=1; 	    
 	return 0;// 无按键按下
}


