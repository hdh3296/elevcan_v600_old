


#include    <pic18.h>
#include        "..\..\system_com\memory_map.h"
#include        "iodef.h"
#include        "fontout.h"
#include        "comdata.h"
#include        "esdots.h"
#include        "keysort.h"
#include        "setup.h"


extern	bit	bDoorOpenWaitOn;



const   unsigned        char    OVL[]={

   0x00,0x00,
   0x3E,0x41,0x41,0x41,0x3E, // O  31
   0x00, 
   0x1F,0x20,0x40,0x20,0x1F, // V  38
   0x00,
   0x7F,0x49,0x49,0x49,0x41, // E  21
   0x00,
   0x7F,0x09,0x19,0x29,0x46, // R  30
   0x00,    
   0x7F,0x40,0x40,0x40,0x40, // L  28
   0x00,
   0x3E,0x41,0x41,0x41,0x3E, // O  31
   0x00, 
   0x7E,0x11,0x11,0x11,0x7E, // A  17
   0x00,   
   0x7F,0x41,0x41,0x22,0x1C, // D  20

   0x00,0x00,0x00 

};


const   unsigned        char    FULL[]={
   0x00,0x00,
   0x7F,0x09,0x09,0x09,0x01,  // F
   0x00,   
   0x3F,0x40,0x40,0x40,0x3F,  // U  37
   0x00,
   0x7F,0x40,0x40,0x40,0x40,  // L  28
   0x00,
   0x7F,0x40,0x40,0x40,0x40,  // L  28
   0x00,0x00,0x00 
};


const   unsigned        char    STOP1[]={
   0x00,0x00,
   0x46,0x49,0x49,0x49,0x31, // S  35
   0x00,   
   0x01,0x01,0x7F,0x01,0x01, // T  36
   0x00,
   0x3E,0x41,0x41,0x41,0x3E, // O  31
   0x00,
   0x7F,0x09,0x09,0x09,0x06, // P  32
   0x00,0x00,0x00 
};

const   unsigned        char    FIRE[]={
   0x00,0x00,
   0x7F,0x09,0x09,0x09,0x01,  //F
   0x00,   
   0x00,0x41,0x7F,0x41,0x00,  //I  25
   0x00,
   0x7F,0x09,0x19,0x29,0x46,  //R  30
   0x00,
   0x7F,0x49,0x49,0x49,0x41,  //E  21
   0x00,0x00,0x00 
};

const   unsigned        char    EMG[]={
   0x00,0x00,
   0x7F,0x49,0x49,0x49,0x41, // E  21
   0x00,   
   0x7F,0x02,0x0C,0x02,0x7F, // M  29
   0x00,
   0x3E,0x41,0x49,0x49,0x7A, // G  23
   0x00,    
   0x00,0x00,0x00,0x00,0x00,  // blanck  
   0x00,0x00,0xff 
};

const   unsigned        char    INS[]={
   0x00,0x00,
   0x00,0x41,0x7F,0x41,0x00,  // I  25
   0x00, 
   0x7F,0x04,0x08,0x10,0x7F,  // N  30
   0x00, 
   0x46,0x49,0x49,0x49,0x31,  // S  35
   0x00,    
   0x00,0x00,0x00,0x00,0x00,  // blanck  
   0x00,0x00,0x00 
};



const   unsigned        char    PARKING[]={
   0x00,0x00,
   0x7F,0x09,0x09,0x09,0x06,  // P  25
   0x00,   
   0x7E,0x11,0x11,0x11,0x7E,  // A  17
   0x00,   
   0x7F,0x09,0x19,0x29,0x46,  // R  30
   0x00,
   0x7F,0x08,0x14,0x22,0x41,  // K  35
   0x00, 
   0x00,0x41,0x7F,0x41,0x00,  // I  25
   0x00, 
   0x7F,0x04,0x08,0x10,0x7F,  // N  30
   0x00,    
   0x3E,0x41,0x49,0x49,0x7A,  // G  23
   0x00,    
   0x00,0x00,0x00,0x00,0x00,  // blanck  
   0x00,0x00,0x00 
};



