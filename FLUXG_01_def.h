//=====================================================
//                     MODUL UWM_v01
//=====================================================
// =================== PIN DEFINE =====================
#define TP1         	(0x0001)  // Port 1 bit 0 
#define REF25           (0x0002)  // Port 1 bit 1 
#define TP2             (0x0004)  // Port 1 bit 2 
#define KEY         	(0x0008)  // Port 1 bit 3 
#define RxTx       	(0x0010)  // Port 1 bit 4 
#define LED           	(0x0020)  // Port 1 bit 5 
#define SDA          	(0x0040)  // Port 1 bit 6 
#define SCL      	(0x0080)  // Port 1 bit 7 
				
#define TMR6         	(0x0001)  // Port 2 bit 0 
#define TMR5      	(0x0002)  // Port 2 bit 1 
#define TMR4       	(0x0004)  // Port 2 bit 2 
#define NC_23           (0x0008)  // Port 2 bit 3 
#define NA_24           (0x0010)  // Port 2 bit 4 
#define NA_25           (0x0020)  // Port 2 bit 5 
#define NA_26           (0x0040)  // Port 2 bit 6 
#define NA_27           (0x0080)  // Port 2 bit 7 
				 
#define B1_CLK	        (0x0001)  // Port 3 bit 0 
#define B1_SI           (0x0002)  // Port 3 bit 1 
#define NC_32           (0x0004)  // Port 3 bit 2 
#define X3_33           (0x0008)  // Port 3 bit 3 
#define NC_34           (0x0010)  // Port 3 bit 4 
#define NC_35           (0x0020)  // Port 3 bit 5 
#define TP5             (0x0040)  // Port 3 bit 6 
#define TMR3      	(0x0080)  // Port 3 bit 7 
				
#define TxD      	(0x0004)  // Port 4 bit 2 
#define RxD             (0x0008)  // Port 4 bit 3 
#define X2_42     	(0x0010)  // Port 4 bit 4 
#define X1_43           (0x0020)  // Port 4 bit 5 
#define SDA1            (0x0040)  // Port 4 bit 6 
#define SCL1            (0x0080)  // Port 4 bit 7 
				 
#define LD6             (0x0080)  // Port 5 bit 7 
				
#define NC_60	        (0x0001)  // Port 6 bit 0 
#define NC_61           (0x0002)  // Port 6 bit 1 
#define NC_62           (0x0004)  // Port 6 bit 2 
#define DDS1_CS         (0x0008)  // Port 6 bit 3 
#define DDS2_CS         (0x0010)  // Port 6 bit 4 
#define TMR1            (0x0020)  // Port 6 bit 5 
#define TMR2            (0x0040)  // Port 6 bit 6 

#define LD1             (0x0001)  // Port 7 bit 0 
#define LD2             (0x0002)  // Port 7 bit 1 
#define LD3             (0x0004)  // Port 7 bit 2 
#define LD4             (0x0008)  // Port 7 bit 3 
#define LD5             (0x0010)  // Port 7 bit 4 
				
#define APOW     	(0x0010)  // Port 9 bit 4 
#define ASENS           (0x0020)  // Port 9 bit 5 
#define AN1             (0x0040)  // Port 9 bit 6 
#define AN2             (0x0080)  // Port 9 bit 7 
				 
#define SMCLK       	(0x0001)  // Port J bit 0 
#define NC_J1           (0x0002)  // Port J bit 1 
#define X1_J2       	(0x0004)  // Port J bit 2 
#define X2_J3           (0x0008)  // Port J bit 3 
#define LFXIN           (0x0010)  // Port J bit 4 
#define LFXOUT         	(0x0020)  // Port J bit 5 
#define HFXIN          	(0x0040)  // Port J bit 6 
#define HFXOUT	        (0x0080)  // Port J bit 7 



 #ifdef	__MSP430_HAS_MPY32__
#define __MSP430_HAS_MPY__
 #endif	

#define  __I2C_HARD__
//Twc       = 5  		//  [mS] Write cycle time (byte or page)
MAX_NAC_N = 100   	// 5mS  
//MAX_PAGE_WRITE_N = 128
#define SDA_DIR   SDA, &P1DIR  
#define SCL_DIR   SCL, &P1DIR  
#define SDA_OUT   SDA, &P1OUT  
#define SCL_OUT   SCL, &P1OUT  
#define SCL_SDA	  SCL|SDA, &P1SEL1  
// =================== BIT DEFINE =====================
#define SW_B		SW, &P2IN

#define LED_GREEN_B		LED, &P1OUT
//#define TxRx_B                TxRx, 	&P1OUT // No RS485!!!
#define SiNC_B			TP2, 	&P1OUT


#define PD_Req_B	        PowerSaveReq_B, &Status01	// Power Save request..
#define PD_Mode_B	        PowerSaveMode_B, &Status01
#define PD_Req_PD_Mode	        PowerSaveReq_B|PowerSaveMode_B, &Status01

// =============== REDEFINE REG  ==============

