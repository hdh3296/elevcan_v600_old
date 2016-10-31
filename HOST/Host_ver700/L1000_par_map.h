


//#ifdef	AUTO_LANDING_COMM

#ifdef	AUTO_LANDING_485

/////rd/wr cmd value///////////////
#define		L1000_RD_SDO_INV_REG		0x03	
//#define		EDS_RD_SDO_INV_ATB			0x60	
//#define		EDS_RD_SDO_INV_DSR			0x61	
//#define		EDS_WR_SDO_INV_REG			0x06
#define		L1000_WR_SDO_INV_REG_MB		0x10
/////////////////////////////////////


#define		L1000_MOTOR_TUNNING1		0x01   	// PM motor tunning	1	????	
#define		L1000_MOTOR_TUNNING2		0x03   	// PM motor tunning	2	??????	
#define		L1000_MOTOR_TUNNING3		0x04   	// PM motor tunning	2	??????	


#define		L1000_IM_MOTOR				0x03   	// IM motor type		
#define		L1000_PM_MOTOR				0x07   	// PM motor type		






//////////////////memory address////////////////////////////////

#define		L1000_MOTOR_TYPE_ADDRH		0x01   	// A1 // motor type		
#define		L1000_MOTOR_TYPE_ADDRL		0x02   	// 02 //motor type 		


/////////////////////////////////////////////////////////////////
#define		L1000_MAX_HZ_ADDRH			0x03   	//E1   //parameter 03 		
#define		L1000_MAX_HZ_ADDRL			0x05	//06   //parameter 03 		


#define		L1000_S_CUV_TIME1_ADDRH		0x02   	// C2		
#define		L1000_S_CUV_TIME1_ADDRL		0x0d 	// 03 		

#define		L1000_DEC_TIME_ADDRH		0x02   	// C1		
#define		L1000_DEC_TIME_ADDRL		0x01  	// 02 		
//////////////////////////////////////////////////////



/////////////////////IM MOTOR/////////////////////////////////
#define		L1000_IM_MOTOR_MAX_HZ_ADDRH	0x07   	//T1	//zzz 		
#define		L1000_IM_MOTOR_MAX_HZ_ADDRL	0x05	//05 	//zzz	

#define		L1000_IM_MOTOR_VOLT_ADDRH	0x07	//T1   //zz
#define		L1000_IM_MOTOR_VOLT_ADDRL	0x03	//03   //zz

#define		L1000_IM_MOTOR_AMP_ADDRH	0x07    //T1
#define		L1000_IM_MOTOR_AMP_ADDRL	0x04    //04

#define		L1000_IM_MOTOR_KW_ADDRH		0x07    //T1
#define		L1000_IM_MOTOR_KW_ADDRL		0x02    //02

#define		L1000_IM_MOTOR_RPM_ADDRH	0x07    //T1		
#define		L1000_IM_MOTOR_RPM_ADDRL	0x07    //07 		

#define		L1000_IM_MOTOR_POLE_ADDRH	0x07    //T1
#define		L1000_IM_MOTOR_POLE_ADDRL	0x06    //06

#define		L1000_IM_ENCODER_PULSE_ADDRH	0x07	//T1
#define		L1000_IM_ENCODER_PULSE_ADDRL	0x08    //08

#define		L1000_IM_NOLOAD_AMP_ADDRH	0x07	//T1
#define		L1000_IM_NOLOAD_AMP_ADDRL	0x09    //09

#define		L1000_IM_TUNNING_ADDRH		0x07	//T1
#define		L1000_IM_TUNNING_ADDRL		0x01    //01



///////////////////////pm motor/////////////
#define		L1000_PM_MOTOR_MAX_HZ_ADDRH	0x07   	//T1  		
#define		L1000_PM_MOTOR_MAX_HZ_ADDRL	0x05	//05  		

#define		L1000_PM_MOTOR_VOLT_ADDRH	0x07	//T2
#define		L1000_PM_MOTOR_VOLT_ADDRL	0x32	//05

#define		L1000_PM_MOTOR_AMP_ADDRH	0x07	//T2
#define		L1000_PM_MOTOR_AMP_ADDRL	0x33    //06

