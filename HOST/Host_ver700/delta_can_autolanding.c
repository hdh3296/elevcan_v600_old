

#include <p30fxxxx.h>
#include 	"you_can_lib.h" 
#include 	"you_can2.h" 

           
#include  	"30f6010_io.h"            
#include  	"host_io.h"            
#include  	"iodef.h"
#include  	"door.h"
#include  	"com.h"
#include  	"counter.h"
#include	"Host_NewProtocol.h" 
#include	"you_can2.h" 
#include  	"default_setup.h" 
#include  	"Host_Autolanding.h" 




#ifdef	DELTA_INVERTER_AUTOLANDING_CAN




extern	LocalType __attribute__((section(".usercode"))) DeltaDataSortForPDO(void);

extern UserDataType    EnterKey;



#define		HOST_SDO_0		0x60		
#define		HOST_SDO_1		0x61		
#define		HOST_SDO_2		0x62		
#define		HOST_PDO		0x01		
#define		INVERTER_SDO	0x50		
#define		INVERTER_PDO	0x02		


#define		INV_COM_ERR_TIME	100   // 100msec		


#define		IV_POWER_ON_CHK		0x01
#define		IV_FHM_SUCCESS		0x02
#define		IV_FHM_EXCUTE		0x04
#define		IV_PG_P_RECORD		0x08
#define		IV_PG_P_RESET		0x10


#define		FHM_CMD_EXCUT		(IV_FHM_EXCUTE 					| IV_POWER_ON_CHK)
#define		FHM_CMD_P_RESET_H	(IV_FHM_EXCUTE | IV_PG_P_RESET 	| IV_POWER_ON_CHK)
#define		FHM_CMD_P_RESET_L	(IV_FHM_EXCUTE  				| IV_POWER_ON_CHK)
#define		FHM_CMD_P_RECORD_H	(IV_FHM_EXCUTE | IV_PG_P_RECORD | IV_POWER_ON_CHK)
#define		FHM_CMD_P_RECORD_L	(IV_FHM_EXCUTE 					| IV_POWER_ON_CHK)
#define		FHM_CMD_SUCCESS		(IV_FHM_SUCCESS 				| IV_POWER_ON_CHK)


#define		AUTO_TUN_END		0x00
#define		AUTO_TUN_STOPPING	0x02
#define		AUTO_TUN_RUNNING	0x03



#define		IV_READY_0		0x01
#define		IV_ERROR_0		0x02
#define		IV_WARNNING_0	0x04
#define		IV_UP_0			0x08
#define		IV_DOWN_0		0x10
#define		IV_NORMAL_0		0x20
#define		IV_CONST_SPD_0	0x40
#define		IV_ZERO_SPD_0	0x80

#define		IV_INSPE_1		0x01
#define		IV_RESCUE_1		0x02
#define		IV_RELEVEL_1	0x04
#define		IV_RESERVE2_1	0x08
#define		IV_RESERVE3_1	0x10
#define		IV_DECREASE_1	0x20
#define		IV_FSD_1		0x40
#define		IV_BK_RELEASE_1	0x80









unsigned char	Delta_bUnd;



/*
LocalType __attribute__((section(".usercode"))) Set_Fhm_Cmd(void)
{    
	ParRdWrNm=INVETER_FHM_RUN;
}
*/


LocalType __attribute__((section(".usercode"))) Set_Fhm_Cmd(void)
{    
ParRdWrNm=INVETER_RW_SEQ;	
//	ParRdWrNm=INVETER_PARAMETER_WR;

	ThisRdWrMode=PARAMETER_WR_SEQ;
}