unsigned        char    EMG_buf[]		={"EMG"};
unsigned        char    PARKING_buf[]	={"PARKING"};
unsigned        char    INS_buf[]		={"INS"};
unsigned        char    FIRE_buf[]		={"FIRE"};
unsigned        char    STOP1_buf[]		={"STOP"};
unsigned        char    FULL_buf[]		={"FULL"};
unsigned        char    OVL_buf[]		={"OVERLOAD"};
unsigned        char    ETC_ERR_buf[]	={"E"};


extern	void Dsp_Char_load(unsigned char Cdata,unsigned char *ptx);
extern	unsigned char VirCarKeySet(unsigned char virkey);




unsigned    char  MaxHighButton;
unsigned    char  MaxLowButton;
unsigned    char  MaxLongFlr;
unsigned    char  MaxButton;



unsigned    char  DspFlr[3];
unsigned    char  xDspCharBuf[100];
unsigned    char  ThisStstus,BefStstus=0xff,shiftpt;

unsigned    char  befDspChar[2];

bit	bErrorCar; 
bit	bNew_Law=0;


#if defined(__TYPE_DIRECT_BCD)

void out_lcdDisplay(unsigned char id)
{
	unsigned int    IdPt;

	IdPt=IsBufferPt(id);
	/*--> 1(HIGH)값을 주면 출력 접점은 출력을준다. 출력값은 0V이다. <--*/
	if ((RcvBuf[IdPt+DSP1] == '0') && (RcvBuf[IdPt+DSP2] == 'G'))
	{
		BCD1_LAMP=0;
		BCD2_LAMP=1; 
		BCD3_LAMP=0;
		BCD4_LAMP=0;
		BCD5_LAMP=1;
	}
	else if ((RcvBuf[IdPt+DSP1] == '0') && (RcvBuf[IdPt+DSP2] == 'L'))
	{
		BCD1_LAMP=1;
		BCD2_LAMP=0;
		BCD3_LAMP=0;
		BCD4_LAMP=0;
		BCD5_LAMP=1;
	}
	else if ((RcvBuf[IdPt+DSP1] == '0') && (RcvBuf[IdPt+DSP2] == 'M'))
	{
		BCD1_LAMP=0;
		BCD2_LAMP=0;
		BCD3_LAMP=0;
		BCD4_LAMP=0;
		BCD5_LAMP=1;
	}
	else if ((RcvBuf[IdPt+DSP1] == '0') && (RcvBuf[IdPt+DSP2] == 'B'))
	{
		BCD1_LAMP=1;
		BCD2_LAMP=1;
		BCD3_LAMP=0;
		BCD4_LAMP=0;
		BCD5_LAMP=1;
	}
	else if((RcvBuf[IdPt+DSP1] == 'B') && (RcvBuf[IdPt+DSP2] == '1'))
	{
		BCD1_LAMP=1;
		BCD2_LAMP=1;
		BCD3_LAMP=0;
		BCD4_LAMP=0;
		BCD5_LAMP=1;
	}
	else if (RcvBuf[IdPt+DSP1] == '0')
	{
		if (RcvBuf[IdPt+DSP2] == '0')
		{
			// 이런 경우는 없음 .
		}		
		else if (RcvBuf[IdPt+DSP2] == '1')
		{
			BCD1_LAMP=0; // M0
				BCD2_LAMP=0; // M1
				BCD3_LAMP=0; // M2
				BCD4_LAMP=0; // M3
				BCD5_LAMP=0; // M4
		}
		else if (RcvBuf[IdPt+DSP2] == '2')
		{
			BCD1_LAMP=1;
				BCD2_LAMP=0;
				BCD3_LAMP=0;
				BCD4_LAMP=0;
				BCD5_LAMP=0;
		}
		else if (RcvBuf[IdPt+DSP2] == '3')
		{
			BCD1_LAMP=1;
				BCD2_LAMP=1;
				BCD3_LAMP=0;
				BCD4_LAMP=0;
				BCD5_LAMP=0;
		}
		else if (RcvBuf[IdPt+DSP2] == '4')
		{
			BCD1_LAMP=0;
				BCD2_LAMP=1;
				BCD3_LAMP=0;
				BCD4_LAMP=0;
				BCD5_LAMP=0;
		}
		else if (RcvBuf[IdPt+DSP2] == '5')
		{
			BCD1_LAMP=0;
				BCD2_LAMP=1;
				BCD3_LAMP=1;
				BCD4_LAMP=0;
				BCD5_LAMP=0;
		}
		else if (RcvBuf[IdPt+DSP2] == '6')
		{
			BCD1_LAMP=1;
				BCD2_LAMP=1;
				BCD3_LAMP=1;
				BCD4_LAMP=0;
				BCD5_LAMP=0;
		}
		else if (RcvBuf[IdPt+DSP2] == '7')
		{
			BCD1_LAMP=1;
				BCD2_LAMP=0;
				BCD3_LAMP=1;
				BCD4_LAMP=0;
				BCD5_LAMP=0;
		}
		else if (RcvBuf[IdPt+DSP2] == '8')
		{
			BCD1_LAMP=0;
				BCD2_LAMP=0;
				BCD3_LAMP=1;
				BCD4_LAMP=0;
				BCD5_LAMP=0;
		}
		else if (RcvBuf[IdPt+DSP2] == '9')
		{
			BCD1_LAMP=0;
				BCD2_LAMP=0;
				BCD3_LAMP=1;
				BCD4_LAMP=1;
				BCD5_LAMP=0;
		}
	}
	else if (RcvBuf[IdPt+DSP1] == '1')
	{
		if (RcvBuf[IdPt+DSP2] == '0')
		{
			BCD1_LAMP=1;
				BCD2_LAMP=0;
				BCD3_LAMP=1;
				BCD4_LAMP=1;
				BCD5_LAMP=0;
			
		}		
		else if (RcvBuf[IdPt+DSP2] == '1')
		{
			BCD1_LAMP=1;
				BCD2_LAMP=1;
				BCD3_LAMP=1;
				BCD4_LAMP=1;
				BCD5_LAMP=0;
		}
		else if (RcvBuf[IdPt+DSP2] == '2')
		{
			BCD1_LAMP=0;
				BCD2_LAMP=1;
				BCD3_LAMP=1;
				BCD4_LAMP=1;
				BCD5_LAMP=0;
		}
		else if (RcvBuf[IdPt+DSP2] == '3')
		{
			BCD1_LAMP=0;
				BCD2_LAMP=1;
				BCD3_LAMP=0;
				BCD4_LAMP=1;
				BCD5_LAMP=0;
		}
		else if (RcvBuf[IdPt+DSP2] == '4')
		{
			BCD1_LAMP=1;
				BCD2_LAMP=1;
				BCD3_LAMP=0;
				BCD4_LAMP=1;
				BCD5_LAMP=0;
		}
		else if (RcvBuf[IdPt+DSP2] == '5')
		{
			BCD1_LAMP=1;
				BCD2_LAMP=0;
				BCD3_LAMP=0;
				BCD4_LAMP=1;
				BCD5_LAMP=0;
		}
		else if (RcvBuf[IdPt+DSP2] == '6')
		{
			BCD1_LAMP=0;
				BCD2_LAMP=0;
				BCD3_LAMP=0;
				BCD4_LAMP=1;
				BCD5_LAMP=0;
		}
		else if (RcvBuf[IdPt+DSP2] == '7')
		{
			BCD1_LAMP=0;
				BCD2_LAMP=0;
				BCD3_LAMP=0;
				BCD4_LAMP=1;
				BCD5_LAMP=1;
		}
		else if (RcvBuf[IdPt+DSP2] == '8')
		{
			BCD1_LAMP=1;
				BCD2_LAMP=0;
				BCD3_LAMP=0;
				BCD4_LAMP=1;
				BCD5_LAMP=1;
		}
		else if (RcvBuf[IdPt+DSP2] == '9')
		{
			BCD1_LAMP=1;
				BCD2_LAMP=1;
				BCD3_LAMP=0;
				BCD4_LAMP=1;
				BCD5_LAMP=1;
		}
	}
	else if (RcvBuf[IdPt+DSP1] == '2')
	{
		if (RcvBuf[IdPt+DSP2] == '0')
		{
			BCD1_LAMP=0;
				BCD2_LAMP=1;
				BCD3_LAMP=0;
				BCD4_LAMP=1;
				BCD5_LAMP=1;
			
		}		
		else if (RcvBuf[IdPt+DSP2] == '1')
		{
			BCD1_LAMP=0;
				BCD2_LAMP=1;
				BCD3_LAMP=1;
				BCD4_LAMP=1;
				BCD5_LAMP=1;
		}
		else if (RcvBuf[IdPt+DSP2] == '2')
		{
			BCD1_LAMP=1;
				BCD2_LAMP=1;
				BCD3_LAMP=1;
				BCD4_LAMP=1;
				BCD5_LAMP=1;
		}
		else if (RcvBuf[IdPt+DSP2] == '3')
		{
			BCD1_LAMP=1;
				BCD2_LAMP=0;
				BCD3_LAMP=1;
				BCD4_LAMP=1;
				BCD5_LAMP=1;
		}
		else if (RcvBuf[IdPt+DSP2] == '4')
		{
			BCD1_LAMP=0;
				BCD2_LAMP=0;
				BCD3_LAMP=1;
				BCD4_LAMP=1;
				BCD5_LAMP=1;
		}
		else if (RcvBuf[IdPt+DSP2] == '5')
		{
			BCD1_LAMP=0;
				BCD2_LAMP=0;
				BCD3_LAMP=1;
				BCD4_LAMP=0;
				BCD5_LAMP=1;
		}
		else if (RcvBuf[IdPt+DSP2] == '6')
		{
			BCD1_LAMP=1;
				BCD2_LAMP=0;
				BCD3_LAMP=1;
				BCD4_LAMP=0;
				BCD5_LAMP=1;
		}
		else if (RcvBuf[IdPt+DSP2] == '7')
		{
			BCD1_LAMP=1;
				BCD2_LAMP=1;
				BCD3_LAMP=0;
				BCD4_LAMP=1;
				BCD5_LAMP=1;
		}
		else if (RcvBuf[IdPt+DSP2] == '8')
		{
			BCD1_LAMP=0;
				BCD2_LAMP=1;
				BCD3_LAMP=1;
				BCD4_LAMP=0;
				BCD5_LAMP=1;
		}
	}	
	
	
	
		//Segment not dispaly			
		SEG_F=Fire; 		 
		SEG_G1=OverLoad;		 
		SEG_G2=1; // 24V 전원 공급 용.(n24) 
		/*---> FULL 은 기본적으로  FULL 접점에서 출력 나온다. <---*/ 

}


