


//master/slave   =>RxSingleOn=1 master  0=slave
//SpreadingFactor ==11;  350msec  ->  ¼öÁ¤  SpreadingFactor ==7   247(60byte)msec  ,sensitivity=-126
//Codingrate=2
//Bandwith=62.5
//center Hz=433,701,250==>433,826,250==>433,951,250==>434,076,250
//power 8 db
//can com check
//extio8  delay time

#include    <pic18.h>
#include        "..\crt_can_232_45k80\crt_canport1.h"
#include        "..\crt_can_232_45k80\crt_comport1.h"
#include        "loader_45k80.h"
#include        "spi.h"





unsigned    char  	MainTimer=0;
unsigned    char	msec100=0;


extern  void  Timer0Init(void);
extern  void  Initial(void);



void    PortInit(void)
{
	TRISA=0xff;
	TRISB=0xff;
	TRISC=0xff;
	TRISD=0xff;
	TRISE0=1;
	TRISE1=1;
	TRISE2=1;

  	LATA=0xff;	
  	LATB=0xff;	
  	LATC=0xff;	
  	LATD=0xff;	
  	LATE=0xff;	
}



extern	int LoRa_Init( void );
extern	int Lora_Func( void );
extern	int Lora_Msec1_Interrpt( void );
extern	int RunLed( void );


void main(void)
{
    
	unsigned int i;

    di();
    Initial();
    PortInit();
    Timer0Init(); 
/////////////////	Loader_Com_Init();

//	Com1Init();
	Can1Init();


    ei();

	MainTimer=0;
	msec100=0;


	for(i=0;i<65530;i++)	CLRWDT();

	LoRa_Init( );
	
    while(1){    
    	CLRWDT();
//		Loader_Func();
		Lora_Func();
		Can1Check();

		if(MainTimer >=10){
			RunLed();
			MainTimer=0;
		}
    }
}



void interrupt isr(void)
{
   
    if( TMR0IF )
    {    
        TMR0IF = 0 ;
        TMR0L=MSEC_L;
        TMR0H=MSEC_H;    

//		Loader_Msec1_Interrpt();
		Lora_Msec1_Interrpt();

        msec100++;
        if(msec100>100){
            msec100=0;
			MainTimer++;
        }  
    }

//	Loader_Com_Interrpt();

	Can1Interrupt();
	
}




