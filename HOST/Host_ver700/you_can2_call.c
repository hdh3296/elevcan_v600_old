

#include <p30fxxxx.h>
#include "you_can_lib.h" 
#include "you_can2.h" 

           
#include  "30f6010_io.h"            
#include  "host_io.h"            
#include  "iodef.h"
#include  "door.h"
//#include  "eeprom.h"
#include  "com.h"
#include  "counter.h"
#include	"Host_NewProtocol.h" 


unsigned long	C2ThisRxEid;
unsigned int	C2ThisRxSid;
unsigned int	C2ThisRxDataCnt;
unsigned int   	C2ThisRxBuf[8];

unsigned long	C2ThisTxEid;
unsigned int	C2ThisTxSid;
unsigned int	C2ThisTxDataCnt;
unsigned int   	C2ThisTxBuf[8];




UserDataType   C2DataSeqStart=0;

UserDataType   C2Time=0;
UserDataType   C2DataSeq=0;
unsigned int   C2ReceiveSlaveAdr=0;
unsigned int   C2ReceiveAdrStatus=0;

unsigned int   C2TmpSid=0;
unsigned int   C2TmdEidL=0;
unsigned int   C2TmdEidH=0;

unsigned int   C2Loop=0;


#define  H2_INTV_TIME1  100   //msec
#define  H2_INTV_TIME2  100   //msec
#define  H2_INTV_TIME3  100   //msec
#define  H2_INTV_TIME4  100   //msec
#define  H2_INTV_TIME5  100   //msec



unsigned int   CAN2_RxBuf[13];
unsigned int   CAN2_TxBuf[13];







void   __attribute__((section(".usercode"))) CAN2SendMessageyou(char MsgFlag,unsigned int * data, unsigned int  datalen) 
{
    int i;

    for(i = 0;i < datalen;i++)
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

    
    
    switch(MsgFlag)
    {
    case 0:
        C2TX0DLCbits.DLC = datalen;
        C2TX0CON=7;         
        C2TX0CONbits.TXREQ = 1;
        break;
    case 1:
        C2TX1DLCbits.DLC = datalen;
        C2TX1CON=7; 
        C2TX1CONbits.TXREQ = 1;
        break;
    case 2:
        C2TX2DLCbits.DLC = datalen;
        C2TX2CON=7; 
        C2TX2CONbits.TXREQ = 1;
        break;
    default:
        C2TX0DLCbits.DLC = datalen;
        C2TX0CON=7; 
        C2TX0CONbits.TXREQ = 1;
        break;
    }
}



void  __attribute__((section(".usercode"))) SetSidEid(void)
{

    C2TmpSid=(unsigned int)cF_COMPANY;
    C2TmpSid=(C2TmpSid | (MyGroupAddr << 7));

    C2TmpSid=(C2TmpSid & 0x07ff);

    C2TmdEidH=0;
	C2TmdEidL=0;

#ifndef	MAX_EIGHT_CAR
	if(MyGroupAddr & 0x10)	C2TmdEidH=(C2TmdEidH | 0x0001);	
	if(MyGroupAddr & 0x20)	C2TmdEidH=(C2TmdEidH | 0x0002);


    if(MyLocalAddr & 0x01)   C2TmdEidL=(C2TmdEidL | 0x4000);
    if(MyLocalAddr & 0x02)   C2TmdEidL=(C2TmdEidL | 0x8000);
#else
	if(MyGroupAddr & 0x10)	C2TmdEidH=(C2TmdEidH | 0x0002);
	
    if(MyLocalAddr & 0x01)   C2TmdEidL=(C2TmdEidL | 0x4000);
    if(MyLocalAddr & 0x02)   C2TmdEidL=(C2TmdEidL | 0x8000);
    if(MyLocalAddr & 0x04)   C2TmdEidH=(C2TmdEidH | 0x0001);

	if(MyGroupAddr >= 0x20){
		if(MyGroupAddr & 0x10)	C2TmdEidH=(C2TmdEidH | 0x0002);
	    if(MyLocalAddr & 0x01)	C2TmdEidL=(C2TmdEidL | 0x4000);
	    if(MyLocalAddr & 0x02)	C2TmdEidL=(C2TmdEidL | 0x8000);
		C2TmdEidH=(C2TmdEidH | 0x0001);
	}
#endif

	C2TmdEidL = (C2TmdEidL | I_AM_MASTER); //master set
	
}



