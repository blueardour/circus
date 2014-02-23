/*----------------------------------------------------------
	RT12864 底层驱动程序	
	创建日期:	2009.07.25
	修改日期:
	Starli		V1.0
----------------------------------------------------------*/
#ifndef _LCD_H_
#define _LCD_H_
#include "config.h"
#include "SPI.h"
#include "Key.h"
#include "Delay.h"

//==========================同步数据类型定义====================================
#define		SYNC_WRITE_COMMAND	0xF8           //5个‘1’启动一个周期，RW=0 写，RS=0 命令
#define		SYNC_READ_COMMAND	0xFC		   //5个‘1’启动一个周期，RW=1 读，RS=0 命令
#define		SYNC_WRITE_DATA		0xFA           //5个‘1’启动一个周期，RW=0 写，RS=1 数据
#define		SYNC_READ_DATA		0xFE		   //5个‘1’启动一个周期，RW=1 读，RS=1 数据

//===========================液晶基本指令集定义=================================
#define		LCD_CMD_CLRSCR		    0x01		//清屏,用0x20填充整个DDRAM,并且AC复位到0x00
#define		LCD_CMD_RESET_ADDRESS	0x02	    //地址归位,设置DDRAM中的AC到0x00并且将游标移动到开头的原点位置
#define		LCD_CMD_DOT_MODE    	0x06		//进入点设定


#define		LCD_CMD_DISPLAY		0x08	    	// 显示状态开关
#define		BIT_DISPLAY_D		4		        // D 整体显示开关 1 = ON , 0 = OFF
#define		BIT_DISPLAY_C		2		        // C 游标开关 1 = ON , 0 = OFF
#define		BIT_DISPLAY_B		1		        // B 游标位置开关 1 = ON , 0 = OFF


#define     TORIGHT   			0x14      	    //游标右走
#define     TOLEFT				0x10	    	//游标左走
#define     ALLRIGHT			0x1C	    	//整体右走
#define     ALLLEFT				0x18	    	//整体左走


#define     NOMAL_COMMAND		0x30	       //普通功能
#define     EXTRA_COMMAND		0x34           //扩展功能
#define     EXTRA_COMMAND_BIT   0x36           //与上共同开启绘图功能

#define		LCD_CMD_CGRAM		0x40		   // 设定CGRAM地址
#define		LCD_CMD_DDRAM		0x80		   // 设定DDRAM地址计数器

#define     LCD_DDRAM_1         0x80           //第1行地址
#define     LCD_DDRAM_2         0x90           //第2行地址
#define     LCD_DDRAM_3         0x88           //第3行地址
#define     LCD_DDRAM_4         0x98           //第4行地址
//==============================扩充指令集======================================
#define		LCD_EXT_CMD_HALT	0x01		  // 将DDRAM填满0x20,并且设定DDRAM的地址计数器AC到0x00
#define		LCD_EXT_CMD_RAM_EN	0x03		  // 卷动地址或RAM地址选择
#define		BIT_IRAM_SR		    0x01		  // SR = 1 允许输入垂直卷动地址 , SR = 0 允许输入RAM地址

#define		LCD_EXT_CMD_INV		0x04		  // 反白选
#define		BIT_INV_R1		1
#define		BIT_INV_R0		0

#define		LCD_EXT_CMD_SLEEP	0x08		  // 睡眠模式
#define		BIT_SLEEP_SL		2		      // SL = 1 脱离睡眠模式 , SL = 0进入睡眠模式

#define		LCD_EXT_CMD_MODE_SELECT	0x30	  // 扩充功能设定
#define		BIT_EXT_MODE_SELECT_RE	4		  // RE = 1 扩充指令集 , RE = 0 基本指令集.
#define		BIT_EXT_MODE_SELECT_G	2		  // G = 1 绘图显示ON , G = 0 绘图显示OFF

#define		LCD_EXT_CMD_IRAM		0x40	  // 设定IRAM地址或卷动地址
#define		LCD_EXT_CMD_GRAM_SET	0x80      // 设置绘图RAM地址


#define		ASCII_MAX_ROW		4
#define		ASCII_MAX_LINE		16



extern void LCD_Init(void);
extern uint8 point(uint8 x,uint8 y,uint8 value);
extern void line(uint8 x1,uint8 y1,uint8 x2,uint8 y2,uint8 value);
extern void LCD_RAMClear(void);
extern void LCD_Clear(void);
extern void LCD_SHOWStr(uint8 reg,uint8 *buf,uint8 num);
void LCD_ToExtra(void);
void LCD_ToNormal(void);
void LCD_Test(void);


#endif

