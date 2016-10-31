
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

#include  	"L1000_par_map.h" 


//#ifdef	AUTO_LANDING_COMM	

#ifdef		AUTO_LANDING_485			


extern	unsigned char GroupParaAddrH,GroupParaAddrL;
extern	unsigned char *MenuName;		



const unsigned char L1000_A_MSG[][5]={   
                                    "A1-00",	//00
                                    "A1-01",	//00
                                    "A1-02",	//00
                                    "A1-03",	//00
                                    "A1-04",	//00
                                    "A1-05",	//00
								};

const unsigned char L1000_B_MSG[][5]={   
                                    "B1-01",	//00
                                    "B1-02",	//00
                                    "B1-03",	//00
                                    "B1-06",	//00
                                    "B1-08",	//00
                                    "B1-14",	//00
                                    "B2-08",	//00
                                    "B4-01",	//00
                                    "B4-02",	//00
                                    "B6-01",	//00
                                    "B6-02",	//00
                                    "B6-03",	//00
                                    "B6-04",	//00
                                    "B7-01",	//00
                                    "B7-02",	//00
                                    "B8-01",	//00
                                    "B8-16",	//00
                                    "B8-17",	//00
								};

						

const unsigned char L1000_C_MSG[][5]={   
                                    "C1-01",	//00
                                    "C1-02",	//00
                                    "C1-03",	//00
                                    "C1-04",	//00
                                    "C1-05",	//00
                                    "C1-06",	//00
                                    "C1-07",	//00
                                    "C1-08",	//00
                                    "C1-09",	//00
                                    "C1-10",	//00
                                    "C1-11",	//00
                                    "C1-15",	//00
                                    "C2-01",	//00
                                    "C2-02",	//00
                                    "C2-03",	//00
                                    "C2-04",	//00
                                    "C2-05",	//00
                                    "C3-01",	//00
                                    "C3-02",	//00
                                    "C3-03",	//00
                                    "C3-04",	//00
                                    "C3-05",	//00
                                    "C4-01",	//00
                                    "C4-02",	//00
                                    "C4-03",	//00
                                    "C4-04",	//00
                                    "C4-05",	//00
                                    "C5-01",	//00
                                    "C5-02",	//00
                                    "C5-03",	//00
                                    "C5-04",	//00
                                    "C5-06",	//00
                                    "C5-07",	//00
                                    "C5-08",	//00
                                    "C5-13",	//00
                                    "C5-14",	//00
                                    "C5-16",	//00
                                    "C5-19",	//00
                                    "C5-20",	//00
                                    "C6-03",	//00
                                    "C6-06",	//00
                                    "C6-09",	//00
                                    "C6-21",	//00
                                    "C6-23",	//00
								};


const unsigned char L1000_D_MSG[][5]={   
                                    "D1-01",	//00
                                    "D1-02",	//00
                                    "D1-03",	//00
                                    "D1-04",	//00
                                    "D1-05",	//00
                                    "D1-06",	//00
                                    "D1-07",	//00
                                    "D1-08",	//00
                                    "D1-18",	//00
                                    "D1-19",	//00
                                    "D1-20",	//00
                                    "D1-21",	//00
                                    "D1-22",	//00
                                    "D1-23",	//00
                                    "D1-24",	//00
                                    "D1-25",	//00
                                    "D1-26",	//00
                                    "D1-28",	//00
                                    "D1-29",	//00
                                    "D6-03",	//00
                                    "D6-06",	//00
								};
									

const unsigned char L1000_E_MSG[][5]={   
                                    "E1-01",	//00
                                    "E1-03",	//00
                                    "E1-04",	//00
                                    "E1-05",	//00
                                    "E1-06",	//00
                                    "E1-07",	//00
                                    "E1-08",	//00
                                    "E1-09",	//00
                                    "E1-10",	//00
                                    "E1-11",	//00
                                    "E1-12",	//00
                                    "E1-13",	//00
                                    "E2-01",	//00
                                    "E2-02",	//00
                                    "E2-03",	//00
                                    "E2-04",	//00
                                    "E2-05",	//00
                                    "E2-06",	//00
                                    "E2-07",	//00
                                    "E2-08",	//00
                                    "E2-09",	//00
                                    "E2-10",	//00
                                    "E2-11",	//00
                                    "E5-02",	//00
                                    "E5-03",	//00
                                    "E5-04",	//00
                                    "E5-05",	//00
                                    "E5-06",	//00
                                    "E5-07",	//00
                                    "E5-09",	//00
                                    "E5-11",	//00
                                    "E5-24",	//00
								};