void    __attribute__((section(".usercode"))) Can2Init(void)
{
    unsigned int sid;
    unsigned int eidh,eidl;


    C2CTRLbits.REQOP    = 0x4;      // Entry Configration Mode
//    C2CTRLbits.CANCAP   = 0x1;      // enable CAN Capture mode
    C2CTRLbits.CANCAP   = 0x0;      // disable CAN Capture mode
    C2CTRLbits.CSIDL    = 0x1;      // when idle mode,stop can
    C2CTRLbits.ABAT     = 0x1;      // aboart all pending transmit
    C2CTRLbits.CANCKS   = 0x1;      // fcan=fcy

    C2CFG2bits.SAM      = 0x1 ;     // Bus Line is sampled three times prior to the sample point
    C2CFG2bits.WAKFIL   = 0x0 ; 	// CAN bus line filter is not used for wake-up
    C2CFG2bits.SEG2PHTS = 0x1 ;     // Freely programmable;

    C2CFG1bits.BRP      = 19;      // tq=0.0000025  // 50kbps

  
    C2CFG1bits.SJW      = 0x0;      // Synchronized Jump Width bits 1xTq
    C2CFG2bits.SEG1PH   = 0x1 ;     // 2 Tq
    C2CFG2bits.SEG2PH   = 0x1 ; 	// 2 Tq
    C2CFG2bits.PRSEG    = 0x2 ;     // 3 Tq



#ifdef	AUTO_LANDING_CAN					
//    C2CFG1bits.BRP      = 1;      	// 500kbps
    C2CFG1bits.BRP      = 3;      		// 250kbps
//    C2CFG1bits.BRP      = 7;      	// 125kbps

#endif

    C2TX0CON            = 0x3;
    C2TX1CON            = 0x3;

    C2TX0SIDbits.TXIDE  = 0x1;
    C2TX0SIDbits.SRR    = 0x0;
    C2TX0DLCbits.TXRB0  = 0x0;
    C2TX0DLCbits.TXRB1  = 0x0;
    C2TX0DLCbits.TXRTR  = 0x0;

    C2TX1SIDbits.TXIDE  = 0x1;
    C2TX1SIDbits.SRR    = 0x0;
    C2TX1DLCbits.TXRB0  = 0x0;
    C2TX1DLCbits.TXRB1  = 0x0;
    C2TX1DLCbits.TXRTR  = 0x0;

    C2TX2SIDbits.TXIDE  = 0x1;
    C2TX2SIDbits.SRR    = 0x1;
    C2TX2DLCbits.TXRB0  = 0x0;
    C2TX2DLCbits.TXRB1  = 0x0;
    C2TX2DLCbits.TXRTR  = 0x0;


    C2RXM0SID           = 0x0;
    C2RXM0EIDH          = 0x0;
    C2RXM0EIDL          = 0x0;
    C2RXM0SIDbits.MIDE  = 0x0;

    C2RXM1SID           = 0x0;
    C2RXM1EIDH          = 0x0;
    C2RXM1EIDL          = 0x0;
    C2RXM1SIDbits.MIDE  = 0x0;

    C2RXF0SID           = 0x0;
    C2RXF0EIDH          = 0x0;
    C2RXF0EIDL          = 0x0;
    C2RXF0SIDbits.EXIDE = 0x0;

    C2RXF1SID           = 0x0;
    C2RXF1EIDH          = 0x0;
    C2RXF1EIDL          = 0x0;
    C2RXF1SIDbits.EXIDE = 0x0;

    C2RXF2SID           = 0x0;
    C2RXF2EIDH          = 0x0;
    C2RXF2EIDL          = 0x0;
    C2RXF2SIDbits.EXIDE = 0x0;

    C2RXF3SID           = 0x0;
    C2RXF3EIDH          = 0x0;
    C2RXF3EIDL          = 0x0;
    C2RXF3SIDbits.EXIDE = 0x0;

    C2RXF4SID           = 0x0;
    C2RXF4EIDH          = 0x0;
    C2RXF4EIDL          = 0x0;
    C2RXF4SIDbits.EXIDE = 0x0;

    C2RXF5SID           = 0x0;
    C2RXF5EIDH          = 0x0;
    C2RXF5EIDL          = 0x0;
    C2RXF5SIDbits.EXIDE = 0x0;

    C2RX0CONbits.RXFUL  = 0x0;
//    C1RX0CONbits.DBEN   = 0x1;
    C2RX0CONbits.DBEN   = 0x0;
    C2RX0CONbits.JTOFF  = 0x0;
    C2RX0CONbits.FILHIT0= 0x0;

    C2RX1CONbits.RXFUL  = 0x0;


    C2INTE              = 0x0;
    C2INTEbits.ERRIE    = 0x1;
    C2INTEbits.RX0IE    = 0x1;
    C2INTEbits.RX1IE    = 0x1;

    C2IE       = 0x1;



	SetSidEid();

/*
    sid=(unsigned int)cF_COMPANY;
    sid=(sid | (MyGroupAddr << 7));

    eidh=0;
    eidl=0;


    if(MyLocalAddr & 0x02)   eidl=(eidl | 0x8000);
    if(MyLocalAddr & 0x01)   eidl=(eidl | 0x4000);

    if(MyGroupAddr & 0x20)   eidh=(eidh | 0x0002);
    if(MyGroupAddr & 0x10)   eidh=(eidh | 0x0001);
*/


    youCAN2SetFilter(0,C2TmpSid,C2TmdEidH,C2TmdEidL);
    youCAN2SetFilter(1,0x0,0x0,0x0);
    youCAN2SetFilter(2,0x0,0x0,0x0);
    youCAN2SetFilter(3,0x0,0x0,0x0);
    youCAN2SetFilter(4,0x0,0x0,0x0);
    youCAN2SetFilter(5,0x0,0x0,0x0);
 
    youCAN2SetMask(5,0xffff,0xffff,0xffff);
    youCAN2SetMask(4,0xffff,0xffff,0xffff);
    youCAN2SetMask(3,0xffff,0xffff,0xffff);
    youCAN2SetMask(1,0xffff,0xffff,0xffff);
    youCAN2SetMask(0,0x07ff,0x0003,0xc000);


#ifdef	AUTO_LANDING_CAN					
    youCAN2SetMask(5,0x0,0x0,0x0);
    youCAN2SetMask(4,0x0,0x0,0x0);
    youCAN2SetMask(3,0x0,0x0,0x0);
    youCAN2SetMask(1,0x0,0x0,0x0);
    youCAN2SetMask(0,0x0,0x0,0x0);
#endif





    IPC9bits.C2IP=4;


/*
    C2Time=0;
    while(C2Time<10);

    C2CTRLbits.REQOP    = 0x0;

    C2Time=0;
    while(C2Time<10);
*/
    
    C2CTRLbits.REQOP    = 0x0;

                
    C2DataSeq=0;                
    C2Time=0;
    C2EC=0;
}






