
#include <p30fxxxx.h>
#include  	"30f6010_io.h"            
#include  	"default_setup.h" 
#include  	"host_io.h"            
#include  	"iodef.h"
#include  	"door.h"
#include  	"com.h"
#include  	"counter.h"
#include    "you_can2.h" 

#include    "ladder485.h" 
#include	"Host_NewProtocol.h" 
#include  	"Host_Autolanding.h" 


#ifdef	AUTO_LANDING_COMM




LocalType __attribute__((section(".usercode"))) ValidSpeedSearch(void)
{
	unsigned int i;	
	do{
		if(EVLowSpd <= 1000)	return(0);
		if(xVarMpm1000 ==0)		return(0);

		EVLowSpd=(EVLowSpd-1000);  //1hz
		Length1=((xVarMpm1000 * 10)/xVarMaxHz);
		xVarCurMpm=(Length1 * EVLowSpd)/10;
		A_CurDecPulseCalcu();
		EVLowDecLength=CurSpdDecPulse;
		i=GetMinimumFloorPulse();						
	}while(i);

	return(1);
}



LocalType __attribute__((section(".usercode"))) WaitAckTimeOutChk(void)
{    
	if((EV_ReqRdWrTxBuf[REQ_DATA_SEQ]==0) && (DeltaNoAck > 30))	return(1);
	else														return(0);
}


LocalType __attribute__((section(".usercode"))) RxTxReqToInveterInit(void)
{
	EV_ReqRdWrTxBuf[REQ_DATA_SEQ]=0;
	IV_AckRdWrTxBuf[REQ_DATA_SEQ]=0;
}




LocalType __attribute__((section(".usercode"))) ThisNewAddressData_Load(unsigned char addressH,unsigned char addressL,unsigned char WriteWordNm,unsigned char valH,unsigned char valL)
{
	ThisRdWrAddrH=addressH;
	ThisRdWrAddrL=addressL;
	ThisRdWrWNm=WriteWordNm;
	ThisRdWrValueH=valH;
	ThisRdWrValueL=valL;					
	ThisRdWrMode=ATTR_RD_SEQ;
					
	return(0);
}




LocalType __attribute__((section(".usercode"))) MyDataOkChk(unsigned char addressH,unsigned char addressL)
{
	if((ThisRdWrMode==PARAMETER_RD_OK_SEQ)){
		if((ThisRdWrAddrH==addressH) && (ThisRdWrAddrL==addressL)){
			if( (Com1TxBuffer[2]==addressH) && (Com1TxBuffer[3]==addressL)){ 
				ThisRdWrMode=RDWR_READY_SEQ;	
				return(1);
			}
		} 
	}
	return(0);
}



LocalType __attribute__((section(".usercode"))) IntThisNewAddressData_Load(unsigned int address,unsigned char WriteWordNm,unsigned char valH,unsigned char valL)
{
	ThisRdWrAddrH=(unsigned char)(address >> 8);
	ThisRdWrAddrL=(unsigned char)(address);
	ThisNewAddressData_Load(ThisRdWrAddrH,ThisRdWrAddrL,WriteWordNm,valH,valL);

/*
	ThisRdWrWNm=WriteWordNm;
	ThisRdWrValueH=valH;
	ThisRdWrValueL=valL;					
	ThisRdWrMode=ATTR_RD_SEQ;
*/
					
	return(0);
}


LocalType __attribute__((section(".usercode"))) IntMyDataOkChk(unsigned int address)
{
	unsigned char adrH,adrL;

	adrH=(unsigned char)(address >> 8);
	adrL=(unsigned char)(address);
	return(MyDataOkChk(adrH,adrL));


/*
	if((ThisRdWrMode==PARAMETER_RD_OK_SEQ)){
		if((ThisRdWrAddrH==adrH) && (ThisRdWrAddrL==adrL)){
			ThisRdWrMode=RDWR_READY_SEQ;	
			return(1);
		} 
	}
	return(0);
*/
}










