
#include  "iodef.h"
#include  "30f6010_io.h"            
#include  "default_setup.h" 
#include  "you_can2.h" 


void  __attribute__((section(".usercode"))) Delta_inverter_Par_DataSort(unsigned int this_data);

void  __attribute__((section(".usercode"))) Pc_Command(void);

//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////

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


#define MAX_GROUP_SPD3              17
#define MAX_GROUP                   18



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
#define     SUBNM_BASE_DEC_LENTH        13  
#define     SUBNM_BASE_DEC_TIME         14  
#define     SUBNM_BASE_SCURVE_TIME      15  
#define     SUBNM_SU2SD2_SPD           	16  
#define     SUBNM_X0X1_SPD             	17  
#define     SUBNM_LULD_MPM             	18
#define     SUBNM_NOTUSE             	19  
#define     SUBNM_AUTO_LANDING          20  
#define     SUBNM_AUTO_TUN             	21  
#define     SUBNM_FHM             		22  

#define     SUBNM_LOW_SPD_PULSE     	26  
#define     SUBNM_MID_SPD_PULSE     	27  
#define     SUBNM_HIGH_SPD_PULSE     	28  
#define     SUBNM_BASE_PULSE     		29  
#define     SUBNM_MPM_VARIABLE     		30  
#define     SUBNM_MM_PER_PULSE     		31  






#ifdef	FLOOR_64
#define FLR_DSP_GROUP_MAX           64
#define ONOFF1_GROUP_MAX            64
#else
#define FLR_DSP_GROUP_MAX           32
#define ONOFF1_GROUP_MAX            32
#endif



#define USER_GROUP_MAX              32
#define FLR_GROUP_MAX               16
#define TIMER_GROUP_MAX             25
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
#define     FINAL_ERR_DSP_MESSAGE_CNT   15
#define     SYSTEM_SET_MESSAGE_CNT  	4
#define     SENSOR_POSITION_MESSAGE_CNT 10



#define     ELEV_SPEED_MESSAGE_CNT_SPD3  	5
#define     ELEV_SPEED_MESSAGE_CNT  		9

#define     AUTO_LANDING_MESSAGE_CNT  		2
//#define     AUTO_LANDING_MESSAGE_CNT  		3


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
#define     PASSWARD                2
#define     USER_LAMP1              3
#define     USER_LAMP2              4
#define     SERIAL_NM               5   
#define     NORMAL_DSP              6  
#define     DRIVE_METHOD            7  
#define     FHM_RUN_CHK             8  
#define     ALL_MENU_CHK            9 
#define     ENGINEER_NM             10
#define     TOTAL_USE_TIME          11 
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
#define     SENSOR_POSITION         29
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




UserDataType    New485Ladder[MAX_LADDER_BUF]={0};      


UserDataType    LadderGroupSelect;

UserDataType    GroupBaseAddr;
UserDataType    LadderGroup;
UserDataType    LadderGroupSub;
UserDataType    LadderKey;
UserDataType    EnterKey;
UserDataType    Cursor;
UserDataType    EditStatus;
UserDataType    EditBlanck;
UserDataType    ShiftCnt;
UserDataType    MaxSubMenu;
UserDataType    MemPointer;


UserDataType   pw[4];

unsigned int   DigitData;
unsigned int   DigitMaxValue;
unsigned int   DigitMinValue;
unsigned int   OrgNcNo;


/*
const unsigned char ErrStatusMessage[][16]={
                                      "Inspection      ",      //000                               
                                      "Inverter        ",      //001                               
                                      "INV Floor       ",      //002                               
                                      "Emergency       ",      //003                               
                                      "Governer        ",      //004                               
                                      "Motor Overht    ",      //005                                                                           
                                      "Slip            ",      //006                               
                                      "ULS             ",      //007                                                                     
                                      "DLS             ",      //008                               
                                      "LuLd Off        ",      //009
                                      "NextFloor       ",      //010
                                      "InPort          ",      //011
                                      "Hall Door       ",      //012
                                      "Car Door        ",      //013
                                      "Relvel          ",      //014
                                      "No Encoder      ",      //015
                                      "Encoder A-B     ",      //016
                                      "ElevSpeed       ",      //017
                                      "Speed Port      ",      //018
                                      "No Use Speed    ",      //019
                                      "MinDecLength    ",      //020
                                      "Flr Match       ",      //021
                                      "System          ",      //022
                                      "Break Mgt       ",      //023
                                      "Break On/Off    ",      //024
                                      "Sus             ",      //025
                                      "Sds             ",      //026
									  "LuLd Change     ",      //027 
									  "Ld On     	   ",      //028
									  "Ld Off          ",      //029
									  "Lu On           ",      //030
									  "Lu Off          ",      //031
									  "LuLd OnOff      ",      //032
                                      "CarDoor Jmp     ",      //033                                                                           
                                      "HallDoor Jmp    ",      //034
                                      "CarHall Jmp     ",      //035
                                      "036             ",      //036
                                      "037             ",      //037
                                      "038             ",      //038
                                      "039             ",      //039
                                      "040             ",      //040
                                      "041             ",      //041
                                      "042             ",      //042
                                      "FHM_Error       ",      //043
                                      "No Hall Door Sw ",      //044
                                      "No Close End    ",      //045
                                      "Over Load Stop  ",      //046
                                      "Parking Mode    ",      //047
                                      "   Fire         ",      //048
                                      "Water_Sensing   ",      //049                                       
                                      "No Open End     ",      //050
                                      "VIP Drive       ",      //051                                     
                                      "FHM_Mode        ",      //052                                     
                                      "Manual Up       ",      //053
                                      "Manual Dn       ",      //054
                                      "Manual Mode     ",      //055
                                      "Safety Open     ",      //056
                                      "Open Door       ",      //057
                                      "Close Door      ",      //058                                     
                                      "Auto Up         ",      //059                                     
                                      "Auto Dn         ",      //060                                     
                                      "Slow Speed      ",      //061
                                      "Wait LuLd       ",      //062
                                      "Auto Stop       ",      //063
                                      "Wait... Home !  ",      //064
                                      "Auto Ready      ",      //065
                                    };                                       
*/


const unsigned char BdName485[][4]={"000"," 01"," 02"," 03"," 04"," 05"," 06"," 07"," 08"," 09"," 10",
                                          " 11"," 12"," 13"," 14"," 15"," 16"," 17"," 18"," 19"," 20",
                                          " 21"," 22"," 23"," 24"," 25"," 26"," 27"," 28"," 29"," 30",
                                          " 31"," 32","AVO","BVO","CVO","DVO","AC1","AC2","AC3","AC4",
                                          "BC1","BC2","BC3","BC4","CC1","CC2","CC3","CC4","DC1","DC2",
                                          "DC3","DC4","AXO","AX1","BXO","BX1","CXO","CX1","DXO","DX1",
                                          "A_M","BM1","BM2","CM1","CM2","DM1","DM2","ALD","BLD","CLD",
                                          "DLD","APC","BPC","CPC","DPC"};


const unsigned char GroupLineMessage[][17]={
                                    "FL:00           ",//0
///////////////////////////////////////////////////////////                                                                                                           
                                    "USER:Version    ",//1  
                                    "USER:BoardId    ",//2 
                                    "USER:Passward   ",//3  
                                    "USER:UserLamp1  ",//4  
                                    "USER:UserLamp2  ",//5  
                                    "USER:SerialNm   ",//6  
                                    "USER:Normal Dsp ",//7  
                                    "USER:DriveMethod",//8 
                                    "USER:Fhm Run    ",//9 
                                    "USER:SubMenu On ",//10 
                                    "USER:Engineer Nm",//11 
                                    "USER:Tt Use Time",//12 
                                    "USER:Init Data  ",//13 
                                    "USER:Group Nm   ",//14 
                                    "USER:Local Nm   ",//15 
                                    "USER:Inv InBd Tp",//16
                                    "USER:Call(c-f-f)",//17
                                    "USER:hh-mm-ss   ",//18 
                                    "USER:yy-mm-dd   ",//19
                                    "USER:ErrStCnt   ",//20  
                                    "USER:Company    ",//21									  
                                    "USER:OutDate    ",//22  
                                    "USER:UserLamp3  ",//23  
                                    "USER:UserLamp4  ",//24  
                                    "USER:C-K-H-O-B-R",//25  //cancle,openkey,halllantern,offset,button type,reserve
                                    "USER:User4      ",//26 
                                    "USER:User5      ",//27 
                                    "USER:User6      ",//28 
                                    "USER:F-Error(00)",//29 
                                    "USER:SenPosi(00)",//30 
                                    "USER:System Mode",//31  
                                    "USER: Stop Pulse",//32 
///////////////////////////////////////////////////////////                                    
                                    "DSP:Floor01     ",//1
                                    "DSP:Floor02     ",//2
                                    "DSP:Floor03     ",//3
                                    "DSP:Floor04     ",//4
                                    "DSP:Floor05     ",//5
                                    "DSP:Floor06     ",//6
                                    "DSP:Floor07     ",//7
                                    "DSP:Floor08     ",//8
                                    "DSP:Floor09     ",//9
                                    "DSP:Floor10     ",//0
                                    "DSP:Floor11     ",//11
                                    "DSP:Floor12     ",//12
                                    "DSP:Floor13     ",//13
                                    "DSP:Floor14     ",//14
                                    "DSP:Floor15     ",//15
                                    "DSP:Floor16     ",//16
                                    "DSP:Floor17     ",//17
                                    "DSP:Floor18     ",//18
                                    "DSP:Floor19     ",//19
                                    "DSP:Floor20     ",//20
                                    "DSP:Floor21     ",//21
                                    "DSP:Floor22     ",//22
                                    "DSP:Floor23     ",//23
                                    "DSP:Floor24     ",//24
                                    "DSP:Floor25     ",//25
                                    "DSP:Floor26     ",//26
                                    "DSP:Floor27     ",//27
                                    "DSP:Floor28     ",//28
                                    "DSP:Floor29     ",//29
                                    "DSP:Floor30     ",//30
                                    "DSP:Floor31     ",//31
                                    "DSP:Floor32     ",//32
///////////////////////////////////////////////////////////                                    
                                    "FLR:TopFlr      ",//1 
                                    "FLR:PrkFlr      ",//2 
                                    "FLR:NoUse Go Flr",//3 
                                    "FLR:FireSafe Flr",//4 
                                    "FLR:2'F_Safe Flr",//5 
                                    "FLR:WaterSafeFlr",//6 
                                    "FLR:Start Flr   ",//7
                                    "FLR:OneStop Flr ",//8
                                    "FLR:Kids Key Cnt",//9
                                    "FLR:X6 Safe  Flr",//10
                                    "FLR:X5 Safe  Flr",//11
                                    "FLR:Nc21Flr     ",//12
                                    "FLR:Nc20Flr     ",//13
                                    "FLR:Nc19Flr     ",//14
                                    "FLR:Nc18Flr     ",//15
                                    "FLR:Nc17Flr     ",//16
                                    "FLR:Nc16Flr     ",//17
                                    "FLR:Nc15Flr     ",//18
                                    "FLR:Nc14Flr     ",//19
                                    "FLR:Nc13Flr     ",//20
                                    "FLR:Nc12Flr     ",//21
                                    "FLR:Nc11Flr     ",//22
                                    "FLR:Nc10Flr     ",//23
                                    "FLR:Nc09Flr     ",//24
                                    "FLR:Nc08Flr     ",//25
                                    "FLR:Nc07Flr     ",//26
                                    "FLR:Nc06Flr     ",//27
                                    "FLR:Nc05Flr     ",//28
                                    "FLR:Nc04Flr     ",//29
                                    "FLR:Nc03Flr     ",//30
                                    "FLR:Nc02Flr     ",//31
                                    "FLR:Nc01Flr     ",//32
///////////////////////////////////////////////////////////                                                                       
                                    "TMR:Op Wait Time",// 1
                                    "TMR:Op Total Tm ",// 2
                                    "TMR:No Use Time ",// 3
                                    "TMR:NextFlr Time",// 4
                                    "TMR:LuLdOff Time",// 5
                                    "TMR:Fan Off Time",// 6
                                    "TMR:Lit Off Time",// 7
                                    "TMR:OpClWaitTime",// 8
//                                    "TMR:DrJmpChkTime",// 9
                                    "TMR:PowerRunTime",// 9
                                    "TMR:Dir Set Time",//10
                                    "TMR:Voice OnTime",//11
                                    "TMR:Brk Mgt Time",//12
                                    "TMR:Op Hold Time",//13
                                    "TMR:P4  On  Time",//14
                                    "TMR:U/D On  Time",//15
                                    "TMR:Bk2 On  Time",//16
                                    "TMR:Bk1 On  Time",//17
                                    "TMR:Run On  Time",//18
                                    "TMR:Run Off Time",//19
                                    "TMR:Bk1 Off Time",//20
                                    "TMR:Bk2 Off Time",//21
                                    "TMR:U/D Off Time",//22
                                    "TMR:P4  Off Time",//23
                                    "TMR:Sol On  Time",//24
                                    "TMR:Door St Time",//25
                                    "TMR:Stop9   Time",//26
                                    "TMR:Stop10  Time",//27
                                    "TMR:Stop11  Time",//28
                                    "TMR:Stop12  Time",//29
                                    "TMR:Stop13  Time",//30
                                    "TMR:Stop14  Time",//31
                                    "TMR:Stop15  Time",//32
///////////////////////////////////////////////////////////                                                                                                           
                                    "ONOFF1:Floor01  ",//1 
                                    "ONOFF1:Floor02  ",//2 
                                    "ONOFF1:Floor03  ",//3 
                                    "ONOFF1:Floor04  ",//4  
                                    "ONOFF1:Floor05  ",//5  
                                    "ONOFF1:Floor06  ",//6  
                                    "ONOFF1:Floor07  ",//7  
                                    "ONOFF1:Floor08  ",//8  
                                    "ONOFF1:Floor09  ",//9  
                                    "ONOFF1:Floor10  ",//10 
                                    "ONOFF1:Floor11  ",//11 
                                    "ONOFF1:Floor12  ",//12
                                    "ONOFF1:Floor13  ",//13
                                    "ONOFF1:Floor14  ",//14
                                    "ONOFF1:Floor15  ",//15
                                    "ONOFF1:Floor16  ",//16
                                    "ONOFF1:Floor17  ",//17
                                    "ONOFF1:Floor18  ",//18
                                    "ONOFF1:Floor19  ",//19
                                    "ONOFF1:Floor20  ",//20
                                    "ONOFF1:Floor21  ",//21
                                    "ONOFF1:Floor22  ",//22
                                    "ONOFF1:Floor23  ",//23
                                    "ONOFF1:Floor24  ",//24
                                    "ONOFF1:Floor25  ",//25
                                    "ONOFF1:Floor26  ",//26
                                    "ONOFF1:Floor27  ",//27
                                    "ONOFF1:Floor28  ",//28
                                    "ONOFF1:Floor29  ",//29
                                    "ONOFF1:Floor30  ",//30
                                    "ONOFF1:Floor31  ",//31
                                    "ONOFF1:Floor32  ",//32
///////////////////////////////////////////////////////////                
                                                                                           
///////////////////////////////////////////////////////////                                                                                                           
                                    "ONOFF2:FHM Chk  ",//1 
                                    "ONOFF2:DrJmpChk ",//2 
                                    "ONOFF2:EncoderPh",//3 
                                    "ONOFF2:WardPrior",//4  
                                    "ONOFF2:NonStop  ",//5  
                                    "ONOFF2:OpenTotal",//6  
                                    "ONOFF2:WaitTotal",//7  
                                    "ONOFF2:ClosTotal",//8  
                                    "ONOFF2:C_Dr1 Chk",//9  
                                    "ONOFF2:C_Dr2 Chk",//10  
                                    "ONOFF2:H_Dr1 Chk",//11
                                    "ONOFF2:H_Dr2 Chk",//12 
                                    "ONOFF2:S_Sft Chk",//13
                                    "ONOFF2:MgtMonChk",//14
                                    "ONOFF2:Encod Chk",//15
                                    "ONOFF2:ReleveChk",//16
                                    "ONOFF2:OilLopeTy",//17
                                    "ONOFF2:1 CallChk",//18
                                    "ONOFF2:ManSusChk",//19
                                    "ONOFF2:BrkMonChk",//20
                                    "ONOFF2:KidKeyClr",//21
                                    "ONOFF2:F_CarKey ",//22
                                    "ONOFF2:SingleCar",//23
                                    "ONOFF2:OpOutSet ",//24
                                    "ONOFF2:SftUse RL",//25
                                    "ONOFF2:Floor Sel",//26
                                    "ONOFF2:RunningOp",//27
                                    "ONOFF2:Not Use  ",//28
                                    "ONOFF2:Not Use  ",//29
                                    "ONOFF2:Not Use  ",//30
                                    "ONOFF2:Copy_Encd",//31
                                    "ONOFF2:Work Mode",//32
///////////////////////////////////////////////////////////                                                                                                           
                                    "DOOR-S:Floor01  ",//1 
                                    "DOOR-S:Floor02  ",//2 
                                    "DOOR-S:Floor03  ",//3 
                                    "DOOR-S:Floor04  ",//4  
                                    "DOOR-S:Floor05  ",//5  
                                    "DOOR-S:Floor06  ",//6  
                                    "DOOR-S:Floor07  ",//7  
                                    "DOOR-S:Floor08  ",//8  
                                    "DOOR-S:Floor09  ",//9  
                                    "DOOR-S:Floor10  ",//10 
                                    "DOOR-S:Floor11  ",//11 
                                    "DOOR-S:Floor12  ",//12
                                    "DOOR-S:Floor13  ",//13
                                    "DOOR-S:Floor14  ",//14
                                    "DOOR-S:Floor15  ",//15
                                    "DOOR-S:Floor16  ",//16
                                    "DOOR-S:Floor17  ",//17
                                    "DOOR-S:Floor18  ",//18
                                    "DOOR-S:Floor19  ",//19
                                    "DOOR-S:Floor20  ",//20
                                    "DOOR-S:Floor21  ",//21
                                    "DOOR-S:Floor22  ",//22
                                    "DOOR-S:Floor23  ",//23
                                    "DOOR-S:Floor24  ",//24
                                    "DOOR-S:Floor25  ",//25
                                    "DOOR-S:Floor26  ",//26
                                    "DOOR-S:Floor27  ",//27
                                    "DOOR-S:Floor28  ",//28
                                    "DOOR-S:Floor29  ",//29
                                    "DOOR-S:Floor30  ",//30
                                    "DOOR-S:Floor31  ",//31
                                    "DOOR-S:Floor32  ",//32
///////////////////////////////////////////////////////////                

///////////////////////////////////////////////////////////              
                                    "I_O:ManSpd  Port",//1  
                                    "I_O:BatSpd  Port",//2  
                                    "I_O:DecSpd  Port",//3  
                                    "I_O:FHMSpd  Port",//4  
                                    "I_O:Spd30   Port",//5  
                                    "I_O:Spd45   Port",//6  
                                    "I_O:Spd60   Port",//7  
                                    "I_O:Spd90   Port",//8 
                                    "I_O:Spd105  Port",//9 
                                    "I_O:Spd120  Port",//10 
                                    "I_O:Spd150  Port",//11 
                                    "I_O:Spd180  Port",//12 
                                    "I_O:Spd210  Port",//13 
                                    "I_O:Etc1Spd Port",//14  
                                    "I_O:Etc2Spd Port",//15  
                                    "I_O:Elev Max Spd",//16 
                                    "I_O:Limt Max Spd",//17
                                    "I_O:MaxSuSd1 Spd",//18 
                                    "I_O:MaxSuSd2 Spd",//19 
                                    "I_O:MaxX0X1  Spd",//20                                   
                                    "I_O:AutoLanding ",//21 
                                    "I_O:spd2        ",//22 
                                    "I_O:spd3        ",//23 
                                    "I_O:Spd4        ",//24 
                                    "I_O:Spd5        ",//25  
                                    "I_O:Spd6        ",//26 
                                    "I_O:Spd7        ",//27 
                                    "I_O:Spd8        ",//28 
                                    "I_O:Spd9        ",//29 
                                    "I_O:Spd10       ",//30 
                                    "I_O:Spd11       ",//31 
                                    "I_O:Spd12       ",//32 
///////////////////////////////////////////////////////////                                                                                                           
///////////////////////////////////////////////////////////             
                                    "PAR:EncoderPulse",//1  
                                    "PAR: TM Mpm     ",//2  
                                    "PAR:Motor Rpm   ",//3  
                                    "PAR:Dec30 Length",//4  
                                    "PAR:Dec45 Length",//5  
                                    "PAR:Dec60 Length",//6  
                                    "PAR:Dec90 Length",//7  
                                    "PAR:Dec105Length",//8  
                                    "PAR:Dec120Length",//9  
                                    "PAR:Dec150Length",//10 
                                    "PAR:Dec180Length",//11 
                                    "PAR:Dec210Length",//12 
                                    "PAR:Dec30 Pulse ",//13  
                                    "PAR:Dec45 Pulse ",//14 
                                    "PAR:Dec60 Pulse ",//15 
                                    "PAR:Dec90 Pulse ",//16 
                                    "PAR:Dec105 Pulse",//17 
                                    "PAR:Dec120 Pulse",//18 
                                    "PAR:Dec150 Pulse",//19 
                                    "PAR:Dec180 Pulse",//20 
                                    "PAR:Dec210 Pulse",//21 
                                    "PAR:Min30  Pulse",//22 
                                    "PAR:Min45  Pulse",//23 
                                    "PAR:Min60  Pulse",//24 
                                    "PAR:Min90  Pulse",//25 
                                    "PAR:Min105 Pulse",//26 
                                    "PAR:Min120 Pulse",//27 
                                    "PAR:Min150 Pulse",//28 
                                    "PAR:Min180 Pulse",//29 
                                    "PAR:Min210 Pulse",//30 
                                    "PAR:Mpm Variable",//31 
                                    "PAR:MmPerPulse  ",//32 
///////////////////////////////////////////////////////////
                                    "W_FLR:(1)hm_hm_F",//1  
                                    "W_FLR:(2)hm_hm_F",//2  
                                    "W_FLR:(3)hm_hm_F",//3  
                                    "W_FLR:(4)hm_hm_F",//4  
                                    "W_FLR:Time0910  ",//5  
                                    "W_FLR:Time1011  ",//6  
                                    "W_FLR:Time1112  ",//7  
                                    "W_FLR:Time1213  ",//8  
                                    "W_FLR:Time1314  ",//9  
                                    "W_FLR:Time1415  ",//10 
                                    "W_FLR:Time1516  ",//11 
                                    "W_FLR:Time1617  ",//12 
                                    "W_FLR:Time1718  ",//13 
                                    "W_FLR:Time1819  ",//14 
                                    "W_FLR:Time1920  ",//15 
                                    "W_FLR:Time2021  ",//16 
                                    "W_FLR:Time2105  ",//17 
                                    "W_FLR:Time0002  ",//18 
                                    "W_FLR:Time0003  ",//19 
                                    "W_FLR:Time0004  ",//20 
                                    "W_FLR:Time0005  ",//21 
                                    "W_FLR:Time0006  ",//22 
                                    "W_FLR:Time0007  ",//23 
                                    "W_FLR:Time0008  ",//24 
                                    "W_FLR:Time0009  ",//25 
                                    "W_FLR:Time0010  ",//26 
                                    "W_FLR:Time0011  ",//27 
                                    "W_FLR:Time0012  ",//28 
                                    "W_FLR:Time0013  ",//29 
                                    "W_FLR:Time0014  ",//30 
                                    "W_FLR:Prk S_Time",//31 
                                    "W_FLR:Prk E_Time",//32 
///////////////////////////////////////////////////////////                          
                                    "NcNo1:EMG       ",//1  
                                    "NcNo1:PRK       ",//2  
                                    "NcNo1:AT        ",//3  
                                    "NcNo1:UB        ",//4  
                                    "NcNo1:DB        ",//5  
                                    "NcNo1:OLS       ",//6  
                                    "NcNo1:GS        ",//7  
                                    "NcNo1:HDS       ",//8  
                                    "NcNo1:SUS       ",//9  
                                    "NcNo1:SDS       ",//10 
                                    "NcNo1:SFT       ",//11 
                                    "NcNo1:OVL       ",//12 
                                    "NcNo1:ULS       ",//13 
                                    "NcNo1:DLS       ",//14 
                                    "NcNo1:LU        ",//15 
                                    "NcNo1:LD        ",//16 
                                    "NcNo1:RG        ",//17 
                                    "NcNo1:BAT       ",//18 
                                    "NcNo1:PAS       ",//19 
                                    "NcNo1:FIR       ",//20 
                                    "NcNo1:WAT       ",//21 
                                    "NcNo1:FUL       ",//22 
                                    "NcNo1:MM        ",//23 
                                    "NcNo1:TH        ",//24
                                    "NcNo1:FR1       ",//25 
                                    "NcNo1:FR2       ",//26
                                    "NcNo1:BMR       ",//27 
                                    "NcNo1:BML       ",//28
                                    "NcNo1:SU1       ",//29 
                                    "NcNo1:SD1       ",//30
                                    "NcNo1:DZ        ",//31 
                                    "NcNo1:INV       ",//32 
///////////////////////////////////////////////////////////                                                                                                           
                                    "NcNo2:X0        ",//1  
                                    "NcNo2:X1        ",//2  
                                    "NcNo2:X2        ",//3  
                                    "NcNo2:X3        ",//4  
                                    "NcNo2:X4        ",//5  
                                    "NcNo2:X5        ",//6  
                                    "NcNo2:X6        ",//7  
                                    "NcNo2:HOLS/X7   ",//8  
                                    "NcNo2:W/FS0     ",//9  
                                    "NcNo2:S.S/FS1   ",//10 
                                    "NcNo2:FS2       ",//11 
                                    "NcNo2:FS3       ",//12 
                                    "NcNo2:FS4       ",//13 
                                    "NcNo2:DER       ",//14 
                                    "NcNo2:FID       ",//15 
                                    "NcNo2:UND       ",//16 
                                    "NcNo2:DOOR_HOLD ",//17 
                                    "NcNo2:VIRTUAL_X1",//18 
                                    "NcNo2:VIRTUAL_X2",//19 
                                    "NcNo2:VIRTUAL_X3",//20 
                                    "NcNo2:VIRTUAL_X4",//21 
                                    "NcNo2:VIRTUAL_X5",//22 
                                    "NcNo2:VIRTUAL_X6",//23 
                                    "NcNo2:VIRTUAL_X7",//24
                                    "NcNo2:nc        ",//25 
                                    "NcNo2:nc        ",//26
                                    "NcNo2:nc        ",//27 
                                    "NcNo2:nc        ",//28
                                    "NcNo2:nc        ",//29 
                                    "NcNo2:nc        ",//30
                                    "NcNo2:nc        ",//31 
                                    "NcNo2:nc        ",//32 
///////////////////////////////////////////////////////////                                                                                                           
/////////////////////////////////////////////////////////// 
                                    "NcNo3:FAN       ",//9
                                    "NcNo3:LIT       ",//10 
                                    "NcNo3:BUZ       ",//11
                                    "NcNo3:BEL       ",//12
                                    "NcNo3:REL       ",//13
                                    "NcNo3:ERR       ",//14
                                    "NcNo3:HOP       ",//15
                                    "NcNo3:HCl       ",//16
                                    "NcNo3:OP        ",//1  
                                    "NcNo3:CL        ",//2  
                                    "NcNo3:SOP       ",//3  
                                    "NcNo3:SCL       ",//4  
                                    "NcNo3:BK2       ",//5  
                                    "NcNo3:D_S       ",//6  
                                    "NcNo3:UCM       ",//7  
                                    "NcNo3:BK1       ",//8  
                                    "NcNo3:UP        ",//17 
                                    "NcNo3:DN        ",//18 
                                    "NcNo3:P1        ",//19 
                                    "NcNo3:P2        ",//20 
                                    "NcNo3:P3        ",//21 
                                    "NcNo3:P4        ",//22 
                                    "NcNo3:DAC       ",//23 
///////////////////////////////////////////newio insert
                                    "NcNo3:SLOW_DOOR ",//24 
                                    "NcNo3:VIRTUAL_Y1",//25 
                                    "NcNo3:VIRTUAL_Y2",//26 
                                    "NcNo3:VIRTUAL_Y3",//27 
                                    "NcNo3:VIRTUAL_Y4",//28 
                                    "NcNo3:VIRTUAL_Y5",//29 
                                    "NcNo3:VIRTUAL_Y6",//30 
                                    "NcNo3:VIRTUAL_Y7",//31 
///////////////////////////////////////////newio insert


/*
                                    "NcNo3:nc        ",//24
                                    "NcNo3:nc        ",//25 
                                    "NcNo3:nc        ",//26
                                    "NcNo3:nc        ",//27 
                                    "NcNo3:nc        ",//28
                                    "NcNo3:nc        ",//29 
                                    "NcNo3:nc        ",//30
                                    "NcNo3:nc        ",//31
*/ 
                                    "NcNo3:nc        ",//32
 
///////////////////////////////////////////////////////////                                                                                                           
                                    "INP1:EMG        ",//1  
                                    "INP1:PRK        ",//2  
                                    "INP1:AT         ",//3  
                                    "INP1:UP         ",//4  
                                    "INP1:DN         ",//5  
                                    "INP1:OLS        ",//6  
                                    "INP1:GS         ",//7  
                                    "INP1:HDS        ",//8  
                                    "INP1:SUS        ",//9  
                                    "INP1:SDS        ",//10 
                                    "INP1:SFT        ",//11 
                                    "INP1:OVL        ",//12 
                                    "INP1:ULS        ",//13 
                                    "INP1:DLS        ",//14 
                                    "INP1:LU         ",//15 
                                    "INP1:LD         ",//16 
                                    "INP1:RG         ",//17 
                                    "INP1:BAT        ",//18 
                                    "INP1:PAS        ",//19 
                                    "INP1:FIR        ",//20 
                                    "INP1:WAT        ",//21 
                                    "INP1:FUL        ",//22 
                                    "INP1:MM         ",//23 
                                    "INP1:TH         ",//24
                                    "INP1:FR1        ",//25 
                                    "INP1:FR2        ",//26
                                    "INP1:BMR        ",//27 
                                    "INP1:BML        ",//28
                                    "INP1:SU1        ",//29 
                                    "INP1:SD1        ",//30
                                    "INP1:DZ         ",//31 
                                    "INP1:INV        ",//32 
///////////////////////////////////////////////////////////                                                                                                           
                                    "INP2:X0         ",//1  
                                    "INP2:X1         ",//2  
                                    "INP2:X2         ",//3  
                                    "INP2:X3         ",//4  
                                    "INP2:X4         ",//5  
                                    "INP2:X5         ",//6  
                                    "INP2:X6         ",//7  
                                    "INP2:HOLS/X7    ",//8  
                                    "INP2:W/FS0      ",//9  
                                    "INP2:S.S/FS1    ",//10 
                                    "INP2:FS2        ",//11 
                                    "INP2:FS3        ",//12 
                                    "INP2:FS4        ",//13 
                                    "INP2:DER        ",//14 
                                    "INP2:FID        ",//15 
                                    "INP2:UND        ",//16 
                                    "NcNo2:DOOR_HOLD ",//17 
                                    "NcNo2:VIRTUAL_X2",//18 
                                    "NcNo2:VIRTUAL_X2",//19 
                                    "NcNo2:VIRTUAL_X3",//20 
                                    "NcNo2:VIRTUAL_X4",//21 
                                    "NcNo2:VIRTUAL_X5",//22 
                                    "NcNo2:VIRTUAL_X6",//23 
                                    "NcNo2:VIRTUAL_X7",//24
/*
                                    "INP2:nc         ",//17 
                                    "INP2:nc         ",//18 
                                    "INP2:nc         ",//19 
                                    "INP2:nc         ",//20 
                                    "INP2:nc         ",//21 
                                    "INP2:nc         ",//22 
                                    "INP2:nc         ",//23 
                                    "INP2:nc         ",//24
*/
                                    "INP2:nc         ",//25 
                                    "INP2:nc         ",//26
                                    "INP2:nc         ",//27 
                                    "INP2:nc         ",//28
                                    "INP2:nc         ",//29 
                                    "INP2:nc         ",//30
                                    "INP2:nc         ",//31 
                                    "INP2:nc         ",//32 
///////////////////////////////////////////////////////////                                                                                                           
///////////////////////////////////////////////////////////                                                                                                           
                                    "OUTP:FAN        ",//9
                                    "OUTP:LIT        ",//10 
                                    "OUTP:BUZ        ",//11
                                    "OUTP:BEL        ",//12
                                    "OUTP:REL        ",//13
                                    "OUTP:ERR        ",//14
                                    "OUTP:HOP        ",//15
                                    "OUTP:HCL        ",//16
                                    "OUTP:OP         ",//1  
                                    "OUTP:CL         ",//2  
                                    "OUTP:SOP        ",//3  
                                    "OUTP:SCL        ",//4  
                                    "OUTP:BK2        ",//5  
                                    "OUTP:D_S        ",//6  
                                    "OUTP:UCM        ",//7  
                                    "OUTP:BK1        ",//8  
                                    "OUTP:UP         ",//17 
                                    "OUTP:DN         ",//18 
                                    "OUTP:P1         ",//19 
                                    "OUTP:P2         ",//20 
                                    "OUTP:P3         ",//21 
                                    "OUTP:P4         ",//22 
                                    "OUTP:DAC        ",//23 
///////////////////////////////////////////newio insert
                                    "OUTP:SLOW_DOOR  ",//24
                                    "OUTP:VIRTUAL_Y1 ",//25
                                    "OUTP:VIRTUAL_Y2 ",//26
                                    "OUTP:VIRTUAL_Y3 ",//27
                                    "OUTP:VIRTUAL_Y4 ",//28
                                    "OUTP:VIRTUAL_Y5 ",//29
                                    "OUTP:VIRTUAL_Y6 ",//30
                                    "OUTP:VIRTUAL_Y7 ",//31
///////////////////////////////////////////newio insert
/*
                                    "OUTP:nc         ",//24
                                    "OUTP:nc         ",//25 
                                    "OUTP:nc         ",//26
                                    "OUTP:nc         ",//27 
                                    "OUTP:nc         ",//28
                                    "OUTP:nc         ",//29 
                                    "OUTP:nc         ",//30
                                    "OUTP:nc         ",//31
*/ 
                                    "OUTP:Not Use    ",//32 

///////////////////////////////////////////////////////////                                                                                                           
///////////////////////////////////////////////////////////                    
///////////////////////////////////////////////////////////                                                                                                   
                                    "ER:NO ERRORE(01)",//1  
                                    "ER:NO ERRORE(02)",//2  
                                    "ER:NO ERRORE(03)",//3  
                                    "ER:NO ERRORE(04)",//4  
                                    "ER:NO ERRORE(05)",//5  
                                    "ER:NO ERRORE(06)",//6  
                                    "ER:NO ERRORE(07)",//7  
                                    "ER:NO ERRORE(08)",//8  
                                    "ER:NO ERRORE(09)",//9 
                                    "ER:NO ERRORE(10)",//10 
                                    "ER:NO ERRORE(11)",//11 
                                    "ER:NO ERRORE(12)",//12 
                                    "ER:NO ERRORE(13)",//13 
                                    "ER:NO ERRORE(14)",//14 
                                    "ER:NO ERRORE(15)",//15 
                                    "ER:NO ERRORE(16)",//16 
                                    "ER:NO ERRORE(17)",//17 
                                    "ER:NO ERRORE(18)",//18 
                                    "ER:NO ERRORE(19)",//19 
                                    "ER:NO ERRORE(20)",//20 
                                    "ER:NO ERRORE(21)",//21 
                                    "ER:NO ERRORE(22)",//22 
                                    "ER:NO ERRORE(23)",//23 
                                    "ER:NO ERRORE(24)",//24 
                                    "ER:NO ERRORE(25)",//25 
                                    "ER:NO ERRORE(26)",//26 
                                    "ER:NO ERRORE(27)",//27 
                                    "ER:NO ERRORE(28)",//28 
                                    "ER:NO ERRORE(29)",//29 
                                    "ER:NO ERRORE(30)",//30 
                                    "ER:NO ERRORE(31)",//31 
                                    "ER:NO ERRORE(32)",//32 
////////////////////////////////////////////////////////////////////////////////
                                    "E/L:EncoderPulse",//1  
                                    "E/L: TM Mpm     ",//2  
                                    "E/L:Motor Rpm   ",//3 
                                    "E/L:ManSpd  Port",//4  
                                    "E/L:BatSpd  Port",//5  
                                    "E/L:DecSpd  Port",//6  
                                    "E/L:FHMSpd  Port",//7  
                                    "E/L:LowSpd  Port",//8  
                                    "E/L:MidSpd  Port",//9  
                                    "E/L:HighSpd Port",//10
                                    "E/L:L_Spd DecLen",//11  
                                    "E/L:M_Spd DecLen",//12  
                                    "E/L:H_Spd DecLen",//13  
                                    "E/L:Base_Length ",//14 
                                    "E/L:Base D_Time ",//15  
                                    "E/L:Base S_Time ",//16  
                                    "E/L:SuSd2 Spd   ",//17 
                                    "E/L:X0X1  Spd   ",//18 
                                    "E/L:LuLd-StopMpm",//19 
                                    "E/L:Not Use     ",//20 
                                    "E/L:AutoLanding ",//21 
                                    "E/L:Tuning Mode ",//22  
                                    "E/L:Fhm Mode    ",//23 
                                    "E/L:Not Use     ",//24 
                                    "E/L:Not Use     ",//25 
                                    "E/L:Not Use     ",//26 
                                    "E/L:L_Spd Pulse ",//27  
                                    "E/L:M_Spd Pulse ",//28 
                                    "E/L:H_Spd Pulse ",//29 
                                    "E/L:Base_Pulse  ",//30 
                                    "E/L:Mpm Variable",//31 
                                    "E/L:MmPerPulse  ",//32
                                };


