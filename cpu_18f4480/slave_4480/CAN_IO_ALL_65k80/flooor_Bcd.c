

#include    <pic18.h>



#include        "..\..\..\system_com\memory_map.h"
#include        "..\..\comm_4480\iodef.h"
#include        "..\..\comm_4480\fontout.h"
#include        "..\..\comm_4480\comdata.h"
#include        "..\..\comm_4480\keysort.h"
#include        "..\..\comm_4480\setup.h"
#include        "..\..\comm_4480\esdots.h"



#if   defined(NEW_CAN_IO_32_BCD)


#define	CHARTER_TIME	20	// 20 msec

unsigned char	charter_IO_00;
unsigned char	charter_IO_01;
unsigned char	charter_IO_02;
unsigned char	charter_IO_03;
unsigned char	charter_IO_04;
unsigned char	charter_IO_05;
unsigned char	charter_IO_06;
unsigned char	charter_IO_07;
unsigned char	charter_IO_08;
unsigned char	charter_IO_09;
unsigned char	charter_IO_10;
unsigned char	charter_IO_11;
unsigned char	charter_IO_12;
unsigned char	charter_IO_13;
unsigned char	charter_IO_14;
unsigned char	charter_IO_15;
unsigned char	charter_IO_16;
unsigned char	charter_IO_17;
unsigned char	charter_IO_18;
unsigned char	charter_IO_19;
unsigned char	charter_IO_20;
unsigned char	charter_IO_21;
unsigned char	charter_IO_22;
unsigned char	charter_IO_23;
unsigned char	charter_IO_24;
unsigned char	charter_IO_25;
unsigned char	charter_IO_26;
unsigned char	charter_IO_27;
unsigned char	charter_IO_28;
unsigned char	charter_IO_29;
unsigned char	charter_IO_30;
unsigned char	charter_IO_31;


bit	Bef_IO_00=0;	
bit	Cur_IO_00=0;	
bit	Bef_IO_01=0;	
bit	Cur_IO_01=0;	
bit	Bef_IO_02=0;	
bit	Cur_IO_02=0;	
bit	Bef_IO_03=0;	
bit	Cur_IO_03=0;	
bit	Bef_IO_04=0;	
bit	Cur_IO_04=0;	
bit	Bef_IO_05=0;	
bit	Cur_IO_05=0;	
bit	Bef_IO_06=0;	
bit	Cur_IO_06=0;	
bit	Bef_IO_07=0;	
bit	Cur_IO_07=0;	
bit	Bef_IO_08=0;	
bit	Cur_IO_08=0;	
bit	Bef_IO_09=0;	
bit	Cur_IO_09=0;	

bit	Bef_IO_10=0;	
bit	Cur_IO_10=0;	
bit	Bef_IO_11=0;	
bit	Cur_IO_11=0;	
bit	Bef_IO_12=0;	
bit	Cur_IO_12=0;	
bit	Bef_IO_13=0;	
bit	Cur_IO_13=0;	
bit	Bef_IO_14=0;	
bit	Cur_IO_14=0;	
bit	Bef_IO_15=0;	
bit	Cur_IO_15=0;	
bit	Bef_IO_16=0;	
bit	Cur_IO_16=0;	
bit	Bef_IO_17=0;	
bit	Cur_IO_17=0;	
bit	Bef_IO_18=0;	
bit	Cur_IO_18=0;	
bit	Bef_IO_19=0;	
bit	Cur_IO_19=0;
	
bit	Bef_IO_20=0;	
bit	Cur_IO_20=0;	
bit	Bef_IO_21=0;	
bit	Cur_IO_21=0;	
bit	Bef_IO_22=0;	
bit	Cur_IO_22=0;	
bit	Bef_IO_23=0;	
bit	Cur_IO_23=0;	
bit	Bef_IO_24=0;	
bit	Cur_IO_24=0;	
bit	Bef_IO_25=0;	
bit	Cur_IO_25=0;	
bit	Bef_IO_26=0;	
bit	Cur_IO_26=0;	
bit	Bef_IO_27=0;	
bit	Cur_IO_27=0;	
bit	Bef_IO_28=0;	
bit	Cur_IO_28=0;	
bit	Bef_IO_29=0;	
bit	Cur_IO_29=0;	
bit	Bef_IO_30=0;	
bit	Cur_IO_30=0;
	
