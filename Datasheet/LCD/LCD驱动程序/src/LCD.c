#include "LCD.h"
#define NOP()  delayms()
uint16 RAM[32][16]={0};

/***************************************************************************
* 名称：LCD_WriteCommand(uint cmd)
* 功能：向LCD发送命令
* 入口参数：cmd		要发送的命令
* 出口参数：无
* 前提：SPI已初始化
* 说明：发送命另时，先发启动字节。
****************************************************************************/
void LCD_WriteCommand(uint8 cmd)
{
	MSPI_SendData(SYNC_WRITE_COMMAND);
	MSPI_SendData(cmd & 0xF0);//高四位
	MSPI_SendData(cmd <<4);	  //低四位
}
/***************************************************************************
* 名称：LCD_WriteData(uint data)
* 功能：向LCD发送数据
* 入口参数：data		要发送的数据
* 出口参数：无
* 前提：SPI已初始化
* 说明：发送数据时，先发启动字节。
****************************************************************************/
void LCD_WriteData(uint8 data)
{
	MSPI_SendData(SYNC_WRITE_DATA);
	MSPI_SendData(data & 0xF0);//高四位
	MSPI_SendData(data<<4);	   //低四位
}
/***********************************************************************
*函数名称：void LCD_SHOWStr(uint8 reg,uint8 *buf,uint8 num)
*入口参数：reg 要显示处的地址 buf 显示的内容的指针 num 显示的字符个数
*出口参数：无
*说明：    在指定地处显示字符
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
*函数名称：void LCD_Clear()
*入口参数：无
*出口参数：无
*前提：    RE=0 基本指令集
*说明：    清屏
************************************************************************/
void LCD_Clear()
{
	LCD_WriteCommand(0x01);
	DelayNS(2);
}

/***********************************************************************
*函数名称：void LCD_RAMClear()
*入口参数：无
*出口参数：无
*前提：    RE=1 扩展指令集
*说明：    清屏
************************************************************************/
void LCD_RAMClear()
{   
	int8 i=0,j=0;
	/*向上填满*/
	for(i=31;i>=0;i--)
	{
		for(j=8;j<16;j++)
		{
			LCD_WriteCommand(LCD_EXT_CMD_GRAM_SET+i); 	    //设置垂直地址
			NOP();
			LCD_WriteCommand(LCD_EXT_CMD_GRAM_SET+j); 	    //设置水平地址 
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
			LCD_WriteCommand(LCD_EXT_CMD_GRAM_SET+i); 	    //设置垂直地址
			NOP();
			LCD_WriteCommand(LCD_EXT_CMD_GRAM_SET+j); 	    //设置水平地址 
			NOP();
			LCD_WriteData(0xff);
			NOP();
			LCD_WriteData(0xff);
			NOP();
		}
	}
	/*向下清屏*/
	for(i=0;i<32;i++)
	{
		for(j=0;j<8;j++)
		{
			LCD_WriteCommand(LCD_EXT_CMD_GRAM_SET+i); 	    //设置垂直地址
			NOP();
			LCD_WriteCommand(LCD_EXT_CMD_GRAM_SET+j); 	    //设置水平地址 
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
			LCD_WriteCommand(LCD_EXT_CMD_GRAM_SET+i); 	    //设置垂直地址
			NOP();
			LCD_WriteCommand(LCD_EXT_CMD_GRAM_SET+j); 	    //设置水平地址 
			NOP();
			LCD_WriteData(0x00);
			NOP();
			LCD_WriteData(0x00);
			NOP();
		}
	}
}
/***********************************************************************
*函数名称：uint8 point(uint8 x,uint8 y,uint8 value)
*入口参数：x 横坐标 0-127  y 纵坐标 0-63  value 写入的值 value=0 清零 value!=0 置1
*出口参数：无
*前提：    RE=1 扩展指令集
*说明：    无
************************************************************************/
uint8 point(uint8 x,uint8 y,uint8 value)
{
	uint16 bit;
	if(x>127)             //横坐标值检验
	{
		return 0;
	}
	if(y>64)			  //纵坐标值检验
	{
		return 0; 
	}

	bit=x%16;		      //所对应的位
	bit=15-bit;			  //反过来，和横坐标对应起来
	bit=1<<bit;   
	x=x/16;		 		  //所对应的横坐标
	if(y>=32)	 		  //如果是下半部分，x加8
	{
		x+=8;
		y-=32;
	}
	if(value==0)
	{
		RAM[y][x]=RAM[y][x]&(~bit);              //对应位清零
	}   
	else
	{
		 RAM[y][x]=RAM[y][x]|bit;                //对应位置1
	}
			
	LCD_WriteCommand(LCD_EXT_CMD_GRAM_SET+y); 	    //设置垂直地址
	NOP();
	LCD_WriteCommand(LCD_EXT_CMD_GRAM_SET+x); 	    //设置水平地址 
    NOP();
	LCD_WriteData((RAM[y][x]&0xFF00)>>8);	        //高8位
	NOP();
	LCD_WriteData(RAM[y][x]&0x00FF);				//低8位
	NOP();
	return 1;	
}
/***********************************************************************
*函数名称：void line(uint8 x1,uint8 y1,uint8 x2,uint8 y2,uint8 value)
*入口参数：x1,y1 起始点    x2,y2 终点 	  value 写入的值 0 或非0
*出口参数：无
*前提：    RE=1 扩展指令集
*说明：    x1等于x2 或者y1等于y2,   x1,x2不能同时大于127 y1,y2 不能同时大于63 
************************************************************************/
void line(uint8 x1,uint8 y1,uint8 x2,uint8 y2,uint8 value)
{
   uint8 i=0;
   if( ( ((x1!=x2)&&(y1!=y2)) )||( (x1>127)&&(x2>127) ) || ( (y1>63)&&(y2>63) ) ) //判断是否符和要求
   {
   		return;
	}
	if(x1==x2)			         //x1,x2都小于127
	{						  
		if(y1>y2)		         //y1大于y2，则y1可能超了
		{
			y1=y1>63?63:y1;      //若超了，赋给其最大值
			for(i=y2;i<=y1;i++)
			{
				point(x1,i,value);
			}
		    
		}
		else if(y2>y1)           //y2大于y1，则y2可能超了
		{
		 	y2=y2>63?63:y2;      //若超了，赋给其最大值
			for(i=y1;i<=y2;i++)
			{
				point(x1,i,value);
			}
		}
		else                     //是个点
		{
			point(x1,y1,1);	
		}
	}
	else	                     //y2等于y1
	{
		if(x1>x2)		         //x1大于x2，则x1可能超了
		{
			x1=x1>127?127:x1;      //若超了，赋给其最大值
			for(i=x2;i<=x1;i++)
			{
				point(i,y1,value);
			}
		}
		if(x2>x1)		         //x2大于x1，则x2可能超了
		{
			x2=x2>127?127:x2;      //若超了，赋给其最大值
			for(i=x1;i<=x2;i++)
			{
				point(i,y1,value);
			} 
		}
	}			
}
/***********************************************************************
*函数名称：LCD_ToNormal(void)
*入口参数：无
*出口参数：无
*说明：    LCD由基本指令切换到扩展指令 并将绘图显示设为关
************************************************************************/
void LCD_ToNormal(void)
{
	 LCD_WriteCommand(EXTRA_COMMAND);                    //绘图显示关
	 NOP();
	 LCD_WriteCommand(NOMAL_COMMAND);                    //设定为基本指令
	 NOP();
}
/***********************************************************************
*函数名称：LCD_ToExtra(void)
*入口参数：无
*出口参数：无
*说明：    LCD由扩展指令切换到基本指令	并将绘图显示设为开
************************************************************************/
void LCD_ToExtra(void)
{
	 LCD_WriteCommand(EXTRA_COMMAND);                    //设定为扩展指令
	 NOP();
	 LCD_WriteCommand(EXTRA_COMMAND_BIT);                //绘图显示开
	 NOP();
}

