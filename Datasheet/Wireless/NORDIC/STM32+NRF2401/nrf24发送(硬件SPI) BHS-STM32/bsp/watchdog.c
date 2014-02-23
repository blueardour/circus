#include "..\main\include.h"
//#include "include.h"


#define __myIWDG_PERIOD           0x0000007D
#define __myIWDG_PR             (0)
#define __myIWDGCLOCK   (32000UL/4)
#define __myIWGDCLK  (32000UL/(0x04<<__myIWDG_PR))
#define __myIWDG_RLR (__myIWDG_PERIOD*__myIWGDCLK/1000000UL-1)

//看门狗初始化。喂狗时间短，用于系统复位
void ShortTimeIwdgSetup (void) 
{

//  RCC->CSR |= (1<<0);                                           // LSI enable, necessary for IWDG
//  while ((RCC->CSR & (1<<1)) == 0);                             // wait till LSI is ready

  IWDG->KR  = 0x5555;                                           // enable write to PR, RLR
  IWDG->PR  = __myIWDG_PR;                                        // Init prescaler
  IWDG->RLR = __myIWDG_RLR;                                       // Init RLR
  IWDG->KR  = 0xAAAA;                                           // Reload the watchdog
  IWDG->KR  = 0xCCCC;                                           // Start the watchdog
} // end of stm32_IwdgSetup

void Watchdog(void)
{
    IWDG->KR  = 0xAAAA;                           // reload the watchdog
}





