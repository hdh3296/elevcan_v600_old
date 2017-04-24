



#include <p30fxxxx.h>
#include  "30f6010_io.h"            
#include  "host_io.h"            
#include  "iodef.h"
#include  "door.h"
#include  "com.h"
#include  "counter.h"
#include    "you_can2.h" 
#include	"Host_NewProtocol.h" 


void  __attribute__((section(".usercode"))) NormalDataReturn_485(void)
{
   	unsigned char   My485Address=0,ThisCmd;
    unsigned int   j,mpm; 

	typedef  union  _long_Type
	{
	    unsigned char byte[4];
	    unsigned int  intger[2];
	    unsigned long long_data; 
	}long_type1;

	long_type1	long_type;


	ThisCmd=RxBuffer[2];

	My485Address=cF_GroupNm;
	My485Address=(My485Address << 3);
	My485Address=(My485Address | cF_LocalNm);

	
	RxBuffer[0]=0xfe;
	RxBuffer[1]=My485Address;
	RxBuffer[2]=0xA3;
	RxBuffer[3]=0x28;
//	RxBuffer[3]=0x58;
		

	RxBuffer[4] =(sRamDArry[S0_FLOOR]        + (unsigned char)(cF_START_FLOOR));
	RxBuffer[5] = sRamDArry[S1_STATE];
	RxBuffer[6] = sRamDArry[S2_STATE];
	RxBuffer[7] = sRamDArry[S3_STATE];
	RxBuffer[8] = sRamDArry[S4_STATE];
	RxBuffer[9] =(sRamDArry[DEST_FLR]        + (unsigned char)(cF_START_FLOOR));
	RxBuffer[10]= sRamDArry[DSP1];
	RxBuffer[11]= sRamDArry[DSP2];


/////////////////////////////////////////////
	j=cF_START_FLOOR;
	
	long_type.byte[0] = sRamDArry[FLR_ON_OFF0];
	long_type.byte[1] = sRamDArry[FLR_ON_OFF1];
	long_type.byte[2] = sRamDArry[FLR_ON_OFF2];
	long_type.byte[3] = sRamDArry[FLR_ON_OFF3];     
	
	long_type.long_data = (long_type.long_data << j);
	
	
	RxBuffer[12]= long_type.byte[0];
	RxBuffer[13]= long_type.byte[1];
	RxBuffer[14]= long_type.byte[2];
	RxBuffer[15]= long_type.byte[3];     
	
	RxBuffer[16]=0;
	RxBuffer[17]=0;
	RxBuffer[18]=0;
	
#ifdef	FLOOR_64
			if(sRamDArry[mEqualFloor] 	>0)	RxBuffer[16]=(sRamDArry[mEqualFloor]     + (unsigned char)(cF_START_FLOOR));
            if(sRamDArry[mHighFloor] 	>0){
				RxBuffer[17]=(sRamDArry[mHighFloor]      + (unsigned char)(cF_START_FLOOR));
				if( (sRamDArry[mMostLongDst] & ONLY_FLR) > (sRamDArry[mHighFloor] & ONLY_FLR)){
					RxBuffer[17] = (RxBuffer[17] | UP_READY);	
				} 
			}
            if(sRamDArry[mLowFloor] 	>0)	{
				RxBuffer[18]=(sRamDArry[mLowFloor]       + (unsigned char)(cF_START_FLOOR));
				if( (sRamDArry[mMostLongDst] & ONLY_FLR) < (sRamDArry[mLowFloor] & ONLY_FLR)){
					if(sRamDArry[mMostLongDst] > 0)	
					RxBuffer[18] = (RxBuffer[18] | DN_READY);	
				} 				
			}


#else
	if(sRamDArry[mEqualFloor] & UPDN_CAR_READY)	RxBuffer[16]=(sRamDArry[mEqualFloor]      + (unsigned char)(cF_START_FLOOR));
	if(sRamDArry[mHighFloor] & UPDN_CAR_READY)	RxBuffer[17]=(sRamDArry[mHighFloor]       + (unsigned char)(cF_START_FLOOR));
	if(sRamDArry[mLowFloor] & UPDN_CAR_READY)	RxBuffer[18]=(sRamDArry[mLowFloor]        + (unsigned char)(cF_START_FLOOR));
#endif
	RxBuffer[19]= sRamDArry[mDoor];
//////////////////////////////////////////////////////

	RxBuffer[20]= sRamDArry[mCarOpCl];
	RxBuffer[21]= sRamDArry[mCarKey1];
	RxBuffer[22]= sRamDArry[mCarKey9];
	RxBuffer[23]= sRamDArry[mCarKey17];     
	RxBuffer[24]= sRamDArry[mCarKey25];
	RxBuffer[25]= sRamDArry[mSysStatus];
	RxBuffer[26]= sRamDArry[O_OP];
	RxBuffer[27]= sRamDArry[O_U_W];
/////////////////////////////////////////////

	RxBuffer[28]= sRamDArry[O_Y_0];
	RxBuffer[29]= sRamDArry[I_EMG];
	RxBuffer[30]= sRamDArry[I_SU1];
	RxBuffer[31]= sRamDArry[I_GR];     
	RxBuffer[32]= sRamDArry[I_FIRE];
	RxBuffer[33]=(sRamDArry[mMostLongDst]    + (unsigned char)(cF_START_FLOOR));
	RxBuffer[34]= (unsigned char)(cF_START_FLOOR);
	RxBuffer[35]=(cF_TOPFLR       + (unsigned char)(cF_START_FLOOR));

////////////////////////////////////////////

	mpm=(unsigned int)CurMeterPerMin;
	RxBuffer[36]= (unsigned char)mpm;
	RxBuffer[37]= (unsigned char)(mpm >> 8);
	RxBuffer[38]= sRamDArry[mExtIN0];
	RxBuffer[39]= sRamDArry[I_X_0];     
	RxBuffer[40]= sRamDArry[I_FS0];
	RxBuffer[41]= sRamDArry[S5_STATE_37];
	RxBuffer[42]= sRamDArry[mCrtExtMoveFlr];
	RxBuffer[43]= sRamDArry[mCallMe];
	RxBuffer[43]= ThisCmd;

    Com1Crc=0xffff;
    for(j=0;j<(RxBuffer[3]+4);j++){
        Crc_Calulate_Cmm1((unsigned int)RxBuffer[j]);
    }
    RxBuffer[j]=(unsigned char)(Com1Crc & 0x00ff);
    RxBuffer[j+1]=(unsigned char)((Com1Crc >> 8) & 0x00ff);
    RxBuffer[j+2]=0;


	Com1RxREGClear();

	TXEN=0;  
	SerialTime=0;
   	RxCurCnt=0;	
   	RxStatus=TX_SET;
    U1TXREG=RxBuffer[RxCurCnt];
   	RxCurCnt=1;   

}




