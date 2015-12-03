


//#define		FLOOR_32_USE	1						

//#define		CARLIFT		1

unsigned    char  MyTmpAddress=0;



#include    <pic18.h>
//#include    <pic18fxx8.h>

#include        "..\..\system_com\memory_map.h"
#include        "..\comm_4480\iodef.h"
#include        "..\comm_4480\fontout.h"
#include        "..\comm_4480\setup.h"
#include        "..\comm_4480\esdots.h"


/////////////////////////////////
#ifndef  __TYPE_CAR
     #error  "\nType Not Define Error(iodef.h)"
     #error  "\nType Not Define Error(iodef.h)"
     #error  "\nType Not Define Error(iodef.h)"
     #error  "\nType Not Define Error(iodef.h)"
     #error  "\nType Not Define Error(iodef.h)"
#endif

/////////////////////////////////

extern  unsigned char  Lamp(unsigned char id);   //5
//extern  void    ButtonLampClrChk(void);
extern  void    ShiftData(void);
//extern  void    UpDownBlink(unsigned char id);
extern  void    CompanyChk(unsigned char id);  //new








extern  int     KeyLoad(unsigned char id);





unsigned    char  DisableFlr[4]={0,0,0,0};            
unsigned    char  BefDisableFlr[4]={0,0,0,0};            
unsigned    char  DoorKey=0;            
unsigned    char  CarKey[4]={0,0,0,0};            
unsigned    char  ToggleKey[4]={0,0,0,0};
unsigned    char  newscan[4] ={0,0,0,0};
unsigned    char  oldscan[4] ={0,0,0,0};
unsigned    char  scantime[4]={0,0,0,0};
unsigned    char  ClrKey[4]={0,0,0,0};

unsigned    char  YourDoor;
unsigned    char  YourDoor0;
unsigned    char  YourDoor1;
unsigned    char  YourDoor2;
unsigned    char  YourDoor3;

unsigned    char  YourKey[4]={0,0,0,0};
unsigned    char  YourKey0[4]={0,0,0,0};
unsigned    char  YourKey1[4]={0,0,0,0};
unsigned    char  YourKey2[4]={0,0,0,0};
unsigned    char  YourKey3[4]={0,0,0,0};

unsigned    char  OtherDoorKey[5];



unsigned    char  TopFloor;
unsigned    char  CurFloor;          /*current floor */
unsigned    char  BellTime;          /* bell time */
unsigned    char  OffsetAdr;          /* bell time */
unsigned    char  MyAddress;        
unsigned    char  Arrowshift;    
unsigned    char  htpt;
unsigned    char  BefCurFloor;
unsigned    char  shift;
unsigned    char  shiftTime;
unsigned    char  MainTimer;   
unsigned    char  msec100;
unsigned    char  UpButtonTime;
unsigned    char  DnButtonTime;
unsigned    char  EqualFlr;
unsigned    char  HighFlr;
unsigned    char  LowFlr;
unsigned    char  MostlongFlr;

                    
unsigned    char    Door;
unsigned    char    sfttime;
unsigned    char    ButCnt;
unsigned    char    RstTimer;
unsigned    char    KeyClrTime;
unsigned    char    DisableOnOff;
unsigned    char    DoorSel;
unsigned    char    YourLiveTimer;


unsigned    char  MoveTime[MAX_ELEV];
unsigned    char  BlinkTime;

////////////unsigned    char  TwoDoorDrive;
unsigned    char  CallMeAdr;
//unsigned    char  DoorOpCl;

unsigned    char  virtualTimer;

unsigned    char  CarKeyCancle;

//unsigned    char  ClearCnt;
//unsigned    char  BefHighFlr,BefLowFlr;


unsigned    char  MyBaseFlr=0;




bit   HostCallMe;

bit   BlinkOn;
bit   Up_Key_Valid;
bit   Dn_Key_Valid;
bit   Open;
bit   Close;


bit   Bell;
bit   BellSet;
bit   UpMove;
bit   DnMove;
bit   Toggle;
bit   CarMove;
bit   Fire;
bit   KeyClr;
bit   OpenLampSet;
bit   KeyClrExt;
bit   Auto;
bit   Parking;
bit   Vip;
bit   BefVip;
bit   BefFire;
bit   FloorChange;
bit   ManualToggle;
bit   FDsp;
bit   ShiftOn;
//bit   OpenSet;
bit   OnceMoveCar;
/////////////
bit   UpKeyBit;   
bit   DnKeyBit;   
bit   Emg;   
bit   CurKey;
bit   StopBit;
bit   Full;
bit   OverLoad;
bit   Car_Key_Valid;
//bit   SetupBit;         
bit   EqualKeyOn;         
bit   bIamXSubDoor=0;                    
bit   bRealOpenkey=0;
bit   bDoorOpenWaitOn=0;

bit   bBefDoorOpen=0;
bit   bBefK=0;


bit   bOneskeySet=0;
bit   bDoorOpenMain=0;
bit   bDoorOpenSub=0;

bit   bOtherCarClear=0;


#ifdef	CPU65K80
bit		LIVE_LAMP=0;
bit		WR_CLK=0;
bit		DSP_OFF=0;
unsigned char P1=0;
unsigned char P2=0;
#endif




unsigned int  CarOneButtonSetCheck(void)
{
	#ifdef	 CARLIFT
		if( (newscan[0] == CarKey[0]) && (newscan[1] == CarKey[1]) && (newscan[2] == CarKey[2]) && (newscan[3] == CarKey[3])){
			return(0);
		}
		else if( (HighFlr > 0) || (LowFlr > 0))	return(1);
		else	return(0);
	#else
		return(0);
	#endif
}



unsigned int  ButtonCloseSet(void)
{ 
	if( Fire && bNew_Law){
		if( (newscan[0] == CarKey[0]) && (newscan[1] == CarKey[1]) && (newscan[2] == CarKey[2]) && (newscan[3] == CarKey[3])){
			if( newscan[0] || newscan[1]  || newscan[2] || newscan[3]){
   				DnKeyBit=1;
				DnButtonTime=10;
			}
		}
	}
	return(1);
}


unsigned int  OtherKeyClear(void)
{ 

	if( Fire && bNew_Law){
		CarKey[0] 		= 0;
		ToggleKey[0]  	= 0xff;
		CarKey[1] 		= 0;
		ToggleKey[1]  	= 0xff;
		CarKey[2] 		= 0;
		ToggleKey[2]  	= 0xff;
		CarKey[3] 		= 0;
		ToggleKey[3]  	= 0xff;
		return(1);
	}

	return(0);
}





unsigned char  MyLampdoubleClear(void)
{
	unsigned char i,j;

	j=0;
	if( Fire && bNew_Law){
		for(i=0;i<4;i++){
			if(CarKey[i]){
				j=1;	
			}
		}
	}

	if(j==1){
		for(i=0;i<4;i++){
			YourKey[i]=0;
			YourKey0[i]=0;	
			YourKey1[i]=0;	
			YourKey2[i]=0;	
			YourKey3[i]=0;	
		}
	}

	return(0);
}


unsigned int  OtherCarButtonOn(void)
{ 
	if( Fire && bNew_Law){
		if((EqualDataBuf[7] &  OTHER_CAR_CLEAR)){
			OtherKeyClear();
		}   
	}
	return(1);
}


unsigned int  MyCarButtonBefOnChk(void)
{ 
	if( Fire && bNew_Law){
		if(CarKey[0] || CarKey[1] || CarKey[2] || CarKey[3]){
			if( (newscan[0]==0) && (newscan[1]==0)  && (newscan[2]==0) && (newscan[3]==0)){
				if(Open){
					OtherKeyClear();
				}
			}
		} 
	}
	return(0);
}



unsigned char VirCarKeySet(unsigned char virkey)
{

	unsigned char i,j,bitkey,tmpflr;

	tmpflr=(virkey-1);

	if( (CurFloor != virkey) && (tmpflr <= TopFloor)){ 
		i=(tmpflr/8);
		j=(tmpflr%8);
		bitkey=0x01;
		bitkey=(bitkey << j);
		CarKey[i]=(CarKey[i] | bitkey);
	}  
	return(0);

}	


