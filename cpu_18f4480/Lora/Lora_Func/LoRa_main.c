/*
 * THE FOLLOWING FIRMWARE IS PROVIDED: (1) "AS IS" WITH NO WARRANTY; AND 
 * (2)TO ENABLE ACCESS TO CODING INFORMATION TO GUIDE AND FACILITATE CUSTOMER.
 * CONSEQUENTLY, SEMTECH SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR
 * CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT
 * OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION
 * CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 * 
 * Copyright (C) SEMTECH S.A.
 */
/*! 
 * \file       main.c
 * \brief      Ping-Pong example application on how to use Semtech's Radio
 *             drivers.
 *
 * \version    2.0
 * \date       Nov 21 2012
 * \author     Miguel Luis
 */
#include    <pic18.h>

#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#include	"..\loader_45k80.h"
#include    "..\..\crt_can_232_45k80\crt_canport1.h"


#include "platform.h"

#include "sx1276.h"
#include "sx1276-Lora.h"
#include "spi.h"

//#include "led.h"


#include "radio.h"

#define	IAM_MASTER		0
#define	IAM_SLAVE		1
#define	IAM_REPEATER	2


#define	ONE_BLOCK		13
#define	TWO_BLOCK		(ONE_BLOCK + ONE_BLOCK)													//26
#define	THREE_BLOCK		(ONE_BLOCK + ONE_BLOCK + ONE_BLOCK)										//39
#define	FOUR_BLOCK		(ONE_BLOCK + ONE_BLOCK + ONE_BLOCK + ONE_BLOCK)							//52
#define	FIVE_BLOCK		(ONE_BLOCK + ONE_BLOCK + ONE_BLOCK + ONE_BLOCK + ONE_BLOCK)				//65
#define	SIX_BLOCK		(ONE_BLOCK + ONE_BLOCK + ONE_BLOCK + ONE_BLOCK + ONE_BLOCK + ONE_BLOCK)	//78

#define	RX_ALIVE_TIME	3000	// 3sec

extern	uint32_t TickCounter;


uint8_t MyFuncId=0;

double	abc[5];


uint16_t	IOBoardRxTimer=0;
uint16_t	MyFuncTimeOut=0;
uint16_t	youRxTime=0;
uint8_t		rxstate=0;

uint8_t  	tmpHostbuf[80];
uint8_t  	tmpHostDtatCnt=0;


/*
 * Manages the master operation
 */



#define RUNLED 			LATD0	
#define RF_TXLED       	LATD1	
#define RF_RXLED       	LATD2 	

//#define RF_TXLED       	LATC1	
//#define RF_RXLED       	LATC2 	

extern volatile bit xRB0                @ ((unsigned)&PORTB*8)+0;
extern volatile bit xRB1                @ ((unsigned)&PORTB*8)+1;



void YouMyFuncRead(void)
{
	TRISB0=1;
	TRISB1=1;
	xRB0=1;
	xRB1=1;

	MyFuncId=0;

	if(!xRB0)	MyFuncId=(MyFuncId | 0x01);
	if(!xRB1)	MyFuncId=(MyFuncId | 0x02);
}


uint16_t	CanLowDataLoad(uint8_t *buf)
{
	uint16_t	i,j,savept;
	uint8_t		ThisRxAdr;

	savept=0xff;

	if(MyFuncId == IAM_MASTER){
		if(Can1RxEid & 0x2000){
			j=(unsigned char)(Can1RxEid & 0x0f);
			if(j>4)	j=4;	
			savept=(j * ONE_BLOCK);
			if(Can1RxDataTotalCnt==0)	Can1RxDataTotalCnt=FIVE_BLOCK;
		}
		else{
			ThisRxAdr=(uint8_t)(Can1RxEid & 0xff);

			if(Can1RxBuf[FIVE_BLOCK+4]==0){
				savept=FIVE_BLOCK;
				Can1RxDataTotalCnt=SIX_BLOCK;
			}
			else if(Can1RxBuf[FIVE_BLOCK+4]==ThisRxAdr){
				savept=FIVE_BLOCK;
			}
		}
	}
	else{	
		if( !(Can1RxEid & 0x2000)){
			ThisRxAdr=(uint8_t)(Can1RxEid & 0xff);
			if( ThisRxAdr == 0x8b){
				savept=0;
				if(Can1RxDataTotalCnt==0)	Can1RxDataTotalCnt=ONE_BLOCK;
				IOBoardRxTimer=0;
			}
			else{
				if(Can1RxBuf[ONE_BLOCK+4]==0){
					savept=ONE_BLOCK;
					Can1RxDataTotalCnt=TWO_BLOCK;
				}
				else if(Can1RxBuf[ONE_BLOCK+4]==ThisRxAdr){
					savept=ONE_BLOCK;
				}				
				else if(Can1RxBuf[TWO_BLOCK+4]==0){
					savept=TWO_BLOCK;
					Can1RxDataTotalCnt=THREE_BLOCK;
				}
				else if(Can1RxBuf[TWO_BLOCK+4]==ThisRxAdr){
					savept=TWO_BLOCK;
				}				
			}
		}
	}

	if(savept != 0xff){
		for( i = 0; i < ONE_BLOCK; i++ )	Can1RxBuf[savept+i] = *(buf+i);		
		Can1RxTimer=0;
	}

	return(0);
}




