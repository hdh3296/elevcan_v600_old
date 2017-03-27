

      
//#include  <p30f6010.h>
            
#include <p30fxxxx.h>      
#include  "iodef.h"
#include  "host_io.h"            
#include  "door.h"
#include  "com.h"
#include  "counter.h"
#include  "default_setup.h"



void    CarStopCmd(void);
void    CarUpStartCmd(void);
void    CarDnStartCmd(void);
void    CarCurFloorRead(void);
void	InverterErrorCheck(void);



//extern   void   CallMeUpDnDirectionSet(void);                                                                       
extern   void   ClrUpDnWard(void);
extern   void   UpDnCallClear(void);           
extern   void   UpWard(void);
extern	 void   DnWard(void);


const   unsigned        int    seg1[]={0x0,0x06,0x0b,0x07};
const   unsigned        int    seg0[]={0x3f,0x06,0xdb,0xcf,0xe6,0xed,0xfd,0x27,0xff,0xef,0x5c};
 


void __attribute__((section(".usercode")))   DspFloorSet(void)
{
    LocalType i,j;  

	if( !bDspSeq && (!PerfectAuto() || DoorOpenEndWaitChk() || (NoStart > 0) ) ){
//    if( !bDspSeq && (bCarErr || bCarStopNoRun || bCarStop || !bAuto || DoorOpenEndWaitChk()) ){
        j=SegError;
    
        i=(j%10);    
        SegData0=~seg0[i];
        SegData0=(SegData0 | 0x80);
    
        i=(j/10);
        SegData1=~seg0[i];
        SegData1=(SegData1 | 0x80);
    
        SegData2=( ~(0x79) | 0x80);    
    }
    else{
/*
    	sRamDArry[S0_FLOOR]  = sRamDArry[mcurfloor]+1;

        i=(UserDataType)(sRamDArry[mcurfloor] * 2);	        
		i=(i + F_FlrDspCh);
	            
        sRamDArry[DSP1]  = cF_FLRDSPCH((unsigned long)i);
        sRamDArry[DSP2]  = cF_FLRDSPCH((unsigned long)(i+1)); 

		if( bFhmRun && (sRamDArry[FHM_SEQ] < FHM_SEQ_3)){
	        sRamDArry[DSP1]  = '0';
	        sRamDArry[DSP2]  = '0'; 
		}
  */
  

        j=sRamDArry[mcurfloor]+1;
    
        i=(j%10);    
        SegData0=~seg0[i];
        SegData0=(SegData0 | 0x80);
    
        i=(j/10);
        SegData1=~seg0[i];
        SegData1=(SegData1 | 0x80);
    
        SegData2=0xff;
    }    


   	sRamDArry[S0_FLOOR]  = sRamDArry[mcurfloor]+1;
	i=(UserDataType)(sRamDArry[mcurfloor] * 2);	        		
	i=(i + F_FlrDspCh);   
	sRamDArry[DSP1]  = cF_FLRDSPCH((unsigned long)i);
	sRamDArry[DSP2]  = cF_FLRDSPCH((unsigned long)(i+1)); 

	if( bFhmRun && (sRamDArry[FHM_SEQ] < FHM_SEQ_3)){
        sRamDArry[DSP1]  = '0';
        sRamDArry[DSP2]  = '0'; 
	}
}



////////////////
/*/////////// I/O MODE////////////////////////////
000 x  zero         //
001 x  60           //fun 13    
010 x  decrease     //fun 14
011 x  90           //fun 15
100 x  manual       //fun 16
101 x  120          //fun 17
110 x  batery       //fun 18
111 x  150          //fun 19
///////////////////////////////////////*/
/*/////////// E/L MODE////////////////////////////
000 x  zero         //fun 12
001 x  manual       //fun 13
010 x  not use      //fun 14
011 x  decrease     //fun 15
100 x  auto         //fun 16
101 x  not use      //fun 17
110 x  not use      //fun 18
111 x  not use      //fun 19
///////////////////////////////////////*/

