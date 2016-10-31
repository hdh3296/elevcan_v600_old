
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




void  __attribute__((section(".usercode"))) IO_Mode(void)
{
    LocalType  i;

	SaveVerify = 0x55;

/////////////////////////////////////////////////////////
/////////////////////block1//////////////////////////////
/////////////////////////////////////////////////////////
	GetFlashDataToBufRam(F_TopFlr);	//block1

	//floor group	
//	b_LdTmpBufRam(F_TopFlr)         = Init_TopFlr;
//	b_LdTmpBufRam(F_PrkFlr)         = Init_PrkFlr;
	b_LdTmpBufRam(F_FixFloor)       = Init_FixFloor;
//	b_LdTmpBufRam(F_OneStopFlr)     = Init_OneStopFlr;
//	b_LdTmpBufRam(F_FireSafeFlr)    = Init_FireSafeFlr;
//	b_LdTmpBufRam(F_X7SafeFlr)      = Init_X7SafeFlr;
//	b_LdTmpBufRam(F_WaterSafeFlr)   = Init_WaterSafeFlr;
//	b_LdTmpBufRam(F_StartFloor)     = START_FLOOR;   	
//	b_LdTmpBufRam(F_KidsKeyCnt)     = Init_KidsKeyCnt;
//	b_LdTmpBufRam(F_X6SafeFlr)      = Init_X6SafeFlr;
//	b_LdTmpBufRam(F_X5SafeFlr)      = Init_X5SafeFlr;
		
	
/* not use		                              //     7 ,      6,      5,        4,         3,        2,       1,     0
//	b_LdTmpBufRam(F_NcNoBit0)       = Init_ALL_FF;  //                                                                     emg
//	b_LdTmpBufRam(F_NcNoBit1)       = Init_ALL_FF;  //                                                                     su1
//	b_LdTmpBufRam(F_NcNoBit2)       = Init_ALL_FF;  //                                                                     rg
//	b_LdTmpBufRam(F_NcNoBit3)       = Init_ALL_FF;  //                                                                     fr1
//	b_LdTmpBufRam(F_NcNoBit4)       = Init_ALL_FF;  //                                                                     x0
//	b_LdTmpBufRam(F_NcNoBit5)       = Init_ALL_FF;  //                                                                     fs0
//	b_LdTmpBufRam(F_NcNoBit6)       = Init_ALL_FF;  //                                                                     op
//	b_LdTmpBufRam(F_NcNoBit7)       = Init_ALL_FF;  //                                                                     fan
//	b_LdTmpBufRam(F_NcNoBit8)       = Init_ALL_FF;  //                                                                     up
*/		
		
	//onoff2 group		
//	bit_LdTmpBufRamSet  (F_OnOff0,bFhmOnOff             % 8);
//	bit_LdTmpBufRamSet  (F_OnOff0,bDoorJumperOff        % 8); 
//	bit_LdTmpBufRamReset(F_OnOff0,bEncoderPhase         % 8);
//	bit_LdTmpBufRamSet  (F_OnOff0,bWardPriority         % 8);
//	bit_LdTmpBufRamReset(F_OnOff0,bNonStop              % 8);
//	bit_LdTmpBufRamSet  (F_OnOff0,bOpenTotalOnOff       % 8);
//	bit_LdTmpBufRamSet  (F_OnOff0,bCloseTotalOnOff      % 8);
//	bit_LdTmpBufRamSet  (F_OnOff0,bOpenWaitToTalOnOff   % 8);
		
//	bit_LdTmpBufRamSet  (F_OnOff1,bCarDoor1Use      	% 8);
//	bit_LdTmpBufRamReset(F_OnOff1,bCarDoor2Use      	% 8);
//	bit_LdTmpBufRamSet  (F_OnOff1,bHoleDoor1Use     	% 8);
//	bit_LdTmpBufRamReset(F_OnOff1,bHoleDoor2Use     	% 8);
//	bit_LdTmpBufRamReset(F_OnOff1,bSubSafety        	% 8);
	bit_LdTmpBufRamSet  (F_OnOff1,bBrkMgtUse        	% 8);  //on
	bit_LdTmpBufRamSet  (F_OnOff1,bEncoderUse       	% 8);
	bit_LdTmpBufRamReset(F_OnOff1,bRelevelOnOff     	% 8);
		
	bit_LdTmpBufRamSet  (F_OnOff2,bOilLopeTypeChk   	% 8);
//	bit_LdTmpBufRamReset(F_OnOff2,bOnlyOneCall      	% 8);
//	bit_LdTmpBufRamReset(F_OnOff2,bManualSusChk     	% 8);
	bit_LdTmpBufRamSet  (F_OnOff2,bBrkOpenUse       	% 8);  //on
//	bit_LdTmpBufRamReset(F_OnOff2,bKidsKeyChkUse    	% 8);
//	bit_LdTmpBufRamReset(F_OnOff2,bCarKeyFirstService  	% 8);
//	bit_LdTmpBufRamReset(F_OnOff2,bFamilyService    	% 8);
//	bit_LdTmpBufRamReset(F_OnOff2,bOpenOutSet    		% 8);
	
	
//	bit_LdTmpBufRamReset(F_OnOff3,bSafetyValidLR    	% 8);
//	bit_LdTmpBufRamReset(F_OnOff3,bFloorSel             % 8);
//	bit_LdTmpBufRamReset(F_OnOff3,bRunOpenSetClear      % 8);
//	bit_LdTmpBufRamReset(F_OnOff3,bUcmpFeedback      	% 8);
//	bit_LdTmpBufRamReset(F_OnOff3,bManWorkingChk      	% 8);
//	bit_LdTmpBufRamSet(F_OnOff3,bEncoderCpy         	% 8);
	
	
	
//timer group
	b_LdTmpBufRam(F_OpWtTm)         = Init_OpWtTm;			//0      
	b_LdTmpBufRam(F_OpTtTm)         = Init_OpTtTm; 			//1 		
	b_LdTmpBufRam(F_FixFloorTime)   = Init_FixFloorTime;   	//2
	b_LdTmpBufRam(F_NextFlrTime)    = Init_NextFlrTime;    	//3
	b_LdTmpBufRam(F_LuLdOffTime)    = Init_LuLdOffTime;    	//4
//	b_LdTmpBufRam(F_FanTime)        = Init_FanTime;        	//5
//	b_LdTmpBufRam(F_LightTime)      = Init_LightTime;      	//6
//	b_LdTmpBufRam(F_OpClWaitTime)   = Init_OpClWTime;      	//7
//	b_LdTmpBufRam(F_DrJmpChkTime)   = Init_DrJmpChkTime;   	//8(power run time/power save)
//	b_LdTmpBufRam(F_DirTime)        = Init_DirTime;			//9
//	b_LdTmpBufRam(F_VoiceTime)      = Init_VoiceTime;		//10
//	b_LdTmpBufRam(F_BrkMgtTime)     = Init_BrkMgtTime;		//11
//	b_LdTmpBufRam(F_ReOpTime)       = Init_ReOpTime;       	//12(open hold time/door open)
	b_LdTmpBufRam(F_StTm1)          = Init_StTm1;          	//13(p4 on time)
	b_LdTmpBufRam(F_StTm2)          = Init_StTm2;          	//14(updn on time)
	b_LdTmpBufRam(F_StTm3)          = Init_StTm3;          	//15(bk2 on time)
	b_LdTmpBufRam(F_StTm4)          = Init_StTm4;          	//16(bk1 on time)
	b_LdTmpBufRam(F_StTm5)          = Init_StTm5;          	//17(run on time)		
	b_LdTmpBufRam(F_RunOffTime)		= Init_RunOff_Time;	//18(run off time)        
	b_LdTmpBufRam(F_Bk1OffTime)     = Init_Bk1Off_Time;	//19(bk1 off time)
	b_LdTmpBufRam(F_Bk2OffTime)     = Init_Bk2Off_Time;	//20(bk2 off time)
	b_LdTmpBufRam(F_UDOffTime)      = Init_UDOff_Time;		//21(updn off time)      
	b_LdTmpBufRam(F_P4OffTime)      = Init_P4Off_Time;     //22(p4 off time)
	b_LdTmpBufRam(F_SolOnTime)      = Init_SolOn_Time;		//23(sol on time)        
	b_LdTmpBufRam(F_DoorWaitTime)   = Init_DoorWait_Time;  //24(door start time)

	if(USE_CHECK != MAN_USE){
		b_LdTmpBufRam(F_OpWtTm)         = 30;					//0      
		b_LdTmpBufRam(F_OpTtTm)         = 30; 					//1 		

		b_LdTmpBufRam(F_SolOnTime)      = 40;					//23(sol on time)        
		b_LdTmpBufRam(F_DoorWaitTime)   = 20;  					//24(door start time)

	}


	flash_write_DspChar(F_TopFlr);		//block1
/////////////////////////////////////////////////////////
/////////////////////block1//////////////////////////////
/////////////////////////////////////////////////////////
	
	
/*
	/////////////////////wait floor group//////////////////////////////
	for(i=0;i<32;i++){
		b_LdTmpBufRam(F_0506+i)           = DISABLE_FLR;
	}
	
	flash_write_DspChar(F_BLOCK3);
	//////////////////////////////////////////////////////////////
*/
	



/////////////////////////////////////////////////////////
/////////////////////block4//////////////////////////////
/////////////////////////////////////////////////////////

	/////////////////////ncno group//////////////////////////////

	GetFlashDataToBufRam(EMG_PORT);	

//	b_LdTmpBufRam(EMG_PORT)         =SILK_EMG   | BIT_NORMAL_OPEN;			//1     64    ncno1 group
//	b_LdTmpBufRam(PRK_PORT)         =SILK_PRK   | BIT_NORMAL_CLOSE;         //1     
//	b_LdTmpBufRam(AUTO_PORT)        =SILK_AUTO  | BIT_NORMAL_OPEN;         	//1     
//	b_LdTmpBufRam(U_B_PORT)         =SILK_U_B   | BIT_NORMAL_OPEN;          //1             
//	b_LdTmpBufRam(D_B_PORT)         =SILK_D_B   | BIT_NORMAL_OPEN;          //1     65
	b_LdTmpBufRam(OLS_PORT)         =SILK_OLS   | BIT_NORMAL_OPEN ;         //1     
//	b_LdTmpBufRam(GS_PORT)          =SILK_GS    | BIT_NORMAL_OPEN;      	//1     
//	b_LdTmpBufRam(DS_PORT)          =SILK_DS    | BIT_NORMAL_OPEN;       	//1             
	
	b_LdTmpBufRam(SU1_PORT)         =SILK_SU1   | BIT_NORMAL_CLOSE;         //1     66
	b_LdTmpBufRam(SD1_PORT)         =SILK_SD1   | BIT_NORMAL_CLOSE;         //1     
//	b_LdTmpBufRam(SFT_PORT)         =SILK_SFT   | BIT_NORMAL_OPEN;          //1     
//	b_LdTmpBufRam(OVL_PORT)         =SILK_OVL   | BIT_NORMAL_OPEN;          //1             
//	b_LdTmpBufRam(ULS_PORT)         =SILK_ULS   | BIT_NORMAL_OPEN;          //1     67
//	b_LdTmpBufRam(DLS_PORT)         =SILK_DLS   | BIT_NORMAL_OPEN;          //1     
//	b_LdTmpBufRam(LU_PORT)          =SILK_LU    | BIT_NORMAL_OPEN;          //1     
//	b_LdTmpBufRam(LD_PORT)          =SILK_LD    | BIT_NORMAL_OPEN;          //1             
	
//	b_LdTmpBufRam(RG_PORT)          =SILK_GR    | BIT_NORMAL_CLOSE;			//1     68
//	b_LdTmpBufRam(BAT_PORT)         =SILK_BAT   | BIT_NORMAL_OPEN;			//1     
//	b_LdTmpBufRam(PASS_PORT)        =SILK_PASS  | BIT_NORMAL_OPEN;         	//1     
//	b_LdTmpBufRam(FIRE_PORT)        =SILK_FIRE  | BIT_NORMAL_OPEN;         	//1             
//	b_LdTmpBufRam(WATER_PORT)       =SILK_WATER | BIT_NORMAL_OPEN;        	//1     69
//	b_LdTmpBufRam(FULL_PORT)        =SILK_FULL  | BIT_NORMAL_OPEN;         	//1     
//	b_LdTmpBufRam(MM_PORT)          =SILK_MM    | BIT_NORMAL_OPEN;         	//1     
//	b_LdTmpBufRam(FHM_PORT)         =SILK_FHM   | BIT_NORMAL_OPEN;          //1             
	
//	b_LdTmpBufRam(FR1_PORT)         =SILK_FR1   | BIT_NORMAL_OPEN;          //1     70
//	b_LdTmpBufRam(FR2_PORT)         =SILK_FR2   | BIT_NORMAL_OPEN;          //1     
	b_LdTmpBufRam(GS2_PORT)         =SILK_GS2   | BIT_NORMAL_OPEN;          //1     
//	b_LdTmpBufRam(DS2_PORT)         =SILK_DS2   | BIT_NORMAL_OPEN;          //1             
//	b_LdTmpBufRam(SU2_PORT)         =SILK_SU2   | BIT_NORMAL_OPEN;          //1     71
//	b_LdTmpBufRam(SD2_PORT)         =SILK_SD2   | BIT_NORMAL_OPEN;          //1     
//	b_LdTmpBufRam(BM_PORT)          =SILK_BM    | BIT_NORMAL_OPEN;          //1     
	b_LdTmpBufRam(INV_PORT)         =SILK_INV   | BIT_NORMAL_CLOSE;         //1             
	
//	b_LdTmpBufRam(X0_PORT)          =SILK_X0    | BIT_NORMAL_OPEN;       	//1     72	ncno2 group
//	b_LdTmpBufRam(X1_PORT)          =SILK_X1    | BIT_NORMAL_OPEN;      	//1     
//	b_LdTmpBufRam(X2_PORT)          =SILK_X2    | BIT_NORMAL_OPEN;			//1     
//	b_LdTmpBufRam(X3_PORT)          =SILK_X3    | BIT_NORMAL_OPEN;			//1             
//	b_LdTmpBufRam(X4_PORT)          =SILK_X4    | BIT_NORMAL_OPEN;			//1     73
//	b_LdTmpBufRam(X5_PORT)          =SILK_X5    | BIT_NORMAL_OPEN;			//1     
//	b_LdTmpBufRam(X6_PORT)          =SILK_X6    | BIT_NORMAL_OPEN;			//1     
	b_LdTmpBufRam(X7_PORT)          =SILK_X7    | BIT_NORMAL_OPEN;			//1             
	
//	b_LdTmpBufRam(FS0_PORT)         =SILK_FS0   | BIT_NORMAL_OPEN;          //1     74
//	b_LdTmpBufRam(FS1_PORT)         =SILK_FS1   | BIT_NORMAL_CLOSE;         //1     
	b_LdTmpBufRam(FS2_PORT)         =SILK_FS2   | BIT_NORMAL_OPEN;          //1     
//	b_LdTmpBufRam(FS3_PORT)         =SILK_FS3   | BIT_NORMAL_OPEN;          //1             
//	b_LdTmpBufRam(FS4_PORT)         =SILK_FS4   | BIT_NORMAL_OPEN;          //1     75
//	b_LdTmpBufRam(DER_PORT)         =SILK_DER   | BIT_NORMAL_OPEN;          //1     
//	b_LdTmpBufRam(FID_PORT)         =SILK_FID   | BIT_NORMAL_OPEN;          //1     
//	b_LdTmpBufRam(UND_PORT)         =SILK_UND   | BIT_NORMAL_OPEN;          //1     
	
	
/////////mainsub door group////////////////	
//	b_LdTmpBufRam(F_SubDoorFlr1)    = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr2)    = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr3)    = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr4)    = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr5)    = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr6)    = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr7)    = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr8)    = Init_SubDoorFlr1;
	
//	b_LdTmpBufRam(F_SubDoorFlr9)    = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr10)   = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr11)   = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr12)   = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr13)   = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr14)   = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr15)   = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr16)   = Init_SubDoorFlr1;		
	

	if(USE_CHECK != MAN_USE){
		if(New_Law_SystemChk()){
			b_LdTmpBufRam(FS2_PORT)         =SILK_FS2   | BIT_NORMAL_CLOSE;          //1     
		}
		else{
			b_LdTmpBufRam(GS2_PORT)         =SILK_GS2   | BIT_NORMAL_CLOSE;          //1     
		}

		b_LdTmpBufRam(OLS_PORT)         	=SILK_OLS   | BIT_NORMAL_CLOSE;         //1     
		b_LdTmpBufRam(X7_PORT)          	=SILK_X7    | BIT_NORMAL_CLOSE;			//1    
         
		b_LdTmpBufRam(SU1_PORT)         	=SILK_SU1   | BIT_NORMAL_OPEN;         //1     
		b_LdTmpBufRam(SD1_PORT)         	=SILK_SD1   | BIT_NORMAL_OPEN;         //1     
	}
	
	flash_write_DspChar(EMG_PORT);		//block4
/////////////////////////////////////////////////////////
/////////////////////block4//////////////////////////////
/////////////////////////////////////////////////////////
	



/////////////////////////////////////////////////////////
/////////////////////block5//////////////////////////////
/////////////////////////////////////////////////////////
	////////////////ncno3 group/////////////////////////////////
////////////////////	GetFlashDataToBufRam(FAN_PORT);	

//	b_LdTmpBufRam(FAN_PORT)         =SILK_FAN   | BIT_NORMAL_OPEN;
//	b_LdTmpBufRam(LIT_PORT)         =SILK_LIT   | BIT_NORMAL_CLOSE;  //     
//	b_LdTmpBufRam(BUZ_PORT)         =SILK_BUZ   | BIT_NORMAL_OPEN;     
//	b_LdTmpBufRam(BELL_PORT)        =SILK_BELL  | BIT_NORMAL_OPEN;
//	b_LdTmpBufRam(RST_PORT)         =SILK_RST   | BIT_NORMAL_OPEN;             
//	b_LdTmpBufRam(ERR_PORT)         =SILK_ERR   | BIT_NORMAL_OPEN;     
//	b_LdTmpBufRam(HOP_PORT)         =SILK_HOP   | BIT_NORMAL_OPEN;     
//	b_LdTmpBufRam(HCL_PORT)         =SILK_HCL   | BIT_NORMAL_OPEN;
	
//	b_LdTmpBufRam(OP_PORT)          =SILK_OP    | BIT_NORMAL_OPEN;     
//	b_LdTmpBufRam(CL_PORT)          =SILK_CL    | BIT_NORMAL_OPEN;     
//	b_LdTmpBufRam(OP_S_PORT)        =SILK_OP_S  | BIT_NORMAL_OPEN;     
//	b_LdTmpBufRam(CL_S_PORT)        =SILK_CL_S  | BIT_NORMAL_OPEN;
//	b_LdTmpBufRam(BK2_PORT)         =SILK_BK2   | BIT_NORMAL_OPEN;             
//	b_LdTmpBufRam(D_S_PORT)         =SILK_D_S   | BIT_NORMAL_OPEN;     
//	b_LdTmpBufRam(GBR_PORT)         =SILK_GBR   | BIT_NORMAL_CLOSE;     
//	b_LdTmpBufRam(BK1_PORT)         =SILK_BK1   | BIT_NORMAL_OPEN;
	
//	b_LdTmpBufRam(UP_PORT)          =SILK_UP    | BIT_NORMAL_OPEN;
//	b_LdTmpBufRam(DN_PORT)          =SILK_DN    | BIT_NORMAL_OPEN;     
//	b_LdTmpBufRam(P1_PORT)          =SILK_P1    | BIT_NORMAL_OPEN;     
//	b_LdTmpBufRam(P2_PORT)          =SILK_P2    | BIT_NORMAL_OPEN;             
//	b_LdTmpBufRam(P3_PORT)          =SILK_P3    | BIT_NORMAL_OPEN;
//	b_LdTmpBufRam(P4_PORT)          =SILK_P4    | BIT_NORMAL_OPEN;     
//	b_LdTmpBufRam(DAC_PORT)         =SILK_DAC   | BIT_NORMAL_OPEN;     
	
	/////////////
//	b_LdTmpBufRam(SLOW_DOOR_PORT)   =(SILK_SLOW_DOOR	| BIT_NORMAL_OPEN);
//	b_LdTmpBufRam(VIRTUAL_Y1_PORT)  =(SILK_VIRTUAL_Y1	| BIT_NORMAL_OPEN);     
//	b_LdTmpBufRam(VIRTUAL_Y2_PORT)  =(SILK_VIRTUAL_Y2	| BIT_NORMAL_OPEN);     
//	b_LdTmpBufRam(VIRTUAL_Y3_PORT)  =(SILK_VIRTUAL_Y3	| BIT_NORMAL_OPEN);     
//	b_LdTmpBufRam(VIRTUAL_Y4_PORT)  =(SILK_VIRTUAL_Y4	| BIT_NORMAL_OPEN);     
//	b_LdTmpBufRam(VIRTUAL_Y5_PORT)  =(SILK_VIRTUAL_Y5	| BIT_NORMAL_OPEN);     
//	b_LdTmpBufRam(VIRTUAL_Y6_PORT)  =(SILK_VIRTUAL_Y6	| BIT_NORMAL_OPEN);     
//	b_LdTmpBufRam(VIRTUAL_Y7_PORT)  =(SILK_VIRTUAL_Y7	| BIT_NORMAL_OPEN);     
	
	
//	b_LdTmpBufRam(DOOR_HOLD_PORT)   =(SILK_DOOR_HOLD	| BIT_NORMAL_OPEN);
//	b_LdTmpBufRam(VIRTUAL_X1_PORT)  =(SILK_VIRTUAL_X1	| BIT_NORMAL_OPEN);
//	b_LdTmpBufRam(VIRTUAL_X2_PORT) 	=(SILK_VIRTUAL_X2	| BIT_NORMAL_OPEN);
//	b_LdTmpBufRam(VIRTUAL_X3_PORT) 	=(SILK_VIRTUAL_X3	| BIT_NORMAL_OPEN);
//	b_LdTmpBufRam(VIRTUAL_X4_PORT)	=(SILK_VIRTUAL_X4	| BIT_NORMAL_OPEN);
//	b_LdTmpBufRam(VIRTUAL_X5_PORT)	=(SILK_VIRTUAL_X5	| BIT_NORMAL_OPEN);
//	b_LdTmpBufRam(VIRTUAL_X6_PORT)	=(SILK_VIRTUAL_X6	| BIT_NORMAL_OPEN);
//	b_LdTmpBufRam(VIRTUAL_X7_PORT)	=(SILK_VIRTUAL_X7	| BIT_NORMAL_OPEN);
	
	
/////////////	flash_write_DspChar(FAN_PORT);		//block5

/////////////////////////////////////////////////////////
/////////////////////block5//////////////////////////////
/////////////////////////////////////////////////////////

	


/////////////////////////////////////////////////////////
/////////////////////block2//////////////////////////////
/////////////////////////////////////////////////////////
	//////////////user group/////////////////////////////
//////////////////	
	GetFlashDataToBufRam(F_ManualSpeed);	

/*
//	b_LdTmpBufRam(F_Ver0)           = VERSION_0;		//0
//	b_LdTmpBufRam(F_Ver1)           = VERSION_1;		//0
//	b_LdTmpBufRam(F_Ver2)           = VERSION_2;		//0
//	b_LdTmpBufRam(F_Bd_Id)          = (IO | MAN_USE);   //1        
	
	
//	b_LdTmpBufRam(F_Passward0)      = '0';				//2	autolanding== 5
//	b_LdTmpBufRam(F_Passward1)      = '0';				//2
//	b_LdTmpBufRam(F_Passward2)      = '0';				//2
//	b_LdTmpBufRam(F_Passward3)      = '0';				//2
*/


	
//	i_LdTmpBufRam(F_SerialNm10)     = 0;				//not use
	
//	b_LdTmpBufRam(F_ErrStopCnt)     = 0xff;				//19
//	b_LdTmpBufRam(F_NormalDsp)      = 0x0;				//6
//	b_LdTmpBufRam(F_UserLamp1)      = 0;				//3		//auto
//	b_LdTmpBufRam(F_UserLamp2)      = 1;				//4		//manual
//	b_LdTmpBufRam(F_UserLamp3)      = 6;				//22	//vip 
//	b_LdTmpBufRam(F_UserLamp4)      = 3;				//24    //fire
//	b_LdTmpBufRam(F_GroupNm)        = 0;				//13
//	b_LdTmpBufRam(F_LocalNm)        = 0;				//14
//	b_LdTmpBufRam(F_PcbType)        = 0;				//???
	
//	i_LdTmpBufRam(F_StopPulse0)     = 1000;				//31
	
//	b_LdTmpBufRam(F_year)           = 0;				//18
//	b_LdTmpBufRam(F_month)          = 0;				//18
//	b_LdTmpBufRam(F_day)            = 0;				//18
	
//	b_LdTmpBufRam(F_Company)        = COMPANY;			//20
//	b_LdTmpBufRam(F_SystemSet)      = 0x0;				//30 n_law,old_law,n_spd,o_spd
	

////////////////////even/odd group(�汝� 礎熱)///////////////////
//	b_LdTmpBufRam(F_NonService0)    = Init_ALL_FF;
//	b_LdTmpBufRam(F_NonService1)    = Init_ALL_FF;
//	b_LdTmpBufRam(F_NonService2)    = Init_ALL_FF;
//	b_LdTmpBufRam(F_NonService3)    = Init_ALL_FF;
//	b_LdTmpBufRam(F_NonService4)    = Init_ALL_FF;
//	b_LdTmpBufRam(F_NonService5)    = Init_ALL_FF;
//	b_LdTmpBufRam(F_NonService6)    = Init_ALL_FF;
//	b_LdTmpBufRam(F_NonService7)    = Init_ALL_FF;
///////////////////////////////////////////////////////////////
	
	
//	b_LdTmpBufRam(F_ManualSpeed)    = P3_SPD;          
//	b_LdTmpBufRam(F_BatterySpeed)   = NONE_USE_SPD;      
//	b_LdTmpBufRam(F_DecreaseSpeed)  = P1P2_SPD;                    
//	b_LdTmpBufRam(F_FhmSpeed)       = NONE_USE_SPD;     
//	b_LdTmpBufRam(F_Etc1Speed)      = NONE_USE_SPD;     
//	b_LdTmpBufRam(F_Etc2Speed)      = NONE_USE_SPD;     
//	b_LdTmpBufRam(F_Speed30)        = NONE_USE_SPD;     
//	b_LdTmpBufRam(F_Speed45)        = P1P3_SPD;              
//	b_LdTmpBufRam(F_Speed60)        = P1P2P3_SPD;                    
//	b_LdTmpBufRam(F_Speed90)        = NONE_USE_SPD;     
//	b_LdTmpBufRam(F_Speed105)       = NONE_USE_SPD;     
//	b_LdTmpBufRam(F_Speed120)       = NONE_USE_SPD;     
//	b_LdTmpBufRam(F_Speed150)       = NONE_USE_SPD;     
//	b_LdTmpBufRam(F_Speed180)       = NONE_USE_SPD;     
//	b_LdTmpBufRam(F_Speed210)       = NONE_USE_SPD;    
//	b_LdTmpBufRam(F_ElevSpeed)      = SPEED_60;
//	b_LdTmpBufRam(F_LimitSpeed)     = SPEED_210;
//	b_LdTmpBufRam(F_Su1Sd1_Velocity)= 90;      //mpm
//	b_LdTmpBufRam(F_Su2Sd2_Velocity)= 90;      //mpm
//	b_LdTmpBufRam(F_X0X1_Velocity)  = 210;     //mpm
//	b_LdTmpBufRam(F_AutoLandingMode)= 0;     			//no Auto landing(user group 2)
	
	
	b_LdTmpBufRam(F_Su2Sd2_Velocity)= 0;      	//mpm
	b_LdTmpBufRam(F_X0X1_Velocity)  = 0;     	//mpm
	b_LdTmpBufRam(F_AutoLandingMode)= 0;     	//no Auto landing(user group 2)
	

	b_LdTmpBufRam(F_ManualSpeed)    = P3_SPD;                   
	b_LdTmpBufRam(F_BatterySpeed)   = NONE_USE_SPD;      
	b_LdTmpBufRam(F_DecreaseSpeed)  = P1P2_SPD;                    
	b_LdTmpBufRam(F_FhmSpeed)       = NONE_USE_SPD;     
	b_LdTmpBufRam(F_Speed1)        	= P1P3_SPD;     
	b_LdTmpBufRam(F_Speed2)        	= P2P3_SPD;              
	b_LdTmpBufRam(F_Speed3)        	= P1P2P3_SPD;                    
//	b_LdTmpBufRam(F_LULD_MPM_SPD3)  = 0;     
	b_LdTmpBufRam(F_SU2SD2_V_SPD3)	= 0;    
	b_LdTmpBufRam(F_X0X1_V_SPD3)  	= 0;   

	flash_write_DspChar(F_ManualSpeed);	// block2
	
/////////////////////////////////////////////////////////
/////////////////////block2//////////////////////////////
/////////////////////////////////////////////////////////

	
/*	
//////////////display gorup///////////////////block0////////////////////
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
///////////////////////////////////////////////////////////////
*/
	
	DefaultEncoderRpmMpm();
	CaluDecreasePulse();

    asm("RESET");
}