LocalType __attribute__((section(".usercode"))) Inverter_Par_Adr_RdWr(unsigned char addressH,unsigned char addressL,unsigned char WriteWordNm,unsigned char valH,unsigned char valL)
{    
	unsigned int b_data0,b_data1;


		switch(ThisRdWrMode){
			case	RDWR_READY_SEQ:
				break;
			case	ATTR_RD_SEQ:
				if(ReadAttribute(addressH,addressL)){
					ThisRdWrMode=WAIT_ATTR_RD_SEQ;
				}
				break;
			case	WAIT_ATTR_RD_SEQ:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					ThisRdWrMode=PARAMETER_RD_SEQ;
				}		
				else{
					if(WaitAckTimeOutChk())	ThisRdWrMode=ATTR_RD_SEQ;	
				}
				break;
			case	PARAMETER_RD_SEQ:
				if(ReadParameter(addressH,addressL,1)){
					ThisRdWrMode=WAIT_PARAMETER_RD_SEQ;
				}
				break;
			case	WAIT_PARAMETER_RD_SEQ:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){

					ThisRdWrMode=PARAMETER_RD_OK_SEQ;

					if(bParRd){
						b_data0=(unsigned int)(IV_AckRdWrTxBuf[5]);
						b_data0=(unsigned int)(b_data0 << 8);
						b_data0=(unsigned int)(b_data0 & 0xff00);
						b_data1=(unsigned int)(IV_AckRdWrTxBuf[6]);
						b_data1=(unsigned int)(b_data1 & 0x00ff);
						IV_This_Value=(b_data0 | b_data1); 
	
						b_data0=(unsigned int)(ThisAttribute[0]);
						b_data0=(unsigned int)(b_data0 << 8);
						b_data0=(unsigned int)(b_data0 & 0xff00);
						b_data1=(unsigned int)(ThisAttribute[1]);
						b_data1=(unsigned int)(b_data1 & 0x00ff);
						IV_This_Attrv=(b_data0 | b_data1); 
	
						b_data0=(unsigned int)(ThisAttribute[2]);
						b_data0=(unsigned int)(b_data0 << 8);
						b_data0=(unsigned int)(b_data0 & 0xff00);
						b_data1=(unsigned int)(ThisAttribute[3]);
						b_data1=(unsigned int)(b_data1 & 0x00ff);
						IV_This_Min=(b_data0 | b_data1); 
	
						b_data0=(unsigned int)(ThisAttribute[4]);
						b_data0=(unsigned int)(b_data0 << 8);
						b_data0=(unsigned int)(b_data0 & 0xff00);
						b_data1=(unsigned int)(ThisAttribute[5]);
						b_data1=(unsigned int)(b_data1 & 0x00ff);
						IV_This_Max=(b_data0 | b_data1); 

						Inv_Par_DataSort(IV_This_Value);					

						bParRd=0;		
					}
					else{
						b_data0=(unsigned int)(IV_AckRdWrTxBuf[5]);
						b_data0=(unsigned int)(b_data0 << 8);
						b_data0=(unsigned int)(b_data0 & 0xff00);
						b_data1=(unsigned int)(IV_AckRdWrTxBuf[6]);
						b_data1=(unsigned int)(b_data1 & 0x00ff);
						This_Value=(b_data0 | b_data1); 
					}

					if(bParWr){
						bParWr=0;
						EnterKey=0;
					}
				}		
				else{
					if(WaitAckTimeOutChk())	ThisRdWrMode=PARAMETER_RD_SEQ;	
				}
				break;
			case	PARAMETER_RD_OK_SEQ:
				break;
			case	PARAMETER_WR_SEQ:
				if(AddrWriteParameter(addressH,addressL,WriteWordNm,valH,valL)){
					ThisRdWrMode=WAIT_PARAMETER_WR_SEQ;
				}
				break;
			case	WAIT_PARAMETER_WR_SEQ:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					ThisRdWrMode=ATTR_RD_SEQ;
					#ifdef		AUTO_LANDING_485			
					L1000_SaveCommand(addressH,addressL);
					#endif

				}		
				else{
					if(WaitAckTimeOutChk()){
						ThisRdWrMode=PARAMETER_WR_SEQ;
					}
				}
				break;
			default:
				ThisRdWrMode=RDWR_READY_SEQ;
				RxTxReqToInveterInit();
				break;
		}

	return(0);
}	



