
#include <p30fxxxx.h>
#include  "..\..\system_com\memory_map.h"

#include  "30f6010_io.h"            
#include  "host_io.h"            
#include  "iodef.h"
#include  "door.h"
//#include  "eeprom.h"
#include  "com.h"
#include  "counter.h"
#include  "you_can1.h" 
#include  "you_can2.h" 
#include  "lader.h" 
#include  "default_setup.h" 



#define F_LINE_START_PT     5
#define S_LINE_START_PT     22
#define PULL_DOWN_MENU      100
#define LEFT_MENU_MAX       200


#define FLASH_WR_BLOCK      64	//flash max write block == 64 byte
#define BACKUP_MAX_BLOCK    80  //32
#define BACKUP_COM_BLK      16  //16 byte hex --> ascii 32 byte
#define BACKUP_PER_BLK      4   //16 byte hex --> ascii 32 byte




UserDataType	SrcAdrBlk;
UserDataType	LoaderChk;


void    __attribute__((section(".usercode"))) DataLoadSBuf(void)
{
	unsigned int  i,j,k;

	i=((SrcAdrBlk / BACKUP_PER_BLK) * FLASH_WR_BLOCK); 	
    GetFlashDataToBufRam(i);   											//block read(0-7)


	i=(SrcAdrBlk % BACKUP_PER_BLK) * BACKUP_COM_BLK;    				//pointer search in block
    
	for(j=0;j<BACKUP_COM_BLK;j++){										//16 byte load(ascii == 32 byte)
		k=(j * 2);
		src  = (unsigned char)(b_LdTmpBufRam((unsigned long)(i+j)));    // hex to ascii trans
		HextoASCIIByte();
		
	    RxBuffer2[5+k]  = firstdata;
	    RxBuffer2[6+k]  = seconddata;
	}
	k=(j * 2);

    RxBuffer2[5+k]  = ETX;
    RxBuffer2[6+k]  = 0;
}



void    __attribute__((section(".usercode"))) IntegerToString(unsigned int i)
{
	i=(i%100);

	RxBuffer2[3] = (i/10)  + '0';                     
	RxBuffer2[4] = (i%10)  + '0';                     
}


void    __attribute__((section(".usercode"))) DataDumpToLoader(void)
{
	if((SrcAdrBlk < BACKUP_MAX_BLOCK) && (LoaderChk < 20) ){    // area check and tim out check
	    RxBuffer2[0]  = ACK;
	    RxBuffer2[1]  = 'W';
	    RxBuffer2[2]  = 'F';
		IntegerToString(SrcAdrBlk);
		DataLoadSBuf();
		LoaderChk++;
	}
	else	bExportData=0;	
}




void    __attribute__((section(".usercode"))) ReceiveDataLoad(void)
{
	unsigned int i,j,k;

	j=((SrcAdrBlk % BACKUP_PER_BLK) * BACKUP_COM_BLK);						//pointer search in block

	for(i=0;i<BACKUP_COM_BLK;i++){
		k=(i*2);
		src=b_LdTmpBufRam((unsigned long)(j+i));
		HextoASCIIByte();

		if( (firstdata  < '0') || (firstdata  > 'F'))	firstdata ='0'; 		
		if( (seconddata < '0') || (seconddata > 'F'))	seconddata='0'; 		
			
		RxBuffer2[5+k]=firstdata;
		RxBuffer2[6+k]=seconddata;
	}		
	
    RxBuffer2[37]  = ETX;
    RxBuffer2[38]  = 0;
}



void    __attribute__((section(".usercode"))) DataReqToLoader(void)
{
	unsigned int i,j,k;

	if((SrcAdrBlk < BACKUP_MAX_BLOCK) && (LoaderChk < 20) ){    // area check and tim out check

	    RxBuffer2[0]  = ACK;
	    RxBuffer2[1]  = 'R';
	    RxBuffer2[2]  = 'F';
		IntegerToString(SrcAdrBlk);
		ReceiveDataLoad();	
		LoaderChk++;
	}
	else	bExportData=0;	
}





unsigned int  __attribute__((section(".usercode"))) ReceiveCmp(void)
{
	unsigned int i,j,k,good;

	good=1;

	i=(SrcAdrBlk % BACKUP_PER_BLK) * BACKUP_COM_BLK;  						//pointer search in block
    
	for(j=0;j<BACKUP_COM_BLK;j++){
		k=(j *2);
		src  = (unsigned char)(b_LdTmpBufRam((unsigned long)(i + j)));
		HextoASCIIByte();
		
	    if(RxBuffer2[5+k]  != firstdata)  good=0;
	    if(RxBuffer2[6+k]  != seconddata) good=0;	
	}

	if(RxBuffer2[0]  != ACK)	good=0;	
	if(RxBuffer2[1]  != 'w')	good=0;
	if(RxBuffer2[2]  != 'F')	good=0;

	return(good);
}


