NOTE: AVR Code addresses are word addresses
All other addresses (including ones in FLASH) are byte addresses

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                           idata   0054   001D =     29. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0054  __idata_start
       0071  __idata_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            text   0072   0922 =   2338. bytes (rel,con,rom)

       Addr  Global Symbol
      -----  --------------------------------
       0039  __text_start
       0039  __start
       0059  _exit
       005A  _speaData
       00B9  _I2C_Start
       00C6  _I2C_Restart
       00D3  _I2C_SendWrDAdr
       00E1  _I2C_SendWrDAdr_
       00FB  _I2C_SendRdDAdr
       0109  _I2C_SendRdDAdr_
       0123  _I2C_SendDat
       0131  _I2C_RcvNAckDat
       0141  _I2C_RcvAckDat
       0151  _I2C_Write
       0172  _I2C_Read
       019F  _I2C_Read_
       01E1  _delay50us
       01F3  _delay50ms
       0209  _SPI_init
       0212  _lcd_wrByte
       0216  _lcd_wrCmd
       0223  _lcd_wrDat
       0230  _lcd_set_xy
       025B  _lcd_putc
       026F  _lcd_putd0
       02A9  _lcd_putd
       035E  _lcd_puts
       0381  _lcd_puts_
       03A5  _lcd_clr
       03AC  _lcd_init
       03C0  _main
       03D4  push_arg4
       03D6  push_arg2
       03D9  div32u
       03DB  mod32u
       03DF  div32s
       03E1  mod32s
       040C  long_div_prolog
       041F  long_div_epilog
       042E  tst_R16_R19
       0433  tst_R24_R27
       0438  neg_R16_R19
       0441  neg_R24_R27
       044A  empy32u
       044A  empy32s
       047A  pop_gset2
       047D  pop_gset3
       0480  pop_gset4
       0483  pop_gset5
       0486  push_gset5
       0488  push_gset4
       048A  push_gset3
       048C  push_gset2
       048E  push_gset1
       0491  pop_gset1
       0492  pop
       04A5  long_prolog
       04B3  long_epilog
       04BE  tstzero1
       04C4  tstzero2
       04CA  __text_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                            data   0060   001D =     29. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       0060  __data_start
       007D  __data_end

Area                               Addr   Size   Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                             bss   007D   0006 =      6. bytes (rel,con,ram)

       Addr  Global Symbol
      -----  --------------------------------
       007D  __bss_start
       007D  _dataElem
       0083  __bss_end

Area                               Start  End    Decimal Bytes (Attributes)
--------------------------------   ----   ----   ------- ----- ------------
                          vector   0000   0004 =      4. bytes (abs,ovr,rom)

Files Linked      [ module(s) ]

c:\icc\lib\crtatmega.o	[ crtatmega.s ]
LCD12864_ST7920.o	[ LCD12864_ST7920.C ]
<library>	[ asave.s, div32.s, emul32.s, gpop2.s, gpop3.s, gpop4.s, gpop5.s, gpush.s, longutil.s ]

User Global Definitions

ram_end = 0x45f
hwstk_size = 0x10

User Base Address Definitions

func_lit = 0x54
data = 0x60
eeprom:1.512