#ifdef	FLOOR_64
const unsigned char DSP_CHAR[] 		={"DSP:Floor01     "};
const unsigned char FLR_ONOFF[]		={"ONOFF1:Floor01  "};
const unsigned char DOOR_MAIN_SUB[]	={"DOOR-S:Floor01  "};
#endif
						
			   
const unsigned char FhmSuccessMsg[16]     ="  FHM Success   "; 
const unsigned char AutoTun_SuccessMsg[16]="Tunning Success "; 

//digitData == 1 
const unsigned char ElevOnOffSetMessage[ELEV_ONOFF_MESSAGE_CNT][11]={   
                                    "FHM No Good",
                                    "Chk DoorJmp",
                                    "B Phase    ", 
                                    "Call But On",   
                                    "NonStop On ",   
                                    "Op TtTm On ",   
                                    "WaitTtTm On",                                      
                                    "Cl TtTm On ",   
                                    "CarDr1  Use",   
                                    "CarDr2  Use",   
                                    "HolDr1  Use",   
                                    "HolDr2  Use",   
                                    "S_Sfty  Use",   
                                    "Mgt Mon On ",   
                                    "Encoder Use",   
                                    "Relevel On ",   
                                    "Lope  Type ",   
                                    "OneCall  On",   
                                    "M/Sus  Stop",   
                                    "Brk Mon On ",   
                                    "KidsClr On ",   
                                    "F_CarKey On",   
                                    "Single Car ",   
                                    "Op Out On  ",   
                                    "Sft Comm On",   
                                    " BCD Floor ",
                                    "Run_Op  On ",   
                                    "Reserve5   ",   
                                    "Reserve4   ",   
                                    "Reserve3   ",   
                                    "EncCopy On",   
                                    "Manual Job ",   
                                };


//digitData == 0 
const unsigned char ElevOnOffResetMessage[ELEV_ONOFF_MESSAGE_CNT][11]={
                                    "FHM Good   ",
                                    "NoChk DrJmp",
                                    "A Phase    ", 
                                    "Cur Ward On",    
                                    "NonStop Off",   
                                    "Op TtTm Off",   
                                    "WaitTtTmOff",                                      
                                    "Cl TtTm Off",   
                                    "C_Dr1 N_Use",   
                                    "C_Dr2 N_Use",   
                                    "H_Dr1 N_Use",   
                                    "H_Dr2 N_Use",   
                                    "S_Sft N_Use",   
                                    "Mgt Mon Off",   
                                    "Encod N_Use",   
                                    "Relevel Off",   
                                    "Oil  P_Type",   
                                    "OneCall Off",   
                                    "M/SusNoStop",   
                                    "Brk Mon Off",   
                                    "KidsClr Off",   
                                    "F_CarKeyOff",   
                                    "Multi Car  ",   
                                    "Op Out Off ",   
                                    "Sft CommOff",   
                                    "DirectFloor",   
                                    "Run_Op Off ",   
                                    "Reserve5   ",   
                                    "Reserve4   ",   
                                    "Reserve3   ",   
                                    "EncCopy Off",   
                                    "Auto Ready ",   
                                };





const unsigned char IOPortMessage[IO_PORT_MESSAGE_CNT][11]={
                                    "-----------",//0
                                    "---------P1",//1
                                    "-------P2--",//2
                                    "-------P2P1",//3
                                    "-----P3----",//4
                                    "-----P3--P1",//5
                                    "-----P3P2--",//6
                                    "-----P3P2P1",//7
                                    "---P4------",//8
                                };

const unsigned char ElevSpeedMessage_spd3[ELEV_SPEED_MESSAGE_CNT_SPD3][11]={
                                    "Not Use    ",    
                                    "Dec/Spd_M_H",
                                    "Dec/Spd_H  ",
                                    "Low_Spd    ",
                                    "Mid_Spd    ", 
                                };

const unsigned char AUTO_LANDING_MSG[AUTO_LANDING_MESSAGE_CNT][11]={
                                    "Not Use    ",    
                                    "YK_ALanding",
//                                    "DS_ALanding",
                                };

const unsigned char ElevSpeedMessage[ELEV_SPEED_MESSAGE_CNT][11]={
                                    "SPEED30    ",
                                    "SPEED45    ",
                                    "SPEED60    ", 
                                    "SPEED90    ",   
                                    "SPEED105   ",    
                                    "SPEED120   ",       
                                    "SPEED150   ",       
                                    "SPEED180   ",       
                                    "SPEED210   ",
                                };




const unsigned char ElevBdIdMessage[ELEV_BD_ID_MESSAGE_CNT][11]={
                                    "LG  Elevato",  //0
                                    "I/O Elevato",  //1
                                    "D_F Elevato",  //2
                                    "LG  Baggage",  //3
                                    "I/O Baggage",  //4
                                    "D_F Baggage",  //5
                                    "LG  CarLift",  //6
                                    "I/O CarLift",  //7
                                    "D_F CarLift",  //8
                                    "Reserve1   ",
                                };


const unsigned char SystemSetMessage[SYSTEM_SET_MESSAGE_CNT][13]={		
                                    "0.O_Law/O_spd",  //0
                                    "1.N_Law/O_spd",  //1
                                    "2.O_Law/N_spd",  //2
                                    "3.N_Law/N_spd",  //3
                                };


const unsigned char SensorPositionMessage[SENSOR_POSITION_MESSAGE_CNT][16]={		
                                    "29.ULS:0000-0000",  //0
                                    "29.SUS:0000-0000",  //1
                                    "29.SU1:0000-0000",  //2
                                    "29.X0 :0000-0000",  //3
                                    "29.DLS:0000-0000",  //3
                                    "29.SDS:0000-0000",  //1
                                    "29.SD1:0000-0000",  //2
                                    "29.X1 :0000-0000",  //3
                                    "29.nu :0000-0000",  //1
                                    "29.nu :0000-0000",  //2
                                };




const unsigned char FinalErrMessage[FINAL_ERR_DSP_MESSAGE_CNT][16]={		
                                    "28.00/00-00.    ",  //0
                                    "28.No Error     ",  //1
                                    "28.00/00        ",  //2
                                    "28.Puls:00000000",  //3
                                    "28.mpm :000.0   ",  //4
                                    "28.D/T:0000/0000",  //5
                                    "28.Up  :00000000",  //6
                                    "28.Op  :00000000",  //7
                                    "28.FAN :00000000",  //8
                                    "28.Emg :00000000",  //9
                                    "28.SUS :00000000",  //10
                                    "28.RG  :00000000",  //11
                                    "28.FR1 :00000000",  //12
                                    "28.X0  :00000000",  //13
                                    "28.FS0 :00000000",  //14
                                };



const unsigned char UserLampMessage[USER_LAMP_MESSAGE_CNT][11]={
                                      "AUTO       ",                                      
                                      "INSPECTION ",                                      
                                      "OVERLOAD   ",                                      
                                      "FIRE       ",                                                                            
                                      "EMERGENCY  ",
                                      "PARKING    ",
                                      "VIP        ",
                                      "USE LAMP   ",
                                      "FULL LAMP  ",
                                      "POWER SAVE ",
                                      "NOT USE    "                                      
                                    };                                       


const unsigned char DriveMethodMessage[3][11]={
                                      "All Drive..",                                      
                                      "1,3,5,7... ",    //�汝�                                   
                                      "2,4,6,8... ",    //礎熱                                   
                                    };                                       

const unsigned char DoorOnOffMessage[DOOR_SEL_MESSAGE_CNT][11]={
                                      "Not Door   ",    //no door                                 
                                      "MainDoor   ",    //main door                                   
                                      "Sub Door   ",    //sub door                                   
                                      "MainSubDoor",    //main sub door                                   
                                    };                                       


const unsigned char FhmMessage[][11]={
                                      "Fhm Stop   ",                                      
                                      "Fhm Start  ",                                       
                                    };                                       


#ifdef	DELTA_INVERTER
const unsigned char AutoTunMessage[][16]={
                                      "Tuning Stop   ",                                      
                                      "Tuning Up On  ",                                       
                                      "Tuning Dn On  ",                                       
                                    };                                       


#else
const unsigned char AutoTunMessage[][16]={
                                      "Tuning Stop   ",                                      
                                      "StopTuning On ",                                       
                                      "RunTuning  On ",                                       
                                    };                                       

#endif




const unsigned char PcbTypeMessage[2][11]={
                                      "Ext Bd Type",   // extbd/inbd                                    
                                      "In_Bd Type ",                                      
                                    };                                       

/*
const unsigned char ReadDataFromHost[2][11]={
                                      "Read Data ?",   // extbd/inbd                                    
                                      "Dont Read  ",                                      
                                    };
                                       
const unsigned char WriteDataToHost[2][11]={
                                      "Write Data ?",   // extbd/inbd                                    
                                      "Dont Write  ",                                      
                                    };                                       

*/

const unsigned char InitMessage[INIT_MESSAGE][11]={
                                      "Not Sel Clr",                                      
                                      "MoveCnt Clr",                                      
                                      "ErrMsg  Clr",                                      
                                      "Read Data  ",                                      
                                      "Write Data ",                                                                            
                                      "Reserve3   ",
                                      "Reserve2   ",
                                      "Reserve1   ",
                                    };                                       

const unsigned char NormalDspMessage[NORMAL_DSP_MESSAGE_CNT][11]={
                                      "Cur Status ",                                      
                                      "Mpm        ",                                      
                                      "Rpm        ",                                      
                                      "Time       ",                                                                            
                                      "Date       ",                                                                            
                                      "Date_Time  ",
                                      "Encod Pulse",                                      
                                      "EMG  Input ",  
                                      "SUS  Input ",  
                                      "RG   Input ",  
                                      "FR1  Input ",  
                                      "X0   Input ",  
                                      "FS0  Input ",
                                      "Mem  Dsp   ",     
                                      "Move Counte",
                                      "Err Counter",
                                      "Can Com Chk",
                                      "485 Com Chk",
                                      "Dec  Pulse ",
                                      "Reserve13  ",
                                      "Reserve12  ",
                                      "Reserve11  ",
                                      "Reserve10  ",
                                      "Reserve9   ",
                                      "Reserve8   ",
                                      "Reserve7   ",
                                      "Reserve6   ",
                                      "Reserve5   ",
                                      "Reserve4   ",
                                      "Reserve3   ",
                                      "Reserve2   ",
                                      "Reserve1   ",
                                    };                                       


const unsigned char InputPort1SelMessage[][11]={
                                      "SILK_EMG   ",                                      
                                      "SILK_PRK   ",                                      
                                      "SILK_AT    ",                                      
                                      "SILK_UB    ",                                                                            
                                      "SILK_DB    ",                                                                            
                                      "SILK_OLS   ",
                                      "SILK_GS    ",                                      
                                      "SILK_HDS   ",  
                                      "SILK_SUS   ",  
                                      "SILK_SDS   ",  
                                      "SILK_SFT   ",  
                                      "SILK_OVL   ",  
                                      "SILK_ULS   ",   
                                      "SILK_DLS   ",
                                      "SILK_LU    ",
                                      "SILK_LD    ",
                                      "SILK_RG    ",
                                      "SILK_BAT   ",
                                      "SILK_PAS   ",
                                      "SILK_FIR   ",
                                      "SILK_WAT   ",
                                      "SILK_FUL   ",
                                      "SILK_MM    ",
                                      "SILK_TH    ",
                                      "SILK_FR1   ",
                                      "SILK_FR2   ",
                                      "SILK_BMR   ",
                                      "SILK_BML   ",
                                      "SILK_SU1   ",
                                      "SILK_SD1   ",
                                      "SILK_DZ    ",
                                      "SILK_INV   ",
                                      "SILK_X0    ",                                      
                                      "SILK_X1    ",                                      
                                      "SILK_X2    ",                                      
                                      "SILK_X3    ",                                                                            
                                      "SILK_X4    ",                                                                            
                                      "SILK_X5    ",
                                      "SILK_X6    ",                                      
                                      "SILK_HOS/X7",  
                                      "SILK_W/FS0 ",  
                                      "SILK_SS/FS1",  
                                      "SILK_FS2   ",  
                                      "SILK_FS3   ",  
                                      "SILK_FS4   ",   
                                      "SILK_DER   ",
                                      "SILK_FID   ",
                                      "SILK_UND   ",
									  "DOOR_HOLD  ",
									  "VIRTUAL_X1 ",
									  "VIRTUAL_X2 ",
									  "VIRTUAL_X3 ",
									  "VIRTUAL_X4 ",
									  "VIRTUAL_X5 ",
									  "VIRTUAL_X6 ",
									  "VIRTUAL_X7 ",
                                      "EXT_X0     ",
                                      "EXT_X1     ",
                                      "EXT_X2     ",
                                      "EXT_X3     ",
                                      "EXT_X4     ",
                                      "EXT_X5     ",
                                      "EXT_X6     ",
                                      "EXT_X7     ",
                                      "Not Use    ",

/*
                                      "Not Use    ",
                                      "SILK_NC    ",
                                      "SILK_NC    ",
                                      "SILK_NC    ",
                                      "SILK_NC    ",
                                      "SILK_NC    ",
                                      "SILK_NC    ",
                                      "SILK_NC    ",
                                      "SILK_NC    ",
                                      "SILK_NC    ",
                                      "SILK_NC    ",
                                      "SILK_NC    ",
                                      "SILK_NC    ",
                                      "SILK_NC    ",
                                      "SILK_NC    ",
                                      "SILK_NC    ",
*/
                                    };                                       


const unsigned char OutputPortSelMessage[OUTPORT_SEL_MESSAGE_CNT][11]={
                                      "SILK_FAN   ",                                      
                                      "SILK_LIT   ",                                      
                                      "SILK_BUZ   ",                                      
                                      "SILK_BEL   ",                                                                            
                                      "SILK_REL   ",                                                                            
                                      "SILK_ERR   ",
                                      "SILK_HOP   ",                                      
                                      "SILK_HCL   ",  
                                      "SILK_OP    ",  
                                      "SILK_CL    ",  
                                      "SILK_SOP   ",  
                                      "SILK_SCL   ",  
                                      "SILK_BK2   ",   
                                      "SILK_D_S   ",
                                      "SILK_UCM   ",
                                      "SILK_BK1   ",
                                      "SILK_UP    ",
                                      "SILK_DN    ",
                                      "SILK_P1    ",
                                      "SILK_P2    ",
                                      "SILK_P3    ",
                                      "SILK_P4    ",
                                      "SILK_DAC   ",	                                    
									  "SLOW_DOOR  ",
	                                  "VIRTUAL_Y1 ",
	                                  "VIRTUAL_Y2 ",
	                                  "VIRTUAL_Y3 ",
	                                  "VIRTUAL_Y4 ",
	                                  "VIRTUAL_Y5 ",
	                                  "VIRTUAL_Y6 ",
	                                  "VIRTUAL_Y7 ",
                                      "EXT_Y0     ",
                                      "EXT_Y1     ",
                                      "EXT_Y2     ",
                                      "EXT_Y3     ",
                                      "EXT_Y4     ",
                                      "EXT_Y5     ",
                                      "EXT_Y6     ",
                                      "EXT_Y7     ",
                                      "Not Use    ",
                                    };                                       



const unsigned char BdName[][8]={
                                    "M_Hib  :",                                      
                                    "S_Hib  :",                                      
                                    "Voice  :",                                      
                                    "Car    :",                                                                            
                                    "Not Sel:",                                                                            
                                 };


/*
   
const unsigned char SlipMessage[][11]={
									  "UCMP Clear ",                                      
                                 };

*/


const unsigned char InputName[6][3]={
                                      "EMG",                                      
                                      "SUS",    
                                      "RG ",   
                                      "FR1",                                      
                                      "X0 ",    
                                      "FS0",   
                                    };                                       



const unsigned char blinkx[]        ="                ";  




void  __attribute__((section(".usercode")))	PasswardCheck(void)
{
    pw[0]=cF_PASSWARD0;
    pw[1]=cF_PASSWARD1;
    pw[2]=cF_PASSWARD2;
    pw[3]=cF_PASSWARD3;

	if(bAllMenu)	bPasswardOk=1;	
    else if((pw[0]=='0') && (pw[1]=='0') && (pw[2]=='0') && (pw[3]=='0')){
    	bPasswardOk=1;
	}
    else{
    	if((pw[0]== PassWardKeyBuf[0]) && (pw[1]==PassWardKeyBuf[1]) && (pw[2]==PassWardKeyBuf[2]) && (pw[3]==PassWardKeyBuf[3])){
    		bPasswardOk=1;   		
		}
		else{
    		bPasswardOk=0;   		
		}	
	}

}



void    __attribute__((section(".usercode"))) VirtualMoveCntReDsp(void)
{
    LocalType  value;

	if((LadderGroup == USER_GROUP) && (LadderGroupSub == VIRTUAL_CALL)){
		value = sRamDArry[mVFlrCnt];
		New485Ladder[SECONDLINE_BASE+EditBlanck+0] =(value / 100) + '0';
		value = (value % 100);          
		New485Ladder[SECONDLINE_BASE+EditBlanck+1] =(value / 10)  + '0';		          
		New485Ladder[SECONDLINE_BASE+EditBlanck+2] =(value % 10)  + '0';          
	}
}


unsigned int  __attribute__((section(".usercode"))) Deciml_Dsp(unsigned int total_dig,unsigned int dp)
{
    unsigned int i,j;
    unsigned char tempbuf[10];
		
	if(dp == 0)			return(0);
	if(dp >= total_dig)	return(0);

	for(i=0;i<total_dig;i++){
		tempbuf[i]=New485Ladder[SECONDLINE_BASE+EditBlanck+i];                       
	}


	j=(total_dig-dp);
	New485Ladder[SECONDLINE_BASE+EditBlanck+j]='.';            
           
	for(i=j;i<total_dig;i++){
		New485Ladder[SECONDLINE_BASE+EditBlanck+i+1]=tempbuf[i];                       
	}
	return(0);
}


void    __attribute__((section(".usercode"))) Il_Dsp(unsigned int val,unsigned int dp)
{
    unsigned int il;
		
    il  =(val % 10);
	New485Ladder[SECONDLINE_BASE+EditBlanck+0] = il   + '0';                      
}


void    __attribute__((section(".usercode"))) Sip_Dsp(unsigned int val,unsigned int dp)
{
    unsigned int sip,il;
		
    sip =(val / 10);
    il  =(val % 10);

	New485Ladder[SECONDLINE_BASE+EditBlanck+0] = sip  + '0';                       
	New485Ladder[SECONDLINE_BASE+EditBlanck+1] = il   + '0';                      
	Deciml_Dsp(2,dp);
}


void    __attribute__((section(".usercode"))) Bek_Dsp(unsigned int val,unsigned int dp)
{
    unsigned int bek,sip,il;
		
    bek =(val / 100);
    val =(val % 100);
    sip =(val / 10);
    il  =(val % 10);

	New485Ladder[SECONDLINE_BASE+EditBlanck+0] = bek  + '0';                     
	New485Ladder[SECONDLINE_BASE+EditBlanck+1] = sip  + '0';                       
	New485Ladder[SECONDLINE_BASE+EditBlanck+2] = il   + '0';                      

	Deciml_Dsp(3,dp);
}


void    __attribute__((section(".usercode"))) Chun_Dsp(unsigned int val,unsigned int dp)
{

    unsigned int chun,bek,sip,il;
		
	chun=(val / 1000);
    val =(val % 1000);

    bek =(val / 100);
    val =(val % 100);

    sip =(val / 10);
    il  =(val % 10);

	New485Ladder[SECONDLINE_BASE+EditBlanck+0] = (unsigned)(chun + '0');                     
	New485Ladder[SECONDLINE_BASE+EditBlanck+1] = (unsigned)(bek  + '0');                     
	New485Ladder[SECONDLINE_BASE+EditBlanck+2] = (unsigned)(sip  + '0');                       
	New485Ladder[SECONDLINE_BASE+EditBlanck+3] = (unsigned)(il   + '0');                      

	Deciml_Dsp(4,dp);
}


void    __attribute__((section(".usercode"))) Man_Dsp(unsigned int val,unsigned int dp)
{

    unsigned int man,chun,bek,sip,il;

	man =(val / 10000);
    val =(val % 10000);		
	chun=(val / 1000);
    val =(val % 1000);
    bek =(val / 100);
    val =(val % 100);
    sip =(val / 10);
    il  =(val % 10);

	New485Ladder[SECONDLINE_BASE+EditBlanck+0] = man + '0';                     
	New485Ladder[SECONDLINE_BASE+EditBlanck+1] = chun + '0';                     
	New485Ladder[SECONDLINE_BASE+EditBlanck+2] = bek  + '0';                     
	New485Ladder[SECONDLINE_BASE+EditBlanck+3] = sip  + '0';                       
	New485Ladder[SECONDLINE_BASE+EditBlanck+4] = il   + '0';                      

	Deciml_Dsp(5,dp);
}


void    __attribute__((section(".usercode"))) Chunman_Dsp(unsigned long vx,unsigned int dp)
{
    unsigned long value;
	value=vx;
	
    New485Ladder[SECONDLINE_BASE+EditBlanck+0]=(value/10000000)  + '0';
    value=value%10000000;              
    New485Ladder[SECONDLINE_BASE+EditBlanck+1]=(value/1000000)   + '0';
    value=value%1000000;              
    New485Ladder[SECONDLINE_BASE+EditBlanck+2]=(value/100000)    + '0';
    value=value%100000;              
    New485Ladder[SECONDLINE_BASE+EditBlanck+3]=(value/10000)     + '0';
    value=value%10000;              
    New485Ladder[SECONDLINE_BASE+EditBlanck+4]=(value/1000)      + '0';
    value=value%1000;                        
    New485Ladder[SECONDLINE_BASE+EditBlanck+5]=(value/100)      + '0';
    value=value%100;                        
    New485Ladder[SECONDLINE_BASE+EditBlanck+6]=(value/10)       + '0';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+7]=(value%10)       + '0';          

	Deciml_Dsp(7,dp);
}





	
void    __attribute__((section(".usercode"))) RpmDsp485(void)
{
    unsigned int chun;
    unsigned long tmpcalu;

    tmpcalu=(PulsePer100Msec >> 2); // 4x
    tmpcalu=tmpcalu * 600 * 10;
    tmpcalu=(tmpcalu/(unsigned long)FlashDspCharBuf[ENCODER_PULSE].long_data);

    chun=(unsigned int)tmpcalu;

	Chun_Dsp(chun,1);

	New485Ladder[SECONDLINE_BASE+EditBlanck+5] = ' ';
	New485Ladder[SECONDLINE_BASE+EditBlanck+6] = 'R';
	New485Ladder[SECONDLINE_BASE+EditBlanck+7] = 'p';
	New485Ladder[SECONDLINE_BASE+EditBlanck+8] = 'm';

}



void    __attribute__((section(".usercode"))) MpmDsp485(unsigned int val)
{
    unsigned int chun;
	
	chun=val;
	Chun_Dsp(chun,1);

	New485Ladder[SECONDLINE_BASE+EditBlanck+5] = ' ';
	New485Ladder[SECONDLINE_BASE+EditBlanck+6] = 'm';
	New485Ladder[SECONDLINE_BASE+EditBlanck+7] = 'p';
	New485Ladder[SECONDLINE_BASE+EditBlanck+8] = 'm';
}





void    __attribute__((section(".usercode"))) CurEncoderPulse(unsigned long vx)
{

	Chunman_Dsp(vx,0);

    New485Ladder[SECONDLINE_BASE+EditBlanck+8] ='p';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+9] ='u';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+10]='l';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+11]='s';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+12]='e';          

}





void    __attribute__((section(".usercode"))) MoveCounterDsp(void)
{
    unsigned long value;


    value=MoveCounterx;

    New485Ladder[SECONDLINE_BASE+EditBlanck+0]=(value/1000000)  + '0';
    value=value%1000000;              
    New485Ladder[SECONDLINE_BASE+EditBlanck+1]=(value/100000)   + '0';
    value=value%100000;              
    New485Ladder[SECONDLINE_BASE+EditBlanck+2]=(value/10000)    + '0';
    value=value%10000;              
    New485Ladder[SECONDLINE_BASE+EditBlanck+3]=(value/1000)     + '0';
    value=value%1000;              
    New485Ladder[SECONDLINE_BASE+EditBlanck+4]=(value/100)      + '0';
    value=value%100;                        
    New485Ladder[SECONDLINE_BASE+EditBlanck+5]=(value/10)       + '0';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+6]=(value%10)       + '0';          


    New485Ladder[SECONDLINE_BASE+EditBlanck+7]  =' ';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+8]  ='m';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+9]  ='o';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+10] ='v';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+11] ='e';          
}



void    __attribute__((section(".usercode"))) ErrCounterDsp(void)
{
    LocalType  value;

    value=eDArry[eErrCntPt];

	Man_Dsp(value,0);

    New485Ladder[SECONDLINE_BASE+EditBlanck+5]  =' ';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+6]  ='E';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+7]  ='r';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+8]  ='r';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+9]  ='o';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+10] ='r';          
}



void    __attribute__((section(".usercode"))) Rs485ComDsp(void)
{
    New485Ladder[SECONDLINE_BASE+EditBlanck+0]='E';
    New485Ladder[SECONDLINE_BASE+EditBlanck+1]='/';
    New485Ladder[SECONDLINE_BASE+EditBlanck+2]='B';
    New485Ladder[SECONDLINE_BASE+EditBlanck+3]=' ';
    New485Ladder[SECONDLINE_BASE+EditBlanck+4]=BdName485[ErrBdNamePt][0];
    New485Ladder[SECONDLINE_BASE+EditBlanck+5]=BdName485[ErrBdNamePt][1];
    New485Ladder[SECONDLINE_BASE+EditBlanck+6]=BdName485[ErrBdNamePt][2];
}

void    __attribute__((section(".usercode"))) CanComDsp(void)
{
    LocalType  value;

    switch(sRamDArry[mCallMe]){
        case    0x01:
        case    0x02:
        case    0x03:
        case    0x04:
        case    0x05:
        case    0x06:
        case    0x07:
        case    0x08:
        case    0x09:
        case    0x0a:
        case    0x0b:
        case    0x0c:
        case    0x0d:
        case    0x0e:
        case    0x0f:
        case    0x10:
        case    0x11:
        case    0x12:
        case    0x13:
        case    0x14:
        case    0x15:
        case    0x16:
        case    0x17:
        case    0x18:
        case    0x19:
        case    0x1a:
        case    0x1b:
        case    0x1c:
        case    0x1d:
        case    0x1e:
        case    0x1f:
        case    0x20:
            New485Ladder[SECONDLINE_BASE+EditBlanck+0]=BdName[0][0];
            New485Ladder[SECONDLINE_BASE+EditBlanck+1]=BdName[0][1];
            New485Ladder[SECONDLINE_BASE+EditBlanck+2]=BdName[0][2];
            New485Ladder[SECONDLINE_BASE+EditBlanck+3]=BdName[0][3];
            New485Ladder[SECONDLINE_BASE+EditBlanck+4]=BdName[0][4];
            New485Ladder[SECONDLINE_BASE+EditBlanck+5]=BdName[0][5];
            New485Ladder[SECONDLINE_BASE+EditBlanck+6]=BdName[0][6];
            New485Ladder[SECONDLINE_BASE+EditBlanck+7]=BdName[0][7];

            New485Ladder[SECONDLINE_BASE+EditBlanck+5]= (sRamDArry[mCallMe]/10) + '0';
            New485Ladder[SECONDLINE_BASE+EditBlanck+6]= (sRamDArry[mCallMe]%10) + '0';
            break;
        case    0x41:
        case    0x42:
        case    0x43:
        case    0x44:
        case    0x45:
        case    0x46:
        case    0x47:
        case    0x48:
        case    0x49:
        case    0x4a:
        case    0x4b:
        case    0x4c:
        case    0x4d:
        case    0x4e:
        case    0x4f:
        case    0x50:
        case    0x51:
        case    0x52:
        case    0x53:
        case    0x54:
        case    0x55:
        case    0x56:
        case    0x57:
        case    0x58:
        case    0x59:
        case    0x5a:
        case    0x5b:
        case    0x5c:
        case    0x5d:
        case    0x5e:
        case    0x5f:
        case    0x60:
            New485Ladder[SECONDLINE_BASE+EditBlanck+0]=BdName[1][0];
            New485Ladder[SECONDLINE_BASE+EditBlanck+1]=BdName[1][1];
            New485Ladder[SECONDLINE_BASE+EditBlanck+2]=BdName[1][2];
            New485Ladder[SECONDLINE_BASE+EditBlanck+3]=BdName[1][3];
            New485Ladder[SECONDLINE_BASE+EditBlanck+4]=BdName[1][4];
            New485Ladder[SECONDLINE_BASE+EditBlanck+5]=BdName[1][5];
            New485Ladder[SECONDLINE_BASE+EditBlanck+6]=BdName[1][6];
            New485Ladder[SECONDLINE_BASE+EditBlanck+7]=BdName[1][7];

            New485Ladder[SECONDLINE_BASE+EditBlanck+5]= ((sRamDArry[mCallMe]-0x40)/10) + '0';
            New485Ladder[SECONDLINE_BASE+EditBlanck+6]= ((sRamDArry[mCallMe]-0x40)%10) + '0';
            break;
        case    0x80:
        case    0x81:
        case    0x82:
        case    0x83:
            New485Ladder[SECONDLINE_BASE+EditBlanck+0]=BdName[3][0];
            New485Ladder[SECONDLINE_BASE+EditBlanck+1]=BdName[3][1];
            New485Ladder[SECONDLINE_BASE+EditBlanck+2]=BdName[3][2];
            New485Ladder[SECONDLINE_BASE+EditBlanck+3]=BdName[3][3];
            New485Ladder[SECONDLINE_BASE+EditBlanck+4]=BdName[3][4];
            New485Ladder[SECONDLINE_BASE+EditBlanck+5]=BdName[3][5];
            New485Ladder[SECONDLINE_BASE+EditBlanck+6]=BdName[3][6];
            New485Ladder[SECONDLINE_BASE+EditBlanck+7]=BdName[3][7];

            New485Ladder[SECONDLINE_BASE+EditBlanck+3]= (sRamDArry[mCallMe] & 0x03) + '1';
            break;
        default:
            New485Ladder[SECONDLINE_BASE+EditBlanck+0]=BdName[4][0];
            New485Ladder[SECONDLINE_BASE+EditBlanck+1]=BdName[4][1];
            New485Ladder[SECONDLINE_BASE+EditBlanck+2]=BdName[4][2];
            New485Ladder[SECONDLINE_BASE+EditBlanck+3]=BdName[4][3];
            New485Ladder[SECONDLINE_BASE+EditBlanck+4]=BdName[4][4];
            New485Ladder[SECONDLINE_BASE+EditBlanck+5]=BdName[4][5];
            New485Ladder[SECONDLINE_BASE+EditBlanck+6]=BdName[4][6];
            New485Ladder[SECONDLINE_BASE+EditBlanck+7]=BdName[4][7];
            sRamDArry[mCallMe]=0x00;
            break;
    }   


    
    value=Percent;

    New485Ladder[SECONDLINE_BASE+EditBlanck+8]=(value/100)      + '0';
    value=value%100;                        
    New485Ladder[SECONDLINE_BASE+EditBlanck+9]=(value/10)       + '0';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+10]=(value%10)      + '0';          

    New485Ladder[SECONDLINE_BASE+EditBlanck+11]  ='%'; 


    if(LadderBuf[C_SAVE_DATA+0] == 'u'){
        TxPercent=0;
        Percent=0;
        ThisReceiveSlave=0;

        sRamDArry[mCallMe]++;
        if(sRamDArry[mCallMe] > 0x83){
            sRamDArry[mCallMe]=0x0;
        }
        else if((sRamDArry[mCallMe] >= 0x41) && (sRamDArry[mCallMe] <= 0x60)){
            if((sRamDArry[mCallMe]- 0x40) > (cF_TOPFLR+1) ){            
                sRamDArry[mCallMe]=0x80;
            }
        }
        else if((sRamDArry[mCallMe] > 0x0) && (sRamDArry[mCallMe] <= 0x20)){
            if(sRamDArry[mCallMe] > (cF_TOPFLR+1) ){            
                sRamDArry[mCallMe]=0x41;
            }
        }
    }
    if(LadderBuf[C_SAVE_DATA+0] == 'd'){
        TxPercent=0;
        Percent=0;
        ThisReceiveSlave=0;

        sRamDArry[mCallMe]--;

        if(sRamDArry[mCallMe] == 0xffff){
            sRamDArry[mCallMe]=0x83;
        }
        else if(sRamDArry[mCallMe] > 0x83){
            sRamDArry[mCallMe]=0x1;
        }
        else if(sRamDArry[mCallMe] == 0x7f){
            sRamDArry[mCallMe]=(cF_TOPFLR+1) + 0x40;
        }
        else if(sRamDArry[mCallMe] == 0x40){
            sRamDArry[mCallMe]=(cF_TOPFLR+1);
        }
        else if(sRamDArry[mCallMe] == 0x20){
            sRamDArry[mCallMe]=(cF_TOPFLR+1);
        }
    }         
}