unsigned char SyncButtonCheck(unsigned char src)
{
	unsigned char i;

   	if(RxEidBuffer & HOST_BOARD){
		if(SrcAddress  == LocalNumber)	return(1);
		else							return(0);							
	}
	else{
		if(SrcAddress  == LocalNumber){
	        i=(unsigned char)RxEidBuffer;
			if( (i == 0x80) || (i == 0x81) || (i == 0x82)|| (i == 0x83)){
				#ifdef	FLOOR_64
					if(MyBaseFlr >= 32){	
						if( (EqualDataBuf[7] & IAM_FLR32))	return(1);
						else								return(0);
					}
					else{	
						if( !(EqualDataBuf[7] & IAM_FLR32))	return(1);
						else								return(0);
					}
				#else
					return(1);
				#endif
			}
			else	return(0);
		}
		else	return(0);
	}

}



unsigned char  SubDoorMainDoorCheck(void)
{
    unsigned char ret=1;


	#ifdef	FLOOR_64
		if(MyBaseFlr >= 32){	
			if( !(EqualDataBuf[7] & IAM_FLR32))	return(1);
		}
		else{	
			if( (EqualDataBuf[7] & IAM_FLR32))	return(1);
		}
	#endif


    if( bIamXSubDoor  &&  (EqualDataBuf[7] & SUB_DOOR_BIT))    ret=0;
    if( !bIamXSubDoor && !(EqualDataBuf[7] & SUB_DOOR_BIT))    ret=0;


    return(ret);
}


void    MyLampCheck(void)
{

    unsigned int i,j;
    i=0;
    j=0;
    
    if((SelHostAdr == ReceiveAdr) && (MyTmpAddress==0)){
        i=(unsigned char)RxEidBuffer;
        if(!SubDoorMainDoorCheck()){            
            switch(i){
                case    0x80:
                    YourDoor0=EqualDataBuf[2];
                    YourKey0[0]=EqualDataBuf[3];
                    YourKey0[1]=EqualDataBuf[4];
                    YourKey0[2]=EqualDataBuf[5];
                    YourKey0[3]=EqualDataBuf[6];
                    j=1;
                    break;
                case    0x81:
                    YourDoor1=EqualDataBuf[2];
                    YourKey1[0]=EqualDataBuf[3];
                    YourKey1[1]=EqualDataBuf[4];
                    YourKey1[2]=EqualDataBuf[5];
                    YourKey1[3]=EqualDataBuf[6];
                    j=1;
                    break;
                case    0x82:
                    YourDoor2=EqualDataBuf[2];
                    YourKey2[0]=EqualDataBuf[3];
                    YourKey2[1]=EqualDataBuf[4];
                    YourKey2[2]=EqualDataBuf[5];
                    YourKey2[3]=EqualDataBuf[6];
                    j=1;
                    break;
                case    0x83:
                    YourDoor3=EqualDataBuf[2];
                    YourKey3[0]=EqualDataBuf[3];
                    YourKey3[1]=EqualDataBuf[4];
                    YourKey3[2]=EqualDataBuf[5];
                    YourKey3[3]=EqualDataBuf[6];
                    j=1;
                    break;
            }
        
            if(j==1){    
                YourDoor  =YourDoor0   | YourDoor1   | YourDoor2   | YourDoor3;
                YourKey[0]=YourKey0[0] | YourKey1[0] | YourKey2[0] | YourKey3[0];
                YourKey[1]=YourKey0[1] | YourKey1[1] | YourKey2[1] | YourKey3[1];
                YourKey[2]=YourKey0[2] | YourKey1[2] | YourKey2[2] | YourKey3[2];
                YourKey[3]=YourKey0[3] | YourKey1[3] | YourKey2[3] | YourKey3[3];                
            }
        }
		else{
            switch(i){
                case    0x80:
					OtherDoorKey[1]=EqualDataBuf[2];
                    j=1;
                    break;
                case    0x81:
					OtherDoorKey[2]=EqualDataBuf[2];
                    j=1;
                    break;
                case    0x82:
					OtherDoorKey[3]=EqualDataBuf[2];
                    j=1;
                    break;
                case    0x83:
					OtherDoorKey[4]=EqualDataBuf[2];
                    j=1;
                    break;
            }
        
            if(j==1){    
                OtherDoorKey[0]  = (OtherDoorKey[1]   | OtherDoorKey[2]   | OtherDoorKey[3]   | OtherDoorKey[4]);
            }
		}
		
		OtherCarButtonOn();	
    }
}            







unsigned char SetHighFloor(unsigned char i)
{

    unsigned char j,k,l=0;
   

    k=HighFlr;


#ifdef		FLOOR_64
    if((!UpMove && !DnMove) || UpMove){
        j=(HighFlr & ONLY_FLR);
   
        if(j == 0)        HighFlr = i;
        else if(j > i)    HighFlr = i;
        else if(j < i){
            if((HighFlr & UPDN_READY)== DN_READY)   HighFlr = i;            
            else{
                ButCnt++;
                l=1;   
            }            
        }
    }
#else
    if((!UpMove && !DnMove) || UpMove){
        j=(HighFlr & ONLY_FLR);
   
        if(j == 0)        HighFlr = (i |  CAR_READY);
        else if(j > i)    HighFlr = (i |  CAR_READY);
        else if(j < i){
            if((HighFlr & UPDN_CAR_READY)== DN_READY)   HighFlr = (i |  CAR_READY);            
            else if(!(HighFlr & UPDN_CAR_READY))   HighFlr = (i |  CAR_READY);   
            else{
                ButCnt++;
                l=1;   
            }            
        }
        else if(j == i) HighFlr = (HighFlr |  CAR_READY);
    }
#endif   

    if(l==1)                        return(1);
    if(k != HighFlr)                return(0);
    else                            return(1);

}



unsigned char SetLowFloor(unsigned char i)
{

	unsigned char j,k,l=0;

	unsigned char tmp_Max_Low=0;
	    
	
	tmp_Max_Low=i;
	if(i == 0)	tmp_Max_Low=(i | UP_READY);


	k=LowFlr;

#ifdef		FLOOR_64
		       	
	if((!UpMove && !DnMove) || DnMove){
		j=(LowFlr & ONLY_FLR);      
		if(j == 0)										LowFlr = tmp_Max_Low;
		else if(j < i)  								LowFlr = tmp_Max_Low;
		else if(j > i){
            if((LowFlr & UPDN_READY) == UP_READY)   	LowFlr = tmp_Max_Low;            
            else{
                ButCnt++;
                l=1;   
            }            
		}        
	}
#else
       if((!UpMove && !DnMove) || DnMove){
          j=(LowFlr & ONLY_FLR);      
          if(j == 0)  LowFlr = (i |  CAR_READY);      
          else if(j < i)  LowFlr = (i |  CAR_READY);
          else if(j > i){
             if((LowFlr & UPDN_CAR_READY) == UP_READY)   LowFlr = (i |  CAR_READY);   
             else if(!(LowFlr & UPDN_CAR_READY))   LowFlr = (i |  CAR_READY);   
             else{
                ButCnt++;   
                l=1;
             }            
          }        
          else if(j == i) LowFlr = (LowFlr |  CAR_READY);
       }
#endif
    
       if(l==1)          return(1);
       if(k != LowFlr)   return(0);
       else              return(1);

}







