/*********************************************************************
	微 雪 电 子   WaveShare   http://www.waveShare.net            	
		                                                        
目    的:   建立AVR的硬件提取库，增加各类补丁，方便移植
					
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

----------------------------------------------------------------------
待定参数说明：

----------------------------------------------------------------------	
对外变量说明：
    
----------------------------------------------------------------------
对外函数说明：
   
----------------------------------------------------------------------
10101010101010101010101010101010101010101010101010101010101010101010*/

#ifndef Hardware_H
#define Hardware_H

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <macros.h>
#include <eeprom.h>
//#include <wdt.h>

/* TWI configs */
//如使用ATMEGA162(没有TWI接口)之类的MCU，在加载Hardware.H前，务必加“#define NO_INCLUDE_I2C_H 1”语句
#if NO_INCLUDE_I2C_H
;
#else
#include "D:\ICC_H\I2C.H"	//i2c即AVR的"twi"
#endif

/* hard configs */
#ifndef flash
	#define flash	const
#endif

#ifndef code
	#define code	const
#endif

#ifndef NOP
	#define NOP()	asm("nop")
#endif

/* io configs */
#define sbi(io,bit)		(  io |=  (1<<bit) )	//example: sbi(PORTA,0);sbi(DDRA,0);
#define cbi(io,bit)		(  io &= ~(1<<bit) )	//example: cbi(PORTA,0);cbi(DDRA,0);
#define gbi(pin ,bit)	( pin &   (1<<bit) )	//example: gbi(PINA,0);

/* interrupt configs */
#define DIS_INT  asm("sei")
#define EN_INT   asm("cli")

/* wdt configs */
#define WDT()    asm("wdr")

/* bit operation */
//#ifndef BIT
//#define BIT(x)	( 1<<(x) )
//#endif

/* USART configs for 4 Mhz crystal */
//#define BAUD9600			25
//#define BAUD19000			12
//#define UART_TRAN_ON()	UCR |=  0x08
//#define UART_TRAN_OFF()	UCR &= ~0x08
//#define UART_RCV_ON()		UCR |=  0x10
//#define UART_RCV_OFF()	UCR &= ~0x10

/*--------------------------------------------------------------------
函数全称：50us 延时
函数功能：当然是 50us延时 啦
注意事项：基于7.3728M晶振，稍微有点误差
提示说明：调用delay50us（20），得到1ms延时
输    入：	
返    回：无 
--------------------------------------------------------------------*/
void delay50us(sint16 t)
{
    uint8 j;		
    for(;t>0;t--)			
        for(j=0;j<70;j++)	
            ;
}
/*--------------------------------------------------------------------
函数全称：50ms 延时
函数功能：当然是 50ms延时 啦
注意事项：基于7.3728M晶振，稍微有点误差
提示说明：调用delay50ms（20），得到1s延时 
输    入：
返    回：无
--------------------------------------------------------------------*/
void delay50ms(sint16 t)
{
	uint16 i; 
	for(;t>0;t--)
		for(i=0;i<52642;i++)
			; 
}

#endif

