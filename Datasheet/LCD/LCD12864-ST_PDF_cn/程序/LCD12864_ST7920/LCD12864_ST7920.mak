CC = iccavr
CFLAGS =  -Ic:\icc\include\ -e -DATMEGA -DATMega16  -l -g -Mavr_enhanced 
ASFLAGS = $(CFLAGS)  -Wa-g
LFLAGS =  -Lc:\icc\lib\ -g -ucrtatmega.o -bfunc_lit:0x54.0x4000 -dram_end:0x45f -bdata:0x60.0x45f -dhwstk_size:16 -beeprom:1.512 -fihx_coff -S2
FILES = LCD12864_ST7920.o 

LCD12864_ST7920:	$(FILES)
	$(CC) -o LCD12864_ST7920 $(LFLAGS) @LCD12864_ST7920.lk   -lcatmega
LCD12864_ST7920.o: c:/icc/include/iom16v.h D:\ICC_H\LCD12864_ST7920.H D:\ICC_H\CmmIcc.h c:/icc/include/math.h c:/icc/include/string.h c:/icc/include/_const.h c:/icc/include/stdio.h c:/icc/include/stdarg.h c:/icc/include/_const.h\
 c:/icc/include/macros.h c:/icc/include/eeprom.h D:\ICC_H\Software.H c:/icc/include/math.h c:/icc/include/string.h D:\ICC_H\Hardware.H c:/icc/include/math.h c:/icc/include/string.h c:/icc/include/stdio.h c:/icc/include/macros.h\
 c:/icc/include/eeprom.h D:\ICC_H\I2C.H D:\ICC_H\CmmICC.H
LCD12864_ST7920.o:	E:\微雪电子CD1\产品资料\开发板实验板\SMK系列\SMK1632\实验教程\外围模块相关实验\LCD128~1\LCD12864_ST7920\LCD12864_ST7920.C
	$(CC) -c $(CFLAGS) E:\微雪电子CD1\产品资料\开发板实验板\SMK系列\SMK1632\实验教程\外围模块相关实验\LCD128~1\LCD12864_ST7920\LCD12864_ST7920.C
