
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


//#define  bPlankLandingOk       	GET_BITFIELD(&StateBit13).bit5 
//#define  bInvCommActive485		GET_BITFIELD(&StateBit13).bit6 
//#define  bAutoLandingActive		GET_BITFIELD(&StateBit13).bit7 


unsigned long 	FhmDecMpm,SetMidMpm,SetLowMpm,LastMpm,LastSpd_LMH;
unsigned long 	ThisUseMpm,ThisUseMpmVariable,ThisUseMmPerPulse;


unsigned int  __attribute__((section(".usercode")))   PlankAutoLandingOkChk(void)
{

	PulseToMm(GET_LONG(BASE_PLANK_LENGTH));		
	OneceUseBuf1=PulseBuf;
	if(OneceUseBuf1<10){
		bPlankLandingOk=0;
		return(0);
	}
	else{
		OneceUseBuf2=GET_LONG(B_USER_PLANK_LENGTH);
		if(OneceUseBuf1>=OneceUseBuf2)	OneceUseBuf3=(OneceUseBuf1-OneceUseBuf2);
		else							OneceUseBuf3=(OneceUseBuf2-OneceUseBuf1);
	
		if(OneceUseBuf3>10)				bPlankLandingOk=0;
		else							bPlankLandingOk=1;
		return(0);
	}
}


unsigned int  __attribute__((section(".usercode")))   AutoLandingStatusChk(void)
{
	WhoAutolanding = (unsigned int)cF_AUTO_LANDING;

	if(INVERTER_CHECK != IO)	WhoAutolanding=0;	
	if(!New_Spd_SystemChk())	WhoAutolanding=0;			

	switch(WhoAutolanding){
		case	EDS_AUTOLANDING_485:
		case	VL_AUTOLANDING_485:
			bInvCommActive485=1;
			bAutoLandingActive=1;
//			bHostAutoLanding=1;
			EdsAddressSet();
			break;
		case	L1000_AUTOLANDING_485:
			bInvCommActive485=1;
			bAutoLandingActive=1;
//			bHostAutoLanding=1;
			L1000AddressSet();
			break;
		case	TEST_AUTOLANDING:
			bInvCommActive485=0;
			bAutoLandingActive=1;
//			bHostAutoLanding=1;
			break;
		default:
			bInvCommActive485=0;
			bAutoLandingActive=0;
//			bHostAutoLanding=0;
			break;
	}
}





unsigned int  __attribute__((section(".usercode")))   UserAutoLandingScurveLoad(void)
{
	unsigned long	tmpMaxMpm,tmpSCurve;

	ELGroupDataLoad();


	SetMidMpm=0;
	SetLowMpm=0;


	tmpSCurve=GET_LONG(BASE_SCURVE_TIME);
	if( (tmpSCurve < 500) || (tmpSCurve < 2000)){
   		parameter_mirror[(BASE_SCURVE_TIME- ENCODER_PULSE)]  		= (unsigned long)1200;  // 1.2sec
	}


	tmpMaxMpm=GET_LONG(B_USER_MPM);
parameter_mirror[(BASE_DEC_TIME- ENCODER_PULSE)]  		= (unsigned long)1600;  	// 1.7sec

/*
	if(tmpMaxMpm < 400){   		// 30mpm 
   		parameter_mirror[(BASE_DEC_TIME- ENCODER_PULSE)]  		= (unsigned long)1200;  	// 1.2sec
	}
	else if(tmpMaxMpm < 500){	// 45mpm
   		parameter_mirror[(BASE_DEC_TIME- ENCODER_PULSE)]  		= (unsigned long)1400;  	// 1.5sec
	}
	else if(tmpMaxMpm < 700){	// 60mpm
   		parameter_mirror[(BASE_DEC_TIME- ENCODER_PULSE)]  		= (unsigned long)1600;  	// 1.7sec
	}
	else if(tmpMaxMpm < 970){	// 90mpm
   		parameter_mirror[(BASE_DEC_TIME- ENCODER_PULSE)]  		= (unsigned long)2000;  	// 2.0sec
	}
	else if(tmpMaxMpm < 110){	// 105mpm
   		parameter_mirror[(BASE_DEC_TIME- ENCODER_PULSE)]  		= (unsigned long)2200;  	// 2.0sec
	}

	else if(tmpMaxMpm < 130){	// 120mpm
   		parameter_mirror[(BASE_DEC_TIME- ENCODER_PULSE)]  		= (unsigned long)2400;  	// 2.0sec
	}
	else if(tmpMaxMpm < 160){	// 150mpm
   		parameter_mirror[(BASE_DEC_TIME- ENCODER_PULSE)]  		= (unsigned long)2600;  	// 2.0sec
	}

	else if(tmpMaxMpm < 190){	// 180mpm
   		parameter_mirror[(BASE_DEC_TIME- ENCODER_PULSE)]  		= (unsigned long)2600;  	// 2.0sec
	}
	else if(tmpMaxMpm < 220){	// 210mpm
   		parameter_mirror[(BASE_DEC_TIME- ENCODER_PULSE)]  		= (unsigned long)2600;  	// 2.0sec
	}
	else if(tmpMaxMpm < 250){	// 240mpm
   		parameter_mirror[(BASE_DEC_TIME- ENCODER_PULSE)]  		= (unsigned long)2800;  	// 2.0sec
	}
	else{
   		parameter_mirror[(BASE_DEC_TIME- ENCODER_PULSE)]  		= (unsigned long)3000;  	// 2.0sec
	}
*/
	WriteFlash_spd3();
	SaveVerify = 0x0;

	return(0);	
}




