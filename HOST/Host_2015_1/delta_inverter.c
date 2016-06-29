

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


// delta:  stop sequence--		o	
//         auto tunning-----	o 
//         relevel
//         cancle
//         target floor check 
//         sus,sds length 
//         parameter edit 


#ifdef	DELTA_INVERTER	

extern	LocalType __attribute__((section(".usercode"))) DeltaDataSortForPDO(void);

extern UserDataType    EnterKey;


#define		INV_COM_ERR_TIME	100   // 100msec		
#define		CAN_BASE_TIME		10		

#define		HOST_SDO_0		0x60		
#define		HOST_SDO_1		0x61		
#define		HOST_SDO_2		0x62
		
#define		HOST_PDO		0x01		

#define		INVERTER_SDO	0x50		
#define		INVERTER_PDO	0x02		




#define		RD_SDO_INV_REG	0x03	
#define		RD_SDO_INV_ATB	0x60	
#define		RD_SDO_INV_DSR	0x61	

#define		WR_SDO_INV_REG	0x06



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




#define		ID_CODE			0
#define		RD_WR_CMD		1
#define		RD_WR_LENGTH	2
#define		BASE_ADDR_H		3
#define		BASE_ADDR_L		4
#define		DATA_0_H		5
#define		DATA_0_L		6
#define		DATA_1_H		7
#define		DATA_1_L		8
#define		DATA_2_H		9
#define		DATA_2_L		10
#define		DATA_3_H		11
#define		DATA_3_L		12
#define		DATA_4_H		13
#define		DATA_4_L		14
#define		DATA_5_H		15
#define		DATA_5_L		16
#define		DATA_6_H		17
#define		DATA_6_L		18
#define		DATA_7_H		19
#define		DATA_7_L		20
#define		DATA_8_H		21
#define		DATA_8_L		22
#define		DATA_9_H		23
#define		DATA_9_L		24
#define		REQ_TIMEOUT		25
#define		REQ_DATA_SEQ	26


unsigned int	DeltaNoAck=0;
unsigned int	InverterPDORxTime=0;
unsigned int	InverterReady=0;
unsigned int	DeltaRdWrStatus=0;
unsigned int	DeltaRdWrStatusFhm=0;

unsigned char	EV_ReqRdWrTxBuf[27];
unsigned char	IV_AckRdWrTxBuf[27];
unsigned char	ElevStatus[8];
unsigned char	InvStatus[8];
unsigned char	ThisAttribute[8];
unsigned char	PDO_TX_DataBuf[8];

unsigned char	Delta_bUnd;
unsigned char	OrgTargetFlr;


unsigned int	IV_This_Attrv,IV_This_Min,IV_This_Max,IV_This_Value;



/*
LocalType __attribute__((section(".usercode"))) DeltaInverterRelevelHzSet(void)
{
	if(bOneLuOrLd)	return(1);

	if( (sRamDArry[mcurfloor] == 0) && !IN_SD1 && (bCarDnMove)){
        tmppulse1=FLOOR_COUNT(sRamDArry[mcurfloor+1]);
        tmppulse2=FLOOR_COUNT(sRamDArry[mcurfloor]);

	return(0);
}
*/



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