////////////////
void __attribute__((section(".usercode")))     CurSelSpeed(unsigned int spd)
{

	#ifdef	DELTA_INVERTER_AUTOLANDING_CAN
	if(WhoAutolanding == (unsigned int)DELTA_INVERTER_AUTOLANDING_CAN){
		if( (spd >= 1) && (spd <= 7)){
			spd=1;	 
			bDeltaSpdOff=1;
		}
		else	bDeltaSpdOff=0;
	}
	#endif


    switch(spd){
        case    0:
            OUT_P1(0);
            OUT_P2(0);
            OUT_P3(0);    
            break;
        case    1:
            OUT_P1(1);
            OUT_P2(0);
            OUT_P3(0);    
            break;
        case    2:
            OUT_P1(0);
            OUT_P2(1);
            OUT_P3(0);    
            break;
        case    3:
            OUT_P1(1);
            OUT_P2(1);
            OUT_P3(0);    
            break;
        case    4:
            OUT_P1(0);
            OUT_P2(0);
            OUT_P3(1);    
            break;
        case    5:
            OUT_P1(1);
            OUT_P2(0);
            OUT_P3(1);    
            break;
        case    6:
            OUT_P1(0);
            OUT_P2(1);
            OUT_P3(1);    
            break;
        case    7:
            OUT_P1(1);
            OUT_P2(1);
            OUT_P3(1);    
            break;
        default:
            OUT_P1(0);
            OUT_P2(0);
            OUT_P3(0);    
            OUT_P4(0);    
            break;
    }
}




void __attribute__((section(".usercode")))    ManualSpeedCmd_IO(void)
{
    CurSelSpeed(cF_MANUALSPEED);                        
}



/*
void __attribute__((section(".usercode")))    RelevelSpeedCmd_IO(void)
{
    CurSelSpeed(cF_RELEVELSPEED);                        
}

*/


void __attribute__((section(".usercode")))    BatterySpeedCmd_IO(void)
{
    CurSelSpeed(cF_BATTERYSPEED);                        
}



void __attribute__((section(".usercode")))    DecreaseSpeedCmd_IO(void)
{
    CurSelSpeed(cF_DECREASESPEED);     
}


void __attribute__((section(".usercode")))    ZeroSpeedCmd_IO(void)
{
    CurSelSpeed(0);                        
}





void  __attribute__((section(".usercode")))  CarCurFloorRead_ELEV(void)
{
    if(IN_FID){
#ifdef	FLOOR_64
        sRamDArry[mReqStopFloor]   = ((I_FS0_bit & 0x1f)  | UPDN_READY);
#else
        sRamDArry[mReqStopFloor]   = (I_FS0_bit  & 0x3f);				
#endif

        NextFTime=0;		
    }         
    else{
        sRamDArry[mcurfloor] = (I_FS0_bit & 0x1f);
		sRamDArry[mInvFloor] = sRamDArry[mcurfloor];  		      
        CurFTime=0;
    }
    
    if(IN_UND1)  bUnd=1;      
    else         bUnd=0;      
}



void  __attribute__((section(".usercode"))) 	InverterErrorCheck_ELEV(void)
{
    if((CurFTime>10) || (NextFTime>10)){
        if(bAuto){
            bCarStopNoRun=1;       	
            bsInvCurNext=1;
        }         		
        CurFTime=11;
        NextFTime=11;
    }
    else{	
        bsInvCurNext=0;
    }
}					




void  __attribute__((section(".usercode")))    CarLowSpeedCmd_IO(void)
{        
    if(bAuto && bManualAuto){
        if(bMoveDnOk && bMoveUpOk){
            bVoiceReady=1;			
 	        DecreaseSpeedCmd_IO();
       }
   	    else{
            sRamDArry[mCarMoveState]=0;
        }    
    }	 		     
}