unsigned char  CarKeyLoad(unsigned char id)
{

    unsigned char  i,j,k,ret,Curf; 

    ret=1;
    k=0x01; 
    j=0;
    Curf=(CurFloor-1);
       
    ButCnt=0;
    EqualKeyOn=0;

	MaxHighButton=0;
	MaxLowButton=0xff;


    for(i=(0+MyBaseFlr);i<(32+MyBaseFlr);i++){
        if(CarKey[j] & k){            
            if(i>Curf){
                if(!SetHighFloor(i)) ret=0;

				if(UpMove){
					MaxHighButton=i;
				}
            }
            else if(i<Curf){
                if(!SetLowFloor(i))  ret=0;

				if(DnMove){
					if(i<MaxLowButton)	MaxLowButton=i;
				}
            }
            else{                
			#ifdef		FLOOR_64
				EqualFlr=i;
				if(EqualFlr == 0)	EqualFlr=(EqualFlr | UP_READY);
			#else
                if(EqualFlr)    EqualFlr=(EqualFlr | CAR_READY);            
                else            EqualFlr=(i | CAR_READY);
			#endif

                EqualKeyOn=1;
                ret=0;
            }
        }     
        
        k=(k<<1);
        
        if(k==0){
            k=0x01;
            j++;
        }  
    }  
    

#ifdef		FLOOR_64

#else
    if((ButCnt>0) && !(Door & CAR_READY)){        
        Door=(Door | CAR_READY);
        ret=0;
    }
#endif



    DoorSel = 0;

    if(((bRealOpenkey) || CLOSE_LAMP) &&  !CarMove){
       if(bIamXSubDoor){
       		if(bRealOpenkey){
     			DoorSel = (DoorSel | 0x04);
				if(bDoorOpenWaitOn)	DoorSel = (DoorSel | 0x10);	
			}
          	else if(CLOSE_LAMP)  DoorSel = (DoorSel | 0x08);
       }         
       else{
          	if(bRealOpenkey){
  				DoorSel=DoorSel | 0x01;
				if(bDoorOpenWaitOn)	DoorSel = (DoorSel | 0x10);	
			}
          	if(CLOSE_LAMP) 	DoorSel=DoorSel | 0x02;
       }     
       ret=0;      
    }


#ifdef		FLOOR_64
	MaxButton=0xff;
	if( (MaxHighButton > 0)){
		if(MaxHighButton > MaxLongFlr){
			if( (UpMove) && ( MaxHighButton > (HighFlr & ONLY_FLR) )){ 
				MaxButton=MaxHighButton;
			}
		}
	}
	if((MaxLowButton < 0xff)){
		if( (MaxLowButton < (MaxLongFlr & ONLY_FLR)) || (MaxLongFlr==0)){
			if( (DnMove) && (MaxLowButton < (LowFlr & ONLY_FLR) )){ 
				MaxButton=MaxLowButton;
				if(MaxButton == 0)	MaxButton=(MaxButton | UP_READY);
			}
		}
	}
#endif

   return(ret); 

}



unsigned char NoKeyClr(unsigned char srcflr)
{

    unsigned char  i,j,k,l;       
    unsigned char  ret;       


#ifdef		FLOOR_64
	ret=0;
	l=srcflr;

	l =(l & ONLY_FLR);
                  
	if(MyBaseFlr > 0){
		if(l > MyBaseFlr){
			l = (l - MyBaseFlr);			
		}
	}
	
    if(srcflr > 0){          
        i=(l / 8);                              
        j=(l % 8);
		
        k=(0x01 << j);
        if( (!(CarKey[i] & k)) && (ToggleKey[i] & k) ){
			CarKeyCancle=(srcflr & ONLY_FLR);
			ToggleKey[i] = (ToggleKey[i] & ~k);
			ret=1;
        }
    }
    return(ret);

#else
    if(srcflr & CAR_READY){          
        i=(srcflr & ONLY_FLR)/8;                              
        j=(srcflr & ONLY_FLR)%8;
        k=(0x01 << j);
        if( (!(CarKey[i] & k)) && (ToggleKey[i] & k) ){
            srcflr =  (srcflr  &  ~CAR_READY);
			ToggleKey[i] = (ToggleKey[i] & ~k);
			ret=1;
        }
    }
    return(srcflr);

#endif
       

}




#ifdef		FLOOR_64

unsigned char  NoKeyCheck(unsigned char id)
{ 
    unsigned char  i,ret;
    unsigned int    IdPt;

    ret=1;

    IdPt=(id * HOST_DATA_RECOD) + RCV_DATA;

    EqualFlr=(RcvBuf[IdPt + mEqualFloor]);
    HighFlr=(RcvBuf[IdPt + mHighFloor]);
    LowFlr=(RcvBuf[IdPt + mLowFloor]);

    MostlongFlr=MaxLongFlr;


    if(NoKeyClr(HighFlr)){
       ret=0;
    }    

    if( NoKeyClr(LowFlr)){
       ret=0;
    }

    if(NoKeyClr(MostlongFlr)){
       ret=0;
    }


    return(ret); 
}


#else

unsigned char  NoKeyCheck(unsigned char id)
{ 

    unsigned char  i,ret;
    unsigned int    IdPt;

    ret=1;

    IdPt=(id * HOST_DATA_RECOD) + RCV_DATA;

    EqualFlr=(RcvBuf[IdPt + mEqualFloor]);
    HighFlr=(RcvBuf[IdPt + mHighFloor]);
    LowFlr=(RcvBuf[IdPt + mLowFloor]);

    i=NoKeyClr(EqualFlr);
    if(i != EqualFlr){
       EqualFlr=i;
       ret=0;
    }

    i=NoKeyClr(HighFlr);
    if(i != HighFlr){
       HighFlr=i;
       ret=0;
    }    

    i=NoKeyClr(LowFlr);
    if(i != LowFlr){
       LowFlr=i;
       ret=0;
    }

    return(ret); 

}
#endif





