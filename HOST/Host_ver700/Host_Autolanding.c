

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





unsigned long 	MinimumFloorPulse=0;

unsigned long 	xVarMotorType=0;


unsigned long 	xVarDecTime,xVarSCurve;
unsigned long 	xVarCurMpm,xVarRpm,xVarEncoder,xVarMpm,xVarMpm1000,xVarMaxHz,xDecMpm,xLowSpdMpm,xMidSpdMpm;
unsigned long 	Length1,Length2;
unsigned long 	EVManualSpd,EVLowSpd,EVMidSpd,EVHighSpd,CurSpdDecPulse,EVLowDecLength,EVMidDecLength,EVHighDecLength,EVDecLength;
unsigned long 	TMaxMpm,TCurMpm,TLastMpm,TVarDecTime,TVarSCurve,TVarLengthVal1,TVarLengthVal2;


#ifdef	AUTO_LANDING_COMM	


//////////////new//////////////////////////



unsigned long 	LastMpm,LastSpd_LMH,LastDecMpm;
unsigned long 	ThisUseMaxMpm,ThisUseMpmVariable,ThisUseMmPerPulse,ThisUseDecSpd,ThisUseLowSpd,ThisUseMidSpd;


unsigned int 	zDecTime,xTestDectime,TestDectime=0;

/*
unsigned long AvrBuf[11];
unsigned long AvrBefCurPulse,AvrPulse,AvrPulseMinimum;
unsigned int  AvrPt;
*/

unsigned long	BefPlankLength;


unsigned long	PlankMpm,PlankMmPerPulse,PlankMpmVariable;



unsigned int __attribute__((section(".usercode")))  A_CurDecPulseCalcu(void)
{

	TMaxMpm=ThisUseMaxMpm;
	TVarDecTime=GET_LONG(BASE_DEC_TIME);
	TVarSCurve=GET_LONG(BASE_SCURVE_TIME);	
	TLastMpm=ThisUseDecSpd;

	TMaxMpm=(TMaxMpm * 100);  //newmpm 180000
	if(TMaxMpm==0){
		CurSpdDecPulse=0;
		return(0);
	}

	TCurMpm=((xVarCurMpm * 100)/60);
	TMaxMpm=(TMaxMpm/60);										// max mpm  ==> mps  //3000


	TLastMpm=((TLastMpm*100)/60);										// last mpm ==> mps  ////60

	if(TCurMpm <= TLastMpm){
		CurSpdDecPulse=0;
		return(0);
	}



	if(TCurMpm > TMaxMpm){
		TCurMpm=TMaxMpm;   
	}
		

	TVarLengthVal1=(TCurMpm + TLastMpm)/2;                      	//1530
 	TVarLengthVal2=(TCurMpm - TLastMpm) * TVarDecTime;  			//11760000
 	TVarLengthVal2=(TVarLengthVal2/TMaxMpm);                     	//3920
 	TVarLengthVal2=(TVarLengthVal2 + TVarSCurve);					//4920
    TVarLengthVal1=(TVarLengthVal1 * TVarLengthVal2);              	//
	CurSpdDecPulse=(TVarLengthVal1/1000);	            			// dec length

	MmToPulse(CurSpdDecPulse);
	CurSpdDecPulse=PulseBuf;
		
	return(1);
}


unsigned int __attribute__((section(".usercode")))  RunningDecPulseCalcu(void)
{
	if(PerfectAuto()){
		if(!bUnd && bMoveCar){
			if( CurMeterPerMin > ThisUseDecSpd){ 
				A_CurDecPulseCalcu();
				DecreasePulse=(CurSpdDecPulse + xBefLuLdPulse);
			}
		}
	}
	return(0);
}







unsigned int  __attribute__((section(".usercode")))   AutoLandingStatusChk(void)
{
//	WhoAutolanding = (unsigned int)cF_AUTO_LANDING;

	if(INVERTER_CHECK != IO)	WhoAutolanding=0;	

	switch(WhoAutolanding){
		case	EDS_AUTOLANDING_485:
		case	VL_AUTOLANDING_485:
			bInvCommActive485=1;
			bAutoLandingActive=1;
			EdsAddressSet();
			break;
		case	L1000_AUTOLANDING_485:
			bInvCommActive485=1;
			bAutoLandingActive=1;
			L1000AddressSet();
			break;
		case	USER_AUTOLANDING:
			bInvCommActive485=0;
			bAutoLandingActive=1;
			break;
		default:
			bInvCommActive485=0;
			bAutoLandingActive=0;
			break;
	}
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

	return(1);
}







