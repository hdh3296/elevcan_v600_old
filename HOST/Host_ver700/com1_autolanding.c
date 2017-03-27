



#include <p30fxxxx.h>
#include  "30f6010_io.h"            
#include  "host_io.h"            
#include  "iodef.h"
#include  "com.h"
#include  "iomap.h"
#include  "default_setup.h" 

#include	"Host_Autolanding.h" 


//#ifdef	AUTO_LANDING_485


/*
unsigned char   Com1RxBuffer[MAX_RTX_BUF]={0,0};
unsigned char   Com1TxBuffer[MAX_RTX_BUF]={0,0};
unsigned char   Com1RxStatus=0;
unsigned char   Com1TxOn=0;
unsigned char   Com1SerialTime=0x0;
unsigned char   Com1AckTime=0;
unsigned char   Com1Chksum=0;

unsigned char   Com1RxCnt=0;
unsigned char   Com1RxThisPt=0;
unsigned char   Com1TxCnt=0;
unsigned char   Com1TxThisPt=0;
UserDataType	Com1Crc=0;	
*/



/*
#define     ASCTOHEX(x) ((x <= '9') ? (x - '0') : (x - '7')) 
#define     L_SHIFT(x)  (x << 4)


#define     ASCTOHEX(x) ((x <= '9') ? (x - '0') : (x - '7')) 
#define     L_SHIFT(x)  (x << 4)

*/





void  __attribute__((section(".usercode"))) Com1RxSuccess(void)
{
	unsigned int i;


	IV_AckRdWrTxBuf[1]=Com1RxBuffer[1];
	IV_AckRdWrTxBuf[2]=Com1RxBuffer[2];
	IV_AckRdWrTxBuf[3]=Com1TxBuffer[3];
	IV_AckRdWrTxBuf[4]=Com1TxBuffer[4];

	for(i=0;i<Com1RxCnt;i++)	IV_AckRdWrTxBuf[i+5]=Com1RxBuffer[i+3];


	ThisAttribute[4]= Com1RxBuffer[5+0];  // max
	ThisAttribute[5]= Com1RxBuffer[5+1];

	ThisAttribute[2]= Com1RxBuffer[5+2];  // min
	ThisAttribute[3]= Com1RxBuffer[5+3];

	ThisAttribute[0]= Com1RxBuffer[5+4];  // decimal pt
	ThisAttribute[1]= Com1RxBuffer[5+5];


	IV_AckRdWrTxBuf[REQ_DATA_SEQ]=0;
}



/*
void  __attribute__((section(".usercode"))) OneWardWrAck(unsigned char val)
{
	unsigned int i;
	unsigned int txCnt,rcvCnt;

	switch(Com1RxThisPt){
		case	2:	//number of data low
		case	3:	//number of data low
		case	4:	//number of data low
		case	5:	//number of data low
		case	6:	//number of data low
			Com1RxThisPt++;	
			break;
		case	7:	//number of data low
			Com1RxBuffer[7]=val;
			Com1RxSuccess();
			Com1RxStatus=RX_GOOD;
			Com1RxThisPt=0;	
			break;
		default:
			Com1RxThisPt=0;	
			break;
	}
}
*/


void  __attribute__((section(".usercode"))) MultiWardWrAck(unsigned char val)
{
	unsigned int i;
	unsigned int txCnt,rcvCnt;

	switch(Com1RxThisPt){
		case	2:	//number of data low
		case	3:	//number of data low
		case	4:	//number of data low
		case	5:	//number of data low
		case	6:	//number of data low
			Com1RxThisPt++;	
			break;
		case	7:	//number of data low
			Com1RxBuffer[7]=val;
			Com1RxSuccess();
			Com1RxStatus=RX_GOOD;
			Com1RxThisPt=0;	
			break;
		default:
			Com1RxThisPt=0;	
			break;
	}
}



void  __attribute__((section(".usercode"))) ReadWardAck(unsigned char val)
{
	unsigned int i;
	unsigned int txCnt,rcvCnt;

	switch(Com1RxThisPt){
		case	2:	//number of data low
			txCnt=(Com1TxBuffer[5] * 2);
			rcvCnt=Com1RxBuffer[Com1RxThisPt];
			if(txCnt==rcvCnt){ 			
				Com1RxThisPt++;	
				Com1RxCnt=(rcvCnt+5);
			}
			else	Com1RxThisPt=0;
			break;
		default:
			Com1RxThisPt++;	
			if(Com1RxThisPt==Com1RxCnt){
				Com1Crc=0xffff;
				for(i=0;i< (Com1RxCnt-2);i++){
					Crc_Calulate_Cmm1((unsigned int)Com1RxBuffer[i]);
				}
	
				if(Com1RxBuffer[Com1RxCnt-2] != (unsigned char)Com1Crc)			Com1RxThisPt=0;
				if(Com1RxBuffer[Com1RxCnt-1] != (unsigned char)(Com1Crc >> 8))	Com1RxThisPt=0;
	
				if(Com1RxThisPt>0){
					Com1RxSuccess();
					Com1RxStatus=RX_GOOD;
				}
			} 
			else if(Com1RxThisPt > (Com1RxCnt+1)){
				Com1RxThisPt=0;	
			}
			break;
	}
}


