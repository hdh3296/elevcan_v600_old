



#include <p30fxxxx.h>
#include  "30f6010_io.h"            
#include  "host_io.h"            
#include  "iodef.h"
#include  "door.h"
//#include  "eeprom.h"
#include  "com.h"
#include  "counter.h"
#include    "you_can2.h" 
#include	"Host_NewProtocol.h" 



#ifndef	AUTO_LANDING_485	


#ifndef		RS485_FOR_CRT	


UserDataType  __attribute__((section(".usercode"))) OnceSaveErrorSet(UserDataType set)
{

   LocalType  temp,temp1,temp3;
   
   temp=ErrBdNamePt/8;
   temp1=ErrBdNamePt%8;      
   
	temp3=0x01;
	temp1=(temp3 << temp1);

   
   if(set==2){
      if(Olderrbd[temp] & temp1) return(1);         
      else                       return(0);         
   }
   else if(set==1){
      Olderrbd[temp]=(UserDataType)(Olderrbd[temp] | temp1);         
   }
   else{
      Olderrbd[temp]=(UserDataType)(Olderrbd[temp] & ~temp1);          
   }

   return(2);     
}




void  __attribute__((section(".usercode"))) ErrorSet(void)
{
   LocalType  temp,temp1,temp2,temp3;
   

   temp=ErrBdNamePt;
   ErrBdNamePt=BDid[CurRcvAdr];
   OnceSaveErrorSet(0);
   ErrBdNamePt=temp;
      
   for(temp2=BefRcvAdr;temp2+1 < CurRcvAdr;temp2++){
      	temp=temp2/8;
      	temp1=temp2%8;      

		temp3=0x01;
		temp1=(temp3 << temp1);
		
      	errbd[temp]=errbd[temp] | temp1;         
   }         
}



void  __attribute__((section(".usercode"))) ErrorBoardSet(void)  
{
   LocalType   vtemp,vtemp1,vtemp2,vtemp3,vtemp4;
   
      if(errtime>ERR_DSP_TIME){
            ErrBdNamePt=0;
            errtime=0;

            vtemp4=errpt;
            do{
               errpt=(errpt+1)% ABS_ADDRESS;
               vtemp=errpt/8;
               vtemp1=errpt%8;
               vtemp3=errbd[vtemp];         
               vtemp2=0x01;
               vtemp2=vtemp2<<vtemp1;          
            }while(!(vtemp2 & vtemp3) && (vtemp4 != errpt) );
      
            if(vtemp2 & vtemp3){
               errbd[vtemp]=errbd[vtemp] & (~vtemp2);         
               vtemp=errpt+1;  
               ErrBdNamePt=BDid[vtemp];
               BdErrCntSeq[ErrBdNamePt]++; 
            }            
      }            
}




void    __attribute__((section(".usercode"))) Com0COMM(UserDataType Absadr,UserDataType Logadr,UserDataType cmd)
{
   RxBuffer[0]=(UserDataType)ENQ;
   
   src=cF_COMPANY;
   HextoASCIIByte();
   RxBuffer[1]=firstdata;            
   RxBuffer[2]=seconddata;            

   src=Logadr;
   HextoASCIIByte();
   RxBuffer[3]=firstdata;   
   RxBuffer[4]=seconddata;   

   src=Absadr;
   HextoASCIIByte();
   RxBuffer[5]=firstdata;   
   RxBuffer[6]=seconddata;               
   
   src=cmd;
   HextoASCIIByte();
   RxBuffer[7]=firstdata;            
   RxBuffer[8]=seconddata;               
}



void    __attribute__((section(".usercode"))) MyDataTx(void)
{         
	LocalType  i,k;

    
	Com0COMM(MAS_A,LOG_ADR,NORMAL);

    RxBuffer[0] = ACK;

	src=0;
	HextoASCIIByte();
	RxBuffer[9]=firstdata;            
	RxBuffer[10]=seconddata;            

	src=0;
	HextoASCIIByte();
	RxBuffer[11]=firstdata;   
	RxBuffer[12]=seconddata;               
   
	src=0;
	HextoASCIIByte();
	RxBuffer[13]=firstdata;            
	RxBuffer[14]=seconddata;            

	k=17;   
   
	for(i=S0_FLOOR; i < mcurfloor ; i++ ){
		src=sRamDArry[i];
		HextoASCIIByte();
		RxBuffer[ k + 0]=firstdata;   
		RxBuffer[ k + 1]=seconddata;
		k=k+2;   
	}

	src= (k-17)/2;
	HextoASCIIByte();   
	RxBuffer[15]=firstdata;
	RxBuffer[16]=seconddata;

	RxBuffer[k+0]=(UserDataType)ETX;
	RxBuffer[k+1]=0;
      

	TXEN=0;  
	Serial();
}