void  __attribute__((section(".usercode"))) DF_Mode(void)
{
    LocalType  i;

	SaveVerify = 0x55;

/////////////////////////////////////////////////////////
/////////////////////block1//////////////////////////////
/////////////////////////////////////////////////////////
	GetFlashDataToBufRam(F_TopFlr);	//block1

	//floor group	
//	b_LdTmpBufRam(F_TopFlr)         = Init_TopFlr;
//	b_LdTmpBufRam(F_PrkFlr)         = Init_PrkFlr;
	b_LdTmpBufRam(F_FixFloor)       = 0;                  // 1 flloor
//	b_LdTmpBufRam(F_OneStopFlr)     = Init_OneStopFlr;
//	b_LdTmpBufRam(F_FireSafeFlr)    = Init_FireSafeFlr;
//	b_LdTmpBufRam(F_X7SafeFlr)      = Init_X7SafeFlr;
//	b_LdTmpBufRam(F_WaterSafeFlr)   = Init_WaterSafeFlr;
//	b_LdTmpBufRam(F_StartFloor)     = START_FLOOR;   	
//	b_LdTmpBufRam(F_KidsKeyCnt)     = Init_KidsKeyCnt;
//	b_LdTmpBufRam(F_X6SafeFlr)      = Init_X6SafeFlr;
//	b_LdTmpBufRam(F_X5SafeFlr)      = Init_X5SafeFlr;
		
	
/* not use		                              //     7 ,      6,      5,        4,         3,        2,       1,     0
//	b_LdTmpBufRam(F_NcNoBit0)       = Init_ALL_FF;  //                                                                     emg
//	b_LdTmpBufRam(F_NcNoBit1)       = Init_ALL_FF;  //                                                                     su1
//	b_LdTmpBufRam(F_NcNoBit2)       = Init_ALL_FF;  //                                                                     rg
//	b_LdTmpBufRam(F_NcNoBit3)       = Init_ALL_FF;  //                                                                     fr1
//	b_LdTmpBufRam(F_NcNoBit4)       = Init_ALL_FF;  //                                                                     x0
//	b_LdTmpBufRam(F_NcNoBit5)       = Init_ALL_FF;  //                                                                     fs0
//	b_LdTmpBufRam(F_NcNoBit6)       = Init_ALL_FF;  //                                                                     op
//	b_LdTmpBufRam(F_NcNoBit7)       = Init_ALL_FF;  //                                                                     fan
//	b_LdTmpBufRam(F_NcNoBit8)       = Init_ALL_FF;  //                                                                     up
*/		
		
	//onoff2 group		
//	bit_LdTmpBufRamSet  (F_OnOff0,bFhmOnOff             % 8);
//	bit_LdTmpBufRamSet  (F_OnOff0,bDoorJumperOff        % 8); 
//	bit_LdTmpBufRamReset(F_OnOff0,bEncoderPhase         % 8);
//	bit_LdTmpBufRamSet  (F_OnOff0,bWardPriority         % 8);
//	bit_LdTmpBufRamReset(F_OnOff0,bNonStop              % 8);
//	bit_LdTmpBufRamSet  (F_OnOff0,bOpenTotalOnOff       % 8);
//	bit_LdTmpBufRamSet  (F_OnOff0,bCloseTotalOnOff      % 8);
//	bit_LdTmpBufRamSet  (F_OnOff0,bOpenWaitToTalOnOff   % 8);
		
//	bit_LdTmpBufRamSet  (F_OnOff1,bCarDoor1Use      	% 8);
//	bit_LdTmpBufRamReset(F_OnOff1,bCarDoor2Use      	% 8);
//	bit_LdTmpBufRamSet  (F_OnOff1,bHoleDoor1Use     	% 8);
//	bit_LdTmpBufRamReset(F_OnOff1,bHoleDoor2Use     	% 8);
//	bit_LdTmpBufRamReset(F_OnOff1,bSubSafety        	% 8);
	bit_LdTmpBufRamSet(F_OnOff1,bBrkMgtUse        	    % 8);	//on
	bit_LdTmpBufRamReset(F_OnOff1,bEncoderUse       	% 8);   //not use
	bit_LdTmpBufRamSet(F_OnOff1,bRelevelOnOff     		% 8);   //on
		
	bit_LdTmpBufRamReset(F_OnOff2,bOilLopeTypeChk   	% 8);	//oil type
//	bit_LdTmpBufRamReset(F_OnOff2,bOnlyOneCall      	% 8);
//	bit_LdTmpBufRamReset(F_OnOff2,bManualSusChk     	% 8);
	bit_LdTmpBufRamReset(F_OnOff2,bBrkOpenUse       	% 8);	//off
//	bit_LdTmpBufRamReset(F_OnOff2,bKidsKeyChkUse    	% 8);
//	bit_LdTmpBufRamReset(F_OnOff2,bCarKeyFirstService  	% 8);
//	bit_LdTmpBufRamReset(F_OnOff2,bFamilyService    	% 8);
//	bit_LdTmpBufRamReset(F_OnOff2,bOpenOutSet    		% 8);
	
	
//	bit_LdTmpBufRamReset(F_OnOff3,bSafetyValidLR    	% 8);
//	bit_LdTmpBufRamReset(F_OnOff3,bFloorSel             % 8);
//	bit_LdTmpBufRamReset(F_OnOff3,bRunOpenSetClear      % 8);
//	bit_LdTmpBufRamReset(F_OnOff3,bUcmpFeedback      	% 8);
//	bit_LdTmpBufRamReset(F_OnOff3,bManWorkingChk      	% 8);
//	bit_LdTmpBufRamSet(F_OnOff3,bEncoderCpy         	% 8);
	
	
	
//timer group
	b_LdTmpBufRam(F_OpWtTm)         = Init_OpWtTm;			//0      
	b_LdTmpBufRam(F_OpTtTm)         = Init_OpTtTm; 			//1 		
	b_LdTmpBufRam(F_FixFloorTime)   = 185; 	//Init_FixFloorTime;   	//2
	b_LdTmpBufRam(F_NextFlrTime)    = 30;   //Init_NextFlrTime;    	//3
	b_LdTmpBufRam(F_LuLdOffTime)    = 15;   //Init_LuLdOffTime;    	//4
//	b_LdTmpBufRam(F_FanTime)        = Init_FanTime;        	//5
//	b_LdTmpBufRam(F_LightTime)      = Init_LightTime;      	//6
//	b_LdTmpBufRam(F_OpClWaitTime)   = Init_OpClWTime;      	//7
//	b_LdTmpBufRam(F_DrJmpChkTime)   = Init_DrJmpChkTime;   	//8(power run time/power save)
//	b_LdTmpBufRam(F_DirTime)        = Init_DirTime;			//9
//	b_LdTmpBufRam(F_VoiceTime)      = Init_VoiceTime;		//10
//	b_LdTmpBufRam(F_BrkMgtTime)     = Init_BrkMgtTime;		//11
//	b_LdTmpBufRam(F_ReOpTime)       = Init_ReOpTime;       	//12(open hold time/door open)
	b_LdTmpBufRam(F_StTm1)          = 0;          			//13(p4 on time)
	b_LdTmpBufRam(F_StTm2)          = 0;              		//14(updn on time)
	b_LdTmpBufRam(F_StTm3)          = 0;          			//15(bk2 on time)
	b_LdTmpBufRam(F_StTm4)          = 0;          			//16(bk1 on time)
	b_LdTmpBufRam(F_StTm5)          = 10;          			//17(run on time)		
	b_LdTmpBufRam(F_RunOffTime)		= 0;					//18(run off time)        
	b_LdTmpBufRam(F_Bk1OffTime)     = 0;					//19(bk1 off time)
	b_LdTmpBufRam(F_Bk2OffTime)     = 0;					//20(bk2 off time)
	b_LdTmpBufRam(F_UDOffTime)      = 9;					//21(updn off time)      
	b_LdTmpBufRam(F_P4OffTime)      = 12;     				//22(p4 off time)
	b_LdTmpBufRam(F_SolOnTime)      = Init_SolOn_Time;		//23(sol on time)        
	b_LdTmpBufRam(F_DoorWaitTime)   = Init_DoorWait_Time;  //24(door start time)

	if(USE_CHECK != MAN_USE){
		b_LdTmpBufRam(F_OpWtTm)         = 30;					//0      
		b_LdTmpBufRam(F_OpTtTm)         = 30; 					//1 		

		b_LdTmpBufRam(F_SolOnTime)      = 40;					//23(sol on time)        
		b_LdTmpBufRam(F_DoorWaitTime)   = 20;  					//24(door start time)
	}


	flash_write_DspChar(F_TopFlr);		//block1
/////////////////////////////////////////////////////////
/////////////////////block1//////////////////////////////
/////////////////////////////////////////////////////////
	
	
/*
	/////////////////////wait floor group//////////////////////////////
	for(i=0;i<32;i++){
		b_LdTmpBufRam(F_0506+i)           = DISABLE_FLR;
	}
	
	flash_write_DspChar(F_BLOCK3);
	//////////////////////////////////////////////////////////////
*/
	



/////////////////////////////////////////////////////////
/////////////////////block4//////////////////////////////
/////////////////////////////////////////////////////////

	/////////////////////ncno group//////////////////////////////

	GetFlashDataToBufRam(EMG_PORT);	

//	b_LdTmpBufRam(EMG_PORT)         =SILK_EMG   | BIT_NORMAL_OPEN;			//1     64    ncno1 group
//	b_LdTmpBufRam(PRK_PORT)         =SILK_PRK   | BIT_NORMAL_CLOSE;         //1     
//	b_LdTmpBufRam(AUTO_PORT)        =SILK_AUTO  | BIT_NORMAL_OPEN;         	//1     
//	b_LdTmpBufRam(U_B_PORT)         =SILK_U_B   | BIT_NORMAL_OPEN;          //1             
//	b_LdTmpBufRam(D_B_PORT)         =SILK_D_B   | BIT_NORMAL_OPEN;          //1     65
	b_LdTmpBufRam(OLS_PORT)         =SILK_OLS   | BIT_NORMAL_OPEN;          //1     
//	b_LdTmpBufRam(GS_PORT)          =SILK_GS    | BIT_NORMAL_OPEN;      	//1     
//	b_LdTmpBufRam(DS_PORT)          =SILK_DS    | BIT_NORMAL_OPEN;       	//1             
	
//	b_LdTmpBufRam(SU1_PORT)         =SILK_SU1   | BIT_NORMAL_CLOSE;         //1     66
//	b_LdTmpBufRam(SD1_PORT)         =SILK_SD1   | BIT_NORMAL_CLOSE;         //1     
//	b_LdTmpBufRam(SFT_PORT)         =SILK_SFT   | BIT_NORMAL_OPEN;          //1     
//	b_LdTmpBufRam(OVL_PORT)         =SILK_OVL   | BIT_NORMAL_OPEN;          //1             
//	b_LdTmpBufRam(ULS_PORT)         =SILK_ULS   | BIT_NORMAL_OPEN;          //1     67
//	b_LdTmpBufRam(DLS_PORT)         =SILK_DLS   | BIT_NORMAL_OPEN;          //1     
//	b_LdTmpBufRam(LU_PORT)          =SILK_LU    | BIT_NORMAL_OPEN;          //1     
//	b_LdTmpBufRam(LD_PORT)          =SILK_LD    | BIT_NORMAL_OPEN;          //1             
	
//	b_LdTmpBufRam(RG_PORT)          =SILK_GR    | BIT_NORMAL_CLOSE;			//1     68
//	b_LdTmpBufRam(BAT_PORT)         =SILK_BAT   | BIT_NORMAL_OPEN;			//1     
//	b_LdTmpBufRam(PASS_PORT)        =SILK_PASS  | BIT_NORMAL_OPEN;         	//1     
//	b_LdTmpBufRam(FIRE_PORT)        =SILK_FIRE  | BIT_NORMAL_OPEN;         	//1             
//	b_LdTmpBufRam(WATER_PORT)       =SILK_WATER | BIT_NORMAL_OPEN;        	//1     69
//	b_LdTmpBufRam(FULL_PORT)        =SILK_FULL  | BIT_NORMAL_OPEN;         	//1     
//	b_LdTmpBufRam(MM_PORT)          =SILK_MM    | BIT_NORMAL_OPEN;         	//1     
//	b_LdTmpBufRam(FHM_PORT)         =SILK_FHM   | BIT_NORMAL_OPEN;          //1             
	
//	b_LdTmpBufRam(FR1_PORT)         =SILK_FR1   | BIT_NORMAL_OPEN;          //1     70
//	b_LdTmpBufRam(FR2_PORT)         =SILK_FR2   | BIT_NORMAL_OPEN;          //1     
	b_LdTmpBufRam(GS2_PORT)         =SILK_GS2   | BIT_NORMAL_OPEN;          //1     
//	b_LdTmpBufRam(DS2_PORT)         =SILK_DS2   | BIT_NORMAL_OPEN;          //1             
//	b_LdTmpBufRam(SU2_PORT)         =SILK_SU2   | BIT_NORMAL_OPEN;          //1     71
//	b_LdTmpBufRam(SD2_PORT)         =SILK_SD2   | BIT_NORMAL_OPEN;          //1     
//	b_LdTmpBufRam(BM_PORT)          =SILK_BM    | BIT_NORMAL_OPEN;          //1     
	b_LdTmpBufRam(INV_PORT)         =SILK_INV   | BIT_NORMAL_OPEN;         //1             
	
//	b_LdTmpBufRam(X0_PORT)          =SILK_X0    | BIT_NORMAL_OPEN;       	//1     72	ncno2 group
//	b_LdTmpBufRam(X1_PORT)          =SILK_X1    | BIT_NORMAL_OPEN;      	//1     
//	b_LdTmpBufRam(X2_PORT)          =SILK_X2    | BIT_NORMAL_OPEN;			//1     
//	b_LdTmpBufRam(X3_PORT)          =SILK_X3    | BIT_NORMAL_OPEN;			//1             
//	b_LdTmpBufRam(X4_PORT)          =SILK_X4    | BIT_NORMAL_OPEN;			//1     73
//	b_LdTmpBufRam(X5_PORT)          =SILK_X5    | BIT_NORMAL_OPEN;			//1     
//	b_LdTmpBufRam(X6_PORT)          =SILK_X6    | BIT_NORMAL_OPEN;			//1     
	b_LdTmpBufRam(X7_PORT)          =SILK_X7    | BIT_NORMAL_OPEN;			//1             
	
//	b_LdTmpBufRam(FS0_PORT)         =SILK_FS0   | BIT_NORMAL_OPEN;          //1     74
//	b_LdTmpBufRam(FS1_PORT)         =SILK_FS1   | BIT_NORMAL_CLOSE;         //1     
	b_LdTmpBufRam(FS2_PORT)         =SILK_FS2   | BIT_NORMAL_OPEN;          //1     
//	b_LdTmpBufRam(FS3_PORT)         =SILK_FS3   | BIT_NORMAL_OPEN;          //1             
//	b_LdTmpBufRam(FS4_PORT)         =SILK_FS4   | BIT_NORMAL_OPEN;          //1     75
//	b_LdTmpBufRam(DER_PORT)         =SILK_DER   | BIT_NORMAL_OPEN;          //1     
//	b_LdTmpBufRam(FID_PORT)         =SILK_FID   | BIT_NORMAL_OPEN;          //1     
//	b_LdTmpBufRam(UND_PORT)         =SILK_UND   | BIT_NORMAL_OPEN;          //1     
	
	
/////////mainsub door group////////////////	
//	b_LdTmpBufRam(F_SubDoorFlr1)    = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr2)    = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr3)    = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr4)    = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr5)    = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr6)    = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr7)    = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr8)    = Init_SubDoorFlr1;
	
//	b_LdTmpBufRam(F_SubDoorFlr9)    = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr10)   = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr11)   = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr12)   = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr13)   = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr14)   = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr15)   = Init_SubDoorFlr1;
//	b_LdTmpBufRam(F_SubDoorFlr16)   = Init_SubDoorFlr1;		
	

	if(USE_CHECK != MAN_USE){
		if(New_Law_SystemChk()){
			b_LdTmpBufRam(FS2_PORT)         =SILK_FS2   | BIT_NORMAL_CLOSE;          //1     
		}
		else{
			b_LdTmpBufRam(GS2_PORT)         =SILK_GS2   | BIT_NORMAL_CLOSE;          //1     
		}

		b_LdTmpBufRam(OLS_PORT)         	=SILK_OLS   | BIT_NORMAL_CLOSE;         //1     
		b_LdTmpBufRam(X7_PORT)          	=SILK_X7    | BIT_NORMAL_CLOSE;			//1             
	}
	
	flash_write_DspChar(EMG_PORT);		//block4
/////////////////////////////////////////////////////////
/////////////////////block4//////////////////////////////
/////////////////////////////////////////////////////////
	



/////////////////////////////////////////////////////////
/////////////////////block5//////////////////////////////
/////////////////////////////////////////////////////////
	////////////////ncno3 group/////////////////////////////////
////////////////////	GetFlashDataToBufRam(FAN_PORT);	

//	b_LdTmpBufRam(FAN_PORT)         =SILK_FAN   | BIT_NORMAL_OPEN;
//	b_LdTmpBufRam(LIT_PORT)         =SILK_LIT   | BIT_NORMAL_CLOSE;  //     
//	b_LdTmpBufRam(BUZ_PORT)         =SILK_BUZ   | BIT_NORMAL_OPEN;     
//	b_LdTmpBufRam(BELL_PORT)        =SILK_BELL  | BIT_NORMAL_OPEN;
//	b_LdTmpBufRam(RST_PORT)         =SILK_RST   | BIT_NORMAL_OPEN;             
//	b_LdTmpBufRam(ERR_PORT)         =SILK_ERR   | BIT_NORMAL_OPEN;     
//	b_LdTmpBufRam(HOP_PORT)         =SILK_HOP   | BIT_NORMAL_OPEN;     
//	b_LdTmpBufRam(HCL_PORT)         =SILK_HCL   | BIT_NORMAL_OPEN;
	
//	b_LdTmpBufRam(OP_PORT)          =SILK_OP    | BIT_NORMAL_OPEN;     
//	b_LdTmpBufRam(CL_PORT)          =SILK_CL    | BIT_NORMAL_OPEN;     
//	b_LdTmpBufRam(OP_S_PORT)        =SILK_OP_S  | BIT_NORMAL_OPEN;     
//	b_LdTmpBufRam(CL_S_PORT)        =SILK_CL_S  | BIT_NORMAL_OPEN;
//	b_LdTmpBufRam(BK2_PORT)         =SILK_BK2   | BIT_NORMAL_OPEN;             
//	b_LdTmpBufRam(D_S_PORT)         =SILK_D_S   | BIT_NORMAL_OPEN;     
//	b_LdTmpBufRam(GBR_PORT)         =SILK_GBR   | BIT_NORMAL_CLOSE;     
//	b_LdTmpBufRam(BK1_PORT)         =SILK_BK1   | BIT_NORMAL_OPEN;
	
//	b_LdTmpBufRam(UP_PORT)          =SILK_UP    | BIT_NORMAL_OPEN;
//	b_LdTmpBufRam(DN_PORT)          =SILK_DN    | BIT_NORMAL_OPEN;     
//	b_LdTmpBufRam(P1_PORT)          =SILK_P1    | BIT_NORMAL_OPEN;     
//	b_LdTmpBufRam(P2_PORT)          =SILK_P2    | BIT_NORMAL_OPEN;             
//	b_LdTmpBufRam(P3_PORT)          =SILK_P3    | BIT_NORMAL_OPEN;
//	b_LdTmpBufRam(P4_PORT)          =SILK_P4    | BIT_NORMAL_OPEN;     
//	b_LdTmpBufRam(DAC_PORT)         =SILK_DAC   | BIT_NORMAL_OPEN;     
	
	/////////////
//	b_LdTmpBufRam(SLOW_DOOR_PORT)   =(SILK_SLOW_DOOR	| BIT_NORMAL_OPEN);
//	b_LdTmpBufRam(VIRTUAL_Y1_PORT)  =(SILK_VIRTUAL_Y1	| BIT_NORMAL_OPEN);     
//	b_LdTmpBufRam(VIRTUAL_Y2_PORT)  =(SILK_VIRTUAL_Y2	| BIT_NORMAL_OPEN);     
//	b_LdTmpBufRam(VIRTUAL_Y3_PORT)  =(SILK_VIRTUAL_Y3	| BIT_NORMAL_OPEN);     
//	b_LdTmpBufRam(VIRTUAL_Y4_PORT)  =(SILK_VIRTUAL_Y4	| BIT_NORMAL_OPEN);     
//	b_LdTmpBufRam(VIRTUAL_Y5_PORT)  =(SILK_VIRTUAL_Y5	| BIT_NORMAL_OPEN);     
//	b_LdTmpBufRam(VIRTUAL_Y6_PORT)  =(SILK_VIRTUAL_Y6	| BIT_NORMAL_OPEN);     
//	b_LdTmpBufRam(VIRTUAL_Y7_PORT)  =(SILK_VIRTUAL_Y7	| BIT_NORMAL_OPEN);     
	
	
//	b_LdTmpBufRam(DOOR_HOLD_PORT)   =(SILK_DOOR_HOLD	| BIT_NORMAL_OPEN);
//	b_LdTmpBufRam(VIRTUAL_X1_PORT)  =(SILK_VIRTUAL_X1	| BIT_NORMAL_OPEN);
//	b_LdTmpBufRam(VIRTUAL_X2_PORT) 	=(SILK_VIRTUAL_X2	| BIT_NORMAL_OPEN);
//	b_LdTmpBufRam(VIRTUAL_X3_PORT) 	=(SILK_VIRTUAL_X3	| BIT_NORMAL_OPEN);
//	b_LdTmpBufRam(VIRTUAL_X4_PORT)	=(SILK_VIRTUAL_X4	| BIT_NORMAL_OPEN);
//	b_LdTmpBufRam(VIRTUAL_X5_PORT)	=(SILK_VIRTUAL_X5	| BIT_NORMAL_OPEN);
//	b_LdTmpBufRam(VIRTUAL_X6_PORT)	=(SILK_VIRTUAL_X6	| BIT_NORMAL_OPEN);
//	b_LdTmpBufRam(VIRTUAL_X7_PORT)	=(SILK_VIRTUAL_X7	| BIT_NORMAL_OPEN);
	
	
/////////////	flash_write_DspChar(FAN_PORT);		//block5

/////////////////////////////////////////////////////////
/////////////////////block5//////////////////////////////
/////////////////////////////////////////////////////////

	


/////////////////////////////////////////////////////////
/////////////////////block2//////////////////////////////
/////////////////////////////////////////////////////////
	//////////////user group/////////////////////////////
//////////////////	
	GetFlashDataToBufRam(F_ManualSpeed);	

/*
//	b_LdTmpBufRam(F_Ver0)           = VERSION_0;		//0
//	b_LdTmpBufRam(F_Ver1)           = VERSION_1;		//0
//	b_LdTmpBufRam(F_Ver2)           = VERSION_2;		//0
//	b_LdTmpBufRam(F_Bd_Id)          = (IO | MAN_USE);   //1        
	
	
//	b_LdTmpBufRam(F_Passward0)      = '0';				//2	autolanding== 5
//	b_LdTmpBufRam(F_Passward1)      = '0';				//2
//	b_LdTmpBufRam(F_Passward2)      = '0';				//2
//	b_LdTmpBufRam(F_Passward3)      = '0';				//2
*/


	
//	i_LdTmpBufRam(F_SerialNm10)     = 0;				//not use
	
//	b_LdTmpBufRam(F_ErrStopCnt)     = 0xff;				//19
//	b_LdTmpBufRam(F_NormalDsp)      = 0x0;				//6
//	b_LdTmpBufRam(F_UserLamp1)      = 0;				//3		//auto
//	b_LdTmpBufRam(F_UserLamp2)      = 1;				//4		//manual
//	b_LdTmpBufRam(F_UserLamp3)      = 6;				//22	//vip 
//	b_LdTmpBufRam(F_UserLamp4)      = 3;				//24    //fire
//	b_LdTmpBufRam(F_GroupNm)        = 0;				//13
//	b_LdTmpBufRam(F_LocalNm)        = 0;				//14
//	b_LdTmpBufRam(F_PcbType)        = 0;				//???
	
//	i_LdTmpBufRam(F_StopPulse0)     = 1000;				//31
	
//	b_LdTmpBufRam(F_year)           = 0;				//18
//	b_LdTmpBufRam(F_month)          = 0;				//18
//	b_LdTmpBufRam(F_day)            = 0;				//18
	
//	b_LdTmpBufRam(F_Company)        = COMPANY;			//20
//	b_LdTmpBufRam(F_SystemSet)      = 0x0;				//30 n_law,old_law,n_spd,o_spd
	

////////////////////even/odd group(�汝� 礎熱)///////////////////
//	b_LdTmpBufRam(F_NonService0)    = Init_ALL_FF;
//	b_LdTmpBufRam(F_NonService1)    = Init_ALL_FF;
//	b_LdTmpBufRam(F_NonService2)    = Init_ALL_FF;
//	b_LdTmpBufRam(F_NonService3)    = Init_ALL_FF;
//	b_LdTmpBufRam(F_NonService4)    = Init_ALL_FF;
//	b_LdTmpBufRam(F_NonService5)    = Init_ALL_FF;
//	b_LdTmpBufRam(F_NonService6)    = Init_ALL_FF;
//	b_LdTmpBufRam(F_NonService7)    = Init_ALL_FF;
///////////////////////////////////////////////////////////////
	
	
//	b_LdTmpBufRam(F_ManualSpeed)    = P3_SPD;          
//	b_LdTmpBufRam(F_BatterySpeed)   = NONE_USE_SPD;      
//	b_LdTmpBufRam(F_DecreaseSpeed)  = P1P2_SPD;                    
//	b_LdTmpBufRam(F_FhmSpeed)       = NONE_USE_SPD;     
//	b_LdTmpBufRam(F_Etc1Speed)      = NONE_USE_SPD;     
//	b_LdTmpBufRam(F_Etc2Speed)      = NONE_USE_SPD;     
//	b_LdTmpBufRam(F_Speed30)        = NONE_USE_SPD;     
//	b_LdTmpBufRam(F_Speed45)        = P1P3_SPD;              
//	b_LdTmpBufRam(F_Speed60)        = P1P2P3_SPD;                    
//	b_LdTmpBufRam(F_Speed90)        = NONE_USE_SPD;     
//	b_LdTmpBufRam(F_Speed105)       = NONE_USE_SPD;     
//	b_LdTmpBufRam(F_Speed120)       = NONE_USE_SPD;     
//	b_LdTmpBufRam(F_Speed150)       = NONE_USE_SPD;     
//	b_LdTmpBufRam(F_Speed180)       = NONE_USE_SPD;     
//	b_LdTmpBufRam(F_Speed210)       = NONE_USE_SPD;    
//	b_LdTmpBufRam(F_ElevSpeed)      = SPEED_60;
//	b_LdTmpBufRam(F_LimitSpeed)     = SPEED_210;
//	b_LdTmpBufRam(F_Su1Sd1_Velocity)= 90;      //mpm
//	b_LdTmpBufRam(F_Su2Sd2_Velocity)= 90;      //mpm
//	b_LdTmpBufRam(F_X0X1_Velocity)  = 210;     //mpm
//	b_LdTmpBufRam(F_AutoLandingMode)= 0;     			//no Auto landing(user group 2)
	

	b_LdTmpBufRam(F_Su2Sd2_Velocity)= 0;      	//mpm
	b_LdTmpBufRam(F_X0X1_Velocity)  = 0;     	//mpm
	b_LdTmpBufRam(F_AutoLandingMode)= 0;     	//no Auto landing(user group 2)
	

	b_LdTmpBufRam(F_ManualSpeed)    = P3_SPD;                   
	b_LdTmpBufRam(F_BatterySpeed)   = NONE_USE_SPD;      
	b_LdTmpBufRam(F_DecreaseSpeed)  = P3_SPD;                    
	b_LdTmpBufRam(F_FhmSpeed)       = NONE_USE_SPD;     
	b_LdTmpBufRam(F_Speed1)        	= P1P3_SPD;     
	b_LdTmpBufRam(F_Speed2)        	= P1P3_SPD;              
	b_LdTmpBufRam(F_Speed3)        	= P1P3_SPD;                    
//	b_LdTmpBufRam(F_LULD_MPM_SPD3)  = 0;     
	b_LdTmpBufRam(F_SU2SD2_V_SPD3)	= 0;    
	b_LdTmpBufRam(F_X0X1_V_SPD3)  	= 0;   
	
	flash_write_DspChar(F_ManualSpeed);	// block2
	
/////////////////////////////////////////////////////////
/////////////////////block2//////////////////////////////
/////////////////////////////////////////////////////////

	
/*	
//////////////display gorup///////////////////block0////////////////////
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
///////////////////////////////////////////////////////////////
*/
	
	DefaultEncoderRpmMpm();
	CaluDecreasePulse();

    asm("RESET");

}





