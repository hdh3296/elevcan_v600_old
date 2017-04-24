


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


//extern	UserDataType	NoStart;




/*
void  __attribute__((section(".usercode")))    Mnanual_Speed_Sel_spd3(void)
{
       
    ManualSpeedCmd_IO();

    if(S1_POWER_FAIL && (cF_BATTERYSPEED > 0)){
 		BatterySpeedCmd_IO();
	}
                  				
		switch(sRamDArry[FHM_SEQ]){ 
			case  FHM_SEQ_0:

    if(bCarUpMove){
        if(!IN_LU || !IN_LD ){
            if(!IN_SU1 || bSearchHome || (bFhmRun && (sRamDArry[FHM_SEQ]== FHM_SEQ_3) ){     
                DecreaseSpeedCmd_IO();
            }
        } 
    }
    else if(bCarDnMove){
        if(!IN_LU || !IN_LD){
            if(!IN_SD1 || bSearchHome  || bFhmRun){
                DecreaseSpeedCmd_IO();
            }
        }
    }
}
*/


unsigned int __attribute__((section(".usercode")))    SetWhyDec(unsigned int Dec_Nm)
{

	if(!bsFsd){
		bsFsd=1;
		FsdNm=Dec_Nm;	 
		sRamDArry[mAckStopFloor]=0;
	}

	OUT_DAC(1);
	bExtButClr=1;
	bCarButClr=1;
    bUnd=1;
    CarLowSpeedCmd_IO();

	return(0);
}



void __attribute__((section(".usercode")))    RunSpeedCmd_IO_spd3(void)
{

    if(INVERTER_CHECK == LG)    CurSpeed=SPEED_HIGH;  ////////5xx
    if(INVERTER_CHECK == D_F)   CurSpeed=SPEED_HIGH;  ////////5xx

    switch(CurSpeed){
        case    SPEED_LOW:    
            CurSelSpeed(cF_SPEED_LOW_PORT);                        
            break;
        case    SPEED_MID:
            CurSelSpeed(cF_SPEED_MID_PORT);                        
            break;
        case    SPEED_HIGH:
            CurSelSpeed(cF_SPEED_HIGH_PORT);                        
            break;
        default:
            CurSelSpeed(0);                
        	CurSpeed=0;
            break;
    }
}



LocalType  __attribute__((section(".usercode")))    Su1Sd1X0X1_100mm(unsigned long val)
{
	unsigned long 	tmppulse,basePulse,highpulse,lowpulse;

	MmToPulse((unsigned long)OFFSET_LIMIT_SUSD);
	basePulse=PulseBuf;
	
	tmppulse=val;
	highpulse=(tmppulse + basePulse);
	lowpulse =(tmppulse - basePulse);
	
	tmppulse=CurPulse;
	if( (tmppulse > highpulse) || (tmppulse < lowpulse)){
		return(1);
	} 
	else	return(0);
}