LocalType __attribute__((section(".usercode"))) HostCommandAct_485(void)
{
    unsigned int   good; 

	good=0;

    if((RxBuffer[2]    ==   (PC_COMMAND | CMD_PARKING)) && (RxBuffer[3] == 0x00)){
        if(RxBuffer[4] == 0x01) bExt_PRKING = 1;
        else                    bExt_PRKING = 0;
		good=1;
    }    
    else if((RxBuffer[2]    ==   (PC_COMMAND | CMD_FIRE)) && (RxBuffer[3] == 0x00)){
        if(RxBuffer[4] == 0x01) bExt_FIRE = 1;
        else                    bExt_FIRE = 0;
		good=1;
    }
    else if((RxBuffer[2]    ==   (PC_COMMAND | CMD_FAMILY_SEV)) && (RxBuffer[3] == 0x00)){
        if(RxBuffer[4] == 0x01) bExt_FAMILY = 1;
        else                    bExt_FAMILY = 0;
		good=1;
    }

    else if((RxBuffer[2]    ==   (PC_COMMAND | CMD_VIP)) && (RxBuffer[3] == 0x00)){
        if(RxBuffer[4] == 0x01) bExt_VIP = 1;
        else                    bExt_VIP = 0;
		good=1;
    }
    else if((RxBuffer[2]    ==   (PC_COMMAND | CMD_SECOND_FIRE)) && (RxBuffer[3] == 0x00)){
        if(RxBuffer[4] == 0x01) bExt_Second_FIRE = 1;
        else                    bExt_Second_FIRE = 0;
		good=1;
    }
    else if((RxBuffer[2]    ==   (PC_COMMAND | CMD_CALL_SEV)) && (RxBuffer[3] == 0x00)){
		#ifdef	FLOOR_64
		CrtMoveFlr=(unsigned char)(RxBuffer[4]);
		if(CrtMoveFlr==0)	CrtMoveFlr=(CrtMoveFlr | UP_READY);
		#else
		CrtMoveFlr=(unsigned char)(RxBuffer[4] | CAR_READY);
		#endif
		good=1;
    }
    else if((RxBuffer[2]    ==   (PC_COMMAND | CMD_EXT_CALL_SEV)) && (RxBuffer[3] == 0x00)){
		sRamDArry[mCrtExtMoveFlr]=(unsigned char)(RxBuffer[4]);
		ExtKeyCnt=3;
		good=1;
    }
    else if((RxBuffer[2]    ==   (PC_COMMAND | CMD_FAN_LIGHT_ETC)) && (RxBuffer[3] == 0x00)){
		if( (RxBuffer[4] > 0) &&  (RxBuffer[4] < 0xff)){
			ExtFanTimer=(unsigned char)(RxBuffer[4]-1);
			ExtFanTimer=(ExtFanTimer % 100);
			good=1;
		}
		if( (RxBuffer[5] > 0) &&  (RxBuffer[5] < 0xff)){
			ExtLightTimer=(unsigned char)(RxBuffer[5]-1);
			ExtLightTimer=(ExtLightTimer % 100);
			good=1;
		}
    }

	if(good)	NormalDataReturn_485();	
}



