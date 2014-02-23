/*********************************************************************
	微 雪 电 子   WaveShare   http://www.waveShare.net            	
		                                                        
目    的:   建立PCF8563操作库
	
目标系统:   基于AVR单片机
		                                                                
应用软件:   ICCAVR
		                                                                
版    本:   Version 1.0                                                
		                                                                
圆版时间:   2005-06-25
	
开发人员:   SEE

说    明:   若用于商业用途，请保留此段文字或注明代码来源
	
	深 圳 市 微 雪 电 子 有 限 公 司 保 留 所 有 的 版 权     
*********************************************************************/

/*01010101010101010101010101010101010101010101010101010101010101010101
----------------------------------------------------------------------
版本更新记录：

----------------------------------------------------------------------
入口参数说明：
	//#define WR_DADR	0xA2	//器件地址：A2 A1 A0 = 0 0 0
	//#define RD_DADR	0xA3	//器件地址：A2 A1 A0 = 0 0 0

----------------------------------------------------------------------
待定参数说明：

----------------------------------------------------------------------	
对外变量说明：

----------------------------------------------------------------------
对外函数说明：

----------------------------------------------------------------------
10101010101010101010101010101010101010101010101010101010101010101010*/

#ifndef PCF8563_H
#define PCF8563_H

#include "D:\ICC_H\CmmICC.H"
#include "D:\ICC_H\I2C.H"

//器件地址：A0 A1 A2 = 0 0 0
#ifndef WR_DADR 
	#define WR_DADR		0xA2	//write device-address 
#endif
#ifndef RD_DADR 
	#define RD_DADR		0xA3	//read device-address
#endif

#define CTRL_BUF1		0x00
#define CTRL_BUF2		0x01

#define SECOND_DATA_BUF	0x02
#define MINUTE_DATA_BUF	0x03
#define HOUR_DATA_BUF	0x04

#define DAY_DATA_BUF	0x05
#define WEEK_DATA_BUF	0x06
#define MONTH_DATA_BUF	0x07
#define YEAR_DATA_BUF	0x08

#define MINUTE_AE_BUF	0x09
#define HOUR_AE_BUF		0x0A
#define DAY_AE_BUF		0x0B
#define WEEK_AE_BUF		0x0C

#define CLK_FRQ_BUF		0x0D
#define TIMER_CTRL_BUF	0x0E
#define COUNT_VAL_BUF	0x0F

#define PCF8563_ERR		0
#define PCF8563_CRR		1

/*--------------------------------------------------------------------
函数名称：
函数功能：写 1个 Byte 到相应的寄存器
注意事项：
提示说明：
输    入：
返    回：
--------------------------------------------------------------------*/
bool WriteAByte(uint8 wordAdr,uint8 dat)
{
	if( I2C_Write(WR_DADR,wordAdr,dat)==I2C_ERR )
		return I2C_ERR;
	return I2C_CRR;
}
/*--------------------------------------------------------------------
函数名称：
函数功能：写 N个 Byte 到相应的寄存器
注意事项：
提示说明：
输    入：
返    回：
--------------------------------------------------------------------*/
//void WriteNByte(uint8 wordAdr,uint8 num,uint8 *pWrDat)
//{
//
//}
/*--------------------------------------------------------------------
函数名称：
函数功能：读 1个 Byte 到相应的寄存器
注意事项：
提示说明：
输    入：
返    回：
--------------------------------------------------------------------*/
//void ReadAByte(uint8 wordAdr,uint8 *pRdDat) 
//{  
//	I2C_Start();
//
//	I2C_SendByte(WR_DADR); 			
//	I2C_WaitAck();
//
//	I2C_SendByte(wordAdr); 			
//	I2C_WaitAck();
//
//	I2C_Start();
//
//	I2C_SendByte(RD_DADR);			
//	I2C_WaitAck();
//
//	I2C_RcvByte(pRdDat);
//	I2C_SendNoAck();
//
//	I2C_Stop();
//}
/*--------------------------------------------------------------------
函数名称：
函数功能：读 N个 Byte 到相应的寄存器
注意事项：
提示说明：
输    入：
返    回：
--------------------------------------------------------------------*/
bool ReadNByte(uint8 wordAdr,uint8 *pRdDat,uint8 num)
{  
	if( I2C_Read_(WR_DADR,wordAdr,RD_DADR,pRdDat,num)==I2C_ERR )
		return I2C_ERR;
	return I2C_CRR;
}
/*--------------------------------------------------------------------
函数名称：
函数功能：获取PCF8563的时间
注意事项：
提示说明：
输    入：
返    回：
--------------------------------------------------------------------*/
void PCF8563_getTime(uint8 *buf)
{
ReadAgain:    
	ReadNByte(SECOND_DATA_BUF,buf,3);
	buf[0]=buf[0]&0x7f;		//get second data
	if(buf[0]==0)
		goto ReadAgain;		//if "second==0"，read again for avoid mistake
	buf[1]=buf[1]&0x7f;		//get minute data
	buf[2]=buf[2]&0x3f;		//get hour data

	buf[0]=changeHexToInt(buf[0]);
	buf[1]=changeHexToInt(buf[1]);
	buf[2]=changeHexToInt(buf[2]);
}
/*--------------------------------------------------------------------
函数名称：
函数功能：设置PCF8563的时间
注意事项：
提示说明：
输    入：
返    回：
--------------------------------------------------------------------*/
void PCF8563_setTime(uint8 hour,uint8 minute,uint8 second)
{
	hour=changeIntToHex(hour);		//将数据的Dex格式转换为Hex格式
	minute=changeIntToHex(minute);
	second=changeIntToHex(second);

	WriteAByte(HOUR_DATA_BUF,hour);
	WriteAByte(MINUTE_DATA_BUF,minute);
	WriteAByte(SECOND_DATA_BUF,second);
}
/*--------------------------------------------------------------------
函数名称：
函数功能：获取PCF8563的日期
注意事项：
提示说明：
输    入：
返    回：
--------------------------------------------------------------------*/
//void PCF8563_getDate()
//{
//
//}
/*--------------------------------------------------------------------
函数名称：
函数功能：设置PCF8563的日期
注意事项：
提示说明：
输    入：
返    回：
--------------------------------------------------------------------*/
//void PCF8563_setDate()
//{
//
//}
/*--------------------------------------------------------------------
函数名称：
函数功能：初始化PCF8563
注意事项：
提示说明：
输    入：
返    回：
--------------------------------------------------------------------*/
void PCF8563_init()
{
	WriteAByte(CTRL_BUF1,0x00);			//basic setting
	WriteAByte(CTRL_BUF2,0x12);			//alarm enable
	//WriteAByte(HOUR_AE_BUF,0x09);		//set alarm hour at 9:00
	//WriteAByte(CLK_FRQ_BUF,0xf0);		//set clkout frequency
}

#endif

