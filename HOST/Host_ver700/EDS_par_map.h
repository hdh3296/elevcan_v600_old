

#ifdef	AUTO_LANDING_COMM

/////rd/wr cmd value///////////////
#define		EDS_RD_SDO_INV_REG			0x03	
#define		EDS_RD_SDO_INV_ATB			0x60	
#define		EDS_RD_SDO_INV_DSR			0x61	
#define		EDS_WR_SDO_INV_REG			0x06
#define		EDS_WR_SDO_INV_REG_MB		0x10
/////////////////////////////////////


#define		EDS_MOTOR_TUNNING1			0x02   	// PM motor tunning	1		
#define		EDS_MOTOR_TUNNING2			0x03   	// PM motor tunning	2		
#define		EDS_MOTOR_TUNNING3			0x03   	// PM motor tunning	2		

#define		EDS_IM_MOTOR				0x03   	// IM motor type		
#define		EDS_PM_MOTOR				0x08   	// PM motor type		




//////////////////memory address////////////////////////////////

#define		EDS_MOTOR_TYPE_ADDRH		0x00   	// motor type		
#define		EDS_MOTOR_TYPE_ADDRL		0x09   	// motor type 		


/////////////////////////////////////////////////////////////////
#define		EDS_MAX_HZ_ADDRH			0x01   	// parameter 01 		
#define		EDS_MAX_HZ_ADDRL			0x00	// parameter 00 		

#define		EDS_MOTOR_MAX_HZ_ADDRH		0x01   	// parameter 01 		
#define		EDS_MOTOR_MAX_HZ_ADDRL		0x01	// parameter 01 		

#define		EDS_MOTOR_VOLT_ADDRH		0x01	// parameter 01
#define		EDS_MOTOR_VOLT_ADDRL		0x02	// parameter 02

#define		EDS_S_CUV_TIME1_ADDRH		0x01   	// parameter 01 group		
#define		EDS_S_CUV_TIME1_ADDRL		0x1a 	// parameter 10  first scurve 		

#define		EDS_DEC_TIME_ADDRH			0x01   	// parameter 01 group		
#define		EDS_DEC_TIME_ADDRL			0x0d  	// parameter 13 		
//////////////////////////////////////////////////////

#define		EDS_IM_MOTOR_VOLT_ADDRH		EDS_MOTOR_VOLT_ADDRH	// parameter 01
#define		EDS_IM_MOTOR_VOLT_ADDRL		EDS_MOTOR_VOLT_ADDRL	// parameter 02


#define		EDS_IM_MOTOR_MAX_HZ_ADDRH	EDS_MOTOR_MAX_HZ_ADDRH   	// parameter 01 		
#define		EDS_IM_MOTOR_MAX_HZ_ADDRL	EDS_MOTOR_MAX_HZ_ADDRL	// parameter 01 		

#define		EDS_IM_TUNNING_ADDRH		0x05	
#define		EDS_IM_TUNNING_ADDRL		0x00    

#define		EDS_IM_MOTOR_AMP_ADDRH		0x05
#define		EDS_IM_MOTOR_AMP_ADDRL		0x01

#define		EDS_IM_MOTOR_KW_ADDRH		0x05
#define		EDS_IM_MOTOR_KW_ADDRL		0x02

#define		EDS_IM_MOTOR_RPM_ADDRH		0x05   // IM motor type		
#define		EDS_IM_MOTOR_RPM_ADDRL		0x03   // motor type 		

#define		EDS_IM_MOTOR_POLE_ADDRH		0x05
#define		EDS_IM_MOTOR_POLE_ADDRL		0x04

#define		EDS_IM_ENCODER_PULSE_ADDRH	0x0a
#define		EDS_IM_ENCODER_PULSE_ADDRL	0x01

#define		EDS_IM_NOLOAD_AMP_ADDRH		0x05
#define		EDS_IM_NOLOAD_AMP_ADDRL		0x05

///////////////////////////////////////////////////////////////
#define		EDS_INV_ERR_ADDRH			0x06	// inverter err parameter 06 group		
#define		EDS_INV_ERR_ADDRL			0x10	// inverter err parameter 16 current Error 		
/////////////////////////////////////////////////////////

#define		EDS_RUN_ZERO_SERVO_ADDRH	0x07	
#define		EDS_RUN_ZERO_SERVO_ADDRL	0x03    

#define		EDS_STOP_ZERO_SERVO_ADDRH	0x07	
#define		EDS_STOP_ZERO_SERVO_ADDRL	0x04    