const unsigned char L1000_F_MSG[][5]={   
                                    "F1-01",	//00
                                    "F1-02",	//00
                                    "F1-03",	//00
                                    "F1-04",	//00
                                    "F1-05",	//00
                                    "F1-06",	//00
                                    "F1-08",	//00
                                    "F1-09",	//00
                                    "F1-10",	//00
                                    "F1-11",	//00
                                    "F1-14",	//00
                                    "F1-18",	//00
                                    "F1-19",	//00
                                    "F1-20",	//00
                                    "F1-29",	//00
                                    "F1-51",	//00
                                    "F1-63",	//00
                                    "F3-01",	//00
                                    "F3-03",	//00
                                    "F4-01",	//00
                                    "F4-02",	//00
                                    "F4-03",	//00
                                    "F4-04",	//00
                                    "F4-05",	//00
                                    "F4-06",	//00
                                    "F4-07",	//00
                                    "F4-08",	//00
                                    "F5-01",	//00
                                    "F5-02",	//00
                                    "F5-03",	//00
                                    "F5-04",	//00
                                    "F5-05",	//00
                                    "F5-06",	//00
                                    "F5-07",	//00
                                    "F5-08",	//00
                                    "F5-09",	//00
                                    "F6-01",	//00
                                    "F6-02",	//00
                                    "F6-03",	//00
                                    "F6-04",	//00
                                    "F6-06",	//00
                                    "F6-08",	//00
                                    "F6-35",	//00
                                    "F6-36",	//00
								};


const unsigned char L1000_H_MSG[][5]={   
                                    "H1-03",	//00
                                    "H1-04",	//00
                                    "H1-05",	//00
                                    "H1-06",	//00
                                    "H1-07",	//00
                                    "H1-08",	//00
                                    "H1-08",	//00
                                    "H2-01",	//00
                                    "H2-02",	//00
                                    "H2-03",	//00
                                    "H2-04",	//00
                                    "H2-05",	//00
                                    "H3-01",	//00
                                    "H3-02",	//00
                                    "H3-03",	//00
                                    "H3-04",	//00
                                    "H3-09",	//00
                                    "H3-10",	//00
                                    "H3-11",	//00
                                    "H3-12",	//00
                                    "H3-13",	//00
                                    "H3-16",	//00
                                    "H3-17",	//00
                                    "H4-01",	//00
                                    "H4-02",	//00
                                    "H4-03",	//00
                                    "H4-04",	//00
                                    "H4-05",	//00
                                    "H4-06",	//00
                                    "H4-07",	//00
                                    "H4-08",	//00
                                    "H5-01",	//00
                                    "H5-02",	//00
                                    "H5-03",	//00
                                    "H5-04",	//00
                                    "H5-05",	//00
                                    "H5-06",	//00
                                    "H5-07",	//00
                                    "H5-08",	//00
                                    "H5-09",	//00
                                    "H5-10",	//00
                                    "H5-11",	//00
								};



const unsigned char L1000_L_MSG[][5]={   
                                    "L1-01",	//00
                                    "L1-02",	//00
                                    "L1-13",	//00
                                    "L2-05",	//00
                                    "L3-07",	//00
                                    "L3-08",	//00
                                    "L3-01",	//00
                                    "L3-02",	//00
                                    "L3-05",	//00
                                    "L3-06",	//00
                                    "L4-01",	//00
                                    "L4-02",	//00
                                    "L4-03",	//00
                                    "L4-04",	//00
                                    "L4-05",	//00
                                    "L4-06",	//00
                                    "L4-13",	//00
                                    "L5-01",	//00
                                    "L5-02",	//00
                                    "L5-04",	//00
                                    "L5-06",	//00
                                    "L6-01",	//00
                                    "L6-02",	//00
                                    "L6-03",	//00
                                    "L6-04",	//00
                                    "L6-05",	//00
                                    "L6-06",	//00
                                    "L7-01",	//00
                                    "L7-02",	//00
                                    "L7-03",	//00
                                    "L7-04",	//00
                                    "L8-02",	//00
                                    "L8-03",	//00
                                    "L8-05",	//00
                                    "L8-06",	//00
                                    "L8-07",	//00
                                    "L8-09",	//00
                                    "L8-10",	//00
                                    "L8-11",	//00
                                    "L8-12",	//00
                                    "L8-15",	//00
                                    "L8-27",	//00
                                    "L8-29",	//00
                                    "L8-35",	//00
                                    "L8-38",	//00
                                    "L8-39",	//00
                                    "L8-55",	//00
                                    "L8-62",	//00
                                    "L8-77",	//00
                                    "L8-88",	//00
								};


