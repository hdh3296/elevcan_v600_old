

#include    <pic18.h>



#include        "..\..\..\system_com\memory_map.h"
#include        "..\..\comm_4480\iodef.h"
#include        "..\..\comm_4480\fontout.h"
#include        "..\..\comm_4480\comdata.h"
#include        "..\..\comm_4480\keysort.h"
#include        "..\..\comm_4480\setup.h"
#include        "..\..\comm_4480\esdots.h"
#include        "..\..\can_4480\you_can.h"



#if   defined(POWER_CONTROL) 


#define  MAIN_POWER		IO_00         
#define  HOST_CAN_ON	IO_01        



unsigned int	sec1_Timer=0;
unsigned int	EL_StopTime=0;
unsigned int	EL_OnTime=0;

unsigned char	ThisBufPt=0;


#define	CHARTER_TIME	20	// 20 msec

unsigned char	charter_IO_08;
unsigned char	charter_IO_09;
unsigned char	charter_IO_10;
unsigned char	charter_IO_11;
unsigned char	charter_IO_12;
unsigned char	charter_IO_13;
unsigned char	charter_IO_14;
unsigned char	charter_IO_15;


unsigned char	IN_BUF=0;


bit	Bef_IO_08=0;	
bit	Cur_IO_08=0;	
bit	Bef_IO_09=0;	
bit	Cur_IO_09=0;	
bit	Bef_IO_10=0;	
bit	Cur_IO_10=0;	
bit	Bef_IO_11=0;	
bit	Cur_IO_11=0;	
bit	Bef_IO_12=0;	
bit	Cur_IO_12=0;	
bit	Bef_IO_13=0;	
bit	Cur_IO_13=0;	
bit	Bef_IO_14=0;	
bit	Cur_IO_14=0;	
bit	Bef_IO_15=0;	
bit	Cur_IO_15=0;	

bit	bTimeClear=0;
bit	bPowerOnOff=0;



extern	void CANTxSidEidSet(char MsgFlag,unsigned int sid, unsigned long eid);


void    Power_TxSidEidArrary(void)
{
    unsigned int  itmp1,itmp2;
    unsigned long ltmp1;

Company=COMPANY;

    SidBuffer=(unsigned int)Company;
	if(MyAddress & 0x08)	SidBuffer=(SidBuffer | 0x080);		
	if(MyAddress & 0x10)	SidBuffer=(SidBuffer | 0x100);		
	if(MyAddress & 0x20)	SidBuffer=(SidBuffer | 0x200);		
	if(MyAddress & 0x40)	SidBuffer=(SidBuffer | 0x400);		

    EidBuffer=HOST_BOARD;
	if(MyAddress & 0x01)	EidBuffer=(EidBuffer | 0x400);		
	if(MyAddress & 0x02)	SidBuffer=(EidBuffer | 0x800);		
	if(MyAddress & 0x04)	EidBuffer=(EidBuffer | 0x1000);		
	if(MyAddress & 0x80)	EidBuffer=(EidBuffer | 0x2000);		


}




void    Power_LoadCanTxBuf(unsigned char *pt)
{
	unsigned char	i,j;

	j=(ThisBufPt * 8);
	for(i=0;i<8;i++)	*(pt+i)=RcvBuf[i + j];           
}



void    Power_CanTx0(void)
{
    if(!TXB0CONbits.TXREQ && CanTxAct){
        Power_TxSidEidArrary();
        CANTxDLC(0,8);

		if(ThisBufPt==4)	ThisBufPt=8;

        CANTxSidEidSet(0,SidBuffer,EidBuffer + ThisBufPt);
		Power_LoadCanTxBuf((unsigned char *)&TXB0D0);

#if  defined(CPU65K80)   ||  defined(CPU45K80)
IPR5=0;
#else        
IPR3=0;
#endif

        TXB0IP=1;

        TXB0CONbits.TXREQ = 1 ; // 전송 요구 비트 셋


		ThisBufPt=(ThisBufPt + 1);
		if(ThisBufPt > 5){
			CanTxAct=0;
			ThisBufPt=0;
			EL_StopTime=0;
		}	

    }
}









void  MyAdrRead(void)
{
   	MyAddress=0;
}





void    PortInit_X(void)
{

  	TRISE2=1;	    // port E data direction...(output)
  	TRISE1=1;
  	TRISE0=1;

  	TRISA=0xff;
  	TRISB=0xff;
  	TRISC=0xff;
  	TRISD=0x00;
	

	PORTA=0xff;
	PORTB=0xff;
	PORTC=0xff;
	PORTD=0x00;
	
	PORTE=0xff;

	TRISB0=0;		//RUN LED 
	TRISB3=1;   	//can rx 
	TRISB2=0;   	//can tx
	
	LATB0=0;		//RUN LED
	LATB3=1;		//can rx
	LATB2=0;		//can tx


	MAIN_POWER=0;
	HOST_CAN_ON=0;

	EL_OnTime=0;
	EL_StopTime=0;	
	sec1_Timer=0;
	bTimeClear=0;
	bPowerOnOff=0;
}