LocalType  __attribute__((section(".usercode")))    SpeedReSetting(unsigned int spd_sig)
{

	unsigned int 	spd_val,spd_change_sta,event_name;
//	unsigned long 	tmppulse,basePulse,highpulse,lowpulse;
	unsigned long 	tmppulse;

	event_name=0;
	spd_change_sta=0;
	spd_val=NOT_USE_SPEED;


/////	if(bUnd)							return(0);	  
    if(!bCarUpMove && !bCarDnMove)		return(0);
	if( !PerfectAuto())					return(0); 					


    if(bCarUpMove){
		if(spd_sig == 1){
			if( !IN_SU2){
				event_name=1;									//su1
				spd_val=cF_SU2SD2_VELOCITY;
				if( spd_val == CHANGE_DEC_LIMIT_SUSD){
					if(!bFindSU){
						bFindSU=1;
						tmppulse=GET_LONG(BASE_SU1_PULSE);
						if(Su1Sd1X0X1_100mm(tmppulse))	spd_change_sta=1;
						else							spd_change_sta=0;	
					}	
				}				else	spd_change_sta=1; 
			}
		}
		else{
			if(USE_CHECK == MAN_USE){
				if( !IN_X0){
					event_name=3;									//x0
					spd_val=cF_X0X1_VELOCITY;
					if( spd_val == CHANGE_DEC_LIMIT_SUSD){
						if(!bFindUpX0){
							bFindUpX0=1;
							tmppulse=GET_LONG(BASE_X0_PULSE);
							if(Su1Sd1X0X1_100mm(tmppulse))	spd_change_sta=1;
							else							spd_change_sta=0;	
						}	
					}					else	spd_change_sta=1; 
				}
			}	
		}
    }
    else if(bCarDnMove){
		if(spd_sig == 1){
			if( !IN_SD2){
				event_name=2;									//Sd1
				spd_val=cF_SU2SD2_VELOCITY;
				if( spd_val == CHANGE_DEC_LIMIT_SUSD){
					if(!bFindSD){
						bFindSD=1;
						tmppulse=GET_LONG(BASE_SD1_PULSE);
						if(Su1Sd1X0X1_100mm(tmppulse))	spd_change_sta=1;
						else							spd_change_sta=0;	
					}
				}				else	spd_change_sta=1; 
			}
		}
		else{
			if(USE_CHECK == MAN_USE){
				if( !IN_X1){
					event_name=4;									//x1
					spd_val=cF_X0X1_VELOCITY;
					if( spd_val == CHANGE_DEC_LIMIT_SUSD){
						if(!bFindDnX1){
							bFindDnX1=1;
							tmppulse=GET_LONG(BASE_X1_PULSE);
							if(Su1Sd1X0X1_100mm(tmppulse))	spd_change_sta=1;
							else							spd_change_sta=0;	
						}	
					}					else	spd_change_sta=1; 
				}
			}	
		}
    }



	if(spd_change_sta==0)				return(0);	
	if(spd_val == NOT_USE_SPEED)		return(0);

//	if(spd_val >= SPEED_MAX)			return(0);
//	if(spd_val == NOT_USE_SPEED)		return(0);
//	if(spd_val >= CurSpeed)				return(0);
	



	switch(spd_val){
		case    CHANGE_DEC_AT_SPD_M_H:
			if(CurSpeed >= SPEED_MID){
				bUnd=1;
				CurSpeed=spd_val;
				bSetSpeedOn=1;                    
				CarLowSpeedCmd_IO();
			}
			break;
		case    CHANGE_DEC_AT_SPD_H:
			if(CurSpeed >= SPEED_HIGH){
				bUnd=1;				
				CurSpeed=spd_val;
				bSetSpeedOn=1;                    
				CarLowSpeedCmd_IO();
			}
			break;
		case    CHANGE_DEC_LIMIT_SUSD:
			SetWhyDec(DEC_SDS+event_name);
			bUnd=1;			
			CurSpeed=spd_val;
			bSetSpeedOn=1;                    
			CarLowSpeedCmd_IO();
			break;
		case    SPEED_LOW:
			if(cF_SPEED_LOW_PORT > NOT_USE_SPEED){
				bSetSpeedOn=1;                    				
				CurSpeed=spd_val;
				GetDecreasePulse(spd_val);
				DecreasePulse=CurSpdDecPulse;

//				DecreasePulse=GET_LONG(DEC_PULSE_SPD_LOW);


				if(bCarUpMove)  StopMinimumPulse=DecreasePulse+CurPulse;
				else            StopMinimumPulse=CurPulse-DecreasePulse;

				RunSpeedCmd_IO_spd3();									
			}
			break;
		case    SPEED_MID:
			if(cF_SPEED_MID_PORT > NOT_USE_SPEED){
				bSetSpeedOn=1;                    				
				CurSpeed=spd_val;

				GetDecreasePulse(spd_val);
				DecreasePulse=CurSpdDecPulse;

//				DecreasePulse=GET_LONG(DEC_PULSE_SPD_MID);

				if(bCarUpMove)  StopMinimumPulse=DecreasePulse+CurPulse;
				else            StopMinimumPulse=CurPulse-DecreasePulse;

				RunSpeedCmd_IO_spd3();						
			}
			break;
		default:
			break;
	
	}
		
	return(0);
}




	
	
	
void  __attribute__((section(".usercode")))  CarCurFloorRead_IO_spd3(void)
{

    unsigned long decrease_pulse;
    unsigned long tmppulse1,tmppulse2,newFloor;

    LocalType ReqFlr;  


    CurFTime=0;
	NextFTime=0;

    if(bFhmRun) return;


////////////////////////////////////	ForceSettingSpeed();


    ReqFlr=(LocalType)(sRamDArry[mReqStopFloor] & ONLY_FLR);     	


    if(sRamDArry[mcurfloor] > cF_TOPFLR){
        sRamDArry[mcurfloor]=0;
    }

    if(bCarUpMove){
        if(!IN_SU1){
//            if(!IN_EMG)	sRamDArry[mcurfloor]=cF_TOPFLR;   //modify ?

			if(PerfectAuto() && !bUnd){
				SetWhyDec(DEC_SUS);
			}

            bUnd=1;
            CarLowSpeedCmd_IO();
        }

		SpeedReSetting(1);
		SpeedReSetting(2);

        if(sRamDArry[mcurfloor] >= cF_TOPFLR){
            tmppulse1=FLOOR_COUNT(cF_TOPFLR);
            tmppulse2=FLOOR_COUNT(cF_TOPFLR-1);
        }
        else{
            tmppulse1=FLOOR_COUNT(sRamDArry[mcurfloor]+1);
            tmppulse2=FLOOR_COUNT(sRamDArry[mcurfloor]);
        }
            
        newFloor=(tmppulse1-tmppulse2);
        newFloor=(unsigned long)(newFloor >> 1);
        newFloor=(unsigned long)(tmppulse2 + newFloor);

        if((unsigned long)CurPulse >= (unsigned long)newFloor){
            if(sRamDArry[mcurfloor] < cF_TOPFLR) sRamDArry[mcurfloor]++;
        }


        if(ReqFlr >= cF_TOPFLR){
            tmppulse1=FLOOR_COUNT(cF_TOPFLR);
        }
        else{
            tmppulse1=FLOOR_COUNT(ReqFlr);
        }
            
        tmppulse2=DecreasePulse;
        decrease_pulse=(tmppulse1-tmppulse2);


        if((unsigned long)CurPulse >= (unsigned long)decrease_pulse){
            if(bDac || (sRamDArry[mcurfloor] >= cF_TOPFLR) || (ReqFlr >= cF_TOPFLR)){   
                bUnd=1;
                CarLowSpeedCmd_IO();
                if(sRamDArry[mcurfloor] >= cF_TOPFLR){
						#ifdef	FLOOR_64
						sRamDArry[mReqStopFloor]  = (sRamDArry[mcurfloor] | DN_READY);
						#else
						sRamDArry[mReqStopFloor]  = (sRamDArry[mcurfloor] | CAR_READY);
						#endif
                }
            }
            else{
            	if(ReqFlr < cF_TOPFLR)	sRamDArry[mReqStopFloor]++;
			}   
        }



#ifdef	FLOOR_64
        if(bUnd){
            CarLowSpeedCmd_IO();
        }			
        else{
			if(sRamDArry[mcurfloor] >= cF_TOPFLR){
				sRamDArry[mReqStopFloor] = (sRamDArry[mcurfloor] | DN_READY);  
		    	sRamDArry[mAckStopFloor] = (sRamDArry[mcurfloor] | DN_READY);
			}
			else{			
/*
               	if(CurPulse > StopMinimumPulse) sRamDArry[mReqStopFloor]  = (sRamDArry[mReqStopFloor] | UPDN_READY);
               	else                            sRamDArry[mReqStopFloor]  = (sRamDArry[mReqStopFloor] & ~UPDN_READY);    
*/
				sRamDArry[mReqStopFloor]  = (sRamDArry[mReqStopFloor] | UPDN_READY);
            }
        }

#else
        if(bUnd){
            CarLowSpeedCmd_IO();
        }		
        else{
			if(sRamDArry[mcurfloor] >= cF_TOPFLR){
				sRamDArry[mReqStopFloor] = (sRamDArry[mcurfloor] | CAR_READY);  
		    	sRamDArry[mAckStopFloor] = (sRamDArry[mcurfloor] | CAR_READY);
			}
			else{
/*
               	if(CurPulse > StopMinimumPulse) sRamDArry[mReqStopFloor]  = (sRamDArry[mReqStopFloor] | CAR_READY);
               	else                            sRamDArry[mReqStopFloor]  = (sRamDArry[mReqStopFloor] & ~CAR_READY);
*/   
				sRamDArry[mReqStopFloor]  = (sRamDArry[mReqStopFloor] | CAR_READY);
            }
        }


#endif

    }

    else if(bCarDnMove){
        if(!IN_SD1){                              //modify ?
//            if(!IN_EMG)	sRamDArry[mcurfloor]=0;

			if(PerfectAuto() && !bUnd){
				SetWhyDec(DEC_SDS);
			}
            bUnd=1;
            CarLowSpeedCmd_IO();
     	}

		SpeedReSetting(1);
		SpeedReSetting(2);



        if(sRamDArry[mcurfloor] == 0){
            tmppulse1=FLOOR_COUNT(1);
            tmppulse2=FLOOR_COUNT(0);
        }
        else{
            tmppulse1=FLOOR_COUNT(sRamDArry[mcurfloor]);
            tmppulse2=FLOOR_COUNT(sRamDArry[mcurfloor]-1);
        }
            
        newFloor=(tmppulse1-tmppulse2);
        newFloor=(unsigned long)(newFloor >> 1);
        newFloor=(unsigned long)(tmppulse2 + newFloor);

        if((unsigned long)CurPulse <= (unsigned long)newFloor){
            if(sRamDArry[mcurfloor] > 0 ) sRamDArry[mcurfloor]--;
        }


        if(ReqFlr == 0){
            tmppulse1=FLOOR_COUNT(0);
        }
        else{
            tmppulse1=FLOOR_COUNT(ReqFlr);
        }

        tmppulse2=DecreasePulse;
        decrease_pulse=(tmppulse1 + tmppulse2);


        if((unsigned long)CurPulse <= (unsigned long)decrease_pulse){
            if(bDac || (sRamDArry[mcurfloor] == 0) || (ReqFlr == 0)){   
                bUnd=1;
                CarLowSpeedCmd_IO();
                if(sRamDArry[mcurfloor] == 0){
					#ifdef	FLOOR_64
                    sRamDArry[mReqStopFloor]  = (sRamDArry[mcurfloor] | UP_READY);
					#else
                    sRamDArry[mReqStopFloor]  = (sRamDArry[mcurfloor] | CAR_READY);
					#endif
                }
            }
            else{
 				if(ReqFlr > 0)	sRamDArry[mReqStopFloor]--;
			}
        }


		#ifdef	FLOOR_64
	        if(bUnd){
	            CarLowSpeedCmd_IO();
	        }
	        else{
				if(sRamDArry[mcurfloor] == 0){
					sRamDArry[mReqStopFloor] = (sRamDArry[mcurfloor] | UP_READY);  
			    	sRamDArry[mAckStopFloor] = (sRamDArry[mcurfloor] | UP_READY);				                      
				}
				else{
/*
	                if(CurPulse < StopMinimumPulse) sRamDArry[mReqStopFloor]  = (sRamDArry[mReqStopFloor] | UPDN_READY);
	                else                            sRamDArry[mReqStopFloor]  = (sRamDArry[mReqStopFloor] & ~UPDN_READY);    
*/
					sRamDArry[mReqStopFloor]  = (sRamDArry[mReqStopFloor] | UPDN_READY);
				}
	        }

		#else
	        if(bUnd){
	            CarLowSpeedCmd_IO();
	        }			
	        else{
				if(sRamDArry[mcurfloor] == 0){
					sRamDArry[mReqStopFloor] = (sRamDArry[mcurfloor] | CAR_READY);  
			    	sRamDArry[mAckStopFloor] = (sRamDArry[mcurfloor] | CAR_READY);				                      
				}
				else{
/*
	                if(CurPulse < StopMinimumPulse) sRamDArry[mReqStopFloor]  = (sRamDArry[mReqStopFloor] | CAR_READY);
	                else                            sRamDArry[mReqStopFloor]  = (sRamDArry[mReqStopFloor] & ~CAR_READY);    
*/
					sRamDArry[mReqStopFloor]  = (sRamDArry[mReqStopFloor] | CAR_READY);
	            }
	        }
	
		#endif
    }
    else{
        bUnd=0;
        sRamDArry[mReqStopFloor]  = sRamDArry[mcurfloor];            
    }
    
    return;
}



