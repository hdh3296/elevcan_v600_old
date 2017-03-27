
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



#ifdef	AUTO_LANDING_COMM	







const unsigned char INVERTER_PAR[] 		={"Inv:00          "};
const unsigned char INVERTER_VAL[] 		={"00:             "};



const unsigned char IM_NO_LOAD[] 		={"MOTOR:NoLoad Amp"};


#define	MAX_MOTOR_PARAM	32
const unsigned char MOTOR_GROUP_MSG[MAX_MOTOR_PARAM][16]={   
                                    "MOTOR: PM/IM    ",	//00
                                    "MOTOR: Max Hz   ", //01
                                    "MOTOR: Motor Hz ",	//02 
                                    "MOTOR:Motor Volt",	//03   
                                    "MOTOR: Motor Amp",	//04   
                                    "MOTOR: Motor Kw ",	//05   
                                    "MOTOR: Motor Rpm",	//06   
                                    "MOTOR:Motor Pole",	//07   
                                    "MOTOR: PM Deg   ",	//08     //MOTOR:NoLoad Amp 
                                    "MOTOR:Enc Pulse ",	//09   
                                    "MOTOR:Enc Phase ",	//10   
                                    "MOTOR:Dc RunGain",	//11   
                                    "MOTOR:DcStopGain",	//12   
                                    "MOTOR: P-Gain   ",	//13   
                                    "MOTOR: I-Gain   ",	//14   
                                    "MOTOR: Reserve  ",	//15   
                                    "MOTOR: Reserve  ",	//16   
                                    "MOTOR: Reserve  ",	//17   
                                    "MOTOR: Reserve  ",	//18   
                                    "MOTOR: Reserve  ",	//19   
                                    "MOTOR: Reserve  ",	//20   
                                    "MOTOR: Reserve  ",	//21   
                                    "MOTOR: Reserve  ",	//22   
                                    "MOTOR: Reserve  ",	//23   
                                    "MOTOR: Reserve  ",	//24   
                                    "MOTOR: Reserve  ",	//25   
                                    "MOTOR: Reserve  ",	//26   
                                    "MOTOR: Reserve  ",	//27   
                                    "MOTOR:E Spd(m/s)",	//28   
                                    "MOTOR:SheaveSize",	//29   
                                    "MOTOR:Susp Ratio",	//30   
                                    "MOTOR: Tunning  ",	//31   
							};		
										   


unsigned char *MenuName;		




unsigned int InverterAddress;
unsigned int IM_Motor_ID;
unsigned int PM_Motor_ID;

unsigned int TunningValue1;
unsigned int TunningValue2;
unsigned int TunningValue3;

unsigned int Addr_MotorType;
unsigned int Addr_MaxHz;
unsigned int Addr_MaxEvSpd;
unsigned int Addr_IM_MotorHz;
unsigned int Addr_PM_MotorHz;
unsigned int Addr_IM_MotorVlot;
unsigned int Addr_PM_MotorVlot;
unsigned int Addr_IM_MotorAmp;
unsigned int Addr_PM_MotorAmp;
unsigned int Addr_IM_MotorKw;
unsigned int Addr_PM_MotorKw;
unsigned int Addr_IM_MotorRpm;
unsigned int Addr_PM_MotorRpm;
unsigned int Addr_IM_MotorPole;
unsigned int Addr_PM_MotorPole;
unsigned int Addr_IM_NoLdAmp;
unsigned int Addr_PM_MotorDeg;
unsigned int Addr_IM_EncoderPulse;
unsigned int Addr_PM_EncoderPulse;
unsigned int Addr_EncoderAB;
unsigned int Addr_Run_Zero;
unsigned int Addr_Stop_Zero;
unsigned int Addr_Gain1;
unsigned int Addr_Gain2;
unsigned int Addr_IM_Tunning;
unsigned int Addr_PM_Tunning;


unsigned int Addr_Dec_Time;
unsigned int Addr_SCurve_Time;
unsigned int Addr_DecSpdPort;
unsigned int Addr_ManualSpdPort;
unsigned int Addr_LowSpdPort;
unsigned int Addr_MidSpdPort;
unsigned int Addr_HighSpdPort;


unsigned int Addr_CurError;
unsigned int Addr_CurAmp;
unsigned int Addr_Reset;



unsigned char ThisRdWrAddrH,ThisRdWrAddrL,ThisRdWrWNm,ThisRdWrValueH,ThisRdWrValueL,ThisRdWrMode;		