LocalType __attribute__((section(".usercode"))) DeltaRdWrFhm(unsigned char addressH,unsigned char addressL)
{    

	unsigned int val,dp;
	unsigned int ret=0;

	switch(DeltaRdWrStatusFhm){
		case	0:
			ThisNewAddressData_Load(0x09,0x0a,1,0,0);
			Set_Fhm_Cmd();
			DeltaRdWrStatusFhm=1;
			break;
		case	1:
			if(MyDataOkChk(0x09,0x0a)){
				if(IV_AckRdWrTxBuf[6] == 0){
					DeltaRdWrStatusFhm=2;
				}
				else{
					DeltaRdWrStatusFhm=0;	
				}
			}
			else{
				if(WaitAckTimeOutChk())	DeltaRdWrStatusFhm=0;	
			}	
			break;	

		case	2:
			ThisNewAddressData_Load(0x09,0x0a,1,0,FHM_CMD_EXCUT);
			Set_Fhm_Cmd();
			DeltaRdWrStatusFhm=3;
			break;
		case	3:
			if(MyDataOkChk(0x09,0x0a)){
				if(IV_AckRdWrTxBuf[6] == FHM_CMD_EXCUT){
					DeltaRdWrStatusFhm=4;
				}
				else{
					DeltaRdWrStatusFhm=2;	
				}
			}
			else{
				if(WaitAckTimeOutChk())	DeltaRdWrStatusFhm=2;	
			}	
			break;	

		case	4:
			ThisNewAddressData_Load(0x09,0x0a,1,0,FHM_CMD_P_RESET_H);
			Set_Fhm_Cmd();
			DeltaRdWrStatusFhm=5;
			break;
		case	5:
			if(MyDataOkChk(0x09,0x0a)){
				if(IV_AckRdWrTxBuf[6] == FHM_CMD_P_RESET_H){
					DeltaRdWrStatusFhm=6;
				}
				else{
					DeltaRdWrStatusFhm=4;	
				}
			}
			else{
				if(WaitAckTimeOutChk())	DeltaRdWrStatusFhm=4;	
			}	
			break;	
		case	6:
			ThisNewAddressData_Load(0x09,0x0a,1,0,FHM_CMD_P_RESET_L);
			Set_Fhm_Cmd();
			DeltaRdWrStatusFhm=7;
			break;
		case	7:
			if(MyDataOkChk(0x09,0x0a)){
				if(IV_AckRdWrTxBuf[6] == FHM_CMD_P_RESET_L){
					DeltaRdWrStatusFhm=8;
				}
				else{
					DeltaRdWrStatusFhm=6;	
				}
			}
			else{
				if(WaitAckTimeOutChk())	DeltaRdWrStatusFhm=6;	
			}	
			break;	
		case	8:
			ret=1;	
			break;	
		case	9:
			ThisNewAddressData_Load(0x09,0x0a,1,0,FHM_CMD_P_RECORD_H);
			Set_Fhm_Cmd();
			DeltaRdWrStatusFhm=10;
			break;
		case	10:
			if(MyDataOkChk(0x09,0x0a)){
				if(IV_AckRdWrTxBuf[6] == FHM_CMD_P_RECORD_H){
					DeltaRdWrStatusFhm=11;
				}
				else{
					DeltaRdWrStatusFhm=9;	
				}
			}
			else{
				if(WaitAckTimeOutChk())	DeltaRdWrStatusFhm=9;	
			}	
			break;	
		case	11:
			ThisNewAddressData_Load(0x09,0x0a,1,0,FHM_CMD_P_RECORD_L);
			Set_Fhm_Cmd();
			DeltaRdWrStatusFhm=12;
			break;
		case	12:
			if(MyDataOkChk(0x09,0x0a)){
				if(IV_AckRdWrTxBuf[6] == FHM_CMD_P_RECORD_L){
					DeltaRdWrStatusFhm=13;
				}
				else{
					DeltaRdWrStatusFhm=11;	
				}
			}
			else{
				if(WaitAckTimeOutChk())	DeltaRdWrStatusFhm=11;	
			}	
			break;

		case	13:
			ThisNewAddressData_Load(0x09,0x0a,1,0,(IV_AckRdWrTxBuf[6] & (~IV_FHM_EXCUTE)));
			Set_Fhm_Cmd();
			DeltaRdWrStatusFhm=14;
			break;
		case	14:
			if(MyDataOkChk(0x09,0x0a)){
				if( !(IV_AckRdWrTxBuf[6] & IV_FHM_EXCUTE)){
					DeltaRdWrStatusFhm=15;
				}
				else{
					DeltaRdWrStatusFhm=13;	
				}
			}
			else{
				if(WaitAckTimeOutChk())	DeltaRdWrStatusFhm=13;	
			}	
			break;
	
		case	15:
			ThisNewAddressData_Load(0x09,0x0a,1,0,FHM_CMD_SUCCESS);
			Set_Fhm_Cmd();
			DeltaRdWrStatusFhm=16;
			break;
		case	16:
			if(MyDataOkChk(0x09,0x0a)){
				if( IV_AckRdWrTxBuf[6] == FHM_CMD_SUCCESS){
					DeltaRdWrStatusFhm=17;
				}
				else{
					DeltaRdWrStatusFhm=15;	
				}
			}
			else{
				if(WaitAckTimeOutChk())	DeltaRdWrStatusFhm=15;	
			}	
			break;	
		case	17:	
			ThisNewAddressData_Load(4,52,1,0,0);
			DeltaRdWrStatusFhm=18;
			break;
		case	18:
			if(MyDataOkChk(4,52)){
				if( (IV_AckRdWrTxBuf[6] >= 2) && (IV_AckRdWrTxBuf[6] <= 3)){
					DeltaRdWrStatusFhm=19;
				}
				else{
					sRamDArry[FHM_SEQ] = FHM_SEQ_6;						
					DeltaRdWrStatusFhm=19;
				}
			}
			else{
				if(WaitAckTimeOutChk())	DeltaRdWrStatusFhm=17;	
			}	
			break;	
		case	19:
			ParRdWrNm=INVETER_NOT_SEL_SEQ;
			ret=1;
			break;
		default:
			DeltaRdWrStatusFhm=0;
			break;	
	}

	return(ret);
}	