const unsigned char L1000_N_MSG[][5]={   
                                    "N2-01",	//00
                                    "N2-02",	//00
                                    "N2-03",	//00
                                    "N5-01",	//00
                                    "N5-02",	//00
                                    "N5-03",	//00
                                    "N6-01",	//00
                                    "N6-05",	//00
                                    "N8-01",	//00
                                    "N8-02",	//00
                                    "N8-29",	//00
                                    "N8-30",	//00
                                    "N8-32",	//00
                                    "N8-33",	//00
                                    "N8-35",	//00
                                    "N8-36",	//00
                                    "N8-37",	//00
                                    "N8-62",	//00
                                    "N8-81",	//00
                                    "N8-82",	//00
                                    "N8-84",	//00
                                    "N8-86",	//00
                                    "N9-60",	//00
								};


const unsigned char L1000_O_MSG[][5]={   
                                    "O1-01",	//00
                                    "O1-02",	//00
                                    "O1-03",	//00
                                    "O1-04",	//00
                                    "O1-10",	//00
                                    "O1-11",	//00
                                    "O1-20",	//00
                                    "O1-21",	//00
                                    "O1-22",	//00
                                    "O2-01",	//00
                                    "O2-02",	//00
                                    "O2-03",	//00
                                    "O2-04",	//00
                                    "O2-05",	//00
                                    "O2-06",	//00
                                    "O2-09",	//00
                                    "O3-01",	//00
                                    "O3-02",	//00
                                    "O4-01",	//00
                                    "O4-02",	//00
                                    "O4-03",	//00
                                    "O4-05",	//00
                                    "O4-07",	//00
                                    "O4-09",	//00
                                    "O4-11",	//00
                                    "O4-12",	//00
                                    "O4-13",	//00
								};


const unsigned char L1000_S_MSG[][5]={   
                                    "S1-01",	//00
                                    "S1-02",	//00
                                    "S1-03",	//00
                                    "S1-04",	//00
                                    "S1-05",	//00
                                    "S1-06",	//00
                                    "S1-07",	//00
                                    "S1-10",	//00
                                    "S1-11",	//00
                                    "S2-01",	//00
                                    "S2-02",	//00
                                    "S2-03",	//00
                                    "S2-05",	//00
                                    "S2-06",	//00
                                    "S3-01",	//00
                                    "S3-02",	//00
                                    "S3-03",	//00
                                    "S3-04",	//00
                                    "S3-10",	//00
                                    "S3-12",	//00
                                    "S3-14",	//00
                                    "S3-15",	//00
                                    "S3-16",	//00
                                    "S3-25",	//00
                                    "S3-26",	//00
                                    "S3-27",	//00
                                    "S3-28",	//00
                                    "S3-29",	//00
                                    "S3-30",	//00
                                    "S3-34",	//00
                                    "S3-35",	//00
                                    "S3-37",	//00
                                    "S3-38",	//00
                                    "S3-39",	//00
                                    "S3-40",	//00
                                    "S3-41",	//00
                                    "S4-01",	//00
                                    "S4-02",	//00
                                    "S4-03",	//00
                                    "S4-04",	//00
                                    "S4-05",	//00
                                    "S4-06",	//00
                                    "S4-07",	//00
                                    "S4-08",	//00
                                    "S4-12",	//00
                                    "S4-13",	//00
                                    "S5-01",	//00
                                    "S5-02",	//00
                                    "S6-01",	//00
                                    "S6-02",	//00
                                    "S6-04",	//00
                                    "S6-05",	//00
                                    "S6-10",	//00
                                    "S6-11",	//00
                                    "S6-12",	//00
                                    "S6-15",	//00
                                    "S6-16",	//00
								};


