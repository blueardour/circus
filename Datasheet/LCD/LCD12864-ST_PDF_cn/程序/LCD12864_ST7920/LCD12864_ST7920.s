	.module LCD12864_ST7920.C
	.area text(rom, con, rel)
	.dbfile D:\ICC_H\Software.H
	.dbfunc e speaData _speaData fV
;              y -> y+4
;              j -> y+0
;              i -> R10
;            len -> R12
;            dat -> y+16
	.even
_speaData::
	xcall push_arg4
	xcall push_gset4
	sbiw R28,8
	ldd R12,y+20
	.dbline -1
	.dbline 116
; /*********************************************************************
; 	н╒ я╘ ╣Г вс   WaveShare   http://www.waveShare.net            	
; 		                                                            
; д©    ╣д:   ╫╗а╒╡ывВLCD12864_ST7920р╨╬╖╣дй╬юЩЁлпР
; 
; д©╠Йо╣мЁ:   ╩Ысзхн╨нAVR╣╔ф╛╩З
; 		                                                                
; с╕сцхМ╪Ч:   ICCAVR
; 		                                                                
; ╟Ф    ╠╬:   Version 1.0                                                          
; 		                                                                
; т╡╟Фй╠╪Д:   2005-06-25
; 	
; ©╙╥╒хкт╠:   SEE
; 
; к╣    цВ:   хТсцсзилр╣сцм╬ё╛гК╠ёаТ╢к╤нндвж╩Рв╒цВ╢ЗбКю╢т╢
; 	
; 	иН шз йп н╒ я╘ ╣Г вс сп оч ╧╚ к╬ ╠ё аТ кЫ сп ╣д ╟Ф х╗
; *********************************************************************/
; 
; /*01010101010101010101010101010101010101010101010101010101010101010101
; ----------------------------------------------------------------------
; ╟Ф╠╬╦Эпб╪гб╪ё╨
; 
; ----------------------------------------------------------------------
; й╣яИдзхщё╨
; ЁУй╪╩╞║╒╤ап╢Lcd12864_ST7920║ё
; ----------------------------------------------------------------------
; с╡╪Ча╛╫сё╨
; LCD12864_ST7920			ATmega16
; 1.GND		--------	GND
; 2.VCC		--------	VCC
; 3.V0		--------	V0
; 4.RS(CS)	--------	VCC
; 5.R/W(SID)	--------	MOSI/PB5
; 6.E(SCLK)	--------	SCK/PB7
; 7.D0		--------	NC
; 8.D1		--------	NC
; 9.D2		--------	NC
; 10.D3		--------	NC
; 11.D4		--------	NC
; 12.D5		--------	NC
; 13.D6		--------	NC
; 14.D7		--------	NC
; 15.PSB		--------	GND
; 16.NC		--------	NC
; 17.RST		--------	NC
; 18.NC		--------	NC
; 19.LED+		--------	VCC
; 20.LED-		--------	GND
; 
; ╡ывВ╡╫жХё╨
; (1)╠ЮрКиуп╢╦цЁлпР╣╫ATmega16ё╛╤о©╙╣Гт╢
; (2)хТй╧сцISP╫с©зиуп╢ЁлпРё╛гК╤о©╙ISPиуп╢фВ
; ё╗сисз╠╬й╬юЩЁлпРй╧сц╣дйгATmega16╣дSPI╫с©зё╛╦у╨цйгISPиуп╢фВ╣диуп╢©зё╘
; (3)╫╚LCD12864_ST7920╡ЕхКжВ╟Е╣дLcd12864╡Е╡ш
; (4)й╧сца╛╫соъ╫╚LCD12864_ST7920╣дртобрЩуК╫с©за╛╫с╣╫MCUё╨
; ё╗сисзSMK1632ря╬╜вЖ╨цак╢С╡©╥ж╣дс╡╪Ча╛╫сё╛дЗж╩пХа╛╫сртобйЩ╬щ╤к©зё╘
; LCD12864_ST7920			ATmega16
; 4.RS(CS)	--------	VCC
; 5.R/W(SID)	--------	MOSI/PB5
; 6.E(SCLK)	--------	SCK/PB7
; 15.PSB		--------	GND
; (5)ио╣Гё╛хГ╧Ш╡ывВуЩх╥ё╛уБй╠дЗ©ирт©╢╣╫отй╬╣ддзхщак
; 
; ----------------------------------------------------------------------
; в╒рБйбоНё╨
; ё╗1ё╘хТсп╪сть©Б╨╞йЩё╛гК╫╚╧Бел╦Ыд©б╪об╣д║╟©Б╨╞йЩ║╠об╣д║╟ICC_H║╠нд╪Ч╪п©╫╣╫Dел 
; ё╗2ё╘гКоЙо╦тд╤аё╨╧Бел╦Ыд©б╪об╣д║╟╡Зф╥вйао\©╙╥╒╟Ей╣яИ╟Е\SMKо╣ап\SMK1632\к╣цВвйао║╠
; ----------------------------------------------------------------------
; 10101010101010101010101010101010101010101010101010101010101010101010*/
; 
; #include <iom16v.h>
; 
; #include "D:\ICC_H\LCD12864_ST7920.H"
; 
; /*--------------------------------------------------------------------
; ╨╞йЩцШЁфё╨
; ╨╞йЩ╧╕дэё╨
; в╒рБйбоНё╨
; лАй╬к╣цВё╨
; йД    хКё╨
; ╥╣    ╩ьё╨
; --------------------------------------------------------------------*/
; void main()
; {             
; 	SEI();
; 	lcd_init();
; 	lcd_puts(1,1,"  WaveShare.net");
; 	lcd_puts(3,1,"    н╒я╘╣Гвс");
; 	while(1);
; }
; }
; }
; }
; }
; }
; }
; }
; }
; }
; }
; }
; }
; }
; }
; }
; }
; }
; }
; }
; }
; }
; }
; }
; }
	.dbline 119
