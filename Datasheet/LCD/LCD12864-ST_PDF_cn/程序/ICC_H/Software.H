/*********************************************************************
	微 雪 电 子   WaveShare   http://www.waveShare.net            	
		                                                        
目    的:   建立AVR的软件提取库，增加各类补丁，方便系统程序移植
	
目标系统:   基于AVR单片机
		                                                                
应用软件:   ICCAVR
		                                                                
版    本:   Version 1.0                                                       
		                                                                
圆版时间:   2005-06-25
	
开发人员:   SEE

说    明:   若用于商业用途，请保留此段文字或注明代码来源
	
	深 圳 市 微 雪 电 子 有 限 公 司 保 留 所 有 的 版 权     
*********************************************************************/

/*01010101010101010101010101010101010101010101010101010101010101010101
----------------------------------------------------------------------
版本更新记录：

----------------------------------------------------------------------
入口参数说明：

----------------------------------------------------------------------
待定参数说明：

----------------------------------------------------------------------	
对外变量说明：
    
----------------------------------------------------------------------
对外函数说明：
   
----------------------------------------------------------------------
10101010101010101010101010101010101010101010101010101010101010101010*/

#ifndef Software_H
#define Software_H

#include <math.h>
#include <string.h>

/* 兼容一般程序员的常用写法 */
typedef unsigned char	uchar;
typedef unsigned int	uint;
typedef unsigned long	ulong;
typedef signed char		schar;
typedef signed int		sint;
typedef signed long		slong;

/* 为方便移植，建议使用下面写法 */
typedef unsigned char	bool;
typedef unsigned char	uint8;
typedef unsigned int	uint16;
typedef unsigned long   uint32;
typedef signed  char	sint8;
typedef signed	int		sint16;
typedef signed	long	sint32;
typedef signed  char	int8;
typedef signed  int		int16;
typedef signed  long	int32;

/* 下面写法一般不推荐 */
//typedef unsigned char ubyte;
//typedef unsigned int	uword;
//typedef unsigned long udword;
//typedef signed   char	sbyte;
//typedef signed   int	sword;
//typedef signed   long	sdword;

/* 一般程序定义的默认值 */
//#define NULL			0
//#define EOF			-1
//#define TRUE   		1
//#define FALSE  		0
//#define YES   		1
//#define NO  			0
//#define ON			1
//#define OFF			0
//#define ENABLE   		1
//#define DISABLE		0
//#define CRR			1
//#define ERR			0
//#define RIGHT			1
//#define WRONG			0
//#define SUCCESS		1
//#define FAILURE		0
//#define PI			3.1415926	//3.1415926535897932

/* 如果你手头上的RAM实在很紧，不如尝试下面的define～ */
//#define _CALLOC(a)		( (a *)calloc(n,sizeof(a)) )
//#define _MALLOC(a)		( (a *)malloc(sizeof(a)) )
//#define _MIN(a,b)			( (a) < (b) ? (a) : (b) )
//#define _MAX(a,b)			( (a) > (b) ? (a) : (b) )
//#define _EXCHANGE(a,b)	{ int t; t=a; a=b; b=t; }
//#define _TOLOWER(c)		( (c)+32 )
//#define _TOUPPER(c)		( (c)-32 )

//#ifndef BIT
//#define BIT(x)	( 1<<(x) )
//#endif

/*--------------------------------------------------------------------
函数全称：数据拆字
函数功能：
注意事项：D<=999999,C<=6
提示说明：调用speaData(12,2)，得到dataElem[0]=2，dataElem[1]=1
输    入：
返    回：无
--------------------------------------------------------------------*/
uint8 dataElem[6];
void speaData(uint32 dat,sint8 len)
{
    uint8 i;
    uint32 j,y;
    for(i=0,j=1;i<len;i++)
    {
        y=dat/j;
        dataElem[i]=y%10;
        j*=10;
    }
}
/*--------------------------------------------------------------------
函数全称：十进制强制转换为十六进制
函数功能：
注意事项：
提示说明：调用changeIntToHex（33），return 0x33
输    入：
返    回：
--------------------------------------------------------------------*/
#define changeIntToHex(dec)		( ( ((dec)/10) <<4 ) + ((dec)%10) )
/*--------------------------------------------------------------------
函数全称：十进制化为十六进制，并以十进制格式返回
函数功能：
注意事项：传参必须为 unsigned 类型，否则移位结果可能吓你一跳
提示说明：调用converseIntToHex（33），return 21
输    入：
返    回：
--------------------------------------------------------------------*/
#define converseIntToHex(dec)	( ( ((dec)>>4) *10 ) + ((dec)%16) )
/*--------------------------------------------------------------------
函数全称：十六进制强制转换为十进制
函数功能：
注意事项：传参必须为 unsigned 类型，否则移位结果可能吓你一跳
提示说明：调用changeHexToInt（0x33），return 33
输    入：
返    回：
--------------------------------------------------------------------*/
#define changeHexToInt(hex)		( ( ((hex)>>4) *10 ) + ((hex)%16) )
/*--------------------------------------------------------------------
函数全称：十六进制化为十进制，，并以十六进制格式返回
函数功能：
注意事项：
提示说明：调用converseHexToInt（0x33），return 0x51
输    入：
返    回：
--------------------------------------------------------------------*/
#define converseHexToInt(hex)	( ( ((hex)/10) <<4 ) + ((hex)%10) )

#endif