unsigned char GroupParaAddrH,GroupParaAddrL;



LocalType __attribute__((section(".usercode"))) EDS_VL_485_Check(void)
{
#ifdef	AUTO_LANDING_485
	if( (WhoAutolanding == (unsigned int)EDS_AUTOLANDING_485))			return(1);
	else if( (WhoAutolanding == (unsigned int)VL_AUTOLANDING_485))		return(1);
	else if( (WhoAutolanding == (unsigned int)L1000_AUTOLANDING_485))	return(1);
	else																return(0);
#else
	return(0);
#endif

}





LocalType __attribute__((section(".usercode"))) ReadAttribute(unsigned char addressH,unsigned char addressL)
{

#ifdef	AUTO_LANDING_485
	if(EDS_VL_485_Check()){
		return(Delta_ReadAttribute_485( (unsigned char)(addressH),(unsigned char)(addressL)));
	}
#endif

#ifdef		AUTO_LANDING_CAN			
	if((WhoAutolanding == (unsigned int)EDS_AUTOLANDING_CAN) ){
		return(Delta_ReadAttribute_CAN( (unsigned char)(addressH),(unsigned char)(addressL)));
	}
	
	#ifdef		DELTA_INVERTER_AUTOLANDING_CAN				
		if((WhoAutolanding == (unsigned int)DELTA_INVERTER_AUTOLANDING_CAN) ){
			return(Delta_ReadAttribute_CAN( (unsigned char)(addressH),(unsigned char)(addressL)));
		}
	#endif

#endif

	return(0);
}



LocalType __attribute__((section(".usercode"))) ReadParameter(unsigned char addressH,unsigned char addressL,unsigned char ReadWordNm)
{
#ifdef	AUTO_LANDING_485
	if(EDS_VL_485_Check()){	
		return(Delta_ReadParameter_485( (unsigned char)(addressH),(unsigned char)(addressL),(unsigned char)(ReadWordNm)));
	}
#endif

#ifdef		AUTO_LANDING_CAN			
	if((WhoAutolanding == (unsigned int)EDS_AUTOLANDING_CAN) ){
		return(Delta_ReadParameter_CAN( (unsigned char)(addressH),(unsigned char)(addressL),(unsigned char)(ReadWordNm)));
	}

	#ifdef		DELTA_INVERTER_AUTOLANDING_CAN				
		if((WhoAutolanding == (unsigned int)DELTA_INVERTER_AUTOLANDING_CAN) ){
			return(Delta_ReadParameter_CAN( (unsigned char)(addressH),(unsigned char)(addressL),(unsigned char)(ReadWordNm)));
		}
	#endif
#endif

	return(0);
}


LocalType __attribute__((section(".usercode"))) AddrWriteParameter(unsigned char addressH,unsigned char addressL,unsigned char WriteWordNm,unsigned char valH,unsigned char valL)
{

#ifdef	AUTO_LANDING_485
	if(EDS_VL_485_Check()){	
		return(Delta_WriteParameter_485_Multi((unsigned char)addressH,(unsigned char)(addressL),(unsigned char)(WriteWordNm),(unsigned char)(valH),(unsigned char)(valL)));
	}
#endif

#ifdef		AUTO_LANDING_CAN			
	if((WhoAutolanding == (unsigned int)EDS_AUTOLANDING_CAN) ){
		return(Delta_WriteParameter_CAN((unsigned char)addressH,(unsigned char)(addressL),(unsigned char)(WriteWordNm),(unsigned char)(valH),(unsigned char)(valL)));
	}

	#ifdef		DELTA_INVERTER_AUTOLANDING_CAN				
		if((WhoAutolanding == (unsigned int)DELTA_INVERTER_AUTOLANDING_CAN) ){
			return(Delta_WriteParameter_CAN((unsigned char)addressH,(unsigned char)(addressL),(unsigned char)(WriteWordNm),(unsigned char)(valH),(unsigned char)(valL)));
		}
	#endif
#endif
	return(0);
}