const unsigned char L1000_T_MSG[][5]={   
                                    "T1-01",	//00
                                    "T1-02",	//00
                                    "T1-03",	//00
                                    "T1-04",	//00
                                    "T1-05",	//00
                                    "T1-06",	//00
                                    "T1-07",	//00
                                    "T1-08",	//00
                                    "T1-09",	//00
                                    "T1-10",	//00
                                    "T2-01",	//00
                                    "T2-04",	//00
                                    "T2-05",	//00
                                    "T2-06",	//00
                                    "T2-08",	//00
                                    "T2-09",	//00
                                    "T2-10",	//00
                                    "T2-11",	//00
                                    "T2-12",	//00
                                    "T2-13",	//00
                                    "T2-14",	//00
                                    "T2-16",	//00
                                    "T2-17",	//00
								};





LocalType __attribute__((section(".usercode"))) L1000_SaveCommand(unsigned char addressH,unsigned char addressL)
{
	if(WhoAutolanding==L1000_AUTOLANDING_485){
		if( (addressH==0x09) && (addressL ==0x00) && bL1000_Enter){
			bL1000_Enter=0;
			ThisRdWrMode=PARAMETER_RD_OK_SEQ;
			ParRdWrNm=INVETER_NOT_SEL_SEQ;
		}
	}	

	return(0);
}







