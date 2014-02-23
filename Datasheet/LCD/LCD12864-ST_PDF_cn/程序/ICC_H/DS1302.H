/*********************************************************************
	微 雪 电 子   WaveShare   http://www.waveShare.net            	
	                                                        
目    的:   建立方便的DS1302操作库
						  
目标系统:   基于AVR单片机
	                                                                
应用软件:   ICCAVR                                               
	                                                                
版    本:   Version 1.0
	                                                                
圆版时间:   2004-08-25

开发人员:   SEE

说    明:   若用于商业用途，请保留此段文字或注明代码来源

	深 圳 市 微 雪 电 子 有 限 公 司 保 留 所 有 的 版 权 
*********************************************************************/

/*01010101010101010101010101010101010101010101010101010101010101010101
----------------------------------------------------------------------
版本更新记录：

----------------------------------------------------------------------
入口参数说明：
	#include "D:\ICC51\CmmICC.H"

	#define OUT_SCK sbi(DDRD,0)
	#define OUT_SIO sbi(DDRD,1)
	#define OUT_RST sbi(DDRD,2)

	#define IN_SIO  cbi(DDRD,1)

	#define SET_SCK sbi(PORTD,0)
	#define SET_SIO sbi(PORTD,1)
	#define SET_RST sbi(PORTD,2)

	#define CLR_SCK cbi(PORTD,0)
	#define CLR_SIO cbi(PORTD,1)
	#define CLR_RST cbi(PORTD,2)

	#define GET_SIO gbi(PIND,1)

----------------------------------------------------------------------
待定参数说明：
	#define DELAY()	{NOP();NOP();NOP();}

----------------------------------------------------------------------	
对外变量说明：

----------------------------------------------------------------------
对外函数说明：

----------------------------------------------------------------------
10101010101010101010101010101010101010101010101010101010101010101010*/

#ifndef DS1302_H
#define DS1302_H

#include "D:\ICC_H\CmmICC.H"

#define DELAY()	{NOP();NOP();NOP();NOP();NOP();NOP();}

//uint8 DS1302Second;
//uint8 DS1302Minute;
//uint8 DS1302Hour;

//uint8 DS1302Day;
//uint8 DS1302Month;
//uint8 DS1302Year;

//uint8 DS1302SecLow;
//uint8 DS1302MinLow;
//uint8 DS1302HourLow; 
//uint8 DS1302DayLow;
//uint8 DS1302MonLow;
//uint8 DS1302YearLow;
//uint8 DS1302SecHi;
//uint8 DS1302MinHi;
//uint8 DS1302HourHi;
//uint8 DS1302DayHi;
//uint8 DS1302MonHi;
//uint8 DS1302YearHi;

uint8 operData;
#define data0  (bool)operData&0x01
//#define data7  (bool)operData&0x80

