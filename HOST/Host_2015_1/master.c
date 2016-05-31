
///////////////////////////////////////////////////
//ver 5.62  modify
// no use time   sec -> sec/ min
// relevel on/off  error modify
///////////////////////////////////////////////////


///////////////////////////////////////////////////
//ver 5.63  modify
// relevel 시 Error
// MM error modify
///////////////////////////////////////////////////

///////////////////////////////////////////////////
//ver 5.71-->5.72  modify
//power save mode   사용여부는 아래 1,2번 충족되어야함
//   사용시 :  1).timer group 08번 이  1-255 까지 되어있어야함( 인버터 가동시간)             
//             2).외부 결선도 되어있어야함
//autolanding 기능추가 ( n - spd 모드에서만 적용   E/L group 20번) 사용시 반드시 대성에 문의 
//passward -> '*' 있으면 무시  
//신법 에서 반드시 사용 dz error 추가  
///////////////////////////////////////////////////
///////////////////////////////////////////////////
//ver 5.72-->5.74  modify
// dac out time  25.5 ->  25 
// luld 센서 층 카운터  와  encoder 층 카운터 비교 -> floor match error 후 1층 복귀
// safety check(표시 강화) 
// encoder copy on/off 추가  onoff2 group 30번  copy on/off
///////////////////////////////////////////////////

///////////////////////////////////////////////////
//ver 5.74-->5.75  modify
// 야스까와 이버터  오토 랜딩시 층 중간에 멈출시 엘리베이터 에러 추가
// 부저,door slow  추가 (voice) 
///////////////////////////////////////////////////

///////////////////////////////////////////////////
//ver 5.75-->5.76 -> 6.00 modify
// bFlrMatchErr delete 
// encoderAB error  -> start시  Lu,Ld off  후 check
// 확장 i/o  8점  추가
// break,mgt,encoder,encoderAB error -> AUTO 버튼 AUTO 시  일단 stop 그리고 relevel(LU,LD) 후  도어 열고 (복구불가 에러)
// sensor position insert
// slip pulse 확인
// emergency error gbr error 확인  > slip,lope break,inverter,hall door,emergency
// motor move 시  display 수정
// final error 
// ucmp clear(old law ??)
// parking  manual mode ??? 
// door open relevel  시  ????????????????
// delta inverter  fhm ??
///////////////////////////////////////////////////


///////////////////////////////////////////////////
//ver 6.00 --> 6.01  modify
//door stop modify 
// 1).door stop input  select
// 2).door stop and wait time menu  insert( timer group 12번 "Op Hold Time"
// 3).op hold time > 30sec 보다크면  외부 hib에  stop 표시
//                 <=30sec 보다 작거나 같으면 open 후 설정타임동안 open 후  close  
//encoder slip 100mm -> 200mm
//door open 후 200mm 이상의 encoder pulse 가 들어오면  slip error(UCMP) 로 간주    
///////////////////////////////////////////////////

///////////////////////////////////////////////////
//ver 6.01 --> 6.02  modify
// -------slip,gov err modify---------- 
// 1).순간 정전시 slip,gov err -> slip,gov err  발생시 일단 slip,gov error 인지후 약 1.5초  동안 유지하면 error 를 인정하고
//      1.5 초  이내에  복구 되면  순간정전으로 인식하여   error 를 복구한다.      
// 2).encoder 에 의한 slip은 6.1과 동일
// -------next floor error modify--------
//    신법에서 next floor error 발생시 일단 정지하고 가까운 층으로 복귀후(LU or LD  하나라도 들어온경우) 멈추고 도어 open 후 멈추며 
//    수동,또는 power off-> power on 후에 복귀된다(구법에서는 정지후 레벨찾고 정상 운행, 유압식은 바로 정이하고 복구 불가) 
///////////////////////////////////////////////////


///////////////////////////////////////////////////
//ver 6.02 --> 6.03  modify
// ------- vip  err modify---------- 
// 1).전용운전 ERROR  수정
///////////////////////////////////////////////////


///////////////////////////////////////////////////
//ver 6.03 --> 6.04  modify
// group16번 이상 Error 수정   
// group32번 수정 ->    63번 까지  수정
///////////////////////////////////////////////////


///////////////////////////////////////////////////
//ver 6.04 --> 6.05 modify 
// move counter 에러 수정 ( counter 가 안되고 있었음)-> 최대 백만회 카운트    
// total use time( hour 추가)
// 작업모드 추가 > 작업자가 작업모드 설정시 층중간에 멈춤(Man Ins Mode)
// 유압식 에서 final err 추가( 가바나 err 과 유사)
///////////////////////////////////////////////////


///////////////////////////////////////////////////
//ver 6.05 --> 6.06 modify 
// 1.total use time 수정 
//   **.user group 11-> usergroup 6번(sub menu -> powerOnTime) 으로 변경
//   **.최대시간 65300 -> 999999시간으로 변경 
// 2.작업모드 변경 > 작업자가 작업모드 종료시  manual down 에서  manual Up으로 변경 
// 3.encoder copy   -> default  "no copy"  ->  "copy" 로 수정
// 4.passward 2번 으로  수정
//   >1).passward 한버 입력시 passward 입력에서 -> 연속 해서 같은 문자  두번 입력해야됨 
// 5.소방운전 수정 (IN_FIR)
//   >1.신법에서  IN_FIRE  이 ON 되었을경우 복귀층으로 복귀를 하는데
//      복귀층이 아닌경우  Safety, Open Key 등으로 인해 문을 열고 대기 하는데 이분이 경과하면 BUZ 가 울린다
//      이때 safety 는 유효,스크린센서 무효, 이분경괴시 open key는 무시 하여 safety가 off 되면 open key는 무시하여 문닫고(SLOW_DOOR ON) 복귀층으로 복귀 
//   >2.피난층으로 복귀후 FR1이 ON 되면 2차화재운행 개시        
//   >2.만약 2차 화재 운전중 IN_FR1 이 복구 되더라도 IN_FIRE이  ON 되어 있으면  2차 소방운전 지속한다 
// 6. nextfloor error
//    >1).레벨 안맞을시 우선 리레벨후 도어 오픈
//    >2).에러 띄우고 정지
//    >3). 수동상태에서(수동버튼) 파워 오푸후 파워온 하면 복구
// 7.ucmp 이중화 체크(신법에서만 전용)
//   >1). ucmp feedbak port=WAT port(INPUT PORT)
//   >2). ucmp on 시 WAT port 가 On 시 정상
//   >3). ucmp off 시 WAT port 가 Off 시 정상     
//   >4). 그외 상태가 0.5초 이상 지속될경우 ucmp port err
//   >5). ucmp 이중화 체크 기능 ON/Off  기능 설정
//   >6). OnOff2 group27번 "Ucmp 2'Chk"    ucmpchk On 또는 ucmpchk Off       
//   >7). 에러 메세지는  "UCMP Port Err"       
// 8.solenoid 수정 
//   >1). 수동모드에서 open solenoid on 후 open 출력(자동과 같다)
//
// 9.수동모드에서 Door open  수정 
//   >1).레벨 맞은상태에서  door open 동작한다 ( LU or LD 둘중에 하나는 On 되어 있어야 문을 연다)
//
// 10.sub safety  port  FULL  에서 DER  port 로 교체(신법에서) 
//   >1). 신법에서 Sub Safety port 가 FUL port 에서 DER port로 교체(LG inverter 가 아닐때)
//   >2). 신법에서 FULL  은  정상 FULL  모드로  동작(원래 FULL)
//   >3). 구법에서는 sub safety 사용을 지정하면 sub safety port 는 IN_FULL 사용하고 
//   >4). 구법에서는 sub safety 사용을 지정 안하면 하면 IN_FULL은  FULL port로 사용 
//
// 11.POWER SAVE 에러  수정
//   >1. timergroup 8번  powerRunTime  이  0  이외의값이 설정되었을경우 power 절약 모드로 동작합니다.
//   이경우  리레벨시  에러가 발생합니다.
//   가능한 사용 하지마시고  꼭 필요한경우  ver 6.06 이상 사용바랍니다.
// 12.Error clear 기능 에러 수정
//   >1. user group 12번에서 Err clear 기능을 수행했을경우 당장은 클리어되지만 power off/on 시에는
//       그전 에러가 표시됩니다.   
//

//  INPUT :  IN_WAT  (7.ucmp 이중화 체크(신법에서만 전용))
//  INPUT :  IN_FULL (10.sub safety  port  FULL  에서 DER  port 로 교체(신법에서))   
//
///////////////////////////////////////////////////



///////////////////////////////////////////////////
//ver 6.06 --> 6.07 modify 
// 1.safety Buz 수정 
/////////////////////////////////

///////////////////////////////////////////////////
//ver 6.07 --> 6.08 modify 
// 1.fire 수정 
/////////////////////////////////

///////////////////////////////////////////////////
//ver 6.08 --> 6.09 modify 
// 1.vip 운전 수정 
/////////////////////////////////





//Earthquake  routine
//bsEarthquake 
//bBefbsEarthquake
//bSlaveEarthquake
//unsigned int  __attribute__((section(".usercode")))   EarthquakeCheck(void)
//ButtonClrCheck();   


//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
///2014,3,14, ver 5.31 : screen door "fs1" ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//층고측정
//화재
//부저  
//오버로드
//세프티



//door open wait
//over heat
//door select(running open)
//handok gbr

#include <p30fxxxx.h>

#include  "..\..\system_com\memory_map.h"
#include  "30f6010_io.h"            
#include  "host_io.h"            
#include  "iodef.h"
#include  "door.h"
#include  "com.h"
#include  "counter.h"
#include  "you_can1.h" 
#include  "you_can2.h" 
#include  "lader.h" 
#include  "default_setup.h" 
#include  "Host_NewProtocol.h" 



_FOSC(CSW_FSCM_OFF & XT_PLL8 & 0xc30f);
_FWDT(WDT_ON & WDTPSA_64 & WDTPSB_1 & 0x803f);
//_FWDT(WDT_OFF & WDTPSA_64 & WDTPSB_1 & 0x803f);

_FBORPOR(PBOR_ON & BORV27 & PWRT_64 & MCLR_EN & 0x87b3);
_FGS(0x0007);

//_FGS(CODE_PROT_OFF & 0x0003);
//_FGS(0x0004);

/*
#define _CONFIG4(x) __attribute__((section("__CONFIG4.sec,x"))) int _CONFIG4 = (x);
#define _CONFIG5(x) __attribute__((section("__CONFIG5.sec,x"))) int _CONFIG5 = (x);

_CONFIG4(0x0000);
_CONFIG5(0x0000);
*/





extern void	Initialize_DS1302(void);
extern void disp_clk_regs(void);
extern void	FireKeyCheck(void);
extern void erase_flash_row(unsigned int);
extern void program_flash(unsigned int, unsigned int);

UserDataType    PassWardKeyBuf[4]={0,0,0,0};     
UserDataType    BefPassWardKeyBuf[4]={0,0,0,0};     

UserDataType    YourKey0[8]={0,0,0,0,0,0,0,0};
UserDataType    YourKey1[8]={0,0,0,0,0,0,0,0};
UserDataType    YourKey2[8]={0,0,0,0,0,0,0,0};
UserDataType    YourKey3[8]={0,0,0,0,0,0,0,0};
UserDataType    BaggageFlrOnOff[8]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,};

UserDataType    errbd[12]={0};
UserDataType    Olderrbd[12]={0};
UserDataType    LadderBuf[16]={0};                         
UserDataType    LadderData[16]={0};                           
UserDataType    sRamDArry[END_SRAM]={0};     
UserDataType    ShadowsRamDArry[END_SRAM]={0};     
UserDataType    BdErrCntSeq[ABS_ADDRESS]={0};
UserDataType    BDid[ABS_ADDRESS]={0};
UserDataType    eDArry[E_END]={0};      
UserDataType    eDArryEvent[ERR_SAVE_CNT]={0};

UserDataType    Cancle=0;
UserDataType    BefRcvAdr=0;
UserDataType    CurRcvAdr=0;
UserDataType    LogAddress=0;
UserDataType    AbsAddress=0;
UserDataType    LogAddressLoop=0;
UserDataType    TimeOutBd=0;
UserDataType    src=0;
UserDataType    firstdata=0;
UserDataType    seconddata=0;
UserDataType    Bef_I_EMG=0;
UserDataType    Bef_I_FS0=0;
UserDataType    Bef_I_GR=0;
UserDataType    Bef_I_SU1=0;
UserDataType    Bef_I_X_0=0;
UserDataType    Bef_I_FIRE=0;
UserDataType    I_EMG_Cht=0;
UserDataType    I_FS0_Cht=0;
UserDataType    I_GR_Cht=0;
UserDataType    I_SU1_Cht=0;
UserDataType    I_X_0_Cht=0;
UserDataType    I_FIRE_Cht=0;
UserDataType    NoCloseCnt=0;
UserDataType    errpt=0;
UserDataType    ErrBdNamePt=0;
UserDataType    BefErrBdNamePt=0;
UserDataType    CloseOutOffTime=0;        
UserDataType    VoiceTime=0;        
UserDataType    BellTime=0;        
UserDataType    FhmLoaderTime=0;        
UserDataType    TuningLoaderTime=0;        
UserDataType    AccTimer=0;                
UserDataType    UpBttonTime=0;
UserDataType    DnBttonTime=0;
UserDataType    DoorCloseTime=0;
UserDataType    DoorOpenOnTime=0;
UserDataType    DoorCloseOnTime=0;
UserDataType    msec10=0;
UserDataType    sec1=0;
UserDataType    EepTime=0;
UserDataType    FanTime=0; 
UserDataType    ManualStopTime=0;  
UserDataType    WarmingUpTime=0; 
UserDataType    FixFlrTimeCnt=0; 
UserDataType    errtime=0;
UserDataType    CurFTime=0;
UserDataType    NextFTime=0;
UserDataType    RestartTime=0;
UserDataType    ExtCmdFlrONOFFCnt=0;
UserDataType    SerialLoopMaxTime=0;
UserDataType    RelevelTime=0;
UserDataType    FireBaseFloor=0;
UserDataType    CurSpeed=0;
UserDataType    OriginalHighFlr=0;
UserDataType    OriginalLowFlr=0;
UserDataType    CountDn=0;
UserDataType    CountUp=0;
UserDataType    UseBaseTime=0;
UserDataType    NewDoorSelect=0;
UserDataType    CurDoorSelect=0;
/////////UserDataType    SaveMoveCounter=0;
////////////////UserDataType    LuLdCounter=0;


UserDataType    LuLdErrNm=0;
UserDataType    LuLdSeqPt=0;
UserDataType    LuLdSeqMinCnt=0;
UserDataType    LuLdSeq[5];

UserDataType    CrtMoveFlr;




UserDataType    NotRecoveryData;     

UserDataType    ReLevelAnounceTime;     


unsigned	int    	    UcmpOnOffChkTimer=0;
unsigned	int    	    NextFloorTime=0;
unsigned	int     	MinuteTime=0;
unsigned	int   	    LuLdTime=0;
//unsigned	int   	    LuOrLdOnTime=0;
unsigned	int   	    CounterTime=0;
unsigned	int   	    CounterChkTime=0;
unsigned	int    	    DoorOpenTime=0;
unsigned	int    	    LightTime=0;
unsigned	int    	    AutoNoMoveTime=0;
unsigned	int    	    SolTimer=0;
//////unsigned	int    	    SolWaitTimer=0;
unsigned	int    	    ExIOTimer=0;

unsigned	int    	    msec10Timer=0;

unsigned	int    	    BreakTime=0;
unsigned	int    	    HuntingTimer=0;
unsigned	int    	    HuntingCnter=0;


unsigned	int			SlipTimer=0;
unsigned	int			LopeTimer=0;
unsigned	int			EmgTimer=0;

unsigned	int			FiremanTimer=0;
unsigned	int			TunningTimer=0;


//////////////////////////////////////////////
unsigned	int			PowerSaveTimer=0;
//////////////////////////////////////////////


unsigned	int			SensorPositionBuf[20];



/*
unsigned	int			LuOffTimer=0;
unsigned	int			LdOffTimer=0;
unsigned	int			DzOffTimer=0;
*/




UserDataType    ManWorkingSeq=0;   

UserDataType    OldFireBuf=0;  
UserDataType    AutoBit=0;
UserDataType    EmerBit=0;
UserDataType    SlipBit=0;
UserDataType    LuLdBit=0;
UserDataType    OpenEndBit=0;
UserDataType    BefDlsBit=0;
UserDataType    BefDestFBit=0;
UserDataType    EepRWBit=0;
UserDataType    Etc1Bit=0;
UserDataType    Etc2Bit=0;
UserDataType    Etc3Bit=0;
UserDataType    PC1Bit=0;
UserDataType    StateBit0=0;
UserDataType    StateBit1=0;   
UserDataType    StateBit2=0;
UserDataType    StateBit3=0;   
UserDataType    StateBit4=0;   
UserDataType    StateBit5=0;   
UserDataType    StateBit6=0;   
UserDataType    StateBit7=0;   
UserDataType    StateBit8=0;   
UserDataType    StateBit9=0;   
UserDataType    StateBit10=0;   
UserDataType    Vip_Floor=0;   


UserDataType    S0_STATE_bit=0;
UserDataType    S1_STATE_bit=0;
UserDataType    S2_STATE_bit=0;
UserDataType    S3_STATE_bit=0;
UserDataType    S4_STATE_bit=0;

UserDataType    I_SU1_bit=0;
UserDataType    I_EMG_bit=0;
UserDataType    I_GR_bit=0;
UserDataType    I_FIRE_bit=0;
UserDataType    I_FS0_bit=0;
UserDataType    I_X0_bit=0;
UserDataType    O_OP_bit=0;
UserDataType    O_U_W_bit=0;
UserDataType    O_Y_0_bit=0;

///////////////////////////////////////////newio insert
UserDataType    Virtual_OUT_bit=0;
UserDataType    EXT_OUT0_bit=0;

UserDataType    Virtual_IN_bit=0;
///////////////////////////////////////////newio insert

UserDataType    Comm_O_OP_bit=0;
UserDataType    Comm_O_U_W_bit=0;
UserDataType    Comm_O_Y_0_bit=0;


UserDataType    DoorStatus_bit=0;
UserDataType    FhmToggle=0;
UserDataType    PowerFailTime=0;
UserDataType    CarOnceStopTime=0;
UserDataType    LadderKeyTime=0;
UserDataType    ElevStopTime=0;
UserDataType    ElevMoveTime=0;
UserDataType    MyGroupAddr;
UserDataType    MyLocalAddr;

UserDataType    CarBdButtonFlr=0;

//UserDataType    MyNc_Addr;
//UserDataType    MyLowDip;

UserDataType    BefDspMode;

UserDataType    SegData0;
UserDataType    SegData1;
UserDataType    SegData2;
UserDataType    SegSel;
UserDataType    LadderTime;

UserDataType    SegError;
UserDataType    ClrCnt=0;
UserDataType    SaveVerify=0;

UserDataType	lu_ld_state;
UserDataType	bef_lu_ld_state;
UserDataType	DoorJumperNm;
UserDataType	NoStart=0;
		
///////////////
//20005


UserDataType    EmgByte;
UserDataType    Su1Byte;
UserDataType    GrByte;
UserDataType    FireByte;
UserDataType    Fs_Byte;
UserDataType    X0Byte;

UserDataType    BefEmgByte;
UserDataType    BefSu1Byte;
UserDataType    BefGrByte;
UserDataType    BefFireByte;
UserDataType    BefFs_Byte;
UserDataType    BefX0Byte;



UserDataType    EmgTime;
UserDataType    PrkTime;
UserDataType    AtTime;
UserDataType    UbTime;
UserDataType    DbTime;
UserDataType    OlsTime;
UserDataType    GsTime;
UserDataType    DsTime;

UserDataType    Su1Time;
UserDataType    Sd1Time;
UserDataType    SftTime;
UserDataType    OvlTime;
UserDataType    UlsTime;
UserDataType    DlsTime;
UserDataType    LuTime;
UserDataType    LdTime;

UserDataType    RgTime;
UserDataType    BatTime;
UserDataType    PassTime;
UserDataType    FireTime;
UserDataType    WaterTime;
UserDataType    FullTime;
UserDataType    MmTime;
UserDataType    FhmInTime;

UserDataType    Fr1Time;
UserDataType    Fr2Time;
UserDataType    Gs2Time;
UserDataType    Ds2Time;
UserDataType    Su2Time;
UserDataType    Sd2Time;
//UserDataType    Su3Time;
UserDataType    BmTime;
UserDataType    InvTime;

UserDataType    X0Time;
UserDataType    X1Time;
UserDataType    X2Time;
UserDataType    X3Time;
UserDataType    X4Time;
UserDataType    X5Time;
UserDataType    X6Time;
UserDataType    X7Time;


UserDataType    Fs0Time;
UserDataType    Fs1Time;
UserDataType    Fs2Time;
UserDataType    Fs3Time;
UserDataType    Fs4Time;
UserDataType    DerTime;
UserDataType    FidTime;
UserDataType    UndTime;

///////////////
//20005

UserDataType    LoopTime=0;


UserDataType    RstTime=0;
UserDataType    InvErrTime=0;
UserDataType    RstCnt=0;

//UserDataType    ErrChkNm=0;


UserDataType    HibSet[10]={0,0,0,0,0,0,0,0,0,0};
UserDataType    CmdFixFlrTime=0;

UserDataType    TmpBuzor;   
UserDataType    ExtKeyCnt=0;

unsigned int 	AutotunUpDn=0;
unsigned int	Befsensor_type=0xff;
unsigned int    iType_Test_PlusMinus=0;
unsigned long   LType_Test_Value=0;

unsigned long   MpmValue=0;
unsigned long   tmpVarValue=0;


////////unsigned long   FindDecTime=1,FindScurveTime=0,MiniMumSpd=0;
unsigned long 	PositionPulse1;

unsigned long   Slip_pulse,Base_Slip_pulse;


unsigned long 	BefCurEncoderPulse=0;
unsigned long   TmpEncoderPulse=0;

unsigned long 	LevelEncoderPulse1,LevelEncoderPulse2,LevelEncoderPulse3;
unsigned long 	TestPulse1,LuLdEncoder,UpDnEncoder;


unsigned long 	xPulse1,xPulse2,BaseDecPulseX;
unsigned long 	xVarTime,xVarSCurve,MaxMpm,xCurMpm,xCurMpm_MaxMpmSpd,Length1,Length2;
unsigned long 	ManJobPulse;


unsigned long   PowerOnTime=0;

unsigned long 	Err_CurPulse=0;
unsigned int 	Err_CurMpm=0;
unsigned char	Err_CurFloor,Err_RunFloor,Err_DestFloor,Err_LuLdFloor,Err_InvFloor,Err_Number;
unsigned char	Err_Out_Up_Byte,Err_Out_Op_Byte,Err_Out_Fan_Byte;
unsigned char	Err_In_Emg_Byte,Err_In_Sus_Byte,Err_In_Rg_Byte,Err_In_Fr1_Byte,Err_In_X0_Byte,Err_In_Fs0_Byte;



unsigned long  parameter_mirror[MAX_LONG_BUF]; // = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};


long_field  FlashDspCharBuf[512]    __attribute__((aligned(512) , space(psv)));


const unsigned char DftFlrName[] = {"B7B6B5B4B3B2B101020304050607080910111213141516171819202122232425262728293031323334353637383940414243444546474849505152535455565758596061626364"}; 





const unsigned char StatusMessage[][16]={
                                      "Inspect Stop    ",      //000                               
                                      "InverterStop    ",      //001                               
                                      "INVFloorStop    ",      //002                               
                                      "Emgency Stop    ",      //003                               
                                      "GOV/Final Error ",      //004                               
                                      "MotorOverheat   ",      //005                                                                           
                                      "Slip Stop       ",      //006                               
                                      "ULS Stop        ",      //007                                                                     
                                      "DLS Stop        ",      //008                               
                                      "LuLd Off Stop   ",      //009
                                      "NextFloorStop   ",      //010
                                      "InPort Error    ",      //011
                                      "HallDoor Stop   ",      //012
                                      "CarDoor  Stop   ",      //013
                                      "Relevel Error   ",      //014
                                      "NoEncoderPulse  ",      //015
                                      "EncoderAB Err   ",      //016
                                      "SpeedPortErr    ",      //017
                                      "Min Dec Length  ",      //018
                                      "System Error    ",      //019
                                      "AtButton Off    ",      //020
                                      "Flr Match Err   ",      //021
                                      "Inv Comm Err    ",      //022
                                      "BkMgt Err       ",      //023
                                      "Bk On/Off Err   ",      //024
                                      "Sus Error       ",      //025
                                      "Sds Error       ",      //026
									  "LuLdChangeErr   ",      //027 
									  "Ld On Error	   ",      //028
									  "Ld Off Error    ",      //029
									  "Lu On Error     ",      //030
									  "Lu Off Error    ",      //031
									  "LuLdOnOff Err   ",      //032
                                      "CarDoorJumper   ",      //033                                                                           
                                      "HallDoorJump    ",      //034
                                      "CarHallJumper   ",      //035
                                      "Earthquake      ",      //036
                                      "DZ Error        ",      //037
                                      "No Close End    ",      //038
                                      "Ucmp Port Err   ",      //039
                                      "040             ",      //040
                                      "041             ",      //041
                                      "Tunning..Wait...",      //042
                                      "FHM_Error       ",      //043
                                      "044             ",      //044
                                      "045             ",      //045
                                      "OverLoad Stop   ",      //046
                                      "Parking Mode    ",      //047
                                      "Fire            ",      //048
                                      "Water_Sensing   ",      //049                                       
                                      "050             ",      //050
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
                                      "063             ",      //063
                                      "No Define       ",      //064
                                      "Auto Ready      ",      //065
                                    };                                       


/*******************************************************
   manual play and record
*******************************************************/


//    unsigned long xxx;

void  __attribute__((section(".usercode"))) flash_write(unsigned int pt)
{

    unsigned int write_verify,y;
    unsigned long src_data,target_data;

	if((SaveVerify == 0x55) &&  (bMoveCar==0)){

	    asm("CLRWDT");
	
	    DISABLE_INTERRUPTS;
	
	    do{
	        asm("CLRWDT");
	
	        write_verify=0;
	
	    	// Erase the 32 location row of flash
	    	erase_flash_row((unsigned int)&FlashDspCharBuf[pt]);
	    	// Write the 32 parameters back 
	    	program_flash((unsigned int)&FlashDspCharBuf[pt],(unsigned int)&parameter_mirror[0]);
	        
	        for(y=0;y<16;y++){
	            target_data=FlashDspCharBuf[pt+y].long_data;    
	            src_data=parameter_mirror[y];  
	
	            if(src_data != target_data){  
	                write_verify=1;
	                break;
	            }
	        }                        
	    }while(write_verify);
	
	
	    ENABLE_INTERRUPTS;
	}
    asm("CLRWDT");
}





void  __attribute__((section(".usercode"))) SaveFloorCnt(void)
{
    unsigned int i;

#ifdef	FLOOR_64
    flash_write(FLR_01_PULSE);
    for(i=0;i<16;i++)    parameter_mirror[i] = parameter_mirror[i+16];
    flash_write(FLR_17_PULSE);
    for(i=0;i<16;i++)    parameter_mirror[i] = parameter_mirror[i+32];
    flash_write(FLR_33_PULSE);
    for(i=0;i<16;i++)    parameter_mirror[i] = parameter_mirror[i+48];
    flash_write(FLR_49_PULSE);
#else
    flash_write(FLR_01_PULSE);
    for(i=0;i<16;i++)    parameter_mirror[i] = parameter_mirror[i+16];
    flash_write(FLR_17_PULSE);
#endif
}                                                                     








void  __attribute__((section(".usercode"))) flash_write_DspChar(unsigned int pt)
{
    unsigned int i;

    i=((pt/64) * 16);

    flash_write(i);
}







void  __attribute__((section(".usercode"))) F_SetupData_ReSet(unsigned int pt,unsigned int DtNm)
{
    LocalType  i,j,k;

    k=(pt % 64);

    j=((pt/64) * 16);

//    if(pt<64)   j=0;
//    else        j=16;

    for(i=0;i<16;i++){
        parameter_mirror[i]=FlashDspCharBuf[j+i].long_data;
    }

    for(i=0;i<DtNm;i++){
        b_LdTmpBufRam((unsigned long)(k+i))     = (UserDataType)(LadderBuf[C_SAVE_DATA+i]);
    }

    if((j==0) && (k==1)){
        if(cF_FLRDSPCH(0) == 'B'){             
            if((LadderBuf[C_SAVE_DATA+0] == '7'))      i=0;  
            else if((LadderBuf[C_SAVE_DATA+0] == '6')) i=2;  
            else if((LadderBuf[C_SAVE_DATA+0] == '5')) i=4;  
            else if((LadderBuf[C_SAVE_DATA+0] == '4')) i=6;  
            else if((LadderBuf[C_SAVE_DATA+0] == '3')) i=8;  
            else if((LadderBuf[C_SAVE_DATA+0] == '2')) i=10;  
            else if((LadderBuf[C_SAVE_DATA+0] == '1')) i=12;
            else                                       j=1;  
        }
        if(cF_FLRDSPCH(0) == '0'){ 
            if((LadderBuf[C_SAVE_DATA+0] == '1'))       i=14;
            else                                        j=1;  
        }

        if(j==0){
			#ifdef	FLOOR_64
            for(k=0;k<128;k++,i++){
                b_LdTmpBufRam(k)  = DftFlrName[i];
            }

			#else
            for(k=0;k<64;k++,i++){
                b_LdTmpBufRam(k)  = DftFlrName[i];
            }
			#endif
        }
    }

    flash_write_DspChar(pt);
}



unsigned int  __attribute__((section(".usercode")))   PerfectAuto(void)
{
	if(bAuto && bMotorRestartOn && bManualAuto)	return(1);
	else										return(0);	
}



unsigned int  __attribute__((section(".usercode")))   ErrAutoClear(void)
{
	if(ElevStopTime > 10){			
		bAutoButtonErr=0;
	}
	return(0);
}



UserDataType  __attribute__((section(".usercode"))) New_Spd_SystemChk(void)
{
	if( (cF_SystemSet == OLD_LAW_NEW_SPD) || (cF_SystemSet == NEW_LAW_NEW_SPD))			return(1);
	else																				return(0); 
}

UserDataType  __attribute__((section(".usercode"))) New_Law_SystemChk(void)
{
	if( (cF_SystemSet == NEW_LAW_OLD_SPD) || (cF_SystemSet == NEW_LAW_NEW_SPD))			return(1);
	else																				return(0); 
}


UserDataType  __attribute__((section(".usercode"))) Old_Spd_SystemChk(void)
{
	if( (cF_SystemSet == OLD_LAW_OLD_SPD) || (cF_SystemSet == NEW_LAW_OLD_SPD))			return(1);
	else if( New_Spd_SystemChk()==0)													return(1);
	else																				return(0); 
}


UserDataType  __attribute__((section(".usercode"))) Old_Law_SystemChk(void)
{
	if( (cF_SystemSet == OLD_LAW_OLD_SPD) || (cF_SystemSet == OLD_LAW_NEW_SPD))			return(1);
	else if( New_Law_SystemChk()==0)													return(1);
	else																				return(0);
}



/*
UserDataType  __attribute__((section(".usercode"))) No_SystemChk(void)
{
	if( (cF_SystemSet == NO_LAW_NO_SPD) || (cF_SystemSet >= INVALID_SYSTEM))			return(1);
	else																				return(0); 
}
*/


unsigned int  __attribute__((section(".usercode")))   AutoLandingModeChk(unsigned char val)
{
	if( (INVERTER_CHECK == IO) && (cF_AUTO_LANDING == val)){
		return(1);
	}
	return(0);
}


unsigned int  __attribute__((section(".usercode")))   DaesungAutoLandingModeChk(unsigned char val)
{
	unsigned int i;

	i=1;
	if( !AutoLandingModeChk((unsigned char)val))	i=0;
	if( !New_Spd_SystemChk())						i=0;

	if(i==0){
		BaseDecPulseX=0;
	}

	return(i);
}





UserDataType  __attribute__((section(".usercode"))) LoadSensorPotionInit(void)
{
	unsigned long	tmp_x0,tmp_x1,tmp_x2;
	unsigned int	i;
   
/*
#define  	SET_ULS_POSITION    0
#define  	REAL_ULS_PO      	1
#define  	SET_SUS_POSITION    2
#define  	REAL_SUS_PO      	3
#define  	SET_SUS1_POSITION   4
#define  	REAL_SUS1_PO      	5
#define  	SET_X0_POSITION    	6
#define  	REAL_X0_PO      	7
#define  	SET_DLS_POSITION    8
#define  	REAL_DLS_PO      	9
#define  	SET_SDS_POSITION    10
#define  	REAL_SDS_PO      	11
#define  	SET_SDS1_POSITION   12
#define  	REAL_SDS1_PO      	13
#define  	SET_X1_POSITION    	14
#define  	REAL_X1_PO      	15
*/

	for(i=0;i<POSITION_END;i++)	SensorPositionBuf[i]	=0;

	SensorPositionBuf[SET_ULS_POSITION]=(unsigned int)(ULSDLS_LENGTH);
	SensorPositionBuf[SET_DLS_POSITION]=(unsigned int)(ULSDLS_LENGTH);


	if(New_Spd_SystemChk()){
		tmp_x0=(GET_LONG((unsigned long)DEC_LENGTH_SPD_LOW));
		tmp_x1=(GET_LONG((unsigned long)DEC_LENGTH_SPD_MID));
		tmp_x2=(GET_LONG((unsigned long)DEC_LENGTH_SPD_HIGH));

		if( (tmp_x0>0) && (tmp_x1>0) && (tmp_x2>0)){						// low,mid,high  spd
			SensorPositionBuf[SET_SUS_POSITION]	=(unsigned int)(tmp_x0);
			SensorPositionBuf[SET_SUS1_POSITION]=(unsigned int)(tmp_x1);
			SensorPositionBuf[SET_X0_POSITION]	=(unsigned int)(tmp_x2);

			SensorPositionBuf[SET_SDS_POSITION]	=(unsigned int)(tmp_x0);
			SensorPositionBuf[SET_SDS1_POSITION]=(unsigned int)(tmp_x1);
			SensorPositionBuf[SET_X1_POSITION]	=(unsigned int)(tmp_x2);
		}
		else if((tmp_x1>0) && (tmp_x2>0)){									// mid,high
			SensorPositionBuf[SET_SUS_POSITION]	=(unsigned int)(tmp_x1);
			SensorPositionBuf[SET_SUS1_POSITION]=(unsigned int)(tmp_x2);

			SensorPositionBuf[SET_SDS_POSITION]	=(unsigned int)(tmp_x1);
			SensorPositionBuf[SET_SDS1_POSITION]=(unsigned int)(tmp_x2);
		}
		else{																// high
			SensorPositionBuf[SET_SUS_POSITION]	=(unsigned int)(tmp_x2);
			SensorPositionBuf[SET_SDS_POSITION]	=(unsigned int)(tmp_x2);
		}
	}

	return(0);
}	


unsigned int __attribute__((section(".usercode")))  OneEncoderBkErrChk(void)
{
	if( bEncoderErr || bEncoderABErr || bsBreakMgtOpen || bsBreakOpen)	return(1);
	else																return(0);
}



unsigned int __attribute__((section(".usercode")))  DoorOpenEndWaitChk(void)
{			  
	if(bDoorJumper || bMotor_Overheat || S1_POWER_FAIL || bInspect || bsCleNoOn)		return(1);		
 	else if(bWaterAndArrive  ||  bsEarthquake)											return(1);
 	else if(bDZ_Err  &&  !bMoveCar)														return(1);
 	else if(OneEncoderBkErrChk())														return(1);
 	else if(bsNextFloor){
		if(New_Law_SystemChk()){
			return(1);
		}	
	}		

	return(0);
}





UserDataType  __attribute__((section(".usercode"))) VersionCheck(void)
{
    UserDataType    i;

    i=0;
    do{
        i++;
        if(i>10)    return(i);  
    }while((cF_VER0 != VERSION_0) || (cF_VER1 != VERSION_1) || (cF_VER2 != VERSION_2));

    return(0);
}






//////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////
UserDataType  __attribute__((section(".usercode"))) Flash_ErrClear_All(void)
{
	unsigned int	i;

	SaveVerify = 0x55;

	sRamDArry[mBefErrCntPt]=0;
	eDArry[eErrCntPt]=0;

	for(i=0;i<16;i++)	parameter_mirror[i]=0;

	flash_write_DspChar(F_BLOCK_X1+0);
	flash_write_DspChar(F_BLOCK_X1+64);
	flash_write_DspChar(F_BLOCK_X1+128);
	flash_write_DspChar(F_BLOCK_X1+192);

	SaveVerify = 0x0;

	return(0);
}


UserDataType  __attribute__((section(".usercode"))) EEP_Clear_All(void)
{
	unsigned int	i;
	for(i=0;i<16;i++)	parameter_mirror[i]=0;

	flash_write_DspChar(F_BLOCK_X0+0);
	flash_write_DspChar(F_BLOCK_X0+64);
	flash_write_DspChar(F_BLOCK_X0+128);
	flash_write_DspChar(F_BLOCK_X0+192);
	flash_write_DspChar(F_BLOCK_X0+256);

	return(0);
}


UserDataType  __attribute__((section(".usercode"))) EEP_Save_All(void)
{
	unsigned int	i,j,k,err_savept;
	long_field	m_data;  

    GetFlashDataToBufRam(F_BLOCK_X0);

	parameter_mirror[0]=CurPulse;
	parameter_mirror[1]=MoveCounterx;


	m_data.byte[2]=sRamDArry[mcurfloor];
	m_data.byte[3]=CurDoorSelect;
	parameter_mirror[2]=m_data.long_data;


	m_data.byte[0]=NotRecoveryData;
	m_data.byte[1]=eDArry[eErrCntPt];
	parameter_mirror[3]=m_data.long_data;

	parameter_mirror[4]=PowerOnTime;

	flash_write_DspChar(F_BLOCK_X0);



/*	temp delete


	if(sRamDArry[mBefErrCntPt] != eDArry[eErrCntPt]){
		if(sRamDArry[mBefErrCntPt] >= 40)	sRamDArry[mBefErrCntPt]=0; 
		err_savept=(sRamDArry[mBefErrCntPt] * 6);
		err_savept=(err_savept/64);
		if(err_savept >= 4)	return(0);

		j=(err_savept * 64);
		k=j;
		for(i=0;i<16;i++){
			m_data.byte[0]=eDArry[j+0];
			m_data.byte[1]=eDArry[j+1];
			m_data.byte[2]=eDArry[j+2];
			m_data.byte[3]=eDArry[j+3];
			parameter_mirror[i]=m_data.long_data;
			j=(j+4);
		}
		flash_write_DspChar( (F_BLOCK_X1 + k));


		j=( k + 64);
		if(j >= 256)	j=0;
		k=j;	 

		for(i=0;i<16;i++){
			m_data.byte[0]=eDArry[j+0];
			m_data.byte[1]=eDArry[j+1];
			m_data.byte[2]=eDArry[j+2];
			m_data.byte[3]=eDArry[j+3];
			parameter_mirror[i]=m_data.long_data;
			j=(j+4);
		}

		flash_write_DspChar( (F_BLOCK_X1 + k));
	}


temp delete 
*/	

	return(0);
}



UserDataType  __attribute__((section(".usercode"))) EEP_Load_All(void)
{
	unsigned int i;	

    for(i=0;i<ERR_SAVE_CNT;i++){
    	eDArryEvent[i]=0x0;
	}

    for(i=0;i<E_END;i++){
    	eDArry[eSysErCnt+i]=cF_FLRDSPCH((unsigned long)(F_BLOCK_X1 + i));         
	}

    eDArry[eErrCntPt]=cF_FLRDSPCH((unsigned long)(F_eErrCntPt));   
      
    sRamDArry[mcurfloor]=cF_FLRDSPCH((unsigned long)(F_CurFloor));         
    CurDoorSelect=cF_FLRDSPCH((unsigned long)(F_CurDoorSelect));         
    NotRecoveryData=cF_FLRDSPCH((unsigned long)(F_GBR));         

	CurPulse=GET_LONG_BYTE((unsigned long)(F_CurPulse0));
	MoveCounterx=GET_LONG_BYTE((unsigned long)(F_MoveCount0));

	PowerOnTime=GET_LONG_BYTE((unsigned long)(F_PowerOnTime0));
	
	sRamDArry[mBefErrCntPt]=eDArry[eErrCntPt];

	return(0);
}

//////////////////////////////////////////////////////////////////


unsigned int  __attribute__((section(".usercode"))) PcCmdSaveChk(void)
{
	unsigned char i,j;

	LocalType block_pt;

	if(bMoveCar)	return(0);
	if(bImportData)	return(0);


	if((unsigned char)CmdFixFlrTime != cF_FIXFLOORTIME){
		SaveVerify=0x55;
        GetFlashDataToBufRam(F_BLOCK1);
        b_LdTmpBufRam(F_FixFloorTime)   = (unsigned char)(CmdFixFlrTime);
        flash_write_DspChar(F_BLOCK1);
		SaveVerify=0;
	}


	if( (cF_NONSERVICE0 != ShadowsRamDArry[FLR_ON_OFF0]) || (cF_NONSERVICE1 != ShadowsRamDArry[FLR_ON_OFF1]) || (cF_NONSERVICE2 != ShadowsRamDArry[FLR_ON_OFF2]) || (cF_NONSERVICE3 != ShadowsRamDArry[FLR_ON_OFF3])	
	||  (cF_NONSERVICE4 != ShadowsRamDArry[FLR_ON_OFF4]) || (cF_NONSERVICE5 != ShadowsRamDArry[FLR_ON_OFF5]) || (cF_NONSERVICE6 != ShadowsRamDArry[FLR_ON_OFF6]) || (cF_NONSERVICE7 != ShadowsRamDArry[FLR_ON_OFF7])){	

		SaveVerify=0x55;
		block_pt=(F_NonService0/64);
		block_pt=(block_pt * 64);
    	GetFlashDataToBufRam(block_pt);
     	i=(F_NonService0 % 64);		
 		b_LdTmpBufRam((unsigned long)(i+0))=ShadowsRamDArry[FLR_ON_OFF0];
		b_LdTmpBufRam((unsigned long)(i+1))=ShadowsRamDArry[FLR_ON_OFF1];
		b_LdTmpBufRam((unsigned long)(i+2))=ShadowsRamDArry[FLR_ON_OFF2];
		b_LdTmpBufRam((unsigned long)(i+3))=ShadowsRamDArry[FLR_ON_OFF3];        
		b_LdTmpBufRam((unsigned long)(i+4))=ShadowsRamDArry[FLR_ON_OFF4];
		b_LdTmpBufRam((unsigned long)(i+5))=ShadowsRamDArry[FLR_ON_OFF5];
		b_LdTmpBufRam((unsigned long)(i+6))=ShadowsRamDArry[FLR_ON_OFF6];
		b_LdTmpBufRam((unsigned long)(i+7))=ShadowsRamDArry[FLR_ON_OFF7];                   
		flash_write_DspChar(block_pt);

		SaveVerify=0;
	}



	i=0;
	j=0;
	if(bExt_FAMILY)		i=1;
	if(FamilyService)	j=1;

	if(i != j){
		SaveVerify=0x55;
        GetFlashDataToBufRam(F_BLOCK1);
		if(bExt_FAMILY)	bit_LdTmpBufRamSet(F_OnOff2,bFamilyService    	% 8);
		else			bit_LdTmpBufRamReset(F_OnOff2,bFamilyService    % 8);
        flash_write_DspChar(F_BLOCK1);

		SaveVerify=0;
	}

	return(0);
}


UserDataType  __attribute__((section(".usercode"))) PowerSaveValidChk(void)
{
	unsigned int pt;

	bDspClr=0;

	if( (cF_DRJMPCHKTTM > 0) && (cF_DRJMPCHKTTM <= 200)){
		if(CurSelOutPortChk(cF_LIT)){
			pt=(unsigned int)(cF_DRJMPCHKTTM);
			if(PowerSaveTimer >= cF_DRJMPCHKTTM){
				bPowerSaveMoveValid=1;
				return(0);
			}
			else{
				bPowerSaveMoveValid=0;
				return(2);             //power save mode and wait 
			}
		}
		else{
			bDspClr=1;
			PowerSaveTimer=0;
			bPowerSaveMoveValid=0;
			return(1);					// power save mode 
		}
	}
	else{
		PowerSaveTimer=255;
		bPowerSaveMoveValid=1;
		return(0);					// disable 
	}
}




UserDataType  __attribute__((section(".usercode"))) ReadInitSetupData(void)
{

    LocalType  i,j;
	LocalType block_pt;

    
    if(VersionCheck()){
		SaveVerify = 0x55;

		EEP_Clear_All();

        b_LdTmpBufRam(F_TopFlr)         = Init_TopFlr;
        b_LdTmpBufRam(F_PrkFlr)         = Init_PrkFlr;
        b_LdTmpBufRam(F_OpWtTm)         = Init_OpWtTm;      
        b_LdTmpBufRam(F_OpTtTm)         = Init_OpTtTm;  
        b_LdTmpBufRam(F_DirTime)        = Init_DirTime;
        b_LdTmpBufRam(F_VoiceTime)      = Init_VoiceTime;
        b_LdTmpBufRam(F_BrkMgtTime)     = Init_BrkMgtTime;


        b_LdTmpBufRam(F_FixFloor)       = Init_FixFloor;
        b_LdTmpBufRam(F_OneStopFlr)     = Init_OneStopFlr;

        b_LdTmpBufRam(F_FireSafeFlr)    = Init_FireSafeFlr;
        b_LdTmpBufRam(F_X7SafeFlr)      = Init_X7SafeFlr;
        b_LdTmpBufRam(F_WaterSafeFlr)   = Init_WaterSafeFlr;

        b_LdTmpBufRam(F_KidsKeyCnt)     = Init_KidsKeyCnt;
        b_LdTmpBufRam(F_X6SafeFlr)      = Init_X6SafeFlr;
        b_LdTmpBufRam(F_X5SafeFlr)      = Init_X5SafeFlr;

                                                 //     7 ,      6,      5,        4,         3,        2,       1,     0
        b_LdTmpBufRam(F_NcNoBit0)       = Init_ALL_FF;  //                                                                     emg
        b_LdTmpBufRam(F_NcNoBit1)       = Init_ALL_FF;  //                                                                     su1
        b_LdTmpBufRam(F_NcNoBit2)       = Init_ALL_FF;  //                                                                     rg
        b_LdTmpBufRam(F_NcNoBit3)       = Init_ALL_FF;  //                                                                     fr1
        b_LdTmpBufRam(F_NcNoBit4)       = Init_ALL_FF;  //                                                                     x0
        b_LdTmpBufRam(F_NcNoBit5)       = Init_ALL_FF;  //                                                                     fs0
        b_LdTmpBufRam(F_NcNoBit6)       = Init_ALL_FF;  //                                                                     op
        b_LdTmpBufRam(F_NcNoBit7)       = Init_ALL_FF;  //                                                                     fan
        b_LdTmpBufRam(F_NcNoBit8)       = Init_ALL_FF;  //                                                                     up

        b_LdTmpBufRam(F_StartFloor)     = START_FLOOR;   


        bit_LdTmpBufRamSet  (F_OnOff0,bFhmOnOff             % 8);
        bit_LdTmpBufRamSet  (F_OnOff0,bDoorJumperOff        % 8); 
        bit_LdTmpBufRamReset(F_OnOff0,bEncoderPhase         % 8);
        bit_LdTmpBufRamSet  (F_OnOff0,bWardPriority         % 8);
        bit_LdTmpBufRamReset(F_OnOff0,bNonStop              % 8);
        bit_LdTmpBufRamSet  (F_OnOff0,bOpenTotalOnOff       % 8);
        bit_LdTmpBufRamSet  (F_OnOff0,bCloseTotalOnOff      % 8);
        bit_LdTmpBufRamSet  (F_OnOff0,bOpenWaitToTalOnOff   % 8);

        bit_LdTmpBufRamSet  (F_OnOff1,bCarDoor1Use      	% 8);
        bit_LdTmpBufRamReset(F_OnOff1,bCarDoor2Use      	% 8);
        bit_LdTmpBufRamSet  (F_OnOff1,bHoleDoor1Use     	% 8);
        bit_LdTmpBufRamReset(F_OnOff1,bHoleDoor2Use     	% 8);
        bit_LdTmpBufRamReset(F_OnOff1,bSubSafety        	% 8);
        bit_LdTmpBufRamReset(F_OnOff1,bBrkMgtUse        	% 8);
        bit_LdTmpBufRamSet  (F_OnOff1,bEncoderUse       	% 8);
        bit_LdTmpBufRamReset(F_OnOff1,bRelevelOnOff     	% 8);

        bit_LdTmpBufRamSet  (F_OnOff2,bOilLopeTypeChk   	% 8);
        bit_LdTmpBufRamReset(F_OnOff2,bOnlyOneCall      	% 8);
        bit_LdTmpBufRamReset(F_OnOff2,bManualSusChk     	% 8);
        bit_LdTmpBufRamReset(F_OnOff2,bBrkOpenUse       	% 8);
        bit_LdTmpBufRamReset(F_OnOff2,bKidsKeyChkUse    	% 8);
        bit_LdTmpBufRamReset(F_OnOff2,bCarKeyFirstService  	% 8);
        bit_LdTmpBufRamReset(F_OnOff2,bFamilyService    	% 8);
        bit_LdTmpBufRamReset(F_OnOff2,bOpenOutSet    		% 8);


        bit_LdTmpBufRamReset(F_OnOff3,bSafetyValidLR    	% 8);
        bit_LdTmpBufRamReset(F_OnOff3,bFloorSel             % 8);
        bit_LdTmpBufRamReset(F_OnOff3,bRunOpenSetClear      % 8);
        bit_LdTmpBufRamSet(F_OnOff3,bUcmpFeedback      		% 8);
        bit_LdTmpBufRamSet(F_OnOff3,bManWorkingChk      	% 8);
        bit_LdTmpBufRamSet(F_OnOff3,bEncoderCpy         	% 8);

/*
//DEFAULT  NEW_LAW
        bit_LdTmpBufRamSet(F_OnOff0,bDoorJumperOff    		% 8); 
        bit_LdTmpBufRamSet(F_OnOff1,bBrkMgtUse        		% 8);
        bit_LdTmpBufRamSet(F_OnOff2,bBrkOpenUse       		% 8);
*/

        SWPAB   = 0;    //****

        b_LdTmpBufRam(F_FanTime)        = Init_FanTime;        //3 sec
        b_LdTmpBufRam(F_LightTime)      = Init_LightTime;       //99 min
        b_LdTmpBufRam(F_FixFloorTime)   = Init_FixFloorTime;
        b_LdTmpBufRam(F_NextFlrTime)    = Init_NextFlrTime;
        b_LdTmpBufRam(F_LuLdOffTime)    = Init_LuLdOffTime;
        b_LdTmpBufRam(F_ReOpTime)       = Init_ReOpTime;  
        b_LdTmpBufRam(F_OpClWaitTime)   = Init_OpClWTime;
        b_LdTmpBufRam(F_DrJmpChkTime)   = Init_DrJmpChkTime;

        b_LdTmpBufRam(F_StTm1)          = Init_StTm1;
        b_LdTmpBufRam(F_StTm2)          = Init_StTm2;
        b_LdTmpBufRam(F_StTm3)          = Init_StTm3;
        b_LdTmpBufRam(F_StTm4)          = Init_StTm4;
        b_LdTmpBufRam(F_StTm5)          = Init_StTm5;



        b_LdTmpBufRam(F_RunOffTime)      = Init_RunOff_Time;        
        b_LdTmpBufRam(F_Bk1OffTime)      = Init_Bk1Off_Time;
        b_LdTmpBufRam(F_Bk2OffTime)      = Init_Bk2Off_Time;
        b_LdTmpBufRam(F_UDOffTime)       = Init_UDOff_Time;
        b_LdTmpBufRam(F_P4OffTime)       = Init_P4Off_Time;


        b_LdTmpBufRam(F_SolOnTime)       = Init_SolOn_Time;        
        b_LdTmpBufRam(F_DoorWaitTime)    = Init_DoorWait_Time;


//        i_LdTmpBufRam(F_BrkStTm10)      = Init_BrkStTm10;        
//        i_LdTmpBufRam(F_BrkStTm20)      = Init_BrkStTm20;
//        i_LdTmpBufRam(F_BrkStTm30)      = Init_BrkStTm30;
//        i_LdTmpBufRam(F_BrkStTm40)      = Init_BrkStTm40;
//        i_LdTmpBufRam(F_BrkStTm50)      = Init_BrkStTm50;

#ifdef  TEST_SIMULATION  
	#ifdef	FLOOR_64
        b_LdTmpBufRam(F_TopFlr)         = 63;
	#else
        b_LdTmpBufRam(F_TopFlr)         = 31;
	#endif

        bit_LdTmpBufRamReset  (F_OnOff0,bDoorJumperOff        % 8); 
        bit_LdTmpBufRamReset(F_OnOff3,bManWorkingChk      % 8);
#endif

        flash_write_DspChar(F_TopFlr);


/////////////////////////////////////////////////////////
		for(i=0;i<32;i++){
        	b_LdTmpBufRam(F_0506+i)           = DISABLE_FLR;
		}
/*
        b_LdTmpBufRam(F_0607)           = DISABLE_FLR;
        b_LdTmpBufRam(F_0708)           = DISABLE_FLR;
        b_LdTmpBufRam(F_0809)           = DISABLE_FLR;
        b_LdTmpBufRam(F_0910)           = DISABLE_FLR;
        b_LdTmpBufRam(F_1011)           = DISABLE_FLR;
        b_LdTmpBufRam(F_1112)           = DISABLE_FLR;
        b_LdTmpBufRam(F_1213)           = DISABLE_FLR;
        b_LdTmpBufRam(F_1314)           = DISABLE_FLR;
        b_LdTmpBufRam(F_1415)           = DISABLE_FLR;
        b_LdTmpBufRam(F_1516)           = DISABLE_FLR;
        b_LdTmpBufRam(F_1617)           = DISABLE_FLR;
        b_LdTmpBufRam(F_1718)           = DISABLE_FLR;
        b_LdTmpBufRam(F_1819)           = DISABLE_FLR;
        b_LdTmpBufRam(F_1920)           = DISABLE_FLR;
        b_LdTmpBufRam(F_2021)           = DISABLE_FLR;
        b_LdTmpBufRam(F_2105)           = DISABLE_FLR;
        b_LdTmpBufRam(F_0002)           = DISABLE_FLR;
        b_LdTmpBufRam(F_0003)           = DISABLE_FLR;
        b_LdTmpBufRam(F_0004)           = DISABLE_FLR;
        b_LdTmpBufRam(F_0005)           = DISABLE_FLR;
        b_LdTmpBufRam(F_0006)           = DISABLE_FLR;
        b_LdTmpBufRam(F_0007)           = DISABLE_FLR;
        b_LdTmpBufRam(F_0008)           = DISABLE_FLR;
        b_LdTmpBufRam(F_0009)           = DISABLE_FLR;
        b_LdTmpBufRam(F_0010)           = DISABLE_FLR;
        b_LdTmpBufRam(F_0011)           = DISABLE_FLR;
        b_LdTmpBufRam(F_0012)           = DISABLE_FLR;
        b_LdTmpBufRam(F_0013)           = DISABLE_FLR;
        b_LdTmpBufRam(F_0014)           = DISABLE_FLR;
        b_LdTmpBufRam(F_ParkingStart)   = Init_ParkingStartTime;
        b_LdTmpBufRam(F_ParkingEnd)     = Init_ParkingEndTime;
*/

        flash_write_DspChar(F_BLOCK3);
//////////////////////////////////////////////////////////////
#ifdef  TEST_SIMULATION 
#ifdef	KTL
        b_LdTmpBufRam(EMG_PORT)         =SILK_EMG   | BIT_NORMAL_OPEN;          //1     64
        b_LdTmpBufRam(PRK_PORT)         =SILK_PRK   | 0x00;          			//1     
        b_LdTmpBufRam(AUTO_PORT)        =SILK_AUTO  | BIT_NORMAL_OPEN;          //1     
        b_LdTmpBufRam(U_B_PORT)         =SILK_U_B   | 0x80;          			//1             
        b_LdTmpBufRam(D_B_PORT)         =SILK_D_B   | 0x80;          			//1     65
        b_LdTmpBufRam(OLS_PORT)         =SILK_OLS   | 0x80;          			//1     
        b_LdTmpBufRam(GS_PORT)          =SILK_GS    | BIT_NORMAL_OPEN;           //1     
        b_LdTmpBufRam(DS_PORT)          =SILK_DS    | BIT_NORMAL_OPEN;           //1             
#else 
        b_LdTmpBufRam(EMG_PORT)         =SILK_EMG   | 0x00;          //1     64
        b_LdTmpBufRam(PRK_PORT)         =SILK_PRK   | 0x00;          //1     
        b_LdTmpBufRam(AUTO_PORT)        =SILK_AUTO  | 0x00;          //1     
        b_LdTmpBufRam(U_B_PORT)         =SILK_U_B   | 0x80;          //1             
        b_LdTmpBufRam(D_B_PORT)         =SILK_D_B   | 0x80;          //1     65
        b_LdTmpBufRam(OLS_PORT)         =SILK_OLS   | 0x80;          //1     
        b_LdTmpBufRam(GS_PORT)          =SILK_GS    | 0x00;           //1     
        b_LdTmpBufRam(DS_PORT)          =SILK_DS    | 0x00;           //1             
#endif                                                                    
        b_LdTmpBufRam(SU1_PORT)         =SILK_SU1   | 0x80;          //1     66
        b_LdTmpBufRam(SD1_PORT)         =SILK_SD1   | 0x80;          //1     
        b_LdTmpBufRam(SFT_PORT)         =SILK_SFT   | 0x00;          //1     
        b_LdTmpBufRam(OVL_PORT)         =SILK_OVL   | 0x00;          //1             
        b_LdTmpBufRam(ULS_PORT)         =SILK_ULS   | 0x00;          //1     67
        b_LdTmpBufRam(DLS_PORT)         =SILK_DLS   | 0x00;          //1     
        b_LdTmpBufRam(LU_PORT)          =SILK_LU    | 0x00;           //1     
        b_LdTmpBufRam(LD_PORT)          =SILK_LD    | 0x00;           //1             

        b_LdTmpBufRam(RG_PORT)          =SILK_GR    | 0x00;           //1     68
        b_LdTmpBufRam(BAT_PORT)         =SILK_BAT   | 0x80;          //1     
        b_LdTmpBufRam(PASS_PORT)        =SILK_PASS  | 0x80;         //1     
        b_LdTmpBufRam(FIRE_PORT)        =SILK_FIRE  | 0x80;         //1             
        b_LdTmpBufRam(WATER_PORT)       =NO_USE_IN  | 0x80;        //1     69
        b_LdTmpBufRam(FULL_PORT)        =SILK_FULL  | 0x80;         //1     
        b_LdTmpBufRam(MM_PORT)          =SILK_MM    | 0x80;          //1     
        b_LdTmpBufRam(FHM_PORT)         =SILK_FHM   | 0x80;          //1             

        b_LdTmpBufRam(FR1_PORT)         =SILK_FR1   | 0x80;          //1     70
        b_LdTmpBufRam(FR2_PORT)         =SILK_FR2   | 0x80;          //1     
        b_LdTmpBufRam(GS2_PORT)         =SILK_GS2   | 0x80;          //1     
        b_LdTmpBufRam(DS2_PORT)         =SILK_DS2   | 0x80;          //1             
        b_LdTmpBufRam(SU2_PORT)         =SILK_SU2   | 0x80;          //1     71
        b_LdTmpBufRam(SD2_PORT)         =SILK_SD2   | 0x80;          //1     
        b_LdTmpBufRam(BM_PORT)          =SILK_BM    | 0x80;          //1     
        b_LdTmpBufRam(INV_PORT)         =SILK_INV   | 0x80;          //1             

        b_LdTmpBufRam(X0_PORT)          =SILK_X0    | BIT_NORMAL_OPEN;           //1     72
        b_LdTmpBufRam(X1_PORT)          =SILK_X1    | BIT_NORMAL_OPEN;           //1     
        b_LdTmpBufRam(X2_PORT)          =SILK_X2    | BIT_NORMAL_OPEN;           //1     
        b_LdTmpBufRam(X3_PORT)          =SILK_X3    | BIT_NORMAL_OPEN;           //1             
        b_LdTmpBufRam(X4_PORT)          =SILK_X4    | BIT_NORMAL_OPEN;           //1     73
        b_LdTmpBufRam(X5_PORT)          =SILK_X5    | BIT_NORMAL_OPEN;           //1     
        b_LdTmpBufRam(X6_PORT)          =SILK_X6    | BIT_NORMAL_OPEN;           //1     
        b_LdTmpBufRam(X7_PORT)          =SILK_X7    | BIT_NORMAL_OPEN;           //1             

        b_LdTmpBufRam(FS0_PORT)         =SILK_FS0   | 0x80;          //1     74
        b_LdTmpBufRam(FS1_PORT)         =SILK_FS1   | 0x80;          //1     
        b_LdTmpBufRam(FS2_PORT)         =SILK_FS2   | 0x80;          //1     
        b_LdTmpBufRam(FS3_PORT)         =SILK_FS3   | 0x80;          //1             
        b_LdTmpBufRam(FS4_PORT)         =SILK_FS4   | 0x80;          //1     75
        b_LdTmpBufRam(DER_PORT)         =SILK_DER   | 0x80;          //1     
        b_LdTmpBufRam(FID_PORT)         =SILK_FID   | 0x80;          //1     
        b_LdTmpBufRam(UND_PORT)         =SILK_UND   | 0x80;          //1     
#else

        b_LdTmpBufRam(EMG_PORT)         =SILK_EMG   | BIT_NORMAL_OPEN;          //1     64
        b_LdTmpBufRam(PRK_PORT)         =SILK_PRK   | BIT_NORMAL_OPEN;          //1     
        b_LdTmpBufRam(AUTO_PORT)        =SILK_AUTO  | BIT_NORMAL_OPEN;         //1     
        b_LdTmpBufRam(U_B_PORT)         =SILK_U_B   | BIT_NORMAL_OPEN;          //1             
        b_LdTmpBufRam(D_B_PORT)         =SILK_D_B   | BIT_NORMAL_OPEN;          //1     65
        b_LdTmpBufRam(OLS_PORT)         =SILK_OLS   | BIT_NORMAL_OPEN;          //1     
        b_LdTmpBufRam(GS_PORT)          =SILK_GS    | BIT_NORMAL_OPEN;           //1     
        b_LdTmpBufRam(DS_PORT)          =SILK_DS    | BIT_NORMAL_OPEN;           //1             

        b_LdTmpBufRam(SU1_PORT)         =SILK_SU1   | BIT_NORMAL_OPEN;          //1     66
        b_LdTmpBufRam(SD1_PORT)         =SILK_SD1   | BIT_NORMAL_OPEN;          //1     
        b_LdTmpBufRam(SFT_PORT)         =SILK_SFT   | BIT_NORMAL_OPEN;          //1     
        b_LdTmpBufRam(OVL_PORT)         =SILK_OVL   | BIT_NORMAL_OPEN;          //1             
        b_LdTmpBufRam(ULS_PORT)         =SILK_ULS   | BIT_NORMAL_OPEN;          //1     67
        b_LdTmpBufRam(DLS_PORT)         =SILK_DLS   | BIT_NORMAL_OPEN;          //1     
        b_LdTmpBufRam(LU_PORT)          =SILK_LU    | BIT_NORMAL_OPEN;           //1     
        b_LdTmpBufRam(LD_PORT)          =SILK_LD    | BIT_NORMAL_OPEN;           //1             

        b_LdTmpBufRam(RG_PORT)          =SILK_GR    | BIT_NORMAL_OPEN;           //1     68
        b_LdTmpBufRam(BAT_PORT)         =SILK_BAT   | BIT_NORMAL_OPEN;          //1     
        b_LdTmpBufRam(PASS_PORT)        =SILK_PASS  | BIT_NORMAL_OPEN;         //1     
        b_LdTmpBufRam(FIRE_PORT)        =SILK_FIRE  | BIT_NORMAL_OPEN;         //1             
        b_LdTmpBufRam(WATER_PORT)       =SILK_WATER | BIT_NORMAL_OPEN;        //1     69
        b_LdTmpBufRam(FULL_PORT)        =SILK_FULL  | BIT_NORMAL_OPEN;         //1     
        b_LdTmpBufRam(MM_PORT)          =SILK_MM    | BIT_NORMAL_OPEN;         //1     
        b_LdTmpBufRam(FHM_PORT)         =SILK_FHM   | BIT_NORMAL_OPEN;          //1             

        b_LdTmpBufRam(FR1_PORT)         =SILK_FR1   | BIT_NORMAL_OPEN;          //1     70
        b_LdTmpBufRam(FR2_PORT)         =SILK_FR2   | BIT_NORMAL_OPEN;          //1     
        b_LdTmpBufRam(GS2_PORT)         =SILK_GS2   | BIT_NORMAL_OPEN;          //1     
        b_LdTmpBufRam(DS2_PORT)         =SILK_DS2   | BIT_NORMAL_OPEN;          //1             
        b_LdTmpBufRam(SU2_PORT)         =SILK_SU2   | BIT_NORMAL_OPEN;          //1     71
        b_LdTmpBufRam(SD2_PORT)         =SILK_SD2   | BIT_NORMAL_OPEN;          //1     
        b_LdTmpBufRam(BM_PORT)          =SILK_BM    | BIT_NORMAL_OPEN;          //1     
        b_LdTmpBufRam(INV_PORT)         =SILK_INV   | BIT_NORMAL_OPEN;          //1             

        b_LdTmpBufRam(X0_PORT)          =SILK_X0    | BIT_NORMAL_OPEN;           //1     72
        b_LdTmpBufRam(X1_PORT)          =SILK_X1    | BIT_NORMAL_OPEN;           //1     
        b_LdTmpBufRam(X2_PORT)          =SILK_X2    | BIT_NORMAL_OPEN;           //1     
        b_LdTmpBufRam(X3_PORT)          =SILK_X3    | BIT_NORMAL_OPEN;           //1             
        b_LdTmpBufRam(X4_PORT)          =SILK_X4    | BIT_NORMAL_OPEN;           //1     73
        b_LdTmpBufRam(X5_PORT)          =SILK_X5    | BIT_NORMAL_OPEN;           //1     
        b_LdTmpBufRam(X6_PORT)          =SILK_X6    | BIT_NORMAL_OPEN;           //1     
        b_LdTmpBufRam(X7_PORT)          =SILK_X7    | BIT_NORMAL_OPEN;           //1             

        b_LdTmpBufRam(FS0_PORT)         =SILK_FS0   | BIT_NORMAL_OPEN;          //1     74
        b_LdTmpBufRam(FS1_PORT)         =SILK_FS1   | BIT_NORMAL_OPEN;          //1     
        b_LdTmpBufRam(FS2_PORT)         =SILK_FS2   | BIT_NORMAL_OPEN;          //1     
        b_LdTmpBufRam(FS3_PORT)         =SILK_FS3   | BIT_NORMAL_OPEN;          //1             
        b_LdTmpBufRam(FS4_PORT)         =SILK_FS4   | BIT_NORMAL_OPEN;          //1     75
        b_LdTmpBufRam(DER_PORT)         =SILK_DER   | BIT_NORMAL_OPEN;          //1     
        b_LdTmpBufRam(FID_PORT)         =SILK_FID   | BIT_NORMAL_OPEN;          //1     
        b_LdTmpBufRam(UND_PORT)         =SILK_UND   | BIT_NORMAL_OPEN;          //1     


#endif

        b_LdTmpBufRam(F_SubDoorFlr1)    = Init_SubDoorFlr1;
        b_LdTmpBufRam(F_SubDoorFlr2)    = Init_SubDoorFlr1;
        b_LdTmpBufRam(F_SubDoorFlr3)    = Init_SubDoorFlr1;
        b_LdTmpBufRam(F_SubDoorFlr4)    = Init_SubDoorFlr1;
        b_LdTmpBufRam(F_SubDoorFlr5)    = Init_SubDoorFlr1;
        b_LdTmpBufRam(F_SubDoorFlr6)    = Init_SubDoorFlr1;
        b_LdTmpBufRam(F_SubDoorFlr7)    = Init_SubDoorFlr1;
        b_LdTmpBufRam(F_SubDoorFlr8)    = Init_SubDoorFlr1;

        b_LdTmpBufRam(F_SubDoorFlr9)    = Init_SubDoorFlr1;
        b_LdTmpBufRam(F_SubDoorFlr10)   = Init_SubDoorFlr1;
        b_LdTmpBufRam(F_SubDoorFlr11)   = Init_SubDoorFlr1;
        b_LdTmpBufRam(F_SubDoorFlr12)   = Init_SubDoorFlr1;
        b_LdTmpBufRam(F_SubDoorFlr13)   = Init_SubDoorFlr1;
        b_LdTmpBufRam(F_SubDoorFlr14)   = Init_SubDoorFlr1;
        b_LdTmpBufRam(F_SubDoorFlr15)   = Init_SubDoorFlr1;
        b_LdTmpBufRam(F_SubDoorFlr16)   = Init_SubDoorFlr1;		


        flash_write_DspChar(EMG_PORT);

/////////////////////////////////////////////////////////

        b_LdTmpBufRam(FAN_PORT)         =SILK_FAN   | BIT_NORMAL_OPEN;
        b_LdTmpBufRam(LIT_PORT)         =SILK_LIT   | BIT_NORMAL_OPEN;  //     
        b_LdTmpBufRam(BUZ_PORT)         =SILK_BUZ   | BIT_NORMAL_OPEN;     
        b_LdTmpBufRam(BELL_PORT)        =SILK_BELL  | BIT_NORMAL_OPEN;
        b_LdTmpBufRam(RST_PORT)         =SILK_RST   | BIT_NORMAL_OPEN;             
        b_LdTmpBufRam(ERR_PORT)         =SILK_ERR   | BIT_NORMAL_OPEN;     
        b_LdTmpBufRam(HOP_PORT)         =SILK_HOP   | BIT_NORMAL_OPEN;     
        b_LdTmpBufRam(HCL_PORT)         =SILK_HCL   | BIT_NORMAL_OPEN;

        b_LdTmpBufRam(OP_PORT)          =SILK_OP    | BIT_NORMAL_OPEN;     
        b_LdTmpBufRam(CL_PORT)          =SILK_CL    | BIT_NORMAL_OPEN;     
        b_LdTmpBufRam(OP_S_PORT)        =SILK_OP_S  | BIT_NORMAL_OPEN;     
        b_LdTmpBufRam(CL_S_PORT)        =SILK_CL_S  | BIT_NORMAL_OPEN;
        b_LdTmpBufRam(BK2_PORT)         =SILK_BK2   | BIT_NORMAL_OPEN;             
        b_LdTmpBufRam(D_S_PORT)         =SILK_D_S   | BIT_NORMAL_OPEN;     
        b_LdTmpBufRam(GBR_PORT)         =SILK_GBR   | BIT_NORMAL_OPEN;     
        b_LdTmpBufRam(BK1_PORT)         =SILK_BK1   | BIT_NORMAL_OPEN;

        b_LdTmpBufRam(UP_PORT)          =SILK_UP    | BIT_NORMAL_OPEN;
        b_LdTmpBufRam(DN_PORT)          =SILK_DN    | BIT_NORMAL_OPEN;     
        b_LdTmpBufRam(P1_PORT)          =SILK_P1    | BIT_NORMAL_OPEN;     
        b_LdTmpBufRam(P2_PORT)          =SILK_P2    | BIT_NORMAL_OPEN;             
        b_LdTmpBufRam(P3_PORT)          =SILK_P3    | BIT_NORMAL_OPEN;
        b_LdTmpBufRam(P4_PORT)          =SILK_P4    | BIT_NORMAL_OPEN;     
        b_LdTmpBufRam(DAC_PORT)         =SILK_DAC   | BIT_NORMAL_OPEN;     

/////////////
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


        flash_write_DspChar(FAN_PORT);
////////////////////////////////////////////////


///////////////////////////////////////////////
        b_LdTmpBufRam(F_Ver0)           = VERSION_0;
        b_LdTmpBufRam(F_Ver1)           = VERSION_1;
        b_LdTmpBufRam(F_Ver2)           = VERSION_2;


        b_LdTmpBufRam(F_Bd_Id)          = (IO | MAN_USE);           

#ifdef  TEST_SIMULATION  
        b_LdTmpBufRam(F_Bd_Id)          = (LG | MAN_USE);           
#endif


        b_LdTmpBufRam(F_Passward0)      = '0';
        b_LdTmpBufRam(F_Passward1)      = '0';
        b_LdTmpBufRam(F_Passward2)      = '0';
        b_LdTmpBufRam(F_Passward3)      = '0';

        i_LdTmpBufRam(F_SerialNm10)     = 0;

        b_LdTmpBufRam(F_ErrStopCnt)     = 0xff;
        b_LdTmpBufRam(F_NormalDsp)      = 0x0;
        b_LdTmpBufRam(F_UserLamp1)      = 8;
        b_LdTmpBufRam(F_UserLamp2)      = 1;
        b_LdTmpBufRam(F_UserLamp3)      = 6;
        b_LdTmpBufRam(F_UserLamp4)      = 3;
        b_LdTmpBufRam(F_GroupNm)        = 0;
        b_LdTmpBufRam(F_LocalNm)        = 0;
        b_LdTmpBufRam(F_PcbType)        = 0;

//        b_LdTmpBufRam(F_EncoderRate)    = 1;
        i_LdTmpBufRam(F_StopPulse0)     = 1000;

        b_LdTmpBufRam(F_year)           = 0;
        b_LdTmpBufRam(F_month)          = 0;
        b_LdTmpBufRam(F_day)            = 0;

        b_LdTmpBufRam(F_Company)        = COMPANY;
        b_LdTmpBufRam(F_SystemSet)      = 0x0;

        b_LdTmpBufRam(F_NonService0)    = Init_ALL_FF;
        b_LdTmpBufRam(F_NonService1)    = Init_ALL_FF;
        b_LdTmpBufRam(F_NonService2)    = Init_ALL_FF;
        b_LdTmpBufRam(F_NonService3)    = Init_ALL_FF;
        b_LdTmpBufRam(F_NonService4)    = Init_ALL_FF;
        b_LdTmpBufRam(F_NonService5)    = Init_ALL_FF;
        b_LdTmpBufRam(F_NonService6)    = Init_ALL_FF;
        b_LdTmpBufRam(F_NonService7)    = Init_ALL_FF;


///////////////////////////////////////////////
        //  P1  P2  P3  P4
        //  0   0   0   0           :NONE_USE_SPD  
        //  1   0   0   0           :P1
        //  0   1   0   0           :P2
        //  1   1   0   0           :P1P2
        //  0   0   1   0           :P3
        //  1   0   1   0           :P1P3
        //  0   1   1   0           :P2P3
        //  1   1   1   0           :P1P2P3
        //  0   0   0   1           :P4
        //  1   0   0   1           :P1P4
        //  0   1   0   1           :P2P4
        //  1   1   0   1           :P1P2P4
        //  0   0   1   1           :P3P4
        //  1   0   1   1           :P1P3P4
        //  0   1   1   1           :P2P3P4
        //  1   1   1   1           :P1P2P3P4

///////////////////////////////////////////////
/*
DEFAULT_SPD	   
        b_LdTmpBufRam(F_ManualSpeed)    = P1P2_SPD;                   
        b_LdTmpBufRam(F_BatterySpeed)   = NONE_USE_SPD;      
        b_LdTmpBufRam(F_DecreaseSpeed)  = P2_SPD;                    
        b_LdTmpBufRam(F_FhmSpeed)       = NONE_USE_SPD;     
        b_LdTmpBufRam(F_Speed1)        	= NONE_USE_SPD;     
        b_LdTmpBufRam(F_Speed2)        	= P3_SPD;              
        b_LdTmpBufRam(F_Speed3)        	= P1_SPD;                    
        b_LdTmpBufRam(F_LuLd_mpm)       = 0;     
        b_LdTmpBufRam(F_SU2SD2_V_SPD3)	= 0;    
        b_LdTmpBufRam(F_X0X1_V_SPD3)  	= 0;   

*/
        b_LdTmpBufRam(F_ManualSpeed)    = P1P2_SPD;          
        b_LdTmpBufRam(F_BatterySpeed)   = NONE_USE_SPD;      
        b_LdTmpBufRam(F_DecreaseSpeed)  = P2_SPD;                    
        b_LdTmpBufRam(F_FhmSpeed)       = NONE_USE_SPD;     
        b_LdTmpBufRam(F_Etc1Speed)      = NONE_USE_SPD;     
        b_LdTmpBufRam(F_Etc2Speed)      = NONE_USE_SPD;     
        b_LdTmpBufRam(F_Speed30)        = NONE_USE_SPD;     
        b_LdTmpBufRam(F_Speed45)        = P3_SPD;              
        b_LdTmpBufRam(F_Speed60)        = P1_SPD;                    
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
        b_LdTmpBufRam(F_AutoLandingMode)= 0;     //no Auto landing


        flash_write_DspChar(F_ManualSpeed);


/*
		block_pt=(F_NonService0/64);
		block_pt=(block_pt * 64);
        GetFlashDataToBufRam(block_pt);

//#ifdef	FLOOR_64
        b_LdTmpBufRam(F_NonService0)    = Init_ALL_FF;
        b_LdTmpBufRam(F_NonService1)    = Init_ALL_FF;
        b_LdTmpBufRam(F_NonService2)    = Init_ALL_FF;
        b_LdTmpBufRam(F_NonService3)    = Init_ALL_FF;
        b_LdTmpBufRam(F_NonService4)    = Init_ALL_FF;
        b_LdTmpBufRam(F_NonService5)    = Init_ALL_FF;
        b_LdTmpBufRam(F_NonService6)    = Init_ALL_FF;
        b_LdTmpBufRam(F_NonService7)    = Init_ALL_FF;
        flash_write_DspChar(block_pt);

*/

#ifdef	FLOOR_64
        for(i=0;i<64;i++){
            b_LdTmpBufRam(i)  = DftFlrName[i+14];
        }
	    flash_write_DspChar(F_FlrDspCh);         		


        for(i=0;i<64;i++){
            b_LdTmpBufRam(i)  = DftFlrName[i+14+64];
        }
	    flash_write_DspChar(F_FlrDspCh1);         		
#else
        for(i=0;i<64;i++){
            b_LdTmpBufRam(i)  = DftFlrName[i+14];
        }
        flash_write_DspChar(F_FlrDspCh);         		
#endif

        DefaultEncoderRpmMpm();
        CaluDecreasePulse();
	}  



   	if(cF_TOPFLR < 1 ){
        LadderBuf[C_SAVE_DATA]=1;
		SaveVerify = 0x55;
        F_SetupData_ReSet(F_TopFlr,1);
    }

#ifdef	FLOOR_64
   	if(cF_TOPFLR > 63 ){
#else
   	if(cF_TOPFLR > 31 ){
#endif
        LadderBuf[C_SAVE_DATA]=31;
		SaveVerify = 0x55;
        F_SetupData_ReSet(F_TopFlr,1);
    }

   	if(cF_PRKFLR > cF_TOPFLR ){
        LadderBuf[C_SAVE_DATA]=0;
		SaveVerify = 0x55;
        F_SetupData_ReSet(F_PrkFlr,1);
    }


   	if(cF_OPWTTM > 9999 ){
        LadderBuf[C_SAVE_DATA]=0;
		SaveVerify = 0x55;
        F_SetupData_ReSet(F_OpWtTm,1);
    }

   	if(cF_OPTTTM > 9999 ){
        LadderBuf[C_SAVE_DATA]=0;
		SaveVerify = 0x55;
        F_SetupData_ReSet(F_OpTtTm,1);
    }


/*
   	if(cF_USERLAMP1 > USER_LAMP_SORT ){
        LadderBuf[C_SAVE_DATA]=0;
		SaveVerify = 0x55;
        F_SetupData_ReSet(F_UserLamp1,1);
    }

   	if(cF_USERLAMP2 > USER_LAMP_SORT ){
        LadderBuf[C_SAVE_DATA]=1;
		SaveVerify = 0x55;
        F_SetupData_ReSet(F_UserLamp2,1);
    }
*/



	EEP_Load_All();

	SaveVerify = 0x0;

   	return(0);     
}




void    __attribute__((section(".usercode"))) HextoASCIIByte(void)
{
    
    LocalType   i;

    i=(src & 0xf0) >> 4;
    if(i<0x0a)   i= i + '0';
    else         i= i + '7';
    firstdata=i;
        
    i=(src & 0x0f);
    if(i<0x0a)   i= i + '0';
    else         i= i + '7';
    seconddata=i;        
}




UserDataType	__attribute__((section(".usercode"))) SaveEebuf(UserDataType  ErrName)
{
	LocalType i;

	i=(eDArry[eErrCntPt] % (ERR_SAVE_CNT));


	eDArryEvent[i]=1;
	

	i=(i * ERR_SAVE_WIDE);

	eDArry[eSysErCnt + i + 0] = sRamDArry[Month];             
    eDArry[eSysErCnt + i + 1] = sRamDArry[Day];             
    eDArry[eSysErCnt + i + 2] = sRamDArry[mcurfloor];            
    eDArry[eSysErCnt + i + 3] = ErrName;       
    eDArry[eSysErCnt + i + 4] = sRamDArry[Hour];             
    eDArry[eSysErCnt + i + 5] = sRamDArry[Minuate];             



	eDArry[eErrCntPt]++; 
	if(eDArry[eErrCntPt] > 0xff){
     	eDArry[eErrCntPt]=0; 
	}     	
           
	bErrSaveFlag=1;

	return(0);
}


       
UserDataType  __attribute__((section(".usercode"))) ErrSave(void)
{  

	if( IN_AUTO && !bAutoButtonErr)				return(0);							
	if( bsEmergency && (EmgTimer < 5))			return(0);


   	if(bsSdsErr){								//26
      	if(!bBefbsSdsErr){
			SaveEebuf(sSdsErr);
        	bBefbsSdsErr=bsSdsErr;
      	}        
   	}

   	if(bsSusErr){								//25
      	if(!bBefbsSusErr){
			SaveEebuf(sSusErr);
        	bBefbsSusErr=bsSusErr;
      	}        
   	}

   	if(bsBreakOpen){							//24
      	if(!bBefbsBreakOpen){
			SaveEebuf(sBreakOpen);
        	bBefbsBreakOpen=bsBreakOpen;
      	}        
   	}

   	if(bsBreakMgtOpen){							//23
      	if(!bBefbsBreakMgtOpen){
			SaveEebuf(sBreakMgtOpen);
        	bBefbsBreakMgtOpen=bsBreakMgtOpen;
      	}        
   	}

   	if(bEncoderABErr){							//16
      	if(!bBefbEncoderABErr){
			SaveEebuf(sEncoderABErr);
        	bBefbEncoderABErr=bEncoderABErr;
      	}        
   	}


   	if(bEncoderErr){							//15
      	if(!bBefbEncoderErr){
			SaveEebuf(sEncoderErr);
        	bBefbEncoderErr=bEncoderErr;
      	}        
   	}     

   	if(bMotor_Overheat){								
      	if(!bBefbMotor_Overheat){
   			SaveEebuf(sMOTOR_OVERHEAT);
        	bBefbMotor_Overheat=bMotor_Overheat;
      	}        
   	}


	if(bRelevelErr){							//13
		if(!bBefbRelevelErr){
			SaveEebuf(sRelevelError);
        	bBefbRelevelErr=bRelevelErr;
      	}        
   	}


	if(bsCleRunOff){							//13
		if(!bBefbsCleRunOff){
			SaveEebuf(sCLE_RUN_OFF);
        	bBefbsCleRunOff=bsCleRunOff;
      	}        
   	}


   	if(bsHdsRunOff){							//12
      	if(!bBefbsHdsRunOff){
			SaveEebuf(sHDS_RUN_OFF);
        	bBefbsHdsRunOff=bsHdsRunOff;
      	}        
   	}

   	if(bsNextFloor){							//10
      	if(!bBefbsNextFloor){
			SaveEebuf(sNEXT_FLOOR);
        	bBefbsNextFloor=bsNextFloor;
      	}        
   	}

   	if(bsLuLdNoOff){							//9
      	if(!bBefbsLuLdNoOff){
   			SaveEebuf(sLULD_NO_OFF);
        	bBefbsLuLdNoOff=bsLuLdNoOff;
      	}        
   	}

   	if(bsDls){									//8
      	if(!bBefbsDls){
			SaveEebuf(sDLS);
        	bBefbsDls=bsDls;
      	}        
   	}

   	if(bsUls){									//7
      	if(!bBefbsUls){
			SaveEebuf(sULS);
        	bBefbsUls=bsUls;
      	}        
   	}

   	if(bsSlip){		
      	if(!bBefbsSlip){
      		SaveEebuf(sSLIP);
        	bBefbsSlip=bsSlip;
      	}        
   	}

   	if(bsLope){									//4
      	if(!bBefbsLope){
      		SaveEebuf(sLOPE_BRK);
        	bBefbsLope=bsLope;
      	}        
   	}

   	if(bsUcmpFeedErr){									//4
      	if(!bBefbsUcmpFeedErr){
      		SaveEebuf(sUcmpFeedErrMsg);
        	bBefbsUcmpFeedErr=bsUcmpFeedErr;
      	}        
   	}
        

   	if(bsInvCurNext){							//2
      	if(!bBefbsInvCurNext){
			SaveEebuf(sI_C_N_FLR);
        	bBefbsInvCurNext=bsInvCurNext;
      	}        
   	}     

   	if(bsInvertErr){							//1
      	if(!bBefbsInvertErr){
			SaveEebuf(sInvertErr);
        	bBefbsInvertErr=bsInvertErr;
      	}        
   	}

	if(bEqualFloorError){             ///not
      	if(!bBefbEqualFloorError){
			SaveEebuf(sEqualFloorError);
        	bBefbEqualFloorError=bEqualFloorError;
      	}        
	}   
   	if(bsLuOrLdErr && (LuLdErrNm > 0)){							  //
      	if(!bBefsLuOrLdErr){
			SaveEebuf(sLuOrLdErr0 + LuLdErrNm-1);
        	bBefsLuOrLdErr=bsLuOrLdErr;
      	}        
   	}

   	if(bDoorJumper){							  //
      	if(!bBefDoorJumper){
			SaveEebuf(sCarDoor_Jumper + DoorJumperNm);
        	bBefDoorJumper=bDoorJumper;
      	}        
   	}

   	if(bsCleNoOn){							  
      	if(!bBefbsCleNoOn){
			SaveEebuf(sCLE_NO_ON);
        	bBefbsCleNoOn=bsCleNoOn;
      	}        
   	}

   	if(bsEarthquake){							//36
      	if(!bBefbsEarthquake){
			SaveEebuf(sEarthquake);
        	bBefbsEarthquake=bsEarthquake;
      	}        
   	}

	if(bDZ_Err){
      	if(!bBefbDZ_Err){
			SaveEebuf(sDZErr);
        	bBefbDZ_Err=bDZ_Err;
      	}        
	}   

	if(bAutoButtonErr){
      	if(!bBefbAutoButtonErr){
			SaveEebuf(sAutoOff);
        	bBefbAutoButtonErr=bAutoButtonErr;
      	}        
	}   

   	if(bsEmergency){							//3
      	if(!bBefbsEmergency){
			SaveEebuf(sEMERGENCY);    
        	bBefbsEmergency=bsEmergency;
      	}        
   	}

    return(0);		
}


void  __attribute__((section(".usercode"))) ErrFlagClr(void)
{        
	if(bErrClearOnce){
		bBefbsBreakOpen=0;
		bBefbsBreakMgtOpen=0;
		bBefbRelevelErr=0;
		bBefbsSlip=0;
		bBefbsLope=0;
		bBefsLuOrLdErr=0;
		bBefbsCleRunOff=0;
		bBefbsHdsRunOff=0;
		bBefbsEmergency=0;
		bBefbsNextFloor=0;
		bBefbsCleNoOn=0;
		bBefbsLuLdNoOff=0;
	    bBefbsInvCurNext=0;
		bBefbsDls=0;
		bBefbsUls=0; 
	    bBefbEncoderErr=0;
	    bBefbEncoderABErr=0;
	    bBefbsInvertErr=0;
	    bBefbsSdsErr=0;
	    bBefbsSusErr=0;
		bBefDoorJumper=0;
		bBefbMotor_Overheat=0;
		bBefbEqualFloorError=0;
		bBefbAutoButtonErr=0;
		bBefbsEarthquake=0;
    	bBefbDZ_Err=0;
		bBefbsUcmpFeedErr=0;
		bErrClearOnce=0;
	}
}





UserDataType  __attribute__((section(".usercode"))) ErrSaveFlash(void)
{
	unsigned int	i,j;
	long_field	m_data;  
	
	if(sRamDArry[mBefErrCntPt] >= 40)	sRamDArry[mBefErrCntPt]=0; 

	j=0;
	for(i=0;i<16;i++){
		m_data.byte[0]=eDArry[j+0];
		m_data.byte[1]=eDArry[j+1];
		m_data.byte[2]=eDArry[j+2];
		m_data.byte[3]=eDArry[j+3];
		parameter_mirror[i]=m_data.long_data;
		j=(j+4);
	}

	SaveVerify=0x55;
	flash_write_DspChar( (F_BLOCK_X1 + 0));
	SaveVerify=0x0;


	for(i=0;i<16;i++){
		m_data.byte[0]=eDArry[j+0];
		m_data.byte[1]=eDArry[j+1];
		m_data.byte[2]=eDArry[j+2];
		m_data.byte[3]=eDArry[j+3];
		parameter_mirror[i]=m_data.long_data;
		j=(j+4);
	}

	SaveVerify=0x55;
	flash_write_DspChar( (F_BLOCK_X1 + 64));
	SaveVerify=0x0;

	return(0);
}


void  __attribute__((section(".usercode"))) SystemErrSave(void)
{
	unsigned char kk;

	if(bSaveErrCnt){
		ErrSave(); 
		bErrClearOnce=1;
	}              
    else    ErrFlagClr();


	if(bErrSaveFlag && !bMoveCar && (ElevStopTime > 100)){	// 10 sec
		bErrSaveFlag=0;
		ErrSaveFlash();
	}  

}









void  __attribute__((section(".usercode"))) Serial2Check(void)
{
    if(RxStatus2==RX_GOOD){
		if(bExportData || bImportData){
			NewLoaderChk();
		}
        LadderBuf[C_SAVE_DATA+0]=RxBuffer2[2];

		if(RxBuffer2[1] == '0'){
            bAllMenu=1;
		} 

		if(RxBuffer2[1] == cF_COMPANY)	bLoaderActive=1;
		
     
        NewFlashData();
        RxStatus2=STX_CHK;                        
    }         
                           
    if((RxStatus2 != TX_SET) && (SerialTime2 > 10)){
        if(LadderTime>100){
            LadderBuf[C_SAVE_DATA+0]='N';      
            NewFlashData();
            LadderTime=0;
        }
        LdDataTx();
        SerialTime2=0;
    }               
}




void  __attribute__((section(".usercode"))) ClrUpDnWard(void)
{        
    S2_DN1=0;
    S1_UP1=0;                                                     //up
    S3_SHIFT1=0;
 
    bUpWard=0;              
    bDnWard=0;              

	sRamDArry[DEST_FLR] = (sRamDArry[DEST_FLR] & ONLY_FLR);
}


void  __attribute__((section(".usercode"))) UpWard(void)
{    
   S2_DN1=0;
   S1_UP1=1;
   bUpWard=1;              
   bDnWard=0;             

//	sRamDArry[DEST_FLR]= (sRamDArry[DEST_FLR] & ~DN_READY);
//	sRamDArry[DEST_FLR]= (sRamDArry[DEST_FLR] |  UP_READY);
   
   if(bMoveCar && !bUnd)    S3_SHIFT1=1; //shift
   else                     S3_SHIFT1=0; //shift
}


void  __attribute__((section(".usercode"))) DnWard(void)
{    
   S2_DN1=1;
   S1_UP1=0;         
   bUpWard=0;              
   bDnWard=1;              

//	sRamDArry[DEST_FLR]= (sRamDArry[DEST_FLR] & ~UP_READY);
//	sRamDArry[DEST_FLR]= (sRamDArry[DEST_FLR] |  DN_READY);
   
   if(bMoveCar && !bUnd)    S3_SHIFT1=1; //shift
   else                     S3_SHIFT1=0; //shift
}



UserDataType  __attribute__((section(".usercode"))) ReadyAndNoKeyCheck(void)
{
	if((sRamDArry[mDoorSeq] == READY_ELEVATOR) && 
        (sRamDArry[mHighFloor] == 0) && 
        (sRamDArry[mLowFloor] == 0)){  
     	return(0);       
	}                      
	else	return(1);
}



void  __attribute__((section(".usercode"))) Virtual_Floor_Set(UserDataType vFloor)
{

#ifdef	FLOOR_64
	if(vFloor <= cF_TOPFLR){
		if(sRamDArry[mcurfloor] > (unsigned char)(vFloor)){
			if(vFloor == 0)	vFloor=(vFloor | UP_READY);                     
			sRamDArry[mLowFloor] = (unsigned char)(vFloor);
		}
		else if(sRamDArry[mcurfloor] < (unsigned char)(vFloor)){
			sRamDArry[mHighFloor] = (unsigned char)(vFloor);                     
		}
	}
#else
	if(vFloor <= cF_TOPFLR){
		if(sRamDArry[mcurfloor] > (unsigned char)(vFloor)){
			sRamDArry[mLowFloor] = (unsigned char)(vFloor | CAR_READY);                     
		}
		else if(sRamDArry[mcurfloor] < (unsigned char)(vFloor)){
			sRamDArry[mHighFloor] = (unsigned char)(vFloor | CAR_READY);                     
		}
	}
#endif
}



unsigned int  __attribute__((section(".usercode"))) AutoRunReady(void)
{
    if(!bAuto  || !bMotorRestartOn)    							return(0);
    if(S3_PARKING1  || S2_FIRE1)    							return(0);
	else if(DoorOpenEndWaitChk())								return(0);
    else if(bCarErr || bCarStopNoRun || bCarStop)               return(0);                 
    else                                                        return(1);
}




/*
unsigned int  __attribute__((section(".usercode"))) HighVirtualKeyCheck(void)
{
	unsigned int	i,base_buf,base_bit;
	unsigned char tmpkey[8];
	
	for(i=0;i<8;i++){
		tmpkey[0]= (sRamDArry[ExtCarKey1]  | sRamDArry[ExtUpCall0]); 
		tmpkey[1]= (sRamDArry[ExtCarKey9]  | sRamDArry[ExtUpCall1]); 
		tmpkey[2]= (sRamDArry[ExtCarKey17] | sRamDArry[ExtUpCall2]); 
		tmpkey[3]= (sRamDArry[ExtCarKey25] | sRamDArry[ExtUpCall3]); 
		tmpkey[4]= (sRamDArry[ExtCarKey33] | sRamDArry[ExtUpCall4]); 
		tmpkey[5]= (sRamDArry[ExtCarKey41] | sRamDArry[ExtUpCall5]); 
		tmpkey[6]= (sRamDArry[ExtCarKey49] | sRamDArry[ExtUpCall6]); 
		tmpkey[7]= (sRamDArry[ExtCarKey57] | sRamDArry[ExtUpCall7]); 
	}

	if(tmpkey[0] || tmpkey[1] || tmpkey[2] || tmpkey[3] || tmpkey[4] || tmpkey[5] || tmpkey[6] || tmpkey[7]){		
		i=sRamDArry[mcurfloor];
		base_buf=(i/8);
		base_bit=(i%8);
		
		
	}
	else	return(0);

	i=sRamDArry[mcurfloor];
	


}
*/


unsigned int  __attribute__((section(".usercode"))) SlipPulseCalu(void)
{
	Base_Slip_pulse=GET_LONG(MM_PULSE);

	if(Base_Slip_pulse>0){
		Slip_pulse = ((unsigned long)10000 * (unsigned long)SLIP_MM);		
		Slip_pulse = (Slip_pulse /Base_Slip_pulse);		
	}
	
	return(0);
}


unsigned int  __attribute__((section(".usercode"))) VirtualExtKeyClear(void)
{
	unsigned int i,j;
	unsigned int curkeybyte,virkeybyte,virkeybit,virkeyfloor;

	virkeyfloor=sRamDArry[mcurfloor];
	i=(virkeyfloor/8);
	j=(virkeyfloor%8);
	virkeybit=0x01;
	virkeybit=(virkeybit << j);

	if(bUpWard){
		sRamDArry[HibUpCall0+i] 		= (sRamDArry[HibUpCall0+i] 			& ~virkeybit); 	
		ShadowsRamDArry[HibUpCall0+i] 	= (ShadowsRamDArry[HibUpCall0+i]	& ~virkeybit); 	
	}
	if(bDnWard){
		sRamDArry[HibDnCall0+i] 		= (sRamDArry[HibDnCall0+i] 			& ~virkeybit); 	
		ShadowsRamDArry[HibDnCall0+i] 	= (ShadowsRamDArry[HibDnCall0+i] 	& ~virkeybit); 	
	}

	if(i < 4){
		sRamDArry[mCarKey1+i] 			= (sRamDArry[mCarKey1+i] 			& ~virkeybit); 	
		ShadowsRamDArry[mCarKey1+i] 	= (ShadowsRamDArry[mCarKey1+i] 		& ~virkeybit); 	
	}
	else if((i >= 4) && (i < 8)){
		i=i-4;
		sRamDArry[mCarKey33+i] 			= (sRamDArry[mCarKey33+i] 			& ~virkeybit); 	
		ShadowsRamDArry[mCarKey33+i] 	= (ShadowsRamDArry[mCarKey33+i] 	& ~virkeybit); 	
	}


/*
	for(i=0;i<8;i++){
		if( sRamDArry[HibUpCall0+i] != ShadowsRamDArry[HibUpCall0+i]){	
			virkeybyte=ShadowsRamDArry[HibUpCall0+i];
			curkeybyte=sRamDArry[HibUpCall0+i];
			virkeybit=0x01;
			for(j=0;j<8;j++){
				if( (virkeybyte & virkeybit) && !(curkeybyte & virkeybit)){
					virkeyfloor=(i * 8) + j + 1;
					sRamDArry[mCrtExtMoveFlr]=(unsigned char)(virkeyfloor | 0x80);
					sRamDArry[HibUpCall0+i]= (sRamDArry[HibUpCall0+i] | virkeybit);
					ExtKeyCnt=3;
					return(0);
				} 
				virkeybit=(virkeybit << 1);
			}
		}
	}

	for(i=0;i<8;i++){
		if( sRamDArry[HibDnCall0+i] != ShadowsRamDArry[HibDnCall0+i]){	
			virkeybyte=ShadowsRamDArry[HibDnCall0+i];
			curkeybyte=sRamDArry[HibDnCall0+i];
			virkeybit=0x01;
			for(j=0;j<8;j++){
				if( (virkeybyte & virkeybit) && !(curkeybyte & virkeybit)){
					virkeyfloor=(i * 8) + j + 1;
					sRamDArry[mCrtExtMoveFlr]=(unsigned char)(virkeyfloor | 0x40);
					sRamDArry[HibDnCall0+i]= (sRamDArry[HibDnCall0+i] | virkeybit);
					ExtKeyCnt=3;
					return(0);
				} 
				virkeybit=(virkeybit << 1);
			}
		}
	}
*/
    return(0);
}


unsigned int  __attribute__((section(".usercode"))) VirtualExtKey(void)
{
	unsigned int i,j;
	unsigned int curkeybyte,virkeybyte,virkeybit,virkeyfloor;

	if(ExtKeyCnt > 0)													return(0);

	for(i=0;i<8;i++){
//		if( sRamDArry[HibUpCall0+i] != ShadowsRamDArry[HibUpCall0+i]){	
		if( ShadowsRamDArry[HibUpCall0+i]){	
			virkeybyte=ShadowsRamDArry[HibUpCall0+i];
			curkeybyte=sRamDArry[HibUpCall0+i];
			virkeybit=0x01;
			for(j=0;j<8;j++){
				if( (virkeybyte & virkeybit) && !(curkeybyte & virkeybit)){
					virkeyfloor=(i * 8) + j + 1;
					sRamDArry[mCrtExtMoveFlr]=(unsigned char)(virkeyfloor | UP_READY);
					sRamDArry[HibUpCall0+i]= (sRamDArry[HibUpCall0+i] | virkeybit);
					ShadowsRamDArry[HibUpCall0+i]= (ShadowsRamDArry[HibUpCall0+i] & ~virkeybit);
					ExtKeyCnt=3;
					return(0);
				} 
				virkeybit=(virkeybit << 1);
			}
		}
	}

	for(i=0;i<8;i++){
//		if( sRamDArry[HibDnCall0+i] != ShadowsRamDArry[HibDnCall0+i]){	
		if( ShadowsRamDArry[HibDnCall0+i]){	
			virkeybyte=ShadowsRamDArry[HibDnCall0+i];
			curkeybyte=sRamDArry[HibDnCall0+i];
			virkeybit=0x01;
			for(j=0;j<8;j++){
				if( (virkeybyte & virkeybit) && !(curkeybyte & virkeybit)){
					virkeyfloor=(i * 8) + j + 1;
					sRamDArry[mCrtExtMoveFlr]=(unsigned char)(virkeyfloor | DN_READY);
					sRamDArry[HibDnCall0+i]= (sRamDArry[HibDnCall0+i] | virkeybit);
					ShadowsRamDArry[HibDnCall0+i]= (ShadowsRamDArry[HibDnCall0+i] & ~virkeybit);
					ExtKeyCnt=3;
					return(0);
				} 
				virkeybit=(virkeybit << 1);
			}
		}
	}


	for(i=0;i<4;i++){
//		if( sRamDArry[mCarKey1+i] != ShadowsRamDArry[mCarKey1+i]){	
		if( ShadowsRamDArry[mCarKey1+i]){	
			virkeybyte=ShadowsRamDArry[mCarKey1+i];
			curkeybyte=sRamDArry[mCarKey1+i];
			virkeybit=0x01;
			for(j=0;j<8;j++){
				if( (virkeybyte & virkeybit) && !(curkeybyte & virkeybit)){
					virkeyfloor=(i * 8) + j + 1;
					sRamDArry[mCrtExtMoveFlr]=(unsigned char)(virkeyfloor);
					sRamDArry[mCarKey1+i]= (sRamDArry[mCarKey1+i] | virkeybit);
					ShadowsRamDArry[mCarKey1+i]= (ShadowsRamDArry[mCarKey1+i] & ~virkeybit);
					ExtKeyCnt=3;
					return(0);
				} 
				virkeybit=(virkeybit << 1);
			}
		}
	}

	for(i=0;i<4;i++){
//		if( sRamDArry[mCarKey33+i] != ShadowsRamDArry[mCarKey33+i]){	
		if( ShadowsRamDArry[mCarKey33+i]){	
			virkeybyte=ShadowsRamDArry[mCarKey33+i];
			curkeybyte=sRamDArry[mCarKey33+i];
			virkeybit=0x01;
			for(j=0;j<8;j++){
				if( (virkeybyte & virkeybit) && !(curkeybyte & virkeybit)){
					virkeyfloor=(i * 8) + j + 1;
					sRamDArry[mCrtExtMoveFlr]=(unsigned char)(virkeyfloor);
					sRamDArry[mCarKey33+i]= (sRamDArry[mCarKey33+i] | virkeybit);
					ShadowsRamDArry[mCarKey33+i]= (ShadowsRamDArry[mCarKey33+i] & ~virkeybit);
					ExtKeyCnt=3;
					return(0);
				} 
				virkeybit=(virkeybit << 1);
			}
		}
	}

    return(0);
}




unsigned int  __attribute__((section(".usercode"))) OneStopKey(void)
{

    unsigned 	char  TmpOneStopFlr;
	

	if( !(cF_ONESTOP_FLOOR & UPDN_READY))									return(0);


	TmpOneStopFlr = (cF_ONESTOP_FLOOR & (~(UPDN_READY)) );

  	if(S3_VIP1)																return(0);
    if(TmpOneStopFlr >= cF_TOPFLR)                                          return(0);
    if(!AutoRunReady())                                                     return(0);
    if(bTestKey)                                                            return(0);  
	if( !bUpWard && !bDnWard)												return(0); 		
	if( (sRamDArry[mAckStopFloor] & ONLY_FLR) == (TmpOneStopFlr))			return(0);
    if((sRamDArry[mcurfloor] == TmpOneStopFlr))                           	return(0);

	if(bUpWard){
        if( !(cF_ONESTOP_FLOOR & UP_READY))           						return(0);	

		#ifdef  FLOOR_64
        if( sRamDArry[mHighFloor] == 0)            							return(0);
		#else
        if( !(sRamDArry[mHighFloor] & UPDN_CAR_READY))            			return(0);
		#endif

        if((sRamDArry[mHighFloor] & ONLY_FLR) <= (TmpOneStopFlr))           return(0);

        if((sRamDArry[mcurfloor] > TmpOneStopFlr))                          return(0);
        if((sRamDArry[mcurfloor] >= cF_TOPFLR))                             return(0);
    	Virtual_Floor_Set(TmpOneStopFlr);

    }
    else if(bDnWard){
        if( !(cF_ONESTOP_FLOOR & DN_READY))           						return(0);			

		#ifdef  FLOOR_64
        if( sRamDArry[mLowFloor] == 0)            							return(0);
		#else
        if( !(sRamDArry[mLowFloor] & UPDN_CAR_READY))            			return(0);
		#endif

        if((sRamDArry[mLowFloor] & ONLY_FLR) >= (TmpOneStopFlr))            return(0);
        if((sRamDArry[mcurfloor] < TmpOneStopFlr))                          return(0);
        if((sRamDArry[mcurfloor] <  1))                                 	return(0);
	    Virtual_Floor_Set(TmpOneStopFlr);
    }

    return(0);
}



void  __attribute__((section(".usercode"))) VirCarKeyClr(void)
{
    sRamDArry[mCarKey1] =0x0;
    sRamDArry[mCarKey9] =0x0;
    sRamDArry[mCarKey17]=0x0;     
    sRamDArry[mCarKey25]=0x0;
    sRamDArry[mCarKey33]=0x0;
    sRamDArry[mCarKey41]=0x0;
    sRamDArry[mCarKey49]=0x0;     
    sRamDArry[mCarKey57]=0x0;


    ShadowsRamDArry[mCarKey1] =0x0;
    ShadowsRamDArry[mCarKey9] =0x0;
    ShadowsRamDArry[mCarKey17]=0x0;     
    ShadowsRamDArry[mCarKey25]=0x0;
    ShadowsRamDArry[mCarKey33]=0x0;
    ShadowsRamDArry[mCarKey41]=0x0;
    ShadowsRamDArry[mCarKey49]=0x0;     
    ShadowsRamDArry[mCarKey57]=0x0;

}

void  __attribute__((section(".usercode"))) VirExtKeyClr(void)
{
    sRamDArry[HibUpCall0]=0x0;
    sRamDArry[HibUpCall1]=0x0;
    sRamDArry[HibUpCall2]=0x0;     
    sRamDArry[HibUpCall3]=0x0;
    sRamDArry[HibUpCall4]=0x0;
    sRamDArry[HibUpCall5]=0x0;
    sRamDArry[HibUpCall6]=0x0;     
    sRamDArry[HibUpCall7]=0x0;

    sRamDArry[HibDnCall0]=0x0;
    sRamDArry[HibDnCall1]=0x0;
    sRamDArry[HibDnCall2]=0x0;     
    sRamDArry[HibDnCall3]=0x0;
    sRamDArry[HibDnCall4]=0x0;
    sRamDArry[HibDnCall5]=0x0;
    sRamDArry[HibDnCall6]=0x0;     
    sRamDArry[HibDnCall7]=0x0;


    ShadowsRamDArry[HibUpCall0]=0x0;
    ShadowsRamDArry[HibUpCall1]=0x0;
    ShadowsRamDArry[HibUpCall2]=0x0;     
    ShadowsRamDArry[HibUpCall3]=0x0;
    ShadowsRamDArry[HibUpCall4]=0x0;
    ShadowsRamDArry[HibUpCall5]=0x0;
    ShadowsRamDArry[HibUpCall6]=0x0;     
    ShadowsRamDArry[HibUpCall7]=0x0;

    ShadowsRamDArry[HibDnCall0]=0x0;
    ShadowsRamDArry[HibDnCall1]=0x0;
    ShadowsRamDArry[HibDnCall2]=0x0;     
    ShadowsRamDArry[HibDnCall3]=0x0;
    ShadowsRamDArry[HibDnCall4]=0x0;
    ShadowsRamDArry[HibDnCall5]=0x0;
    ShadowsRamDArry[HibDnCall6]=0x0;     
    ShadowsRamDArry[HibDnCall7]=0x0;
}


void  __attribute__((section(".usercode"))) CarKeyClr(void)
{

#ifdef	FLOOR_64

	if((sRamDArry[mEqualFloor]	& UPDN_READY) == 0)	sRamDArry[mEqualFloor]=0;	
	if((sRamDArry[mHighFloor]  	& UPDN_READY) == 0)	sRamDArry[mHighFloor]=0;	
	if((sRamDArry[mLowFloor]   	& UPDN_READY) == 0)	sRamDArry[mLowFloor]=0;	

    sRamDArry[mCurCarkey]  =0x0;
//    sRamDArry[mMostCarkey] =0x0;

    sRamDArry[mCarKey1] =0x0;
    sRamDArry[mCarKey9] =0x0;
    sRamDArry[mCarKey17]=0x0;     
    sRamDArry[mCarKey25]=0x0;

    sRamDArry[mCarKey33]=0x0;
    sRamDArry[mCarKey41]=0x0;
    sRamDArry[mCarKey49]=0x0;     
    sRamDArry[mCarKey57]=0x0;
#else
	sRamDArry[mEqualFloor]=(sRamDArry[mEqualFloor] & ~CAR_READY);
	sRamDArry[mHighFloor]=(sRamDArry[mHighFloor] & ~CAR_READY);	
	sRamDArry[mLowFloor]=(sRamDArry[mLowFloor] & ~CAR_READY);

    sRamDArry[mCarKey1] =0x0;
    sRamDArry[mCarKey9] =0x0;
    sRamDArry[mCarKey17]=0x0;     
    sRamDArry[mCarKey25]=0x0;
#endif


	VirCarKeyClr();
///	VirExtKeyClr();
}


void  __attribute__((section(".usercode"))) KeyClr(void)
{
#ifdef	FLOOR_64
	sRamDArry[mEqualFloor]=0x0;
	sRamDArry[mHighFloor]=0x0;	
	sRamDArry[mLowFloor]=0x0;
    sRamDArry[mAckStopFloor] = 0x0;
    sRamDArry[mNewAckStopFloor]=0x0;

    sRamDArry[mCurCarkey]  =0x0;
//    sRamDArry[mMostCarkey] =0x0;
	sRamDArry[mMostLongDst]=0x0;

    sRamDArry[mCarKey1] =0x0;
    sRamDArry[mCarKey9] =0x0;
    sRamDArry[mCarKey17]=0x0;     
    sRamDArry[mCarKey25]=0x0;

    sRamDArry[mCarKey33]=0x0;
    sRamDArry[mCarKey41]=0x0;
    sRamDArry[mCarKey49]=0x0;     
    sRamDArry[mCarKey57]=0x0;

#else
	sRamDArry[mEqualFloor]=0x0;
	sRamDArry[mHighFloor]=0x0;	
	sRamDArry[mLowFloor]=0x0;
    sRamDArry[mAckStopFloor] = 0x0;
    sRamDArry[mNewAckStopFloor]=0x0;

    sRamDArry[mCarKey1] =0x0;
    sRamDArry[mCarKey9] =0x0;
    sRamDArry[mCarKey17]=0x0;     
    sRamDArry[mCarKey25]=0x0;
#endif

	VirCarKeyClr();
	VirExtKeyClr();
}




void   __attribute__((section(".usercode"))) Init485_Bd(void)
{
	for(LogAddressLoop=0;LogAddressLoop<ABS_ADDRESS;LogAddressLoop++){
		BDid[sRamDArry[mDoorSeq]]=0;
		BdErrCntSeq[sRamDArry[mDoorSeq]]=0;
	}
      
	for(LogAddressLoop=0;LogAddressLoop < 12;LogAddressLoop++){
		errbd[LogAddressLoop]=0x0;
		Olderrbd[LogAddressLoop]=0x0;
	}
   
	LogAddressLoop=0;
	LogAddress=0;        
	TimeOutBd=0;
	BefRcvAdr=0;
	AbsAddress=0;
	SerialTime=0;
	bFindBoard=0;   
	errpt=0;
	ErrBdNamePt=0;
	BefErrBdNamePt=0;
}


void  __attribute__((section(".usercode"))) OutData(void)
{

    unsigned int tmp_O_OP_bit,tmp_O_U_W_bit,tmp_O_Y_0_bit;
	
    unsigned int tmpio;
    unsigned int tmpiobuf;

	if(AutoLandingModeChk((unsigned char)YASKAWA_AUTOLANDING)){
		if(bCarUpMove){
	    	if(!IN_LU)	OUT_BK2(1);
	    	else		OUT_BK2(0);
		}
		else if(bCarDnMove){
	    	if(!IN_LD)	OUT_BK2(1);
	    	else		OUT_BK2(0);
		}
		else{
	    	OUT_BK2(0);
		}
	}


    TRISB=0x00ff;

    OUT_ACT1=0;
    OUT_ACT2=0;

    OUT_0=0;
    OUT_1=0;
    OUT_2=0;


    RD_WR=1;
    RD_WR=1;


    tmpio=(LATB & 0x00ff);
    tmpiobuf=(O_U_W_bit << 8);          
    tmpio=(tmpiobuf | tmpio);
    LATB=tmpio;
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////

    OUT_0=1;
    OUT_0=1;
    OUT_0=1;
    OUT_0=1;

    OUT_0=0;
    OUT_0=0;
    OUT_0=0;
    OUT_0=0;

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////


    tmpio=(LATB & 0x00ff);         
    tmpiobuf=(O_OP_bit << 8);          
    tmpio=(tmpiobuf | tmpio);

    LATB=tmpio;

    OUT_1=1;
    OUT_1=1;
    OUT_1=1;
    OUT_1=1;

    OUT_1=0;
    OUT_1=0;
    OUT_1=0;
    OUT_1=0;


    tmpio=(LATB & 0x00ff);         
    tmpiobuf=(O_Y_0_bit << 8);          

    tmpio=(tmpiobuf | tmpio);

    LATB=tmpio;

    OUT_2=1;
    OUT_2=1;
    OUT_2=1;
    OUT_2=1;

    OUT_2=0;
    OUT_2=0;
    OUT_2=0;
    OUT_2=0;

/////////////
    OUT_SEG_SEL0=1;
    OUT_SEG_SEL1=1;                               
    
    SegSel=(SegSel+1) % 3;

    switch(SegSel){
        case    0:
            tmpio=(LATB & 0x00ff);         
            tmpiobuf=(SegData0 << 8);          
            tmpio=(tmpiobuf | tmpio);
            LATB=tmpio;
            OUT_SEG_SEL0=0;
            OUT_SEG_SEL1=0;                               
            break;
        case    1:
            tmpio=(LATB & 0x00ff);         
            tmpiobuf=(SegData1 << 8);          
            tmpio=(tmpiobuf | tmpio);
            LATB=tmpio;
            OUT_SEG_SEL0=1;
            OUT_SEG_SEL1=0;                               
            break;
        case    2:
            tmpio=(LATB & 0x00ff);         
            tmpiobuf=(SegData2 << 8);          
            tmpio=(tmpiobuf | tmpio);
            LATB=tmpio;
            OUT_SEG_SEL0=0;
            OUT_SEG_SEL1=1;                               
            break;
        default:
            break;
    }
    
    OUT_SEG=1;
    OUT_SEG=1;
    OUT_SEG=1;
    OUT_SEG=1;

    OUT_SEG=0;
    OUT_SEG=0;
    OUT_SEG=0;
    OUT_SEG=0;
//////////////////


    OUT_ACT1=0;
    OUT_ACT2=0;

	RD_WR=0;

    TRISB=0xffff;



    tmp_O_OP_bit  		= O_OP_bit;
    tmp_O_U_W_bit 		= O_U_W_bit;
    tmp_O_Y_0_bit 		= O_Y_0_bit;


	if(cF_OP 	!= SILK_OP)		OUT_OP_PORT		=CurSelOutPortChk(cF_OP);
	if(cF_CL 	!= SILK_CL)		OUT_CL_PORT		=CurSelOutPortChk(cF_CL);
	if(cF_OP_S 	!= SILK_OP_S)	OUT_OP_S_PORT	=CurSelOutPortChk(cF_OP_S);
	if(cF_CL_S 	!= SILK_CL_S)	OUT_CL_S_PORT	=CurSelOutPortChk(cF_CL_S);
	if(cF_BK2 	!= SILK_BK2)	OUT_BK2_PORT	=CurSelOutPortChk(cF_BK2);
	if(cF_D_S 	!= SILK_D_S)	OUT_D_S_PORT	=CurSelOutPortChk(cF_D_S);
	if(cF_GBR	!= SILK_GBR)	OUT_GBR_PORT	=CurSelOutPortChk(cF_GBR);
	if(cF_BK1	!= SILK_BK1)	OUT_BK1_PORT	=CurSelOutPortChk(cF_BK1);


	if(cF_UP 	!= SILK_UP)		OUT_U_W_PORT	=CurSelOutPortChk(cF_UP);
	if(cF_DN 	!= SILK_DN)		OUT_D_W_PORT	=CurSelOutPortChk(cF_DN);
	if(cF_P1 	!= SILK_P1)		OUT_P1_PORT		=CurSelOutPortChk(cF_P1);
	if(cF_P2 	!= SILK_P2)		OUT_P2_PORT		=CurSelOutPortChk(cF_P2);
	if(cF_P3 	!= SILK_P3)		OUT_P3_PORT		=CurSelOutPortChk(cF_P3);
	if(cF_P4 	!= SILK_P4)		OUT_P4_PORT		=CurSelOutPortChk(cF_P4);
	if(cF_DAC	!= SILK_DAC)	OUT_DAC_PORT	=CurSelOutPortChk(cF_DAC);


	if(cF_FAN != SILK_FAN)		OUT_FAN_PORT	=CurSelOutPortChk(cF_FAN);
	if(cF_LIT != SILK_LIT)		OUT_LIT_PORT	=CurSelOutPortChk(cF_LIT);
	if(cF_BUZ != SILK_BUZ)		OUT_BUZ_PORT	=CurSelOutPortChk(cF_BUZ);
	if(cF_BELL!= SILK_BELL)		OUT_BELL_PORT	=CurSelOutPortChk(cF_BELL);
	if(cF_RST != SILK_RST)		OUT_RST_PORT	=CurSelOutPortChk(cF_RST);
	if(cF_ERR != SILK_ERR)		OUT_ERR_PORT	=CurSelOutPortChk(cF_ERR);
	if(cF_HOP != SILK_HOP)		OUT_HOP_PORT	=CurSelOutPortChk(cF_HOP);
	if(cF_HCL != SILK_HCL)		OUT_HCL_PORT	=CurSelOutPortChk(cF_HCL);


    sRamDArry[O_OP]  = O_OP_bit;
    sRamDArry[O_U_W] = O_U_W_bit;
    sRamDArry[O_Y_0] = O_Y_0_bit;


    O_OP_bit =tmp_O_OP_bit;
    O_U_W_bit=tmp_O_U_W_bit;
    O_Y_0_bit=tmp_O_Y_0_bit;

}



void __attribute__((section(".usercode")))  UpDnAllOff(void)
{
	bMoveOk=0;
	bMoveUpOk=0;
	bMoveDnOk=0;
}



void __attribute__((section(".usercode")))  ButtonClrCheck(void)
{
    S2_EXT_BUT_CLR1=0;
    S2_CAR_BUT_CLR1=0;


   	if(bExtButClr){   
        S2_EXT_BUT_CLR1=1; 
   	}

   	if(bCarButClr){
		CarKeyClr();   
        S2_CAR_BUT_CLR1=1;
   	}

   	if(bCarUpDnChButClr){    // && (sRamDArry[mDoorSeq] == STOP_ELEVATOR)){
		CarKeyClr();   
        S2_CAR_BUT_CLR1=1;
   	}


   	bExtButClr=0;
 	bCarButClr=0;   
}   


void  __attribute__((section(".usercode")))   UpDnStopCmd(void)
{
    OUT_U_W(0);
    OUT_D_W(0);
    OUT_P1(0);
    OUT_P2(0);
    OUT_P3(0);
    OUT_P4(0);

    OUT_BK2(0);
    OUT_BK1(0);


    sRamDArry[mCarMoveState]=0;

	if(New_Law_SystemChk())	OUT_RST(0);
}


void   __attribute__((section(".usercode"))) CarAllStopCmd(void)
{

	UpDnStopCmd();

    OUT_DAC(0);
    bDac=0;

    bInvOutAllClr=0;	
	bMotorRestartOn=0;
    ManualStopTime=0;


    S2_CAR_MOVE1=0;
    
    S3_UPDN_VO1=0;
    
    ClrUpDnWard();
    
    bMoveCar=0;
    bCarUpMove=0;
    bCarDnMove=0;
   	ElevMoveTime=0;

    bDoorOpenCmd=0;
    bDoorCloseCmd=0;
 
    sRamDArry[mReqStopFloor]=0;      
    sRamDArry[mCarMoveState]=0;


   	bExtButClr=1;
    bCarButClr=1;   
    KeyClr();     

   	OUT_ON=0;
   	OUT_ON=0;
    OutData();
    OutData();
}




void  __attribute__((section(".usercode")))   CarManualStopCmd(void)
{        
    LocalType tmp;     
    unsigned int	tmp_time;

    tmp_time = (ManualStopTime * 100);
    
    tmp=0;

    ZeroSpeedCmd_IO(); 		
    if(tmp_time>iF_Bk1OffTime){
        OUT_BK1(0);                     
        tmp=(tmp | 0x01);
    }

    if(tmp_time>iF_Bk2OffTime){
        OUT_BK2(0);
        tmp=(tmp | 0x02);
    }              

    if(tmp_time>iF_UDOffTime){
        OUT_U_W(0);                                                               
        OUT_D_W(0);                                                        
        tmp=(tmp | 0x04);
    }              

    if(tmp_time>iF_P4OffTime){
        OUT_P4(0);
        tmp=(tmp | 0x08);
    }

    if(tmp == 0x0f){
		ManualStopTime=0;           
        bInvOutAllClr=1;      
    }
}



void   __attribute__((section(".usercode"))) CarAllStopCmdTest(void)
{
    unsigned long i,j;
 
    if(bMotorRestartOn){
        ManualStopTime=0;
        bInvOutAllClr=0;
		bMotorRestartOn=0;
    }           


    bDoorOpenCmd=0;
    bDoorCloseCmd=0;

   	bExtButClr=1;
    bCarButClr=1;   
	ClrUpDnWard();     
    KeyClr();

	bFR2Start1=0;
	S3_UPDN_VO1=0;

     
	ElevMoveTime=0;    

    OUT_DAC(0);
    bDac=0;


	if( !bInvOutAllClr){
	    if(!OilLopeTypeChk || bCarErr || bCarStopNoRun){                                             
			UpDnStopCmd();
			ManualStopTime=0;           
	        bInvOutAllClr=1;
	    }
	    else    CarManualStopCmd();
	}
   
        
    if(bInvOutAllClr){        
		S2_CAR_MOVE1=0;
		bMoveCar=0;
		bCarUpMove=0;
		bCarDnMove=0;
		UpDnStopCmd();

		if(ManualStopTime > 10){		
			bMotorRestartOn=1;

			if(bEqualFloorError)	sRamDArry[mcurfloor] = 0;
		
	      	if(IN_DLS)		            bHomeUpDn = 1;                   
	      	else if(IN_ULS)             bHomeUpDn = 0;
	      	else if(!IN_BAT){												//3.4d
	    		bHomeUpDn = 1;												//3.4d
				if(!IN_X4 && (USE_CHECK == MAN_USE))	bHomeUpDn = 0;		//3.4d			
			}																//3.4d
	      	else if(!IN_LU && IN_LD)    bHomeUpDn = 1;
	      	else if(IN_LU && !IN_LD)    bHomeUpDn = 0;
	
	        else if(!IN_SD1)          bHomeUpDn=0;           
	        else if(!IN_SU1)  		  bHomeUpDn=1;           
	        else if((sRamDArry[mcurfloor] == 0))          bHomeUpDn=0;           
	        else if((sRamDArry[mcurfloor] == cF_TOPFLR))  bHomeUpDn=1;           

	        else if(ManWorkingSeq==3)  					  bHomeUpDn=1;           
			else{
				PositionPulse1=FLOOR_COUNT(0);
		      	if(CurPulse <= PositionPulse1){
		            bHomeUpDn = 1;    
		        }
		      	else{
					PositionPulse1=FLOOR_COUNT(cF_TOPFLR);
	 				if(CurPulse >= PositionPulse1){
		            	bHomeUpDn = 0;
					}
					else{
						PositionPulse1=FLOOR_COUNT(sRamDArry[mcurfloor]);
		      			if(CurPulse <= PositionPulse1)	bHomeUpDn = 1;
						else							bHomeUpDn = 0;		
					}				   
		        }
			}
		}

	}       
}



void   __attribute__((section(".usercode")))  MotorStop(void)
{
    if(!bMoveCar){
		bZeroHzSet=0;
    	OUT_DAC(0);
        if(!bCarOnceStop){
            CarOnceStopTime=0;
            bCarOnceStop=1;
        }

		DaesungAutoLandingModeChk((unsigned char)DS_AUTOLANDING);		
    }                
    else{
        bCarOnceStop=0;
    }
}


UserDataType	__attribute__((section(".usercode"))) NextUpDnKeyChk(unsigned int UpDn)
{
	UserDataType	i,j,k,bitvar,Fstartflr,Flastflr,ret;
	UserDataType	tmpCarkey[8];

	ret=1;
	CarBdButtonFlr=0;


	k=(UserDataType)(sRamDArry[mcurfloor]);
    k=(k & 0x00ff);

//	if(k < 1)					return(1);
//	if(k >= cF_TOPFLR)			return(1); 


	tmpCarkey[0]=(sRamDArry[mCarKey1]  & sRamDArry[FLR_ON_OFF0]);
	tmpCarkey[1]=(sRamDArry[mCarKey9]  & sRamDArry[FLR_ON_OFF1]);
	tmpCarkey[2]=(sRamDArry[mCarKey17] & sRamDArry[FLR_ON_OFF2]);
	tmpCarkey[3]=(sRamDArry[mCarKey25] & sRamDArry[FLR_ON_OFF3]);

#ifdef	 FLOOR_64
	tmpCarkey[4]=(sRamDArry[mCarKey33] & sRamDArry[FLR_ON_OFF4]);
	tmpCarkey[5]=(sRamDArry[mCarKey41] & sRamDArry[FLR_ON_OFF5]);
	tmpCarkey[6]=(sRamDArry[mCarKey49] & sRamDArry[FLR_ON_OFF6]);
	tmpCarkey[7]=(sRamDArry[mCarKey57] & sRamDArry[FLR_ON_OFF7]);
#endif	

	j=0;


    bitvar=0x01;    

   	if(UpDn){
		if(k >= cF_TOPFLR)			return(1);
		else{ 
			Fstartflr = (k+1);
			Flastflr  = cF_TOPFLR;
	
			i = (Fstartflr / 8);
			j = (j + i);
	
			i = (Fstartflr % 8);
	   	 	bitvar=(bitvar << i);    
		}
	}
	else{
		if(k < 1)		return(1);
		else{
			Fstartflr=0;
			Flastflr=(k-1);
		}		
	}


    for( ; Fstartflr <= Flastflr;Fstartflr++){
		if(tmpCarkey[j] & bitvar){
//////////////////			CarBdButtonFlr=(Fstartflr | CAR_READY);
			ret=0;
   			if(UpDn==0)	return(ret);
        }
        bitvar=(bitvar << 1);
        bitvar=(bitvar & 0x00ff);

        if(bitvar==0x0){
            bitvar=0x01;
            j++;
        }
    }

    return(ret);
}




UserDataType  __attribute__((section(".usercode"))) TopDirectionSet(void)
{			
	bCarUpDnChButClr=1;
	DnWard();
	if( !(sRamDArry[mAckStopFloor] & DN_READY))	sRamDArry[DEST_FLR] = (sRamDArry[DEST_FLR]	& ~DN_READY);	
	sRamDArry[mAckStopFloor]=(sRamDArry[mcurfloor] | DN_READY);	
}


UserDataType  __attribute__((section(".usercode"))) LowDirectionSet(void)
{			
	bCarUpDnChButClr=1;
	UpWard();
	if( !(sRamDArry[mAckStopFloor] & UP_READY))	sRamDArry[DEST_FLR] = (sRamDArry[DEST_FLR]	& ~UP_READY);	
	sRamDArry[mAckStopFloor]=(sRamDArry[mcurfloor] | UP_READY);	
}




unsigned int  __attribute__((section(".usercode"))) EncoderClear(void)
{	
	CounterTime=0;
	CountDn=0;
	CountUp=0;
	return(0);
}



unsigned int  __attribute__((section(".usercode"))) CounterCheck(void)
{
//    if((INVERTER_CHECK == IO) && (bitChk_FLRDSPCH(F_OnOff1,(bEncoderUse % 8))) ){
//    if((INVERTER_CHECK == IO) && (EncoderUseChk) ){

	if( !EncoderUseChk)	    return(1);    

    if( (!bMoveCar || bCarErr || bUnd) || S1_POWER_FAIL || (IN_AUTO && !bFhmRun)){
		EncoderClear();
	}

    if(INVERTER_CHECK == IO){
        if(bFhmRun)             CounterChkTime=30;
        else if(!bManualAuto)   CounterChkTime=30;
        else                    CounterChkTime=10;

        if((bAuto || bFhmRun) && bMoveCar && (CounterTime > CounterChkTime)){
			UpDnAllOff();
            bCarErr=1;
            bEncoderErr=1;
        }

        if((bAuto || bFhmRun) && bMoveCar && bCarUpMove && (CountDn> 200)){
			UpDnAllOff();
            bCarErr=1;
            bEncoderABErr=1;
        }

        if((bAuto || bFhmRun) && bMoveCar && bCarDnMove && (CountUp> 200)){
			UpDnAllOff();
            bCarErr=1;
            bEncoderABErr=1;
        }

        if(bEncoderErr || bEncoderABErr){
            return(0);
        }

    }
    return(1);    
}







void  __attribute__((section(".usercode"))) LightOnOff(void)
{    
    OUT_LIT(1);
	if(bReadyCall){
	    if(S3_PARKING1 && (FanTime > 2))                OUT_LIT(0);
	    if(S1_POWER_FAIL && bDoorCloseOk)               OUT_LIT(0);
	    if((LightTime >= cF_LIGHTTIME))                 OUT_LIT(0);
		if(bWaterAndArrive)								OUT_LIT(0);     
	}
}



unsigned int __attribute__((section(".usercode")))  ThisFloorDoorCheck(void)
{   	
	OneDoorSelOpenKeyCheck();
	if(CurDoorSelect == SUB_DOOR)	OUT_D_S(1);
	else							OUT_D_S(0);
	return(0);
}


void  __attribute__((section(".usercode"))) EmergencyCheck(void)
{
	unsigned int i;
	i=0;

	if(bsEmergency || bsLope || bsSlip || bSlip_Occur || bLope_Occur)		i=1;
	if(New_Law_SystemChk() && bsInvertErr)	i=1;

	if(i){
        OUT_U_W(0);
        OUT_D_W(0);
        OUT_P1(0);
        OUT_P2(0);
        OUT_P3(0);
        OUT_P4(0);
        OUT_DAC(0);
        OUT_OP(0);
        OUT_CL(0);
        OUT_OP_S(0);
        OUT_CL_S(0); 
        OUT_BK2(0);
        OUT_D_S(0);
        OUT_GBR(0);
        OUT_BK1(0);
        OUT_FAN(1);
        OUT_LIT(1); 
        OUT_BELL(0);
        OUT_RST(0);
        OUT_HOP(0);
        OUT_HCL(0);
 	
        bCarErr=1;        
   		ElevMoveTime=0;
		ClrUpDnWard();				
	}


    if(bsSlip || bSlip_Occur)			OUT_GBR(1);
    else if(bsLope || bLope_Occur)		OUT_GBR(1);
    else                				OUT_GBR(0);



    if(bCarErr ||  bCarStopNoRun || (DoorOpenEndWaitChk()) ){
        OUT_ERR(1);
	}
       


    if(bOnLuLd && !bsEmergency && !bMoveCar && bCarStopNoRun && !IN_AUTO){
		if(ElevStopTime > 10){
			ThisFloorDoorCheck();
			if(ElevStopTime > 20){
		        bDoorOpenCmd=1;
		    	DoorOpenClose_you();
			}
		}
	}



	if(S2_FIRE1){
        OUT_FAN(0);
	}
}





unsigned int __attribute__((section(".usercode")))  OneDoorSenserNoCloseChk(void)
{

    if(!bHoleDoorCloseEnd)         return(1);
    else if(!bCarDoorCloseEnd)     return(1);
    else                           return(0);

}


unsigned int __attribute__((section(".usercode")))  OneDoorSenserCloseChk(void)
{

	DoorJumperNm=0;

    if(CarDoor1UseChk){
        if(CarDoorCloseEndCheckForDoorjmp())        DoorJumperNm= 1;
//return(1);
    }


    if(HoleDoor1UseChk){
        if(HoleDoorCloseEndCheckForDoorjmp())      DoorJumperNm=(DoorJumperNm | 2);
//return(1);
    }

    return(DoorJumperNm);
}




#ifdef	FIX_FLOOR

unsigned char FixCallFlr=0x0;

unsigned int	__attribute__((section(".usercode")))	TmpFixFloorChk(void)
{
	unsigned int flr1,flr2;

	if(!IN_X3 && !IN_AUTO && AutoRunReady()){
		if( (cF_X6SAFEFLR <= cF_TOPFLR) && (cF_X5SAFEFLR <= cF_TOPFLR)){
			flr1=0x01;
 			flr1=(flr1 << cF_X6SAFEFLR);

			flr2=0x01;
 			flr2=(flr2 << cF_X5SAFEFLR);
			
			flr1=(flr1 | flr2);

			BaggageFlrOnOff[0]=flr1;
			BaggageFlrOnOff[1]=0xff;
			BaggageFlrOnOff[2]=0xff;
			BaggageFlrOnOff[3]=0xff;

			flr1=(sRamDArry[mEqualFloor]);
			if(flr1 & UPDN_READY){
				FixCallFlr=flr1;				
			} 				
		}
	    else{
			BaggageFlrOnOff[0]=0xff;
			BaggageFlrOnOff[1]=0xff;
			BaggageFlrOnOff[2]=0xff;
			BaggageFlrOnOff[3]=0xff;
			FixCallFlr=0;				
		}				
	}
	else{
		BaggageFlrOnOff[0]=0xff;
		BaggageFlrOnOff[1]=0xff;
		BaggageFlrOnOff[2]=0xff;
		BaggageFlrOnOff[3]=0xff;
		FixCallFlr=0;				
	}

	if(FixCallFlr & UPDN_READY){
		if( (sRamDArry[mDoorSeq] >= DOOR_OPEN_WAIT) && (sRamDArry[mDoorSeq] <= READY_ELEVATOR) ){
			flr1=(FixCallFlr & ONLY_FLR);
			if(cF_X6SAFEFLR != flr1){
				Virtual_Floor_Set(cF_X6SAFEFLR);
			}
			else{
				Virtual_Floor_Set(cF_X5SAFEFLR);
			}


			FixfloorSetThisDoor=0;
	    	if(CurDoorSelect == SUB_DOOR){
				FixfloorSetThisDoor=1;
			}			
		}
	}			

}
#endif



unsigned int __attribute__((section(".usercode")))  OnlyOneCallChk(void)
{
	UserDataType	i,j,k,ext_clr_chk;


    BaggageFlrOnOff[0]     = 0xff;
    BaggageFlrOnOff[1]     = 0xff;
    BaggageFlrOnOff[2]     = 0xff;
    BaggageFlrOnOff[3]     = 0xff;
#ifdef	FLOOR_64
    BaggageFlrOnOff[4]     = 0xff;
    BaggageFlrOnOff[5]     = 0xff;
    BaggageFlrOnOff[6]     = 0xff;
    BaggageFlrOnOff[7]     = 0xff;
#endif

	#ifdef	FIX_FLOOR
		TmpFixFloorChk();	
	#endif


    ext_clr_chk=0;
            

    if(AutoRunReady()){
        if(OnlyOneCallOnOffChk){            
            if((sRamDArry[mDoorSeq] != READY_ELEVATOR) || (sRamDArry[mHighFloor] > 0) || (sRamDArry[mLowFloor] > 0)){
                ext_clr_chk=1;
            }

            if(sRamDArry[mDoorSeq] > READY_ELEVATOR){                
                BaggageFlrOnOff[0]     = 0x0;
                BaggageFlrOnOff[1]     = 0x0;
                BaggageFlrOnOff[2]     = 0x0;
                BaggageFlrOnOff[3]     = 0x0;
            
			#ifdef	FLOOR_64
			    BaggageFlrOnOff[4]     = 0x0;
			    BaggageFlrOnOff[5]     = 0x0;
			    BaggageFlrOnOff[6]     = 0x0;
			    BaggageFlrOnOff[7]     = 0x0;
			#endif

                i=(sRamDArry[DEST_FLR] & ONLY_FLR);
                j=(i / 8);
                k=(i % 8);
                i=(0x01 << k);

				#ifdef	FLOOR_64          		
				if(j < 8){
            		BaggageFlrOnOff[j] = i;
				}
				#else
				if(j < 4){
            		BaggageFlrOnOff[j] = i;
				}
				#endif  
            }
        }
    }

    if(ext_clr_chk) bHibCallClear=1;
    else            bHibCallClear=0;
}



unsigned int __attribute__((section(".usercode")))  SafetyChk(void)
{

	unsigned int    i,j;
	unsigned int    subsafetyOnOff;
	

    i=0;

	bSafety_scrSft=0;

	if(IN_AUTO)		return(0);

    if(USE_CHECK == MAN_USE){
		if( bMoveCar)	return(0);
	}

	

	if(Old_Law_SystemChk()){	
		if(bFirstFire){
			return(0);
		} 
	}
       
    if(S3_PARKING1){
  		return(0);       
	}


	if(IN_SFT){
		bSafety_scrSft=1;
	}

	
    if(INVERTER_CHECK != LG){
		if(!S2_FIRE1){	                   
    		if(IN_FS1)	bSafety_scrSft=1;
		}                           		
	}



	subsafetyOnOff=0;

	if(Old_Law_SystemChk()){	
		if(IN_FULL)		subsafetyOnOff=1;
	}
	else{
    	if(INVERTER_CHECK != LG){
    		if(IN_DER) 		subsafetyOnOff=1;
		}
	}


    if((SubSafetyUseChk)){
        if(USE_CHECK == CARLIFT_USE){
            if(bSafety_scrSft)                              i=1;
            else if(subsafetyOnOff)							i=1;
        }
        else{
            if(!bMoveCar){
    	        j=MainSubDoorFlrChk(sRamDArry[mcurfloor]);
                if(j==0)                                    i=0;
                else if(j==1){
                    if(bSafety_scrSft)                      i=1;
                }
                else if(j==2){
                    if(subsafetyOnOff)                      i=1;
                }
                else{
                    if(OneDoorSenserNoCloseChk()){
                        if(CurDoorSelect == MAIN_DOOR){
                            if(bSafety_scrSft || (SafetyValidLR && subsafetyOnOff)){
                            	sRamDArry[mDoor] = (sRamDArry[mDoor] | MAIN_OPEN_KEY);
                      			i=1;
							}			                            
                        }
                        else if(CurDoorSelect == SUB_DOOR){
                            if(subsafetyOnOff || (SafetyValidLR && bSafety_scrSft)){
                            	sRamDArry[mDoor] = (sRamDArry[mDoor] | SUB_OPEN_KEY);
                      			i=1;
							}			                            
                        }
                    }
                    else{
                        if(bSafety_scrSft){
                            sRamDArry[mDoor] = (sRamDArry[mDoor] | MAIN_OPEN_KEY);
                            i=1;
                        }
                        else if(subsafetyOnOff){
                            sRamDArry[mDoor] = (sRamDArry[mDoor] | SUB_OPEN_KEY);
                            i=1;
                        }
                    }                    
                }                        
            }
        }
    }
    else{
        if(bSafety_scrSft)                             						i=1;
    }        


	if(i==1)	bSafety_scrSft=1;						// sub safety on

    return(i);
}





unsigned int  __attribute__((section(".usercode")))  SaftyStopChk(void)
{
	UserDataType	safty_stop_chk;

    safty_stop_chk=0;

	if(bAuto){
//	    if(!CarDoor1UseChk && !CarDoor2UseChk)  safty_stop_chk=1;

	    if(!CarDoor1UseChk )  					safty_stop_chk=1;
	    if(USE_CHECK == CARLIFT_USE)            safty_stop_chk=1;    
	}  

    if(safty_stop_chk){
        if(SafetyChk() && !bLevelFind){
			UpDnAllOff();
            if(bMoveCar){
        		bCarErr=1;  				         		            
            }
        }    
    }
    return(0);
}



unsigned int  __attribute__((section(".usercode"))) FHMDlsUlsCancleCheck(unsigned int ulsdls)   
{
	if(!bFhmRun)																	return(0);
	if( !(!bAuto && IN_AUTO && !ManWorkingChk))										return(0);
	if( sRamDArry[FHM_SEQ] >= FHM_SEQ_4)												return(0);
	if( FhmLoaderTime > 10)															return(0);

	if(ulsdls==1){  	// uls
		if(IN_SU1)																	return(0);													
		if(IN_LU && IN_LD)															return(0);													
	}
	else if(ulsdls==2){	// dls
		if(IN_SD1)																	return(0);													
		if(IN_LU && IN_LD)															return(0);													
	}
	else																			return(0);	

	return(1);
}



unsigned int  __attribute__((section(".usercode"))) SensorPositionRead(void)   
{
	unsigned long tmp_mmpulse,tmp_pulse,tmp_base_pulse;
	unsigned int  sensor_type;
	
	if(bCarUpMove){		
		tmp_base_pulse=FLOOR_COUNT(cF_TOPFLR);

		if( IN_ULS){
			sensor_type=REAL_ULS_POSITION;				
		}
		else if( !IN_SU1){
			sensor_type=REAL_SUS_POSITION;	
		}
		else if( !IN_SU2){
			sensor_type=REAL_SUS1_POSITION;	
		}
		else if( !IN_X0){
			sensor_type=REAL_X0_POSITION;	
		}
		else{
			sensor_type=0xff;
			Befsensor_type=sensor_type;
		}
	}
	else if(bCarDnMove){			
		tmp_base_pulse=FLOOR_COUNT(0);
		if( IN_DLS){
			sensor_type=REAL_DLS_POSITION;	
		}
		else if( !IN_SD1){
			sensor_type=REAL_SDS_POSITION;	
		}
		else if( !IN_SD2){
			sensor_type=REAL_SDS2_POSITION;	
		}
		else if( !IN_X1){
			sensor_type=REAL_X1_POSITION;	
		}
		else{
			sensor_type=0xff;
			Befsensor_type=sensor_type;
		}
	}
	else{
		sensor_type=0xff;
		Befsensor_type=sensor_type;
	}


	if( (sensor_type < POSITION_END) && (Befsensor_type != sensor_type)){
		Befsensor_type = sensor_type;
		tmp_pulse=CurPulse;
		
		if(tmp_base_pulse > tmp_pulse)	tmp_pulse=(tmp_base_pulse - tmp_pulse);
		else							tmp_pulse=(tmp_pulse      - tmp_base_pulse);


		tmp_mmpulse=(GET_LONG((unsigned long)MM_PULSE));

		if((tmp_pulse>0) && (tmp_mmpulse>0)){
			SensorPositionBuf[sensor_type]	=(unsigned int)(tmp_pulse/tmp_mmpulse);	
		}	
	}

	return(0);	
}




void  __attribute__((section(".usercode"))) EmgDlsUlsCheck(void)   
{

	if(IN_EMG){
		bExtButClr=1;
		bCarButClr=1;
		UpDnAllOff();
		S1_EMG1=1; 
		bsEmergency=1;
		bCarErr=1;  				         		
	}
	else{
		bMoveOk=1;
		bMoveUpOk=1;
		bMoveDnOk=1;
		bsEmergency=0;
        S1_EMG1=0; 
	}         



	if(IN_ULS && (FHMDlsUlsCancleCheck(1)==0)){
		if(bCarUpMove || bUpWard){
			bCarErr=1;  
		    bExtButClr=1;
		    bCarButClr=1;

        	bsUls=1;
    		bMoveUpOk=0;
        }
    	else{            
            if(bsUls){
                if(bMotorRestartOn)   	bsUls=0;          
            }
            else                   		bsUls=0;          
        }
	}
	else    bsUls=0;          
	
            
	if(IN_DLS && (FHMDlsUlsCancleCheck(2)==0)){
		if(bCarDnMove || bDnWard){
			bCarErr=1;   
    		bExtButClr=1;
	    	bCarButClr=1;
            bsDls=1;    
    		bMoveDnOk=0;
        }
    	else{
            if(bsDls){
                if(bMotorRestartOn)   	bsDls=0;          
            }          
            else                   		bsDls=0;          
        }
	}                        
	else  bsDls=0;



	if(!bMoveUpOk && bUpWard){
		bCarErr=1;  
	}     
   
	if( !bMoveDnOk && bCarDnMove){
         bCarErr=1;   
   	}           
}




/*
void    SDSSUSChk(void)
{
    if(!IN_SD1 && bAuto && (CurPulse >= UP_DEC_COUNT(UP_FLR_0102_PULSE)) ){
   		bMoveOk=0;
		bMoveUpOk=0;
		bMoveDnOk=0;
        bCarErr=1;   
    }    

    if(!IN_SU1 && bAuto && ((CurPulse + 1000) <= UP_DEC_COUNT(cF_TOPFLR-1))  ){
   		bMoveOk=0;
		bMoveUpOk=0;
		bMoveDnOk=0;
        bCarErr=1;   
    }
}         
*/




unsigned int __attribute__((section(".usercode")))  RunningOpenCheck(void)
{   	

#ifdef  TEST_SIMULATION                  
	return(0);
#else
	if( !RunningOpenOnOff)																	return(0);	
	if((USE_CHECK != MAN_USE) )																return(0);
 	if(!bAuto || !bDac || !bUnd || !bOnLuLd)												return(0);
	if((sRamDArry[mcurfloor] & ONLY_FLR) != (sRamDArry[mAckStopFloor] & ONLY_FLR))			return(0);
	if(bSolControl)																			return(0);
	if( !NoUseNoOpen())																		return(0);	
	if( !bRunningOpenOn){
	    if(S2_FIRE1)																		return(0);
	    if(S1_POWER_FAIL)																	return(0);
	}

	return(1);
#endif 
}



unsigned int __attribute__((section(".usercode")))  RunningOpenAction(void)
{   	

	if(S2_FIRE1 || bWaterSensing){
		bRunningOpenOn=0;
		return(0);
	}

	if(RunningOpenCheck()){
		ThisFloorDoorCheck();
		SelectDoorOpen_you();    		
		bRunningOpenOn=1;
		return(1);
	}
	else{
		bRunningOpenOn=0;
		return(0);
	} 
}



unsigned int  __attribute__((section(".usercode")))  DoorCloseOkCheck(void)
{   	

    if( !CarDoor1UseChk && !HoleDoor1UseChk){
		UpDnAllOff();
        bCarErr=1;   
		return(0);
    }




	if(bLevelFind || bRunningOpenOn){
		bDoorCloseOk=1;
		return(0);
	}




	DoorCloseEndCheck((UserDataType)bMoveCar);

   	if(!bDoorCloseOk){
		UpDnAllOff();
      	if(bMoveCar){
        	bCarErr=1;   
      	}
		if(!bsEmergency)    S1_EMG1=0;
   	}

	return(0);

}

unsigned int  __attribute__((section(".usercode")))  RunningOpenValidChk(void)
{   	
	if(!AutoRunReady()){
		if( !bMoveCar)	bRunningOpenOn=0;
	}
	else{
		if( !bManualAuto)	bRunningOpenOn=0;
    	if(sRamDArry[mDoorSeq] < WAIT_NEXT_LULD){
    		if(sRamDArry[mDoorSeq] > DOOR_OPEN_START){
				bRunningOpenOn=0;	
			}
		}
	}

	return(0);
}	




void __attribute__((section(".usercode")))  LuLdErrSave(unsigned int updn)
{         
	UserDataType	i,j,err;

	err=0;

	bsLuOrLdErr=1;
	LuLdErrNm=6;
	

	j=LuLdSeq[3];
	j= (j +1) % 4;
	if(LuLdSeq[2] == j){
		j= (j +1) % 4;
		if(LuLdSeq[1] == j){
			j= (j +1) % 4;
			if(LuLdSeq[0] == j){
				LuLdErrNm=1;
				err=1;
			}		
		}
	}


	if(err==0){		
		if(updn){
			if((LuLdSeq[0] == LuLdSeq[2]) && (LuLdSeq[1] == LuLdSeq[3])){
				if( (LuLdSeq[0] + LuLdSeq[1]) == 1)					LuLdErrNm=2;		//LD ON	
				if( (LuLdSeq[0] + LuLdSeq[1]) == 5)					LuLdErrNm=3;		//LD OFF	
				if( (LuLdSeq[0] + LuLdSeq[1]) == 3){
					if( (LuLdSeq[0] == 0) || (LuLdSeq[0] == 3))		LuLdErrNm=4;		//LU ON	
					if( (LuLdSeq[0] == 1) || (LuLdSeq[0] == 2))		LuLdErrNm=5;		//LU OFF	
				}
			}
		}
		else{
			if((LuLdSeq[0] == LuLdSeq[2]) && (LuLdSeq[1] == LuLdSeq[3])){
				if( (LuLdSeq[0] + LuLdSeq[1]) == 1)					LuLdErrNm=4;		//LU ON	
				if( (LuLdSeq[0] + LuLdSeq[1]) == 5)					LuLdErrNm=5;		//LU OFF	
				if( (LuLdSeq[0] + LuLdSeq[1]) == 3){
					if( (LuLdSeq[0] == 0) || (LuLdSeq[0] == 3))		LuLdErrNm=2;		//LD ON	
					if( (LuLdSeq[0] == 1) || (LuLdSeq[0] == 2))		LuLdErrNm=3;		//LD OFF	
				}
			}
		}
	}

	UpDnAllOff();           
}



void __attribute__((section(".usercode")))  LuLdOnCheck(void)
{         
	UserDataType	err,befStat,curStat;
	 
	err=0;

	befStat=lu_ld_state;

    if(!IN_LU && !IN_LD){
		if(!bOnLuLd){
			LuLdEncoder=CurPulse;			
		}

		bFirstOnLuLd=1;
        bOnLuLd=1;
		lu_ld_state=0;
    }      
    else{
        bOnLuLd=0;         
	    if(IN_LU && IN_LD){
	        LuLdTime=0;
			bFirstOnLuLd=0;
			lu_ld_state=2;
			bOnceOpen=0;
		}
/////////////////////////////////////////////////
	    else if(IN_LU && !IN_LD){
			if(bCarDnMove){
				lu_ld_state=3;
			}
			else	lu_ld_state=1;
		}
		else{
//	    else if( !IN_LU && IN_LD){
			if(bCarDnMove){
				lu_ld_state=1;
			}
			else	lu_ld_state=3;
		}
	}


	curStat=lu_ld_state;
	if(befStat != curStat){
		if(!PerfectAuto() || (sRamDArry[mDoorSeq]!= MOVE_ELEVATOR)){
			NextFloorTime=0;
		}
	}



    if(!IN_LU || !IN_LD)	bOneLuOrLd=1;
    else					bOneLuOrLd=0;




#ifndef  TEST_SIMULATION  
//	if(bFhmRun || (bAuto && !bManualAuto)){
	if(bFhmRun){
		if(bMoveCar){	
			if( (lu_ld_state != LuLdSeq[LuLdSeqPt]) && (lu_ld_state <= 3) ){
				bef_lu_ld_state=LuLdSeq[LuLdSeqPt];
			
				LuLdSeqPt=(LuLdSeqPt + 1) % 4;
				LuLdSeq[LuLdSeqPt]=lu_ld_state;
				LuLdSeqMinCnt++;
				if(LuLdSeqMinCnt >= 4){
					bef_lu_ld_state=(bef_lu_ld_state + 1) % 4;	
					if(lu_ld_state != bef_lu_ld_state)	err=1;	
					LuLdSeqMinCnt=5;
				}
			}
				
			if(err){
				if(bCarUpMove)		LuLdErrSave(1);
				else				LuLdErrSave(0);	
			}
		}
		else{
			LuLdSeqMinCnt=0;
			LuLdSeqPt=0;
			LuLdSeq[LuLdSeqPt]=lu_ld_state;
			bef_lu_ld_state=lu_ld_state;

//			LuLdSeqMinCnt=0;
//			LuLdSeqPt=0;
//			LuLdSeq[LuLdSeqPt]=lu_ld_state;
		}
	}
	else{
		bsLuOrLdErr=0;
		LuLdSeqMinCnt=0;
		LuLdSeqPt=0;
		LuLdErrNm=0;	
		LuLdSeq[LuLdSeqPt]=lu_ld_state;
	}

#else
	LuLdErrNm=0;	
	bsLuOrLdErr=0;
//	bLuOrLdErr=0;
	LuLdSeqMinCnt=0;
	LuLdSeqPt=0;
#endif

}       





void __attribute__((section(".usercode")))  OverLoadCheck(void)
{
    if(IN_OVL && !bMoveCar && (!IN_LU || !IN_LD) && !bDoorCloseOk && bAuto && !bFirstFire){      
        S1_OVERLOAD1=1;    
		UpDnAllOff();

		if(sRamDArry[mDoorSeq] >= DOOR_OPEN_WAIT){
			sRamDArry[mDoorSeq]=DOOR_OPEN_START;      
			DoorOpenTime=0;                 
		}			
    }
    else{
        S1_OVERLOAD1=0;         
    }
}


/*
unsigned int    __attribute__((section(".usercode")))   AutoParkingCheck(void)
{    

    LocalType tmphour;

    tmphour=(sRamDArry[Hour] >> 4);
    tmphour=(tmphour * 10);
    tmphour=((sRamDArry[Hour] & 0x000f) + tmphour);

    if(cF_ParkingStart < cF_ParkingEnd){
        if((cF_ParkingStart <= tmphour) && (cF_ParkingEnd > tmphour))   return(1);
    }
    else if(cF_ParkingStart > cF_ParkingEnd){
        if(cF_ParkingStart <= tmphour)                                  return(1);
        else if(cF_ParkingEnd > tmphour)                                return(1);
    }

    return(0);
}
*/


unsigned int    __attribute__((section(".usercode"))) ParkingValidCheck(void)
{

	S4_PARKING_READY1=bExt_PRKING;

//	if(IN_PRK || bPC_PRK || bSlavePrk){
	if(IN_PRK || S4_PARKING_READY1 || bSlavePrk){

		return(1);
/*		
        if(cF_ParkingStart == cF_ParkingEnd)    return(1);        
        else{
            if(AutoParkingCheck())              return(1);
            else                                return(0);
        }
*/
    }
    else    return(0);
}



void  __attribute__((section(".usercode"))) ParkingCheck(void)
{

	if(S3_PARKING1 && (ParkingValidCheck()) && !S2_FIRE1 && (!IN_LU || !IN_LD) ){      
            
        if(!bDoorCloseOk){
			UpDnAllOff();
        }
     
    	bExtButClr=1;
    	bCarButClr=1;
    	KeyClr();     

    	bTestKey=0;


   		sRamDArry[mEqualFloor] = 0;
   		sRamDArry[mHighFloor] = 0;
   		sRamDArry[mLowFloor] = 0;

		#ifdef	FLOOR_64
	    sRamDArry[mCurCarkey]  =0x0;
//////	    sRamDArry[mMostCarkey] =0x0;
		sRamDArry[mMostLongDst]=0x0;
		#endif

	                        
   		if(!OpenKeyCheck()){
       		sRamDArry[mDoorSeq] = DOOR_OPEN_START;      		         
            S3_PARKING1=0;
   		}

  	}
//  	else if((ParkingValidCheck() || bPC_PRK) && bAuto && !S2_FIRE1 && (!IN_LU || !IN_LD) ){
  	else if((ParkingValidCheck()) && bAuto && !S2_FIRE1 && (!IN_LU || !IN_LD) ){
   		if(sRamDArry[mcurfloor]== cF_PRKFLR){
       		if((sRamDArry[mDoorSeq] >= DOOR_CLOSE_END) && bDoorCloseOk && (sRamDArry[mDoorSeq] <= READY_ELEVATOR)){
                S3_PARKING1=1;   
	    		OpenKeyCheck();
       		}                     
   		}
   		else if(!ReadyAndNoKeyCheck()){
   			Virtual_Floor_Set(cF_PRKFLR);
		}
  	}
  	else{
   		if(S3_PARKING1){
			sRamDArry[mDoor]    = (sRamDArry[mDoor] & MAIN_SUB_OPEN_KEY_CLEAR);   
			if(bSubSlavePrk)	sRamDArry[mDoor]=( sRamDArry[mDoor] | SUB_OPEN_KEY);                            
			else				sRamDArry[mDoor]=( sRamDArry[mDoor] | MAIN_OPEN_KEY);                            
       		sRamDArry[mDoorSeq] = DOOR_OPEN_START;      		             
   		}    		
   		S3_PARKING1=0;
		bSubSlavePrk=0;
  	}
}



void  __attribute__((section(".usercode"))) MyFamilyServiceCheck(void)
{      

	S4_FAMILY_SERVICE1=0;
	if( (bExt_FAMILY || FamilyService) && !S2_FIRE1){
		S4_FAMILY_SERVICE1=1;
	}

	S4_WAIT_FLR_SERVICE1=0;
	if( (cF_FIXFLOORTIME > 0) || (CmdFixFlrTime > 0)){
		S4_WAIT_FLR_SERVICE1=1;
	}
}




void __attribute__((section(".usercode")))  VipCheck(void)
{

    if( (!IN_PASS || bOnceVip || bExt_VIP) && AutoRunReady()){
        S3_VIP1=1;
        bExtButClr=1;

        if((sRamDArry[mDoorSeq] == READY_ELEVATOR) && (sRamDArry[mNewAckStopFloor]==0) ){
            sRamDArry[mDoorSeq] = DOOR_OPEN_START;    
        }                  
    }
    else{   
        S3_VIP1=0;
        bOnceVip=0;
        Vip_Floor=0;
    }    
    
    if(bOnceVip){
        if(((Vip_Floor & ONLY_FLR) != sRamDArry[mcurfloor]) &&  !bMoveCar){
            bOnceVip=0;
            Vip_Floor=0;
        }  
    }
        
}



void __attribute__((section(".usercode")))  FullCheck(void)
{
	unsigned int full_use_chk;
	
	full_use_chk=1;

	if(Old_Law_SystemChk()){
		if(SubSafetyUseChk)	full_use_chk=0;			
	}
	

	if(full_use_chk){
		if(!AutoRunReady())	S3_FULL1=0;
		else{
			if(!bDoorCloseOk || !bMoveCar){
		        if(!IN_FULL){
		            S3_FULL1=1;
					#ifdef	FLOOR_64
		            if((sRamDArry[mHighFloor] & UPDN_READY))	sRamDArry[mHighFloor]=0;
		            if((sRamDArry[mLowFloor]  & UPDN_READY))	sRamDArry[mLowFloor]=0;
				
	
					#else
		            if( !(sRamDArry[mHighFloor] & CAR_READY))	sRamDArry[mHighFloor]=0;
		            if( !(sRamDArry[mLowFloor]  & CAR_READY))	sRamDArry[mLowFloor]=0;
					#endif
		        }
		        else{   
		            S3_FULL1=0;
		        }
			}
		}
	}
    else	S3_FULL1=0;

/*
    if(!SubSafetyUseChk){
		if(!AutoRunReady())	S3_FULL1=0;
		else{
			if(!bDoorCloseOk || !bMoveCar){
		        if(!IN_FULL){
		            S3_FULL1=1;
					#ifdef	FLOOR_64
		            if((sRamDArry[mHighFloor] & UPDN_READY))	sRamDArry[mHighFloor]=0;
		            if((sRamDArry[mLowFloor]  & UPDN_READY))	sRamDArry[mLowFloor]=0;
				

					#else
		            if( !(sRamDArry[mHighFloor] & CAR_READY))	sRamDArry[mHighFloor]=0;
		            if( !(sRamDArry[mLowFloor]  & CAR_READY))	sRamDArry[mLowFloor]=0;
					#endif
		        }
		        else{   
		            S3_FULL1=0;
		        }
			}
		}
    }
    else	S3_FULL1=0;
*/
}



void __attribute__((section(".usercode")))  DoorOpenAndHoldCheck(void)
{
	unsigned int door_stop;

	if(!AutoRunReady())	bDoorOpenHold=0;
	else{
		if(bDoorCloseOk || bMoveCar){
			bDoorOpenHold=0;
		}
		else{
			door_stop=0;
			if(cF_TOPFLR < 31){
				if(sRamDArry[mDoor] & 0x10){
					sRamDArry[mDoor]=(sRamDArry[mDoor] & 0xef);
					door_stop=1;
				}
			}

			if( !IN_DOOR_HOLD || (door_stop==1)){
				if(cF_REOPTM > 0){
					bDoorOpenHold=1;
					DoorOpenTime=0;
					if(sRamDArry[mDoorSeq] >= DOOR_REOPEN_CHECK){
	               		sRamDArry[mDoorSeq]=DOOR_OPEN_START;
					}
				}
			}
		}			
    }
}



/*
UserDataType __attribute__((section(".usercode")))  SubDoorTimer(void)
{
    if(IN_X7)	return(1);
	else		return(0);
}
*/


UserDataType __attribute__((section(".usercode")))  SubFireCheck(void)
{

    if(USE_CHECK == BAGGAGE_USE)    return(0);
    if(USE_CHECK == CARLIFT_USE)   	return(0);
    if(INVERTER_CHECK == D_F)		return(0);                                             
 
	if(!IN_X6 && (cF_X6SAFEFLR <= cF_TOPFLR)){
		FireBaseFloor=cF_X6SAFEFLR;    
    	return(1);         
	}
    else if(!IN_X5 && (cF_X5SAFEFLR <= cF_TOPFLR)){
		FireBaseFloor=cF_X5SAFEFLR;    
    	return(1);         
	}
    else                          	return(0);
}



UserDataType __attribute__((section(".usercode")))  UpLimitSpeedCheck(void)
{
    if(USE_CHECK == BAGGAGE_USE)    return(0);
    if(USE_CHECK == CARLIFT_USE)   	return(0);
    if(INVERTER_CHECK == D_F)		return(0);                                             

    if(!IN_X1)                     	return(1);         
    else                           	return(0);
}


UserDataType __attribute__((section(".usercode")))  DnLimitSpeedCheck(void)
{	
    if(USE_CHECK == BAGGAGE_USE)    return(0);
    if(USE_CHECK == CARLIFT_USE)   	return(0);
    if(INVERTER_CHECK == D_F)		return(0);                                             

    if(!IN_X0)                     	return(1);         
    else                           	return(0);
}



UserDataType __attribute__((section(".usercode")))  KidsKeyCheck(void)
{
	UserDataType	i,j,k,l;
		
    if(USE_CHECK == BAGGAGE_USE)	return(0);
    if(USE_CHECK == CARLIFT_USE)   	return(0);
    if(INVERTER_CHECK == D_F)		return(0);                                             
	if(cF_KIDS_KEY_CNT <= 1)		return(0);
    if(!IN_X2 || !KidsKeyChkUse)   	return(0);         
	
	j=mCarKey1-1;
	k=0;
	for(i=0;i <= cF_TOPFLR;i++){
		if( !(i % 8)){
			l=0x01;		
			j++;	
		}

		if(sRamDArry[j] & l){
			k++;
		}
		l=(l << 1);
	}	

	if(k > cF_KIDS_KEY_CNT)	bCarUpDnChButClr=1;														

	return(0);
}



UserDataType __attribute__((section(".usercode")))  CarKeyMostServiceCheck(void)
{

	if(bMoveCar)	return(0);
						
	S4_CAR_MOST_SERVICE1=0;
	
    if(!CarKeyFirstService)   return(0);         

#ifdef	FLOOR_64                                             
	if( !(sRamDArry[mCarKey1] | sRamDArry[mCarKey9] | sRamDArry[mCarKey17] | sRamDArry[mCarKey25] | sRamDArry[mCarKey33] | sRamDArry[mCarKey41] | sRamDArry[mCarKey49] | sRamDArry[mCarKey57]))	return(0);  
#else
	if( !(sRamDArry[mCarKey1] | sRamDArry[mCarKey9] | sRamDArry[mCarKey17] | sRamDArry[mCarKey25]))	return(0);  
#endif

	if(!bUpWard && !bDnWard)																		return(0);




#ifdef	FLOOR_64
#else                                             
	if( !(sRamDArry[mHighFloor] & CAR_READY))	sRamDArry[mHighFloor]=0x0;					
	if( !(sRamDArry[mLowFloor]  & CAR_READY))	sRamDArry[mLowFloor] =0x0;					

	if(bDoorCloseOk){
		if((sRamDArry[mHighFloor] & UPDN_CAR_READY) ||  (sRamDArry[mLowFloor]  & UPDN_CAR_READY)){
			S4_CAR_MOST_SERVICE1=1;
		}
	}
#endif

	return(0);  
}




void __attribute__((section(".usercode")))  BatCheck(void)
{
    if(!IN_BAT && bAuto){
        if(PowerFailTime > 20){
            PowerFailTime=21;

			if((USE_CHECK == MAN_USE) && bMoveCar){
				if(!IN_X4 && bHomeUpDn)			PowerFailTime=0;                                                                 
				else if(IN_X4 && !bHomeUpDn)	PowerFailTime=0;                                                                 		
			}


            if(bOnLuLd && bDoorOpenEnd && !bMoveCar){
              	ClrUpDnWard();       
                OUT_FAN(0);            
            }
        }

        if(PowerFailTime < 20){
            bCarErr=1;                                                                 
        }

        S1_POWER_FAIL=1;
    }
    else{
        if(S1_POWER_FAIL){
            if(PowerFailTime > 40){
                PowerFailTime=41;
                S1_POWER_FAIL=0;
                if(INVERTER_CHECK == IO){                                             
                    OUT_P4(0);                                             
                }
            }
            else{
                if(INVERTER_CHECK == IO){                                             
                    OUT_P4(0);                                             
                }
                bCarErr=1;
            }
        }
        else{                    
            PowerFailTime=0;
        }
    }     
}


unsigned int  __attribute__((section(".usercode"))) MotorOverheatChk(void)
{
	bMotor_Overheat=0;	
	if(!S2_FIRE1 && !IN_FHM){
		bMotor_Overheat=1;                    
	}	
	return(0);
}


unsigned int  __attribute__((section(".usercode")))   EarthquakeCheck(void)
{

	if(bSlaveEarthquake){
		bExtButClr=1;
   		bsEarthquake=1;
        sRamDArry[mLowFloor]  = 0;
        sRamDArry[mHighFloor] = 0;
	}
	else{
   		bsEarthquake=0;
	}

	return(0);
}


unsigned int  __attribute__((section(".usercode"))) LuLdDzCheckNormal(void)
{
		
	#ifdef  TEST_SIMULATION  
		return(0);
	#else
		if(New_Law_SystemChk()){
			if( ( IN_LU &&  IN_LD)  && !IN_BM)				bDZ_Err=1;	
			else if( (!IN_LU && !IN_LD)  &&  IN_BM) 		bDZ_Err=1;				
			else											bDZ_Err=0;	
		}	
	#endif

	return(0);
}


void    __attribute__((section(".usercode"))) WaterCheck(void)
{

    unsigned char watersafefloor;


	if(New_Law_SystemChk()){
		if(INVERTER_CHECK != LG){	
			if(!IN_FS0)	bWaterSensing=1;	
			else		bWaterSensing=0;	
		}
	}
	else{
		if(!IN_WATER)	bWaterSensing=1;	
		else			bWaterSensing=0;	
	}	


   	if(bWaterSensing){
	   	bExtButClr=1;
	 	bCarButClr=1;   

	    watersafefloor=cF_WATERSAFEFLR;	    
	    if(cF_WATERSAFEFLR >= cF_TOPFLR){
	        watersafefloor=cF_TOPFLR;
	    }

		if(bMoveCar){                
			if(bCarUpMove){                
				if(sRamDArry[mcurfloor] < watersafefloor){
					if(!bUnd){
						sRamDArry[mAckStopFloor]=(unsigned char)(watersafefloor | UPDN_CAR_READY);
						sRamDArry[mHighFloor]   =(unsigned char)(watersafefloor | UPDN_CAR_READY);
					}
				}
				else{
					sRamDArry[mLowFloor]  = 0;
					sRamDArry[mHighFloor] = 0;
				}
			}	
			else if(bCarDnMove){                
				if(sRamDArry[mcurfloor] > watersafefloor){
					if(!bUnd){
						sRamDArry[mAckStopFloor]=(unsigned char)(watersafefloor | UPDN_CAR_READY);
						sRamDArry[mLowFloor] = (unsigned char)(watersafefloor | UPDN_CAR_READY);
					}
				}
				else{
					sRamDArry[mLowFloor]  = 0;
					sRamDArry[mHighFloor] = 0;
				}
			}
		}
	 	else{
	    	if(sRamDArry[mcurfloor] == watersafefloor){			
				bWaterAndArrive=1;
			}
			else{
				bReOpen=1;
				if(ElevStopTime > 10){
					if(sRamDArry[mcurfloor] > watersafefloor)        sRamDArry[mLowFloor] = (watersafefloor | CAR_READY);
					else                                             sRamDArry[mHighFloor] =(watersafefloor | CAR_READY);
					sRamDArry[mNewAckStopFloor]= (watersafefloor | CAR_READY);        	
				}
			}            
		}
	}
    else{
        bWaterAndArrive=0;
    }
}



unsigned int  __attribute__((section(".usercode"))) LuLdDzCheck(void)
{
	if( (IN_LU && IN_LD))			return(1);	
	if( (IN_LU || IN_LD) && IN_BM) 	return(1);	
	return(0);
}





unsigned int  __attribute__((section(".usercode")))   ReLevelCheck(void)
{

	if(RelevelUseChk == 0){
		bRelevelErr=0;
		bLevelFind=0;
		return(0);
	}


    if(!bAuto || !bMotorRestartOn){
		bLevelFind=0;
		return(0);
	}

    if(bAuto && bMotorRestartOn && (sRamDArry[mDoorSeq] >= READY_ELEVATOR)){
		bLevelFind=0;
		return(0);
	}

    if(RelevelTime > RELEVEL_TIME){
		bRelevelErr=1;
	}



	if(New_Law_SystemChk()){
		if( LuLdDzCheck() && bLevelFind){
			bLevelFind=0;
			bRelevelErr=1;
		}         	         		        
	}
	else{	
	    if(IN_LU && IN_LD && bLevelFind){
  			bLevelFind=0;
			bRelevelErr=1;
		}
	}


	if(S1_OVERLOAD1){
    	if(bLevelFind){
			bRelevelErr=1;
		}
		else{
			return(0);	
		}
	}	


	if(New_Law_SystemChk()){
		if( !CurSelOutPortChk(cF_RST)){
			bNewRelevel=0;		         		
		}
					
	    if(!bOnLuLd && bOneLuOrLd){
	    	if(bManualAuto){
				OUT_RST(1);					
				if(	bNewRelevel==0){
					ReLevelAnounceTime=0;
					bNewRelevel=1;
				}		         		
				else{
					if(ReLevelAnounceTime > 10){
						LuLdTime=0;
						bFirstOnLuLd=0;
			       		CarOnceStopTime = 31;
			         	bManualAuto=0;
			            bLevelFind=1;
			            bDoorCloseOk=1;             		
			            if(!IN_LU && IN_LD)         bHomeUpDn = 1;
			            else if(IN_LU && !IN_LD)    bHomeUpDn = 0;
					}
				}
	  		}
	    }
	}
	else{
	    if(!bOnLuLd && bOneLuOrLd){
			if(bManualAuto){
				LuLdTime=0;
				bFirstOnLuLd=0;
				CarOnceStopTime = 31;
				bManualAuto=0;
				bLevelFind=1;
				bDoorCloseOk=1;             
				if(!IN_LU && IN_LD)         bHomeUpDn = 1;
				else if(IN_LU && !IN_LD)    bHomeUpDn = 0;
			}
	    }
	}


    if(bRelevelErr){
		UpDnAllOff();
		bLevelFind=0;
	    bCarErr=1;   
		bCarStopNoRun=1;  				         
		bNewRelevel=0;		         		
		ReLevelAnounceTime=0;
    }        
}




void __attribute__((section(".usercode")))  InputCheck(void)
{
   	ButtonClrCheck();   
    EmgDlsUlsCheck();   
	ReLevelCheck();
	DoorCloseOkCheck();
	RunningOpenValidChk();
    OverLoadCheck();
    ParkingCheck();
	MyFamilyServiceCheck();
	VipCheck();
    FullCheck();
	DoorOpenAndHoldCheck();
    LuLdOnCheck();      
    BatCheck();
	SensorPositionRead();
}





unsigned int  __attribute__((section(".usercode")))  Key_Auto_FhmCheck(void)
{
    if(FhmOnOffChk && (INVERTER_CHECK == IO)){
	    S1_AUTO1=0;
	    bAuto=0;
	    bExtButClr=1;
	    bCarButClr=1;               

		bFhmRun=1;	
		sRamDArry[FHM_SEQ]=FHM_SEQ_7;
		bAutoButtonErr=1;
		bCarErr=1;
    }      
	else{
		if(bFhmRun && (sRamDArry[FHM_SEQ] != FHM_SEQ_5)){	
			sRamDArry[FHM_SEQ]=FHM_SEQ_7;
			bAutoButtonErr=1;
			bCarErr=1;
		}
		else{
			bFhmRun=0;
			sRamDArry[FHM_SEQ]=FHM_SEQ_8;
		}
	}	

	return(0);
}


unsigned int  __attribute__((section(".usercode")))  Key_Manual_FhmCheck(void)
{
    if( !bAuto && !ManWorkingChk && (sRamDArry[FHM_SEQ] <= FHM_SEQ_7) && (FhmLoaderTime < 10)){
		bFhmRun=1;
	}
	else{
		bFhmRun=0;
		sRamDArry[FHM_SEQ]=FHM_SEQ_8;
	}

	return(0);
}






unsigned int  __attribute__((section(".usercode")))   Auto_Manual_Key_Check(void)
{

	if(IN_AUTO){		// manual key
		bDZ_Err=0;
		bMotor_Overheat=0;	
   		bsEarthquake=0;

        bWaterAndArrive=0;
		bWaterSensing=0;

		bInspect=0;


        if(bAuto && bMotorRestartOn && bMoveCar && bAutoRunningErr){
			bAutoButtonErr=1;
			bCarErr=1;
		}

		if( (WarmingUpTime > 20) && (WarmingUpTime < 30)){
		    bsSlip=0;	
		    bsLope=0;	
			bsUcmpFeedErr=0;
			bsNextFloor=0;

			NotRecoveryData=(NotRecoveryData & ~0x0f);
			bSaveFlash=1;
			bSlipCheckStart=0;
		}					

		if(!bCarUpMove && !bCarDnMove && !bManualUpKey && !bManualDnKey ){
			ClrUpDnWard();
		}


        if(bDoorCloseOk && (DoorCloseOnTime > 2)){
			CurDoorSelect=NO_DOOR;
		}


		Key_Manual_FhmCheck();	
	}
	else{				// auto key
		Key_Auto_FhmCheck();
	}

	return(0);
}


void __attribute__((section(".usercode")))  AutoManualCheck(void)
{

	Auto_Manual_Key_Check();


    if(IN_AUTO || (WarmingUpTime<15) || (sRamDArry[LD_INSP] == 0x55) || ManWorkingChk){

        if(S1_AUTO1){
            if(bMoveCar)    bCarErr=1;
        }
        S1_AUTO1=0;
       	bExtButClr=1;
        bCarButClr=1;   
        bAuto=0;
    }      
    else{
        S1_AUTO1=1;
        bAuto=1;
    }
  
}

 
      
void __attribute__((section(".usercode")))  AutoUpDownStart(void)
{   
    if(sRamDArry[mAckStopFloor]){  
        if((sRamDArry[mAckStopFloor] & ONLY_FLR) > sRamDArry[mcurfloor]){
            if(sRamDArry[mCarMoveState]==0){
                if(bMoveUpOk)   MoveCounterx++;
            }    
            CarUpStartCmd(); 
        }                         
        else if((sRamDArry[mAckStopFloor] & ONLY_FLR) < sRamDArry[mcurfloor]){
            if(sRamDArry[mCarMoveState]==0){
                if(bMoveDnOk)   MoveCounterx++;
            }
            CarDnStartCmd();
        }       

        if(MoveCounterx > 999999)	MoveCounterx=999999;

    }
}



unsigned int	__attribute__((section(".usercode"))) LoadCmdStartCheck(void)
{

	if(!AutoRunReady())								return(0);


/*
	if((sRamDArry[mVFlr1] != sRamDArry[mVFlr2]) && (sRamDArry[mVFlrCnt] > 0)){
		if((cF_FLRDSPCH(0) == 'Z') && (cF_FLRDSPCH(1) == 'Z')){		
			AccTimer=0;
			sRamDArry[ExtCmdFlrONOFF0]=0x0;	
			sRamDArry[ExtCmdFlrONOFF1]=0x0;	
			sRamDArry[ExtCmdFlrONOFF2]=0x0;	
			sRamDArry[ExtCmdFlrONOFF3]=0x0;
			#ifdef	FLOOR_64
				sRamDArry[ExtCmdFlrONOFF4]=0x0;
				sRamDArry[ExtCmdFlrONOFF5]=0x0;
				sRamDArry[ExtCmdFlrONOFF6]=0x0;
				sRamDArry[ExtCmdFlrONOFF7]=0x0;
			#endif

		}	
	}
*/


   	if(bCarUpMove || bCarDnMove)					return(0);        	

#ifdef  KTL  
     sRamDArry[mVFlrCnt]= 254;
     sRamDArry[mVFlr1] 	= cF_TOPFLR+1;
     sRamDArry[mVFlr2] 	= 1;
#else
	if(sRamDArry[mVFlrCnt] == 0)					return(0);
	if(sRamDArry[mVFlrCnt] > 254)					return(0);
	if( !(sRamDArry[mVFlr1] | sRamDArry[mVFlr2]))	return(0);

	if(sRamDArry[mVFlrCnt] > 250)	sRamDArry[mVFlrCnt] = 254;
#endif


#ifdef	FLOOR_64
	if(sRamDArry[mLowFloor] > 0)		return(0);	
	if(sRamDArry[mHighFloor]> 0)		return(0);
#else
	if(sRamDArry[mLowFloor]  & UPDN_CAR_READY)		return(0);	
	if(sRamDArry[mHighFloor] & UPDN_CAR_READY)		return(0);
#endif


		if((sRamDArry[mVFlr1] != sRamDArry[S0_FLOOR]) && (sRamDArry[mVFlr1] > 0) && (sRamDArry[mVFlr1] <= (cF_TOPFLR+1))){
			Virtual_Floor_Set(sRamDArry[mVFlr1] -1);	
		}    
		if((sRamDArry[mVFlr2] != sRamDArry[S0_FLOOR]) && (sRamDArry[mVFlr2] > 0) && (sRamDArry[mVFlr2] <= (cF_TOPFLR+1))){
			Virtual_Floor_Set((sRamDArry[mVFlr2] -1));	
		}    

	return(0);      
}


unsigned int __attribute__((section(".usercode"))) TimeCmpare(unsigned int i_basetime,unsigned int i)
{
    LocalType     Tmp_timeH,Tmp_timeM,Tmp_Stime,Tmp_Etime;
    LocalType     i_localtime;

	Tmp_timeH=cF_FLRDSPCH((unsigned long)(F_0506 + i + 0));
	if(Tmp_timeH >= 24)	return(0);
	Tmp_timeM=cF_FLRDSPCH((unsigned long)(F_0506 + i + 1));
	if(Tmp_timeM >= 60)	return(0);
	Tmp_Stime=( (Tmp_timeH << 8) | Tmp_timeM);


	Tmp_timeH=cF_FLRDSPCH((unsigned long)(F_0506 + i + 2));
	if(Tmp_timeH >= 24)	return(0);
	Tmp_timeM=cF_FLRDSPCH((unsigned long)(F_0506 + i + 3));
	if(Tmp_timeM >= 60)	return(0);
	Tmp_Etime=( (Tmp_timeH << 8) | Tmp_timeM);


	if(Tmp_Stime == Tmp_Etime)	return(0);
	if(Tmp_Stime == 0)			return(0);
	if(Tmp_Etime == 0)			return(0);

	
	if( (i_basetime >= Tmp_Stime) && (i_basetime < Tmp_Etime)){
		return(1);
	} 

	return(0);
}



unsigned int	__attribute__((section(".usercode"))) FixFloorStartTimeCheck(void)
{
    LocalType     cTime,cMin;

	cTime=0;

//zz	if(CmdFixFlrTime > 0){
//	if(S4_WAIT_FLR_SERVICE1){
	    cTime=(((sRamDArry[Hour] & 0xf0) >> 4) * 10);
	    cTime=((sRamDArry[Hour] & 0x0f) + cTime);
	    cMin=(((sRamDArry[Minuate] & 0xf0) >> 4) * 10);
	    cMin=((sRamDArry[Minuate] & 0x0f) + cMin);		
		if((cTime < 24) && (cMin < 60)){	
			cTime=((cTime << 8) | cMin);
		}
		else	cTime=0;	
//	}
	return(cTime);	
}


unsigned int	__attribute__((section(".usercode"))) FixFloorStartValidCheck(void)
{
	unsigned int i;

	if( !S4_WAIT_FLR_SERVICE1)				return(0);
	if( cF_FIXFLOOR > cF_TOPFLR)			return(0);
//	if( FixFlrTimeCnt < cF_FIXFLOORTIME)	return(0);
	if( cF_FIXFLOORTIME == 0)				return(0);



	
	i= (unsigned int)cF_FIXFLOORTIME;
	if( i > SEC_MIN_TIME){
		i= (i - SEC_MIN_TIME);
		i= (i * 60);
		if( FixFlrTimeCnt < i)				return(0);
	}
	else{
		if( FixFlrTimeCnt < i)	return(0);
//		if( FixFlrTimeCnt < cF_FIXFLOORTIME)	return(0);
	}


	return(1);
}

unsigned int	__attribute__((section(".usercode"))) FixFloorStartCheck(void)
{
    LocalType     TmpFlrBuf;
    LocalType     cTime;


	if(S3_PARKING1)					return(0);
   	if(bCarUpMove || bCarDnMove)	return(0);        	


	TmpFlrBuf=0xff;
	cTime=FixFloorStartTimeCheck();



	if( FixFloorStartValidCheck()){
		Virtual_Floor_Set(cF_FIXFLOOR);
		return(0);
	}
	else if(cTime > 0){
		if(TimeCmpare(cTime,0)){
			TmpFlrBuf=cF_FLRDSPCH((unsigned long)(F_0506 +  4));
		}
		else if(TimeCmpare(cTime,5)){
			TmpFlrBuf=cF_FLRDSPCH((unsigned long)(F_0506 +  9));
		}
		else if(TimeCmpare(cTime,10)){
			TmpFlrBuf=cF_FLRDSPCH((unsigned long)(F_0506 +  14));
		}

		if((TmpFlrBuf <= cF_TOPFLR) && (TmpFlrBuf != sRamDArry[mcurfloor])){
			Virtual_Floor_Set(TmpFlrBuf);
			return(0);
		}
		else	return(0);
	}
	return(0);
}







unsigned int  __attribute__((section(".usercode"))) 	UpDnRstCheck(void)
{
#ifdef	FLOOR_64
	if(bUpWard){
		if(sRamDArry[mHighFloor]==0){
            ClrUpDnWard();
            sRamDArry[mNewAckStopFloor] = 0x0;
        }
	}         				
   	else if(bDnWard){
       	if(sRamDArry[mLowFloor]==0){
            ClrUpDnWard();
            sRamDArry[mNewAckStopFloor] = 0x0;
       	}         
	}
#else
	if(bUpWard){
		if(!(sRamDArry[mHighFloor] & UPDN_CAR_READY)){
            ClrUpDnWard();
            sRamDArry[mHighFloor]=0;
            sRamDArry[mNewAckStopFloor] = 0x0;
        }
	}         				
   	else if(bDnWard){
       	if(!(sRamDArry[mLowFloor] & UPDN_CAR_READY)){
            ClrUpDnWard();
            sRamDArry[mNewAckStopFloor] = 0x0;
            sRamDArry[mLowFloor]=0;
       	}         
	}
#endif
	return(0);

}


LocalType  __attribute__((section(".usercode"))) UpMoveCheck(void)
{
    LocalType   i;

    i=0;    
    if(bsUls)                                                       i=1;

#ifdef	FLOOR_64
    if( (sRamDArry[mHighFloor] & ONLY_FLR) <= sRamDArry[mcurfloor]) i=1;
    if( sRamDArry[mHighFloor]==0)                   				i=1;
#else
    if( (sRamDArry[mHighFloor] & ONLY_FLR) <= sRamDArry[mcurfloor]) i=1;
    if(!(sRamDArry[mHighFloor] & UPDN_CAR_READY))                   i=1;
#endif
    return(i);
}



LocalType  __attribute__((section(".usercode"))) DnMoveCheck(void)
{
    LocalType   i;

    i=0;
    
    if(bsDls)                                                       	i=1;

#ifdef	FLOOR_64
    if( (sRamDArry[mLowFloor] & ONLY_FLR) >= sRamDArry[mcurfloor])  	i=1;
    if(sRamDArry[mLowFloor]==0)                    					i=1;
#else
    if( (sRamDArry[mLowFloor] & ONLY_FLR) >= sRamDArry[mcurfloor])  	i=1;
    if(!(sRamDArry[mLowFloor] & UPDN_CAR_READY))                    	i=1;
#endif
    return(i);
}



void  __attribute__((section(".usercode"))) AutoDoorSystem(void)
{

	if(SafetyChk() || 	(!OpenKeyCheck()) ){

        S3_PARKING1=0;          
        sRamDArry[mDoor]= (sRamDArry[mDoor] & MAIN_SUB_CLOSE_KEY_CLEAR);
    		    		         
     	if(sRamDArry[mDoorSeq] >= DOOR_OPEN_WAIT){         
            if(USE_CHECK == MAN_USE){      
                if(sRamDArry[mDoorSeq] >= DOOR_REOPEN_CHECK){         
                   	sRamDArry[mDoorSeq]=DOOR_OPEN_START;
                    DoorOpenTime=0;
		            bReOpen=1;


					if(OpenOutSet){  
		            	bReOpen=0;
					}

	         			if(!bUpWard && !bDnWard){                                 		   	
	         				if(sRamDArry[mEqualFloor] & UP_READY)		bReOpen=0;
	         	      		else if(sRamDArry[mEqualFloor] & DN_READY)	bReOpen=0;
	         			}      
	               		else if((bUpWard) && (sRamDArry[mEqualFloor] & UP_READY))	bReOpen=0;
	               		else if((bDnWard) && (sRamDArry[mEqualFloor] & DN_READY))	bReOpen=0;
                }
            }
            else{
               	sRamDArry[mDoorSeq]=DOOR_OPEN_START;
                DoorOpenTime=0;
                bReOpen=1;
            }
      	} 
 
		SafetyChk();
	}         
	else if(!CloseKeyCheck()){
         if(sRamDArry[mDoorSeq] < DOOR_CLOSE_START){
	         if(bOpenDoorOk || (sRamDArry[mDoorSeq] >= DOOR_OPEN_WAIT) ){
				if( !DoorOpenEndWaitChk()){
	                DoorOpenTime = cF_OPWTTM + DEFAULT_REOPTM + 1;
		         	sRamDArry[mDoorSeq]=DOOR_CLOSE_START;
				}     	          
	         }
		 }
         sRamDArry[mDoor]= (sRamDArry[mDoor] & MAIN_SUB_CLOSE_KEY_CLEAR);            
	}


  
//	AutoUpDnDirectionSet();
	

    if(sRamDArry[mDoorSeq] == READY_ELEVATOR){          
        if(bUpWard){
            if(!UpMoveCheck()){
				OneStopKey();
                sRamDArry[mNewAckStopFloor] = sRamDArry[mHighFloor];
            }                          
            else{
                ClrUpDnWard();
                sRamDArry[mEqualFloor]=0;
                sRamDArry[mHighFloor]=0;
                sRamDArry[mNewAckStopFloor] = 0x0;
            }
        }
        else if(bDnWard){
            if(!DnMoveCheck()){
				OneStopKey();
               	sRamDArry[mNewAckStopFloor] = sRamDArry[mLowFloor];
            }  
            else{
                ClrUpDnWard();
                sRamDArry[mNewAckStopFloor] = 0x0;
                sRamDArry[mEqualFloor]=0;
                sRamDArry[mLowFloor]=0;
            }         
        }
    }
}   





//20051008insert
void __attribute__((section(".usercode"))) 	NoButtonAndDefaultLoad(void)
{
#ifdef	FLOOR_64
	if(sRamDArry[mReqStopFloor] & UPDN_READY){
		sRamDArry[DEST_FLR]=sRamDArry[mAckStopFloor] = sRamDArry[mReqStopFloor];
	}         	
#else
	if(sRamDArry[mReqStopFloor] & CAR_READY){
		sRamDArry[DEST_FLR]=sRamDArry[mAckStopFloor] = sRamDArry[mReqStopFloor];
	}         	
#endif
}





#ifdef	DELTA_INVERTER	

void __attribute__((section(".usercode")))  TuningRunCheck(void)
{
	unsigned int i;
	
	i=0;
    if( IN_AUTO && (sRamDArry[AUTO_TUNING] > AUTOTUN_SEQ_0) && (TuningLoaderTime < 10) && (INVERTER_CHECK == IO) ){	
		if( !bManualUpKey && !bManualDnKey && !bMoveCar && !bCarUpMove && !bCarDnMove){
			i=1;
			DeltaAutoTunningRun(0x08,0x00);
			bAutoTunning=1;
		} 
	}

	if(i==0){
		if(bAutoTunning){
		    OUT_P4(0);
		    OUT_U_W(0);
		    OUT_D_W(0);
		    OUT_BK1(0);

			AutotunUpDn=0;
			sRamDArry[AUTO_TUNING] = AUTOTUN_SEQ_0;	
			AutotunUpDn=0;
			bAutoTunning=0;
		}
	}
}
#else

void __attribute__((section(".usercode")))  TuningRunCheck(void)
{
	unsigned int i;	
	i=0;
    if( IN_AUTO && (sRamDArry[AUTO_TUNING] > AUTOTUN_SEQ_0) && (TuningLoaderTime < 10) && (INVERTER_CHECK == IO) ){	
		if( !bManualUpKey && !bManualDnKey && !bMoveCar && !bCarUpMove && !bCarDnMove){
			i=1;
			if(AutotunUpDn==1){
				OUT_P4(1);
			}
			else{
				OUT_P4(1);
				OUT_BK1(1);
				OUT_BK2(1);
			}	
			bAutoTunning=1;
		} 
	}

	if(i==0){
		if(bAutoTunning){
			OUT_P4(0);
			OUT_BK1(0);
			OUT_BK2(0);
			bAutoTunning=0;
			AutotunUpDn=0;
			sRamDArry[AUTO_TUNING] = AUTOTUN_SEQ_0;	
		}
	}
}
#endif







void __attribute__((section(".usercode")))  ManualUpDnKeyCheck(void)
{
	LocalType KeyTime;

	unsigned int  x,y;
	unsigned int  i;
 
  
	if(bAuto)      KeyTime=30;
	else           KeyTime=5;
      
	if( (!IN_U_B && IN_D_B) && (!bCarDnMove)){
		if(UpBttonTime >= KeyTime){
			UpBttonTime = KeyTime;                  
			bManualUpKey=1;
		}                
		DnBttonTime=0;     
	}         
	else if( (!IN_D_B && IN_U_B) && (!bCarUpMove)){                  
		if(DnBttonTime >= KeyTime){
			DnBttonTime=KeyTime;
			bManualDnKey=1;
		}                  
		UpBttonTime=0;
	}
	else{
		DnBttonTime=0;
		UpBttonTime=0;    
		bManualUpKey=0;
		bManualDnKey=0;        
	}
   

	if(ManWorkingSeq==1){
		bManualDnKey=1;
	}




	if(bFhmRun){		

		if(bCarErr){
			if(sRamDArry[FHM_SEQ] < FHM_SEQ_6){
				sRamDArry[FHM_SEQ] = FHM_SEQ_6;
			}
		}

		switch(sRamDArry[FHM_SEQ]){ 
			case  FHM_SEQ_0:
				if(bMotorRestartOn && !bMoveCar){
	               	for(i=0;i<32;i++)	parameter_mirror[i]= 0x0fffffff;
                                                                   
					if(!IN_LU && IN_LD && !IN_SD1){
						sRamDArry[FHM_SEQ]=FHM_SEQ_2;
					}
					else if(IN_DLS){
						sRamDArry[FHM_SEQ]=FHM_SEQ_2;
					}
					else{
						sRamDArry[FHM_SEQ]=FHM_SEQ_1;
					}
				}
	            if(INVERTER_CHECK == LG) OUT_P4(0);
				#ifdef	DELTA_INVERTER 					
					DeltaRdWrStatusFhm=1;
				#endif
				break;
			case  FHM_SEQ_1:
				if(!IN_LU && IN_LD && !IN_SD1){
					if(!bMotorRestartOn){
                		sRamDArry[FHM_SEQ]=FHM_SEQ_2;
					}
				}
				else{
					bManualDnKey=1;
				}
				break;
			case  FHM_SEQ_2:
				if(!IN_LU && IN_LD && !IN_SD1){
	               	sRamDArry[mcurfloor]=1;
					#ifdef	DELTA_INVERTER 					
						if(DeltaInverterRdWrFhm(0x09,0x0a)){
							if(bMotorRestartOn){
								FhmToggle=LU_OFF_LD_OFF;	
                        		sRamDArry[FHM_SEQ]=FHM_SEQ_3;
							}
						}
					#else
						if(bMotorRestartOn){
                        	if(INVERTER_CHECK == LG) OUT_P4(1);

	                		sRamDArry[FHM_SEQ]=FHM_SEQ_3;
							FhmToggle=LU_OFF_LD_OFF;	
						}
					#endif
            	}  
				else{
                    sRamDArry[FHM_SEQ]=FHM_SEQ_1;
				}        
				break;   
			case  FHM_SEQ_3:
				if(IN_LU && !IN_LD && !IN_SU1){
					if(!bMoveCar){		
                        LevelEncoderPulse2=CurPulse;

                        if(INVERTER_CHECK == LG) OUT_P4(0);

                        if(INVERTER_CHECK == IO){
                        	LevelEncoderPulse2=(CurPulse - LevelEncoderPulse2);

							#ifdef	FLOOR_64
   								for(i=0;i<64;i++)    parameter_mirror[i] = (parameter_mirror[i] + LevelEncoderPulse1);
							#else
   								for(i=0;i<32;i++)    parameter_mirror[i] = (parameter_mirror[i] + LevelEncoderPulse1);
							#endif

							SaveVerify=0x55;
                            SaveFloorCnt();
    
                        }
    
                        GetFlashDataToBufRam(F_BLOCK1);
                        b_LdTmpBufRam(F_TopFlr)    = sRamDArry[mcurfloor]; // top floor
                        bit_LdTmpBufRamReset(F_OnOff0,bFhmOnOff);


						SaveVerify=0x55;
                        flash_write_DspChar(F_BLOCK1);
						SaveVerify=0;


                        GetFlashDataToBufRam(F_BLOCK2);
       					i_LdTmpBufRam(F_StopPulse0)     = (unsigned int)LevelEncoderPulse1;
						SaveVerify=0x55;
                        flash_write_DspChar(F_BLOCK2);
						SaveVerify=0;

						#ifdef	DELTA_INVERTER 					
						DeltaRdWrStatusFhm=10;
						#endif

                        sRamDArry[FHM_SEQ]=FHM_SEQ_4;
					}
				}	
				else{
                    if(INVERTER_CHECK == LG) OUT_P4(1);
					bManualUpKey=1;					
	
                    if(INVERTER_CHECK == IO){                        
						if(!IN_LU && IN_LD){
							if(FhmToggle == LU_OFF_LD_OFF){	
								FhmToggle=LU_ON_LD_OFF;
							}
                        }
                        else if(!IN_LU && !IN_LD){
							if(FhmToggle == LU_ON_LD_OFF){    
	                            if(!IN_SD1){
	                                sRamDArry[mcurfloor]=0;   
		                            POSCNT=0;
									BefCurEncoderPulse=0;
		                            CurPulse=BASE_PULSE;        
	                            }
	                            else{ 
	                                sRamDArry[mcurfloor]++;                            
	                            }                        
	                            parameter_mirror[sRamDArry[mcurfloor]] =CurPulse; 
								FhmToggle=LU_ON_LD_ON;
							}
                        }
                        else if(IN_LU && !IN_LD){
							if(FhmToggle == LU_ON_LD_ON){	
	                            LevelEncoderPulse2 = CurPulse;                    
	                            if(parameter_mirror[0] != BASE_PULSE){
	                        		sRamDArry[FHM_SEQ]=FHM_SEQ_1;
								}
								FhmToggle=LU_OFF_LD_ON;
							}
                        }
                        else if(IN_LU && IN_LD){
							if(FhmToggle == LU_OFF_LD_ON){			
								if(!IN_SD1){
		                            LevelEncoderPulse1=(CurPulse - parameter_mirror[0]);
		                            LevelEncoderPulse2=(CurPulse - LevelEncoderPulse2);                                	
		                            LevelEncoderPulse1=(LevelEncoderPulse1 / 2);
		                            LevelEncoderPulse2=(LevelEncoderPulse2 / 2);                       
		                            LevelEncoderPulse1=(LevelEncoderPulse1 - LevelEncoderPulse2); 
								}
								FhmToggle=LU_OFF_LD_OFF;
							}
                        }
                    }
				}
				break;               
			case  FHM_SEQ_4:
                if(INVERTER_CHECK == LG) OUT_P4(0);
				#ifdef	DELTA_INVERTER 					
					if(DeltaInverterRdWrFhm(0x09,0x0a)){
                        sRamDArry[FHM_SEQ]=FHM_SEQ_5;
					}
				#else
                	sRamDArry[FHM_SEQ]=FHM_SEQ_5;
             	#endif
				break;
			case  FHM_SEQ_5:			
				break;
			case  FHM_SEQ_6:
				if(ElevStopTime > 10){			// 10 sec
					bsBreakMgtOpen=0;    
					bsBreakOpen=0;
					bEncoderErr=0;
	 				bEncoderABErr=0;
				}
	            if(INVERTER_CHECK == LG) OUT_P4(0);
				break;
			case  FHM_SEQ_7:
                if(INVERTER_CHECK == LG) OUT_P4(0);                                             
				break;
			case  FHM_SEQ_8:
				break;
			default:
                if(INVERTER_CHECK == LG) OUT_P4(0);                                             
				break;            
		}
	}
}



void __attribute__((section(".usercode")))  ManualUpDown(void)
{    
    unsigned int i;
    i=1;

    if(SafetyChk()){
        i=0;        
    }

	if(bManualUpKey){
		if(!bDoorCloseOk){         
            if(i==1){
            	SelectDoorClose_you();
			}
            else if(!IN_LU || !IN_LD)   SelectDoorOpen_you();
		}  
        else if(bMotorRestartOn){                         
    		CarUpStartCmd();    
    		if(!bMoveUpOk){
    			bCarErr=1;
    		}      
        }
        else{
			bCarErr=1;
        }                         
	}          
   	else if(bManualDnKey){
		if(!bDoorCloseOk){
            if(i==1){
            	SelectDoorClose_you();
			}
            else if(!IN_LU || !IN_LD)   SelectDoorOpen_you();
        }
        else if(bMotorRestartOn){                         
            CarDnStartCmd();
            if(!bMoveDnOk){                  
                bCarErr=1;
            } 
        }
        else{
            bCarErr=1;
        }                         
    }
    else{
    	if(bMoveCar) 	bCarStop=1;
    }    
}            



unsigned int	__attribute__((section(".usercode")))  OutDateCheck(void)
{    

	bInspect=0;

    if((cF_ERRSTOPCNT < eDArry[eErrCntPt]) && (cF_ERRSTOPCNT != 0xff) && (cF_ERRSTOPCNT > 0x00)){
		bInspect=1;
		return(0);
    }


	if( !AutoRunReady())			return(1);	

	if(cF_year	== 0)				return(1);		
	if(cF_month == 0)				return(1);		
	if(cF_day 	== 0)				return(1);		
	if(cF_month > 0x12)				return(1);		
	if(cF_day 	> 0x31)				return(1);		

	if(sRamDArry[Year]	== 0)		return(1);		
	if(sRamDArry[Month] == 0)		return(1);		
	if(sRamDArry[Day] 	== 0)		return(1);		
	if(sRamDArry[Month] > 0x12)		return(1);		
	if(sRamDArry[Day] 	> 0x31)		return(1);		


	if(sRamDArry[Year]	< cF_year)	return(1);		
	if(sRamDArry[Month]	< cF_month)	return(1);		
	if(sRamDArry[Day]	< cF_day)	return(1);		

	bInspect=1;

	return(0);
}            




unsigned int __attribute__((section(".usercode")))  CheckFloorSensor(void)
{
	LocalType FloorPort;

	bFlrMatchChk=0;

#ifdef	TEST_SIMULATION
	bFlrMatchChk=0;
	return(0);
#else


    if(((USE_CHECK == BAGGAGE_USE) ||  (USE_CHECK == CARLIFT_USE))){ 
		if((sRamDArry[mcurfloor] == 0) && IN_SD1){
			bFlrMatchChk=1;
		}

		if((sRamDArry[mcurfloor] == cF_TOPFLR) && IN_SU1){
			bFlrMatchChk=1;
		}

        if(!IN_SD1 || !IN_SU1){
	        if(!IN_X0 || !IN_X1 || !IN_X2 || !IN_X3 || !IN_X4 || !IN_X5 || !IN_X6){ 
				bFlrMatchChk=1;
	        }

        	if(!IN_SD1 && !IN_SU1){           
				bFlrMatchChk=1;
			}          
			return(0);
		}

		if(!FloorSelMethod){
	        switch(sRamDArry[mcurfloor]){
	            case    1:    
	                if(IN_X0 || !IN_X1 || !IN_X2 || !IN_X3 || !IN_X4 || !IN_X5 || !IN_X6){ 
						bFlrMatchChk=1;
	                }                    
	                break;
	            case    2:
	                if(IN_X1 || !IN_X0 || !IN_X2 || !IN_X3 || !IN_X4 || !IN_X5 || !IN_X6){ 
						bFlrMatchChk=1;
	                }                    
	                break;
	            case    3:
	                if(IN_X2 || !IN_X0 || !IN_X1 || !IN_X3 || !IN_X4 || !IN_X5 || !IN_X6){ 
						bFlrMatchChk=1;
	                }                    
	                break;
	            case    4:
	                if(IN_X3 || !IN_X0 || !IN_X1 || !IN_X2 || !IN_X4 || !IN_X5 || !IN_X6){
						bFlrMatchChk=1;
	                }                    
	                break;
	            case    5:
	                if(IN_X4 || !IN_X0 || !IN_X1 || !IN_X2 || !IN_X3 || !IN_X5 || !IN_X6){ 
						bFlrMatchChk=1;
	                }                    
	                break;
	            case    6:
	                if(IN_X5 || !IN_X0 || !IN_X1 || !IN_X2 || !IN_X3 || !IN_X4 || !IN_X6){ 
						bFlrMatchChk=1;
	                }                    
	                break;
	            case    7:
	                if((IN_X6 || IN_X0) || !IN_X1 || !IN_X2 || !IN_X3 || !IN_X4 || !IN_X5){ 
						bFlrMatchChk=1;
	                }                    
	                break;
	            case    8:
	                if((IN_X6 || IN_X1) || !IN_X0 || !IN_X2 || !IN_X3 || !IN_X4 || !IN_X5){ 
						bFlrMatchChk=1;
	                }                    
	                break;
	            case    9:
	                if((IN_X6 || IN_X2) || !IN_X0 || !IN_X1 || !IN_X3 || !IN_X4 || !IN_X5){ 
						bFlrMatchChk=1;
	                }                    
	                break;
	            case    10:
	                if((IN_X6 || IN_X3) || !IN_X0 || !IN_X1 || !IN_X2 || !IN_X4 || !IN_X5){ 
						bFlrMatchChk=1;
	                }                    
	                break;
	            case    11:
	                if((IN_X6 || IN_X4) || !IN_X0 || !IN_X1 || !IN_X2 || !IN_X3 || !IN_X5){ 
						bFlrMatchChk=1;
	                }                    
	                break;
	            case    12:
	                if((IN_X6 || IN_X5) || !IN_X0 || !IN_X1 || !IN_X2 || !IN_X3 || !IN_X4){ 
						bFlrMatchChk=1;
	                }                    
	                break;
	
	            default:
						bFlrMatchChk=1;
	                break;        
	        }    
		}
		else{
			FloorPort=0;
			if( !IN_X0)	FloorPort=(FloorPort | 0x01);
			if( !IN_X1)	FloorPort=(FloorPort | 0x02);
			if( !IN_X2)	FloorPort=(FloorPort | 0x04);
			if( !IN_X3)	FloorPort=(FloorPort | 0x08);
			if( !IN_X4)	FloorPort=(FloorPort | 0x10);
			if( !IN_X5)	FloorPort=(FloorPort | 0x20);
	
	        if(sRamDArry[mcurfloor] != FloorPort){
					bFlrMatchChk=1;
			}
		}			
    }

#endif
	return(0);
}



unsigned int __attribute__((section(".usercode")))  FlrMatchInitChk(void)
{
#ifdef	TEST_SIMULATION
		bEqualFloorError=0;
		return(0);
#else
	if(bEqualFloorError){		
	    if(!IN_SU1 && IN_SD1 && !IN_EMG){               
 			sRamDArry[mcurfloor]=cF_TOPFLR;
			sRamDArry[mLuLdFloor]=sRamDArry[mcurfloor];          		
			bEqualFloorError=0;
	    }
		else{
 			sRamDArry[mcurfloor]=0;
			sRamDArry[mLuLdFloor]=sRamDArry[mcurfloor];          		
			bEqualFloorError=0;
		}
	}
	return(0);
#endif

}






unsigned int __attribute__((section(".usercode")))  PositionOkChk(void)
{
#ifdef	TEST_SIMULATION
        bsSdsErr=0;
        bsSusErr=0;
		return(0);
#else

	if( OneEncoderBkErrChk()){
        bsSdsErr=0;
        bsSusErr=0;
		return(0);
	}		        						


    if( !IN_SU1 || (sRamDArry[mcurfloor] >= cF_TOPFLR)){
        if(!IN_SU1 && (sRamDArry[mcurfloor] == cF_TOPFLR)){
            bsSusErr=0;
        }
        else{
            bsSusErr=1;
            bCarErr=1;
        }
    
        if(!IN_SU1 && !IN_EMG) sRamDArry[mcurfloor]=cF_TOPFLR;        //modify ?
    }    
    else if(!IN_SD1 || (sRamDArry[mcurfloor] == 0)){
        if(!IN_SD1 && (sRamDArry[mcurfloor] == 0)){
            bsSdsErr=0;
        }
        else{
            bsSdsErr=1;
            bCarErr=1;
        }
    
        if(!IN_SD1 && !IN_EMG) sRamDArry[mcurfloor]=0;                 //modify ?
    }
    else{
        bsSdsErr=0;
        bsSusErr=0;
    }

#endif

}

//////

unsigned int  __attribute__((section(".usercode")))  StopPulseCheck(void)
{

#ifdef	TEST_SIMULATION
	return(0);

#else
//////	unsigned int ZeroHzSet;
///////	ZeroHzSet=0;

	LuLdTime=0;

	if(bOnLuLd){
		TestPulse1= (unsigned long)iF_StopPulse;
		if(bCarUpMove){
			if(CurPulse >= ((LuLdEncoder + TestPulse1) - LevelEncoderPulse2))	bZeroHzSet=1;			
		}
		else if(bCarDnMove){
			if(CurPulse <= ((LuLdEncoder - TestPulse1) + LevelEncoderPulse2))	bZeroHzSet=1;			
		}

		if(bZeroHzSet==1){			
            ZeroSpeedCmd_IO();
			LuLdTime = iF_RunOffTime;
		  	sRamDArry[mCarMoveState]=0;
			LevelEncoderPulse1=CurPulse;
			return(0);
		}
	}	
	return(1);

#endif
}




unsigned int  __attribute__((section(".usercode")))  DoorjumperChkValid(void)
{
	unsigned int	i;

	#ifdef  TEST_SIMULATION  
		i=0;
	#else
		if(DoorJumperChkOnOffChk){
			if(Old_Law_SystemChk()){
				if((!bFirstFire && !bSecondFire))	i=1;
				else								i=0;
			}
			else									i=1;
		}
		else	i=0;
	#endif

	if(i==0){
		DoorJumperNm=0;
		bDoorJumper=0;
	}

	return(i);					  
}



unsigned int  __attribute__((section(".usercode")))  TestArriveEncoderValueReload(void)
{
	unsigned long tmp_p2,tmp_p3;


	tmp_p2=(unsigned long)(CurPulse);

	tmp_p3=(unsigned long)FLOOR_COUNT(sRamDArry[mcurfloor]);							
	if(tmp_p2 >= tmp_p3){
		LType_Test_Value=(unsigned long)(tmp_p2 - tmp_p3);
		iType_Test_PlusMinus=1;   	// plus
	}
	else{
		LType_Test_Value=(unsigned long)(tmp_p3 - tmp_p2);
		iType_Test_PlusMinus=0;		// minus
	}

	return(0);
}


/*
unsigned int  __attribute__((section(".usercode")))  EncoderValueReload(void)
{
	unsigned long tmp_p1,tmp_p2,tmp_p3,tmp_p4;


	tmp_p1=(unsigned long)iF_StopPulse;
	tmp_p2=(unsigned long)FLOOR_COUNT(sRamDArry[mcurfloor]);							

	if(bCarUpMove){
		tmp_p3=(unsigned long)(tmp_p2 - tmp_p1);
	}
	else if(bCarDnMove){
		tmp_p3=(unsigned long)(tmp_p2 + tmp_p1);
	}
	else{
		return(0);
	}


	ReadEncoder();
	tmp_p4=(unsigned long)(CurPulse);

	CurPulse=(unsigned long)(tmp_p3);
	BefCurPulse=CurPulse;
  	POSCNT = 0;
	BefCurEncoderPulse=0;


////////////////////////
	if(tmp_p4 >= tmp_p3){
		LType_Test_Value=(unsigned long)(tmp_p4 - tmp_p3);
		iType_Test_PlusMinus=1;   	// plus
	}
	else{
		LType_Test_Value=(unsigned long)(tmp_p3 - tmp_p4);
		iType_Test_PlusMinus=0;   	// plus
	}
///////////


	return(0);
}
*/


unsigned int  __attribute__((section(".usercode")))  EncoderValueReload(void)
{
	unsigned long tmp_p1,tmp_p2,tmp_p3,tmp_p4;


	bReLoadEncoderExe=0;

	tmp_p4=(unsigned long)(CurPulse);

	tmp_p1=(unsigned long)iF_StopPulse;
	tmp_p2=(unsigned long)FLOOR_COUNT(sRamDArry[mcurfloor]);							

	if(bCarUpMove){
		tmp_p3=(unsigned long)(tmp_p2 - tmp_p1);
	}
	else if(bCarDnMove){
		tmp_p3=(unsigned long)(tmp_p2 + tmp_p1);
	}
	else{
		return(0);
	}


  	POSCNT = 0;
	BefCurEncoderPulse=0;

	CurPulse=(unsigned long)(tmp_p3);
	BefCurPulse=CurPulse;

	bCalcuMpmOn=0;


/*
	ReadEncoder();
	tmp_p4=(unsigned long)(CurPulse);

	CurPulse=(unsigned long)(tmp_p3);
	BefCurPulse=CurPulse;
  	POSCNT = 0;
	BefCurEncoderPulse=0;

*/

////////////////////////
	if(tmp_p4 >= tmp_p3){
		LType_Test_Value=(unsigned long)(tmp_p4 - tmp_p3);
		iType_Test_PlusMinus=1;   	// plus
	}
	else{
		LType_Test_Value=(unsigned long)(tmp_p3 - tmp_p4);
		iType_Test_PlusMinus=0;   	// plus
	}
///////////


	return(0);
}



void __attribute__((section(".usercode")))  Dz_Overheat_Earthquake_Water_Chk(void)
{			  
	LuLdDzCheckNormal();		
	MotorOverheatChk();
	EarthquakeCheck();
	WaterCheck();
}





unsigned int __attribute__((section(".usercode")))  ManWorkingStartCheck(void)
{
	unsigned long	tx1,tx2;

	if(INVERTER_CHECK != IO){
		ManWorkingSeq=0;
		return(0);			  
	}


	if(IN_VIRTUAL_X1){
		ManWorkingSeq=0;
		return(0);			  
	}

	switch(ManWorkingSeq){
		case	0:
			if(!IN_VIRTUAL_X1 && !bFhmRun){
				if(AutoRunReady()){
					if((sRamDArry[mDoorSeq] == READY_ELEVATOR)){
						if(bDoorCloseOk && bOneLuOrLd){
	        				if(sRamDArry[mcurfloor] > 0){
								
								tx1=GET_LONG(MM_PULSE);							
								if(tx1>0){
									tx2 = ((unsigned long)10000 * (unsigned long)(2000));  // 2m		
									tx2 = (tx2/tx1);		
								}									

								tx1=CurPulse;
								tx1=(tx1 - tx2);
								ManJobPulse=(tx1);
	
								bAuto=0;
								bExtButClr=1;
								bCarButClr=1;
								ManWorkingSeq=1;
								bSlipCheckStart=0;
							}
						}
					}
				}
			}
			break;
		case	1:
			bAuto=0;
			bExtButClr=1;
			bCarButClr=1;
			if(CurPulse <= ManJobPulse){
				ManWorkingSeq=2;
			}
			else if( (IN_AUTO) || (bCarErr || bCarStopNoRun)){
				ManWorkingSeq=2;
			}
			break;
		case	2:
			if(IN_AUTO){
				ManWorkingSeq=3;
			}
			else{
				bAuto=0;
				bExtButClr=1;
				bCarButClr=1;
			}	
			break;
		case	3:
			bExtButClr=1;
			bCarButClr=1;
			if(!IN_AUTO){
				if(bOnLuLd && (sRamDArry[mDoorSeq] > DOOR_REOPEN_CHECK) ){
					sRamDArry[mDoorSeq] = DOOR_OPEN_START;
				}

				if((bCarErr || bCarStopNoRun)){
					ManWorkingSeq=0;
				}
			}
			break;
		default:
			break;			
	}

	return(0);			  
}



unsigned int __attribute__((section(".usercode")))  SolOnChk(void)
{
    LocalType in_decrease; 

	in_decrease=0;
	bDoorOpenValid=0;

	if((iF_SolOnTime < 3) || (iF_DoorWaitTime < 3)){
		bDoorOpenValid=1;
		SolTimer=0;
		bSolControl=0;
		return(1);
	}


	bSolControl=1;
	if(New_Law_SystemChk()){
		if(INVERTER_CHECK != LG){	
			if(!IN_FS2)	in_decrease=1;   	// decrease
		}
	}
	else{
		if(!IN_GS2)	in_decrease=1;   		// decrease
	}	


    if(bDoorOpenCmd && in_decrease){
		if(bOpenDoorOk){
			SolTimer = iF_SolOnTime;	
		}

		if(SolTimer >= iF_SolOnTime){
			SolTimer = iF_SolOnTime;	
			bDoorOpenValid=1;
			OUT_BELL(0);
		}
		else{
			OUT_BELL(1);
			if(SolTimer > iF_DoorWaitTime){
				bDoorOpenValid=1;
			}
		}
	}
	else{
		OUT_BELL(0);
		SolTimer=0;
		bDoorOpenValid=0;
	}

	return(1);
}



unsigned int __attribute__((section(".usercode")))  DoorCloseTimeChk(void)
{
	if(!bDoorCloseCmd)		DoorCloseTime=0;
}



void __attribute__((section(".usercode")))  DoorOpenCloseSeq(void)
{			  
	LocalType TmpTime;



    if((sRamDArry[mDoorSeq] >= DOOR_CLOSE_START) && (sRamDArry[mDoorSeq] < READY_ELEVATOR) && !S2_FIRE1){
        CloseOutOffTime=0;
        DoorOpenTime=0;
    }
 

    if((sRamDArry[mDoorSeq] >= DOOR_OPEN_START) && (sRamDArry[mDoorSeq] < READY_ELEVATOR)){
		if(bFlrMatchChk || bEqualFloorError){
			bFlrMatchErr=1;
            bCarErr=1;
			FlrMatchInitChk();
		}
		else	bFlrMatchErr=0;	
    }


    if((sRamDArry[mDoorSeq] >= DOOR_OPEN_START) && (sRamDArry[mDoorSeq] <= READY_ELEVATOR)){		
		if(DoorOpenEndWaitChk()){
			if(sRamDArry[mDoorSeq] > DOOR_REOPEN_CHECK){   		
		  		sRamDArry[mDoorSeq]=DOOR_OPEN_START;
			}
		}
    }


    if(DoorjumperChkValid()){
	    if((sRamDArry[mDoorSeq] > DOOR_OPEN_START) && (sRamDArry[mDoorSeq] < READY_ELEVATOR) && ( !bDoorJumper)){
			if(sRamDArry[mDoorSeq] == DOOR_OPEN_WAIT){
				if(OneDoorSenserCloseChk())	bDoorJumper=1;	
			}
			else{
			    if((USE_CHECK == BAGGAGE_USE) || (USE_CHECK == CARLIFT_USE)){			
	        		if( (!IN_OP_E) && (CarDoorCloseEndCheckForDoorjmp()) ){
						DoorJumperNm=1;
						bDoorJumper=1;
					}
					if( (!IN_X7) && (HoleDoorCloseEndCheckForDoorjmp()) ){
						DoorJumperNm=(DoorJumperNm | 2);
						bDoorJumper=1;
					}					
			    }
			    else{
        			if(!IN_OP_E){
						if(OneDoorSenserCloseChk())	bDoorJumper=1;
					}
				}
			}

			if(bDoorJumper){		
				if(DoorJumperNm > 0)	DoorJumperNm=(DoorJumperNm-1);
			}
		}

		if(bDoorJumper){		
		  	sRamDArry[mDoorSeq]=DOOR_REOPEN_CHECK;
		}
	}



    switch(sRamDArry[mDoorSeq]){
        case    DOOR_OPEN_START:


			VirtualExtKeyClear();
            sRamDArry[mDoor]= (sRamDArry[mDoor] & MAIN_SUB_CLOSE_KEY_CLEAR);

			#ifdef	FLOOR_64
			#else
	        sRamDArry[mDoor] =(sRamDArry[mDoor] & ~UPDN_CAR_READY);
			#endif

            PositionOkChk();

            if(INVERTER_CHECK == IO){				
				SlipPulseCalu();
				CurPulse=FLOOR_COUNT(sRamDArry[mcurfloor]);
				Base_Slip_pulse=CurPulse;
            }


            sRamDArry[mEqualFloor] = 0x0;

            S3_UPDN_VO1=0;
			bDoorOpenEndFind=0;


			ThisFloorDoorCheck();


			if(bRunningOpenOn){			
                SelectDoorOpen_you();    
                sRamDArry[mDoorSeq] = DOOR_OPEN_CHECK;
                DoorOpenTime=0;
			}
			else if(S2_FIRE1 && (sRamDArry[mcurfloor] != FireBaseFloor) && (sRamDArry[mFireSeq] == FIRE_START) && bDoorCloseOk && !bSafeFire){	
                sRamDArry[mDoor]=0;
                sRamDArry[mDoorSeq] = READY_ELEVATOR;
            }
			else if(NoUseNoOpen() || S1_POWER_FAIL){			
				if(DoorOpenTime >= 5){
					SelectDoorOpen_you();
					if(bDoorOpenValid){    
						sRamDArry[mDoorSeq] = DOOR_OPEN_CHECK;
						DoorOpenTime=0;
					}
				}
            }
            else{             
                bSlipCheckStart=1;
                DoorOpenTime=0;
                bReOpen=0;
                bCarUpDnChButClr=0;
                sRamDArry[mDoorSeq] = DOOR_CLOSE_START;
            }                
            break;                                        
        case	DOOR_OPEN_CHECK:        
            bSlipCheckStart=1;
            SelectDoorOpen_you();    
			OpenKeyClear();

            if(bOpenDoorOk){
				bDoorOpenEndFind= 1;
                DoorOpenTime	= 0;

                if(USE_CHECK == MAN_USE){
	                if(bReOpen && !bDoorOpenHold){
	                    DoorOpenTime = cF_OPWTTM;    //car
	                }
	                else{
	                    DoorOpenTime = DEFAULT_REOPTM;    //hib
	                }
				}
                else{
                    DoorOpenTime = DEFAULT_REOPTM;    //hib
                }

                bReOpen=0;
                sRamDArry[mDoorSeq] = DOOR_OPEN_WAIT;
            }            		
            else if(DoorOpenTime > cF_OPTTTM){
                if(OpenTotalUseChk){
                    sRamDArry[mDoorSeq] = DOOR_OPEN_WAIT;            
                    DoorOpenTime = DEFAULT_REOPTM;   
                }
            }

/*
            if((DoorOpenTime > 60) && (bDoorCloseOk)){
                sRamDArry[mDoorSeq] = DOOR_OPEN_WAIT;            
   	            DoorOpenTime 	= cF_OPWTTM + DEFAULT_REOPTM;
            }
*/

            if(DoorOpenTime > 10){
                bCarUpDnChButClr=0;
            }
         		                              		         		         		
            break;                  		
		case	DOOR_OPEN_WAIT:    		      
            bDoorOpenEnd=1;
            bCarUpDnChButClr=0;
            OpenKeyClear();

			if(OpenOutSet){  
	            SelectDoorOpen_you();    
			}

			OutDateCheck();

			if(bDoorJumper==0){
				if(bDoorOpenHold)	TmpTime=(unsigned int)(cF_OPWTTM + DEFAULT_REOPTM + cF_REOPTM);
				else				TmpTime=(unsigned int)(cF_OPWTTM + DEFAULT_REOPTM);

				if(DoorOpenTime > TmpTime){
	                if(OpenWaitUseChk){    
	    				sRamDArry[mDoorSeq] = DOOR_REOPEN_CHECK;
						DoorOpenTime=0;   ///
	                }
				}
			}
            break;            
        case	DOOR_REOPEN_CHECK:     
			if(DoorOpenEndWaitChk()){
			   	bExtButClr=1;
			 	bCarButClr=1;
				ClrUpDnWard();

                SelectDoorOpen_you();    
                sRamDArry[mDoorSeq]=DOOR_REOPEN_CHECK; 

				if(OneEncoderBkErrChk()){
					bCarStopNoRun=1;				
				}		        						
            }
            else{         		
    
                if(S3_VIP1){
		            SelectDoorOpen_you();    
					DoorOpenTime=cF_OPWTTM+1;
                    UpDnRstCheck();            		
                }
	            else{
                    if(DoorOpenTime > DEFAULT_REOPTM){             ////
        		        sRamDArry[mDoorSeq] = DOOR_CLOSE_START;
                    }
                }                               
            }         			
            break;            
        case  DOOR_CLOSE_START:
			if(DoorOpenEndWaitChk()){
                sRamDArry[mDoorSeq]=DOOR_REOPEN_CHECK; 
			}
			else{
	            bDoorOpenEnd=0;
	            if(sRamDArry[mHighFloor] | sRamDArry[mLowFloor])	S3_UPDN_VO1=1;
				sRamDArry[mDoorSeq]=DOOR_CLOSE_CHECK;     
			}

            break;
        case  DOOR_CLOSE_CHECK:                  
			if(bDoorJumper == 0){

                SelectDoorClose_you();                      //4    	            		
    
                if(bDoorCloseOk){
                    sRamDArry[mDoorSeq]=DOOR_CLOSE_END;                                        
                    UpDnRstCheck();
 
					if(S3_VIP1){
						DoorCloseTime=0;
					}					

					#ifdef	TEST_SIMULATION
                        if(!IN_X5)	sRamDArry[mDoorSeq]=DOOR_OPEN_START; 
					#endif
           		
                }
         		      
                else if(DoorCloseTime > cF_OPTTTM){
    	        	if(CloseTotalUseChk){   
	                    if((USE_CHECK == BAGGAGE_USE) || (USE_CHECK == CARLIFT_USE)){
	                        bsCleNoOn=1;
	                    }
	                    else{
	                        bReOpen=1;
	                    }
	                    sRamDArry[mDoorSeq]=DOOR_OPEN_START; 
					}
                }

            }
			else{
	    		sRamDArry[mDoorSeq] = DOOR_REOPEN_CHECK;
			}
            break;               
        case  DOOR_CLOSE_END:  
            SelectDoorClose_you();   //5            
            if(bDoorCloseOk){
                if(DoorCloseTime > 5){
                    sRamDArry[mDoorSeq]=READY_ELEVATOR;  
					if( !bUpWard && !bDnWard){ 
						VirCarKeyClr();
						VirExtKeyClr();
					}
                }
            }               
            else{
                sRamDArry[mDoorSeq]=DOOR_CLOSE_CHECK;
            }            
            break;                
    }            
}





void __attribute__((section(".usercode")))  DoorOpClSystem(void)
{
	unsigned int pt;  

	unsigned long tmp_p;
/*
    if(bUnd && bDac){
        if((VoiceTime > cF_DIRTIME) &&  (sRamDArry[mDoorSeq] >= WAIT_NEXT_LULD)){
            if(cF_DIRTIME>0){
                CallMeUpDnDirectionSet();                                                                           
            }
        }
    }                
  
*/
                                                                         
    HighLowCallClear();
    UpDnDirectionSet();
    
    if(sRamDArry[mDoorSeq] <= READY_ELEVATOR){
        UpDnCallClear();           	
		AutoDoorSystem();   
    }
                         
	switch(sRamDArry[mDoorSeq]){

		case  READY_ELEVATOR:		


            UpDnStopCmd();

			#ifdef	FLOOR_64
			#else
			sRamDArry[mDoor] =( sRamDArry[mDoor] & ~UPDN_CAR_READY);
			#endif

            sRamDArry[mReqStopFloor]  = sRamDArry[mcurfloor];
        
            S2_FLOW1=0;
			bSaveErrCnt=0; 

            bCarUpDnChButClr=0;

            CloseOutOffTime=200;

			PositionOkChk();
			
////////////////////////////////////////////// SelectDoorClose_you();   //5                         	            		

			if(!bDoorCloseOk){
   				sRamDArry[mDoorSeq]=DOOR_CLOSE_START;         
			}
			else{
				if( !S2_FIRE1)	bReadyCall=1;

				CurDoorSelect=NO_DOOR;
				#ifdef	FLOOR_64
				if((sRamDArry[mNewAckStopFloor] > 0) && ((sRamDArry[mNewAckStopFloor] & ONLY_FLR) != sRamDArry[mcurfloor])){					
				#else
				if((sRamDArry[mNewAckStopFloor] & UPDN_CAR_READY) && ((sRamDArry[mNewAckStopFloor] & ONLY_FLR) != sRamDArry[mcurfloor])){					
				#endif
					sRamDArry[mAckStopFloor] = sRamDArry[mNewAckStopFloor];
                    if(!SpeedSet()){
        				LightTime=0;
						if(bPowerSaveMoveValid){
	    					sRamDArry[DEST_FLR] = sRamDArry[mNewAckStopFloor];
	        				OriginalHighFlr     = sRamDArry[mHighFloor];
	        				OriginalLowFlr      = sRamDArry[mLowFloor];
		    				sRamDArry[mNewAckStopFloor]=0; 
			    			sRamDArry[mCarMoveState]=0;
					    	bSlipCheckStart=0;
							bPowerChkStart=1;
	    					bSetSpeedOn=0;
	                        S3_UPDN_VO1=1; 	
		    				sRamDArry[mDoorSeq]=MOVE_ELEVATOR;
	                        sRamDArry[mReqStopFloor]  	= sRamDArry[mcurfloor];

							sRamDArry[mRunFloor]		= sRamDArry[mcurfloor];
							sRamDArry[mLuLdFloor]		= sRamDArry[mcurfloor];          		
						}
                    }
                    else{
    					sRamDArry[mAckStopFloor] = sRamDArry[mNewAckStopFloor] = 0;
                        sRamDArry[mHighFloor]    = sRamDArry[mLowFloor]        = 0; 
                    }
				}               
				else{
					FixFloorStartCheck();
					LoadCmdStartCheck();
				}
			}            

			if(!bOnLuLd){
		        LuLdTime=0;
				bFirstOnLuLd=0;

                if( (!IN_LU || !IN_LD) && bDoorCloseOk){
                    if(bManualAuto){
                        bManualAuto=0;
                        CarOnceStopTime=31;      

                      	if(!IN_LU && IN_LD)         bHomeUpDn = 1;
                      	else if(IN_LU && !IN_LD)    bHomeUpDn = 0;
                    }
                }
                else{
    				bCarErr=1;
                }
            }

            break;                

		case  MOVE_ELEVATOR:  
			AutoUpDownStart();         
			EncoderClear();
			bAutoRunningErr=1;
 			bReLoadEncoder=0;
			bReLoadEncoderExe=0;

#ifdef  TEST_SIMULATION  
            if(MotorMoveTime>10){
                sRamDArry[mDoorSeq]=WAIT_NEXT_LULD;         
                LuLdTime=0;
                bUpDnSet=0;
            }			   
#else
///////////////////if(!bOnLuLd){
	    	if(IN_LU && IN_LD){
				sRamDArry[mDoorSeq]=WAIT_NEXT_LULD;   
                bUpDnSet=0;
				LuLdTime=0;
			}			   
			else  if(NextFloorTime>cF_LULDOFFTIME){		
				bsLuLdNoOff=1;
				bCarErr=1;	
			}               
#endif
            break;                         
         case  WAIT_NEXT_LULD:
				#ifdef	FLOOR_64
    			if(((sRamDArry[mReqStopFloor] & ONLY_FLR) == (sRamDArry[mAckStopFloor] & ONLY_FLR))  && (sRamDArry[mReqStopFloor] & UPDN_READY)){
				#else
    			if(((sRamDArry[mReqStopFloor] & ONLY_FLR) == (sRamDArry[mAckStopFloor] & ONLY_FLR))  && (sRamDArry[mReqStopFloor] & CAR_READY)){
				#endif


                    bDac=1; 
    				if( (INVERTER_CHECK == LG) || (Old_Spd_SystemChk()) ){
					    OUT_DAC(1);
					}


#ifdef  TEST_SIMULATION  
					if(bDac && !bUnd){
						LuLdTime=0;
				        CarLowSpeedCmd_IO();
					}

            		if(bUnd && (LuLdTime > iF_RunOffTime)){
    	       	        sRamDArry[mDoorSeq]=STOP_ELEVATOR;
         	  	      	sRamDArry[mCarMoveState]=0;
						LuLdTime=0;
    				}
#else

					RunningOpenAction();

    				if(INVERTER_CHECK == IO){
	 					if( ((sRamDArry[mcurfloor] & ONLY_FLR) == (sRamDArry[mAckStopFloor] & ONLY_FLR)) && bUnd){

							if(AutoLandingModeChk((unsigned char)YASKAWA_AUTOLANDING)){
			 					if((sRamDArry[mcurfloor] & ONLY_FLR) != (sRamDArry[mAckStopFloor] & ONLY_FLR))	LuLdTime =0;  //xx							                                    
								if(bOnLuLd && !IN_FS4){	
			    	       	        sRamDArry[mDoorSeq]=STOP_ELEVATOR;
			         	  	      	sRamDArry[mCarMoveState]=0;			    				
								}
							}
							else{
								if(bOnLuLd){
									#ifdef	DELTA_INVERTER 					
										if(DeltaInverterZeroHzSet())	sRamDArry[mDoorSeq]=STOP_ELEVATOR;	
									#else				
										if( !StopPulseCheck()){
					    					sRamDArry[mDoorSeq]=STOP_ELEVATOR;
										}
									#endif
	
								}
	
	
								if(New_Spd_SystemChk()){
									if(bOneLuOrLd){
										tmp_p=(unsigned long)(cF_LULD_MPM_SPD3_10);
										if( (CurMeterPerMin > tmp_p) && (tmp_p > 0) && (tmp_p <= 255)){
							    			OUT_DAC(1);									
										}	
									}
								}
							}
						}
					}
					else{
	 					if((sRamDArry[mcurfloor] & ONLY_FLR) != (sRamDArry[mAckStopFloor] & ONLY_FLR))	LuLdTime =0;  //xx				
	                                    
	            		if(bUnd && (LuLdTime > iF_RunOffTime)){
	    	       	        sRamDArry[mDoorSeq]=STOP_ELEVATOR;
	         	  	      	sRamDArry[mCarMoveState]=0;
	    				}
					}


                    if(!bUnd){
        				NewFloorLoad();
    			        if((sRamDArry[mReqStopFloor] & ONLY_FLR) != (sRamDArry[mAckStopFloor] & ONLY_FLR)){
    						if( (INVERTER_CHECK == LG) || (Old_Spd_SystemChk()) ){
							    OUT_DAC(0);
							}
                            bDac=0;

                        }
                    }

#endif    

    			}
    			else if(bUnd){

					#ifdef	FLOOR_64
                    if(sRamDArry[mAckStopFloor] == 0){
    				    sRamDArry[mAckStopFloor] = ((sRamDArry[mReqStopFloor] & ONLY_FLR) | UP_READY);				
    				}
					#else
                    if(!(sRamDArry[mAckStopFloor] & UPDN_CAR_READY)){
    				    sRamDArry[mAckStopFloor] = ((sRamDArry[mReqStopFloor] & ONLY_FLR) | CAR_READY);				
    				}
					#endif


    				if( (INVERTER_CHECK == LG) || (Old_Spd_SystemChk()) ){
					    OUT_DAC(1);
					}

                    bDac=1;		
    			}			
                else{			       
    				if( (INVERTER_CHECK == LG) || (Old_Spd_SystemChk()) ){
					    OUT_DAC(0);
					}

                    bDac=0;		
					NewFloorLoad();                  
    			}	


    			if(IN_LU && IN_LD){
					bReLoadEncoder=0;
					bReLoadEncoderExe=0;
				}
				else if(bOnLuLd){
					if(!bReLoadEncoder){
						bReLoadEncoder=1;
			        	if( (INVERTER_CHECK == IO) && (EncoderCopyOnOff) && (!bUnd)){
							bReLoadEncoderExe=1;
						}	
	
						if(bCarUpMove){
							sRamDArry[mLuLdFloor]++;
						}
						else if(bCarDnMove){
							sRamDArry[mLuLdFloor]--;
						}		

					}
				}




/*
    			if(IN_LU && IN_LD){
					bReLoadEncoder=0;
					bReLoadEncoderExe=0;
				}
				else if(bOnLuLd){
					if(!bReLoadEncoder){
						bReLoadEncoder=1;
			        	if( (INVERTER_CHECK == IO) && (EncoderCopyOnOff) && (!bUnd)){
							bReLoadEncoderExe=1;
						}
		
						if(bCarUpMove){
							sRamDArry[mLuLdFloor]++;
						}
						else if(bCarDnMove){
							sRamDArry[mLuLdFloor]--;
						}		
					}

					if( (sRamDArry[mcurfloor] != sRamDArry[mLuLdFloor]) && (!bEqualFloorError)){
						bUnd=1;				         
						bEqualFloorError=1;         
						LuLdTime=0;
					}
				}

				if(bEqualFloorError){
					if(bUnd){
	            		if(LuLdTime > iF_RunOffTime){
	    	       	        sRamDArry[mDoorSeq]=STOP_ELEVATOR;
	         	  	      	sRamDArry[mCarMoveState]=0;
							LuLdTime=0;
	    				}
					}
					else	bUnd=1;	
				}

*/




/*
    			if(IN_LU && IN_LD)	bReLoadEncoder=0;
				else if(bOnLuLd && !bEqualFloorError){
					if(!bReLoadEncoder){
						bReLoadEncoder=1;
			        	if( (INVERTER_CHECK == IO) && (EncoderCopyOnOff)){
							if(!bUnd){
								bCalcuMpmOn=0;
								bReLoadEncoderExe=1;
								EncoderValueReload();						
								bReLoadEncoderExe=0;
							}
						}
		
						if(bCarUpMove){
							sRamDArry[mLuLdFloor]++;
						}
						else if(bCarDnMove){
							sRamDArry[mLuLdFloor]--;
						}		
					}

					if(sRamDArry[mcurfloor] != sRamDArry[mLuLdFloor]){
						bUnd=1;				         
						bEqualFloorError=1;         
						LuLdTime=0;
					}
				}
				else if(bEqualFloorError && bUnd){
            		if(LuLdTime > iF_RunOffTime){
    	       	        sRamDArry[mDoorSeq]=STOP_ELEVATOR;
         	  	      	sRamDArry[mCarMoveState]=0;
						LuLdTime=0;
    				}
				}
*/


				if( bCarUpMove && !IN_SU1 && (IN_LU && !IN_LD) ){
					bCarErr=1;
				}
				else if(bCarDnMove  && !IN_SD1 && (!IN_LU && IN_LD)){
					bCarErr=1;
				}
	

        		if(bUnd){				
	        		if((LuLdTime==0)){				
	                    UpDnCallClear();  
	                }
				}



   				if(INVERTER_CHECK == IO){
					if(AutoLandingModeChk((unsigned char)YASKAWA_AUTOLANDING)){
						if(!bOnLuLd && !IN_FS4){	
							bCarErr=1;
						}
					}
				}


				#ifdef	DELTA_INVERTER 					
					if(InverterPDORxTime > 50){
						if( (sRamDArry[mcurfloor] & ONLY_FLR) == (sRamDArry[mAckStopFloor] & ONLY_FLR)){
							if(bOnLuLd && (LuLdTime > iF_RunOffTime)){
								sRamDArry[mDoorSeq] = STOP_ELEVATOR;
							}
						}
					}
					else if( DeltaInverterZeroHzSet()){
						sRamDArry[mDoorSeq] = STOP_ELEVATOR;
/*
						if(sRamDArry[mDoorSeq] != STOP_ELEVATOR){
							bCarErr=1;
						}
*/

					}
				#endif

               break;                         
         	case  STOP_ELEVATOR:

				RunningOpenAction();            			


			    CarStopCmd();

				if(!bOnLuLd){
					bCarErr=1;	
				}	

                if(!bMoveCar){
					bAutoRunningErr=0;
					bFR2Start1=0;

            		sRamDArry[mCarMoveState]=0;

					if(CurPulse > LevelEncoderPulse1)	LevelEncoderPulse2=(unsigned int)(CurPulse - LevelEncoderPulse1);
					else							    LevelEncoderPulse2=(unsigned int)(LevelEncoderPulse1 - CurPulse);


                    bVoiceReady=0;   
                    OpenKeyCheck();


                    bDac=0;

				    DoorOpenTime = 0;

					#ifdef	FLOOR_64

					#else
	    				if(bUpWard && !(sRamDArry[mHighFloor] & UPDN_CAR_READY)){
	    				    bCarUpDnChButClr=1;	
	    			    }   		 
	    			    else if(bDnWard && !(sRamDArry[mLowFloor] & UPDN_CAR_READY)){
	      					bCarUpDnChButClr=1;	
	    			    }
					#endif   			


//fire modify

                    if(S2_FIRE1 && !bSafeFire){
                        KeyClr();
                        ClrUpDnWard();       
    				    bCarUpDnChButClr=0;	
					}


					if(!bRunningOpenOn && S2_FIRE1 && (sRamDArry[mcurfloor] != FireBaseFloor) && (sRamDArry[mFireSeq] == FIRE_START)  && !bSafeFire){	
                        sRamDArry[mDoor]=0;
                        sRamDArry[mDoorSeq] = READY_ELEVATOR;
                   	}
                   	else	if(!bRunningOpenOn && S2_FIRE1 && (sRamDArry[mFireSeq] == FIRE_TWO)  && !bSafeFire){
                        sRamDArry[mDoor]=0;
                        sRamDArry[mDoorSeq] = READY_ELEVATOR;
                        sRamDArry[mFireSeq] = FIRE_THREE;
                   	}
                   	else	if(!bRunningOpenOn && bWaterSensing){
                        sRamDArry[mDoor]=0;
                        sRamDArry[mDoorSeq] = READY_ELEVATOR;
                   	}
                    else{
						CurDoorSelect=NO_DOOR;
						KidsKeyCheck();
						sRamDArry[mDoorSeq] = DOOR_OPEN_START;
						TestArriveEncoderValueReload();

						if(sRamDArry[mVFlrCnt] > 0){
							if((sRamDArry[mVFlr1] == sRamDArry[S0_FLOOR]) || (sRamDArry[mVFlr2] == sRamDArry[S0_FLOOR])){

								#ifndef  KTL  
								sRamDArry[mVFlrCnt]--;
								#endif

								VirtualMoveCntReDsp();
							}				
						}
					}
                }
                break;         
             default:
               if(sRamDArry[mDoorSeq] > STOP_ELEVATOR){      
					bCarErr=1;
                  sRamDArry[mDoorSeq] = DOOR_CLOSE_START;                    
               }            
               break;                
   }
}



unsigned int  __attribute__((section(".usercode"))) TestUpDn(void)
{
	ManualUpDnKeyCheck();

#ifdef	FLOOR_64
   	if(bManualUpKey){
		if(sRamDArry[mcurfloor] < cF_TOPFLR){
			if(sRamDArry[mHighFloor] == 0x0){
				sRamDArry[mHighFloor] = cF_TOPFLR;
     	    	bTestKey=1;
			}     	    
		}         		
   	}              
    else if(bManualDnKey){
        if(sRamDArry[mcurfloor] > 0){
			if(sRamDArry[mLowFloor] == 0x0){
				sRamDArry[mLowFloor] = UP_READY;
     	    	bTestKey=1;
			}
		}         		
   	}        
   	else{
        if(bTestKey){   		
            sRamDArry[mLowFloor]  	= 0x0;
            sRamDArry[mHighFloor] 	= 0x0;
            sRamDArry[mEqualFloor]	= 0x0;
            bTestKey=0;		
		}
   	}
#else
   	if(bManualUpKey){
		if(sRamDArry[mcurfloor] < cF_TOPFLR){
			if(sRamDArry[mHighFloor] == 0x0){
				sRamDArry[mHighFloor] = (cF_TOPFLR | CAR_READY);
     	    	bTestKey=1;
			}     	    
		}         		
   	}              
    else if(bManualDnKey){
        if(sRamDArry[mcurfloor] > 0){
			if(sRamDArry[mLowFloor] == 0x0){
				sRamDArry[mLowFloor] = CAR_READY;
     	    	bTestKey=1;
			}
		}         		
   	}        
   	else{
        if(bTestKey){   		
            sRamDArry[mLowFloor]  = 0x0;
            sRamDArry[mHighFloor] = 0x0;
            sRamDArry[mEqualFloor]= 0x0;
            bTestKey=0;		
		}
   	}
#endif
	return(0);
}



unsigned int  __attribute__((section(".usercode"))) NotHomePositionChk(void)
{
	if(((sRamDArry[mcurfloor] == 0) && (IN_SD1)) || ((sRamDArry[mcurfloor] == cF_TOPFLR) && (IN_SU1)))	return(1);
	else	return(0);	
}



unsigned int  __attribute__((section(".usercode"))) RelevelStopChk(void)
{

    if(IN_LU && IN_LD){
		return(1);
	}

	if(NotHomePositionChk()){
		if( !OneEncoderBkErrChk()){
			return(1);			
		}
	}

    if(bOnLuLd){
		if( (CurMeterPerMin==0) || 	(bZeroHzSet) || (LuLdTime > iF_RunOffTime)){
			if(LuLdTime < iF_RunOffTime){
				LuLdTime = iF_RunOffTime;
			}
			bZeroHzSet=1;
			return(0); 
		}

		#ifndef	DELTA_INVERTER
		else{
			StopPulseCheck();
			if(bZeroHzSet)			return(0);
			else					return(1);
		}
		#endif
	}



    if( bCarUpMove && IN_LU && !IN_LD){
		if(!bFirstOnLuLd){
			if(LuLdTime < iF_RunOffTime){
				LuLdTime = iF_RunOffTime;
			}
			bFirstOnLuLd=1;
		}
		return(0);  // error stop
	}
    if( bCarDnMove && !IN_LU && IN_LD){
		if(!bFirstOnLuLd){
			if(LuLdTime < iF_RunOffTime){
				LuLdTime = iF_RunOffTime;
			}
			bFirstOnLuLd=1;
		}
		return(0);  // error stop
	}

	return(1);	// not stop		
}



void  __attribute__((section(".usercode"))) FindLuLdManual(void)
{

#ifdef  TEST_SIMULATION      
		sRamDArry[mCarMoveState]=0;
		bSearchHome=0;
		CarStopCmd();
		bManualUpKey=0;
		bManualDnKey=0;                  
		bManualAuto=1;

		sRamDArry[mDoorSeq] = DOOR_OPEN_START;      
		LuLdTime = (F_UDOffTime + F_RunOffTime);		
#else 


/////////	NextFloorTime=0;  

	EncoderClear();

    if( RelevelStopChk()== 0){
		bManualUpKey=0;
		bManualDnKey=0;

		if(bSearchHome){
			sRamDArry[mCarMoveState]=0;
			bSearchHome=0;
		}			
		CarStopCmd();		

		
		if(!bMoveCar){		
			if( !bOnceOpen){
				sRamDArry[mDoorSeq] = DOOR_OPEN_START;
				bOnceOpen=1;
			}

			if(!bLevelFind){
				ClrUpDnWard();
			}

			bManualAuto=1;
			bLevelFind=0;
            DoorOpenTime=0;
	    }
    }
    else{
        bAuto=0;        
        bSearchHome=1;
               
        bManualUpKey=0;
        bManualDnKey=0;

        if(!bHomeUpDn){
            bManualUpKey=0;
            bManualDnKey=1;
            ManualUpDown();
        }  
        else{
            bManualDnKey=0;
            bManualUpKey=1;
            ManualUpDown();               
        }
										                  
        bAuto=1;
    }
#endif
}      


unsigned int  __attribute__((section(".usercode"))) SlipCheck(void)
{
	unsigned long save_pulse;


	if(New_Law_SystemChk() && UcmpFeedBackChk){
		if(CurSelOutPortChk(cF_GBR) && !IN_WATER){
			UcmpOnOffChkTimer=0;				
		}
		else if( !CurSelOutPortChk(cF_GBR) && IN_WATER){
			UcmpOnOffChkTimer=0;				
		}
		else{
			if(UcmpOnOffChkTimer>5){
				NotRecoveryData=( NotRecoveryData | 0x04);
				bsUcmpFeedErr=1;
			}				
		}	
	}



	if(bsSlip || bsLope || bLope_Occur || bSlip_Occur){
		UpDnAllOff();
		bExtButClr=1;
		bCarButClr=1;
        bCarErr=1;
   
		if(bsLope || bLope_Occur){
			if(LopeTimer > SLIP_TIME){
				bsLope=1;
				bLope_Occur=0;					
        		bCarStopNoRun=1;
				if(New_Law_SystemChk()){
					NotRecoveryData=( NotRecoveryData | 0x01);
				}
			}
			else if(!IN_GR)	bLope_Occur=0;   // recovery lope break        
		}  
          
		if(bsSlip || bSlip_Occur){
		 	if(SlipTimer > SLIP_TIME){
				bsSlip=1;
				bSlip_Occur=0;
	        	bCarStopNoRun=1;
				if(New_Law_SystemChk()){
					NotRecoveryData=( NotRecoveryData | 0x02);
				}
			}
			else{
				if(New_Law_SystemChk()){
					if( !LuLdDzCheck() ){         	         	
						bSlip_Occur=0;
					}
				}
				else{
					if( !IN_LU || !IN_LD){         	         		        
						bSlip_Occur=0;
					}
				}
			}			           
		}




		if( !OilLopeTypeChk){					// oil type final err
			if(IN_AUTO){
				if(bsLope || bLope_Occur){
					LopeTimer=0;
				}
			}
		}

	
		return(0);
	}



 
	if(IN_GR)	bLope_Occur=1;
	if(IN_AUTO)	bSlipCheckStart=0;


	if( bSlipCheckStart && (OneDoorSenserNoCloseChk())){         
    	if(INVERTER_CHECK == IO){				
			save_pulse=CurPulse;	         
			if(Base_Slip_pulse > save_pulse){
				if( (Base_Slip_pulse - save_pulse) > Slip_pulse){
			        bsSlip=1; 
					SlipTimer=(SLIP_TIME+1);
				}
			}
			else{
				if( (save_pulse - Base_Slip_pulse) > Slip_pulse){
			        bsSlip=1; 
					SlipTimer=(SLIP_TIME+1);
				}
			}
		}



		if(New_Law_SystemChk()){
			if( LuLdDzCheck() ){         	         	
				bSlip_Occur=1;
			}
		}
		else{
			if(IN_LU && IN_LD){         	         		        
				bSlip_Occur=1;
			}
		}
	}




	if(bsSlip || bSlip_Occur || bsLope || bLope_Occur || bsUcmpFeedErr){
		UpDnAllOff();
		bExtButClr=1;
		bCarButClr=1;
		bCarErr=1;   
  		bSaveFlash=1;
	} 

	return(0);

}




unsigned int __attribute__((section(".usercode")))  NextFloorCheck(void)
{
	unsigned int ntime,TmpnextTime;

	if(!OilLopeTypeChk && (bsNextFloor || bsLuLdNoOff)){
		bCarErr=1;
		bCarStopNoRun=1;
		return(0);
	}



   if(sRamDArry[mBefcurfloor] != sRamDArry[mcurfloor]){
      NextFloorTime=0;  
      sRamDArry[mBefcurfloor] = sRamDArry[mcurfloor];
   }

	if( !bMoveCar || S1_POWER_FAIL)		NextFloorTime=0;


	ntime=(BASE_NEXT_FLR_TIME + (cF_NEXTFLRTIME * 10));


#ifndef  TEST_SIMULATION  
	TmpnextTime=NextFloorTime;

	if((TmpnextTime > ntime) && bMoveCar){
		UpDnAllOff();
		bsNextFloor=1;
		NotRecoveryData=(NotRecoveryData | 0x08);
		bCarErr=1;
	} 
	else if(ElevStopTime > 10){			// 10 sec
		if(Old_Law_SystemChk()){
			bsNextFloor=0;
		}
		bsLuLdNoOff=0;
	}
#endif

}









/*
*/

void  __attribute__((section(".usercode")))   AddressRead(void)
{

    MyGroupAddr=cF_GroupNm;
    MyLocalAddr=cF_LocalNm;
}











void __attribute__((section(".usercode")))  InPutRead(void)
{
    unsigned int i;

    LocalType tmp;


    OUT_ON=0;

    PORTD=0xffff;
    i=PORTD;
     
    tmp=(UserDataType)(i & 0x00ff);
    EmgByte=tmp;

	i=(i >> 8);
    tmp=(UserDataType)(i & 0x00ff);
    Su1Byte=tmp;


    tmp=0;
    if(PORTBbits.RB2)    tmp = tmp | 0x01;  //IN_RG
    if(PORTBbits.RB6)    tmp = tmp | 0x02;  //IN_BAT
    if(PORTBbits.RB7)    tmp = tmp | 0x04;  //IN_PASS
    if(PORTAbits.RA9)    tmp = tmp | 0x08;  //IN_FIRE
    if(PORTAbits.RA10)   tmp = tmp | 0x10;  //IN_WATER
    if(PORTAbits.RA14)   tmp = tmp | 0x20;  //IN_EX0
    if(PORTAbits.RA15)   tmp = tmp | 0x40;  //IN_EX1
    if(PORTFbits.RF6)    tmp = tmp | 0x80;  //IN_EX2

    GrByte=tmp;


	RD_WR=0;  

    IN_3=0;
    IN_3=0;
    IN_3=0;
    IN_3=0;



    i=PORTB; 
    tmp=(UserDataType)(i>>8);
    FireByte=tmp; 

    IN_3=1;


    IN_0=0;
    IN_0=0;
    IN_0=0;
    IN_0=0;

    i=PORTB;
    tmp=(UserDataType)(i>>8);
 
    if(INVERTER_CHECK == LG){
	    if(Bef_I_FS0 == tmp){
	        if(I_FS0_Cht >= 10){
	                I_FS0_bit = ~tmp;
	                Bef_I_FS0 = tmp;
	                I_FS0_Cht = 0;
	        }  
	    }
	    else{
	        I_FS0_Cht=0;
	        Bef_I_FS0=tmp;
	    }    
	}
	else{
		I_FS0_bit = tmp;
	}



    IN_0=1;
    IN_0=1;


    IN_1=0;
    IN_1=0;
    IN_1=0;
    IN_1=0;

    i=PORTB;
    tmp=(UserDataType)(i>>8);
    X0Byte=tmp;
  
    IN_1=1;



    if(INVERTER_CHECK != LG){

	    if(BEF_IN_FS0_IN == IN_FS0_IN){
	        if(Fs0Time>20){
	            IN_FS0_IN=BEF_IN_FS0_IN;
	            Fs0Time=0;
	        }
	    }
	    else{
	        BEF_IN_FS0_IN=IN_FS0_IN;
	        Fs0Time=0;
	    }    
	
	
	    if(BEF_IN_FS1_IN == IN_FS1_IN){
	        if(Fs1Time>20){
	            IN_FS1_IN=BEF_IN_FS1_IN;
	            Fs1Time=0;
	        }
	    }
	    else{
	        BEF_IN_FS1_IN=IN_FS1_IN;
	        Fs1Time=0;
	    }
	    
	    if(BEF_IN_FS2_IN == IN_FS2_IN){
	        if(Fs2Time>20){
	            IN_FS2_IN=BEF_IN_FS2_IN;
	            Fs2Time=0;
	        }
	    }
	    else{
	        BEF_IN_FS2_IN=IN_FS2_IN;
	        Fs2Time=0;
	    }    
	
	    if(BEF_IN_FS3_IN == IN_FS3_IN){
	        if(Fs3Time>20){
	            IN_FS3_IN=BEF_IN_FS3_IN;
	            Fs3Time=0;
	        }
	    }
	    else{
	        BEF_IN_FS3_IN=IN_FS3_IN;
	        Fs3Time=0;
	    }    
	
	    if(BEF_IN_FS4_IN == IN_FS4_IN){
	        if(Fs4Time>20){
	            IN_FS4_IN=BEF_IN_FS4_IN;
	            Fs4Time=0;
	        }
	    }
	    else{
	        BEF_IN_FS4_IN=IN_FS4_IN;
	        Fs4Time=0;
	    }    
	
	
	    if(BEF_IN_DER_IN == IN_DER_IN){
	        if(DerTime>20){
	            IN_DER_IN=BEF_IN_DER_IN;
	            DerTime=0;
	        }
	    }
	    else{
	        BEF_IN_DER_IN=IN_DER_IN;
	        DerTime=0;
	    }    
	
	
	    if(BEF_IN_FID_IN == IN_FID_IN){
	        if(FidTime>20){
	            IN_FID_IN=BEF_IN_FID_IN;
	            FidTime=0;
	        }
	    }
	    else{
	        BEF_IN_FID_IN=IN_FID_IN;
	        FidTime=0;
	    }    
	
	    if(BEF_IN_UND1_IN == IN_UND1_IN){
	        if(UndTime>20){
	            IN_UND1_IN=BEF_IN_UND1_IN;
	            UndTime=0;
	        }
	    }
	    else{
	        BEF_IN_UND1_IN=IN_UND1_IN;
	        UndTime=0;
	    }    
	}

//////////////////////
    if(BEF_IN_EMG_IN == IN_EMG_IN){
        if(EmgTime>20){
            IN_EMG_PORT=BEF_IN_EMG_IN;
            EmgTime=0;
        }
    }
    else{
        BEF_IN_EMG_IN=IN_EMG_IN;
        EmgTime=0;
    }    


    if(BEF_IN_PRK_IN == IN_PRK_IN){
        if(PrkTime>20){
            IN_PRK_PORT=BEF_IN_PRK_IN;
            PrkTime=0;
        }
    }
    else{
        BEF_IN_PRK_IN=IN_PRK_IN;
        PrkTime=0;
    }    


    if(BEF_IN_AUTO_IN == IN_AUTO_IN){
        if(AtTime>20){
            IN_AUTO_PORT=BEF_IN_AUTO_IN;
            AtTime=0;
        }
    }
    else{
        BEF_IN_AUTO_IN=IN_AUTO_IN;
        AtTime=0;
    }    


    if(BEF_IN_U_B_IN == IN_U_B_IN){
        if(UbTime>10){
            IN_U_B_PORT=BEF_IN_U_B_IN;
            UbTime=0;
        }
    }
    else{
        BEF_IN_U_B_IN=IN_U_B_IN;
        UbTime=0;
    }    


    if(BEF_IN_D_B_IN == IN_D_B_IN){
        if(DbTime>10){
            IN_D_B_PORT=BEF_IN_D_B_IN;
            DbTime=0;
        }
    }
    else{
        BEF_IN_D_B_IN=IN_D_B_IN;
        DbTime=0;
    }    



    if(BEF_IN_OP_E_IN == IN_OP_E_IN){
        if(OlsTime>10){
            IN_OP_E_PORT=BEF_IN_OP_E_IN;
            OlsTime=0;
        }
    }
    else{
        BEF_IN_OP_E_IN=IN_OP_E_IN;
        OlsTime=0;
    }    


    if(BEF_IN_CL_E_IN == IN_CL_E_IN){
        if(GsTime>10){
            IN_CL_E_PORT=BEF_IN_CL_E_IN;
            GsTime=0;
        }
    }
    else{
        BEF_IN_CL_E_IN=IN_CL_E_IN;
        GsTime=0;
    }    


    if(BEF_IN_HL_D_IN == IN_HL_D_IN){
        if(DsTime>10){
            IN_HL_D_PORT=BEF_IN_HL_D_IN;
            DsTime=0;
        }
    }
    else{
        BEF_IN_HL_D_IN=IN_HL_D_IN;
        DsTime=0;
    }    




//////////////////////

    if(BEF_IN_SU1_IN == IN_SU1_IN){
        if(Su1Time>30){
            IN_SU1_PORT=BEF_IN_SU1_IN;
            Su1Time=0;
        }
    }
    else{
        BEF_IN_SU1_IN=IN_SU1_IN;
        Su1Time=0;
    }    


    if(BEF_IN_SD1_IN == IN_SD1_IN){
        if(Sd1Time>30){
            IN_SD1_PORT=BEF_IN_SD1_IN;
            Sd1Time=0;
        }
    }
    else{
        BEF_IN_SD1_IN=IN_SD1_IN;
        Sd1Time=0;
    }    




    if(BEF_IN_SFT_IN == IN_SFT_IN){
        if(SftTime>10){
            IN_SFT_PORT=BEF_IN_SFT_IN;
            SftTime=0;
        }
    }
    else{
        BEF_IN_SFT_IN=IN_SFT_IN;
        SftTime=0;
    }    




    if(BEF_IN_OVL_IN == IN_OVL_IN){
        if(OvlTime>20){
            IN_OVL_PORT=BEF_IN_OVL_IN;
            OvlTime=0;
        }
    }
    else{
        BEF_IN_OVL_IN=IN_OVL_IN;
        OvlTime=0;
    }    



    if(BEF_IN_ULS_IN == IN_ULS_IN){
        if(UlsTime>10){
            IN_ULS_PORT=BEF_IN_ULS_IN;
            UlsTime=0;
        }
    }
    else{
        BEF_IN_ULS_IN=IN_ULS_IN;
        UlsTime=0;
    }    


    if(BEF_IN_DLS_IN == IN_DLS_IN){
        if(DlsTime>10){
            IN_DLS_PORT=BEF_IN_DLS_IN;
            DlsTime=0;
        }
    }
    else{
        BEF_IN_DLS_IN=IN_DLS_IN;
        DlsTime=0;
    }    


    if(BEF_IN_LU_IN == IN_LU_IN){
        if(LuTime>=10){
            IN_LU_PORT=BEF_IN_LU_IN;
            LuTime=0;
        }
    }
    else{
        BEF_IN_LU_IN=IN_LU_IN;
        LuTime=0;
    }    


    if(BEF_IN_LD_IN == IN_LD_IN){
        if(LdTime>=10){
            IN_LD_PORT=BEF_IN_LD_IN;
            LdTime=0;
        }
    }
    else{
        BEF_IN_LD_IN=IN_LD_IN;
        LdTime=0;
    }    

//////////////////////


    if(BEF_IN_GR_IN == IN_GR_IN){
        if(RgTime>20){
            IN_GR_PORT=BEF_IN_GR_IN;
            RgTime=0;
        }
    }
    else{
        BEF_IN_GR_IN=IN_GR_IN;
        RgTime=0;
    }    



    if(BEF_IN_BAT_IN == IN_BAT_IN){
        if(BatTime>10){
            IN_BAT_PORT=BEF_IN_BAT_IN;
            BatTime=0;
        }
    }
    else{
        BEF_IN_BAT_IN=IN_BAT_IN;
        BatTime=0;
    }    



    if(BEF_IN_PASS_IN == IN_PASS_IN){
        if(PassTime>20){
            IN_PASS_PORT=BEF_IN_PASS_IN;
            PassTime=0;
        }
    }
    else{
        BEF_IN_PASS_IN=IN_PASS_IN;
        PassTime=0;
    }    


    if(BEF_IN_FIRE_IN == IN_FIRE_IN){
        if(FireTime>20){
            IN_FIRE_PORT=BEF_IN_FIRE_IN;
            FireTime=0;
        }
    }
    else{
        BEF_IN_FIRE_IN=IN_FIRE_IN;
        FireTime=0;
    }    


    if(BEF_IN_WATER_IN == IN_WATER_IN){
        if(WaterTime>20){
            IN_WATER_PORT=BEF_IN_WATER_IN;
            WaterTime=0;
        }
    }
    else{
        BEF_IN_WATER_IN=IN_WATER_IN;
        WaterTime=0;
    }    



    if(BEF_IN_FULL_IN == IN_FULL_IN){
        if(FullTime>20){
            IN_FULL_PORT=BEF_IN_FULL_IN;
            FullTime=0;
        }
    }
    else{
        BEF_IN_FULL_IN=IN_FULL_IN;
        FullTime=0;
    }    


    if(BEF_IN_MM_IN == IN_MM_IN){
        if(MmTime>10){
            IN_MM_PORT=BEF_IN_MM_IN;
            MmTime=0;
        }
    }
    else{
        BEF_IN_MM_IN=IN_MM_IN;
        MmTime=0;
    }    



    if(BEF_IN_FHM_IN == IN_FHM_IN){
        if(FhmInTime>20){
            IN_FHM_PORT=BEF_IN_FHM_IN;
            FhmInTime=0;
        }
    }
    else{
        BEF_IN_FHM_IN=IN_FHM_IN;
        FhmInTime=0;
    }    

//////////////////////


    if(BEF_IN_FR1_IN == IN_FR1_IN){
        if(Fr1Time>20){
            IN_FR1_PORT=BEF_IN_FR1_IN;
            Fr1Time=0;
        }
    }
    else{
        BEF_IN_FR1_IN=IN_FR1_IN;
        Fr1Time=0;
    }    

    if(BEF_IN_FR2_IN == IN_FR2_IN){
        if(Fr2Time>20){
            IN_FR2_PORT=BEF_IN_FR2_IN;
            Fr2Time=0;
        }
    }
    else{
        BEF_IN_FR2_IN=IN_FR2_IN;
        Fr2Time=0;
    }    



    if(BEF_IN_GS2_IN == IN_GS2_IN){
        if(Gs2Time>20){
            IN_GS2_PORT=BEF_IN_GS2_IN;
            Gs2Time=0;
        }
    }
    else{
        BEF_IN_GS2_IN=IN_GS2_IN;
        Gs2Time=0;
    }    


    if(BEF_IN_DS2_IN == IN_DS2_IN){
        if(Ds2Time>20){
            IN_DS2_PORT=BEF_IN_DS2_IN;
            Ds2Time=0;
        }
    }
    else{
        BEF_IN_DS2_IN=IN_DS2_IN;
        Ds2Time=0;
    }


    
    if(BEF_IN_SU2_IN == IN_SU2_IN){
        if(Su2Time>10){
            IN_SU2_PORT=BEF_IN_SU2_IN;
            Su2Time=0;
        }
    }
    else{
        BEF_IN_SU2_IN=IN_SU2_IN;
        Su2Time=0;
    }    

    if(BEF_IN_SD2_IN == IN_SD2_IN){
        if(Sd2Time>10){
            IN_SD2_PORT=BEF_IN_SD2_IN;
            Sd2Time=0;
        }
    }
    else{
        BEF_IN_SD2_IN=IN_SD2_IN;
        Sd2Time=0;
    }    



    if(BEF_IN_BM_IN == IN_BM_IN){
        if(BmTime>10){
            IN_BM_PORT=BEF_IN_BM_IN;
            BmTime=0;
        }
    }
    else{
        BEF_IN_BM_IN=IN_BM_IN;
        BmTime=0;
    }    


    if(BEF_IN_INV_IN == IN_INV_IN){
        if(InvTime>10){
            IN_INV_PORT=BEF_IN_INV_IN;
            InvTime=0;
        }
    }
    else{
        BEF_IN_INV_IN=IN_INV_IN;
        InvTime=0;
    }    


    if(cF_PcbType == 1){
        IN_SU2_PORT =1;
        IN_SD2_PORT =1;
        IN_BM_PORT  =1;
        IN_INV_PORT =1;
    }


    if(BEF_IN_X0_IN == IN_X0_IN){
        if(X0Time>10){
            IN_X0_PORT=BEF_IN_X0_IN;
            X0Time=0;
        }
    }
    else{
        BEF_IN_X0_IN=IN_X0_IN;
        X0Time=0;
    }    

    if(BEF_IN_X1_IN == IN_X1_IN){
        if(X1Time>10){
            IN_X1_PORT=BEF_IN_X1_IN;
            X1Time=0;
        }
    }
    else{
        BEF_IN_X1_IN=IN_X1_IN;
        X1Time=0;
    }    


    if(BEF_IN_X2_IN == IN_X2_IN){
        if(X2Time>10){
            IN_X2_PORT=BEF_IN_X2_IN;
            X2Time=0;
        }
    }
    else{
        BEF_IN_X2_IN=IN_X2_IN;
        X2Time=0;
    }    
    if(BEF_IN_X3_IN == IN_X3_IN){
        if(X3Time>10){
            IN_X3_PORT=BEF_IN_X3_IN;
            X3Time=0;
        }
    }
    else{
        BEF_IN_X3_IN=IN_X3_IN;
        X3Time=0;
    }    


    if(BEF_IN_X4_IN == IN_X4_IN){
        if(X4Time>10){
            IN_X4_PORT=BEF_IN_X4_IN;
            X4Time=0;
        }
    }
    else{
        BEF_IN_X4_IN=IN_X4_IN;
        X4Time=0;
    }    

    if(BEF_IN_X5_IN == IN_X5_IN){
        if(X5Time>10){
            IN_X5_PORT=BEF_IN_X5_IN;
            X5Time=0;
        }
    }
    else{
        BEF_IN_X5_IN=IN_X5_IN;
        X5Time=0;
    }    

    if(BEF_IN_X6_IN == IN_X6_IN){
        if(X6Time>10){
            IN_X6_PORT=BEF_IN_X6_IN;
            X6Time=0;
        }
    }
    else{
        BEF_IN_X6_IN=IN_X6_IN;
        X6Time=0;
    }    

    if(BEF_IN_X7_IN == IN_X7_IN){
        if(X7Time>10){
            IN_X7_PORT=BEF_IN_X7_IN;
            X7Time=0;
        }
    }
    else{
        BEF_IN_X7_IN=IN_X7_IN;
        X7Time=0;
    }    

///#endif


	if(ExIOTimer > 30)	sRamDArry[mExtIN0]= 0xff;

///OLD VERSION
    OldFireBuf = 0x00;

    if((I_GR_bit   & 0x01))  OldFireBuf=(OldFireBuf | 0x01);
    if((I_FIRE_bit & 0x01))  OldFireBuf=(OldFireBuf | 0x02);
    if((I_FIRE_bit & 0x02))  OldFireBuf=(OldFireBuf | 0x20);
    if((I_FIRE_bit & 0x04))  OldFireBuf=(OldFireBuf | 0x40);
    if((I_FIRE_bit & 0x08))  OldFireBuf=(OldFireBuf | 0x80);

    OldFireBuf=(OldFireBuf | 0x04);
///OLD VERSION

    sRamDArry[I_EMG]  = I_EMG_bit;
    sRamDArry[I_SU1]  = I_SU1_bit;
    sRamDArry[I_GR]   = I_GR_bit;
    sRamDArry[I_FIRE] = I_FIRE_bit;
    sRamDArry[I_X_0]  = I_X0_bit;
    sRamDArry[I_FS0]  = I_FS0_bit;
}




unsigned int  __attribute__((section(".usercode")))  UserLampSetCheck(unsigned int val)
{
	unsigned int i;

	i=0;

   	switch(val){
      	case  0:
         		if(bAuto)           i=1;
         		break;
      	case  1:
         		if(!bAuto)          i=1;
         		break;
      	case  2:
         		if(S1_OVERLOAD1)    i=1;
         		break;
      	case  3:
         		if(S2_FIRE1)        i=1;
         		break;
      	case  4:
         		if(S1_EMG1)         i=1;
         		break;
      	case  5:
         		if(S3_PARKING1)     i=1;
         		break;
      	case  6:
         		if(S3_VIP1)         i=1;
         		break;
      	case  7:
                if( AutoRunReady() && (sRamDArry[mDoorSeq] != READY_ELEVATOR))  i=1;
         		break;
      	case  8:
         		if(S3_FULL1)     	i=1;
         		break;
      	case  9:
				if(bDspClr)	i=1;
         		break;
      	default:
         		i=0;     
         		break;
   	}

	return(i);
}


void  __attribute__((section(".usercode")))  	UserLampSet(void)
{
	unsigned int i;
	
 	i=UserLampSetCheck((unsigned int)(cF_USERLAMP1));
	if(i)	S2_LAMP_USER1=1; 	
	else	S2_LAMP_USER1=0; 	

 	i=UserLampSetCheck((unsigned int)(cF_USERLAMP2));
	if(i)	S1_MANUAL1=1; 	
	else	S1_MANUAL1=0; 	

 	i=UserLampSetCheck((unsigned int)(cF_USERLAMP3));
	if(i)	S4_USERLAMP3=1; 	
	else	S4_USERLAMP3=0; 	

	i=UserLampSetCheck((unsigned int)(cF_USERLAMP4));
	if(i)	S4_USERLAMP4=1; 	
	else	S4_USERLAMP4=0; 	
}




void  __attribute__((section(".usercode")))   VoiceStart(void)
{
    LocalType voice_start,bell_start;

    LocalType in_decrease,in_closeend; 
		

    voice_start=1;
	bell_start=1;

    if(bAuto && bUnd){
//        if((sRamDArry[mDoorSeq] >= WAIT_NEXT_LULD) && (VoiceTime > cF_VOICETIME) ){
        if((sRamDArry[mDoorSeq] >= WAIT_NEXT_LULD)){
            if((sRamDArry[DEST_FLR] & ONLY_FLR) == (sRamDArry[mcurfloor] & ONLY_FLR)){
                if((cF_VOICETIME > 0) && (VoiceTime < (cF_VOICETIME + 10)) && (VoiceTime > cF_VOICETIME)){
                    voice_start=0;                
                }

                if(BellTime < 10){
                    bell_start=0;                
                }
            }
			else{
				BellTime=0;
				VoiceTime=0;
			}
        }
    }

	
    if(!voice_start){
        S2_FLOW1=1;	
    }       		
    else{
        S2_FLOW1=0;	
    }

	if( !bSolControl){
    	if(!bell_start)		OUT_BELL(1);
		else				OUT_BELL(0);
    }       		
}






void  __attribute__((section(".usercode"))) 	ServiceCheck(void)
{
	unsigned int i,j,bit_val;


	sRamDArry[FLR_ON_OFF0] =(ShadowsRamDArry[FLR_ON_OFF0] & BaggageFlrOnOff[0] & cF_NONSERVICE0);
	sRamDArry[FLR_ON_OFF1] =(ShadowsRamDArry[FLR_ON_OFF1] & BaggageFlrOnOff[1] & cF_NONSERVICE1);
	sRamDArry[FLR_ON_OFF2] =(ShadowsRamDArry[FLR_ON_OFF2] & BaggageFlrOnOff[2] & cF_NONSERVICE2);
	sRamDArry[FLR_ON_OFF3] =(ShadowsRamDArry[FLR_ON_OFF3] & BaggageFlrOnOff[3] & cF_NONSERVICE3);	
	sRamDArry[FLR_ON_OFF4] =(ShadowsRamDArry[FLR_ON_OFF4] & BaggageFlrOnOff[4] & cF_NONSERVICE4);
	sRamDArry[FLR_ON_OFF5] =(ShadowsRamDArry[FLR_ON_OFF5] & BaggageFlrOnOff[5] & cF_NONSERVICE5);
	sRamDArry[FLR_ON_OFF6] =(ShadowsRamDArry[FLR_ON_OFF6] & BaggageFlrOnOff[6] & cF_NONSERVICE6);
	sRamDArry[FLR_ON_OFF7] =(ShadowsRamDArry[FLR_ON_OFF7] & BaggageFlrOnOff[7] & cF_NONSERVICE7);		
	

	if((sRamDArry[mVFlr1] != sRamDArry[mVFlr2]) && (sRamDArry[mVFlrCnt] > 0)){
		if((sRamDArry[mVFlr1] > 0) && (sRamDArry[mVFlr2] > 0)){
			if((cF_FLRDSPCH(0) == 'Z') && (cF_FLRDSPCH(1) == 'Z')){		
				AccTimer=0;
				sRamDArry[FLR_ON_OFF0]=0x0;	
				sRamDArry[FLR_ON_OFF1]=0x0;	
				sRamDArry[FLR_ON_OFF2]=0x0;	
				sRamDArry[FLR_ON_OFF3]=0x0;
				sRamDArry[FLR_ON_OFF4]=0x0;	
				sRamDArry[FLR_ON_OFF5]=0x0;	
				sRamDArry[FLR_ON_OFF6]=0x0;	
				sRamDArry[FLR_ON_OFF7]=0x0;
			}
		}	
	}

/*
	sRamDArry[FLR_ON_OFF0] =(sRamDArry[ExtCmdFlrONOFF0] & BaggageFlrOnOff[0]);
	sRamDArry[FLR_ON_OFF1] =(sRamDArry[ExtCmdFlrONOFF1] & BaggageFlrOnOff[1]);
	sRamDArry[FLR_ON_OFF2] =(sRamDArry[ExtCmdFlrONOFF2] & BaggageFlrOnOff[2]);
	sRamDArry[FLR_ON_OFF3] =(sRamDArry[ExtCmdFlrONOFF3] & BaggageFlrOnOff[3]);	
	sRamDArry[FLR_ON_OFF4] =(sRamDArry[ExtCmdFlrONOFF4] & BaggageFlrOnOff[4]);
	sRamDArry[FLR_ON_OFF5] =(sRamDArry[ExtCmdFlrONOFF5] & BaggageFlrOnOff[5]);
	sRamDArry[FLR_ON_OFF6] =(sRamDArry[ExtCmdFlrONOFF6] & BaggageFlrOnOff[6]);
	sRamDArry[FLR_ON_OFF7] =(sRamDArry[ExtCmdFlrONOFF7] & BaggageFlrOnOff[7]);		
	

	if((sRamDArry[mVFlr1] != sRamDArry[mVFlr2]) && (sRamDArry[mVFlrCnt] > 0)){
		if((sRamDArry[mVFlr1] > 0) && (sRamDArry[mVFlr2] > 0)){
			if((cF_FLRDSPCH(0) == 'Z') && (cF_FLRDSPCH(1) == 'Z')){		
				AccTimer=0;
				sRamDArry[FLR_ON_OFF0]=0x0;	
				sRamDArry[FLR_ON_OFF1]=0x0;	
				sRamDArry[FLR_ON_OFF2]=0x0;	
				sRamDArry[FLR_ON_OFF3]=0x0;
				sRamDArry[FLR_ON_OFF4]=0x0;	
				sRamDArry[FLR_ON_OFF5]=0x0;	
				sRamDArry[FLR_ON_OFF6]=0x0;	
				sRamDArry[FLR_ON_OFF7]=0x0;
			}
		}	
	}
*/






/*
    if( (!IN_PASS) && AutoRunReady()){
		AccTimer=0;
		sRamDArry[FLR_ON_OFF0]=0x0;	
		sRamDArry[FLR_ON_OFF1]=0x0;	
		sRamDArry[FLR_ON_OFF2]=0x0;	
		sRamDArry[FLR_ON_OFF3]=0x0;

		i=(cF_TOPFLR%8);
		j=(cF_TOPFLR/8);
		bit_val=0x01;
		bit_val=(bit_val << i);
		
		sRamDArry[(FLR_ON_OFF0+j)]=(sRamDArry[(FLR_ON_OFF0+j)] | bit_val);
		sRamDArry[FLR_ON_OFF0]=(sRamDArry[FLR_ON_OFF0] | 0x01);		
	}
*/


//fire modify
	if(S2_FIRE1){
		sRamDArry[FLR_ON_OFF0] = 0xff;
		sRamDArry[FLR_ON_OFF1] = 0xff;
		sRamDArry[FLR_ON_OFF2] = 0xff;
		sRamDArry[FLR_ON_OFF3] = 0xff;		
		sRamDArry[FLR_ON_OFF4] = 0xff;
		sRamDArry[FLR_ON_OFF5] = 0xff;
		sRamDArry[FLR_ON_OFF6] = 0xff;
		sRamDArry[FLR_ON_OFF7] = 0xff;
	}		
}








void  __attribute__((section(".usercode")))  InitialInPortChk(void)
{

	bInPortErr=0;
    if(WarmingUpTime < 15){
        if(!IN_U_B || !IN_D_B ){
            if(WarmingUpTime >= 8) WarmingUpTime=8;
			bInPortErr=1;
            bCarErr=1;
        }
    }
    
}


void  __attribute__((section(".usercode")))  AllReadyCheck(void)
{
    LocalType readygood;

    readygood=1;

    if(!AutoRunReady())                         readygood=0;                                                             
    if(!bDoorCloseOk)                           readygood=0;
    if(sRamDArry[mDoorSeq] != READY_ELEVATOR)   readygood=0;


    if(readygood==0){
        MinuteTime=0;        
        FixFlrTimeCnt=0;
        LightTime=0;
    }

//////////////////////////////////////
    if(ElevStopTime>10){
        bCarUpDnChButClr=0;
    }

}


void  __attribute__((section(".usercode")))  FanOnOff(void)
{
    if(bCarUpMove || bCarDnMove || !bDoorCloseOk){
        OUT_FAN(1);
        FanTime=0;  
    }   
    else if(FanTime > cF_FANTIME){
        FanTime = cF_FANTIME +1;              
        OUT_FAN(0);
    }
}



unsigned int   __attribute__((section(".usercode")))  Old_Law_FireBuzChk(void) 
{
	if(Old_Law_SystemChk()){
		if(bFirstFire && S2_FIRE1 && bSecondFire && (sRamDArry[mFireSeq] == FIRE_ONE))	return(1);              
	}
	return(0);
}


unsigned int   __attribute__((section(".usercode")))  BuzOnOff(void)    // new law
{

	OUT_SLOW_DOOR(0);

	if(bDoorCloseOk || IN_AUTO || S3_PARKING1 || Old_Law_SystemChk() || bFireFlrOn || !PerfectAuto()){
		bDoorSlowExe=0;
		FiremanTimer =0;
	}


    OUT_BUZ(0);
    
	if(New_Law_SystemChk()){
		if(IN_AUTO && (!IN_FIRE || bExt_FIRE || bSlaveFire || bExt_Second_FIRE)){
        	OUT_BUZ(1);         
		}
	    if(IN_AUTO && ( !IN_U_B || !IN_D_B)){
	        OUT_BUZ(1);         
	    }

		if( (FiremanTimer >= 120) && S2_FIRE1 && !bFireFlrOn){
			bDoorSlowExe=1;
 			if(!bMoveCar)	OUT_BUZ(1);
		}


		if(bDoorSlowExe){	
			if((CurSelOutPortChk(cF_CL)) || CurSelOutPortChk(cF_CL_S)  || CurSelOutPortChk(cF_HCL)){
				OUT_SLOW_DOOR(1);	
			}
		}
	}
	else{
		if(bOldFireBuz)	OUT_BUZ(1);         
	}


	if(bAuto){
		if(S1_OVERLOAD1)								OUT_BUZ(1);

		if(USE_CHECK == BAGGAGE_USE){
			if(bOnLuLd && !bMoveCar && SafetyChk()){              
				OUT_BUZ(1);          
			}
			else if(bOnLuLd && !bMoveCar && (TmpBuzor < 10)){              
				OUT_BUZ(1);          
			}
		}
		else if(USE_CHECK == CARLIFT_USE){
			if(SafetyChk()){              
				OUT_BUZ(1);          
			}
		}
	}

    return(0);
}




void  __attribute__((section(".usercode")))  EtcStopSet(void)
{
    S3_STOP1=0;    

	if(!IN_AUTO && !bMoveCar){
//		if( (sRamDArry[mDoor] & 0x10))			S3_STOP1=1;
		if(bDoorOpenHold && (cF_REOPTM > 300))	S3_STOP1=1;
		if(DoorOpenEndWaitChk())				S3_STOP1=1;

		if(ManWorkingSeq >= 1)					S3_STOP1=1;
	}


    if(sRamDArry[mDoorSeq] >= READY_ELEVATOR)	sRamDArry[mDoor]= (sRamDArry[mDoor] & 0xef);
    if( !AutoRunReady())    					sRamDArry[mDoor]= (sRamDArry[mDoor] & 0xef); 
}



void  __attribute__((section(".usercode")))  WaitAndNotMoveChk(void)
{
    if(WarmingUpTime < 15){
        bCarErr=1;
        CurFTime=0;
        NextFTime=0;
    }
}





unsigned int  __attribute__((section(".usercode")))  CheckStartBreakMgt(void)
{
    if(INVERTER_CHECK == D_F){
		if( (CurSelOutPortChk(cF_UP)) && CurSelOutPortChk(cF_BK1)){
			if(!bBK1){
				BreakTime=0;
				bBK1=1;
			}

            if(bVoiceReady)	BreakTime=0;	   

			return(1);
		}
		else if( !CurSelOutPortChk(cF_UP) && !CurSelOutPortChk(cF_BK1)){
			if(bBK1){
				BreakTime=0;
				bBK1=0;
			}
			return(1);
		}
		else{
			BreakTime=0;
			return(0);
		}
	}
	else{
		if( (CurSelOutPortChk(cF_UP) || CurSelOutPortChk(cF_DN)) && CurSelOutPortChk(cF_BK1)){
			if(!bBK1){
				BreakTime=0;
				bBK1=1;
			}

            if(bVoiceReady)	BreakTime=0;	   

			return(1);
		}
		else if( !CurSelOutPortChk(cF_UP) &&  !CurSelOutPortChk(cF_DN) && !CurSelOutPortChk(cF_BK1)){
			if(bBK1){
				BreakTime=0;
				bBK1=0;
			}
			return(1);
		}
		else{
			BreakTime=0;
			return(0);
		}
	}
}




unsigned int  __attribute__((section(".usercode")))  BreakMgtOpenCheck(void)
{
	unsigned int rdy;

	#ifdef	TEST_SIMULATION	
		return(0);
	#else

		if(bsBreakMgtOpen)	return(0);


		rdy=CheckStartBreakMgt();
		if(rdy == 0){
			return(0);
		}
	

		if(!BrkMgtUseChk){
	        bsBreakMgtOpen=0;
			return(0);
		}


		if(bBK1){
    		if(BreakTime > cF_BRK_MGT_TIME){
				if(IN_MM){
	            	bsBreakMgtOpen=1;
				}            
			 } 
		}
		else{
    		if(BreakTime > cF_BRK_MGT_TIME){
				if(!IN_MM){
	            	bsBreakMgtOpen=1;
				}            
			 } 
		}
		
		if(bsBreakMgtOpen){
			bCarErr=1;
		}

	#endif

	return(0);

}


unsigned int    __attribute__((section(".usercode")))  BreakOpenCheck(void)
{
	unsigned int rdy;

	#ifdef	TEST_SIMULATION	
		return(0);
	#else

	    if(bsBreakOpen)	return(0);


		rdy=CheckStartBreakMgt();
		if(rdy == 0){
			return(0);
		}

		if(!BrkOpenUseChk){
	        bsBreakOpen=0;
			return(0);
		}


		if(New_Law_SystemChk()){
			if(bBK1){
	    		if(BreakTime > cF_BRK_MGT_TIME){
					if((IN_GS2 || IN_DS2)){
		            	bsBreakOpen=1;
					}            
				 } 
			}
			else{
	    		if(BreakTime > cF_BRK_MGT_TIME){
					if((!IN_GS2 || !IN_DS2)){
		            	bsBreakOpen=1; 
					}           
				 } 
			}
		}
		else{
			if(bBK1){
	    		if(BreakTime > cF_BRK_MGT_TIME){
					if(IN_BM){
		            	bsBreakOpen=1; 
					}           
				 } 
			}	
			else{
	    		if(BreakTime > cF_BRK_MGT_TIME){
					if(!IN_BM){
		            	bsBreakOpen=1;
					}            
				 } 
			}		
		}

		if(bsBreakOpen){
			bCarErr=1;
		}

	#endif

	return(0);

}




unsigned int  __attribute__((section(".usercode")))   HuntingChk(void)
{

    if(INVERTER_CHECK != D_F){
		HuntingCnter=0;
		return(0);
	}                                          
    if(!bAuto){
		HuntingCnter=0;
		return(0);
	}

    if(!bManualAuto){
		HuntingCnter=0;
		return(0);
	}

	if(bsBreakMgtOpen)	return(0);



	if(bBef_IN_MM == IN_MM){
		if(	HuntingTimer > 30){
			HuntingCnter=0;
		}
	}
	else{
		if(HuntingCnter > 10){
	        bsBreakMgtOpen=1;
			bCarErr=1;
		}	
		HuntingTimer=0;
		HuntingCnter++;
		bBef_IN_MM = IN_MM;
	}
	return(0);
}





void  __attribute__((section(".usercode")))   InvErrChk(void)
{

    LocalType rst;

    if( (OilLopeTypeChk) && (bPowerSaveMoveValid)){
        if(!IN_INV){
			bCarErr=1;
			bsInvertErr=1;
		}
		else{
			bsInvertErr=0;
		}
    }
    else{
        bsInvertErr=0;
        bInvErrCnt=0;
        InvErrTime=0;
        RstCnt=0;
    }
}








////////hib_crt

unsigned int	__attribute__((section(".usercode")))	PcCmdchk(void)
{

#ifdef	FLOOR_64
	if(CrtMoveFlr == 0)	return(0);

	if(sRamDArry[mcurfloor] == (CrtMoveFlr & ONLY_FLR)){
    	if( (sRamDArry[mDoorSeq] >= DOOR_OPEN_START) && (sRamDArry[mDoorSeq] <= DOOR_OPEN_WAIT)){
			CrtMoveFlr=0;
		}
	}
	
	if(bExtButClr)	CrtMoveFlr=0;
	if( (CrtMoveFlr & ONLY_FLR) > cF_TOPFLR)	CrtMoveFlr=0;	

	if( !bCarUpMove && !bCarDnMove){
		Virtual_Floor_Set((CrtMoveFlr & ONLY_FLR));
	}
#else
	if( !(CrtMoveFlr & CAR_READY))	return(0);

	if(sRamDArry[mcurfloor] == (CrtMoveFlr & ONLY_FLR)){
    	if( (sRamDArry[mDoorSeq] >= DOOR_OPEN_START) && (sRamDArry[mDoorSeq] <= DOOR_OPEN_WAIT)){
			CrtMoveFlr=0;
		}
	}
	
	if(bExtButClr)	CrtMoveFlr=0;
	if( (CrtMoveFlr & ONLY_FLR) > cF_TOPFLR)	CrtMoveFlr=0;	

	if( !(CrtMoveFlr & CAR_READY))	return(0);



	if( !bCarUpMove && !bCarDnMove){
		Virtual_Floor_Set((CrtMoveFlr & ONLY_FLR));
	}
#endif
}





unsigned int  __attribute__((section(".usercode")))   LastErrDspChk(void)
{

   	if(sRamDArry[mSysStatus] <= sCLE_NO_ON){
		sRamDArry[mEV_LastErr] = sRamDArry[mSysStatus];  // save
	}

	if(bFhmRun && (sRamDArry[FHM_SEQ] >= FHM_SEQ_6)){
		sRamDArry[mSysStatus]=sFhmError;
	}


/*
	if(sRamDArry[mEV_LastErr] > sCLE_NO_ON){
		sRamDArry[mLoader_mSysStatus]	=sRamDArry[mSysStatus];
		sRamDArry[mEV_LastErr]			=sRamDArry[mSysStatus];
	}
	else if(sRamDArry[mSysStatus]==sREADY){
		sRamDArry[mLoader_mSysStatus]=sRamDArry[mEV_LastErr];
	} 	
	else if((sRamDArry[mSysStatus] == sOPEN)){
		if(DoorOpenEndWaitChk() && (sRamDArry[mDoorSeq] == DOOR_REOPEN_CHECK)){
			sRamDArry[mLoader_mSysStatus]=sRamDArry[mEV_LastErr];
		}
		else{
			sRamDArry[mLoader_mSysStatus]=sRamDArry[mSysStatus];
		}	
	}
	else{
		sRamDArry[mLoader_mSysStatus]=sRamDArry[mSysStatus];
	}
*/

	return(0);
}


unsigned int  __attribute__((section(".usercode")))   ManualKeyStatus(void)
{
	unsigned int i;

	i=0;

	if(!IN_AUTO){
		if(PerfectAuto())	i=1;
		else				i=2;
	}	
	else{
		if(bCarUpMove){
			sRamDArry[mSysStatus]=sMANUAL_UP;
			i=2;
		}	
		else if(bCarDnMove){
			sRamDArry[mSysStatus]=sMANUAL_DN;
			i=2;
		}
		else{
    		if(bFhmRun)								i=2;
    		else if(bAutoTunning)					i=2;

    		else if(bCarErr || bCarStopNoRun)		i=2;

			else{
				sRamDArry[mSysStatus]=sMANUAL;
				i=0;
			}
		}		
	}

	return(i);
}


unsigned int  __attribute__((section(".usercode")))   CurErrFind(void)
{
	unsigned int auto_manu;

	sRamDArry[mSysStatus]=sNoDefine;      

	auto_manu=ManualKeyStatus();


	if( auto_manu > 0){
		if(bsLope || bLope_Occur)				sRamDArry[mSysStatus]=sLOPE_BRK;      
		else if(bsSlip || bSlip_Occur)			sRamDArry[mSysStatus]=sSLIP;      
		else if(bsUcmpFeedErr)					sRamDArry[mSysStatus]=sUcmpFeedErrMsg;      
		else if(bsBreakMgtOpen)					sRamDArry[mSysStatus]=sBreakMgtOpen;
		else if(bsBreakOpen)					sRamDArry[mSysStatus]=sBreakOpen;
		else if(bEncoderErr)					sRamDArry[mSysStatus]=sEncoderErr;      		
		else if(bEncoderABErr)					sRamDArry[mSysStatus]=sEncoderABErr;    
		else if(bRelevelErr)					sRamDArry[mSysStatus]=sRelevelError;     
		
		else if(bsHdsRunOff)					sRamDArry[mSysStatus]=sHDS_RUN_OFF;	
		else if(bsCleRunOff)    				sRamDArry[mSysStatus]=sCLE_RUN_OFF;
		else if(bsEmergency)					sRamDArry[mSysStatus]=sEMERGENCY;
		else if(bsUls)							sRamDArry[mSysStatus]=sULS;								
		else if(bsDls)							sRamDArry[mSysStatus]=sDLS;								
		else if(bAutoButtonErr)					sRamDArry[mSysStatus]=sAutoOff;

		else if(bsInvCurNext)					sRamDArry[mSysStatus]=sI_C_N_FLR;      	                // inverter error ??
		else if(bsNextFloor)					sRamDArry[mSysStatus]=sNEXT_FLOOR;
		else if(bFlrMatchErr)	sRamDArry[mSysStatus]=sEqualFloorError;
		else if(bInvComErr)		sRamDArry[mSysStatus]=sInvCommErr;
		else if(LuLdErrNm==1)	sRamDArry[mSysStatus]=sLuOrLdErr0;		
		else if(LuLdErrNm==2)	sRamDArry[mSysStatus]=sLuOrLdErr1;
		else if(LuLdErrNm==3)	sRamDArry[mSysStatus]=sLuOrLdErr2;		
		else if(LuLdErrNm==4)	sRamDArry[mSysStatus]=sLuOrLdErr3;
		else if(LuLdErrNm==5)	sRamDArry[mSysStatus]=sLuOrLdErr4;		
		else if(LuLdErrNm==6)	sRamDArry[mSysStatus]=sLuOrLdErr5;			
		else if( (bDoorJumper==1) && (DoorJumperNm==1)) sRamDArry[mSysStatus]=sCarDoor_Jumper;
		else if( (bDoorJumper==1) && (DoorJumperNm==2)) sRamDArry[mSysStatus]=sHoleDoor_Jumper;
		else if( (bDoorJumper==1) && (DoorJumperNm==3)) sRamDArry[mSysStatus]=sCarHoleDoor_Jumper;			
		else if(bsSusErr)		sRamDArry[mSysStatus]=sSusErr;
		else if(bsSdsErr)		sRamDArry[mSysStatus]=sSdsErr;
		else if(bsLuLdNoOff)	sRamDArry[mSysStatus]=sLULD_NO_OFF;
		else if(bsInvertErr)	sRamDArry[mSysStatus]=sInvertErr;
		else if(bMotor_Overheat)sRamDArry[mSysStatus]=sMOTOR_OVERHEAT;
		else if(bsEarthquake)	sRamDArry[mSysStatus]=sEarthquake;
		else if(bDZ_Err)		sRamDArry[mSysStatus]=sDZErr;			
		else if(NoStart==1)		sRamDArry[mSysStatus]=sSpeedPortError;		
		else if(NoStart==2)		sRamDArry[mSysStatus]=sMinLengthErr;
		else if(NoStart==3)		sRamDArry[mSysStatus]=sSystemErr;			
   		else if(bsCleNoOn)		sRamDArry[mSysStatus]=sCLE_NO_ON;							
		else if(bInPortErr)		sRamDArry[mSysStatus]=sInPortError;
		else if(bInspect)		sRamDArry[mSysStatus]=sINSPECT;      
		else if(S2_FIRE1)		sRamDArry[mSysStatus]=sFireOn;
		else if(bWaterSensing)	sRamDArry[mSysStatus]=sWaterSense;	
		else if(S3_PARKING1)	sRamDArry[mSysStatus]=sPARKING;
		else if(S3_VIP1)		sRamDArry[mSysStatus]=sVIP;
		else if(S1_OVERLOAD1)	sRamDArry[mSysStatus]=sOVL;	
		else if(bSafety_scrSft)	sRamDArry[mSysStatus]=sSFT;	
		
		else{
			if( bCarUpMove){
				if(auto_manu == 1){
					if(bUnd)	sRamDArry[mSysStatus]=sSLOW_SPEED;                                                     
					else		sRamDArry[mSysStatus]=sUP;
				}		
				else				sRamDArry[mSysStatus]=sMANUAL_UP;
			}	
			else if(bCarDnMove){
				if(auto_manu == 1){
					if(bUnd)	sRamDArry[mSysStatus]=sSLOW_SPEED;                                                     
					else		sRamDArry[mSysStatus]=sDN;
				}		
				else				sRamDArry[mSysStatus]=sMANUAL_DN;
			}	
			else if(bDoorOpenCmd )	sRamDArry[mSysStatus]=sOPEN;
			else if((auto_manu == 1) && (sRamDArry[mDoorSeq] < DOOR_CLOSE_START))	sRamDArry[mSysStatus]=sOPEN; 
			else if(bDoorCloseCmd)	sRamDArry[mSysStatus]=sCLOSE;		
			else if((auto_manu == 1) && (sRamDArry[mDoorSeq] < READY_ELEVATOR))		sRamDArry[mSysStatus]=sCLOSE; 
			else if(auto_manu == 2)	sRamDArry[mSysStatus]=sMANUAL;		
			else					sRamDArry[mSysStatus]=sREADY;		


			if(bAutoTunning)		sRamDArry[mSysStatus]=sTuning;
    		if(bFhmRun){
				if(sRamDArry[FHM_SEQ] <= FHM_SEQ_5){
					sRamDArry[mSysStatus]=sFHM_MODE;
				}
			}
		}

		LastErrDspChk();
	}

    SegError=sRamDArry[mSysStatus];

	return(0);
}


unsigned int  __attribute__((section(".usercode")))   NormalFloorLoad(void)
{

	CurErrFind();

    if( !bCarErr && !bCarStopNoRun){
		Err_CurFloor	=(unsigned char)(sRamDArry[mcurfloor]);
		Err_DestFloor   =((unsigned char)sRamDArry[DEST_FLR] & ONLY_FLR);
		Err_InvFloor	=(unsigned char)(sRamDArry[mInvFloor]);				
	}
	return(0);
}


unsigned int  __attribute__((section(".usercode")))   CurErrRead(void)
{
	#ifdef	TEST_SIMULATION
		return(0); 
	#endif	

	if( (!IN_AUTO) || (IN_AUTO && bAutoButtonErr)){
		if( (bCarErr || bCarStopNoRun) && !bSaveErrCnt){
			bSaveErrCnt=1;
		}
	}



    if( !bCarErr && !bCarStopNoRun)	return(0);
	if(bFinalErrSaveChk)			return(0); 

//	CurErrFind();

	Err_CurPulse	=(unsigned long)(CurPulse);
	Err_CurMpm  	=(unsigned int)(CurMeterPerMin);

//	Err_CurFloor	=(unsigned char)(sRamDArry[mcurfloor]);
//	Err_DestFloor	=(unsigned char)(sRamDArry[mLastDestFlr] & ONLY_FLR);
	Err_RunFloor	=(unsigned char)(sRamDArry[mRunFloor]);   				//??
	Err_LuLdFloor	=(unsigned char)(sRamDArry[mLuLdFloor]);				//??
//	Err_InvFloor	=(unsigned char)(sRamDArry[mInvFloor]);					//??
	Err_Number		=(unsigned char)(sRamDArry[mSysStatus]);				// err number

	Err_Out_Up_Byte	=(unsigned char)(O_U_W_bit);
	Err_Out_Op_Byte	=(unsigned char)(O_OP_bit);
	Err_Out_Fan_Byte=(unsigned char)(O_Y_0_bit);

	Err_In_Emg_Byte	=(unsigned char)(I_EMG_bit);
	Err_In_Sus_Byte	=(unsigned char)(I_SU1_bit);
	Err_In_Rg_Byte	=(unsigned char)(I_GR_bit);
	Err_In_Fr1_Byte	=(unsigned char)(I_FIRE_bit);
	Err_In_X0_Byte	=(unsigned char)(I_X0_bit);
	Err_In_Fs0_Byte	=(unsigned char)(I_FS0_bit);

	if(bAutoRunningErr) bFinalErrSaveChk=1;
	bAutoRunningErr=0;

	return(0);
}



unsigned int  __attribute__((section(".usercode")))   SaveFinalErr(void)
{
	long_field	m_data;  


	if(!bFinalErrSaveChk || bMoveCar)		return(0);


    GetFlashDataToBufRam(F_BLOCK_X0);

	parameter_mirror[5]=(unsigned long)(Err_CurPulse);
	parameter_mirror[6]=0;   // extra

				

	m_data.intger[0]=(unsigned int)(Err_CurMpm);
	m_data.intger[1]=0;								// extra
	parameter_mirror[7]=m_data.long_data;


	m_data.byte[0]=(unsigned char)(Err_Out_Up_Byte);
	m_data.byte[1]=(unsigned char)(Err_Out_Op_Byte);
	m_data.byte[2]=(unsigned char)(Err_Out_Fan_Byte);
	m_data.byte[3]=0;
	parameter_mirror[8]=m_data.long_data;



	m_data.byte[0]=(unsigned char)(Err_In_Emg_Byte);
	m_data.byte[1]=(unsigned char)(Err_In_Sus_Byte);
	m_data.byte[2]=(unsigned char)(Err_In_Rg_Byte);
	m_data.byte[3]=(unsigned char)(Err_In_Fr1_Byte);
	parameter_mirror[9]=m_data.long_data;



	m_data.byte[0]=(unsigned char)(Err_In_X0_Byte);
	m_data.byte[1]=(unsigned char)(Err_In_Fs0_Byte);
	m_data.byte[2]=0;
	m_data.byte[3]=(unsigned char)(Err_Number);
	parameter_mirror[10]=m_data.long_data;


	m_data.byte[0]=(unsigned char)(Err_CurFloor);
	m_data.byte[1]=(unsigned char)(Err_RunFloor);
	m_data.byte[2]=(unsigned char)(Err_DestFloor);
	m_data.byte[3]=(unsigned char)(Err_LuLdFloor);
	parameter_mirror[11]=m_data.long_data;

	m_data.byte[0]=(unsigned char)(Err_InvFloor);
	m_data.byte[1]=0;
	m_data.byte[2]=sRamDArry[Year];
	m_data.byte[3]=sRamDArry[Month];
	parameter_mirror[12]=m_data.long_data;


	m_data.byte[0]=sRamDArry[Day];
	m_data.byte[1]=sRamDArry[Hour];
	m_data.byte[2]=sRamDArry[Minuate];
	m_data.byte[3]=sRamDArry[sec];
	parameter_mirror[13]=m_data.long_data;

	SaveVerify = 0x55;
    flash_write_DspChar(F_BLOCK_X0);
	SaveVerify = 0x0;

	bFinalErrSaveChk=0;
	
	return(0);
}


void  __attribute__((section(".usercode")))   IO_Check(void)
{

	if(New_Law_SystemChk())	S4_NEW_LAW_SYSTEM1=1;
	else					S4_NEW_LAW_SYSTEM1=0;

	bReadyCall=0;
	bDoorOpenCmd=0;
	bDoorCloseCmd=0;
    OUT_ERR(0);        


	ErrAutoClear();
   	InPutRead();        
   	InputCheck();
   	AutoManualCheck();
    InitialInPortChk();
#ifdef	TEST_SIMULATION
    CarCurFloorReadSimulation();	
#else
   	CarCurFloorRead();   
#endif
	ServiceCheck();
    FireKeyCheck();
	SlipCheck();         
    WaitAndNotMoveChk();
	CarKeyMostServiceCheck();
    OnlyOneCallChk();
    SaftyStopChk();
	PcCmdchk();
	VirtualExtKey();

  	BreakMgtOpenCheck();
 	BreakOpenCheck();

   	InvErrChk();
	CheckFloorSensor();
	HuntingChk();
	CounterCheck();
	ManWorkingStartCheck();
	

        if(bAuto){
            if(bMotorRestartOn){
                if(!bManualAuto){
                    if(CarOnceStopTime>30){     
	                    FindLuLdManual();
						CarOnceStopTime=31;      
                        bTestKey=0;
						bLevelOpen=0;
					}

					if(SafetyChk() || (!OpenKeyCheck())){
			            if( (!IN_LU || !IN_LD) && !bMoveCar && !bLevelFind){
                			if(!bDoorCloseOk){
								bLevelOpen=1;
								DoorOpenTime=0;
								sRamDArry[mDoorSeq] = DOOR_OPEN_START;
								sRamDArry[mDoor]    = (sRamDArry[mDoor] & CLEAR_ALL_DOOR_KEY);   							
							}
						}
					}	
					if(bLevelOpen){
						ThisFloorDoorCheck();
						CarOnceStopTime=0;      
            			if( (bOpenDoorOk) || (DoorOpenTime > cF_OPTTTM)){
							bLevelOpen=0;
						}
						else{
			   				SelectDoorOpen_you();
						}
					}									

                }
                else{
                    if(!((sRamDArry[mFireSeq] == FIRE_ONE) || (sRamDArry[mFireSeq] == FIRE_THREE) )){          
                        DoorOpenCloseSeq();
                        DoorOpClSystem();
                    }

					Dz_Overheat_Earthquake_Water_Chk();
                    TestUpDn();
                    OneStopKey();
					bSaveFlash=1;
                }        
                NextFloorCheck();
            }

        }                     
        else{    
            sRamDArry[mDoorSeq] = DOOR_CLOSE_START;                    
			bNewFire2=0;
			bLevelOpen=0;
            bOnceOpen=0;
            bSearchHome=0;
            NoCloseCnt=0;
            bTempCall=0;
            bInspect=0;
            bFR2Start1=0;
			bDoorJumper=0;
			DoorJumperNm=0;
            MinuteTime=0;        
            bsCleNoOn=0;
			bLevelFind=0;
			bRunningOpenOn=0;
			NoStart=0;
			bFlrMatchErr=0;	

            bTestKey=0;                        
            bCarUpDnChButClr=0;
            
            if(!S3_PARKING1){

                if(CarOnceStopTime < 10){
 					sRamDArry[mDoor]=0;
				}


                OUT_FAN(1);
                FanTime=0;  
                sRamDArry[mReqStopFloor]=0;
                sRamDArry[mAckStopFloor]=0;
                sRamDArry[mNewAckStopFloor]=0;
                bManualAuto=0; 
     

				OUT_DAC(0);
                bDac=0;

                ManualUpDnKeyCheck();
                ManualUpDown();            

                if(!bFhmRun &&  !IN_SU1 && ManualSusChk ){
            		UpBttonTime=0;    
            		bManualUpKey=0;
                }
            
                if(!bManualUpKey && !bManualDnKey){
                    if(!OpenKeyCheck() || (LoopTime < 5) ){						
    					if( IN_AUTO && (!IN_LU || !IN_LD)){
                        	SelectDoorOpen_you();
						}
                    }
                    else{
                        AllDoorOpenClrCmd_abcdefg();
                    }

		            sRamDArry[mDoor] = (sRamDArry[mDoor] & 0xf5);										   	
                    AllDoorCloseClrCmd_abcdefg();
                }
            }	                   
        }




    DoorOpenEndCheck();            
    InverterErrorCheck();
	NormalFloorLoad();


    if(bCarErr || bCarStopNoRun || bCarStop || !bMotorRestartOn){
		CurErrRead();
		if(!bOnLuLd){
	        LuLdTime=0;
			bFirstOnLuLd=0;
		}

        bOnceOpen=0;
        CarAllStopCmdTest();      	
        if(bMotorRestartOn){      	        
            if(bCarStopNoRun){
                AllDoorOpenClrCmd_abcdefg();      	
                bTestKey=0;    
            }   
            else if(bCarErr){
                bTestKey=0;                                 		
            }           
    
            bManualAuto=0;    
            bCarStop=0;       
            bCarErr=0;        
        }     	

		bLevelFind=0;	
        bVoiceReady=0;   
		bReLoadEncoderExe=0;
    }



    DoorOpenClose_you();
    MotorStop();
    AllReadyCheck();
    EtcStopSet();
	LightOnOff();
    FanOnOff();
    BuzOnOff();
    VoiceStart();
    PcCmdSaveChk();
	PowerSaveValidChk();
	TuningRunCheck();
   	UserLampSet();
    DspFloorSet();
	SolOnChk();
	DoorCloseTimeChk();


	#ifdef	DELTA_INVERTER
		DeltaInvDataSortForPDO();
	#endif


    EmergencyCheck();
    OutData();

	SaveFinalErr();
	SystemErrSave();

    sRamDArry[S1_STATE]		= (unsigned char)(S1_STATE_bit);
    sRamDArry[S2_STATE]		= (unsigned char)(S2_STATE_bit);
    sRamDArry[S3_STATE]		= (unsigned char)(S3_STATE_bit);
    sRamDArry[S4_STATE]		= (unsigned char)(S4_STATE_bit);
	sRamDArry[S5_STATE_37]	= (unsigned char)(EXT_OUT0_bit);

    sRamDArry[SelDoorStatus]=DoorStatus_bit;
}      



void  Timer1Init(void)
{
     
	T1CON = 0 ;//Turn off Timer1 by clearing control register
    IPC0bits.T1IP=1;
	TMR1 = 0 ;  //Start Timer1 at zero
    PR1=16000;
//    PR1=32000;
    _T1ON = 1;
    _T1IE = 1;
}



void  LvdInit(void)
{
    LVDIE=0;

//    RCONbits.LVDL=0x0e; //4.6v
//    RCONbits.LVDL=0x0d; //4.3v
//    RCONbits.LVDL=0x0c; //4.1v
//    LVDEN=1;


    RCON=RCON & 0xc0ff;
    RCON=RCON | 0x1c00;    //4.1v


    LVDIF=0;
    LVDIE=1;
}


void  Uart1Init(void)
{
    U1BRG=51;
    U1STA=0x0;

    _U1RXIP=4;
    _U1TXIP=4;

    _U1PDSEL=0;

    _U1STSEL  = 0;

    _U1ABAUD  = 0;
    _U1LPBACK = 0;
    _U1WAKE   = 0;
    _U1ALTIO  = 0;
    _U1USIDL  = 0;
    _U1UARTEN = 1;

    _U1TXEN=1;
    _U1TXISEL=1;

    _U1TXIF=0;
    _U1RXIF=0;

    _U1RXIE=1;
    _U1TXIE=1;
}


void  Uart2Init(void)
{
    U2BRG=51;
    U2STA=0x0;

    _U2RXIP=4;
    _U2TXIP=4;

    _U2PDSEL=0;

    _U2STSEL  = 0;

    _U2ABAUD  = 0;
    _U2LPBACK = 0;
    _U2WAKE   = 0;
////////////    _U2ALTIO  = 0;
    _U2USIDL  = 0;
    _U2UARTEN = 1;

//    U2STA=0x0;

    _U2TXEN=1;
    _U2TXISEL=1;

    _U2TXIF=0;
    _U2RXIF=0;

    _U2RXIE=1;
    _U2TXIE=1;
}




void  __attribute__((section(".usercode")))  FindCurFloor(void)
{
	unsigned long save_pulse;

    LocalType i;


    i=sRamDArry[mcurfloor];


    if(sRamDArry[mcurfloor] == 0){
		save_pulse=GET_LONG(FLR_02_PULSE);
        if(CurPulse >= save_pulse){
            sRamDArry[mcurfloor] = 0;
			CurPulse=1;
        } 
    }           
    else if(sRamDArry[mcurfloor] > cF_TOPFLR){
        sRamDArry[mcurfloor] = 0;
		CurPulse=2;
    } 
          
    else if(sRamDArry[mcurfloor] == cF_TOPFLR){
		save_pulse=GET_LONG( (unsigned long)(FLR_01_PULSE + cF_TOPFLR - 1) );
        if(CurPulse <= save_pulse){
            sRamDArry[mcurfloor] = 0;
			CurPulse=3;
        }
    }    
	else{
		save_pulse=GET_LONG(FLR_01_PULSE + (i+1));
        if(CurPulse >= save_pulse){
	        sRamDArry[mcurfloor]=0;
			CurPulse=0;
		}

		save_pulse=GET_LONG(FLR_01_PULSE + (i-1));
        if(CurPulse < save_pulse){
	        sRamDArry[mcurfloor]=0;
			CurPulse=0;
		}

	}	

    DspFloorSet();
}




unsigned int  __attribute__((section(".usercode"))) NcNoOutPortInit(void)
{
    LocalType i,selID;

	for(i=SILK_FAN;i<0xff;i++){
		selID=CurSelPortIDRead(i);
		if(selID == 0xff)	return(0);
		else				CurSelOutPort(selID,0);
	}
	return(0);
}




//int   main(void)
int   __attribute__((section(".usercode"))) main(void)
{
    unsigned int i;


    PORTA=0xffff;
    PORTB=0xffff;
    PORTC=0xffff;
    PORTD=0xffff;
    PORTE=0xffff;
    PORTF=0xffff;
    PORTG=0xffff;


    TRISA=0xffff;
    TRISB=0xffff;
    TRISC=0x0000;
    TRISD=0xffff;
    TRISE=0x0000;

    TRISF=0x0055;  //    01010101;
  
    TRISG=0x0001;  //          01 

    SPLIM=SPLIM;

    ADPCFG=0xffff;  //portb digital i/o

   	TXEN=1;
    C2IE       = 0x0;


    bSaveFlash=0;

    OUT_ACT1=1;
    OUT_ACT2=1;

    IN_0=1;
    IN_1=1;
    IN_2=1;
    IN_3=1;
    IN_4=1;

    OUT_0=0;
    OUT_1=0;
    OUT_2=0;


    RD_WR=0;

   	OUT_ON=0;
   	OUT_ON=0;


    I_SU1_bit=0xff;
    I_EMG_bit=0xff;
  	I_GR_bit=0xff;
  	I_FIRE_bit=0xff;
 	I_FS0_bit=0xff;
  	I_X0_bit=0xff;

   	O_OP_bit=0x0;
  	O_U_W_bit=0x80;
   	O_Y_0_bit=0x0;


    sRamDArry[I_EMG]  = I_EMG_bit;
    sRamDArry[I_SU1]  = I_SU1_bit;
    sRamDArry[I_GR]   = I_GR_bit;
    sRamDArry[I_FIRE] = I_FIRE_bit;
    sRamDArry[I_X_0]  = I_X0_bit;
    sRamDArry[I_FS0]  = I_FS0_bit;

    sRamDArry[O_OP]  = O_OP_bit;
    sRamDArry[O_U_W] = O_U_W_bit;
    sRamDArry[O_Y_0] = O_Y_0_bit;


	CarAllStopCmd();


	for(LogAddressLoop=0;LogAddressLoop < MAX_LONG_BUF;LogAddressLoop++){
        parameter_mirror[LogAddressLoop]=0x0;
	}



	bExportData=0;
	bImportData=0;
	bPowerChkStart=0;



    AddressRead();
   
	for(LogAddressLoop=0;LogAddressLoop <= sec;LogAddressLoop++){
		sRamDArry[sRamDArry[mDoorSeq]]=0x0;
	}


	sRamDArry[mDoorSeq]=DOOR_CLOSE_START;
	DoorCloseTime=0;


    sRamDArry[S1_STATE]=S1_STATE_bit=0;
    sRamDArry[S2_STATE]=S2_STATE_bit=0;
    sRamDArry[S3_STATE]=S3_STATE_bit=0;
    sRamDArry[S4_STATE]=S4_STATE_bit=0;
    sRamDArry[SelDoorStatus]=DoorStatus_bit=0;

	Init485_Bd();

	
	bManualAuto=0;
	bHomeUpDn=0;


    INTCON1bits.NSTDIS=1;



    QEI_Init(); 
    LvdInit();
    Timer1Init();
    Uart1Init();
    Uart2Init();
    Can1Init();
    Can2Init();


    INTCON1bits.NSTDIS=1;

CmdFixFlrTime=cF_FIXFLOORTIME;


    asm("CLRWDT");
    ReadInitSetupData();
    asm("CLRWDT");


    if(!SWR){
        asm("RESET");
    }
    SWR=0;

    Ladder485Init();

#ifndef		RS485_FOR_CRT	
	Init485_Ladder();
   	MyDataTx();
#endif

   	RxStatus=STX_CHK;      



   	sRamDArry[LD_INSP] = 0x0;


	NcNoOutPortInit();


   	NoCloseCnt=0;
   	WarmingUpTime=0;
   	CurFTime=0;
   	NextFTime=0;
	SaveVerify=0;
   	    

	sRamDArry[mMostLongDst]= 0x00;
	sRamDArry[mStartFloor] = 0;   //delete value


    while(WarmingUpTime < 10){
        InPutRead();
        asm("CLRWDT");
    }        

//	OnOffFlrResetting();


    if(INVERTER_CHECK == IO){
        FindCurFloor();
    }




	bSlaveEarthquake=0;

    C1Loop=0;
    C2Loop=0;

   	bSlavePrk=0;
	bSubSlavePrk=0;

	bSlaveFire=0;
	bSubSlaveFire=0;

//	bPC_FAMILY=0;
//	bPC_HOME_RETURN=0;

    disp_clk_regs();
    UseBaseTime = sRamDArry[Hour];

    sRamDArry[FHM_SEQ]=FHM_SEQ_8;
	sRamDArry[mEV_LastErr]=0xff;


    bCarService=0;

	bErrSaveFlag=0;
	SlipTimer=0;
	LopeTimer=0;

	bSlip_Occur=0;
	bLope_Occur=0;

	LevelEncoderPulse2=0;

/*
////////////////////////////////////
	sRamDArry[ExtCmdFlrONOFF0]=cF_NONSERVICE0;
	sRamDArry[ExtCmdFlrONOFF1]=cF_NONSERVICE1;
	sRamDArry[ExtCmdFlrONOFF2]=cF_NONSERVICE2;
	sRamDArry[ExtCmdFlrONOFF3]=cF_NONSERVICE3;
//#ifdef	FLOOR_64
	sRamDArry[ExtCmdFlrONOFF4]=cF_NONSERVICE4;
	sRamDArry[ExtCmdFlrONOFF5]=cF_NONSERVICE5;
	sRamDArry[ExtCmdFlrONOFF6]=cF_NONSERVICE6;
	sRamDArry[ExtCmdFlrONOFF7]=cF_NONSERVICE7;
//#endif
*/

//zz
/*
	if(FamilyService)	bPC_FAMILY=1;
	else				bPC_FAMILY=0;
*/

	
//	CmdFixFlrTime=cF_FIXFLOORTIME;
////////////////////////////////////
/*
	sRamDArry[ExtCmdFlrONOFF0]=0xff;
	sRamDArry[ExtCmdFlrONOFF1]=0xff;
	sRamDArry[ExtCmdFlrONOFF2]=0xff;
	sRamDArry[ExtCmdFlrONOFF3]=0xff;
	sRamDArry[ExtCmdFlrONOFF4]=0xff;
	sRamDArry[ExtCmdFlrONOFF5]=0xff;
	sRamDArry[ExtCmdFlrONOFF6]=0xff;
	sRamDArry[ExtCmdFlrONOFF7]=0xff;
*/

	ShadowsRamDArry[FLR_ON_OFF0]=cF_NONSERVICE0;
	ShadowsRamDArry[FLR_ON_OFF1]=cF_NONSERVICE1;
	ShadowsRamDArry[FLR_ON_OFF2]=cF_NONSERVICE2;
	ShadowsRamDArry[FLR_ON_OFF3]=cF_NONSERVICE3;
	ShadowsRamDArry[FLR_ON_OFF4]=cF_NONSERVICE4;
	ShadowsRamDArry[FLR_ON_OFF5]=cF_NONSERVICE5;
	ShadowsRamDArry[FLR_ON_OFF6]=cF_NONSERVICE6;
	ShadowsRamDArry[FLR_ON_OFF7]=cF_NONSERVICE7;


	BaggageFlrOnOff[0]=0xff;
	BaggageFlrOnOff[1]=0xff;
	BaggageFlrOnOff[2]=0xff;
	BaggageFlrOnOff[3]=0xff;
	BaggageFlrOnOff[4]=0xff;
	BaggageFlrOnOff[5]=0xff;
	BaggageFlrOnOff[6]=0xff;
	BaggageFlrOnOff[7]=0xff;

	sRamDArry[FLR_ON_OFF0] =(ShadowsRamDArry[FLR_ON_OFF0] & BaggageFlrOnOff[0] & cF_NONSERVICE0);
	sRamDArry[FLR_ON_OFF1] =(ShadowsRamDArry[FLR_ON_OFF1] & BaggageFlrOnOff[1] & cF_NONSERVICE1);
	sRamDArry[FLR_ON_OFF2] =(ShadowsRamDArry[FLR_ON_OFF2] & BaggageFlrOnOff[2] & cF_NONSERVICE2);
	sRamDArry[FLR_ON_OFF3] =(ShadowsRamDArry[FLR_ON_OFF3] & BaggageFlrOnOff[3] & cF_NONSERVICE3);	
	sRamDArry[FLR_ON_OFF4] =(ShadowsRamDArry[FLR_ON_OFF4] & BaggageFlrOnOff[4] & cF_NONSERVICE4);
	sRamDArry[FLR_ON_OFF5] =(ShadowsRamDArry[FLR_ON_OFF5] & BaggageFlrOnOff[5] & cF_NONSERVICE5);
	sRamDArry[FLR_ON_OFF6] =(ShadowsRamDArry[FLR_ON_OFF6] & BaggageFlrOnOff[6] & cF_NONSERVICE6);
	sRamDArry[FLR_ON_OFF7] =(ShadowsRamDArry[FLR_ON_OFF7] & BaggageFlrOnOff[7] & cF_NONSERVICE7);		


	CmdFixFlrTime=cF_FIXFLOORTIME;


	if(FamilyService)			bExt_FAMILY=1;
	else						bExt_FAMILY=0;	


	bBK1=0;
	BreakTime=0;

	ThisFloorDoorCheck();
	BaseDecPulseX=0;


	PassWardKeyBuf[0]='0';
	PassWardKeyBuf[1]='0';
	PassWardKeyBuf[2]='0';
	PassWardKeyBuf[3]='0';


	bFhmRun=0;
    bAllMenu=0;
    bPasswardOk=0;   		
    bUserOn=0;
	bExportData=0;
	bImportData=0;
	bAutoTunning=0;


	PowerSaveTimer=255;
	bPowerSaveMoveValid=1;
	bReLoadEncoderExe=0;

	LoadSensorPotionInit();

	sRamDArry[AUTO_TUNING] = AUTOTUN_SEQ_0;	
	AutotunUpDn=0;


	bsSlip=0;
	bsLope=0;
	bRelevelErr=0;
	bFinalErrSaveChk=0;
	bAutoRunningErr=0;
	bCarErr=0;
   	bCarStopNoRun=0;
    bManualAuto=0;
	bsLope=0;
   	bsSlip=0;                  
    bSlipCheckStart=0;
	bsLuLdNoOff=0;         	         		        
	bsBreakMgtOpen=0;    
	bsBreakOpen=0;
	bRunningOpenOn=0;
	bEqualFloorError=0;
   	bDZ_Err=0;
	bsNextFloor=0;
	bsUcmpFeedErr=0;


	bSaveErrCnt=0;
	bErrSaveFlag=0;
	bErrClearOnce=1;
	ErrFlagClr();

	if(New_Law_SystemChk()){
		if(NotRecoveryData & 0x01){
			bsLope=1;
			bBefbsLope=1;
		}	
		else if(NotRecoveryData & 0x02){
			bsSlip=1;
			bBefbsSlip=1;
		}	
		else if(NotRecoveryData & 0x04){
			bsUcmpFeedErr=1;
			bBefbsUcmpFeedErr=1;
		}	
		else if(NotRecoveryData & 0x08){
			bsNextFloor=1;
			bBefbsNextFloor=1;
		}	
	}
	else{
		NotRecoveryData= (NotRecoveryData & ~0x0f);
	}


	DOOR_STOP_PORT_Inport_Init();  // old version -> new version menu insert init
	Virtual_IN_bit=0xff;

    do{

        AddressRead();

        IO_Check();                                
        SerialCheck();
        Serial2Check();

        asm("CLRWDT");

        Can1Check();
        Can2Check();

        disp_clk_regs();

        asm("CLRWDT");
   	}while(1);                                  
}




void _ISR_X _T1Interrupt(void)
{
	unsigned int icur_mpm;

    if( _T1IF ){

        _T1IF = 0 ;
        TMR1=0;

//		MainLoopTime++;

        if(EepTime<50)    EepTime++;


        EmgTime++;
        PrkTime++;
        AtTime++;
        UbTime++;
        DbTime++;
        OlsTime++;
        GsTime++;
        DsTime++;

        Su1Time++;
        Sd1Time++;
        SftTime++;
        OvlTime++;
        UlsTime++;
        DlsTime++;
        LuTime++;
        LdTime++;

        RgTime++;
        BatTime++;
        PassTime++;
        FireTime++;
        WaterTime++;
        FullTime++;
        MmTime++;
        FhmInTime++;

        Fr1Time++;
        Fr2Time++;
        Gs2Time++;
        Ds2Time++;
        Su2Time++;
        Sd2Time++;
        BmTime++;
        InvTime++;

		Fs0Time++;
		Fs1Time++;
		Fs2Time++;
		Fs3Time++;
		Fs4Time++;
		DerTime++;
		FidTime++;
		UndTime++;


        X0Time++;
        X1Time++;
        X2Time++;
        X3Time++;
        X4Time++;
        X5Time++;
        X6Time++;
        X7Time++;
        

        I_EMG_Cht++;
        I_FS0_Cht++;
        I_GR_Cht++;
        I_SU1_Cht++;
        I_X_0_Cht++;
        I_FIRE_Cht++;

        C1Time++;
        C2Time++;    
        SerialTime2++;

		#ifdef	DELTA_INVERTER
		if(DeltaNoAck < 100)			DeltaNoAck++;
		#endif


		ReadEncoder();
		if(bReLoadEncoderExe){
			EncoderValueReload();
		}


		msec10Timer++;
		if(msec10Timer >= 10){
			msec10Timer=0;

			#ifdef	DELTA_INVERTER
			if(InverterPDORxTime < 1000)	InverterPDORxTime++;
			#endif


			if(bCalcuMpmOn){
	            if(CurPulse>BefCurPulse){
					PulsePer100Msec=CurPulse-BefCurPulse;
	                CountDn=0;    
	                CountUp++;    
	            }
	            else if(CurPulse<BefCurPulse){
	                PulsePer100Msec=BefCurPulse-CurPulse;   
	                CountUp=0;    
	                CountDn++;    
	            }
	            else{
	                PulsePer100Msec=BefCurPulse-CurPulse;    
	                CountUp=0;    
	                CountDn=0;    
	            }
//	            BefCurPulse=CurPulse;


				PulsePer100Msec=(PulsePer100Msec * 10);				
				
	            TmpMmPerMin=GET_LONG(MPM_VARIABLE);
	            CurMeterPerMin=(PulsePer100Msec * TmpMmPerMin);

				xCurMpm=(CurMeterPerMin/(unsigned long)10000);                    ////???
	            CurMeterPerMin=(CurMeterPerMin/(unsigned long)1000000);

				icur_mpm=(unsigned int)CurMeterPerMin;
	            sRamDArry[mMpmL]= (unsigned char)icur_mpm;
	            sRamDArry[mMpmH]= (unsigned char)(icur_mpm >> 8);



				if(BaseDecPulseX > 0){	

/*  ???????????
	    			if(sRamDArry[mDoorSeq] == WAIT_NEXT_LULD){
						if(bMoveCar){
							FindScurveTime++;
							if(!bUnd){
								FindDecTime=0;
								FindScurveTime=0;
								MiniMumSpd=0xff;
							}
							else{
								if( (CurMeterPerMin < (unsigned long)(cF_LULD_MPM_SPD3)) && (FindDecTime==0)){
									FindDecTime=FindScurveTime;
									MiniMumSpd=CurMeterPerMin;
								}
							}
						}
					}

?????????  */
					
					if(!bUnd && bMoveCar){
						MaxMpm=GET_LONG(MPM);
						xVarTime  =GET_LONG(BASE_DEC_TIME);     	// 3870             	
						xVarSCurve=GET_LONG(BASE_SCURVE_TIME);  	// 1200             	

						if(xCurMpm > (MaxMpm * 1000)){
							xCurMpm=(MaxMpm * 1000);   
						}

						xCurMpm_MaxMpmSpd= (xCurMpm/MaxMpm);		// 150000/180=833		
						xCurMpm=(xCurMpm/120);						// 150000/120 = 1250    
	
						Length1=(xVarTime * xCurMpm_MaxMpmSpd);  	//(3870 * 833)=3,223,710  
						Length1=(Length1/1000);  					//(3,223,710/1000)= 3,223  
						Length1=(Length1 + xVarSCurve);  			//3,223 + 1200 =4,423    
						Length1=(Length1 * xCurMpm);				//4,423 * 1250=	551,500 //1900 * 50 = 95000
						Length1=(Length1 * 10);
    					Length2=GET_LONG(MM_PULSE);
						DecreasePulse=(Length1/Length2);	
					}
				}
			}

			bCalcuMpmOn=1;
	        BefCurPulse=CurPulse;

		}



		

#ifndef		RS485_FOR_CRT	  
        SerialTime++;  
        if(SerialTime>10){
            TimeOutBd++;
            SerialTime=0;
        }
#else
        if(SerialTime < 100)	SerialTime++;
#endif


        if(bOpenDoorOk && (DoorOpenOnTime<250)){	
            DoorOpenOnTime++;
        }


        if((!IN_LU || !IN_LD) && (LuLdTime < 50000)){
			if(bFirstOnLuLd)	LuLdTime++;
        }


        if(LadderTime  < 20002)  LadderTime++;



        msec10++;
        if(msec10 >= 100){
            msec10=0;

			OUT_RUN = !OUT_RUN;

			if(TmpBuzor < 100)	TmpBuzor++;

            if(RstTime < 65530) RstTime++;

            C2Loop++;

            if(CarOnceStopTime < 250)   CarOnceStopTime++;        
            if(PowerFailTime<250)       PowerFailTime++;
            if(LoopTime<100)            LoopTime++;


            if(!bMoveCar){
                ElevMoveTime=0;
                if(ElevStopTime < 50000)    ElevStopTime++;
            }
            else{
                ElevStopTime=0;
                if(CounterTime < 250)   	CounterTime++;
                if(ElevMoveTime < 50000)  	ElevMoveTime++;
            }  


            if(bLevelFind){  
                if(RelevelTime < 250)  RelevelTime++;
                if(RelevelTime > 240){
					bCarErr=1;
                }
            }
            else    RelevelTime=0;

			TuningLoaderTime++;        
            FhmLoaderTime++;
            CurFTime++;
            NextFTime++;
            errtime++;
            DoorOpenTime++;
            NextFloorTime++;       
            UpBttonTime++;
            DnBttonTime++;   
            SerialLoopMaxTime++;

			if(TunningTimer < 1000)			TunningTimer++;

            if(DoorCloseTime < 1000)		DoorCloseTime++;
			if(BreakTime  < 1000)			BreakTime++;
			if(PowerSaveTimer  < 250)		PowerSaveTimer++;
			if(UcmpOnOffChkTimer < 1000)	UcmpOnOffChkTimer++;								
			if(ReLevelAnounceTime  < 100)	ReLevelAnounceTime++;
			if(SolTimer < 100)				SolTimer++;
//			if(SolWaitTimer < 100)			SolWaitTimer++;
            if(SelMainCarTime < 100)    	SelMainCarTime++;
            if(SelSubCarTime < 100)     	SelSubCarTime++;
            if(LadderKeyTime < 36500)   	LadderKeyTime++;
            if(WarmingUpTime < 210)     	WarmingUpTime++;                                 
            if(CloseOutOffTime < 250)   	CloseOutOffTime++;
            if(ExIOTimer < 250)   			ExIOTimer++;
			if(HuntingTimer < 100)			HuntingTimer++;

			if(CommonConnectPortTime < 250)	CommonConnectPortTime++;

            if(bUnd){
                if(VoiceTime < 250) VoiceTime++;
                if(BellTime < 250) BellTime++;
            }
            else{
		        VoiceTime=0;
				BellTime=0;
			}

            if( bDoorCloseOkSensor && (DoorCloseOnTime<250)){
                DoorCloseOnTime++;
            }


			if(bsLope || bLope_Occur){
				if(LopeTimer < 1000)		LopeTimer++;
			}
			else							LopeTimer=0;


			if(bsSlip || bSlip_Occur){
				if(SlipTimer < 1000)		SlipTimer++;
			}
			else							SlipTimer=0;


			if(bsEmergency){
				if(EmgTimer < 1000)			EmgTimer++;
			}
			else							EmgTimer=0;
							

            sec1++;
            if(sec1 >= 10){
                sec1=0;
                bDspSeq=!bDspSeq;
                FanTime++; 
				if(AccTimer < 254)			AccTimer++;							 
                if(FixFlrTimeCnt <= 6000)	FixFlrTimeCnt++;
				if(FiremanTimer < 1000)		FiremanTimer++;
            }

            MinuteTime++;
            if(MinuteTime>=600){
                MinuteTime=0;        
                LightTime++;

				UseBaseTime++;
				if(UseBaseTime >= 60){
					UseBaseTime=0;

        			if(PowerOnTime < 999999)	PowerOnTime++;
        			if(PowerOnTime >= 1000000)	PowerOnTime++;
				}	

                if(InvErrTime < 600)    InvErrTime++;
            }        

            if( !bMotorRestartOn){
                if(ManualStopTime < 100)  ManualStopTime++;
            }
            else	ManualStopTime=0;


            if(bFireTimeRun){
                if(RestartTime<60)  RestartTime++;
            }
            else{
                RestartTime=0;
            }

#ifdef  TEST_SIMULATION  
            if(bMoveCar){
                if(MotorMoveTime<250)	MotorMoveTime++;
            }
            else{
        		MotorMoveTime=0;    
            }
#endif

        }      
    }
}




void _ISR_X _OscillatorFail(void)
{

    INTCON1bits.OSCFAIL=0;
    asm("RESET");
}


void _ISR_X _AddressError(void)
{   
    INTCON1bits.ADDRERR=0;
    asm("RESET");
}


void _ISR_X _StackError(void)
{   
    INTCON1bits.STKERR=0;
    asm("RESET");
}




void _ISR_X _MathError(void)
{   
    INTCON1bits.MATHERR=0;
    asm("RESET");
}



void	SaveEEpromPulse(void)
{
    unsigned int i;

	CarAllStopCmd();
	CarAllStopCmd();

    if(bSaveFlash){
		SaveVerify = 0x55;
		EEP_Save_All();
        bSaveFlash=0;
		SaveVerify = 0x0;
    }
}


void _ISR_X _LVDInterrupt(void)
{
	SaveEEpromPulse();
    LVDIF=0;
    asm("RESET");
}




void _ISR_X _DefaultInterrupt(void)
{
	SaveEEpromPulse();
    asm("RESET");
}