#define	__DDS__
  #ifdef	__DDS__
#define	DDS_SPI_BUSY_B    UCBUSY, &UCB1STAT
#define	DDS_SPI_TXIFG_B   UCTXIFG, &UCB1IFG
#define	DDS_SPI_TXBUF     UCB1TXBUF_
#define	DDS_SPI_RXBUF     UCB1RXBUF
#define  DDS_CS_B  	DDS1_CS, &P1OUT
#define  DDS2_CS_B  	DDS2_CS, &P1OUT
 #endif

#define RTC       YES
#define __NO_RF__
//#define LCD_PRESENT
//#define __DIV64__
//#define  __ATAN__
//#define PTR_TUPE_BLOCK
// =============== END DEFINE =========================

;-------------------------------------------------------------------------------
;-------------------------------------
;-------- *** StatusI2C bits *** ------
#define _I2C_RxOk_B      (0x0001) 	//
#define _I2C_TxOk_B      (0x0002) 	//
#define _I2C_rSTT_B  	 (0x0004) 	//
#define _I2C_Fill_B  	 (0x0008) 	//
#define _I2C_nNAC_B  	 (0x0010) 	//

#define I2C_RxOk_B  	 _I2C_RxOk_B, &StatusI2C     
#define I2C_TxOk_B  	 _I2C_TxOk_B, &StatusI2C     
#define I2C_rSTT_B  	 _I2C_rSTT_B, &StatusI2C
#define I2C_Fill_B  	 _I2C_Fill_B, &StatusI2C
#define I2C_nNAC_B  	 _I2C_nNAC_B, &StatusI2C
#define I2C_Rx_Tx_St_B   _I2C_RxOk_B|_I2C_TxOk_B|_I2C_nNAC_B, &StatusI2C     

;-------- *** Status01 bits *** ------
#define _1sec_B          (0x0001) 	// 
#define _1min_B          (0x0002) 	//
#define _1hour_B         (0x0004) 	//
#define _025sec_B        (0x0008) 	//
#define ConvADC_B   	 (0x0010) 	//
#define StartWorking_B	 (0x0020) 	// 0 - cold start, 1 - start all working APP
#define Sign_B   	 (0x0040) 	// sign
#define PowerSaveReq_B 	 (0x0100) 	// Power Save request
#define PowerSaveMode_B	 (0x0200) 	// Power Save mode
#define scr_div10_B 	 (0x0400) 	//
#define scr_div100_B 	 (0x0800) 	//
#define LCD_On_B 	 (0x1000) 	//
#define Flash_EraseWr_B	 (0x2000) 	// 

#define LCD_active_B  	LCD_On_B, &Status01
;-------------------------------------
;-------- *** StatusAPP bits *** -----
//#define UW_DATA_RDY_B 	 (0x0001) 	// -- Resived pack decode Ok!
//#define MODEM_BUZY_B 	 (0x0002) 	// 
//#define MODEM_TX_B	 (0x0004) 	//
#define DUBLE_ERR_B      (0x0008) 	//
#define LRC_ERR_B  	 (0x0010) 	//
#define INV_DATA_B	 (0x0020) 	//
#define MESSAGE_REQ_B	 (0x0040) 	// 

#define INVALID_COM_B	 (0x0100) 	//
#define WATER_SEN_B	 (0x0200) 	//

#define RefreshScript_B  (0x1000) 	//
#define StopScript_B	 (0x2000) 	// 
#define LOW_NOISE_MODE_B (0x4000) 	//
;-------------------------------------
;-------------------------------------
#define DelayINx 	50000/k_61uS	// wait INx [uS]  
#define DelaySWx 	250000/k_61uS	// wait SWx [uS]
#define DelayLedImp	1000/k_61uS	// LED flash time [uS]
#define DelayLedFlash 	10000/k_61uS	// [uS] LED flash time
;-------------------------------------------------------------------------------
;           ***** Memory definitions *****
;-------------------------------------------------------------------------------
  #define  FRAM_START   0x04400
  #define  RAM_START    0x01C00 
  #define  RAM_LENGTH   0x00800 

  #define  TINYRAM_START   0x00006 

  #define  AddrInfoSegA    0x01980      	// 5x 
  #define  AddrInfoSegB    0x01900      	// 5x
  #define  AddrInfoSegC    0x01880      	// 5x
  #define  AddrInfoSegD    0x01800  		// 5x
  #define  SizeInfoSeg     0x0080         	// 5x
  #define  SizeSeg    	   0x0200


  // The TLV structure stores device specific data 
  #define  CAL_ADC_GANE_FACTOR 		0x1A16	
  #define  CAL_ADC_OFFSET      		0x1A18
  #define  CAL_ADC_25VREF_FACTOR      	0x1A20
  #define  CAL_ADC_25T30      		0x1A22
  #define  CAL_ADC_25T85      		0x1A24
