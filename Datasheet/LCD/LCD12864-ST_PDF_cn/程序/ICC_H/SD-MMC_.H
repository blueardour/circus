/*********************************************************************
	微 雪 电 子   WaveShare   http://www.waveShare.net            	
		                                                        
目    的:   建立SD-MMC操作库
	
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

#ifndef SD_MMC_H
#define SD_MMC_H

// constants/macros/typdefs
// MMC commands (taken from sandisk MMC reference)
#define MMC_GO_IDLE_STATE			0
#define MMC_SEND_OP_COND			1
#define MMC_SEND_CSD				9
#define MMC_SEND_CID				10
#define MMC_SEND_STATUS				13
#define MMC_SET_BLOCKLEN			16
#define MMC_READ_SINGLE_BLOCK		17
#define MMC_WRITE_BLOCK				24
#define MMC_PROGRAM_CSD				27
#define MMC_SET_WRITE_PROT			28
#define MMC_CLR_WRITE_PROT			29
#define MMC_SEND_WRITE_PROT			30
#define MMC_TAG_SECTOR_START		32
#define MMC_TAG_SECTOR_END			33
#define MMC_UNTAG_SECTOR			34
#define MMC_TAG_ERASE_GROUP_START 	35
#define MMC_TAG_ERARE_GROUP_END		36
#define MMC_UNTAG_ERASE_GROUP		37
#define MMC_ERASE					38
#define MMC_CRC_ON_OFF				59
// R1 Response bit-defines
#define MMC_R1_BUSY					0x80
#define MMC_R1_PARAMETER			0x40
#define MMC_R1_ADDRESS				0x20
#define MMC_R1_ERASE_SEQ			0x10
#define MMC_R1_COM_CRC				0x08
#define MMC_R1_ILLEGAL_COM			0x04
#define MMC_R1_ERASE_RESET			0x02
#define MMC_R1_IDLE_STATE			0x01
// Data Start Tokens
#define MMC_STARTBLOCK_READ			0xFE
#define MMC_STARTBLOCK_WRITE		0xFE
#define MMC_STARTBLOCK_MWRITE		0xFC
// Data Stop tokens
#define MMC_STOPTRAN_WRITE			0xFD
// Data Error Token values
#define MMC_DE_MASK					0x1F
#define MMC_DE_ERROR				0x01
#define MMC_DE_CC_ERROR				0x02
#define MMC_DE_ECC_FAIL				0x04
#define MMC_DE_OUT_OF_RANGE			0x04
#define MMC_DE_CARD_LOCKED			0x04
// Data Response Token values
#define MMC_DR_MASK					0x1F
#define MMC_DR_ACCEPT				0x05
#define MMC_DR_REJECT_CRC			0x0B
#define MMC_DR_REJECT_WRITE_ERROR	0x0D

/*--------------------------------------------------------------------
函数全称：SPI 初始化
函数功能：
注意事项：
提示说明：
输    入：	
返    回：
--------------------------------------------------------------------*/
void spi_init(void) 
{
	sbi(DDRB,7);
	cbi(DDRB,6);
	sbi(DDRB,5);
	sbi(DDRB,4);
	SPCR = (1<<SP) | (1<<MSTR) | (1<<SPR1) | (1<<SPR0);
}
/*--------------------------------------------------------------------
函数全称：从SPI发送一个数据并返回一个获取的数据
函数功能：
注意事项：
提示说明：
输    入：	
返    回：
--------------------------------------------------------------------*/
uint8 spi_(uint8 byte)
{ 
	SPDR = byte;
	while(!(SPSR & (1<<SPIF)));
	return (SPDR);
}
/*--------------------------------------------------------------------
函数全称：发送一个命令给MMC
函数功能：
注意事项：
提示说明：命令格式：0xFF, 命令, 地址, (CRC), 0xFF
输    入：	
返    回：
--------------------------------------------------------------------*/
uint8 MMC_setCmd(uint8 cmd, uint16 adrH, uint16 adrL)
{	
	spi_(0xFF);
	spi_(cmd|0x40);
	spi_((uint8)(adrH >> 8));
	spi_((uint8)adrH);
	spi_((uint8)(adrL >> 8));
	spi_((uint8)adrL);
	spi_(0x95);				//第一个命令不能少，之后可以省去
	spi_(0xFF);
	return spi_(0xFF);		//返回最后一个接收的数据
}
/*--------------------------------------------------------------------
函数全称：MMC初始化
函数功能：
注意事项：
提示说明：
输    入：	
返    回：
--------------------------------------------------------------------*/
bool MMC_init(void) 
{ 
	uint8 i;

/* 为选中MMC， 必须先发送 10*8=80 个'1' */
	sbi(PORTB,4);
	for(i=0; i < 10; i++)	
		spi_(0xFF);			
	cbi(PORTB,4);

	if(MMC_setCmd(MMC_GO_IDLE_STATE,0,0) != 1) 
	{
		dispMMCErr();
		return 0;
	}
	
	while(MMC_setCmd(MMC_SEND_OP_COND,0,0) !=0)	
		dispMMCChkExist();

	return 1;
}

