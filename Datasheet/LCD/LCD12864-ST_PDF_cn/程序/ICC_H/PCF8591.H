/*********************************************************************
	微 雪 电 子   WaveShare   http://www.waveShare.net	

目    的:   建立方便的PCF8591操作库

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
	sbit I2C_SCL=P3^1;
	sbit I2C_SDA=P3^0;
	#define WR_DADR	0x90	//器件地址：A2 A1 A0 = 0 0 0
	#define RD_DADR	0x91	//器件地址：A2 A1 A0 = 0 0 0

----------------------------------------------------------------------
待定参数说明：

----------------------------------------------------------------------	
对外变量说明：

----------------------------------------------------------------------
对外函数说明：

----------------------------------------------------------------------
10101010101010101010101010101010101010101010101010101010101010101010*/

#ifndef PCF8591_H
#define PCF8591_H

#include "D:\ICC_H\CmmICC.H"
//sbit I2C_SCL=P3^1;
//sbit I2C_SDA=P3^0;
#include "D:\ICC_H\I2C.H"

//器件地址：A0 A1 A2 = 0 0 0
#ifndef WR_DADR 
	#define WR_DADR		0x90	//write device-address 
#endif
#ifndef RD_DADR 
	#define RD_DADR		0x91	//read device-address
#endif

#define MODE0 	0x00	//Channel0 = AIN0;
						//Channel1 = AIN1;
						//Channel2 = AIN2;
						//Channel3 = AIN3;
#define MODE1 	0x10	//Channel0 = AIN3-AIN0;
						//Channel1 = AIN3-AIN1
						//Channel2 = AIN3-AIN2;
#define MODE2 	0x20	//Channel0 = AIN0;
						//Channel1 = AIN1;
						//Channel2 = AIN3-AIN2;
#define MODE3 	0x30	//Channel0 = AIN1-AIN0;
						//Channel1 = AIN3-AIN2;

#define CHNL0 	0		//Using Channel0
#define CHNL1 	1		//Using Channel1
#define CHNL2 	2		//Using Channel2
#define CHNL3 	3		//Using Channel3

#define DAouputEn	0x40	//0x50 or 0x60 or 0x70 is also ok!

/*--------------------------------------------------------------------
函数全称：
函数功能：
注意事项：
提示说明：
输    入：	
返    回：00H~FFH
--------------------------------------------------------------------*/
void PCF8591_getAD(uint8 mode,uint8 chan,uint8 *pRdDat)
{
	I2C_Read(WR_DADR,mode|chan,RD_DADR,pRdDat);
}
/*--------------------------------------------------------------------
函数全称：
函数功能：
注意事项：
提示说明：
输    入：00H~FFH	
返    回：
--------------------------------------------------------------------*/
void PCF8591_setDA(uint8 val)
{
	I2C_Write(WR_DADR,DAouputEn,val);
}

#endif