LocalType __attribute__((section(".usercode"))) DeltaDecCheck(void)
{
	if(InvStatus[1] & IV_DECREASE_1)	return(1);
	else								return(0);
}


LocalType __attribute__((section(".usercode"))) BreakReleaseCheck(void)
{
	if(InvStatus[1] & IV_BK_RELEASE_1)		return(1);
	else									return(0);
}


LocalType __attribute__((section(".usercode"))) DeltaZeroHzSet(void)
{
	if(InvStatus[0] & IV_ZERO_SPD_0)	return(1);
	else								return(0);
}






LocalType __attribute__((section(".usercode"))) DeltaInvertFloorResetting(void)
{
	if( InvStatus[5] != sRamDArry[S0_FLOOR]){
		bsInvCurNext=1;

		if(ThisRdWrMode==RDWR_READY_SEQ){
			ThisNewAddressData_Load(4,23,1,0,sRamDArry[S0_FLOOR]);
			ParRdWrNm=INVETER_RW_SEQ;
			ThisRdWrMode=PARAMETER_WR_SEQ;
		}

	} 	
	return(0);
}



LocalType __attribute__((section(".usercode"))) DeltaInverterReqStopFloor(void)
{
	if(InvStatus[3] > 0){
		sRamDArry[mReqStopFloor] = (InvStatus[3] - 1); 
	}
	else{
		sRamDArry[mReqStopFloor] = (InvStatus[5] - 1); 
	}

	sRamDArry[mReqStopFloor] = (sRamDArry[mReqStopFloor] | CAR_READY);


	if( !bMoveCar){
		Delta_bUnd=0;
	}
	else{
		if(DeltaDecCheck())	Delta_bUnd=1;
	}

	if(Delta_bUnd==1)	bUnd=1;
	else				bUnd=0;

	return(0);
}


