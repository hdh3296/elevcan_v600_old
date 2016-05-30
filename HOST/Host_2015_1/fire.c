
#include <p30fxxxx.h>
#include  "30f6010_io.h"            
#include  "host_io.h"            
#include  "iodef.h"
#include  "door.h"
#include  "com.h"
#include  "counter.h"

/*
unsigned int  __attribute__((section(".usercode")))   FireTwoBuzStart(void)
{
	if(bFirstFire && bSecondFire){
		S3_CUR_KEY1=1;       
		if((sRamDArry[mHighFloor] > 0) || (sRamDArry[mLowFloor] > 0)){
			bFireTimeRun=1;
			if((RestartTime/5) % 2) OUT_BUZ(1);
			else                    OUT_BUZ(0);
			if(RestartTime > 50){
				bDoorCloseCmd=1;
				bOpenDoorOk=0;
				bDoorCloseOk=1;
				bFR2Start1=1;
				OUT_BUZ(0);
				StartFireFloor();
			}
		}
	}
///////////////////

	if(bFirstFire && bSecondFire){
		if((sRamDArry[mHighFloor] > 0) || (sRamDArry[mLowFloor] > 0)){
			bFireTimeRun=1;
			if((RestartTime/5) % 2) OUT_BUZ(1);
			else                    OUT_BUZ(0);
			if(RestartTime > 50){
				bDoorCloseCmd=1;
				bOpenDoorOk=0;
				bDoorCloseOk=1;
				bFR2Start1=1;
				OUT_BUZ(0);
				if( !StartFireFloor())	sRamDArry[mFireSeq]=FIRE_THREE;
			}
		}
	}

///////////////////
}
*/



unsigned int  __attribute__((section(".usercode")))   FireOneTwoClear(void)
{
	bFR2Start1=0;
	if(bFireTimeRun){
		bFireTimeRun=0;		                  	
	}		                  	
	return(0);			                  	
}



unsigned int  __attribute__((section(".usercode")))   DoorOpenOnChk(void)
{
	if(New_Law_SystemChk()){
		SafetyChk();	
		if(CloseKeyCheck() || SafetyChk()){
			return(1);
		}                   
	}
	else{
    	if(CloseKeyCheck() && (sRamDArry[mHighFloor]==0) && (sRamDArry[mLowFloor]==0)){
			return(1);
		}
	}
	return(0);
}



unsigned int  __attribute__((section(".usercode")))   StartFireFloor(void)
{

	if(sRamDArry[mHighFloor] > 0){
		S3_CUR_KEY1=0;         
		sRamDArry[mNewAckStopFloor]=sRamDArry[mHighFloor];  
		sRamDArry[mDoorSeq] = DOOR_CLOSE_START;
		sRamDArry[mFireSeq]=FIRE_TWO;                     
		return(1);
	}
	else if(sRamDArry[mLowFloor] > 0){
		S3_CUR_KEY1=0;       
		sRamDArry[mNewAckStopFloor]=sRamDArry[mLowFloor];
		sRamDArry[mDoorSeq] = DOOR_CLOSE_START;
		sRamDArry[mFireSeq]=FIRE_TWO;                     
		return(1);
	}
	else	return(0);
}




unsigned int  __attribute__((section(".usercode")))   Safe_Fire_Service(void)
{

	bCarButClr=0;
	if(bExt_Second_FIRE)	bCarButClr=1;	

	if(!bMoveCar && (sRamDArry[mcurfloor] == FireBaseFloor)){  
		if(bUpWard || bDnWard)					return(0);             
		if(sRamDArry[mDoor] | MAIN_CLOSE_KEY)	return(0);
		if(sRamDArry[mDoor] | SUB_CLOSE_KEY)	return(0);
                            
		if(bOnLuLd && bDoorOpenEnd && (ElevStopTime < 200)){
			ClrUpDnWard();       			
			sRamDArry[mDoor]    = (sRamDArry[mDoor] & MAIN_SUB_OPEN_KEY_CLEAR);   
			if(bSubSlaveFire)	sRamDArry[mDoor]=( sRamDArry[mDoor] | SUB_OPEN_KEY);                            
			else				sRamDArry[mDoor]=( sRamDArry[mDoor] | MAIN_OPEN_KEY);                           
		} 			
	}
	else{
		if(sRamDArry[mDoorSeq] == READY_ELEVATOR){                
			if(ElevStopTime > 10){
				if(sRamDArry[mcurfloor] > FireBaseFloor)        sRamDArry[mLowFloor] = (FireBaseFloor | CAR_READY);
				else                                            sRamDArry[mHighFloor] =(FireBaseFloor | CAR_READY);
				sRamDArry[mNewAckStopFloor]=FireBaseFloor | CAR_READY;        	
			}
		}
	}            

	return(0);            
}


