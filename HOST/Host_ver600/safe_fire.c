
#include <p30fxxxx.h>
#include  "30f6010_io.h"            
#include  "host_io.h"            
#include  "iodef.h"
#include  "door.h"
#include  "com.h"
#include  "counter.h"




unsigned int  __attribute__((section(".usercode")))   SafeFire_Service(void)
{
	

  switch(sRamDArry[mFireSeq]){
        case    NO_FIRE:
            break;                
        case    FIRE_START:
			bCarButClr=0;
            if(!bMoveCar){  
                if(sRamDArry[mcurfloor] == FireBaseFloor){
                	if(bOnLuLd && bDoorOpenEnd && (ElevStopTime < 200)){
                    	ClrUpDnWard();       
                        NextFloorTime=0;

						sRamDArry[mDoor]    = (sRamDArry[mDoor] & MAIN_SUB_OPEN_KEY_CLEAR);   
						if(bSubSlaveFire)	sRamDArry[mDoor]=( sRamDArry[mDoor] | SUB_OPEN_KEY);                            
						else				sRamDArry[mDoor]=( sRamDArry[mDoor] | MAIN_OPEN_KEY);                            

					}
					return(0);

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
            }            
            break;
        case    FIRE_ONE:              

/*
			sta=0;
            if(bFirstFire){
                ClrUpDnWard();       
                S3_CUR_KEY1=1;               

				if(DoorOpenOnChk()){
                    SelectDoorOpen_you();
				}

                else  if(!bDoorCloseOk){
                    bDoorCloseCmd=1;
                    if(bFirstFire && bSecondFire){
                        if((sRamDArry[mHighFloor] > 0) || (sRamDArry[mLowFloor] > 0)){
							sta=1;
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
*/

            break;            
        case    FIRE_TWO:
/*
			bFireTimeRun=0;
        	if(sRamDArry[mDoorSeq] == STOP_ELEVATOR){
                S3_CUR_KEY1=1;
            }

            if(!bDoorCloseOk){
                sRamDArry[mFireSeq]=FIRE_THREE;
                S3_CUR_KEY1=0;

				if( !bFR2Start1){
                	bCarErr=1;
				}
            	bFR2Start1=0;
            }
*/

            break;
        case    FIRE_THREE:
/*
			sta=0;				
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
						sta=1;
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


              	if(bOpenDoorOk){
                	DoorCloseTime=0;
                	sRamDArry[mFireSeq]=FIRE_ONE;     
              	}			
              	else if(bDoorCloseOk){                 
            		if(bFirstFire){
						StartFireFloor();
                    }
              	}
            }
            else{
              S3_CUR_KEY1=0;
              sRamDArry[mFireSeq] = FIRE_START;                            
              sRamDArry[mDoorSeq] = DOOR_CLOSE_START;
            }                 
*/

            break;
  }

	return(0);
}