void out_1_1_flr(unsigned char id)
{
	unsigned int    IdPt;

	IdPt=IsBufferPt(id);


	switch(RcvBuf[IdPt])
	{
		case	1:
			BCD1_LAMP=1;
			BCD2_LAMP=0;
			BCD3_LAMP=0;
			BCD4_LAMP=0;
			BCD5_LAMP=0;
			BCD6_LAMP=0;
			BCD7_LAMP=0;
			BCD8_LAMP=0;			
			break;
		case	2:
			BCD1_LAMP=0;
			BCD2_LAMP=1;
			BCD3_LAMP=0;
			BCD4_LAMP=0;
			BCD5_LAMP=0;
			BCD6_LAMP=0;
			BCD7_LAMP=0;
			BCD8_LAMP=0;
			break;
		case	3:
			BCD1_LAMP=0;
			BCD2_LAMP=0;
			BCD3_LAMP=1;
			BCD4_LAMP=0;
			BCD5_LAMP=0;
			BCD6_LAMP=0;
			BCD7_LAMP=0;
			BCD8_LAMP=0;

			break;
		case	4:
			BCD1_LAMP=0;
			BCD2_LAMP=0;
			BCD3_LAMP=0;
			BCD4_LAMP=1;
			BCD5_LAMP=0;
			BCD6_LAMP=0;
			BCD7_LAMP=0;
			BCD8_LAMP=0;
			break;
		case	5:
			BCD1_LAMP=0;
			BCD2_LAMP=0;
			BCD3_LAMP=0;
			BCD4_LAMP=0;
			BCD5_LAMP=1;
			BCD6_LAMP=0;
			BCD7_LAMP=0;
			BCD8_LAMP=0;
			break;
		case	6:
			BCD1_LAMP=0;
			BCD2_LAMP=0;
			BCD3_LAMP=0;
			BCD4_LAMP=0;
			BCD5_LAMP=0;
			BCD6_LAMP=1;
			BCD7_LAMP=0;
			BCD8_LAMP=0;
			break;
		case	7:
			BCD1_LAMP=0;
			BCD2_LAMP=0;
			BCD3_LAMP=0;
			BCD4_LAMP=0;
			BCD5_LAMP=0;
			BCD6_LAMP=0;
			BCD7_LAMP=1;
			BCD8_LAMP=0;
			break;
		case	8:
			BCD1_LAMP=0;
			BCD2_LAMP=0;
			BCD3_LAMP=0;
			BCD4_LAMP=0;
			BCD5_LAMP=0;
			BCD6_LAMP=0;
			BCD7_LAMP=0;
			BCD8_LAMP=1;
			break;
	}

}