void    __attribute__((section(".usercode"))) SetBitData(LocalType  pt)
{
    if(pt & 0x01)  New485Ladder[SECONDLINE_BASE+EditBlanck+0] = '1';
    else           New485Ladder[SECONDLINE_BASE+EditBlanck+0] = '0';
    if(pt & 0x02)  New485Ladder[SECONDLINE_BASE+EditBlanck+1] = '2';
    else           New485Ladder[SECONDLINE_BASE+EditBlanck+1] = '0';
    if(pt & 0x04)  New485Ladder[SECONDLINE_BASE+EditBlanck+2] = '3';
    else           New485Ladder[SECONDLINE_BASE+EditBlanck+2] = '0';
    if(pt & 0x08)  New485Ladder[SECONDLINE_BASE+EditBlanck+3] = '4';
    else           New485Ladder[SECONDLINE_BASE+EditBlanck+3] = '0';
    if(pt & 0x10)  New485Ladder[SECONDLINE_BASE+EditBlanck+4] = '5';
    else           New485Ladder[SECONDLINE_BASE+EditBlanck+4] = '0';
    if(pt & 0x20)  New485Ladder[SECONDLINE_BASE+EditBlanck+5]= '6';
    else           New485Ladder[SECONDLINE_BASE+EditBlanck+5]= '0';
    if(pt & 0x40)  New485Ladder[SECONDLINE_BASE+EditBlanck+6]= '7';
    else           New485Ladder[SECONDLINE_BASE+EditBlanck+6]= '0';
    if(pt & 0x80)  New485Ladder[SECONDLINE_BASE+EditBlanck+7]= '8';
    else           New485Ladder[SECONDLINE_BASE+EditBlanck+7]= '0';
}


void    __attribute__((section(".usercode"))) Input(LocalType  pt)
{
    LocalType  i,tmpedit;

    pt=pt-7;

	for(i=0;i<3;i++)	New485Ladder[SECONDLINE_BASE+EditBlanck+i]=InputName[pt][i]; 


    New485Ladder[SECONDLINE_BASE+EditBlanck+3]= ' ';
    New485Ladder[SECONDLINE_BASE+EditBlanck+4]= ' ';

	tmpedit=EditBlanck;
	EditBlanck=(EditBlanck+5);
	switch(pt){
		case	0:
			i=(LocalType)sRamDArry[I_EMG];
			i= ~i;
			SetBitData(i);
			break;
		case	1:
			i=(LocalType)sRamDArry[I_SU1];
			i= ~i;
			SetBitData(i);
			break;
		case	2:
			i=(LocalType)sRamDArry[I_GR];
			i= ~i;
			SetBitData(i);
			break;
		case	3:
			i=(LocalType)sRamDArry[I_FIRE];
			i= ~i;
			SetBitData(i);
			break;
		case	4:
			i=(LocalType)sRamDArry[I_X_0];
			i= ~i;
			SetBitData(i);
			break;
		case	5:
			i=(LocalType)sRamDArry[I_FS0];
			i= ~i;
			SetBitData(i);
			break;
	}
													
	EditBlanck=tmpedit;
}



/*
void    __attribute__((section(".usercode"))) VirtualCall(void)
{
    LocalType  value;

    New485Ladder[SECONDLINE_BASE+EditBlanck+0]= 'M';
    New485Ladder[SECONDLINE_BASE+EditBlanck+1]= ' ';
    New485Ladder[SECONDLINE_BASE+EditBlanck+2]= ' ';
    New485Ladder[SECONDLINE_BASE+EditBlanck+3]= ' ';
    New485Ladder[SECONDLINE_BASE+EditBlanck+4]= ' ';

    value=MemPointer;

    New485Ladder[SECONDLINE_BASE+EditBlanck+1]=(value/100)      + '0';
    value=value%100;                        
    New485Ladder[SECONDLINE_BASE+EditBlanck+2]=(value/10)       + '0';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+3]=(value%10)       + '0';          


    if(sRamDArry[MemPointer] & 0x01)  New485Ladder[SECONDLINE_BASE+EditBlanck+5] = '1';
    else                              New485Ladder[SECONDLINE_BASE+EditBlanck+5] = '0';
    if(sRamDArry[MemPointer] & 0x02)  New485Ladder[SECONDLINE_BASE+EditBlanck+6] = '1';
    else                              New485Ladder[SECONDLINE_BASE+EditBlanck+6] = '0';
    if(sRamDArry[MemPointer] & 0x04)  New485Ladder[SECONDLINE_BASE+EditBlanck+7] = '1';
    else                              New485Ladder[SECONDLINE_BASE+EditBlanck+7] = '0';
    if(sRamDArry[MemPointer] & 0x08)  New485Ladder[SECONDLINE_BASE+EditBlanck+8] = '1';
    else                              New485Ladder[SECONDLINE_BASE+EditBlanck+8] = '0';
    if(sRamDArry[MemPointer] & 0x10)  New485Ladder[SECONDLINE_BASE+EditBlanck+9] = '1';
    else                              New485Ladder[SECONDLINE_BASE+EditBlanck+9] = '0';
    if(sRamDArry[MemPointer] & 0x20)  New485Ladder[SECONDLINE_BASE+EditBlanck+10]= '1';
    else                              New485Ladder[SECONDLINE_BASE+EditBlanck+10]= '0';
    if(sRamDArry[MemPointer] & 0x40)  New485Ladder[SECONDLINE_BASE+EditBlanck+11]= '1';
    else                              New485Ladder[SECONDLINE_BASE+EditBlanck+11]= '0';
    if(sRamDArry[MemPointer] & 0x80)  New485Ladder[SECONDLINE_BASE+EditBlanck+12]= '1';
    else                              New485Ladder[SECONDLINE_BASE+EditBlanck+12]= '0';
}
*/

void    __attribute__((section(".usercode"))) MemDsp(void)
{
    LocalType  value,tmpedit;

    New485Ladder[SECONDLINE_BASE+EditBlanck+0]= 'M';
    New485Ladder[SECONDLINE_BASE+EditBlanck+1]= ' ';
    New485Ladder[SECONDLINE_BASE+EditBlanck+2]= ' ';
    New485Ladder[SECONDLINE_BASE+EditBlanck+3]= ' ';
    New485Ladder[SECONDLINE_BASE+EditBlanck+4]= ' ';

    value=MemPointer;

    New485Ladder[SECONDLINE_BASE+EditBlanck+1]=(value/100)      + '0';
    value=value%100;                        
    New485Ladder[SECONDLINE_BASE+EditBlanck+2]=(value/10)       + '0';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+3]=(value%10)       + '0';          

	tmpedit=EditBlanck;
	EditBlanck=(EditBlanck+5);

	SetBitData((LocalType)sRamDArry[MemPointer]);

	EditBlanck=tmpedit;

}



void    __attribute__((section(".usercode"))) SpeedDsp(void)
{
    unsigned int count,tmpspddsp;
    unsigned int chun,bek,sip,il;

    chun=bek=sip=il=0;

	bExportData=0;
	bImportData=0;

	New485Ladder[2+0]='F';
	New485Ladder[2+1]='L';
	New485Ladder[2+2]=':';


	if(sRamDArry[DSP1] == 0)	sRamDArry[DSP1] = '?';	
	if(sRamDArry[DSP2] == 0)	sRamDArry[DSP2] = '?';	
	New485Ladder[2+3]=sRamDArry[DSP1];
	New485Ladder[2+4]=sRamDArry[DSP2];

	New485Ladder[2+5]=' ';

	if(CurMeterPerMin > 1)	tmpspddsp=1;
	else					tmpspddsp=0;

	if( (bCarUpMove || bCarDnMove) || (tmpspddsp > 0) ){ 
	
	    chun=(unsigned int)CurMeterPerMin;
	
	    if(chun)    il=(chun%10);
	    
	    if(chun)    sip=(chun/10);
	    if(sip)     sip=(sip%10);
	
	    if(chun)    bek=(chun/100);
	    if(bek)     bek=(bek%10);;
	
	    if(chun)    chun=chun/1000;
	    if(chun)    chun=(chun%10);
        

   		if(New_Spd_SystemChk()){
			if(PerfectAuto()){
	            New485Ladder[2+6] =chun + '0';
	            New485Ladder[2+7] =bek  + '0';
	            New485Ladder[2+8]=sip   + '0';
	            New485Ladder[2+9]='.';
	            New485Ladder[2+10]=il   + '0';
	            New485Ladder[2+11]='m';
	            New485Ladder[2+12]='p';
	            New485Ladder[2+13]='m';
	            New485Ladder[2+14]=' ';
	            New485Ladder[2+15]=' ';

	            New485Ladder[2+14]='-';
	            New485Ladder[2+15]=' ';
	
				if(bUnd){
	            	New485Ladder[2+15]='D';
				}
				else if(CurSpeed==SPEED_LOW){
	            	New485Ladder[2+15]='L';
				}
				else if(CurSpeed==SPEED_MID){
	            	New485Ladder[2+15]='M';
				}
				else if(CurSpeed==SPEED_HIGH){
	            	New485Ladder[2+15]='H';
				}
				else{
	            	New485Ladder[2+15]='Z';
				}
			}
			else{
	            New485Ladder[2+6]=' ';
	            New485Ladder[2+7]=' ';
	            New485Ladder[2+8] =chun + '0';
	            New485Ladder[2+9] =bek  + '0';
	            New485Ladder[2+10]=sip  + '0';
	            New485Ladder[2+11]='.';
	            New485Ladder[2+12]=il   + '0';
	            New485Ladder[2+13]='m';
	            New485Ladder[2+14]='p';
	            New485Ladder[2+15]='m';
			}
		}
		else{
	           New485Ladder[2+6]=' ';
	           New485Ladder[2+7]=' ';
	           New485Ladder[2+8] =chun + '0';
	           New485Ladder[2+9] =bek  + '0';
	           New485Ladder[2+10]=sip  + '0';
	           New485Ladder[2+11]='.';
	           New485Ladder[2+12]=il   + '0';
	           New485Ladder[2+13]='m';
	           New485Ladder[2+14]='p';
	           New485Ladder[2+15]='m';
		}	 
	}    
	else{
	    New485Ladder[2+6]=' ';
	    New485Ladder[2+7]=' ';
	    New485Ladder[2+8]='E';
	    New485Ladder[2+9]='/';
	    New485Ladder[2+10]='L';
	    New485Ladder[2+11]='.';
	    New485Ladder[2+12]='S';
	    New485Ladder[2+13]='t';
	    New485Ladder[2+14]='o';
	    New485Ladder[2+15]='p';
	}
}



unsigned int __attribute__((section(".usercode"))) TunningMessage(void)
{
	unsigned int i,j;

	#ifdef	DELTA_INVERTER
	if(sRamDArry[AUTO_TUNING] == AUTOTUN_SEQ_12){          
           for(i=0;i<16;i++)	New485Ladder[SECONDLINE_BASE+i] =AutoTun_SuccessMsg[i];
	}
	else{
        j=sRamDArry[mSysStatus];
        for(i=0;i<16;i++)	New485Ladder[SECONDLINE_BASE+i] =StatusMessage[j][i];
		New485Ladder[SECONDLINE_BASE+14]=(unsigned char)((sRamDArry[AUTO_TUNING]/10) + '0');
		New485Ladder[SECONDLINE_BASE+15]=(unsigned char)((sRamDArry[AUTO_TUNING]%10) + '0');
	}
	#else
    j=sRamDArry[mSysStatus];
    for(i=0;i<16;i++)	New485Ladder[SECONDLINE_BASE+i] =StatusMessage[j][i];
	#endif
	           
	return(0);
}



unsigned int __attribute__((section(".usercode"))) FHM_SuccessDisplay(void)
{
	unsigned int i;
	for(i=0;i<16;i++){
		New485Ladder[SECONDLINE_BASE+i] = FhmSuccessMsg[i];          
	}
	return(0);
}

unsigned int __attribute__((section(".usercode"))) BlinkDisplay(void)
{	

 	if( (sRamDArry[mSysStatus]==sFhmError) && bFhmRun)								return(1);  // blink
	else if(bAutoTunning)															return(0);  // no blink
 	else if(bFhmRun)																return(0);  // no blink
	else if(sRamDArry[mSysStatus] <= sCLE_NO_ON)									return(0);  // no blink


	if(!IN_AUTO){
		if(sRamDArry[mSysStatus]==sREADY){
			if(sRamDArry[mEV_LastErr] != 0xff)	return(1);	// blink
			else								return(0);  // no blink
		}	
		else{
			if((sRamDArry[mSysStatus]==sFireOn) || (sRamDArry[mSysStatus]==sWaterSense) || (sRamDArry[mSysStatus]==sVIP)){
				if(S1_OVERLOAD1)		return(2);  // blink
				else if(bSafety_scrSft)	return(3);  // blink
				else					return(0);  // no blink
			}
		}
	}
	else{
		return(0);  // no blink
	}
}



unsigned int __attribute__((section(".usercode"))) Default_Cur_State_Display(void)
{
	unsigned int i,j;

/*
	if(bAutoTunning){
		if(sRamDArry[AUTO_TUNING] == AUTOTUN_SEQ_12){          
            for(i=0;i<16;i++)	New485Ladder[SECONDLINE_BASE+i] =AutoTun_SuccessMsg[i];
		}
		else{
            j=sRamDArry[mSysStatus];
            for(i=0;i<16;i++)	New485Ladder[SECONDLINE_BASE+i] =StatusMessage[j][i];
			New485Ladder[SECONDLINE_BASE+14]=(unsigned char)((sRamDArry[AUTO_TUNING]/10) + '0');
			New485Ladder[SECONDLINE_BASE+15]=(unsigned char)((sRamDArry[AUTO_TUNING]%10) + '0');
		}	           
	}
	else{
*/
		i=BlinkDisplay();
		if( i>0){
			if(i==1){
				if(!bDspSeq)	j=sRamDArry[mEV_LastErr];
				else			j=sRamDArry[mSysStatus];
			}
			else if(i==2){
				if(!bDspSeq)	j=sOVL;
				else			j=sRamDArry[mSysStatus];				
			}
			else if(i==3){
				if(!bDspSeq)	j=sSFT;
				else			j=sRamDArry[mSysStatus];				
			}
			else				j=sRamDArry[mSysStatus];

	        for(i=0;i<16;i++)	New485Ladder[SECONDLINE_BASE+i] =StatusMessage[j][i];          		
		}
		else{
			if(bAutoTunning){
				TunningMessage();
			}
			else if( bFhmRun && (sRamDArry[FHM_SEQ] == FHM_SEQ_5)){
				FHM_SuccessDisplay();
			}
			else{
	            j=sRamDArry[mSysStatus];
	            for(i=0;i<16;i++)	New485Ladder[SECONDLINE_BASE+i] =StatusMessage[j][i];          
			}
		}
//	}
	return(0);
}


unsigned int __attribute__((section(".usercode"))) DefaultDisplay(void)
{
    LocalType  i,j,k;


    k=cF_NormalDsp;

    if(bCarErr || bCarStopNoRun || bFhmRun)    k=0;

	if(LadderGroup != 0)	k=0;    

	EditBlanck=0;


	if(BefDspMode != k){
		BefDspMode = k;
        for(i=0;i<16;i++){
            New485Ladder[SECONDLINE_BASE+i] =' ';          
        }
	}
	

    switch(k){
        case    0:
			Default_Cur_State_Display();
            break;
        case    1:
            MpmDsp485((unsigned int)CurMeterPerMin);
            break;
        case    2:
            RpmDsp485();
            break;
        case    3:
            New485Ladder[SECONDLINE_BASE+0] =(sRamDArry[Hour]    >> 4)      + '0';          
            New485Ladder[SECONDLINE_BASE+1] =(sRamDArry[Hour]    &  0x0f)   + '0';          
            New485Ladder[SECONDLINE_BASE+2] ='/';          
            New485Ladder[SECONDLINE_BASE+3] =(sRamDArry[Minuate] >> 4)      + '0';          
            New485Ladder[SECONDLINE_BASE+4] =(sRamDArry[Minuate] & 0x0f)    + '0';          
            New485Ladder[SECONDLINE_BASE+5] ='/';          
            New485Ladder[SECONDLINE_BASE+6] =(sRamDArry[sec]     >> 4)      + '0';          
            New485Ladder[SECONDLINE_BASE+7] =(sRamDArry[sec]     & 0x0f)    + '0';          
            break;
        case    4:
            New485Ladder[SECONDLINE_BASE+0] =(sRamDArry[Year]    >> 4)      + '0';          
            New485Ladder[SECONDLINE_BASE+1] =(sRamDArry[Year]    & 0x0f)    + '0';          
            New485Ladder[SECONDLINE_BASE+2] ='/';          
            New485Ladder[SECONDLINE_BASE+3] =(sRamDArry[Month]   >> 4)      + '0';          
            New485Ladder[SECONDLINE_BASE+4] =(sRamDArry[Month]   & 0x0f)    + '0';          
            New485Ladder[SECONDLINE_BASE+5] ='/';          
            New485Ladder[SECONDLINE_BASE+6] =(sRamDArry[Day]     >> 4)      + '0';          
            New485Ladder[SECONDLINE_BASE+7] =(sRamDArry[Day]     & 0x0f)    + '0';          
            break;
        case    5:
            New485Ladder[SECONDLINE_BASE+0] =(sRamDArry[Year]    >> 4)      + '0';          
            New485Ladder[SECONDLINE_BASE+1] =(sRamDArry[Year]    & 0x0f)    + '0';          
            New485Ladder[SECONDLINE_BASE+2] =(sRamDArry[Month]   >> 4)      + '0';          
            New485Ladder[SECONDLINE_BASE+3] =(sRamDArry[Month]   & 0x0f)    + '0';          
            New485Ladder[SECONDLINE_BASE+4] =(sRamDArry[Day]     >> 4)      + '0';          
            New485Ladder[SECONDLINE_BASE+5] =(sRamDArry[Day]     & 0x0f)    + '0';          
            New485Ladder[SECONDLINE_BASE+6] ='/';          
            New485Ladder[SECONDLINE_BASE+7] =(sRamDArry[Hour]    >> 4)      + '0';          
            New485Ladder[SECONDLINE_BASE+8] =(sRamDArry[Hour]    &  0x0f)   + '0';          
            New485Ladder[SECONDLINE_BASE+9] =(sRamDArry[Minuate] >> 4)      + '0';          
            New485Ladder[SECONDLINE_BASE+10]=(sRamDArry[Minuate] & 0x0f)    + '0';          
            New485Ladder[SECONDLINE_BASE+11]=(sRamDArry[sec]     >> 4)      + '0';          
            New485Ladder[SECONDLINE_BASE+12]=(sRamDArry[sec]     & 0x0f)    + '0';          
            break;
        case    6:
            CurEncoderPulse(CurPulse);
            break;
        case    7:
        case    8:
        case    9:
        case    10:
        case    11:
        case    12:
            Input(cF_NormalDsp);
            break;
        case    13:
            switch(LadderKey){
                case    UPKEY:
                    MemPointer=(MemPointer+1)%1000;
                    break;
                case    DOWNKEY:
                    if(MemPointer>0)    MemPointer--;
                    else                MemPointer=999;
                    break;
            }            
            LadderKey='0';
            MemDsp();
            break;
        case    14:
            MoveCounterDsp();
            break;
        case    15:
            ErrCounterDsp();
			break;
        case    16:
            CanComDsp();
            break;
        case    17:
            Rs485ComDsp();
            break;
        case    18:
   			CurEncoderPulse(LType_Test_Value);
			if(iType_Test_PlusMinus)	New485Ladder[SECONDLINE_BASE]= '+';
			else						New485Ladder[SECONDLINE_BASE]= '-';
        	break;
        default:
			Default_Cur_State_Display();
            break;
    }

	if(k != 16)	sRamDArry[mCallMe]=0x0;

	return(0);		
}


void  __attribute__((section(".usercode"))) CalendarChk(void)
{
    if(LadderGroupSub==30){
        switch(Cursor){
            case    0:
                if(New485Ladder[SECONDLINE_BASE+EditBlanck+Cursor] > '2'){
                    New485Ladder[SECONDLINE_BASE+EditBlanck+Cursor]='0';          
                }
                else if(New485Ladder[SECONDLINE_BASE+EditBlanck+Cursor] == '2'){
                    if(New485Ladder[SECONDLINE_BASE+EditBlanck+Cursor+1] > '4'){
                        New485Ladder[SECONDLINE_BASE+EditBlanck+Cursor+1]='0';          
                    }
                }
                break;
            case    1:
                if(New485Ladder[SECONDLINE_BASE+EditBlanck+Cursor-1] == '2'){
                    if(New485Ladder[SECONDLINE_BASE+EditBlanck+Cursor] > '4'){
                        New485Ladder[SECONDLINE_BASE+EditBlanck+Cursor]='0';          
                    }
                }
                break;
            case    3:
            case    6:
                if(New485Ladder[SECONDLINE_BASE+EditBlanck+Cursor] > '5')    New485Ladder[SECONDLINE_BASE+EditBlanck+Cursor]='0';          
                break;
        }
    }
    else if(LadderGroupSub==31){
        switch(Cursor){
            case    3:
                if(New485Ladder[SECONDLINE_BASE+EditBlanck+Cursor] > '1')    New485Ladder[SECONDLINE_BASE+EditBlanck+Cursor]='0';          
                else if(New485Ladder[SECONDLINE_BASE+EditBlanck+Cursor] == '1'){
                    if(New485Ladder[SECONDLINE_BASE+EditBlanck+Cursor+1] > '2'){
                        New485Ladder[SECONDLINE_BASE+EditBlanck+Cursor+1]='0';          
                    }
                }
                break;
            case    4:
                if(New485Ladder[SECONDLINE_BASE+EditBlanck+Cursor-1] == '1'){
                    if(New485Ladder[SECONDLINE_BASE+EditBlanck+Cursor] > '2'){
                        New485Ladder[SECONDLINE_BASE+EditBlanck+Cursor]='0';          
                    }
                }
                break;
            case    6:
                if(New485Ladder[SECONDLINE_BASE+EditBlanck+Cursor] > '3')    New485Ladder[SECONDLINE_BASE+EditBlanck+Cursor]='0';          
                else if(New485Ladder[SECONDLINE_BASE+EditBlanck+Cursor] == '3'){
                    if(New485Ladder[SECONDLINE_BASE+EditBlanck+Cursor+1] > '1'){
                        New485Ladder[SECONDLINE_BASE+EditBlanck+Cursor+1]='0';          
                    }
                }
                break;
            case    7:
                if(New485Ladder[SECONDLINE_BASE+EditBlanck+Cursor-1] == '3'){
                    if(New485Ladder[SECONDLINE_BASE+EditBlanck+Cursor] > '1'){
                        New485Ladder[SECONDLINE_BASE+EditBlanck+Cursor]='0';          
                    }
                }
                break;
        }
    }
}




unsigned int __attribute__((section(".usercode"))) SensorPositionDisplay(unsigned int pt)
{
    LocalType  i,val;

	New485Ladder[FIRSTLINE_BASE+13]=(unsigned char)((pt/10) + '0');
	New485Ladder[FIRSTLINE_BASE+14]=(unsigned char)((pt%10) + '0');

	EditBlanck=7;

	i=(pt * 2);
	val=SensorPositionBuf[i];
	if(val > 9999)	val = 9999;	
	Chun_Dsp(val,0);

	i++;
	EditBlanck=(EditBlanck + 5);
	val=SensorPositionBuf[i];
	if(val > 9999)	val = 9999;	
	Chun_Dsp(val,0);

	EditBlanck=0;

	return(0);		
}



unsigned int __attribute__((section(".usercode"))) FinalErrDisplay(unsigned int pt)
{

    LocalType  i,val;
	
	New485Ladder[FIRSTLINE_BASE+13]=(unsigned char)((pt/10) + '0');
	New485Ladder[FIRSTLINE_BASE+14]=(unsigned char)((pt%10) + '0');

	EditBlanck=8;

    switch(pt){
        case    0:
			EditBlanck=3;

			i= cF_FLRDSPCH((unsigned long)(F_E_StartFloor));
			i=(i * 2);

            New485Ladder[SECONDLINE_BASE+EditBlanck+0] = cF_FLRDSPCH((unsigned long)i);          
            New485Ladder[SECONDLINE_BASE+EditBlanck+1] = cF_FLRDSPCH((unsigned long)(i+1));          


			i= cF_FLRDSPCH((unsigned long)(F_E_DestFloor));
			i=(i * 2);

            New485Ladder[SECONDLINE_BASE+EditBlanck+3] = cF_FLRDSPCH((unsigned long)i);          
            New485Ladder[SECONDLINE_BASE+EditBlanck+4] = cF_FLRDSPCH((unsigned long)(i+1));          


			i= cF_FLRDSPCH((unsigned long)(F_E_CurFloor));
			i=(i * 2);

            New485Ladder[SECONDLINE_BASE+EditBlanck+6] = cF_FLRDSPCH((unsigned long)i);          
            New485Ladder[SECONDLINE_BASE+EditBlanck+7] = cF_FLRDSPCH((unsigned long)(i+1));          


			i= cF_FLRDSPCH((unsigned long)(F_E_ErrNum));
            New485Ladder[SECONDLINE_BASE+EditBlanck+10] = 'E';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+11] = (unsigned char)((i/10) + '0');          
            New485Ladder[SECONDLINE_BASE+EditBlanck+12] = (unsigned char)((i%10) + '0');          

            break;
        case    1:
			EditBlanck=3;
			val= cF_FLRDSPCH((unsigned long)(F_E_ErrNum));
            for(i=0;i<13;i++){
                New485Ladder[SECONDLINE_BASE+EditBlanck+i] =StatusMessage[val][i];          
            }
            break;
        case    2:
			EditBlanck=3;

			i= cF_FLRDSPCH((unsigned long)(F_E_LuLdFloor));
			i=(i * 2);

            New485Ladder[SECONDLINE_BASE+EditBlanck+0] = cF_FLRDSPCH((unsigned long)i);          
            New485Ladder[SECONDLINE_BASE+EditBlanck+1] = cF_FLRDSPCH((unsigned long)(i+1));          


			i= cF_FLRDSPCH((unsigned long)(F_E_InvFloor));
			i=(i * 2);

            New485Ladder[SECONDLINE_BASE+EditBlanck+3] = cF_FLRDSPCH((unsigned long)i);          
            New485Ladder[SECONDLINE_BASE+EditBlanck+4] = cF_FLRDSPCH((unsigned long)(i+1));          
            break;
        case    3:
			Chunman_Dsp( GET_LONG_BYTE((unsigned long)(F_E_CurPulse0)),0 );
            break;
        case    4:
			val=iF_FLRDSPCH((unsigned long)(F_E_Mpm0));
			Chun_Dsp(val,1);
            break;
        case    5:			
			EditBlanck=7;

			i= cF_FLRDSPCH((unsigned long)(F_E_CurMonth));
			i=(i & 0x00ff);
            New485Ladder[SECONDLINE_BASE+EditBlanck+0] = (unsigned char)((i >> 4)      + '0');          
            New485Ladder[SECONDLINE_BASE+EditBlanck+1] = (unsigned char)((i &  0x0f)   + '0');          


			i= cF_FLRDSPCH((unsigned long)(F_E_CurDay));
			i=(i & 0x00ff);
            New485Ladder[SECONDLINE_BASE+EditBlanck+2] = (unsigned char)((i >> 4)      + '0');         
            New485Ladder[SECONDLINE_BASE+EditBlanck+3] = (unsigned char)((i &  0x0f)   + '0');          

            New485Ladder[SECONDLINE_BASE+EditBlanck+4] = '/';

          
			i= cF_FLRDSPCH((unsigned long)(F_E_CurHour));
			i=(i & 0x00ff);
            New485Ladder[SECONDLINE_BASE+EditBlanck+5] = (unsigned char)((i >> 4)      + '0');          
            New485Ladder[SECONDLINE_BASE+EditBlanck+6] = (unsigned char)((i &  0x0f)   + '0');          

			i= cF_FLRDSPCH((unsigned long)(F_E_CurMin));
			i=(i & 0x00ff);
            New485Ladder[SECONDLINE_BASE+EditBlanck+7] = (unsigned char)((i >> 4)      + '0');          
            New485Ladder[SECONDLINE_BASE+EditBlanck+8] = (unsigned char)((i &  0x0f)   + '0');          

            break;

        case    6:
			SetBitData((LocalType)(cF_FLRDSPCH((unsigned long)(F_E_OUT_UP))) );
			break;
        case    7:			// 
			SetBitData((LocalType)(cF_FLRDSPCH((unsigned long)(F_E_OUT_OP))) );
			break;
        case    8:
			SetBitData((LocalType)(cF_FLRDSPCH((unsigned long)(F_E_OUT_FAN))) );
			break;	
        case    9:
			i=(LocalType)(cF_FLRDSPCH((unsigned long)(F_E_IN_EMG)));
			i= ~i;
			SetBitData((LocalType)(i));
			break;	
        case    10:
			i=(LocalType)(cF_FLRDSPCH((unsigned long)(F_E_IN_SUS)));
			i= ~i;
			SetBitData((LocalType)(i));
			break;	
        case    11:
			i=(LocalType)(cF_FLRDSPCH((unsigned long)(F_E_IN_RG)));
			i= ~i;
			SetBitData((LocalType)(i));
			break;	
        case    12:
			i=(LocalType)(cF_FLRDSPCH((unsigned long)(F_E_IN_FR1)));
			i= ~i;
			SetBitData((LocalType)(i));
			break;	
        case    13:
			i=(LocalType)(cF_FLRDSPCH((unsigned long)(F_E_IN_X0)));
			i= ~i;
			SetBitData((LocalType)(i));
			break;	
        case    14:
			i=(LocalType)(cF_FLRDSPCH((unsigned long)(F_E_IN_FS0)));
			i= ~i;
			SetBitData((LocalType)(i));
            break;

	}

	EditBlanck=0;

	return(0);		
}



void  __attribute__((section(".usercode"))) GetFlashDataToBufRam(unsigned int BytePt)
{
    LocalType  i,j;

    j=((BytePt/64) * 16);

    for(i=0;i<16;i++){
        parameter_mirror[i]=FlashDspCharBuf[j+i].long_data;
    }
}


/////////

#ifdef	FLOOR_64