LocalType __attribute__((section(".usercode"))) C2InvAckDataSort(void)
{
	unsigned int ret;
	unsigned int i;

	ret=0xff;

//	if( !((C2ThisRxSid == 0x02) || (C2ThisRxSid == 0x50)	|| (C2ThisRxSid == 0x51) || (C2ThisRxSid == 0x52)) ){
//		return(ret);	
//	}	 

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




void _ISR_X _C2Interrupt(void)
{
    if(C2INTFbits.RX0IF){        
		C2RxSidEidDataLoad();
		C2InvAckDataSort();				

/*
		Delta_LoadThisTxCan2Buf(C2ThisRxSid,C2ThisTxDataCnt,&C2ThisRxBuf[0]);
		youCAN2TxSidSet(0,C2ThisTxSid);
		youCAN2TxEidSet(0,0,0);
		CAN2SendMessageyou(0,&C2ThisTxBuf[0], C2ThisTxDataCnt);        
*/

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



void Delta_LoadThisTxCan2Buf(unsigned int Tsid,unsigned int Tdatacnt,unsigned int *Tdata)
{
	unsigned int i;

	C2ThisTxSid=Tsid;
	C2ThisTxDataCnt=Tdatacnt;

    for(i = 0;i < C2ThisTxDataCnt;i++)	          C2ThisTxBuf[i]= *(Tdata + i);


/*
  *((unsigned char *)&C2TX0B1+i)= data[i];

    {
        switch(MsgFlag)
        {
        case 0: 
            *((unsigned char *)&C2TX0B1+i)= data[i];
            break;
        case 1: *((unsigned char *)&C2TX1B1+i)= data[i];
            break;
        case 2: *((unsigned char *)&C2TX2B1+i)= data[i];
            break;
        default:*((unsigned char *)&C2TX0B1+i)= data[i];
            break;
        }
    }

	C2ThisTxBuf[0]=C2ThisRxBuf[0];
	C2ThisTxBuf[1]=C2ThisRxBuf[1];
	C2ThisTxBuf[2]=C2ThisRxBuf[2];
	C2ThisTxBuf[3]=C2ThisRxBuf[3];
	C2ThisTxBuf[4]=C2ThisRxBuf[4];
	C2ThisTxBuf[5]=C2ThisRxBuf[5];
	C2ThisTxBuf[6]=C2ThisRxBuf[6];
	C2ThisTxBuf[7]=C2ThisRxBuf[7];
*/

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


LocalType __attribute__((section(".usercode"))) RxTxReqToInveterInit(void)
{
	EV_ReqRdWrTxBuf[REQ_DATA_SEQ]=0;
	IV_AckRdWrTxBuf[REQ_DATA_SEQ]=0;
}


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

//	Read_SDO();

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


LocalType __attribute__((section(".usercode"))) PDOReqMode(void)
{
	PDO_DataLoad();
	return(0);
}





LocalType __attribute__((section(".usercode"))) Can2Check(void)
{    
	unsigned int i;

	i=1;

	if(C2Time < CAN_BASE_TIME)	return(0);
    if(C2TX0CONbits.TXREQ)		return(0);


	if(InverterReady == 0x01){
		if(SDOReqMode()){
			PDOReqMode();
		}
	}
	else{
		InverterReadyCheck();
	}

    return(0);
}




LocalType __attribute__((section(".usercode"))) ReadAttribute(unsigned char addressH,unsigned char addressL)
{    
	EV_ReqRdWrTxBuf[ID_CODE]		=HOST_SDO_0;
	EV_ReqRdWrTxBuf[RD_WR_CMD]		=RD_SDO_INV_ATB;
	EV_ReqRdWrTxBuf[RD_WR_LENGTH]	=0x04;
	EV_ReqRdWrTxBuf[BASE_ADDR_H]	=addressH;
	EV_ReqRdWrTxBuf[BASE_ADDR_L]	=addressL;
	EV_ReqRdWrTxBuf[REQ_DATA_SEQ]	=1;
	IV_AckRdWrTxBuf[REQ_DATA_SEQ]	=1;
}

LocalType __attribute__((section(".usercode"))) ReadParameter(unsigned char addressH,unsigned char addressL,unsigned char ReadWordNm)
{    
	EV_ReqRdWrTxBuf[ID_CODE]		=HOST_SDO_0;
	EV_ReqRdWrTxBuf[RD_WR_CMD]		=RD_SDO_INV_REG;
	EV_ReqRdWrTxBuf[RD_WR_LENGTH]	=ReadWordNm;
	EV_ReqRdWrTxBuf[BASE_ADDR_H]	=addressH;
	EV_ReqRdWrTxBuf[BASE_ADDR_L]	=addressL;
	EV_ReqRdWrTxBuf[REQ_DATA_SEQ]	=1;
	IV_AckRdWrTxBuf[REQ_DATA_SEQ]	=1;
}




LocalType __attribute__((section(".usercode"))) AddrWriteParameter(unsigned char addressH,unsigned char addressL,unsigned char WriteWordNm,unsigned char valH,unsigned char valL)
{    
	EV_ReqRdWrTxBuf[ID_CODE]		=HOST_SDO_0;
	EV_ReqRdWrTxBuf[RD_WR_CMD]		=WR_SDO_INV_REG;
	EV_ReqRdWrTxBuf[RD_WR_LENGTH]	=WriteWordNm;
	EV_ReqRdWrTxBuf[BASE_ADDR_H]	=addressH;
	EV_ReqRdWrTxBuf[BASE_ADDR_L]	=addressL;
	EV_ReqRdWrTxBuf[DATA_0_H]		=valH;
	EV_ReqRdWrTxBuf[DATA_0_L]		=valL;
	EV_ReqRdWrTxBuf[REQ_DATA_SEQ]	=1;
	IV_AckRdWrTxBuf[REQ_DATA_SEQ]	=1;
}



/*
LocalType __attribute__((section(".usercode"))) EqualAddrWriteParameter(unsigned char WriteWordNm,unsigned char valH,unsigned char valL)
{    
	EV_ReqRdWrTxBuf[ID_CODE]		=HOST_SDO_0;
	EV_ReqRdWrTxBuf[RD_WR_CMD]		=WR_SDO_INV_REG;
	EV_ReqRdWrTxBuf[RD_WR_LENGTH]	=WriteWordNm;
//	EV_ReqRdWrTxBuf[BASE_ADDR_H]	=addressH;
//	EV_ReqRdWrTxBuf[BASE_ADDR_L]	=addressL;

	EV_ReqRdWrTxBuf[DATA_0_H]		=valH;
	EV_ReqRdWrTxBuf[DATA_0_L]		=valL;

	EV_ReqRdWrTxBuf[REQ_DATA_SEQ]	=1;
	IV_AckRdWrTxBuf[REQ_DATA_SEQ]	=1;
}
*/

LocalType __attribute__((section(".usercode"))) WaitAckTimeOutChk(void)
{    
	if((EV_ReqRdWrTxBuf[REQ_DATA_SEQ]==0) && (DeltaNoAck > 30))	return(1);
	else														return(0);
}




LocalType __attribute__((section(".usercode"))) DeltaRdWr(unsigned char addressH,unsigned char addressL,unsigned char WriteWordNm,unsigned char valH,unsigned char valL)
{    
	unsigned int val,dp;
	unsigned int ret;
	unsigned int b_data0,b_data1;

	ret=0;

	if(DeltaRdWrStatus>0){
		switch(DeltaRdWrStatus){
			case	1:
				ReadAttribute(addressH,addressL);
				DeltaRdWrStatus=2;
				break;
			case	2:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					DeltaRdWrStatus=3;
				}		
				else{
					if(WaitAckTimeOutChk())	DeltaRdWrStatus=1;	
				}
				break;
			case	3:
				ReadParameter(addressH,addressL,1);
				DeltaRdWrStatus=4;
				break;
			case	4:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){

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

					Delta_Par_DataSort(IV_This_Value);					
					DeltaRdWrStatus=0;
				}		
				else{
					if(WaitAckTimeOutChk())	DeltaRdWrStatus=3;	
				}
				break;
			case	5:
				AddrWriteParameter(addressH,addressL,WriteWordNm,valH,valL);
				DeltaRdWrStatus=6;
				break;
			case	6:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					if(bsInvCurNext)	DeltaRdWrStatus=0;
					if(bDeltaGroupEdit){
						DeltaRdWrStatus=1;
						EnterKey=0;
					}
				}		
				else{
					if(WaitAckTimeOutChk()){
						AddrWriteParameter(addressH,addressL,WriteWordNm,valH,valL);
					}
				}
				break;
			default:
				DeltaRdWrStatus=0;
				RxTxReqToInveterInit();
				break;
		}
	}	

	return(ret);
}	




LocalType __attribute__((section(".usercode"))) DeltaRdWrFhm(unsigned char addressH,unsigned char addressL)
{    
	unsigned int val,dp;
	unsigned int ret;

	ret=0;


	if(DeltaRdWrStatusFhm>0){
		switch(DeltaRdWrStatusFhm){
			case	1:
				ReadParameter(addressH,addressL,1);
				DeltaRdWrStatusFhm=2;
				break;
			case	2:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					AddrWriteParameter(addressH,addressL,1,0,FHM_CMD_EXCUT);
//					EqualAddrWriteParameter(1,0,FHM_CMD_EXCUT);
					DeltaRdWrStatusFhm=3;
				}
				else{
					if(WaitAckTimeOutChk())	DeltaRdWrStatusFhm=1;	
				}		
				break;
			case	3:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					ReadParameter(addressH,addressL,1);
					DeltaRdWrStatusFhm=4;
				}		
				else{
					if(WaitAckTimeOutChk())	DeltaRdWrStatusFhm=1;	
				}		
				break;
			case	4:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					if(IV_AckRdWrTxBuf[6] == FHM_CMD_EXCUT){
						AddrWriteParameter(addressH,addressL,1,0,FHM_CMD_P_RESET_H);
//						EqualAddrWriteParameter(1,0,FHM_CMD_P_RESET_H);
						DeltaRdWrStatusFhm=5;
					}
					else{
						DeltaRdWrStatusFhm=1;
					}					
				}		
				else{
					if(WaitAckTimeOutChk())	DeltaRdWrStatusFhm=1;	
				}		
				break;
			case	5:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					ReadParameter(addressH,addressL,1);
					DeltaRdWrStatusFhm=6;
				}		
				else{
					if(WaitAckTimeOutChk())	DeltaRdWrStatusFhm=1;	
				}		
				break;
			case	6:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					if(IV_AckRdWrTxBuf[6] == FHM_CMD_P_RESET_H){
						AddrWriteParameter(addressH,addressL,1,0,FHM_CMD_P_RESET_L);
//						EqualAddrWriteParameter(1,0,FHM_CMD_P_RESET_L);
						DeltaRdWrStatusFhm=7;
					}
					else{
						DeltaRdWrStatusFhm=1;
					}					
				}		
				else{
					if(WaitAckTimeOutChk())	DeltaRdWrStatusFhm=1;	
				}		
				break;
			case	7:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					ReadParameter(addressH,addressL,1);
					DeltaRdWrStatusFhm=8;
				}
				else{
					if(WaitAckTimeOutChk())	DeltaRdWrStatusFhm=1;	
				}		
				break;
			case	8:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					if(IV_AckRdWrTxBuf[6] == FHM_CMD_P_RESET_L){
						ret=1;
						DeltaRdWrStatusFhm=9;
					}
					else{
						DeltaRdWrStatusFhm=1;
					}
				}		
				else{
					if(WaitAckTimeOutChk())	DeltaRdWrStatusFhm=1;	
				}		
				break;
			case	9:
				ret=1;
				break;
			case	10:
				ReadParameter(addressH,addressL,1);
				DeltaRdWrStatusFhm=11;
				break;
			case	11:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					AddrWriteParameter(addressH,addressL,1,0,FHM_CMD_P_RECORD_H);
