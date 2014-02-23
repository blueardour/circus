#include "LCD.h"
#define NOP()  delayms()
uint16 RAM[32][16]={0};

/***************************************************************************
* ���ƣ�LCD_WriteCommand(uint cmd)
* ���ܣ���LCD��������
* ��ڲ�����cmd		Ҫ���͵�����
* ���ڲ�������
* ǰ�᣺SPI�ѳ�ʼ��
* ˵������������ʱ���ȷ������ֽڡ�
****************************************************************************/
void LCD_WriteCommand(uint8 cmd)
{
	MSPI_SendData(SYNC_WRITE_COMMAND);
	MSPI_SendData(cmd & 0xF0);//����λ
	MSPI_SendData(cmd <<4);	  //����λ
}
/***************************************************************************
* ���ƣ�LCD_WriteData(uint data)
* ���ܣ���LCD��������
* ��ڲ�����data		Ҫ���͵�����
* ���ڲ�������
* ǰ�᣺SPI�ѳ�ʼ��
* ˵������������ʱ���ȷ������ֽڡ�
****************************************************************************/
void LCD_WriteData(uint8 data)
{
	MSPI_SendData(SYNC_WRITE_DATA);
	MSPI_SendData(data & 0xF0);//����λ
	MSPI_SendData(data<<4);	   //����λ
}
/***********************************************************************
*�������ƣ�void LCD_SHOWStr(uint8 reg,uint8 *buf,uint8 num)
*��ڲ�����reg Ҫ��ʾ���ĵ�ַ buf ��ʾ�����ݵ�ָ�� num ��ʾ���ַ�����
*���ڲ�������
*˵����    ��ָ���ش���ʾ�ַ�
************************************************************************/
void LCD_SHOWStr(uint8 reg,uint8 *buf,uint8 num)
{
	uint8 i;
	LCD_WriteCommand(reg);
	NOP();
	for(i=0;i<num;i++)
	{
		LCD_WriteData(*buf);
		buf++;
		NOP();
	}
}
/***********************************************************************
*�������ƣ�void LCD_Clear()
*��ڲ�������
*���ڲ�������
*ǰ�᣺    RE=0 ����ָ�
*˵����    ����
************************************************************************/
void LCD_Clear()
{
	LCD_WriteCommand(0x01);
	DelayNS(2);
}