unsigned int  __attribute__((section(".usercode")))   CalMinimumFloorPulse(void)
{
	unsigned int	tmptop,ret,search;

	search=0;
	OneceUseBuf3=0xfffffff0;

	tmptop=(unsigned int)(cF_TOPFLR);
	for(ret=1;ret<=tmptop;tmptop++){
		OneceUseBuf1=FLOOR_COUNT((ret-1));		
		OneceUseBuf2=FLOOR_COUNT(ret);
		if(OneceUseBuf2 > OneceUseBuf1){
			OneceUseBuf2=(OneceUseBuf2 - OneceUseBuf1);
			if(OneceUseBuf3 > OneceUseBuf2){
				OneceUseBuf3 = OneceUseBuf2;	
				search=1;
			}
		}
	}
	if(search==0)	OneceUseBuf3=0;

/*	

	PulseToMm(OneceUseBuf3);
	OneceUseBuf3 = MmBuf;
*/
	return(1);
}







unsigned int  __attribute__((section(".usercode")))   DefaultLowMpmSet(void)
{

	unsigned long	tmpCurMpm,tmpMaxMpm,HSpdDecLength;
	unsigned long	Length1;
	unsigned int	save,ret;

	ret=0;
	save=0;
	
//	if(WhoAutolanding != TEST_AUTOLANDING)	return(0);
//	PlankAutoLandingOkChk();
//	UserAutoLandingScurveLoad();



//	if(!bPlankLandingOk)	return(0);


//	ELGroupDataLoad();


/*
	tmpMaxMpm=GET_LONG(B_USER_MPM);
	xVarCurMpm=(tmpMaxMpm * 100);

	if(CurDecPulseCalcu()){
		Length1=GET_LONG(DEC_LENGTH_SPD_HIGH);
		HSpdDecLength=CurSpdDecPulse;	
		if(HSpdDecLength != Length1){
    		parameter_mirror[(DEC_LENGTH_SPD_HIGH- ENCODER_PULSE)] = (unsigned long)HSpdDecLength;
			save=1;					
			ret=1;		
		}
	}


*/
	CalMinimumFloorPulse();
	if(OneceUseBuf3 ==0){
		SetLowMpm=200;	// 20mpm
		return(0);
	}

	for(tmpCurMpm=tmpMaxMpm;tmpCurMpm>100;tmpCurMpm--){
        asm("CLRWDT");
		xVarCurMpm=(tmpCurMpm * 100);
		if(CurDecPulseCalcu()){
			MmToPulse(CurSpdDecPulse);
			if(OneceUseBuf3 > (PulseBuf *2)){
				SetLowMpm=xVarCurMpm;
				tmpCurMpm=1;  // end,,return


/*
    			parameter_mirror[(DEC_LENGTH_SPD_LOW - ENCODER_PULSE)] = (unsigned long)CurSpdDecPulse;
				save=1;
				
				Length1=(tmpMaxMpm-tmpCurMpm);
				Length1=(Length1/2);					
				xVarCurMpm=(tmpCurMpm + Length1) * 100;
				if(CurDecPulseCalcu()){
    				parameter_mirror[(DEC_LENGTH_SPD_MID - ENCODER_PULSE)] = (unsigned long)CurSpdDecPulse;
				}
				tmpCurMpm=1;  // end
*/
			}
		}
	}

	if(SetLowMpm<200){
		SetLowMpm=200;		// minimum mpm 20.0mpm
	}


/*
	if(save){
		WriteFlash_spd3();
		SaveVerify = 0x0;
		return(1);
	}
	else		return(0);	//fail
*/
}



unsigned int  __attribute__((section(".usercode")))   ReCaluMidSpd(void)
{
	unsigned long tmpSpdGap;

	if(LastSpd_LMH==SPEED_MID){
		if(SetMidMpm >= LastMpm)		tmpSpdGap=(SetMidMpm - LastMpm);
		else							tmpSpdGap=(LastMpm 	 - SetMidMpm);
		if(tmpSpdGap>10)				SetMidMpm=tmpSpdGap;				//1.0 mpm
	}

	if(SetMidMpm==0){
		if(SetLowMpm >= 200){
			SetMidMpm=(SetMidMpm + 50);
		}
	}
	return(0);
}


unsigned int  __attribute__((section(".usercode")))   ReCaluLowSpd(void)
{
	unsigned long tmpSpdGap;


	if(LastSpd_LMH==SPEED_LOW){
		if(SetLowMpm >= LastMpm)		tmpSpdGap=(SetLowMpm - LastMpm);
		else							tmpSpdGap=(LastMpm 	 - SetLowMpm);
		if(tmpSpdGap>10)				SetLowMpm=tmpSpdGap;				//1.0 mpm
	}

	if(SetLowMpm==0){
		DefaultLowMpmSet();
	}

	return(0);
}



unsigned int  __attribute__((section(".usercode")))   ReSettingMidLowSpd(void)
{
	if( !PerfectAuto())	return(0);

	ReCaluLowSpd();
	ReCaluMidSpd();
	return(0);
}


unsigned int  __attribute__((section(".usercode")))   Init_AutoLandingModeChk(void)
{
	WhoAutolanding = (unsigned int)cF_AUTO_LANDING;
	AutoLandingStatusChk();

	if(Old_Spd_SystemChk()){
		NewSpdForceSet();

    	GetFlashDataToBufRam(F_BLOCK2);

		if(cF_SystemSet == NEW_LAW_OLD_SPD){
        	b_LdTmpBufRam((unsigned long)F_SystemSet)=(unsigned char)(NEW_LAW_NEW_SPD);	
		}
		else{
        	b_LdTmpBufRam((unsigned long)F_SystemSet)=(unsigned char)(OLD_LAW_NEW_SPD);		
		}	

		SaveVerify = 0x55;		
        flash_write_DspChar(F_BLOCK2);
		SaveVerify = 0x0;
		asm("RESET");
	}
	return(0);
}



