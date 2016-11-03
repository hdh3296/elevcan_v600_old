
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
#include  	"L1000_par_map.h" 


/*
const unsigned char InverterMap[]={
EDS_MOTOR_TYPE_ADDRH,			//00	
EDS_MOTOR_TYPE_ADDRL,			//01
EDS_MAX_HZ_ADDRH,				//02 0x01 parameter 01
EDS_MAX_HZ_ADDRL,				//03 0x00 parameter 00
EDS_IM_MOTOR_MAX_HZ_ADDRH,		//04 		
EDS_IM_MOTOR_MAX_HZ_ADDRL,		//05 		
EDS_PM_MOTOR_MAX_HZ_ADDRH,		//06 		
EDS_PM_MOTOR_MAX_HZ_ADDRL,		//07 		
EDS_IM_MOTOR_VOLT_ADDRH,		//08	
EDS_IM_MOTOR_VOLT_ADDRL,		//09	
EDS_PM_MOTOR_VOLT_ADDRH,		//10	
EDS_PM_MOTOR_VOLT_ADDRL,		//11	
EDS_IM_MOTOR_AMP_ADDRH,			//12
EDS_IM_MOTOR_AMP_ADDRL,			//13
EDS_PM_MOTOR_AMP_ADDRH,			//14
EDS_PM_MOTOR_AMP_ADDRL,			//15
EDS_IM_MOTOR_KW_ADDRH,			//16
EDS_IM_MOTOR_KW_ADDRL,			//17
EDS_PM_MOTOR_KW_ADDRH,			//18
EDS_PM_MOTOR_KW_ADDRL,			//19
EDS_IM_MOTOR_RPM_ADDRH,			//20
EDS_IM_MOTOR_RPM_ADDRL,			//21
EDS_PM_MOTOR_RPM_ADDRH,			//22
EDS_PM_MOTOR_RPM_ADDRL,			//23
EDS_IM_MOTOR_POLE_ADDRH,		//24
EDS_IM_MOTOR_POLE_ADDRL,		//25
EDS_PM_MOTOR_POLE_ADDRH,		//26
EDS_PM_MOTOR_POLE_ADDRL,		//27
EDS_IM_NOLOAD_AMP_ADDRH,		//28
EDS_IM_NOLOAD_AMP_ADDRL,		//29
EDS_PM_MOTOR_DEG_ADDRH,			//30
EDS_PM_MOTOR_DEG_ADDRL,			//31
EDS_IM_ENCODER_PULSE_ADDRH,		//32	
EDS_IM_ENCODER_PULSE_ADDRL,		//33	
EDS_PM_ENCODER_PULSE_ADDRH,		//34	
EDS_PM_ENCODER_PULSE_ADDRL,		//35
EDS_ENCODER_PHASE_ADDRH,		//36	
EDS_ENCODER_PHASE_ADDRL,		//37   
EDS_RUN_ZERO_SERVO_ADDRH,		//38
EDS_RUN_ZERO_SERVO_ADDRL,		//39   
EDS_STOP_ZERO_SERVO_ADDRH,		//40
EDS_STOP_ZERO_SERVO_ADDRL,		//41   
EDS_INER_RATIO_ADDRH,			//42
EDS_INER_RATIO_ADDRL,			//43
EDS_BANDWITH_ADDRH,				//44
EDS_BANDWITH_ADDRL,				//45
EDS_IM_TUNNING_ADDRH,			//46
EDS_IM_TUNNING_ADDRL,			//47   
EDS_PM_TUNNING_ADDRH,			//48
EDS_PM_TUNNING_ADDRL,			//49   
0,								//50
0,								//51
0,								//52
0,								//53
0,								//54
0,								//55
0,								//56
0,								//57
0,								//58
0,								//59
0,								//60
0,								//61
0,								//62
0,								//63
0,								//64
0,								//65
0,								//66
0,								//67
0,								//68
0,								//69
0,								//70
0,								//71
0,								//72
0,								//73
0,								//74
0,								//75
0,								//76
0,								//77
0,								//78
0,								//79
0,								//80
0,								//81
0,								//82
0,								//83
0,								//84
0,								//85
0,								//86
0,								//87
0,								//88
0,								//89
0,								//90
0,								//91
0,								//92
0,								//93
0,								//94
0,								//95
0,								//96
0,								//97
0,								//98
0,								//90
L1000_MOTOR_TYPE_ADDRH,			//00 motor type	
L1000_MOTOR_TYPE_ADDRL,			//01 motor type
L1000_MAX_HZ_ADDRH,				//02 0x01 parameter 01
L1000_MAX_HZ_ADDRL,				//03 0x00 parameter 00
L1000_IM_MOTOR_MAX_HZ_ADDRH,	//04 		
L1000_IM_MOTOR_MAX_HZ_ADDRL,	//05 		
L1000_PM_MOTOR_MAX_HZ_ADDRH,	//06 		
L1000_PM_MOTOR_MAX_HZ_ADDRL,	//07 		
L1000_IM_MOTOR_VOLT_ADDRH,		//08	
L1000_IM_MOTOR_VOLT_ADDRL,		//09	
L1000_PM_MOTOR_VOLT_ADDRH,		//10	
L1000_PM_MOTOR_VOLT_ADDRL,		//11	
L1000_IM_MOTOR_AMP_ADDRH,		//12
L1000_IM_MOTOR_AMP_ADDRL,		//13
L1000_PM_MOTOR_AMP_ADDRH,		//14
L1000_PM_MOTOR_AMP_ADDRL,		//15
L1000_IM_MOTOR_KW_ADDRH,		//16
L1000_IM_MOTOR_KW_ADDRL,		//17
L1000_PM_MOTOR_KW_ADDRH,		//18
L1000_PM_MOTOR_KW_ADDRL,		//19
L1000_IM_MOTOR_RPM_ADDRH,		//20
L1000_IM_MOTOR_RPM_ADDRL,		//21
L1000_PM_MOTOR_RPM_ADDRH,		//22
L1000_PM_MOTOR_RPM_ADDRL,		//23
L1000_IM_MOTOR_POLE_ADDRH,		//24
L1000_IM_MOTOR_POLE_ADDRL,		//25
L1000_PM_MOTOR_POLE_ADDRH,		//26
L1000_PM_MOTOR_POLE_ADDRL,		//27
L1000_IM_NOLOAD_AMP_ADDRH,		//28
L1000_IM_NOLOAD_AMP_ADDRL,		//29
L1000_PM_MOTOR_DEG_ADDRH,		//30
L1000_PM_MOTOR_DEG_ADDRL,		//31
L1000_IM_ENCODER_PULSE_ADDRH,	//32	
L1000_IM_ENCODER_PULSE_ADDRL,	//33	
L1000_PM_ENCODER_PULSE_ADDRH,	//34	
L1000_PM_ENCODER_PULSE_ADDRL,	//35
L1000_ENCODER_PHASE_ADDRH,		//36	
L1000_ENCODER_PHASE_ADDRL,		//37   
L1000_RUN_ZERO_SERVO_ADDRH,		//38
L1000_RUN_ZERO_SERVO_ADDRL,		//39   
L1000_STOP_ZERO_SERVO_ADDRH,	//40
L1000_STOP_ZERO_SERVO_ADDRL,	//41   
L1000_INER_RATIO_ADDRH,			//42
L1000_INER_RATIO_ADDRL,			//43
L1000_BANDWITH_ADDRH,			//44
L1000_BANDWITH_ADDRL,			//45
L1000_IM_TUNNING_ADDRH,			//46
L1000_IM_TUNNING_ADDRL,			//47   
L1000_PM_TUNNING_ADDRH,			//48
L1000_PM_TUNNING_ADDRL			//49

};

*/