#ifndef		AUTO_LANDING_CAN			


void  __attribute__((section(".usercode"))) NormalDataReturn(void)
{
    LocalType sel,xx;

    sel=0;

    if(!C2TX0CONbits.TXREQ && (C2DataSeqStart==1)){

#ifdef	FLOOR_64
        if(C2Time > H2_INTV_TIME5){

            youCAN2TxSidSet(sel,C2TmpSid);
			
			if(C2DataSeq >= 10){
		      	youCAN2TxEidSet(sel,C2TmdEidH,C2TmdEidL+(0x80+ C2DataSeq));
	            LoadCanBuffer(C2DataSeq);
			}
			else{
		      	youCAN2TxEidSet(sel,C2TmdEidH,C2TmdEidL+C2DataSeq);
	            LoadCanBuffer(C2DataSeq);
			}


		
			if(C2DataSeq == 4){
				CAN_Buf[7] = CAN2_RxBuf[2];
			}

            CAN2SendMessageyou(sel,&CAN_Buf[0], 8);        
            C2DataSeq++;       			

			if(C2DataSeq > 10){
	            C2Time=0;
	            C2DataSeq=0;       
	            C2DataSeqStart=0;
			}
		}
#else
        if(C2Time > H2_INTV_TIME5){
			xx=0;
			if(C2DataSeq == 4){
				C2DataSeq=8;
				xx=4;
			}
            youCAN2TxSidSet(sel,C2TmpSid);
            youCAN2TxEidSet(sel,C2TmdEidH,C2TmdEidL+C2DataSeq);
            LoadCanBuffer(C2DataSeq-xx);

////////////////////////////////////////////////////////////////
			if( (C2DataSeq-xx) == 1){
	            CAN_Buf[0] = sRamDArry[FLR_ON_OFF0];
	            CAN_Buf[1] = sRamDArry[FLR_ON_OFF1];
	            CAN_Buf[2] = sRamDArry[FLR_ON_OFF2];
	            CAN_Buf[3] = sRamDArry[FLR_ON_OFF3];
			}     
////////////////////////////////////////////////////////////


			if(C2DataSeq >= 8){
				CAN_Buf[7] = CAN2_RxBuf[2];
			}

            CAN2SendMessageyou(sel,&CAN_Buf[0], 8);        
            C2DataSeq++;       			

			if(C2DataSeq > 8){
	            C2Time=0;
	            C2DataSeq=0;       
	            C2DataSeqStart=0;
			}
		}
#endif

	}
 
}