LocalType __attribute__((section(".usercode"))) HostWriteMyData_485(void)
{
//	if( !bMoveCar ){

		CAN2_RxBuf[0]=RxBuffer[0];
		CAN2_RxBuf[1]=RxBuffer[1];
		CAN2_RxBuf[2]=RxBuffer[2];
		CAN2_RxBuf[3]=RxBuffer[3];
		CAN2_RxBuf[4]=RxBuffer[4];
		CAN2_RxBuf[5]=RxBuffer[5];
		CAN2_RxBuf[6]=RxBuffer[6];
		CAN2_RxBuf[7]=RxBuffer[7];


	    if((RxBuffer[2] == (CMD_EVEN_ODD)) && (RxBuffer[3] == 0x00)){
	        Pc_Command();
    		NormalDataReturn_485();    
	    }    
	    else if((RxBuffer[2] == (CMD_MORNING)) && (RxBuffer[3] == 0x00)){
	        Pc_Command();
    		NormalDataReturn_485();    
	    }    
//	}

}


void  __attribute__((section(".usercode"))) CrtReqCheck(void)
{
	unsigned int i,j;
	
	if((RxStatus==RX_GOOD) && (SerialTime > 3)){

	    Com1Crc=0xffff;
	    for(j=0;j<(RxBuffer[3]+4);j++){
	        Crc_Calulate_Cmm1((unsigned int)RxBuffer[j]);
	    }

		j=(unsigned int)( RxBuffer[RxBuffer[3]+4] );
		i=(unsigned int)(RxBuffer[RxBuffer[3]+5]);
		i=(i << 8);
		j=(j | i);

	
		if( (j == Com1Crc) && (RxBuffer[1]== 0xfe)){
		    if( (RxBuffer[2]== 0x23) || (RxBuffer[2]== 0x24)){
				RxBuffer[0]=RxBuffer[2];
				RxBuffer[1]=RxBuffer[3];
				RxBuffer[2]=RxBuffer[4];
				RxBuffer[3]=RxBuffer[5];
				RxBuffer[4]=RxBuffer[6];
				RxBuffer[5]=RxBuffer[7];
				RxBuffer[6]=RxBuffer[8];
				RxBuffer[7]=RxBuffer[9];
	
			    switch(RxBuffer[0]){
			        case    0x23:
		        		NormalDataReturn_485();
			            break;
			        case    0x24:
			            if(RxBuffer[2] & PC_COMMAND){
			                HostCommandAct_485();             
			            }
			            else{
			                HostWriteMyData_485();             
			            }
			            break;
	
				}
			}
/*
		#ifndef	AUTO_LANDING_COMM
			else{
				if(CommonNewSoketChk(COM_PORT_COM1)){
					CommonConnectPort=COM_PORT_COM1;
					CommonConnectPortTime=0;

					CommonRxCnt=0; 
					for(i=0;i<RxBuffer[3]+2;i++){
						CommonRcvBuf[i]=RxBuffer[2+i];
						CommonRxCnt++; 
					}
					CommonDataCheck();

					if(CommonRxGood==1){
						RxBuffer[1]=RxBuffer[0];
						RxBuffer[0]=0xfe;

						for(i=0;i<CommonRcvBuf[1]+2;i++){
							RxBuffer[2+i]=CommonRcvBuf[i];
						}

					    Com1Crc=0xffff;
					    for(j=0;j<(RxBuffer[3]+4);j++){
					        Crc_Calulate_Cmm1((unsigned int)RxBuffer[j]);
					    }
					    RxBuffer[j]=(unsigned char)(Com1Crc & 0x00ff);
					    RxBuffer[j+1]=(unsigned char)((Com1Crc >> 8) & 0x00ff);
					    RxBuffer[j+2]=0;
					

						Com1RxREGClear();
						TXEN=0;  
						SerialTime=0;
					   	RxCurCnt=0;	
					   	RxStatus=TX_SET;
					    U1TXREG=RxBuffer[RxCurCnt];
					   	RxCurCnt=1;   

						CommonConnectPort=COM_PORT_NO;
						CommonRxGood=0;
					}
				}
			}
		#endif
*/
			if(RxStatus != TX_SET){
				SerialTime=0;
			   	RxCurCnt=0;
			   	RxStatus=STX_CHK;
			}
		}
		else{
			SerialTime=0;
		   	RxCurCnt=0;
		   	RxStatus=STX_CHK;
		}   
	}
}


//#endif