unsigned int  __attribute__((section(".usercode")))   Normal_Fire_Service(void)
{

	bCarButClr=1;

	if(bMoveCar){                
		if(bCarUpMove){                
			if(sRamDArry[mcurfloor] < FireBaseFloor){
				if(!bUnd){
					sRamDArry[mAckStopFloor]=(unsigned char)(FireBaseFloor | UPDN_CAR_READY);
					sRamDArry[mHighFloor]   =(unsigned char)(FireBaseFloor | UPDN_CAR_READY);
				}
			}
			else{
				sRamDArry[mLowFloor]  = 0;
				sRamDArry[mHighFloor] = 0;
			}
		}	
		else if(bCarDnMove){                
			if(sRamDArry[mcurfloor] > FireBaseFloor){
				if(!bUnd){
					sRamDArry[mAckStopFloor]=(unsigned char)(FireBaseFloor | UPDN_CAR_READY);
					sRamDArry[mLowFloor] = (unsigned char)(FireBaseFloor | UPDN_CAR_READY);
				}
			}
			else{
				sRamDArry[mLowFloor]  = 0;
				sRamDArry[mHighFloor] = 0;
			}
		}
	}

 	else{
    	if(sRamDArry[mcurfloor] == FireBaseFloor){
			if(bExt_Second_FIRE){
				Safe_Fire_Service();
				return(0);
			}

			sRamDArry[mDoor]    = (sRamDArry[mDoor] & MAIN_SUB_OPEN_KEY_CLEAR);   
			if(bSubSlaveFire)	sRamDArry[mDoor]=( sRamDArry[mDoor] | SUB_OPEN_KEY);                            
			else				sRamDArry[mDoor]=( sRamDArry[mDoor] | MAIN_OPEN_KEY);                            

			if( (bOpenDoorOk || !bDoorCloseOk)){
				bFireFlrOn=1;
				if(bFirstFire)	sRamDArry[mFireSeq]=FIRE_ONE;                
			}
			else{
				if(bOnLuLd && bDoorOpenEnd){
					ClrUpDnWard();       
					if(sRamDArry[mDoorSeq] >= DOOR_REOPEN_CHECK){
						if(NewDoorSelect == MAIN_SUB_DOOR){
							if( (CurDoorSelect == SUB_DOOR) && bSubSlaveFire){
	                			sRamDArry[mDoorSeq]=DOOR_OPEN_START;
							}
						}
						else{
                			sRamDArry[mDoorSeq]=DOOR_OPEN_START;
						}
                	}
				}
          		else if(bOnLuLd && (sRamDArry[mDoorSeq] > DOOR_OPEN_WAIT)){
					if(NewDoorSelect == MAIN_SUB_DOOR){
						if( (CurDoorSelect == SUB_DOOR) && bSubSlaveFire){
                			sRamDArry[mDoorSeq]=DOOR_OPEN_START;
						}
					}
					else{
               			sRamDArry[mDoorSeq]=DOOR_OPEN_START;
					}
				}								
        	}
		}
		else{
			bReOpen=1;
			if(ElevStopTime > 10){
				if(sRamDArry[mcurfloor] > FireBaseFloor)        sRamDArry[mLowFloor] = (FireBaseFloor | CAR_READY);
				else                                            sRamDArry[mHighFloor] =(FireBaseFloor | CAR_READY);
				sRamDArry[mNewAckStopFloor]=FireBaseFloor | CAR_READY;        	
			}
		}            
	}

	return(0);
}


unsigned int  __attribute__((section(".usercode")))   Fire_Service(void)
{
	unsigned int	sta;
	

  switch(sRamDArry[mFireSeq]){
        case    NO_FIRE:
            break;                
        case    FIRE_START:
			if(bSafeFire){
				Safe_Fire_Service();
				return(0);
			}
			else{			
				Normal_Fire_Service();	
				return(0);
			}
            break;
        case    FIRE_ONE:              
            if(bFirstFire){
                ClrUpDnWard();       
                S3_CUR_KEY1=1;               
//				bFireFlrOn=1;

				if(DoorOpenOnChk()){
                    SelectDoorOpen_you();
				}
                else  if(!bDoorCloseOk){
                    bDoorCloseCmd=1;
                    if(bFirstFire && bSecondFire){
                        if((sRamDArry[mHighFloor] > 0) || (sRamDArry[mLowFloor] > 0)){
							bFireTimeRun=1;
                            if(RestartTime > 50){
		                        bDoorCloseCmd=1;
		                        bOpenDoorOk=0;
		                        bDoorCloseOk=1;
		                        bFR2Start1=1;
								if( !StartFireFloor())	sRamDArry[mFireSeq]=FIRE_THREE;
                            }
							else if((RestartTime/5) % 2)	bOldFireBuz=1;

                        }
                    }
                }
                if(bDoorCloseOk){
					if( !StartFireFloor())	sRamDArry[mFireSeq]=FIRE_THREE;
                }
            }
            else{
                S3_CUR_KEY1=0;
                sRamDArry[mFireSeq]=FIRE_START;                            
                sRamDArry[mDoorSeq] = DOOR_CLOSE_START;
            }              

            break;            
        case    FIRE_TWO:
			bFireTimeRun=0;
        	if(sRamDArry[mDoorSeq] == STOP_ELEVATOR){
                S3_CUR_KEY1=1;
            }

            if(!bDoorCloseOk){
                sRamDArry[mFireSeq]=FIRE_THREE;
                S3_CUR_KEY1=0;
                bCarErr=1;
            	bFR2Start1=0;


/*
				if( !bFR2Start1){
                	bCarErr=1;
				}
            	bFR2Start1=0;
*/

            }
            break;
        case    FIRE_THREE:
			bFR2Start1=0;

            if(bFirstFire){
				S3_CUR_KEY1=1;       
              	ClrUpDnWard();       
                SafetyChk();
              	if(!OpenKeyCheck() || SafetyChk() ){
              		SelectDoorOpen_you();
                	sRamDArry[mHighFloor]=sRamDArry[mLowFloor]=0;
               		sRamDArry[mNewAckStopFloor]=0;
              		sRamDArry[mAckStopFloor] = 0;         
              		ClrUpDnWard(); 
              	}                        
          		else{
                	if(DoorCloseOnTime <= 5)  bDoorCloseCmd=1;      
              	}

                if(bFirstFire && bSecondFire){
					S3_CUR_KEY1=1;       
					if((sRamDArry[mHighFloor] > 0) || (sRamDArry[mLowFloor] > 0)){
						StartFireFloor();
					}
				}

              	if(bOpenDoorOk){
                	DoorCloseTime=0;
                	sRamDArry[mFireSeq]=FIRE_ONE;     
              	}			
              	else if(bDoorCloseOk){   
					StartFireFloor();
              	}
            }
            else{
              S3_CUR_KEY1=0;
              sRamDArry[mFireSeq] = FIRE_START;                            
              sRamDArry[mDoorSeq] = DOOR_CLOSE_START;
            }                 

            break;
  }

	return(0);
}