void  __attribute__((section(".usercode"))) ELGroupDataLoad(void)
{	
	unsigned int k;
	for(k=0;k<32;k++)	parameter_mirror[k]=FlashDspCharBuf[ENCODER_PULSE+k].long_data;  
}


void  __attribute__((section(".usercode"))) WriteFlash_spd3(void)
{
    unsigned int i;

	SaveVerify = 0x55;
    flash_write(ENCODER_PULSE);
    for(i=0;i<16;i++)   parameter_mirror[i]=parameter_mirror[i+16];
    flash_write(ENCODER_PULSE + 16);
}



void  __attribute__((section(".usercode"))) DefaultDecreaseLength_spd3(void)
{
#ifndef	TEST_SIMULATION
    parameter_mirror[(DEC_LENGTH_SPD_LOW 	- ENCODER_PULSE)]  		= DEFAULT_SPEED1_DEC_LENGTH;
    parameter_mirror[(DEC_LENGTH_SPD_MID	- ENCODER_PULSE)]		= DEFAULT_SPEED2_DEC_LENGTH;
    parameter_mirror[(DEC_LENGTH_SPD_HIGH	- ENCODER_PULSE)]  		= DEFAULT_SPEED3_DEC_LENGTH;
#endif	
}       


void  __attribute__((section(".usercode"))) CaluDecreasePulseCommon_spd3(uint16_t i)
{
#ifndef	TEST_SIMULATION	
	unsigned long	tmp_mm;
	tmp_mm=GET_LONG((unsigned long)(DEC_LENGTH_SPD_LOW+i));
	MmToPulse(tmp_mm);
	
	switch(i){
		case	0:
			SpdL_DecPulse=PulseBuf;
			break;
		case	1:
			SpdM_DecPulse=PulseBuf;
			break;
		case	2:
			SpdH_DecPulse=PulseBuf;	
			break;
		default:
			break;
	}
#endif
}	