unsigned int MasterCanRxDataTxToRf(void)
{
	uint8_t		i;
	if(Can1RxTimer<(RX_ALIVE_TIME)){		// 3sec
		if(Can1RxDataTotalCnt >= FIVE_BLOCK){
			SX1276SetTxPacket( &Can1RxBuf,Can1RxDataTotalCnt);	
			for(i=0;i<Can1RxDataTotalCnt;i++)	Can1RxBuf[i]=0;		
			Can1RxDataTotalCnt=0;
			youRxTime=0;
			rxstate=0;
		}
	}
	else{
		rxstate=0;
		Can1RxTimer=0;
		Can1RxDataTotalCnt=0;
		for(i=0;i<CAN1_MAX_RX_BUF;i++)	Can1RxBuf[i]=0;
	}

	return(0);
}



unsigned int SlaveCanRxDataTxToRf(void)
{
	uint8_t		i;
	if(Can1RxTimer<RX_ALIVE_TIME){		// 3sec
		if(Can1RxDataTotalCnt >= ONE_BLOCK){
			SX1276SetTxPacket( &Can1RxBuf,Can1RxDataTotalCnt);
			MyFuncTimeOut=0;
			
			if(IOBoardRxTimer > 1200){
				for(i=0;i<Can1RxDataTotalCnt;i++)	Can1RxBuf[i]=0;		
				Can1RxDataTotalCnt=0;
			}
			else{
				for(i=0;i<Can1RxDataTotalCnt;i++)	Can1RxBuf[ONE_BLOCK+i]=0;		
				Can1RxDataTotalCnt=ONE_BLOCK;
			}
		}
	}
	else{
		Can1RxTimer=0;
		Can1RxDataTotalCnt=0;
		for(i=0;i<CAN1_MAX_RX_BUF;i++)	Can1RxBuf[i]=0;
	}

	return(0);
}


/*
unsigned int SlaveCanRxDataTxToRf(void)
{
	uint8_t		i;

	if(Can1RxTimer<RX_ALIVE_TIME){		// 3sec
		if(Can1RxDataTotalCnt >= ONE_BLOCK){
			SX1276SetTxPacket( &Can1RxBuf,Can1RxDataTotalCnt);
			MyFuncTimeOut=0;
			for(i=0;i<Can1RxDataTotalCnt;i++)	Can1RxBuf[i]=0;		
			Can1RxDataTotalCnt=0;
		}
	}
	else{
		Can1RxTimer=0;
		Can1RxDataTotalCnt=0;
		for(i=0;i<CAN1_MAX_RX_BUF;i++)	Can1RxBuf[i]=0;
	}
	return(0);
}
*/


void MyFuncTimeOutChk(void)
{
	if(MyFuncTimeOut>7000){
		MyFuncTimeOut=0;
    	asm("reset");

/*
		if(MyFuncId == IAM_MASTER){
			Can1RxDataTotalCnt=0;
		}
		else if(MyFuncId == IAM_SLAVE){
			Can1TxDataTxPointer=0;
		}
//		else if(MyFuncId == IAM_REPEATER){
//			Can1RxDataTotalCnt=0;
//		}
        SX1276StartRx();			
*/

	}
}




