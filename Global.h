;----------------------------------------------------------------------------------------------
YES		equ	1
NO		equ	0
ON		equ	1
OFF		equ	0
NONE            equ     0
ConstTest	equ	0x55		; константа для теста EEPROM
ConstClean	equ	0xFF 		; константа для обнуления EEPROM
EMPTY_FLASH_W	equ	0xFFFF
EMPTY_FLASH_B	equ	0xFF

TimeRestart	equ	04		; время рестарта системы в часах
CR		equ	0x0D
LF		equ	0x0A
END_TEXT	equ	0x03

SUCCESS		equ	0x00

Ver0  equ  00	;
Ver1  equ  01	;
Ver2  equ  02	;
Ver3  equ  03	;
Ver4  equ  04	;
Ver5  equ  05	;
Ver6  equ  06	;
Ver7  equ  07	;
Ver8  equ  08	;
Ver9  equ  09	;
Ver10  equ  10	;
Ver11  equ  11	;
Ver12  equ  12	;
Ver13  equ  13	;
Ver14  equ  14	;
Ver15  equ  15	;
Ver16  equ  16	;
Ver17  equ  17	;
Ver18  equ  18	;
Ver19  equ  19	;

Ver95  equ  95

Rd0 equ 0
Rd1 equ 1
Rd2 equ 2
Rd3 equ 3
RdX equ 7
Wrr0 equ Rd0
Wrr1 equ Rd1
Wrr2 equ Rd2
Wrr3 equ Rd3
WrrX equ RdX

MaskRdX equ  0x07
MaskWrX equ  0x70

#define ACL(R,W) (R+(W shl 4))

YMDDhhmm  equ 8
YMDDhh  equ 6
YMDD  equ 4
YM  equ 2

BR9600   equ 5
BR19200  equ 6
BR38400  equ 7
BR57600  equ 8
BR115200 equ 9

_8N2     equ 0		; 8 bit, None Parity, 2 stop
_8E1     equ 1	        ; 8 bit, Even Parity, 1 stop
_8O1     equ 2	        ; 8 bit, Odd  Parity, 1 stop


MEM_FLASH  equ 0	// system FLASH or FRAM
MEM_RAM	   equ 1	// system RAM
EXT_RAM	   equ 2	// ext SPI RAM
BIT_WORD   equ 3	// expand bits => word! 0=0x0000, 1=0xFF00
VIRTUAL	   equ 4
EXT_IIC    equ 5	// ext I2C EEPROM
PTR_TUPE_I2C = 6
PTR_TUPE   equ 7
EXT_UART   equ 8
#define	MaskLocation  		(0x0F)
#define	SizeBlock_BitWord	32


HidenFlag  equ 0x80

LowBYTE		equ  0x00FF
HighBYTE	equ  0xFF00

#define  _nop_     0x4303 

#include "MACRO_1.s43"                     		// #define controlled include file