#define		L1000_PM_MOTOR_KW_ADDRH		0x07	//T2
#define		L1000_PM_MOTOR_KW_ADDRL		0x30    //04

#define		L1000_PM_MOTOR_RPM_ADDRH	0x07    //T2		
#define		L1000_PM_MOTOR_RPM_ADDRL	0x31    //09 		

#define		L1000_PM_MOTOR_POLE_ADDRH	0x07    //T2
#define		L1000_PM_MOTOR_POLE_ADDRL	0x34    //08

#define		L1000_PM_ENCODER_PULSE_ADDRH	0x07	//T2
#define		L1000_PM_ENCODER_PULSE_ADDRL	0x38    //16

#define		L1000_PM_MOTOR_DEG_ADDRH	0x03    //E5
#define		L1000_PM_MOTOR_DEG_ADDRL	0x11    //11

#define		L1000_PM_TUNNING_ADDRH		0x07	//T2
#define		L1000_PM_TUNNING_ADDRL		0x50    //01



#define		L1000_ENCODER_PHASE_ADDRH	0x03	//F1	
#define		L1000_ENCODER_PHASE_ADDRL	0x84    //05



#define		L1000_MAX_EV_SPD_ADDRH		0x0b	//?????????
#define		L1000_MAX_EV_SPD_ADDRL		0x01    //????????????????

#define		L1000_EL_SHIVE_ADDRH		0x0b	
#define		L1000_EL_SHIVE_ADDRL		0x02    

#define		L1000_EL_GEAR_ADDRH			0x0b	
#define		L1000_EL_GEAR_ADDRL			0x03    


#define		L1000_RUN_ZERO_SERVO_ADDRH	0x06	//S3	
#define		L1000_RUN_ZERO_SERVO_ADDRL	0x97    //01

#define		L1000_STOP_ZERO_SERVO_ADDRH	0x06	//S3
#define		L1000_STOP_ZERO_SERVO_ADDRL	0x99    //03


#define		L1000_INER_RATIO_ADDRH		0x02	//C5  gain1
#define		L1000_INER_RATIO_ADDRL		0x1b    //01

#define		L1000_BANDWITH_ADDRH		0x02	//c5  gain2
#define		L1000_BANDWITH_ADDRL		0x1d    //03



///////////////////////////////////////////////////////////////
#define		L1000_INV_ERR_ADDRH			0x00	// U2  inverter err parameter	
#define		L1000_INV_ERR_ADDRL			0x80	// 01  inverter err parameter  		
/////////////////////////////////////////////////////////


#define		L1000_INV_CUR_AMP_ADDRH		0x00	// U1  inverter current A	
#define		L1000_INV_CUR_AMP_ADDRL		0x42	// 03  inverter current A 		

#define		L1000_INV_RESET_ADDRH		0x20	// reset address  //??????????????		
#define		L1000_INV_RESET_ADDRL		0x02	// reset address  //??????????????		



#define		L1000_EDS_MAX_EV_SPD_ADDRH	0x00	//?????????
#define		L1000_EDS_MAX_EV_SPD_ADDRL	0x00	//??????????????


#define		L1000_DEC_SPD_PORTH			0x02	
#define		L1000_DEC_SPD_PORTL			0x80    

#define		L1000_MANUAL_SPD_PORTH		0x02	
#define		L1000_MANUAL_SPD_PORTL		0x80    

#define		L1000_LOW_SPD_PORTH			0x02	
#define		L1000_LOW_SPD_PORTL			0x80    

#define		L1000_MID_SPD_PORTH			0x02	
#define		L1000_MID_SPD_PORTL			0x80    

#define		L1000_HIGH_SPD_PORTH		0x02	
#define		L1000_HIGH_SPD_PORTL		0x80    


///////////////Inverter map redeifine///////////////////////////

