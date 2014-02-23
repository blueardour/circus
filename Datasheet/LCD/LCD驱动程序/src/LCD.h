/*----------------------------------------------------------
	RT12864 �ײ���������	
	��������:	2009.07.25
	�޸�����:
	Starli		V1.0
----------------------------------------------------------*/
#ifndef _LCD_H_
#define _LCD_H_
#include "config.h"
#include "SPI.h"
#include "Key.h"
#include "Delay.h"

//==========================ͬ���������Ͷ���====================================
#define		SYNC_WRITE_COMMAND	0xF8           //5����1������һ�����ڣ�RW=0 д��RS=0 ����
#define		SYNC_READ_COMMAND	0xFC		   //5����1������һ�����ڣ�RW=1 ����RS=0 ����
#define		SYNC_WRITE_DATA		0xFA           //5����1������һ�����ڣ�RW=0 д��RS=1 ����
#define		SYNC_READ_DATA		0xFE		   //5����1������һ�����ڣ�RW=1 ����RS=1 ����

//===========================Һ������ָ�����=================================
#define		LCD_CMD_CLRSCR		    0x01		//����,��0x20�������DDRAM,����AC��λ��0x00
#define		LCD_CMD_RESET_ADDRESS	0x02	    //��ַ��λ,����DDRAM�е�AC��0x00���ҽ��α��ƶ�����ͷ��ԭ��λ��
#define		LCD_CMD_DOT_MODE    	0x06		//������趨


#define		LCD_CMD_DISPLAY		0x08	    	// ��ʾ״̬����
#define		BIT_DISPLAY_D		4		        // D ������ʾ���� 1 = ON , 0 = OFF
#define		BIT_DISPLAY_C		2		        // C �α꿪�� 1 = ON , 0 = OFF
#define		BIT_DISPLAY_B		1		        // B �α�λ�ÿ��� 1 = ON , 0 = OFF


#define     TORIGHT   			0x14      	    //�α�����
#define     TOLEFT				0x10	    	//�α�����
#define     ALLRIGHT			0x1C	    	//��������
#define     ALLLEFT				0x18	    	//��������


#define     NOMAL_COMMAND		0x30	       //��ͨ����
#define     EXTRA_COMMAND		0x34           //��չ����
#define     EXTRA_COMMAND_BIT   0x36           //���Ϲ�ͬ������ͼ����

#define		LCD_CMD_CGRAM		0x40		   // �趨CGRAM��ַ
#define		LCD_CMD_DDRAM		0x80		   // �趨DDRAM��ַ������

#define     LCD_DDRAM_1         0x80           //��1�е�ַ
#define     LCD_DDRAM_2         0x90           //��2�е�ַ
#define     LCD_DDRAM_3         0x88           //��3�е�ַ
#define     LCD_DDRAM_4         0x98           //��4�е�ַ
//==============================����ָ�======================================
#define		LCD_EXT_CMD_HALT	0x01		  // ��DDRAM����0x20,�����趨DDRAM�ĵ�ַ������AC��0x00
#define		LCD_EXT_CMD_RAM_EN	0x03		  // ����ַ��RAM��ַѡ��
#define		BIT_IRAM_SR		    0x01		  // SR = 1 �������봹ֱ����ַ , SR = 0 ��������RAM��ַ

#define		LCD_EXT_CMD_INV		0x04		  // ����ѡ
#define		BIT_INV_R1		1
#define		BIT_INV_R0		0

#define		LCD_EXT_CMD_SLEEP	0x08		  // ˯��ģʽ
#define		BIT_SLEEP_SL		2		      // SL = 1 ����˯��ģʽ , SL = 0����˯��ģʽ

#define		LCD_EXT_CMD_MODE_SELECT	0x30	  // ���书���趨
#define		BIT_EXT_MODE_SELECT_RE	4		  // RE = 1 ����ָ� , RE = 0 ����ָ�.
#define		BIT_EXT_MODE_SELECT_G	2		  // G = 1 ��ͼ��ʾON , G = 0 ��ͼ��ʾOFF

#define		LCD_EXT_CMD_IRAM		0x40	  // �趨IRAM��ַ�����ַ
#define		LCD_EXT_CMD_GRAM_SET	0x80      // ���û�ͼRAM��ַ


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

