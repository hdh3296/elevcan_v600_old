

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
#include  	"EDS_par_map.h" 






	


extern	LocalType __attribute__((section(".usercode"))) DeltaDataSortForPDO(void);

extern UserDataType    EnterKey;




#define		CAN_BASE_TIME		10		


#define		HOST_SDO_0		0x60		
#define		HOST_SDO_1		0x61		
#define		HOST_SDO_2		0x62		




/*

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
*/



unsigned int	DeltaNoAck=0;
unsigned int	InverterPDORxTime=0;
unsigned int	InverterReady=0;
unsigned int	DeltaRdWrStatusFhm=0;

unsigned char	EV_ReqRdWrTxBuf[27];
unsigned char	IV_AckRdWrTxBuf[27];
unsigned char	ElevStatus[8];
unsigned char	InvStatus[8];
unsigned char	ThisAttribute[8];
unsigned char	PDO_TX_DataBuf[8];

/////////////////////////////////////////unsigned char	Delta_bUnd;
unsigned char	OrgTargetFlr;

unsigned char	RunDataRdWr=0;


unsigned int	IV_This_Attrv,IV_This_Min,IV_This_Max,IV_This_Value;

unsigned int	This_Value;





#ifdef	AUTO_LANDING_CAN

LocalType __attribute__((section(".usercode"))) Delta_ReadAttribute_CAN(unsigned char addressH,unsigned char addressL)
{    
	if(C2Time < CAN_BASE_TIME)	return(0);
    if(C2TX0CONbits.TXREQ)		return(0);

	EV_ReqRdWrTxBuf[ID_CODE]		=HOST_SDO_0;
	EV_ReqRdWrTxBuf[RD_WR_CMD]		=RD_SDO_INV_ATB;
	EV_ReqRdWrTxBuf[RD_WR_LENGTH]	=0x04;
	EV_ReqRdWrTxBuf[BASE_ADDR_H]	=addressH;
	EV_ReqRdWrTxBuf[BASE_ADDR_L]	=addressL;
	EV_ReqRdWrTxBuf[REQ_DATA_SEQ]	=1;
	IV_AckRdWrTxBuf[REQ_DATA_SEQ]	=1;

	return(1);

}

LocalType __attribute__((section(".usercode"))) Delta_ReadParameter_CAN(unsigned char addressH,unsigned char addressL,unsigned char ReadWordNm)
{    
	if(C2Time < CAN_BASE_TIME)	return(0);
    if(C2TX0CONbits.TXREQ)		return(0);

	EV_ReqRdWrTxBuf[ID_CODE]		=HOST_SDO_0;
	EV_ReqRdWrTxBuf[RD_WR_CMD]		=RD_SDO_INV_REG;
	EV_ReqRdWrTxBuf[RD_WR_LENGTH]	=ReadWordNm;
	EV_ReqRdWrTxBuf[BASE_ADDR_H]	=addressH;
	EV_ReqRdWrTxBuf[BASE_ADDR_L]	=addressL;
	EV_ReqRdWrTxBuf[REQ_DATA_SEQ]	=1;
	IV_AckRdWrTxBuf[REQ_DATA_SEQ]	=1;

	return(1);
}




LocalType __attribute__((section(".usercode"))) Delta_WriteParameter_CAN(unsigned char addressH,unsigned char addressL,unsigned char WriteWordNm,unsigned char valH,unsigned char valL)
{    
	if(C2Time < CAN_BASE_TIME)	return(0);
    if(C2TX0CONbits.TXREQ)		return(0);

	EV_ReqRdWrTxBuf[ID_CODE]		=HOST_SDO_0;
	EV_ReqRdWrTxBuf[RD_WR_CMD]		=WR_SDO_INV_REG;
	EV_ReqRdWrTxBuf[RD_WR_LENGTH]	=WriteWordNm;
	EV_ReqRdWrTxBuf[BASE_ADDR_H]	=addressH;
	EV_ReqRdWrTxBuf[BASE_ADDR_L]	=addressL;
	EV_ReqRdWrTxBuf[DATA_0_H]		=valH;
	EV_ReqRdWrTxBuf[DATA_0_L]		=valL;
	EV_ReqRdWrTxBuf[REQ_DATA_SEQ]	=1;
	IV_AckRdWrTxBuf[REQ_DATA_SEQ]	=1;

	return(1);
}