/*--------------------------------------------------------------------
函数名称：DS1302写一个字节
函数功能：
注意事项：无
提示说明：无
输    入：无
返    回：无
--------------------------------------------------------------------*/
void writeByte(void)
{
	uint8 i;

	OUT_SIO;
	DELAY();
	for(i=0;i<8;i++)
	{
		CLR_SCK;
		if(data0)
			SET_SIO;
		else
			CLR_SIO;
		SET_SCK;
		operData = operData>>1;
	}
}
/*--------------------------------------------------------------------
函数名称：DS1302读一个字节
函数功能：
注意事项：无
提示说明：无
输    入：无
返    回：无
--------------------------------------------------------------------*/
void readByte(void)
{
	uint8 i;
	
	IN_SIO;
	SET_SCK;
	for(i=0;i<8;i++)
	{
		operData = operData>>1;
		CLR_SCK;
		DELAY();
		//delay50us(1);
		if(GET_SIO)
			operData |= 0x80;
		SET_SCK;
	}
}
/*--------------------------------------------------------------------
函数名称：DS1302充电参数
函数功能：
注意事项：无
提示说明：无
输    入：无
返    回：无
--------------------------------------------------------------------*/
void setChargePrmt(void)
{
	CLR_SCK;
	SET_RST;
	operData=0X90;
	writeByte();
	operData=0XA4;
	writeByte();
/* the following sentence here is not indispensable,
   but insert this sentence here can prevent ariseing error!
   because when start operating,RST must keep low level! */
	CLR_RST;
}
/*--------------------------------------------------------------------
函数名称：DS1302关写保护
函数功能：
注意事项：无
提示说明：无
输    入：无
返    回：无
--------------------------------------------------------------------*/
void closeWP(void)
{
	CLR_RST;
	CLR_SCK;
	SET_RST;
	operData=0X8E;
	writeByte();
	operData=0X80;
	CLR_SIO;
	writeByte();
/* the following sentence here is not indispensable,
   but insert this sentence here can prevent ariseing error!
   because when start operating,RST must keep low level! */
	CLR_RST;			
}
/*--------------------------------------------------------------------
函数名称：DS1302开写保护
函数功能：
注意事项：无
提示说明：无
输    入：无
返    回：无
--------------------------------------------------------------------*/
void openWP(void)
{
	CLR_RST;
	CLR_SCK;
	SET_RST;
	operData=0X8E;
	writeByte();
	operData=0X00;
	CLR_SIO;
	writeByte();
/* the following sentence here is not indispensable,
   but insert this sentence here can prevent ariseing error!
   because when start operating,RST must keep low level! */
	CLR_RST;
}
/*--------------------------------------------------------------------
函数名称：DS1302的一个完整写操作
函数功能：
注意事项：无
提示说明：无
输    入：
返    回：无
--------------------------------------------------------------------*/
void write(uint8 addr,uint8 dat)
{
	CLR_RST;   	//before SCL change to low level, RST must keep low level
	CLR_SCK;
	SET_RST;
	
	//CLR_SCK;   	//also ok!!!
	//CLR_RST;
	//SET_RST;
	
	//CLR_RST;   	//error
	//SET_RST;
	//CLR_SCK;
	
	operData=0X80|(addr<<1);
	writeByte();
	operData=dat;
	writeByte();
/* the following sentence here is not indispensable,
   but insert this sentence here can prevent ariseing error!
   because when start operating,RST must keep low level! */
	CLR_RST;
}
/*--------------------------------------------------------------------
函数名称：DS1302的一个完整读操作
函数功能：
注意事项：无
提示说明：无
输    入：
返    回：无
--------------------------------------------------------------------*/
uint8 read(uint8 cmd)
{
	//CLR_RST;
	CLR_SCK;
	SET_RST;
	operData=(cmd<<1)|0x81;
	writeByte();
	readByte();
/* the following sentence here is not indispensable,
   but insert this sentence here can prevent ariseing error!
   because when start operating,RST must keep low level! */
	CLR_RST;
	return(operData); 
}
/*--------------------------------------------------------------------
函数名称：DS1302读时间
函数功能：
注意事项：无
提示说明：无
输    入：
返    回：无
--------------------------------------------------------------------*/
void DS1302_getTime(uint8 *buf)
{
	uint8 hourAdr=2,minuteAdr=1,secondAdr=0;

	buf[0]=read(secondAdr);
	buf[0]=changeHexToInt(buf[0]);

	buf[1]=read(minuteAdr);
	buf[1]=changeHexToInt(buf[1]);

	buf[2]=read(hourAdr);
	buf[2]=changeHexToInt(buf[2]);

	//DS1302_speaTime();
}
/*--------------------------------------------------------------------
函数名称：DS1302读日期
函数功能：
注意事项：无
提示说明：无
输    入：无
返    回：无
--------------------------------------------------------------------*/
//void DS1302_getDate(void)
//{
//
//}
/*--------------------------------------------------------------------
函数名称：DS1302拆时间
函数功能：
注意事项：无
提示说明：低层将时间拆好，方便上层调用
输    入：无
返    回：无
--------------------------------------------------------------------*/
//void DS1302_speaTime(void)
//{
//	speaData(DS1302Second,2);
//	DS1302SecHi=dataElem[1];
//	DS1302SecLow=dataElem[0];
//
//	speaData(DS1302Minute,2);
//	DS1302MinHi=dataElem[1];
//	DS1302MinLow=dataElem[0];
//
//	speaData(DS1302Hour,2);
//	DS1302HourHi=dataElem[1];
//	DS1302HourLow=dataElem[0];
//}
/*--------------------------------------------------------------------
函数名称：DS1302拆日期
函数功能：
注意事项：无
提示说明：无
输    入：无
返    回：无
--------------------------------------------------------------------*/
//void DS1302_speaDate(void)
//{
//
//}
/*--------------------------------------------------------------------
函数名称：DS1302设置时间
函数功能：
注意事项：无
提示说明：无
输    入：
返    回：无
--------------------------------------------------------------------*/
void DS1302_setTime(uint8 hour,uint8 minute,uint8 second)
{
	uint8 hourAdr=2,minuteAdr=1,secondAdr=0;

	hour=changeIntToHex(hour);
	minute=changeIntToHex(minute);
	second=changeIntToHex(second);

	openWP();
	write(hourAdr,hour);
	write(minuteAdr,minute);
	write(secondAdr,second);
	closeWP();
}
/*--------------------------------------------------------------------
函数名称：DS1302设置日期
函数功能：
注意事项：无
提示说明：无
输    入：
返    回：无
--------------------------------------------------------------------*/
//void DS1302_setDate(uint8 year,uint8 month,uint8 day)
//{
//
//}
/*--------------------------------------------------------------------
函数名称：DS1302初始化
函数功能：
注意事项：无
提示说明：无
输    入：无
返    回：无
--------------------------------------------------------------------*/
void DS1302_init(void)
{
	OUT_SCK;
	OUT_SIO;
	OUT_RST;
	openWP();
	setChargePrmt();
	closeWP();
}

#endif
