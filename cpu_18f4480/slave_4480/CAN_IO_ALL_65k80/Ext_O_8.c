

#include    <pic18.h>



#include        "..\..\..\system_com\memory_map.h"
#include        "..\..\comm_4480\iodef.h"
#include        "..\..\comm_4480\fontout.h"
#include        "..\..\comm_4480\comdata.h"
#include        "..\..\comm_4480\keysort.h"
#include        "..\..\comm_4480\setup.h"
#include        "..\..\comm_4480\esdots.h"



#if   defined(NEW_CAN_O_8) 


#define  OUT_UP		IO_00         
#define  OUT_DN		IO_01        
#define  OUT_NORMAL	IO_02
#define  OUT_ERR   	IO_03
#define  OUT_FLOOR1	IO_04
#define  OUT_FLOOR2	IO_05
#define  OUT_FLOOR3	IO_06



void  MyAdrRead(void)
{
   	MyAddress=0;
   	MyAddress=0x8b;
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

}




unsigned int  MyFunc(void)
{
    unsigned 	int    IdPt;

    IdPt=(LocalNumber * HOST_DATA_RECOD) + RCV_DATA;


   if(RcvBuf[IdPt + S1_STATE] & S1_UP)      OUT_UP=1;
   else                                     OUT_UP=0;

   if(RcvBuf[IdPt + S2_STATE] & S2_DN)      OUT_DN=1;
   else                                     OUT_DN=0;

   if(RcvBuf[IdPt + S1_STATE] & S1_AUTO)    OUT_NORMAL=1;
   else    									OUT_NORMAL=0;

   if(RcvBuf[IdPt + SL_mSysStatus] <= 35)   OUT_ERR=1;
   else    									OUT_ERR=0;



	switch(RcvBuf[IdPt + S0_FLOOR]){
		case	1:
			OUT_FLOOR1=1;
			OUT_FLOOR2=0;
			OUT_FLOOR3=0;
			break;
		case	2:
			OUT_FLOOR1=0;
			OUT_FLOOR2=1;
			OUT_FLOOR3=0;
			break;
		case	3:
			OUT_FLOOR1=0;
			OUT_FLOOR2=0;
			OUT_FLOOR3=1;
			break;
		default:
			OUT_FLOOR1=0;
			OUT_FLOOR2=0;
			OUT_FLOOR3=0;
			break;		
	}

/*
	if(RcvBuf[IdPt + SL_OUT_FAN] & 0x01)	OUT_FAN=1;
	else									OUT_FAN=0;

	if(RcvBuf[IdPt + SL_OUT_FAN] & 0x02)	OUT_LIT=1;
	else									OUT_LIT=0;
	
	if(RcvBuf[IdPt + SL_OUT_FAN] & 0x04)	OUT_BUZ=1;
	else									OUT_BUZ=0;

	if(RcvBuf[IdPt + SL_OUT_FAN] & 0x08)	OUT_BELL=1;
	else									OUT_BELL=0;
*/

	return(1);
}



void	Timer_1msec(void)
{
}


#endif