void	Input_Chk(void)
{
    if(Bef_IO_08 == IO_08){
        if(charter_IO_08 > CHARTER_TIME ){
            Cur_IO_08 = IO_08;
        }
    }
    else{
        Bef_IO_08 = IO_08;
        charter_IO_08 = 0;
    }    


    if(Bef_IO_09 == IO_09){
        if(charter_IO_09 > CHARTER_TIME ){
            Cur_IO_09 = IO_09;
        }
    }
    else{
        Bef_IO_09 = IO_09;
        charter_IO_09 = 0;
    }    



    if(Bef_IO_10 == IO_10){
        if(charter_IO_10 > CHARTER_TIME ){
            Cur_IO_10 = IO_10;
        }
    }
    else{
        Bef_IO_10 = IO_10;
        charter_IO_10 = 0;
    }    



    if(Bef_IO_11 == IO_11){
        if(charter_IO_11 > CHARTER_TIME ){
            Cur_IO_11 = IO_11;
        }
    }
    else{
        Bef_IO_11 = IO_11;
        charter_IO_11 = 0;
    }    


    if(Bef_IO_12 == IO_12){
        if(charter_IO_12 > CHARTER_TIME ){
            Cur_IO_12 = IO_12;
        }
    }
    else{
        Bef_IO_12 = IO_12;
        charter_IO_12 = 0;
    }    


    if(Bef_IO_13 == IO_13){
        if(charter_IO_13 > CHARTER_TIME ){
            Cur_IO_13 = IO_13;
        }
    }
    else{
        Bef_IO_13 = IO_13;
        charter_IO_13 = 0;
    }    



    if(Bef_IO_14 == IO_14){
        if(charter_IO_14 > CHARTER_TIME ){
            Cur_IO_14 = IO_14;
        }
    }
    else{
        Bef_IO_14 = IO_14;
        charter_IO_14 = 0;
    }    



    if(Bef_IO_15 == IO_15){
        if(charter_IO_15 > CHARTER_TIME ){
            Cur_IO_15 = IO_15;
        }
    }
    else{
        Bef_IO_15 = IO_15;
        charter_IO_15 = 0;
    }    


	IN_BUF=0;
	if(Cur_IO_08)	IN_BUF = (IN_BUF | 0x01);	
	if(Cur_IO_09)	IN_BUF = (IN_BUF | 0x02);	
	if(Cur_IO_10)	IN_BUF = (IN_BUF | 0x04);	
	if(Cur_IO_11)	IN_BUF = (IN_BUF | 0x08);	
	if(Cur_IO_12)	IN_BUF = (IN_BUF | 0x10);	
	if(Cur_IO_13)	IN_BUF = (IN_BUF | 0x20);	
	if(Cur_IO_14)	IN_BUF = (IN_BUF | 0x40);	
	if(Cur_IO_15)	IN_BUF = (IN_BUF | 0x80);	

}



unsigned int  MyFunc(void)
{
    unsigned 	int    IdPt;

	IdPt=(LocalNumber * HOST_DATA_RECOD) + RCV_DATA;

	if(!bPowerOnOff){	
		if(RcvBuf[IdPt + SL_mSysStatus] != 65)		bTimeClear=1;	
		if( !(RcvBuf[IdPt + S1_STATE] & S1_AUTO))	bTimeClear=1;
		if((RcvBuf[IdPt + S2_STATE] & S2_CAR_MOVE))	bTimeClear=1;
		
		if(bTimeClear){
			sec1_Timer=0;	
			EL_StopTime=0;
			EL_OnTime=0;
			bTimeClear=0;
		}

		if(EL_StopTime > 30){
			MAIN_POWER=1;
			HOST_CAN_ON=1;
			bPowerOnOff=1;
			sec1_Timer=0;	
			EL_StopTime=1;
			EL_OnTime=0;

			EqualDataBuf[0]=0;

			RcvBuf[IdPt + S0_FLOOR]=RcvBuf[IdPt + S0_FLOOR]+1;	
			RcvBuf[IdPt + S1_STATE]=0;
			RcvBuf[IdPt + S2_STATE]=0;
			RcvBuf[IdPt + S3_STATE]=0;
			RcvBuf[IdPt + S4_STATE]=0;

			RcvBuf[IdPt + S1_STATE]=(RcvBuf[IdPt + S1_STATE] | S1_AUTO); 

			RcvBuf[IdPt + DSP1]='0';
			RcvBuf[IdPt + DSP2]='0';
		}	
	}
	else{
		if(EqualDataBuf[0] ==0){
			EL_OnTime=0;
		}
		else{
			MAIN_POWER=0;
			if(EL_OnTime >= 4){
				HOST_CAN_ON=0;
				bPowerOnOff=0;

				sec1_Timer=0;	
				EL_StopTime=0;
				EL_OnTime=0;
			}			
		}
		
		if( bPowerOnOff){	
			RcvBuf[IdPt + S0_FLOOR]=0;	
			RcvBuf[IdPt + S1_STATE]=0;
			RcvBuf[IdPt + S2_STATE]=0;
			RcvBuf[IdPt + S3_STATE]=0;
			RcvBuf[IdPt + S4_STATE]=0;

			RcvBuf[IdPt + S1_STATE]=(RcvBuf[IdPt + S1_STATE] | S1_AUTO); 

			RcvBuf[IdPt + DSP1]='0';
			RcvBuf[IdPt + DSP2]='0';


			if(EL_StopTime >= 1){
				if( !CanTxAct){
					ThisBufPt=0;
					CanTxAct=1;
				}
			}
			Power_CanTx0();
		}
	}



	Input_Chk();

	return(1);
}


void	Timer_1msec(void)
{

	sec1_Timer++;
	if(sec1_Timer > 1000){
		sec1_Timer=0;	
		if(EL_StopTime < 6000)	EL_StopTime++;   // 100 minute
		if(EL_OnTime   < 6000)	EL_OnTime++;
	} 

    if(charter_IO_08 < 250)	charter_IO_08++;
    if(charter_IO_09 < 250)	charter_IO_09++;
    if(charter_IO_10 < 250)	charter_IO_10++;
    if(charter_IO_11 < 250)	charter_IO_11++;
    if(charter_IO_12 < 250)	charter_IO_12++;
    if(charter_IO_13 < 250)	charter_IO_13++;
    if(charter_IO_14 < 250)	charter_IO_14++;
    if(charter_IO_15 < 250)	charter_IO_15++;
}




#endif