#define		EDS_PM_MOTOR_VOLT_ADDRH		EDS_MOTOR_VOLT_ADDRH	// parameter 01
#define		EDS_PM_MOTOR_VOLT_ADDRL		EDS_MOTOR_VOLT_ADDRL	// parameter 02

#define		EDS_PM_MOTOR_MAX_HZ_ADDRH	EDS_MOTOR_MAX_HZ_ADDRH   	// parameter 01 		
#define		EDS_PM_MOTOR_MAX_HZ_ADDRL	EDS_MOTOR_MAX_HZ_ADDRL	// parameter 01 		


#define		EDS_PM_TUNNING_ADDRH		0x08	
#define		EDS_PM_TUNNING_ADDRL		0x00    

#define		EDS_PM_MOTOR_AMP_ADDRH		0x08
#define		EDS_PM_MOTOR_AMP_ADDRL		0x01

#define		EDS_PM_MOTOR_KW_ADDRH		0x08
#define		EDS_PM_MOTOR_KW_ADDRL		0x02

#define		EDS_PM_MOTOR_RPM_ADDRH		0x08   // IM motor type		
#define		EDS_PM_MOTOR_RPM_ADDRL		0x03   // motor type 		

#define		EDS_PM_MOTOR_POLE_ADDRH		0x08
#define		EDS_PM_MOTOR_POLE_ADDRL		0x04

#define		EDS_PM_ENCODER_PULSE_ADDRH	0x0a
#define		EDS_PM_ENCODER_PULSE_ADDRL	0x01

#define		EDS_PM_MOTOR_DEG_ADDRH		0x08
#define		EDS_PM_MOTOR_DEG_ADDRL		0x09



#define		EDS_ENCODER_PHASE_ADDRH		0x0a	
#define		EDS_ENCODER_PHASE_ADDRL		0x02    


#define		EDS_MAX_EV_SPD_ADDRH		0x0b	
#define		EDS_MAX_EV_SPD_ADDRL		0x01    

#define		EDS_EL_SHIVE_ADDRH			0x0b	
#define		EDS_EL_SHIVE_ADDRL			0x02    

#define		EDS_EL_GEAR_ADDRH			0x0b	
#define		EDS_EL_GEAR_ADDRL			0x03    


#define		EDS_INER_RATIO_ADDRH		0x0b	//??
#define		EDS_INER_RATIO_ADDRL		0x05    //??

#define		EDS_BANDWITH_ADDRH			0x0b	//??
#define		EDS_BANDWITH_ADDRL			0x06    //??




#define		EDS_INV_CUR_AMP_ADDRH		0x21	// inverter current A		
#define		EDS_INV_CUR_AMP_ADDRL		0x04	// inverter current A 		

#define		EDS_INV_RESET_ADDRH			0x20	// reset address		
#define		EDS_INV_RESET_ADDRL			0x02	// reset address 		




///////////////Inverter map redeifine///////////////////////////

///////command//////////////////////////////
#define		RD_SDO_INV_REG		EDS_RD_SDO_INV_REG
#define		RD_SDO_INV_ATB		EDS_RD_SDO_INV_ATB	
#define		RD_SDO_INV_DSR		EDS_RD_SDO_INV_DSR	
#define		WR_SDO_INV_REG		EDS_WR_SDO_INV_REG
#define		WR_SDO_INV_REG_MB	EDS_WR_SDO_INV_REG_MB