LocalType  __attribute__((section(".usercode"))) Inverter_MotorGroup_Attribute(void)
{

#ifdef	AUTO_LANDING_485
	if(WhoAutolanding==L1000_AUTOLANDING_485){
		switch(LadderGroupSub){
			case	NM_MOTOR_TYPE:
				DigitAttribute=0;
				DigitMinValue=0;
				DigitMaxValue=7;
				break;	
			case	NM_INV_MAX_HZ:
				DigitAttribute=1;
				DigitMinValue=0;
				DigitMaxValue=1200;
				break;	
			case	NM_MOTOR_MAX_HZ:
				DigitAttribute=1;
				DigitMinValue=0;
				DigitMaxValue=1200;
				break;	
			case	NM_MOTOR_MAX_VOLT:
				DigitAttribute=1;
				DigitMinValue=0;
				DigitMaxValue=2550;
				break;	
			case	NM_MOTOR_MAX_AMP:	// ????
				DigitAttribute=1;
				DigitMinValue=0;
				DigitMaxValue=3000;
				break;
			case	NM_MOTOR_MAX_KW:	// motor kw
				DigitAttribute=2;
				DigitMinValue=0;
				DigitMaxValue=65000;
				break;
			case	NM_MOTOR_MAX_RPM:	// motor rpm
				DigitAttribute=0;
				DigitMinValue=0;
				DigitMaxValue=24000;
				break;	
			case	NM_MOTOR_POLE:	// motor pole
				DigitAttribute=0;
				DigitMinValue=2;
				DigitMaxValue=48;
				break;
			case	NM_MOTOR_NOLOAD_DEG:	// IM= NO Load Current, PM=DEG
				DigitAttribute=1;
				DigitMinValue=0;
				DigitMaxValue=3600;
				break;	
			case	NM_ENCODER_PULSE:	// ENCODER PULSE
				DigitAttribute=0;
				DigitMinValue=0;
				DigitMaxValue=60000;
				break;	
			case	NM_ENCODER_PHASE:	// ENCODER AB
				DigitAttribute=0;
				DigitMinValue=0;
				DigitMaxValue=1;
				break;	
			case	NM_RUN_ZERO:	// BRAKE CHOPPER LEVEL  7-2
				DigitAttribute=0;
				DigitMinValue=0;
				DigitMaxValue=100;
				break;	
			case	NM_STOP_ZERO:	// BRAKE CHOPPER LEVEL  7-3
				DigitAttribute=0;
				DigitMinValue=0;
				DigitMaxValue=100;
				break;	
			case	NM_MOTOR_GAIN1:	//GAIN1  11-5
				DigitAttribute=2;
				DigitMinValue=0;
				DigitMaxValue=65000;
				break;	
			case	NM_MOTOR_GAIN2:	//GAIN2  11-6
				DigitAttribute=2;
				DigitMinValue=0;
				DigitMaxValue=65000;
				break;
			case	NM_AUTO_TUNNING_NM:	//autotunning
				DigitAttribute=0;
				DigitMinValue=0;
				DigitMaxValue=11;
				break;	
			default:
				break;
	
		}
	}
#endif

	return(0);
}


void  __attribute__((section(".usercode"))) Inv_Par_DataSort(unsigned int this_data)
{
	unsigned int dp,i;

	if((ThisRdWrAddrH==GroupParaAddrH) && (ThisRdWrAddrL==GroupParaAddrL)){
		dp=IV_This_Attrv;
	
		dp=(dp & 0x0300);
		if( 	 dp == 0x0100)	dp=1;
		else if( dp == 0x0200)	dp=2;
		else if( dp == 0x0300)	dp=3;
		else					dp=0;
	
	
		DigitAttribute=dp;
		DigitMinValue=IV_This_Min;
		DigitMaxValue=IV_This_Max;



		Inverter_MotorGroup_Attribute();	// no attribute other inverter 
		
		EditStatus=DIGIT_EDIT;	
		DigitData=this_data;	
		NewdigitEdit(this_data);
	}
		
	ThisRdWrMode=RDWR_READY_SEQ;
	ParRdWrNm=INVETER_NOT_SEL_SEQ;
}




