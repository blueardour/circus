#include "include.h"


/*
说明：
1.buf,必须比实际空间多1byte
2.n<65535
3.存储器为大端模式
ARM 大端模式 同51结构相同
ARM 小端模式 同51结构相反, 要做相应修改
*/
uint16 Check_Sum(uint8 *buf, uint16 n)
{uint16 check=0;
 uint16  temp;
   
   if( (n%2) != 0 )//不是偶数
   {
      buf[n]=0;
      n++;
   }
   n /= 2;
   
   while(n--)
   {
      cpyU16fU8(temp, buf);
      
      buf++;buf++;
      check += temp;
      //check += *pbuf++;
   }
   return(~check);
}

//16位数据交换高低字节
void swp16HL(uint16 *dat)
{uint16 temp;
   
   temp=(*dat)>>8;
   temp+=(*dat)<<8;
   (*dat)=temp;
}