int KeyLoad(unsigned char id)
{ 

    int i=1;
    int j=0;
    unsigned char hi,lo,eq,dr,flrlong;
    unsigned int IdPt;

    CanCmd=CAN_NO_KEY_SET;

    IdPt=(id * HOST_DATA_RECOD) + RCV_DATA;
    
    hi=RcvBuf[IdPt+mHighFloor];
    lo=RcvBuf[IdPt+mLowFloor];
    eq=RcvBuf[IdPt+mEqualFloor];
    dr=RcvBuf[IdPt+mDoor];

    flrlong=MaxLongFlr;

    EqualFlr=eq;
    HighFlr=hi;
    LowFlr=lo;
    MostlongFlr=flrlong;


#ifdef		FLOOR_64
	i=1;
    if(!NoKeyCheck(id)){
        if( ((hi & ONLY_FLR) == CarKeyCancle) && (hi > 0)){
            CanCmd=CAN_KEY_CLEAR;
            CanKeyValue[1] = CarKeyCancle;
			i=0;
        }

        else if( ((lo & ONLY_FLR) == CarKeyCancle) && (lo > 0) && (DnMove)){
            CanCmd=CAN_KEY_CLEAR;
			if(CarKeyCancle==0){
				CarKeyCancle=(CarKeyCancle | UP_READY);
			}
            CanKeyValue[1] = CarKeyCancle;            
			i=0;
        }

        else if( ((MaxLongFlr & ONLY_FLR) == CarKeyCancle) && (MaxLongFlr > 0)){
            CanCmd=CAN_KEY_CLEAR;
			if(CarKeyCancle==0){
				CarKeyCancle=(CarKeyCancle | UP_READY);
			}
            CanKeyValue[1] = CarKeyCancle;            
			i=0;
        }
    }
    else if(!CarKeyLoad(id) && (i==1)){ 
        if(DoorSel){
            CanCmd=CAN_KEY_DOOR;
   			CanKeyValue[1] = DoorSel;            
 	       	i=0;
        }
        else  if(hi != HighFlr){
            CanCmd=CAN_KEY_SET;
            CanKeyValue[1] = HighFlr;     
 	       	i=0;
        }
        else if(lo != LowFlr){
            CanCmd=CAN_KEY_SET;
			if(LowFlr==0)	LowFlr=(LowFlr | UP_READY);	
            CanKeyValue[1] = LowFlr;            
 	       	i=0;
        }
        else if((eq !=  EqualFlr) || (EqualKeyOn &&  Close && !CarMove)){
            if( bIamXSubDoor && !(dr & 0x04)){
                CanCmd=CAN_KEY_SET;
				if(EqualFlr==0)	EqualFlr=(EqualFlr | UP_READY);	
	            CanKeyValue[1] = EqualFlr;
	 	       	i=0;
            }
            else if( !bIamXSubDoor && !(dr & 0x01)){
                CanCmd=CAN_KEY_SET;
				if(EqualFlr==0)	EqualFlr=(EqualFlr | UP_READY);	
	            CanKeyValue[1] = EqualFlr;
	 	       	i=0;
            }
        }
    }
#else
	i=1;
    if(!NoKeyCheck(id)){
        if(hi != HighFlr){
            CanCmd=CAN_KEY_CLEAR;
            CanKeyValue[1] = (HighFlr & ONLY_FLR) | CAR_READY;
			i=0;
        }
        else if((lo != LowFlr)){
            CanCmd=CAN_KEY_CLEAR;
            CanKeyValue[1] = (LowFlr & ONLY_FLR) | CAR_READY;            
			i=0;
        }
        else if((eq !=  EqualFlr)){
            CanCmd=CAN_KEY_CLEAR;
            CanKeyValue[1] = (EqualFlr & ONLY_FLR) | CAR_READY;
			i=0;
        }
    }
    else if(!CarKeyLoad(id) && (i==1)){ 
        if(DoorSel){
            CanCmd=CAN_KEY_DOOR;
            CanKeyValue[1] = DoorSel;            
			i=0;
        }
        else  if(hi != HighFlr){
            CanCmd=CAN_KEY_SET;
            CanKeyValue[1] = (HighFlr & ONLY_FLR) | CAR_READY;     
			i=0;
        }
        else if(lo != LowFlr){
            CanCmd=CAN_KEY_SET;
            CanKeyValue[1] = (LowFlr & ONLY_FLR) | CAR_READY;            
			i=0;
        }
        else if((eq !=  EqualFlr) || (EqualKeyOn &&  Close && !CarMove)){
            if( bIamXSubDoor && !(dr & 0x04)){
                CanCmd=CAN_KEY_SET;
                CanKeyValue[1] = (EqualFlr & ONLY_FLR) | CAR_READY;            
				i=0;
            }
            else if( !bIamXSubDoor && !(dr & 0x01)){
                CanCmd=CAN_KEY_SET;
                CanKeyValue[1] = (EqualFlr & ONLY_FLR) | CAR_READY;            
				i=0;
            }
        }
    }

#endif


    if((!bNew_Law && Fire)){
        j=(CarKey[0] | YourKey[0] | CarKey[1] | YourKey[1] | CarKey[2] | YourKey[2] | CarKey[3] | YourKey[3] | YourDoor | DoorKey);
        if((j==0)){
			if(!bOneskeySet){
				ToggleKey[0] = 0;
				ToggleKey[1] = 0;
				ToggleKey[2] = 0;
				ToggleKey[3] = 0;
				
				CanCmd=ALL_KEY_CLEAR;
				CanKeyValue[1] = 0x0;
				i=0;           
				bOneskeySet=1;
			}
        }
		else{
			bOneskeySet=0;
		}
    }  


	if( CurKey){
    	if(bNew_Law){
	        j=(YourDoor | DoorKey);
			if(j==0){
	       		if(bIamXSubDoor){
			        if(dr & 0x0c){
						CanCmd=ALL_KEY_CLEAR;
						CanKeyValue[1] = 0x0;
						i=0;           
			        }
				}
	       		else{
			        if(dr & 0x03){
						CanCmd=ALL_KEY_CLEAR;
						CanKeyValue[1] = 0x0;
						i=0;           
			        }
				}
			}	
	    }
		else{
			for(j=0;j<4;j++){      
		        ClrKey[j]     = 0x0;  
		        ToggleKey[j]  = 0x0;
		        CarKey[j]     = oldscan[j];   
			}         
		}  
	}



	if(Vip || BefVip){
		if(Vip != BefVip){
			if(!CarMove){		
		     	for(j=0;j<4;j++){      
		        	ClrKey[j]     = 0x0;  
		        	ToggleKey[j]  = 0x0;
		        	CarKey[j]     = 0x0;   
		      	}      
				CanKeyValue[1] = 0x0;
				CanCmd=ALL_KEY_CLEAR;
				BefVip=Vip;
				i=0;           
			}
		}	   		
	}

	if(Fire || BefFire){
		if(Fire != BefFire){
	     	for(j=0;j<4;j++){      
	        	ClrKey[j]     = 0x0;  
	        	ToggleKey[j]  = 0x0;
	        	CarKey[j]     = 0x0;   
	      	}      
			CanKeyValue[1] = 0x0;
			CanCmd=ALL_KEY_CLEAR;
			BefFire=Fire;
			bOneskeySet=0;
			i=0;           
		}	   		
	}

    return(i);

}






void  MyLocalAdr(void)
{

   if(MULTI_ADR0 && MULTI_ADR1){
      SelHostAdr=0;
   }            
   else if(!MULTI_ADR0 && MULTI_ADR1){
      SelHostAdr=1;
   }            
   else if(MULTI_ADR0 && !MULTI_ADR1){
      SelHostAdr=2;
   }            
   else if(!MULTI_ADR0 && !MULTI_ADR1){
      SelHostAdr=3;
   } 
           
}



void  MyAdrRead(void)
{

   if(DIPS2 && DIPS3){
      MyAddress=0;
   }            
   else if(!DIPS2 && DIPS3){
      MyAddress=1;
   }      
   else if( DIPS2 && !DIPS3){
      MyAddress=2;
   }      
   else{
      MyAddress=3;
   }      

   MyAddress=MyAddress | 0x80;

}



void  WaitMyAdr(void)
{

   unsigned char i;
   
//   MyAdrRead();

   if(FDsp){ 
      if(MyAddress == 0x80)        i='1';
      else if(MyAddress == 0x81)   i='2';
      else if(MyAddress == 0x82)   i='3';
      else if(MyAddress == 0x83)   i='4';

      
      Floor_Char_load(0,'C',i);

      EngDisplay(11,EXT_VERSION);             
      for(i=0;i<=15;i++){
         shiftDataBuf[i]=DspBuf[i];
      }
   }
   else{
      for(i=0;i<=15;i++){
         shiftDataBuf[i]=0x0;
      }   
   }          
         
}



unsigned char  KeyClearAll(void)
{

   	unsigned char  i,j,k,tmp_flr;
   
   	i=0;
   	j=0;
   	k=0;
	   
	   
   	if(KeyClr){   
		if(MyBaseFlr == 32){
			if(CurFloor > 32){		
				tmp_flr=(CurFloor - MyBaseFlr)-1;
			}			
		}
		else{
			if(CurFloor <= 32){
				tmp_flr=(CurFloor-1);
			}
		}
		
		i=(tmp_flr/8);                              
	    j=(tmp_flr%8);	
	    k=(0x01 << j);   
	    j = (CarKey[i] & k);        
	}
   
   	for(k=0;k<4;k++){
      	if((i==k) && Auto){
        	CarKey[k] = j;
      	}        
      	else{
        	CarKey[k] = 0x0;        
      	}  
	
      	ToggleKey[k]  = 0x0;      
      	YourKey0[k]   = 0x0;
      	YourKey1[k]   = 0x0;
      	YourKey2[k]   = 0x0;
      	YourKey3[k]   = 0x0;
      	YourKey[k]    = 0x0;
   	}
	
	return(0);		   

}



