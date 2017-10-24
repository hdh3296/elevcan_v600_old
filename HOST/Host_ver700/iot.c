

#include <p30fxxxx.h>

#include  "..\..\system_com\memory_map.h"
#include  "30f6010_io.h"            
#include  "host_io.h"            
#include  "iodef.h"
#include  "door.h"
#include  "com.h"
#include  "counter.h"
#include  "you_can1.h" 
#include  "you_can2.h" 
#include  "lader.h" 
#include  "default_setup.h" 
#include  "Host_NewProtocol.h" 
#include  "Host_Autolanding.h" 



unsigned int	DoorCloseCnt=0;
unsigned int	DoorOnceOpenTime;

unsigned int   __attribute__((section(".usercode"))) ManCarInCheck(void)
{
	if(sRamDArry[mCarKey1] || sRamDArry[mCarKey9] ||sRamDArry[mCarKey17] ||sRamDArry[mCarKey25]){
		if(!bManOnCar){
			bManOnCar=1;
			DoorOnceOpenTime=0;
		}
	}

	if( !OneDoorSenserCloseChk()){
		bManOnCar=0;	
		DoorOnceOpenTime=0;
		STATE0_MAN_INCAR1=0;
	}	

	if(bManOnCar &&	(DoorOnceOpenTime > 300)){		// 30 sec
		STATE0_MAN_INCAR1=1;
	}

	return(0);
}                                                                     



unsigned int   __attribute__((section(".usercode"))) NoLevelZoneStopCheck(void)
{
	if(!IN_AUTO){
		if( !bMoveCar && !bOneLuOrLd){
			STATE0_INVALIDSTOP1=1;
		}

    	if( (sRamDArry[mDoorSeq] == DOOR_OPEN_WAIT) && PerfectAuto()){
			if(OneDoorSenserCloseChk()){
				STATE0_DOOR_OP_ERR1=1;
			}
		}

		if(DoorCloseCnt >= 3){
			STATE0_DOOR_CL_ERR1=1;
		}

	}



	if(bOneLuOrLd){
		STATE0_INVALIDSTOP1=0;
	}

	if(!OneDoorSenserCloseChk()){
		STATE0_DOOR_OP_ERR1=0;
	}

	if(DoorCloseCnt == 0){
		STATE0_DOOR_CL_ERR1=0;
	}


	return(0);
}                                                                     