/*
LocalType __attribute__((section(".usercode"))) DeltaInverterUpFlrChk(void)
{
    unsigned long tmppulse1,tmppulse2,newFloor;

	if( (sRamDArry[mcurfloor] >= cF_TOPFLR) && !IN_SU1 && (bCarUpMove)){
	    tmppulse1=FLOOR_COUNT(cF_TOPFLR);
	    tmppulse2=FLOOR_COUNT(cF_TOPFLR-1);
        newFloor=(tmppulse1-tmppulse2);

        newFloor=(unsigned long)(newFloor >> 1);  // 1/2
        tmppulse1=(unsigned long)(newFloor >> 1); // 1/4

        newFloor=(unsigned long)(tmppulse2 + newFloor + tmppulse1);

        if((unsigned long)CurPulse >= (unsigned long)newFloor){
			return(1);
        }
	}

	return(0);            
}



LocalType __attribute__((section(".usercode"))) DeltaInverterDnFlrChk(void)
{
    unsigned long tmppulse1,tmppulse2,newFloor;

	if( (sRamDArry[mcurfloor] == 0) && !IN_SD1 && (bCarDnMove)){
        tmppulse1=FLOOR_COUNT(sRamDArry[mcurfloor+1]);
        tmppulse2=FLOOR_COUNT(sRamDArry[mcurfloor]);

        newFloor=(tmppulse1-tmppulse2);
        newFloor=(unsigned long)(newFloor >> 2);  // 1/4
        newFloor=(unsigned long)(tmppulse2 + newFloor);

        if((unsigned long)CurPulse <= (unsigned long)newFloor){
			return(1);
        }
	}

	return(0);            
}
*/



LocalType __attribute__((section(".usercode"))) DeltaTopFirstFloorChkSearch(void)
{
	if(bOneLuOrLd){
		if( (sRamDArry[mcurfloor]==0) 			&& (IN_SD1))		return(0);
		else if( (sRamDArry[mcurfloor]== cF_TOPFLR)  && (IN_SU1))	return(0);
		else														return(1);		
	}	
	return(0);
}



LocalType __attribute__((section(".usercode"))) DeltaTopFirstFloorChk(void)
{
	unsigned int i,j;

	i=0;

	if(bOneLuOrLd){
		if( bFhmRun  && !IN_SD1 && bCarDnMove)										return(1);
		else if( bFhmRun  && !IN_SU1 && bCarUpMove)									return(1);
		else if( (sRamDArry[mcurfloor]==0) 			&& (!IN_SD1) && bCarDnMove)		return(1);
		else if( (sRamDArry[mcurfloor]== cF_TOPFLR)  && (!IN_SU1) && bCarUpMove)	return(1);
		else																		return(0);
	}	
	return(0);
}




LocalType __attribute__((section(".usercode"))) DeltaCancleValidChk(unsigned int up_dn)
{
	unsigned long ev_mpm,cur_mpm,min_mpm;

	min_mpm=10;

	ev_mpm=(unsigned long)GET_LONG(NEW_MPM);
	ev_mpm=(ev_mpm * 80)/100;          		// 80%  of max mpm
	cur_mpm=(unsigned long)CurMeterPerMin;

	cur_mpm=(cur_mpm/10);					//new 
//	cur_mpm=(cur_mpm/10);					//


	if(Delta_bUnd==1){
		return(0);
	}
	else if((InvStatus[0] & IV_CONST_SPD_0)){
		return(1);  // cancle
	}
	else{
		if(CurMeterPerMin > ev_mpm){
			return(1);
		}
	}


/*
	if(Delta_bUnd==1){
		return(0);
	}
	else if(!(InvStatus[0] & IV_CONST_SPD_0)){
		if(cur_mpm < ev_mpm){
			if(cur_mpm > min_mpm){
				return(0);
			}
		}
	}
	return(1);			
*/

	return(0);			
}













void __attribute__((section(".usercode"))) 	DeltaNoButtonAndDefaultLoad(void)
{

	sRamDArry[DEST_FLR]=sRamDArry[mAckStopFloor] = sRamDArry[mReqStopFloor];

/*
#ifdef	FLOOR_64
	if(sRamDArry[mReqStopFloor] & UPDN_READY){
		sRamDArry[DEST_FLR]=sRamDArry[mAckStopFloor] = sRamDArry[mReqStopFloor];
	}         	
#else
	if(sRamDArry[mReqStopFloor] & CAR_READY){
		sRamDArry[DEST_FLR]=sRamDArry[mAckStopFloor] = sRamDArry[mReqStopFloor];
	}         	
#endif
*/

}