; }
; }
; }
	clr R10
	ldi R20,1
	ldi R21,0
	ldi R22,0
	ldi R23,0
	movw R30,R28
	std z+0,R20
	std z+1,R21
	std z+2,R22
	std z+3,R23
	xjmp L5
L2:
	.dbline 120
	.dbline 121
	movw R30,R28
	ldd R2,z+0
	ldd R3,z+1
	ldd R4,z+2
	ldd R5,z+3
	movw R30,R28
	ldd R6,z+16
	ldd R7,z+17
	ldd R8,z+18
	ldd R9,z+19
	st -y,R5
	st -y,R4
	st -y,R3
	st -y,R2
	movw R16,R6
	movw R18,R8
	xcall div32u
	movw R30,R28
	std z+4,R16
	std z+5,R17
	std z+6,R18
	std z+7,R19
	.dbline 122
	ldi R20,10
	ldi R21,0
	ldi R22,0
	ldi R23,0
	movw R30,R28
	ldd R2,z+4
	ldd R3,z+5
	ldd R4,z+6
	ldd R5,z+7
	st -y,R23
	st -y,R22
	st -y,R21
	st -y,R20
	movw R16,R2
	movw R18,R4
	xcall mod32u
	ldi R24,<_dataElem
	ldi R25,>_dataElem
	mov R30,R10
	clr R31
	add R30,R24
	adc R31,R25
	std z+0,R16
	.dbline 123
	movw R30,R28
	ldd R2,z+0
	ldd R3,z+1
	ldd R4,z+2
	ldd R5,z+3
	ldi R20,10
	ldi R21,0
	ldi R22,0
	ldi R23,0
	st -y,R5
	st -y,R4
	st -y,R3
	st -y,R2
	movw R16,R20
	movw R18,R22
	xcall empy32u
	movw R30,R28
	std z+0,R16
	std z+1,R17
	std z+2,R18
	std z+3,R19
	.dbline 124
L3:
	.dbline 119
	inc R10
L5:
	.dbline 119
	cp R10,R12
	brsh X0
	xjmp L2
X0:
	.dbline -2
L1:
	adiw R28,8
	xcall pop_gset4
	adiw R28,4
	.dbline 0 ; func end
	ret
	.dbsym l y 4 l
	.dbsym l j 0 l
	.dbsym r i 10 c
	.dbsym r len 12 C
	.dbsym l dat 16 l
	.dbend
	.dbfile D:\ICC_H\I2C.H
	.dbfunc e I2C_Start _I2C_Start fc
	.even
_I2C_Start::
	.dbline -1
	.dbline 128
; }
; }
; }
; }
; }
; }
; }
; }
; }
	.dbline 129
; }
	ldi R24,164
	out 0x36,R24
	.dbline 130
L7:
	.dbline 130
L8:
	.dbline 130
; }
	in R2,0x36
	sbrs R2,7
	rjmp L7
	.dbline 130
	.dbline 130
	.dbline 131
; }
	in R24,0x1
	andi R24,248
	cpi R24,8
	breq L10
	.dbline 132
; }
	clr R16
	xjmp L6
L10:
	.dbline 133
; }
	ldi R16,1
	.dbline -2
L6:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e I2C_Restart _I2C_Restart fc
	.even
_I2C_Restart::
	.dbline -1
	.dbline 144
; }
; }
; }
; }
; }
; }
; }
; }
; }
; }
; }
	.dbline 145
; }
	ldi R24,164
	out 0x36,R24
	.dbline 146
L13:
	.dbline 146
L14:
	.dbline 146
; }
	in R2,0x36
	sbrs R2,7
	rjmp L13
	.dbline 146
	.dbline 146
	.dbline 147
; }
	in R24,0x1
	andi R24,248
	cpi R24,16
	breq L16
	.dbline 148
; }
	clr R16
	xjmp L12
L16:
	.dbline 149
; }
	ldi R16,1
	.dbline -2
L12:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e I2C_SendWrDAdr _I2C_SendWrDAdr fc
;         wrDAdr -> R16
	.even
_I2C_SendWrDAdr::
	.dbline -1
	.dbline 160
; }
; }
; }
; }
; }
; }
; }
; }
; }
; }
; }
	.dbline 161
; }
	.dbline 161
	out 0x3,R16
	.dbline 161
	ldi R24,132
	out 0x36,R24
	.dbline 161
	.dbline 161
	.dbline 162
L19:
	.dbline 162
L20:
	.dbline 162
; }
	in R2,0x36
	sbrs R2,7
	rjmp L19
	.dbline 162
	.dbline 162
	.dbline 163
; }
	in R24,0x1
	andi R24,248
	cpi R24,24
	breq L22
	.dbline 164
; }
	clr R16
	xjmp L18
L22:
	.dbline 165
; }
	ldi R16,1
	.dbline -2
L18:
	.dbline 0 ; func end
	ret
	.dbsym r wrDAdr 16 c
	.dbend
	.dbfunc e I2C_SendWrDAdr_ _I2C_SendWrDAdr_ fc
