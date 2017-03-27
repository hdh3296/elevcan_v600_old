

extern void             __attribute__((section(".usercode"))) Ladder485Init(void);
extern unsigned int     __attribute__((section(".usercode"))) NewFlashData(void);
extern void    __attribute__((section(".usercode"))) VirtualMoveCntReDsp(void);



#define     ONEKEY                  '1'      
#define     TWOKEY                  '2'      
#define     THREEKEY                '3'      
#define     FOURKEY                 '4'
#define     FIVEKEY                 '5'      
#define     SIXKEY                  '6'
#define     SEVENKEY                '7'      
#define     EIGHTKEY                '8'      
#define     NINEKEY                 '9'      
#define     ZEROKEY                 '0'
#define     ENTKEY                  'e'      
#define     MENUKEY                 'm'      
#define     ESCKEY                  'c'      
#define     UPKEY                   'u'      
#define     DOWNKEY                 'd'
#define     LEFTKEY                 'l'      
#define     RIGHTKEY                'r'
#define     ENTKEY                  'e'      


#define     DIGIT_EDIT              0
#define     DIGIT_ALPHAR_EDIT       1
#define     TABLE_EDIT              2
#define     TOGGLE_EDIT             3
#define     DIGIT_STRING_EDIT       4
#define     CLOCK_EDIT              5
#define     NO_EDIT                 6



#define SECONDLINE_CURSOR           1

#define FIRSTLINE_BASE           	2
#define SECONDLINE_BASE             18



#define GROUP_01                  	1
#define GROUP_02               		2
#define GROUP_03                   	3
#define GROUP_04                 	4
#define GROUP_05                	5
#define GROUP_06                	6
#define GROUP_07              		7
#define GROUP_08                    8
#define GROUP_09             		9
#define GROUP_10             		10
#define GROUP_11                 	11
#define GROUP_12                 	12
#define GROUP_13                 	13
#define GROUP_14               		14
#define GROUP_15               		15
#define GROUP_16               		16
#define GROUP_17                 	17
#define GROUP_18               		18	  	// 0  delta inverter parameter group
#define GROUP_19               		19    	// 1
#define GROUP_20               		20    	// 2
#define GROUP_21               		21    	// 3
#define GROUP_22               		22		// 4
#define GROUP_23               		23		// 5
#define GROUP_24               		24		// 6
#define GROUP_25               		25		// 7
#define GROUP_26               		26		// 8
#define GROUP_27               		27		// 9
#define GROUP_28               		28		// 10
#define GROUP_29               		29		// 11
#define GROUP_30               		30		// 12
#define GROUP_31               		31		// 13
#define GROUP_32               		32		// 14


/*
#define USER_GROUP                  1
#define FLR_DSP_GROUP               2
#define FLR_GROUP                   3
#define TIMER_GROUP                 4
#define ONOFF1_GROUP                5
#define ONOFF2_GROUP                6
#define SUB_DOOR_GROUP              7
#define IO_GROUP                    8
#define PARAMETER_GROUP             9
#define OPEN_WAIT_GROUP             10
#define NCNO1_GROUP                 11
#define NCNO2_GROUP                 12
#define NCNO3_GROUP                 13
#define INPORT1_GROUP               14
#define INPORT2_GROUP               15
#define OUTPORT_GROUP               16
#define ERROR_GROUP                 17
#define EL_GROUP               		18
#define INV_PAR_GROUP_00          19
#define INV_PAR_GROUP_01          20
#define INV_PAR_GROUP_02          21
#define INV_PAR_GROUP_03          22
#define INV_PAR_GROUP_04          23
#define INV_PAR_GROUP_05          24
#define INV_PAR_GROUP_06          25
#define INV_PAR_GROUP_07          26
#define INV_PAR_GROUP_08          27
#define INV_PAR_GROUP_09          28
#define INV_PAR_GROUP_10          29
#define INV_PAR_GROUP_11          30
#define INV_PAR_GROUP_12          31
#define INV_PAR_GROUP_13          32
#define INV_PAR_GROUP_14          33
#define INV_PAR_GROUP_END		  34

#define MAX_GROUP_SPD3              17
#define MAX_GROUP                   18
*/