/*
void     __attribute__((section(".usercode"))) C2RxSidEidDataLoad_ZZ(void)
{
	unsigned long	tmp0,tmp1;

	C2ThisRxSid= ((C2RX0SID >> 2) & 0x007f);
	C2ThisRxDataCnt=(C2RX0DLC & 0x000f);

	tmp0=0;
	tmp1=0;
	tmp0=(unsigned long)(C2RX0DLC >> 10);
	tmp1=(unsigned long)(C2RX0EID);
	tmp1=(unsigned long)(tmp1 << 2);
	tmp1=(unsigned long)(tmp1 & 0xfffffffc);

	C2ThisRxEid=(tmp0 | tmp1);


	C2ThisRxBuf[0] =(UserDataType)(C2RX0B1 & 0x00ff);
	C2ThisRxBuf[1] =(UserDataType)((C2RX0B1 >> 8) & 0x00ff);     
	
	C2ThisRxBuf[2] =(UserDataType)(C2RX0B2 & 0x00ff);
	C2ThisRxBuf[3] =(UserDataType)((C2RX0B2 >> 8) & 0x00ff);     
	
	C2ThisRxBuf[4] =(UserDataType)(C2RX0B3 & 0x00ff);
	C2ThisRxBuf[5] =(UserDataType)((C2RX0B3 >> 8) & 0x00ff);     
	
	C2ThisRxBuf[6] =(UserDataType)(C2RX0B4 & 0x00ff);
	C2ThisRxBuf[7] =(UserDataType)((C2RX0B4 >> 8) & 0x00ff);     
}
*/


LocalType __attribute__((section(".usercode"))) Receive_All(void)
{
	unsigned int i;

	if(IV_AckRdWrTxBuf[1]==0x60){
		for(i=0;i<8;i++)	ThisAttribute[i]= IV_AckRdWrTxBuf[i+5];
	} 

	IV_AckRdWrTxBuf[REQ_DATA_SEQ]=0;		// receive all good
	EV_ReqRdWrTxBuf[REQ_DATA_SEQ]=0;
	EV_ReqRdWrTxBuf[REQ_TIMEOUT]=0;
	DeltaNoAck=0;

	C2Time = CAN_BASE_TIME;

	return(0);
}


LocalType __attribute__((section(".usercode"))) Ack_SDO(void)
{
	unsigned int i;
	
	switch(C2ThisRxSid){
		case	0x50:	
			IV_AckRdWrTxBuf[0]=C2ThisRxSid;
			for(i=0;i<8;i++)	IV_AckRdWrTxBuf[i+1] = C2ThisRxBuf[i];
			if(IV_AckRdWrTxBuf[2] <= 2){
				Receive_All();
			}
			break;			
		case	0x51:
			for(i=0;i<8;i++)	IV_AckRdWrTxBuf[i+9] = C2ThisRxBuf[i];
			if(IV_AckRdWrTxBuf[2] <= 6){
				Receive_All();
			}
			break;
		case	0x52:
			for(i=0;i<8;i++)	IV_AckRdWrTxBuf[i+17] = C2ThisRxBuf[i];
			if(IV_AckRdWrTxBuf[2] <= 10){
				Receive_All();
			}
			break;
	}
	
	return(0);
}


/*
LocalType __attribute__((section(".usercode"))) C2InvAckDataSort(void)
{
	unsigned int ret;
	unsigned int i;

	ret=0xff;

	switch(C2ThisRxSid){
		case	0x02:
			for(i=0;i<8;i++)	InvStatus[i] = C2ThisRxBuf[i];
			InverterPDORxTime=0;
			ret=0; 	
			break;
		case	0x50:
			if( !((C2ThisRxBuf[0] == 0x03) || (C2ThisRxBuf[0] == 0x06)	|| (C2ThisRxBuf[0] == 0x60) || (C2ThisRxBuf[0] == 0x61) || (C2ThisRxBuf[0] == 0x62)) ){
				ret=1;
				return(ret);	
			}	 
			else if(C2ThisRxBuf[0] == WR_SDO_INV_REG){
				Receive_All();
				ret=0; 	
			}	 	
			else{
				Ack_SDO();			
			}	
			break;	
		case	0x51:
		case	0x52:
			Ack_SDO();
			break;
		default:
			ret=1; 	
			break;
	}

	return(ret);	
}




//void _ISR_X _C2Interrupt_ZZ(void)
void __attribute__((section(".usercode")))  C2Interrupt_ZZ(void)
{
    if(C2INTFbits.RX0IF){        
		C2RxSidEidDataLoad_ZZ();
		C2InvAckDataSort();				

        C2INTFbits.RX0IF=0;
        C2RX0CONbits.RXFUL=0;
    }    
    else{
        C2CTRLbits.ABAT=1;      // aboart all pending transmit
        C2INTFbits.RX1IF=0;
        C2RX1CONbits.RXFUL=0;
        C2INTFbits.WAKIF=0;
        C2INTF=0;
        C2INTFbits.ERRIF=0;        
    }

    C2IF=0;
    C2INTFbits.RX0IF=0;
    C2RX0CONbits.RXFUL=0;
}
*/



