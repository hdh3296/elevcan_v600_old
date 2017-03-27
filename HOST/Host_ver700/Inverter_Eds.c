
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
#include  	"ladder485.h" 
#include  	"Host_Autolanding.h" 

#include  	"EDS_par_map.h" 

#ifdef	AUTO_LANDING_COMM	


LocalType __attribute__((section(".usercode"))) EdsAddressSet(void)
{
	InverterAddress=0xff;

	IM_Motor_ID=EDS_IM_MOTOR;			// IM motor type		03
	PM_Motor_ID=EDS_PM_MOTOR;			// PM motor type		08

	TunningValue1=EDS_MOTOR_TUNNING1;
	TunningValue2=EDS_MOTOR_TUNNING2;
	TunningValue3=EDS_MOTOR_TUNNING3;

	Addr_MotorType		=( ((unsigned int)(EDS_MOTOR_TYPE_ADDRH 		<< 8)) | ((unsigned int)(EDS_MOTOR_TYPE_ADDRL)));
	Addr_MaxHz    		=( ((unsigned int)(EDS_MAX_HZ_ADDRH     		<< 8)) | ((unsigned int)(EDS_MAX_HZ_ADDRL)));
	Addr_MaxEvSpd    	=( ((unsigned int)(EDS_MAX_EV_SPD_ADDRH     	<< 8)) | ((unsigned int)(EDS_MAX_EV_SPD_ADDRL)));


	Addr_IM_MotorHz		=( ((unsigned int)(EDS_IM_MOTOR_MAX_HZ_ADDRH 	<< 8)) | ((unsigned int)(EDS_IM_MOTOR_MAX_HZ_ADDRL)));
	Addr_PM_MotorHz		=( ((unsigned int)(EDS_PM_MOTOR_MAX_HZ_ADDRH 	<< 8)) | ((unsigned int)(EDS_PM_MOTOR_MAX_HZ_ADDRL)));

	Addr_IM_MotorVlot	=( ((unsigned int)(EDS_IM_MOTOR_VOLT_ADDRH 		<< 8)) | ((unsigned int)(EDS_IM_MOTOR_VOLT_ADDRL)));
	Addr_PM_MotorVlot	=( ((unsigned int)(EDS_PM_MOTOR_VOLT_ADDRH 		<< 8)) | ((unsigned int)(EDS_PM_MOTOR_VOLT_ADDRL)));

	Addr_IM_MotorAmp	=( ((unsigned int)(EDS_IM_MOTOR_AMP_ADDRH 		<< 8)) | ((unsigned int)(EDS_IM_MOTOR_AMP_ADDRL)));
	Addr_PM_MotorAmp	=( ((unsigned int)(EDS_PM_MOTOR_AMP_ADDRH 		<< 8)) | ((unsigned int)(EDS_PM_MOTOR_AMP_ADDRL)));

	Addr_IM_MotorKw		=( ((unsigned int)(EDS_IM_MOTOR_KW_ADDRH 		<< 8)) | ((unsigned int)(EDS_IM_MOTOR_KW_ADDRL)));
	Addr_PM_MotorKw		=( ((unsigned int)(EDS_PM_MOTOR_KW_ADDRH 		<< 8)) | ((unsigned int)(EDS_PM_MOTOR_KW_ADDRL)));


	Addr_IM_MotorRpm	=( ((unsigned int)(EDS_IM_MOTOR_RPM_ADDRH 		<< 8)) | ((unsigned int)(EDS_IM_MOTOR_RPM_ADDRL)));
	Addr_PM_MotorRpm	=( ((unsigned int)(EDS_PM_MOTOR_RPM_ADDRH 		<< 8)) | ((unsigned int)(EDS_PM_MOTOR_RPM_ADDRL)));

	Addr_IM_MotorPole	=( ((unsigned int)(EDS_IM_MOTOR_POLE_ADDRH 		<< 8)) | ((unsigned int)(EDS_IM_MOTOR_POLE_ADDRL)));
	Addr_PM_MotorPole	=( ((unsigned int)(EDS_PM_MOTOR_POLE_ADDRH 		<< 8)) | ((unsigned int)(EDS_PM_MOTOR_POLE_ADDRL)));

	Addr_IM_NoLdAmp		=( ((unsigned int)(EDS_IM_NOLOAD_AMP_ADDRH		<< 8)) | ((unsigned int)(EDS_IM_NOLOAD_AMP_ADDRL)));
	Addr_PM_MotorDeg	=( ((unsigned int)(EDS_PM_MOTOR_DEG_ADDRH		<< 8)) | ((unsigned int)(EDS_PM_MOTOR_DEG_ADDRL)));

	Addr_IM_EncoderPulse=( ((unsigned int)(EDS_IM_ENCODER_PULSE_ADDRH	<< 8)) | ((unsigned int)(EDS_IM_ENCODER_PULSE_ADDRL)));
	Addr_PM_EncoderPulse=( ((unsigned int)(EDS_PM_ENCODER_PULSE_ADDRH	<< 8)) | ((unsigned int)(EDS_PM_ENCODER_PULSE_ADDRL)));


	Addr_EncoderAB		=( ((unsigned int)(EDS_ENCODER_PHASE_ADDRH 		<< 8)) | ((unsigned int)(EDS_ENCODER_PHASE_ADDRL)));

	Addr_Run_Zero		=( ((unsigned int)(EDS_RUN_ZERO_SERVO_ADDRH 	<< 8)) | ((unsigned int)(EDS_RUN_ZERO_SERVO_ADDRL)));
	Addr_Stop_Zero		=( ((unsigned int)(EDS_STOP_ZERO_SERVO_ADDRH 	<< 8)) | ((unsigned int)(EDS_STOP_ZERO_SERVO_ADDRL)));

	Addr_Gain1			=( ((unsigned int)(EDS_INER_RATIO_ADDRH 		<< 8)) | ((unsigned int)(EDS_INER_RATIO_ADDRL)));
	Addr_Gain2			=( ((unsigned int)(EDS_BANDWITH_ADDRH 			<< 8)) | ((unsigned int)(EDS_BANDWITH_ADDRL)));


	Addr_IM_Tunning		=( ((unsigned int)(EDS_IM_TUNNING_ADDRH 		<< 8)) | ((unsigned int)(EDS_IM_TUNNING_ADDRL)));
	Addr_PM_Tunning		=( ((unsigned int)(EDS_PM_TUNNING_ADDRH 		<< 8)) | ((unsigned int)(EDS_PM_TUNNING_ADDRL)));

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Addr_Dec_Time		=( ((unsigned int)(EDS_DEC_TIME_ADDRH 			<< 8)) | ((unsigned int)(EDS_DEC_TIME_ADDRL)));
	Addr_SCurve_Time	=( ((unsigned int)(EDS_S_CUV_TIME1_ADDRH 		<< 8)) | ((unsigned int)(EDS_S_CUV_TIME1_ADDRL)));


	Addr_DecSpdPort		=( ((unsigned int)(EDS_DEC_SPD_PORTH 			<< 8)) | ((unsigned int)(EDS_DEC_SPD_PORTL)));
	Addr_ManualSpdPort	=( ((unsigned int)(EDS_MANUAL_SPD_PORTH 		<< 8)) | ((unsigned int)(EDS_MANUAL_SPD_PORTL)));
	Addr_LowSpdPort		=( ((unsigned int)(EDS_LOW_SPD_PORTH 			<< 8)) | ((unsigned int)(EDS_LOW_SPD_PORTL)));
	Addr_MidSpdPort		=( ((unsigned int)(EDS_MID_SPD_PORTH 			<< 8)) | ((unsigned int)(EDS_MID_SPD_PORTL)));
	Addr_HighSpdPort	=( ((unsigned int)(EDS_HIGH_SPD_PORTH 			<< 8)) | ((unsigned int)(EDS_HIGH_SPD_PORTL)));

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Addr_CurError		=( ((unsigned int)(EDS_INV_ERR_ADDRH 			<< 8)) | ((unsigned int)(EDS_INV_ERR_ADDRL)));
	Addr_CurAmp			=( ((unsigned int)(EDS_INV_CUR_AMP_ADDRH 		<< 8)) | ((unsigned int)(EDS_INV_CUR_AMP_ADDRL)));
	Addr_Reset			=( ((unsigned int)(EDS_INV_RESET_ADDRH 			<< 8)) | ((unsigned int)(EDS_INV_RESET_ADDRL)));


	return(0);	
}

#endif