#endif

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
    unsigned char   virkey;


#ifdef	__COUNT_CAR
    unsigned char   f_dsp,s_dsp;
#endif
   
//    IdPt=(id * HOST_DATA_RECOD) + RCV_DATA;
	IdPt=IsBufferPt(id);
    
    FDsp=0;

//    HostCallMe=0;
    if(CallMeAdr == RcvBuf[IdPt + SL_mCallMe]){
 	 	HostCallMe=1;
	}


	ThisStstus = RcvBuf[IdPt + SL_mSysStatus];
	DspFlr[0]=RcvBuf[IdPt+DSP1];
	DspFlr[1]=RcvBuf[IdPt+DSP2];
	DspFlr[2]=0;







/*
    if((RcvBuf[IdPt+DSP1] == 'J') && (RcvBuf[IdPt+DSP2] == 'D') && !(RcvBuf[IdPt+1] & S1_AUTO))	SetupBit=1;
    else                                                                                        SetupBit=0;      

    if(SetupBit)    return(0);
*/

    TopFloor=RcvBuf[IdPt + SL_mTopFlr];

    CurFloor=RcvBuf[IdPt];

    MaxLongFlr=RcvBuf[IdPt + SL_mMostLongDst];

#ifdef	CARD_KEY
	if((RcvBuf[IdPt + 35] & 0x08))		bCardKeyValid=0;
	else									bCardKeyValid=1;