void    __attribute__((section(".usercode"))) Find_Absolute(UserDataType Absadr,UserDataType Logadr,UserDataType cmd)
{                    
	LocalType i,j,k;      

	Com0COMM(Absadr,Logadr,cmd);  
   
    RxBuffer[0]=(UserDataType)ENQ;

	src=LadderData[C_CMDTYPE];
	HextoASCIIByte();
	RxBuffer[9]=firstdata;            
	RxBuffer[10]=seconddata;            

	src=LadderData[C_BASE_MEMORY];
	HextoASCIIByte();
	RxBuffer[11]=firstdata;   
	RxBuffer[12]=seconddata;               
   
	src=LadderData[C_OFFSET_MEMORY];
	HextoASCIIByte();
	RxBuffer[13]=firstdata;            
	RxBuffer[14]=seconddata;            

////////new
    LadderData[C_DATA_CNT]=7;
    src=(11 + LadderData[C_DATA_CNT]);
    HextoASCIIByte();   
    RxBuffer[15]=firstdata;
    RxBuffer[16]=seconddata;
    
    j=17;
    k=0;
    for(i=0;i<(LadderData[C_DATA_CNT] + 10);i++){
        if((New485Ladder[k+0] >= ' ') &&  (New485Ladder[k+0] < '0'))    (New485Ladder[k+0] = New485Ladder[k+0] + 0x80);    
        if((New485Ladder[k+1] >= ' ') &&  (New485Ladder[k+1] < '0'))    (New485Ladder[k+1] = New485Ladder[k+1] + 0x80);    
        RxBuffer[j+0]=New485Ladder[k+0];
        RxBuffer[j+1]=New485Ladder[k+1];
        k=k+2;
        j=j+2;
    }        
	RxBuffer[j+0]=(UserDataType)ETX;
	RxBuffer[j+1]=0;      
	TXEN=0;
	Serial();
}




void  __attribute__((section(".usercode"))) Ram0DataRdWr(void)
{
   LocalType i,j,k;
   
   if((LadderBuf[C_CMD] == READ_DATA) || (LadderBuf[C_CMD] == BIT_READ_DATA)){
      for(i=0;i < LadderBuf[C_DATA_CNT];i++){   
         LadderBuf[C_SAVE_DATA + i] = sRamDArry[LadderBuf[C_OFFSET_MEMORY]+i];                        
      }        
      LadderBuf[C_CMDTYPE]= LadderBuf[C_CMDTYPE] + RET_GOOD;
   }

   else if(LadderBuf[C_CMD] == WRITE_DATA){
      for(j=0;j < LadderBuf[C_DATA_CNT];j++){   
         sRamDArry[LadderBuf[C_OFFSET_MEMORY]+j] = LadderBuf[C_SAVE_DATA+j];
      }              
      LadderBuf[C_CMDTYPE] = LadderBuf[C_CMDTYPE] + RET_GOOD;      
   }  
   else if(LadderBuf[C_CMD] == BIT_WRITE_DATA){
      i=0;
      for(j=1;j < LadderBuf[C_DATA_CNT];j++){
         k=LadderBuf[C_SAVE_DATA+j];
         if(k){   
            sRamDArry[LadderBuf[C_BASE_MEMORY]+i] = (sRamDArry[LadderBuf[C_BASE_MEMORY]+i] | k);
         }           
         else{             
            sRamDArry[LadderBuf[C_BASE_MEMORY]+i] = (sRamDArry[LadderBuf[C_BASE_MEMORY]+i] & ~LadderBuf[C_OFFSET_MEMORY]);
         }           
         i=i+LadderBuf[C_SAVE_DATA];
      }        
      LadderBuf[C_CMDTYPE] = LadderBuf[C_CMDTYPE] + RET_GOOD;
   }  
   
   if(LadderBuf[C_OFFSET_MEMORY] == FLR_ON_OFF0){
 		ExtCmdFlrONOFFCnt=0;
		AccTimer=0;
	}
}



