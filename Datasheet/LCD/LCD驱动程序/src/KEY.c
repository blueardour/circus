#include "KEY.h"

/***********************************************************************
*函数名称：void KeyInit()
*入口参数：无
*出口参数：无
*说明：    初始化按键端口
************************************************************************/
void KeyInit(void)
{
	PINSEL1&=0xFFFFF000;  //P0.16-P0.21作为GPIO	 默认为输入
}

/***********************************************************************
*函数名称：uint8 KeyRead(void)
*入口参数：无
*出口参数：返回值为1-6
*说明：    直到按下键才返回  KEY6优先级最高
************************************************************************/
uint8 KeyRead(void)
{
  while(1)
  {
	  	if((IO0PIN&KEY6)==0)
		{
			while((IO0PIN&KEY6)==0);
			return 6;
		}
		else if((IO0PIN&KEY5)==0)
		{
			while((IO0PIN&KEY5)==0);
			return 5;
		}
		else if((IO0PIN&KEY4)==0)
		{
			while((IO0PIN&KEY4)==0);
			return 4;
		}
		else if((IO0PIN&KEY3)==0)
		{
			while((IO0PIN&KEY3)==0);
			return 3;
		}
		else if((IO0PIN&KEY2)==0)
		{
			while((IO0PIN&KEY2)==0);
			return 2;
		}
		else if((IO0PIN&KEY1)==0)
		{
			while((IO0PIN&KEY1)==0);
			return 1;
		}
	}
}



