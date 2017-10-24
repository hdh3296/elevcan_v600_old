

#include  "iodef.h"
#include  "30f6010_io.h"            
#include  "default_setup.h" 
#include  "you_can2.h" 
#include  "ladder485.h" 


void  __attribute__((section(".usercode"))) Delta_Par_DataSort(unsigned int this_data);
void  __attribute__((section(".usercode"))) Pc_Command(void);

//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////


//extern	UserDataType    you_plank_length,you_ind_length;     




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
UserDataType    DecimalPt;
UserDataType    MaxSubMenu;
UserDataType    MemPointer;

//UserDataType    flrPt;


UserDataType   pw[4];

unsigned int   DigitData;
unsigned int   DigitMaxValue;
unsigned int   DigitMinValue;
unsigned int   DigitAttribute;
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


/*
const unsigned char BdName485[][4]={"000"," 01"," 02"," 03"," 04"," 05"," 06"," 07"," 08"," 09"," 10",
                                          " 11"," 12"," 13"," 14"," 15"," 16"," 17"," 18"," 19"," 20",
                                          " 21"," 22"," 23"," 24"," 25"," 26"," 27"," 28"," 29"," 30",
                                          " 31"," 32","AVO","BVO","CVO","DVO","AC1","AC2","AC3","AC4",
                                          "BC1","BC2","BC3","BC4","CC1","CC2","CC3","CC4","DC1","DC2",
                                          "DC3","DC4","AXO","AX1","BXO","BX1","CXO","CX1","DXO","DX1",
                                          "A_M","BM1","BM2","CM1","CM2","DM1","DM2","ALD","BLD","CLD",
                                          "DLD","APC","BPC","CPC","DPC"};

*/



const unsigned char GroupLineMessage[][17]={
                                    "FL:00           ",//0
///////////////////////////////////////////////////////////                                                                                                           
                                    "USER:Version    ",//1  
                                    "USER:BoardId    ",//2 
                                    "USER:AutoLanding",//3  
                                    "USER:UserLamp1  ",//4  
                                    "USER:UserLamp2  ",//5  
                                    "USER:Passward   ",//6  
                                    "USER:Normal Dsp ",//7  
                                    "USER:DriveMethod",//8 
                                    "USER:Fhm Run    ",//9 
                                    "USER:SubMenu On ",//10 
                                    "USER:Engineer Nm",//11 
                                    "USER:Not Use12  ",//12 
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
                                    "USER:User8      ",//30 
                                    "USER:System Mode",//31  
                                    "USER:User9      ",//32 
//////////////////////////////////////////////////////////////////
                                    "FLR:TopFlr      ",//1 
                                    "FLR:PrkFlr      ",//2 
                                    "FLR:NoUse Go Flr",//3 
                                    "FLR:FireSafe Flr",//4 
                                    "FLR:Reserve     ",//5 
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
#ifdef	RUSSIA_HALL_DOOR_STOP
                                    "USER:SafePrtTime",//26 
#else
                                    "TMR:Not Use Time",//26
#endif
                                    "TMR:Stop10  Time",//27
                                    "TMR:Stop11  Time",//28
                                    "TMR:Stop12  Time",//29
                                    "TMR:Stop13  Time",//30
                                    "TMR:Stop14  Time",//31
                                    "TMR:Stop15  Time",//32
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
                                    "ONOFF2:NextFlChk",//10  
                                    "ONOFF2:H_Dr1 Chk",//11
                                    "ONOFF2:Reserve  ",//12 
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
                                    "ONOFF2:UcmpOnOff",//28
                                    "ONOFF2: E/V Use ",//29
                                    "ONOFF2:Not Use  ",//30
                                    "ONOFF2:Copy_Encd",//31
                                    "ONOFF2:Work Mode",//32
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
                                    "NcNo2:ManInsMode",//18 
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
                                    "INP2:DOOR_HOLD  ",//17 
                                    "INP2:Man InsMode",//18 
                                    "INP2:VIRTUAL_X2 ",//19 
                                    "INP2:VIRTUAL_X3 ",//20 
                                    "INP2:VIRTUAL_X4 ",//21 
                                    "INP2:VIRTUAL_X5 ",//22 
                                    "INP2:VIRTUAL_X6 ",//23 
                                    "INP2:VIRTUAL_X7 ",//24
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
                                    "OUTP:Not Use    ",//32 
///////////////////////////////////////////////////////////                                                                                                           
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
                                    "E/L:DecSpd Mpm  ",//14 
                                    "E/L:D_Time(sec) ",//15  
                                    "E/L:S_Time(sec) ",//16  
                                    "E/L:SuSd2 Spd   ",//17 
                                    "E/L:X0X1  Spd   ",//18 
                                    "E/L:Position(mm)",//19 
                                    "E/L:Not Use     ",//20 
                                    "E/L:Not Use     ",//21 
                                    "E/L:Not Use     ",//22  
                                    "E/L:Not Use     ",//23 
                                    "E/L:Not Use     ",//24 
                                    "E/L:Not Use     ",//25 
                                    "E/L:Not Use     ",//26 
                                    "E/L:Not Use     ",//27  
                                    "E/L:Not Use     ",//28 
                                    "E/L:Plank/Mpm   ",//29  
                                    "E/L:Base_Pos(mm)",//30 
                                    "E/L:Mpm Variable",//31 
                                    "E/L:MmPerPulse  ",//32
                                };


const	uint8_t	F_SpeMenuName[][17]={
									"ER:NO ERRORE(01)",
									"DSP:Floor01     ",
									"ONOFF1:Floor01  ",
									"DOOR-S:Floor01  ",
									"Level:Floor01   ",
								};


#ifdef	FLOOR_64
const unsigned char DSP_CHAR[] 		={"DSP:Floor01     "};
const unsigned char FLR_ONOFF[]		={"ONOFF1:Floor01  "};
const unsigned char DOOR_MAIN_SUB[]	={"DOOR-S:Floor01  "};
#endif
						
			   
const unsigned char FhmSuccessMsg[16]     ="  FHM Success   "; 
//const unsigned char AutoTun_SuccessMsg[16]="Tunning Success "; 
//const unsigned char AutoTun_FailMsg[16]   =" Tunning Fail   "; 

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
                                    "NextFlr_Run",   
                                    "HolDr1  Use",   
                                    "Reserve    ",   
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
                                    "UcmpChk On ",   
                                    "Normal E/V ",   
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
                                    "NextFl_Stop",   
                                    "H_Dr1 N_Use",   
                                    "Reserve    ",   
                                    "S_Sft N_Use",   
                                    "Mgt Mon Off",   
                                    "Encod N_Use",   
                                    "Relevel Off",   
                                    "Oil_Type   ",   
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
                                    "UcmpChk Off",   
                                    "Emgency E/V",   
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
                                    "Dec/100mm  ", 
                                    "Low_Spd    ",
                                    "Mid_Spd    ", 
                                };




//#define		TEST_AUTOLANDING				4

const uint8_t 	AUTO_LANDING_FIRST[2][16]={
                                    "E/L:L_Spd  Mpm  ",//11  
                                    "E/L:M_Spd  Mpm  ",//12  
							};


//#ifdef	AUTO_LANDING_485
#define     AUTO_LANDING_MESSAGE_CNT  		5

const unsigned char AUTO_LANDING_MSG[AUTO_LANDING_MESSAGE_CNT][11]={
                                    "Not Use    ",    
                                    "EDS_485    ",
                                    "VL_485     ",
                                    "L1000_485  ",
                                    "UserLanding",
                                };

/*
//#endif
//#ifdef	AUTO_LANDING_CAN

#elif defined(AUTO_LANDING_CAN)

#define     AUTO_LANDING_MESSAGE_CNT  		3
const unsigned char AUTO_LANDING_MSG[AUTO_LANDING_MESSAGE_CNT][11]={
                                    "Not Use    ",    
                                    "EDS_CAN    ",
                                    "DELTA_At   ",
                                };

#else
#define     AUTO_LANDING_MESSAGE_CNT  		4
const unsigned char AUTO_LANDING_MSG[AUTO_LANDING_MESSAGE_CNT][11]={
                                    "Not Use    ",    
                                    "Not Use    ",
                                    "Not Use    ",
                                };
#endif
*/


/*
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

*/


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
                                    "18.Sensor:123456",  //0
                                    "18.Plank :000000",  //1
                                    "18.SDS   :000000",  //2
                                    "18.SUS   :000000",  //3
                                    "18.SD1   :000000",  //4
                                    "18.SU1   :000000",  //5
                                    "18.X1(DL):000000",  //6
                                    "18.X0(UL):000000",  //7
                                    "18.Center:000000",  //8
                                    "18.nc2   :000000",  //9
                                    "18.L_Dec :000000",  //10
                                    "18.M_Dec :000000",  //11
                                    "18.H_Dec :000000",  //12
                                    "18.00_Flr:000000",  //13
                                };




const unsigned char FinalErrMessage[FINAL_ERR_DSP_MESSAGE_CNT][16]={		
                                    "28.00/00-00  *00",  //0
                                    "28.No Error     ",  //1
                                    "28.Dec :        ",  //2
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
                                    "28.Slip:00000000",  //15
                                    "28.puls:00000000",  //16
                                    "28.Slip:00000000",  //17
                                };


const unsigned char WhyDecMessage[][8]={		
                                    "No  Dec ",  //0
                                    "SUS Dec ",  //1
                                    "SDS Dec ",  //2
                                    "SU1 Dec ",  //3
                                    "SD1 Dec ",  //4
                                    "X0  Dec ",  //5
                                    "X1  Dec ",  //6
                                    "Enc High",  //7
                                    "Enc Low ",  //8
                                    "Dec Low ",  //9
                                    "Spd Go  ",  //10
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



const unsigned char WARNING_VAL[] 	        ={"Up/Dn Key Press."};


const unsigned char AutoTunMessage[][16]={
                                      "Tuning Stop   ",                                      
                                      "Tuning Up Run ",                                       
                                      "Tuning Dn Run ",                                       
                                      "Tuning Run... ",                                       
                                    };                                       



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
                                      "Current(A) ",                                                                            
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
                                      "PowerOnTime",
                                      "Err Counter",
                                      "Can Com Chk",
                                      "485 Com Chk",
                                      "Slip  mm   ",
                                      "ZeroSpd mm ",
                                      "Slip mm-Flr",
                                      "  Debug00  ",
                                      "  Debug01  ",
                                      "  Debug02  ",
                                      "  Debug03  ",
                                      "  Debug04  ",
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



   
const unsigned char ClearMessage[][11]={
									"Clear      ",                                      
                                 };




const unsigned char InputName[6][3]={
                                      "EMG",                                      
                                      "SUS",    
                                      "RG ",   
                                      "FR1",                                      
                                      "X0 ",    
                                      "FS0",   
                                    };                                       



const unsigned char blinkx[]        ="                ";  



void  __attribute__((section(".usercode")))	FirstMenuReDsp(uint8_t	sel)
{
	unsigned char	i;
		
	for(i=0;i<16;i++){
		New485Ladder[i+2]=F_SpeMenuName[sel][i];
	}
	
	switch(sel){
		case	0:			// err  group
			i=15;
			break;
		case	1:			// dsp group
			i=11;
			break;
		case	2:			// onoff1 group
			i=14;
			break;
		case	3:			//door sel group
			i=14;
			break;
		case	4:			//door sel group
			i=13;
			break;
	}		
	New485Ladder[(i+0)]=( (LadderGroupSub+1) /  10)+ '0';
	New485Ladder[(i+1)]=( (LadderGroupSub+1) % 10)+ '0';										
}



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

/*
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

	New485Ladder[SECONDLINE_BASE+EditBlanck+0] = man  + '0';                     
	New485Ladder[SECONDLINE_BASE+EditBlanck+1] = chun + '0';                     
	New485Ladder[SECONDLINE_BASE+EditBlanck+2] = bek  + '0';                     
	New485Ladder[SECONDLINE_BASE+EditBlanck+3] = sip  + '0';                       
	New485Ladder[SECONDLINE_BASE+EditBlanck+4] = il   + '0';                      

	Deciml_Dsp(5,dp);
}



void    __attribute__((section(".usercode"))) Sipman_Dsp(unsigned long vx,unsigned int dp)
{
    unsigned long value;
	value=vx;
	
    New485Ladder[SECONDLINE_BASE+EditBlanck+0]=(value/100000)    + '0';
    value=value%100000;              
    New485Ladder[SECONDLINE_BASE+EditBlanck+1]=(value/10000)     + '0';
    value=value%10000;              
    New485Ladder[SECONDLINE_BASE+EditBlanck+2]=(value/1000)      + '0';
    value=value%1000;                        
    New485Ladder[SECONDLINE_BASE+EditBlanck+3]=(value/100)      + '0';
    value=value%100;                        
    New485Ladder[SECONDLINE_BASE+EditBlanck+4]=(value/10)       + '0';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+5]=(value%10)       + '0';          

	Deciml_Dsp(6,dp);
}


void    __attribute__((section(".usercode"))) Bakman_Dsp(unsigned long vx,unsigned int dp)
{
    unsigned long value;
	value=vx;
	
    New485Ladder[SECONDLINE_BASE+EditBlanck+0]=(value/1000000)   + '0';
    value=value%1000000;              
    New485Ladder[SECONDLINE_BASE+EditBlanck+1]=(value/100000)    + '0';
    value=value%100000;              
    New485Ladder[SECONDLINE_BASE+EditBlanck+2]=(value/10000)     + '0';
    value=value%10000;              
    New485Ladder[SECONDLINE_BASE+EditBlanck+3]=(value/1000)      + '0';
    value=value%1000;                        
    New485Ladder[SECONDLINE_BASE+EditBlanck+4]=(value/100)      + '0';
    value=value%100;                        
    New485Ladder[SECONDLINE_BASE+EditBlanck+5]=(value/10)       + '0';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+6]=(value%10)       + '0';          

	Deciml_Dsp(7,dp);
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

	Deciml_Dsp(8,dp);
}
*/


void    __attribute__((section(".usercode"))) ValueToChar(unsigned long vx)
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
}