void Delta_LoadThisTxCan2Buf(unsigned int Tsid,unsigned int Tdatacnt,unsigned int *Tdata)
{
	unsigned int i;

	C2ThisTxSid=Tsid;
	C2ThisTxDataCnt=Tdatacnt;

    for(i = 0;i < C2ThisTxDataCnt;i++)	          C2ThisTxBuf[i]= *(Tdata + i);

}






LocalType __attribute__((section(".usercode"))) C2TxAct(void)
{    	
	youCAN2TxSidSet(0,C2ThisTxSid);
	youCAN2TxEidSet(0,0,0);

    if(C2TX0CONbits.TXREQ)		return(1);    				// fault
	CAN2SendMessageyou(0,&C2ThisTxBuf[0], C2ThisTxDataCnt); // tx success       
	C2Time=0;

	return(0);
}



LocalType __attribute__((section(".usercode"))) RdWrBufInit(void)
{    
	unsigned	int	i;
	for(i=0;i<8;i++)	C2ThisTxBuf[i]=0;
	return(0);
}

/*
LocalType __attribute__((section(".usercode"))) RxTxReqToInveterInit(void)
{
	EV_ReqRdWrTxBuf[REQ_DATA_SEQ]=0;
	IV_AckRdWrTxBuf[REQ_DATA_SEQ]=0;
}
*/

LocalType __attribute__((section(".usercode"))) Read_SDO(void)
{

	RdWrBufInit();

	C2ThisTxSid 	=EV_ReqRdWrTxBuf[ID_CODE];
	C2ThisTxBuf[0] 	=EV_ReqRdWrTxBuf[RD_WR_CMD];
	C2ThisTxBuf[1]	=EV_ReqRdWrTxBuf[RD_WR_LENGTH];
	C2ThisTxBuf[2]	=EV_ReqRdWrTxBuf[BASE_ADDR_H];
	C2ThisTxBuf[3]	=EV_ReqRdWrTxBuf[BASE_ADDR_L];

	C2ThisTxDataCnt	=0x04;

	if( !C2TxAct()){
		EV_ReqRdWrTxBuf[REQ_TIMEOUT]++;
		DeltaNoAck=0;
		EV_ReqRdWrTxBuf[REQ_DATA_SEQ]=0;
	}
	
	return(0);
}