/*
void  __attribute__((section(".usercode"))) DataReturn(unsigned int par,unsigned int nmb)
{
    LocalType sel;
    LocalType cmdgood;

    cmdgood=0;
    sel=0;


    if(par==0x01){  //prk
        CAN_Buf[0]=0x0;
//        if(IN_PRK || bPC_PRK)   CAN_Buf[0]=0x01;
        if(IN_PRK || bPC_PRK || bSlavePrk)   CAN_Buf[0]=0x01;
        CAN_Buf[1]=0x00;
        cmdgood=1;
    }
    else if(par==0x02){ //odd/even
        CAN_Buf[0]=cF_NONSERVICE0;
        CAN_Buf[1]=cF_NONSERVICE1;
        CAN_Buf[2]=cF_NONSERVICE2;
        CAN_Buf[3]=cF_NONSERVICE3;
        cmdgood=1;
    }
    else if(par==0x03){  //rush hour
        CAN_Buf[0]=0x0;
        CAN_Buf[0]=cF_FIXFLOORTIME;
        CAN_Buf[1]=0x00;
        cmdgood=1;
    }
    else if(par==0x04){  //fire
        CAN_Buf[0]=0x0;
        if(!IN_FIRE || bPC_FIRE)   CAN_Buf[0]=0x01;
        CAN_Buf[1]=0x00;
        cmdgood=1;
    }



    if(!C2TX0CONbits.TXREQ && (C2DataSeqStart==1) && (cmdgood)){
        youCAN2TxSidSet(sel,C2TmpSid);
        youCAN2TxEidSet(sel,C2TmdEidH,C2TmdEidL+0);         
        CAN2SendMessageyou(sel,&CAN_Buf[0], nmb);            
        C2Time=0;
        C2DataSeq=0;       
        C2DataSeqStart=0;               
    }
}
*/




LocalType __attribute__((section(".usercode"))) HostReadMyData(void)
{
    if((CAN2_RxBuf[2] == 0x00) && (CAN2_RxBuf[3] == 0x00)){
        NormalDataReturn();
    }
}





