
#include <p30fxxxx.h>
      
#include  "30f6010_io.h"            
#include  "host_io.h"            
#include  "iodef.h"
#include  "door.h"
//#include  "eeprom.h"
#include  "com.h"
#include  "counter.h"
#include  "default_setup.h"




void __attribute__((section(".usercode")))    QEI_Init(void)
{

    ADPCFG=0xFFFF;

    UPDN_SRC=0;    //QEB
    TQCS    =0;    //internal
    POSRES  =0;    //index  no reset
    TQGATE  =0;
    PCDOUT  =0;
    SWPAB   =0;    
    QEISIDL =0;
    CNTERR  =0;

//    if(bitChk_FLRDSPCH(F_OnOff0,bEncoderPhase)) SWPAB   = 1;

    if(EncoderPhaseChk) SWPAB   = 1;
    else                SWPAB   = 0;

    QEICONbits.TQCKPS =0;
    QEICONbits.QEIM   =7;

    CEID  =1;                //disable 
    INDOUT=1;                //filter on
    QEOUT =1;
    DFLTCONbits.INDCK=7;
    DFLTCONbits.QECK =3;


    POSCNT = 0;

////////////////encoder////
///////////////////		if(cF_EncoderRate < 4)	MAXCNT =EncRate[cF_EncoderRate]; 
///////////////////////	else					MAXCNT =EncRate[1]; 
////////////////encoder////



    QEIIF  = 0;
    QEIIE  = 0;


////////////////encoder////
MAXCNT =0xffff; 
//////////////QEIIE  =0;
QEICONbits.QEIM   =6;

    DFLTCONbits.QECK =4;


BefCurEncoderPulse = 0;
////////////////encoder////

} 



void _ISR_X _QEIInterrupt(void)
{ 
    if(QEIIF){ 
      QEIIF=0;
    }
}



unsigned long 	TestEncoder=0,TestAvrEncoder=0;
unsigned int 	TestEncoderCnt=0;


unsigned int   __attribute__((section(".usercode")))  ReadEncoder(void)
{
	unsigned int rry;

	rry=0;

/*
	if(MaxEncoderPerMsec==0){
		MaxEncoderPerMsec=1000;
	}
*/

	if(BefCurEncoderPulse > 0xffff)	BefCurEncoderPulse=0;

 	TmpCurEncoderPulse=(unsigned long)POSCNT;	

	if( TmpCurEncoderPulse > BefCurEncoderPulse){
		BefCurEncoderPulse = (TmpCurEncoderPulse - BefCurEncoderPulse);
		TestAvrEncoder=BefCurEncoderPulse;
		if(BefCurEncoderPulse <= MaxEncoderPerMsec){
    		CurPulse=(CurPulse + BefCurEncoderPulse);
			rry=1;
		}	
		else{
			BefCurEncoderPulse = ((unsigned long)0x10000 - BefCurEncoderPulse);
			TestAvrEncoder=BefCurEncoderPulse;
			if(BefCurEncoderPulse <= MaxEncoderPerMsec){
		   		CurPulse=(CurPulse - BefCurEncoderPulse);
				rry=1;
			}
		}		
	}
	else if(TmpCurEncoderPulse < BefCurEncoderPulse){
		BefCurEncoderPulse = (BefCurEncoderPulse-TmpCurEncoderPulse);
		TestAvrEncoder=BefCurEncoderPulse;
		if(BefCurEncoderPulse <= MaxEncoderPerMsec){
    		CurPulse=(CurPulse - BefCurEncoderPulse);
			rry=1;
		}	
		else{
			BefCurEncoderPulse = ((unsigned long)0x10000 - BefCurEncoderPulse);
			TestAvrEncoder=BefCurEncoderPulse;
			if(BefCurEncoderPulse <= MaxEncoderPerMsec){
		   		CurPulse=(CurPulse + BefCurEncoderPulse);
				rry=1;
			}				
		}
	}
	else{
		TestAvrEncoder=0;
	}

	if(TestAvrEncoder > MaxEncoderPerMsec){
		TestEncoder = TestAvrEncoder;
		TestEncoderCnt++;
	}


	if(rry==1){
		CounterTime=0;
	}


	BefCurEncoderPulse=TmpCurEncoderPulse;

	if(CurPulse >= 0xfffff000)	CurPulse=BASE_PULSE;	
	if(CurPulse <= 50000)		CurPulse=BASE_PULSE;	

	return(0); 
}