;         wrDAdr -> R20,R21
	.even
_I2C_SendWrDAdr_::
	xcall push_gset1
	movw R20,R16
	.dbline -1
	.dbline 176
; ╢'т
; ╢'т
; ╢'т
; ╢'т
; ╢'т
; ╢'т
; ╢'т
; ╢'т
; ╢'т
; ╢'т
; ╢'т
	.dbline 177
; ╢'т
	sbrs R20,0
	rjmp L25
	.dbline 178
; ╢'т
	mov R16,R20
	clr R17
	mov R16,R17
	clr R17
	sbrc R16,7
	com R17
	xcall _I2C_SendWrDAdr
	tst R16
	brne L27
	.dbline 179
; ╢'т
	clr R16
	xjmp L24
L27:
L25:
	.dbline 180
; ╢'т
	mov R16,R20
	xcall _I2C_SendWrDAdr
	tst R16
	brne L29
	.dbline 181
; ╢'т
	clr R16
	xjmp L24
L29:
	.dbline 182
; ╢'т
	ldi R16,1
	.dbline -2
L24:
	xcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r wrDAdr 20 i
	.dbend
	.dbfunc e I2C_SendRdDAdr _I2C_SendRdDAdr fc
;         rdDAdr -> R16
	.even
_I2C_SendRdDAdr::
	.dbline -1
	.dbline 193
; ╢'т
; ╢'т
; ╢'т
; ╢'т
; ╢'т
; ╢'т
; ╢'т
; ╢'т
; ╢'т
; ╢'т
; ╢'т
	.dbline 194
; ╢'т
	.dbline 194
	out 0x3,R16
	.dbline 194
	ldi R24,132
	out 0x36,R24
	.dbline 194
	.dbline 194
	.dbline 195
L32:
	.dbline 195
L33:
	.dbline 195
; ╢'т
	in R2,0x36
	sbrs R2,7
	rjmp L32
	.dbline 195
	.dbline 195
	.dbline 196
; ╢'т
	in R24,0x1
	andi R24,248
	cpi R24,64
	breq L35
	.dbline 197
; ╢'т
	clr R16
	xjmp L31
L35:
	.dbline 198
; ╢'т
	ldi R16,1
	.dbline -2
L31:
	.dbline 0 ; func end
	ret
	.dbsym r rdDAdr 16 c
	.dbend
	.dbfunc e I2C_SendRdDAdr_ _I2C_SendRdDAdr_ fc
;         rdDAdr -> R20
	.even
_I2C_SendRdDAdr_::
	xcall push_gset1
	mov R20,R16
	.dbline -1
	.dbline 209
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
	.dbline 210
; дис
	sbrs R20,0
	rjmp L38
	.dbline 211
; дис
	mov R16,R20
	clr R17
	mov R16,R17
	clr R17
	sbrc R16,7
	com R17
	xcall _I2C_SendWrDAdr
	tst R16
	brne L40
	.dbline 212
; дис
	clr R16
	xjmp L37
L40:
L38:
	.dbline 213
; дис
	mov R16,R20
	xcall _I2C_SendWrDAdr
	tst R16
	brne L42
	.dbline 214
; дис
	clr R16
	xjmp L37
L42:
	.dbline 215
; дис
	ldi R16,1
	.dbline -2
L37:
	xcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r rdDAdr 20 c
	.dbend
	.dbfunc e I2C_SendDat _I2C_SendDat fc
;      configDat -> R16
	.even
_I2C_SendDat::
	.dbline -1
	.dbline 226
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
	.dbline 227
; дис
	.dbline 227
	out 0x3,R16
	.dbline 227
	ldi R24,132
	out 0x36,R24
	.dbline 227
	.dbline 227
	.dbline 228
L45:
	.dbline 228
L46:
	.dbline 228
; дис
	in R2,0x36
	sbrs R2,7
	rjmp L45
	.dbline 228
	.dbline 228
	.dbline 229
; дис
	in R24,0x1
	andi R24,248
	cpi R24,40
	breq L48
	.dbline 230
; дис
	clr R16
	xjmp L44
L48:
	.dbline 231
; дис
	ldi R16,1
	.dbline -2
L44:
	.dbline 0 ; func end
	ret
	.dbsym r configDat 16 c
	.dbend
	.dbfunc e I2C_RcvNAckDat _I2C_RcvNAckDat fc
;         pRdDat -> R16,R17
	.even
_I2C_RcvNAckDat::
	.dbline -1
	.dbline 242
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
	.dbline 243
; дис
	ldi R24,132
	out 0x36,R24
	.dbline 244
L51:
	.dbline 244
L52:
	.dbline 244
; дис
	in R2,0x36
	sbrs R2,7
	rjmp L51
	.dbline 244
	.dbline 244
	.dbline 245
; дис
	in R24,0x1
	andi R24,248
	cpi R24,88
	breq L54
	.dbline 246
; дис
	clr R16
	xjmp L50
L54:
	.dbline 247
; дис
	in R2,0x3
	movw R30,R16
	std z+0,R2
	.dbline 248
; дис
	ldi R16,1
	.dbline -2
L50:
	.dbline 0 ; func end
	ret
	.dbsym r pRdDat 16 pc
	.dbend
	.dbfunc e I2C_RcvAckDat _I2C_RcvAckDat fc
;         pRdDat -> R16,R17
	.even