LocalType __attribute__((section(".usercode"))) L1000AddressSet(void)
{

	InverterAddress=0x01;

	IM_Motor_ID=L1000_IM_MOTOR;			// IM motor type		03
	PM_Motor_ID=L1000_PM_MOTOR;			// PM motor type		08

	TunningValue1=L1000_MOTOR_TUNNING1;
	TunningValue2=L1000_MOTOR_TUNNING2;
	TunningValue3=L1000_MOTOR_TUNNING3;


	Addr_MotorType		=( ((unsigned int)(L1000_MOTOR_TYPE_ADDRH 		<< 8)) | ((unsigned int)(L1000_MOTOR_TYPE_ADDRL)));
	Addr_MaxHz    		=( ((unsigned int)(L1000_MAX_HZ_ADDRH     		<< 8)) | ((unsigned int)(L1000_MAX_HZ_ADDRL)));
	Addr_MaxEvSpd    	=( ((unsigned int)(L1000_EDS_MAX_EV_SPD_ADDRH	<< 8)) | ((unsigned int)(L1000_EDS_MAX_EV_SPD_ADDRL)));


	Addr_IM_MotorHz		=( ((unsigned int)(L1000_IM_MOTOR_MAX_HZ_ADDRH 	<< 8)) | ((unsigned int)(L1000_IM_MOTOR_MAX_HZ_ADDRL)));
	Addr_PM_MotorHz		=( ((unsigned int)(L1000_PM_MOTOR_MAX_HZ_ADDRH 	<< 8)) | ((unsigned int)(L1000_PM_MOTOR_MAX_HZ_ADDRL)));

	Addr_IM_MotorVlot	=( ((unsigned int)(L1000_IM_MOTOR_VOLT_ADDRH 	<< 8)) | ((unsigned int)(L1000_IM_MOTOR_VOLT_ADDRL)));
	Addr_PM_MotorVlot	=( ((unsigned int)(L1000_PM_MOTOR_VOLT_ADDRH 	<< 8)) | ((unsigned int)(L1000_PM_MOTOR_VOLT_ADDRL)));

	Addr_IM_MotorAmp	=( ((unsigned int)(L1000_IM_MOTOR_AMP_ADDRH 	<< 8)) | ((unsigned int)(L1000_IM_MOTOR_AMP_ADDRL)));
	Addr_PM_MotorAmp	=( ((unsigned int)(L1000_PM_MOTOR_AMP_ADDRH 	<< 8)) | ((unsigned int)(L1000_PM_MOTOR_AMP_ADDRL)));

	Addr_IM_MotorKw		=( ((unsigned int)(L1000_IM_MOTOR_KW_ADDRH 		<< 8)) | ((unsigned int)(L1000_IM_MOTOR_KW_ADDRL)));
	Addr_PM_MotorKw		=( ((unsigned int)(L1000_PM_MOTOR_KW_ADDRH 		<< 8)) | ((unsigned int)(L1000_PM_MOTOR_KW_ADDRL)));


	Addr_IM_MotorRpm	=( ((unsigned int)(L1000_IM_MOTOR_RPM_ADDRH 	<< 8)) | ((unsigned int)(L1000_IM_MOTOR_RPM_ADDRL)));
	Addr_PM_MotorRpm	=( ((unsigned int)(L1000_PM_MOTOR_RPM_ADDRH 	<< 8)) | ((unsigned int)(L1000_PM_MOTOR_RPM_ADDRL)));

	Addr_IM_MotorPole	=( ((unsigned int)(L1000_IM_MOTOR_POLE_ADDRH 	<< 8)) | ((unsigned int)(L1000_IM_MOTOR_POLE_ADDRL)));
	Addr_PM_MotorPole	=( ((unsigned int)(L1000_PM_MOTOR_POLE_ADDRH 	<< 8)) | ((unsigned int)(L1000_PM_MOTOR_POLE_ADDRL)));

	Addr_IM_NoLdAmp		=( ((unsigned int)(L1000_IM_NOLOAD_AMP_ADDRH 	<< 8)) | ((unsigned int)(L1000_IM_NOLOAD_AMP_ADDRL)));
	Addr_PM_MotorDeg	=( ((unsigned int)(L1000_PM_MOTOR_DEG_ADDRH 	<< 8)) | ((unsigned int)(L1000_PM_MOTOR_DEG_ADDRL)));

	Addr_IM_EncoderPulse=( ((unsigned int)(L1000_IM_ENCODER_PULSE_ADDRH << 8)) | ((unsigned int)(L1000_IM_ENCODER_PULSE_ADDRL)));
	Addr_PM_EncoderPulse=( ((unsigned int)(L1000_PM_ENCODER_PULSE_ADDRH << 8)) | ((unsigned int)(L1000_PM_ENCODER_PULSE_ADDRL)));


	Addr_EncoderAB		=( ((unsigned int)(L1000_ENCODER_PHASE_ADDRH 	<< 8)) | ((unsigned int)(L1000_ENCODER_PHASE_ADDRL)));

	Addr_Run_Zero		=( ((unsigned int)(L1000_RUN_ZERO_SERVO_ADDRH 	<< 8)) | ((unsigned int)(L1000_RUN_ZERO_SERVO_ADDRL)));
	Addr_Stop_Zero		=( ((unsigned int)(L1000_STOP_ZERO_SERVO_ADDRH 	<< 8)) | ((unsigned int)(L1000_STOP_ZERO_SERVO_ADDRL)));

	Addr_Gain1			=( ((unsigned int)(L1000_INER_RATIO_ADDRH 		<< 8)) | ((unsigned int)(L1000_INER_RATIO_ADDRL)));
	Addr_Gain2			=( ((unsigned int)(L1000_BANDWITH_ADDRH 		<< 8)) | ((unsigned int)(L1000_BANDWITH_ADDRL)));


	Addr_IM_Tunning		=( ((unsigned int)(L1000_IM_TUNNING_ADDRH 		<< 8)) | ((unsigned int)(L1000_IM_TUNNING_ADDRL)));
	Addr_PM_Tunning		=( ((unsigned int)(L1000_PM_TUNNING_ADDRH 		<< 8)) | ((unsigned int)(L1000_PM_TUNNING_ADDRL)));

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Addr_Dec_Time		=( ((unsigned int)(L1000_DEC_TIME_ADDRH 		<< 8)) | ((unsigned int)(L1000_DEC_TIME_ADDRL)));
	Addr_SCurve_Time	=( ((unsigned int)(L1000_S_CUV_TIME1_ADDRH 		<< 8)) | ((unsigned int)(L1000_S_CUV_TIME1_ADDRL)));


	Addr_DecSpdPort		=( ((unsigned int)(L1000_DEC_SPD_PORTH 			<< 8)) | ((unsigned int)(L1000_DEC_SPD_PORTL)));
	Addr_ManualSpdPort	=( ((unsigned int)(L1000_MANUAL_SPD_PORTH 		<< 8)) | ((unsigned int)(L1000_MANUAL_SPD_PORTL)));
	Addr_LowSpdPort		=( ((unsigned int)(L1000_LOW_SPD_PORTH 			<< 8)) | ((unsigned int)(L1000_LOW_SPD_PORTL)));
	Addr_MidSpdPort		=( ((unsigned int)(L1000_MID_SPD_PORTH 			<< 8)) | ((unsigned int)(L1000_MID_SPD_PORTL)));
	Addr_HighSpdPort	=( ((unsigned int)(L1000_HIGH_SPD_PORTH 		<< 8)) | ((unsigned int)(L1000_HIGH_SPD_PORTL)));

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	Addr_CurError		=( ((unsigned int)(L1000_INV_ERR_ADDRH 			<< 8)) | ((unsigned int)(L1000_INV_ERR_ADDRL)));
	Addr_CurAmp			=( ((unsigned int)(L1000_INV_ERR_ADDRH 			<< 8)) | ((unsigned int)(L1000_INV_ERR_ADDRL)));
	Addr_Reset			=( ((unsigned int)(L1000_INV_RESET_ADDRH 		<< 8)) | ((unsigned int)(L1000_INV_RESET_ADDRL)));


	return(0);	
}