#endif


#if  defined(__TYPE_HIB_HPI)   ||  defined(__TYPE_ES15)
	if(RcvBuf[IdPt+SL_mCrtExtMoveFlr] & UP_READY){
		if((RcvBuf[IdPt+SL_mCrtExtMoveFlr] & (~UPDN_READY)) == MyAddress){
			if( !UP_KEY_LAMP){
				UpKeyBit=1;
				UpButtonTime=10;
			}
		}
	}

	if(RcvBuf[IdPt+SL_mCrtExtMoveFlr] & DN_READY){
		if((RcvBuf[IdPt+SL_mCrtExtMoveFlr] & (~UPDN_READY)) == MyAddress){
			if( !DN_KEY_LAMP){
				DnKeyBit=1;
				DnButtonTime=10;
			}
		}
	}
#elif defined(__TYPE_CAR)
	if(RcvBuf[IdPt+SL_mCrtExtMoveFlr]>0){
		virkey=(RcvBuf[IdPt+SL_mCrtExtMoveFlr] & ONLY_FLR);
		if( (virkey==0) && (RcvBuf[IdPt+SL_mCrtExtMoveFlr] & DN_READY) ){
			virkey=64;	
			VirCarKeySet(virkey);	
		}
		else if( !(RcvBuf[IdPt+SL_mCrtExtMoveFlr] & UPDN_READY)){ 
			VirCarKeySet(virkey);				
		}
	}
