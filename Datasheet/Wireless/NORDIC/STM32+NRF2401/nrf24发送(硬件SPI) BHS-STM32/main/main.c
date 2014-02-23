/*----------------------------------------------------------------------------
QQ: 958664258
21IC用户名：banhushui
交流平台：http://blog.21ic.com/user1/5817/index.html
淘宝店铺：http://shop58559908.taobao.com
旺旺：半壶水电子
编译器版本：MDK3.5
 *---------------------------------------------------------------------------*/

/* Includes ------------------------------------------------------------------*/
#define SYS_GLOBALS
#include "include.h"


void LEDFlash(void)
{static uint32 counter=0;
 static u8 flag=0;  
   
   IntervalTimems(500);
   if(flag==0)
   {
      flag=1;
      GPIO_SetBits(GPIOC, GPIO_Pin_11);
   }
   else
   {
      flag=0;
      GPIO_ResetBits(GPIOC, GPIO_Pin_11);
   }
   //GPIO_Write(GPIOC, (u16)~GPIO_ReadOutputData(GPIOC));
}

int main(void)
{

// u16 buf[64];
 
#ifdef DEBUG
  debug();
#endif

  /* System Clocks Configuration */
  RCC_Configuration();   

  GPIO_Configuration();
/* NVIC configuration */
  NVIC_Configuration();
  
  SysTick_Init();
  
  mySPI_Init();
  
  init_NRF24L01();
  NRF24_TX_Mode();

  while (1)
  {
    LEDFlash();
    
    NRF_Send();
  }
}



/*END OF FILE*/