void  __attribute__((section(".usercode"))) VipCarKeyClr(void)
{
#ifdef	FLOOR_64
  if(S3_VIP1){
    if((sRamDArry[mEqualFloor] & UPDN_READY)){
		if( (sRamDArry[mEqualFloor] & ONLY_FLR) != 0)	sRamDArry[mEqualFloor]=0;
	}
    if((sRamDArry[mHighFloor] & UPDN_READY)){
  		sRamDArry[mHighFloor]=0;
	}
    if((sRamDArry[mLowFloor] & UPDN_READY)){
		if( (sRamDArry[mLowFloor] & ONLY_FLR) != 0)	sRamDArry[mLowFloor]=0;
	}


/*
    sRamDArry[mEqualFloor]=(sRamDArry[mEqualFloor] & ~UPDN_READY);
    sRamDArry[mHighFloor] =(sRamDArry[mHighFloor] & ~UPDN_READY);
    sRamDArry[mLowFloor]  =(sRamDArry[mLowFloor] & ~UPDN_READY);
     
    if(!(sRamDArry[mEqualFloor] & CAR_READY))  sRamDArry[mEqualFloor]=0;
    if(!(sRamDArry[mHighFloor] & CAR_READY))  sRamDArry[mHighFloor]=0;	
    if(!(sRamDArry[mLowFloor] & CAR_READY))   sRamDArry[mLowFloor]=0;
*/

  }
#else	
  if(S3_VIP1){
    sRamDArry[mEqualFloor]=(sRamDArry[mEqualFloor] & ~UPDN_READY);
    sRamDArry[mHighFloor] =(sRamDArry[mHighFloor] & ~UPDN_READY);
    sRamDArry[mLowFloor]  =(sRamDArry[mLowFloor] & ~UPDN_READY);
     
    if(!(sRamDArry[mEqualFloor] & CAR_READY))  sRamDArry[mEqualFloor]=0;
    if(!(sRamDArry[mHighFloor] & CAR_READY))  sRamDArry[mHighFloor]=0;	
    if(!(sRamDArry[mLowFloor] & CAR_READY))   sRamDArry[mLowFloor]=0;
  }
#endif
}



void  __attribute__((section(".usercode"))) SaveReceiveData(void)
{	
	LadderBuf[C_CMD]=RcvBuf[RCV_CMD];               
   	LadderBuf[C_CMDTYPE]=RcvBuf[RCV_CMDTYPE];             
	LadderBuf[C_BASE_MEMORY]=RcvBuf[RCV_BASE_ADR];              
	LadderBuf[C_OFFSET_MEMORY]=RcvBuf[RCV_OFFS_ADR];          
	LadderBuf[C_DATA_CNT]=RcvBuf[RCV_DATA_CNT];
                        
	LadderBuf[C_SAVE_DATA+0]=RcvBuf[RCV_DATA+0];             
	LadderBuf[C_SAVE_DATA+1]=RcvBuf[RCV_DATA+1];             
	LadderBuf[C_SAVE_DATA+2]=RcvBuf[RCV_DATA+2];             
	LadderBuf[C_SAVE_DATA+3]=RcvBuf[RCV_DATA+3];             
	LadderBuf[C_SAVE_DATA+4]=RcvBuf[RCV_DATA+4];                               



	if(LadderBuf[C_CMDTYPE] == RW_SRAM0_AREA)           Ram0DataRdWr();         
	else if(LadderBuf[C_CMDTYPE] == NEW_FLASH_RD_WR)    NewFlashData();  
          
    

	if((RcvBuf[RCV_ABSADR] == A_LD) || (RcvBuf[RCV_ABSADR] == A_PC)){
        if(RcvBuf[RCV_GROUP] == '0'){
            bAllMenu=1;
        }        

		if(RcvBuf[RCV_GROUP] == cF_COMPANY)	bLoaderActive=1;
		
		FhmLoaderTime=0;   	

		LadderData[C_CMD]=LadderBuf[C_CMD];             
		LadderData[C_CMDTYPE]=LadderBuf[C_CMDTYPE];              
		LadderData[C_BASE_MEMORY]=LadderBuf[C_BASE_MEMORY];               
		LadderData[C_OFFSET_MEMORY]=LadderBuf[C_OFFSET_MEMORY];              

		LadderData[C_DATA_CNT]=LadderBuf[C_DATA_CNT];
                        
		LadderData[C_SAVE_DATA+0]=LadderBuf[C_SAVE_DATA+0];               
		LadderData[C_SAVE_DATA+1]=LadderBuf[C_SAVE_DATA+1];               
		LadderData[C_SAVE_DATA+2]=LadderBuf[C_SAVE_DATA+2];               
		LadderData[C_SAVE_DATA+3]=LadderBuf[C_SAVE_DATA+3];               
		LadderData[C_SAVE_DATA+4]=LadderBuf[C_SAVE_DATA+4];                                    
	}

     VipCarKeyClr();
}



