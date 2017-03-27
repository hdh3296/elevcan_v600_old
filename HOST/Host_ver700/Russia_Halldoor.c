
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





#ifdef	RUSSIA_HALL_DOOR_STOP	
unsigned char	HibHallDoorStatus[4];
unsigned char	RussiaErr=0;


/*
unsigned int  __attribute__((section(".usercode"))) Russia_HallDoor_Save_Check(void)
{
	if(NotRecoveryData & 0x10){
		bsHdsRunOff=1;
       	bBefbsHdsRunOff=1;
	}
	return(0);	
}
*/


/*
unsigned int  __attribute__((section(".usercode"))) Russia_HallDoor_Recovery_Check(void)
{
	if( !(NotRecoveryData & 0x10))	bsHdsRunOff=0;	

	return(0);
}


unsigned int  __attribute__((section(".usercode"))) Russia_HallDoor_Onece_Off_Stop(void)
{
	if( NotRecoveryData & 0x10){
		bsHdsRunOff=1;
       	bBefbsHdsRunOff=1;
		bCarErr=1;
		return(0);
	}

    if(!bHoleDoorCloseEnd && !IN_AUTO){
		if(HallDoorOpenTime > (unsigned int)(cF_SafetyTimeSec)){			
			NotRecoveryData = (NotRecoveryData | 0x10);
		}
	}	
	else{
		HallDoorOpenTime=0;
	}
	return(0);
}
*/


unsigned int  __attribute__((section(".usercode"))) RussiaTwoHallDoorOpenCheck(void)
{
	unsigned char flrBytePt,flrBitPt,flrCnt,valBit=0,OpenCnt=0;

	flrBytePt=0;
	OpenCnt=0;
	valBit=0x01;

	for(flrCnt=0;flrCnt <= cF_TOPFLR;flrCnt++){
		if( !(HibHallDoorStatus[flrBytePt] & valBit)){
			OpenCnt++;
	
			if(OpenCnt==1)		HallDoorOpenFloor[0]=(flrCnt + 1);	
			else if(OpenCnt==2)	HallDoorOpenFloor[1]=(flrCnt + 1);	

			if(OpenCnt >= 2)	return(2);	
		}

		if(valBit==0x80){
			valBit=0x01;
			flrBytePt=(flrBytePt+1);
		}
		else	valBit=(valBit << 1);
	}


	if(OpenCnt==1){
		HallDoorOpenFloor[1]=0;
		if(HallDoorOpenFloor[0] == (sRamDArry[mcurfloor]+1)){
			return(0);
		}
	}
	else if(OpenCnt==0){
		HallDoorOpenFloor[0]=0;
		HallDoorOpenFloor[1]=0;
	}

	return( (unsigned int)OpenCnt);
}


unsigned int  __attribute__((section(".usercode"))) Russia_HallDoor_Check(void)
{
	unsigned int DoorOpenCnt=0;


	if( (cF_SafetyTimeSec == 0) || IN_AUTO){	
		if(RussiaErr){
			bsHdsRunOff=0;
	       	bBefbsHdsRunOff=0;
		}
		HallDoorOpenTime=0;
		RussiaErr=0;
		return(0);
	}		
	else{
		if(RussiaErr){
			bsHdsRunOff=1;
	       	bBefbsHdsRunOff=1;
			bCarErr=1;
			HallDoorOpenTime=0;
			return(0);
		}


		DoorOpenCnt=RussiaTwoHallDoorOpenCheck();
		if(DoorOpenCnt==2){
			RussiaErr=1;
			HallDoorOpenTime=0;
		}
		else if(DoorOpenCnt==1){
			if(!bCarDoorCloseEnd)	HallDoorOpenTime=0;
		
			if(HallDoorOpenTime > (unsigned int)(cF_SafetyTimeSec)){			
				RussiaErr=1;
			}
		}
		else	HallDoorOpenTime=0;
	}
	return(0);
}


unsigned int  __attribute__((section(".usercode"))) Russia_Tmpdsp(void)
{			
	sRamDArry[230]=HibHallDoorStatus[0];
	sRamDArry[231]=HibHallDoorStatus[1];
	sRamDArry[232]=HibHallDoorStatus[2];
	sRamDArry[233]=HibHallDoorStatus[3];
}



unsigned int  __attribute__((section(".usercode"))) Russia_HallDoor_OnOff(unsigned char HallDoorfloor,unsigned char HallDoorOnOffCmd,unsigned char HallDoorOnOff)
{
	unsigned char flrBytePt,flrBitPt,valBit=0;

	if(HallDoorOnOffCmd == CAN_NO_KEY_SET){

		if(HallDoorfloor >= 64)	HallDoorfloor=(HallDoorfloor-64);


		flrBytePt=(HallDoorfloor/8);
		flrBitPt =(HallDoorfloor%8);
	
		valBit=(0x01 << flrBitPt);
	
		if(HallDoorOnOff & 0x20)	HibHallDoorStatus[flrBytePt]= (HibHallDoorStatus[flrBytePt] |  valBit);  // 1
		else						HibHallDoorStatus[flrBytePt]= (HibHallDoorStatus[flrBytePt] & ~valBit);  // 0
			

		Russia_Tmpdsp();
	}
}



unsigned int  __attribute__((section(".usercode"))) Russia_HallDoor_AllOn(void)
{			
	HibHallDoorStatus[0]=0xff;
	HibHallDoorStatus[1]=0xff;
	HibHallDoorStatus[2]=0xff;
	HibHallDoorStatus[3]=0xff;

	Russia_Tmpdsp();
}

#endif