#endif

 
////////////////dot type dsp hib,hpi////////////////////////////////////////////
#if defined(__DSP_DOT)

    if((RcvBuf[IdPt+DSP1]!= befDspChar[0]) || (RcvBuf[IdPt+DSP2] != befDspChar[1])){
        FloorChange=1;   
        BefCurFloor=CurFloor;
		BefStstus=0xff;
		shift=0;

		befDspChar[0]=RcvBuf[IdPt+DSP1];
		befDspChar[1]=RcvBuf[IdPt+DSP2];



	    if( (RcvBuf[IdPt+DSP1] == ' ') && (RcvBuf[IdPt+DSP2] == ' ')){
			RcvBuf[IdPt+DSP1] = 0x3d;
			RcvBuf[IdPt+DSP2] = 0x3d;
	    }	
	    else if( (RcvBuf[IdPt+DSP1] < '0') || (RcvBuf[IdPt+DSP1] > 'Z')){
			RcvBuf[IdPt+DSP1] = 0x30;
			RcvBuf[IdPt+DSP2] = 0x30;
	    }
	    else if( (RcvBuf[IdPt+DSP2] < '0') || (RcvBuf[IdPt+DSP2] > 'Z')){
			RcvBuf[IdPt+DSP1] = 0x30;
			RcvBuf[IdPt+DSP2] = 0x30;
	    }
	}

    Floor_Char_load(0,RcvBuf[IdPt+DSP1],RcvBuf[IdPt+DSP2]);



#ifdef	__COUNT_CAR
	f_dsp=RcvBuf[MyAddress-1];
	s_dsp=(f_dsp % 10) + '0';
	f_dsp=(f_dsp / 10) + '0';
    Floor_Char_load(0,f_dsp,s_dsp);
#endif
////////////////dot type es15////////////////////////////////////////////
#elif defined(__TYPE_ES15)



#if defined(__TYPE_DIRECT_BCD)

	out_lcdDisplay(id); // 만일, LCD 용이면 이 함수를 사요하세요. 
	//out_1_1_flr(id);
		


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


	if( (RcvBuf[IdPt+DSP1] == ' ') && (RcvBuf[IdPt+DSP2] == ' ')){
      dsplamp1=0;
	} 

   P0=dsplamp1;





/*
	switch(RcvBuf[IdPt])
	{
		case	1:
			dsplamp1=0x01;
			break;
		case	2:
			dsplamp1=0x02;
			break;
		case	3:
			dsplamp1=0x04;
			break;
		case	4:
			dsplamp1=0x08;
			break;
		case	5:
			dsplamp1=0x10;
			break;
		case	6:
			dsplamp1=0x20;
			break;
		case	7:
			dsplamp1=0x40;
			break;
	}	
*/




