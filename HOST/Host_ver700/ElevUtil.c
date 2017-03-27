
#include <p30fxxxx.h>
#include  	"30f6010_io.h"            
#include  	"host_io.h"            
#include  	"iodef.h"
#include  	"door.h"
#include  	"com.h"
#include  	"default_setup.h" 


unsigned long 	PulseBuf,MmBuf;


unsigned long  __attribute__((section(".usercode")))   MmToPulse(unsigned long Mm)
{
	unsigned long	tmpVar1,tmpVar2,tmpMm;
 
	tmpVar1=(unsigned long)10000;
	tmpMm=Mm;
	tmpVar2=(tmpVar1 * tmpMm); 
	tmpVar1=GET_LONG(MM_PULSE);

	if(tmpVar1 > 0)		PulseBuf=(tmpVar2/tmpVar1);
	else				PulseBuf=0;

	PulseBuf=(tmpVar2/tmpVar1);

	return(PulseBuf);
}

unsigned long  __attribute__((section(".usercode")))   PulseToMm(unsigned long Pulse)
{
	unsigned long	tmpVar1,tmpVar2,tmpMm;
 
	tmpVar1=GET_LONG(MM_PULSE);
	tmpVar2=Pulse;
	tmpMm=(tmpVar2 * tmpVar1);	
	tmpVar1=10000;
	tmpMm=(tmpMm / tmpVar1);
	MmBuf=tmpMm;	
	return(tmpMm);	
}

