#include "KEY.h"

/***********************************************************************
*�������ƣ�void KeyInit()
*��ڲ�������
*���ڲ�������
*˵����    ��ʼ�������˿�
************************************************************************/
void KeyInit(void)
{
	PINSEL1&=0xFFFFF000;  //P0.16-P0.21��ΪGPIO	 Ĭ��Ϊ����
}

/***********************************************************************
*�������ƣ�uint8 KeyRead(void)
*��ڲ�������
*���ڲ���������ֵΪ1-6
*˵����    ֱ�����¼��ŷ���  KEY6���ȼ����
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