LocalType __attribute__((section(".usercode"))) Default_Inverter_ParameterRdWr(void)
{    
#ifdef		AUTO_LANDING_485			

	unsigned long 	tmpdecpulse=0,tmpP=0;
	unsigned char 	portadr=0;
	unsigned char 	adrH=0,adrL=0;
	unsigned int 	tmp_address;

    LocalType  j,k;

	if(ParRdWrTime> 1000){	
		ParRdWrTime=0;
		bParameterMdf=0;
		ParRdWrNm=ERR_SEQ;	
		ThisRdWrMode = RDWR_READY_SEQ;

		#ifdef	DELTA_INVERTER_AUTOLANDING_CAN
			ParRdWrNm=CUR_AMP_SEQ;
		#endif
	}


 	if(bMoveCar){
		if( (ParRdWrNm >= ERR_SEQ) && (ParRdWrNm < CUR_AMP_SEQ)){
			ParRdWrNm = CUR_AMP_SEQ;
		} 
	}

	switch(ParRdWrNm){
//////////////////////////////////////////////////////////////
		case	ERR_SEQ:
			if(ThisRdWrMode == RDWR_READY_SEQ){
				IntThisNewAddressData_Load(Addr_CurError,0,0,0);				
			}
			else{
				if(IntMyDataOkChk(Addr_CurError)){
					InvErrNm=(unsigned int)(This_Value);

					#ifdef	AUTO_LANDING_485
					if(WhoAutolanding==L1000_AUTOLANDING_485)	ParRdWrNm=L1000_HZ_DEG1;
					else										ParRdWrNm=MOTOR_TYPE_SEQ;
					#else
					ParRdWrNm=MOTOR_TYPE_SEQ;
					#endif
				}
			}						
			break;
		case	L1000_HZ_DEG1:
			if(ThisRdWrMode == RDWR_READY_SEQ){
				IntThisNewAddressData_Load(0x0502,0,0,0);				
			}
			else{
				if(IntMyDataOkChk(0x0502)){
					if(This_Value == 0){
						ParRdWrNm=L1000_HZ_DEG3;
					}
					else{
						ParRdWrNm=L1000_HZ_DEG2;
					}
				}
			}						
			break;
		case	L1000_HZ_DEG2:
			if(ThisRdWrMode == RDWR_READY_SEQ){
				IntThisNewAddressData_Load(0x0502,1,0,0);				
				ThisRdWrMode=PARAMETER_WR_SEQ;
				bL1000_Enter=1;
			}
			else{
				if(IntMyDataOkChk(0x0502)){
					ParRdWrNm=L1000_HZ_DEG3;
				}
			}						
			break;
		case	L1000_HZ_DEG3:
			if(ThisRdWrMode == RDWR_READY_SEQ){
				IntThisNewAddressData_Load(0x0503,0,0,0);				
			}
			else{
				if(IntMyDataOkChk(0x0503)){
					if(This_Value == 0){
						ParRdWrNm=L1000_SAVE_ENTER;
					}
					else{
						ParRdWrNm=L1000_HZ_DEG4;
					}
				}
			}						
			break;
		case	L1000_HZ_DEG4:
			if(ThisRdWrMode == RDWR_READY_SEQ){
				IntThisNewAddressData_Load(0x0503,1,0,0);				
				ThisRdWrMode=PARAMETER_WR_SEQ;
				bL1000_Enter=1;
			}
			else{
				if(IntMyDataOkChk(0x0503)){
					ParRdWrNm=L1000_SAVE_ENTER;
				}
			}						
			break;
		case	L1000_SAVE_ENTER:
			if(bL1000_Enter){
				if(ThisRdWrMode == RDWR_READY_SEQ){
					IntThisNewAddressData_Load(0x0900,1,0,0);				
					ThisRdWrMode=PARAMETER_WR_SEQ;
				}
			}
			else	ParRdWrNm=MOTOR_TYPE_SEQ;							
			break;

		case	MOTOR_TYPE_SEQ:
			if(ThisRdWrMode == RDWR_READY_SEQ){
				IntThisNewAddressData_Load(Addr_MotorType,0,0,0);
			}
			else{
				if(IntMyDataOkChk(Addr_MotorType)){
					xVarMotorType= (This_Value);  // 3=유도,8=동기
					if((xVarMotorType==IM_Motor_ID) || (xVarMotorType==PM_Motor_ID)){
						ParRdWrNm=RPM_SEQ;
					}
					else{
						ParRdWrNm=CUR_AMP_SEQ;
					}
				}
			}						
			break;
		case	RPM_SEQ:
			#ifdef	AUTO_LANDING_485
			if(WhoAutolanding==L1000_AUTOLANDING_485){
				xVarRpm=GET_LONG(RPM);
				ParRdWrNm=ENCODER_PULSE_SEQ;
			}
			else{
				if(xVarMotorType==IM_Motor_ID)	tmp_address=Addr_IM_MotorRpm;
				else							tmp_address=Addr_PM_MotorRpm;
	
				if(ThisRdWrMode == RDWR_READY_SEQ){
					IntThisNewAddressData_Load(tmp_address,0,0,0);
				}
				else{
					if(IntMyDataOkChk(tmp_address)){
						xVarRpm= (This_Value); 
						Length1=GET_LONG(RPM);
						if(xVarRpm != Length1)		bParameterMdf=1;
						ParRdWrNm=ENCODER_PULSE_SEQ;	
					}
				}
			}
			#else
				if(xVarMotorType==IM_Motor_ID)	tmp_address=Addr_IM_MotorRpm;
				else							tmp_address=Addr_PM_MotorRpm;
	
				if(ThisRdWrMode == RDWR_READY_SEQ){
					IntThisNewAddressData_Load(tmp_address,0,0,0);
				}
				else{
					if(IntMyDataOkChk(tmp_address)){
						xVarRpm= (This_Value); 
						Length1=GET_LONG(RPM);
						if(xVarRpm != Length1)	bParameterMdf=1;
						ParRdWrNm=ENCODER_PULSE_SEQ;	
					}
				}
			#endif
			break;
		case	ENCODER_PULSE_SEQ:
			if(xVarMotorType==IM_Motor_ID)	tmp_address=Addr_IM_EncoderPulse;
			else							tmp_address=Addr_PM_EncoderPulse;			

			if(ThisRdWrMode == RDWR_READY_SEQ){
				IntThisNewAddressData_Load(tmp_address,0,0,0);
			}
			else{
				if(IntMyDataOkChk(tmp_address)){
					xVarEncoder= (This_Value );  
					Length1=GET_LONG(ENCODER_PULSE);
					if(xVarEncoder != Length1)		bParameterMdf=1;
					ParRdWrNm=MAX_EV_SPD_SEQ;	
					ParRdWrTime=0;
				}
			}
			break;

		case	MAX_EV_SPD_SEQ:
//			xVarMpm=GET_LONG(NEW_MPM);
			xVarMpm=ThisUseMaxMpm;
			xVarMpm1000= (xVarMpm * 100);			// new
			ParRdWrNm=MAX_HZ_SEQ;
			break;
		case	MAX_HZ_SEQ:
			if(ThisRdWrMode == RDWR_READY_SEQ){
				IntThisNewAddressData_Load(Addr_MaxHz,0,0,0);
			}
			else{
				if(IntMyDataOkChk(Addr_MaxHz)){
					#ifdef	AUTO_LANDING_485
						if(WhoAutolanding==L1000_AUTOLANDING_485){
							xVarMaxHz= (This_Value * 100);  // hz read ( 50.0= 50000)
						}
						else{
							xVarMaxHz= (This_Value * 10);  // hz read ( 50.00= 50000)
						}
					#else
						xVarMaxHz= (This_Value * 10);  // hz read ( 50.00= 50000)
					#endif

					ParRdWrNm=DEC_TIME_SEQ;	
				}
			}
			break;
		case	DEC_TIME_SEQ:
			if(ThisRdWrMode == RDWR_READY_SEQ){
				IntThisNewAddressData_Load(Addr_Dec_Time,0,0,0);
			}
			else{
				if(IntMyDataOkChk(Addr_Dec_Time)){
					xVarDecTime= (This_Value * 10);  // 10msec  -> 1msec
					Length1=GET_LONG(BASE_DEC_TIME);
					if(xVarDecTime != Length1)		bParameterMdf=1; 
					ParRdWrNm=S_CUV_TIME1_SEQ;	
				}
			}
			break;

		case	S_CUV_TIME1_SEQ:
			if(ThisRdWrMode == RDWR_READY_SEQ){
				IntThisNewAddressData_Load(Addr_SCurve_Time,0,0,0);
			}
			else{
				if(IntMyDataOkChk(Addr_SCurve_Time)){
					xVarSCurve= (This_Value * 10);  // 10msec  -> 1msec
					Length1=GET_LONG(BASE_SCURVE_TIME);
					if(xVarSCurve != Length1)	bParameterMdf=1;   	
					ParRdWrNm=SPEED_DEC_PORT_SEQ;	
				}
			}
			break;
		case	SPEED_DEC_PORT_SEQ:
			tmp_address=(Addr_DecSpdPort & 0xfff0);
			tmp_address=(tmp_address | (unsigned int)(cF_SPEED_DEC_PORT));

			if(ThisRdWrMode == RDWR_READY_SEQ){
				IntThisNewAddressData_Load(tmp_address,0,0,0);
			}
			else{
				if(IntMyDataOkChk(tmp_address)){
					xDecMpm= (This_Value * 10);  
					if( (cF_SPEED_DEC_PORT ==0)){
						xDecMpm=0;
					}
					
					xDecMpm=(xVarMpm1000 * xDecMpm)/xVarMaxHz;

					xDecMpm=(xDecMpm/100);							// new insert
					Length1=GET_LONG(BASE_DEC_MPM);
					if(xDecMpm != Length1)	bParameterMdf=1;
					ParRdWrNm=SPEED_LOW_PORT_SEQ;
					ParRdWrTime=0;

				}
			}
			break;

		case	SPEED_LOW_PORT_SEQ:
			tmp_address=(Addr_LowSpdPort & 0xfff0);
			tmp_address=(tmp_address | (unsigned int)(cF_SPEED_LOW_PORT));

			if(ThisRdWrMode == RDWR_READY_SEQ){
				IntThisNewAddressData_Load(tmp_address,0,0,0);
			}
			else{
				if(IntMyDataOkChk(tmp_address)){
					EVLowSpd= (This_Value * 10);  // hz read

/*
					if( (cF_SPEED_LOW_PORT ==0)){
						EVLowSpd=0;
					}
*/
 
					Length1=((xVarMpm1000 * 10)/xVarMaxHz);
					xVarCurMpm=(Length1 * EVLowSpd)/1000;
					xLowSpdMpm=GET_LONG(DEC_PULSE_SPD_LOW);

					if(xVarCurMpm != xLowSpdMpm){
						xLowSpdMpm=xVarCurMpm;
						bParameterMdf=1;
					}
					ParRdWrTime=0;
					ParRdWrNm=SPEED_MID_PORT_SEQ;

/*	
					CurDecPulseCalcu();
					EVLowDecLength=CurSpdDecPulse;
					Length1=GET_LONG(DEC_LENGTH_SPD_LOW);
					if(EVLowDecLength != Length1)	bParameterMdf=1;
					ParRdWrNm=SPEED_MID_PORT_SEQ;

				    if(!FhmOnOffChk && (EVLowSpd>0)){
						if(GetMinimumFloorPulse()){				
							if(ValidSpeedSearch()){								
								EVLowSpd=(EVLowSpd/10);
								portadr=(unsigned char)(EVLowSpd >> 8);

								IntThisNewAddressData_Load(tmp_address,1,portadr,(unsigned char)EVLowSpd);
								ThisRdWrMode=PARAMETER_WR_SEQ;
								bL1000_Enter=1;
								ParRdWrTime=900;
							}
						}
					}
*/				
				}
			}



/*
			tmp_address=(Addr_LowSpdPort & 0xfff0);
			tmp_address=(tmp_address | (unsigned int)(cF_SPEED_LOW_PORT));

			if(ThisRdWrMode == RDWR_READY_SEQ){
				IntThisNewAddressData_Load(tmp_address,0,0,0);
			}
			else{
				if(IntMyDataOkChk(tmp_address)){
					EVLowSpd= (This_Value * 10);  // hz read

					if( (cF_SPEED_LOW_PORT ==0)){
						EVLowSpd=0;
					}
 
					Length1=((xVarMpm1000 * 10)/xVarMaxHz);
					xVarCurMpm=(Length1 * EVLowSpd)/10;
					CurDecPulseCalcu();
					EVLowDecLength=CurSpdDecPulse;
					Length1=GET_LONG(DEC_LENGTH_SPD_LOW);
					if(EVLowDecLength != Length1)	bParameterMdf=1;
					ParRdWrNm=SPEED_MID_PORT_SEQ;

				    if(!FhmOnOffChk && (EVLowSpd>0)){
						if(GetMinimumFloorPulse()){				
							if(ValidSpeedSearch()){								
								EVLowSpd=(EVLowSpd/10);
								portadr=(unsigned char)(EVLowSpd >> 8);

								IntThisNewAddressData_Load(tmp_address,1,portadr,(unsigned char)EVLowSpd);
								ThisRdWrMode=PARAMETER_WR_SEQ;
								bL1000_Enter=1;
								ParRdWrTime=900;
							}
						}
					}				
				}
			}
*/
			break;
		case	SPEED_MID_PORT_SEQ:
			tmp_address=(Addr_MidSpdPort & 0xfff0);
			tmp_address=(tmp_address | (unsigned int)(cF_SPEED_MID_PORT));

			if(ThisRdWrMode == RDWR_READY_SEQ){
				IntThisNewAddressData_Load(tmp_address,0,0,0);
			}
			else{
				if(IntMyDataOkChk(tmp_address)){
					EVMidSpd= (This_Value * 10);  // hz read

/*
					if( (cF_SPEED_MID_PORT ==0)){
						EVMidSpd=0;
					}
*/

					Length1=((xVarMpm1000 * 10)/xVarMaxHz);
					xVarCurMpm=(Length1 * EVMidSpd)/1000;

//					xMidSpdMpm=GET_LONG(DEC_LENGTH_SPD_MID);
					xMidSpdMpm=GET_LONG(DEC_PULSE_SPD_MID);
					if(xVarCurMpm != xMidSpdMpm){
						xMidSpdMpm=xVarCurMpm;
						bParameterMdf=1;
					}
					ParRdWrTime=0;
					ParRdWrNm=SPEED_HIGH_PORT_SEQ;
/*

					CurDecPulseCalcu();
					EVMidDecLength=CurSpdDecPulse;
					Length1=GET_LONG(DEC_LENGTH_SPD_MID);
					if(EVMidDecLength != Length1)	bParameterMdf=1;	
					ParRdWrTime=0;
					ParRdWrNm=SPEED_HIGH_PORT_SEQ;
*/
				}
			}



/*
			tmp_address=(Addr_MidSpdPort & 0xfff0);
			tmp_address=(tmp_address | (unsigned int)(cF_SPEED_MID_PORT));

			if(ThisRdWrMode == RDWR_READY_SEQ){
				IntThisNewAddressData_Load(tmp_address,0,0,0);
			}
			else{
				if(IntMyDataOkChk(tmp_address)){
					EVMidSpd= (This_Value * 10);  // hz read

					if( (cF_SPEED_MID_PORT ==0)){
						EVMidSpd=0;
					}


					Length1=((xVarMpm1000 * 10)/xVarMaxHz);
					xVarCurMpm=(Length1 * EVMidSpd)/10;
					CurDecPulseCalcu();
					EVMidDecLength=CurSpdDecPulse;
					Length1=GET_LONG(DEC_LENGTH_SPD_MID);
					if(EVMidDecLength != Length1)	bParameterMdf=1;	
					ParRdWrTime=0;
					ParRdWrNm=SPEED_HIGH_PORT_SEQ;
				}
			}
*/
			break;

		case	SPEED_HIGH_PORT_SEQ:			
/*
			tmp_address=(Addr_HighSpdPort & 0xfff0);
			tmp_address=(tmp_address | (unsigned int)(cF_SPEED_HIGH_PORT));

			if(ThisRdWrMode == RDWR_READY_SEQ){
				IntThisNewAddressData_Load(tmp_address,0,0,0);
			}
			else{
				if(IntMyDataOkChk(tmp_address)){
					EVHighSpd= (This_Value * 10);  // hz read

					if( (cF_SPEED_HIGH_PORT ==0)){
						EVHighSpd=0;
					}

					Length1=((xVarMpm1000 * 10)/xVarMaxHz);
					xVarCurMpm=(Length1 * EVHighSpd)/10;

					CurDecPulseCalcu();
					EVHighDecLength=CurSpdDecPulse;
					Length1=GET_LONG(DEC_LENGTH_SPD_HIGH);
					if(EVHighDecLength != Length1)		bParameterMdf=1;

*/

					if(bParameterMdf){
						if(FlashWrCnt<10){
							FlashWrCnt++;
							SaveVerify = 0x55;
	
							for(k=0;k<16;k++){
								parameter_mirror[k]=FlashDspCharBuf[ENCODER_PULSE+k].long_data;  
							}
	
							k=( (ENCODER_PULSE) % (ENCODER_PULSE));
							l_LdTmpBufRam(k)=(unsigned long)xVarEncoder;
	
	//						k=( (NEW_MPM) % (ENCODER_PULSE));
	//						l_LdTmpBufRam(k)=(unsigned long)xVarMpm;
	
							k=( (RPM) % (ENCODER_PULSE));
							l_LdTmpBufRam(k)=(unsigned long)xVarRpm;
	
	
							k=( (BASE_DEC_TIME) % (ENCODER_PULSE));
							l_LdTmpBufRam(k)=(unsigned long)xVarDecTime;
			
							k=( (BASE_SCURVE_TIME) % (ENCODER_PULSE));
							l_LdTmpBufRam(k)=(unsigned long)xVarSCurve;		
	
							k=( (DEC_PULSE_SPD_LOW) % (ENCODER_PULSE));
							l_LdTmpBufRam(k)=(unsigned long)xLowSpdMpm;		
	
							k=( (DEC_PULSE_SPD_MID) % (ENCODER_PULSE));
							l_LdTmpBufRam(k)=(unsigned long)xMidSpdMpm;		
	
	/*
							k=( (DEC_LENGTH_SPD_HIGH) % (ENCODER_PULSE));
							l_LdTmpBufRam(k)=(unsigned long)EVHighDecLength;		
	*/
	
							k=( (BASE_DEC_MPM) % (ENCODER_PULSE));
							l_LdTmpBufRam(k)=(unsigned long)xDecMpm;		
	
	
							flash_write(ENCODER_PULSE);
							CaluDecreasePulse_spd3();
							bParameterMdf=0;
							SaveVerify=0;
						}
					}
					else{
						FlashWrCnt=0;
					}

					ParRdWrNm=SPEED_MANUAL_PORT_SEQ;
//				}
//			}
			break;
		case	SPEED_MANUAL_PORT_SEQ:
			tmp_address=(Addr_ManualSpdPort & 0xfff0);
			tmp_address=(tmp_address | (unsigned int)(cF_MANUALSPEED));

			if(!IN_AUTO && !bMoveCar){
				if(ThisRdWrMode == RDWR_READY_SEQ){
					IntThisNewAddressData_Load(tmp_address,0,0,0);
				}
				else{
					if(IntMyDataOkChk(tmp_address)){
						EVManualSpd= (This_Value * 10);  // hz read
						
						if( (cF_MANUALSPEED ==0)){
							EVManualSpd=0;
						}
	 
						Length1=((xVarMpm1000 * 10)/xVarMaxHz);
						xVarCurMpm=(Length1 * EVManualSpd)/10;
						ParRdWrNm=CUR_AMP_SEQ;

///*	manual speed > 10.0  -> manual spd slow  
						j=0;
						while(xVarCurMpm > 10000){
							EVManualSpd=(EVManualSpd-1000);
							Length1=((xVarMpm1000 * 10)/xVarMaxHz);
							xVarCurMpm=(Length1 * EVManualSpd)/10;
							j=1;	
						};
				
					    if(j==1){
							EVManualSpd=(EVManualSpd/10);
							portadr=(unsigned char)(EVManualSpd >> 8);
							IntThisNewAddressData_Load(tmp_address,1,portadr,(unsigned char)EVManualSpd);
							ThisRdWrMode=PARAMETER_WR_SEQ;
							bL1000_Enter=1;
							ParRdWrTime=900;					
						}
//
				
					}
				}
			}
			else	ParRdWrNm=CUR_AMP_SEQ;
			break;

		case	CUR_AMP_SEQ:
			if(ThisRdWrMode == RDWR_READY_SEQ){
				IntThisNewAddressData_Load(Addr_CurAmp,0,0,0);
				ThisRdWrMode=PARAMETER_RD_SEQ;  // attribute not read
			}
			else{
				if(IntMyDataOkChk(Addr_CurAmp)){
					CurAmp=(unsigned int)(This_Value);
					ParRdWrNm=INVETER_NOT_SEL_SEQ;
 					if(bMoveCar){
						ParRdWrTime=900;	// 100msec
					}
				}
			}
			break;
		default:
			ThisRdWrMode=RDWR_READY_SEQ;
			break;


	}

#endif

	return(0);
}