void    __attribute__((section(".usercode"))) Chunman_Dsp(unsigned long vx,unsigned int dp)
{
	ValueToChar(vx);
	Deciml_Dsp(8,dp);
}

void    __attribute__((section(".usercode"))) Bakman_Dsp(unsigned long vx,unsigned int dp)
{
	ValueToChar(vx);
    New485Ladder[SECONDLINE_BASE+EditBlanck+0]=New485Ladder[SECONDLINE_BASE+EditBlanck+1];
    New485Ladder[SECONDLINE_BASE+EditBlanck+1]=New485Ladder[SECONDLINE_BASE+EditBlanck+2];
    New485Ladder[SECONDLINE_BASE+EditBlanck+2]=New485Ladder[SECONDLINE_BASE+EditBlanck+3];
    New485Ladder[SECONDLINE_BASE+EditBlanck+3]=New485Ladder[SECONDLINE_BASE+EditBlanck+4];
    New485Ladder[SECONDLINE_BASE+EditBlanck+4]=New485Ladder[SECONDLINE_BASE+EditBlanck+5];
    New485Ladder[SECONDLINE_BASE+EditBlanck+5]=New485Ladder[SECONDLINE_BASE+EditBlanck+6];
    New485Ladder[SECONDLINE_BASE+EditBlanck+6]=New485Ladder[SECONDLINE_BASE+EditBlanck+7];
    New485Ladder[SECONDLINE_BASE+EditBlanck+7]=' ';
	Deciml_Dsp(7,dp);
}

void    __attribute__((section(".usercode"))) Sipman_Dsp(unsigned long vx,unsigned int dp)
{
	ValueToChar(vx);
    New485Ladder[SECONDLINE_BASE+EditBlanck+0]=New485Ladder[SECONDLINE_BASE+EditBlanck+2];
    New485Ladder[SECONDLINE_BASE+EditBlanck+1]=New485Ladder[SECONDLINE_BASE+EditBlanck+3];
    New485Ladder[SECONDLINE_BASE+EditBlanck+2]=New485Ladder[SECONDLINE_BASE+EditBlanck+4];
    New485Ladder[SECONDLINE_BASE+EditBlanck+3]=New485Ladder[SECONDLINE_BASE+EditBlanck+5];
    New485Ladder[SECONDLINE_BASE+EditBlanck+4]=New485Ladder[SECONDLINE_BASE+EditBlanck+6];
    New485Ladder[SECONDLINE_BASE+EditBlanck+5]=New485Ladder[SECONDLINE_BASE+EditBlanck+7];
    New485Ladder[SECONDLINE_BASE+EditBlanck+6]=' ';
    New485Ladder[SECONDLINE_BASE+EditBlanck+7]=' ';
	Deciml_Dsp(6,dp);
}


void    __attribute__((section(".usercode"))) Man_Dsp(unsigned long vx,unsigned int dp)
{
	ValueToChar(vx);
    New485Ladder[SECONDLINE_BASE+EditBlanck+0]=New485Ladder[SECONDLINE_BASE+EditBlanck+3];
    New485Ladder[SECONDLINE_BASE+EditBlanck+1]=New485Ladder[SECONDLINE_BASE+EditBlanck+4];
    New485Ladder[SECONDLINE_BASE+EditBlanck+2]=New485Ladder[SECONDLINE_BASE+EditBlanck+5];
    New485Ladder[SECONDLINE_BASE+EditBlanck+3]=New485Ladder[SECONDLINE_BASE+EditBlanck+6];
    New485Ladder[SECONDLINE_BASE+EditBlanck+4]=New485Ladder[SECONDLINE_BASE+EditBlanck+7];
    New485Ladder[SECONDLINE_BASE+EditBlanck+5]=' ';
    New485Ladder[SECONDLINE_BASE+EditBlanck+6]=' ';
    New485Ladder[SECONDLINE_BASE+EditBlanck+7]=' ';
	Deciml_Dsp(5,dp);
}



void  __attribute__((section(".usercode"))) NewdigitEdit(unsigned int this_data)
{
	unsigned int dp,i;


	EditStatus=DIGIT_EDIT;
//	DigitData=this_data;
	dp=DigitAttribute;	


	if(DigitMaxValue < 10){
	    ShiftCnt=1;
		if(dp == 1 )	ShiftCnt=3;
		Il_Dsp(this_data,dp);
	}
	else if(DigitMaxValue < 100){
	    ShiftCnt=2;
		if(dp == 1 )		ShiftCnt=3;
		else if(dp == 2 )	ShiftCnt=4;
		Sip_Dsp(this_data,dp);
	}
	else if(DigitMaxValue < 1000){
	    ShiftCnt=3;
		if(dp == 1 )		ShiftCnt=4;
		else if(dp == 2 )	ShiftCnt=4;
		else if(dp == 3 )	ShiftCnt=5;
		Bek_Dsp(this_data,dp);
	}
	else if(DigitMaxValue < 10000){
	    ShiftCnt=4;
		if(dp > 0 )	ShiftCnt++;
		Chun_Dsp(this_data,dp);
	}
	else{
	    ShiftCnt=5;
		if(dp > 0 )	ShiftCnt++;
		Man_Dsp(this_data,dp);
	}
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


void    __attribute__((section(".usercode"))) AmpDsp(unsigned int val)
{
    unsigned int chun;
	
	chun=val;
	Chun_Dsp(chun,2);

	New485Ladder[SECONDLINE_BASE+EditBlanck+5] = 'A';
//	New485Ladder[SECONDLINE_BASE+EditBlanck+6] = 'm';
//	New485Ladder[SECONDLINE_BASE+EditBlanck+7] = 'p';
//	New485Ladder[SECONDLINE_BASE+EditBlanck+8] = 'm';
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


void    __attribute__((section(".usercode"))) Mm_Dsp(unsigned long vx)
{
	Bakman_Dsp(vx,0);
    New485Ladder[SECONDLINE_BASE+EditBlanck+7] ='m';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+8] ='m';          
}




void    __attribute__((section(".usercode"))) MoveCounterDsp(void)
{


	Chunman_Dsp(MoveCounterx,0);

    New485Ladder[SECONDLINE_BASE+EditBlanck+8]  =' ';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+9]  ='m';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+10] ='o';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+11] ='v';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+12] ='e';          

/*
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
*/
}


void    __attribute__((section(".usercode"))) PowerOnTimeDsp(void)
{
	Chunman_Dsp(PowerOnTime,0);

    New485Ladder[SECONDLINE_BASE+EditBlanck+8]  =' ';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+9]  ='H';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+10] ='o';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+11] ='u';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+12] ='r';          


/*
    unsigned long value;


    value=PowerOnTime;

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
    New485Ladder[SECONDLINE_BASE+EditBlanck+8]  ='H';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+9]  ='o';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+10] ='u';          
    New485Ladder[SECONDLINE_BASE+EditBlanck+11] ='r';        
*/  
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
/*
    New485Ladder[SECONDLINE_BASE+EditBlanck+0]='E';
    New485Ladder[SECONDLINE_BASE+EditBlanck+1]='/';
    New485Ladder[SECONDLINE_BASE+EditBlanck+2]='B';
    New485Ladder[SECONDLINE_BASE+EditBlanck+3]=' ';
    New485Ladder[SECONDLINE_BASE+EditBlanck+4]=BdName485[ErrBdNamePt][0];
    New485Ladder[SECONDLINE_BASE+EditBlanck+5]=BdName485[ErrBdNamePt][1];
    New485Ladder[SECONDLINE_BASE+EditBlanck+6]=BdName485[ErrBdNamePt][2];
*/
}



void    __attribute__((section(".usercode"))) DspBdName(unsigned int i)
{
	unsigned int j;
	for(j=0;j<8;j++)	New485Ladder[SECONDLINE_BASE+EditBlanck+j]=BdName[i][j];
/*
	New485Ladder[SECONDLINE_BASE+EditBlanck+0]=BdName[i][0];
	New485Ladder[SECONDLINE_BASE+EditBlanck+1]=BdName[i][1];
	New485Ladder[SECONDLINE_BASE+EditBlanck+2]=BdName[i][2];
	New485Ladder[SECONDLINE_BASE+EditBlanck+3]=BdName[i][3];
	New485Ladder[SECONDLINE_BASE+EditBlanck+4]=BdName[i][4];
	New485Ladder[SECONDLINE_BASE+EditBlanck+5]=BdName[i][5];
	New485Ladder[SECONDLINE_BASE+EditBlanck+6]=BdName[i][6];
	New485Ladder[SECONDLINE_BASE+EditBlanck+7]=BdName[i][7];
*/
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
			DspBdName(0);
/*
            New485Ladder[SECONDLINE_BASE+EditBlanck+0]=BdName[0][0];
            New485Ladder[SECONDLINE_BASE+EditBlanck+1]=BdName[0][1];
            New485Ladder[SECONDLINE_BASE+EditBlanck+2]=BdName[0][2];
            New485Ladder[SECONDLINE_BASE+EditBlanck+3]=BdName[0][3];
            New485Ladder[SECONDLINE_BASE+EditBlanck+4]=BdName[0][4];
            New485Ladder[SECONDLINE_BASE+EditBlanck+5]=BdName[0][5];
            New485Ladder[SECONDLINE_BASE+EditBlanck+6]=BdName[0][6];
            New485Ladder[SECONDLINE_BASE+EditBlanck+7]=BdName[0][7];
*/
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
			DspBdName(1);
/*
            New485Ladder[SECONDLINE_BASE+EditBlanck+0]=BdName[1][0];
            New485Ladder[SECONDLINE_BASE+EditBlanck+1]=BdName[1][1];
            New485Ladder[SECONDLINE_BASE+EditBlanck+2]=BdName[1][2];
            New485Ladder[SECONDLINE_BASE+EditBlanck+3]=BdName[1][3];
            New485Ladder[SECONDLINE_BASE+EditBlanck+4]=BdName[1][4];
            New485Ladder[SECONDLINE_BASE+EditBlanck+5]=BdName[1][5];
            New485Ladder[SECONDLINE_BASE+EditBlanck+6]=BdName[1][6];
            New485Ladder[SECONDLINE_BASE+EditBlanck+7]=BdName[1][7];
*/
            New485Ladder[SECONDLINE_BASE+EditBlanck+5]= ((sRamDArry[mCallMe]-0x40)/10) + '0';
            New485Ladder[SECONDLINE_BASE+EditBlanck+6]= ((sRamDArry[mCallMe]-0x40)%10) + '0';
            break;
        case    0x80:
        case    0x81:
        case    0x82:
        case    0x83:
			DspBdName(3);
/*
            New485Ladder[SECONDLINE_BASE+EditBlanck+0]=BdName[3][0];
            New485Ladder[SECONDLINE_BASE+EditBlanck+1]=BdName[3][1];
            New485Ladder[SECONDLINE_BASE+EditBlanck+2]=BdName[3][2];
            New485Ladder[SECONDLINE_BASE+EditBlanck+3]=BdName[3][3];
            New485Ladder[SECONDLINE_BASE+EditBlanck+4]=BdName[3][4];
            New485Ladder[SECONDLINE_BASE+EditBlanck+5]=BdName[3][5];
            New485Ladder[SECONDLINE_BASE+EditBlanck+6]=BdName[3][6];
            New485Ladder[SECONDLINE_BASE+EditBlanck+7]=BdName[3][7];
*/
            New485Ladder[SECONDLINE_BASE+EditBlanck+3]= (sRamDArry[mCallMe] & 0x03) + '1';
            break;
        default:
			DspBdName(4);
/*
            New485Ladder[SECONDLINE_BASE+EditBlanck+0]=BdName[4][0];
            New485Ladder[SECONDLINE_BASE+EditBlanck+1]=BdName[4][1];
            New485Ladder[SECONDLINE_BASE+EditBlanck+2]=BdName[4][2];
            New485Ladder[SECONDLINE_BASE+EditBlanck+3]=BdName[4][3];
            New485Ladder[SECONDLINE_BASE+EditBlanck+4]=BdName[4][4];
            New485Ladder[SECONDLINE_BASE+EditBlanck+5]=BdName[4][5];
            New485Ladder[SECONDLINE_BASE+EditBlanck+6]=BdName[4][6];
            New485Ladder[SECONDLINE_BASE+EditBlanck+7]=BdName[4][7];
*/
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
//			i= ~i;
//			SetBitData(i);
			break;
		case	1:
			i=(LocalType)sRamDArry[I_SU1];
//			i= ~i;
//			SetBitData(i);
			break;
		case	2:
			i=(LocalType)sRamDArry[I_GR];
//			i= ~i;
//			SetBitData(i);
			break;
		case	3:
			i=(LocalType)sRamDArry[I_FIRE];
//			i= ~i;
//			SetBitData(i);
			break;
		case	4:
			i=(LocalType)sRamDArry[I_X_0];
//			i= ~i;
//			SetBitData(i);
			break;
		case	5:
			i=(LocalType)sRamDArry[I_FS0];
//			i= ~i;
//			SetBitData(i);
			break;
	}

	SetBitData(~i);												
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