void  __attribute__((section(".usercode"))) DspCharSave(unsigned int pt,unsigned int DtNm)
{
    LocalType  i,j,k,x;

    k=(pt % 64);

    j=((pt/64) * 16);


    for(i=0;i<16;i++){
        parameter_mirror[i]=FlashDspCharBuf[j+i].long_data;
    }

    for(i=0;i<DtNm;i++){
        b_LdTmpBufRam((unsigned long)(k+i))     = New485Ladder[SECONDLINE_BASE+EditBlanck+i];
    }

	flash_write_DspChar(pt);    	

    

    k = New485Ladder[SECONDLINE_BASE+EditBlanck+1];
    
    if(pt==F_FlrDspCh){ 
        if(b_LdTmpBufRam(0) == 'B'){             
            if(k == '7')        i=0;  
            else if(k == '6')   i=2;  
            else if(k == '5')   i=4;  
            else if(k == '4')   i=6;  
            else if(k == '3')   i=8;  
            else if(k == '2')   i=10;  
            else if(k == '1')   i=12;
            else                pt=1;  
        }
        else if(b_LdTmpBufRam(0) == '0'){ 
            if(k == '1')        i=14;
            else                pt=1;  
        }
        else                    pt=1;
        
        if(pt==F_FlrDspCh){

    		j=((F_FlrDspCh/64) * 16);

		    for(x=0;x<16;x++){
		        parameter_mirror[x]=FlashDspCharBuf[j+x].long_data;
		    }

            for(k=0;k<64;k++,i++){
                b_LdTmpBufRam(k)  = DftFlrName[i];
            }
        
			flash_write_DspChar(F_FlrDspCh);



    		j=((F_FlrDspCh1/64) * 16);

		    for(x=0;x<16;x++){
		        parameter_mirror[x]=FlashDspCharBuf[j+x].long_data;
		    }

            for(k=0;k<64;k++,i++){
                b_LdTmpBufRam(k)  = DftFlrName[i];
            }
        
			flash_write_DspChar(F_FlrDspCh1);
		}    	
    }
}

#else
void  __attribute__((section(".usercode"))) DspCharSave(unsigned int pt,unsigned int DtNm)
{
    LocalType  i,j,k;

    k=(pt % 64);

    j=((pt/64) * 16);

    for(i=0;i<16;i++){
        parameter_mirror[i]=FlashDspCharBuf[j+i].long_data;
    }

    for(i=0;i<DtNm;i++){
        b_LdTmpBufRam((unsigned long)(pt+i))     = New485Ladder[SECONDLINE_BASE+EditBlanck+i];
    }
    
    k = New485Ladder[SECONDLINE_BASE+EditBlanck+1];

    
    if(pt==0){ 
        if(b_LdTmpBufRam(0) == 'B'){             
            if(k == '7')        i=0;  
            else if(k == '6')   i=2;  
            else if(k == '5')   i=4;  
            else if(k == '4')   i=6;  
            else if(k == '3')   i=8;  
            else if(k == '2')   i=10;  
            else if(k == '1')   i=12;
            else                pt=1;  
        }
        else if(b_LdTmpBufRam(0) == '0'){ 
            if(k == '1')        i=14;
            else                pt=1;  
        }
        else                    pt=1;
        
        if(pt==0){
            for(k=0;k<64;k++,i++){
                b_LdTmpBufRam(k)  = DftFlrName[i];
            }
        }
    }

    flash_write_DspChar(pt);
}
#endif

void  __attribute__((section(".usercode"))) GroupSelect(void)
{

	if(New_Spd_SystemChk()){
		switch(LadderGroupSelect){
	        case    GROUP_01:    
				LadderGroup=USER_GROUP;
	            break;
	        case    GROUP_02:    
				LadderGroup=FLR_DSP_GROUP;
	            break;
	        case    GROUP_03:
				LadderGroup=FLR_GROUP;
	            break;
	        case    GROUP_04:
				LadderGroup=TIMER_GROUP;
	            break;
	        case    GROUP_05:
				LadderGroup=ONOFF1_GROUP;
	            break;
	        case    GROUP_06: 
				LadderGroup=ONOFF2_GROUP;
	            break;
	        case    GROUP_07:
				LadderGroup=SUB_DOOR_GROUP;
	            break;
	        case    GROUP_08:
				LadderGroup=EL_GROUP;
	            break;
	        case    GROUP_09:
				LadderGroup=OPEN_WAIT_GROUP;
	            break;
	        case    GROUP_10:
				LadderGroup=NCNO1_GROUP;
	            break;
	        case    GROUP_11:
				LadderGroup=NCNO2_GROUP;
	            break;
	        case    GROUP_12:
				LadderGroup=NCNO3_GROUP;
	            break;
	        case    GROUP_13:
				LadderGroup=INPORT1_GROUP;
	            break;
	        case    GROUP_14:
				LadderGroup=INPORT2_GROUP;
	            break;
	        case    GROUP_15:
				LadderGroup=OUTPORT_GROUP;
	            break;            
	        case    GROUP_16:
				LadderGroup=ERROR_GROUP;
	            break;

#ifdef	DELTA_INVERTER
	        case    GROUP_17:
				LadderGroup=DELTA_PAR_GROUP_00;
				break;
	        case    GROUP_18:
				LadderGroup=DELTA_PAR_GROUP_01;
				break;
	        case    GROUP_19:
				LadderGroup=DELTA_PAR_GROUP_02;
				break;
	        case    GROUP_20:
				LadderGroup=DELTA_PAR_GROUP_03;
				break;
	        case    GROUP_21:
				LadderGroup=DELTA_PAR_GROUP_04;
				break;
	        case    GROUP_22:
				LadderGroup=DELTA_PAR_GROUP_05;
				break;
	        case    GROUP_23:
				LadderGroup=DELTA_PAR_GROUP_06;
				break;
	        case    GROUP_24:
				LadderGroup=DELTA_PAR_GROUP_07;
				break;
	        case    GROUP_25:
				LadderGroup=DELTA_PAR_GROUP_08;
				break;
	        case    GROUP_26:
				LadderGroup=DELTA_PAR_GROUP_09;
				break;
	        case    GROUP_27:
				LadderGroup=DELTA_PAR_GROUP_10;
				break;
	        case    GROUP_28:
				LadderGroup=DELTA_PAR_GROUP_11;
				break;
	        case    GROUP_29:
				LadderGroup=DELTA_PAR_GROUP_12;
				break;
	        case    GROUP_30:
				LadderGroup=DELTA_PAR_GROUP_13;
				break;
	        case    GROUP_31:
				LadderGroup=DELTA_PAR_GROUP_14;
				break;
#endif

			default:
				LadderGroup=0;
				break;
		}
	}
	else{
	    switch(LadderGroupSelect){
	        case    GROUP_01:    //save
				LadderGroup=USER_GROUP;
	            break;
	        case    GROUP_02:    
				LadderGroup=FLR_DSP_GROUP;
	            break;
	        case    GROUP_03:
				LadderGroup=FLR_GROUP;
	            break;
	        case    GROUP_04:
				LadderGroup=TIMER_GROUP;
	            break;
	        case    GROUP_05:
				LadderGroup=ONOFF1_GROUP;
	            break;
	        case    GROUP_06: 
				LadderGroup=ONOFF2_GROUP;
	            break;
	        case    GROUP_07:
				LadderGroup=SUB_DOOR_GROUP;
	            break;
	        case    GROUP_08: 
				LadderGroup=IO_GROUP;
	            break;
	        case    GROUP_09:
				LadderGroup=PARAMETER_GROUP;
	            break;
	        case    GROUP_10:
				LadderGroup=OPEN_WAIT_GROUP;
	            break;
	        case    GROUP_11:
				LadderGroup=NCNO1_GROUP;
	            break;
	        case    GROUP_12:
				LadderGroup=NCNO2_GROUP;
	            break;
	        case    GROUP_13:
				LadderGroup=NCNO3_GROUP;
	            break;
	        case    GROUP_14:
				LadderGroup=INPORT1_GROUP;
	            break;
	        case    GROUP_15:
				LadderGroup=INPORT2_GROUP;
	            break;
	        case    GROUP_16:
				LadderGroup=OUTPORT_GROUP;
	            break;            
	        case    GROUP_17:
				LadderGroup=ERROR_GROUP;
	            break;
#ifdef	DELTA_INVERTER
	        case    GROUP_18:
				LadderGroup=DELTA_PAR_GROUP_00;
				break;
	        case    GROUP_19:
				LadderGroup=DELTA_PAR_GROUP_01;
				break;
	        case    GROUP_20:
				LadderGroup=DELTA_PAR_GROUP_02;
				break;
	        case    GROUP_21:
				LadderGroup=DELTA_PAR_GROUP_03;
				break;
	        case    GROUP_22:
				LadderGroup=DELTA_PAR_GROUP_04;
				break;
	        case    GROUP_23:
				LadderGroup=DELTA_PAR_GROUP_05;
				break;
	        case    GROUP_24:
				LadderGroup=DELTA_PAR_GROUP_06;
				break;
	        case    GROUP_25:
				LadderGroup=DELTA_PAR_GROUP_07;
				break;
	        case    GROUP_26:
				LadderGroup=DELTA_PAR_GROUP_08;
				break;
	        case    GROUP_27:
				LadderGroup=DELTA_PAR_GROUP_09;
				break;
	        case    GROUP_28:
				LadderGroup=DELTA_PAR_GROUP_10;
				break;
	        case    GROUP_29:
				LadderGroup=DELTA_PAR_GROUP_11;
				break;
	        case    GROUP_30:
				LadderGroup=DELTA_PAR_GROUP_12;
				break;
	        case    GROUP_31:
				LadderGroup=DELTA_PAR_GROUP_13;
				break;
	        case    GROUP_32:
				LadderGroup=DELTA_PAR_GROUP_14;
				break;
#endif

			default:
				LadderGroup=0;
				break;
		}
	}
}


void  __attribute__((section(".usercode"))) NewMenuStart(void)
{
	PasswardCheck();

    EnterKey=0;
    Cursor=0;
    ShiftCnt=0;
    EditStatus=0;
    EditBlanck=0;

	GroupSelect();
    
    switch(LadderGroup){
        case    FLR_DSP_GROUP:    
            MaxSubMenu=FLR_DSP_GROUP_MAX;
            break;
        case    FLR_GROUP:
            MaxSubMenu=FLR_GROUP_MAX;
            break;
        case    TIMER_GROUP:
            MaxSubMenu=TIMER_GROUP_MAX;
            break;
        case    SUB_DOOR_GROUP:
            MaxSubMenu=ONOFF1_GROUP_MAX;
            break;
        case    ONOFF1_GROUP:
            MaxSubMenu=ONOFF1_GROUP_MAX;
            break;
        case    ONOFF2_GROUP: 
            MaxSubMenu=ONOFF2_GROUP_MAX;
            break;
        case    NCNO1_GROUP:
            MaxSubMenu=NCNO1_GROUP_MAX;
            break;
        case    NCNO2_GROUP:
            MaxSubMenu=NCNO2_GROUP_MAX;
            break;
        case    NCNO3_GROUP:
            MaxSubMenu=NCNO3_GROUP_MAX;
            break;
        case    IO_GROUP: 
            MaxSubMenu=IO_GROUP_MAX;
            break;
        case    USER_GROUP:    //save
            MaxSubMenu=USER_GROUP_MAX;
            break;
        case    OPEN_WAIT_GROUP:
            MaxSubMenu=OPEN_WAIT_GROUP_MAX;
            break;
        case    PARAMETER_GROUP:
            MaxSubMenu=PARAMETER_GROUP_MAX;
            break;
        case    INPORT1_GROUP:
            MaxSubMenu=INPORT1_GROUP_MAX;
            break;
        case    INPORT2_GROUP:
            MaxSubMenu=INPORT2_GROUP_MAX;
            break;
        case    OUTPORT_GROUP:
            MaxSubMenu=OUTPORT_GROUP_MAX;
            break;            
        case    ERROR_GROUP:
            MaxSubMenu=ERROR_GROUP_MAX;
            break;
        case    EL_GROUP:
            MaxSubMenu=EL_GROUP_MAX;
            break;

#ifdef	DELTA_INVERTER
		case    DELTA_PAR_GROUP_00:
            MaxSubMenu=EL_GROUP_MAX;
			break;
		case    DELTA_PAR_GROUP_01:
            MaxSubMenu=EL_GROUP_MAX;
			break;
        case    DELTA_PAR_GROUP_02:
            MaxSubMenu=EL_GROUP_MAX;
			break;
        case    DELTA_PAR_GROUP_03:
            MaxSubMenu=EL_GROUP_MAX;
			break;
        case    DELTA_PAR_GROUP_04:
            MaxSubMenu=EL_GROUP_MAX;
            MaxSubMenu=100;
			break;
        case    DELTA_PAR_GROUP_05:
            MaxSubMenu=EL_GROUP_MAX;
			break;
        case    DELTA_PAR_GROUP_06:
            MaxSubMenu=EL_GROUP_MAX;
			break;
        case    DELTA_PAR_GROUP_07:
            MaxSubMenu=EL_GROUP_MAX;
			break;
        case    DELTA_PAR_GROUP_08:
            MaxSubMenu=EL_GROUP_MAX;
			break;
        case    DELTA_PAR_GROUP_09:
            MaxSubMenu=EL_GROUP_MAX;
			break;
        case    DELTA_PAR_GROUP_10:
            MaxSubMenu=EL_GROUP_MAX;
			break;
        case    DELTA_PAR_GROUP_11:
            MaxSubMenu=EL_GROUP_MAX;
			break;
        case    DELTA_PAR_GROUP_12:
            MaxSubMenu=EL_GROUP_MAX;
			break;
        case    DELTA_PAR_GROUP_13:
            MaxSubMenu=EL_GROUP_MAX;
			break;
        case    DELTA_PAR_GROUP_14:
            MaxSubMenu=EL_GROUP_MAX;
			break;
#endif


    }
}




void  __attribute__((section(".usercode"))) DigitStringMessage(void)
{
    LocalType i,value;

    switch(LadderGroup){
/*
        case    FLR_GROUP:
            if((LadderGroupSub == 2) || (LadderGroupSub == 4) || (LadderGroupSub == 5) || (LadderGroupSub == 6)){
                if(DigitData > 32){
                    New485Ladder[SECONDLINE_BASE+EditBlanck+0]='N';          
                    New485Ladder[SECONDLINE_BASE+EditBlanck+1]='o';          
                    New485Ladder[SECONDLINE_BASE+EditBlanck+2]='t';          
                    New485Ladder[SECONDLINE_BASE+EditBlanck+3]=' ';          
                    New485Ladder[SECONDLINE_BASE+EditBlanck+4]='U';          
                    New485Ladder[SECONDLINE_BASE+EditBlanck+5]='s';          
                    New485Ladder[SECONDLINE_BASE+EditBlanck+6]='e';          
                }
                else{
                    New485Ladder[SECONDLINE_BASE+EditBlanck+2]=' ';          
                    New485Ladder[SECONDLINE_BASE+EditBlanck+3]=' ';          
                    New485Ladder[SECONDLINE_BASE+EditBlanck+4]=' ';          
                    New485Ladder[SECONDLINE_BASE+EditBlanck+5]=' ';          
                    New485Ladder[SECONDLINE_BASE+EditBlanck+6]=' ';          
                }
            }
            else{
                New485Ladder[SECONDLINE_BASE+EditBlanck+2]=' ';          
                New485Ladder[SECONDLINE_BASE+EditBlanck+3]=' ';          
                New485Ladder[SECONDLINE_BASE+EditBlanck+4]=' ';          
                New485Ladder[SECONDLINE_BASE+EditBlanck+5]=' ';          
                New485Ladder[SECONDLINE_BASE+EditBlanck+6]=' ';          
            }
            break;
*/
        case    TIMER_GROUP:
//            if((LadderGroupSub == 2) || (LadderGroupSub == 6)){
            if(LadderGroupSub == 6){
                New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+0]='M';          
                New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+1]='i';          
                New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+2]='n';          
            }
            else if((LadderGroupSub >= 13) && (LadderGroupSub <= 24)){
                New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+0]='H';          
                New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+1]='s';          
                New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+2]='e';          
                New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+3]='c';          
            }

/*
            else if((LadderGroupSub >= 13) && (LadderGroupSub <= 17)){
                New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+0]='H';          
                New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+1]='s';          
                New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+2]='e';          
                New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+3]='c';          
            }
            else if((LadderGroupSub > 12) && (LadderGroupSub <= 21)){
                New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+0]='m';          
                New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+1]='s';          
                New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+2]='e';          
                New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+3]='c';          
            }
*/

//            else if((LadderGroupSub == 7) || (LadderGroupSub == 9) || (LadderGroupSub == 10) || (LadderGroupSub == 12)){
            else if((LadderGroupSub == 9) || (LadderGroupSub == 10)){
                New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+0]='H';          
                New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+1]='s';          
                New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+2]='e';          
                New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+3]='c';          
            }
            else{
                New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+0]='S';          
                New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+1]='e';          
                New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+2]='c';   
            }
            break;
        case    SUB_DOOR_GROUP:
			for(i=0;i<11;i++){
            	New485Ladder[SECONDLINE_BASE+EditBlanck+i]=DoorOnOffMessage[DigitData][i];
			}					
            break;
        case    ONOFF1_GROUP:
            if(DigitData){
                New485Ladder[SECONDLINE_BASE+EditBlanck+0]='S';
                New485Ladder[SECONDLINE_BASE+EditBlanck+1]='e';
                New485Ladder[SECONDLINE_BASE+EditBlanck+2]='r';
                New485Ladder[SECONDLINE_BASE+EditBlanck+3]='v';
                New485Ladder[SECONDLINE_BASE+EditBlanck+4]='i';
                New485Ladder[SECONDLINE_BASE+EditBlanck+5]='c';
                New485Ladder[SECONDLINE_BASE+EditBlanck+6]='e';
                New485Ladder[SECONDLINE_BASE+EditBlanck+7]=' ';
                New485Ladder[SECONDLINE_BASE+EditBlanck+8]=' ';
                New485Ladder[SECONDLINE_BASE+EditBlanck+9]=' ';
            }
            else{
                New485Ladder[SECONDLINE_BASE+EditBlanck+0]='N';
                New485Ladder[SECONDLINE_BASE+EditBlanck+1]='o';
                New485Ladder[SECONDLINE_BASE+EditBlanck+2]=' ';
                New485Ladder[SECONDLINE_BASE+EditBlanck+3]='S';
                New485Ladder[SECONDLINE_BASE+EditBlanck+4]='e';
                New485Ladder[SECONDLINE_BASE+EditBlanck+5]='r';
                New485Ladder[SECONDLINE_BASE+EditBlanck+6]='v';
                New485Ladder[SECONDLINE_BASE+EditBlanck+7]='i';
                New485Ladder[SECONDLINE_BASE+EditBlanck+8]='c';
                New485Ladder[SECONDLINE_BASE+EditBlanck+9]='e';
            }
            break;
        case    ONOFF2_GROUP:
            if(DigitData){
                for(i=0;i<11;i++){
                    New485Ladder[SECONDLINE_BASE+EditBlanck+i]=ElevOnOffSetMessage[LadderGroupSub][i];
                }
            }
            else{               
                for(i=0;i<11;i++){
                    New485Ladder[SECONDLINE_BASE+EditBlanck+i]=ElevOnOffResetMessage[LadderGroupSub][i];
                }
            }
            break;
        case    NCNO1_GROUP:
        case    NCNO2_GROUP:
        case    NCNO3_GROUP:			
            if(DigitData){
                New485Ladder[SECONDLINE_BASE+EditBlanck+0]='N';
                New485Ladder[SECONDLINE_BASE+EditBlanck+1]='-';
                New485Ladder[SECONDLINE_BASE+EditBlanck+2]='O';
                New485Ladder[SECONDLINE_BASE+EditBlanck+3]='p';
                New485Ladder[SECONDLINE_BASE+EditBlanck+4]='e';
                New485Ladder[SECONDLINE_BASE+EditBlanck+5]='n';
                New485Ladder[SECONDLINE_BASE+EditBlanck+6]=' ';
            }
            else{               
                New485Ladder[SECONDLINE_BASE+EditBlanck+0]='N';
                New485Ladder[SECONDLINE_BASE+EditBlanck+1]='-';
                New485Ladder[SECONDLINE_BASE+EditBlanck+2]='C';
                New485Ladder[SECONDLINE_BASE+EditBlanck+3]='l';
                New485Ladder[SECONDLINE_BASE+EditBlanck+4]='o';
                New485Ladder[SECONDLINE_BASE+EditBlanck+5]='s';
                New485Ladder[SECONDLINE_BASE+EditBlanck+6]='e';
            }

            break;
        case    IO_GROUP:
            if(LadderGroupSub <= 14){
                for(i=0;i<11;i++){
                    New485Ladder[SECONDLINE_BASE+EditBlanck+i]=IOPortMessage[DigitData][i];
                }
            }
            else if(LadderGroupSub <= 16){               
                for(i=0;i<11;i++){
                    New485Ladder[SECONDLINE_BASE+EditBlanck+i]=ElevSpeedMessage[DigitData][i];
                }
            }
            else if(LadderGroupSub == 20){               
                for(i=0;i<11;i++){
                    New485Ladder[SECONDLINE_BASE+EditBlanck+i]=AUTO_LANDING_MSG[DigitData][i];
                }
            }
            break;
        case    USER_GROUP:  //save
			switch(LadderGroupSub){
				case	BOARD_ID:
	                for(i=0;i<11;i++){
	                    New485Ladder[SECONDLINE_BASE+EditBlanck+i]=ElevBdIdMessage[DigitData][i];
	                }
					break;
				case	USER_LAMP1:
				case	USER_LAMP2:
				case	USER_LAMP3:
				case	USER_LAMP4:
	                for(i=0;i<11;i++){
	                    New485Ladder[SECONDLINE_BASE+EditBlanck+i]=UserLampMessage[DigitData][i];
	                }
					break;
/*
				case	USER_LAMP2:
	                for(i=0;i<11;i++){
	                    New485Ladder[SECONDLINE_BASE+EditBlanck+i]=UserLampMessage[DigitData][i];
	                }
					break;
*/
				case	NORMAL_DSP:
	                for(i=0;i<11;i++){
	                    New485Ladder[SECONDLINE_BASE+EditBlanck+i]=NormalDspMessage[DigitData][i];
	                }
	                i=1;
	                i=0;
					break;
				case	DRIVE_METHOD:
	                for(i=0;i<11;i++){
	                    New485Ladder[SECONDLINE_BASE+EditBlanck+i]=DriveMethodMessage[DigitData][i];
	                }
					break;
				case	FHM_RUN_CHK:
	                for(i=0;i<11;i++){
	                    New485Ladder[SECONDLINE_BASE+EditBlanck+i]=FhmMessage[DigitData][i];
	                }
					break;
				case	INIT_DATA:
	                for(i=0;i<11;i++){
	                    New485Ladder[SECONDLINE_BASE+EditBlanck+i]=InitMessage[DigitData][i];
	                }
					break;
				case	LG_INV_IN_BD:
	                for(i=0;i<11;i++){
	                    New485Ladder[SECONDLINE_BASE+EditBlanck+i]=PcbTypeMessage[DigitData][i];
	                }
					break;
				case	SYSTEM_SET:
	                for(i=0;i<13;i++){
	                    New485Ladder[SECONDLINE_BASE+EditBlanck+i]=SystemSetMessage[DigitData][i];
	                }
					break;
				case	SENSOR_POSITION:
	                for(i=0;i<16;i++){
	                    New485Ladder[SECONDLINE_BASE+i]=SensorPositionMessage[DigitData][i];
	                }

	                New485Ladder[SECONDLINE_BASE+0]= (unsigned char)((SENSOR_POSITION/10) + '0');
	                New485Ladder[SECONDLINE_BASE+1]= (unsigned char)((SENSOR_POSITION%10) + '0');

					SensorPositionDisplay(DigitData);
					break;
				case	FINAL_ERR_DSP:
	                for(i=0;i<16;i++){
	                    New485Ladder[SECONDLINE_BASE+i]=FinalErrMessage[DigitData][i];
	                }
	                New485Ladder[SECONDLINE_BASE+0]= (unsigned char)((FINAL_ERR_DSP/10) + '0');
	                New485Ladder[SECONDLINE_BASE+1]= (unsigned char)((FINAL_ERR_DSP%10) + '0');
					
					i= cF_FLRDSPCH((unsigned long)(F_E_ErrNum));
					if(i >0)	FinalErrDisplay(DigitData);
				
					break;
 			}
            break;
        case    INPORT1_GROUP:
            for(i=0;i<11;i++){
                New485Ladder[SECONDLINE_BASE+EditBlanck+i]=InputPort1SelMessage[DigitData][i];
            }
            break;
        case    INPORT2_GROUP:
            for(i=0;i<11;i++){
                New485Ladder[SECONDLINE_BASE+EditBlanck+i]=InputPort1SelMessage[DigitData][i];
            }
            break;
        case    OUTPORT_GROUP:
            for(i=0;i<11;i++){
                New485Ladder[SECONDLINE_BASE+EditBlanck+i]=OutputPortSelMessage[DigitData][i];
            }
            break;


        case    EL_GROUP:  //save
			switch(LadderGroupSub){
				case	SUBNM_MANUAL_PORT:
				case	SUBNM_BATTERY_PORT:
				case	SUBNM_DEC_PORT:
				case	SUBNM_FHM_PORT:
				case	SUBNM_LOW_SPD_PORT:
				case	SUBNM_MID_SPD_PORT:
				case	SUBNM_HIGH_SPD_PORT:
                	for(i=0;i<11;i++){
                    	New485Ladder[SECONDLINE_BASE+EditBlanck+i]=IOPortMessage[DigitData][i];
					}
					break;
				case	SUBNM_SU2SD2_SPD:
				case	SUBNM_X0X1_SPD:
	                for(i=0;i<11;i++){
	                    New485Ladder[SECONDLINE_BASE+EditBlanck+i]=ElevSpeedMessage_spd3[DigitData][i];
	                }
					break;
				case	SUBNM_LULD_MPM:
	                New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+0]='m';          
	                New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+1]='p';          
	                New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+2]='m';          
					break;
				case	SUBNM_AUTO_TUN:
	                for(i=0;i<14;i++){
	                    New485Ladder[SECONDLINE_BASE+EditBlanck+i]=AutoTunMessage[DigitData][i];
	                }
					break;
				case	SUBNM_AUTO_LANDING:
	                for(i=0;i<11;i++){
	                    New485Ladder[SECONDLINE_BASE+EditBlanck+i]=AUTO_LANDING_MSG[DigitData][i];
	                }
					break;

				case	SUBNM_FHM:
	                for(i=0;i<11;i++){
	                    New485Ladder[SECONDLINE_BASE+EditBlanck+i]=FhmMessage[DigitData][i];
	                }
					break;

			}
			break;
 
       default:
            break;

    }    
}



void  __attribute__((section(".usercode"))) Integer_Digit(void)
{
    unsigned int i,tmpdata;
    unsigned int value;



	if(DigitData > DigitMaxValue){	
		value=DigitMinValue;
		DigitData=DigitMinValue;
	}
	else if(DigitData < DigitMinValue){
		value=DigitMaxValue;
		DigitData=DigitMaxValue;
	}
	else{
		value=DigitData;
	}



  	if((LadderGroup == TIMER_GROUP) && (LadderGroupSub==2)){
		if(DigitData > SEC_MIN_TIME){
			value=(DigitData - SEC_MIN_TIME);
		}
	}     



    if(ShiftCnt == 1){
        New485Ladder[SECONDLINE_BASE+EditBlanck+0]=value            + '0';          
    }
    else if(ShiftCnt == 2){
        New485Ladder[SECONDLINE_BASE+EditBlanck+0]=(value/10)       + '0';          
        New485Ladder[SECONDLINE_BASE+EditBlanck+1]=(value%10)       + '0';          
    }
    else if(ShiftCnt == 3){
        New485Ladder[SECONDLINE_BASE+EditBlanck+0]=(value/100)      + '0';
        value=value%100;              
        New485Ladder[SECONDLINE_BASE+EditBlanck+1]=(value/10)       + '0';          
        New485Ladder[SECONDLINE_BASE+EditBlanck+2]=(value%10)       + '0';          
    }
    else if(ShiftCnt == 4){
        New485Ladder[SECONDLINE_BASE+EditBlanck+0]=(value/1000)     + '0';
        value=value%1000;              
        New485Ladder[SECONDLINE_BASE+EditBlanck+1]=(value/100)      + '0';
        value=value%100;                        
        New485Ladder[SECONDLINE_BASE+EditBlanck+2]=(value/10)       + '0';          
        New485Ladder[SECONDLINE_BASE+EditBlanck+3]=(value%10)       + '0';          
    }
    else if(ShiftCnt == 5){
        New485Ladder[SECONDLINE_BASE+EditBlanck+0]=(value/10000)    + '0';
        value=value%10000;              
        New485Ladder[SECONDLINE_BASE+EditBlanck+1]=(value/1000)     + '0';
        value=value%1000;              
        New485Ladder[SECONDLINE_BASE+EditBlanck+2]=(value/100)      + '0';
        value=value%100;                        
        New485Ladder[SECONDLINE_BASE+EditBlanck+3]=(value/10)       + '0';          
        New485Ladder[SECONDLINE_BASE+EditBlanck+4]=(value%10)       + '0';          
    }

	#ifdef	DELTA_INVERTER
	if( (LadderGroup >= DELTA_PAR_GROUP_00) && (LadderGroup < DELTA_PAR_GROUP_END)){
		Delta_inverter_Par_DataSort(value);					
	}
	#endif

    DigitStringMessage();



  	if((LadderGroup == TIMER_GROUP) && (LadderGroupSub==2)){
		if(DigitData > SEC_MIN_TIME){
	        New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+0]='M';          
	        New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+1]='i';          
	        New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+2]='n';   
		}
	}     

}


/*
void  __attribute__((section(".usercode"))) MinSec(void)
{
//   LocalType i;
//	i=DigitData;

	if(DigitData >= 128){
		DigitData=(DigitData - 127);
		Integer_Digit();
        New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+0]='M';          
        New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+1]='i';          
        New485Ladder[SECONDLINE_BASE+EditBlanck+ShiftCnt+2]='n';   
		DigitData=(DigitData + 127);
	}
}
*/



/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////


void  __attribute__((section(".usercode"))) FlrDspGroup(LocalType offset)
{
    LocalType i;

    i=(offset *2 );
	i=(i+F_FlrDspCh);

    Cursor=0;
    ShiftCnt=2;
    EditBlanck=7;
    EditStatus=DIGIT_ALPHAR_EDIT;

    New485Ladder[SECONDLINE_BASE+EditBlanck+0]=cF_FLRDSPCH((unsigned long)(i+0));  
    New485Ladder[SECONDLINE_BASE+EditBlanck+1]=cF_FLRDSPCH((unsigned long)(i+1));          
}


void  __attribute__((section(".usercode"))) FlrDspGroupSave(LocalType offset)
{
	offset=(offset *2);
	offset=(offset + F_FlrDspCh);
		
    DspCharSave(offset,ShiftCnt);

//    DspCharSave((offset*2),ShiftCnt);

#ifdef	L_K_J
	if((PowerOnTime < L_K_J_TIME) && (PowerOnTime < 0xfff0) ){
		PowerOnTime=0x0;
	}
#endif

}





void  __attribute__((section(".usercode"))) FlrGroup(void)
{
    LocalType i;

    
    i=(LadderGroupSub + GroupBaseAddr);

    Cursor=0;
    ShiftCnt=2;
    EditBlanck=7;
    EditStatus=DIGIT_EDIT;

    DigitMaxValue=cF_TOPFLR+1;
    DigitMinValue=1;

    switch(LadderGroupSub){  
        case    TOP_FLR:      
        case    NO_USE_GO_FLR:
		case	KIDS_KEY_CNT:
		case	X7_SAFE_FLR:
		case	X6_SAFE_FLR:
		case	X5_SAFE_FLR:
            DigitMaxValue=SYSTEM_TOP_FLR+1;
            break;
#ifndef	 FLOOR_64
        case    ONE_STOP_FLR:
		    ShiftCnt=3;
		    EditBlanck=6;
    		DigitMinValue=0;
            DigitMaxValue=256;
			break;

#else
        case    ONE_STOP_FLR:
            DigitMaxValue=SYSTEM_TOP_FLR+1;
			break;

#endif
    }
    DigitData=cF_FLRDSPCH((unsigned long)i);
    DigitData=DigitData+1;
    Integer_Digit();    
}



void  __attribute__((section(".usercode"))) FlrGroupSave(void)
{
    LocalType i;

    DigitData=DigitData-1;

    i=(LadderGroupSub + GroupBaseAddr);
    GetFlashDataToBufRam(F_BLOCK1);
    b_LdTmpBufRam(i)=(LocalType)(DigitData);
    flash_write_DspChar(F_BLOCK1);
}



void  __attribute__((section(".usercode"))) WaitFlrConvStr(LocalType	i)
{
	New485Ladder[SECONDLINE_BASE+EditBlanck+ (i+0)] =(DigitData / 10)  	+ '0';          
	New485Ladder[SECONDLINE_BASE+EditBlanck+ (i+1)] =(DigitData % 10)  	+ '0';          
}