/*
	dsplamp1=RcvBuf[IdPt];


   	if((RcvBuf[IdPt+2] & S2_FIRE))          dsplamp1=(dsplamp1 | 0x20);
   	if((RcvBuf[IdPt+3] & S3_PARKING))       dsplamp1=(dsplamp1 | 0x40);
   	if((RcvBuf[IdPt+3] & S3_SHIFT))         dsplamp1=(dsplamp1 | 0x80);
	P0=dsplamp1;


	dsplamp0 = 0x0;

	if((RcvBuf[IdPt+3] 	& S3_PARKING))      dsplamp0=(dsplamp0 | 0x10); //parking
	if(RcvBuf[IdPt+3] 	& S3_STOP)          dsplamp0=(dsplamp0 | 0x02); //water
	if(RcvBuf[IdPt + 24] & 0x20)      		dsplamp0=(dsplamp0 | 0x04); //error  


    if((RcvBuf[IdPt+3] & S3_OPEN_SUB) && (RcvBuf[IdPt+2] 	& S2_FIRE))	dsplamp0=(dsplamp0 | 0x01); //fire      
    if((RcvBuf[IdPt+1] & S1_OPEN)     && (RcvBuf[IdPt+2] 	& S2_FIRE))	dsplamp0=(dsplamp0 | 0x01); //fire      


    BefCurFloor=(P2 & 0xe0);
    BefCurFloor=(dsplamp0 | BefCurFloor);
    P2=BefCurFloor;
*/

#endif

//	if(RcvBuf[IdPt + 24] & 0x20)      		FULL_LAMP=1; //error
//	else									FULL_LAMP=0;					  

   if(RcvBuf[IdPt+3] & S3_FULL)             FULL_LAMP=1;
   else                                     FULL_LAMP=0;

   if(RcvBuf[IdPt+1] & S1_UP)               UP_LAMP=1;
   else                                     UP_LAMP=0;

   if(RcvBuf[IdPt+2] & S2_DN)               DN_LAMP=1;
   else                                     DN_LAMP=0;

#else
    #error Not Select Board Dsplay Type -- error
#endif



#ifndef	__COUNT_CAR

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

/*
   StopBit=0;
   if((RcvBuf[IdPt+3] & S3_STOP)&& (bDoorOpenWaitOn))             StopBit=1;
*/

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

	bNew_Law=0;
	if(RcvBuf[IdPt+4] & S4_NEW_LAW_SYSTEM)        bNew_Law=1;


#ifdef __TYPE_CAR


   AUTO_LAMP=OverLoad;
//   if(RcvBuf[IdPt+2] & S2_LAMP_USER)        AUTO_LAMP=1;


//   AUTO_LAMP=0;
//   if(RcvBuf[IdPt+2] & S2_LAMP_USER)        AUTO_LAMP=1;

   MANUAL_LAMP=0;
   if(RcvBuf[IdPt+1] & S1_MANUAL)           MANUAL_LAMP=1;


/*
	if(bErrorCar){
   		AUTO_LAMP=1;
   		MANUAL_LAMP=1;
	}
	else{
   		AUTO_LAMP=0;
   		MANUAL_LAMP=0;
	}
*/


	
#else
   AUTO_LAMP=0;
   if(RcvBuf[IdPt+2] & S2_LAMP_USER)        AUTO_LAMP=1;
   MANUAL_LAMP=0;
   if(RcvBuf[IdPt+1] & S1_MANUAL)           MANUAL_LAMP=1;
   
#endif	


#else
    Open=0;
    Close=1;   
	CarMove=0;
	AUTO_LAMP=0;
   	MANUAL_LAMP=0;
  	UpMove=0;
   	DnMove=0;
	Vip=0;
   	Parking=0;
   	ShiftOn=0;   
   	Fire=0;
   	KeyClrExt=0;
   	KeyClr=0;   
	Emg=0;
   	StopBit=0;
	CurKey=0;         
	Auto=1;
	OverLoad=0;
	Full=0;
#endif


#if defined(__TYPE_CAR)
   OpenLampSet=0;
   if(RcvBuf[IdPt+2] & S2_OPEN_LAMP_ON)      OpenLampSet=1;
#endif

    return(0);

}