void    __attribute__((section(".usercode"))) CurrentSpeedDsp(unsigned int pt)
{
    unsigned int chun,bek,sip,il,org;

/*
	chun=0;
	bek=0;
	sip=0;
	il=0;
*/
    org=(unsigned int)(CurMeterPerMin % 10000);
	chun=(org/1000);

    org=(unsigned int)(org % 1000);
    bek=(org/100);

    org=(unsigned int)(org % 100);
    sip=(org/10);

    il=(unsigned int)(org % 10);

/*
    sip=(org/100);


    if(chun)    il=(chun%10);
    
    if(chun)    sip=(chun/10);
    if(sip)     sip=(sip%10);

    if(chun)    bek=(chun/100);
    if(bek)     bek=(bek%10);

    if(chun)    chun=chun/1000;
    if(chun)    chun=(chun%10);
*/
	New485Ladder[2+(pt+0)]=' ';
	New485Ladder[2+(pt+1)]=' ';
	New485Ladder[2+(pt+2)] =chun + '0';
	New485Ladder[2+(pt+3)] =bek  + '0';
	New485Ladder[2+(pt+4)]=sip  + '0';
	New485Ladder[2+(pt+5)]='.';
	New485Ladder[2+(pt+6)]=il   + '0';
	New485Ladder[2+(pt+7)]='m';
	New485Ladder[2+(pt+8)]='p';
	New485Ladder[2+(pt+9)]='m';
}


void    __attribute__((section(".usercode"))) SpeedDsp(void)
{
    unsigned int count,tmpspddsp;
    unsigned int chun,bek,sip,il;

    chun=bek=sip=il=0;

	bExportData=0;
	bImportData=0;

/*
	New485Ladder[2+0]='F';
	New485Ladder[2+1]='L';
	New485Ladder[2+2]=':';
	if(sRamDArry[DSP1] == 0)	sRamDArry[DSP1] = '?';	
	if(sRamDArry[DSP2] == 0)	sRamDArry[DSP2] = '?';	
	New485Ladder[2+3]=sRamDArry[DSP1];
	New485Ladder[2+4]=sRamDArry[DSP2];
	New485Ladder[2+5]=' ';
*/

	New485Ladder[2+0]='F';
	New485Ladder[2+1]=':';
	if(sRamDArry[DSP1] == 0)	sRamDArry[DSP1] = '?';	
	if(sRamDArry[DSP2] == 0)	sRamDArry[DSP2] = '?';	
	New485Ladder[2+2]=sRamDArry[DSP1];
	New485Ladder[2+3]=sRamDArry[DSP2];
	New485Ladder[2+4]=' ';
	New485Ladder[2+5]=' ';


	if(CurMeterPerMin > 1)	tmpspddsp=1;
	else					tmpspddsp=0;

	if( (bCarUpMove || bCarDnMove) || (tmpspddsp > 0) ){ 
		if(PerfectAuto()){
			CurrentSpeedDsp(6);

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
			CurrentSpeedDsp(6);
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


//////test/////////////
	New485Ladder[2+4]='/';
	il=(UserDataType)(sRamDArry[mLuLdFloor] * 2);	        		
	il=(il + F_FlrDspCh);   
	New485Ladder[2+5]  = cF_FLRDSPCH((unsigned long)il);
	New485Ladder[2+6]  = cF_FLRDSPCH((unsigned long)(il+1)); 
//////test/////////////

}



unsigned int __attribute__((section(".usercode"))) TunningMessage(void)
{
	unsigned int i,j;

    j=sRamDArry[mSysStatus];
    for(i=0;i<16;i++)	New485Ladder[SECONDLINE_BASE+i] =StatusMessage[j][i];

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
			
			if(j==sInvertErr){
				New485Ladder[SECONDLINE_BASE+13]='E';	
				New485Ladder[SECONDLINE_BASE+14]= (InvErrNm/10) + '0';	
				New485Ladder[SECONDLINE_BASE+15]= (InvErrNm%10) + '0';	
			}    

/*    				
			#ifdef	RUSSIA_HALL_DOOR_STOP
			else if(j==sHDS_RUN_OFF){
				New485Ladder[SECONDLINE_BASE+12]=(HallDoorOpenFloor[0]/10)	+ '0';	
				New485Ladder[SECONDLINE_BASE+13]=(HallDoorOpenFloor[0]%10)	+ '0';	
				New485Ladder[SECONDLINE_BASE+14]=(HallDoorOpenFloor[1]/10)	+ '0';	
				New485Ladder[SECONDLINE_BASE+15]=(HallDoorOpenFloor[1]%10)	+ '0';	
			}        				
			#endif
*/

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

				if(j==sInvertErr){
					New485Ladder[SECONDLINE_BASE+13]='E';	
					New485Ladder[SECONDLINE_BASE+14]= (InvErrNm/10) + '0';	
					New485Ladder[SECONDLINE_BASE+15]= (InvErrNm%10) + '0';	
				}        				
				#ifdef	RUSSIA_HALL_DOOR_STOP
				else if(j==sHDS_RUN_OFF){
					New485Ladder[SECONDLINE_BASE+12]=(HallDoorOpenFloor[0]/10)	+ '0';	
					New485Ladder[SECONDLINE_BASE+13]=(HallDoorOpenFloor[0]%10)	+ '0';	
					New485Ladder[SECONDLINE_BASE+14]=(HallDoorOpenFloor[1]/10)	+ '0';	
					New485Ladder[SECONDLINE_BASE+15]=(HallDoorOpenFloor[1]%10)	+ '0';	
				}        				
				#endif

			}
		}
//	}
	return(0);
}


unsigned int __attribute__((section(".usercode"))) yymmdd_Dsp(unsigned int pt)
{
	New485Ladder[SECONDLINE_BASE+(pt+0)] =(sRamDArry[Year]    >> 4)      + '0';          
	New485Ladder[SECONDLINE_BASE+(pt+1)] =(sRamDArry[Year]    & 0x0f)    + '0';          
	New485Ladder[SECONDLINE_BASE+(pt+2)] ='-';          
	New485Ladder[SECONDLINE_BASE+(pt+3)] =(sRamDArry[Month]   >> 4)      + '0';          
	New485Ladder[SECONDLINE_BASE+(pt+4)] =(sRamDArry[Month]   & 0x0f)    + '0';          
	New485Ladder[SECONDLINE_BASE+(pt+5)] ='-';          
	New485Ladder[SECONDLINE_BASE+(pt+6)] =(sRamDArry[Day]     >> 4)      + '0';          
	New485Ladder[SECONDLINE_BASE+(pt+7)] =(sRamDArry[Day]     & 0x0f)    + '0';     
	return(0);     
}




unsigned int __attribute__((section(".usercode"))) DefaultDisplay(void)
{
    LocalType  i,j,k,sig;

	unsigned long tx1,tx2,tx3,slippulse;

    k=cF_NormalDsp;

    if(bCarErr || bCarStopNoRun || bFhmRun)    k=0;

//	if(LadderGroup != 0)	k=0;    

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
			if(WhoAutolanding==L1000_AUTOLANDING_485){
//24.00a
				tx1=(unsigned long)CurAmp;
				tx2=(tx1 * (unsigned long)2400);
				tx2=(tx2/(unsigned long)8192);
				AmpDsp((unsigned int)tx2);
			}
			else	AmpDsp(CurAmp);
            break;
        case    4:
			yymmdd_Dsp(0);
/*
            New485Ladder[SECONDLINE_BASE+0] =(sRamDArry[Year]    >> 4)      + '0';          
            New485Ladder[SECONDLINE_BASE+1] =(sRamDArry[Year]    & 0x0f)    + '0';          
            New485Ladder[SECONDLINE_BASE+2] ='/';          
            New485Ladder[SECONDLINE_BASE+3] =(sRamDArry[Month]   >> 4)      + '0';          
            New485Ladder[SECONDLINE_BASE+4] =(sRamDArry[Month]   & 0x0f)    + '0';          
            New485Ladder[SECONDLINE_BASE+5] ='/';          
            New485Ladder[SECONDLINE_BASE+6] =(sRamDArry[Day]     >> 4)      + '0';          
            New485Ladder[SECONDLINE_BASE+7] =(sRamDArry[Day]     & 0x0f)    + '0';          
*/
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
            PowerOnTimeDsp();
            break;
        case    16:
            ErrCounterDsp();
			break;
        case    17:
            CanComDsp();
            break;
        case    18:
            Rs485ComDsp();
            break;
        case    19:
			if(!bMoveCar){
				if(bSlipWard){					// upward
					if(SlipOrgPulse > SlipArrivePulse){
						slippulse=(SlipOrgPulse - SlipArrivePulse);
						sig='-';
//						PulseToMm((unsigned long)(SlipOrgPulse - SlipArrivePulse));
//						Mm_Dsp((unsigned long)(MmBuf));
//	    				New485Ladder[SECONDLINE_BASE+EditBlanck+0] ='-';          
					}
					else{
						slippulse=(SlipArrivePulse-SlipOrgPulse);
						sig='+';
//						PulseToMm((unsigned long)(SlipArrivePulse-SlipOrgPulse));
//						Mm_Dsp((unsigned long)(MmBuf));
//	    				New485Ladder[SECONDLINE_BASE+EditBlanck+0] ='+';          
					}
				}
				else{
					if(SlipOrgPulse >= SlipArrivePulse){
						slippulse=(SlipOrgPulse - SlipArrivePulse);
						sig='+';

//						PulseToMm((unsigned long)(SlipOrgPulse - SlipArrivePulse));
//						Mm_Dsp((unsigned long)(MmBuf));
//	    				New485Ladder[SECONDLINE_BASE+EditBlanck+0] ='+';          
					}
					else{
						slippulse=(SlipArrivePulse-SlipOrgPulse);
						sig='-';
//						PulseToMm((unsigned long)(SlipArrivePulse-SlipOrgPulse));
//						Mm_Dsp((unsigned long)(MmBuf));
//	    				New485Ladder[SECONDLINE_BASE+EditBlanck+0] ='-';          
					}
				}

				PulseToMm(slippulse);
				Mm_Dsp((unsigned long)(MmBuf));
	    		New485Ladder[SECONDLINE_BASE+EditBlanck+0] =(unsigned char)(sig);          



				i=sRamDArry[mRunFloor];
				i=(i * 2);
	            New485Ladder[SECONDLINE_BASE+EditBlanck+10] ='/';          
	            New485Ladder[SECONDLINE_BASE+EditBlanck+11] = cF_FLRDSPCH((unsigned long)i);          
	            New485Ladder[SECONDLINE_BASE+EditBlanck+12] = cF_FLRDSPCH((unsigned long)(i+1));          

				i=(sRamDArry[DEST_FLR] & ONLY_FLR);
				i=(i * 2);
	            New485Ladder[SECONDLINE_BASE+EditBlanck+13] ='-';          
	            New485Ladder[SECONDLINE_BASE+EditBlanck+14] = cF_FLRDSPCH((unsigned long)i);          
	            New485Ladder[SECONDLINE_BASE+EditBlanck+15] = cF_FLRDSPCH((unsigned long)(i+1));          
			}
			else	Mm_Dsp((unsigned long)(0));
        	break;
////////////////////////////////////////////////////
        case    20:
			if( !bMoveCar){
				PulseToMm((unsigned long)(ZeroHzPulse));
				Mm_Dsp((unsigned long)(MmBuf));
			}
			else	Mm_Dsp((unsigned long)(0));
        	break;
        case    21:
			Mm_Dsp((unsigned long)(Flr_Slip));

			i=sRamDArry[mcurfloor];
			i=(i * 2);
            New485Ladder[SECONDLINE_BASE+EditBlanck+10] ='/';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+11] = cF_FLRDSPCH((unsigned long)i);          
            New485Ladder[SECONDLINE_BASE+EditBlanck+12] = cF_FLRDSPCH((unsigned long)(i+1));          
        	break;
        case    22:   // debug00