bit	Bef_IO_31=0;	
bit	Cur_IO_31=0;	

void  MyAdrRead(void)
{
   MyAddress=0;
   MyAddress=0x8a;
}




#ifdef  CPU65K80

	void    PortInit_X(void)
	{
	  TRISG4=1;
	  TRISG3=1;	    
	  TRISG2=1;	    
	  TRISG1=1;
	  TRISG0=1;
	
	  TRISF7=1;	    
	  TRISF6=1;
	  TRISF5=1;
	  TRISF4=1;	    
	  TRISF3=1;
	  TRISF4=1;
	  TRISF2=1;	    
	  TRISF1=1;
	  TRISF0=1;
	
	
	  TRISE7=1;	    
	  TRISE6=1;
	  TRISE5=1;
	  TRISE4=1;	    
	  TRISE4=1;
	  TRISE2=1;	    
	  TRISE1=1;
	  TRISE0=1;
	

	  TRISD7=0;	
	  TRISD6=0;
	  TRISD5=0;
	  TRISD4=0;
	  TRISD3=0;
	  TRISD2=0;
	  TRISD1=0;
	  TRISD0=0;
	
	
	  TRISC7=1;	
	  TRISC6=1;
	  TRISC5=1;
	  TRISC4=1;
	  TRISC3=1;
	  TRISC2=1;
	  TRISC1=1;
	  TRISC0=1;


	  TRISB7=1;	
	  TRISB6=1;
	  TRISB5=1;
	  TRISB4=1;
	  TRISB3=1;   //can rx 
	  TRISB2=0;   //can tx
	  TRISB1=1;   
	  TRISB0=0;   //run
	
	
	  TRISA7=1;	
	  TRISA6=1;
	  TRISA5=1;
	  TRISA3=1;
	  TRISA2=1;
	  TRISA1=1;
	  TRISA0=1;


//////////////////////////////////////
	  LATG4=1;
	  LATG3=1;
	  LATG2=1;	
	  LATG1=1;
	  LATG0=1;
	
	  LATF7=1;
	  LATF6=1;
	  LATF5=1;	
	  LATF4=1;
	  LATF3=1;
	  LATF2=1;	
	  LATF1=1;
	  LATF0=1;
	
	
	  LATE7=1;
	  LATE6=1;
	  LATE5=1;	
	  LATE4=1;
	  LATE2=1;	
	  LATE1=1;
	  LATE0=1;


	  LATD7=0;	
	  LATD6=0;
	  LATD5=0;
	  LATD4=0;
	  LATD3=0;
	  LATD2=0;
	  LATD1=0;
	  LATD0=0;
	
	  LATC7=1;	
	  LATC6=1;
	  LATC5=1;
	  LATC4=1;
	  LATC3=1;
	  LATC2=1;
	  LATC1=1;
	  LATC0=1;
	
	  LATB7=1;	
	  LATB6=1;
	  LATB5=1;
	  LATB4=1;
	  LATB3=1;
	  LATB2=1;
	  LATB1=1;
	  LATB0=1;

	  LATA7=1;	
	  LATA6=1;
	  LATA5=1;
	  LATA3=1;
	  LATA2=1;
	  LATA1=1;
	  LATA0=1;
	}
#else
    #error  "Type Not Define Error( I_AM_FLOOR_BCD)"
#endif

	


