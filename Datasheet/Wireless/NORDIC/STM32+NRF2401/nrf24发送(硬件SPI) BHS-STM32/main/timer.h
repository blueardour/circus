#if !defined( _TIMER_H )
#define _TIMER_H

void SysTick_Init(void);

void Delayms(u32 nTime);

#define  Wait_ms  Delayms

void TimingDelay_Decrement(void);



#endif