void __attribute__((section(".usercode"))) DeltaNewFloorLoadCheck(void)
{
    if(bCarUpMove && (sRamDArry[mHighFloor]==0)){    		
		NoButtonAndDefaultLoad();
	}
    else if(bCarDnMove && (sRamDArry[mLowFloor]==0)){    
		NoButtonAndDefaultLoad();
	}
   	else if(sRamDArry[mAckStopFloor] == 0){
		NoButtonAndDefaultLoad();	
	}
	else{
	  	if(bCarUpMove){
	        sRamDArry[DEST_FLR]=sRamDArry[mAckStopFloor] = sRamDArry[mHighFloor];            																							
	    }
	    else if(bCarDnMove){
	        sRamDArry[DEST_FLR]=sRamDArry[mAckStopFloor] = sRamDArry[mLowFloor];																							
	    }	
	}
}            		




void   __attribute__((section(".usercode"))) DeltaNewFloorLoad(void)
{  	
   	if(bCarUpMove){
   		if(sRamDArry[DEST_FLR] != sRamDArry[mHighFloor]){
			if( DeltaCancleValidChk(1)){	
				DeltaNewFloorLoadCheck();
			}				
   		}
   	}
   	else if(bCarDnMove){
   		if(sRamDArry[DEST_FLR] != sRamDArry[mLowFloor]){
			if( DeltaCancleValidChk(2)){	
				DeltaNewFloorLoadCheck();
			}	
   		}
   	}                        

	if(!(sRamDArry[mAckStopFloor] & UPDN_CAR_READY)){
		if(sRamDArry[mReqStopFloor] & CAR_READY){	
			sRamDArry[mAckStopFloor] = sRamDArry[mReqStopFloor];		
		}
	}
}



void  __attribute__((section(".usercode")))  Delta_ComErrChk(void)
{
	if(InverterPDORxTime > INV_COM_ERR_TIME)	bInvComErr=1;
	else										bInvComErr=0;	
	
	if(bInvComErr){
		if(bMoveCar){
			if(PerfectAuto()){
				bStrongDec=1; 					
			}
			else	bCarErr=1;
		}
		else{
			bCarErr=1;
		}	
		bsInvCurNext=0;
	}
}





LocalType __attribute__((section(".usercode"))) DeltaStopChk(void)
{

	unsigned int ret=0;


	unsigned char InvFloor,HostFloor;

	ret=0;

	InvFloor=InvStatus[5];
	HostFloor=(sRamDArry[mcurfloor]+1);
	sRamDArry[mInvFloor] = (InvFloor-1);  		      



	if(!bInvComErr){
		if( !bMoveCar){
			if( (InvFloor >= 1) && (InvFloor != HostFloor) && (WarmingUpTime > 20) && !IN_AUTO  && bOnLuLd){
				if(HostFloor <= (cF_TOPFLR+1)/2)	sRamDArry[mcurfloor]=0;
				else								sRamDArry[mcurfloor]=cF_TOPFLR;

				DeltaInvertFloorResetting();
			}
			else{
				bsInvCurNext=0;
			}
		}
	}


	if(PerfectAuto()){ 					
		if( bMoveCar && bOnLuLd && (InvFloor != HostFloor)){
			bStrongDec=1;
		}

		if(bCarUpMove){
			HostFloor=(cF_TOPFLR+1);
			if(!IN_SU1){
				if(InvFloor != HostFloor){
					bStrongDec=1;
				}
			}

			if( InvStatus[4] > HostFloor){
				bStrongDec=1;
			}

		}

		else if(bCarDnMove){
			HostFloor=1;
			if(!IN_SD1){
				if(InvFloor != HostFloor){
					bStrongDec=1;
				}
			}
		
			if( !DeltaZeroHzSet()){
				if(InvStatus[4] < HostFloor){
					bStrongDec=1;
				} 
			}
		}
	}



	if(!bMoveCar){
		if(bStrongDec){
			bCarErr=1;
		}	
		bStrongDec=0;	
	}

	return(ret);
}


