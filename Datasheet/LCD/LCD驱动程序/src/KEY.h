#ifndef	_KEY_H_
#define _KEY_H_

#include "config.h"

/*°´¼üÒı½ÅP0.16-P0.21*/
#define 	KEY1	(1<<16)
#define 	KEY2	(1<<17)
#define 	KEY3	(1<<18)
#define 	KEY4	(1<<19)
#define		KEY5	(1<<20)
#define 	KEY6	(1<<21)

extern void KeyInit(void);
extern uint8 KeyRead(void);

#endif