_I2C_RcvAckDat::
	.dbline -1
	.dbline 259
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
	.dbline 260
; дис
	ldi R24,196
	out 0x36,R24
	.dbline 261
L57:
	.dbline 261
L58:
	.dbline 261
; дис
	in R2,0x36
	sbrs R2,7
	rjmp L57
	.dbline 261
	.dbline 261
	.dbline 262
; дис
	in R24,0x1
	andi R24,248
	cpi R24,80
	breq L60
	.dbline 263
; дис
	clr R16
	xjmp L56
L60:
	.dbline 264
; дис
	in R2,0x3
	movw R30,R16
	std z+0,R2
	.dbline 265
; дис
	ldi R16,1
	.dbline -2
L56:
	.dbline 0 ; func end
	ret
	.dbsym r pRdDat 16 pc
	.dbend
	.dbfunc e I2C_Write _I2C_Write fc
;            dat -> y+4
;        wordAdr -> R20
;         wrDAdr -> R22,R23
	.even
_I2C_Write::
	xcall push_gset2
	mov R20,R18
	movw R22,R16
	.dbline -1
	.dbline 278
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
	.dbline 279
; дис
	xcall _I2C_Start
	tst R16
	brne L63
	.dbline 280
; дис
	clr R16
	xjmp L62
L63:
	.dbline 282
; дис
; дис
	movw R16,R22
	xcall _I2C_SendWrDAdr_
	tst R16
	brne L65
	.dbline 283
; дис
	clr R16
	xjmp L62
L65:
	.dbline 285
; дис
; дис
	mov R16,R20
	xcall _I2C_SendDat
	tst R16
	brne L67
	.dbline 286
; дис
	clr R16
	xjmp L62
L67:
	.dbline 288
; дис
; дис
	ldd R16,y+4
	xcall _I2C_SendDat
	tst R16
	brne L69
	.dbline 289
; дис
	clr R16
	xjmp L62
L69:
	.dbline 291
; дис
; дис
	ldi R24,148
	out 0x36,R24
	.dbline 293
; дис
; дис
	ldi R16,1
	.dbline -2
L62:
	xcall pop_gset2
	.dbline 0 ; func end
	ret
	.dbsym l dat 4 c
	.dbsym r wordAdr 20 c
	.dbsym r wrDAdr 22 i
	.dbend
	.dbfunc e I2C_Read _I2C_Read fc
;         pRdDat -> y+6
;         rdDAdr -> y+4
;        wordAdr -> R20
;         wrDAdr -> R22,R23
	.even
_I2C_Read::
	xcall push_gset2
	mov R20,R18
	movw R22,R16
	.dbline -1
	.dbline 324
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
	.dbline 325
; дис
	xcall _I2C_Start
	tst R16
	brne L72
	.dbline 326
; дис
	clr R16
	xjmp L71
L72:
	.dbline 328
; дис
; дис
	movw R16,R22
	xcall _I2C_SendWrDAdr_
	tst R16
	brne L74
	.dbline 329
; дис
	clr R16
	xjmp L71
L74:
	.dbline 331
; дис
; дис
	mov R16,R20
	xcall _I2C_SendDat
	tst R16
	brne L76
	.dbline 332
; дис
	clr R16
	xjmp L71
L76:
	.dbline 334
; дис
; дис
	xcall _I2C_Restart
	tst R16
	brne L78
	.dbline 335
; дис
	clr R16
	xjmp L71
L78:
	.dbline 337
; дис
; дис
	ldd R16,y+4
	xcall _I2C_SendRdDAdr
	tst R16
	brne L80
	.dbline 338
; дис
	clr R16
	xjmp L71
L80:
	.dbline 340
; дис
; дис
	ldd R16,y+6
	ldd R17,y+7
	xcall _I2C_RcvNAckDat
	tst R16
	brne L82
	.dbline 341
; дис
	clr R16
	xjmp L71
L82:
	.dbline 343
; дис
; дис
	ldi R24,148
	out 0x36,R24
	.dbline 345
; дис
; дис
	ldi R16,1
	.dbline -2
L71:
	xcall pop_gset2
	.dbline 0 ; func end
	ret
	.dbsym l pRdDat 6 pc
	.dbsym l rdDAdr 4 c
	.dbsym r wordAdr 20 c
	.dbsym r wrDAdr 22 i
	.dbend
	.dbfunc e I2C_Read_ _I2C_Read_ fc
;              i -> R20
;            num -> R22
;         pRdDat -> R10,R11
;         rdDAdr -> y+8
;        wordAdr -> R20
;         wrDAdr -> R12,R13
	.even
_I2C_Read_::
	xcall push_gset4
	mov R20,R18
	movw R12,R16
	ldd R10,y+10
	ldd R11,y+11
	ldd R22,y+12
	.dbline -1
	.dbline 361
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
; дис
	.dbline 364
; дис
; дис
; дис
	xcall _I2C_Start
	tst R16
	brne L85
	.dbline 365
; дис
	clr R16
	xjmp L84
L85:
	.dbline 367
; дис
; дис
	movw R16,R12
	xcall _I2C_SendWrDAdr_
	tst R16
	brne L87
	.dbline 368
; дис
	clr R16
	xjmp L84
L87:
	.dbline 370
; дис
; дис
	mov R16,R20
	xcall _I2C_SendDat
	tst R16
	brne L89
	.dbline 371
; дис
	clr R16
	xjmp L84
L89:
	.dbline 373
; дис
; дис
	xcall _I2C_Restart
	tst R16
	brne L91
	.dbline 374
