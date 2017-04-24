
/////////////////////////////////
/////////////////////////////////
//////memory 부족 으로 지움
/////////////////////////////////
/////////////////////////////////

/*
#ifndef	AUTO_LANDING_COMM


#include <p30fxxxx.h>

#include  "..\..\system_com\memory_map.h"
#include  "30f6010_io.h"            
#include  "host_io.h"            
#include  "iodef.h"
#include  "door.h"
#include  "com.h"
#include  "counter.h"
#include  "you_can1.h" 
#include  "you_can2.h" 
#include  "lader.h" 
#include  "default_setup.h" 
#include  "Host_NewProtocol.h" 





UserDataType	CommonRcvBuf[100];
UserDataType	CommonThisRxBuf[10];


unsigned int	CommonTmpSid=0;
unsigned int	CommonTmpEidH=0;
unsigned int	CommonTmpEidL=0;



unsigned int	CommonRxSid=0;
unsigned int	CommonRxDlc=0;
unsigned long	CommonRxEid=0;

unsigned int	CommonConnectPort=0;

unsigned int	CommonConnectPortTime=0;

unsigned int	CommonRxThisPt=0;
unsigned int	CommonRxCnt=0;
unsigned int	CommonRxGood=0;

unsigned int	CommonTxThisPt=0;
unsigned int	CommonTxCnt=0;

/////////////////////////////////
/////////////////////////////////
//////memory 부족 으로 지움
/////////////////////////////////
/////////////////////////////////


unsigned int  __attribute__((section(".usercode"))) CommonNewSoketChk(unsigned int thisport)
{
	if( (CommonConnectPort == COM_PORT_NO) || (CommonConnectPortTime > 5)){
		CommonConnectPort=thisport;
		CommonConnectPortTime=0;
		CommonRxThisPt=0;
		CommonRxCnt=0;
		CommonRxGood=0;
		return(1);
	}	
	else if(CommonConnectPort == thisport){
		return(1);
	}	
	else	return(0);
}


void  __attribute__((section(".usercode"))) CommonSetSidEid(void)
{

    CommonTmpSid=(unsigned int)cF_COMPANY;
    CommonTmpSid=(CommonTmpSid | (MyGroupAddr << 7));

    CommonTmpEidH=0;
	CommonTmpEidL=0;

#ifndef	MAX_EIGHT_CAR
	if(MyGroupAddr & 0x10)	CommonTmpEidH=(CommonTmpEidH | 0x0001);	
	if(MyGroupAddr & 0x20)	CommonTmpEidH=(CommonTmpEidH | 0x0002);


    if(MyLocalAddr & 0x01)   CommonTmpEidL=(CommonTmpEidL | 0x4000);
    if(MyLocalAddr & 0x02)   CommonTmpEidL=(CommonTmpEidL | 0x8000);
#else
	if(MyGroupAddr & 0x10)	CommonTmpEidH=(CommonTmpEidH | 0x0002);
	
    if(MyLocalAddr & 0x01)   CommonTmpEidL=(CommonTmpEidL | 0x4000);
    if(MyLocalAddr & 0x02)   CommonTmpEidL=(CommonTmpEidL | 0x8000);
    if(MyLocalAddr & 0x04)   CommonTmpEidH=(CommonTmpEidH | 0x0001);
#endif

	CommonTmpEidL = (CommonTmpEidL | I_AM_MASTER); //master set
	
}


LocalType __attribute__((section(".usercode"))) CommonCmdSort(void)
{    

	unsigned int block_pt,FlashSaveOk,tmp_flash_adr;
	unsigned char i,k,base_mem,data_nm,ThisCmd,ThisBlock;
	unsigned char tmpbit;
	unsigned char tmpnm,offsef_bit_Adr,tmp_max_adr;

	
    ThisCmd=(CommonRcvBuf[0] & 0xf0);
	ThisBlock=(CommonRcvBuf[0] & 0x0f);
	ThisBlock=(ThisBlock << 8);
	base_mem=(CommonRcvBuf[2] | ThisBlock);

	if(CommonRcvBuf[0] & BIT_DEG){
		data_nm =CommonRcvBuf[4];
		tmpnm= (CommonRcvBuf[3]);
		tmpnm= (tmpnm-1);
		offsef_bit_Adr=(tmpnm/8);
		tmpnm=(tmpnm % 8);
		tmpbit=0x01;
		tmpbit=(tmpbit << tmpnm);
		base_mem=(base_mem + offsef_bit_Adr);

		tmp_max_adr=(tmpnm + (data_nm-1));
		tmp_max_adr=(tmp_max_adr/8); 
	}
	else	data_nm =CommonRcvBuf[3];


    switch(ThisCmd){
        case    SRAM_BYTE_READ:
			for(i=0;i<data_nm;i++){
				CommonRcvBuf[4+i]=sRamDArry[(base_mem + i)];
			}

			CommonRcvBuf[1]= CommonRcvBuf[3]+2;
			CommonTxThisPt=0;
			CommonTxCnt=CommonRcvBuf[1]+2;
			CommonRxGood=1;
            break;
		case	FLASH_BYTE_READ:	
			for(i=0;i<data_nm;i++){
				CommonRcvBuf[4+i]=cF_FLRDSPCH( (unsigned long)(base_mem + i));
			}

			CommonRcvBuf[1]= CommonRcvBuf[3]+2;
			CommonTxThisPt=0;
			CommonTxCnt=CommonRcvBuf[1]+2;
			CommonRxGood=1;
            break;
        case    SRAM_BYTE_WRITE:

			for(i=0;i<data_nm;i++){
				ShadowsRamDArry[(base_mem + i)]=CommonRcvBuf[4+i];
			}
									
			CommonTxThisPt=0;
			CommonTxCnt=CommonRcvBuf[1]+2;
			CommonRxGood=1;


			if(ShadowsRamDArry[mCrtExtMoveFlr] != 0){
				if(sRamDArry[mCrtExtMoveFlr] != ShadowsRamDArry[mCrtExtMoveFlr]){
					sRamDArry[mCrtExtMoveFlr]=ShadowsRamDArry[mCrtExtMoveFlr];
					ShadowsRamDArry[mCrtExtMoveFlr]=0;
					ExtKeyCnt=3;
				} 
			}


			if( (ShadowsRamDArry[Year] != 0) || (ShadowsRamDArry[Month] != 0) || (ShadowsRamDArry[Day] != 0) || (ShadowsRamDArry[Hour] != 0) || (ShadowsRamDArry[Minuate] != 0) || (ShadowsRamDArry[sec] != 0)) {
					sRamDArry[Year]		=ShadowsRamDArry[Year];
					sRamDArry[Month]	=ShadowsRamDArry[Month];
					sRamDArry[Day]		=ShadowsRamDArry[Day];
					sRamDArry[Hour]		=ShadowsRamDArry[Hour];
					sRamDArry[Minuate]	=ShadowsRamDArry[Minuate];
					sRamDArry[sec]		=ShadowsRamDArry[sec];
                	Initialize_DS1302();
					ShadowsRamDArry[Year]=0;
					ShadowsRamDArry[Month]=0;
					ShadowsRamDArry[Day]=0;
					ShadowsRamDArry[Hour]=0;
					ShadowsRamDArry[Minuate]=0;
					ShadowsRamDArry[sec]=0;
			}
            break;
        case    FLASH_BYTE_WRITE:
			if(bAuto)			return(0);
			if(data_nm > 64)	return(0);	
				
			i=(base_mem % 64);
			tmp_flash_adr=i;
			if( (i + (data_nm-1)) > 63)	return(0);
 

			FlashSaveOk=0;
			block_pt=(base_mem/64);
			block_pt=(block_pt * 64);
            GetFlashDataToBufRam(block_pt);

			for(i=0;i<data_nm;i++){
				if(b_LdTmpBufRam((unsigned long)(tmp_flash_adr)) != CommonRcvBuf[4+i]){
    				b_LdTmpBufRam((unsigned long)(tmp_flash_adr)) = CommonRcvBuf[4+i];
					FlashSaveOk=1;
				}
				tmp_flash_adr++;
			}				

			if(FlashSaveOk==1){
				SaveVerify = 0x55;
	   			flash_write_DspChar(block_pt);
				SaveVerify = 0x0;
			}

			for(i=0;i<data_nm;i++){
				CommonRcvBuf[4+i]=cF_FLRDSPCH( (unsigned long)(base_mem + i));
			}

			CommonTxThisPt=0;
			CommonTxCnt=CommonRcvBuf[1]+2;
			CommonRxGood=1;

            break;


//////////////////////////////////////////////////////
        case    SRAM_BIT_RWITE:

			for(i=0;i<data_nm;i++){				
				if(CommonRcvBuf[5+i]==1){
					ShadowsRamDArry[base_mem]=(ShadowsRamDArry[base_mem] | tmpbit);
				}
				else if(CommonRcvBuf[5+i]==0){
					ShadowsRamDArry[base_mem]=(ShadowsRamDArry[base_mem] & (~tmpbit));
				}
				else{
					if(ShadowsRamDArry[base_mem] & tmpbit)	CommonRcvBuf[5+i]=1;
					else									CommonRcvBuf[5+i]=0;	
				}

				if(tmpbit >= 0x80){
					tmpbit=0x01;
					base_mem++;
				}				
				else	tmpbit=(tmpbit << 1);
			}

			CommonTxThisPt=0;
			CommonTxCnt=CommonRcvBuf[1]+2;
			CommonRxGood=1;
            break;
        case    FLASH_BIT_WRITE:
			if(bAuto)				return(0);
			if(data_nm==0)			return(0);
				
			i=(base_mem%64);
			tmp_flash_adr=i;
			if( (i + tmp_max_adr) > 63)	return(0);				

			block_pt=(base_mem/64);
			block_pt=(block_pt * 64);
		    GetFlashDataToBufRam(block_pt);
	
			FlashSaveOk=0;	
		
			for(i=0;i<data_nm;i++){				
				if(CommonRcvBuf[5+i]==1){
					if( !bitChk_FLRDSPCH((tmp_flash_adr),tmpnm)){
		        		bit_LdTmpBufRamSet((tmp_flash_adr),tmpnm);
						FlashSaveOk=1;	
					}
				}
				else if(CommonRcvBuf[5+i]==0){
					if(bitChk_FLRDSPCH((tmp_flash_adr),tmpnm)){
			        	bit_LdTmpBufRamReset((tmp_flash_adr),tmpnm);
						FlashSaveOk=1;	
					}
				}
				else{
					if(bitChk_FLRDSPCH((tmp_flash_adr),tmpnm))	CommonRcvBuf[5+i]=1;	
					else										CommonRcvBuf[5+i]=0;
				}


				if(tmpnm >= 0x8){
					tmpnm=0x01;
					tmp_flash_adr++;
				}				
				else	tmpnm++;	
			}

			
			if(FlashSaveOk==1){	
				SaveVerify = 0x55;
			    flash_write_DspChar(block_pt);
				SaveVerify = 0x0;
			}

			CommonTxThisPt=0;
			CommonTxCnt=CommonRcvBuf[1]+2;
			CommonRxGood=1;

            break;
///////////////////////////////
        case    SRAM_BIT_READ:
			for(i=0;i<data_nm;i++){
				if(sRamDArry[base_mem] & tmpbit)	CommonRcvBuf[5+i]=1;	
				else								CommonRcvBuf[5+i]=0;	

				if(tmpbit >= 0x80){
					tmpbit=0x01;
					base_mem++;
				}				
				else	tmpbit=(tmpbit << 1);
			}

			CommonRcvBuf[1]= CommonRcvBuf[1] + CommonRcvBuf[4];
			CommonTxThisPt=0;
			CommonTxCnt=CommonRcvBuf[1] + 2;
			CommonRxGood=1;
            break;
        case    FLASH_BIT_READ:
			k = cF_FLRDSPCH((unsigned long)(base_mem));
			for(i=0;i<data_nm;i++){
				if(k & tmpbit){		
					CommonRcvBuf[5+i]=1;
				}	
				else{
					CommonRcvBuf[5+i]=0;	
				}
				if(tmpbit >= 0x80){
					tmpbit=0x01;
					base_mem++;
					k = cF_FLRDSPCH((unsigned long)(base_mem));
				}				
				else	tmpbit=(tmpbit << 1);
			}

			CommonRcvBuf[1]= CommonRcvBuf[1] + CommonRcvBuf[4];
			CommonTxThisPt=0;
			CommonTxCnt=CommonRcvBuf[1] + 2;
			CommonRxGood=1;
            break;
//////////////////
        default:
			CommonRxGood=0;
			break;
    }        

	CommonSetSidEid();
	CommonRcvBuf[0]= (CommonRcvBuf[0] | REQ_ACK);

    return(0);
}



LocalType __attribute__((section(".usercode"))) CommonDataCheck(void)
{

	if(CommonRcvBuf[3] == 0){	
		// if bit==0  or  r/w nm=0  return(0);
		CommonRxThisPt=0;
		CommonRxCnt=0;
		return(0);
	}


	if(CommonRcvBuf[0] & BIT_DEG){
		if(CommonRcvBuf[4] == 0){
			// bit nm == 0 return(0);
			CommonRxThisPt=0;
			CommonRxCnt=0;
			return(0);
		}
	}
    

	if( (CommonRxCnt-2) == CommonRcvBuf[1]){
		if(CommonRcvBuf[0] & WRITE_CMD){
			if(CommonRcvBuf[0] & BIT_DEG){
				if( (CommonRxCnt-4) == (CommonRcvBuf[4] + 1)){
					CommonCmdSort();
				}
			}
			else{
				if( (CommonRxCnt-4) == CommonRcvBuf[3]){
					CommonCmdSort();
				}
			}			
		}
		else{
			CommonCmdSort();
		}
	}	
	
	CommonRxThisPt=0;
	CommonRxCnt=0;

    return(0);
}


LocalType __attribute__((section(".usercode"))) CommonReceiveDataSave(unsigned int thisport)
{
    unsigned int  i=0;

//	CommonSaveReceiveData();

	CommonConnectPort=thisport;
	CommonConnectPortTime=0;

	CommonRxThisPt=(unsigned int)((CommonRxEid>>8) & 0x0f);
	CommonRxThisPt=(CommonRxThisPt * 8);

	if(CommonRxThisPt==0)	CommonRxCnt=0;	

	for(i=0;i<CommonRxDlc;i++){
		CommonRcvBuf[CommonRxThisPt+i]=CommonThisRxBuf[i];
		CommonRxCnt++; 
	}

	if(DATA_BLOCK_END  & CommonRxEid){
		CommonDataCheck();
	}

	return(0);
}

#endif
 
*/