void  __attribute__((section(".usercode"))) WaitFlrGroup(void)
{
    LocalType i;
    
    i=((LadderGroupSub * 5) + GroupBaseAddr);

	Cursor=0;
	ShiftCnt=12;
	EditBlanck=4;
	EditStatus=CLOCK_EDIT;

	if(LadderGroupSub <= 3){
		DigitData=cF_FLRDSPCH((unsigned long)i);
		WaitFlrConvStr(0);

//		New485Ladder[SECONDLINE_BASE+EditBlanck+0] =(DigitData / 10)  	+ '0';          
//		New485Ladder[SECONDLINE_BASE+EditBlanck+1] =(DigitData % 10)  	+ '0';          
	
		DigitData=cF_FLRDSPCH((unsigned long)(i+1));
		WaitFlrConvStr(2);
//		New485Ladder[SECONDLINE_BASE+EditBlanck+2] =(DigitData / 10)    + '0';          
//		New485Ladder[SECONDLINE_BASE+EditBlanck+3] =(DigitData % 10)    + '0';          
		New485Ladder[SECONDLINE_BASE+EditBlanck+4] ='-';          
	
		DigitData=cF_FLRDSPCH((unsigned long)(i+2));
		WaitFlrConvStr(5);
//		New485Ladder[SECONDLINE_BASE+EditBlanck+5] =(DigitData / 10)	+ '0';          
//		New485Ladder[SECONDLINE_BASE+EditBlanck+6] =(DigitData % 10)    + '0';          
	
		DigitData=cF_FLRDSPCH((unsigned long)(i+3));
		WaitFlrConvStr(7);
//		New485Ladder[SECONDLINE_BASE+EditBlanck+7]=(DigitData / 10)		+ '0';          
//		New485Ladder[SECONDLINE_BASE+EditBlanck+8]=(DigitData % 10)    	+ '0';          
		New485Ladder[SECONDLINE_BASE+EditBlanck+9]='-';          
	
		DigitData=cF_FLRDSPCH((unsigned long)(i+4));
		DigitData=(DigitData + 1);
		New485Ladder[SECONDLINE_BASE+EditBlanck+10]=(DigitData / 10)	+ '0';          
		New485Ladder[SECONDLINE_BASE+EditBlanck+11]=(DigitData % 10)    + '0';          
	}
}



void  __attribute__((section(".usercode"))) WaitFlrConv(LocalType	i)
{
	DigitData=New485Ladder[SECONDLINE_BASE+EditBlanck + i ]-'0';
    DigitData=(DigitData * 10);      
	DigitData=((New485Ladder[SECONDLINE_BASE+EditBlanck + (i+1)] -'0') + DigitData);          
}


void  __attribute__((section(".usercode"))) WaitFlrGroupSave(void)
{
    LocalType i;

	if(LadderGroupSub <= 3){

	    i=(LadderGroupSub * 5);
	    GetFlashDataToBufRam(F_BLOCK3);

		WaitFlrConv(0);
	
//		DigitData=New485Ladder[SECONDLINE_BASE+EditBlanck+0]-'0';
//	    DigitData=(DigitData * 10);      
//		DigitData=((New485Ladder[SECONDLINE_BASE+EditBlanck+1] -'0') + DigitData);          

	    b_LdTmpBufRam((unsigned long)(i))=(LocalType)(DigitData);

	
		i++;
		WaitFlrConv(2);

//		DigitData=New485Ladder[SECONDLINE_BASE+EditBlanck+2]-'0';
//	    DigitData=(DigitData * 10);      
//		DigitData=((New485Ladder[SECONDLINE_BASE+EditBlanck+3] -'0') + DigitData);          
	    b_LdTmpBufRam((unsigned long)(i))=(LocalType)(DigitData);
	
		i++;
		WaitFlrConv(5);
//		DigitData=New485Ladder[SECONDLINE_BASE+EditBlanck+5]-'0';
//	    DigitData=(DigitData * 10);      
//		DigitData=((New485Ladder[SECONDLINE_BASE+EditBlanck+6] -'0') + DigitData);          
	    b_LdTmpBufRam((unsigned long)(i))=(LocalType)(DigitData);
	
		i++;
		WaitFlrConv(7);
//		DigitData=New485Ladder[SECONDLINE_BASE+EditBlanck+7]-'0';
//	    DigitData=(DigitData * 10);      
//		DigitData=((New485Ladder[SECONDLINE_BASE+EditBlanck+8] -'0') + DigitData);          
	    b_LdTmpBufRam((unsigned long)(i))=(LocalType)(DigitData);
	
		i++;
		WaitFlrConv(10);
//		DigitData=New485Ladder[SECONDLINE_BASE+EditBlanck+10]-'0';
//	    DigitData=(DigitData * 10);      
//		DigitData=((New485Ladder[SECONDLINE_BASE+EditBlanck+11] -'0') + DigitData);          
	    b_LdTmpBufRam((unsigned long)(i))=(LocalType)(DigitData-1);

		flash_write_DspChar(F_BLOCK3);
	}
}


/*
void  __attribute__((section(".usercode"))) WaitFlrGroup(void)
{
    LocalType i;
    
    i=(LadderGroupSub + GroupBaseAddr);

    Cursor=0;
    ShiftCnt=2;
    EditBlanck=7;
    EditStatus=DIGIT_EDIT;

    if(LadderGroupSub >= 30){            
        DigitMaxValue=23;
        DigitMinValue=0;
        DigitData=cF_FLRDSPCH((unsigned long)i);
        Integer_Digit();    
    }
    else{
        DigitMaxValue=33;
        DigitMinValue=1;
        DigitData=cF_FLRDSPCH((unsigned long)i);
        DigitData=DigitData+1;
        Integer_Digit();    
    }
}



void  __attribute__((section(".usercode"))) WaitFlrGroupSave(void)
{
    LocalType i;

    if(LadderGroupSub < 30) DigitData=DigitData-1;

    i=(LadderGroupSub + GroupBaseAddr);

    GetFlashDataToBufRam(F_BLOCK3);
    b_LdTmpBufRam(i)=(LocalType)(DigitData);
    flash_write_DspChar(F_BLOCK3);
}

*/



void  __attribute__((section(".usercode"))) TimerGroup(void)
{
    LocalType i;


    switch(LadderGroupSub){        
        case    23:
        case    24:
            Cursor=0;
            ShiftCnt=2;
            EditBlanck=5;
            EditStatus=DIGIT_EDIT;
            DigitMinValue=0;
            DigitMaxValue=81;
            i=(LadderGroupSub + F_OpWtTm);
			DigitData=cF_FLRDSPCH((unsigned long)i);
            Integer_Digit();
            break;

        case    12:
        case    18:
        case    19:
        case    20:
        case    21:
        case    22:
//            Cursor=0;
//            ShiftCnt=5;
//            EditBlanck=5;
//            EditStatus=DIGIT_EDIT;
//            DigitMinValue=0;
//            DigitMaxValue=65535;
//            DigitData=iF_FLRDSPCH(F_BrkStTm10);

            Cursor=0;
            ShiftCnt=3;
            EditBlanck=5;
            EditStatus=DIGIT_EDIT;
            DigitMinValue=0;
            DigitMaxValue=254;
            i=(LadderGroupSub + F_OpWtTm);
			DigitData=cF_FLRDSPCH((unsigned long)i);

            Integer_Digit();
            break;
/*
        case    19:
            Cursor=0;
            ShiftCnt=5;
            EditBlanck=5;
            EditStatus=DIGIT_EDIT;
            DigitMaxValue=65535;
            DigitMinValue=0;
            DigitData=iF_FLRDSPCH(F_BrkStTm20);
            Integer_Digit();
            break;
        case    20:
            Cursor=0;
            ShiftCnt=5;
            EditBlanck=5;
            EditStatus=DIGIT_EDIT;
            DigitMaxValue=65535;
            DigitMinValue=0;

            DigitData=iF_FLRDSPCH(F_BrkStTm30);
            Integer_Digit();
            break;
        case    21:
            Cursor=0;
            ShiftCnt=5;
            EditBlanck=5;
            EditStatus=DIGIT_EDIT;
            DigitMaxValue=65535;
            DigitMinValue=0;

            DigitData=iF_FLRDSPCH(F_BrkStTm40);
            Integer_Digit();
            break;
        case    22:
            Cursor=0;
            ShiftCnt=5;
            EditBlanck=5;
            EditStatus=DIGIT_EDIT;
            DigitMaxValue=65535;
            DigitMinValue=0;

            DigitData=iF_FLRDSPCH(F_BrkStTm50);
            Integer_Digit();
            break;
*/

        case    0:
        case    1:
		case	2:
            i=(LadderGroupSub + F_OpWtTm);
            Cursor=0;
            ShiftCnt=3;
            EditBlanck=5;
            EditStatus=DIGIT_EDIT;
            DigitMaxValue=254;
            DigitMinValue=0;
            DigitData=cF_FLRDSPCH((unsigned long)i);
            Integer_Digit();
			break;
        case    3:
            i=(LadderGroupSub + F_OpWtTm);
            Cursor=0;
            EditBlanck=6;
            EditStatus=DIGIT_EDIT;
//            ShiftCnt=2;
//            DigitMaxValue=95;
            ShiftCnt=3;
            DigitMaxValue=200;
            DigitMinValue=0;
            DigitData=cF_FLRDSPCH((unsigned long)i);
            Integer_Digit();    
            break;
        case    5:
        case    6:
        case    4:
        case    8:
        case    9:
        case   10:
            i=(LadderGroupSub + F_OpWtTm);
            Cursor=0;
            ShiftCnt=2;
            EditBlanck=6;
            EditStatus=DIGIT_EDIT;
            DigitMaxValue=99;
            DigitMinValue=0;
            DigitData=cF_FLRDSPCH((unsigned long)i);
            Integer_Digit();    
            break;
        case    7:
        case    11:
            i=(LadderGroupSub + F_OpWtTm);
            Cursor=0;
            ShiftCnt=2;
            EditBlanck=6;
            EditStatus=DIGIT_EDIT;
            DigitMaxValue=20;
            DigitMinValue=0;
            DigitData=cF_FLRDSPCH((unsigned long)i);
            Integer_Digit();    
            break;
        default:
            i=(LadderGroupSub + F_OpWtTm);
            Cursor=0;
            ShiftCnt=3;
            EditBlanck=6;
            EditStatus=DIGIT_EDIT;
            DigitMaxValue=250;
            DigitMinValue=0;
            DigitData=cF_FLRDSPCH((unsigned long)i);
            Integer_Digit();    
            break;
    }    
}


void  __attribute__((section(".usercode"))) TimerGroupSave(void)
{
    LocalType i;

    i=(LadderGroupSub + F_OpWtTm);

    GetFlashDataToBufRam(F_BLOCK1);
    b_LdTmpBufRam(i)=(LocalType)(DigitData);
    flash_write_DspChar(F_BLOCK1);


/*
    LocalType i,j;

    j=0;

    switch(LadderGroupSub){        
        case    18:
            i=F_BrkStTm10;
            j=1;
            break;
        case    19:
            i=F_BrkStTm20;
            j=1;
            break;
        case    20:
            i=F_BrkStTm30;
            j=1;
            break;
        case    21:
            i=F_BrkStTm40;
            j=1;
            break;
        case    22:
            i=F_BrkStTm50;
            j=1;
            break;
        default:
            i=(LadderGroupSub + F_OpWtTm);
            j=2;
            break;
    }    

    if(j>0){
        GetFlashDataToBufRam(F_BLOCK1);
        if(j==1){
            i_LdTmpBufRam(i)=(LocalType)(DigitData);
        }
        else if(j==2){
            b_LdTmpBufRam(i)=(LocalType)(DigitData);
        }
        flash_write_DspChar(F_BLOCK1);
    }
*/
}


void  __attribute__((section(".usercode"))) OnOffGroup(void)
{
    LocalType i,j,BitValue;

    i=((LadderGroupSub/8) + GroupBaseAddr);
    j=(LadderGroupSub%8);
    BitValue=(0x01 << j);

    Cursor=0;
    ShiftCnt=0;
    EditBlanck=4;
    EditStatus=DIGIT_STRING_EDIT;                   
    DigitMaxValue=2;
    DigitMinValue=0;

    DigitData=cF_FLRDSPCH((unsigned long)i);

    if(DigitData &  BitValue)   DigitData=1;     
    else                        DigitData=0;     

    if((LadderGroup == ONOFF2_GROUP)  && (LadderGroupSub == FHM_CHK)) EditStatus=NO_EDIT;                   

    Integer_Digit();
}



#ifdef	 FLOOR_64
void  __attribute__((section(".usercode"))) OnOffGroupSave(void)
{
    LocalType i,j;

	LocalType block_pt;

	block_pt=(GroupBaseAddr/64);
	block_pt=(block_pt * 64);

    i=((LadderGroupSub/8) + GroupBaseAddr);
    j=(LadderGroupSub%8);

    GetFlashDataToBufRam(block_pt);

    if(DigitData){
        bit_LdTmpBufRamSet(i,j);
    }
    else{
        bit_LdTmpBufRamReset(i,j);
    }
    flash_write_DspChar(block_pt);

    if(LadderGroup == ONOFF1_GROUP){
		ShadowsRamDArry[FLR_ON_OFF0]=cF_NONSERVICE0;
		ShadowsRamDArry[FLR_ON_OFF1]=cF_NONSERVICE1;
		ShadowsRamDArry[FLR_ON_OFF2]=cF_NONSERVICE2;
		ShadowsRamDArry[FLR_ON_OFF3]=cF_NONSERVICE3;
		ShadowsRamDArry[FLR_ON_OFF4]=cF_NONSERVICE4;
		ShadowsRamDArry[FLR_ON_OFF5]=cF_NONSERVICE5;
		ShadowsRamDArry[FLR_ON_OFF6]=cF_NONSERVICE6;
		ShadowsRamDArry[FLR_ON_OFF7]=cF_NONSERVICE7;
	}
}
#else

void  __attribute__((section(".usercode"))) OnOffGroupSave(void)
{
    LocalType i,j;
	LocalType block_pt;

	block_pt=(GroupBaseAddr/64);
	block_pt=(block_pt * 64);


    i=((LadderGroupSub/8) + GroupBaseAddr);
    j=(LadderGroupSub%8);

    GetFlashDataToBufRam(block_pt);

    if(DigitData){
        bit_LdTmpBufRamSet(i,j);
    }
    else{
        bit_LdTmpBufRamReset(i,j);
    }
    flash_write_DspChar(block_pt);


    if(LadderGroup == ONOFF1_GROUP){
		ShadowsRamDArry[FLR_ON_OFF0]=cF_NONSERVICE0;
		ShadowsRamDArry[FLR_ON_OFF1]=cF_NONSERVICE1;
		ShadowsRamDArry[FLR_ON_OFF2]=cF_NONSERVICE2;
		ShadowsRamDArry[FLR_ON_OFF3]=cF_NONSERVICE3;
	}
}
#endif



void  __attribute__((section(".usercode"))) NcNoGroup(void)
{
    LocalType i,j,BitValue;

    i=(LadderGroupSub + GroupBaseAddr);

	if     (i==F_SubDoorFlr1)	i=DOOR_HOLD_PORT;	
	else if(i==F_SubDoorFlr2)	i=VIRTUAL_X1_PORT;
	else if(i==F_SubDoorFlr3)	i=VIRTUAL_X2_PORT;	
	else if(i==F_SubDoorFlr4)	i=VIRTUAL_X3_PORT;	
	else if(i==F_SubDoorFlr5)	i=VIRTUAL_X4_PORT;	
	else if(i==F_SubDoorFlr6)	i=VIRTUAL_X5_PORT;	
	else if(i==F_SubDoorFlr7)	i=VIRTUAL_X6_PORT;	
	else if(i==F_SubDoorFlr8)	i=VIRTUAL_X7_PORT;	

    Cursor=0;
    ShiftCnt=0;
    EditBlanck=4;
    EditStatus=DIGIT_STRING_EDIT;                   
    DigitMaxValue=2;
    DigitMinValue=0;

    DigitData=cF_FLRDSPCH((unsigned long)i);

    if(DigitData &  0x80)       DigitData=1;     
    else                        DigitData=0;     

    Integer_Digit();
}


void  __attribute__((section(".usercode"))) InNcNoGroupSave(void)
{
    LocalType i,j;


    i=(LadderGroupSub + GroupBaseAddr);

	if ( (i >= F_SubDoorFlr1) && (i <= F_SubDoorFlr8)){
		if     (i==F_SubDoorFlr1)	i=DOOR_HOLD_PORT;	
		else if(i==F_SubDoorFlr2)	i=VIRTUAL_X1_PORT;
		else if(i==F_SubDoorFlr3)	i=VIRTUAL_X2_PORT;	
		else if(i==F_SubDoorFlr4)	i=VIRTUAL_X3_PORT;	
		else if(i==F_SubDoorFlr5)	i=VIRTUAL_X4_PORT;	
		else if(i==F_SubDoorFlr6)	i=VIRTUAL_X5_PORT;	
		else if(i==F_SubDoorFlr7)	i=VIRTUAL_X6_PORT;	
		else if(i==F_SubDoorFlr8)	i=VIRTUAL_X7_PORT;	


	    GetFlashDataToBufRam(F_BLOCK5);
	
	    if(DigitData){
	        b_LdTmpBufRam(i)=(LocalType)(b_LdTmpBufRam(i) | 0x80);
	    }
	    else{
	        b_LdTmpBufRam(i)=(LocalType)(b_LdTmpBufRam(i) & 0x7f);
	    }
	    flash_write_DspChar(F_BLOCK5);
	}	
	else{

	    GetFlashDataToBufRam(F_BLOCK4);
	
	    if(DigitData){
	        b_LdTmpBufRam(i)=(LocalType)(b_LdTmpBufRam(i) | 0x80);
	    }
	    else{
	        b_LdTmpBufRam(i)=(LocalType)(b_LdTmpBufRam(i) & 0x7f);
	    }
	    flash_write_DspChar(F_BLOCK4);
	}
}


void  __attribute__((section(".usercode"))) OutNcNoGroupSave(void)
{
    LocalType i,j,selID,real_val;


	selID=CurSelPortIDRead(LadderGroupSub);
	real_val=CurSelOutPortChk(selID);


    i=(LadderGroupSub + GroupBaseAddr);

    GetFlashDataToBufRam(F_BLOCK5);

    if(DigitData){
        b_LdTmpBufRam(i)=(LocalType)(b_LdTmpBufRam(i) | 0x80);
    }
    else{
        b_LdTmpBufRam(i)=(LocalType)(b_LdTmpBufRam(i) & 0x7f);
    }
    flash_write_DspChar(F_BLOCK5);


	selID=CurSelPortIDRead(LadderGroupSub);
	CurSelOutPort(selID,real_val);
}



void  __attribute__((section(".usercode"))) IoGroup(void)
{
    LocalType i;
    
    i=(LadderGroupSub + GroupBaseAddr);

    Cursor=0;
    ShiftCnt=3;
    EditBlanck=5;
    EditStatus=DIGIT_EDIT;

    DigitMinValue=0;
    if(LadderGroupSub <= 14){
        ShiftCnt=0;
        EditStatus=DIGIT_STRING_EDIT;    

        if(INVERTER_CHECK == IO)      DigitMaxValue=IO_PORT_MESSAGE_CNT-1;
        else                          DigitMaxValue=IO_PORT_MESSAGE_CNT;

        DigitData=cF_FLRDSPCH((unsigned long)i);
        Integer_Digit();
    }
    else if(LadderGroupSub <= 16){               
        ShiftCnt=0;
        EditStatus=DIGIT_STRING_EDIT;                   

        if(INVERTER_CHECK == IO)        DigitMaxValue=ELEV_SPEED_MESSAGE_CNT;
        else                            DigitMaxValue=ELEV_SPEED_MESSAGE_CNT;

        DigitData=cF_FLRDSPCH((unsigned long)i);
        Integer_Digit();
    }
    else if(LadderGroupSub == 20){               
        ShiftCnt=0;
        EditStatus=DIGIT_STRING_EDIT;                   
		DigitMaxValue=AUTO_LANDING_MESSAGE_CNT;

        DigitData=cF_FLRDSPCH((unsigned long)F_AutoLandingMode);
        Integer_Digit();
    }
    else{               
        ShiftCnt=3;
        EditBlanck=7;
        DigitMaxValue=220;
        DigitData=cF_FLRDSPCH((unsigned long)i);
        Integer_Digit();
    }
}



void  __attribute__((section(".usercode"))) IoGroupSave(void)
{
    LocalType i;

    i=(LadderGroupSub + GroupBaseAddr);

    if(i==16){
        switch(DigitData){
            case    SPEED_30:
                if(cF_SPEED30 == 0)    DigitData=SPEED_210;     
                break;
            case    SPEED_45:
                if(cF_SPEED45 == 0)    DigitData=SPEED_210;     
                break;
            case    SPEED_60:
                if(cF_SPEED60 == 0)    DigitData=SPEED_210;     
                break;
            case    SPEED_90:
                if(cF_SPEED90 == 0)    DigitData=SPEED_210;     
                break;
            case    SPEED_105:
                if(cF_SPEED105 == 0)    DigitData=SPEED_210;     
                break;
            case    SPEED_120:
                if(cF_SPEED120 == 0)    DigitData=SPEED_210;     
                break;
            case    SPEED_150:
                if(cF_SPEED150 == 0)    DigitData=SPEED_210;     
                break;
            case    SPEED_180:
                if(cF_SPEED180 == 0)    DigitData=SPEED_210;     
                break;
            case    SPEED_210:
                if(cF_SPEED210 == 0)    DigitData=SPEED_210;     
                break;
            default:
                DigitData=SPEED_210;     
                break;
        }
    }
    
    GetFlashDataToBufRam(F_BLOCK2);
    b_LdTmpBufRam(i)=(LocalType)(DigitData);
    flash_write_DspChar(F_BLOCK2);
}





void  __attribute__((section(".usercode"))) DoorGroup(void)
{
    LocalType i;
    
    i=(LadderGroupSub + GroupBaseAddr);

    Cursor=0;
    ShiftCnt=0;
    EditBlanck=5;
    EditStatus=DIGIT_STRING_EDIT;
    DigitMinValue=0;
	DigitMaxValue=DOOR_SEL_MESSAGE_CNT;

    DigitData=MainSubDoorFlrChk(LadderGroupSub);

    Integer_Digit();


/*

    if(LadderGroupSub <= 14){
        ShiftCnt=0;
        EditStatus=DIGIT_STRING_EDIT;    

        if(INVERTER_CHECK == IO)      DigitMaxValue=IO_PORT_MESSAGE_CNT-1;
        else                          DigitMaxValue=IO_PORT_MESSAGE_CNT;

        DigitData=cF_FLRDSPCH((unsigned long)i);
        Integer_Digit();
    }
    else if(LadderGroupSub <= 16){               
        ShiftCnt=0;
        EditStatus=DIGIT_STRING_EDIT;                   

        if(INVERTER_CHECK == IO)        DigitMaxValue=IO_PORT_MESSAGE_CNT-1;
        else                            DigitMaxValue=IO_PORT_MESSAGE_CNT;

//kkk        if(cF_BD_ID == IO_INVERTER) DigitMaxValue=IO_PORT_MESSAGE_CNT-1;
//kkk        else                        DigitMaxValue=IO_PORT_MESSAGE_CNT;

        DigitData=cF_FLRDSPCH((unsigned long)i);
        Integer_Digit();
    }
    else{               
        ShiftCnt=3;
        EditBlanck=7;
        DigitMaxValue=200;
        DigitData=cF_FLRDSPCH((unsigned long)i);
        Integer_Digit();
    }
*/

}




LocalType   __attribute__((section(".usercode"))) DoorGroupSave(void)
{
    LocalType i,j,k;

	LocalType block_pt;

	block_pt=(GroupBaseAddr/64);
	block_pt=(block_pt * 64);


	i=0x0;
    k=0x0;

    i=LadderGroupSub/4;
    k=LadderGroupSub%4;

    j=0;

    switch(i){
        case    0:
            j=cF_SUBDOORFLR1;
            break;
        case    1:
            j=cF_SUBDOORFLR2;
            break;
        case    2:
            j=cF_SUBDOORFLR3;
            break;
        case    3:        
            j=cF_SUBDOORFLR4;
            break;
        case    4:
            j=cF_SUBDOORFLR5;
            break;
        case    5:
            j=cF_SUBDOORFLR6;
            break;
        case    6:
            j=cF_SUBDOORFLR7;
            break;
        case    7:        
            j=cF_SUBDOORFLR8;
            break;
        case    8:
            j=cF_SUBDOORFLR9;
            break;
        case    9:
            j=cF_SUBDOORFLR10;
            break;
        case    10:
            j=cF_SUBDOORFLR11;
            break;
        case    11:        
            j=cF_SUBDOORFLR12;
            break;
        case    12:
            j=cF_SUBDOORFLR13;
            break;
        case    13:
            j=cF_SUBDOORFLR14;
            break;
        case    14:
            j=cF_SUBDOORFLR15;
            break;
        case    15:        
            j=cF_SUBDOORFLR16;
            break;
		default:
			return(0);
    }

    switch(k){
        case    0:
            j=(j & 0xfc);
            break;
        case    1:
            j=(j & 0xf3);
			DigitData=(DigitData << 2); 
            break;
        case    2:
            j=(j & 0xcf);
			DigitData=(DigitData << 4); 
            break;
        case    3:        
            j=(j & 0x3f);
			DigitData=(DigitData << 6); 
            break;
    }
	DigitData=(DigitData | j);
	    
	k=(LadderGroupSub/4);
    i=(k + GroupBaseAddr);

    GetFlashDataToBufRam(block_pt);
    b_LdTmpBufRam(i)=(LocalType)(DigitData);
    flash_write_DspChar(block_pt);

	return(0);
}




void  __attribute__((section(".usercode"))) UserGroup(void)
{
    LocalType i,j;

    switch(LadderGroupSub){
        case    VERSION:
            Cursor=0;
            ShiftCnt=0;
            EditBlanck=5;
            EditStatus=NO_EDIT;
            DigitMaxValue=0;
            DigitMinValue=0;

            i=F_Ver0;
            New485Ladder[SECONDLINE_BASE+EditBlanck+0]=cF_FLRDSPCH((unsigned long)(i+0));  
            New485Ladder[SECONDLINE_BASE+EditBlanck+1]='.';      
            New485Ladder[SECONDLINE_BASE+EditBlanck+2]=cF_FLRDSPCH((unsigned long)(i+1));  
            New485Ladder[SECONDLINE_BASE+EditBlanck+3]=cF_FLRDSPCH((unsigned long)(i+2));   


/*
            New485Ladder[SECONDLINE_BASE+EditBlanck+0]=cF_FLRDSPCH((unsigned long)(i+0));  
            New485Ladder[SECONDLINE_BASE+EditBlanck+1]=cF_FLRDSPCH((unsigned long)(i+1));  
            New485Ladder[SECONDLINE_BASE+EditBlanck+2]='.';      
            New485Ladder[SECONDLINE_BASE+EditBlanck+3]=cF_FLRDSPCH((unsigned long)(i+2));      
*/
            break;
        case    BOARD_ID:
            Cursor=0;
            ShiftCnt=0;
            EditBlanck=5;
            EditStatus=DIGIT_STRING_EDIT;
            DigitMaxValue=ELEV_BD_ID_MESSAGE_CNT;
            DigitMinValue=0;
            i=F_Bd_Id;
            DigitData=cF_FLRDSPCH((unsigned long)i);

            switch(DigitData){
                case    0x0:
                case    0x1:
                case    0x2:
                    break;
                case    0x4:
                    DigitData=3;    
                    break;
                case    0x5:
                    DigitData=4;    
                    break;
                case    0x6:
                    DigitData=5;    
                    break;
                case    0x8:
                    DigitData=6;    
                    break;
                case    0x9:
                    DigitData=7;    
                    break;
                case    0xa:
                    DigitData=8;    
                    break;
            }

            Integer_Digit();
            break;
        case    PASSWARD:
            Cursor=0;
            ShiftCnt=4;
            EditBlanck=5;
            EditStatus=DIGIT_ALPHAR_EDIT;
            DigitMaxValue=0;
            DigitMinValue=0;
            New485Ladder[SECONDLINE_BASE+EditBlanck+0]='*';  
            New485Ladder[SECONDLINE_BASE+EditBlanck+1]='*';  
            New485Ladder[SECONDLINE_BASE+EditBlanck+2]='*';      
            New485Ladder[SECONDLINE_BASE+EditBlanck+3]='*';      
            break;
        case    SERIAL_NM:
            Cursor=0;
            ShiftCnt=5;
            EditBlanck=5;
            EditStatus=DIGIT_EDIT;
            DigitMaxValue=65535;
            DigitMinValue=0;

            i=F_SerialNm10;
            DigitData=iF_FLRDSPCH((unsigned long)i);
            Integer_Digit();
            break;
        case    USER_LAMP1:
        case    USER_LAMP2:
        case    USER_LAMP3:
        case    USER_LAMP4:
            Cursor=0;
            ShiftCnt=0;
            EditBlanck=5;
            EditStatus=DIGIT_STRING_EDIT;
            DigitMaxValue=USER_LAMP_MESSAGE_CNT;
            DigitMinValue=0;
			if(LadderGroupSub == USER_LAMP1)		i=F_UserLamp1;
			else if(LadderGroupSub == USER_LAMP2)	i=F_UserLamp2;
			else if(LadderGroupSub == USER_LAMP3)	i=F_UserLamp3;
			else if(LadderGroupSub == USER_LAMP4)	i=F_UserLamp4;
            DigitData=cF_FLRDSPCH((unsigned long)i);
            Integer_Digit();
            break;
        case    SYSTEM_SET:
            Cursor=0;
            ShiftCnt=0;
            EditBlanck=3;
            EditStatus=DIGIT_STRING_EDIT;
            DigitMaxValue=SYSTEM_SET_MESSAGE_CNT;
            DigitMinValue=0;
            i=F_SystemSet;
            DigitData=cF_FLRDSPCH((unsigned long)i);
            Integer_Digit();
			break;
        case    ERR_ST_CNT:
            Cursor=0;
            ShiftCnt=3;
            EditBlanck=5;
            EditStatus=DIGIT_EDIT;
            DigitMaxValue=255;
            DigitMinValue=0;
            i=F_ErrStopCnt;
            DigitData=cF_FLRDSPCH((unsigned long)i);
            Integer_Digit();
            break;
        case    GROUP_NUMBER:
            Cursor=0;
            ShiftCnt=2;
            EditBlanck=6;
            EditStatus=DIGIT_EDIT;
            DigitMaxValue=31;
            DigitMinValue=0;
            i=F_GroupNm;
            DigitData=cF_FLRDSPCH((unsigned long)i);
            Integer_Digit();
            break;
        case    LOCAL_NUMBER:
            Cursor=0;
            ShiftCnt=1;
            EditBlanck=7;
            EditStatus=DIGIT_EDIT;

#ifndef	MAX_EIGHT_CAR
            DigitMaxValue=3;
#else
            DigitMaxValue=7;
#endif
            DigitMinValue=0;
            i=F_LocalNm;
            DigitData=cF_FLRDSPCH((unsigned long)i);
            Integer_Digit();
            break;
        case    NORMAL_DSP:                                      //NormalDsp
            Cursor=0;
            ShiftCnt=0;
            EditBlanck=5;
            EditStatus=DIGIT_STRING_EDIT;
            DigitMaxValue=NORMAL_DSP_MESSAGE_CNT;
            DigitMinValue=0;
            i=F_NormalDsp;
            DigitData=cF_FLRDSPCH((unsigned long)i);
            Integer_Digit();
            break;
        case    COMPANY_NAME:                           
            Cursor=0;
            ShiftCnt=1;
            EditBlanck=7;
            EditStatus=DIGIT_ALPHAR_EDIT;
            DigitMaxValue=0;
            DigitMinValue=0;
            i=F_Company;
            New485Ladder[SECONDLINE_BASE+EditBlanck+0]=cF_FLRDSPCH((unsigned long)(i));  
            break;
        case    HH_MM_SS:
            Cursor=0;
            ShiftCnt=8;
            EditBlanck=5;
            EditStatus=CLOCK_EDIT;

            New485Ladder[SECONDLINE_BASE+EditBlanck+0] =(sRamDArry[Hour]    >> 4)      + '0';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+1] =(sRamDArry[Hour]    &  0x0f)   + '0';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+2]='-';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+3] =(sRamDArry[Minuate] >> 4)      + '0';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+4]=(sRamDArry[Minuate] & 0x0f)     + '0';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+5]='-';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+6]=(sRamDArry[sec]     >> 4)       + '0';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+7]=(sRamDArry[sec]     & 0x0f)     + '0';          
            break;
        case    YY_MM_DD:
            Cursor=0;
            ShiftCnt=8;
            EditBlanck=5;
            EditStatus=CLOCK_EDIT;

            New485Ladder[SECONDLINE_BASE+EditBlanck+0] =(sRamDArry[Year]    >> 4)      + '0';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+1] =(sRamDArry[Year]    & 0x0f)    + '0';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+2]='-';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+3] =(sRamDArry[Month]   >> 4)      + '0';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+4] =(sRamDArry[Month]   & 0x0f)    + '0';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+5]='-';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+6] =(sRamDArry[Day]     >> 4)      + '0';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+7] =(sRamDArry[Day]     & 0x0f)    + '0';          
            break;
        case    OUT_DATE:
            Cursor=0;
            ShiftCnt=8;
            EditBlanck=5;
            EditStatus=CLOCK_EDIT;

            New485Ladder[SECONDLINE_BASE+EditBlanck+0] =(cF_year    >> 4)      + '0';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+1] =(cF_year    & 0x0f)    + '0';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+2]='-';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+3] =(cF_month   >> 4)      + '0';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+4] =(cF_month   & 0x0f)    + '0';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+5]='-';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+6] =(cF_day     >> 4)      + '0';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+7] =(cF_day     & 0x0f)    + '0';          
            break;
        case    DRIVE_METHOD:
            Cursor=0;
            ShiftCnt=0;
            EditBlanck=5;
            EditStatus=DIGIT_STRING_EDIT;
            DigitMaxValue=3;
            DigitMinValue=0;


            if(cF_NONSERVICE0 == 0x55)		DigitData=1;
            else if(cF_NONSERVICE0 == 0xaa)	DigitData=2;
 			else							DigitData=0;

            Integer_Digit();
            break;
        case    FHM_RUN_CHK:
            Cursor=0;
            ShiftCnt=0;
            EditBlanck=5;
            EditStatus=DIGIT_STRING_EDIT;
            DigitMaxValue=2;
            DigitMinValue=0;

			DigitData=0;
            Integer_Digit();
            break;
        case    LG_INV_IN_BD:
            Cursor=0;
            ShiftCnt=0;
            EditBlanck=5;
            EditStatus=DIGIT_STRING_EDIT;
            DigitMaxValue=2;
            DigitMinValue=0;
            i=F_PcbType;
            DigitData=cF_FLRDSPCH((unsigned long)i);
            Integer_Digit();
            break;
        case    ALL_MENU_CHK:
        case    ENGINEER_NM:
            Cursor=0;
            ShiftCnt=4;
            EditBlanck=5;
            EditStatus=DIGIT_ALPHAR_EDIT;
            DigitMaxValue=0;
            DigitMinValue=0;

            New485Ladder[SECONDLINE_BASE+EditBlanck+0]='0';  
            New485Ladder[SECONDLINE_BASE+EditBlanck+1]='0';  
            New485Ladder[SECONDLINE_BASE+EditBlanck+2]='0';      
            New485Ladder[SECONDLINE_BASE+EditBlanck+3]='0';      
            break;
        case    TOTAL_USE_TIME:
            Cursor=0;
            ShiftCnt=5;
            EditBlanck=5;
            EditStatus=NO_EDIT;
            DigitMaxValue=0xffff;
            DigitMinValue=0;

            DigitData=PowerOnTime;
            Integer_Digit();
            break;
        case    INIT_DATA:
            Cursor=0;
            ShiftCnt=0;
            EditBlanck=5;
            EditStatus=DIGIT_STRING_EDIT;
            DigitMaxValue=INIT_MESSAGE;
            DigitMinValue=0;
            DigitData=0;
            Integer_Digit();
            break;
        case    VIRTUAL_CALL:
            Cursor=0;
            ShiftCnt=9;
            EditBlanck=4;
            EditStatus=CLOCK_EDIT;

            if(sRamDArry[mVFlrCnt] > 254)			sRamDArry[mVFlrCnt]=0;
            if(sRamDArry[mVFlr1]   > (cF_TOPFLR+1))	sRamDArry[mVFlr1]=0;
            if(sRamDArry[mVFlr2]   > (cF_TOPFLR+1))	sRamDArry[mVFlr2]=0;
	
			i=sRamDArry[mVFlrCnt];
            New485Ladder[SECONDLINE_BASE+EditBlanck+0] =(i / 100)	+ '0';
			i=(i % 100);           
            New485Ladder[SECONDLINE_BASE+EditBlanck+1] =(i / 10)  + '0';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+2] =(i % 10)  + '0';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+3] ='-';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+4] =(sRamDArry[mVFlr1] / 10)    + '0';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+5] =(sRamDArry[mVFlr1] % 10)    + '0';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+6] ='-';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+7] =(sRamDArry[mVFlr2] / 10)	+ '0';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+8] =(sRamDArry[mVFlr2] % 10)    + '0';         
            break;

        case    HALL_IND_SET:
            Cursor=0;
            ShiftCnt=11;
            EditBlanck=5;
            EditStatus=CLOCK_EDIT;

            New485Ladder[SECONDLINE_BASE+EditBlanck+0]  =HibSet[0] + '0';
            New485Ladder[SECONDLINE_BASE+EditBlanck+1]  ='-';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+2]  =HibSet[1] + '0';
            New485Ladder[SECONDLINE_BASE+EditBlanck+3]  ='-';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+4]  =HibSet[2] + '0';
            New485Ladder[SECONDLINE_BASE+EditBlanck+5]  ='-';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+6]  =HibSet[3] + '0';
            New485Ladder[SECONDLINE_BASE+EditBlanck+7]  ='-';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+8]  =HibSet[4] + '0';
            New485Ladder[SECONDLINE_BASE+EditBlanck+9]  ='-';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+10] =HibSet[5] + '0';
            break;
		case    User_G4:
		case    User_G5:
		case    User_G6:
				break;
		case    FINAL_ERR_DSP:			
            Cursor=0;
            ShiftCnt=0;
            EditBlanck=0;
            EditStatus=DIGIT_STRING_EDIT;
            DigitMaxValue=FINAL_ERR_DSP_MESSAGE_CNT;
            DigitMinValue=0;
            DigitData=0;
            Integer_Digit();
			break;
		case    SENSOR_POSITION:
            Cursor=0;
            ShiftCnt=0;
            EditBlanck=0;
            EditStatus=DIGIT_STRING_EDIT;
            DigitMaxValue=SENSOR_POSITION_MESSAGE_CNT;
            DigitMinValue=0;
            DigitData=0;
            Integer_Digit();
			break;
		case    ENCODER_RATE: 
            Cursor=0;
            ShiftCnt=5;
            EditBlanck=5;
            EditStatus=DIGIT_EDIT;
            DigitMaxValue=65535;
            DigitMinValue=0;

            i=F_StopPulse0;
            DigitData=iF_FLRDSPCH((unsigned long)i);
            Integer_Digit();
           break;
        default:
            break;
    }
}