//            CurEncoderPulse(cF_FLRDSPCH((unsigned long)(F_not_use1)));
//            CurEncoderPulse(CounterTime);
//            CurEncoderPulse(RxCurCnt);	
            CurEncoderPulse(TestEncoderCnt);	
        	break;
        case    23:		// debug01
            CurEncoderPulse(U1STA);
//            CurEncoderPulse(RxStatus);
//            CurEncoderPulse(TestEncoder);	
        	break;
        case    24:		// debug02
            CurEncoderPulse(DebugFlow0);
//            CurEncoderPulse(TestAvrEncoder);
        	break;
        case    25:		//// debug03
            CurEncoderPulse(DebugFlow1);
//            CurEncoderPulse(MaxEncoderPerMsec);
        	break;
/*
        case    26:
        	break;
*/
////////////////////////////////////////////////////
        default:
			Default_Cur_State_Display();
            break;
    }

	if(k != 17)	sRamDArry[mCallMe]=0x0;		//can com check 

	return(0);		
}



unsigned int  __attribute__((section(".usercode"))) CalendarChk(void)
{
	unsigned int xvalue;

    if(LadderGroup != USER_GROUP) 	return(0);
	if(EditStatus != CLOCK_EDIT)	return(0);

	switch(LadderGroupSub){
    	case    HH_MM_SS:
			xvalue=(New485Ladder[SECONDLINE_BASE+EditBlanck+0]-'0') * 10;
			xvalue=xvalue + (New485Ladder[SECONDLINE_BASE+EditBlanck+1]-'0');
			if(xvalue > 23){
                New485Ladder[SECONDLINE_BASE+EditBlanck+0]='0';
                New485Ladder[SECONDLINE_BASE+EditBlanck+1]='0';
			}

			xvalue=(New485Ladder[SECONDLINE_BASE+EditBlanck+3]-'0') * 10;
			xvalue=xvalue + (New485Ladder[SECONDLINE_BASE+EditBlanck+4]-'0');
			if(xvalue > 59){
                New485Ladder[SECONDLINE_BASE+EditBlanck+3]='0';
                New485Ladder[SECONDLINE_BASE+EditBlanck+4]='0';
			}

			xvalue=(New485Ladder[SECONDLINE_BASE+EditBlanck+6]-'0') * 10;
			xvalue=xvalue + (New485Ladder[SECONDLINE_BASE+EditBlanck+7]-'0');
			if(xvalue > 59){
                New485Ladder[SECONDLINE_BASE+EditBlanck+6]='0';
                New485Ladder[SECONDLINE_BASE+EditBlanck+7]='0';
			}
			break;
		case	YY_MM_DD:
		case	OUT_DATE:
			xvalue=(New485Ladder[SECONDLINE_BASE+EditBlanck+0]-'0') * 10;
			xvalue=xvalue + (New485Ladder[SECONDLINE_BASE+EditBlanck+1]-'0');
			if(xvalue > 99){
                New485Ladder[SECONDLINE_BASE+EditBlanck+0]='0';
                New485Ladder[SECONDLINE_BASE+EditBlanck+1]='0';
			}

			xvalue=(New485Ladder[SECONDLINE_BASE+EditBlanck+3]-'0') * 10;
			xvalue=xvalue + (New485Ladder[SECONDLINE_BASE+EditBlanck+4]-'0');
			if(xvalue > 12){
                New485Ladder[SECONDLINE_BASE+EditBlanck+3]='0';
                New485Ladder[SECONDLINE_BASE+EditBlanck+4]='0';
			}

			xvalue=(New485Ladder[SECONDLINE_BASE+EditBlanck+6]-'0') * 10;
			xvalue=xvalue + (New485Ladder[SECONDLINE_BASE+EditBlanck+7]-'0');
			if(xvalue > 31){
                New485Ladder[SECONDLINE_BASE+EditBlanck+6]='0';
                New485Ladder[SECONDLINE_BASE+EditBlanck+7]='0';
			}
			break;
		default:
			break;	
	}
	return(0);
}






 
unsigned int __attribute__((section(".usercode"))) SensorPositionDisplay(unsigned int pt)
{

	EditBlanck=10;

	switch(pt){
		case	SENSOR_LENGTH:
			PulseToMm(GET_LONG(BASE_SENSOR_PULSE));		
			break;
		case	PLANK_LENGTH:
			PulseToMm(GET_LONG(BASE_PLANK_PULSE));		
			break;
		case	SDS_LENGTH:
	    	OneceUseBuf1=FLOOR_COUNT(0);
			OneceUseBuf2=GET_LONG(BASE_SDS_PULSE);
			if(OneceUseBuf2 > 0)	OneceUseBuf2=(OneceUseBuf2- OneceUseBuf1);
			PulseToMm(OneceUseBuf2);		
			break;
		case	SUS_LENGTH:
	    	OneceUseBuf1=FLOOR_COUNT(cF_TOPFLR);
			OneceUseBuf2=GET_LONG(BASE_SUS_PULSE);
			if(OneceUseBuf2 > 0)	OneceUseBuf2=(OneceUseBuf1- OneceUseBuf2);
			PulseToMm(OneceUseBuf2);		
			break;
		case	SD1_LENGTH:
	    	OneceUseBuf1=FLOOR_COUNT(0);
			OneceUseBuf2=GET_LONG(BASE_SD1_PULSE);
			if(OneceUseBuf2 > 0)	OneceUseBuf2=(OneceUseBuf2- OneceUseBuf1);
			PulseToMm(OneceUseBuf2);		
			break;
		case	SU1_LENGTH:
	    	OneceUseBuf1=FLOOR_COUNT(cF_TOPFLR);
			OneceUseBuf2=GET_LONG(BASE_SU1_PULSE);
			if(OneceUseBuf2 > 0)	OneceUseBuf2=(OneceUseBuf1- OneceUseBuf2);
			PulseToMm(OneceUseBuf2);		
			break;
		case	X1_LENGTH:		// dn limt
	    	OneceUseBuf1=FLOOR_COUNT(0);
			OneceUseBuf2=GET_LONG(BASE_X1_PULSE);
			if(OneceUseBuf2 > 0)	OneceUseBuf2=(OneceUseBuf2- OneceUseBuf1);
			PulseToMm(OneceUseBuf2);		
			break;
		case	X0_LENGTH:		// up limt
	    	OneceUseBuf1=FLOOR_COUNT(cF_TOPFLR);
			OneceUseBuf2=GET_LONG(BASE_X0_PULSE);
			if(OneceUseBuf2 > 0)	OneceUseBuf2=(OneceUseBuf2- OneceUseBuf1);
			PulseToMm(OneceUseBuf2);		
			break;
		case	CENTER_LENGTH:
			OneceUseBuf2=GET_LONG(BASE_CENTER_PULSE);
			PulseToMm(OneceUseBuf2);		
			break;
		case	NC2_LENGTH:
			PulseToMm((unsigned long)(0));		
			break;
		case	L_DEC_LENGTH:
			GetDecreasePulse(SPEED_LOW);
			PulseToMm(CurSpdDecPulse);		
			break;
		case	M_DEC_LENGTH:
			GetDecreasePulse(SPEED_MID);
			PulseToMm(CurSpdDecPulse);		
			break;
		case	H_DEC_LENGTH:
			GetDecreasePulse(SPEED_HIGH);
			PulseToMm(CurSpdDecPulse);		
			break;
//		case	LEVEL_POSITION:
		default:
			if(pt == (unsigned int)(LEVEL_POSITION))	OneceUseBuf2=0;
			else{
//				flrPt=pt;
				pt=(pt - (unsigned int)(LEVEL_POSITION));		
		    	OneceUseBuf1=FLOOR_COUNT(0);
		    	OneceUseBuf3=FLOOR_COUNT(pt);
				OneceUseBuf2=(OneceUseBuf3- OneceUseBuf1);
			}
			PulseToMm(OneceUseBuf2);		
			break;
	}

	Sipman_Dsp(MmBuf,0);
	EditBlanck=0;

	return(0);		
}