LocalType  __attribute__((section(".usercode"))) Inverter_MotorGroup_Rd(void)
{
	unsigned int ret;

	ret=0;

	if( (LadderGroupSub >= 15) &&  (LadderGroupSub <= 30)){
    	if(LadderKey == 'u')		LadderGroupSub = 31;
    	else if(LadderKey == 'd')	LadderGroupSub = 14;
	}

	switch(LadderGroupSub){
		case	0:
			GroupParaAddrH=(unsigned char)(Addr_MotorType >> 8);
			GroupParaAddrL=(unsigned char)(Addr_MotorType);
			break;	
		case	1:
			GroupParaAddrH=(unsigned char)(Addr_MaxHz >> 8);
			GroupParaAddrL=(unsigned char)(Addr_MaxHz);
			break;	
		case	2:
			if(xVarMotorType==IM_Motor_ID){     // IM	
				GroupParaAddrH=(unsigned char)(Addr_IM_MotorHz >> 8);
				GroupParaAddrL=(unsigned char)(Addr_IM_MotorHz);
			}
			else if(xVarMotorType==PM_Motor_ID){ // PM
				GroupParaAddrH=(unsigned char)(Addr_PM_MotorHz >> 8);
				GroupParaAddrL=(unsigned char)(Addr_PM_MotorHz);
			}
			break;	
		case	3:
			if(xVarMotorType==IM_Motor_ID){     // IM	
				GroupParaAddrH=(unsigned char)(Addr_IM_MotorVlot >> 8);
				GroupParaAddrL=(unsigned char)(Addr_IM_MotorVlot);
			}
			else if(xVarMotorType==PM_Motor_ID){ // PM
				GroupParaAddrH=(unsigned char)(Addr_PM_MotorVlot >> 8);
				GroupParaAddrL=(unsigned char)(Addr_PM_MotorVlot);
			}
			break;	
		case	4:	// motor current
			if(xVarMotorType==IM_Motor_ID){     // IM
				GroupParaAddrH=(unsigned char)(Addr_IM_MotorAmp >> 8);
				GroupParaAddrL=(unsigned char)(Addr_IM_MotorAmp);
			}
			else if(xVarMotorType==PM_Motor_ID){ // PM
				GroupParaAddrH=(unsigned char)(Addr_PM_MotorAmp >> 8);
				GroupParaAddrL=(unsigned char)(Addr_PM_MotorAmp);
			}
			break;
		case	5:	// motor kw
			if(xVarMotorType==IM_Motor_ID){     // IM	
				GroupParaAddrH=(unsigned char)(Addr_IM_MotorKw >> 8);
				GroupParaAddrL=(unsigned char)(Addr_IM_MotorKw);
			}
			else if(xVarMotorType==PM_Motor_ID){ // PM
				GroupParaAddrH=(unsigned char)(Addr_PM_MotorKw >> 8);
				GroupParaAddrL=(unsigned char)(Addr_PM_MotorKw);
			}
			break;
		case	6:	// motor rpm
			if(xVarMotorType==IM_Motor_ID){     // IM	
				GroupParaAddrH=(unsigned char)(Addr_IM_MotorRpm >> 8);
				GroupParaAddrL=(unsigned char)(Addr_IM_MotorRpm);
			}
			else if(xVarMotorType==PM_Motor_ID){ // PM
				GroupParaAddrH=(unsigned char)(Addr_PM_MotorRpm >> 8);
				GroupParaAddrL=(unsigned char)(Addr_PM_MotorRpm);
			}
			break;	
		case	7:	// motor pole
			if(xVarMotorType==IM_Motor_ID){     // IM	
				GroupParaAddrH=(unsigned char)(Addr_IM_MotorPole >> 8);
				GroupParaAddrL=(unsigned char)(Addr_IM_MotorPole);
			}
			else if(xVarMotorType==PM_Motor_ID){ // PM
				GroupParaAddrH=(unsigned char)(Addr_PM_MotorPole >> 8);
				GroupParaAddrL=(unsigned char)(Addr_PM_MotorPole);
			}
			break;
		case	8:	// IM= NO Load Current, PM=DEG
			if(xVarMotorType==IM_Motor_ID){     // IM	
				GroupParaAddrH=(unsigned char)(Addr_IM_NoLdAmp >> 8);
				GroupParaAddrL=(unsigned char)(Addr_IM_NoLdAmp);
			}
			else if(xVarMotorType==PM_Motor_ID){ // PM
				GroupParaAddrH=(unsigned char)(Addr_PM_MotorDeg >> 8);
				GroupParaAddrL=(unsigned char)(Addr_PM_MotorDeg);
			}
			break;	
		case	9:	// ENCODER PULSE
			if(xVarMotorType==IM_Motor_ID){     // IM	
				GroupParaAddrH=(unsigned char)(Addr_IM_EncoderPulse >> 8);
				GroupParaAddrL=(unsigned char)(Addr_IM_EncoderPulse);
			}
			else if(xVarMotorType==PM_Motor_ID){ // PM
				GroupParaAddrH=(unsigned char)(Addr_IM_EncoderPulse >> 8);
				GroupParaAddrL=(unsigned char)(Addr_PM_EncoderPulse);
			}
			break;	
		case	10:	// ENCODER AB
			GroupParaAddrH=(unsigned char)(Addr_EncoderAB >> 8);
			GroupParaAddrL=(unsigned char)(Addr_EncoderAB);
			break;	
		case	11:	// BRAKE CHOPPER LEVEL  7-2
			GroupParaAddrH=(unsigned char)(Addr_Run_Zero >> 8);
			GroupParaAddrL=(unsigned char)(Addr_Run_Zero);
			break;	
		case	12:	// BRAKE CHOPPER LEVEL  7-3
			GroupParaAddrH=(unsigned char)(Addr_Stop_Zero >> 8);
			GroupParaAddrL=(unsigned char)(Addr_Stop_Zero);
			break;	
		case	13:	//GAIN1  11-5
			GroupParaAddrH=(unsigned char)(Addr_Gain1 >> 8);
			GroupParaAddrL=(unsigned char)(Addr_Gain1);
			break;	
		case	14:	//GAIN2  11-6
			GroupParaAddrH=(unsigned char)(Addr_Gain2 >> 8);
			GroupParaAddrL=(unsigned char)(Addr_Gain2);
			break;
/*	
		case	28:	//EL SPEED	m/s
			GroupParaAddrH=MAX_EV_SPD_ADDRH;
			GroupParaAddrL=MAX_EV_SPD_ADDRL;
			break;	
		case	29:	//SHIVE SIZE
			GroupParaAddrH=EL_SHIVE_ADDRH;
			GroupParaAddrL=EL_SHIVE_ADDRL;
			break;	
		case	30:	//GEAR RATIO
			GroupParaAddrH=EL_GEAR_ADDRH;
			GroupParaAddrL=EL_GEAR_ADDRL;
			break;	
*/

		case	NM_AUTO_TUNNING_NM:	//autotunning
			if(xVarMotorType==IM_Motor_ID){     // IM	
				GroupParaAddrH=(unsigned char)(Addr_IM_Tunning >> 8);
				GroupParaAddrL=(unsigned char)(Addr_IM_Tunning);
			}
			else if(xVarMotorType==PM_Motor_ID){ // PM
				GroupParaAddrH=(unsigned char)(Addr_PM_Tunning >> 8);
				GroupParaAddrL=(unsigned char)(Addr_PM_Tunning);
			}
			break;	
		default:
			ret=1;
			break;

	}

	return(ret);
}




