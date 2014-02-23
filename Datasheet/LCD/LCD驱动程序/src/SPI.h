#ifndef _SPI_H_
#define _SPI_H_

#include  "config.h"

#define   SPI_CS	(1<<29)			/* P0.29 ,2114			*/

extern  void  DelayNS(uint32  dly);
extern  void  MSPI_Init(void );
extern  uint8 MSPI_SendData(uint8 dat)	;

#endif												  
