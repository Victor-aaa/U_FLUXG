;-----------------------------------------------	
#include "BlockDef.h"                     	// #define Blocks ID
;-----------------------------------------------	
Block_Header:
		DC8	IdBlock_Header,   Ver1, ACL(Rd0,WrrX), MEM_FLASH
		DC32	Block_Header, SizeBlock_Header, 0
Block_HeaderX:		
		DC8	IdBlock_Info, 	  Ver2, ACL(Rd0,WrrX), MEM_FLASH
		DC32	Block_Info, SizeBlock_Info, 0
		
		DC8	IdBlock_Constant, Ver6, ACL(Rd0,Wrr3), MEM_FLASH
		DC32	Block_Constant, SizeBlock_Constant, 0
		
		DC8	IdBlock_Data, Ver6, ACL(Rd0,Wrr0), MEM_RAM
		DC32	Block_Data, SizeBlock_Data, 0
		
		DC8	IdBlock_Settings, Ver6, ACL(Rd0,Wrr1), MEM_RAM
		DC32	Block_Settings, SizeBlock_Settings, 0
		
		DC8	IdBlock_Status,   Ver6, ACL(Rd0,WrrX), MEM_RAM
		DC32	Block_Status, SizeBlock_Status, 0
		
		DC8	IdBlock_TextTask,   Ver6, ACL(Rd0,Wrr1), MEM_FLASH
		DC32	Block_TextTask, SizeBlock_TextTask, 0
		


EndBlock_Header:		
SizeBlock_Header equ ($-Block_Header)
/*
Type&_Name:		ds 1	    	; 0-not, 1-Header, 2-MeterID, 3-CryptoKey, 4-Constants ...
SubType&_Name:		ds 1 	        ; VerX
Acces&_Name:		ds 1
Location&_Name:		ds 1            ; location & tupe
Adress&_Name:		ds 4	 	; BIN format
Size&_Name:		ds 4	 	; BIN format
Pointer&_Name:		ds 4	 	; Reserved
*/
;-----------------------------------------------	
Block_Info:              // location in ROM
			DB	MaxPDU, (SizeBlock_Header/16)
			DB	YES, 0
			DB	'FLUXG v1.00',0
			DB	__DATE__, __TIME__,0
			DB	'isc_labs@i.ua',0
			DB	END_TEXT

SizeBlock_Info = $-Block_Info
//=================================================================================================
END_PROGRAMM_CODE equ (($+SizeSeg-1) & 0xFE00)-1 		// end write protect!!
	// ALIGN   (9)      // Now align to a SizeSeg byte boundary
		ORG	END_PROGRAMM_CODE+1
//=================================================================================================
/*		  Block_CharGen:              			// location in ROM - Char Generator
	M_Font8x11                              // Font_U1 
	M_Font13x16                             // Font_U2      
Font_U3	  
#include "Arial_Arrow_22x26_20.h"               // Font_U3 
//#include "Agency FB_16x29_20.h"               // Font_U3     
Font_U4
#include "Arial_Arrow_30x37_28.h"               // Font_U4    	
//#include "Agency FB_23x39_28.h"               // Font_U4    	
	
	DS8	SizeBlock_CharGen-($-Block_CharGen)
SizeBlock_CharGen = (SizeSeg*24)
//=======================
*/
Block_TextTask:              			// location in ROM
#include "FLUXG_01_Scr_Menu.s43"
		DS8	SizeBlock_TextTask-($-Block_TextTask)
SizeBlock_TextTask = SizeSeg*2

 #ifdef	PROFILE_32_A
Size_Profile32_A equ (SizeSeg*2) // 512*2=512*16bit!
;---------------
Block_Profile32_A:
  			DS8 	Size_Profile32_A
SizeBlock_Profile32_A = $-Block_Profile32_A
 #endif
;-----------------------------------------------
//F_TEMP_SEG  		DS8	SizeSeg         // for TEMPORARY STORAGE SEG
;-----------------------------------------------
F_END_ALL_SEGMENT
;-----------------------------------------------
	ORG	AddrInfoSegD
Block_Constant:              			//  id=103,  == Block_CONSTANT ==
C_DEVICE_NUMBER		DC32	DEVICE_ID     	// 00 reserved for METER Number /1- 99999999/
C_DEVICE_CHANNEL	DC16	0             	// 04 4bits Channels
C_DEVICE_ADDR		DC16	DEVICE_ADDR   	// 06 6bits Device Address
C_FLAGS			DC16	0 		// 08 [flags]
C_FLAGS_APP             DC16    0		// 10
C_PPM			DC16	0     		// 12 Pulse Per Milion -240ppm to +240ppm, bit15 - or +
C_OFFSET_TEMP		DC16	0               // 14 TEMP OffSet
C_OFFSET_APOW		DC16	0            	// 16 APOW OffSet
C_OFFSET_ASENS		DC16	0  		// 18 ASENS OffSet
C_OFFSET_AN1		DC16	0           	// 20 AN1  OffSet
C_OFFSET_AN2		DC16	0            	// 22 AN2  OffSet

