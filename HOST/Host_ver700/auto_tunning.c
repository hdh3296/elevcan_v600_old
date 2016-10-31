
#include  "iodef.h"
#include  "30f6010_io.h"            
#include  "default_setup.h" 
#include  "you_can2.h" 
#include  "ladder485.h" 
#include  	"Host_Autolanding.h" 


#ifdef		AUTO_LANDING_COMM

UserDataType 	BefxTunningSeq=0;
UserDataType 	TunningMode=0;

unsigned char Tun_WNm,Tun_ValueH,Tun_ValueL;		
unsigned int Tunning_adr;		


unsigned int  __attribute__((section(".usercode"))) Get_Tunning_Addr(void)
{
	if(xVarMotorType==IM_Motor_ID){     // IM
		Tunning_adr=Addr_IM_Tunning;
		return(1);
	}
	else if(xVarMotorType==PM_Motor_ID){ // PM
		Tunning_adr=Addr_PM_Tunning;
		return(1);
	}
	else{
		return(0);
	}	
}



unsigned int  __attribute__((section(".usercode"))) TunningStartEndCheck(void)
{
	#ifdef	AUTO_LANDING_CAN			
		return(0);
	#else


	if(WhoAutolanding==L1000_AUTOLANDING_485){
		return(0);
	}

	if( (LadderGroup != INV_PAR_GROUP_14) || (LadderGroupSub != NM_AUTO_TUNNING_NM) || bMoveCar || !IN_AUTO){
		if(BefxTunningSeq>0){
			BefxTunningSeq=0;
			TunningMode=0;
			OUT_P4(0);
        	OUT_U_W(0);
        	OUT_D_W(0);
        	OUT_BK1(0);
        	OUT_BK2(0);

			bParWr=0;
			EnterKey=0;
			ParRdWrNm=INVETER_NOT_SEL_SEQ;
			ThisRdWrMode=RDWR_READY_SEQ;
		}
		return(0);
	}



	switch(BefxTunningSeq){
		case	1:
			DigitData=TunningMode;
			IntThisNewAddressData_Load(Addr_MotorType,1,0,0);
			ParRdWrNm=INVETER_RW_SEQ;
			BefxTunningSeq=2;
			break;
		case	2:
			if(IntMyDataOkChk(Addr_MotorType)){
				xVarMotorType= (This_Value);  // 3=유도,8=동기
				if((xVarMotorType==IM_Motor_ID) || (xVarMotorType==PM_Motor_ID)){
					Get_Tunning_Addr();
					BefxTunningSeq=3;
				}
				else{
					BefxTunningSeq=1;
				}
			}
			else{
				if(WaitAckTimeOutChk())	BefxTunningSeq=1;	
			}	
			break;
	
		case	3:
			IntThisNewAddressData_Load(Tunning_adr,1,0,TunningValue1);
			ParRdWrNm=INVETER_RW_SEQ;
			ThisRdWrMode=PARAMETER_WR_SEQ;	
			BefxTunningSeq=4;
			break;
		case	4:
			if(IntMyDataOkChk(Tunning_adr)){
				if(This_Value ==(unsigned int)TunningValue1){
					OUT_P4(1);
					if(TunningMode==1)	OUT_U_W(1);
					else				OUT_D_W(1);
					BefxTunningSeq=5;
				} 
				else{
					BefxTunningSeq=3;
				}
			}
			else{
				if(WaitAckTimeOutChk())	BefxTunningSeq=3;	
			}	
			break;	
		case	5:
			DigitData=3;
			IntThisNewAddressData_Load(Tunning_adr,1,0,0);
			ParRdWrNm=INVETER_RW_SEQ;
			BefxTunningSeq=6;
			break;
		case	6:
			if(IntMyDataOkChk(Tunning_adr)){
				if(This_Value ==(unsigned int)0){
					DigitData=0;
					BefxTunningSeq=11;	

/*
					if(xVarMotorType==PM_Motor_ID){ // PM
						BefxTunningSeq=7;
						OUT_P4(0);
			        	OUT_U_W(0);
			        	OUT_D_W(0);
			        	OUT_BK1(0);
        				OUT_BK2(0);
					}
					else{
						DigitData=0;
						BefxTunningSeq=11;	
					}
*/
				} 
				else{
					BefxTunningSeq=5;
				}
			}
			else{
				if(WaitAckTimeOutChk())	BefxTunningSeq=5;	
			}	
			break;	
		case	7:
			IntThisNewAddressData_Load(Tunning_adr,1,0,TunningValue2);
			ParRdWrNm=INVETER_RW_SEQ;
			ThisRdWrMode=PARAMETER_WR_SEQ;	
			BefxTunningSeq=8;
			break;
		case	8:
			if(IntMyDataOkChk(Tunning_adr)){
				if(This_Value ==(unsigned int)TunningValue2){
					OUT_P4(1);
					if(TunningMode==1)	OUT_U_W(1);
					else				OUT_D_W(1);

					#ifdef	AUTO_LANDING_485
					if( (WhoAutolanding == (unsigned int)VL_AUTOLANDING_485)){
						OUT_BK1(1);
						OUT_BK2(1);
					}
					#endif

					BefxTunningSeq=9;
				} 
				else{
					BefxTunningSeq=7;
				}
			}
			else{
				if(WaitAckTimeOutChk())	BefxTunningSeq=7;	
			}	
			break;
		case	9:
			IntThisNewAddressData_Load(Tunning_adr,1,0,0);
			ParRdWrNm=INVETER_RW_SEQ;
			BefxTunningSeq=10;
			break;
		case	10:
			if(IntMyDataOkChk(Tunning_adr)){
				if(This_Value ==(unsigned int)0){
					BefxTunningSeq=11;	
					DigitData=0;
				} 
				else{
					BefxTunningSeq=9;
				}
			}
			else{
				if(WaitAckTimeOutChk())	BefxTunningSeq=9;	
			}	
			break;
		default:	
			BefxTunningSeq=0;
			TunningMode=0;
			OUT_P4(0);
        	OUT_U_W(0);
        	OUT_D_W(0);
        	OUT_BK1(0);
        	OUT_BK2(0);

			if(EnterKey != 2){
				DigitData=0;
			}
			DigitData=(DigitData % 3);
			break;

	}

	AutoTunningMsgDsp(DigitData);

	return(0);

	#endif

}


unsigned int  __attribute__((section(".usercode"))) AutoTunningStartChk(void)
{
	if( (LadderGroup == INV_PAR_GROUP_14) && (LadderGroupSub == NM_AUTO_TUNNING_NM) ){
		if( !bMoveCar && IN_AUTO && (BefxTunningSeq==0) && (DigitData>0) ){
			TunningMode=DigitData;
			BefxTunningSeq=1;
		}
		return(1);
	}
	else	return(0);
}


#endif