void  __attribute__((section(".usercode"))) Setup_Default(void)
{
    LocalType  i;

	SaveVerify = 0x55;

	    	
//floor group	
	b_LdTmpBufRam(F_TopFlr)         = Init_TopFlr;
	b_LdTmpBufRam(F_PrkFlr)         = Init_PrkFlr;
	b_LdTmpBufRam(F_FixFloor)       = Init_FixFloor;
	b_LdTmpBufRam(F_OneStopFlr)     = Init_OneStopFlr;
	b_LdTmpBufRam(F_FireSafeFlr)    = Init_FireSafeFlr;
	b_LdTmpBufRam(F_X7SafeFlr)      = Init_X7SafeFlr;
	b_LdTmpBufRam(F_WaterSafeFlr)   = Init_WaterSafeFlr;
	b_LdTmpBufRam(F_StartFloor)     = START_FLOOR;   	
	b_LdTmpBufRam(F_KidsKeyCnt)     = Init_KidsKeyCnt;
	b_LdTmpBufRam(F_X6SafeFlr)      = Init_X6SafeFlr;
	b_LdTmpBufRam(F_X5SafeFlr)      = Init_X5SafeFlr;
	

/*	                              //     7 ,      6,      5,        4,         3,        2,       1,     0
	b_LdTmpBufRam(F_NcNoBit0)       = Init_ALL_FF;  //                                                                     emg
	b_LdTmpBufRam(F_NcNoBit1)       = Init_ALL_FF;  //                                                                     su1
	b_LdTmpBufRam(F_NcNoBit2)       = Init_ALL_FF;  //                                                                     rg
	b_LdTmpBufRam(F_NcNoBit3)       = Init_ALL_FF;  //                                                                     fr1
	b_LdTmpBufRam(F_NcNoBit4)       = Init_ALL_FF;  //                                                                     x0
	b_LdTmpBufRam(F_NcNoBit5)       = Init_ALL_FF;  //                                                                     fs0
	b_LdTmpBufRam(F_NcNoBit6)       = Init_ALL_FF;  //                                                                     op
	b_LdTmpBufRam(F_NcNoBit7)       = Init_ALL_FF;  //                                                                     fan
	b_LdTmpBufRam(F_NcNoBit8)       = Init_ALL_FF;  //                                                                     up
*/

	
	
//onoff2 group		
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
	bit_LdTmpBufRamSet  (F_OnOff1,bBrkMgtUse        	% 8);  //on
	bit_LdTmpBufRamSet  (F_OnOff1,bEncoderUse       	% 8);
	bit_LdTmpBufRamReset(F_OnOff1,bRelevelOnOff     	% 8);
	
	bit_LdTmpBufRamSet  (F_OnOff2,bOilLopeTypeChk   	% 8);  //lope type
	bit_LdTmpBufRamReset(F_OnOff2,bOnlyOneCall      	% 8);
	bit_LdTmpBufRamReset(F_OnOff2,bManualSusChk     	% 8);
	bit_LdTmpBufRamSet  (F_OnOff2,bBrkOpenUse       	% 8);	//on
	bit_LdTmpBufRamReset(F_OnOff2,bKidsKeyChkUse    	% 8);
	bit_LdTmpBufRamReset(F_OnOff2,bCarKeyFirstService  	% 8);
	bit_LdTmpBufRamReset(F_OnOff2,bFamilyService    	% 8);
	bit_LdTmpBufRamReset(F_OnOff2,bOpenOutSet    		% 8);
	
	
	bit_LdTmpBufRamReset(F_OnOff3,bSafetyValidLR    	% 8);
	bit_LdTmpBufRamReset(F_OnOff3,bFloorSel             % 8);
	bit_LdTmpBufRamReset(F_OnOff3,bRunOpenSetClear      % 8);
	bit_LdTmpBufRamReset(F_OnOff3,bUcmpFeedback      	% 8);
	bit_LdTmpBufRamReset(F_OnOff3,bManWorkingChk      	% 8);
	bit_LdTmpBufRamSet(F_OnOff3,bEncoderCpy         	% 8);
	
	
	
//timer group
	b_LdTmpBufRam(F_OpWtTm)         = Init_OpWtTm;			//0      
	b_LdTmpBufRam(F_OpTtTm)         = Init_OpTtTm; 			//1 		
	b_LdTmpBufRam(F_FixFloorTime)   = Init_FixFloorTime;   	//2
	b_LdTmpBufRam(F_NextFlrTime)    = Init_NextFlrTime;    	//3
	b_LdTmpBufRam(F_LuLdOffTime)    = Init_LuLdOffTime;    	//4
	b_LdTmpBufRam(F_FanTime)        = Init_FanTime;        	//5
	b_LdTmpBufRam(F_LightTime)      = Init_LightTime;      	//6
	b_LdTmpBufRam(F_OpClWaitTime)   = Init_OpClWTime;      	//7
	b_LdTmpBufRam(F_DrJmpChkTime)   = Init_DrJmpChkTime;   	//8(power run time/power save)
	b_LdTmpBufRam(F_DirTime)        = Init_DirTime;			//9
	b_LdTmpBufRam(F_VoiceTime)      = Init_VoiceTime;		//10
	b_LdTmpBufRam(F_BrkMgtTime)     = Init_BrkMgtTime;		//11
	b_LdTmpBufRam(F_ReOpTime)       = Init_ReOpTime;       	//12(open hold time/door open)
	b_LdTmpBufRam(F_StTm1)          = Init_StTm1;          	//13(p4 on time)
	b_LdTmpBufRam(F_StTm2)          = Init_StTm2;          	//14(updn on time)
	b_LdTmpBufRam(F_StTm3)          = Init_StTm3;          	//15(bk2 on time)
	b_LdTmpBufRam(F_StTm4)          = Init_StTm4;          	//16(bk1 on time)
	b_LdTmpBufRam(F_StTm5)          = Init_StTm5;          	//17(run on time)		
	b_LdTmpBufRam(F_RunOffTime)		= Init_RunOff_Time;		//18(run off time)        
	b_LdTmpBufRam(F_Bk1OffTime)     = Init_Bk1Off_Time;		//19(bk1 off time)
	b_LdTmpBufRam(F_Bk2OffTime)     = Init_Bk2Off_Time;		//20(bk2 off time)
	b_LdTmpBufRam(F_UDOffTime)      = Init_UDOff_Time;		//21(updn off time)      
	b_LdTmpBufRam(F_P4OffTime)      = Init_P4Off_Time;     //22(p4 off time)
	b_LdTmpBufRam(F_SolOnTime)      = Init_SolOn_Time;		//23(sol on time)        
	b_LdTmpBufRam(F_DoorWaitTime)   = Init_DoorWait_Time;  //24(door start time)
	
	flash_write_DspChar(F_TopFlr);		//block1
	
	

	/////////////////////wait floor group//////////////////////////////
	for(i=0;i<32;i++){
		b_LdTmpBufRam(F_0506+i)           = DISABLE_FLR;
	}
	
	flash_write_DspChar(F_BLOCK3);
	//////////////////////////////////////////////////////////////
	

	/////////////////////ncno group//////////////////////////////
	b_LdTmpBufRam(EMG_PORT)         =SILK_EMG   | BIT_NORMAL_OPEN;			//1     64    ncno1 group
	b_LdTmpBufRam(PRK_PORT)         =SILK_PRK   | BIT_NORMAL_OPEN;          //1     
	b_LdTmpBufRam(AUTO_PORT)        =SILK_AUTO  | BIT_NORMAL_OPEN;         	//1     
	b_LdTmpBufRam(U_B_PORT)         =SILK_U_B   | BIT_NORMAL_OPEN;          //1             
	b_LdTmpBufRam(D_B_PORT)         =SILK_D_B   | BIT_NORMAL_OPEN;          //1     65
	b_LdTmpBufRam(OLS_PORT)         =SILK_OLS   | BIT_NORMAL_OPEN;          //1     
	b_LdTmpBufRam(GS_PORT)          =SILK_GS    | BIT_NORMAL_OPEN;      	//1     
	b_LdTmpBufRam(DS_PORT)          =SILK_DS    | BIT_NORMAL_OPEN;       	//1             
	
//	b_LdTmpBufRam(SU1_PORT)         =SILK_SU1   | BIT_NORMAL_OPEN;         	//1     66
//	b_LdTmpBufRam(SD1_PORT)         =SILK_SD1   | BIT_NORMAL_OPEN;          //1     
	b_LdTmpBufRam(SU1_PORT)         =SILK_SU1   | BIT_NORMAL_CLOSE;         //1     66
	b_LdTmpBufRam(SD1_PORT)         =SILK_SD1   | BIT_NORMAL_CLOSE;         //1     

	b_LdTmpBufRam(SFT_PORT)         =SILK_SFT   | BIT_NORMAL_OPEN;          //1     
	b_LdTmpBufRam(OVL_PORT)         =SILK_OVL   | BIT_NORMAL_OPEN;          //1             
	b_LdTmpBufRam(ULS_PORT)         =SILK_ULS   | BIT_NORMAL_OPEN;          //1     67
	b_LdTmpBufRam(DLS_PORT)         =SILK_DLS   | BIT_NORMAL_OPEN;          //1     
	b_LdTmpBufRam(LU_PORT)          =SILK_LU    | BIT_NORMAL_OPEN;          //1     
	b_LdTmpBufRam(LD_PORT)          =SILK_LD    | BIT_NORMAL_OPEN;          //1             
	
	b_LdTmpBufRam(RG_PORT)          =SILK_GR    | BIT_NORMAL_OPEN;			//1     68
	b_LdTmpBufRam(BAT_PORT)         =SILK_BAT   | BIT_NORMAL_OPEN;			//1     
	b_LdTmpBufRam(PASS_PORT)        =SILK_PASS  | BIT_NORMAL_OPEN;         	//1     
	b_LdTmpBufRam(FIRE_PORT)        =SILK_FIRE  | BIT_NORMAL_OPEN;         	//1             
	b_LdTmpBufRam(WATER_PORT)       =SILK_WATER | BIT_NORMAL_OPEN;        	//1     69
	b_LdTmpBufRam(FULL_PORT)        =SILK_FULL  | BIT_NORMAL_OPEN;         	//1     
	b_LdTmpBufRam(MM_PORT)          =SILK_MM    | BIT_NORMAL_OPEN;         	//1     
	b_LdTmpBufRam(FHM_PORT)         =SILK_FHM   | BIT_NORMAL_OPEN;          //1             
	
	b_LdTmpBufRam(FR1_PORT)         =SILK_FR1   | BIT_NORMAL_OPEN;          //1     70
	b_LdTmpBufRam(FR2_PORT)         =SILK_FR2   | BIT_NORMAL_OPEN;          //1     
	b_LdTmpBufRam(GS2_PORT)         =SILK_GS2   | BIT_NORMAL_OPEN;          //1     
	b_LdTmpBufRam(DS2_PORT)         =SILK_DS2   | BIT_NORMAL_OPEN;          //1             
	b_LdTmpBufRam(SU2_PORT)         =SILK_SU2   | BIT_NORMAL_OPEN;          //1     71
	b_LdTmpBufRam(SD2_PORT)         =SILK_SD2   | BIT_NORMAL_OPEN;          //1     
	b_LdTmpBufRam(BM_PORT)          =SILK_BM    | BIT_NORMAL_OPEN;          //1     
	b_LdTmpBufRam(INV_PORT)         =SILK_INV   | BIT_NORMAL_CLOSE;          //1             
	
	b_LdTmpBufRam(X0_PORT)          =SILK_X0    | BIT_NORMAL_OPEN;       	//1     72	ncno2 group
	b_LdTmpBufRam(X1_PORT)          =SILK_X1    | BIT_NORMAL_OPEN;      	//1     
	b_LdTmpBufRam(X2_PORT)          =SILK_X2    | BIT_NORMAL_OPEN;			//1     
	b_LdTmpBufRam(X3_PORT)          =SILK_X3    | BIT_NORMAL_OPEN;			//1             
	b_LdTmpBufRam(X4_PORT)          =SILK_X4    | BIT_NORMAL_OPEN;			//1     73
	b_LdTmpBufRam(X5_PORT)          =SILK_X5    | BIT_NORMAL_OPEN;			//1     
	b_LdTmpBufRam(X6_PORT)          =SILK_X6    | BIT_NORMAL_OPEN;			//1     
	b_LdTmpBufRam(X7_PORT)          =SILK_X7    | BIT_NORMAL_OPEN;			//1             
	
	b_LdTmpBufRam(FS0_PORT)         =SILK_FS0   | BIT_NORMAL_OPEN;          //1     74
//	b_LdTmpBufRam(FS1_PORT)         =SILK_FS1   | BIT_NORMAL_OPEN;          //1     
	b_LdTmpBufRam(FS1_PORT)         =SILK_FS1   | BIT_NORMAL_CLOSE;         //1     
	b_LdTmpBufRam(FS2_PORT)         =SILK_FS2   | BIT_NORMAL_OPEN;          //1     
	b_LdTmpBufRam(FS3_PORT)         =SILK_FS3   | BIT_NORMAL_OPEN;          //1             
	b_LdTmpBufRam(FS4_PORT)         =SILK_FS4   | BIT_NORMAL_OPEN;          //1     75
	b_LdTmpBufRam(DER_PORT)         =SILK_DER   | BIT_NORMAL_OPEN;          //1     
	b_LdTmpBufRam(FID_PORT)         =SILK_FID   | BIT_NORMAL_OPEN;          //1     
	b_LdTmpBufRam(UND_PORT)         =SILK_UND   | BIT_NORMAL_OPEN;          //1     
	
	
/////////mainsub door group////////////////	
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
	
	
	flash_write_DspChar(EMG_PORT);		//block4
	


	////////////////ncno3 group/////////////////////////////////
	
	b_LdTmpBufRam(FAN_PORT)         =SILK_FAN   | BIT_NORMAL_OPEN;
//	b_LdTmpBufRam(LIT_PORT)         =SILK_LIT   | BIT_NORMAL_OPEN;  //     
	b_LdTmpBufRam(LIT_PORT)         =SILK_LIT   | BIT_NORMAL_CLOSE;  //     
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
//	b_LdTmpBufRam(GBR_PORT)         =SILK_GBR   | BIT_NORMAL_OPEN;     
	b_LdTmpBufRam(GBR_PORT)         =SILK_GBR   | BIT_NORMAL_CLOSE;     
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
	
	
	flash_write_DspChar(FAN_PORT);		//block5
	////////////////////////////////////////////////
	
	
	//////////////user group/////////////////////////////
	b_LdTmpBufRam(F_Ver0)           = VERSION_0;		//0
	b_LdTmpBufRam(F_Ver1)           = VERSION_1;		//0
	b_LdTmpBufRam(F_Ver2)           = VERSION_2;		//0
	b_LdTmpBufRam(F_Bd_Id)          = (IO | MAN_USE);   //1        
	
	
	b_LdTmpBufRam(F_Passward0)      = '0';				//2	autolanding== 5
	b_LdTmpBufRam(F_Passward1)      = '0';				//2
	b_LdTmpBufRam(F_Passward2)      = '0';				//2
	b_LdTmpBufRam(F_Passward3)      = '0';				//2
	
	i_LdTmpBufRam(F_SerialNm10)     = 0;				//not use
	
	b_LdTmpBufRam(F_ErrStopCnt)     = 0xff;				//19
	b_LdTmpBufRam(F_NormalDsp)      = 0x0;				//6
	b_LdTmpBufRam(F_UserLamp1)      = 2;				//3		//overload
	b_LdTmpBufRam(F_UserLamp2)      = 1;				//4		//manual
	b_LdTmpBufRam(F_UserLamp3)      = 6;				//22	//vip 
	b_LdTmpBufRam(F_UserLamp4)      = 3;				//24    //fire
	b_LdTmpBufRam(F_GroupNm)        = 0;				//13
	b_LdTmpBufRam(F_LocalNm)        = 0;				//14
	b_LdTmpBufRam(F_PcbType)        = 0;				//???
	
	i_LdTmpBufRam(F_StopPulse0)     = 1000;				//31
	
	b_LdTmpBufRam(F_year)           = 0;				//18
	b_LdTmpBufRam(F_month)          = 0;				//18
	b_LdTmpBufRam(F_day)            = 0;				//18
	
	b_LdTmpBufRam(F_Company)        = COMPANY;			//20
	b_LdTmpBufRam(F_SystemSet)      = NEW_LAW_NEW_SPD;	//30 n_law,old_law,n_spd,o_spd
	

////////////////////even/odd group(�汝� 礎熱)///////////////////
	b_LdTmpBufRam(F_NonService0)    = Init_ALL_FF;
	b_LdTmpBufRam(F_NonService1)    = Init_ALL_FF;
	b_LdTmpBufRam(F_NonService2)    = Init_ALL_FF;
	b_LdTmpBufRam(F_NonService3)    = Init_ALL_FF;
	b_LdTmpBufRam(F_NonService4)    = Init_ALL_FF;
	b_LdTmpBufRam(F_NonService5)    = Init_ALL_FF;
	b_LdTmpBufRam(F_NonService6)    = Init_ALL_FF;
	b_LdTmpBufRam(F_NonService7)    = Init_ALL_FF;
///////////////////////////////////////////////////////////////
	
/*	
	b_LdTmpBufRam(F_ManualSpeed)    = P3_SPD;          
	b_LdTmpBufRam(F_BatterySpeed)   = NONE_USE_SPD;      
	b_LdTmpBufRam(F_DecreaseSpeed)  = P1P2_SPD;                    
	b_LdTmpBufRam(F_FhmSpeed)       = NONE_USE_SPD;     
	b_LdTmpBufRam(F_Etc1Speed)      = NONE_USE_SPD;     
	b_LdTmpBufRam(F_Etc2Speed)      = NONE_USE_SPD;     
	b_LdTmpBufRam(F_Speed30)        = NONE_USE_SPD;     
	b_LdTmpBufRam(F_Speed45)        = P1P3_SPD;              
	b_LdTmpBufRam(F_Speed60)        = P1P2P3_SPD;                    
	b_LdTmpBufRam(F_Speed90)        = NONE_USE_SPD;     
	b_LdTmpBufRam(F_Speed105)       = NONE_USE_SPD;     
	b_LdTmpBufRam(F_Speed120)       = NONE_USE_SPD;     
	b_LdTmpBufRam(F_Speed150)       = NONE_USE_SPD;     
	b_LdTmpBufRam(F_Speed180)       = NONE_USE_SPD;     
	b_LdTmpBufRam(F_Speed210)       = NONE_USE_SPD;    
	b_LdTmpBufRam(F_ElevSpeed)      = SPEED_60;
	b_LdTmpBufRam(F_LimitSpeed)     = SPEED_210;
	b_LdTmpBufRam(F_Su1Sd1_Velocity)= 90;      //mpm
*/

	b_LdTmpBufRam(F_Su2Sd2_Velocity)= 0;      	//mpm
	b_LdTmpBufRam(F_X0X1_Velocity)  = 0;     	//mpm
	b_LdTmpBufRam(F_AutoLandingMode)= 0;     	//no Auto landing(user group 2)
	
	
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

	flash_write_DspChar(F_ManualSpeed);	// block2
	
	
	
//////////////display gorup///////////////////block0////////////////////
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
///////////////////////////////////////////////////////////////
	


#ifdef  TEST_SIMULATION  
	GetFlashDataToBufRam(F_TopFlr);	
	#ifdef	FLOOR_64
        b_LdTmpBufRam(F_TopFlr)         = 63;
	#else
        b_LdTmpBufRam(F_TopFlr)         = 31;
	#endif
	bit_LdTmpBufRamReset  (F_OnOff0,bDoorJumperOff        % 8); 
	bit_LdTmpBufRamReset(F_OnOff3,bManWorkingChk      % 8);
	flash_write_DspChar(F_TopFlr);	




	GetFlashDataToBufRam(F_ManualSpeed);	
    b_LdTmpBufRam(F_Bd_Id)          = (LG | MAN_USE);           
	flash_write_DspChar(F_ManualSpeed);	// block2


	GetFlashDataToBufRam(EMG_PORT);	
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

		flash_write_DspChar(EMG_PORT);	// block2
#endif

	DefaultEncoderRpmMpm();
	CaluDecreasePulse();
  
	SWPAB   = 0;    
}