//					EqualAddrWriteParameter(1,0,FHM_CMD_P_RECORD_H);
					DeltaRdWrStatusFhm=12;
				}		
				else{
					if(WaitAckTimeOutChk())	DeltaRdWrStatusFhm=10;	
				}		
				break;
			case	12:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					ReadParameter(addressH,addressL,1);
					DeltaRdWrStatusFhm=13;
				}		
				else{
					if(WaitAckTimeOutChk())	DeltaRdWrStatusFhm=10;	
				}		
				break;
			case	13:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					if(IV_AckRdWrTxBuf[6] == FHM_CMD_P_RECORD_H){
						if(DeltaNoAck > 10){
							AddrWriteParameter(addressH,addressL,1,0,FHM_CMD_P_RECORD_L);
//							EqualAddrWriteParameter(1,0,FHM_CMD_P_RECORD_L);
							DeltaRdWrStatusFhm=14;
						}
					}
					else{
						DeltaRdWrStatusFhm=10;
					}					
				}		
				else{
					if(WaitAckTimeOutChk())	DeltaRdWrStatusFhm=10;	
				}		
				break;
			case	14:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					ReadParameter(addressH,addressL,1);
					DeltaRdWrStatusFhm=15;
				}		
				else{
					if(WaitAckTimeOutChk())	DeltaRdWrStatusFhm=10;	
				}		
				break;

			case	15:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					if(IV_AckRdWrTxBuf[6] == FHM_CMD_P_RECORD_L){
						AddrWriteParameter(addressH,addressL,1,0, (IV_AckRdWrTxBuf[6] & (~IV_FHM_EXCUTE)));
//						EqualAddrWriteParameter(1,0, (IV_AckRdWrTxBuf[6] & (~IV_FHM_EXCUTE)));   // dsb excute
						DeltaRdWrStatusFhm=16;
					}
					else{
						DeltaRdWrStatusFhm=10;
					}					
				}		
				else{
					if(WaitAckTimeOutChk())	DeltaRdWrStatusFhm=10;	
				}		
				break;
			case	16:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					ReadParameter(addressH,addressL,1);
					DeltaRdWrStatusFhm=17;
				}		
				else{
					if(WaitAckTimeOutChk())	DeltaRdWrStatusFhm=10;	
				}		
				break;