void  __attribute__((section(".usercode"))) UserGroupSave(void)
{
    LocalType i,j,k,l;
	LocalType block_pt,tmp_new_law,tmp_new_spd,tmp_old_spd;

    GetFlashDataToBufRam(F_BLOCK2);

    switch(LadderGroupSub){
        case    VERSION:
        case    TOTAL_USE_TIME:
            break;
        case    BOARD_ID:
            if((DigitData==0) || (DigitData==3)|| (DigitData==6) ){
                b_LdTmpBufRam(F_ManualSpeed)    = P1_SPD;      
                b_LdTmpBufRam(F_DecreaseSpeed)  = P1P2_SPD;     
                b_LdTmpBufRam(F_FhmSpeed)       = P4_SPD;                     
                b_LdTmpBufRam(F_Speed60)        = P3_SPD;     
                b_LdTmpBufRam(F_ElevSpeed)      = SPEED_60;                                    
            }

            if(DigitData==0){
                DigitData=(LG | MAN_USE);
            }
            else if(DigitData==1){
                DigitData=(IO | MAN_USE);
            }
            else if(DigitData==2){
                DigitData=(D_F | MAN_USE);
            }
            else if(DigitData==3){
                DigitData=(LG | BAGGAGE_USE);
            }
            else if(DigitData==4){
                DigitData=(IO | BAGGAGE_USE);
            }
            else if(DigitData==5){
                DigitData=(D_F | BAGGAGE_USE);
            }
            else if(DigitData==6){
                DigitData=(LG | CARLIFT_USE);
            }
            else if(DigitData==7){
                DigitData=(IO | CARLIFT_USE);
            }
            else if(DigitData==8){
                DigitData=(D_F | CARLIFT_USE);
            }

            i=F_Bd_Id;
            b_LdTmpBufRam(i)=(LocalType)(DigitData);

            flash_write_DspChar(F_BLOCK2);                        
            break;
        case    ALL_MENU_CHK:
            if(bCompanyCtl==0){	
                i=((sRamDArry[Month] >> 4) & 0x000f) * 1000;
                j=(sRamDArry[Month] & 0x000f) * 100;
                i=(i+j);
                j=((sRamDArry[Day] >> 4) & 0x000f) * 10;
                i=(i+j);
                j=(sRamDArry[Day] & 0x000f);
                i=(i+j);
                j=1014;
                i=i+j;
                if(i>=10000)    i=i-10000;

                
                k=((New485Ladder[SECONDLINE_BASE+EditBlanck+0] - '0') * 1000);
                j=((New485Ladder[SECONDLINE_BASE+EditBlanck+1] - '0') * 100);
                k=(j+k);
                j=((New485Ladder[SECONDLINE_BASE+EditBlanck+2] - '0') * 10);
                k=(j+k);
                j=(New485Ladder[SECONDLINE_BASE+EditBlanck+3] - '0');
                k=(j+k);

                if(i==k){
					bCompanyCtl=1;
                    LadderGroup=0;
                    LadderGroupSub=0;
               } 
            }
            break;
        case    ENGINEER_NM:
             if(   ('1'== New485Ladder[SECONDLINE_BASE+EditBlanck+0]) 
                && ('2'== New485Ladder[SECONDLINE_BASE+EditBlanck+1]) 
                && ('3'== New485Ladder[SECONDLINE_BASE+EditBlanck+2]) 
                && ('4'== New485Ladder[SECONDLINE_BASE+EditBlanck+3])){

                 bUserOn=1;
                 LadderGroup=0;
                 LadderGroupSub=0;
            } 
            break;
        case    PASSWARD:
			PassWardKeyBuf[0]=New485Ladder[SECONDLINE_BASE+EditBlanck+0];
			PassWardKeyBuf[1]=New485Ladder[SECONDLINE_BASE+EditBlanck+1];
			PassWardKeyBuf[2]=New485Ladder[SECONDLINE_BASE+EditBlanck+2];
			PassWardKeyBuf[3]=New485Ladder[SECONDLINE_BASE+EditBlanck+3];

			if( (PassWardKeyBuf[0] != '*') && (PassWardKeyBuf[1] != '*') && (PassWardKeyBuf[2] != '*') && (PassWardKeyBuf[3] != '*')){ 
	            if(bPasswardOk){
	                i=F_Passward0;    
	                b_LdTmpBufRam((unsigned long)(i+0))=(LocalType)(PassWardKeyBuf[0]);
	                b_LdTmpBufRam((unsigned long)(i+1))=(LocalType)(PassWardKeyBuf[1]);
	                b_LdTmpBufRam((unsigned long)(i+2))=(LocalType)(PassWardKeyBuf[2]);
	                b_LdTmpBufRam((unsigned long)(i+3))=(LocalType)(PassWardKeyBuf[3]);
	                flash_write_DspChar(F_BLOCK2);
				}
	
				PasswardCheck();
				if(bPasswardOk){
	                LadderGroup=0;
	                LadderGroupSub=0;
				}
			}


/*
            if(bPasswardOk==0){
                if(   (pw[0]== New485Ladder[SECONDLINE_BASE+EditBlanck+0]) 
                   && (pw[1]== New485Ladder[SECONDLINE_BASE+EditBlanck+1]) 
                   && (pw[2]== New485Ladder[SECONDLINE_BASE+EditBlanck+2]) 
                   && (pw[3]== New485Ladder[SECONDLINE_BASE+EditBlanck+3])){

                    bPasswardOk=1;
                    LadderGroup=0;
                    LadderGroupSub=0;					
               } 
            }
            else{
                i=F_Passward0;
    
                b_LdTmpBufRam((unsigned long)(i+0))=(LocalType)(New485Ladder[SECONDLINE_BASE+EditBlanck+0]);
                b_LdTmpBufRam((unsigned long)(i+1))=(LocalType)(New485Ladder[SECONDLINE_BASE+EditBlanck+1]);
                b_LdTmpBufRam((unsigned long)(i+2))=(LocalType)(New485Ladder[SECONDLINE_BASE+EditBlanck+2]);
                b_LdTmpBufRam((unsigned long)(i+3))=(LocalType)(New485Ladder[SECONDLINE_BASE+EditBlanck+3]);
    
                flash_write_DspChar(F_BLOCK2);

				PasswardCheck();
                LadderGroup=0;
                LadderGroupSub=0;
            }
*/



            break;
        case    SERIAL_NM:
            i=F_SerialNm10;
            i_LdTmpBufRam((unsigned long)i)=(LocalType)(DigitData);
            flash_write_DspChar(F_BLOCK2);
            break;
        case    USER_LAMP1:
        case    USER_LAMP2:
        case    USER_LAMP3:
        case    USER_LAMP4:
        case    GROUP_NUMBER:
        case    LOCAL_NUMBER:
			if(LadderGroupSub == USER_LAMP1)		i=F_UserLamp1;
			else if(LadderGroupSub == USER_LAMP2)	i=F_UserLamp2;
			else if(LadderGroupSub == USER_LAMP3)	i=F_UserLamp3;
			else if(LadderGroupSub == USER_LAMP4)	i=F_UserLamp4;
			else if(LadderGroupSub == LOCAL_NUMBER)	i=F_LocalNm;
			else									i=F_GroupNm;
            b_LdTmpBufRam((unsigned long)i)=(LocalType)(DigitData);
            flash_write_DspChar(F_BLOCK2);
            break;
/*
        case    USER_LAMP2:
           i=F_UserLamp2;
           b_LdTmpBufRam((unsigned long)i)=(LocalType)(DigitData);
           flash_write_DspChar(F_BLOCK2);
            break;
        case    GROUP_NUMBER:
            i=F_GroupNm;
            b_LdTmpBufRam((unsigned long)i)=(LocalType)(DigitData);
            flash_write_DspChar(F_BLOCK2);
            break;
        case    LOCAL_NUMBER:
            i=F_LocalNm;
            b_LdTmpBufRam((unsigned long)i)=(LocalType)(DigitData);
            flash_write_DspChar(F_BLOCK2);
            break;
*/
        case    LG_INV_IN_BD:
            i=F_PcbType;
            b_LdTmpBufRam((unsigned long)i)=(LocalType)(DigitData);
            flash_write_DspChar(F_BLOCK2);
            break;
        case    ERR_ST_CNT:
            i=F_ErrStopCnt;
            b_LdTmpBufRam((unsigned long)i)=(LocalType)(DigitData);
            flash_write_DspChar(F_BLOCK2);
            break;
        case    SYSTEM_SET:
			if(New_Law_SystemChk())	tmp_new_law=1;
			else					tmp_new_law=0;

			if(New_Spd_SystemChk())	tmp_new_spd=1;
			else					tmp_new_spd=0;

			if(Old_Spd_SystemChk())	tmp_old_spd=1;
			else					tmp_old_spd=0;


            i=F_SystemSet;
            b_LdTmpBufRam((unsigned long)i)=(LocalType)(DigitData);
            flash_write_DspChar(F_BLOCK2);


			//////////////////////////BLOCK1//////////////////////////
			if( (New_Law_SystemChk()) && (tmp_new_law==0)){
    			GetFlashDataToBufRam(F_BLOCK1);
		        bit_LdTmpBufRamSet(F_OnOff0,bDoorJumperOff    		% 8); 
		        bit_LdTmpBufRamSet(F_OnOff1,bBrkMgtUse        		% 8);
		        bit_LdTmpBufRamSet(F_OnOff2,bBrkOpenUse       		% 8);
            	flash_write_DspChar(F_BLOCK1);				
			}
			//////////////////////////BLOCK1//////////////////////////

			if( (New_Spd_SystemChk()) && (tmp_new_spd==0)){
    			GetFlashDataToBufRam(F_BLOCK2);
		        b_LdTmpBufRam(F_ManualSpeed)    = P3_SPD;                   
		        b_LdTmpBufRam(F_BatterySpeed)   = NONE_USE_SPD;      
		        b_LdTmpBufRam(F_DecreaseSpeed)  = P1P2_SPD;                    
		        b_LdTmpBufRam(F_FhmSpeed)       = NONE_USE_SPD;     
		        b_LdTmpBufRam(F_Speed1)        	= P1P3_SPD;     
		        b_LdTmpBufRam(F_Speed2)        	= P2P3_SPD;              
		        b_LdTmpBufRam(F_Speed3)        	= P1P2P3_SPD;                    
		        b_LdTmpBufRam(F_LULD_MPM_SPD3)  = 0;     
		        b_LdTmpBufRam(F_SU2SD2_V_SPD3)	= 0;    
		        b_LdTmpBufRam(F_X0X1_V_SPD3)  	= 0;   
            	flash_write_DspChar(F_BLOCK2);

		        DefaultDecreaseLength_spd3();
		        CaluDecreasePulse();
			}
			else if( (Old_Spd_SystemChk()) && (tmp_old_spd==0)){
    			GetFlashDataToBufRam(F_BLOCK2);
		        b_LdTmpBufRam(F_ManualSpeed)    = P3_SPD;          
		        b_LdTmpBufRam(F_BatterySpeed)   = NONE_USE_SPD;      
		        b_LdTmpBufRam(F_DecreaseSpeed)  = P1P2_SPD;                    
		        b_LdTmpBufRam(F_FhmSpeed)       = NONE_USE_SPD;     
		        b_LdTmpBufRam(F_Etc1Speed)      = NONE_USE_SPD;     
		        b_LdTmpBufRam(F_Etc2Speed)      = NONE_USE_SPD;     
		        b_LdTmpBufRam(F_Speed30)        = NONE_USE_SPD;     
		        b_LdTmpBufRam(F_Speed45)        = NONE_USE_SPD;              
		        b_LdTmpBufRam(F_Speed60)        = NONE_USE_SPD;                    
		        b_LdTmpBufRam(F_Speed90)        = NONE_USE_SPD;     
		        b_LdTmpBufRam(F_Speed105)       = NONE_USE_SPD;     
		        b_LdTmpBufRam(F_Speed120)       = NONE_USE_SPD;     
		        b_LdTmpBufRam(F_Speed150)       = NONE_USE_SPD;     
		        b_LdTmpBufRam(F_Speed180)       = NONE_USE_SPD;     
		        b_LdTmpBufRam(F_Speed210)       = NONE_USE_SPD;    
		        b_LdTmpBufRam(F_ElevSpeed)      = SPEED_60;
		        b_LdTmpBufRam(F_LimitSpeed)     = SPEED_210;
		        b_LdTmpBufRam(F_Su1Sd1_Velocity)= 90;      //mpm
		        b_LdTmpBufRam(F_Su2Sd2_Velocity)= 90;      //mpm
		        b_LdTmpBufRam(F_X0X1_Velocity)  = 210;     //mpm
				
				if(GET_LONG(MPM) == 30){
					b_LdTmpBufRam(F_Speed30)        = P1P2P3_SPD;

		        	b_LdTmpBufRam(F_ElevSpeed)      = SPEED_30;
				}
				else if(GET_LONG(MPM) == 45){
					b_LdTmpBufRam(F_Speed45)        = P1P2P3_SPD;
					b_LdTmpBufRam(F_Speed30)        = P2P3_SPD;

		        	b_LdTmpBufRam(F_ElevSpeed)      = SPEED_45;
				}      
				else if(GET_LONG(MPM) == 60){
					b_LdTmpBufRam(F_Speed60)        = P1P2P3_SPD;
					b_LdTmpBufRam(F_Speed45)        = P2P3_SPD;
					b_LdTmpBufRam(F_Speed30)        = P1P3_SPD;

		        	b_LdTmpBufRam(F_ElevSpeed)      = SPEED_60;
				}      
				else if(GET_LONG(MPM) == 90){
					b_LdTmpBufRam(F_Speed90)        = P1P2P3_SPD;
					b_LdTmpBufRam(F_Speed60)        = P2P3_SPD;
					b_LdTmpBufRam(F_Speed45)        = P1P3_SPD;

		        	b_LdTmpBufRam(F_ElevSpeed)      = SPEED_90;
				}      
				else if(GET_LONG(MPM) == 105){
					b_LdTmpBufRam(F_Speed105)       = P1P2P3_SPD;
					b_LdTmpBufRam(F_Speed60)        = P2P3_SPD;
					b_LdTmpBufRam(F_Speed45)        = P1P3_SPD;

		        	b_LdTmpBufRam(F_ElevSpeed)      = SPEED_105;
				}      
				else if(GET_LONG(MPM) == 120){
					b_LdTmpBufRam(F_Speed120)       = P1P2P3_SPD;
					b_LdTmpBufRam(F_Speed60)        = P2P3_SPD;
					b_LdTmpBufRam(F_Speed45)        = P1P3_SPD;

		        	b_LdTmpBufRam(F_ElevSpeed)      = SPEED_120;
				}      
				else if(GET_LONG(MPM) == 150){
					b_LdTmpBufRam(F_Speed150)       = P1P2P3_SPD;
					b_LdTmpBufRam(F_Speed60)        = P2P3_SPD;
					b_LdTmpBufRam(F_Speed45)        = P1P3_SPD;

		        	b_LdTmpBufRam(F_ElevSpeed)      = SPEED_150;
				}      
				else if(GET_LONG(MPM) == 180){
					b_LdTmpBufRam(F_Speed180)       = P1P2P3_SPD;
					b_LdTmpBufRam(F_Speed60)        = P2P3_SPD;
					b_LdTmpBufRam(F_Speed45)        = P1P3_SPD;

		        	b_LdTmpBufRam(F_ElevSpeed)      = SPEED_180;
				}      


				flash_write_DspChar(F_BLOCK2);


		        DefaultDecreaseLength_old();
		        CaluDecreasePulse();
			}
	
            break;
        case    NORMAL_DSP:
            i=F_NormalDsp;
            b_LdTmpBufRam((unsigned long)i)=(LocalType)(DigitData);
            flash_write_DspChar(F_BLOCK2);
            break;
        case    COMPANY_NAME:
            i=F_Company;
            b_LdTmpBufRam((unsigned long)i)=(LocalType)(New485Ladder[SECONDLINE_BASE+EditBlanck+0]);
            flash_write_DspChar(F_BLOCK2);
            break;
        case    VIRTUAL_CALL:
			i=New485Ladder[SECONDLINE_BASE+EditBlanck+0];
			i=((i - '0') * 100);
			j=New485Ladder[SECONDLINE_BASE+EditBlanck+1];
			j=((j-'0') * 10);
			k=New485Ladder[SECONDLINE_BASE+EditBlanck+2];
			k=(k -'0');

			i = (i + j + k);
			if(i <= 254)	sRamDArry[mVFlrCnt]=i;	


//////////////////////////////////////////////////////////
			i=New485Ladder[SECONDLINE_BASE+EditBlanck+4];
			i=((i - '0') * 10);
			j=New485Ladder[SECONDLINE_BASE+EditBlanck+5];
			j=(j-'0');
			i=(i+j);

			if(i <= (cF_TOPFLR+1))	sRamDArry[mVFlr1]=i;	
			else					sRamDArry[mVFlr1]=0;	
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
			i=New485Ladder[SECONDLINE_BASE+EditBlanck+7];
			i=((i - '0') * 10);
			j=New485Ladder[SECONDLINE_BASE+EditBlanck+8];
			j=(j-'0');
			i=(i+j);

			if(i <= (cF_TOPFLR+1))	sRamDArry[mVFlr2]=i;	
			else					sRamDArry[mVFlr2]=0;	
//////////////////////////////////////////////////////////



/*
			i=New485Ladder[SECONDLINE_BASE+EditBlanck+0];
			i=((i - '0') * 10);
			j=New485Ladder[SECONDLINE_BASE+EditBlanck+1];
			j=(j-'0');
			i=(i+j);

			if(i < 100)	sRamDArry[mVFlrCnt]=i;	
//////////////////////////////////////////////////////////
			i=New485Ladder[SECONDLINE_BASE+EditBlanck+3];
			i=((i - '0') * 10);
			j=New485Ladder[SECONDLINE_BASE+EditBlanck+4];
			j=(j-'0');
			i=(i+j);

			if(i <= (cF_TOPFLR+1))	sRamDArry[mVFlr1]=i;	
			else					sRamDArry[mVFlr1]=0;	
//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
			i=New485Ladder[SECONDLINE_BASE+EditBlanck+6];
			i=((i - '0') * 10);
			j=New485Ladder[SECONDLINE_BASE+EditBlanck+7];
			j=(j-'0');
			i=(i+j);

			if(i <= (cF_TOPFLR+1))	sRamDArry[mVFlr2]=i;	
			else					sRamDArry[mVFlr2]=0;	
//////////////////////////////////////////////////////////
*/
            break;
        case    HH_MM_SS:
                DigitData=(New485Ladder[SECONDLINE_BASE+EditBlanck+0]-'0') << 4;
                sRamDArry[Hour]=DigitData  | (New485Ladder[SECONDLINE_BASE+EditBlanck+1]-'0');
    
                DigitData=(New485Ladder[SECONDLINE_BASE+EditBlanck+3]-'0') << 4;
                sRamDArry[Minuate]=DigitData | (New485Ladder[SECONDLINE_BASE+EditBlanck+4]-'0');
    
                DigitData=(New485Ladder[SECONDLINE_BASE+EditBlanck+6]-'0') << 4;
                sRamDArry[sec]=DigitData | (New485Ladder[SECONDLINE_BASE+EditBlanck+7]-'0');
    
                Initialize_DS1302();
            break;
        case    YY_MM_DD:
                DigitData=(New485Ladder[SECONDLINE_BASE+EditBlanck+0]-'0') << 4;
                sRamDArry[Year]=DigitData | (New485Ladder[SECONDLINE_BASE+EditBlanck+1]-'0');
    
                DigitData=(New485Ladder[SECONDLINE_BASE+EditBlanck+3]-'0') << 4;
                sRamDArry[Month]=DigitData | (New485Ladder[SECONDLINE_BASE+EditBlanck+4]-'0');
    
                DigitData=(New485Ladder[SECONDLINE_BASE+EditBlanck+6]-'0') << 4;
                sRamDArry[Day]=DigitData | (New485Ladder[SECONDLINE_BASE+EditBlanck+7]-'0');
    
                Initialize_DS1302();
            break;
        case    OUT_DATE:
                DigitData=(New485Ladder[SECONDLINE_BASE+EditBlanck+0]-'0') << 4;
                b_LdTmpBufRam(F_year)=DigitData | (New485Ladder[SECONDLINE_BASE+EditBlanck+1]-'0');
    
                DigitData=(New485Ladder[SECONDLINE_BASE+EditBlanck+3]-'0') << 4;
                b_LdTmpBufRam(F_month)=DigitData | (New485Ladder[SECONDLINE_BASE+EditBlanck+4]-'0');
    
                DigitData=(New485Ladder[SECONDLINE_BASE+EditBlanck+6]-'0') << 4;
                b_LdTmpBufRam(F_day)=DigitData | (New485Ladder[SECONDLINE_BASE+EditBlanck+7]-'0');

	            flash_write_DspChar(F_BLOCK2);
            break;
        case    DRIVE_METHOD:
//#ifdef	FLOOR_64
			block_pt=(F_NonService0/64);
			block_pt=(block_pt * 64);

            GetFlashDataToBufRam(block_pt);
            i=F_NonService0;

            if(DigitData==1)		DigitData=0x55;  //礎熱
            else if(DigitData==2)	DigitData=0xaa;	 //�汝�	
            else if(DigitData==0)	DigitData=0xff;  //瞪類 
			
            b_LdTmpBufRam((unsigned long)(i+0))=(LocalType)(DigitData);
            b_LdTmpBufRam((unsigned long)(i+1))=(LocalType)(DigitData);
            b_LdTmpBufRam((unsigned long)(i+2))=(LocalType)(DigitData);
            b_LdTmpBufRam((unsigned long)(i+3))=(LocalType)(DigitData);        
            b_LdTmpBufRam((unsigned long)(i+4))=(LocalType)(DigitData);
            b_LdTmpBufRam((unsigned long)(i+5))=(LocalType)(DigitData);
            b_LdTmpBufRam((unsigned long)(i+6))=(LocalType)(DigitData);
            b_LdTmpBufRam((unsigned long)(i+7))=(LocalType)(DigitData);        
        
            flash_write_DspChar(block_pt);

			ShadowsRamDArry[FLR_ON_OFF0]=cF_NONSERVICE0;
			ShadowsRamDArry[FLR_ON_OFF1]=cF_NONSERVICE1;
			ShadowsRamDArry[FLR_ON_OFF2]=cF_NONSERVICE2;
			ShadowsRamDArry[FLR_ON_OFF3]=cF_NONSERVICE3;
			ShadowsRamDArry[FLR_ON_OFF4]=cF_NONSERVICE4;
			ShadowsRamDArry[FLR_ON_OFF5]=cF_NONSERVICE5;
			ShadowsRamDArry[FLR_ON_OFF6]=cF_NONSERVICE6;
			ShadowsRamDArry[FLR_ON_OFF7]=cF_NONSERVICE7;
            break;
        case    FHM_RUN_CHK:
            if(DigitData==1){
				sRamDArry[FHM_SEQ]=FHM_SEQ_0;
				LadderKey = 0xff;
			}
			else		sRamDArry[FHM_SEQ]=FHM_SEQ_8;

            LadderGroup=0;
            LadderGroupSub=0;
            break;
        case    INIT_DATA:
            switch(DigitData){
                case    1:
					bSaveFlash=1;
					MoveCounterx=0;
                    break;
                case    2:
					if(!bMoveCar){
						for(i=0;i<E_END;i++){
							eDArry[i]=0;
						}
						sRamDArry[mBefErrCntPt]=0xff;
						bSaveFlash=1;

					
/*
	               	    for(i=0;i<ERR_SAVE_SIZE;){
							eDArry[eErrCntPt]=EEPROM_Read_Byte(eErrCntPt);
							if(eDArry[eErrCntPt] > 0){	
			        			EEPROM_Write_Byte((unsigned int)(eErrCntPt),0);
							}            
	
							if(!EEPROM_write_Ready()){
		                  	    eDArry[eSysErCnt+i]=0x0;         
		                        if( !EEPROM_Write_Byte(eSysErCnt+i,0x0)){
									i++;
								}
							}
	               	    }
	
	            	    sRamDArry[mBefErrCntPt]=0x0;
	                    eDArry[eErrCntPt]=0x0;
	                    bSaveErrCnt=0;
*/
					}
                    break;
                case    3:
					bExportData=1;
					SrcAdrBlk=0;
					LoaderChk=0;
                    break;
                case    4:
					bImportData=1;
					SrcAdrBlk=0;
					LoaderChk=0;
                    break;
            }
            break;
        case    ENCODER_RATE:
            i=F_StopPulse0;
            i_LdTmpBufRam((unsigned long)i)=(LocalType)(DigitData);
            flash_write_DspChar(F_BLOCK2);
            break;
        case    HALL_IND_SET:
            HibSet[0]=(New485Ladder[SECONDLINE_BASE+EditBlanck+0] 	- '0');
            HibSet[1]=(New485Ladder[SECONDLINE_BASE+EditBlanck+2] 	- '0');
            HibSet[2]=(New485Ladder[SECONDLINE_BASE+EditBlanck+4] 	- '0');
            HibSet[3]=(New485Ladder[SECONDLINE_BASE+EditBlanck+6] 	- '0');
            HibSet[4]=(New485Ladder[SECONDLINE_BASE+EditBlanck+8] 	- '0');
            HibSet[5]=(New485Ladder[SECONDLINE_BASE+EditBlanck+10] 	- '0');

			if((sRamDArry[DSP1]  == '9') &&  (sRamDArry[DSP2]  == '1')){
				if(HibSet[0] > 9)	HibSet[0]=0;
				if(HibSet[1] > 9)	HibSet[1]=0;
				if(HibSet[2] > 9)	HibSet[2]=0;
				if(HibSet[3] > 9)	HibSet[3]=0;
				if(HibSet[4] > 9)	HibSet[4]=0;
				if(HibSet[5] > 9)	HibSet[5]=0;
				bHibSet=1;
			}	
			break;
        default:
            break;

    }
}





