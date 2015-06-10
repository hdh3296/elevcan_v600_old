


#include    <pic18.h>

#include        "iodef.h"
#include        "fontout.h"
#include        "comdata.h"
#include        "esdots.h"
#include        "keysort.h"
#include        "setup.h"
#include        "..\..\system_com\memory_map.h"


extern	bit	bDoorOpenWaitOn;
bit	bErrorCar; 


//#define	BCD_DSP		1
#define	BINARY_DSP	1

void    CompanyChk(unsigned char id)        
{
    unsigned int    IdPt;
    unsigned char   TmpCompany;

	IdPt=IsBufferPt(id);
    
    if(!MaskSetBit){
       if((RcvBuf[IdPt+DSP1] == 'C') && (RcvBuf[IdPt+DSP2] == 'M') && !(RcvBuf[IdPt+1] & S1_AUTO))  {
	        TmpCompany=(unsigned char)RxSidBuffer;
			if(TmpCompany != Company){ 
	            Company=TmpCompany;
	            CmpSetBit=1;
			}      
        }
    }
}



unsigned char   Lamp(unsigned char id)
{
    unsigned int    IdPt;


	IdPt=IsBufferPt(id);
    
    FDsp=0;

    HostCallMe=0;
    if(CallMeAdr == RcvBuf[IdPt + SL_mCallMe])  HostCallMe=1;


#if  defined(__TYPE_HIB_HPI)   ||  defined(__TYPE_ES15)
	if(RcvBuf[IdPt+SL_mCrtExtMoveFlr] & UP_READY){
		if((RcvBuf[IdPt+SL_mCrtExtMoveFlr] & ONLY_FLR) == MyAddress){
			UpKeyBit=1;
			UpButtonTime=10;
		}
	}

	if(RcvBuf[IdPt+SL_mCrtExtMoveFlr] & DN_READY){
		if((RcvBuf[IdPt+SL_mCrtExtMoveFlr] & ONLY_FLR) == MyAddress){
			DnKeyBit=1;
			DnButtonTime=10;
		}
	}
#endif



    TopFloor=RcvBuf[IdPt + SL_mTopFlr];

    CurFloor=RcvBuf[IdPt];



#ifdef	BCD_DSP
	dsplamp1=CurFloor;
	P0=dsplamp1;
#elif   defined(BINARY_DSP)
	dsplamp1=0; 
	switch(CurFloor){
		case	1:
			dsplamp1=(dsplamp1 | 0x01);
			break;
		case	2:
			dsplamp1=(dsplamp1 | 0x02);
			break;
		case	3:
			dsplamp1=(dsplamp1 | 0x04);
			break;
	}

	P0=dsplamp1;





	dsplamp0 = 0;
	if(CurFloor==9)	dsplamp0=(dsplamp0 | 0x01);	   
	else if(CurFloor==10)	dsplamp0=(dsplamp0 | 0x02);	   


    BefCurFloor=(P2 & 0xe0);
    dsplamp0=(dsplamp0 | BefCurFloor);
    P2=dsplamp0;
	
#else	
   if(RcvBuf[IdPt+DSP1] == 'B')      dsplamp0 = 0x1f;   
   else if(RcvBuf[IdPt+DSP1] == '1') dsplamp0 = 0x06;
   else if(RcvBuf[IdPt+DSP1] == '2') dsplamp0 = 0x0b;
   else if(RcvBuf[IdPt+DSP1] == '3') dsplamp0 = 0x07;
   else                              dsplamp0 = 0x0;
   
    BefCurFloor=(P2 & 0xe0);
    BefCurFloor=(dsplamp0 | BefCurFloor);
    P2=BefCurFloor;

   BefCurFloor=RcvBuf[IdPt+DSP2] - '0';
   dsplamp1=seg0[BefCurFloor];
   if((dsplamp0==0) && (BefCurFloor==1)){
      dsplamp1=0x30;
   }
   else if(RcvBuf[IdPt+DSP2] == 'F'){
      dsplamp1=F_SEG;
   }

   if((RcvBuf[IdPt+3] & S3_PARKING)){
        dsplamp0 = 0x0;
        dsplamp1=P_SEG;
   }

   P0=dsplamp1;
#endif




    Open=0;

	if(bIamXSubDoor){
        if((RcvBuf[IdPt+3] & S3_OPEN_SUB))  Open=1;   
    }
    else{
        if(RcvBuf[IdPt+1] & S1_OPEN)        Open=1;   
    }    


   Close=0;
   if((RcvBuf[IdPt+1] & S1_CLOSE)){
      Close=1;   
   }


   CarMove=0;
   if(RcvBuf[IdPt+2] & S2_CAR_MOVE)         CarMove=1;



#ifdef	CPU65K80
#ifndef __TYPE_CAR      
   USER_LAMP3=0;
   if(RcvBuf[IdPt+4] & S4_HALLLANTERN_UP)        USER_LAMP3=1;

   USER_LAMP4=0;
   if(RcvBuf[IdPt+4] & S4_HALLLANTERN_DN)        USER_LAMP4=1;
#endif
#endif


   UpMove=0;
   if(RcvBuf[IdPt+1] & S1_UP)               UpMove=1;

   DnMove=0;
   if(RcvBuf[IdPt+2] & S2_DN)               DnMove=1;

   Vip=0;
   if((RcvBuf[IdPt+3] & S3_VIP))            Vip=1;

   Parking=0;
   if((RcvBuf[IdPt+3] & S3_PARKING))        Parking=1;

   ShiftOn=0;
   if((RcvBuf[IdPt+3] & S3_SHIFT))          ShiftOn=1;
   
   Fire=0;
   if(RcvBuf[IdPt+2] & S2_FIRE)             Fire=1;

   KeyClrExt=0;
   if(RcvBuf[IdPt+2] & S2_EXT_BUT_CLR)      KeyClrExt=1;

   KeyClr=0;
   if(RcvBuf[IdPt+2] & S2_CAR_BUT_CLR)      KeyClr=1;

   
	Emg=0;
   if(RcvBuf[IdPt+1] & S1_EMG)              Emg=1;


   StopBit=0;
   if(RcvBuf[IdPt+3] & S3_STOP)             StopBit=1;

	CurKey=0;
   if(RcvBuf[IdPt+3] & S3_CURKEY)           CurKey=1;
         
	Auto=0;
   if(RcvBuf[IdPt+1] & S1_AUTO)             Auto=1;

	OverLoad=0;
   if(RcvBuf[IdPt+1] & S1_OVERLOAD)         OverLoad=1;

	Full=0;
   	if(RcvBuf[IdPt+3] & S3_FULL)             Full=1;

	bErrorCar=0;
   	if(RcvBuf[IdPt + SL_mSysStatus] < 25)       bErrorCar=1;
	if( !Auto)									bErrorCar=1;


   AUTO_LAMP=0;
   if(RcvBuf[IdPt+2] & S2_LAMP_USER)        AUTO_LAMP=1;
   MANUAL_LAMP=0;
   if(RcvBuf[IdPt+1] & S1_MANUAL)           MANUAL_LAMP=1;


   if(RcvBuf[IdPt+3] & S3_FULL)             FULL_LAMP=1;
   else                                     FULL_LAMP=0;

   if(RcvBuf[IdPt+1] & S1_UP)               UP_LAMP=1;
   else                                     UP_LAMP=0;

   if(RcvBuf[IdPt+2] & S2_DN)               DN_LAMP=1;
   else                                     DN_LAMP=0;


    return(0);

}