void  __attribute__((section(".usercode")))   CarStopCmd_IO(void)
{        

	
	if(bOnceMove){
		bOnceMove=0;
		sRamDArry[mCarMoveState]=0;

		if(DecStartPulse >0){	
			if(DecStartPulse >= CurPulse)	DecTotalPulse = (DecStartPulse - CurPulse);	
			else							DecTotalPulse = (CurPulse-DecStartPulse);	
			DecStartPulse=0;
		}
	}


    switch(sRamDArry[mCarMoveState]){
        case	0:
            sRamDArry[mCarMoveState]=1;
            break;							
        case  1:                                   
            sRamDArry[mCarMoveState]=2;
            bOneStep=0;               
            bTwoStep=0;                
            bThreeStep=0;              
            bFourStep=0;               
			MotorStopTime=0;
            break;
        case  2:
            ZeroSpeedCmd_IO();
            if(MotorStopTime>iF_Bk1OffTime){
                bOneStep=1;               
                OUT_BK1(0);                     
            }              

            if(MotorStopTime>iF_Bk2OffTime){
                bTwoStep=1;               
                OUT_BK2(0);
            }              

            if(MotorStopTime>iF_UDOffTime){
                bThreeStep=1;               
          	    CallMeUpDnDirectionSet();                                                                       
                OUT_U_W(0);                                                               
                OUT_D_W(0);                                                        
            }              

            if(MotorStopTime>iF_P4OffTime){
                bFourStep=1;               
                OUT_P4(0);
            }


            if(bOneStep && bTwoStep && bThreeStep && bFourStep){               
                ZeroSpeedCmd_IO();
                OUT_P4(0);
                OUT_U_W(0);                                                               
                OUT_D_W(0);                                                        
                OUT_BK1(0);
                OUT_BK2(0);

                bMoveCar=0;
                bCarUpMove=0;
                bCarDnMove=0;
                S2_CAR_MOVE1=0;
   				ElevMoveTime=0;
                if(!bAuto)  ClrUpDnWard();
                bVoiceReady=0;   
            }              
            break;
        default:
            sRamDArry[mCarMoveState]=0;
            break;
    }
}





LocalType  __attribute__((section(".usercode")))  OilTypeRunState(void)
{
    LocalType i;  
    
    i=0;

    if((INVERTER_CHECK == D_F) && (!OilLopeTypeChk) && S1_AUTO1 && !bD_F_FloorOn && IN_LU && IN_LD ){ 
        i=1;
    }
        
    return(i);
}


void  __attribute__((section(".usercode")))  UpDnRunOut(void)
{
    if(bAuto)	RunSpeedCmd_IO();
    else{
        if(OilTypeRunState()){
            RunSpeedCmd_IO();
        }
        else{
            Mnanual_Speed_Sel();
        }
    } 
}



void  __attribute__((section(".usercode")))   CarUpStartCmd_IO(void)
{
    if(bMoveUpOk){
        UpWard();

//	ver7.01	
//        if(sRamDArry[mcurfloor]< cF_TOPFLR)  sRamDArry[mReqStopFloor]  = sRamDArry[mcurfloor]+1;
//        else                                 sRamDArry[mReqStopFloor]  = cF_TOPFLR;
     	
        switch(sRamDArry[mCarMoveState]){
             case  0:
                ZeroSpeedCmd_IO();
                OUT_U_W(0);                                                               
                OUT_D_W(0);                                                        
                OUT_BK1(0);                     
                OUT_BK2(0);
                OUT_P4(0);    

                sRamDArry[mCarMoveState]=1;
                break;
             case  1:
                S2_CAR_MOVE1=1; 
                bMoveCar=1;
                bCarUpMove=1;
                bCarDnMove=0;

                if(ElevMoveTime > cF_STTM1){
                    if(INVERTER_CHECK != LG)    OUT_P4(1);
                }
                if(ElevMoveTime > cF_STTM2){
                    OUT_U_W(1);
                }                                               
                if(ElevMoveTime > cF_STTM3){
                    OUT_BK2(1);
                }              
                if(ElevMoveTime > cF_STTM4){
                     OUT_BK1(1);                     
                }
                if(ElevMoveTime > cF_STTM5){
                    UpDnRunOut();
                }
                break;                  
              default:
                sRamDArry[mCarMoveState]=0;
                break;
        }
    }
    else{
        sRamDArry[mCarMoveState]=0;
    }     
}



