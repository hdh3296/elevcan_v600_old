

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





unsigned long 	MinimumFloorPulse=0;

unsigned long 	xVarMotorType=0;


unsigned long 	xVarDecTime,xVarSCurve;
unsigned long 	xVarCurMpm,xVarRpm,xVarEncoder,xVarMpm,xVarMpm1000,xVarMaxHz,xDecMpm;
unsigned long 	Length1,Length2;
unsigned long 	EVManualSpd,EVLowSpd,EVMidSpd,EVHighSpd,CurSpdDecPulse,EVLowDecLength,EVMidDecLength,EVHighDecLength,EVDecLength;
unsigned long 	TMaxMpm,TCurMpm,TLastMpm,TVarDecTime,TVarSCurve,TVarLengthVal1,TVarLengthVal2;
unsigned long 	CMaxMpm   ,CCurMpm   ,CLastMpm   ,CVarDecTime  ,CVarSCurve   ,CVarLengthVal1 ,CVarLengthVal2;


#ifdef	AUTO_LANDING_COMM	



unsigned int __attribute__((section(".usercode")))  CurDecPulseCalcu(void)
{
//	MaxMpm
//  xCurMpm
//  xVarDecTime
//  xVarSCurve

	TMaxMpm=GET_LONG(NEW_MPM);
	TVarDecTime=GET_LONG(BASE_DEC_TIME);
	TVarSCurve=GET_LONG(BASE_SCURVE_TIME);
	TLastMpm=GET_LONG(BASE_DEC_MPM);

	TMaxMpm=(TMaxMpm * 100);  //newmpm 180000
//	TMaxMpm=(TMaxMpm * 1000);  //180000
	if(TMaxMpm==0)	return(0);

	TMaxMpm=(TMaxMpm/60);										// max mpm  ==> mps  //3000
	TLastMpm=(TLastMpm/60);										// last mpm ==> mps  ////60

	TCurMpm=(xVarCurMpm/60);

	if(TCurMpm > TMaxMpm){
		TCurMpm=TMaxMpm;   
	}
		

	TVarLengthVal1=(TCurMpm + TLastMpm)/2;                      	//1530
 	TVarLengthVal2=(TCurMpm - TLastMpm) * TVarDecTime;  			//11760000
 	TVarLengthVal2=(TVarLengthVal2/TMaxMpm);                     	//3920
 	TVarLengthVal2=(TVarLengthVal2 + TVarSCurve);					//4920
    TVarLengthVal1=(TVarLengthVal1 * TVarLengthVal2);              //
	CurSpdDecPulse=(TVarLengthVal1/1000);	            		// dec length

	return(0);
}




unsigned int __attribute__((section(".usercode")))  RunCurDecPulseCalcu(void)
{
//	MaxMpm
//  xCurMpm
//  xVarDecTime
//  xVarSCurve

//////////////////////////////////
/////////////////////////	


	CMaxMpm=GET_LONG(NEW_MPM);
	if(CMaxMpm==0)	return(0);


	CVarDecTime=GET_LONG(BASE_DEC_TIME);
	CVarSCurve=GET_LONG(BASE_SCURVE_TIME);
	CLastMpm=GET_LONG(BASE_DEC_MPM);

	CMaxMpm=(CMaxMpm * 100);   // new 180000
//	CMaxMpm=(CMaxMpm * 1000);  //180000

	CMaxMpm=(CMaxMpm/60);										// max mpm  ==> mps  //3000
	CLastMpm=(CLastMpm/60);										// last mpm ==> mps  //60

	CCurMpm=(CurMpm_100/60);

	if(CCurMpm > CMaxMpm){
		CCurMpm=CMaxMpm;   
	}
		
	CVarLengthVal1=(CCurMpm + CLastMpm)/2;                      	//1530
 	CVarLengthVal2=(CCurMpm - CLastMpm) * CVarDecTime;  			//11760000
 	CVarLengthVal2=(CVarLengthVal2/CMaxMpm);                     	//3920
 	CVarLengthVal2=(CVarLengthVal2 + CVarSCurve);					//4920
    CVarLengthVal1=(CVarLengthVal1 * CVarLengthVal2);              	//
	CurSpdDecPulse=CVarLengthVal1;	            					// dec length

	return(0);
}


unsigned int __attribute__((section(".usercode")))  RunningDecPulseCalcu(void)
{
	if(PerfectAuto()){
		if(!bUnd && bMoveCar){
			if(CurMeterPerMin > 200){		//20.0	
				RunCurDecPulseCalcu();
				CVarLengthVal1=GET_LONG(MM_PULSE);
				CVarLengthVal2=(CurSpdDecPulse * 10);
				CVarLengthVal1=(CVarLengthVal2/CVarLengthVal1);
				DecreasePulse=(CVarLengthVal1 + xBefLuLdPulse);
			}
			else{
				DecreasePulse=0;
			}
		}
	}
}


#endif