unsigned int  __attribute__((section(".usercode")))   FireConditionChk(void)
{

	bSafeFire=0;
	bSecondFire=0;
	bFirstFire=0;

	if(New_Law_SystemChk()){
		bFireTimeRun=0;	
      	bFR2Start1=0;	          

		if( !IN_FIRE || bExt_FIRE || bSlaveFire || bExt_Second_FIRE){
			S2_FIRE1=1;
/*
			if( !IN_FR1 || bFirstFire){
				if(bFireFlrOn)	bFirstFire=1;
			}	
*/
			if( !IN_FR1){
				bFirstFire=1;
			}	
			else{
				if(!IN_FR2 && !bExt_Second_FIRE){
					bSafeFire=1;
				}

			}
			return(1);         
		}	
	}
	else{
		
		if( !IN_FIRE || bExt_FIRE || bSlaveFire || (SubFireCheck()) || !IN_FR1 || bExt_Second_FIRE){
			S2_FIRE1=1;
			if( !IN_FR1){
				bExt_Second_FIRE=0;
				bFirstFire=1;
				if( !IN_FR2)	bSecondFire=1;
			}
			else	bFirstFire=0;			
			return(1);         
		}	
	}

/////////////////	bFirstFire=0;
	S2_FIRE1=0;
	S3_CUR_KEY1=0;
	sRamDArry[mFireSeq] = NO_FIRE;
	bFireFlrOn=0;
	FireOneTwoClear();

	return(0);         
}



void  __attribute__((section(".usercode")))     CommonFireKeyCheck(void)
{
	if(FireConditionChk()){

		if(!bFirstFire || !bSecondFire){
			FireOneTwoClear();
		}        
	
		if((sRamDArry[mHighFloor] == 0) && (sRamDArry[mLowFloor] == 0) && !bMoveCar){
			FireOneTwoClear();
		}

		if(New_Law_SystemChk()){
			if( !bFireFlrOn)	FireBaseFloor=cF_FIRESAFEFLR;
			else				FireBaseFloor=sRamDArry[mcurfloor];
		}
		else	FireBaseFloor=cF_FIRESAFEFLR;
				
		if(S2_FIRE1){
			if(sRamDArry[mFireSeq]==NO_FIRE){
				if(bFirstFire){
					if(bMoveCar){
						sRamDArry[mFireSeq]=FIRE_TWO;
					}
					else{
						sRamDArry[mFireSeq]=FIRE_THREE;            
					}
				}
				else{
					sRamDArry[mFireSeq]=FIRE_START;
				}
			}
		}

        if(FireBaseFloor>cF_TOPFLR)   FireBaseFloor=sRamDArry[mcurfloor];     
	}
}



void  __attribute__((section(".usercode")))     FireKeyCheck(void)
{

	bOldFireBuz=0;

	if(PerfectAuto()){
		CommonFireKeyCheck();
    }
	else{
      	sRamDArry[mFireSeq] = NO_FIRE;
      	S3_CUR_KEY1=0;
      	S2_FIRE1=0;

		bFirstFire=0;
		bSecondFire=0;
		bSafeFire=0;

		bSlaveFire=0;
		bSubSlaveFire=0;         
		bFireFlrOn=0;
		FireOneTwoClear();
    }

	Fire_Service();
	
}




