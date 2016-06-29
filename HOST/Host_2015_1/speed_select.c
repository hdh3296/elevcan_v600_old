


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




void  __attribute__((section(".usercode"))) DefaultEncoderRpmMpm(void)
{
	if(New_Spd_SystemChk())		DefaultEncoderRpmMpm_spd3();
	else						DefaultEncoderRpmMpm_old();
}



void  __attribute__((section(".usercode"))) CaluDecreasePulse(void)
{
	if(New_Spd_SystemChk())		CaluDecreasePulse_spd3();
	else						CaluDecreasePulse_old();
}



unsigned int    __attribute__((section(".usercode"))) SpeedSet(void)
{
	#ifdef	DELTA_INVERTER
		return(0);
	#else
		if(New_Spd_SystemChk())		return(SpeedSet_spd3());
		else						return(SpeedSet_old());
	#endif
}



void __attribute__((section(".usercode")))    RunSpeedCmd_IO(void)
{
	#ifdef	DELTA_INVERTER
		if(New_Spd_SystemChk())		CurSpeed=SPEED_HIGH; 
		else						CurSpeed=SPEED_60;
	#endif

	if(New_Spd_SystemChk())		RunSpeedCmd_IO_spd3();
	else						RunSpeedCmd_IO_old();
}


void __attribute__((section(".usercode")))    Mnanual_Speed_Sel(void)
{
	if(New_Spd_SystemChk())		Mnanual_Speed_Sel_spd3();
	else						Mnanual_Speed_Sel_old();
}


void __attribute__((section(".usercode")))    CarCurFloorRead_IO(void)
{
	if(New_Spd_SystemChk())		CarCurFloorRead_IO_spd3();
	else						CarCurFloorRead_IO_old();
}


void __attribute__((section(".usercode")))    SpeedChange(void)
{
	if(New_Spd_SystemChk())		SpeedChange_spd3();
	else						SpeedChange_old();
}