void  __attribute__((section(".usercode"))) HibHpiReqCheck(void)
{
  LocalType tmp;     

	if(ClrCnt > 20){
	
	  if(RxStatus==RX_GOOD){      
	
	    if((RcvBuf[RCV_CMD] == ADR_SET_REC) && (RcvBuf[RCV_LOGADR] == LogAddress+1) && (RcvBuf[RCV_ABSADR] == AbsAddress) ){                     
	
		  LadderData[C_CMDTYPE]=RcvBuf[RCV_CMDTYPE];
	
	      if(LogAddress < 99){
	        for(tmp=0; tmp <= LogAddress;tmp++){
	          if(RcvBuf[RCV_ABSADR] == BDid[tmp]){ 
	            if(BdErrCntSeq[BDid[tmp]] > 5){                                                     
	              Find_Absolute(RcvBuf[RCV_ABSADR],tmp,ADR_SET_ACK);
	            }                     
	            tmp=250;                     
	          }                 
	        }
	
	        if(tmp<250){
	          LogAddress++;
	          Find_Absolute(RcvBuf[RCV_ABSADR],LogAddress,ADR_SET_ACK);
	          BDid[LogAddress]=RcvBuf[RCV_ABSADR];
	
	      	  if((RcvBuf[RCV_ABSADR] == A_CAR1) || (RcvBuf[RCV_ABSADR] == A_CAR1) || (RcvBuf[RCV_ABSADR] == A_CAR3) || (RcvBuf[RCV_ABSADR] == A_CAR4) ){
	              bCarService=1;                            
	          }
	        }               
	      }            
	    }
	    else{      
	      if((RcvBuf[RCV_CMD] == NORMAL) || (RcvBuf[RCV_CMD] == NO_DATA)){
	        BdErrCntSeq[RcvBuf[RCV_ABSADR]]=0;                 
	      }                 
	      else if( (RcvBuf[RCV_CMD] == WRITE_DATA) || (RcvBuf[RCV_CMD] == READ_DATA) || (RcvBuf[RCV_CMD] == LONG_READ_DATA) ||
	               (RcvBuf[RCV_CMD] == BIT_WRITE_DATA) ||  (RcvBuf[RCV_CMD] == BIT_READ_DATA)){           
	          if((RcvBuf[RCV_GROUP] == cF_COMPANY) || (RcvBuf[RCV_GROUP] == '0')){
	            SaveReceiveData();
	          }              
	          BdErrCntSeq[RcvBuf[RCV_ABSADR]]=0;
	      }            
	         
	      CurRcvAdr=RcvBuf[RCV_LOGADR];         
	      ErrorSet();
	      BefRcvAdr=CurRcvAdr;
	      TimeOutBd=CurRcvAdr;         
	      RxStatus=STX_CHK;                        	
	    }
	    
	    SerialLoopMaxTime=0;      
	    if(RxStatus == RX_GOOD)  RxStatus = STX_CHK;	
	  }         
	                           
	  if(TimeOutBd > LogAddressLoop){
	    if(!bFindBoard){          
	      LogAddressLoop=LogAddressLoop+1;
	      CurRcvAdr=LogAddressLoop;
	      ErrorSet();
	      AbsAddress++;
	      if(AbsAddress>ABS_ADDRESS) AbsAddress=1;         
	      Find_Absolute(AbsAddress,LogAddress+1,ADR_SET_SEND);
	      bFindBoard=1;         
	      ExtCmdFlrONOFFCnt++;
	    }
	    else{      	
	      BefRcvAdr=0;
	      CurRcvAdr=0;
	      TimeOutBd=0;
	      MyDataTx();
	      LogAddressLoop=LogAddress;                  
	      bFindBoard=0;                  
	      disp_clk_regs();
	    }                  
	  }  
	           
	  ErrorBoardSet();
	}
	else{
	  if(RxStatus == STX_CHK){
	   		Find_Absolute(MAS_A,LOG_ADR,LOGADR_CLR);  
	 		ClrCnt++;
	  }	
	}	              
  return;
}


UserDataType  __attribute__((section(".usercode"))) waitchk(void)
{
	if(SerialTime < 4)	return(0);
	else{
		TXEN=1;  		
		return(1);
	}
}

UserDataType  __attribute__((section(".usercode"))) Init485_Ladder(void)
{
	unsigned int i;

    RxStatus = STX_CHK;
	
   	for(NoCloseCnt=0;NoCloseCnt<30;NoCloseCnt++){	      
   		Find_Absolute(MAS_A,LOG_ADR,LOGADR_CLR);   

//   		while((RxStatus != STX_CHK)){


		SerialTime = 0;
		
		do{
		 	i=waitchk();
            asm("CLRWDT");
		}while(i==0);
		

//		TXEN=1;  		
		RxCurCnt=0;
      	RxStatus = STX_CHK;

		for(firstdata=0;firstdata<600;firstdata++);

        asm("CLRWDT");

		ClrCnt=30;
   	}
	return(0);
}


#endif
#endif