void	Input_Chk(void)
{
    if(Bef_IO_00 == IO_00){
        if(charter_IO_00 > CHARTER_TIME ){
            Cur_IO_00 = IO_00;
        }
    }
    else{
        Bef_IO_00 = IO_00;
        charter_IO_00 = 0;
    }    


    if(Bef_IO_01 == IO_01){
        if(charter_IO_01 > CHARTER_TIME ){
            Cur_IO_01 = IO_01;
        }
    }
    else{
        Bef_IO_01 = IO_01;
        charter_IO_01 = 0;
    }    



    if(Bef_IO_02 == IO_02){
        if(charter_IO_02 > CHARTER_TIME ){
            Cur_IO_02 = IO_02;
        }
    }
    else{
        Bef_IO_02 = IO_02;
        charter_IO_02 = 0;
    }    


    if(Bef_IO_03 == IO_03){
        if(charter_IO_03 > CHARTER_TIME ){
            Cur_IO_03 = IO_03;
        }
    }
    else{
        Bef_IO_03 = IO_03;
        charter_IO_03 = 0;
    }    



    if(Bef_IO_04 == IO_04){
        if(charter_IO_04 > CHARTER_TIME ){
            Cur_IO_04 = IO_04;
        }
    }
    else{
        Bef_IO_04 = IO_04;
        charter_IO_04 = 0;
    }    



    if(Bef_IO_05 == IO_05){
        if(charter_IO_05 > CHARTER_TIME ){
            Cur_IO_05 = IO_05;
        }
    }
    else{
        Bef_IO_05 = IO_05;
        charter_IO_05 = 0;
    }    


    if(Bef_IO_06 == IO_06){
        if(charter_IO_06 > CHARTER_TIME ){
            Cur_IO_06 = IO_06;
        }
    }
    else{
        Bef_IO_06 = IO_06;
        charter_IO_06 = 0;
    }    

    if(Bef_IO_07 == IO_07){
        if(charter_IO_07 > CHARTER_TIME ){
            Cur_IO_07 = IO_07;
        }
    }
    else{
        Bef_IO_07 = IO_07;
        charter_IO_07 = 0;
    }    



    if(Bef_IO_08 == IO_08){
        if(charter_IO_08 > CHARTER_TIME ){
            Cur_IO_08 = IO_08;
        }
    }
    else{
        Bef_IO_08 = IO_08;
        charter_IO_08 = 0;
    }    


    if(Bef_IO_09 == IO_09){
        if(charter_IO_09 > CHARTER_TIME ){
            Cur_IO_09 = IO_09;
        }
    }
    else{
        Bef_IO_09 = IO_09;
        charter_IO_09 = 0;
    }    



    if(Bef_IO_10 == IO_10){
        if(charter_IO_10 > CHARTER_TIME ){
            Cur_IO_10 = IO_10;
        }
    }
    else{
        Bef_IO_10 = IO_10;
        charter_IO_10 = 0;
    }    



    if(Bef_IO_11 == IO_11){
        if(charter_IO_11 > CHARTER_TIME ){
            Cur_IO_11 = IO_11;
        }
    }
    else{
        Bef_IO_11 = IO_11;
        charter_IO_11 = 0;
    }    


    if(Bef_IO_12 == IO_12){
        if(charter_IO_12 > CHARTER_TIME ){
            Cur_IO_12 = IO_12;
        }
    }
    else{
        Bef_IO_12 = IO_12;
        charter_IO_12 = 0;
    }    


    if(Bef_IO_13 == IO_13){
        if(charter_IO_13 > CHARTER_TIME ){
            Cur_IO_13 = IO_13;
        }
    }
    else{
        Bef_IO_13 = IO_13;
        charter_IO_13 = 0;
    }    



    if(Bef_IO_14 == IO_14){
        if(charter_IO_14 > CHARTER_TIME ){
            Cur_IO_14 = IO_14;
        }
    }
    else{
        Bef_IO_14 = IO_14;
        charter_IO_14 = 0;
    }    



    if(Bef_IO_15 == IO_15){
        if(charter_IO_15 > CHARTER_TIME ){
            Cur_IO_15 = IO_15;
        }
    }
    else{
        Bef_IO_15 = IO_15;
        charter_IO_15 = 0;
    }    


    if(Bef_IO_16 == IO_16){
        if(charter_IO_16 > CHARTER_TIME ){
            Cur_IO_16 = IO_16;
        }
    }
    else{
        Bef_IO_16 = IO_16;
        charter_IO_16 = 0;
    }    

    if(Bef_IO_17 == IO_17){
        if(charter_IO_17 > CHARTER_TIME ){
            Cur_IO_17 = IO_17;
        }
    }
    else{
        Bef_IO_17 = IO_17;
        charter_IO_17 = 0;
    }    



    if(Bef_IO_18 == IO_18){
        if(charter_IO_18 > CHARTER_TIME ){
            Cur_IO_18 = IO_18;
        }
    }
    else{
        Bef_IO_18 = IO_18;
        charter_IO_18 = 0;
    }    


    if(Bef_IO_19 == IO_19){
        if(charter_IO_19 > CHARTER_TIME ){
            Cur_IO_19 = IO_19;
        }
    }
    else{
        Bef_IO_19 = IO_19;
        charter_IO_19 = 0;
    }    




    if(Bef_IO_20 == IO_20){
        if(charter_IO_20 > CHARTER_TIME ){
            Cur_IO_20 = IO_20;
        }
    }
    else{
        Bef_IO_20 = IO_20;
        charter_IO_20 = 0;
    }    



    if(Bef_IO_21 == IO_21){
        if(charter_IO_21 > CHARTER_TIME ){
            Cur_IO_21 = IO_21;
        }
    }
    else{
        Bef_IO_21 = IO_21;
        charter_IO_21 = 0;
    }    


    if(Bef_IO_22 == IO_22){
        if(charter_IO_22 > CHARTER_TIME ){
            Cur_IO_22 = IO_22;
        }
    }
    else{
        Bef_IO_22 = IO_22;
        charter_IO_22 = 0;
    }    


    if(Bef_IO_23 == IO_23){
        if(charter_IO_23 > CHARTER_TIME ){
            Cur_IO_23 = IO_23;
        }
    }
    else{
        Bef_IO_23 = IO_23;
        charter_IO_23 = 0;
    }    



    if(Bef_IO_24 == IO_24){
        if(charter_IO_24 > CHARTER_TIME ){
            Cur_IO_24 = IO_24;
        }
    }
    else{
        Bef_IO_24 = IO_24;
        charter_IO_24 = 0;
    }    



    if(Bef_IO_25 == IO_25){
        if(charter_IO_25 > CHARTER_TIME ){
            Cur_IO_25 = IO_25;
        }
    }
    else{
        Bef_IO_25 = IO_25;
        charter_IO_25 = 0;
    }    


    if(Bef_IO_26 == IO_26){
        if(charter_IO_26 > CHARTER_TIME ){
            Cur_IO_26 = IO_26;
        }
    }
    else{
        Bef_IO_26 = IO_26;
        charter_IO_26 = 0;
    }    

    if(Bef_IO_27 == IO_27){
        if(charter_IO_27 > CHARTER_TIME ){
            Cur_IO_27 = IO_27;
        }
    }
    else{
        Bef_IO_27 = IO_27;
        charter_IO_27 = 0;
    }    



    if(Bef_IO_28 == IO_28){
        if(charter_IO_28 > CHARTER_TIME ){
            Cur_IO_28 = IO_28;
        }
    }
    else{
        Bef_IO_28 = IO_28;
        charter_IO_28 = 0;
    }    


    if(Bef_IO_29 == IO_29){
        if(charter_IO_29 > CHARTER_TIME ){
            Cur_IO_29 = IO_29;
        }
    }
    else{
        Bef_IO_29 = IO_29;
        charter_IO_29 = 0;
    }    


    if(Bef_IO_30 == IO_30){
        if(charter_IO_30 > CHARTER_TIME ){
            Cur_IO_30 = IO_30;
        }
    }
    else{
        Bef_IO_30 = IO_30;
        charter_IO_30 = 0;
    }    


    if(Bef_IO_31 == IO_31){
        if(charter_IO_31 > CHARTER_TIME ){
            Cur_IO_31 = IO_31;
        }
    }
    else{
        Bef_IO_31 = IO_31;
        charter_IO_31 = 0;
    }    

}