LocalType __attribute__((section(".usercode"))) DeltaDataSortForPDO(void)
{

	unsigned int i,j;

	PDO_TX_DataBuf[0] 	=0;
	PDO_TX_DataBuf[1]	=0;
	PDO_TX_DataBuf[2]	=0;
	PDO_TX_DataBuf[3]	=0;				
	PDO_TX_DataBuf[4] 	=0;
	PDO_TX_DataBuf[5]	=0;
	PDO_TX_DataBuf[6]	=0;
	PDO_TX_DataBuf[7]	=0;				

	bManDeltaSpdOff=0;

//////////////////////////////////////////////////	
	DeltaStopChk();

	if( (PerfectAuto()) && !(InvStatus[1] & IV_FSD_1)){ 					
	    if((bCarUpMove || bCarDnMove) && (sRamDArry[mAckStopFloor] & UPDN_CAR_READY)){	
			PDO_TX_DataBuf[5]	=((sRamDArry[mAckStopFloor] & ONLY_FLR) + 1);
		}

		if(bMoveCar){
			PDO_TX_DataBuf[0]	= 0x04;

		    if(bCarUpMove){
				if(PDO_TX_DataBuf[5] < InvStatus[3]){
					PDO_TX_DataBuf[5] = InvStatus[3]; 										
				}
			}
			else if(bCarDnMove){
				if(PDO_TX_DataBuf[5] > InvStatus[3]){
					if(InvStatus[3] > 0){
						PDO_TX_DataBuf[5] = InvStatus[3];
					} 										
				}
			}				
		}	
		else{
			PDO_TX_DataBuf[5]	= 0;
			PDO_TX_DataBuf[0]	= 0x0;				
		}
	}
	else{
		if(bMoveCar){		
			if(bSearchHome){
				if(DeltaTopFirstFloorChkSearch()){
					PDO_TX_DataBuf[0]	=0x40;			
				}
				else{
					PDO_TX_DataBuf[0]	=0x10;
				}			
				PDO_TX_DataBuf[5]	=((sRamDArry[mcurfloor] & ONLY_FLR) + 1);
			}
			else{
				if(DeltaTopFirstFloorChk()){
					PDO_TX_DataBuf[0]	=0x40;			
				}
				else{
					PDO_TX_DataBuf[0]	=0x10;
					bManDeltaSpdOff=1;
				}
				PDO_TX_DataBuf[5]	=0;
			}
		}
		else	PDO_TX_DataBuf[0]	=0x10;							                                    

		if( !bDeltaSpdOff && !bFhmRun){
			if(CurSelOutPortChk(cF_BK1) && bManDeltaSpdOff)	PDO_TX_DataBuf[0]	=0x40;
			else											PDO_TX_DataBuf[0]	=0x0;							                                    
		}
	}


	if((InvStatus[0] & IV_ERROR_0)){
		bCarErr=1;                                                     		
	}
		
	PDO_TX_DataBuf[2]	=0x0;


	return(0);
}


LocalType __attribute__((section(".usercode"))) PDO_DataLoad(void)
{
	unsigned int i;

	C2ThisTxSid=HOST_PDO;
	DeltaDataSortForPDO();

	for(i=0;i<8;i++){
		C2ThisTxBuf[i]=PDO_TX_DataBuf[i];
	}

	C2ThisTxDataCnt	=0x08;
	C2TxAct();
	return(0);
}




LocalType __attribute__((section(".usercode"))) InverterReadyCheck(void)
{    
	InverterReady=(InverterReady | 0x01);
	return(0);
}




///////////////////////////////////////////////////////////