; дис
	clr R16
	xjmp L84
L91:
	.dbline 376
; дис
; дис
	ldd R16,y+8
	xcall _I2C_SendRdDAdr
	tst R16
	brne L93
	.dbline 377
; дис
	clr R16
	xjmp L84
L93:
	.dbline 379
; дис
; дис
	clr R20
	xjmp L98
L95:
	.dbline 380
; дис
	mov R16,R20
	clr R17
	add R16,R10
	adc R17,R11
	xcall _I2C_RcvAckDat
	tst R16
	brne L99
	.dbline 381
; дис
	clr R16
	xjmp L84
L99:
L96:
	.dbline 379
	inc R20
L98:
	.dbline 379
	mov R24,R22
	subi R24,1
	cp R20,R24
	brlo L95
	.dbline 383
; дис
; дис
	mov R16,R20
	clr R17
	add R16,R10
	adc R17,R11
	xcall _I2C_RcvNAckDat
	tst R16
	brne L101
	.dbline 384
; дис
	clr R16
	xjmp L84
L101:
	.dbline 386
; дис
; дис
	ldi R24,148
	out 0x36,R24
	.dbline 388
; дис
; дис
	ldi R16,1
	.dbline -2
L84:
	xcall pop_gset4
	.dbline 0 ; func end
	ret
	.dbsym r i 20 c
	.dbsym r num 22 c
	.dbsym r pRdDat 10 pc
	.dbsym l rdDAdr 8 c
	.dbsym r wordAdr 20 c
	.dbsym r wrDAdr 12 i
	.dbend
	.dbfile D:\ICC_H\Hardware.H
	.dbfunc e delay50us _delay50us fV
;              j -> R20
;              t -> R16,R17
	.even
_delay50us::
	xcall push_gset1
	.dbline -1
	.dbline 105
	.dbline 107
	xjmp L107
L104:
	.dbline 108
	clr R20
	xjmp L111
L108:
	.dbline 109
L109:
	.dbline 108
	inc R20
L111:
	.dbline 108
	cpi R20,70
	brlo L108
L105:
	.dbline 107
	subi R16,1
	sbci R17,0
L107:
	.dbline 107
	clr R2
	clr R3
	cp R2,R16
	cpc R3,R17
	brlt L104
	.dbline -2
L103:
	xcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r j 20 c
	.dbsym r t 16 I
	.dbend
	.dbfunc e delay50ms _delay50ms fV
;              i -> R20,R21
;              t -> R16,R17
	.even
_delay50ms::
	xcall push_gset1
	.dbline -1
	.dbline 120
	.dbline 122
	xjmp L116
L113:
	.dbline 123
	clr R20
	clr R21
	xjmp L120
L117:
	.dbline 124
L118:
	.dbline 123
	subi R20,255  ; offset = 1
	sbci R21,255
L120:
	.dbline 123
	cpi R20,162
	ldi R30,205
	cpc R21,R30
	brlo L117
L114:
	.dbline 122
	subi R16,1
	sbci R17,0
L116:
	.dbline 122
	clr R2
	clr R3
	cp R2,R16
	cpc R3,R17
	brlt L113
	.dbline -2
L112:
	xcall pop_gset1
	.dbline 0 ; func end
	ret
	.dbsym r i 20 i
	.dbsym r t 16 I
	.dbend
	.dbfile D:\ICC_H\LCD12864_ST7920.H
	.dbfunc e SPI_init _SPI_init fV
	.even
_SPI_init::
	.dbline -1
	.dbline 83
	.dbline 84
	in R24,0x17
	ori R24,176
	out 0x17,R24
	.dbline 85
	ldi R24,80
	out 0xd,R24
	.dbline 86
	ldi R24,1
	out 0xe,R24
	.dbline 87
	sei
	.dbline -2
L121:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e lcd_wrByte _lcd_wrByte fV
;           data -> R16
	.even
_lcd_wrByte::
	.dbline -1
	.dbline 91
	.dbline 92
	out 0xf,R16
L123:
	.dbline 93
L124:
	.dbline 93
	sbis 0xe,7
	rjmp L123
	.dbline -2
L122:
	.dbline 0 ; func end
	ret
	.dbsym r data 16 c
	.dbend
	.dbfunc e lcd_wrCmd _lcd_wrCmd fV
;             LC -> R20
;             HC -> R22
	.even
_lcd_wrCmd::
	xcall push_gset2
	mov R20,R18
	mov R22,R16
	.dbline -1
	.dbline 97
	.dbline 98
	ldi R16,248
	xcall _lcd_wrByte
	.dbline 99
	mov R16,R22
	xcall _lcd_wrByte
	.dbline 100
	mov R16,R20
	xcall _lcd_wrByte
	.dbline -2
L126:
	xcall pop_gset2
	.dbline 0 ; func end
	ret
	.dbsym r LC 20 c
	.dbsym r HC 22 c
	.dbend
	.dbfunc e lcd_wrDat _lcd_wrDat fV
;             LD -> R20
;             HD -> R22
	.even
_lcd_wrDat::
	xcall push_gset2
	mov R20,R18
	mov R22,R16
	.dbline -1
	.dbline 104
	.dbline 105
	ldi R16,250
	xcall _lcd_wrByte
	.dbline 106
	mov R16,R22
	xcall _lcd_wrByte
	.dbline 107
	mov R16,R20
	xcall _lcd_wrByte
	.dbline -2
