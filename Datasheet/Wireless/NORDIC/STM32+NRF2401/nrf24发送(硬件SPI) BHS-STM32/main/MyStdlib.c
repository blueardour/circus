#include "include.h"


/*
˵����
1.buf,�����ʵ�ʿռ��1byte
2.n<65535
3.�洢��Ϊ���ģʽ
ARM ���ģʽ ͬ51�ṹ��ͬ
ARM С��ģʽ ͬ51�ṹ�෴, Ҫ����Ӧ�޸�
*/
uint16 Check_Sum(uint8 *buf, uint16 n)
{uint16 check=0;
 uint16  temp;
   
   if( (n%2) != 0 )//����ż��
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

//16λ���ݽ����ߵ��ֽ�
void swp16HL(uint16 *dat)
{uint16 temp;
   
   temp=(*dat)>>8;
   temp+=(*dat)<<8;
   (*dat)=temp;
}