/*


#define		INV_ERR_ADDRH			L1000_INV_ERR_ADDRH			// 0x06 inverter err parameter 06 group		
#define		INV_ERR_ADDRL			L1000_INV_ERR_ADDRL			// 0x10 inverter err parameter 16 current Error 		

#define		MAX_EV_SPD_ADDRH		L1000_MAX_EV_SPD_ADDRH		//0x0b 		
#define		MAX_EV_SPD_ADDRL		L1000_MAX_EV_SPD_ADDRL		//0x01  		

#define		EL_SHIVE_ADDRH			L1000_EL_SHIVE_ADDRH			//0x0b	
#define		EL_SHIVE_ADDRL			L1000_EL_SHIVE_ADDRL			//0x02    

#define		EL_GEAR_ADDRH			L1000_EL_GEAR_ADDRH			//0x0b	
#define		EL_GEAR_ADDRL			L1000_EL_GEAR_ADDRL			//0x03    

#define		INER_RATIO_ADDRH		L1000_INER_RATIO_ADDRH		//0x0b	
#define		INER_RATIO_ADDRL		L1000_INER_RATIO_ADDRL		//0x05   

#define		BANDWITH_ADDRH			L1000_BANDWITH_ADDRH			//0x0b	//??
#define		BANDWITH_ADDRL			L1000_BANDWITH_ADDRL			//0x06    //??


#define		DEC_TIME_ADDRH			L1000_DEC_TIME_ADDRH			// 0x01 parameter 01 group		
#define		DEC_TIME_ADDRL			L1000_DEC_TIME_ADDRL			// 0x0d	parameter 13 		

#define		S_CUV_TIME1_ADDRH		L1000_S_CUV_TIME1_ADDRH		// 0x01 parameter 01 group		
#define		S_CUV_TIME1_ADDRL		L1000_S_CUV_TIME1_ADDRL		// 0x1a	parameter 26  first scurve 		



#define		INV_CUR_AMP_ADDRH		L1000_INV_CUR_AMP_ADDRH		// 0x21	inverter current A		
#define		INV_CUR_AMP_ADDRL		L1000_INV_CUR_AMP_ADDRL		// 0x04	inverter current A 		

#define		INV_RESET_ADDRH			L1000_INV_RESET_ADDRH			//0x20	// reset address		
#define		INV_RESET_ADDRL			L1000_INV_RESET_ADDRL			//0x02	// reset address 		
*/