unsigned int __attribute__((section(".usercode"))) FinalErrDisplay(unsigned int pt)
{

    LocalType  i,val;
    unsigned long  tx1,tx2;
	
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


			i= cF_FLRDSPCH((unsigned long)(F_E_LuLdFloor));
			i=(i * 2);
            New485Ladder[SECONDLINE_BASE+EditBlanck+11] = cF_FLRDSPCH((unsigned long)i);          
            New485Ladder[SECONDLINE_BASE+EditBlanck+12] = cF_FLRDSPCH((unsigned long)(i+1));          

//            New485Ladder[SECONDLINE_BASE+EditBlanck+10] = '(';          
//            New485Ladder[SECONDLINE_BASE+EditBlanck+11] = (unsigned char)((i/10) + '0');          
//            New485Ladder[SECONDLINE_BASE+EditBlanck+12] = (unsigned char)((i%10) + '0');          
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
			val= cF_FLRDSPCH((unsigned long)(F_E_FsdNm));
            for(i=0;i<8;i++){
                New485Ladder[SECONDLINE_BASE+EditBlanck+i] =WhyDecMessage[val][i];          
            }
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
        case    15:
			Chunman_Dsp( GET_LONG_BYTE((unsigned long)(F_E_D_ON_Pulse0)),0 );
            break;
        case    16:
	    	OneceUseBuf1=FLOOR_COUNT(0);
			OneceUseBuf2=GET_LONG_BYTE((unsigned long)(F_E_CurPulse0));
			OneceUseBuf2=(OneceUseBuf2- OneceUseBuf1);
			PulseToMm(OneceUseBuf2);
			Mm_Dsp(MmBuf);
			break;
        case    17:
			OneceUseBuf2=GET_LONG_BYTE((unsigned long)(F_E_D_ON_Pulse0));
			PulseToMm(OneceUseBuf2);
			Mm_Dsp(MmBuf);
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



void  __attribute__((section(".usercode"))) GroupSelect_New(void)
{

	switch(LadderGroupSelect){
        case    GROUP_01:    
			LadderGroup=USER_GROUP;
            break;
        case    GROUP_02:    
			LadderGroup=INV_PAR_GROUP_14;
            break;
        case    GROUP_03:    
			LadderGroup=FLR_DSP_GROUP;
            break;
        case    GROUP_04:
			LadderGroup=FLR_GROUP;
            break;
        case    GROUP_05:
			LadderGroup=TIMER_GROUP;
            break;
        case    GROUP_06:
			LadderGroup=ONOFF1_GROUP;
            break;
        case    GROUP_07: 
			LadderGroup=ONOFF2_GROUP;
            break;
        case    GROUP_08:
			LadderGroup=SUB_DOOR_GROUP;
            break;
        case    GROUP_09:
			LadderGroup=EL_GROUP;
            break;
        case    GROUP_10:
			LadderGroup=FLR_OFFSET_GROUP;
			break;
        case    GROUP_11:
			LadderGroup=OPEN_WAIT_GROUP;
            break;
        case    GROUP_12:
			LadderGroup=NCNO1_GROUP;
            break;
        case    GROUP_13:
			LadderGroup=NCNO2_GROUP;
            break;
        case    GROUP_14:
			LadderGroup=NCNO3_GROUP;
            break;
        case    GROUP_15:
			LadderGroup=INPORT1_GROUP;
            break;
        case    GROUP_16:
			LadderGroup=INPORT2_GROUP;
            break;
        case    GROUP_17:
			LadderGroup=OUTPORT_GROUP;
            break;            
        case    GROUP_18:
			LadderGroup=ERROR_GROUP;
            break;
        case    GROUP_19:
			LadderGroup=INV_PAR_GROUP_00;
			break;
        case    GROUP_20:
			LadderGroup=INV_PAR_GROUP_01;
			break;
        case    GROUP_21:
			LadderGroup=INV_PAR_GROUP_02;
			break;
        case    GROUP_22:
			LadderGroup=INV_PAR_GROUP_03;
			break;
        case    GROUP_23:
			LadderGroup=INV_PAR_GROUP_04;
			break;
        case    GROUP_24:
			LadderGroup=INV_PAR_GROUP_05;
			break;
        case    GROUP_25:
			LadderGroup=INV_PAR_GROUP_06;
			break;
        case    GROUP_26:
			LadderGroup=INV_PAR_GROUP_07;
			break;
        case    GROUP_27:
			LadderGroup=INV_PAR_GROUP_08;
			break;
        case    GROUP_28:
			LadderGroup=INV_PAR_GROUP_09;
			break;
        case    GROUP_29:
			LadderGroup=INV_PAR_GROUP_10;
			break;
      	case    GROUP_30:
			LadderGroup=INV_PAR_GROUP_11;
			break;
		case    GROUP_31:
			LadderGroup=INV_PAR_GROUP_12;
			break;
        case    GROUP_32:
			LadderGroup=INV_PAR_GROUP_13;
			break;
		default:
			LadderGroup=0;
			break;
	}
}



void  __attribute__((section(".usercode"))) GroupSelect(void)
{


		if(bInvCommActive485){
			GroupSelect_New();
		}
		else{
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
					LadderGroup=FLR_OFFSET_GROUP;
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
				default:
					LadderGroup=0;
					break;
			}
		}

/*
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

			default:
				LadderGroup=0;
				break;
		}
	}
*/

}


void  __attribute__((section(".usercode"))) NewMenuStart(void)
{
	PasswardCheck();

    EnterKey=0;
    Cursor=0;
    ShiftCnt=0;
    EditStatus=0;
    EditBlanck=0;
	
	DigitAttribute=0;	


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
        case    USER_GROUP:    //save
            MaxSubMenu=USER_GROUP_MAX;
            break;
        case    OPEN_WAIT_GROUP:
            MaxSubMenu=OPEN_WAIT_GROUP_MAX;
            break;
/*
        case    IO_GROUP: 
            MaxSubMenu=IO_GROUP_MAX;
            break;
        case    PARAMETER_GROUP:
            MaxSubMenu=PARAMETER_GROUP_MAX;
            break;
*/

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
        case    FLR_OFFSET_GROUP:
            MaxSubMenu=(cF_TOPFLR+1);
			break;
		default:
			#ifdef		AUTO_LANDING_COMM
				if(bInvCommActive485){
					Inv_Par_NewMenuStart();
				}
			#endif
			break;

    }
}


void  __attribute__((section(".usercode"))) AutoTunningMsgDsp(unsigned int val)
{
	unsigned int i,j;

    EditBlanck=3;

	j=val;
	for(i=0;i<16;i++){				
		New485Ladder[SECONDLINE_BASE+EditBlanck+i]=AutoTunMessage[j][i];
	}
}


void  __attribute__((section(".usercode"))) DigitStringMessage(void)
{
    LocalType i,value;

    switch(LadderGroup){
        case    FLR_OFFSET_GROUP:
				if(DigitData > LULD_OFFSET_CENTER)	value=(DigitData-LULD_OFFSET_CENTER);
				else								value=(DigitData);
	            New485Ladder[SECONDLINE_BASE+EditBlanck+0]= (unsigned char)(value + '0');
				New485Ladder[SECONDLINE_BASE+EditBlanck+1]='m';	
				New485Ladder[SECONDLINE_BASE+EditBlanck+2]='m';	
				if(DigitData > LULD_OFFSET_CENTER)	New485Ladder[SECONDLINE_BASE+EditBlanck-1]='-';
				else								New485Ladder[SECONDLINE_BASE+EditBlanck-1]=' ';	
				break;
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
/*
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
            break;
*/
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

				case	AUTOLANDING_MODE:
	                for(i=0;i<11;i++){
                    	New485Ladder[SECONDLINE_BASE+EditBlanck+i]=AUTO_LANDING_MSG[DigitData][i];
	                }
					break;

				case	NORMAL_DSP:
	                for(i=0;i<11;i++){
	                    New485Ladder[SECONDLINE_BASE+EditBlanck+i]=NormalDspMessage[DigitData][i];
	                }
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
//				case	SUBNM_NOTUSE0:
//					break;
				case	SUBNM_NOTUSE1:
					break;
				case	SUBNM_NOTUSE2:
					break;
				case	SUBNM_NOTUSE3:
					break;
				case	SUBNM_NOTUSE4:
					break;
				case	SUBNM_SNNSOR_POSITION:
					if(DigitData >= LEVEL_POSITION)	value=LEVEL_POSITION;
					else							value=DigitData;	

	                for(i=0;i<16;i++){
	                    New485Ladder[SECONDLINE_BASE+i]=SensorPositionMessage[value][i];
	                }

					if(DigitData >= LEVEL_POSITION){
						value=(DigitData - LEVEL_POSITION);
						value++;		
		                New485Ladder[SECONDLINE_BASE+3]= (unsigned char)((value/10) + '0');
		                New485Ladder[SECONDLINE_BASE+4]= (unsigned char)((value%10) + '0');
					}
					SensorPositionDisplay(DigitData);
					break;
				default:
					break;
			}
			break;
       default:
            break;

    }    
}



/*
void  __attribute__((section(".usercode"))) NewdigitEdit(unsigned int this_data)
{
	unsigned int dp,i;


	EditStatus=DIGIT_EDIT;
	DigitData=this_data;
	dp=DigitAttribute;	


	if(DigitMaxValue < 10){
	    ShiftCnt=1;
		if(dp == 1 )	ShiftCnt=3;
		Il_Dsp(DigitData,dp);
	}
	else if(DigitMaxValue < 100){
	    ShiftCnt=2;
		if(dp == 1 )		ShiftCnt=3;
		else if(dp == 2 )	ShiftCnt=4;
		Sip_Dsp(DigitData,dp);
	}
	else if(DigitMaxValue < 1000){
	    ShiftCnt=3;
		if(dp == 1 )		ShiftCnt=4;
		else if(dp == 2 )	ShiftCnt=4;
		else if(dp == 3 )	ShiftCnt=5;
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
*/


void  __attribute__((section(".usercode"))) Integer_Digit(void)
{
    unsigned int i,tmpdata;
    unsigned int value,valuex;



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

	valuex=value;

/*
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
*/

	if(EditStatus==DIGIT_EDIT){
		NewdigitEdit(valuex);
	}


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
void  __attribute__((section(".usercode"))) FlrOffsetGroup(void)
{
    LocalType i;

	FirstMenuReDsp(4) ;     

    i=(LadderGroupSub + GroupBaseAddr);
    Cursor=0;
    ShiftCnt=0;
    EditBlanck=7;
    EditStatus=DIGIT_STRING_EDIT;
	DigitMaxValue=(LULD_OFFSET_MAX+1);
    DigitMinValue=0;
    DigitData=cF_FLRDSPCH((unsigned long)(i+0));  
               
    Integer_Digit();                   
}


void  __attribute__((section(".usercode"))) FlrOffsetGroupSave(void)
{
/*
	offset=(offset *2);
	offset=(offset + F_FlrDspCh);
		
    DspCharSave(offset,ShiftCnt);
*/

    LocalType i;

    i=(LadderGroupSub + GroupBaseAddr);
    GetFlashDataToBufRam(F_LEVEL01);
    b_LdTmpBufRam(i)=(LocalType)(DigitData);
    flash_write_DspChar(F_LEVEL01);
}



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

	FirstMenuReDsp(1) ;                                   
}


void  __attribute__((section(".usercode"))) FlrDspGroupSave(LocalType offset)
{
	offset=(offset *2);
	offset=(offset + F_FlrDspCh);
		
    DspCharSave(offset,ShiftCnt);
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
            DigitMaxValue=SYSTEM_TOP_FLR+1;
            break;
        case    PRK_FLR:
        case    NO_USE_GO_FLR:
        case    FIRE_SAFE_FLR:
        case    WATER_SAFE_FLR:
		case	START_FLR:
		case	KIDS_KEY_CNT:
		case	X6_SAFE_FLR:
		case	X5_SAFE_FLR:
		    DigitMaxValue=SYSTEM_TOP_FLR+1;
			ShiftCnt=2;
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
        default:
    		EditStatus=NO_EDIT;
			break;
    }
    DigitData=cF_FLRDSPCH((unsigned long)i);
    DigitData=DigitData+1;
    Integer_Digit();    
}