void  __attribute__((section(".usercode")))   CarDnStartCmd_IO(void)
{
    if(bMoveDnOk){   
        DnWard();

//	ver7.01
//        if(sRamDArry[mcurfloor]>0)  sRamDArry[mReqStopFloor]  = sRamDArry[mcurfloor]-1;
//        else                        sRamDArry[mReqStopFloor]  = 0;


        switch(sRamDArry[mCarMoveState]){
            case  0:
                ZeroSpeedCmd_IO();
                OUT_U_W(0);                                                               
                OUT_D_W(0);                                                        
                OUT_BK1(0);                     
                OUT_BK2(0);
                OUT_P4(0);    

                sRamDArry[mCarMoveState]=1;
                break;
             case  1:
                S2_CAR_MOVE1=1; 
                bMoveCar=1;
                bCarUpMove=0;
                bCarDnMove=1;

                if(ElevMoveTime > cF_STTM1){
                    if(INVERTER_CHECK != LG)    OUT_P4(1);
                }
                if(ElevMoveTime > cF_STTM2){
                    OUT_D_W(1);
                }                                               
                if(ElevMoveTime > cF_STTM3){
                    OUT_BK2(1);
                }              
                if(ElevMoveTime > cF_STTM4){
                    OUT_BK1(1);                     
                }
                if(ElevMoveTime > cF_STTM5){
                    UpDnRunOut();
                }
                break;                  

            default:
                sRamDArry[mCarMoveState]=0;
                break;
        }
    }
    else{
        sRamDArry[mCarMoveState]=0;
    }        
}




LocalType  __attribute__((section(".usercode")))  CurFloorRead_OnOff(void)
{
    LocalType   j;

    j=0;


    if(!IN_SD1 && !IN_EMG){				//modify ?
        sRamDArry[mcurfloor]=0;
        j++;
    }

    if(!IN_SU1 && !IN_EMG){               //modify ?
        sRamDArry[mcurfloor]=cF_TOPFLR;
        j++;
    }

    if(!IN_X0 && (cF_TOPFLR >= 2)){   ////chk chk
        sRamDArry[mcurfloor]=1;
        j++;
    }

    if(!IN_X1 && (cF_TOPFLR >= 3)){
        sRamDArry[mcurfloor]=2;
        j++;
    }
    if(!IN_X2 && (cF_TOPFLR >= 4)){
        sRamDArry[mcurfloor]=3;
        j++;
    }
    if(!IN_X3 && (cF_TOPFLR >= 5)){
        sRamDArry[mcurfloor]=4;
        j++;
    }
    if(!IN_X4 && (cF_TOPFLR >= 6)){
        sRamDArry[mcurfloor]=5;
        j++;
    }
    if(!IN_X5 && (cF_TOPFLR >= 7)){
        sRamDArry[mcurfloor]=6;
        j++;
    }
    if(!IN_X6 && (cF_TOPFLR >= 8)){
        sRamDArry[mcurfloor]=7;
        j++;
    }

    bD_F_FloorOn=0;
    
    if(j == 1){
        bD_F_FloorOn=1;        
    }
    else if(j >= 2){
		if( !IN_AUTO){
            bEqualFloorError=1;
			bCarErr=1;
		}
    }

    return(j);
}




int  __attribute__((section(".usercode")))  Up_Direct_Dec_Chk(void)
{
  
	if(sRamDArry[mcurfloor] >= cF_TOPFLR)	return(0);
    else if( (sRamDArry[mcurfloor] & ONLY_FLR) == (sRamDArry[mAckStopFloor] & ONLY_FLR)){
		if(bDac)	return(0);
	}

	return(1);
}