/*
			case	17:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					if(IV_AckRdWrTxBuf[6] == 0x00){
						EqualAddrWriteParameter(1,0,0x0);
						DeltaRdWrStatusFhm=16;
					}
					else{
						DeltaRdWrStatusFhm=10;
					}					
				}		
				else{
					if(WaitAckTimeOutChk()	DeltaRdWrStatusFhm=10;	
				}		
				break;
			case	18:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					ReadParameter(addressH,addressL,1);
					DeltaRdWrStatusFhm=17;
				}		
				else{
					if(WaitAckTimeOutChk()	DeltaRdWrStatusFhm=10;	
				}		
				break;

*/

			case	17:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					if( !(IV_AckRdWrTxBuf[6] & IV_FHM_EXCUTE)){
						AddrWriteParameter(addressH,addressL,1,0,FHM_CMD_SUCCESS);
//						EqualAddrWriteParameter(1,0,FHM_CMD_SUCCESS);
						DeltaRdWrStatusFhm=18;
					}
					else{
						DeltaRdWrStatusFhm=10;
					}					
				}		
				else{
					if(WaitAckTimeOutChk())	DeltaRdWrStatusFhm=10;	
				}		
				break;
			case	18:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					ReadParameter(addressH,addressL,1);
					DeltaRdWrStatusFhm=19;
				}		
				else{
					if(WaitAckTimeOutChk())	DeltaRdWrStatusFhm=10;	
				}		
				break;
			case	19:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					if(IV_AckRdWrTxBuf[6] == FHM_CMD_SUCCESS){
						ret=1;
						DeltaRdWrStatusFhm=20;
					}
					else{
						DeltaRdWrStatusFhm=10;
					}					
				}		
				else{
					if(WaitAckTimeOutChk())	DeltaRdWrStatusFhm=10;	
				}		
				break;
			case	20:
				ret=1;
				break;
			default:
				RxTxReqToInveterInit();
				break;
		}
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
///	if(!bUnd)	bUnd=DeltaDecCheck();

	if( (InvStatus[5] != sRamDArry[S0_FLOOR]) && (DeltaRdWrStatus==0)){
		AddrWriteParameter(4,23,1,0,sRamDArry[S0_FLOOR]);  // current floor reset
		bsInvCurNext=1;
		DeltaRdWrStatus=6;
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


LocalType __attribute__((section(".usercode"))) DeltaTopFirstFloorChk(void)
{
	unsigned int i,j;
	if(bOneLuOrLd){
		if(sRamDArry[mcurfloor]==0){
			if(!IN_SD1)	return(1);
			else		return(0);		
		}	 
		else if(sRamDArry[mcurfloor]== cF_TOPFLR){
			if(!IN_SU1)	return(1);			
			else		return(0);		
		}	 
		else			return(1);
	}	
	return(0);
}


LocalType __attribute__((section(".usercode"))) DeltaStopChk(void)
{
	unsigned int ret=0;
	unsigned char InvFloor,HostFloor;

	ret=0;

	InvFloor=InvStatus[5];
	HostFloor=(sRamDArry[mcurfloor]+1);
	sRamDArry[mInvFloor] = (InvFloor-1);  		      


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
	else{
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


/*

	if( !bMoveCar){
		if(InverterPDORxTime > INV_COM_ERR_TIME){
			bInvComErr=1;
			bsInvCurNext=0;
		}
		else{
			bInvComErr=0;
			HostFloor=(sRamDArry[mcurfloor]+1);
			if( (InvFloor != HostFloor) && (WarmingUpTime > 20) && !IN_AUTO ){
				DeltaInvertFloorResetting();
			}
			else{
				bsInvCurNext=0;
			}
		}	
	}
	else{
		bInvComErr=0;
		bsInvCurNext=0;
	}
*/


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


LocalType __attribute__((section(".usercode"))) DeltaCancleValidChk(void)
{
	unsigned long ev_mpm,cur_mpm,min_mpm;

	min_mpm=10;

	ev_mpm=(unsigned long)GET_LONG(MPM);
	ev_mpm=(ev_mpm * 80)/100;          		// 80%  of max mpm
	cur_mpm=(unsigned long)CurMeterPerMin;
	cur_mpm=(cur_mpm/10);					//


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
				if(DeltaTopFirstFloorChk()){
					PDO_TX_DataBuf[0]	=0x40;			
				}
				else{
					PDO_TX_DataBuf[0]	=0x10;
				}			
				PDO_TX_DataBuf[5]	=((sRamDArry[mcurfloor] & ONLY_FLR) + 1);
			}
			else{
				PDO_TX_DataBuf[0]	=0x10;
				PDO_TX_DataBuf[5]	=0;
			}
		}
		else	PDO_TX_DataBuf[0]	=0x10;							                                    

		if( !bDeltaSpdOff && !bFhmRun){
			PDO_TX_DataBuf[0]	=0x0;							                                    
		}
	}


	if((InvStatus[0] & IV_ERROR_0)){
		bCarErr=1;                                                     		
	}
		
	PDO_TX_DataBuf[2]	=0x0;


	return(0);
}