unsigned int  __attribute__((section(".usercode"))) Inverter_Par_Group_Save(void)
{
	unsigned int val;

	if((LadderGroup == INV_PAR_GROUP_14)){
		if(LadderGroupSub==NM_AUTO_TUNNING_NM)	return(0);		
		if(Inverter_MotorGroup_Rd())			return(0);
	}
	else{ 
		GroupParaAddrH=(unsigned char)(LadderGroup-INV_PAR_GROUP_00);
		GroupParaAddrL=(unsigned char)LadderGroupSub;
	}

	val=(DigitData >> 8);
	ThisNewAddressData_Load((unsigned char)(GroupParaAddrH),(unsigned char)GroupParaAddrL,1,(unsigned char)(val),(unsigned char)(DigitData));

	ParRdWrNm=INVETER_RW_SEQ;
	ThisRdWrMode=PARAMETER_WR_SEQ;	
	
	bParWr=1;
	bL1000_Enter=1;
	return(0);						
}




unsigned int  __attribute__((section(".usercode"))) Inv_Par_NewMenuStart(void)
{    
    switch(LadderGroup){
		case    INV_PAR_GROUP_00:
		case    INV_PAR_GROUP_01:
        case    INV_PAR_GROUP_02:
        case    INV_PAR_GROUP_03:
        case    INV_PAR_GROUP_04:
        case    INV_PAR_GROUP_05:
        case    INV_PAR_GROUP_06:
        case    INV_PAR_GROUP_07:
        case    INV_PAR_GROUP_08:
        case    INV_PAR_GROUP_09:
        case    INV_PAR_GROUP_10:
        case    INV_PAR_GROUP_11:
        case    INV_PAR_GROUP_12:
        case    INV_PAR_GROUP_13:
          	MaxSubMenu=DELTA_GROUP_MAX;
			break;
      	case    INV_PAR_GROUP_14:
          	MaxSubMenu=MOTOR_GROUP_MAX;
			break;
		default:
			break;

    }
	return(0);
}