#define USER_GROUP                  1
#define FLR_DSP_GROUP               2
#define FLR_GROUP                   3
#define TIMER_GROUP                 4
#define ONOFF1_GROUP                5
#define ONOFF2_GROUP                6
#define SUB_DOOR_GROUP              7
#define OPEN_WAIT_GROUP             8
#define NCNO1_GROUP                 9
#define NCNO2_GROUP                 10
#define NCNO3_GROUP                 11
#define INPORT1_GROUP               12
#define INPORT2_GROUP               13
#define OUTPORT_GROUP               14
#define ERROR_GROUP                 15
#define EL_GROUP               		16
									
#define INV_PAR_GROUP_00          	17
#define INV_PAR_GROUP_01          	18
#define INV_PAR_GROUP_02          	19
#define INV_PAR_GROUP_03          	20
#define INV_PAR_GROUP_04          	21
#define INV_PAR_GROUP_05          	22
#define INV_PAR_GROUP_06          	23
#define INV_PAR_GROUP_07          	24
#define INV_PAR_GROUP_08          	25
#define INV_PAR_GROUP_09          	26
#define INV_PAR_GROUP_10          	27
#define INV_PAR_GROUP_11          	28
#define INV_PAR_GROUP_12          	29
#define INV_PAR_GROUP_13          	30
#define INV_PAR_GROUP_14          	31
#define INV_PAR_GROUP_END		  	32

#define MAX_GROUP_SPD3              INV_PAR_GROUP_00
#define MAX_GROUP                   EL_GROUP




//#define IO_GROUP                    50
//#define PARAMETER_GROUP             51





#define     SUBNM_ENCODER_PULSE         0  
#define     SUBNM_TM_MPM                1  
#define     SUBNM_MOTOR_RPM             2  

#define     SUBNM_MANUAL_PORT         	3  
#define     SUBNM_BATTERY_PORT          4  
#define     SUBNM_DEC_PORT             	5  
#define     SUBNM_FHM_PORT             	6  
#define     SUBNM_LOW_SPD_PORT          7  
#define     SUBNM_MID_SPD_PORT       	8  
#define     SUBNM_HIGH_SPD_PORT         9  
#define     SUBNM_LOW_SPD_DEC_LENTH     10  
#define     SUBNM_MID_SPD_DEC_LENTH     11  
#define     SUBNM_HIGH_SPD_DEC_LENTH    12  
#define     SUBNM_BASE_DEC_MPM          13  
#define     SUBNM_BASE_DEC_TIME         14  
#define     SUBNM_BASE_SCURVE_TIME      15  
#define     SUBNM_SU2SD2_SPD           	16  
#define     SUBNM_X0X1_SPD             	17  
#define     SUBNM_SNNSOR_POSITION       18
#define     SUBNM_NOTUSE1             	19  
#define     SUBNM_NOTUSE2          		20  
#define     SUBNM_NOTUSE3             	21  
#define     SUBNM_NOTUSE4             	22  
#define     SUBNM_LIMIT_SU             	24  
#define     SUBNM_LIMIT_SD             	25  
#define     SUBNM_LOW_SPD_PULSE     	26  
#define     SUBNM_MID_SPD_PULSE     	27  
#define     SUBNM_HIGH_SPD_PULSE     	28  
#define     SUBNM_BASE_PULSE     		29  
#define     SUBNM_MPM_VARIABLE     		30  
#define     SUBNM_MM_PER_PULSE     		31  






/*
#define DELTA_PAR_GROUP_00          19
#define DELTA_PAR_GROUP_01          20
#define DELTA_PAR_GROUP_02          21
#define DELTA_PAR_GROUP_03          22
#define DELTA_PAR_GROUP_04          23
#define DELTA_PAR_GROUP_05          24
#define DELTA_PAR_GROUP_06          25
#define DELTA_PAR_GROUP_07          26
#define DELTA_PAR_GROUP_08          27
#define DELTA_PAR_GROUP_09          28
#define DELTA_PAR_GROUP_10          29
#define DELTA_PAR_GROUP_11          30
#define DELTA_PAR_GROUP_12          31
#define DELTA_PAR_GROUP_13          32
#define DELTA_PAR_GROUP_14          33
#define DELTA_PAR_GROUP_END			34
*/


#ifdef	FLOOR_64
#define FLR_DSP_GROUP_MAX           64
#define ONOFF1_GROUP_MAX            64
#else
#define FLR_DSP_GROUP_MAX           32
#define ONOFF1_GROUP_MAX            32
#endif