/////////////////////////////////////
/*
#define		MOTOR_TUNNING1		EDS_MOTOR_TUNNING1	//		0x02   	// PM motor tunning	1		
#define		MOTOR_TUNNING2 		EDS_MOTOR_TUNNING2	//		0x03   	// PM motor tunning	2		
#define		MOTOR_TUNNING3 		EDS_MOTOR_TUNNING3	//		0x03   	// PM motor tunning	2		



/////// parameter map//////////////////////////////
#define		IM_MOTOR	EDS_IM_MOTOR			// IM motor type		03
#define		PM_MOTOR	EDS_PM_MOTOR			// PM motor type		08



#define		MOTOR_TYPE_ADDRH		EDS_MOTOR_TYPE_ADDRH		//0x00   	// motor type
#define		MOTOR_TYPE_ADDRL		EDS_MOTOR_TYPE_ADDRL		//0x09   	// motor type



#define		MAX_HZ_ADDRH			EDS_MAX_HZ_ADDRH			// 0x01 parameter 01
#define		MAX_HZ_ADDRL			EDS_MAX_HZ_ADDRL			// 0x00 parameter 00


#define		MOTOR_VOLT_ADDRH		EDS_MOTOR_VOLT_ADDRH		// 0x01 parameter 01	
#define		MOTOR_VOLT_ADDRL		EDS_MOTOR_VOLT_ADDRL		// 0x02 parameter 02	




#define		IM_MOTOR_MAX_HZ_ADDRH	EDS_MOTOR_MAX_HZ_ADDRH		// 0x01 parameter 01 		
#define		IM_MOTOR_MAX_HZ_ADDRL	EDS_MOTOR_MAX_HZ_ADDRL		// 0x01 parameter 01 		

#define		IM_MOTOR_VOLT_ADDRH		EDS_MOTOR_VOLT_ADDRH		// 0x01 parameter 01	
#define		IM_MOTOR_VOLT_ADDRL		EDS_MOTOR_VOLT_ADDRL		// 0x02 parameter 02	

#define		IM_TUNNING_ADDRH		EDS_IM_TUNNING_ADDRH		//0x05	
#define		IM_TUNNING_ADDRL		EDS_IM_TUNNING_ADDRL		//0x00    

#define		IM_MOTOR_AMP_ADDRH		EDS_IM_MOTOR_AMP_ADDRH		//0x05
#define		IM_MOTOR_AMP_ADDRL		EDS_IM_MOTOR_AMP_ADDRL		//0x01

#define		IM_MOTOR_RPM_ADDRH		EDS_IM_MOTOR_RPM_ADDRH		//0x05
#define		IM_MOTOR_RPM_ADDRL		EDS_IM_MOTOR_RPM_ADDRL		//0x02

#define		IM_MOTOR_KW_ADDRH		EDS_IM_MOTOR_KW_ADDRH		//0x05
#define		IM_MOTOR_KW_ADDRL		EDS_IM_MOTOR_KW_ADDRL		//0x04

#define		IM_MOTOR_POLE_ADDRH		EDS_IM_MOTOR_POLE_ADDRH		//0x05
#define		IM_MOTOR_POLE_ADDRL		EDS_IM_MOTOR_POLE_ADDRL		//0x04

#define		IM_ENCODER_PULSE_ADDRH	EDS_IM_ENCODER_PULSE_ADDRH		//0x0a
#define		IM_ENCODER_PULSE_ADDRL	EDS_IM_ENCODER_PULSE_ADDRL		//0x01

#define		IM_NOLOAD_AMP_ADDRH		EDS_IM_NOLOAD_AMP_ADDRH		//0x05
#define		IM_NOLOAD_AMP_ADDRL		EDS_IM_NOLOAD_AMP_ADDRL		//0x05




#define		RUN_ZERO_SERVO_ADDRH	EDS_RUN_ZERO_SERVO_ADDRH	//0x07	
#define		RUN_ZERO_SERVO_ADDRL	EDS_RUN_ZERO_SERVO_ADDRL	//0x02    

#define		STOP_ZERO_SERVO_ADDRH	EDS_STOP_ZERO_SERVO_ADDRH	//0x07	
#define		STOP_ZERO_SERVO_ADDRL	EDS_STOP_ZERO_SERVO_ADDRL	//0x03    



#define		PM_MOTOR_MAX_HZ_ADDRH	EDS_MOTOR_MAX_HZ_ADDRH		// 0x01 parameter 01 		
#define		PM_MOTOR_MAX_HZ_ADDRL	EDS_MOTOR_MAX_HZ_ADDRL		// 0x01 parameter 01 		

#define		PM_MOTOR_VOLT_ADDRH		EDS_MOTOR_VOLT_ADDRH		// 0x01 parameter 01	
#define		PM_MOTOR_VOLT_ADDRL		EDS_MOTOR_VOLT_ADDRL		// 0x02 parameter 02	

#define		PM_TUNNING_ADDRH		EDS_PM_TUNNING_ADDRH		//0x08	
#define		PM_TUNNING_ADDRL		EDS_PM_TUNNING_ADDRL		//0x00    


#define		PM_MOTOR_AMP_ADDRH		EDS_PM_MOTOR_AMP_ADDRH		//0x08
#define		PM_MOTOR_AMP_ADDRL		EDS_PM_MOTOR_AMP_ADDRL		//0x01

#define		PM_MOTOR_KW_ADDRH		EDS_PM_MOTOR_KW_ADDRH		//0x08
#define		PM_MOTOR_KW_ADDRL		EDS_PM_MOTOR_KW_ADDRL		//0x02

#define		PM_MOTOR_RPM_ADDRH		EDS_PM_MOTOR_RPM_ADDRH		//0x08
#define		PM_MOTOR_RPM_ADDRL		EDS_PM_MOTOR_RPM_ADDRL		//0x03

#define		PM_MOTOR_POLE_ADDRH		EDS_PM_MOTOR_POLE_ADDRH		//0x08
#define		PM_MOTOR_POLE_ADDRL		EDS_PM_MOTOR_POLE_ADDRL		//0x04

#define		PM_ENCODER_PULSE_ADDRH	EDS_PM_ENCODER_PULSE_ADDRH		//0x0a
#define		PM_ENCODER_PULSE_ADDRL	EDS_PM_ENCODER_PULSE_ADDRL		//0x01

#define		PM_MOTOR_DEG_ADDRH		EDS_PM_MOTOR_DEG_ADDRH		//0x08
#define		PM_MOTOR_DEG_ADDRL		EDS_PM_MOTOR_DEG_ADDRL		//0x09



#define		ENCODER_PHASE_ADDRH		EDS_ENCODER_PHASE_ADDRH		//0x0a	
#define		ENCODER_PHASE_ADDRL		EDS_ENCODER_PHASE_ADDRL		//0x02    


#define		MAX_EV_SPD_ADDRH		EDS_MAX_EV_SPD_ADDRH		//0x0b 		
#define		MAX_EV_SPD_ADDRL		EDS_MAX_EV_SPD_ADDRL		//0x01  		

#define		EL_SHIVE_ADDRH			EDS_EL_SHIVE_ADDRH			//0x0b	
#define		EL_SHIVE_ADDRL			EDS_EL_SHIVE_ADDRL			//0x02    

#define		EL_GEAR_ADDRH			EDS_EL_GEAR_ADDRH			//0x0b	
#define		EL_GEAR_ADDRL			EDS_EL_GEAR_ADDRL			//0x03    

#define		INER_RATIO_ADDRH		EDS_INER_RATIO_ADDRH		//0x0b	
#define		INER_RATIO_ADDRL		EDS_INER_RATIO_ADDRL		//0x05   

#define		BANDWITH_ADDRH			EDS_BANDWITH_ADDRH			//0x0b	//??
#define		BANDWITH_ADDRL			EDS_BANDWITH_ADDRL			//0x06    //??




#define		DEC_TIME_ADDRH			EDS_DEC_TIME_ADDRH			// 0x01 parameter 01 group		
#define		DEC_TIME_ADDRL			EDS_DEC_TIME_ADDRL			// 0x0d	parameter 13 		

#define		S_CUV_TIME1_ADDRH		EDS_S_CUV_TIME1_ADDRH		// 0x01 parameter 01 group		
#define		S_CUV_TIME1_ADDRL		EDS_S_CUV_TIME1_ADDRL		// 0x1a	parameter 26  first scurve 		





#define		INV_ERR_ADDRH			EDS_INV_ERR_ADDRH			// 0x06 inverter err parameter 06 group		
#define		INV_ERR_ADDRL			EDS_INV_ERR_ADDRL			// 0x10 inverter err parameter 16 current Error 		


#define		INV_CUR_AMP_ADDRH		EDS_INV_CUR_AMP_ADDRH		// 0x21	inverter current A		
#define		INV_CUR_AMP_ADDRL		EDS_INV_CUR_AMP_ADDRL		// 0x04	inverter current A 		

#define		INV_RESET_ADDRH			EDS_INV_RESET_ADDRH			//0x20	// reset address		
#define		INV_RESET_ADDRL			EDS_INV_RESET_ADDRL			//0x02	// reset address 		

*/



#define		EDS_DEC_SPD_PORTH			0x04	
#define		EDS_DEC_SPD_PORTL			0x00    

#define		EDS_MANUAL_SPD_PORTH		0x04	
#define		EDS_MANUAL_SPD_PORTL		0x00    

#define		EDS_LOW_SPD_PORTH			0x04	
#define		EDS_LOW_SPD_PORTL			0x00    

#define		EDS_MID_SPD_PORTH			0x04	
#define		EDS_MID_SPD_PORTL			0x00    

#define		EDS_HIGH_SPD_PORTH			0x04	
#define		EDS_HIGH_SPD_PORTL			0x00    

#endif