unsigned int  __attribute__((section(".usercode"))) Inv_Par_GroupSaveChk(void)
{
	unsigned int ret;
	ret=0;

    switch(LadderGroup){
		case    INV_PAR_GROUP_00:
		case    INV_PAR_GROUP_01:
		case    INV_PAR_GROUP_02:
		case    INV_PAR_GROUP_03:
		case    INV_PAR_GROUP_04:
		case    INV_PAR_GROUP_05:
		case    INV_PAR_GROUP_06:
		case    INV_PAR_GROUP_07:
		case    INV_PAR_GROUP_08:
		case    INV_PAR_GROUP_09:
		case    INV_PAR_GROUP_10:
		case    INV_PAR_GROUP_11:
		case    INV_PAR_GROUP_12:
		case    INV_PAR_GROUP_13:
		case    INV_PAR_GROUP_14:
			if(bHostAutoLanding && !bParRd ){
				if( !AutoTunningStartChk()){	
					Inverter_Par_Group_Save();
				}
				ret=1;;
			}
			break;
		default:
			break;
	}
	return(1);
}







unsigned int  __attribute__((section(".usercode"))) Inv_Par_Group(void)
{
    LocalType i,j;

	switch(LadderGroup){
		case    INV_PAR_GROUP_00:
		case    INV_PAR_GROUP_01:
        case    INV_PAR_GROUP_02:
        case    INV_PAR_GROUP_03:
        case    INV_PAR_GROUP_04:
        case    INV_PAR_GROUP_05:
        case    INV_PAR_GROUP_06:
        case    INV_PAR_GROUP_07:
        case    INV_PAR_GROUP_08:
        case    INV_PAR_GROUP_09:
        case    INV_PAR_GROUP_10:
        case    INV_PAR_GROUP_11:
        case    INV_PAR_GROUP_12:
        case    INV_PAR_GROUP_13:
        case    INV_PAR_GROUP_14:	
			if( !bParWr && bWarning){  
				if(LadderGroup == INV_PAR_GROUP_14){
					Inverter_MotorGroup_Rd();				
				}
				else if( (LadderGroup >= INV_PAR_GROUP_00) && (LadderGroup < INV_PAR_GROUP_END)){
					GroupParaAddrH=(unsigned char)(LadderGroup-INV_PAR_GROUP_00);
					GroupParaAddrL=(unsigned char)LadderGroupSub;
//////////////////					L1000_Inv_AddressRead();
				}	

				ThisNewAddressData_Load( (unsigned char)(GroupParaAddrH),(unsigned char)GroupParaAddrL,0,0,0);					
				ParRdWrNm=INVETER_RW_SEQ;	
				bParRd=1;
			}		
			break;
        default:
			break;
	}


	if(LadderGroup==INV_PAR_GROUP_14){
	    for(i=0;i<16;i++){
	        New485Ladder[i+2]=MOTOR_GROUP_MSG[LadderGroupSub][i];
	    }

		if( (LadderGroupSub==0x08) && (xVarMotorType==IM_Motor_ID)){
		    for(i=0;i<16;i++){
		        New485Ladder[i+2]=IM_NO_LOAD[i];
		    }
		}
	}
	else{
	    for(i=0;i<16;i++){
	        New485Ladder[i+2]=INVERTER_PAR[i];
	    }
	    New485Ladder[2+4]=( (LadderGroup-INV_PAR_GROUP_00) / 10)+ '0';
	    New485Ladder[2+5]=( (LadderGroup-INV_PAR_GROUP_00) % 10)+ '0';
	
	}

	for(i=0;i<16;i++){
	    New485Ladder[SECONDLINE_BASE+i]=INVERTER_VAL[i];
	}
	New485Ladder[SECONDLINE_BASE+ 0]=(LadderGroupSub / 10)+ '0';
	New485Ladder[SECONDLINE_BASE+ 1]=(LadderGroupSub % 10)+ '0';		



    Cursor=0;
    ShiftCnt=5;
    EditBlanck=4;
    EditStatus=DIGIT_EDIT;

	return(1);
}



#endif