LocalType __attribute__((section(".usercode"))) DeltaAutoTunningRun(unsigned char addressH,unsigned char addressL)
{    

		switch(sRamDArry[AUTO_TUNING]){
			case	AUTOTUN_SEQ_1:
				bAutoTunningMsg=0;
				AddrWriteParameter(addressH,addressL,1,0,(unsigned char)(AUTO_TUN_STOPPING));
				sRamDArry[AUTO_TUNING]=AUTOTUN_SEQ_2;
				break;
			case	AUTOTUN_SEQ_2:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					ReadParameter(addressH,addressL,1);
					sRamDArry[AUTO_TUNING]=AUTOTUN_SEQ_3;
				}		
				else{
					if(WaitAckTimeOutChk())	sRamDArry[AUTO_TUNING]=AUTOTUN_SEQ_1;	
				}		
				break;		
			case	AUTOTUN_SEQ_3:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					if(IV_AckRdWrTxBuf[DATA_0_L] == (unsigned char)(AUTO_TUN_STOPPING)){
						sRamDArry[AUTO_TUNING]=AUTOTUN_SEQ_4;
					}
					else{
						sRamDArry[AUTO_TUNING]=AUTOTUN_SEQ_1;
					}
				}		
				else{
					if(WaitAckTimeOutChk())	sRamDArry[AUTO_TUNING]=AUTOTUN_SEQ_1;	
				}
				break;		

			case	AUTOTUN_SEQ_4:				
				if(AutotunUpDn==1){		// up
                	OUT_P4(1);    
			    	OUT_U_W(1);
				    OUT_D_W(0);
			    	OUT_BK1(0);
				}
				else if(AutotunUpDn==2){
                	OUT_P4(1);    
			    	OUT_U_W(0);
				    OUT_D_W(1);
			    	OUT_BK1(0);
				}
				else{
                	OUT_P4(1);    
			    	OUT_U_W(0);
				    OUT_D_W(0);
			    	OUT_BK1(0);
				}
				if((InvStatus[0] & IV_WARNNING_0)){
					sRamDArry[AUTO_TUNING]=AUTOTUN_SEQ_5;
				}
				break;
			case	AUTOTUN_SEQ_5:
				if( !(InvStatus[0] & IV_WARNNING_0)){
                	OUT_P4(0);    
				    OUT_U_W(0);
				    OUT_D_W(0);
				    OUT_BK1(0);
					sRamDArry[AUTO_TUNING]=AUTOTUN_SEQ_6;
				}
				break;
			case	AUTOTUN_SEQ_6:
					sRamDArry[AUTO_TUNING]=AUTOTUN_SEQ_7;
				break;