LocalType __attribute__((section(".usercode"))) Inverter_ParameterRdWr(void)
{    

/*
	if(ThisRdWrMode==RDWR_READY_SEQ)	ParRdWrReadyTimer=0;

	if(ParRdWrReadyTimer > 200){
		ThisRdWrMode=RDWR_READY_SEQ;
		ParRdWrReadyTimer=0;
	}
*/





	if(!bMoveCar){
		if(ESC_KeyCheck()){
			if(ParRdWrNm != INVETER_RW_SEQ){
				ParRdWrTime=0;
				ParRdWrNm=INVETER_RESET_SEQ;
			}
		}

		if(BefParRdWrNm != ParRdWrNm){
			BefParRdWrNm=ParRdWrNm;
			ParRdWrReadyTimer=0;
		}
		else if(ParRdWrReadyTimer > 200){
			ThisRdWrMode=RDWR_READY_SEQ;
			ParRdWrReadyTimer=0;
			ParRdWrNm=INVETER_NOT_SEL_SEQ;
		}
	}
	else{
		if((ThisRdWrMode==PARAMETER_WR_SEQ) || (ThisRdWrMode==WAIT_PARAMETER_WR_SEQ)){
			ThisRdWrMode=RDWR_READY_SEQ;
		}
	}




	switch(ParRdWrNm){
		case	INVETER_RW_SEQ:
			break;
		case	INVETER_RESET_SEQ:
			if(ThisRdWrMode == RDWR_READY_SEQ){
				IntThisNewAddressData_Load(Addr_Reset,1,0,0x02);
				ThisRdWrMode=PARAMETER_WR_SEQ;
			
			}
			else{
				if(IntMyDataOkChk(Addr_Reset)){
					ParRdWrNm=INVETER_NOT_SEL_SEQ;
				}
			}						
			break;

		default:
			#ifdef		AUTO_LANDING_485			
			Default_Inverter_ParameterRdWr();
			#endif
			break;
	}

	Inverter_Par_Adr_RdWr(ThisRdWrAddrH,ThisRdWrAddrL,ThisRdWrWNm,ThisRdWrValueH,ThisRdWrValueL);

	return(0);
}


#endif