unsigned int  MyFunc(void)
{

	unsigned	char	floor;

	Input_Chk();

	floor=0;

	if(!Cur_IO_00)	floor=1;
	if(!Cur_IO_01)	floor=2;
	if(!Cur_IO_02)	floor=3;
	if(!Cur_IO_03)	floor=4;
	if(!Cur_IO_04)	floor=5;
	if(!Cur_IO_05)	floor=6;
	if(!Cur_IO_06)	floor=7;
	if(!Cur_IO_07)	floor=8;

	if(!Cur_IO_08)	floor=9;
	if(!Cur_IO_09)	floor=10;
	if(!Cur_IO_10)	floor=11;
	if(!Cur_IO_11)	floor=12;
	if(!Cur_IO_12)	floor=13;
	if(!Cur_IO_13)	floor=14;
	if(!Cur_IO_14)	floor=15;
	if(!Cur_IO_15)	floor=16;

	if(!Cur_IO_16)	floor=17;
	if(!Cur_IO_17)	floor=18;
	if(!Cur_IO_18)	floor=19;
	if(!Cur_IO_19)	floor=20;
	if(!Cur_IO_20)	floor=21;
	if(!Cur_IO_21)	floor=22;
	if(!Cur_IO_22)	floor=23;
	if(!Cur_IO_23)	floor=24;

	if(!Cur_IO_24)	floor=25;
	if(!Cur_IO_25)	floor=26;
	if(!Cur_IO_26)	floor=27;
	if(!Cur_IO_27)	floor=28;
	if(!Cur_IO_28)	floor=29;
	if(!Cur_IO_29)	floor=30;
	if(!Cur_IO_30)	floor=31;
	if(!Cur_IO_31)	floor=32;


	LATD=floor;

	return(1);
}