unsigned int  __attribute__((section(".usercode"))) CaluDecreasePulse_spd3(void)
{
#ifndef	TEST_SIMULATION
	bParameterChange=1;
	ParameterChangeChk();
	return(1);
#endif
}                                                                     



void  __attribute__((section(".usercode"))) DefaultEncoderRpmMpm_spd3(void)
{
#ifndef	TEST_SIMULATION

    unsigned int i;
	unsigned long	tmpRpm,tmpMpm,tmpEncoderPulse,tmpMmPerPulse,tmpMpmVariable;	
    
	ELGroupDataLoad();
    parameter_mirror[B_USER_PLANK_LENGTH-ENCODER_PULSE]     = 200;   // mm 
    parameter_mirror[NEW_MPM-ENCODER_PULSE]             	= SET_ELEV_SPEED_PER_MIM; //m/min
    parameter_mirror[RPM-ENCODER_PULSE]             		= SET_MOTOR_RPM;          //r/min

	if(USE_CHECK == MAN_USE){
    	parameter_mirror[ENCODER_PULSE-ENCODER_PULSE]   	= SET_ENCODER_PULSE_2048;      //pulse/rotate
		parameter_mirror[BASE_PLANK_PULSE-ENCODER_PULSE]   = 4878;   // mm 
	}
	else{
    	parameter_mirror[ENCODER_PULSE-ENCODER_PULSE]   	= SET_ENCODER_PULSE_1024;      //pulse/rotate
		parameter_mirror[BASE_PLANK_PULSE-ENCODER_PULSE]     	= 2440;   // mm 
	}


    parameter_mirror[(DEC_LENGTH_SPD_LOW 	- ENCODER_PULSE)]  		= DEFAULT_SPEED1_DEC_LENGTH;
    parameter_mirror[(DEC_LENGTH_SPD_MID	- ENCODER_PULSE)]		= DEFAULT_SPEED2_DEC_LENGTH;
    parameter_mirror[(DEC_LENGTH_SPD_HIGH	- ENCODER_PULSE)]  		= DEFAULT_SPEED3_DEC_LENGTH;


    parameter_mirror[(BASE_DEC_TIME -ENCODER_PULSE)]  		= 1700;	//1.7sec
    parameter_mirror[(BASE_SCURVE_TIME -ENCODER_PULSE)]		= 1000; //1.0sec
    parameter_mirror[(BASE_DEC_MPM- ENCODER_PULSE)]  		= 12; //1.2mpm

	WriteFlash_spd3();

	ELGroupDataLoad();

	tmpMmPerPulse=CaluOrgMmPerPulse();
	tmpMpmVariable	= (tmpMmPerPulse * (unsigned long)600);

    parameter_mirror[MM_PULSE -ENCODER_PULSE]  		= tmpMmPerPulse;
   	parameter_mirror[MPM_VARIABLE -ENCODER_PULSE]  	= tmpMpmVariable;	
//////////////////


	parameter_mirror[BASE_BEF_LULD_PULSE-ENCODER_PULSE] = (unsigned long)50;	// 50mm

	WriteFlash_spd3();

	CaluDecreasePulse_spd3();

#endif	
}       



