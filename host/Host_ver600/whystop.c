

void  __attribute__((section(".usercode"))) WhyStop(void)
{

	if(bsLope){
		if(sRamDArry[mSysStatus] >= sLOPE_BRK)   
		sRamDArry[mSysStatus]=sLOPE_BRK;        
	}   
	else if(bsSlip){
		if(sRamDArry[mSysStatus] >= sSLIP)   
		sRamDArry[mSysStatus]=sSLIP;       
	}
	else if(bsInvertErr){
		if(sRamDArry[mSysStatus] >= sInvertErr)   
		sRamDArry[mSysStatus]=sInvertErr;         
   	}

	else if(bsHdsRunOff){
		if(sRamDArry[mSysStatus] >= sHDS_RUN_OFF)   
		sRamDArry[mSysStatus]=sHDS_RUN_OFF;                       
	}

	else if(bsEmergency){
		if(sRamDArry[mSysStatus] >= sEMERGENCY)   
		sRamDArry[mSysStatus]=sEMERGENCY;         
	}

	else if(bInspect){
        sRamDArry[mSysStatus]=sINSPECT;      
	}
	else if(bsInvCurNext){
		if(sRamDArry[mSysStatus] >= sI_C_N_FLR)   
		sRamDArry[mSysStatus]=sI_C_N_FLR;         
   	}

	else if(bsUls){
		if(sRamDArry[mSysStatus] >= sULS)   
		sRamDArry[mSysStatus]=sULS;            
	}
   
	else if(bsDls){
		if(sRamDArry[mSysStatus] >= sDLS)   
		sRamDArry[mSysStatus]=sDLS;            
	}


	else if(bRelevelErr){
		if(sRamDArry[mSysStatus] >= sRelevelError)   
		sRamDArry[mSysStatus]=sRelevelError;                       
	}
   
   
	else if(bsCleRunOff){
		if(sRamDArry[mSysStatus] >= sCLE_RUN_OFF)   
		sRamDArry[mSysStatus]=sCLE_RUN_OFF;                  
	}
   
	else if(bsHdsNoOn){
		if(sRamDArry[mSysStatus] > sHDS_NO_ON)   
		sRamDArry[mSysStatus]=sHDS_NO_ON;                        
	}
   
	else if(bsCleNoOn){
		if(sRamDArry[mSysStatus] > sCLE_NO_ON)   
		sRamDArry[mSysStatus]=sCLE_NO_ON;                        
	}
   
	else if(bsNextFloor){
		if(sRamDArry[mSysStatus] > sNEXT_FLOOR)   
		sRamDArry[mSysStatus] = sNEXT_FLOOR;               
	}

	else if(bsLuLdNoOff){
		if(sRamDArry[mSysStatus] > sLULD_NO_OFF)  
		sRamDArry[mSysStatus] = sLULD_NO_OFF;                         
	}

	else if(bMotor_Overheat){
		if(sRamDArry[mSysStatus] > sMOTOR_OVERHEAT)   
		sRamDArry[mSysStatus]=sMOTOR_OVERHEAT;      
	}   


	else if(bDoorJumper){
		if(sRamDArry[mSysStatus] >= sCarDoor_Jumper)   
		sRamDArry[mSysStatus]=(sCarDoor_Jumper + DoorJumperNm);       				
	} 
  
	else if(bEncoderErr){
		if(sRamDArry[mSysStatus] >= sEncoderErr)   
		sRamDArry[mSysStatus]=sEncoderErr;       				
	}   

	else if(bEncoderABErr){
		if(sRamDArry[mSysStatus] >= sEncoderABErr)   
		sRamDArry[mSysStatus]=sEncoderABErr;       				
	}   

	else if(bFlrMatchErr){
		if(sRamDArry[mSysStatus] >= sEqualFloorError)   
		sRamDArry[mSysStatus]=sEqualFloorError;       				
	}   

	else if(bsBreakMgtOpen){
		if(sRamDArry[mSysStatus] >= sBreakMgtOpen)      
		sRamDArry[mSysStatus] = sBreakMgtOpen;       				
	} 

	else if(bsBreakOpen){
		if(sRamDArry[mSysStatus] >= sBreakOpen)         
		sRamDArry[mSysStatus] = sBreakOpen;       				
	} 
  
	else if(bsSusErr){
		if(sRamDArry[mSysStatus] >= sSusErr)      
		sRamDArry[mSysStatus] = sSusErr;       				
	}
   
	else if(bsSdsErr){
		if(sRamDArry[mSysStatus] >= sSdsErr)      
		sRamDArry[mSysStatus] = sSdsErr;       				
	}   


	else if(bsLuOrLdErr && (LuLdErrNm > 0)){
		if(sRamDArry[mSysStatus] >= (sLuOrLdErr0 + LuLdErrNm-1))   
		sRamDArry[mSysStatus]=(sLuOrLdErr0 + LuLdErrNm-1);        
	}   

	else if(bsEarthquake){
		if(sRamDArry[mSysStatus] >= sEarthquake)   
		sRamDArry[mSysStatus]=sEarthquake;        
	}   


	else if(bDZ_Err){
		if(sRamDArry[mSysStatus] >= sDZErr)   
		sRamDArry[mSysStatus]=sDZErr;        
	}   

	else if(bInvComErr){
		if(sRamDArry[mSysStatus] > sInvCommErr)   
		sRamDArry[mSysStatus] = sInvCommErr;               
	}

    SegError=sRamDArry[mSysStatus];
}