LocalType __attribute__((section(".usercode"))) Write_SDO(void)
{

	RdWrBufInit();

	switch(EV_ReqRdWrTxBuf[ID_CODE]){
		case	HOST_SDO_0:
			C2ThisTxSid 	=EV_ReqRdWrTxBuf[ID_CODE];
			C2ThisTxBuf[0] 	=EV_ReqRdWrTxBuf[RD_WR_CMD];
			C2ThisTxBuf[1]	=EV_ReqRdWrTxBuf[RD_WR_LENGTH];
			C2ThisTxBuf[2]	=EV_ReqRdWrTxBuf[BASE_ADDR_H];
			C2ThisTxBuf[3]	=EV_ReqRdWrTxBuf[BASE_ADDR_L];				

			C2ThisTxBuf[4] 	=EV_ReqRdWrTxBuf[DATA_0_H];
			C2ThisTxBuf[5]	=EV_ReqRdWrTxBuf[DATA_0_L];
			C2ThisTxBuf[6]	=EV_ReqRdWrTxBuf[DATA_1_H];
			C2ThisTxBuf[7]	=EV_ReqRdWrTxBuf[DATA_1_L];				

			if(EV_ReqRdWrTxBuf[RD_WR_LENGTH] > 2){
				C2ThisTxDataCnt	=8;
				EV_ReqRdWrTxBuf[ID_CODE]++;
			}
			else{
				C2ThisTxDataCnt	=(EV_ReqRdWrTxBuf[RD_WR_LENGTH] * 2) + 4;
				EV_ReqRdWrTxBuf[ID_CODE]=0;
			}
			break;
		case	HOST_SDO_1:
			C2ThisTxSid 	=EV_ReqRdWrTxBuf[ID_CODE];
			C2ThisTxBuf[0] 	=EV_ReqRdWrTxBuf[DATA_2_H];
			C2ThisTxBuf[1]	=EV_ReqRdWrTxBuf[DATA_2_L];
			C2ThisTxBuf[2]	=EV_ReqRdWrTxBuf[DATA_3_H];
			C2ThisTxBuf[3]	=EV_ReqRdWrTxBuf[DATA_3_L];				
			C2ThisTxBuf[4] 	=EV_ReqRdWrTxBuf[DATA_4_H];
			C2ThisTxBuf[5]	=EV_ReqRdWrTxBuf[DATA_4_L];
			C2ThisTxBuf[6]	=EV_ReqRdWrTxBuf[DATA_5_H];
			C2ThisTxBuf[7]	=EV_ReqRdWrTxBuf[DATA_5_L];				

			if(EV_ReqRdWrTxBuf[RD_WR_LENGTH] > 6){
				C2ThisTxDataCnt	=8;
				EV_ReqRdWrTxBuf[ID_CODE]++;
			}
			else{
				EV_ReqRdWrTxBuf[ID_CODE]=0;

				if(EV_ReqRdWrTxBuf[RD_WR_LENGTH]==3){
					C2ThisTxDataCnt	=2;
				}
				else if(EV_ReqRdWrTxBuf[RD_WR_LENGTH]==4){
					C2ThisTxDataCnt	=4;
				}
				else if(EV_ReqRdWrTxBuf[RD_WR_LENGTH]==5){
					C2ThisTxDataCnt	=6;
				}
				else{
					C2ThisTxDataCnt	=8;
				}
			}
			break;
		case	HOST_SDO_2:
			C2ThisTxSid 	=EV_ReqRdWrTxBuf[ID_CODE];
			C2ThisTxBuf[0] 	=EV_ReqRdWrTxBuf[DATA_6_H];
			C2ThisTxBuf[1]	=EV_ReqRdWrTxBuf[DATA_6_L];
			C2ThisTxBuf[2]	=EV_ReqRdWrTxBuf[DATA_7_H];
			C2ThisTxBuf[3]	=EV_ReqRdWrTxBuf[DATA_7_L];				
			C2ThisTxBuf[4] 	=EV_ReqRdWrTxBuf[DATA_8_H];
			C2ThisTxBuf[5]	=EV_ReqRdWrTxBuf[DATA_8_L];
			C2ThisTxBuf[6]	=EV_ReqRdWrTxBuf[DATA_9_H];
			C2ThisTxBuf[7]	=EV_ReqRdWrTxBuf[DATA_9_L];				

			EV_ReqRdWrTxBuf[ID_CODE]=0;

			if(EV_ReqRdWrTxBuf[RD_WR_LENGTH]==7){
				C2ThisTxDataCnt	=2;
			}
			else if(EV_ReqRdWrTxBuf[RD_WR_LENGTH]==8){
				C2ThisTxDataCnt	=4;
			}
			else if(EV_ReqRdWrTxBuf[RD_WR_LENGTH]==9){
				C2ThisTxDataCnt	=6;
			}
			else{
				C2ThisTxDataCnt	=8;
			}
			break;
	}



	if( !C2TxAct()){
		if(EV_ReqRdWrTxBuf[ID_CODE]==0){
			EV_ReqRdWrTxBuf[REQ_TIMEOUT]++;
			EV_ReqRdWrTxBuf[REQ_DATA_SEQ]=0;
			DeltaNoAck=0;
		}
	}

	return(0);
}






LocalType __attribute__((section(".usercode"))) SDOReqMode(void)
{
	unsigned int	ret;

	ret=1;

	if(EV_ReqRdWrTxBuf[REQ_DATA_SEQ] > 0){
		switch(EV_ReqRdWrTxBuf[RD_WR_CMD]){
			case	RD_SDO_INV_REG:
			case	RD_SDO_INV_ATB:
			case	RD_SDO_INV_DSR:
				Read_SDO();
				ret=0;
				break;
			case	WR_SDO_INV_REG:
				Write_SDO();
				ret=0;
				break;
			default:
				RxTxReqToInveterInit();
				break;
		}
	}

	return(ret);
}






/*
LocalType __attribute__((section(".usercode"))) WaitAckTimeOutChk(void)
{    
	if((EV_ReqRdWrTxBuf[REQ_DATA_SEQ]==0) && (DeltaNoAck > 30))	return(1);
	else														return(0);
}
*/