;-------------------------------------------------------------------------------
;           ***** Memory variable definitions *****
;-------------------------------------------------------------------------------
StatusAPP  = st_StatusAPP
MaxPDU		 = 64
BufferLentgh	 = (MaxPDU)
BufferLentghTX	 = (MaxPDU)

	ASEG	DATA
	ORG	RAM_START
VariableRAM
RxBuffer0 	DS8	BufferLentgh
TxBuffer0	DS8  	BufferLentghTX

RxPtr0   	DS16	1
TxPtr0   	DS16	1
CRC16Rx0	DS16	1
CRC16Tx0	DS16	1
StatusMB0	DS16	1	// status ModBus0
CounterTx0	DS16	1
VAL0_3_5ch      DS16	1
SN__      	DS16	1
 #ifdef	__A1_COM__
RxBuffer1Len	=  24
TxBuffer1Len	=  32


RxBuffer1 	DS8	RxBuffer1Len
TxBuffer1	DS8  	TxBuffer1Len
StatusRSCOM
StatusMB1	DS16	1	// status ModBus1
RxPtr1   	DS16	1
TxPtr1   	DS16	1
CRC16Rx1	DS16	1
CRC16Tx1	DS16	1
CounterTx1	DS16	1
VAL1_3_5ch      DS16	1

#endif

Status01	DS16	1
StatusI2C       DS16	1
TimerUSER_mS	DS16	1
TimerLED1	DS16	1
TimerLED2	DS16	1
TimerBUZ	DS16	1
TimerPowOFF	DS16	1
I2C_TxCnt       DS16	1
I2C_DataCnt     DS16	1
I2C_TxPtr       DS16	1
I2C_DataPtr     DS16	1
I2C_cntNAC      DS16	1

DataREG 
AddrREG		DS16	1 // Slot buffer
AddrREG1	DS16	1 // Slot buffer

BufMEM		DS16	(Size_BufMEM/2+2)	// Main buffer8 +4 address + 4 TemporaryDWord = 16byte
Size_BufMEM	= 8
AddrMEM  =  (BufMEM+0)		// Main buffer
DataMEM =   (BufMEM+2)		// Main buffer  +2 address 2 byte
Buf_OLED =  (BufMEM+1)	        // Main buffer  +1 address 1 byte
TemporaryDWord  DS16	1
TemporaryWord   DS16    1

STM_Main        DS16    1
STM_DSP		DS16	1	//
FlagsDSP	DS16	1
DATA_MES	DS16	1       // ptr Data
N_DATA_MES	DS16	1       // len
//IndexDrv	DS16	1	// index Step Drive

TA1R_EXT	DS16	1	// ext. cnt. TA1R
TA1CCR1_EXT	DS16	1	// ext. TA1CCR1
M_dT   		DS32	1	// for MS5837
M_D1   		DS32	1	// for MS5837
M_OFF  		DS16	3	// for MS5837

//-------- XXX ----------

//Cnt_EVENT	DS16	1
//TMP_TA1R	DS32	1
//TMP1_TA1R	DS32	1
//TMP2_TA1R	DS32	1
RndNum		DS16	1
cur_Freq	 DS32   1

//-----------------------
KeyBuf
StatusLCD		DS16	1
ColumnAddress		DS16	1
PageAddress		DS16	1
//-----------------------
ptr_ServScript	DS16	1
IF_STACK     	DS8	1
SlaveAddressMB0	DS8	1       // ModBus USCA0
LRCa		DS8	1
LRCb		DS8	1
//-----------------------
/*
#define	PxIN_key         P2IN
#define	MASK_key  	(KN1|KN2|KN3)
#define	MASK_all_key  	(KN1|KN2|KN3)
#define	MASK_long_key  	(KN2)
#define	NORMAL_key  	2       // 1/16sec
#define	LONG_key  	32	// 1sec
*/
#define PB_SHORT   1, &KeyBuf
#define PB_LONG	   2, &KeyBuf
#define PB_UP      4, &KeyBuf
#define PB_DN	   8, &KeyBuf
#define PB_RIGHT   16, &KeyBuf
#define PB_LEFT	   32, &KeyBuf
/*
TMR_key		DS8	1
HOLD_key	DS8	1
PREV_key	DS8	1
PUSH_key	DS8     1
LONG_PUSH_key	DS8     1
TMR_EXT_INFO	DS8     1
*/
//-----------------------

	EVEN
;-------------------------------------------------------------------------------
EndVariableRAM	= $
;-------------------------------------------------------------------------------
//------- *** STM_DSP *** ----	// 
st_DSP_stop   		= 0    	// -- stop 
st_DSP_start		= 2     // -- start
st_DSP_AB_mn		= 4     // -- set AB mn
st_DSP_on_AB 		= 6    	// -- on_AB
st_DSP_measure		= 8    	// -- measure
st_DSP_off_AB_mn	= 10   	// -- off_AB_mn
st_DSP_calc		= 12   	// -- calc
st_DSP_next		= 14	// -- next

//-------------------------------------------------------------------------------
//-------------------------------------------------------------------------------

