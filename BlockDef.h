;-------------------------------------------------------------------------------
;           ***** Blocks Definition *****
;-------------------------------------------------------------------------------
IdShift			equ 		100
IdBlock_Header		equ 		1	
IdBlock_Info		equ  		IdShift+2
IdBlock_Constant	equ		IdShift+3	// Block System Constant
IdBlock_Data		equ      	IdShift+4
IdBlock_Settings	equ  		IdShift+5
IdBlock_Status		equ    		IdShift+6
IdBlock_Key		equ	    	IdShift+7
IdBlock_RF_Key		equ	    	IdShift+8
IdBlock_ROUTE		equ	    	IdShift+9
IdBlock_COLLECT		equ	    	IdShift+10
IdBlock_Available_Nodes equ	    	IdShift+11		
IdBlock_LIST		equ		IdShift+12
IdBlock_VirtualData	equ		IdShift+13	
IdBlock_ROUTE_02	equ	    	IdShift+14

IdBlock_Profile_E       equ		IdShift+15	// E - ProFile Power
IdBlock_Profile_A       equ		IdShift+16	// A - ProFile Temperature
IdBlock_Profile_B       equ		IdShift+17	// B - ProFile Voice
IdBlock_Profile_C       equ		IdShift+18	// C - ProFile Light
IdBlock_Profile_D       equ		IdShift+19	// D - ProFile Motion

IdBlock_Association_Table equ		IdShift+20	// Table Association - 4byte[addr lo, addr hi, capability, rssi]
							// Internal RAM  4*24=96byte

IdBlock_MessageDATA 	equ		IdShift+21	// Store buffer for pending data - 128*Xbyte
IdBlock_Association_Table_X 	equ	IdShift+22	// Table Association - 4byte[addr lo, addr hi, capability, rssi]
                                                        // таблица разрешенных для ассоциации адресов!
IdBlock_VirtBl_Message_Notify  	equ	IdShift+25      // используется для разбора message внешними приложениями!!!

IdBlock_CharGen		equ		80	// Char Generator
IdBlock_Logo		equ		81	// size 1 KB
IdBlock_Picture		equ		IdBlock_Logo
IdBlock_TextTask	equ		82	// SCRIPT
IdBlock_RAM_BUFF	equ		83	// SPI RAM Buffer
IdBlock_Ext_RAM		equ		83	// RAM Buffer
IdBlock_Ext_EEPROM	equ		84	// EEPROM Buffer

IdBlock_BW_DataIO_CTRL	equ		50	// bit => word expander block
IdBlock_PageMem         equ		51      // PageMem block, size => (65536*X)-1
IdBlock_ConstantII	equ		53      // Block alt Constant

// *** use only TRAFFIC LIGHT! *********************************************************
IdBlock_CONSTANT_TR	equ		60	// == Block_CONSTANT_TR TRAFFIC_LIGHT ==
IdBlock_DATA_TR		equ		61	// == Block_SETTINGS_TR TRAFFIC_LIGHT ==
IdBlock_SETTINGS_TR	equ		62	// == Block_SETTINGS_TR TRAFFIC_LIGHT ==
IdBlock_STATUS_TR	equ		63	// == Block_STATUS_TR 	TRAFFIC_LIGHT ==
IdBlock_CONFIG_TR	equ		64	// == Block_CONFIG_TR 	TRAFFIC_LIGHT ==
IdBlock_STAT_CH_TR	equ		65	// == Block_STAT_CH_TR 	TRAFFIC_LIGHT ==

IdBlock_TASK_01_TR	equ		66	// == Block_TASK_01_TR 	TRAFFIC_LIGHT ==
IdBlock_TASK_02_TR	equ		67	// == Block_TASK_01_TR 	TRAFFIC_LIGHT ==
IdBlock_TASK_03_TR	equ		68	// == Block_TASK_01_TR 	TRAFFIC_LIGHT ==
IdBlock_TASK_04_TR	equ		69	// == Block_TASK_01_TR 	TRAFFIC_LIGHT ==
IdBlock_TASK_05_TR	equ		70	// == Block_TASK_01_TR 	TRAFFIC_LIGHT ==
IdBlock_TASK_06_TR	equ		71	// == Block_TASK_01_TR 	TRAFFIC_LIGHT ==
IdBlock_TASK_07_TR	equ		72	// == Block_TASK_01_TR 	TRAFFIC_LIGHT ==
IdBlock_TASK_08_TR	equ		73	// == Block_TASK_01_TR 	TRAFFIC_LIGHT ==
//**************************************************************************************


//#include "All_Block.s43"                     	
;-------------------------------------------------------------------------------