//////////////////////////////////////////////////////////////////

			case	AUTOTUN_SEQ_7:
				AddrWriteParameter(addressH,addressL,1,0,(unsigned char)(AUTO_TUN_RUNNING));
				sRamDArry[AUTO_TUNING]=AUTOTUN_SEQ_8;
				break;
			case	AUTOTUN_SEQ_8:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					ReadParameter(addressH,addressL,1);
					sRamDArry[AUTO_TUNING]=AUTOTUN_SEQ_9;
				}		
				else{
					if(WaitAckTimeOutChk())	sRamDArry[AUTO_TUNING]=AUTOTUN_SEQ_7;	
				}		
				break;		
			case	AUTOTUN_SEQ_9:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					if(IV_AckRdWrTxBuf[DATA_0_L] == (unsigned char)(AUTO_TUN_RUNNING)){
						sRamDArry[AUTO_TUNING]=AUTOTUN_SEQ_10;
						TunningTimer=0;
					}
					else{
						sRamDArry[AUTO_TUNING]=AUTOTUN_SEQ_7;
					}
				}		
				else{
					if(WaitAckTimeOutChk())	sRamDArry[AUTO_TUNING]=AUTOTUN_SEQ_7;	
				}
				break;		
			case	AUTOTUN_SEQ_10:				
				if(AutotunUpDn==1){		// up
                	OUT_P4(1);    
			    	OUT_U_W(1);
				    OUT_D_W(0);
				}
				else if(AutotunUpDn==2){
                	OUT_P4(1);    
			    	OUT_U_W(0);
				    OUT_D_W(1);
				}
				else{
                	OUT_P4(1);    
			    	OUT_U_W(0);
				    OUT_D_W(0);
				}

				if((InvStatus[0] & IV_WARNNING_0)){
					sRamDArry[AUTO_TUNING]=AUTOTUN_SEQ_11;
				}
				break;
			case	AUTOTUN_SEQ_11:
				if( !(InvStatus[0] & IV_WARNNING_0)){
					sRamDArry[AUTO_TUNING]=AUTOTUN_SEQ_12;
					bAutoTunningMsg=1;
				}
				else if(TunningTimer > 100){		// 10 sec
					sRamDArry[AUTO_TUNING]=AUTOTUN_SEQ_12;	// error
				}
				break;
			case	AUTOTUN_SEQ_12:
                OUT_P4(0);    
			    OUT_U_W(0);
			    OUT_D_W(0);
			    OUT_BK1(0);
				AddrWriteParameter(addressH,addressL,1,0,(unsigned char)(AUTO_TUN_END));
				sRamDArry[AUTO_TUNING]=AUTOTUN_SEQ_13;
				break;
			case	AUTOTUN_SEQ_13:
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					ReadParameter(addressH,addressL,1);
					sRamDArry[AUTO_TUNING]=AUTOTUN_SEQ_14;
				}		
				else{
					if(WaitAckTimeOutChk())	sRamDArry[AUTO_TUNING]=AUTOTUN_SEQ_12;	
				}		
				break;		
			case	AUTOTUN_SEQ_14:
                OUT_P4(0);    
			    OUT_U_W(0);
			    OUT_D_W(0);
			    OUT_BK1(0);
				if(IV_AckRdWrTxBuf[REQ_DATA_SEQ]==0){
					if(IV_AckRdWrTxBuf[DATA_0_L] == (unsigned char)(AUTO_TUN_END)){
						sRamDArry[AUTO_TUNING]=AUTOTUN_SEQ_15;
					}
					else{
						sRamDArry[AUTO_TUNING]=AUTOTUN_SEQ_12;
					}
				}		
				else{
					if(WaitAckTimeOutChk())	sRamDArry[AUTO_TUNING]=AUTOTUN_SEQ_12;	
				}
				break;		
			case	AUTOTUN_SEQ_15:
                OUT_P4(0);    
			    OUT_U_W(0);
			    OUT_D_W(0);
			    OUT_BK1(0);
				break;
			default:
                OUT_P4(0);    
			    OUT_U_W(0);
			    OUT_D_W(0);
			    OUT_BK1(0);
				sRamDArry[AUTO_TUNING]=AUTOTUN_SEQ_0;
				break;
		}

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
//			if( DeltaCancleValidChk()){	
				DeltaNewFloorLoadCheck();
//			}				
   		}
   	}
   	else if(bCarDnMove){
   		if(sRamDArry[DEST_FLR] != sRamDArry[mLowFloor]){
//			if( DeltaCancleValidChk()){	
				DeltaNewFloorLoadCheck();
//			}	
   		}
   	}                        

	if(!(sRamDArry[mAckStopFloor] & UPDN_CAR_READY)){
		if(sRamDArry[mReqStopFloor] & CAR_READY){	
			sRamDArry[mAckStopFloor] = sRamDArry[mReqStopFloor];		
		}
	}
}




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

	if(bUnd){				
		if((LuLdTime==0)){				
        	UpDnCallClear();  
		}
	}

/*
	if(InverterPDORxTime > INV_COM_ERR_TIME){
		if( (sRamDArry[mcurfloor] & ONLY_FLR) == (sRamDArry[mAckStopFloor] & ONLY_FLR)){
			if(bOnLuLd && (LuLdTime > iF_RunOffTime)){
				sRamDArry[mDoorSeq] = STOP_ELEVATOR;
			}
		}
	}
*/


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