LocalType __attribute__((section(".usercode"))) HostCommandAct(void)
{
    unsigned int   good; 
	good=0;

    if((CAN2_RxBuf[2]    ==   (PC_COMMAND | CMD_PARKING)) && (CAN2_RxBuf[3] == 0x00)){
        if(CAN2_RxBuf[4] == 0x01) 	bExt_PRKING = 1;
        else                    	bExt_PRKING = 0;
		good=1;
    }    
    else if((CAN2_RxBuf[2]    ==   (PC_COMMAND | CMD_FIRE)) && (CAN2_RxBuf[3] == 0x00)){
        if(CAN2_RxBuf[4] == 0x01) 	bExt_FIRE = 1;
        else                    	bExt_FIRE = 0;
		good=1;
    }
    else if((CAN2_RxBuf[2]    ==   (PC_COMMAND | CMD_FAMILY_SEV)) && (CAN2_RxBuf[3] == 0x00)){
        if(CAN2_RxBuf[4] == 0x01) 	bExt_FAMILY = 1;
        else                    	bExt_FAMILY = 0;
		good=1;
    }
    else if((CAN2_RxBuf[2]    ==   (PC_COMMAND | CMD_VIP)) && (CAN2_RxBuf[3] == 0x00)){
        if(CAN2_RxBuf[4] == 0x01) 	bExt_VIP = 1;
        else                    	bExt_VIP = 0;
		good=1;
    }
    else if((CAN2_RxBuf[2]    ==   (PC_COMMAND | CMD_SECOND_FIRE)) && (CAN2_RxBuf[3] == 0x00)){
        if(CAN2_RxBuf[4] == 0x01) 	bExt_Second_FIRE = 1;
        else                    	bExt_Second_FIRE = 0;
		good=1;
    }


    else if((CAN2_RxBuf[2]    ==   (PC_COMMAND | CMD_CALL_SEV)) && (CAN2_RxBuf[3] == 0x00)){
#ifdef	FLOOR_64
		CrtMoveFlr=(unsigned char)(CAN2_RxBuf[4]);
		if(CrtMoveFlr == 0)	CrtMoveFlr=(CrtMoveFlr | UP_READY);
#else
		CrtMoveFlr=(unsigned char)(CAN2_RxBuf[4] | CAR_READY);
#endif
		good=1;
    }

    else if((CAN2_RxBuf[2]    ==   (PC_COMMAND | CMD_EXT_CALL_SEV)) && (CAN2_RxBuf[3] == 0x00)){
		sRamDArry[mCrtExtMoveFlr]=(unsigned char)(CAN2_RxBuf[4]);
		ExtKeyCnt=3;
		CAN2_RxBuf[0]=0;
		good=1;
    }
    else if((CAN2_RxBuf[2]    ==   (PC_COMMAND | CMD_FAN_LIGHT_ETC)) && (CAN2_RxBuf[3] == 0x00)){
		if( (CAN2_RxBuf[4] > 0) &&  (CAN2_RxBuf[4] < 0xff)){
			ExtFanTimer=(unsigned char)(CAN2_RxBuf[4]-1);
			ExtFanTimer=(ExtFanTimer % 100);
			good=1;
		}
		if( (CAN2_RxBuf[5] > 0) &&  (CAN2_RxBuf[5] < 0xff)){
			ExtLightTimer=(unsigned char)(CAN2_RxBuf[5]-1);
			ExtLightTimer=(ExtLightTimer % 100);
			good=1;
		}
    }

	if(good)	NormalDataReturn();	
}



LocalType __attribute__((section(".usercode"))) HostWriteMyData(void)
{

    if((CAN2_RxBuf[2] == (CMD_EVEN_ODD)) && (CAN2_RxBuf[3] == 0x00)){
        Pc_Command();
		NormalDataReturn();    
    }    
    else if((CAN2_RxBuf[2] == (CMD_MORNING)) && (CAN2_RxBuf[3] == 0x00)){
        Pc_Command();
		NormalDataReturn();    
    }    
}






#ifndef	AUTO_LANDING_COMM

//////////////////////////////////////////////////////////////////////////////////

LocalType __attribute__((section(".usercode"))) Can2NewProtocolTxData(void)
{    
	unsigned int i,datalen,seqnm,lastdata;
	unsigned int tmpeidl,tmpeidh;
    
	lastdata=0;
	datalen=0;
	seqnm=0;


	tmpeidl=(unsigned int)(CommonRxEid & 0x00ff);
	tmpeidl=(unsigned int)(tmpeidl & 0xc0ff);
	tmpeidh=(unsigned int)((CommonRxEid >> 16)& 0x0003);


	if(!C2TX0CONbits.TXREQ){
		for(i=0;i<8;i++){
			datalen++;
	    	CAN_Buf[i]= CommonRcvBuf[CommonTxThisPt];
			CommonTxThisPt++;
			if( CommonTxThisPt >= CommonTxCnt){
				lastdata=DATA_BLOCK_END;
				CommonRxGood=0;
				break;
			}
		}
	

		seqnm=((CommonTxThisPt -1)/8);

		seqnm=(seqnm << 8);
		tmpeidl=(tmpeidl | seqnm | lastdata | I_AM_MASTER);

        youCAN2TxSidSet(0,CommonRxSid);
        youCAN2TxEidSet(0,tmpeidh,tmpeidl);
        CAN2SendMessageyou(0,&CAN_Buf[0], datalen); 
		
	}
    return(0);
}


