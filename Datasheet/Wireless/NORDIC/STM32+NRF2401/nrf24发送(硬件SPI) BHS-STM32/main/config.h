#if !defined( _CONFIG_H )
#define _CONFIG_H

#include "myGPIOType.h"

//-----------------------------------------------------------------------------------------------------

//#define  myGPIO_SetBits(PORT, Bit)     SetBit32(PORT->ODR, Bit)
//#define  myGPIO_ResetBits(PORT, Bit)   ClrBit32(PORT->ODR, Bit)

//#define  myGPIO_SetBits(PORT, Bit)     GPIO_SetBits(PORT, BIT16(Bit))
//#define  myGPIO_ResetBits(PORT, Bit)   GPIO_ResetBits(PORT, BIT16(Bit))

#define  myGPIO_SetBits(PORT, Bit)     ( PORT->BSRR=BIT16(Bit) )
#define  myGPIO_ResetBits(PORT, Bit)   ( PORT->BRR=BIT16(Bit) )

//485����-------------------------------------------------------------
/******************* ������PC����ͨѶΪ485 ****************/
//#define PC_RS485
#define PC_RS485CAN
/******************* �������������ͨѶΪ485 ****************/
#define RS485

//Ӳ������
#define  RCC_APB2Periph_PC_RS485DIR  RCC_APB2Periph_GPIOB
#define  PC_RS485DIR_PORT    GPIOB
#define  PC_RS485DIR_PIN     0

//#ifdef PC_RS485
#if defined(PC_RS485)
  #define PC_RS485Send_Enable()     myGPIO_SetBits(PC_RS485DIR_PORT, PC_RS485DIR_PIN)
  #define PC_RS485Receive_Enable()  myGPIO_ResetBits(PC_RS485DIR_PORT, PC_RS485DIR_PIN)

#elif defined(PC_RS485CAN)
  #define PC_RS485Send_Enable()     //(USART1->CR1 &= ~USART_FLAG_RXNE)    //�رմ���1�����ж�
  #define PC_RS485Receive_Enable()  //(USART1->CR1 |= USART_FLAG_RXNE)//�򿪴���1�����ж�
  //���ʹ��CANоƬ,ͨ���رս����ж��л����շ���״̬��������ɽ����ж�һֱ�ر��޷���������
#else
  #define PC_RS485Send_Enable()     
  #define PC_RS485Receive_Enable()  

#endif
//--------------------------------------------------------------------

//LED����-------------------------------------------------------------
#define  RCC_APB2Periph_LED  RCC_APB2Periph_GPIOC
#define LED_PORT    GPIOC  //GPIOC
#define LED_PIN    13  
  
  #define LED_Green_ON()   myGPIO_ResetBits(LED_PORT, LED_PIN)//SetBit32(LEDPORT->ODR, 13)
  #define LED_Green_OFF()  myGPIO_SetBits(LED_PORT, LED_PIN)//ClrBit32(LEDPORT->ODR, 13)


#endif