unsigned int __attribute__((section(".usercode"))) FlrGroupSave(void)
{
    LocalType i;

    if( !FhmOnOffChk && (INVERTER_CHECK == IO)){
		if(LadderGroupSub==TOP_FLR){
			OneceUseBuf1=FLOOR_COUNT((DigitData-1));
			if(OneceUseBuf1 >= NO_FLR_PULSE)	return(0);													
			else if(OneceUseBuf1 == 0)			return(0);																
		}      
	}

    DigitData=DigitData-1;
    i=(LadderGroupSub + GroupBaseAddr);
    GetFlashDataToBufRam(F_BLOCK1);
    b_LdTmpBufRam(i)=(LocalType)(DigitData);
    flash_write_DspChar(F_BLOCK1);
	return(0);
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

	
		DigitData=cF_FLRDSPCH((unsigned long)(i+1));
		WaitFlrConvStr(2);
		New485Ladder[SECONDLINE_BASE+EditBlanck+4] ='-';          
	
		DigitData=cF_FLRDSPCH((unsigned long)(i+2));
		WaitFlrConvStr(5);
	
		DigitData=cF_FLRDSPCH((unsigned long)(i+3));
		WaitFlrConvStr(7);
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
	

	    b_LdTmpBufRam((unsigned long)(i))=(LocalType)(DigitData);

	
		i++;
		WaitFlrConv(2);

	    b_LdTmpBufRam((unsigned long)(i))=(LocalType)(DigitData);
	
		i++;
		WaitFlrConv(5);
	    b_LdTmpBufRam((unsigned long)(i))=(LocalType)(DigitData);
	
		i++;
		WaitFlrConv(7);
	    b_LdTmpBufRam((unsigned long)(i))=(LocalType)(DigitData);
	
		i++;
		WaitFlrConv(10);
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

        case    0:
        case    1:
		case	2:
        case    12:
        case    18:
        case    19:
        case    20:
        case    21:
        case    22:
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
*/

        case    3:
            i=(LadderGroupSub + F_OpWtTm);
            Cursor=0;
            EditBlanck=6;
            EditStatus=DIGIT_EDIT;
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

	ExtFanTimer = (unsigned int)(cF_FANTIME);
	ExtLightTimer = (unsigned int)(cF_LIGHTTIME);

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

    if(LadderGroup == ONOFF1_GROUP){		
		FirstMenuReDsp(2) ;                                   
	}


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


/*
void  __attribute__((section(".usercode"))) IoGroup(void)
{

#ifndef		AUTO_LANDING_485

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
    else{               
        ShiftCnt=3;
        EditBlanck=7;
        DigitMaxValue=220;
        DigitData=cF_FLRDSPCH((unsigned long)i);
        Integer_Digit();
    }

#endif

}



void  __attribute__((section(".usercode"))) IoGroupSave(void)
{

#ifndef		AUTO_LANDING_485
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

#endif

}
*/




void  __attribute__((section(".usercode"))) DoorGroup(void)
{    
	FirstMenuReDsp(3);
                                   
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
			if(BefPassWardKeyBuf[0] != '*')	New485Ladder[i+2 + 11]='1';
            break;

        case    AUTOLANDING_MODE:
            Cursor=0;
            ShiftCnt=0;
            EditBlanck=5;
            EditStatus=DIGIT_STRING_EDIT;
            DigitMaxValue=AUTO_LANDING_MESSAGE_CNT;
            DigitMinValue=0;
	        DigitData=cF_FLRDSPCH((unsigned long)F_AutoLandingMode);
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
//            DigitMaxValue=31;
            DigitMaxValue=63;
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

			yymmdd_Dsp((EditBlanck+0));
/*
            New485Ladder[SECONDLINE_BASE+EditBlanck+0] =(sRamDArry[Year]    >> 4)      + '0';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+1] =(sRamDArry[Year]    & 0x0f)    + '0';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+2]='-';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+3] =(sRamDArry[Month]   >> 4)      + '0';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+4] =(sRamDArry[Month]   & 0x0f)    + '0';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+5]='-';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+6] =(sRamDArry[Day]     >> 4)      + '0';          
            New485Ladder[SECONDLINE_BASE+EditBlanck+7] =(sRamDArry[Day]     & 0x0f)    + '0';          
*/
            break;
        case    OUT_DATE:
            Cursor=0;
            ShiftCnt=8;
            EditBlanck=5;
            EditStatus=CLOCK_EDIT;

			yymmdd_Dsp((EditBlanck+0));

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
/*
        case    TOTAL_USE_TIME:
            Cursor=0;
            ShiftCnt=5;
            EditBlanck=5;
            EditStatus=NO_EDIT;
            DigitMaxValue=0xffff;
            DigitMinValue=0;

            DigitData=PowerOnTime;
            Integer_Digit();

            New485Ladder[SECONDLINE_BASE+EditBlanck+5]='H';      
            New485Ladder[SECONDLINE_BASE+EditBlanck+6]='o';      
            New485Ladder[SECONDLINE_BASE+EditBlanck+7]='u';      
            New485Ladder[SECONDLINE_BASE+EditBlanck+8]='r';      
            break;
*/
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
		case    User_G8:
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

		case    YOU_TEST_VAL: 
/*
            Cursor=0;
            ShiftCnt=3;
            EditBlanck=3;
            EditStatus=DIGIT_EDIT;
            DigitMaxValue=201;
            DigitMinValue=0;
            i=F_YouTestVal;
            DigitData=cF_FLRDSPCH((unsigned long)i);
			if(DigitData > 200){
				DigitData = 200;
			} 
            Integer_Digit();
*/
           break;
        default:
            break;
    }


	if((LadderGroupSub != PASSWARD)){
		BefPassWardKeyBuf[0]='*';
		BefPassWardKeyBuf[1]='*';
		BefPassWardKeyBuf[2]='*';
		BefPassWardKeyBuf[3]='*';
	}

}


unsigned int  __attribute__((section(".usercode"))) NewSpdForceSet(void)
{
	SaveVerify = 0x55;

	GetFlashDataToBufRam(F_BLOCK2);
	b_LdTmpBufRam(F_ManualSpeed)    = P3_SPD;                   
	b_LdTmpBufRam(F_BatterySpeed)   = NONE_USE_SPD;      
	b_LdTmpBufRam(F_DecreaseSpeed)  = P1P2_SPD;                    
	b_LdTmpBufRam(F_FhmSpeed)       = NONE_USE_SPD;     
	b_LdTmpBufRam(F_Speed1)        	= P1P3_SPD;     
	b_LdTmpBufRam(F_Speed2)        	= P2P3_SPD;              
	b_LdTmpBufRam(F_Speed3)        	= P1P2P3_SPD;                 
	b_LdTmpBufRam(F_Su2Sd2_Velocity)= CHANGE_DEC_LIMIT_SUSD;      	//mpm
	b_LdTmpBufRam(F_X0X1_Velocity)  = NOT_USE_SPEED;     			//mpm   
	flash_write_DspChar(F_BLOCK2);
	

	GetFlashDataToBufRam(F_BLOCK1);
	bit_LdTmpBufRamSet(F_OnOff0,bFhmOnOff);	
	flash_write_DspChar(F_BLOCK1);


	ELGroupDataLoad();
	DefaultDecreaseLength_spd3();
	WriteFlash_spd3();


	CaluDecreasePulse_spd3();

	SaveVerify = 0x0;

	return(0);
}