/***********************************************************************
*�������ƣ�void LCD_RAMClear()
*��ڲ�������
*���ڲ�������
*ǰ�᣺    RE=1 ��չָ�
*˵����    ����
************************************************************************/
void LCD_RAMClear()
{   
	int8 i=0,j=0;
	/*��������*/
	for(i=31;i>=0;i--)
	{
		for(j=8;j<16;j++)
		{
			LCD_WriteCommand(LCD_EXT_CMD_GRAM_SET+i); 	    //���ô�ֱ��ַ
			NOP();
			LCD_WriteCommand(LCD_EXT_CMD_GRAM_SET+j); 	    //����ˮƽ��ַ 
			NOP();
			LCD_WriteData(0xff);
			NOP();
			LCD_WriteData(0xff);
			NOP();
		}
	}
	for(i=31;i>=0;i--)
	{
		for(j=0;j<8;j++)
		{
			LCD_WriteCommand(LCD_EXT_CMD_GRAM_SET+i); 	    //���ô�ֱ��ַ
			NOP();
			LCD_WriteCommand(LCD_EXT_CMD_GRAM_SET+j); 	    //����ˮƽ��ַ 
			NOP();
			LCD_WriteData(0xff);
			NOP();
			LCD_WriteData(0xff);
			NOP();
		}
	}
	/*��������*/
	for(i=0;i<32;i++)
	{
		for(j=0;j<8;j++)
		{
			LCD_WriteCommand(LCD_EXT_CMD_GRAM_SET+i); 	    //���ô�ֱ��ַ
			NOP();
			LCD_WriteCommand(LCD_EXT_CMD_GRAM_SET+j); 	    //����ˮƽ��ַ 
			NOP();
			LCD_WriteData(0x00);
			NOP();
			LCD_WriteData(0x00);
			NOP();
		}
	}
	for(i=0;i<32;i++)
	{
		for(j=8;j<16;j++)
		{
			LCD_WriteCommand(LCD_EXT_CMD_GRAM_SET+i); 	    //���ô�ֱ��ַ
			NOP();
			LCD_WriteCommand(LCD_EXT_CMD_GRAM_SET+j); 	    //����ˮƽ��ַ 
			NOP();
			LCD_WriteData(0x00);
			NOP();
			LCD_WriteData(0x00);
			NOP();
		}
	}
}
/***********************************************************************
*�������ƣ�uint8 point(uint8 x,uint8 y,uint8 value)
*��ڲ�����x ������ 0-127  y ������ 0-63  value д���ֵ value=0 ���� value!=0 ��1
*���ڲ�������
*ǰ�᣺    RE=1 ��չָ�
*˵����    ��
************************************************************************/
uint8 point(uint8 x,uint8 y,uint8 value)
{
	uint16 bit;
	if(x>127)             //������ֵ����
	{
		return 0;
	}
	if(y>64)			  //������ֵ����
	{
		return 0; 
	}

	bit=x%16;		      //����Ӧ��λ
	bit=15-bit;			  //���������ͺ������Ӧ����
	bit=1<<bit;   
	x=x/16;		 		  //����Ӧ�ĺ�����
	if(y>=32)	 		  //������°벿�֣�x��8
	{
		x+=8;
		y-=32;
	}
	if(value==0)
	{
		RAM[y][x]=RAM[y][x]&(~bit);              //��Ӧλ����
	}   
	else
	{
		 RAM[y][x]=RAM[y][x]|bit;                //��Ӧλ��1
	}
			
	LCD_WriteCommand(LCD_EXT_CMD_GRAM_SET+y); 	    //���ô�ֱ��ַ
	NOP();
	LCD_WriteCommand(LCD_EXT_CMD_GRAM_SET+x); 	    //����ˮƽ��ַ 
    NOP();
	LCD_WriteData((RAM[y][x]&0xFF00)>>8);	        //��8λ
	NOP();
	LCD_WriteData(RAM[y][x]&0x00FF);				//��8λ
	NOP();
	return 1;	
}
/***********************************************************************
*�������ƣ�void line(uint8 x1,uint8 y1,uint8 x2,uint8 y2,uint8 value)
*��ڲ�����x1,y1 ��ʼ��    x2,y2 �յ� 	  value д���ֵ 0 ���0
*���ڲ�������
*ǰ�᣺    RE=1 ��չָ�
*˵����    x1����x2 ����y1����y2,   x1,x2����ͬʱ����127 y1,y2 ����ͬʱ����63 
************************************************************************/
void line(uint8 x1,uint8 y1,uint8 x2,uint8 y2,uint8 value)
{
   uint8 i=0;
   if( ( ((x1!=x2)&&(y1!=y2)) )||( (x1>127)&&(x2>127) ) || ( (y1>63)&&(y2>63) ) ) //�ж��Ƿ����Ҫ��
   {
   		return;
	}
	if(x1==x2)			         //x1,x2��С��127
	{						  
		if(y1>y2)		         //y1����y2����y1���ܳ���
		{
			y1=y1>63?63:y1;      //�����ˣ����������ֵ
			for(i=y2;i<=y1;i++)
			{
				point(x1,i,value);
			}
		    
		}
		else if(y2>y1)           //y2����y1����y2���ܳ���
		{
		 	y2=y2>63?63:y2;      //�����ˣ����������ֵ
			for(i=y1;i<=y2;i++)
			{
				point(x1,i,value);
			}
		}
		else                     //�Ǹ���
		{
			point(x1,y1,1);	
		}
	}
	else	                     //y2����y1
	{
		if(x1>x2)		         //x1����x2����x1���ܳ���
		{
			x1=x1>127?127:x1;      //�����ˣ����������ֵ
			for(i=x2;i<=x1;i++)
			{
				point(i,y1,value);
			}
		}
		if(x2>x1)		         //x2����x1����x2���ܳ���
		{
			x2=x2>127?127:x2;      //�����ˣ����������ֵ
			for(i=x1;i<=x2;i++)
			{
				point(i,y1,value);
			} 
		}
	}			
}
/***********************************************************************
*�������ƣ�LCD_ToNormal(void)
*��ڲ�������
*���ڲ�������
*˵����    LCD�ɻ���ָ���л�����չָ�� ������ͼ��ʾ��Ϊ��
************************************************************************/
void LCD_ToNormal(void)
{
	 LCD_WriteCommand(EXTRA_COMMAND);                    //��ͼ��ʾ��
	 NOP();
	 LCD_WriteCommand(NOMAL_COMMAND);                    //�趨Ϊ����ָ��
	 NOP();
}
/***********************************************************************
*�������ƣ�LCD_ToExtra(void)
*��ڲ�������
*���ڲ�������
*˵����    LCD����չָ���л�������ָ��	������ͼ��ʾ��Ϊ��
************************************************************************/
void LCD_ToExtra(void)
{
	 LCD_WriteCommand(EXTRA_COMMAND);                    //�趨Ϊ��չָ��
	 NOP();
	 LCD_WriteCommand(EXTRA_COMMAND_BIT);                //��ͼ��ʾ��
	 NOP();
}

/***********************************************************************
*�������ƣ�void LCD_Test(void)
*��ڲ�������
*���ڲ�������
*˵������LCD����
************************************************************************/
void  LCD_Test(void)
{
	uint8 str1[]="LCD TEST";
	uint8 str2[]="PRESS 6 TO EXIT";
	while(1)
	{
		LCD_SHOWStr(LCD_CMD_DDRAM+0x01,str1,sizeof(str1));
		LCD_SHOWStr(LCD_CMD_DDRAM+0x10,str2,sizeof(str2));
		if(KeyRead()==6)			                        //�ȴ�����
		{
			LCD_Clear();									    //����
			LCD_ToExtra();	                                    //�л�����չָ��
			LCD_RAMClear();										//����
			break;
		}	                                       
		LCD_ToExtra();	                                    //�л�����չָ��
		LCD_RAMClear();										//����
	
		line(0,40,127,40,1);
		KeyRead();	                                        //�ȴ�����
		line(0,40,127,40,0);
		LCD_RAMClear();
		LCD_ToNormal();                                     //�л�������ָ��
		LCD_Clear();									    //����
	}
}
	
/***********************************************************************
*�������ƣ�LCD_Init(void)
*��ڲ�������
*���ڲ�������
*˵������LCD���г�ʼ��
************************************************************************/
void LCD_Init(void)
{
	LCD_WriteCommand(NOMAL_COMMAND);                    //�����趨
	NOP();
	LCD_WriteCommand(NOMAL_COMMAND);                    //�����趨
	NOP();
	LCD_WriteCommand(LCD_CMD_DISPLAY+BIT_DISPLAY_D);    //��ʾ���أ�������ʾ���� ��
	NOP();
	LCD_Clear();									    //����
	LCD_WriteCommand(LCD_CMD_DOT_MODE);					//������趨
	NOP();
}