void  __attribute__((section(".usercode"))) TmpSave(void)
{
	unsigned int i,j,k,l,pt;

	i=(unsigned int)RxBuffer2[3];
    i=ASCTOHEX(i);

	j=(unsigned int)RxBuffer2[4];
    j=ASCTOHEX(j);


	SrcAdrBlk=((i * 10) + j);

	if(SrcAdrBlk  > BACKUP_MAX_BLOCK)		SrcAdrBlk=0;

/*
	if(SrcAdrBlk == BACKUP_MAX_BLOCK){
		bImportData=0;
	}
*/

	if( ((SrcAdrBlk % BACKUP_PER_BLK) == 0) && ((SrcAdrBlk/BACKUP_PER_BLK) > 0)){
		i = ((SrcAdrBlk / BACKUP_PER_BLK) -1);
		i= (i * FLASH_WR_BLOCK);  
    	flash_write_DspChar(i);
	}

	if(SrcAdrBlk == BACKUP_MAX_BLOCK){
	   	GetFlashDataToBufRam(F_BLOCK2);
	    b_LdTmpBufRam(F_Ver0)           = VERSION_0;
	    b_LdTmpBufRam(F_Ver1)           = VERSION_1;
	    b_LdTmpBufRam(F_Ver2)           = VERSION_2;	
	    flash_write_DspChar(F_BLOCK2);

        CaluDecreasePulse_spd3();

		bImportData=0;
    	SWR=1;
    	asm("RESET");
	}
			

	pt=( (SrcAdrBlk % BACKUP_PER_BLK) * BACKUP_COM_BLK);

	for(i=0;i<BACKUP_COM_BLK;i++){
		l=(i*2);
		k=(unsigned int)RxBuffer2[5+l];
	    k=ASCTOHEX(k);
		k=((k << 4) & 0xf0);
	
		j=(unsigned int)RxBuffer2[6+l];
	    j=ASCTOHEX(j);
		j=(k | j);

		b_LdTmpBufRam((unsigned long)(pt+i))=(unsigned char)(j);
	}
}




void  __attribute__((section(".usercode"))) NewLoaderChk(void)
{
	if(bExportData){
		if(ReceiveCmp()){
			SrcAdrBlk++;
		}

		LadderBuf[C_SAVE_DATA+0]='N';      
		LoaderChk=0;
		LadderKeyTime=0;
	}

	else if(bImportData){
		if(!bAuto && IN_AUTO){
			if((RxBuffer2[0]  == ACK) && (RxBuffer2[1]  == 'r')	&& (RxBuffer2[2]  == 'F')){
				SaveVerify=0x55;
				TmpSave();
				SaveVerify=0;
				RxBuffer2[0]  = 'n';
	 			RxBuffer2[1]  = 'n';
				RxBuffer2[2]  = 'n';
			}
		
			LadderBuf[C_SAVE_DATA+0]='N';      
			LoaderChk=0;
			LadderKeyTime=0;
		}
		else{
			SaveVerify=0x0;
			bImportData=0;	
		}
	}
}




void    __attribute__((section(".usercode"))) LdDataTx(void)
{
    unsigned int i;
         
    RxBuffer2[0]  = ACK;
    RxBuffer2[1]  = cF_COMPANY;
	RxBuffer2[36] = ' ';                     
	RxBuffer2[37] = ' ';                     
	RxBuffer2[38] = ' ';                     
	RxBuffer2[39] = ' ';                     
	RxBuffer2[40] = ' ';                     

	RxBuffer2[41]=ETX;
	RxBuffer2[42]=0;


    for(i=0;i<36;i++){
        if(New485Ladder[i+0] > 0x80)		RxBuffer2[2+i]=New485Ladder[i+0] - 0x80;
        else if(New485Ladder[i+0] < 0x20)	RxBuffer2[2+i]=' ';
        else                            	RxBuffer2[2+i]=New485Ladder[i+0];

        if(New485Ladder[i+0] == 0)    	    RxBuffer2[2+i]=New485Ladder[i+0]=' ';
    }


	if(bExportData){
		DataDumpToLoader();
	}
	else if(bImportData){
		DataReqToLoader();
	}

	Serial2();
}