unsigned int  __attribute__((section(".usercode")))  NewProtocolCan2Chk(void)
{
	if(CommonRxGood==0)	return(0);
	if(CommonConnectPort != COM_PORT_CAN2)	return(0);
	Can2NewProtocolTxData();
	return(1);
}


void    __attribute__((section(".usercode")))  Can2NewProtocolDataLoad(void)
{
	unsigned long tmpeid1,tmpeid2=0;

    CommonThisRxBuf[0] =(UserDataType)(C2RX0B1 & 0x00ff);
    CommonThisRxBuf[1] =(UserDataType)((C2RX0B1 >> 8) & 0x00ff);     

    CommonThisRxBuf[2] =(UserDataType)(C2RX0B2 & 0x00ff);
    CommonThisRxBuf[3] =(UserDataType)((C2RX0B2 >> 8) & 0x00ff);     

    CommonThisRxBuf[4] =(UserDataType)(C2RX0B3 & 0x00ff);
    CommonThisRxBuf[5] =(UserDataType)((C2RX0B3 >> 8) & 0x00ff);     

    CommonThisRxBuf[6] =(UserDataType)(C2RX0B4 & 0x00ff);
    CommonThisRxBuf[7] =(UserDataType)((C2RX0B4 >> 8) & 0x00ff);     


	CommonRxSid=(C2RX0SID >> 2);
	CommonRxDlc=(C2RX0DLC & 0x000f);

	tmpeid1=(unsigned long)((C2RX0DLC >> 10) & 0x003f);
	tmpeid2=(unsigned long)((C2RX0EID << 6) & 0xffc0);
	CommonRxEid=(tmpeid1 | tmpeid2);
}


void    __attribute__((section(".usercode")))  Can2ConnectorValid(void)
{
	if(CommonNewSoketChk(COM_PORT_CAN2)){
		Can2NewProtocolDataLoad();
		CommonReceiveDataSave(COM_PORT_CAN2);
	}
}
#endif



#endif



#ifndef	AUTO_LANDING_CAN	


void    __attribute__((section(".usercode")))  PcCommandMeCan2(void)
{
	unsigned char tmpbuf[8];

    tmpbuf[0] =(UserDataType)(C2RX0B1 & 0x00ff);
    tmpbuf[1] =(UserDataType)((C2RX0B1 >> 8) & 0x00ff);     

    tmpbuf[2] =(UserDataType)(C2RX0B2 & 0x00ff);
    tmpbuf[3] =(UserDataType)((C2RX0B2 >> 8) & 0x00ff);     

    tmpbuf[4] =(UserDataType)(C2RX0B3 & 0x00ff);
    tmpbuf[5] =(UserDataType)((C2RX0B3 >> 8) & 0x00ff);     

    tmpbuf[6] =(UserDataType)(C2RX0B4 & 0x00ff);
    tmpbuf[7] =(UserDataType)((C2RX0B4 >> 8) & 0x00ff);     

    if( (tmpbuf[0]== 0x24) || (tmpbuf[0]== 0x23)){
		CAN2_RxBuf[0] = tmpbuf[0];
		CAN2_RxBuf[1] = tmpbuf[1];
		CAN2_RxBuf[2] = tmpbuf[2];
		CAN2_RxBuf[3] = tmpbuf[3];
		CAN2_RxBuf[4] = tmpbuf[4];
		CAN2_RxBuf[5] = tmpbuf[5];
		CAN2_RxBuf[6] = tmpbuf[6];
		CAN2_RxBuf[7] = tmpbuf[7];
	}
	else{
		#ifndef	AUTO_LANDING_COMM
		Can2ConnectorValid();
		#endif
	}


/*
	if(CommonRxCnt==0){
	    tmpbuf[0] =(UserDataType)(C2RX0B1 & 0x00ff);
	    tmpbuf[1] =(UserDataType)((C2RX0B1 >> 8) & 0x00ff);     
	
	    tmpbuf[2] =(UserDataType)(C2RX0B2 & 0x00ff);
	    tmpbuf[3] =(UserDataType)((C2RX0B2 >> 8) & 0x00ff);     
	
	    tmpbuf[4] =(UserDataType)(C2RX0B3 & 0x00ff);
	    tmpbuf[5] =(UserDataType)((C2RX0B3 >> 8) & 0x00ff);     
	
	    tmpbuf[6] =(UserDataType)(C2RX0B4 & 0x00ff);
	    tmpbuf[7] =(UserDataType)((C2RX0B4 >> 8) & 0x00ff);     
	
	    if( (tmpbuf[0]== 0x24) || (tmpbuf[0]== 0x23)){
			CAN2_RxBuf[0] = tmpbuf[0];
			CAN2_RxBuf[1] = tmpbuf[1];
			CAN2_RxBuf[2] = tmpbuf[2];
			CAN2_RxBuf[3] = tmpbuf[3];
			CAN2_RxBuf[4] = tmpbuf[4];
			CAN2_RxBuf[5] = tmpbuf[5];
			CAN2_RxBuf[6] = tmpbuf[6];
			CAN2_RxBuf[7] = tmpbuf[7];
		}
		else{
			#ifndef	AUTO_LANDING_COMM
			Can2ConnectorValid();
			#endif
		}
	}
	else{
		#ifndef	AUTO_LANDING_COMM
		Can2ConnectorValid();
		#endif
	}
*/

}
//////////////////////////////////////////////////////////////




