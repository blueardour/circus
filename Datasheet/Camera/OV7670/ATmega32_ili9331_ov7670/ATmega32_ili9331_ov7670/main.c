#include <avr/io.h>
#include <avr/interrupt.h>
#include "ILI9331.H"
#include "ov7670.H"
#include "int.H"
#include "delay.h"


//CPU初始化//
int main(void) 
{

	EXCLK_DDR|=1<<EXCLK_BIT ;//en_exclk 引脚输出
	HC245_OE_DDR|=1<<HC245_OE_BIT;//en_245引脚输出
	
	DISEN_EXCLK;//禁止外部CLK，使单片机WR与TFT WR相连	
	DISEN_245;//禁止外部数据线，使单片机数据与TFT数据线相连
	
	DATA_OUPUT(); //数据线输出，准备连数据线到TFT
    LCD_Init();
	//Test();
	//Test_tu();
	Test_tu();
	delay_ms(3000);
	LCD_write_english_string(20,150,"Guanfu_Wang  2010-02-24",RED,BLACK);
	LCD_write_english_string(20,170,"Atmega32 & ILI9331 FOR OV7670 REV3.0",GREEN,BLACK);
	
	LCD_write_english_string(20,190,"OV7670 Init......",BLUE,BLACK);
	
	while(1!=OV7670_init());//初始化ov7660
	delay_ms(1000);
	LCD_write_english_string(20,190,"OV7670 Init  0K  ",RED,BLACK);
	delay_ms(1000);
	LCD_Clear(0);
    DATA_INPUT(); 
	Init_INT0();
	/**/
    while(1)
    {
	//Test();
	}

}