void  __attribute__((section(".usercode"))) Com1ReceiveData(unsigned char val)
{
	unsigned int i;
	unsigned int txCnt,rcvCnt;


	if(Com1RxThisPt>= MAX_RTX_BUF)	Com1RxThisPt=0;	  //you

	Com1RxBuffer[Com1RxThisPt]=val;


	switch(Com1RxThisPt){
		case	0:	//adddress									
			if(Com1RxBuffer[Com1RxThisPt]==Com1TxBuffer[Com1RxThisPt]){
				Com1RxThisPt++;	
			}
			else	Com1RxThisPt=0;	
			break;
		case	1:	//command
			if(Com1RxBuffer[Com1RxThisPt]==Com1TxBuffer[Com1RxThisPt]){
				Com1RxThisPt++;	
			}
			else	Com1RxThisPt=0;	
			break;
		default:
			if(Com1RxBuffer[1] == 0x10){
				MultiWardWrAck(val);
			}
/*
			else if(Com1RxBuffer[1] == 0x06){
				OneWardWrAck(val);
			}
*/
			else if(Com1RxBuffer[1] == 0x03){
				ReadWardAck(val);
			}
			else{
				Com1RxThisPt=0;	
			}
			break;
	}
}

///////////////////


void      __attribute__((section(".usercode"))) Com1TxStart(void)
{   	
	Com1RxREGClear();
	Com1RxThisPt=0;   //you 
	TXEN=0;
	Com1SerialTime=0;
   	Com1TxThisPt=0;
   	Com1RxStatus=TX_SET;
    U1TXREG=Com1TxBuffer[Com1TxThisPt];
   	Com1TxThisPt=1;   
}




void  __attribute__((section(".usercode"))) Com1Autolanding(void)
{
    if(Com1RxStatus == TX_SET){
		if(_TRMT)	TXEN=1;	
	}

	if( (Com1SerialTime > 1) && (Com1RxStatus != STX_CHK)){
		TXEN=1;
		Com1TxThisPt =0;
		Com1TxCnt=0;
		Com1RxCnt=0;
		Com1RxThisPt=0;
      	Com1RxStatus = STX_CHK;
	}
}


void  __attribute__((section(".usercode"))) Com1AutolandingTxInt(void)
{
	Com1SerialTime=0;
	
	if(Com1TxThisPt >= Com1TxCnt){
		Com1TxThisPt =0;
		Com1TxCnt=0;
    }
    else{
      	U1TXREG=Com1TxBuffer[Com1TxThisPt];
      	Com1TxThisPt++;
      	Com1RxStatus = TX_SET;
    }
}

void  __attribute__((section(".usercode"))) Com1AutolandingRxInt(unsigned char buf1)
{
    Com1SerialTime=0;
    if(Com1RxStatus != TX_SET)	Com1ReceiveData(buf1);
}



/*
void  __attribute__((section(".usercode"))) SerialCheck(void)
{
    if(Com1RxStatus == TX_SET){
		if(_TRMT)	TXEN=1;	
	}

	if( (Com1SerialTime > 1) && (Com1RxStatus != STX_CHK)){
		TXEN=1;
		Com1TxThisPt =0;
		Com1TxCnt=0;
		Com1RxCnt=0;
		Com1RxThisPt=0;
      	Com1RxStatus = STX_CHK;
	}
}
*/


/*
void _ISR_X _U1TXInterrupt(void)
{

    _U1TXIF=0;
    
	Com1SerialTime=0;


	if(Com1TxThisPt >= Com1TxCnt){
		Com1TxThisPt =0;
		Com1TxCnt=0;
    }
    else{
      	U1TXREG=Com1TxBuffer[Com1TxThisPt];
      	Com1TxThisPt++;
      	Com1RxStatus = TX_SET;
    }
}
*/



/*

void _ISR_X _U1RXInterrupt(void)
{
   	unsigned char   buf1=0;

    _U1RXIF=0;
    
   	if(_U1RXDA)    buf1=U1RXREG;
   	if(_U1RXDA)    buf1=U1RXREG;
   	if(_U1RXDA)    buf1=U1RXREG;
   	if(_U1RXDA)    buf1=U1RXREG;
   	if(_U1RXDA)    buf1=U1RXREG;
   	if(_U1RXDA)    buf1=U1RXREG;

    Com1SerialTime=0;


    if(_U1FERR){
        _U1FERR=0;
    }

    if(_U1PERR){
        _U1PERR=0;
    }

	
    if(Com1RxStatus != TX_SET)	Com1ReceiveData(buf1);
}
*/


//#endif