void      __attribute__((section(".usercode"))) Can2ReceiveSIDEIDArrary(void)
{

    unsigned int  tmpid1,tmpid2;

//    C2ReceiveGroupNumber=(C2RX0SID >> 9) & 0x000f;
//    C2ReceiveMaterAdr=(C2RX0EID >> 8) & 0x0003; //local address

	
    if(C2RX0EID & 0x80){
        C2ReceiveAdrStatus=MASTER_TX_SLAVE;
    }
    else{
        C2ReceiveAdrStatus=SLAVE_TX_MASTER;
        tmpid1=(C2RX0DLC >> 10) & 0x0007;
        tmpid2=(C2RX0EID << 6)  & 0x00c0;
        C2ReceiveSlaveAdr=(tmpid1 | tmpid2);
    }
}






void      __attribute__((section(".usercode"))) C2RxSidEidDataLoad(void)
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



LocalType __attribute__((section(".usercode"))) Can2Check(void)
{    
	unsigned int i;

    if(C2DataSeqStart==0){
        if(C2Loop > 300){
           	Can2Init();
            C2Loop=0;
        }
        return(0);
    }
    
#ifndef	AUTO_LANDING_COMM
	if(NewProtocolCan2Chk())	return(0);
#endif

    switch(CAN2_RxBuf[0]){
        case    0x23:
        case    0x33:
            HostReadMyData();
            break;
        case    0x24:
            if(CAN2_RxBuf[2] & PC_COMMAND){
                HostCommandAct();             
            }
            else{
                HostWriteMyData();             
            }
            break;
    }
        

    return(0);
}


void _ISR_X _C2Interrupt(void)
{
    if(C2INTFbits.RX0IF){        
		C2RxSidEidDataLoad();
        Can2ReceiveSIDEIDArrary();


        CAN2_RxBuf[0] =(UserDataType)(C2RX0B1 & 0x00ff);
        CAN2_RxBuf[1] =(UserDataType)((C2RX0B1 >> 8) & 0x00ff);     

        CAN2_RxBuf[2] =(UserDataType)(C2RX0B2 & 0x00ff);
        CAN2_RxBuf[3] =(UserDataType)((C2RX0B2 >> 8) & 0x00ff);     

        CAN2_RxBuf[4] =(UserDataType)(C2RX0B3 & 0x00ff);
        CAN2_RxBuf[5] =(UserDataType)((C2RX0B3 >> 8) & 0x00ff);     

        CAN2_RxBuf[6] =(UserDataType)(C2RX0B4 & 0x00ff);
        CAN2_RxBuf[7] =(UserDataType)((C2RX0B4 >> 8) & 0x00ff);     

		
		PcCommandMeCan2();

        C2Time=0;
        C2DataSeq=0;       


        C2DataSeqStart=1;
        C2Time=H2_INTV_TIME1 - 5;
      
        C2INTFbits.RX0IF=0;
        C2RX0CONbits.RXFUL=0;
        C2Loop=0;
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

#endif