void  __attribute__((section(".usercode"))) ELGroup(void)
{
	unsigned long	tmpPlulsex;

    switch(LadderGroupSub){
///////////////////////////////////////////////
/////////////long type data////////////////////
///////////////////////////////////////////////
        case    SUBNM_ENCODER_PULSE:
		    Cursor=0;
		    ShiftCnt=5;
		    EditBlanck=5;
		    EditStatus=DIGIT_EDIT;		
		    DigitMaxValue=0xffff;
		    DigitMinValue=0;
		    DigitData=(unsigned int)(GET_LONG((unsigned long)ENCODER_PULSE));    
		    Integer_Digit();
            break;
        case    SUBNM_TM_MPM:
		    Cursor=0;
		    ShiftCnt=3;
		    EditBlanck=5;
		    EditStatus=DIGIT_EDIT;		
		    DigitMaxValue=211;
		    DigitMinValue=0;
		    DigitData=(unsigned int)(GET_LONG((unsigned long)MPM));    
		    Integer_Digit();
            break;
        case    SUBNM_MOTOR_RPM:
		    Cursor=0;
		    ShiftCnt=5;
		    EditBlanck=5;
		    EditStatus=DIGIT_EDIT;		
		    DigitMaxValue=0xffff;
		    DigitMinValue=0;
		    DigitData=(unsigned int)(GET_LONG((unsigned long)RPM));    
		    Integer_Digit();
            break;

///////////////////////////////////////////////
/////////////char type data////////////////////
///////////////////////////////////////////////
        case    SUBNM_MANUAL_PORT:
	    	Cursor=0;
	        ShiftCnt=0;
	    	EditBlanck=5;
	        EditStatus=DIGIT_STRING_EDIT;   
	    	DigitMinValue=0;
			DigitMaxValue=IO_PORT_MESSAGE_CNT-1;
	        DigitData=cF_FLRDSPCH((unsigned long)F_ManualSpeed);
	        Integer_Digit();
            break;
        case    SUBNM_BATTERY_PORT:
	    	Cursor=0;
	        ShiftCnt=0;
	    	EditBlanck=5;
	        EditStatus=DIGIT_STRING_EDIT;   
	    	DigitMinValue=0;
			DigitMaxValue=IO_PORT_MESSAGE_CNT-1;
	        DigitData=cF_FLRDSPCH((unsigned long)F_BatterySpeed);
	        Integer_Digit();
            break;
        case    SUBNM_DEC_PORT:
	    	Cursor=0;
	        ShiftCnt=0;
	    	EditBlanck=5;
	        EditStatus=DIGIT_STRING_EDIT;   
	    	DigitMinValue=0;
			DigitMaxValue=IO_PORT_MESSAGE_CNT-1;
	        DigitData=cF_FLRDSPCH((unsigned long)F_DecreaseSpeed);
	        Integer_Digit();
            break;
        case    SUBNM_FHM_PORT:
	    	Cursor=0;
	        ShiftCnt=0;
	    	EditBlanck=5;
	        EditStatus=DIGIT_STRING_EDIT;   
	    	DigitMinValue=0;
			DigitMaxValue=IO_PORT_MESSAGE_CNT-1;
	        DigitData=cF_FLRDSPCH((unsigned long)F_FhmSpeed);
	        Integer_Digit();
            break;
        case    SUBNM_LOW_SPD_PORT:
	    	Cursor=0;
	        ShiftCnt=0;
	    	EditBlanck=5;
	        EditStatus=DIGIT_STRING_EDIT;   
	    	DigitMinValue=0;
			DigitMaxValue=IO_PORT_MESSAGE_CNT-1;
	        DigitData=cF_FLRDSPCH((unsigned long)F_Speed1);
	        Integer_Digit();
            break;
        case    SUBNM_MID_SPD_PORT:
	    	Cursor=0;
	        ShiftCnt=0;
	    	EditBlanck=5;
	        EditStatus=DIGIT_STRING_EDIT;   
	    	DigitMinValue=0;
			DigitMaxValue=IO_PORT_MESSAGE_CNT-1;
	        DigitData=cF_FLRDSPCH((unsigned long)F_Speed2);
	        Integer_Digit();
            break;
        case    SUBNM_HIGH_SPD_PORT:
	    	Cursor=0;
	        ShiftCnt=0;
	    	EditBlanck=5;
	        EditStatus=DIGIT_STRING_EDIT;   
	    	DigitMinValue=0;
			DigitMaxValue=IO_PORT_MESSAGE_CNT-1;
	        DigitData=cF_FLRDSPCH((unsigned long)F_Speed3);
	        Integer_Digit();
            break;
        case    SUBNM_LOW_SPD_DEC_LENTH:
		    Cursor=0;
		    ShiftCnt=5;
		    EditBlanck=5;
		    EditStatus=DIGIT_EDIT;		
		    DigitMaxValue=0xffff;
		    DigitMinValue=0;
		    DigitData=(unsigned int)(GET_LONG((unsigned long)DEC_LENGTH_SPD_LOW));    
		    Integer_Digit();
            break;
        case    SUBNM_MID_SPD_DEC_LENTH:
		    Cursor=0;
		    ShiftCnt=5;
		    EditBlanck=5;
		    EditStatus=DIGIT_EDIT;		
		    DigitMaxValue=0xffff;
		    DigitMinValue=0;
		    DigitData=(unsigned int)(GET_LONG((unsigned long)DEC_LENGTH_SPD_MID));    
		    Integer_Digit();
            break;
        case    SUBNM_HIGH_SPD_DEC_LENTH:
		    Cursor=0;
		    ShiftCnt=5;
		    EditBlanck=5;
		    EditStatus=DIGIT_EDIT;		
		    DigitMaxValue=0xffff;
		    DigitMinValue=0;
		    DigitData=(unsigned int)(GET_LONG((unsigned long)DEC_LENGTH_SPD_HIGH));    
		    Integer_Digit();
            break;
        case    SUBNM_BASE_DEC_LENTH:
		    Cursor=0;
		    ShiftCnt=5;
		    EditBlanck=5;
		    EditStatus=DIGIT_EDIT;		
		    DigitMaxValue=0xffff;
		    DigitMinValue=0;
		    DigitData=(unsigned int)(GET_LONG((unsigned long)BASE_DEC_LENGTH));    
		    Integer_Digit();
            break;
        case    SUBNM_BASE_DEC_TIME:
		    Cursor=0;
		    ShiftCnt=5;
		    EditBlanck=5;
		    EditStatus=DIGIT_EDIT;		
		    DigitMaxValue=0xffff;
		    DigitMinValue=0;
		    DigitData=(unsigned int)(GET_LONG((unsigned long)BASE_DEC_TIME));    
		    Integer_Digit();
            break;
        case    SUBNM_BASE_SCURVE_TIME:
		    Cursor=0;
		    ShiftCnt=5;
		    EditBlanck=5;
		    EditStatus=DIGIT_EDIT;		
		    DigitMaxValue=0xffff;
		    DigitMinValue=0;
		    DigitData=(unsigned int)(GET_LONG((unsigned long)BASE_SCURVE_TIME));    
		    Integer_Digit();
            break;
        case    SUBNM_SU2SD2_SPD:
	    	Cursor=0;
	        ShiftCnt=0;
	    	EditBlanck=5;
	        EditStatus=DIGIT_STRING_EDIT;   
	    	DigitMinValue=0;
			DigitMaxValue=ELEV_SPEED_MESSAGE_CNT_SPD3;
	        DigitData=cF_FLRDSPCH((unsigned long)F_Su2Sd2_Velocity);
	        Integer_Digit();
            break;
        case    SUBNM_X0X1_SPD:
	    	Cursor=0;
	        ShiftCnt=0;
	    	EditBlanck=5;
	        EditStatus=DIGIT_STRING_EDIT;   
	    	DigitMinValue=0;
			DigitMaxValue=ELEV_SPEED_MESSAGE_CNT_SPD3;
	        DigitData=cF_FLRDSPCH((unsigned long)F_X0X1_Velocity);
	        Integer_Digit();
            break;
        case    SUBNM_LULD_MPM:
		    Cursor=0;
		    ShiftCnt=3;
		    EditBlanck=5;
		    EditStatus=DIGIT_EDIT;		
		    DigitMaxValue=255;
		    DigitMinValue=0;
	        DigitData=cF_FLRDSPCH((unsigned long)F_LULD_MPM_SPD3);
		    Integer_Digit();
            break;
        case    SUBNM_AUTO_LANDING:
            Cursor=0;
            ShiftCnt=0;
            EditBlanck=5;
            EditStatus=DIGIT_STRING_EDIT;
            DigitMaxValue=AUTO_LANDING_MESSAGE_CNT;
            DigitMinValue=0;
	        DigitData=cF_FLRDSPCH((unsigned long)F_AutoLandingMode);
            Integer_Digit();
			break;				

////////////////
///////////////////////////////
/////////////bit type data////////////////////
///////////////////////////////////////////////
        case    SUBNM_AUTO_TUN:
            DigitMaxValue=3;

/*
			#ifdef	DELTA_INVERTER
            	DigitMaxValue=3;
			#else
            	DigitMaxValue=2;
			#endif
*/
            Cursor=0;
            ShiftCnt=0;
            EditBlanck=3;
            EditStatus=DIGIT_STRING_EDIT;
            DigitMinValue=0;			
			DigitData=0;
			AutotunUpDn=0;
			sRamDArry[AUTO_TUNING]=AUTOTUN_SEQ_0;
            Integer_Digit();
			break;
        case    SUBNM_FHM:
            Cursor=0;
            ShiftCnt=0;
            EditBlanck=5;
            EditStatus=DIGIT_STRING_EDIT;
            DigitMaxValue=2;
            DigitMinValue=0;
			DigitData=0;	
            Integer_Digit();
			break;		
///////////////////////////////////////////////
/////////////long type data////////////////////
///////////////////////////////////////////////
        case    SUBNM_LOW_SPD_PULSE:
		    Cursor=0;
		    ShiftCnt=0;
		    EditBlanck=3;
		    EditStatus=NO_EDIT;		
		    DigitMaxValue=0xffff;
		    DigitMinValue=0;
    		tmpPlulsex=(GET_LONG((unsigned long)DEC_PULSE_SPD_LOW));    
			CurEncoderPulse(tmpPlulsex);
            break;
        case    SUBNM_MID_SPD_PULSE:
		    Cursor=0;
		    ShiftCnt=0;
		    EditBlanck=3;
		    EditStatus=NO_EDIT;		
		    DigitMaxValue=0xffff;
		    DigitMinValue=0;
    		tmpPlulsex=(GET_LONG((unsigned long)DEC_PULSE_SPD_MID));    
			CurEncoderPulse(tmpPlulsex);
            break;
        case    SUBNM_HIGH_SPD_PULSE:
		    Cursor=0;
		    ShiftCnt=0;
		    EditBlanck=3;
		    EditStatus=NO_EDIT;		
		    DigitMaxValue=0xffff;
		    DigitMinValue=0;
    		tmpPlulsex=(GET_LONG((unsigned long)DEC_PULSE_SPD_HIGH));    
			CurEncoderPulse(tmpPlulsex);
            break;
        case    SUBNM_BASE_PULSE:
		    Cursor=0;
		    ShiftCnt=0;
		    EditBlanck=3;
		    EditStatus=NO_EDIT;		
		    DigitMaxValue=0xffff;
		    DigitMinValue=0;

			if(DaesungAutoLandingModeChk((unsigned char)DS_AUTOLANDING)==1){		
	    		tmpPlulsex=(GET_LONG((unsigned long)BASE_DEC_PULSE));    
			}
			else{
	    		tmpPlulsex=BaseDecPulseX;    
			}

			CurEncoderPulse(tmpPlulsex);
            break;
        case    SUBNM_MPM_VARIABLE:
		    Cursor=0;
		    ShiftCnt=5;
		    EditBlanck=5;
		    EditStatus=NO_EDIT;		
		    DigitMaxValue=0xffff;
		    DigitMinValue=0;
		    DigitData=(unsigned int)(GET_LONG((unsigned long)MPM_VARIABLE));    
		    Integer_Digit();
            break;
        case    SUBNM_MM_PER_PULSE:
		    Cursor=0;
		    ShiftCnt=5;
		    EditBlanck=5;
		    EditStatus=NO_EDIT;		
		    DigitMaxValue=0xffff;
		    DigitMinValue=0;
		    DigitData=(unsigned int)(GET_LONG((unsigned long)MM_PULSE));    
		    Integer_Digit();
            break;
        default:
            break;
    }
}



void  __attribute__((section(".usercode"))) ELGroupSave(void)
{

    LocalType  i,j,k;

	i=0xff;
	j=0xff;

    switch(LadderGroupSub){
        case    SUBNM_ENCODER_PULSE:
			j=( (ENCODER_PULSE) % (ENCODER_PULSE));
			break;
        case    SUBNM_TM_MPM:
			j=( (MPM) % (ENCODER_PULSE));
			break;
        case    SUBNM_MOTOR_RPM:
			j=( (RPM) % (ENCODER_PULSE));
			break;
        case    SUBNM_LOW_SPD_DEC_LENTH:
			j=( (DEC_LENGTH_SPD_LOW) % (ENCODER_PULSE) );
			break;
        case    SUBNM_MID_SPD_DEC_LENTH:
			j=( (DEC_LENGTH_SPD_MID) % (ENCODER_PULSE));
			break;
        case    SUBNM_HIGH_SPD_DEC_LENTH:
			j=( (DEC_LENGTH_SPD_HIGH) % (ENCODER_PULSE));
			break;
        case    SUBNM_BASE_DEC_LENTH:
			j=( (BASE_DEC_LENGTH) % (ENCODER_PULSE));
			break;
        case    SUBNM_BASE_DEC_TIME:
			j=( (BASE_DEC_TIME) % (ENCODER_PULSE));
			break;
        case    SUBNM_BASE_SCURVE_TIME:
			j=( (BASE_SCURVE_TIME) % (ENCODER_PULSE));
			break;
//////////////////////////////////////////////
        case    SUBNM_MANUAL_PORT:
			i=( (F_ManualSpeed) % (F_BLOCK2));
			break;
        case    SUBNM_BATTERY_PORT:
			i=((F_BatterySpeed) % (F_BLOCK2));
			break;
        case    SUBNM_DEC_PORT:
			i=( (F_DecreaseSpeed) % (F_BLOCK2));
			break;
        case    SUBNM_FHM_PORT:
			i=( (F_FhmSpeed) % (F_BLOCK2));
			break;

        case    SUBNM_LOW_SPD_PORT:
			i=( (F_Speed1) % (F_BLOCK2));
			break;
        case    SUBNM_MID_SPD_PORT:
			i=( (F_Speed2) % (F_BLOCK2));
			break;
        case    SUBNM_HIGH_SPD_PORT:
			i=( (F_Speed3) % (F_BLOCK2));
			break;
        case    SUBNM_SU2SD2_SPD:
			i=( (F_Su2Sd2_Velocity) % (F_BLOCK2));
			break;
        case    SUBNM_X0X1_SPD:
			i=( (F_X0X1_Velocity) % (F_BLOCK2));
			break;
        case    SUBNM_LULD_MPM:
			i=((F_LULD_MPM_SPD3) % (F_BLOCK2));
			break;
        case    SUBNM_AUTO_LANDING:
			i=((F_AutoLandingMode) % (F_BLOCK2));
			break;

////////////////////////////////
        case    SUBNM_AUTO_TUN:
            if((sRamDArry[AUTO_TUNING] == AUTOTUN_SEQ_0) && (DigitData > 0)){
                sRamDArry[AUTO_TUNING] = AUTOTUN_SEQ_1;
				AutotunUpDn=DigitData;
                LadderKey=0xff;
            }
            else{
				sRamDArry[AUTO_TUNING] = AUTOTUN_SEQ_0;
				AutotunUpDn=0;
            }

            LadderGroup=0;
            LadderGroupSub=0;
            break;
        case    SUBNM_FHM:
            if(DigitData==1){
				sRamDArry[FHM_SEQ]=FHM_SEQ_0;
				LadderKey = 0xff;
			}
			else				sRamDArry[FHM_SEQ]=FHM_SEQ_8;
            LadderGroup=0;
            LadderGroupSub=0;
            break;
/////////////////////////////////////
		default:
			break;
	}


	if(j != 0xff){
		for(k=0;k<16;k++){
			parameter_mirror[k]=FlashDspCharBuf[ENCODER_PULSE+k].long_data;  
		}
		l_LdTmpBufRam(j)=(unsigned long)DigitData;		
		flash_write(ENCODER_PULSE);
		CaluDecreasePulse();
	}


	if(i != 0xff){
	    GetFlashDataToBufRam(F_BLOCK2);
	    b_LdTmpBufRam(i)=(LocalType)(DigitData);
	    flash_write_DspChar(F_BLOCK2);
	}
        
}




void  __attribute__((section(".usercode"))) ParameterGroup(void)
{
	unsigned long tmpPlulsex;

    LocalType i;
    
    i=(LadderGroupSub + GroupBaseAddr);

    Cursor=0;
    ShiftCnt=5;
    EditBlanck=5;
    EditStatus=DIGIT_EDIT;

    DigitMaxValue=0xffff;
    DigitMinValue=0;

    DigitData=(unsigned int)(GET_LONG((unsigned long)i));    
    tmpPlulsex=(GET_LONG((unsigned long)i));    

    if(LadderGroupSub==P_TM_MPM){
        DigitMaxValue=211;
        ShiftCnt=3;
    }
    
    Integer_Digit();

	if(LadderGroupSub >= P_MINDEC30){
		EditStatus=NO_EDIT;
		if(LadderGroupSub < P_PAR1){ 
	    	EditBlanck=3;
			CurEncoderPulse(tmpPlulsex);
		}
	}
}


void  __attribute__((section(".usercode"))) ParameterGroupSave(void)
{
    LocalType  i;

    for(i=0;i<16;i++){
        parameter_mirror[i]=FlashDspCharBuf[ENCODER_PULSE+i].long_data;  
    }

    l_LdTmpBufRam(LadderGroupSub)=(unsigned long)DigitData;

    flash_write(ENCODER_PULSE);

}




void  __attribute__((section(".usercode"))) InportGroup(void)
{
    
    LocalType i;

    i=(LadderGroupSub + GroupBaseAddr);

	if     (i==F_SubDoorFlr1)	i=DOOR_HOLD_PORT;	
	else if(i==F_SubDoorFlr2)	i=VIRTUAL_X1_PORT;
	else if(i==F_SubDoorFlr3)	i=VIRTUAL_X2_PORT;	
	else if(i==F_SubDoorFlr4)	i=VIRTUAL_X3_PORT;	
	else if(i==F_SubDoorFlr5)	i=VIRTUAL_X4_PORT;	
	else if(i==F_SubDoorFlr6)	i=VIRTUAL_X5_PORT;	
	else if(i==F_SubDoorFlr7)	i=VIRTUAL_X6_PORT;	
	else if(i==F_SubDoorFlr8)	i=VIRTUAL_X7_PORT;	

    Cursor=0;
    ShiftCnt=2;
    EditBlanck=4;
    EditStatus=DIGIT_STRING_EDIT;

    DigitMaxValue=NO_USE_IN+1;
    DigitMinValue=0;

    DigitData=cF_FLRDSPCH((unsigned long)i);

    if(DigitData & 0x80)    OrgNcNo=0x80;  //
    else                    OrgNcNo=0x00;  //

    DigitData=(DigitData & 0x7f);

    Integer_Digit();    
}



unsigned int  __attribute__((section(".usercode"))) InportSave(void)
{
    LocalType i,j,k,ChangeDisable;

    ChangeDisable=0;

    i=(LadderGroupSub + GroupBaseAddr);

    for(k=EMG_PORT;k <= UND_PORT;k++){
    	j=cF_FLRDSPCH((unsigned long)(k));
        j=(j & 0x7f);       //
        if(j == DigitData)  ChangeDisable=1;
    }

    for(k=DOOR_HOLD_PORT;k <= VIRTUAL_X7_PORT;k++){
    	j=cF_FLRDSPCH((unsigned long)(k));
        j=(j & 0x7f);       //
        if(j == DigitData)  ChangeDisable=1;
    }


	if((ChangeDisable==0) || (DigitData == NO_USE_IN) ){    
		if ( (i >= F_SubDoorFlr1) && (i <= F_SubDoorFlr8)){
			if     (i==F_SubDoorFlr1)	i=DOOR_HOLD_PORT;	
			else if(i==F_SubDoorFlr2)	i=VIRTUAL_X1_PORT;
			else if(i==F_SubDoorFlr3)	i=VIRTUAL_X2_PORT;	
			else if(i==F_SubDoorFlr4)	i=VIRTUAL_X3_PORT;	
			else if(i==F_SubDoorFlr5)	i=VIRTUAL_X4_PORT;	
			else if(i==F_SubDoorFlr6)	i=VIRTUAL_X5_PORT;	
			else if(i==F_SubDoorFlr7)	i=VIRTUAL_X6_PORT;	
			else if(i==F_SubDoorFlr8)	i=VIRTUAL_X7_PORT;	
			else	return(0);
			    
	    	GetFlashDataToBufRam(F_BLOCK5);
	        if(DigitData == NO_USE_IN)  DigitData=(DigitData | 0x80);       //
	        else                        DigitData=(DigitData | OrgNcNo);    //
	
	        b_LdTmpBufRam(i)=(LocalType)(DigitData);
	        flash_write_DspChar(F_BLOCK5);
		}	
		else{	    
	    	GetFlashDataToBufRam(F_BLOCK4);	
	        if(DigitData == NO_USE_IN)  DigitData=(DigitData | 0x80);       //
	        else                        DigitData=(DigitData | OrgNcNo);    //
	
	        b_LdTmpBufRam(i)=(LocalType)(DigitData);
	        flash_write_DspChar(F_BLOCK4);
		}
	}

	return(0);
}



unsigned int  __attribute__((section(".usercode"))) DOOR_STOP_PORT_Inport_Init(void)
{
    LocalType j,k;
    LocalType pt,pt_dt,init;

	init=0;

	for(pt=DOOR_HOLD_PORT;pt <= VIRTUAL_X7_PORT;pt++){
	    pt_dt=cF_FLRDSPCH((unsigned long)(pt));
		if( (pt_dt == 0) || (pt_dt == 0xff)){
			init=1;
			pt=(VIRTUAL_X7_PORT + 1);
		}
		else{		
			pt_dt=(pt_dt & 0x7f);	
		    for(k=EMG_PORT;k <= UND_PORT;k++){
		    	j=cF_FLRDSPCH((unsigned long)(k));
		        j=(j & 0x7f);       
		        if(j == pt_dt){
  					init=1;
					pt=(VIRTUAL_X7_PORT + 1);
					k =(UND_PORT + 1);
				}
		    }
		}
	}	


	if ( init > 0){			    
    	GetFlashDataToBufRam(F_BLOCK5);

        b_LdTmpBufRam(SLOW_DOOR_PORT)   =(SILK_SLOW_DOOR	| BIT_NORMAL_OPEN);
        b_LdTmpBufRam(VIRTUAL_Y1_PORT)  =(SILK_VIRTUAL_Y1	| BIT_NORMAL_OPEN);     
        b_LdTmpBufRam(VIRTUAL_Y2_PORT)  =(SILK_VIRTUAL_Y2	| BIT_NORMAL_OPEN);     
        b_LdTmpBufRam(VIRTUAL_Y3_PORT)  =(SILK_VIRTUAL_Y3	| BIT_NORMAL_OPEN);     
        b_LdTmpBufRam(VIRTUAL_Y4_PORT)  =(SILK_VIRTUAL_Y4	| BIT_NORMAL_OPEN);     
        b_LdTmpBufRam(VIRTUAL_Y5_PORT)  =(SILK_VIRTUAL_Y5	| BIT_NORMAL_OPEN);     
        b_LdTmpBufRam(VIRTUAL_Y6_PORT)  =(SILK_VIRTUAL_Y6	| BIT_NORMAL_OPEN);     
        b_LdTmpBufRam(VIRTUAL_Y7_PORT)  =(SILK_VIRTUAL_Y7	| BIT_NORMAL_OPEN);     


        b_LdTmpBufRam(DOOR_HOLD_PORT)   =(SILK_DOOR_HOLD	| BIT_NORMAL_OPEN);
        b_LdTmpBufRam(VIRTUAL_X1_PORT)  =(SILK_VIRTUAL_X1	| BIT_NORMAL_OPEN);
        b_LdTmpBufRam(VIRTUAL_X2_PORT) 	=(SILK_VIRTUAL_X2	| BIT_NORMAL_OPEN);
        b_LdTmpBufRam(VIRTUAL_X3_PORT) 	=(SILK_VIRTUAL_X3	| BIT_NORMAL_OPEN);
        b_LdTmpBufRam(VIRTUAL_X4_PORT)	=(SILK_VIRTUAL_X4	| BIT_NORMAL_OPEN);
        b_LdTmpBufRam(VIRTUAL_X5_PORT)	=(SILK_VIRTUAL_X5	| BIT_NORMAL_OPEN);
        b_LdTmpBufRam(VIRTUAL_X6_PORT)	=(SILK_VIRTUAL_X6	| BIT_NORMAL_OPEN);
        b_LdTmpBufRam(VIRTUAL_X7_PORT)	=(SILK_VIRTUAL_X7	| BIT_NORMAL_OPEN);

		SaveVerify = 0x55;
        flash_write_DspChar(F_BLOCK5);
		SaveVerify = 0x0;

	}	
	return(0);
}




/*

void  __attribute__((section(".usercode"))) InportGroup(void)
{
    
    LocalType i;

    i=(LadderGroupSub + GroupBaseAddr);

    Cursor=0;
    ShiftCnt=2;
    EditBlanck=4;
    EditStatus=DIGIT_STRING_EDIT;

    DigitMaxValue=NO_USE_IN+1;
    DigitMinValue=0;

    DigitData=cF_FLRDSPCH((unsigned long)i);

    if(DigitData & 0x80)    OrgNcNo=0x80;  //
    else                    OrgNcNo=0x00;  //

    DigitData=(DigitData & 0x7f);

    Integer_Digit();    
}


void  __attribute__((section(".usercode"))) InportSave(void)
{
    LocalType i,j,k,ChangeDisable;

    i=(LadderGroupSub + GroupBaseAddr);
    GetFlashDataToBufRam(F_BLOCK4);

    ChangeDisable=0;
    for(k=0;k <(DigitMaxValue-1);k++){
        j=b_LdTmpBufRam(k); //
        j=(j & 0x7f);       //
        if(j == DigitData)  ChangeDisable=1;
    }
    
    if((ChangeDisable==0) || (DigitData == NO_USE_IN) ){    
        if(DigitData == NO_USE_IN) DigitData=(DigitData | 0x80);       //
        else                        DigitData=(DigitData | OrgNcNo);    //

        b_LdTmpBufRam(i)=(LocalType)(DigitData);
        flash_write_DspChar(F_BLOCK4);
    }
}
*/


/*
unsigned int  __attribute__((section(".usercode"))) SpecialOutPortSelReload(unsigned int updn)
{    
	return(0);

	if( LadderGroup != OUTPORT_GROUP)	return(0);
 	if(LadderGroupSub >= SILK_SLOW_DOOR)	return(0);
	if(DigitData >= NO_USE_OUT)			return(0);

	if(DigitData >= SILK_SLOW_DOOR){
		if(updn==1){					// up
			DigitData=NO_USE_OUT;	
		}
		else{
			DigitData=(SILK_SLOW_DOOR-1);	
		}	
	}
	return(0);
}
*/


void  __attribute__((section(".usercode"))) OutportGroup(void)
{
    LocalType i;
    
    i=(LadderGroupSub + GroupBaseAddr);

    Cursor=0;
    ShiftCnt=2;
    EditBlanck=4;
    EditStatus=DIGIT_STRING_EDIT;
    DigitMinValue=0;
    DigitMaxValue= (NO_USE_OUT+1);

    DigitData=cF_FLRDSPCH((unsigned long)i);

    if(DigitData & 0x80)    OrgNcNo=0x80;  //
    else                    OrgNcNo=0x00;  //
    DigitData=(DigitData & 0x7f);

    Integer_Digit();    
}




void  __attribute__((section(".usercode"))) OutportSave(void)
{
    LocalType i,j,k,ChangeDisable;

    i=(LadderGroupSub + GroupBaseAddr);
    GetFlashDataToBufRam(F_BLOCK5);
    
    ChangeDisable=0;


    for(k=0;k < SILK_EXT_Y0;k++){
        j=b_LdTmpBufRam(k); //
        j=(j & 0x7f);       //
        if(j == DigitData){
  			ChangeDisable=1;
		}
    }
    
    if((ChangeDisable==0) || (DigitData == NO_USE_OUT) ){
        if(DigitData == NO_USE_OUT) DigitData=(DigitData | 0x80);       //
        else                        DigitData=(DigitData | OrgNcNo);    //

        b_LdTmpBufRam(i)=(LocalType)(DigitData);
        flash_write_DspChar(F_BLOCK5);
    }


}



#ifdef	DELTA_INVERTER

const unsigned char INVERTER_PAR[] 		={"Inverter Par: 00"};
const unsigned char INVERTER_VAL[] 		={"00:             "};


void  __attribute__((section(".usercode"))) Delta_inverter_Par_Group(void)
{
    LocalType i,j;

    for(i=0;i<16;i++){
        New485Ladder[i+2]=INVERTER_PAR[i];
    }
    New485Ladder[2+14]=( (LadderGroup-DELTA_PAR_GROUP_00) / 10)+ '0';
    New485Ladder[2+15]=( (LadderGroup-DELTA_PAR_GROUP_00) % 10)+ '0';


	for(i=0;i<16;i++){
	    New485Ladder[SECONDLINE_BASE+i]=INVERTER_VAL[i];
	}
	New485Ladder[SECONDLINE_BASE+ 0]=(LadderGroupSub / 10)+ '0';
	New485Ladder[SECONDLINE_BASE+ 1]=(LadderGroupSub % 10)+ '0';

    Cursor=0;
    ShiftCnt=5;
    EditBlanck=3;
    EditStatus=DIGIT_EDIT;

}


/*

void  __attribute__((section(".usercode"))) Delta_inverter_Par_DataSet(unsigned int val,unsigned int dp)
{

	Man_Dsp(val,0);

	if(dp==1){
    	New485Ladder[SECONDLINE_BASE+EditBlanck+5]=New485Ladder[SECONDLINE_BASE+EditBlanck+4];          
    	New485Ladder[SECONDLINE_BASE+EditBlanck+4]='.';          
	}	
	else if(dp==2){
    	New485Ladder[SECONDLINE_BASE+EditBlanck+5]=New485Ladder[SECONDLINE_BASE+EditBlanck+4];          
    	New485Ladder[SECONDLINE_BASE+EditBlanck+4]=New485Ladder[SECONDLINE_BASE+EditBlanck+3];          
    	New485Ladder[SECONDLINE_BASE+EditBlanck+3]='.';          
	}	
	else if(dp==3){
    	New485Ladder[SECONDLINE_BASE+EditBlanck+5]=New485Ladder[SECONDLINE_BASE+EditBlanck+4];          
    	New485Ladder[SECONDLINE_BASE+EditBlanck+4]=New485Ladder[SECONDLINE_BASE+EditBlanck+3];          
    	New485Ladder[SECONDLINE_BASE+EditBlanck+3]=New485Ladder[SECONDLINE_BASE+EditBlanck+2];          
    	New485Ladder[SECONDLINE_BASE+EditBlanck+2]='.';          
	}
	Cursor=0;
}
*/


void  __attribute__((section(".usercode"))) Delta_inverter_Par_GroupSave(void)
{
	unsigned int val;

	val=(DigitData >> 8);
	AddrWriteParameter((unsigned char)(LadderGroup-DELTA_PAR_GROUP_00),(unsigned char)LadderGroupSub,1,(unsigned char)(val),(unsigned char)(DigitData));
	DeltaRdWrStatus=6;


////////	AddrWriteParameter((unsigned char)(LadderGroup-DELTA_PAR_GROUP_00),(unsigned char)LadderGroupSub,1,(unsigned char)(val),(unsigned char)(DigitData));


/*
    LocalType i,j;

    for(i=0;i<16;i++){
        New485Ladder[i+2]=INVERTER_PAR[i];
    }
    New485Ladder[2+14]=( (LadderGroup-DELTA_PAR_GROUP_00) / 10)+ '0';
    New485Ladder[2+15]=( (LadderGroup-DELTA_PAR_GROUP_00) % 10)+ '0';


     for(i=0;i<16;i++){
         New485Ladder[SECONDLINE_BASE+i]=INVERTER_VAL[i];
     }
     New485Ladder[SECONDLINE_BASE+ 0]=(LadderGroupSub / 10)+ '0';
     New485Ladder[SECONDLINE_BASE+ 1]=(LadderGroupSub % 10)+ '0';
*/
}


void  __attribute__((section(".usercode"))) Delta_inverter_Par_DataSort(unsigned int this_data)
{
	unsigned int dp;
	
	dp=IV_This_Attrv;	
	dp=(dp & 0x0300);
	if( 	 dp == 0x0100)	dp=1;
	else if( dp == 0x0200)	dp=2;
	else if( dp == 0x0300)	dp=3;
	else					dp=0;


//	if( IV_This_Attrv  & 0x0100)	
	EditStatus=DIGIT_EDIT;	

	DigitMinValue=IV_This_Min;
	DigitMaxValue=IV_This_Max;
	DigitData=this_data;

	if( (DigitMaxValue < 10) && (dp==0)){
	    ShiftCnt=1;
		Il_Dsp(DigitData,dp);
	}
	else if( (DigitMaxValue < 100) && (dp < 2)){
	    ShiftCnt=2;
		if(dp > 0 )	ShiftCnt++;

		Sip_Dsp(DigitData,dp);
	}
	else if( (DigitMaxValue < 1000) && (dp < 3)){
	    ShiftCnt=3;
		if(dp > 0 )	ShiftCnt++;
		Bek_Dsp(DigitData,dp);
	}
	else if(DigitMaxValue < 10000){
	    ShiftCnt=4;
		if(dp > 0 )	ShiftCnt++;
		Chun_Dsp(DigitData,dp);
	}
	else{
	    ShiftCnt=5;
		if(dp > 0 )	ShiftCnt++;
		Man_Dsp(DigitData,dp);
	}
}


#endif




void  __attribute__((section(".usercode"))) ErrorGroup(LocalType offset)
{
    LocalType i,j;

    EditStatus=NO_EDIT;

    offset=offset * ERR_SAVE_WIDE;

    New485Ladder[2]  ='E';          
    New485Ladder[3]  ='R';
    New485Ladder[4]  =':';


    if(eDArry[eSysErCnt + offset + 0] > 0){
        New485Ladder[5]  =(eDArry[eSysErCnt + offset + 0] >> 4  ) + '0';  //month          
        New485Ladder[6]  =(eDArry[eSysErCnt + offset + 0] & 0x0f) + '0';
        New485Ladder[7]  =(eDArry[eSysErCnt + offset + 1] >> 4  ) + '0';  //date          
        New485Ladder[8]  =(eDArry[eSysErCnt + offset + 1] & 0x0f) + '0';
        New485Ladder[9] ='/';          
        New485Ladder[10] =(eDArry[eSysErCnt + offset + 4] >> 4  ) + '0';  //hour         
        New485Ladder[11] =(eDArry[eSysErCnt + offset + 4] & 0x0f) + '0';
        New485Ladder[12] =(eDArry[eSysErCnt + offset + 5] >> 4  ) + '0';  //min         
        New485Ladder[13] =(eDArry[eSysErCnt + offset + 5] & 0x0f) + '0';
        New485Ladder[14] ='/';          



		i=eDArry[eSysErCnt + offset + 2];
		i=(i*2);

		New485Ladder[15]=cF_FLRDSPCH((unsigned long)(i+0));  
    	New485Ladder[16]=cF_FLRDSPCH((unsigned long)(i+1));          

        New485Ladder[17] ='F';

        New485Ladder[SECONDLINE_BASE+0]='E';
        New485Ladder[SECONDLINE_BASE+1]=(LadderGroupSub / 10)+ '0';
        New485Ladder[SECONDLINE_BASE+2]=(LadderGroupSub % 10)+ '0';
        New485Ladder[SECONDLINE_BASE+3]=':';
    
        j=eDArry[eSysErCnt + 3 + offset];
        for(i=0;i<13;i++){
            New485Ladder[SECONDLINE_BASE+i+4] =StatusMessage[j][i];          //error status
//            New485Ladder[SECONDLINE_BASE+i+4] =ErrStatusMessage[j][i];          //error status
        }
    }
    else{
        j=LadderGroup;
        j=((j-1) * 32)+1;

        for(i=0;i<16;i++){
            New485Ladder[i+2]=GroupLineMessage[j][i];
        }
        New485Ladder[15]=(LadderGroupSub / 10)+ '0';
        New485Ladder[16]=(LadderGroupSub % 10)+ '0';

        for(i=0;i<16;i++){
            New485Ladder[SECONDLINE_BASE+i]=GroupLineMessage[j][i];
        }
        New485Ladder[SECONDLINE_BASE+13]=(LadderGroupSub / 10)+ '0';
        New485Ladder[SECONDLINE_BASE+14]=(LadderGroupSub % 10)+ '0';
    }
}