#define USER_GROUP_MAX              32
#define FLR_GROUP_MAX               16
#define TIMER_GROUP_MAX             26
#define ONOFF2_GROUP_MAX            32
#define IO_GROUP_MAX                24
#define PARAMETER_GROUP_MAX         32
#define OPEN_WAIT_GROUP_MAX         4
#define NCNO1_GROUP_MAX             32
#define NCNO2_GROUP_MAX             24
//#define NCNO2_GROUP_MAX             16
//#define NCNO3_GROUP_MAX             23
#define NCNO3_GROUP_MAX             SILK_EXT_Y0
#define INPORT1_GROUP_MAX           32
//#define INPORT2_GROUP_MAX           16
#define INPORT2_GROUP_MAX           24
#define OUTPORT_GROUP_MAX           SILK_EXT_Y0
//#define OUTPORT_GROUP_MAX           23
#define ERROR_GROUP_MAX             40
#define EL_GROUP_MAX         		32
#define DELTA_GROUP_MAX				40
#define MOTOR_GROUP_MAX				32




#define     NORMAL_DSP_MESSAGE_CNT  32
#define     INIT_MESSAGE            8 
#define     USER_LAMP_MESSAGE_CNT   11


#define     IO_PORT_MESSAGE_CNT     	9
#define     ELEV_BD_ID_MESSAGE_CNT  	10
#define     ELEV_ONOFF_MESSAGE_CNT  	32
#define     ENCODERRATE_MESSAGE_CNT 	4

#define     INPORT1_SEL_MESSAGE_CNT 	32
#define     INPORT2_SEL_MESSAGE_CNT 	32
#define     OUTPORT_SEL_MESSAGE_CNT 	(NO_USE_OUT+1)
#define     DOOR_SEL_MESSAGE_CNT 		4
#define     FINAL_ERR_DSP_MESSAGE_CNT   18
#define     SYSTEM_SET_MESSAGE_CNT  	4
#define     SENSOR_POSITION_MESSAGE_CNT 14



#define     ELEV_SPEED_MESSAGE_CNT_SPD3  	6
#define     ELEV_SPEED_MESSAGE_CNT  		9

//#define     AUTO_LANDING_MESSAGE_CNT  		2


#define		SENSOR_LENGTH	0
#define		PLANK_LENGTH	1
#define		SDS_LENGTH		2
#define		SUS_LENGTH		3
#define		SD1_LENGTH		4
#define		SU1_LENGTH		5
#define		X1_LENGTH		6
#define		X0_LENGTH		7	
#define		CENTER_LENGTH	8
#define		NC2_LENGTH		9
#define		L_DEC_LENGTH	10
#define		M_DEC_LENGTH	11
#define		H_DEC_LENGTH	12
#define		LEVEL_POSITION	13


#define     MAX_LADDER_BUF          40


#define     TOP_FLR                 0 
#define     PRK_FLR                 1 
#define     NO_USE_GO_FLR           2 
#define     FIRE_SAFE_FLR           3 
#define     X7_SAFE_FLR             4
#define     WATER_SAFE_FLR          5 
#define     START_FLR               6 
#define     ONE_STOP_FLR            7
#define     KIDS_KEY_CNT            8
#define     X6_SAFE_FLR             9
#define     X5_SAFE_FLR             10
#define     NC21FLR                 11
#define     NC20FLR                 12
#define     NC19FLR                 13
#define     NC18FLR                 14
#define     NC17FLR                 15
#define     NC16FLR                 16
#define     NC15FLR                 17
#define     NC14FLR                 18
#define     NC13FLR                 19
#define     NC12FLR                 20
#define     NC11FLR                 21
#define     NC10FLR                 22
#define     NC09FLR                 23
#define     NC08FLR                 24
#define     NC07FLR                 25
#define     NC06FLR                 26
#define     NC05FLR                 27
#define     NC04FLR                 28
#define     NC03FLR                 29
#define     NC02FLR                 30
#define     NC01FLR                 31


#define     NCNO1_EMG               0 
#define     NCNO1_PRK               1 
#define     NCNO1_AUTO              2 
#define     NCNO1_UB                3 
#define     NCNO1_DB                4 
#define     NCNO1_OLS               5 
#define     NCNO1_GS                6 
#define     NCNO1_DS                7 