void	Timer_1msec(void)
{

    if(charter_IO_00 < 250)	charter_IO_00++;
    if(charter_IO_01 < 250)	charter_IO_01++;
    if(charter_IO_02 < 250)	charter_IO_02++;
    if(charter_IO_03 < 250)	charter_IO_03++;
    if(charter_IO_04 < 250)	charter_IO_04++;
    if(charter_IO_05 < 250)	charter_IO_05++;
    if(charter_IO_06 < 250)	charter_IO_06++;
    if(charter_IO_07 < 250)	charter_IO_07++;
    if(charter_IO_08 < 250)	charter_IO_08++;
    if(charter_IO_09 < 250)	charter_IO_09++;
    if(charter_IO_10 < 250)	charter_IO_10++;
    if(charter_IO_11 < 250)	charter_IO_11++;
    if(charter_IO_12 < 250)	charter_IO_12++;
    if(charter_IO_13 < 250)	charter_IO_13++;
    if(charter_IO_14 < 250)	charter_IO_14++;
    if(charter_IO_15 < 250)	charter_IO_15++;
    if(charter_IO_16 < 250)	charter_IO_16++;
    if(charter_IO_17 < 250)	charter_IO_17++;
    if(charter_IO_18 < 250)	charter_IO_18++;
    if(charter_IO_19 < 250)	charter_IO_19++;
    if(charter_IO_20 < 250)	charter_IO_20++;
    if(charter_IO_21 < 250)	charter_IO_21++;
    if(charter_IO_22 < 250)	charter_IO_22++;
    if(charter_IO_23 < 250)	charter_IO_23++;
    if(charter_IO_24 < 250)	charter_IO_24++;
    if(charter_IO_25 < 250)	charter_IO_25++;
    if(charter_IO_26 < 250)	charter_IO_26++;
    if(charter_IO_27 < 250)	charter_IO_27++;
    if(charter_IO_28 < 250)	charter_IO_28++;
    if(charter_IO_29 < 250)	charter_IO_29++;
    if(charter_IO_30 < 250)	charter_IO_30++;
    if(charter_IO_31 < 250)	charter_IO_31++;

}

#endif