unsigned int  __attribute__((section(".usercode"))) SaveData(void)
{
    LocalType i,ret;

	ret=0;

    switch(LadderGroup){
        case    FLR_DSP_GROUP:
            FlrDspGroupSave(LadderGroupSub);
            break;
        case    FLR_GROUP:
            FlrGroupSave();
            break;
        case    TIMER_GROUP:
            TimerGroupSave();
			CmdFixFlrTime=cF_FIXFLOORTIME;
            break;
        case    SUB_DOOR_GROUP:
			DoorGroupSave();
            break;
        case    ONOFF1_GROUP:
            OnOffGroupSave();
            break;
        case    ONOFF2_GROUP:
            OnOffGroupSave();
            if(EncoderPhaseChk) SWPAB   = 1;
            else                SWPAB   = 0;

			if(FamilyService)	bExt_FAMILY=1;
			else				bExt_FAMILY=0;

            break;
        case    NCNO1_GROUP:
        case    NCNO2_GROUP:
            InNcNoGroupSave();
            break;
        case    NCNO3_GROUP:
            OutNcNoGroupSave();
            break;
        case    IO_GROUP:
			IoGroupSave();
            break;
        case    USER_GROUP:    //save
            UserGroupSave();
            break;
        case    OPEN_WAIT_GROUP:
            WaitFlrGroupSave();
            break;
        case    PARAMETER_GROUP:
            if(LadderGroupSub < P_MINDEC30){
	            ParameterGroupSave();
	            CaluDecreasePulse();
            }
            break;
        case    INPORT1_GROUP:
        case    INPORT2_GROUP:
            InportSave();
            break;
        case    OUTPORT_GROUP:
            OutportSave();
            break;
        case    ERROR_GROUP:
            break;
        case    EL_GROUP:
			ELGroupSave();
			break;
#ifdef	DELTA_INVERTER
		case    DELTA_PAR_GROUP_00:
		case    DELTA_PAR_GROUP_01:
        case    DELTA_PAR_GROUP_02:
        case    DELTA_PAR_GROUP_03:
        case    DELTA_PAR_GROUP_04:
        case    DELTA_PAR_GROUP_05:
        case    DELTA_PAR_GROUP_06:
        case    DELTA_PAR_GROUP_07:
        case    DELTA_PAR_GROUP_08:
        case    DELTA_PAR_GROUP_09:
        case    DELTA_PAR_GROUP_10:
        case    DELTA_PAR_GROUP_11:
        case    DELTA_PAR_GROUP_12:
        case    DELTA_PAR_GROUP_13:
        case    DELTA_PAR_GROUP_14:
			Delta_inverter_Par_GroupSave();
			ret=1;
			break;
#endif

        default:
            break;

    }

    Cursor=0;

	return(ret);
}



void  __attribute__((section(".usercode"))) CursorOff(void)
{
    New485Ladder[SECONDLINE_CURSOR]=' ';  
}

void  __attribute__((section(".usercode"))) CursorOn(void)
{
    LocalType i;

    i=Cursor + EditBlanck;                    
    if(i>0x09)  i=i + '7';
    else        i=i + '0';
    New485Ladder[SECONDLINE_CURSOR]=i;  
}


unsigned int  __attribute__((section(".usercode"))) CusorDigitSet(void)
{
    LocalType i;
    i=SECONDLINE_BASE + EditBlanck + Cursor;

    switch(EditStatus){
        case    DIGIT_EDIT:
        case    DIGIT_ALPHAR_EDIT:
            New485Ladder[i]=LadderKey;
            break;
    }         
}
                        

unsigned int  __attribute__((section(".usercode"))) CusorDataUp(void)
{
    LocalType i;
    i=SECONDLINE_BASE + EditBlanck + Cursor;

    switch(EditStatus){
        case    DIGIT_EDIT:
            switch(ShiftCnt-Cursor){
                case    1:
                    DigitData++;
                    break;
                case    2:
                    DigitData=DigitData+10;
                    break;                    
                case    3:
                    DigitData=DigitData+100;
                    break;                    
                case    4:
                    DigitData=DigitData+1000;
                    break;                    
                case    5:
                    DigitData=DigitData+10000;
                    break;                    
            }
            Integer_Digit();    
            break;
        case    DIGIT_STRING_EDIT:
            if(DigitMaxValue>0){
                DigitData=(DigitData+1)%DigitMaxValue;
            }
            Integer_Digit();    
            break;
        case    DIGIT_ALPHAR_EDIT:
            New485Ladder[i]++;
            if(New485Ladder[i]>'Z')                      					New485Ladder[i]='0';
            else if((New485Ladder[i]>'9') && (New485Ladder[i]<'A'))  		New485Ladder[i]='A';
            else if(New485Ladder[i] < '0')  								New485Ladder[i]='0';

 
/*
	
            if((New485Ladder[i]>'Z'))                      					New485Ladder[i]='0';
            else if((New485Ladder[i]>'A') && ((New485Ladder[i]>'Z'))                      New485Ladder[i]='A'; 
 
            else if((New485Ladder[i]>'9'))                      New485Ladder[i]='A'; 

            if((New485Ladder[i]>'9') && (New485Ladder[i]<'A'))  New485Ladder[i]='A'; 
            else if((New485Ladder[i]>'Z'))                      New485Ladder[i]='0'; 
*/

            break;
        case    CLOCK_EDIT:
            New485Ladder[i]++;
            if((New485Ladder[i]<'0'))       New485Ladder[i]='9'; 
            else if(New485Ladder[i]>'9')    New485Ladder[i]='0'; 
            CalendarChk(); 
            break;
        case    TABLE_EDIT:
                break;    
        case    TOGGLE_EDIT:
                break;    
    }         
}


unsigned int  __attribute__((section(".usercode"))) CusorDataDn(void)
{
    LocalType i;

    i=SECONDLINE_BASE + EditBlanck + Cursor;

    switch(EditStatus){
        case    DIGIT_EDIT:
            switch(ShiftCnt-Cursor){
                case    1:
                    if(DigitData > 0)           DigitData--;
                    break;
                case    2:
                    if(DigitData >= 10)         DigitData=DigitData-10;
                    break;                    
                case    3:
                    if(DigitData >= 100)        DigitData=DigitData-100;
                    break;                    
                case    4:
                    if(DigitData >= 1000)       DigitData=DigitData-1000;
                    break;                    
                case    5:
                    if(DigitData >= 10000)      DigitData=DigitData-10000;
                    break;                    
            }
            Integer_Digit();    
            break;
        case    DIGIT_STRING_EDIT:
            if(DigitData > DigitMinValue)   DigitData--; 
            else                            DigitData=(DigitMaxValue-1);
            Integer_Digit();    
            break;
        case    DIGIT_ALPHAR_EDIT:
            New485Ladder[i]--;
            if((New485Ladder[i]<'0'))                      				New485Ladder[i]='Z'; 
            else if((New485Ladder[i]>'9') && (New485Ladder[i]<'A'))  	New485Ladder[i]='9'; 
            else if(New485Ladder[i]>'Z')  								New485Ladder[i]='Z'; 
            break;
        case    CLOCK_EDIT:
            New485Ladder[i]--;
            if((New485Ladder[i]<'0'))       New485Ladder[i]='9'; 
            else if(New485Ladder[i]>'9')    New485Ladder[i]='0';
            CalendarChk(); 
            break;
        case    TABLE_EDIT:
                break;    
        case    TOGGLE_EDIT:
                break;    
    }         
}


unsigned int  __attribute__((section(".usercode"))) ShiftRightCur(void)
{
    LocalType i;

    if(ShiftCnt==0) Cursor=0;
    else            Cursor=(Cursor+1)%ShiftCnt; 

    i=SECONDLINE_BASE + EditBlanck + Cursor;

    if(EditStatus == DIGIT_EDIT){
        if((New485Ladder[i] == '.') || (New485Ladder[i] == ('.' + 0x80))){
            if(ShiftCnt==0) Cursor=0;
            else            Cursor=(Cursor+1)%ShiftCnt; 
        }
    }           
    else if(EditStatus == CLOCK_EDIT){
        if((New485Ladder[i] == '-') || (New485Ladder[i] == ('-' + 0x80))){
            if(ShiftCnt==0) Cursor=0;
            else            Cursor=(Cursor+1)%ShiftCnt; 
        }
    }           
}


unsigned int  __attribute__((section(".usercode"))) ShiftLeftCur(void)
{
    LocalType i;

    if(ShiftCnt==0)     Cursor=0;
    else if(Cursor>0)   Cursor--;
    else                Cursor=ShiftCnt-1;

    i=SECONDLINE_BASE + EditBlanck + Cursor;

    if(EditStatus == DIGIT_EDIT){
        if((New485Ladder[i] == '.') || (New485Ladder[i] == ('.' + 0x80))){
            if(ShiftCnt==0)     Cursor=0;
            else if(Cursor>0)   Cursor--;
            else                Cursor=ShiftCnt-1;
        }
    }           
    else if(EditStatus == CLOCK_EDIT){
        if((New485Ladder[i] == '-') || (New485Ladder[i] == ('-' + 0x80))){
            if(ShiftCnt==0) Cursor=0;
            else if(Cursor>0)   Cursor--;
            else                Cursor=ShiftCnt-1;
        }
    }           
}



unsigned int  __attribute__((section(".usercode"))) GroupOnChk(void)
{
    if(bAllMenu)  		return(0);
	if(bPasswardOk)		return(0);	

    switch(LadderGroup){
        case    USER_GROUP:  //save
        case    ERROR_GROUP:
            return(0);
            break;
        default:
            return(1);
            break;
    }
}



unsigned int  __attribute__((section(".usercode"))) MenuOnChk(void)
{
    LocalType i;

	i=0;


	switch(LadderGroup){
    	case    USER_GROUP:
			switch(LadderGroupSub){
        		case    LG_INV_IN_BD:
        			if(INVERTER_CHECK != LG)	i=1;                                             
					break;	
				default:
					break;
			}	
			break;
        case    EL_GROUP:
			switch(LadderGroupSub){
				case	SUBNM_BASE_DEC_TIME:
				case	SUBNM_BASE_DEC_LENTH:
				case	SUBNM_BASE_PULSE:
				case	SUBNM_BASE_SCURVE_TIME:
					if(AutoLandingModeChk((unsigned char)DS_AUTOLANDING)){
							i=0;
					}
					else	i=1;
					break;
			}
			break;		
		default:
			break;	
	}
	return(i);
}






unsigned int  __attribute__((section(".usercode"))) EditOnCheck(void)
{
    LocalType i;
    
    i=1;
    if(EditStatus==NO_EDIT) return(0);
    if(bMoveCar)            return(0);

    if(bAllMenu)			i=1;	//ver3.5
	else{
        switch(LadderGroup){
            case    USER_GROUP:
	           	switch(LadderGroupSub){
	               	case    PASSWARD:
	               	case    ALL_MENU_CHK:
	               	case    ENGINEER_NM:
	                   	i=1;
	                   	break;
					case	COMPANY_NAME:
						if(!bCompanyCtl)	i=0;
						break;
					case	ERR_ST_CNT:
					case	OUT_DATE:
					case	ENCODER_RATE:
        			case    SYSTEM_SET:
						if(!bUserOn)		i=0;
						break;
					default:
						i=1;
	                   	break;
	           	}
				break;

            case    ONOFF2_GROUP:
	           	switch(LadderGroupSub){
	               	case    DR_JMP_CHK:
	               	case    MGT_MON_CHK:
	               	case    BRK_MON_CHK:
						if(New_Law_SystemChk() && !bUserOn)	i=0;
						break;
					default:
						i=1;
			        	break;
				}
				break;
            case    NCNO1_GROUP:
            case    INPORT1_GROUP:
	           	switch(LadderGroupSub){
	               	case    NCNO1_EMG:
	               	case    NCNO1_AUTO:
	               	case    NCNO1_UB:
	               	case    NCNO1_DB:
	               	case    NCNO1_GS:
	               	case    NCNO1_DS:
						i=0;
						break;
					default:
						if(New_Law_SystemChk() && !bUserOn)	i=0;
			        	break;
				}
				break;
            case    NCNO2_GROUP:
            case    NCNO3_GROUP:
            case    INPORT2_GROUP:
            case    OUTPORT_GROUP:
					if(New_Law_SystemChk() && !bUserOn)	i=0;
				break;
			default:
				i=1;
				break;
				
       	}
	}
	return(i);

}


unsigned int  __attribute__((section(".usercode"))) KeyCheck(void)
{
    LocalType i,j,newmenu,ret;
    LocalType max_group_sel;

	ret=0;
	if(bSpeedDsp && !bFhmRun)	return(0);

	if(New_Spd_SystemChk())		max_group_sel=MAX_GROUP_SPD3;
	else						max_group_sel=MAX_GROUP;

	#ifdef	DELTA_INVERTER
	max_group_sel= (max_group_sel + (DELTA_PAR_GROUP_END - DELTA_PAR_GROUP_00));
	#endif


	j=0;
    newmenu=1;

    LadderKey = LadderBuf[C_SAVE_DATA+0];
	if( !bLoaderActive)	LadderKey = 'N';	

	if(LadderGroup == 0)	LadderGroupSelect=LadderGroup;

    switch(LadderKey){
        case    MENUKEY:
				bHibSet=0;	
                LadderKeyTime=0;
                do{
					j++;
                    i=1;
					LadderGroupSelect=(LadderGroupSelect+1) % max_group_sel;
					LadderGroupSub=0;

                    NewMenuStart();
                    CursorOff();
                    i=GroupOnChk(); 
                }while(i && (j <30));
                break;
        case    ESCKEY:
				if(EnterKey==2){
					EnterKey=1;
				}
				else if(EnterKey==1){
					EnterKey=0;
					if(LadderGroupSub==0){
						LadderGroupSelect=0;
					}
	                LadderGroupSub=0;

				}
				else{
					LadderGroupSelect=0;
	                LadderGroupSub=0;
				}

				bHibSet=0;	
	            LadderKeyTime=0;
	            NewMenuStart();
                CursorOff(); 
                break;
        case    UPKEY:
				bHibSet=0;	
                LadderKeyTime=0;
                if(EnterKey==1){
	                do{
                        LadderGroupSub=(LadderGroupSub+1)% MaxSubMenu;
	                    i=MenuOnChk(); 
	                }while(i);
                    NewMenuStart();
                    CursorOff(); 
                }
                else if(EnterKey==2){
                    CusorDataUp();
					newmenu=0;
                }
                break;
        case    DOWNKEY:
				bHibSet=0;	
                LadderKeyTime=0;
                if(EnterKey==1){
	                do{
	                    if(LadderGroupSub>0)    LadderGroupSub--;
	                    else                    LadderGroupSub=MaxSubMenu-1;                    
	                    i=MenuOnChk(); 
	                }while(i);
                    NewMenuStart();
                    CursorOff(); 
                }
                else if(EnterKey==2){
                    CusorDataDn();
					newmenu=0;
                }
                break;
        case    LEFTKEY:
				bHibSet=0;	
                LadderKeyTime=0;
                if(EnterKey==1){
                    do{
	           			i=1;
                        if(LadderGroupSub==0){
							LadderGroupSelect=(LadderGroupSelect+1) % max_group_sel;
						}
						else{
	                        LadderGroupSub=0;							
						}
                        NewMenuStart();
                        CursorOff(); 
                        i=GroupOnChk(); 

                    }while(i);
                }
                else if(EnterKey==2){
                    ShiftLeftCur();
                    CursorOn();
					newmenu=0;
                }
                break;
        case    RIGHTKEY:
				bHibSet=0;	
                LadderKeyTime=0;
                if(EnterKey==1){
                    do{
                        i=1;
                        if(LadderGroupSub==0){
	                        if(LadderGroupSelect>0)   	LadderGroupSelect--;
	                        else                		LadderGroupSelect=max_group_sel-1;
						}
						else{
	                        LadderGroupSub=0;							
						}

                        NewMenuStart();
                        CursorOff(); 
                        i=GroupOnChk(); 
                    }while(i);
                }
                else if(EnterKey==2){
                    ShiftRightCur();
                    CursorOn();
					newmenu=0;
                }
                break;
        case    ENTKEY:
				newmenu=0;
                LadderKeyTime=0;
                EnterKey++;
                if(EnterKey==2){
                    if(!EditOnCheck()){
                        EnterKey=1;
                        CursorOff(); 
                    }
                    else    CursorOn();
					bHibSet=0;	
                }
                else if(EnterKey==3){
                    if(!bMoveCar){
						SaveVerify = 0x55;
                        ret=SaveData();
						SaveVerify = 0x0;
                    }
					if(ret==0)	EnterKey=0;	
                }
				else{
					bHibSet=0;	
				}
                break;
        case    ONEKEY:
        case    TWOKEY:
        case    THREEKEY:
        case    FOURKEY:
        case    FIVEKEY:
        case    SIXKEY:
        case    SEVENKEY:
        case    EIGHTKEY:
        case    NINEKEY:
        case    ZEROKEY:   
                LadderKeyTime=0;
                CusorDigitSet();
				newmenu=0;
                break;
        default:
                LadderKey = 0xff;
				newmenu=0;
                break;
    }   
	
	if(newmenu){
        for(i=0;i<16;i++){
            New485Ladder[i+2]=blinkx[i];
        }
        for(i=0;i<16;i++){
            New485Ladder[SECONDLINE_BASE+i]=blinkx[i];
        }
	}

	if( (LadderKeyTime < 2) && (LadderKey != 0xff)){
		sRamDArry[mEV_LastErr]=0xff;
		if(sRamDArry[FHM_SEQ] <= FHM_SEQ_7){
			EnterKey=0;
			LadderGroupSelect=0;
			LadderGroup=0;
			LadderGroupSub=0;
			NewMenuStart();
			CursorOff();
			sRamDArry[FHM_SEQ] = FHM_SEQ_8;
			
		} 

		if(sRamDArry[AUTO_TUNING] > AUTOTUN_SEQ_0){
			EnterKey=0;
			LadderGroupSelect=0;
			LadderGroup=0;
			LadderGroupSub=0;
			NewMenuStart();
			CursorOff();

			AutotunUpDn=0;
			sRamDArry[AUTO_TUNING] = AUTOTUN_SEQ_0;			
		} 
	}

    return(0);
}


unsigned int  __attribute__((section(".usercode"))) LaderDsp(void)
{
    LocalType i,j;


    for(i=0;i<MAX_LADDER_BUF-2;i++)   New485Ladder[i]=' ';
    New485Ladder[MAX_LADDER_BUF-1]=0x0;   


    j=LadderGroup;

	#ifdef	FLOOR_64
		if(j==FLR_DSP_GROUP){
	        for(i=0;i<16;i++){
	            New485Ladder[i+2]=DSP_CHAR[i];
	        }
			i=(LadderGroupSub+1);
	        New485Ladder[11]  =(i/10) + '0';          
	        New485Ladder[12] =(i%10) + '0';          
		}
		else if(j==ONOFF1_GROUP){
	        for(i=0;i<16;i++){
	            New485Ladder[i+2]=FLR_ONOFF[i];
	        }
			i=(LadderGroupSub+1);
	        New485Ladder[14]  =(i/10) + '0';          
	        New485Ladder[15] =(i%10) + '0';          
		}
		else if(j==SUB_DOOR_GROUP){
	        for(i=0;i<16;i++){
	            New485Ladder[i+2]=DOOR_MAIN_SUB[i];
	        }
			i=(LadderGroupSub+1);
	        New485Ladder[14]  =(i/10) + '0';          
	        New485Ladder[15] =(i%10) + '0';          
		}
		else{
	        if(j>0){    
	            j=(LadderGroupSub + ((j-1) * 32))+1;
	        }
	
	        for(i=0;i<16;i++){
	            New485Ladder[i+2]=GroupLineMessage[j][i];
	        }
	
	        if(j==0){
	            New485Ladder[2+3]=sRamDArry[DSP1];
	            New485Ladder[2+4]=sRamDArry[DSP2];
			}
  		}      
	#else
	        if(j>0){    
	            j=(LadderGroupSub + ((j-1) * 32))+1;
	        }
	
	        for(i=0;i<16;i++){
	            New485Ladder[i+2]=GroupLineMessage[j][i];
	        }
	

	        if(j==0){
	            New485Ladder[2+3]=sRamDArry[DSP1];
	            New485Ladder[2+4]=sRamDArry[DSP2];
			}
	#endif

    New485Ladder[0]=LadderKey;    
    New485Ladder[1]=' ';

    New485Ladder[SECONDLINE_BASE+0] =(LadderGroupSub/10) + '0';          
    New485Ladder[SECONDLINE_BASE+1] =(LadderGroupSub%10) + '0';          

	return(0);
}

////////////////////new ladder////////////////////////////
unsigned int  __attribute__((section(".usercode"))) NewFlashData(void)
{
    LocalType i,j;

	#ifdef	DELTA_INVERTER
	LocalType	delta_rdwr_valid=0;
	#endif

    if((LadderKeyTime > 36000) && (LadderKeyTime < 36002)){        
		LadderKeyTime=36012;

        LadderGroup=0;
        LadderGroupSub=0;
        EnterKey=0;

		PassWardKeyBuf[0]='0';
		PassWardKeyBuf[1]='0';
		PassWardKeyBuf[2]='0';
		PassWardKeyBuf[3]='0';
		bPasswardOk=0;
		bUserOn=0;
		bCompanyCtl=0;
		bLoaderActive=0;

///		PasswardCheck();

    }	 

#ifdef	TEST_SIMULATION
	bAllMenu=1;
#endif

	if(bAllMenu){
		bPasswardOk=1;
		bUserOn=1;	
		bCompanyCtl=1;
		bLoaderActive=1;
	}


    KeyCheck();

    if(EnterKey==0){
        EnterKey=1;            
		LaderDsp();






/*
    for(i=0;i<MAX_LADDER_BUF-2;i++)   New485Ladder[i]=' ';
    New485Ladder[MAX_LADDER_BUF-1]=0x0;   

    j=LadderGroup;
	#ifdef	FLOOR_64
		if(j==FLR_DSP_GROUP){
	        for(i=0;i<16;i++){
	            New485Ladder[i+2]=DSP_CHAR[i];
	        }
			i=(LadderGroupSub+1);
	        New485Ladder[11]  =(i/10) + '0';          
	        New485Ladder[12] =(i%10) + '0';          
		}
		else if(j==ONOFF1_GROUP){
	        for(i=0;i<16;i++){
	            New485Ladder[i+2]=FLR_ONOFF[i];
	        }
			i=(LadderGroupSub+1);
	        New485Ladder[14]  =(i/10) + '0';          
	        New485Ladder[15] =(i%10) + '0';          
		}
		else if(j==SUB_DOOR_GROUP){
	        for(i=0;i<16;i++){
	            New485Ladder[i+2]=DOOR_MAIN_SUB[i];
	        }
			i=(LadderGroupSub+1);
	        New485Ladder[14]  =(i/10) + '0';          
	        New485Ladder[15] =(i%10) + '0';          
		}
		else{
	        if(j>0){    
	            j=(LadderGroupSub + ((j-1) * 32))+1;
	        }
	
	        for(i=0;i<16;i++){
	            New485Ladder[i+2]=GroupLineMessage[j][i];
	        }
	
	        if(j==0){
	            New485Ladder[2+3]=sRamDArry[DSP1];
	            New485Ladder[2+4]=sRamDArry[DSP2];
			}
  		}      
	#else
	        if(j>0){    
	            j=(LadderGroupSub + ((j-1) * 32))+1;
	        }
	
	        for(i=0;i<16;i++){
	            New485Ladder[i+2]=GroupLineMessage[j][i];
	        }
	
	        if(j==0){
	            New485Ladder[2+3]=sRamDArry[DSP1];
	            New485Ladder[2+4]=sRamDArry[DSP2];
			}
	#endif


        New485Ladder[0]=LadderKey;    
        New485Ladder[1]=' ';

        New485Ladder[SECONDLINE_BASE+0] =(LadderGroupSub/10) + '0';          
        New485Ladder[SECONDLINE_BASE+1] =(LadderGroupSub%10) + '0';          
*/

//        New485Ladder[0]=LadderKey;    
//        New485Ladder[1]=' ';
        
        switch(LadderGroup){
            case    FLR_DSP_GROUP:
                GroupBaseAddr=F_FlrDspCh;
                FlrDspGroup(LadderGroupSub);
                break;
            case    FLR_GROUP:
                GroupBaseAddr=F_TopFlr;
                FlrGroup();
                break;
            case    TIMER_GROUP:
                GroupBaseAddr=F_OpWtTm;
                TimerGroup();
                break;
/////////////////////////
            case    SUB_DOOR_GROUP:
                GroupBaseAddr=F_SubDoorFlr1;
				DoorGroup();
//                OnOffGroup();
                break;
///////////////////////////////
            case    ONOFF1_GROUP:
                GroupBaseAddr=F_NonService0;
                OnOffGroup();
                break;
            case    ONOFF2_GROUP:
                GroupBaseAddr=F_OnOff0;
                OnOffGroup();
                break;
            case    NCNO1_GROUP:
                GroupBaseAddr=EMG_PORT;
                NcNoGroup();
                break;
            case    NCNO2_GROUP:
                GroupBaseAddr=X0_PORT;
                NcNoGroup();
                break;
            case    NCNO3_GROUP:
                GroupBaseAddr=FAN_PORT;
                NcNoGroup();
                break;
            case    IO_GROUP:
                GroupBaseAddr=F_ManualSpeed;
                IoGroup();
                break;
            case    USER_GROUP:       //save
                GroupBaseAddr=F_Ver0;
                UserGroup();
                break;
            case    OPEN_WAIT_GROUP:
                GroupBaseAddr=F_0506;
                WaitFlrGroup();
                break;
            case    PARAMETER_GROUP:
                GroupBaseAddr=ENCODER_PULSE;
                ParameterGroup();
                break;
            case    INPORT1_GROUP:
                GroupBaseAddr=EMG_PORT;
                InportGroup();
                break;
            case    INPORT2_GROUP:
                GroupBaseAddr=X0_PORT;
                InportGroup();
                break;
            case    OUTPORT_GROUP:
                GroupBaseAddr=FAN_PORT;
                OutportGroup();
                break;
            case    ERROR_GROUP:
                ErrorGroup(LadderGroupSub);
                break;
            case    EL_GROUP:
                GroupBaseAddr=ENCODER_PULSE;
                ELGroup();
                break;
	#ifdef	DELTA_INVERTER
			case    DELTA_PAR_GROUP_00:
			case    DELTA_PAR_GROUP_01:
	        case    DELTA_PAR_GROUP_02:
	        case    DELTA_PAR_GROUP_03:
	        case    DELTA_PAR_GROUP_04:
	        case    DELTA_PAR_GROUP_05:
	        case    DELTA_PAR_GROUP_06:
	        case    DELTA_PAR_GROUP_07:
	        case    DELTA_PAR_GROUP_08:
	        case    DELTA_PAR_GROUP_09:
	        case    DELTA_PAR_GROUP_10:
	        case    DELTA_PAR_GROUP_11:
	        case    DELTA_PAR_GROUP_12:
	        case    DELTA_PAR_GROUP_13:
	        case    DELTA_PAR_GROUP_14:
				Delta_inverter_Par_Group();
				DeltaRdWrStatus=1;
				break;
	#endif
            default:                
                break;
    
        }
    }



   	LadderBuf[C_BASE_MEMORY]=LadderGroup;              
   	LadderBuf[C_OFFSET_MEMORY]=LadderGroupSub;          



	if(bMoveCar){
		SpeedDsp();
       	DefaultDisplay();
		EnterKey=0;
	}
    else if(LadderGroup==0){
		SpeedDsp();
        DefaultDisplay();
	}


    LadderTime=0;



	if(sRamDArry[FHM_SEQ] <= FHM_SEQ_7){
		FhmLoaderTime=0;
	}
	else{
		FhmLoaderTime=15;
	}


    if(New_Spd_SystemChk()){
	    if(sRamDArry[AUTO_TUNING] > AUTOTUN_SEQ_0)          TuningLoaderTime=0;
	    else                                                TuningLoaderTime=15;	                                    
	}


	if((LadderGroup != USER_GROUP) || (LadderGroupSub != HALL_IND_SET) || !IN_AUTO || (sRamDArry[DSP1] != '9') || (sRamDArry[DSP2] != '1')){
		HibSet[0]=0;
		HibSet[1]=0;
		HibSet[2]=0;
		HibSet[3]=0;
		HibSet[4]=0;
		HibSet[5]=0;
		bHibSet=0;	
	}


        
	#ifdef	DELTA_INVERTER

	bDeltaGroupEdit=0;	
	delta_rdwr_valid=0;

	if(bsInvCurNext){		    	
		delta_rdwr_valid=1;
		DeltaInverterRdWr( (unsigned char)(4),(unsigned char)(23),1,0,sRamDArry[S0_FLOOR]);
	}
	else if( (LadderGroup >= DELTA_PAR_GROUP_00) && (LadderGroup < DELTA_PAR_GROUP_END) && (DeltaRdWrStatus > 0)){
		bDeltaGroupEdit=1;
		DeltaInverterRdWr( (unsigned char)(LadderGroup-DELTA_PAR_GROUP_00),(unsigned char)LadderGroupSub,0,0,0);

//		if(DeltaRdWrStatus==0)	EnterKey=1;            

		delta_rdwr_valid=1;
	}
	else if( (LadderGroup == USER_GROUP) && (LadderGroupSub == FHM_RUN_CHK) ){		    	
		delta_rdwr_valid=1;
	}
	else{
		delta_rdwr_valid=0;
	}
	
	if(delta_rdwr_valid==0){
		DeltaRdWrStatus=0;
	}

	#endif

    return(0);
}




void  __attribute__((section(".usercode"))) Ladder485Init(void)
{
    LocalType i;

    LadderGroup=0;
    LadderGroupSub=0;

    MaxSubMenu=USER_GROUP_MAX;   //save

    NewMenuStart();

    for(i=0;i<MAX_LADDER_BUF-2;i++)   New485Ladder[i]=' ';

    New485Ladder[MAX_LADDER_BUF-1]=0x0;


/*
	PasswardCheck();
    bAllMenu=0;
    bUserOn=0;
	bExportData=0;
	bImportData=0;
*/

}




#ifdef	FLOOR_64
void  __attribute__((section(".usercode"))) Pc_Command(void)
{
    if((CAN2_RxBuf[2] == (CMD_EVEN_ODD)) && (CAN2_RxBuf[3] == 0x00)){

		ShadowsRamDArry[FLR_ON_OFF0] = CAN2_RxBuf[4];
		ShadowsRamDArry[FLR_ON_OFF1] = CAN2_RxBuf[5];
		ShadowsRamDArry[FLR_ON_OFF2] = CAN2_RxBuf[6];
		ShadowsRamDArry[FLR_ON_OFF3] = CAN2_RxBuf[7];		

//		ShadowsRamDArry[FLR_ON_OFF4] = CAN2_RxBuf[4];
//		ShadowsRamDArry[FLR_ON_OFF5] = CAN2_RxBuf[5];
//		ShadowsRamDArry[FLR_ON_OFF6] = CAN2_RxBuf[6];
//		ShadowsRamDArry[FLR_ON_OFF7] = CAN2_RxBuf[7];		
    }    
    else if((CAN2_RxBuf[2] == (CMD_MORNING)) && (CAN2_RxBuf[3] == 0x00)){
//		if(CAN2_RxBuf[4] > 0)		bExt_HOME_RETURN=1;		
//		else						bExt_HOME_RETURN=0;		

		CmdFixFlrTime= CAN2_RxBuf[4];
    }    
}

#else

void  __attribute__((section(".usercode"))) Pc_Command(void)
{
    if((CAN2_RxBuf[2] == (CMD_EVEN_ODD)) && (CAN2_RxBuf[3] == 0x00)){
		ShadowsRamDArry[FLR_ON_OFF0] = CAN2_RxBuf[4];
		ShadowsRamDArry[FLR_ON_OFF1] = CAN2_RxBuf[5];
		ShadowsRamDArry[FLR_ON_OFF2] = CAN2_RxBuf[6];
		ShadowsRamDArry[FLR_ON_OFF3] = CAN2_RxBuf[7];		

//		sRamDArry[ExtCmdFlrONOFF0] = CAN2_RxBuf[4];
//		sRamDArry[ExtCmdFlrONOFF1] = CAN2_RxBuf[5];
//		sRamDArry[ExtCmdFlrONOFF2] = CAN2_RxBuf[6];
//		sRamDArry[ExtCmdFlrONOFF3] = CAN2_RxBuf[7];		
    }    
    else if((CAN2_RxBuf[2] == (CMD_MORNING)) && (CAN2_RxBuf[3] == 0x00)){		
		CmdFixFlrTime= CAN2_RxBuf[4];

//		if(CAN2_RxBuf[4] > 0)		bExt_HOME_RETURN=1;		
//		else						bExt_HOME_RETURN=0;		
    }    
}

#endif