/*

unsigned int  __attribute__((section(".usercode"))) L1000_Inv_GroupA(void)
{
    MaxSubMenu=MOTOR_GROUP_MAX;

	EditStatus=DIGIT_EDIT;	
	DigitAttribute=0;
	DigitMinValue=0;
	DigitMaxValue=0xffff;

	MenuName= (unsigned char *)(&L1000_A_MSG[LadderGroupSub][0]);


	switch(LadderGroupSub){
		case	0:
			DigitMaxValue=7;			
			GroupParaAddrH=0x01;
			GroupParaAddrL=0x00;
			break;
		case	1:
			DigitMaxValue=2;			
			GroupParaAddrH=0x01;
			GroupParaAddrL=0x01;
			break;
		case	2:
			DigitMaxValue=7;			
			GroupParaAddrH=0x01;
			GroupParaAddrL=0x02;
			break;
		case	3:
			DigitMaxValue=5550;			
			GroupParaAddrH=0x01;
			GroupParaAddrL=0x03;
			break;
		case	4:
			DigitMaxValue=9999;			
			GroupParaAddrH=0x01;
			GroupParaAddrL=0x04;
			break;
		case	5:
			DigitMaxValue=9999;			
			GroupParaAddrH=0x01;
			GroupParaAddrL=0x05;
			break;
	}	
}


unsigned int  __attribute__((section(".usercode"))) L1000_Inv_GroupB(void)
{
	EditStatus=DIGIT_EDIT;	
	DigitAttribute=0;
	DigitMinValue=0;
	DigitMaxValue=0xffff;

	MenuName= (unsigned char *)(&L1000_B_MSG[LadderGroupSub][0]);

	switch(LadderGroupSub){
		case	0:
			DigitMaxValue=7;			
			break;
		case	1:
			DigitMaxValue=2;			
			break;
		case	2:
			DigitMaxValue=7;			
			break;
		case	3:
			DigitMaxValue=5550;			
			break;
		case	4:
			DigitMaxValue=9999;			
			break;
		case	5:
			DigitMaxValue=9999;			
			break;
	}	
}


unsigned int  __attribute__((section(".usercode"))) L1000_Inv_GroupC(void)
{
	EditStatus=DIGIT_EDIT;	
	DigitAttribute=0;
	DigitMinValue=0;
	DigitMaxValue=0xffff;
	MenuName= (unsigned char *)(&L1000_A_MSG[LadderGroupSub][0]);

	switch(LadderGroupSub){
		case	0:
			DigitMaxValue=7;			
			break;
		case	1:
			DigitMaxValue=2;			
			break;
		case	2:
			DigitMaxValue=7;			
			break;
		case	3:
			DigitMaxValue=5550;			
			break;
		case	4:
			DigitMaxValue=9999;			
			break;
		case	5:
			DigitMaxValue=9999;			
			break;
	}	
}

unsigned int  __attribute__((section(".usercode"))) L1000_Inv_GroupD(void)
{
	EditStatus=DIGIT_EDIT;	
	DigitAttribute=0;
	DigitMinValue=0;
	DigitMaxValue=0xffff;
	MenuName= (unsigned char *)(&L1000_A_MSG[LadderGroupSub][0]);

	switch(LadderGroupSub){
		case	0:
			DigitMaxValue=7;			
			break;
		case	1:
			DigitMaxValue=2;			
			break;
		case	2:
			DigitMaxValue=7;			
			break;
		case	3:
			DigitMaxValue=5550;			
			break;
		case	4:
			DigitMaxValue=9999;			
			break;
		case	5:
			DigitMaxValue=9999;			
			break;
	}	
}


unsigned int  __attribute__((section(".usercode"))) L1000_Inv_GroupE(void)
{
	EditStatus=DIGIT_EDIT;	
	DigitAttribute=0;
	DigitMinValue=0;
	DigitMaxValue=0xffff;
	MenuName= (unsigned char *)(&L1000_A_MSG[LadderGroupSub][0]);

	switch(LadderGroupSub){
		case	0:
			DigitMaxValue=7;			
			break;
		case	1:
			DigitMaxValue=2;			
			break;
		case	2:
			DigitMaxValue=7;			
			break;
		case	3:
			DigitMaxValue=5550;			
			break;
		case	4:
			DigitMaxValue=9999;			
			break;
		case	5:
			DigitMaxValue=9999;			
			break;
	}	
}
unsigned int  __attribute__((section(".usercode"))) L1000_Inv_GroupF(void)
{
	EditStatus=DIGIT_EDIT;	
	DigitAttribute=0;
	DigitMinValue=0;
	DigitMaxValue=0xffff;
	MenuName= (unsigned char *)(&L1000_A_MSG[LadderGroupSub][0]);

	switch(LadderGroupSub){
		case	0:
			DigitMaxValue=7;			
			break;
		case	1:
			DigitMaxValue=2;			
			break;
		case	2:
			DigitMaxValue=7;			
			break;
		case	3:
			DigitMaxValue=5550;			
			break;
		case	4:
			DigitMaxValue=9999;			
			break;
		case	5:
			DigitMaxValue=9999;			
			break;
	}	
}


unsigned int  __attribute__((section(".usercode"))) L1000_Inv_GroupH(void)
{
	EditStatus=DIGIT_EDIT;	
	DigitAttribute=0;
	DigitMinValue=0;
	DigitMaxValue=0xffff;
	MenuName= (unsigned char *)(&L1000_A_MSG[LadderGroupSub][0]);

	switch(LadderGroupSub){
		case	0:
			DigitMaxValue=7;			
			break;
		case	1:
			DigitMaxValue=2;			
			break;
		case	2:
			DigitMaxValue=7;			
			break;
		case	3:
			DigitMaxValue=5550;			
			break;
		case	4:
			DigitMaxValue=9999;			
			break;
		case	5:
			DigitMaxValue=9999;			
			break;
	}	
}

unsigned int  __attribute__((section(".usercode"))) L1000_Inv_GroupL(void)
{
	EditStatus=DIGIT_EDIT;	
	DigitAttribute=0;
	DigitMinValue=0;
	DigitMaxValue=0xffff;
	MenuName= (unsigned char *)(&L1000_A_MSG[LadderGroupSub][0]);

	switch(LadderGroupSub){
		case	0:
			DigitMaxValue=7;			
			break;
		case	1:
			DigitMaxValue=2;			
			break;
		case	2:
			DigitMaxValue=7;			
			break;
		case	3:
			DigitMaxValue=5550;			
			break;
		case	4:
			DigitMaxValue=9999;			
			break;
		case	5:
			DigitMaxValue=9999;			
			break;
	}	
}
unsigned int  __attribute__((section(".usercode"))) L1000_Inv_GroupN(void)
{
	EditStatus=DIGIT_EDIT;	
	DigitAttribute=0;
	DigitMinValue=0;
	DigitMaxValue=0xffff;
	MenuName= (unsigned char *)(&L1000_A_MSG[LadderGroupSub][0]);

	switch(LadderGroupSub){
		case	0:
			DigitMaxValue=7;			
			break;
		case	1:
			DigitMaxValue=2;			
			break;
		case	2:
			DigitMaxValue=7;			
			break;
		case	3:
			DigitMaxValue=5550;			
			break;
		case	4:
			DigitMaxValue=9999;			
			break;
		case	5:
			DigitMaxValue=9999;			
			break;
	}	
}

unsigned int  __attribute__((section(".usercode"))) L1000_Inv_GroupO(void)
{
	EditStatus=DIGIT_EDIT;	
	DigitAttribute=0;
	DigitMinValue=0;
	DigitMaxValue=0xffff;
	MenuName= (unsigned char *)(&L1000_A_MSG[LadderGroupSub][0]);

	switch(LadderGroupSub){
		case	0:
			DigitMaxValue=7;			
			break;
		case	1:
			DigitMaxValue=2;			
			break;
		case	2:
			DigitMaxValue=7;			
			break;
		case	3:
			DigitMaxValue=5550;			
			break;
		case	4:
			DigitMaxValue=9999;			
			break;
		case	5:
			DigitMaxValue=9999;			
			break;
	}	
}
unsigned int  __attribute__((section(".usercode"))) L1000_Inv_GroupS(void)
{
	EditStatus=DIGIT_EDIT;	
	DigitAttribute=0;
	DigitMinValue=0;
	DigitMaxValue=0xffff;
	MenuName= (unsigned char *)(&L1000_A_MSG[LadderGroupSub][0]);

	switch(LadderGroupSub){
		case	0:
			DigitMaxValue=7;			
			break;
		case	1:
			DigitMaxValue=2;			
			break;
		case	2:
			DigitMaxValue=7;			
			break;
		case	3:
			DigitMaxValue=5550;			
			break;
		case	4:
			DigitMaxValue=9999;			
			break;
		case	5:
			DigitMaxValue=9999;			
			break;
	}	
}
unsigned int  __attribute__((section(".usercode"))) L1000_Inv_GroupT(void)
{
	EditStatus=DIGIT_EDIT;	
	DigitAttribute=0;
	DigitMinValue=0;
	DigitMaxValue=0xffff;
	MenuName= (unsigned char *)(&L1000_A_MSG[LadderGroupSub][0]);

	switch(LadderGroupSub){
		case	0:
			DigitMaxValue=7;			
			break;
		case	1:
			DigitMaxValue=2;			
			break;
		case	2:
			DigitMaxValue=7;			
			break;
		case	3:
			DigitMaxValue=5550;			
			break;
		case	4:
			DigitMaxValue=9999;			
			break;
		case	5:
			DigitMaxValue=9999;			
			break;
	}	
}
*/