L127:
	xcall pop_gset2
	.dbline 0 ; func end
	ret
	.dbsym r LD 20 c
	.dbsym r HD 22 c
	.dbend
	.dbfunc e lcd_set_xy _lcd_set_xy fV
;            adr -> R20
;              y -> R22
;              x -> R20
	.even
_lcd_set_xy::
	xcall push_gset2
	mov R22,R18
	mov R20,R16
	.dbline -1
	.dbline 114
	.dbline 117
	clr R21
	cpi R20,1
	ldi R30,0
	cpc R21,R30
	breq L132
	cpi R20,2
	ldi R30,0
	cpc R21,R30
	breq L133
	cpi R20,3
	ldi R30,0
	cpc R21,R30
	breq L134
	cpi R20,4
	ldi R30,0
	cpc R21,R30
	breq L135
	xjmp L129
X1:
	.dbline 118
L132:
	.dbline 119
	mov R20,R22
	subi R20,129    ; addi 127
	.dbline 120
	xjmp L130
L133:
	.dbline 121
	mov R20,R22
	subi R20,113    ; addi 143
	.dbline 122
	xjmp L130
L134:
	.dbline 123
	mov R20,R22
	subi R20,121    ; addi 135
	.dbline 124
	xjmp L130
L135:
	.dbline 125
	mov R20,R22
	subi R20,105    ; addi 151
	.dbline 126
L129:
	.dbline 127
	.dbline 128
L130:
	.dbline 129
	mov R18,R20
	andi R18,15
	andi R18,#0x0F
	swap R18
	mov R16,R20
	andi R16,240
	xcall _lcd_wrCmd
	.dbline -2
L128:
	xcall pop_gset2
	.dbline 0 ; func end
	ret
	.dbsym r adr 20 c
	.dbsym r y 22 c
	.dbsym r x 20 c
	.dbend
	.dbfunc e lcd_putc _lcd_putc fV
;             ch -> y+4
;              y -> R22
;              x -> R20
	.even
_lcd_putc::
	xcall push_gset2
	mov R22,R18
	mov R20,R16
	.dbline -1
	.dbline 133
	.dbline 134
	mov R18,R22
	mov R16,R20
	xcall _lcd_set_xy
	.dbline 135
	ldi R16,20
	ldi R17,0
	xcall _delay50us
	.dbline 136
	ldd R18,y+4
	andi R18,15
	andi R18,#0x0F
	swap R18
	ldd R16,y+4
	andi R16,240
	xcall _lcd_wrDat
	.dbline -2
L136:
	xcall pop_gset2
	.dbline 0 ; func end
	ret
	.dbsym l ch 4 c
	.dbsym r y 22 c
	.dbsym r x 20 c
	.dbend
	.dbfunc e lcd_putd0 _lcd_putd0 fV
;              i -> R20
;         length -> y+9
;            dat -> y+5
;              y -> R22
;              x -> R20
	.even
_lcd_putd0::
	xcall push_gset2
	mov R22,R18
	mov R20,R16
	sbiw R28,1
	.dbline -1
	.dbline 140
	.dbline 143
	ldd R0,y+9
	std y+0,R0
	movw R30,R28
	ldd R16,z+5
	ldd R17,z+6
	ldd R18,z+7
	ldd R19,z+8
	xcall _speaData
	.dbline 144
	mov R18,R22
	mov R16,R20
	xcall _lcd_set_xy
	.dbline 145
	ldi R16,40
	ldi R17,0
	xcall _delay50us
	.dbline 146
	ldd R20,y+9
	subi R20,1
	xjmp L141
L138:
	.dbline 147
	.dbline 148
	ldi R24,<_dataElem
	ldi R25,>_dataElem
	mov R30,R20
	clr R31
	sbrc R30,7
	com R31
	add R30,R24
	adc R31,R25
	ldd R24,z+0
	clr R25
	adiw R24,48
	mov R18,R24
	andi R18,15
	andi R19,0
	lsl R18
	rol R19
	lsl R18
	rol R19
	lsl R18
	rol R19
	lsl R18
	rol R19
	mov R16,R24
	andi R16,240
	andi R17,0
	xcall _lcd_wrDat
	.dbline 149
	ldi R16,40
	ldi R17,0
	xcall _delay50us
	.dbline 150
L139:
	.dbline 146
	dec R20
L141:
	.dbline 146
	cpi R20,0
	brge L138
	.dbline -2
L137:
	adiw R28,1
	xcall pop_gset2
	.dbline 0 ; func end
	ret
	.dbsym r i 20 C
	.dbsym l length 9 c
	.dbsym l dat 5 l
	.dbsym r y 22 c
	.dbsym r x 20 c
	.dbend
	.dbfunc e lcd_putd _lcd_putd fV
;      effectLen -> R12
;              i -> R10
;         length -> y+15
;            dat -> y+11
;              y -> R14
;              x -> R10
	.even
_lcd_putd::
	xcall push_gset5
	mov R14,R18
	mov R10,R16
	sbiw R28,1
	.dbline -1
	.dbline 154
	.dbline 158
	ldi R20,63
	ldi R21,66
	ldi R22,15
	ldi R23,0
	movw R30,R28
	ldd R2,z+11
	ldd R3,z+12
	ldd R4,z+13
	ldd R5,z+14
	cp R20,R2
	cpc R21,R3
	cpc R22,R4
	cpc R23,R5
	brsh L143
	.dbline 159
	ldi R24,7
	mov R12,R24
	xjmp L144