unsigned char  LoadMessage(unsigned char *pt,unsigned char bufpt)
{
	unsigned char i;

	for(i=0;*(pt+i);i++){
		Dsp_Char_load(*(pt+i),&xDspCharBuf[bufpt]);
		xDspCharBuf[bufpt+5]=0x0;
		bufpt=bufpt+6;
	}
	xDspCharBuf[bufpt+0]=0x0;
	xDspCharBuf[bufpt+1]=0x0;
	xDspCharBuf[bufpt+2]=0x0;
	xDspCharBuf[bufpt+3]=0xff;
	shiftpt=bufpt+2;
	return(shiftpt);
}




void  ArrowUpDown(void)
{
   	unsigned char  i,j,k;

   if(!ShiftOn){
      for(i=11;i<=15;i++){
         shiftDataBuf[i]=DspBuf[i];
      }              
      Arrowshift=0; 
   }
   
   else{
      if(UpMove || DnMove){
         Arrowshift=(Arrowshift + 1)%11;
         if(Arrowshift<8){
            k=(7 - Arrowshift);
            for(i=11;i<=15;i++){
				if(UpMove)	j=(DspBuf[i] << k);
				else 		j=(DspBuf[i] >> k);
               shiftDataBuf[i]=j;           
            }
         }
      }         
      else{
         for(i=11;i<=15;i++){
            shiftDataBuf[i]=DspBuf[i];
         }              
         Arrowshift=0;
      }             
   }
}





void  ShiftData(void)
{


   unsigned char  i;

#ifndef	__COUNT_CAR
   unsigned char  j,k,l;
  

   if(Fire || StopBit || Full || Emg || !Auto || OverLoad || Parking || bErrorCar){
      	shift=(shift+1)%shiftpt; 
		j=shift;           
      	for(i=0;i<=10;i++){
			if(BefStstus != ThisStstus){
				BefStstus = ThisStstus;
				LoadMessage( &DspFlr[0],0);

				if(Emg)				LoadMessage( &EMG_buf[0],14);				
				else if(StopBit)	LoadMessage( &STOP1_buf[0],14);
				else if(!Auto)		LoadMessage( &INS_buf[0],14);
				else if(Parking)	LoadMessage( &PARKING_buf[0],14);
				else if(Fire)		LoadMessage( &FIRE_buf[0],14);
				else if(Full)		LoadMessage( &FULL_buf[0],14);
				else if(OverLoad)	LoadMessage( &OVL_buf[0],14);
			}

			shiftDataBuf[i]=xDspCharBuf[j];
			if( j >= shiftpt)	j=0;
			else				j++;
		}
      	ManualToggle=1;
	}


	else{
      if(ManualToggle){
         FloorChange=0;
         shift=0;
         for(i=0;i<=10;i++){
            shiftDataBuf[i]=DspBuf[i];
         }
         ManualToggle=0;                  
      }
      
      if(FloorChange){
         if(!ShiftOn){
            FloorChange=0;
            shift=0;
            for(i=0;i<=10;i++){
               shiftDataBuf[i]=DspBuf[i];
            }            
         }      

         else if(UpMove || DnMove){
            shift=(shift + 1)%9;
            for(i=0;i<=10;i++){
				if(UpMove){
					shiftDataBuf[i]=(shiftDataBuf[i] >> 1);
	               j=(DspBuf[i] << (8 - shift));
				}
				else{
					shiftDataBuf[i]=(shiftDataBuf[i] << 1);
	               j=(DspBuf[i] >> (8 - shift));
				}

           		shiftDataBuf[i]=(shiftDataBuf[i] | j);
            
               	if(shift==8)   FloorChange=0;
            }         
         }         
         else{
            FloorChange=0;
            shift=0;
            for(i=0;i<=10;i++){
               shiftDataBuf[i]=DspBuf[i];
            }            
         }      
      }
   }                     

#else
	for(i=0;i<=10;i++){
	   shiftDataBuf[i]=DspBuf[i];
	}            
#endif

   ArrowUpDown();

}

