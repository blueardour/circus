#ifndef _OV7660_H
#define _OV7660_H

#include <avr/io.h>
#include "VARIABLE.h"
#include "font.h"
#include "SCCB.h"

#define CHANGE_REG_NUM 320



uchar wrOV7660Reg(uchar regID, uchar regDat);
uchar rdOV7660Reg(uchar regID, uchar *regDat);
void OV7660_config_window(uint startx,uint starty,uint width, uint height);
void my_delay_ms(uint time);//delay some time
uchar OV7660_init(void);


#endif /* _OV7660_H */