void  FloorCalu(unsigned char id)
{

    unsigned int	IdPt;
    unsigned char 	i;
    
    IdPt=(id * HOST_DATA_RECOD) + RCV_DATA;



    i=0;
    if((RcvBuf[IdPt + mEqualFloor]==0) &&  (RcvBuf[IdPt + mHighFloor]==0) && (RcvBuf[IdPt + mLowFloor]==0)){
//        if(!CarMove && !UpMove && !DnMove && !OpenSet){
        if(!CarMove && !UpMove && !DnMove && !Open){
            if(YourKey[0] | YourKey[1] | YourKey[2] | YourKey[3]){
                i=1;
            }
        } 
    }

    if(i==0)    YourLiveTimer=0;

/*
////////////////////////////////////////////////////////////////
 x3, x5,x6

	if( !(RcvBuf[IdPt + SL_IN_X0] & 0x08)){
		if( !(RcvBuf[IdPt+mHighFloor] & UPDN_READY) && (RcvBuf[IdPt+mHighFloor])  && (UpMove)){
			i=(RcvBuf[IdPt+mHighFloor] & ONLY_FLR);
			j=0x01;				
			testkey =(j << i);
		}
		else if( !(RcvBuf[IdPt+mLowFloor] & UPDN_READY) && (RcvBuf[IdPt+mLowFloor]) && (DnMove)){
			i=(RcvBuf[IdPt+mLowFloor] & ONLY_FLR);
			j=0x01;				
			testkey =(j << i);
		}
		else{
			testkey=0x0;				
		}
	}
	else{
		testkey=0x0;				
	}
///////////////////////////////////////////////////////////	
*/

}




void  MasterRetKeySave(unsigned char id)
{

    unsigned int IdPt;
    unsigned char  dsbtmp[4];


    IdPt=(id * HOST_DATA_RECOD) + RCV_DATA;

#ifdef	FLOOR_64
	if(MyBaseFlr >= 32){
		dsbtmp[0]=RcvBuf[IdPt + SL_FLR_ON_OFF4];
	   	dsbtmp[1]=RcvBuf[IdPt + SL_FLR_ON_OFF5];
	   	dsbtmp[2]=RcvBuf[IdPt + SL_FLR_ON_OFF6];
	   	dsbtmp[3]=RcvBuf[IdPt + SL_FLR_ON_OFF7];
	}
	else{
		dsbtmp[0]=RcvBuf[IdPt + FLR_ON_OFF0];
	   	dsbtmp[1]=RcvBuf[IdPt + FLR_ON_OFF1];
	   	dsbtmp[2]=RcvBuf[IdPt + FLR_ON_OFF2];
	   	dsbtmp[3]=RcvBuf[IdPt + FLR_ON_OFF3];
	}
#else
	dsbtmp[0]=RcvBuf[IdPt + FLR_ON_OFF0];
   	dsbtmp[1]=RcvBuf[IdPt + FLR_ON_OFF1];
   	dsbtmp[2]=RcvBuf[IdPt + FLR_ON_OFF2];
   	dsbtmp[3]=RcvBuf[IdPt + FLR_ON_OFF3];
#endif


   if((BefDisableFlr[0] == dsbtmp[0]) &&
      (BefDisableFlr[1] == dsbtmp[1]) &&  
      (BefDisableFlr[2] == dsbtmp[2]) &&  
      (BefDisableFlr[3] == dsbtmp[3])){
         DisableOnOff++;
         if(DisableOnOff > 5){  

            DisableFlr[0]=dsbtmp[0];
            DisableFlr[1]=dsbtmp[1];
            DisableFlr[2]=dsbtmp[2];
            DisableFlr[3]=dsbtmp[3];
            DisableOnOff=0;
         }            
   }
   else{
     DisableOnOff=0;   
   }
   
   BefDisableFlr[0]=dsbtmp[0];
   BefDisableFlr[1]=dsbtmp[1];
   BefDisableFlr[2]=dsbtmp[2];
   BefDisableFlr[3]=dsbtmp[3];

}







void  io(void)
{    


   unsigned char a;
   unsigned char tmp,extkey;
   

   a=htpt%4;
   
   if(a==0){
      SEL0=0;
      SEL1=0;
      SEL2=0;
      SEL_ACT=0;

//yousangyong
    tmp=IN_DATA_PORT;
    tmp=IN_DATA_PORT;
//      tmp=IN_DATA_PORT;
//      tmp=IN_DATA_PORT;

      newscan[0]=~tmp;

      extkey=~YourKey[0];  
      newscan[0]=(newscan[0] & extkey); 

      SEL_ACT=1;      
   }

   else if(a==1){
      SEL0=1;
      SEL1=0;
      SEL2=0;
      SEL_ACT=0;
      tmp=IN_DATA_PORT;
      tmp=IN_DATA_PORT;
      newscan[1]=~tmp;
      extkey=~YourKey[1];  
      newscan[1]=(newscan[1] & extkey); 
      SEL_ACT=1;
   }

   else if(a==2){
      SEL0=0;
      SEL1=1;
      SEL2=0;
      SEL_ACT=0;
      tmp=IN_DATA_PORT;
      tmp=IN_DATA_PORT;
      newscan[2]=~tmp;
      extkey=~YourKey[2];  
      newscan[2]=(newscan[2] & extkey); 
      SEL_ACT=1;   
   }
      
   else if(a==3){
      SEL0=1;
      SEL1=1;
      SEL2=0;
      SEL_ACT=0;
      tmp=IN_DATA_PORT;
      tmp=IN_DATA_PORT;
      newscan[3]=~tmp;

      extkey=~YourKey[3];  
      newscan[3]=(newscan[3] & extkey);    
      SEL_ACT=1;
   }

}





unsigned char   CarLampNormal(unsigned char id)
{

    unsigned int IdPt;
    unsigned char 	pt,bit_pt,bit_val,tmp_flr;


    IdPt=(id * HOST_DATA_RECOD) + RCV_DATA;
    
    MasterRetKeySave(id);

    Lamp(id);
//	DoorOpCl=RcvBuf[IdPt+mDoor];
    FloorCalu(id);


	bDoorOpenSub=0;   
	bDoorOpenMain=0;   
    if((RcvBuf[IdPt+ S3_STATE] & S3_OPEN_SUB))  bDoorOpenSub=1;   
    if(RcvBuf[IdPt + S1_STATE] & S1_OPEN)		bDoorOpenMain=1;   



//////////fire ¼öÁ¤ 
    if( ((!bIamXSubDoor) && (RcvBuf[IdPt+1] & S1_OPEN)) || ((bIamXSubDoor==1) && (RcvBuf[IdPt+3] & S3_OPEN_SUB)) || Fire){

		if(MyBaseFlr == 32){
			if(CurFloor <= 32)	return(0);

			tmp_flr=(CurFloor - MyBaseFlr)-1;			
		}
		else{
			if(CurFloor > 32)	return(0);
			tmp_flr=(CurFloor-1);
		}

		pt=(tmp_flr/8);
		bit_pt =(tmp_flr%8);
		bit_val=(0x01 << bit_pt);
		bit_val=(~bit_val);
		
       	CarKey[pt]    = CarKey[pt]   & bit_val;
       	ToggleKey[pt] =ToggleKey[pt] & bit_val;
       	YourKey0[pt]  = YourKey0[pt] & bit_val;
       	YourKey1[pt]  = YourKey1[pt] & bit_val;
       	YourKey2[pt]  = YourKey2[pt] & bit_val;
       	YourKey3[pt]  = YourKey3[pt] & bit_val;


        YourKey[0]=YourKey0[0] | YourKey1[0] | YourKey2[0] | YourKey3[0];
        YourKey[1]=YourKey0[1] | YourKey1[1] | YourKey2[1] | YourKey3[1];
        YourKey[2]=YourKey0[2] | YourKey1[2] | YourKey2[2] | YourKey3[2];
        YourKey[3]=YourKey0[3] | YourKey1[3] | YourKey2[3] | YourKey3[3];
    }

	return(0);

}