void OnMaster( void )
{
    uint16_t datanm;

    switch( SX1276Process())
    {
    case RF_RX_TIMEOUT:
		MasterCanRxDataTxToRf();
		RF_TXLED= !RF_TXLED;
        break;
    case RF_RX_DONE:
        SX1276GetRxPacket( Can1TxBuf, ( uint16_t* )&datanm);
		if(datanm >= ONE_BLOCK){
			Can1TxDataTotalCnt=(uint8_t)datanm;
			if(Can1TxBuf[3] & 0x20){	// if host receive host data cancle   eid = 0x02000
				Can1TxDataTotalCnt=0;
			}
			else{
				RF_RXLED = !RF_RXLED;
				youRxTime=500;
				rxstate++;
				MyFuncTimeOut=0;
			}
		}
        break;
    case RF_TX_DONE:
        SX1276StartRx();
		rxstate=0;
		youRxTime=500;
        break;
    default:
		if((youRxTime>1000) || (rxstate >= 2)){
			rxstate=0;
			youRxTime=0;	
			SX1276SetRFState(RFLR_STATE_RX_TIMEOUT);
		}
        break;
    }
}

/*
 * Manages the slave operation
 */


void OnSlave( void )
{
    uint16_t datanm,i;
	uint8_t  tmpbuf[80];

    switch( SX1276Process())
    {
    case RF_RX_DONE:
	    SX1276GetRxPacket( tmpbuf, ( uint16_t* )&datanm);
//		if(datanm >= 65){
//			youRxTime=0;
			if( (tmpbuf[3] & 0x20) && (datanm >= 65)){	// if host receive host data ok
				youRxTime=0;
				rxstate=0;
				if(MyFuncId == IAM_SLAVE){
					for(i=0;i<datanm;i++)	Can1TxBuf[i]=tmpbuf[i];	
					Can1TxDataTotalCnt=(uint8_t)datanm;
		 			SlaveCanRxDataTxToRf();
					RF_RXLED = !RF_RXLED;				
				}
				else{
					for(i=0;i<datanm;i++)	tmpHostbuf[i]=tmpbuf[i];	
					tmpHostDtatCnt=(uint8_t)datanm;
					rxstate=1;
					RF_RXLED = !RF_RXLED;				
				}
			}
//		}
        break;
    case RF_TX_DONE:
		RF_TXLED=!RF_TXLED;
        SX1276StartRx();
        break;
    default:
		if(MyFuncId == IAM_REPEATER){
			if(rxstate==1){  //master data rx
				if(youRxTime>150){				//200msec		
					for(i=0;i<tmpHostDtatCnt;i++)	Can1TxBuf[i]=tmpHostbuf[i];	
					Can1TxDataTotalCnt=(uint8_t)tmpHostDtatCnt;
		 			SlaveCanRxDataTxToRf();
					rxstate=0;
				}
			}
			else{
				rxstate=0;
			}
		}
        break;
    }
}

extern	void SX1276LoRaSetRxSingleOn( bool enable );
extern	void SX1276LoRaSetOpMode( uint8_t opMode );

//extern	void SX1276WriteBuffer( uint8_t addr, uint8_t *buffer, uint8_t size );
//extern	void SX1276ReadBuffer( uint8_t addr, uint8_t *buffer, uint8_t size );


int LoRa_Init( void )
{

//#define RUNLED 			LATD0	
//#define RF_TXLED       	LATD1	
//#define RF_RXLED       	LATD2 	

	TRISD0=0;				//RUN_LED
	TRISD1=0;				//RF_TXLED
	TRISD2=0;				//RF_RXLED

//	TRISC1=0;				//RF_TXLED
//	TRISC2=0;				//RF_RXLED

	RUNLED=0;
	RF_TXLED=0;
	RF_RXLED=0;


	InitSPI();
	SX1276Init();
	SX1276StartRx();

	YouMyFuncRead();


	if(MyFuncId == IAM_MASTER){ 
		SX1276LoRaSetRxSingleOn(true);	// Master
	}
	else{
		SX1276LoRaSetRxSingleOn(false);	// slave/reprater
	}

	return(0);
}



int Lora_Func( void )
{
	MyFuncTimeOutChk();
	
	if(MyFuncId == IAM_MASTER) 
	{
		OnMaster( );
	}
	else
	{
		OnSlave( );
	}    
}


int RunLed( void )
{
	RUNLED=!RUNLED;
	return(0);
}


int Lora_Msec1_Interrpt( void )
{
	TickCounter++;
	youRxTime++;
	MyFuncTimeOut++;
	Can1RxTimer++;
	IOBoardRxTimer++;
}