int  __attribute__((section(".usercode")))  Dn_Direct_Dec_Chk(void)
{
  
	if(sRamDArry[mcurfloor] == 0)	return(0);
    else if( (sRamDArry[mcurfloor] & ONLY_FLR) == (sRamDArry[mAckStopFloor] & ONLY_FLR)){
		if(bDac)	return(0);
	}

	return(1);
}



void  __attribute__((section(".usercode")))  CarCurFloorRead_OnOff(void)
{

    LocalType ReqFlr;  


    CurFTime=0;
	NextFTime=0;

    if(bFhmRun) return;

    CurFloorRead_OnOff();


    ReqFlr=(LocalType)(sRamDArry[mReqStopFloor] & ONLY_FLR);     	



    if(sRamDArry[mcurfloor] > cF_TOPFLR){
        sRamDArry[mcurfloor]=0;
    }


    if(bCarUpMove){
        if(!IN_SU1){							//modify ?
            if(!IN_EMG)	sRamDArry[mcurfloor]=cF_TOPFLR;   
            bUnd=1;
            CarLowSpeedCmd_IO();
        }

        if(bD_F_FloorOn){
			if( Up_Direct_Dec_Chk() == 0){
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
        }



		#ifdef	FLOOR_64
	        if(bUnd){
	            CarLowSpeedCmd_IO();
	        }			
	        else{
	            if(sRamDArry[mcurfloor] < cF_TOPFLR){
	                if(!bD_F_FloorOn)    sRamDArry[mReqStopFloor]  = ((sRamDArry[mcurfloor]+1) | UPDN_READY);                
	    			else if(((sRamDArry[mReqStopFloor] & ONLY_FLR) != (sRamDArry[mAckStopFloor] & ONLY_FLR))  ||  !(sRamDArry[mReqStopFloor] & UPDN_READY)){
	                    sRamDArry[mReqStopFloor]  = (sRamDArry[mReqStopFloor] & ~UPDN_READY);
	                }
	            }
	        }

			if(sRamDArry[mcurfloor] >= cF_TOPFLR){
				sRamDArry[mReqStopFloor] = (sRamDArry[mcurfloor] | DN_READY);  
		    	sRamDArry[mAckStopFloor] = (sRamDArry[mcurfloor] | DN_READY);
			}
		#else
	        if(bUnd){
	            CarLowSpeedCmd_IO();
	        }			
	        else{
	            if(sRamDArry[mcurfloor] < cF_TOPFLR){
	                if(!bD_F_FloorOn)    sRamDArry[mReqStopFloor]  = ((sRamDArry[mcurfloor]+1) | CAR_READY);                
	    			else if(((sRamDArry[mReqStopFloor] & ONLY_FLR) != (sRamDArry[mAckStopFloor] & ONLY_FLR))  ||  !(sRamDArry[mReqStopFloor] & CAR_READY)){
	                    sRamDArry[mReqStopFloor]  = (sRamDArry[mReqStopFloor] & ~UPDN_READY);
	                }
	            }
	            else    sRamDArry[mReqStopFloor]  = (sRamDArry[mcurfloor] | CAR_READY);                        
	        }

			if(sRamDArry[mcurfloor] >= cF_TOPFLR){
				sRamDArry[mReqStopFloor] = (sRamDArry[mcurfloor] | CAR_READY);  
		    	sRamDArry[mAckStopFloor] = (sRamDArry[mcurfloor] | CAR_READY);
			}
		#endif
    }


    else if(bCarDnMove){
        if(!IN_SD1){                             //modify ?
            if(!IN_EMG)	sRamDArry[mcurfloor]=0;

            bUnd=1;
            CarLowSpeedCmd_IO();
        }

        if(bD_F_FloorOn){
			if( Dn_Direct_Dec_Chk() == 0){
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
        }

		#ifdef	FLOOR_64
	        if(bUnd){
	            CarLowSpeedCmd_IO();
	        }			
	        else{
	            if(sRamDArry[mcurfloor] > 0){
	                if(!bD_F_FloorOn)    sRamDArry[mReqStopFloor]  = ((sRamDArry[mcurfloor]- 1) | UPDN_READY);                
	    			else if(((sRamDArry[mReqStopFloor] & ONLY_FLR) != (sRamDArry[mAckStopFloor] & ONLY_FLR))  ||  !(sRamDArry[mReqStopFloor] & UPDN_READY)){
	                    sRamDArry[mReqStopFloor]  = sRamDArry[mcurfloor];                        
	                }
	            }
	        }

			if(sRamDArry[mcurfloor] == 0){
				sRamDArry[mReqStopFloor] = (sRamDArry[mcurfloor] | UP_READY);  
		    	sRamDArry[mAckStopFloor] = (sRamDArry[mcurfloor] | UP_READY);
			}
		#else
	        if(bUnd){
	            CarLowSpeedCmd_IO();
	        }			
	        else{
	            if(sRamDArry[mcurfloor] > 0){
	                if(!bD_F_FloorOn)    sRamDArry[mReqStopFloor]  = ((sRamDArry[mcurfloor]- 1) | CAR_READY);                
	    			else if(((sRamDArry[mReqStopFloor] & ONLY_FLR) != (sRamDArry[mAckStopFloor] & ONLY_FLR))  ||  !(sRamDArry[mReqStopFloor] & CAR_READY)){
	                    sRamDArry[mReqStopFloor]  = sRamDArry[mcurfloor];                        
	                }
	            }
	            else    sRamDArry[mReqStopFloor]  = (sRamDArry[mcurfloor] | CAR_READY);                        
	        }

			if(sRamDArry[mcurfloor] == 0){
				sRamDArry[mReqStopFloor] = (sRamDArry[mcurfloor] | CAR_READY);  
		    	sRamDArry[mAckStopFloor] = (sRamDArry[mcurfloor] | CAR_READY);
			}
		#endif

    }

    else{
        bUnd=0;
        sRamDArry[mReqStopFloor]  = sRamDArry[mcurfloor];            
    }

}




void  __attribute__((section(".usercode"))) 	InverterErrorCheck_IO(void)
{
	#ifdef	DELTA_INVERTER_AUTOLANDING_CAN
	if(WhoAutolanding == (unsigned int)DELTA_INVERTER_AUTOLANDING_CAN){
    	bsInvCurNext=0;
	}
	#endif

}



void   __attribute__((section(".usercode")))   CarStopCmd(void)
{
    CarStopCmd_IO();
	S3_SHIFT1=0; //shift   
}


void  __attribute__((section(".usercode")))    CarUpStartCmd(void)
{
	if(bPowerSaveMoveValid){
	    bSaveFlash=1;
		bOnceMove=1;
	    CarUpStartCmd_IO();
	}
}


void  __attribute__((section(".usercode")))    CarDnStartCmd(void)
{
	if(bPowerSaveMoveValid){
	    bSaveFlash=1;
		bOnceMove=1;
	    CarDnStartCmd_IO();
	}
}



void  __attribute__((section(".usercode")))    CarCurFloorRead(void)
{
	#ifdef	DELTA_INVERTER_AUTOLANDING_CAN
    	DeltaCarCurFloorRead();
		DeltaInverterReqStopFloor();
	#else
	    if(INVERTER_CHECK == LG)                                CarCurFloorRead_ELEV();                                             
	    else if(INVERTER_CHECK == D_F)                          CarCurFloorRead_OnOff();                                             
	    else{
	    	CarCurFloorRead_IO();
		}
	#endif

}



void   __attribute__((section(".usercode"))) InverterErrorCheck(void)
{
    if(INVERTER_CHECK == LG)            InverterErrorCheck_ELEV();                                             
    else                                InverterErrorCheck_IO();
}
