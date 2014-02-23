#include <avr/io.h>
#include <avr/interrupt.h>
#include "ILI9331.H"
#include "ov7670.H"
#include "int.H"
#include "delay.h"


//CPU��ʼ��//
int main(void) 
{

	EXCLK_DDR|=1<<EXCLK_BIT ;//en_exclk �������
	HC245_OE_DDR|=1<<HC245_OE_BIT;//en_245�������
	
	DISEN_EXCLK;//��ֹ�ⲿCLK��ʹ��Ƭ��WR��TFT WR����	
	DISEN_245;//��ֹ�ⲿ�����ߣ�ʹ��Ƭ��������TFT����������
	
	DATA_OUPUT(); //�����������׼���������ߵ�TFT
    LCD_Init();
	//Test();
	//Test_tu();
	Test_tu();
	delay_ms(3000);
	LCD_write_english_string(20,150,"Guanfu_Wang  2010-02-24",RED,BLACK);
	LCD_write_english_string(20,170,"Atmega32 & ILI9331 FOR OV7670 REV3.0",GREEN,BLACK);
	
	LCD_write_english_string(20,190,"OV7670 Init......",BLUE,BLACK);
	
	while(1!=OV7670_init());//��ʼ��ov7660
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