void  __attribute__((section(".usercode")))  DeltaCarCurFloorRead(void)
{
    unsigned long tmppulse1,tmppulse2,newFloor;

    CurFTime=0;
	NextFTime=0;

    if(bFhmRun) return;


    if(sRamDArry[mcurfloor] > cF_TOPFLR){
        sRamDArry[mcurfloor]=0;
    }


    if(bCarUpMove){
        if(!IN_SU1){
            if(!IN_EMG)	sRamDArry[mcurfloor]=cF_TOPFLR;   //modify ?
        }

		SpeedReSetting(1);
		SpeedReSetting(2);

        if(sRamDArry[mcurfloor] < cF_TOPFLR){
	        tmppulse1=FLOOR_COUNT(sRamDArry[mcurfloor]+1);
	        tmppulse2=FLOOR_COUNT(sRamDArry[mcurfloor]);
	            
	        newFloor=(tmppulse1-tmppulse2);
	        newFloor=(unsigned long)(newFloor >> 1);
	        newFloor=(unsigned long)(tmppulse2 + newFloor);
	
	        if((unsigned long)CurPulse >= (unsigned long)newFloor){
	            if(sRamDArry[mcurfloor] < cF_TOPFLR) sRamDArry[mcurfloor]++;
	        }
		}
		else{
			sRamDArry[mcurfloor] = cF_TOPFLR;
		}

		if(sRamDArry[mcurfloor] >= cF_TOPFLR){
			sRamDArry[mAckStopFloor] = (sRamDArry[mcurfloor] | DN_READY);
		}
    }

    else if(bCarDnMove){
        if(!IN_SD1){                              //modify ?
            if(!IN_EMG)	sRamDArry[mcurfloor]=0;
     	}

		SpeedReSetting(1);
		SpeedReSetting(2);

        if(sRamDArry[mcurfloor] > 0){
            tmppulse1=FLOOR_COUNT(sRamDArry[mcurfloor]);
            tmppulse2=FLOOR_COUNT(sRamDArry[mcurfloor]-1);

	        newFloor=(tmppulse1-tmppulse2);
	        newFloor=(unsigned long)(newFloor >> 1);
	        newFloor=(unsigned long)(tmppulse2 + newFloor);
	
	        if((unsigned long)CurPulse <= (unsigned long)newFloor){
	            if(sRamDArry[mcurfloor] > 0 ) sRamDArry[mcurfloor]--;
	        }
        }
                    
		if(sRamDArry[mcurfloor] == 0){
	    	sRamDArry[mAckStopFloor] = (sRamDArry[mcurfloor] | UP_READY);				                      
		}
	
    }
}



void  __attribute__((section(".usercode")))  DeltaWaitNextLuLd(void)
{

	
#ifdef	FLOOR_64
	if(((sRamDArry[mReqStopFloor] & ONLY_FLR) == (sRamDArry[mAckStopFloor] & ONLY_FLR))  && (sRamDArry[mReqStopFloor] & UPDN_READY)){
#else
	if(((sRamDArry[mReqStopFloor] & ONLY_FLR) == (sRamDArry[mAckStopFloor] & ONLY_FLR))  && (sRamDArry[mReqStopFloor] & CAR_READY)){
#endif
		RunningOpenAction();

		bDac=1; 

		if( ((sRamDArry[mcurfloor] & ONLY_FLR) == (sRamDArry[mAckStopFloor] & ONLY_FLR)) && bUnd){
			if(bOnLuLd){
				if(DeltaZeroHzSet()){
					sRamDArry[mDoorSeq]=STOP_ELEVATOR;	
				}
			}
		}

		if(!bUnd){
			DeltaNewFloorLoad();
 			if((sRamDArry[mReqStopFloor] & ONLY_FLR) != (sRamDArry[mAckStopFloor] & ONLY_FLR)){
                bDac=0;
			}         
		}
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

		bDac=1;		
 	}			
	else{			       
		bDac=0;		
		DeltaNewFloorLoad();
 	}	


 	if(IN_LU && IN_LD){
		bReLoadEncoder=0;
		bReLoadEncoderExe=0;
	}
	else if(bOnLuLd){
		if(!bReLoadEncoder){
			bReLoadEncoder=1;
        	if( (EncoderCopyOnOff) && (!bUnd)){
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


	if(bInvComErr){
		if(CurMeterPerMin <= 1){
			EncoderClear();
			sRamDArry[mDoorSeq] = STOP_ELEVATOR;
		}
	}

	if(DeltaZeroHzSet()){
		sRamDArry[mDoorSeq] = STOP_ELEVATOR;
	}
}



#endif





