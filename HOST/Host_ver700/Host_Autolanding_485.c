

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
#include  	"default_setup.h" 

#include  	"EDS_par_map.h" 

#include  	"Host_Autolanding.h" 


#ifdef	AUTO_LANDING_485	


//#define		INVERTER_ADDR	0xff


LocalType __attribute__((section(".usercode"))) Delta_ReadAttribute_485(unsigned char addressH,unsigned char addressL)
{    

//	unsigned int j;

//	Com1TxBuffer[0]=INVERTER_ADDR;
//	Com1TxBuffer[1]=RD_SDO_INV_REG;
//	Com1TxBuffer[2]=addressH;
//	Com1TxBuffer[3]=addressL;
//	Com1TxBuffer[4]=0x00;
//	Com1TxBuffer[5]=0x05;


//	Com1Crc=0xffff;
//	for(j=0;j<6;j++){
//		Crc_Calulate((unsigned int)Com1TxBuffer[j]);
//	}

//	Com1TxBuffer[6]=(unsigned char)Com1Crc;
//	Com1TxBuffer[7]=(unsigned char)(Com1Crc >> 8);

//	Com1TxCnt=8;
//	Com1TxThisPt=0;

//	IV_AckRdWrTxBuf[REQ_DATA_SEQ]=1;
//	DeltaNoAck=0;

//	Com1TxStart();


	IV_AckRdWrTxBuf[REQ_DATA_SEQ]=0;
	DeltaNoAck=0;
	Com1SerialTime=20;
//	ParRdWrReadyTimer=0;

	return(1);
}



LocalType __attribute__((section(".usercode"))) Delta_ReadParameter_485(unsigned char addressH,unsigned char addressL,unsigned char ReadWordNm)
{
	unsigned int j;

	if(Com1SerialTime < 10)	return(0);

//	Com1TxBuffer[0]=INVERTER_ADDR;
	Com1TxBuffer[0]=(unsigned char)(InverterAddress);
	Com1TxBuffer[1]=RD_SDO_INV_REG;
	Com1TxBuffer[2]=addressH;
	Com1TxBuffer[3]=addressL;
	Com1TxBuffer[4]=0x00;
	Com1TxBuffer[5]=(ReadWordNm + 4);


    Com1Crc=0xffff;
    for(j=0;j<6;j++){
        Crc_Calulate_Cmm1((unsigned int)Com1TxBuffer[j]);
    }

	Com1TxBuffer[6]=(unsigned char)Com1Crc;
	Com1TxBuffer[7]=(unsigned char)(Com1Crc >> 8);

	Com1TxCnt=8;
	Com1TxThisPt=0;

	IV_AckRdWrTxBuf[REQ_DATA_SEQ]=1;
	DeltaNoAck=0;

	Com1TxStart();

	return(1);
}



/*
LocalType __attribute__((section(".usercode"))) Delta_WriteParameter_485(unsigned char addressH,unsigned char addressL,unsigned char WriteWordNm,unsigned char valH,unsigned char valL)
{
	unsigned int j;

	if(Com1SerialTime < 10)	return(0);

	Com1TxBuffer[0]=INVERTER_ADDR;
	Com1TxBuffer[1]=WR_SDO_INV_REG;
	Com1TxBuffer[2]=addressH;
	Com1TxBuffer[3]=addressL;
	Com1TxBuffer[4]=valH;
	Com1TxBuffer[5]=valL;

    Com1Crc=0xffff;
    for(j=0;j<6;j++){
        Crc_Calulate((unsigned int)Com1TxBuffer[j]);
    }
	Com1TxBuffer[6]=(unsigned char)Com1Crc;
	Com1TxBuffer[7]=(unsigned char)(Com1Crc >> 8);


	Com1TxCnt=8;
	Com1TxThisPt=0;

	IV_AckRdWrTxBuf[REQ_DATA_SEQ]=1;
	DeltaNoAck=0;

	Com1TxStart();

	return(1);
}
*/


LocalType __attribute__((section(".usercode"))) Delta_WriteParameter_485_Multi(unsigned char addressH,unsigned char addressL,unsigned char WriteWordNm,unsigned char valH,unsigned char valL)
{
	unsigned int j;
	
	if(Com1SerialTime < 10)	return(0);

//	Com1TxBuffer[0]=INVERTER_ADDR;
	Com1TxBuffer[0]=(unsigned char)(InverterAddress);
	Com1TxBuffer[1]=WR_SDO_INV_REG_MB;
	Com1TxBuffer[2]=addressH;
	Com1TxBuffer[3]=addressL;
	Com1TxBuffer[4]=0;
	Com1TxBuffer[5]=WriteWordNm;  // 1 ward
	Com1TxBuffer[6]=2;			 //  2 byte	
	Com1TxBuffer[7]=valH;
	Com1TxBuffer[8]=valL;

    Com1Crc=0xffff;
    for(j=0;j<9;j++){
        Crc_Calulate_Cmm1((unsigned int)Com1TxBuffer[j]);
    }
	Com1TxBuffer[9]=(unsigned char)Com1Crc;
	Com1TxBuffer[10]=(unsigned char)(Com1Crc >> 8);


	Com1TxCnt=11;
	Com1TxThisPt=0;

	IV_AckRdWrTxBuf[REQ_DATA_SEQ]=1;
	DeltaNoAck=0;

	Com1TxStart();

	return(1);
}



#endif