void    SetKey(unsigned char    pt,unsigned char tfloor)
{
    unsigned char i,st;

	
	tfloor=(tfloor + MyBaseFlr);
      
    st=0x01;
    for(i=0;i<8;i++){      
        if((oldscan[pt] & st) && ((TopFloor+1) >= (tfloor+i))){     			
            if(!(ClrKey[pt] & st) && !CarOneButtonSetCheck()){
//            if(!(ClrKey[pt] & st)){
                ClrKey[pt]   = ClrKey[pt] | st;
				BellTime=0;               
                Car_Key_Valid=1;
                Tx0ConfirmCnt=3;

                if((CarKey[pt] & st) && (bNew_Law || (!bNew_Law && !Fire))){
                    if(Toggle){
                        CarKey[pt] = CarKey[pt] & ~st;
                        ToggleKey[pt]  = ToggleKey[pt]  |  st;
                    }               
                }
                else if(CurFloor != (tfloor+i)){
					if(OtherKeyClear())			bOtherCarClear=1;
					else						bOtherCarClear=0;

                    CarKey[pt] = CarKey[pt] | st;
                    ToggleKey[pt]  = ToggleKey[pt]  & ~st;				
                }
            }               

			if(!bNew_Law && CurKey) BellTime=0; 
        }

        else{
            ClrKey[pt]   = ClrKey[pt] & ~st;

            if(!bNew_Law && CurKey){
                CarKey[pt] = CarKey[pt] & ~st;
                ToggleKey[pt]  = ToggleKey[pt]  &  ~st;          
            }
        }            
        st=st << 1;
    }
   
}





unsigned int  SetKeyButton(void)
{ 

   	unsigned char i,j,k;


   if((newscan[0] == oldscan[0])){
      if(scantime[0]>60){
         SetKey(0,1);
         scantime[0]=0;
      }
   }
   else{
      scantime[0]=0x0;
      oldscan[0]=newscan[0];
   }

   if((newscan[1] == oldscan[1])){
      if(scantime[1]>60){
         SetKey(1,9);
         scantime[1]=0;
      }
   }
   else{
      scantime[1]=0x0;
      oldscan[1]=newscan[1];
   }

   if((newscan[2] == oldscan[2])){
      if(scantime[2]>60){
         SetKey(2,17);
         scantime[2]=0;
      }
   }
   else{
      scantime[2]=0x0;
      oldscan[2]=newscan[2];
   }



   if((newscan[3] == oldscan[3])){
      if(scantime[3]>60){
         SetKey(3,25);
         scantime[3]=0;
      }
   }
   else{
      scantime[3]=0x0;
      oldscan[3]=newscan[3];
   }

 

   for(j=0;j<4;j++){   
      k=0x01;
      if((DisableFlr[j] != 0xff) && !Fire){
         for(i=0;i<8;i++){            
            if(!(DisableFlr[j] & k)){
               CarKey[j] = CarKey[j] & ~k;
               ToggleKey[j]  = ToggleKey[j]  & ~k;
            }
            k=(k << 1);
         }
      }
   }
 
				
	MyLampdoubleClear();
	MyCarButtonBefOnChk();





/*
   if(CurKey){   
     for(j=0;j<4;j++){      
        ClrKey[j]     = 0x0;  
        ToggleKey[j]  = 0x0;
        CarKey[j]     = oldscan[j];   
      }         
   }

		
	if(Vip || BefVip){
		if(Vip != BefVip){
			if(!CarMove){		
		     	for(j=0;j<4;j++){      
		        	ClrKey[j]     = 0x0;  
		        	ToggleKey[j]  = 0x0;
		        	CarKey[j]     = 0x0;   
		      	}      
				BefVip=Vip;
			}
		}	   		
	}

*/




//open wait
//////////////////////////////
//////////////////////////////

	bDoorOpenWaitOn=0;

#ifndef	FLOOR_32_USE						
	if(Auto && Open && !CarMove){
		if(newscan[3] & 0x80){
			bDoorOpenWaitOn=1;
			UpButtonTime=1;
		}
	}
#endif


/*
#ifdef		FLOOR_64
#else
	if(Auto && Open && !CarMove){
		if(newscan[3] & 0x80){
			bDoorOpenWaitOn=1;
			UpButtonTime=1;
		}
	}
#endif
*/


//open wait



//////////////////////////////
//////////////////////////////

	return(0);

}



void    CarOpenCloseKey(void)
{

   if(UpKeyBit || bDoorOpenWaitOn){
      if((UpButtonTime<BUT_CANLE_T) && (UpButtonTime > 0) ){
         OPEN_LAMP=1;
		 bRealOpenkey=1;
         DoorKey=DoorKey | 0x01;
      }
      else{
         OPEN_LAMP=0;
		 bRealOpenkey=0;
         DoorKey=DoorKey & 0xfe;
      }      
   }
   else{
      OPEN_LAMP=0;
	  bRealOpenkey=0;

      UpButtonTime=0;
      DoorKey=DoorKey & 0xfe;
   }
   

	ButtonCloseSet();

   if(DnKeyBit && !Close && Auto && !bRealOpenkey){
      if((DnButtonTime<BUT_CANLE_T) && (DnButtonTime > 0)){
         CLOSE_LAMP=1;
         DoorKey=DoorKey | 0x02;
      }
      else{
         CLOSE_LAMP=0;
         DoorKey=DoorKey & 0xfd;
      }         
   }
   else{
      CLOSE_LAMP=0;
      DnButtonTime=0;
      DoorKey=DoorKey & 0xfd;
   }


	if(!bRealOpenkey && OpenLampSet){
         OPEN_LAMP=1;
	}

}



void    CarUpDownKeyNormal(void)
{
	unsigned char j;

	if(MyTmpAddress==0){        
		CarOpenCloseKey();
	}
	else{
		if((CurFloor == MyTmpAddress) &&  !CarMove){
			CarOpenCloseKey();
		}
		else{
	      OPEN_LAMP=0;
		  bRealOpenkey=0;	
	      UpButtonTime=0;
	      DoorKey=DoorKey & 0xfe;


	      CLOSE_LAMP=0;
	      DnButtonTime=0;
	      DoorKey=DoorKey & 0xfd;

		}

		if(CarMove || Open){
			scantime[0]=0;
			scantime[1]=0;
			scantime[2]=0;
			scantime[3]=0;
		}
	}

	if(Vip){		
		if( !bDoorOpenSub || !bDoorOpenMain)	OtherDoorKey[0]=0;   
      	j=(YourDoor | DoorKey | OtherDoorKey[0]);
		if( ((j & 0x0a)== 0) && !CarMove && Open){
			 bRealOpenkey=1;
	         DoorKey=DoorKey | 0x01;
		} 
	} 


   SetKeyButton();

}





#ifdef	CPU65K80
void    PortInit(void)
{

	TRISA = 0xff;
	TRISB = 0x00;
	TRISC = 0x00;
	TRISD = 0x00;
	TRISE = 0x00;
	TRISF = 0x00;

	TRISG0 = 1; 
	TRISG1 = 0; 
	TRISG2 = 1; 
	TRISG3 = 0; 
	TRISG4 = 0; 

/*
  TRISE2=0;	    // port E data direction...(output)
  TRISE1=1;
  TRISE0=1;

// TRISD Register
  TRISD7=1;	// port D data direction....(output)
  TRISD6=1;
  TRISD5=1;
  TRISD4=1;
  TRISD3=1;
  TRISD2=1;
  TRISD1=1;
  TRISD0=1;


// TRISC Register
  TRISC7=0;	// port C data direction
  TRISC6=1;
  TRISC5=1;
  TRISC4=0;
  TRISC3=0;
  TRISC2=0;
  TRISC1=0;
  TRISC0=0;



// TRISB Register
  TRISB7=0;	// port B data direction
  TRISB6=0;
  TRISB5=1;
  TRISB4=0;
  TRISB3=1;   //can rx 
  TRISB2=0;   //can tx
  TRISB1=1;   //in
  TRISB0=1;   //in

// TRISA Register
  TRISA7=0;	// port A data direction
  TRISA6=0;
  TRISA5=0;
///////////////////////  TRISA4=0;
  TRISA3=0;
  TRISA2=0;
  TRISA1=0;
  TRISA0=0;


// LATE Register
  LATE2=0;	// port E data latch
  LATE1=0;
  LATE0=0;

// LATD Register
  LATD7=0;	// port D data latch
  LATD6=0;
  LATD5=0;
  LATD4=0;
  LATD3=0;
  LATD2=0;
  LATD1=0;
  LATD0=0;

  LATD7=1;	// port D data latch
  LATD6=1;
  LATD5=1;
  LATD4=1;
  LATD3=1;
  LATD2=1;
  LATD1=1;
  LATD0=1;

// LATC Register
  LATC7=0;	// port C data latch
  LATC6=0;
  LATC5=0;
  LATC4=0;
  LATC3=0;
  LATC2=0;
  LATC1=0;
  LATC0=0;

// LATB Register
  LATB7=0;	// port B data latch
  LATB6=0;
  LATB5=0;
  LATB4=0;
  LATB3=0;
  LATB2=0;
  LATB1=1;
  LATB0=0;

// LATA Register
  LATA7=0;	// port A data latch
  LATA6=0;
  LATA5=0;
///////////////  LATA4=0;
  LATA3=0;
  LATA2=0;
  LATA1=0;
  LATA0=0;
*/    
}