unsigned int  __attribute__((section(".usercode"))) UserGroupSave(void)
{
    LocalType i,j,k,l;
	LocalType block_pt,befsystem;

    GetFlashDataToBufRam(F_BLOCK2);

    switch(LadderGroupSub){
        case    VERSION:
//        case    TOTAL_USE_TIME:
            break;
        case    BOARD_ID:
            i=F_Bd_Id;
            j=cF_FLRDSPCH((unsigned long)i);  // before bd id 


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
              
			if(j != DigitData){
				if(INVERTER_CHECK == IO){
					IO_Mode();
				}
				else if(INVERTER_CHECK == D_F){
					DF_Mode();
				}
			}    

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

				if(bUserOn){
					bInvMdfy=1;
				}

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

		    if(bPasswardOk){
				if( (PassWardKeyBuf[0] != '*') && (PassWardKeyBuf[1] != '*') && (PassWardKeyBuf[2] != '*') && (PassWardKeyBuf[3] != '*')){ 
					if( (PassWardKeyBuf[0] == BefPassWardKeyBuf[0]) && (PassWardKeyBuf[1] == BefPassWardKeyBuf[1]) && (PassWardKeyBuf[2] == BefPassWardKeyBuf[2]) && (PassWardKeyBuf[3] == BefPassWardKeyBuf[3])){ 
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
					else{
						BefPassWardKeyBuf[0]=PassWardKeyBuf[0];
						BefPassWardKeyBuf[1]=PassWardKeyBuf[1];
						BefPassWardKeyBuf[2]=PassWardKeyBuf[2];
						BefPassWardKeyBuf[3]=PassWardKeyBuf[3];
		
						PassWardKeyBuf[0]='*';
						PassWardKeyBuf[1]='*';
						PassWardKeyBuf[2]='*';
						PassWardKeyBuf[3]='*';

					}
				}
				else{
					PassWardKeyBuf[0]='*';
					PassWardKeyBuf[1]='*';
					PassWardKeyBuf[2]='*';
					PassWardKeyBuf[3]='*';
	
					BefPassWardKeyBuf[0]=PassWardKeyBuf[0];
					BefPassWardKeyBuf[1]=PassWardKeyBuf[1];
					BefPassWardKeyBuf[2]=PassWardKeyBuf[2];
					BefPassWardKeyBuf[3]=PassWardKeyBuf[3];
				}
			}
			else{
				PasswardCheck();
				if(bPasswardOk){
	                LadderGroup=0;
	                LadderGroupSub=0;
				}
			}

            break;
        case    AUTOLANDING_MODE:
			#ifndef	AUTO_LANDING_COMM	
				DigitData=0;
			#endif
        case    USER_LAMP1:
        case    USER_LAMP2:
        case    USER_LAMP3:
        case    USER_LAMP4:
        case    GROUP_NUMBER:
        case    LOCAL_NUMBER:
			if(LadderGroupSub == USER_LAMP1)			i=F_UserLamp1;
			else if(LadderGroupSub == USER_LAMP2)		i=F_UserLamp2;
			else if(LadderGroupSub == USER_LAMP3)		i=F_UserLamp3;
			else if(LadderGroupSub == USER_LAMP4)		i=F_UserLamp4;
			else if(LadderGroupSub == AUTOLANDING_MODE)	i=F_AutoLandingMode;
			else if(LadderGroupSub == LOCAL_NUMBER)		i=F_LocalNm;
			else										i=F_GroupNm;

            b_LdTmpBufRam((unsigned long)i)=(LocalType)(DigitData);
            flash_write_DspChar(F_BLOCK2);

			if(WhoAutolanding != (unsigned int)cF_AUTO_LANDING){
				SaveEEpromPulse();
				asm("RESET");
			}

            break;
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
			i=(unsigned int)cF_SystemSet;
			if( i == DigitData)	return(0);
			befsystem=i;

			if( DigitData==OLD_LAW_OLD_SPD)	return(0);
			if( DigitData==NEW_LAW_OLD_SPD)	return(0);


            i=F_SystemSet;
            b_LdTmpBufRam((unsigned long)i)=(unsigned char)(DigitData);
            flash_write_DspChar(F_BLOCK2);

			//////////////////////////BLOCK1//////////////////////////
			if((DigitData== OLD_LAW_NEW_SPD) &&  (befsystem == NEW_LAW_NEW_SPD)){
    			GetFlashDataToBufRam(F_BLOCK1);
		        bit_LdTmpBufRamSet(F_OnOff0,bDoorJumperOff    		% 8); 
		        bit_LdTmpBufRamSet(F_OnOff1,bBrkMgtUse        		% 8);
		        bit_LdTmpBufRamSet(F_OnOff2,bBrkOpenUse       		% 8);
            	flash_write_DspChar(F_BLOCK1);				
			}
			//////////////////////////BLOCK1//////////////////////////

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
					if(!bMoveCar){
						MoveCounterx=0;
						EEP_Save_All();
					}
                    break;
                case    2:
					if(!bMoveCar){
						Flash_ErrClear_All();
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
/*
        case    ENCODER_RATE:
            i=F_StopPulse0;
            i_LdTmpBufRam((unsigned long)i)=(LocalType)(DigitData);
            flash_write_DspChar(F_BLOCK2);
            break;
*/
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
/*
        case    YOU_TEST_VAL:
            i=F_YouTestVal;
            b_LdTmpBufRam((unsigned long)i)=(LocalType)(DigitData);
            flash_write_DspChar(F_BLOCK2);
            break;
*/

        default:
            break;

    }

	return(0);
}





void  __attribute__((section(".usercode"))) ELGroup(void)
{
	unsigned long	tmpPlulsex;
	unsigned int	i;

    switch(LadderGroupSub){
///////////////////////////////////////////////
/////////////long type data////////////////////
///////////////////////////////////////////////
        case    SUBNM_ENCODER_PULSE:
        case    SUBNM_MOTOR_RPM:
		    Cursor=0;
		    ShiftCnt=5;
		    EditBlanck=5;
		    EditStatus=DIGIT_EDIT;		
		    DigitMaxValue=0xffff;
		    DigitMinValue=0;
			if(LadderGroupSub==SUBNM_ENCODER_PULSE)			DigitData=(unsigned int)(GET_LONG((unsigned long)ENCODER_PULSE));    
			else if(LadderGroupSub==SUBNM_MOTOR_RPM)		DigitData=(unsigned int)(GET_LONG((unsigned long)RPM));    
		    Integer_Digit();
            break;
        case    SUBNM_TM_MPM:
		    Cursor=0;
		    ShiftCnt=4;
		    EditBlanck=4;
		    EditStatus=DIGIT_EDIT;		
		    DigitMaxValue=2110;
		    DigitMinValue=0;
			DigitAttribute=1;	
		    DigitData=(unsigned int)(GET_LONG((unsigned long)NEW_MPM));    
		    Integer_Digit();

			if(bPlankLandingOk){
			    EditBlanck=10;		
				New485Ladder[SECONDLINE_BASE+ (EditBlanck-1)] = '/';                     		
			    tmpPlulsex=(unsigned int)(PlankMpm);    
				Chun_Dsp(tmpPlulsex,1);
			    EditBlanck=4;		
			}
            break;
/*
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
*/
/////////////////////////////////////////////////////////////
        case    SUBNM_BASE_PULSE:
		    Cursor=0;
		    ShiftCnt=3;
		    EditBlanck=5;
		    EditStatus=DIGIT_EDIT;		
		    DigitMaxValue=BEF_LULD_PULSE_MAX;
		    DigitMinValue=0;
		    DigitData=(unsigned int)(GET_LONG((unsigned long)BASE_BEF_LULD_PULSE));    
			if(DigitData > BEF_LULD_PULSE_MAX)	DigitData=0;	
		    Integer_Digit();
            break;
/////////////////////////////////////////////////////////////
///////////////////////////////////////////////
/////////////char type data////////////////////
///////////////////////////////////////////////
/*
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
*/
        case    SUBNM_MANUAL_PORT:
        case    SUBNM_BATTERY_PORT:
        case    SUBNM_DEC_PORT:
        case    SUBNM_FHM_PORT:
        case    SUBNM_LOW_SPD_PORT:
        case    SUBNM_MID_SPD_PORT:
        case    SUBNM_HIGH_SPD_PORT:
	    	Cursor=0;
	        ShiftCnt=0;
	    	EditBlanck=5;
	        EditStatus=DIGIT_STRING_EDIT;   
	    	DigitMinValue=0;
			DigitMaxValue=IO_PORT_MESSAGE_CNT-1;
    		if(LadderGroupSub==SUBNM_LOW_SPD_PORT)		DigitData=cF_FLRDSPCH((unsigned long)F_Speed1);
    		else if(LadderGroupSub==SUBNM_MID_SPD_PORT)	DigitData=cF_FLRDSPCH((unsigned long)F_Speed2);
    		else if(LadderGroupSub==SUBNM_HIGH_SPD_PORT)DigitData=cF_FLRDSPCH((unsigned long)F_Speed3);
    		else if(LadderGroupSub==SUBNM_FHM_PORT)		DigitData=cF_FLRDSPCH((unsigned long)F_FhmSpeed);
    		else if(LadderGroupSub==SUBNM_DEC_PORT)		DigitData=cF_FLRDSPCH((unsigned long)F_DecreaseSpeed);
    		else if(LadderGroupSub==SUBNM_BATTERY_PORT)	DigitData=cF_FLRDSPCH((unsigned long)F_BatterySpeed);
    		else if(LadderGroupSub==SUBNM_MANUAL_PORT)	DigitData=cF_FLRDSPCH((unsigned long)F_ManualSpeed);
	        Integer_Digit();
            break;
/*
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
*/

        case    SUBNM_LOW_SPD_DEC_LENTH:
			if(bAutoLandingActive){			
				for(i=0;i<16;i++){
					New485Ladder[i+2]=AUTO_LANDING_FIRST[0][i];
				}
				
				Cursor=0;
				ShiftCnt=3;
				EditBlanck=4;
				EditStatus=DIGIT_EDIT;		
				DigitMaxValue=999;
				DigitMinValue=0;
				DigitAttribute=1;	
				DigitData=(unsigned int)(ThisUseLowSpd);    
				Integer_Digit();
			}
			else{
				Cursor=0;
				ShiftCnt=4;
				EditBlanck=5;
				EditStatus=DIGIT_EDIT;		
				DigitMaxValue=0xffff;
				DigitMinValue=0;
		    	DigitData=(unsigned int)(GET_LONG((unsigned long)DEC_LENGTH_SPD_LOW));    
				Integer_Digit();
			}	
            break;
        case    SUBNM_MID_SPD_DEC_LENTH:
			if(bAutoLandingActive){			
				for(i=0;i<16;i++){
					New485Ladder[i+2]=AUTO_LANDING_FIRST[1][i];
				}
				Cursor=0;
				ShiftCnt=4;
				EditBlanck=4;
				EditStatus=DIGIT_EDIT;		
				DigitMaxValue=1500;
				DigitMinValue=0;
				DigitAttribute=1;	
				DigitData=(unsigned int)(ThisUseMidSpd);    
				Integer_Digit();
			}
			else{
				Cursor=0;
				ShiftCnt=5;
				EditBlanck=5;
				EditStatus=DIGIT_EDIT;		
				DigitMaxValue=0xffff;
				DigitMinValue=0;		
		    	DigitData=(unsigned int)(GET_LONG((unsigned long)DEC_LENGTH_SPD_MID));    
				Integer_Digit();
			}	
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
        case    SUBNM_BASE_DEC_MPM:
		    Cursor=0;
		    ShiftCnt=3;
		    EditBlanck=5;
		    EditStatus=DIGIT_EDIT;		
		    DigitMaxValue=99;	// max 9.9 mpm
		    DigitMinValue=0;
			DigitAttribute=1;	
			DigitData=(unsigned int)(ThisUseDecSpd);    
		    Integer_Digit();
            break;
        case    SUBNM_BASE_DEC_TIME:
		    Cursor=0;
		    ShiftCnt=6;
		    EditBlanck=5;
		    EditStatus=DIGIT_EDIT;		
		    DigitMaxValue=10000;		// max 10 sec  10.000msec
		    DigitMinValue=0;
			DigitAttribute=3;	
		    DigitData=(unsigned int)(GET_LONG((unsigned long)BASE_DEC_TIME));    
		    Integer_Digit();
            break;
        case    SUBNM_BASE_SCURVE_TIME:
		    Cursor=0;
		    ShiftCnt=5;
		    EditBlanck=5;
		    EditStatus=DIGIT_EDIT;		
		    DigitMaxValue=5000;		// max 5 sec   5.000 sec	
		    DigitMinValue=0;
			DigitAttribute=3;	
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
			DigitMaxValue=(ELEV_SPEED_MESSAGE_CNT_SPD3-1);
	        DigitData=cF_FLRDSPCH((unsigned long)F_X0X1_Velocity);
	        Integer_Digit();
            break;
		case	SUBNM_SNNSOR_POSITION:
            Cursor=0;
            ShiftCnt=0;
            EditBlanck=5;
            EditStatus=DIGIT_STRING_EDIT;
            DigitMaxValue= (cF_TOPFLR + SENSOR_POSITION_MESSAGE_CNT);
            DigitMinValue=0;
            DigitData=0;
            Integer_Digit();
				break;
/*
        case    SUBNM_NOTUSE1:
        case    SUBNM_NOTUSE2:
        case    SUBNM_NOTUSE3:
        case    SUBNM_NOTUSE4:
        case    SUBNM_LIMIT_SU:
        case    SUBNM_LOW_SPD_PULSE:
        case    SUBNM_MID_SPD_PULSE:
        case    SUBNM_HIGH_SPD_PULSE:
		    EditStatus=NO_EDIT;		
			break;
*/		
///////////////////////////////////////////////
/////////////long type data////////////////////
///////////////////////////////////////////////
/*
        case    SUBNM_LIMIT_SU:
		    Cursor=0;
		    ShiftCnt=0;
		    EditBlanck=3;
		    EditStatus=NO_EDIT;		
		    DigitMaxValue=0xffff;
		    DigitMinValue=0;
    		tmpPlulsex=(GET_LONG((unsigned long)BASE_SU1_PULSE));    
			CurEncoderPulse(tmpPlulsex);
            break;
        case    SUBNM_LIMIT_SD:
		    Cursor=0;
		    ShiftCnt=0;
		    EditBlanck=3;
		    EditStatus=NO_EDIT;		
		    DigitMaxValue=0xffff;
		    DigitMinValue=0;
    		tmpPlulsex=(GET_LONG((unsigned long)BASE_SD1_PULSE));    
			CurEncoderPulse(tmpPlulsex);
            break;
*/

        case    SUBNM_USER_PLANK_MPM:
		    Cursor=0;
		    ShiftCnt=3;
		    EditBlanck=4;
		    EditStatus=DIGIT_EDIT;		
		    DigitMaxValue=999;
		    DigitMinValue=0;
			DigitAttribute=0;			
		    DigitData=(unsigned int)(GET_LONG((unsigned long)B_USER_PLANK_LENGTH));    
		    Integer_Digit();
			New485Ladder[SECONDLINE_BASE+ (EditBlanck+3)] = 'm';                     		
			New485Ladder[SECONDLINE_BASE+ (EditBlanck+4)] = 'm';                     		
				
////////////////////
		    EditBlanck=10;		
			New485Ladder[SECONDLINE_BASE+ (EditBlanck-1)] = '/';                     		
			tmpPlulsex=(unsigned int)(PlankMpm);
			Chun_Dsp(tmpPlulsex,1);
/////////////////////////		
		    EditBlanck=4;
			break;
/*
        case    SUBNM_LOW_SPD_PULSE:
		    Cursor=0;
		    ShiftCnt=0;
		    EditBlanck=3;
		    EditStatus=NO_EDIT;		
//		    DigitMaxValue=0xffff;
//		    DigitMinValue=0;
			CurEncoderPulse(SpdL_DecPulse);		
            break;
*/

        case    SUBNM_MPM_VARIABLE:
		    Cursor=0;
		    ShiftCnt=5;
		    EditBlanck=5;
		    EditStatus=NO_EDIT;		
		    DigitMaxValue=0xffff;
		    DigitMinValue=0;
			tmpPlulsex=ThisUseMpmVariable;
			Mm_Dsp((unsigned long)(tmpPlulsex));
            break;
        case    SUBNM_MM_PER_PULSE:
		    Cursor=0;
		    ShiftCnt=5;
		    EditBlanck=5;
		    EditStatus=NO_EDIT;		
		    DigitMaxValue=0xffff;
		    DigitMinValue=0;
    		tmpPlulsex=ThisUseMmPerPulse;    
			Mm_Dsp((unsigned long)(tmpPlulsex));
            break;
        default:
		    EditStatus=NO_EDIT;		
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
//			j=( (ENCODER_PULSE) % (ENCODER_PULSE));
			j=ENCODER_PULSE;
			break;
        case    SUBNM_TM_MPM:
//			j=( (NEW_MPM) % (ENCODER_PULSE));
			j=NEW_MPM;
			break;
        case    SUBNM_MOTOR_RPM:
//			j=( (RPM) % (ENCODER_PULSE));
			j=RPM;
			break;
        case    SUBNM_LOW_SPD_DEC_LENTH:
//			if(bAutoLandingActive)	j=( (DEC_PULSE_SPD_LOW) % (ENCODER_PULSE));
//			else					j=( (DEC_LENGTH_SPD_LOW) % (ENCODER_PULSE));

			if(bAutoLandingActive)	j=DEC_PULSE_SPD_LOW;
			else					j=DEC_LENGTH_SPD_LOW;
			break;
        case    SUBNM_MID_SPD_DEC_LENTH:
//			if(bAutoLandingActive)	j=( (DEC_PULSE_SPD_MID) % (ENCODER_PULSE));
//			else					j=( (DEC_LENGTH_SPD_MID) % (ENCODER_PULSE));
			if(bAutoLandingActive)	j=DEC_PULSE_SPD_MID;
			else					j=DEC_LENGTH_SPD_MID;
			break;
        case    SUBNM_HIGH_SPD_DEC_LENTH:
//			j=( (DEC_LENGTH_SPD_HIGH) % (ENCODER_PULSE));
			j=DEC_LENGTH_SPD_HIGH;
			break;
        case    SUBNM_BASE_DEC_MPM:
//			j=( (BASE_DEC_MPM) % (ENCODER_PULSE));
			j=BASE_DEC_MPM;
			DigitData=(unsigned int)(ConverteMpm(GET_LONG(MPM_VARIABLE),ThisUseMpmVariable,(unsigned long)(DigitData)));
			break;
        case    SUBNM_BASE_DEC_TIME:
//			j=( (BASE_DEC_TIME) % (ENCODER_PULSE));
			j=BASE_DEC_TIME;
			break;
        case    SUBNM_BASE_SCURVE_TIME:
//			j=( (BASE_SCURVE_TIME) % (ENCODER_PULSE));
			j=BASE_SCURVE_TIME;
			break;
/////////////////////
        case    SUBNM_BASE_PULSE:
//			j=( (BASE_BEF_LULD_PULSE) % (ENCODER_PULSE));
			j=BASE_BEF_LULD_PULSE;
			if(DigitData > DigitMaxValue)	DigitData=0;
			break;
        case    SUBNM_USER_PLANK_MPM:
//			j=( (B_USER_PLANK_LENGTH) % (ENCODER_PULSE));
			j=B_USER_PLANK_LENGTH;
			if(DigitData > DigitMaxValue)	DigitData=0;
			break;
//////////////////////////////////////////////
        case    SUBNM_MANUAL_PORT:
//			i=( (F_ManualSpeed) % (F_BLOCK2));
			i=F_ManualSpeed;
			break;
        case    SUBNM_BATTERY_PORT:
//			i=((F_BatterySpeed) % (F_BLOCK2));
			i=F_BatterySpeed;
			break;
        case    SUBNM_DEC_PORT:
//			i=( (F_DecreaseSpeed) % (F_BLOCK2));
			i=F_DecreaseSpeed;
			break;
        case    SUBNM_FHM_PORT:
//			i=( (F_FhmSpeed) % (F_BLOCK2));
			i=F_FhmSpeed;
			break;
        case    SUBNM_LOW_SPD_PORT:
//			i=( (F_Speed1) % (F_BLOCK2));
			i=F_Speed1;
			break;
        case    SUBNM_MID_SPD_PORT:
//			i=( (F_Speed2) % (F_BLOCK2));
			i=F_Speed2;
			break;
        case    SUBNM_HIGH_SPD_PORT:
//			i=( (F_Speed3) % (F_BLOCK2));
			i=F_Speed3;
			break;
        case    SUBNM_SU2SD2_SPD:
//			i=( (F_Su2Sd2_Velocity) % (F_BLOCK2));
			i=F_Su2Sd2_Velocity;
			break;
        case    SUBNM_X0X1_SPD:
//			i=( (F_X0X1_Velocity) % (F_BLOCK2));
			i=F_X0X1_Velocity;
			break;
		default:
			break;
	}


	if(j != 0xff){
		k=ENCODER_PULSE;
		j=(j % k);
		ELGroupDataLoad();
		l_LdTmpBufRam(j)=(unsigned long)DigitData;		
		WriteFlash_spd3();
		CaluDecreasePulse_spd3();
	}


	if(i != 0xff){
		k=F_BLOCK2;
		i=(i % k);
	    GetFlashDataToBufRam(F_BLOCK2);
	    b_LdTmpBufRam(i)=(LocalType)(DigitData);
	    flash_write_DspChar(F_BLOCK2);
	}        
}



/*
void  __attribute__((section(".usercode"))) ParameterGroup(void)
{
#ifndef		AUTO_LANDING_485

	unsigned long tmpPlulsex;

    LocalType i;
    
    i=(LadderGroupSub + GroupBaseAddr);

    Cursor=0;
    ShiftCnt=5;
    EditBlanck=5;
    EditStatus=DIGIT_EDIT;
	DigitAttribute=0;

    DigitMaxValue=0xffff;
    DigitMinValue=0;

    DigitData=(unsigned int)(GET_LONG((unsigned long)i));    
    tmpPlulsex=(GET_LONG((unsigned long)i));    

    if(LadderGroupSub==P_TM_MPM){
        DigitMaxValue=211;
        ShiftCnt=4;
		DigitAttribute=1;
    }
    
    Integer_Digit();

	if(LadderGroupSub >= P_MINDEC30){
		EditStatus=NO_EDIT;
		if(LadderGroupSub < P_PAR1){ 
	    	EditBlanck=3;
			CurEncoderPulse(tmpPlulsex);
		}
	}
#endif
}


void  __attribute__((section(".usercode"))) ParameterGroupSave(void)
{
#ifndef		AUTO_LANDING_485

    LocalType  i;

    for(i=0;i<16;i++){
        parameter_mirror[i]=FlashDspCharBuf[ENCODER_PULSE+i].long_data;  
    }

    l_LdTmpBufRam(LadderGroupSub)=(unsigned long)DigitData;

    flash_write(ENCODER_PULSE);

#endif
}
*/



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



void  __attribute__((section(".usercode"))) ErrorGroup(LocalType offset)
{
    LocalType i,j;

	FirstMenuReDsp(0) ;                                   


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
/*
        case    IO_GROUP:
			IoGroupSave();
            break;
*/
        case    USER_GROUP:    //save
            UserGroupSave();
            break;
        case    OPEN_WAIT_GROUP:
            WaitFlrGroupSave();
            break;
/*
        case    PARAMETER_GROUP:
            if(LadderGroupSub < P_MINDEC30){
	            ParameterGroupSave();
	            CaluDecreasePulse();
            }
            break;
*/
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
        case    FLR_OFFSET_GROUP:
			FlrOffsetGroupSave();
			break;
        default:
			#ifdef		AUTO_LANDING_COMM
				if(bInvCommActive485){
					Inv_Par_GroupSaveChk();
				}	
			#endif
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
    LocalType j,digCur;

    i=(SECONDLINE_BASE + EditBlanck + Cursor);

    switch(EditStatus){
        case    DIGIT_EDIT:		
		    i=(SECONDLINE_BASE + EditBlanck);
			digCur=Cursor;	

			for(j=Cursor;j<ShiftCnt; j++){
        		if((New485Ladder[i+j] == '.')){
					digCur=(Cursor+1);
					break;
				}
			}
			
//            switch(ShiftCnt-Cursor){
            switch(ShiftCnt-digCur){
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
    LocalType j,digCur;

    i=SECONDLINE_BASE + EditBlanck + Cursor;

    switch(EditStatus){
        case    DIGIT_EDIT:
		    i=(SECONDLINE_BASE + EditBlanck);
			digCur=Cursor;	
			for(j=Cursor;j<ShiftCnt; j++){
        		if((New485Ladder[i+j] == '.')){
					digCur=(Cursor+1);
					break;
				}
			}

//            switch(ShiftCnt-Cursor){
            switch(ShiftCnt-digCur){
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

    if(ShiftCnt==0){
 		Cursor=0;
	}
    else{
    	Cursor=(Cursor+1)%ShiftCnt; 
	}

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

    if(ShiftCnt==0){
     	Cursor=0;
	}
    else if(Cursor>0){
   		Cursor--;
	}
    else{
    	Cursor=ShiftCnt-1;
	}

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
    if(LadderGroup==FLR_OFFSET_GROUP){
    	if(INVERTER_CHECK != IO)	return(1);   // no display                                             
	}


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

///////////////////////////////////////////////
				case	ERR_ST_CNT:
				case	OUT_DATE:
					if( !bPasswardOk && !bAllMenu)	i=1;
					break;
///////////////////////////////////////////////

				default:
					break;
			}	
			break;
        case    EL_GROUP:
			switch(LadderGroupSub){
				case	SUBNM_BASE_DEC_TIME:
				case	SUBNM_BASE_DEC_MPM:
				case	SUBNM_BASE_PULSE:
				case	SUBNM_BASE_SCURVE_TIME:			
					if(bAutoLandingActive)			i=0;
					else							i=1;	
					break;				
				case	SUBNM_HIGH_SPD_DEC_LENTH:			
					if(!bAutoLandingActive)			i=0;
					else							i=1;	
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
//					case	ENCODER_RATE:
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
//	               	case    NCNO1_GS:
//	               	case    NCNO1_DS:
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


unsigned int  __attribute__((section(".usercode"))) ESC_KeyCheck(void)
{
    LocalType ret;

	ret=0;

	#ifdef		AUTO_LANDING_485
		if(bsInvertErr && bInvCommActive485){
			if( (inverterClrTime > 20) && !bMoveCar){		// 2sec
				if((LadderGroup==0) && (LadderGroupSub==0)){
					if((LadderKey == ESCKEY)){
						BefInvErrNm=0;
						ret=1;
					}
				}

				if(ret==0){
					if( (inverterTwoClrTime<INV_RECOVERY_TIME) && (BefInvErrNm==InvErrNm) && (InvErrNm>0) && !bInvRecoveryErr){
						inverterTwoClrTime=0;							
						ret=0;
					}
					else{
						switch(WhoAutolanding){
							case	EDS_AUTOLANDING_485:
							case	VL_AUTOLANDING_485:
								if( (InvErrNm == 11) || (InvErrNm == 12) || (InvErrNm == 13) || (InvErrNm == 14)){
									inverterTwoClrTime=0;							
									BefInvErrNm=InvErrNm;
									bInvRecoveryErr=1;
									ret=1;				
								} 
								break;
							default:
								break;
						}
					}
				}
			}
		}	
		else{
			inverterClrTime=0;
			bInvRecoveryErr=0;
			if(inverterTwoClrTime>=INV_RECOVERY_TIME){
				BefInvErrNm=0;
			}
		}
	#endif

	return(ret);
}


unsigned int  __attribute__((section(".usercode"))) KeyCheck(void)
{
    LocalType i,j,newmenu,ret;
    LocalType max_group_sel;

	ret=0;
	if(bSpeedDsp && !bFhmRun)	return(0);

	max_group_sel=MAX_GROUP_SPD3;

	if(bInvCommActive485){
		#ifdef	AUTO_LANDING_485
			if(WhoAutolanding==L1000_AUTOLANDING_485)	max_group_sel= (max_group_sel + 1);	
			else										max_group_sel= (max_group_sel + (INV_PAR_GROUP_END - INV_PAR_GROUP_00));
		#else
			max_group_sel= (max_group_sel + (INV_PAR_GROUP_END - INV_PAR_GROUP_00));
		#endif
	}


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
			AutotunUpDn=0;
			sRamDArry[AUTO_TUNING] = AUTOTUN_SEQ_0;		

			LadderGroupSelect=0;
			LadderGroup=0;
			LadderGroupSub=0;

			NewMenuStart();
			CursorOff();			
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
		bInvMdfy=0;
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
		BefDspMode=0xff;

        
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
/*
            case    IO_GROUP:
                GroupBaseAddr=F_ManualSpeed;
                IoGroup();
                break;
*/
            case    USER_GROUP:       //save
                GroupBaseAddr=F_Ver0;
                UserGroup();
                break;
            case    OPEN_WAIT_GROUP:
                GroupBaseAddr=F_0506;
                WaitFlrGroup();
                break;
/*
            case    PARAMETER_GROUP:
                GroupBaseAddr=ENCODER_PULSE;
                ParameterGroup();
                break;
*/
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
	        case    FLR_OFFSET_GROUP:
                GroupBaseAddr=F_LEVEL01;
                FlrOffsetGroup();
				break;
            default:                
				#ifdef		AUTO_LANDING_COMM
				if(bInvCommActive485){
					Inv_Par_Group();
				}
				#endif
                break;
    
        }
    }


   	LadderBuf[C_BASE_MEMORY]=LadderGroup;              
   	LadderBuf[C_OFFSET_MEMORY]=LadderGroupSub;          


#ifdef		AUTO_LANDING_COMM
	if(bInvCommActive485){
		if( (LadderGroup >= INV_PAR_GROUP_00) && (LadderGroup < INV_PAR_GROUP_END)){
			if(!bWarning){
				for(i=0;i<16;i++){
				    New485Ladder[SECONDLINE_BASE+i]=WARNING_VAL[i];
				}
		
				if(EnterKey==2){
					EnterKey=0;
					CursorOff();
				}
		
		    	if( (LadderKey == 'u') || (LadderKey == 'd')){
					LadderGroupSub=0;
					bWarning=1;
					EnterKey=0;
				}
			}
		}
		else{
			bWarning=0;
			bParWr=0;
			bParRd=0;
		}	
	}
#endif


/*
	if(bMoveCar || (LadderGroup==0)){
		SpeedDsp();
       	DefaultDisplay();
		if(bMoveCar){			
			CursorOff();
			bDftDspOn=1;
		}
	}
	else{
		if(bDftDspOn){
			EnterKey=0;
			bDftDspOn=0;
		}	
	}
*/
	
	if(LadderGroup==0){
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


    if(sRamDArry[AUTO_TUNING] > AUTOTUN_SEQ_0)          TuningLoaderTime=0;
    else                                                TuningLoaderTime=15;	                                    


	if((LadderGroup != USER_GROUP) || (LadderGroupSub != HALL_IND_SET) || !IN_AUTO || (sRamDArry[DSP1] != '9') || (sRamDArry[DSP2] != '1')){
		HibSet[0]=0;
		HibSet[1]=0;
		HibSet[2]=0;
		HibSet[3]=0;
		HibSet[4]=0;
		HibSet[5]=0;
		bHibSet=0;	
	}



	#ifdef	AUTO_LANDING_COMM				 
	if(bInvCommActive485){
		TunningStartEndCheck();
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