C_PARAMS		DC16	0          	// 24 params
C_SEA_LEVEL		DC16	sea_level       // 26 [mbar]*10
C_TRASHOLD_CD__		DC16	200		// 28 [amp] amplitude 1-10000
C_RESPONCE_DELAY_	DC16	0// [uS] - Info!!!
C_SHIFT_ANGLE__		DC16	0		// 30 [deg], step = 1.4  (-45...+45) 
C_GANE_AMP		DC16	0		// 32 [n] Gain  
C_A_R_AMP___		DC16	0		// 34 [n] 
C_TIME_NAV_POLLING__	DC16	180		// 36 [sec]
C_INTERVAL_BEACON__	DC16	60		// 38 [sec]
C_DELAY_SINC		DC16	0            	// 40 [uS*100] 100 = 1uS

C_TIME_POWER_OFF	DC16	15		// 42 [min] power off
C_BAT_LOW		DC16	1000            // 44 [0.01v]
C_BAT_FULL		DC16	1420            // 46 [0.01v]
C_LCD_FLAGS		DC8	0  		// 48 [flags] LCD_ROTATE_B
C_LCD_BRIGHT		DC8	0x7F            // 49 [n]
C_PHASE_ERR_CD__	DC16	0     // 50 [deg], step = 1.4


//C_PERIPERAL		DC16	st_LCD_B|st_COMPASS_B	// Periperal present

	ORG	Block_Constant+SizeInfoSeg      // == Block_CONSTANT II ==
C_CRC_FD	DC16	0  //	  
C_C1		DC16	0  //
C_C2		DC16	0  //
C_C3		DC16	0  //
C_C4		DC16	0  //
C_C5		DC16	0  //
C_C6		DC16	0  //
C_DEPTH_mm	DC16	0  //

C_FLT1_SET
//#include "PROFI_FIR_Coeff.h"                  	// define coefficient FIR
SizeBlock_Constant = (SizeInfoSeg*2)

//*** C_FLAGS bit ***
SERIAL_CRC_OFF_B	=	0x0001          // CRC = 0xAA55
BEACON_ON_B         	=	0x0010	
ACCESS_CCA_B         	=	0x0020	
POW_AMP_CLASS_D_B	= 	0x0100


//*** C_FLAGS_APP bit ***
UWM_MODE_MASK_B		=	0x0003		// mode 0-off,
UWM_MODE_0_B		=	0x0001		// mode 0
UWM_MODE_1_B		=	0x0002		// mode 1
//UWM_BASE_STATION_B	=	0x0004		// 1 - Navi BASE STATION 

MODBUS_CRC_OFF_B	= 	0x0200		
MESSAGE_ON_B		= 	0x0400	



//*** C_LCD_FLAGS bit ***
LCD_ROTATE_B		=	0x01          // 
LCD_REVERSE_B		=	0x02          // 
;-----------------------------------------------
;-----------------------------------------------
;-----------------------------------------------
;-----------------------------------------------
	ASEG	EndVariableRAM 	//<<< RAM Definition >>>
;-----------------------------------------------
	EVEN
Block_Status:   	// id=106, == Block_Status ==
;---------------
// sys section
st_Periperal            DS16	1	// 00 dinamic status Periperal
st_StatusAPP		DS16	1	// 02
st_ch_ABCDEF		DS16	1	// 04 ch1 - ch6
st_ch_AN1AN2		DS16	1	// 06 AN1, AN2
st_Val_AB		DS16	1	// 08  
st_Val_mn		DS16	1	// 10  
st_Phase        	DS16	1	// 12
st_Phase_min        	DS16	1	// 14
st_Phase_max        	DS16	1	// 16
st_CntErrPack  		DS16	1	// 18 
st_CntResivPac		DS16    1       // 20
st_CntTrxPac		DS16    1       // 22
st_CntReset		DS16	1	// 24 reset counter
st_EvtReset		DS16	1	// 26
st_CntAdcOvfl	 	DS16	1	// 28
st_Level_max            DS16	1	// 30
st_BIAS  		DS16    1       // 32
st_SN			DS8	1	// 34 SN
st_ADC_ID		DS8	1	// 33
//------- *** st_Periperal bits *** ----//  dinamic status Periperal
st_LCD_B       	equ     0x0001          //  |
st_NFC_B       	equ     0x0004          //  |
st_LIGHT_B      equ     0x0008          //  |
st_TMP_B       	equ     0x0010          //  |
st_BAROM_B      equ     0x0020          //  |  
st_ADC24_B      equ     0x0040          //  |  
					//  |