L143:
	.dbline 160
	ldi R20,159
	ldi R21,134
	ldi R22,1
	ldi R23,0
	movw R30,R28
	ldd R2,z+11
	ldd R3,z+12
	ldd R4,z+13
	ldd R5,z+14
	cp R20,R2
	cpc R21,R3
	cpc R22,R4
	cpc R23,R5
	brsh L145
	.dbline 161
	ldi R24,6
	mov R12,R24
	xjmp L146
L145:
	.dbline 162
	ldi R20,15
	ldi R21,39
	ldi R22,0
	ldi R23,0
	movw R30,R28
	ldd R2,z+11
	ldd R3,z+12
	ldd R4,z+13
	ldd R5,z+14
	cp R20,R2
	cpc R21,R3
	cpc R22,R4
	cpc R23,R5
	brsh L147
	.dbline 163
	ldi R24,5
	mov R12,R24
	xjmp L148
L147:
	.dbline 164
	ldi R20,231
	ldi R21,3
	ldi R22,0
	ldi R23,0
	movw R30,R28
	ldd R2,z+11
	ldd R3,z+12
	ldd R4,z+13
	ldd R5,z+14
	cp R20,R2
	cpc R21,R3
	cpc R22,R4
	cpc R23,R5
	brsh L149
	.dbline 165
	ldi R24,4
	mov R12,R24
	xjmp L150
L149:
	.dbline 166
	ldi R20,99
	ldi R21,0
	ldi R22,0
	ldi R23,0
	movw R30,R28
	ldd R2,z+11
	ldd R3,z+12
	ldd R4,z+13
	ldd R5,z+14
	cp R20,R2
	cpc R21,R3
	cpc R22,R4
	cpc R23,R5
	brsh L151
	.dbline 167
	ldi R24,3
	mov R12,R24
	xjmp L152
L151:
	.dbline 168
	ldi R20,9
	ldi R21,0
	ldi R22,0
	ldi R23,0
	movw R30,R28
	ldd R2,z+11
	ldd R3,z+12
	ldd R4,z+13
	ldd R5,z+14
	cp R20,R2
	cpc R21,R3
	cpc R22,R4
	cpc R23,R5
	brsh L153
	.dbline 169
	ldi R24,2
	mov R12,R24
	xjmp L154
L153:
	.dbline 171
	clr R12
	inc R12
L154:
L152:
L150:
L148:
L146:
L144:
	.dbline 172
	std y+0,R12
	movw R30,R28
	ldd R16,z+11
	ldd R17,z+12
	ldd R18,z+13
	ldd R19,z+14
	xcall _speaData
	.dbline 174
	mov R18,R14
	mov R16,R10
	xcall _lcd_set_xy
	.dbline 175
	ldi R16,40
	ldi R17,0
	xcall _delay50us
	.dbline 176
	ldd R0,y+15
	cp R12,R0
	brsh L155
	.dbline 177
	.dbline 178
	mov R24,R0
	sub R24,R12
	subi R24,1
	mov R10,R24
	xjmp L160
L157:
	.dbline 179
	.dbline 180
	clr R18
	ldi R16,32
	xcall _lcd_wrDat
	.dbline 181
	ldi R16,40
	ldi R17,0
	xcall _delay50us
	.dbline 182
L158:
	.dbline 178
	dec R10
L160:
	.dbline 178
	mov R24,R10
	cpi R24,0
	brge L157
	.dbline 183
L155:
	.dbline 184
	mov R24,R12
	subi R24,1
	mov R10,R24
	xjmp L164
L161:
	.dbline 185
	.dbline 186
	ldi R24,<_dataElem
	ldi R25,>_dataElem
	mov R30,R10
	clr R31
	sbrc R30,7
	com R31
	add R30,R24
	adc R31,R25
	ldd R24,z+0
	clr R25
	adiw R24,48
	mov R18,R24
	andi R18,15
	andi R19,0
	lsl R18
	rol R19
	lsl R18
	rol R19
	lsl R18
	rol R19
	lsl R18
	rol R19
	mov R16,R24
	andi R16,240
	andi R17,0
	xcall _lcd_wrDat
	.dbline 187
	ldi R16,40
	ldi R17,0
	xcall _delay50us
	.dbline 188
L162:
	.dbline 184
	dec R10
L164:
	.dbline 184
	mov R24,R10
	cpi R24,0
	brge L161
	.dbline -2
L142:
	adiw R28,1
	xcall pop_gset5
	.dbline 0 ; func end
	ret
	.dbsym r effectLen 12 C
	.dbsym r i 10 C
	.dbsym l length 15 c
	.dbsym l dat 11 l
	.dbsym r y 14 c
	.dbsym r x 10 c
	.dbend
	.dbfunc e lcd_puts _lcd_puts fV
;            str -> R20,R21
;              y -> R10
;              x -> R22
	.even
_lcd_puts::
	xcall push_gset3
	mov R10,R18
	mov R22,R16
	ldd R20,y+6
	ldd R21,y+7
	.dbline -1
	.dbline 192
	.dbline 193
	mov R18,R10
	mov R16,R22
	xcall _lcd_set_xy
	.dbline 194
	ldi R16,20
	ldi R17,0
	xcall _delay50us
	xjmp L167