#else
void    PortInit(void)
{
  TRISE2=0;	    // port E data direction...(output)
  TRISE1=1;
  TRISE0=1;

// TRISD Register
  TRISD7=1;	// port D data direction....(output)
  TRISD6=1;
  TRISD5=1;
  TRISD4=1;
  TRISD3=1;
  TRISD2=1;
  TRISD1=1;
  TRISD0=1;


// TRISC Register
  TRISC7=0;	// port C data direction
  TRISC6=1;
  TRISC5=1;
  TRISC4=0;
  TRISC3=0;
  TRISC2=0;
  TRISC1=0;
  TRISC0=0;



// TRISB Register
  TRISB7=0;	// port B data direction
  TRISB6=0;
  TRISB5=1;
  TRISB4=0;
  TRISB3=1;   //can rx 
  TRISB2=0;   //can tx
  TRISB1=1;   //in
  TRISB0=1;   //in

// TRISA Register
  TRISA7=0;	// port A data direction
  TRISA6=0;
  TRISA5=0;
  TRISA4=0;
  TRISA3=0;
  TRISA2=0;
  TRISA1=0;
  TRISA0=0;


// LATE Register
  LATE2=0;	// port E data latch
  LATE1=0;
  LATE0=0;

// LATD Register
  LATD7=0;	// port D data latch
  LATD6=0;
  LATD5=0;
  LATD4=0;
  LATD3=0;
  LATD2=0;
  LATD1=0;
  LATD0=0;

  LATD7=1;	// port D data latch
  LATD6=1;
  LATD5=1;
  LATD4=1;
  LATD3=1;
  LATD2=1;
  LATD1=1;
  LATD0=1;

// LATC Register
  LATC7=0;	// port C data latch
  LATC6=0;
  LATC5=0;
  LATC4=0;
  LATC3=0;
  LATC2=0;
  LATC1=0;
  LATC0=0;

// LATB Register
  LATB7=0;	// port B data latch
  LATB6=0;
  LATB5=0;
  LATB4=0;
  LATB3=0;
  LATB2=0;
  LATB1=1;
  LATB0=0;

// LATA Register
  LATA7=0;	// port A data latch
  LATA6=0;
  LATA5=0;
  LATA4=0;
  LATA3=0;
  LATA2=0;
  LATA1=0;
  LATA0=0;    
}
#endif

  
void main(void)
{


    di();

    Initial();
    PortInit();
    Timer0Init(); 

   OPEN_LAMP=0;
   CLOSE_LAMP=0;
   OPEN_KEY=1;
   CLOSE_KEY=1;

   AUTO_LAMP=0;
   MANUAL_LAMP=0;


    MyLocalAdr();
    MyAdrRead();


    CmpSetBit=0;            //new
    MaskSetBit=0;           //new

    LoadSetupValue();  //1
	LocalNumber=SelHostAdr;

    CAN_Init();    
    ei();

    CLRWDT();
    MainTimer=0;
    KeyClrTime=0;

    do{
        if(MainTimer>5){
            MainTimer=0;
            FDsp=!FDsp;
            WaitMyAdr();            
        }
        CompanyChk(LocalNumber);  //new
        CLRWDT();
    }while(KeyClrTime<40);


    if(CmpSetBit){              //new
    	new_value[5]=Company;   //
        CompanyWrite();  		//new
    }                           //new


    di();                       //new
    MaskSetBit=1;               //new
    CAN_Init();                 //new
    ei();                       //new


    di();
  
  
#ifdef		 U_COMPILER		1
	CANCONbits.REQOP = 4 ;// Entry Configration Mode
#else
	REQOP2 = 1 ;// Entry Configration Mode
	REQOP1 = 0 ;
	REQOP0 = 0 ;
#endif



    TxSidEidArrary();
        
    CANSetFilter(0,SidBuffer,EidBuffer);
    CANSetFilter(1,SidBuffer,EidBuffer);
    CANSetFilter(2,SidBuffer,EidBuffer);
    CANSetFilter(3,SidBuffer,EidBuffer);
    CANSetFilter(4,SidBuffer,EidBuffer);
    CANSetFilter(5,SidBuffer,EidBuffer);

    CANSetMask(0,0x007f,0x0000c000);
    CANSetMask(1,0x007f,0x0000c000);


    CANSetFilter(0,SidBuffer,EidBuffer);
    CANSetFilter(1,SidBuffer,EidBuffer);
    CANSetFilter(2,SidBuffer,EidBuffer);
    CANSetFilter(3,SidBuffer,EidBuffer);
    CANSetFilter(4,SidBuffer,EidBuffer);
    CANSetFilter(5,SidBuffer,EidBuffer);

    CANSetMask(0,0x007f,0x0001c000);
    CANSetMask(1,0x007f,0x0001c000);



#ifdef		 U_COMPILER		1
	CANCONbits.REQOP = 0 ;// Entry Configration Mode
#else
	REQOP2 = 0 ;// Entry Configration Mode
	REQOP1 = 0 ;
	REQOP0 = 0 ;
#endif


    ei();


//    SetupCheck();
/////    DspModel=1;

       
    SEL_ACT=1;
    SEL0=1;
    SEL1=1;
    SEL2=1;

    CanCmd=0x0;
    CanDatacnt0=0x8;
    CanDatacnt1=0x8;

////////////    TwoDoorDrive=0;

   for(OffsetAdr=0;OffsetAdr<4;OffsetAdr++){
      CarKey[OffsetAdr] =0x0;
      newscan[OffsetAdr]=0x0;
      oldscan[OffsetAdr]=0x0;
      YourKey[OffsetAdr]=0x0;
      YourKey0[OffsetAdr]=0x0;
      YourKey1[OffsetAdr]=0x0;
      YourKey2[OffsetAdr]=0x0;
      YourKey3[OffsetAdr]=0x0;
   }         


	MyBaseFlr=0;
	#ifdef		FLOOR_64          
	MyBaseFlr=IAM_BASE_FLR;
	#endif


   WR_CLK=1;

   DATA_PORT=0xff;

   
   Toggle=0;   
   TOGGLE=1;   
   if(!TOGGLE)   Toggle=1;      
   

   P2=0xff;

   BELL=1;
   BellTime=100;
   
   MainTimer=0;
   RstTimer=0;
   Car_Key_Valid=0;
   Tx0ConfirmCnt=0;

	bIamXSubDoor=0;
    if(bMainSubDoor)	bIamXSubDoor=1;

//    if(SubkDoor & 0x01)	bIamXSubDoor=1;


//  CallMeAdr=(MyAddress + 64);
//  else                CallMeAdr=(MyAddress);

    CallMeAdr=(MyAddress);
    HostCallMe=0;    
	bHibHpiSel=1;
//////////////////////    SetupBit=0;                     //2
	ChangeSetup=0;
	LocalNumber=SelHostAdr;

   while(1){
	    if(ChangeSetup){
			ChangeSetup=0;
			CompanyWrite();
	    }


        CLRWDT();            
	

        CanLiveChk();

		
        if(bOtherCarClear)	CanKeyValue[7]=(CanKeyValue[7] |  OTHER_CAR_CLEAR);                
        else                CanKeyValue[7]=(CanKeyValue[7] & ~OTHER_CAR_CLEAR);            

        if(bIamXSubDoor)    CanKeyValue[7]=(CanKeyValue[7] |  SUB_DOOR_BIT);                
        else                CanKeyValue[7]=(CanKeyValue[7] & ~SUB_DOOR_BIT);            


        if(MyBaseFlr >= 32)	CanKeyValue[7]=(CanKeyValue[7] |  IAM_FLR32);                
        else                CanKeyValue[7]=(CanKeyValue[7] & ~IAM_FLR32);            

                                
        if(CanTxAct){
            if(!KeyLoad(SelHostAdr)){
                CanKeyValue[2]=DoorKey;
                CanKeyValue[3]=CarKey[0];
                CanKeyValue[4]=CarKey[1];
                CanKeyValue[5]=CarKey[2];
                CanKeyValue[6]=CarKey[3];

                CanTx0();

    			HostCallMe=0;    
				LIVE_LAMP=!LIVE_LAMP;
            }

#ifdef		FLOOR_64          
            else if(MaxButton != 0xff){
                CanCmd=CAN_KEY_READY;
                CanKeyValue[1]=MaxButton;
                CanKeyValue[2]=DoorKey;
                CanKeyValue[3]=CarKey[0];
                CanKeyValue[4]=CarKey[1];
                CanKeyValue[5]=CarKey[2];
                CanKeyValue[6]=CarKey[3];                

                CanTx0();
    			HostCallMe=0;    
				LIVE_LAMP=!LIVE_LAMP;
			}
#endif

            else if((Car_Key_Valid && (Tx0ConfirmCnt) )){
                CanCmd=CAN_KEY_CONFIRM;
                CanKeyValue[2]=DoorKey;

                CanKeyValue[3]=CarKey[0];
                CanKeyValue[4]=CarKey[1];
                CanKeyValue[5]=CarKey[2];
                CanKeyValue[6]=CarKey[3];                

                CanTx0();
    			HostCallMe=0;    
				LIVE_LAMP=!LIVE_LAMP;
            }

            else if(HostCallMe){
                CanCmd=CAN_NO_KEY_SET;
                CanKeyValue[2]=DoorKey;
                CanKeyValue[3]=CarKey[0];
                CanKeyValue[4]=CarKey[1];
                CanKeyValue[5]=CarKey[2];
                CanKeyValue[6]=CarKey[3];                

                CanTx0();
    			HostCallMe=0;    
				LIVE_LAMP=!LIVE_LAMP;
            }

        	if(CanKeyValue[0]==CanCmd){
				bOtherCarClear=0;
			}

			CanTxAct=0;
        }
            
        CarLampNormal(SelHostAdr);              
        CarUpDownKeyNormal();
       

        if(shiftTime > 100){         
            ShiftData();
            shiftTime=0;
        }                  


        if((Auto) && (!KeyClr) && (!Parking) && (MyAddress==A_CAR1) ){
			BellTime=0;
		}
                    
        if((Auto==0) || KeyClr || Parking || (YourLiveTimer>10)){
            KeyClearAll();  
            KeyClrTime=0;
        }
        
    }

}




