
#include <p30fxxxx.h>
#include  	"30f6010_io.h"            
#include  	"host_io.h"            
#include  	"iodef.h"
#include  	"door.h"
#include  	"com.h"
#include  	"default_setup.h" 


unsigned long 	PulseBuf;


unsigned int  __attribute__((section(".usercode")))   MmToPulse(unsigned long Mm)
{
	unsigned long	tmpVar1,tmpVar2,tmpMm;
 
	tmpVar1=(unsigned long)10000;
	tmpMm=Mm;
	tmpVar2=(tmpVar1 * tmpMm); 
	tmpVar1=GET_LONG(MM_PULSE);
	PulseBuf=(tmpVar2/tmpVar1);

	return(0);
}