st_RS_B       	equ     0x0400          //  | host connect
st_485_B      	equ     0x0800

st_EEPROM_B    	equ     0x1000          //  |
st_PS_B         equ     0x4000		//  | Power Supply 12v
st_PSEX_B       equ     0x8000		//  | Power Supply 5v EX

SizeBlock_Status = $-Block_Status
;-----------------------------------------------
;-----------------------------------------------
	EVEN
Block_Settings          // id=105,  == Block_Settings ==
app_CtrlFlags		DS16	1       // 00 lo - command, hi - params
app_MODE		DS16	1	// 02 C_FLAGS_APP -> app_MODE -> D_STATUS ????
app_Menu_Line		DS8	1	// 04 0-7
app_Menu_Page		DS8	1	// 05 0-7
app_ScriptFlags		DS8	1	// 06
app_ScriptStatus	DS8	1	// 07
app_RegOperand		DS16	1       // 08

//---- *** app_CtrlFlags *** ----
COM_POWER_MODE    	equ  2  // lo - command  hi - 0-Activ, 1-PD
COM_SCRYPT	    	equ  10 // lo - command  hi - 0-stop, 1-start 
COM_CALIB_ZERO	   	equ  20	// lo - command
COM_CALIB_POINT		equ  22 // lo - command
COM_RST_FLUXG	   	equ  30	// lo - command
COM_RST_CNT		equ  32 // lo - command

COM_RELOAD_CONST_DEFAULT    equ  20  // lo - command=20  hi - param=TAB_DEFAULT
COM_RELOAD_MB_ID_DEFAULT    equ  21  // lo - command=21  hi - param=0 or MB_ID

SizeBlock_Settings = $-Block_Settings
;-----------------------------------------------
;-----------------------------------------------
	EVEN
Block_Data:             // id=104,  == Block_Data ==
D_SEC_256		DS8  	1	// SEC/256
D_SEC			DS8  	1       // ss
D_MIN			DS8  	1       // mm
D_HR			DS8  	1       // hh
D_DATE          	DS8  	1       // DD
D_MONTH        		DS8  	1       // MM
D_YEAR          	DS8  	1       // YY
D_DAY           	DS8  	1       // Day
// message data! 
D_STATUS		DS16	1	// 08 C_FLAGS_APP -> app_MODE -> D_STATUS
D_TEMP        		DS16	1	// 10 Internal Temperature Sensor   [T]*10  (200 = 20.0C)
D_APOW	        	DS16	1       // 12 Data AVIN [V]*100  (100 = 1.00V)
D_ASENS	        	DS16	1       // 14 Data AVEX [V]*100  (100 = 1.00V)
D_PRESSURE        	DS16	1       // 16 Pressure Sensor [mbar]  
D_DEPTH			DS16	1	// 18 Depth [sm]
D_AN1	  		DS16	1	// 20 ANX
D_AN2		       	DS16	1	// 22 ANY
D_PRS_DP		DS16	1	// 24 Hi tetrada PRESSURE,DEPTH
D_ch_1			DS16	1	// 26
D_ch_2			DS16	1	// 28
D_ch_3			DS16	1	// 30
D_ch_4			DS16	1	// 32
D_ch_5			DS16	1	// 34
D_ch_6			DS16	1	// 36
D_ch_7			DS16	1	// 38
D_ch_AB__        	DS16	1	// 40 
D_ch_nm__     		DS16	1	// 42 
D_amp_AB__        	DS16	1	// 44 
D_val_mn__        	DS16	1	// 46

// end message data!

tstSize			DS16	1
SizeBlock_Data = $-Block_Data
;---------- *** D_DAY bits *** ----------
ErrorRTC_B       equ    BIT7          // D_DAY - RTC not correct
DayLightRTC_B    equ    BIT6          // D_DAY - day light RTC - летнее время
;---------- *** D_STATUS bits *** -------
MODE_MASK_B	=	0x03		// mode 0-off, 1-64, 2-32
MODE0_B    	=	0x01        	// MODE 0
MODE1_B    	=	0x02        	// MODE 1
//BASE_STATION_B	=	0x04		// 1 - Navi BASE STATION 

COORD_VALID_B	=	0x10		// Coordinate time valid

SW_DOWN_B	=	0x40		// 0- UP, 1 - DOWN
POWER_ERR_B	=	0x80            // battery low

INVAL_COM_B   	=	0x100
WATER_SENS_B	=	0x200
BatteryLow_B    = POWER_ERR_B
;-----------------------------------------------
;-----------------------------------------------
//==============================================
#ifdef  __RAM_FUNCTION__
	EVEN
#endif		  
	EVEN
END_USED_RAM			
//==============================================


