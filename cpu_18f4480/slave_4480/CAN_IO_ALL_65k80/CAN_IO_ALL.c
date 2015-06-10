

#include    <pic18.h>


#include        "..\..\..\system_com\memory_map.h"
#include        "..\..\comm_4480\iodef.h"
#include        "..\..\comm_4480\fontout.h"
#include        "..\..\comm_4480\comdata.h"
#include        "..\..\comm_4480\keysort.h"
#include        "..\..\comm_4480\setup.h"




extern  unsigned char    Lamp(unsigned char id);  //4
extern	void  			MyAdrRead(void);
extern	unsigned int  	MyFunc(void);
extern	void    		PortInit_X(void);
extern	void  			Timer_1msec(void);

extern  void    		CompanyChk(unsigned char id);  

                            

unsigned    char  	DisableFlr[4]   ={0,0,0,0};            

unsigned    char  	MyAddress;        
unsigned    char  	MainTimer=0;
unsigned    char  	msec100=0;
unsigned    char  	sec1=0;
unsigned    char  	MoveTime[MAX_ELEV];
unsigned    char	CallMeAdr;



bit   FDsp;



void    MyLampCheck(void)
{
}            


void    SetupDisplayES15(unsigned char mdata,unsigned char mode)
{
}

void  WaitMyAdr(void)
{
}



void    PortInit(void)
{
	PortInit_X();
}




unsigned char CompanyPass(void)
{

#if   defined(NEW_CAN_IO_32_BCD)  ||  defined(OLD_CAN_IO_32_FLR_ONOFF) || defined(POWER_CONTROL)
	return(0);	
#else
    unsigned char	i;
    unsigned char	tmpCompany;
	unsigned char	MyCompany[15];

	MyCompany[0]= '0';
	RxEidBuffer=0;
	CanTxAct=0;

    for(i=0;i<10;){
        CLRWDT();
        if((RxEidBuffer & HOST_BOARD) &&  (CanTxAct==1) ){
			CanTxAct=0;
			tmpCompany=(unsigned char)RxSidBuffer;
			if(MyCompany[i] == tmpCompany)	i++;
			else							i=0;
			MyCompany[i] = tmpCompany;
		}
	}

	Company=tmpCompany;	
    new_value[5]=Company;
	return(0);	
#endif   

}




void main(void)
{

    unsigned char confirmkey;
    unsigned int	i;

    di();

    Initial();
    PortInit();
    Timer0Init(); 

    Tx1ConfirmCnt=0;
    Tx0ConfirmCnt=0;

    CmpSetBit=0;            //new
    MaskSetBit=0;           //new    

    MyAdrRead();


    LoadSetupValue();  //1
    CAN_Init();
    ei();
            
    sec1=0;
	MoveTime[0]=0;
 
	CompanyPass();

 
/*
    do{
        if(MainTimer>5){
            MainTimer=0;
            FDsp=!FDsp;
            WaitMyAdr();            
        }
        CompanyChk(LocalNumber);  //new

        CLRWDT();
    }while(MoveTime[0] < 4 );

     
    if(CmpSetBit){              
    	new_value[5]=Company;   
        CompanyWrite();  		
    }                           

*/

	SelHostAdr=LocalNumber;

    di();                       //new
    MaskSetBit=1;               //new
    CAN_Init();                 //new
    ei();                       //new


    FDsp=1;
    MainTimer=0;
    WaitMyAdr();            
       
    CanDatacnt0=3;
    CanDatacnt1=3;
    CanCmd=0;
	ChangeSetup=0;

	
	for(i=0;i<(MAX_SAVE_BUF-1);i++)	RcvBuf[i]=0;

	SelHostAdr=LocalNumber;
	CallMeAdr=MyAddress;

    while(1){    

        CLRWDT();

	    if(ChangeSetup){
			ChangeSetup=0;
			CompanyWrite();
	    }

		MyFunc();
    }
}



void interrupt isr(void)
{

    unsigned char i;
    

    if( TMR0IF )
    {
    
        TMR0IF = 0 ;
        TMR0L=MSEC_L;
        TMR0H=MSEC_H;    

		Timer_1msec();

        msec100++;
    
        if(msec100>100){
            msec100=0;
            for(i=0;i<MAX_ELEV;i++){          
                CanLiveTimeAdr[i]++;
            }        
            
            MainTimer++;
    		NoCanInt++;

            sec1++;
            if(sec1>10){

                sec1=0;
                for(i=0;i<MAX_ELEV;i++){          
                    MoveTime[i]++;
                }
				RUN_LED	=!RUN_LED;
            }
        }
      
    }

#if  defined(CPU45K80)   ||  defined(CPU65K80)
    if(PIR5>0){
        CanInterrupt();
    }
#else
    if(PIR3>0){
        CanInterrupt();
    }
#endif

}