/***********************************************************************
*函数名称：void LCD_Test(void)
*入口参数：无
*出口参数：无
*说明：对LCD测试
************************************************************************/
void  LCD_Test(void)
{
	uint8 str1[]="LCD TEST";
	uint8 str2[]="PRESS 6 TO EXIT";
	while(1)
	{
		LCD_SHOWStr(LCD_CMD_DDRAM+0x01,str1,sizeof(str1));
		LCD_SHOWStr(LCD_CMD_DDRAM+0x10,str2,sizeof(str2));
		if(KeyRead()==6)			                        //等待按键
		{
			LCD_Clear();									    //清屏
			LCD_ToExtra();	                                    //切换到扩展指令
			LCD_RAMClear();										//清屏
			break;
		}	                                       
		LCD_ToExtra();	                                    //切换到扩展指令
		LCD_RAMClear();										//清屏
	
		line(0,40,127,40,1);
		KeyRead();	                                        //等待按键
		line(0,40,127,40,0);
		LCD_RAMClear();
		LCD_ToNormal();                                     //切换到基本指令
		LCD_Clear();									    //清屏
	}
}
	
/***********************************************************************
*函数名称：LCD_Init(void)
*入口参数：无
*出口参数：无
*说明：对LCD进行初始化
************************************************************************/
void LCD_Init(void)
{
	LCD_WriteCommand(NOMAL_COMMAND);                    //功能设定
	NOP();
	LCD_WriteCommand(NOMAL_COMMAND);                    //功能设定
	NOP();
	LCD_WriteCommand(LCD_CMD_DISPLAY+BIT_DISPLAY_D);    //显示开关，整体显示开关 开
	NOP();
	LCD_Clear();									    //清屏
	LCD_WriteCommand(LCD_CMD_DOT_MODE);					//进入点设定
	NOP();
}

