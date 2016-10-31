



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


/*
#ifndef	AUTO_LANDING_485	

void  __attribute__((section(".usercode"))) SerialCheck(void)
{
#ifndef		RS485_FOR_CRT	
    HibHpiReqCheck();
#else
	CrtReqCheck();
#endif


	if((RxStatus==TX_SET) && (SerialTime > 2)){
		TXEN=1;  		
		RxCurCnt=0;
      	RxStatus = STX_CHK;
	}

	if(RxStatus != TX_SET){
		TXEN=1;  		
	}
}


#endif

*/