unsigned int    __attribute__((section(".usercode"))) SpeedSelectCheck(unsigned int spd)
{
    unsigned long MinPulse;

	GetDecreasePulse(spd);
	MinPulse=CurSpdDecPulse;

    if(MinPulse==0) 		return(1);

  	MinPulse= (MinPulse * 2);

    if(TotalPulse>MinPulse) return(0);
    else                    return(1);
}




unsigned int    __attribute__((section(".usercode"))) SpeedHighCheck(void)
{
    if(cF_SPEED_HIGH_PORT == 0)    return(2);     
	return(SpeedSelectCheck((unsigned int)(SPEED_HIGH)));
}


unsigned int    __attribute__((section(".usercode"))) SpeedMidCheck(void)
{
    if(cF_SPEED_MID_PORT == 0)    return(2);     
	return(SpeedSelectCheck((unsigned int)(SPEED_MID)));
}

unsigned int    __attribute__((section(".usercode"))) SpeedLowCheck(void)
{
    if(cF_SPEED_LOW_PORT == 0)    return(2);     
	return(SpeedSelectCheck((unsigned int)(SPEED_LOW)));
}






unsigned int  __attribute__((section(".usercode")))   SpeedChange_spd3(void)
{
	unsigned long	tmppulse1;	
    LocalType     ret;
    ret=1;


	if(!SpeedHighCheck() && (CurSpeed < SPEED_HIGH)){   ////5xx
	    CurSpeed=SPEED_HIGH;
		GetDecreasePulse(CurSpeed);
		DecreasePulse=CurSpdDecPulse;
	    ret=0;
	}
	else if(!SpeedMidCheck() && (CurSpeed < SPEED_MID)){
	    CurSpeed=SPEED_MID;
		GetDecreasePulse(CurSpeed);
		DecreasePulse=CurSpdDecPulse;
	    ret=0;
	}


    if(ret==0){
        if(bCarUpMove)  StopMinimumPulse=DecreasePulse+CurPulse;
        else            StopMinimumPulse=CurPulse-DecreasePulse;
    }

    return(ret);
}