LocalType __attribute__((section(".usercode"))) C2InvAckDataSort(void)
{
	unsigned int ret;
	unsigned int i;

	ret=0xff;


	switch(C2ThisRxSid){
		case	0x02:
			for(i=0;i<8;i++)	InvStatus[i] = C2ThisRxBuf[i];

			InvErrNm=InvStatus[2];
			InverterPDORxTime=0;
			ret=0; 	
			break;
		case	0x50:
			if( !((C2ThisRxBuf[0] == 0x03) || (C2ThisRxBuf[0] == 0x06)	|| (C2ThisRxBuf[0] == 0x60) || (C2ThisRxBuf[0] == 0x61) || (C2ThisRxBuf[0] == 0x62)) ){
				ret=1;
				return(ret);	
			}	 
			else if(C2ThisRxBuf[0] == WR_SDO_INV_REG){
				Receive_All();
				ret=0; 	
			}	 	
			else{
				Ack_SDO();			
			}	
			break;	
		case	0x51:
		case	0x52:
			Ack_SDO();
			break;
		default:
			ret=1; 	
			break;
	}

	C2ThisRxSid=0;

	return(ret);	
}



void     __attribute__((section(".usercode"))) C2RxSidEidDataLoad(void)
{
	unsigned long	tmp0,tmp1;

	C2ThisRxSid= ((C2RX0SID >> 2) & 0x007f);
	C2ThisRxDataCnt=(C2RX0DLC & 0x000f);

	tmp0=0;
	tmp1=0;
	tmp0=(unsigned long)(C2RX0DLC >> 10);
	tmp1=(unsigned long)(C2RX0EID);
	tmp1=(unsigned long)(tmp1 << 2);
	tmp1=(unsigned long)(tmp1 & 0xfffffffc);

	C2ThisRxEid=(tmp0 | tmp1);


	C2ThisRxBuf[0] =(UserDataType)(C2RX0B1 & 0x00ff);
	C2ThisRxBuf[1] =(UserDataType)((C2RX0B1 >> 8) & 0x00ff);     
	
	C2ThisRxBuf[2] =(UserDataType)(C2RX0B2 & 0x00ff);
	C2ThisRxBuf[3] =(UserDataType)((C2RX0B2 >> 8) & 0x00ff);     
	
	C2ThisRxBuf[4] =(UserDataType)(C2RX0B3 & 0x00ff);
	C2ThisRxBuf[5] =(UserDataType)((C2RX0B3 >> 8) & 0x00ff);     
	
	C2ThisRxBuf[6] =(UserDataType)(C2RX0B4 & 0x00ff);
	C2ThisRxBuf[7] =(UserDataType)((C2RX0B4 >> 8) & 0x00ff);     
}




void _ISR_X _C2Interrupt(void)
{
    if(C2INTFbits.RX0IF){        
		C2RxSidEidDataLoad();
		C2InvAckDataSort();				

        C2INTFbits.RX0IF=0;
        C2RX0CONbits.RXFUL=0;
    }    
    else{
        C2CTRLbits.ABAT=1;      // aboart all pending transmit
        C2INTFbits.RX1IF=0;
        C2RX1CONbits.RXFUL=0;
        C2INTFbits.WAKIF=0;
        C2INTF=0;
        C2INTFbits.ERRIF=0;        
    }

    C2IF=0;
    C2INTFbits.RX0IF=0;
    C2RX0CONbits.RXFUL=0;
}




LocalType __attribute__((section(".usercode"))) Can2Check(void)
{    
	unsigned int i;

	i=1;

	if((WhoAutolanding == (unsigned int)EDS_AUTOLANDING_CAN) ){
		if(C2Time < CAN_BASE_TIME)	return(0);
	    if(C2TX0CONbits.TXREQ)		return(0);
		SDOReqMode();
	}

	#ifdef	DELTA_INVERTER_AUTOLANDING_CAN
		else if((WhoAutolanding == (unsigned int)DELTA_INVERTER_AUTOLANDING_CAN) ){
			if(C2Time < CAN_BASE_TIME)	return(0);
		    if(C2TX0CONbits.TXREQ)		return(0);
		
			if(InverterReady == 0x01){
				if(SDOReqMode()){
					PDO_DataLoad();
				}
			}
			else{
				InverterReadyCheck();
			}	
		}
	#endif

    return(0);
}

///////////////////////////////////

#endif