unsigned int  __attribute__((section(".usercode")))   DefaultLowMpmSet(void)
{

	unsigned long	tmpCurMpm,tmpMaxMpm;

	CalMinimumFloorPulse();
	if(OneceUseBuf3 ==0){
		LastMpm=200;	// 20mpm
		return(0);
	}

	if(bPlankLandingOk)	tmpMaxMpm=PlankMpm;
	else				tmpMaxMpm=GET_LONG(NEW_MPM);

	for(tmpCurMpm=tmpMaxMpm;tmpCurMpm>100;tmpCurMpm--){
        asm("CLRWDT");
		xVarCurMpm=tmpCurMpm;
		if(A_CurDecPulseCalcu()){
			if(OneceUseBuf3 > (PulseBuf *2)){
				LastMpm=tmpCurMpm;
				tmpCurMpm=1;  // end,,return
			}
		}
	}

	if(LastMpm<200){
		LastMpm=200;		// minimum mpm 20.0mpm
	}
	return(0);
}


unsigned long  __attribute__((section(".usercode"))) ConverteMpm(unsigned long Tar_mpm_Var,unsigned long Src_mpm_Var,unsigned long src_mpm)
{
	unsigned long	tmpMpmVariable,tmpTargetMpmVar,tmpMpm;	

//	tmpMpmVariable=GET_LONG(MPM_VARIABLE);
	tmpMpmVariable=Src_mpm_Var;
	if(tmpMpmVariable>0){
		tmpTargetMpmVar=Tar_mpm_Var;
		tmpMpm=src_mpm;
		tmpMpm=(tmpMpm * tmpTargetMpmVar);
		tmpMpm=(tmpMpm/tmpMpmVariable);
	}
	else	tmpMpm=0;
	return(tmpMpm);
}




unsigned int  __attribute__((section(".usercode")))   SaveSpdMLD(unsigned int pt,unsigned long spd)
{
	ELGroupDataLoad();
	spd=ConverteMpm(GET_LONG(MPM_VARIABLE),ThisUseMpmVariable,spd);
  	parameter_mirror[(pt - (unsigned int)ENCODER_PULSE)]  = (unsigned long)spd; 
	WriteFlash_spd3();
	SaveVerify = 0x0;
}






unsigned int  __attribute__((section(".usercode")))   ReCaluMidSpd(void)
{
	unsigned int  save;
	unsigned long tmpSpdGap;

	save=0;

	if(LastSpd_LMH==SPEED_MID){
		LastSpd_LMH=0;

		if(ThisUseMidSpd >= LastMpm)		tmpSpdGap=(ThisUseMidSpd - LastMpm);
		else								tmpSpdGap=(LastMpm 	 - ThisUseMidSpd);
		if(tmpSpdGap>20){
			save=1;
		}
	}

	if(bParameterChange){
		if(ThisUseMidSpd <= ThisUseLowSpd){
			LastMpm=(ThisUseLowSpd + 50);
			save=1;
		}
		else if(ThisUseMidSpd >= ThisUseMaxMpm){
			LastMpm=(ThisUseLowSpd + 50);
			save=1;
		}
	}

	if(save){
		SaveSpdMLD((unsigned int)(DEC_PULSE_SPD_MID),LastMpm);		
		if(bPlankLandingOk)	ThisUseMidSpd	=ConverteMpm(PlankMpmVariable,GET_LONG(MPM_VARIABLE),GET_LONG(DEC_PULSE_SPD_MID));
		else				ThisUseMidSpd	=GET_LONG(DEC_PULSE_SPD_MID);				
	}


	return(0);
}