unsigned int  __attribute__((section(".usercode")))   SpeedSet_spd3(void)
{
    unsigned long tmppulse1,tmppulse2;
    LocalType     j,want_updn,ret;


	ret=0;
	NoStart=0;

	if((cF_SPEED_LOW_PORT == 0) && (cF_SPEED_MID_PORT == 0) && (cF_SPEED_HIGH_PORT == 0)){		
		ret=1;
		NoStart=1;
		return(NoStart);
	}



    if(INVERTER_CHECK == LG)    return(0);
    if(INVERTER_CHECK == D_F)   return(0);



    ret=0;
    want_updn=0;

    j=(sRamDArry[mAckStopFloor] & ONLY_FLR);
    
    TotalPulse=1;
    StartPulse=CurPulse;    

    tmppulse1=FLOOR_COUNT(j);
    tmppulse2=FLOOR_COUNT(sRamDArry[mcurfloor]);

    if(j>sRamDArry[mcurfloor]){
        TotalPulse=(tmppulse1-tmppulse2);   
        want_updn=1;            //up want
    }
	else{
        TotalPulse=(tmppulse2-tmppulse1);   
        want_updn=2;            //dn want
    }



    if(ret==0){
		if(!SpeedHighCheck()){
		    CurSpeed=SPEED_HIGH;
			GetDecreasePulse(CurSpeed);
			DecreasePulse=CurSpdDecPulse;

		    ret=0;
		}
		else if(!SpeedMidCheck()){
		    CurSpeed=SPEED_MID;
			GetDecreasePulse(CurSpeed);
			DecreasePulse=CurSpdDecPulse;

		    ret=0;
		}
		else if(!SpeedLowCheck()){
		    CurSpeed=SPEED_LOW;
			GetDecreasePulse(CurSpeed);
			DecreasePulse=CurSpdDecPulse;
		    ret=0;
		}
		else	ret=2;		
	}




    if(ret==0){
        if(want_updn==1){           //up want
            StopMinimumPulse=DecreasePulse + CurPulse;	      
        }
        else if(want_updn==2){           //dn want
            StopMinimumPulse=CurPulse-DecreasePulse;
        }
        else    ret=3;
    }
		    
	
	NoStart=ret;
    return(NoStart);

}


//	ver7.01