L166:
	.dbline 196
	.dbline 197
	movw R30,R20
	ldd R2,z+0
	clr R3
	mov R18,R2
	andi R18,15
	andi R18,#0x0F
	swap R18
	mov R16,R2
	andi R16,240
	xcall _lcd_wrDat
	.dbline 198
	subi R20,255  ; offset = 1
	sbci R21,255
	.dbline 199
	ldi R16,20
	ldi R17,0
	xcall _delay50us
	.dbline 200
L167:
	.dbline 195
	movw R30,R20
	ldd R2,z+0
	tst R2
	brne L166
	.dbline -2
L165:
	xcall pop_gset3
	.dbline 0 ; func end
	ret
	.dbsym r str 20 pc
	.dbsym r y 10 c
	.dbsym r x 22 c
	.dbend
	.dbfunc e lcd_puts_ _lcd_puts_ fV
;          dlyMs -> R20
;            str -> R22,R23
;              y -> R12
;              x -> R10
	.even
_lcd_puts_::
	xcall push_gset4
	mov R12,R18
	mov R10,R16
	ldd R22,y+8
	ldd R23,y+9
	ldd R20,y+10
	.dbline -1
	.dbline 204
	.dbline 205
	mov R18,R12
	mov R16,R10
	xcall _lcd_set_xy
	.dbline 206
	ldi R16,20
	ldi R17,0
	xcall _delay50us
	xjmp L171
L170:
	.dbline 208
	.dbline 209
	movw R30,R22
	ldd R2,z+0
	clr R3
	mov R18,R2
	andi R18,15
	andi R18,#0x0F
	swap R18
	mov R16,R2
	andi R16,240
	xcall _lcd_wrDat
	.dbline 210
	subi R22,255  ; offset = 1
	sbci R23,255
	.dbline 211
	mov R16,R20
	clr R17
	xcall _delay50ms
	.dbline 212
L171:
	.dbline 207
	movw R30,R22
	ldd R2,z+0
	tst R2
	brne L170
	.dbline -2
L169:
	xcall pop_gset4
	.dbline 0 ; func end
	ret
	.dbsym r dlyMs 20 c
	.dbsym r str 22 pc
	.dbsym r y 12 c
	.dbsym r x 10 c
	.dbend
	.dbfunc e lcd_clr _lcd_clr fV
	.even
_lcd_clr::
	.dbline -1
	.dbline 216
	.dbline 217
	ldi R18,16
	clr R16
	xcall _lcd_wrCmd
	.dbline 218
	ldi R16,200
	ldi R17,0
	xcall _delay50us
	.dbline -2
L173:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfunc e lcd_init _lcd_init fV
	.even
_lcd_init::
	.dbline -1
	.dbline 222
	.dbline 223
	xcall _SPI_init
	.dbline 226
	ldi R16,1
	ldi R17,0
	xcall _delay50ms
	.dbline 227
	ldi R18,48
	ldi R16,48
	xcall _lcd_wrCmd
	.dbline 229
	ldi R18,192
	clr R16
	xcall _lcd_wrCmd
	.dbline 230
	ldi R18,16
	clr R16
	xcall _lcd_wrCmd
	.dbline 232
	ldi R18,96
	clr R16
	xcall _lcd_wrCmd
	.dbline 234
	ldi R16,1
	ldi R17,0
	xcall _delay50ms
	.dbline -2
L174:
	.dbline 0 ; func end
	ret
	.dbend
	.dbfile E:\н╒я╘╣ГвсCD1\╡Зф╥вйао\©╙╥╒╟Ей╣яИ╟Е\SMKо╣ап\SMK1632\й╣яИ╫лЁл\мБн╖дё©ИоЮ╧ьй╣яИ\LCD128~1\LCD12864_ST7920\LCD12864_ST7920.C
	.dbfunc e main _main fV
	.even
_main::
	sbiw R28,2
	.dbline -1
	.dbline 86
	.dbline 87
	sei
	.dbline 88
	xcall _lcd_init
	.dbline 89
	ldi R24,<L176
	ldi R25,>L176
	std y+1,R25
	std y+0,R24
	ldi R18,1
	ldi R16,1
	xcall _lcd_puts
	.dbline 90
	ldi R24,<L177
	ldi R25,>L177
	std y+1,R25
	std y+0,R24
	ldi R18,1
	ldi R16,3
	xcall _lcd_puts
L178:
	.dbline 91
L179:
	.dbline 91
	xjmp L178
X2:
	.dbline -2
L175:
	adiw R28,2
	.dbline 0 ; func end
	ret
	.dbend
	.area bss(ram, con, rel)
	.dbfile E:\н╒я╘╣ГвсCD1\╡Зф╥вйао\©╙╥╒╟Ей╣яИ╟Е\SMKо╣ап\SMK1632\й╣яИ╫лЁл\мБн╖дё©ИоЮ╧ьй╣яИ\LCD128~1\LCD12864_ST7920\LCD12864_ST7920.C
_dataElem::
	.blkb 6
	.dbfile D:\ICC_H\Software.H
	.dbsym e dataElem _dataElem A[6:6]c
	.area data(ram, con, rel)
	.dbfile D:\ICC_H\Software.H
L177:
	.blkb 13
	.area idata
	.byte 32,32,32,32,206,162,209,169,181,231,215,211,0
	.area data(ram, con, rel)
	.dbfile D:\ICC_H\Software.H
L176:
	.blkb 16
	.area idata
	.byte 32,32,'W,'a,'v,'e,'S,'h,'a,'r,'e,46,'n,'e,'t,0
	.area data(ram, con, rel)
	.dbfile D:\ICC_H\Software.H