uint16 gTimeout = 0xFF;
uint8 gGetDat;
/*--------------------------------------------------------------------
函数全称：MMC 获取状态
函数功能：
注意事项：
提示说明：
输    入：	
返    回：
--------------------------------------------------------------------*/
uint8 MMC_getSta(void)
{	
	gGetDat = 0xFF;
	gTimeout = 0xFFFF;
	while( (gGetDat==0xFF) && (gTimeout--) ) 
		gGetDat = spi_(0xFF);
	return gGetDat;
}
/*--------------------------------------------------------------------
函数全称：MMC 等待空闲信号
函数功能：
注意事项：
提示说明：
输    入：	
返    回：
--------------------------------------------------------------------*/
uint8 MMC_waitIdle(void)
{
	gGetDat = 0;
	gTimeout = 0xFFFF;
	while( (gGetDat!=0xFF)&& (gTimeout--) ) 
		gGetDat = spi_(0xFF);
	return gGetDat;
}
/*--------------------------------------------------------------------
函数全称：MMC 等待起始信号
函数功能：
注意事项：
提示说明：
输    入：	
返    回：
--------------------------------------------------------------------*/
uint8 MMC_waitStart(void)
{
	gGetDat = 0xFF;
	gTimeout = 0xFFFF;
	while( (gGetDat!=0xFE) && (gTimeout--) ) 
		gGetDat = spi_(0xFF);
	return gGetDat;
}
/*--------------------------------------------------------------------
函数全称：MMC 写内容到第一个扇区
函数功能：
注意事项：
提示说明：这里先指定到第一个扇区作为测试
输    入：	
返    回：
--------------------------------------------------------------------*/
bool MMC_writeSector(uint8 *pWrDat) 
{ 
	uint16 i;

	if(MMC_setCmd(MMC_WRITE_BLOCK,0,512) !=0)	//设置 块 写命令
		return 0;	

	spi_(0xFE);						//发送 起始标志	

	for(i=0;i<512;i++)				
		spi_(*pWrDat++);			//发送数据

	spi_(0xFF);						//发送 2 个 dummy 字节
	spi_(0xFF);

	if( (spi_(0xFF)&0x1F) != 0x05 )	//0x1F = 0b 0001 1111
		return 0;					//0x05 = 0b 0000 0101

	MMC_waitIdle();

	return 1;
}
/*--------------------------------------------------------------------
函数全称：MMC 读内容到第一个扇区
函数功能：
注意事项：
提示说明：这里先指定到第一个扇区作为测试
输    入：	
返    回：
--------------------------------------------------------------------*/
bool MMC_readSector(uint8 *pRdDat) 
{ 
	uint16 i;
	uint8 watchVal=0;				//调试帮助变量

	if(MMC_setCmd(MMC_READ_SINGLE_BLOCK,0,512) != 0)//设置 块 读命令
		return 0;
	
	MMC_waitStart();				//等待 起始信号

	for(i=0;i<512;i++)				//读取数据
	{
		*pRdDat++ = spi_(0xFF);
		watchVal = *(pRdDat-1);		//调试帮助变量
	}
	spi_(0xFF);						//发送 2 个 dummy 字节
	spi_(0xFF);
}

#endif

