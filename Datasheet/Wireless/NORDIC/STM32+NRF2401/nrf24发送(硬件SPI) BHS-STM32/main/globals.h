#if !defined( _GLOBALS_H )
#define _GLOBALS_H



#ifdef   SYS_GLOBALS
  #define  GLOBALS
#else
  #define  GLOBALS  extern
#endif

GLOBALS uint32 volatile gTimer_1ms;

GLOBALS uint8 gBigBuf[4096];//FLASH_SECTOR_SIZE
#define  IntervalTimems(time)          \
{                                        \
   if( (gTimer_1ms-counter)>=(time) )    \
     counter=gTimer_1ms;                 \
   else                                  \
    return;                              \
}

#endif