/*
unsigned int  __attribute__((section(".usercode"))) L1000_Inv_AddressRead(void)
{
	unsigned char addressH,addressL;

	if( (WhoAutolanding == (unsigned int)L1000_AUTOLANDING_485)){
		switch(LadderGroup){
			case    INV_PAR_GROUP_00:
				L1000_Inv_GroupA();
				break;
			case    INV_PAR_GROUP_01:
				L1000_Inv_GroupB();
				break;
			case    INV_PAR_GROUP_02:
				L1000_Inv_GroupC();
				break;
			case    INV_PAR_GROUP_03:
				L1000_Inv_GroupD();
				break;
			case    INV_PAR_GROUP_04:
				L1000_Inv_GroupE();
				break;
			case    INV_PAR_GROUP_05:
				L1000_Inv_GroupF();
				break;
			case    INV_PAR_GROUP_06:
				L1000_Inv_GroupH();
				break;
			case    INV_PAR_GROUP_07:
				L1000_Inv_GroupL();
				break;
			case    INV_PAR_GROUP_08:
				L1000_Inv_GroupN();
				break;
			case    INV_PAR_GROUP_09:
				L1000_Inv_GroupO();
				break;
			case    INV_PAR_GROUP_10:
				L1000_Inv_GroupS();
				break;
			case    INV_PAR_GROUP_11:
				L1000_Inv_GroupT();
				break;
			case    INV_PAR_GROUP_12:
				L1000_Inv_GroupA();
				break;
			case    INV_PAR_GROUP_13:
				L1000_Inv_GroupA();
				break;
		}
	}
	return(0);
}
*/


#endif