unsigned int  __attribute__((section(".usercode")))   ReCaluLowSpd(void)
{
	unsigned int  save;
	unsigned long tmpSpdGap;

	save=0;
	
	if(LastSpd_LMH==SPEED_LOW){
		LastSpd_LMH=0;
		if(ThisUseLowSpd >= LastMpm)	tmpSpdGap=(ThisUseLowSpd - LastMpm);
		else							tmpSpdGap=(LastMpm 	 - ThisUseLowSpd);

		if(tmpSpdGap>20){
			save=1;
		}
	}


	if(bParameterChange){
		if(ThisUseLowSpd<100){
			DefaultLowMpmSet();
			save=1;
		}
		else if(ThisUseLowSpd >= ThisUseMaxMpm){
			DefaultLowMpmSet();
			save=1;
		}
		else if(ThisUseLowSpd >= ThisUseMidSpd){
			DefaultLowMpmSet();
			save=1;
		}
	}

	if(save){
		SaveSpdMLD((unsigned int)(DEC_PULSE_SPD_LOW),LastMpm);
		if(bPlankLandingOk)	ThisUseLowSpd	=ConverteMpm(PlankMpmVariable,GET_LONG(MPM_VARIABLE),GET_LONG(DEC_PULSE_SPD_LOW));
		else				ThisUseLowSpd	=GET_LONG(DEC_PULSE_SPD_LOW);				
	}


	return(0);
}



unsigned int  __attribute__((section(".usercode")))   ReCaluDecSpd(void)
{
	unsigned int  save;
	unsigned long tmpSpdGap;

	save=0;

	if((LastDecMpm > 5) && (LastDecMpm < 50)){
		if(ThisUseDecSpd >= LastDecMpm)	tmpSpdGap=(ThisUseDecSpd - LastDecMpm);
		else							tmpSpdGap=(LastDecMpm 	 - ThisUseDecSpd);

		if(tmpSpdGap>2){
			save=1;
		}
	} 	


	if(bParameterChange){
		tmpSpdGap=GET_LONG(BASE_DEC_MPM);
		if(tmpSpdGap<=5){			//0.5 mpm
			LastDecMpm=12;			//1.2 mpm
			save=1;
		}		
		else if(tmpSpdGap>=50){		//5.0 mpm
			LastDecMpm=12;			//1.2 mpm
			save=1;
		}
	}


	if(save){
		SaveSpdMLD((unsigned int)(BASE_DEC_MPM),LastDecMpm);
		if(bPlankLandingOk)	ThisUseDecSpd	=ConverteMpm(PlankMpmVariable,GET_LONG(MPM_VARIABLE),GET_LONG(BASE_DEC_MPM));
		else				ThisUseDecSpd	=GET_LONG(BASE_DEC_MPM);				
	}

	LastDecMpm=0;

	return(0);
}



unsigned int  __attribute__((section(".usercode")))   MidLowSpdSet(void)
{
	ReCaluLowSpd();
	ReCaluMidSpd();
	ReCaluDecSpd();
	return(0);
}