void interrupt isr(void)
{


    unsigned char a,i,tmp,tmp_buf;


    if( TMR0IF )
    {
        TMR0IF = 0 ;
        TMR0L=MSEC_L;
        TMR0H=MSEC_H;
        
        CanTime++;
        
        scantime[0]++;
        scantime[1]++;
        scantime[2]++;
        scantime[3]++;
        
        
        BellTime++;
        
        if(BellTime<100){
            BELL=0;
        }
        else{
            BELL=1;
            BellTime=100;
        }

        
        tmp=P1;

        TRISD=0x00;       

        SEL_ACT=1;
        
        shiftTime++;
        
        DSP_OFF=1;
 
#ifdef	CPU65K80
		LATC=0x0;
		LATF=0x0;
		LATE=0xff;
		if(shiftDataBuf[htpt] & 0x01)	LATE0=0;	
		if(shiftDataBuf[htpt] & 0x02)	LATE1=0;	
		if(shiftDataBuf[htpt] & 0x04)	LATE2=0;	
		if(shiftDataBuf[htpt] & 0x08)	LATE4=0;	
		if(shiftDataBuf[htpt] & 0x10)	LATE5=0;	
		if(shiftDataBuf[htpt] & 0x20)	LATE6=0;	
		if(shiftDataBuf[htpt] & 0x40)	LATE7=0;	

//        LATE= ~shiftDataBuf[htpt];
#else       
        DATA_PORT=shiftDataBuf[htpt];
#endif     
   
        WR_CLK=0;   
        WR_CLK=1;

#ifdef	CPU65K80

		switch(htpt){
			case	0:
				LATC0=1;
				break;
			case	1:
				LATC1=1;
				break;
			case	2:
				LATC2=1;
				break;
			case	3:
				LATC3=1;
				break;
			case	4:
				LATC4=1;
				break;
			case	5:
				LATC5=1;
				break;
			case	6:
				LATC6=1;
				break;
			case	7:
				LATC7=1;
				break;
			case	8:
				LATF0=1;
				break;
			case	9:
				LATF1=1;
				break;
			case	10:
				LATF2=1;
				break;
			case	11:
				LATF3=1;
				break;
			case	12:
				LATF4=1;
				break;
			case	13:
				LATF5=1;
				break;
			case	14:
				LATF6=1;
				break;
			case	15:
				LATF7=1;
				break;
		}
#else        
        P2=(htpt | 0xf0);      
#endif
        
        DSP_OFF=0;
        

        htpt++;
        if(htpt == 0x10){  
            htpt = 0x0;
        }
        
        
        a=htpt%4;
        
        if(a==0){         

            DATA_PORT=(CarKey[0] | YourKey[0]);

            SEL0=0;
            SEL1=0;
            SEL2=1;

            SEL_ACT=0;            
            SEL_ACT=1; 
        }
        
        else if(a==1){
            DATA_PORT=(CarKey[1] | YourKey[1]);
            SEL0=1;
            SEL1=0;
            SEL2=1;
            SEL_ACT=0;
            SEL_ACT=1;
        }
        
        else if(a==2){
            DATA_PORT=(CarKey[2] | YourKey[2]);
            SEL0=0;
            SEL1=1;
            SEL2=1;
            SEL_ACT=0;   
            SEL_ACT=1;   
        }
        
        else if(a==3){   
         	tmp_buf=(CarKey[3] | YourKey[3]);


#ifndef	FLOOR_32_USE						
			tmp_buf=(tmp_buf & 0x1f);
			if(UpMove)							tmp_buf=(tmp_buf | 0x20);	
			if(DnMove)							tmp_buf=(tmp_buf | 0x40);	
			if(bErrorCar )						tmp_buf=(tmp_buf | 0x80);	
#endif


			DATA_PORT=tmp_buf;

            SEL0=1;
            SEL1=1;
            SEL2=1;
            SEL_ACT=0;
            SEL_ACT=1;
        }   
        
        DATA_PORT=0xff;

        TRISD=0xff;       
        
        CLOSE_KEY=1;
        OPEN_KEY=1;


        
        if(!OPEN_KEY)  UpKeyBit=1;   
        else           UpKeyBit=0;   

        if(!CLOSE_KEY) DnKeyBit=1;   
        else           DnKeyBit=0;
        

		io();           
        
        msec100++;
        if(msec100>100){
            msec100=0;
			NoCanInt++;
            sfttime++;
            MainTimer++;
            KeyClrTime++;
            YourLiveTimer++;
			MoveTime[0]++;

            if(UpButtonTime<BUT_CANLE_T){
				UpButtonTime++;   
				if(bCurOpenKey){
					if(UpButtonTime > 150)	UpButtonTime=150;
				}	 
            }
            if(DnButtonTime<BUT_CANLE_T){
                DnButtonTime++;   
            }      

            for(i=0;i<MAX_ELEV;i++){          
                CanLiveTimeAdr[i]++;
            }                

        }  
                
        P1=tmp;   
    }


#ifdef	CPU65K80
    if(PIR5>0){
        CanInterrupt();
    }
#else
    if(PIR3>0){
        CanInterrupt();
    }
#endif

}





