


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




unsigned int  __attribute__((section(".usercode")))    UpMnanuSpeedToDecSpeed(void)
{
	if(!IN_SU1)												return(1);
	else if(bFhmRun && (sRamDArry[FHM_SEQ]== FHM_SEQ_3))	return(1);     
	else if(bSearchHome){
		if(sRamDArry[mcurfloor] == cF_TOPFLR)	return(0);
		else									return(1);			
	}
	return(0);
}

unsigned int  __attribute__((section(".usercode")))    DnMnanuSpeedToDecSpeed(void)
{
	if(!IN_SD1)									return(1);
	else if(bSearchHome){
		if(sRamDArry[mcurfloor] == 0)			return(0);
		else									return(1);			
	}
	return(0);
}


void  __attribute__((section(".usercode")))    Mnanual_Speed_Sel(void)
{
       
    ManualSpeedCmd_IO();

    if(S1_POWER_FAIL && (cF_BATTERYSPEED > 0)){
 		BatterySpeedCmd_IO();
	}
                  				

    if(bCarUpMove){
        if(!IN_LU || !IN_LD ){
			if(UpMnanuSpeedToDecSpeed()){	
                DecreaseSpeedCmd_IO();
            }
        } 
    }
    else if(bCarDnMove){
        if(!IN_LU || !IN_LD){
			if(DnMnanuSpeedToDecSpeed()){	
                DecreaseSpeedCmd_IO();
            }
        }
    }
}




/*
void  __attribute__((section(".usercode"))) DefaultEncoderRpmMpm(void)
{
	if(New_Spd_SystemChk())		DefaultEncoderRpmMpm_spd3();
}



void  __attribute__((section(".usercode"))) CaluDecreasePulse(void)
{
	if(New_Spd_SystemChk())		CaluDecreasePulse_spd3();
}



unsigned int    __attribute__((section(".usercode"))) SpeedSet(void)
{
	#ifdef	DELTA_INVERTER_AUTOLANDING_CAN
		return(0);
	#else
		if(New_Spd_SystemChk())		return(SpeedSet_spd3());
	#endif
	
}



void __attribute__((section(".usercode")))    RunSpeedCmd_IO(void)
{
	#ifdef	DELTA_INVERTER_AUTOLANDING_CAN
		CurSpeed=SPEED_HIGH; 
	#else
	if(New_Spd_SystemChk())		RunSpeedCmd_IO_spd3();
	#endif

}




void __attribute__((section(".usercode")))    CarCurFloorRead_IO(void)
{
	if(New_Spd_SystemChk())		CarCurFloorRead_IO_spd3();
}




void __attribute__((section(".usercode")))    SpeedChange(void)
{
	if(New_Spd_SystemChk())		SpeedChange_spd3();
}

*/