unsigned int  __attribute__((section(".usercode")))   RunningReSettingMidLowSpd(void)
{
//	if(!PerfectAuto())		return(0);
	if(bMoveCar)					return(0);
	if(bInvCommActive485)			return(0);
	if(bExportData || bImportData)	return(0);
	if(bFhmRun)						return(0);
	if(!bAutoLandingActive)			return(0);

	MidLowSpdSet();

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




unsigned int  __attribute__((section(".usercode")))   GetDecreasePulse(unsigned int ThisSpd)
{
	unsigned int ret=0;

	if(bAutoLandingActive){	
		switch(ThisSpd){
			case	SPEED_LOW:
				xVarCurMpm=(ThisUseLowSpd);
				break;		
			case    SPEED_MID:
				xVarCurMpm=(ThisUseMidSpd);
				break;		
			case    SPEED_HIGH:
				xVarCurMpm=ThisUseMaxMpm;
				break;		
			default:
				break;	
		}
	
		A_CurDecPulseCalcu();
	}
	else{
		switch(ThisSpd){
			case	SPEED_LOW:
				CurSpdDecPulse=SpdL_DecPulse;
				break;		
			case    SPEED_MID:
				CurSpdDecPulse=SpdM_DecPulse;
				break;		
			case    SPEED_HIGH:
				CurSpdDecPulse=SpdH_DecPulse;
				break;		
			default:
				break;	
		}
	}
	return(ret);
}



unsigned int  __attribute__((section(".usercode")))   Spd3ReloadReqFlr(unsigned int updn)
{

    unsigned long 	MinPulsex,tmppulseCur;
	unsigned int	reqflr;

	if((INVERTER_CHECK == IO)){
		GetDecreasePulse(CurSpeed);
		MinPulsex=CurSpdDecPulse;	
		MinPulsex=(MinPulsex * 2);
		tmppulseCur=FLOOR_COUNT(sRamDArry[mcurfloor]);
	
		if(updn==0){	// upward
	        if(sRamDArry[mcurfloor]< cF_TOPFLR)  reqflr  = (unsigned int)(sRamDArry[mcurfloor]+1);
	        else                                 reqflr  = (unsigned int)(cF_TOPFLR);
	
			sRamDArry[mReqStopFloor]  = (unsigned char)(reqflr);	
			OneceUseBuf1=(MinPulsex + tmppulseCur);
			do{
				OneceUseBuf2=FLOOR_COUNT(reqflr);
				if(OneceUseBuf2 >= OneceUseBuf1){
					sRamDArry[mReqStopFloor]  = (unsigned char)(reqflr);
					return(0); 
				}
				else	reqflr++;
			}while(reqflr <= (unsigned int)(cF_TOPFLR));
		}
		else{		// dnward
	        if(sRamDArry[mcurfloor]>0)  reqflr  = (unsigned int)(sRamDArry[mcurfloor]-1);
	        else                        reqflr  = 0;
	
			sRamDArry[mReqStopFloor]  = (unsigned char)(reqflr);	
			OneceUseBuf1=(tmppulseCur - MinPulsex);
			do{
				OneceUseBuf2=FLOOR_COUNT(reqflr);
				if(OneceUseBuf2 <= OneceUseBuf1){
					sRamDArry[mReqStopFloor]  = (unsigned char)(reqflr);
					return(0); 
				}
				else	reqflr--;
				if(reqflr==0)	return(0);
	
			}while(reqflr > 0);
		}
	}
	else{
		if(updn==0){	// upward
	        if(sRamDArry[mcurfloor]< cF_TOPFLR)  sRamDArry[mReqStopFloor]  = sRamDArry[mcurfloor]+1;
	        else                                 sRamDArry[mReqStopFloor]  = cF_TOPFLR;
		}
		else{
	        if(sRamDArry[mcurfloor]>0)  sRamDArry[mReqStopFloor]  = sRamDArry[mcurfloor]-1;
	        else                        sRamDArry[mReqStopFloor]  = 0;
		}
	}

	return(0);
}





LocalType __attribute__((section(".usercode"))) GetMinimumFloorPulse(void)
{
	unsigned int i;
	unsigned long tmpflr1,tmpflr2,tmpflr3,tmpflr4;

	if(MinimumFloorPulse ==0){
		tmpflr4=0xffffffff;
		for(i=1;i<=(unsigned int)cF_TOPFLR;i++){
	    	tmpflr1=FLOOR_COUNT((unsigned char)(i-1));
	    	tmpflr2=FLOOR_COUNT((unsigned char)(i));
			tmpflr3=(tmpflr2 - tmpflr1);
			if(tmpflr3 <= tmpflr4){
				tmpflr4=tmpflr3;
			}
		}
		MinimumFloorPulse= tmpflr4;
	}
	else{
		tmpflr1=EVLowDecLength;
		tmpflr2=(tmpflr1 / 2);
		tmpflr3=(tmpflr1 *  2);
		tmpflr1=(tmpflr2 + tmpflr3);
		if(MinimumFloorPulse < tmpflr1){
			return(1);
		}
	}

	return(0);

}






unsigned int  __attribute__((section(".usercode")))   FhmSaveDecMpm(void)
{
	unsigned long	tmpDecMpm,tmpOrgMpmVariable;

	tmpDecMpm=LastDecMpm;

	if(bPlankLandingOk){
		if(ThisUseMpmVariable > 0){
			tmpOrgMpmVariable=GET_LONG(MPM_VARIABLE);
			tmpDecMpm=(tmpDecMpm * tmpOrgMpmVariable);			
			tmpDecMpm=(tmpDecMpm/ThisUseMpmVariable);
		}
		else{
			tmpDecMpm=12;
		}
	}
	LastDecMpm=tmpDecMpm;
	return(1);
}






unsigned	long  __attribute__((section(".usercode"))) CaluOrgMmPerPulse(void)
{
	unsigned long	tmpRpm,tmpMpm,tmpEncoderPulse,tmpMmPerPulse;

	tmpMpm   		= GET_LONG(NEW_MPM);
	tmpRpm          = GET_LONG(RPM);
	tmpEncoderPulse = GET_LONG(ENCODER_PULSE);

	tmpMmPerPulse=(tmpRpm *  tmpEncoderPulse * 4);
	if(tmpMmPerPulse>0){
		tmpMpm	= (tmpMpm * 100 * 10000);                        		//new length=mm * 10000 ==1200000000
		tmpMmPerPulse   = (tmpMpm/tmpMmPerPulse);
//		tmpMmPerPulse   = tmpMpm / (tmpRpm *  tmpEncoderPulse);  	// 1200000000/1523712
//		tmpMmPerPulse   = (tmpMmPerPulse / (unsigned long)4);
	}
	else	tmpMmPerPulse=0;	
	return(tmpMmPerPulse);
}



unsigned	int  __attribute__((section(".usercode"))) OrgMpmVariableReCal(void)
{
	unsigned int	i;
	unsigned long	tmpMmPerPulse,tmpMpmVariable,BeftmpMpmVariable;	


	i=0;
	tmpMmPerPulse=CaluOrgMmPerPulse();
	tmpMpmVariable	= (tmpMmPerPulse * (unsigned long)600);

	BeftmpMpmVariable= GET_LONG(MPM_VARIABLE);

	if(tmpMpmVariable != BeftmpMpmVariable){
		i=1;	//save
	    parameter_mirror[MM_PULSE -ENCODER_PULSE]  		= tmpMmPerPulse;
    	parameter_mirror[MPM_VARIABLE -ENCODER_PULSE]  	= tmpMpmVariable;	

		parameter_mirror[BASE_DEC_MPM -ENCODER_PULSE]		=ConverteMpm(tmpMpmVariable,BeftmpMpmVariable,GET_LONG(BASE_DEC_MPM));
		parameter_mirror[DEC_PULSE_SPD_LOW -ENCODER_PULSE]	=ConverteMpm(tmpMpmVariable,BeftmpMpmVariable,GET_LONG(DEC_PULSE_SPD_LOW));
		parameter_mirror[DEC_PULSE_SPD_MID -ENCODER_PULSE]	=ConverteMpm(tmpMpmVariable,BeftmpMpmVariable,GET_LONG(DEC_PULSE_SPD_MID));
	}

	return(i);
}                                                                     





unsigned int  __attribute__((section(".usercode"))) PlankMpmVariableReCal(void)
{
	unsigned long	tmpRpm,tmpPlankLength,tmpPlankPulse,tmpEncoderPulse;
//,tmpMmPerPulse,tmpMpmVariable;	

    tmpRpm          =GET_LONG(RPM);
    tmpEncoderPulse =GET_LONG(ENCODER_PULSE);
	tmpPlankLength	=GET_LONG(B_USER_PLANK_LENGTH);						//200mm
	tmpPlankPulse	=GET_LONG(BASE_PLANK_PULSE);						//pulse


	tmpPlankLength=(tmpPlankLength * 10000);
	if(tmpPlankPulse>0)	PlankMmPerPulse=(tmpPlankLength/tmpPlankPulse);
	else				PlankMmPerPulse=0;

	PlankMpmVariable=(PlankMmPerPulse  * (unsigned long)600); 
	PlankMpm		=(PlankMmPerPulse  *   tmpRpm *  tmpEncoderPulse * 4)/1000000;

	return(0);
}




void  __attribute__((section(".usercode"))) GetPlankMpmVariable(void)
{
	ThisUseDecSpd	=ConverteMpm(PlankMpmVariable,GET_LONG(MPM_VARIABLE),GET_LONG(BASE_DEC_MPM));
	ThisUseLowSpd	=ConverteMpm(PlankMpmVariable,GET_LONG(MPM_VARIABLE),GET_LONG(DEC_PULSE_SPD_LOW));
	ThisUseMidSpd	=ConverteMpm(PlankMpmVariable,GET_LONG(MPM_VARIABLE),GET_LONG(DEC_PULSE_SPD_MID));
	
	ThisUseMaxMpm   	=PlankMpm;
	ThisUseMmPerPulse	=PlankMmPerPulse;
	ThisUseMpmVariable	=PlankMpmVariable;
}




void  __attribute__((section(".usercode"))) GetOrgMpmVariable(void)
{
#ifndef	TEST_SIMULATION
	ThisUseMaxMpm   	=GET_LONG(NEW_MPM);
	ThisUseMmPerPulse	=GET_LONG(MM_PULSE);
	ThisUseMpmVariable	=GET_LONG(MPM_VARIABLE);
	ThisUseDecSpd   	=GET_LONG(BASE_DEC_MPM);
	ThisUseLowSpd		=GET_LONG(DEC_PULSE_SPD_LOW);
	ThisUseMidSpd		=GET_LONG(DEC_PULSE_SPD_MID);
#endif
}                                                                     


void  __attribute__((section(".usercode"))) SearchMpm(void)
{	
#ifndef	TEST_SIMULATION
	if(bPlankLandingOk){
		GetPlankMpmVariable();
	}
	else{
		GetOrgMpmVariable();
	}

	CaluDecreasePulseCommon_spd3(0);	
	CaluDecreasePulseCommon_spd3(1);	
	CaluDecreasePulseCommon_spd3(2);	
#endif
}



unsigned int  __attribute__((section(".usercode")))   PlankAutoLandingOkChk(void)
{
	unsigned long	tmpPlankPulse,tmpPlankLength,tmpPlankMpm,tmpOrgMpm,tmpPlankMmPerPulse,tmpOrgMmPerPulse,tmptmp1;	
	
	tmpPlankMmPerPulse=PlankMmPerPulse;
	tmpPlankPulse=GET_LONG(BASE_PLANK_PULSE);			//pulse

	tmpPlankLength=(tmpPlankPulse * tmpPlankMmPerPulse)/10000;
	
	if(GET_LONG(B_USER_PLANK_LENGTH) < 50){
		bPlankLandingOk=0;
		return(0);
	}
	else if(CaluOrgMmPerPulse()==0){
		bPlankLandingOk=0;
		return(0);
	}	
	else if(tmpPlankLength<50){				// 50mm
		bPlankLandingOk=0;
		return(0);
	}
	else if(tmpPlankLength>1000){		// 1000mm		
		bPlankLandingOk=0;
		return(0);
	}
	else{
		tmpOrgMmPerPulse=GET_LONG(MM_PULSE);
		if(tmpOrgMmPerPulse >= tmpPlankMmPerPulse){
			tmptmp1=(tmpPlankMmPerPulse * 10)/100;
			if(tmpOrgMmPerPulse > (tmpPlankMmPerPulse + tmptmp1)){
				bPlankLandingOk=0;
				return(0);
			}
		}
		else{
			tmptmp1=(tmpOrgMmPerPulse * 10)/100;
			if( tmpPlankMmPerPulse > (tmpOrgMmPerPulse + tmptmp1)){
				bPlankLandingOk=0;
				return(0);
			}
		}
 
/*
//		tmpOrgMpm=ConverteMpm(GET_LONG(MPM_VARIABLE),PlankMpmVariable,PlankMpm);
//		tmpPlankMpm=ConverteMpm(PlankMpmVariable,GET_LONG(MPM_VARIABLE),tmpOrgMpm);

		tmpOrgMpm=GET_LONG(NEW_MPM);
		tmpPlankMpm=PlankMpm;

		if(tmpPlankMpm >= tmpOrgMpm)	tmpPlankMpm =(tmpPlankMpm-tmpOrgMpm);	 
		else							tmpPlankMpm =(tmpOrgMpm-tmpPlankMpm);
		
		if(tmpPlankMpm > 50){
			bPlankLandingOk=0;
			return(0);
		}	 
*/
	}
	
	bPlankLandingOk=1;
	return(1);	
}



unsigned int  __attribute__((section(".usercode")))   ParameterChangeChk(void)
{
	unsigned int save;


	if(bParameterChange){
		if(INVERTER_CHECK == IO){
			ELGroupDataLoad();
	
			PlankMpmVariableReCal();
	
			if(OrgMpmVariableReCal())		save=1;
	
			if(save){
				WriteFlash_spd3();
				SaveVerify = 0x0;
			}
	
			PlankAutoLandingOkChk();
			SearchMpm();

			MidLowSpdSet();
		}
	
		bParameterChange=0;
	}

	return(0);
}




unsigned int  __attribute__((section(".usercode")))   UserAutoLandingScurveLoad(void)
{
	unsigned long	tmpMaxMpm,tmpSCurve;

	bParameterChange=1;
	ThisUseLowSpd=0;
	ThisUseMidSpd=0;
	ReCaluLowSpd();
	ReCaluMidSpd();
	bParameterChange=0;


	ELGroupDataLoad();


	tmpSCurve=GET_LONG(BASE_SCURVE_TIME);
	if( (tmpSCurve < 800) || (tmpSCurve > 1500)){
   		parameter_mirror[(BASE_SCURVE_TIME- ENCODER_PULSE)]  		= (unsigned long)1200;  // 1.2sec
	}


	tmpMaxMpm=GET_LONG(NEW_MPM);

	if(tmpMaxMpm < 400){   		// 30mpm 
   		parameter_mirror[(BASE_DEC_TIME- ENCODER_PULSE)]  		= (unsigned long)1200;  	// 1.2sec
	}
	else if(tmpMaxMpm < 500){	// 45mpm
   		parameter_mirror[(BASE_DEC_TIME- ENCODER_PULSE)]  		= (unsigned long)1400;  	// 1.5sec
	}
	else if(tmpMaxMpm < 700){	// 60mpm
   		parameter_mirror[(BASE_DEC_TIME- ENCODER_PULSE)]  		= (unsigned long)1800;  	// 1.7sec
	}
	else if(tmpMaxMpm < 970){	// 90mpm
   		parameter_mirror[(BASE_DEC_TIME- ENCODER_PULSE)]  		= (unsigned long)2300;  	// 2.0sec
	}
	else if(tmpMaxMpm < 110){	// 105mpm
   		parameter_mirror[(BASE_DEC_TIME- ENCODER_PULSE)]  		= (unsigned long)2700;  	// 2.0sec
	}
	else if(tmpMaxMpm < 130){	// 120mpm
   		parameter_mirror[(BASE_DEC_TIME- ENCODER_PULSE)]  		= (unsigned long)3000;  	// 2.0sec
	}
	else if(tmpMaxMpm < 160){	// 150mpm
   		parameter_mirror[(BASE_DEC_TIME- ENCODER_PULSE)]  		= (unsigned long)4000;  	// 2.0sec
	}
	else if(tmpMaxMpm < 190){	// 180mpm
   		parameter_mirror[(BASE_DEC_TIME- ENCODER_PULSE)]  		= (unsigned long)5000;  	// 2.0sec
	}
	else if(tmpMaxMpm < 220){	// 210mpm
   		parameter_mirror[(BASE_DEC_TIME- ENCODER_PULSE)]  		= (unsigned long)6000;  	// 2.0sec
	}
	else if(tmpMaxMpm < 250){	// 240mpm
   		parameter_mirror[(BASE_DEC_TIME- ENCODER_PULSE)]  		= (unsigned long)8000;  	// 2.0sec
	}
	else{
   		parameter_mirror[(BASE_DEC_TIME- ENCODER_PULSE)]  		= (unsigned long)9000;  	// 2.0sec
	}


	WriteFlash_spd3();
	SaveVerify = 0x0;

	return(0);	
}


#endif

