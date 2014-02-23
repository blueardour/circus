#include  "config.h"
#include "SPI.h"
#include "LCD.h"
#include "KEY.h"
#include "Delay.h"

int  main(void)
{  
   	KeyInit();
	MSPI_Init();
	LCD_Init();
	LCD_Test();
	while(1);
   	return(0);
}