/*
///////command//////////////////////////////
#define		RD_SDO_INV_REG		L1000_RD_SDO_INV_REG
//#define		RD_SDO_INV_ATB		L1000_RD_SDO_INV_ATB	
//#define		RD_SDO_INV_DSR		L1000_RD_SDO_INV_DSR	
//#define		WR_SDO_INV_REG		L1000_WR_SDO_INV_REG
#define		WR_SDO_INV_REG_MB	L1000_WR_SDO_INV_REG_MB

/////////////////////////////////////


#define		MOTOR_TUNNING1		L1000_MOTOR_TUNNING1	//		0x01   	// PM motor tunning	1		
#define		MOTOR_TUNNING2 		L1000_MOTOR_TUNNING2	//		0x03   	// PM motor tunning	2		
#define		MOTOR_TUNNING3 		L1000_MOTOR_TUNNING3	//		0x04   	// PM motor tunning	2		


/////// parameter map//////////////////////////////
#define		IM_MOTOR				L1000_IM_MOTOR				// IM motor type		03
#define		PM_MOTOR				L1000_PM_MOTOR				// PM motor type		08



#define		MOTOR_TYPE_ADDRH		L1000_MOTOR_TYPE_ADDRH		//0x00   	// motor type
#define		MOTOR_TYPE_ADDRL		L1000_MOTOR_TYPE_ADDRL		//0x09   	// motor type



#define		MAX_HZ_ADDRH			L1000_MAX_HZ_ADDRH			// 0x01 parameter 01
#define		MAX_HZ_ADDRL			L1000_MAX_HZ_ADDRL			// 0x00 parameter 00



#define		DEC_TIME_ADDRH			L1000_DEC_TIME_ADDRH			// 0x01 parameter 01 group		
#define		DEC_TIME_ADDRL			L1000_DEC_TIME_ADDRL			// 0x0d	parameter 13 		

#define		S_CUV_TIME1_ADDRH		L1000_S_CUV_TIME1_ADDRH		// 0x01 parameter 01 group		
#define		S_CUV_TIME1_ADDRL		L1000_S_CUV_TIME1_ADDRL		// 0x1a	parameter 26  first scurve 		


#define		IM_MOTOR_MAX_HZ_ADDRH	L1000_IM_MOTOR_MAX_HZ_ADDRH		// 0x01 parameter 01 		
#define		IM_MOTOR_MAX_HZ_ADDRL	L1000_IM_MOTOR_MAX_HZ_ADDRL		// 0x01 parameter 01 		

#define		IM_MOTOR_VOLT_ADDRH		L1000_IM_MOTOR_VOLT_ADDRH		// 0x01 parameter 01	
#define		IM_MOTOR_VOLT_ADDRL		L1000_IM_MOTOR_VOLT_ADDRL		// 0x02 parameter 02	

#define		IM_TUNNING_ADDRH		L1000_IM_TUNNING_ADDRH		//0x05	
#define		IM_TUNNING_ADDRL		L1000_IM_TUNNING_ADDRL		//0x00    

#define		IM_MOTOR_AMP_ADDRH		L1000_IM_MOTOR_AMP_ADDRH		//0x05
#define		IM_MOTOR_AMP_ADDRL		L1000_IM_MOTOR_AMP_ADDRL		//0x01

#define		IM_MOTOR_RPM_ADDRH		L1000_IM_MOTOR_RPM_ADDRH		//0x05
#define		IM_MOTOR_RPM_ADDRL		L1000_IM_MOTOR_RPM_ADDRL		//0x02

#define		IM_MOTOR_KW_ADDRH		L1000_IM_MOTOR_KW_ADDRH		//0x05
#define		IM_MOTOR_KW_ADDRL		L1000_IM_MOTOR_KW_ADDRL		//0x04

#define		IM_MOTOR_POLE_ADDRH		L1000_IM_MOTOR_POLE_ADDRH		//0x05
#define		IM_MOTOR_POLE_ADDRL		L1000_IM_MOTOR_POLE_ADDRL		//0x04

#define		IM_ENCODER_PULSE_ADDRH	L1000_IM_ENCODER_PULSE_ADDRH		
#define		IM_ENCODER_PULSE_ADDRL	L1000_IM_ENCODER_PULSE_ADDRL		


#define		IM_NOLOAD_AMP_ADDRH		L1000_IM_NOLOAD_AMP_ADDRH		//0x05
#define		IM_NOLOAD_AMP_ADDRL		L1000_IM_NOLOAD_AMP_ADDRL		//0x05


#define		INV_ERR_ADDRH			L1000_INV_ERR_ADDRH			// 0x06 inverter err parameter 06 group		
#define		INV_ERR_ADDRL			L1000_INV_ERR_ADDRL			// 0x10 inverter err parameter 16 current Error 		


#define		RUN_ZERO_SERVO_ADDRH	L1000_RUN_ZERO_SERVO_ADDRH	//0x07	
#define		RUN_ZERO_SERVO_ADDRL	L1000_RUN_ZERO_SERVO_ADDRL	//0x02    

#define		STOP_ZERO_SERVO_ADDRH	L1000_STOP_ZERO_SERVO_ADDRH	//0x07	
#define		STOP_ZERO_SERVO_ADDRL	L1000_STOP_ZERO_SERVO_ADDRL	//0x03    



#define		PM_MOTOR_MAX_HZ_ADDRH	L1000_PM_MOTOR_MAX_HZ_ADDRH		// 0x01 parameter 01 		
#define		PM_MOTOR_MAX_HZ_ADDRL	L1000_PM_MOTOR_MAX_HZ_ADDRL		// 0x01 parameter 01 		

#define		PM_MOTOR_VOLT_ADDRH		L1000_PM_MOTOR_VOLT_ADDRH		// 0x01 parameter 01	
#define		PM_MOTOR_VOLT_ADDRL		L1000_PM_MOTOR_VOLT_ADDRL		// 0x02 parameter 02	

#define		PM_TUNNING_ADDRH		L1000_PM_TUNNING_ADDRH		//0x08	
#define		PM_TUNNING_ADDRL		L1000_PM_TUNNING_ADDRL		//0x00    


#define		PM_MOTOR_AMP_ADDRH		L1000_PM_MOTOR_AMP_ADDRH		//0x08
#define		PM_MOTOR_AMP_ADDRL		L1000_PM_MOTOR_AMP_ADDRL		//0x01

#define		PM_MOTOR_KW_ADDRH		L1000_PM_MOTOR_KW_ADDRH		//0x08
#define		PM_MOTOR_KW_ADDRL		L1000_PM_MOTOR_KW_ADDRL		//0x02

#define		PM_MOTOR_RPM_ADDRH		L1000_PM_MOTOR_RPM_ADDRH		//0x08
#define		PM_MOTOR_RPM_ADDRL		L1000_PM_MOTOR_RPM_ADDRL		//0x03

#define		PM_MOTOR_POLE_ADDRH		L1000_PM_MOTOR_POLE_ADDRH		//0x08
#define		PM_MOTOR_POLE_ADDRL		L1000_PM_MOTOR_POLE_ADDRL		//0x04

#define		PM_ENCODER_PULSE_ADDRH		L1000_PM_ENCODER_PULSE_ADDRH		//0x0a
#define		PM_ENCODER_PULSE_ADDRL		L1000_PM_ENCODER_PULSE_ADDRL		//0x01

#define		PM_MOTOR_DEG_ADDRH		L1000_PM_MOTOR_DEG_ADDRH		//0x08
#define		PM_MOTOR_DEG_ADDRL		L1000_PM_MOTOR_DEG_ADDRL		//0x09



//#define		ENCODER_PULSE_ADDRH		L1000_ENCODER_PULSE_ADDRH		//0x0a
//#define		ENCODER_PULSE_ADDRL		L1000_ENCODER_PULSE_ADDRL		//0x01

#define		ENCODER_PHASE_ADDRH		L1000_ENCODER_PHASE_ADDRH		//0x0a	
#define		ENCODER_PHASE_ADDRL		L1000_ENCODER_PHASE_ADDRL		//0x02    


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





#define		INV_CUR_AMP_ADDRH		L1000_INV_CUR_AMP_ADDRH		// 0x21	inverter current A		
#define		INV_CUR_AMP_ADDRL		L1000_INV_CUR_AMP_ADDRL		// 0x04	inverter current A 		

#define		INV_RESET_ADDRH			L1000_INV_RESET_ADDRH			//0x20	// reset address		
#define		INV_RESET_ADDRL			L1000_INV_RESET_ADDRL			//0x02	// reset address 		
*/

#endif