#define     VERSION                 0  
#define     BOARD_ID                1
#define     AUTOLANDING_MODE        2    
#define     USER_LAMP1              3
#define     USER_LAMP2              4
#define     PASSWARD                5
#define     NORMAL_DSP              6  
#define     DRIVE_METHOD            7  
#define     FHM_RUN_CHK             8  
#define     ALL_MENU_CHK            9 
#define     ENGINEER_NM             10
//#define     TOTAL_USE_TIME          11 
#define     INIT_DATA               12 
#define     GROUP_NUMBER            13 
#define     LOCAL_NUMBER            14 
#define     LG_INV_IN_BD            15 
#define     VIRTUAL_CALL            16 
#define     HH_MM_SS                17 
#define     YY_MM_DD                18 
#define     ERR_ST_CNT              19  
#define     COMPANY_NAME            20
#define     OUT_DATE         		21
#define     USER_LAMP3              22
#define     USER_LAMP4              23
#define     HALL_IND_SET            24
#define     User_G4                25
#define     User_G5                 26
#define     User_G6                 27
#define     FINAL_ERR_DSP           28
#define     User_G8         		29
#define     SYSTEM_SET              30
#define     ENCODER_RATE          	31
  


#define     FHM_CHK                 0
#define     DR_JMP_CHK              1
#define     ENCODER_PH              2
#define     ONOFF2_29               3
#define     ONOFF2_28               4
#define     ONOFF2_27               5
#define     ONOFF2_26               6    
#define     ONOFF2_25               7
#define     ONOFF2_24               8
#define     ONOFF2_23               9
#define     ONOFF2_22               10
#define     ONOFF2_21               11
#define     ONOFF2_20               12    
#define     MGT_MON_CHK             13
#define     ONOFF2_18               14
#define     ONOFF2_17               15
#define     ONOFF2_16               16    
#define     ONOFF2_15               17
#define     ONOFF2_14               18    
#define     BRK_MON_CHK             19
#define     ONOFF2_12               20
#define     ONOFF2_11               21
#define     ONOFF2_10               22
#define     ONOFF2_9                23
#define     ONOFF2_8                24
#define     ONOFF2_7                25
#define     ONOFF2_6                26
#define     ONOFF2_5                27
#define     ONOFF2_4                28
#define     ONOFF2_3                29
#define     ONOFF2_2                30
#define     ONOFF2_1                31



#define     P_ENCODER_PULSE         0  
#define     P_TM_MPM                1  
#define     P_MOTOR_RPM             2  
#define     P_DEC30                 3  
#define     P_DEC45                 4  
#define     P_DEC60                 5  
#define     P_DEC90                 6  
#define     P_DEC105                7  
#define     P_DEC120                8  
#define     P_DEC150                9  
#define     P_DEC180                10 
#define     P_DEC210                11
#define     P_MINDEC30              12  
#define     P_MINDEC45              13 
#define     P_MINDEC60              14 
#define     P_MINDEC90              15 
#define     P_MINDEC105             16 
#define     P_MINDEC120             17 
#define     P_MINDEC150             18 
#define     P_MINDEC180             19 
#define     P_MINDEC210             20 
#define     P_PAR1                  21
#define     P_PAR2                  22
#define     P_PAR3                  23 
#define     P_PAR4            		24
#define     P_PAR5                  25
#define     P_PAR6                  26
#define     P_PAR7                  27
#define     P_PAR8                  28
#define     P_PAR9                  29
#define     P_PAR10                 30
#define     P_PAR11                 31


extern	UserDataType    LadderGroupSelect;
extern	UserDataType    GroupBaseAddr;
extern	UserDataType    LadderGroup;
extern	UserDataType    LadderGroupSub;
extern	UserDataType    LadderKey;
extern	UserDataType    EnterKey;
extern	UserDataType    Cursor;
extern	UserDataType    EditStatus;
extern	UserDataType    EditBlanck;
extern	UserDataType    ShiftCnt;
extern	UserDataType    DecimalPt;
extern	UserDataType    MaxSubMenu;
extern	UserDataType    MemPointer;



extern	unsigned int   DigitData;
extern	unsigned int   DigitMaxValue;
extern	unsigned int   DigitMinValue;
extern	unsigned int   DigitAttribute;
