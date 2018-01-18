/*================================*/
/*      2000, 08, 20              */
/*         Ver 0.1                */
/*================================*/

#include    <pic18.h>

#include    "iodef.h"
#include    "setup.h"

/*===========================================
   Alpa-Numeric display
=============================================*/
                    
extern      bit     UpMove;
extern      bit     DnMove;
extern      bit     FDsp;

//unsigned    char    DspModel;

//unsigned    char    DspBuf[16];   
unsigned    char    DspBuf[22];   
unsigned    char    shiftDataBuf[16];

unsigned    char    Timexyou;


#ifdef  __DSP_DOT  
// 러시아 russia
const unsigned char  RussiaFont[]=
   {
   0x3E,0x51,0x49,0x45,0x3E, // ;0  
   0x00,0x42,0x7F,0x40,0x00, // ;1  
   0x42,0x61,0x51,0x49,0x46, // ;2  
   0x21,0x41,0x45,0x4B,0x31, // ;3  
   0x18,0x14,0x12,0x7F,0x10, // ;4  
   0x27,0x45,0x45,0x45,0x39, // ;5  
   0x3C,0x4A,0x49,0x49,0x30, // ;6  
   0x01,0x71,0x09,0x05,0x03, // ;7  
   0x36,0x49,0x49,0x49,0x36, // ;8  
   0x06,0x49,0x49,0x29,0x1E, // ;9  
   0x04,0x02,0x7F,0x02,0x04, // ;/\ 10 
   0x10,0x20,0x7F,0x20,0x10, // ;\/ 11
   0x08,0x14,0x22,0x41,0x00, // ;<  12
   0x00,0x00,0x00,0x00,0x00, // ;=  13       
   0x00,0x41,0x22,0x14,0x08, // ;>  14
   0x02,0x01,0x51,0x09,0x06, // ;?  15
   0x32,0x49,0x79,0x41,0x3E, // ;@  16
   0x7E,0x11,0x11,0x11,0x7E, // ;A  17	Letter-А
   0x7F,0x49,0x49,0x49,0x36, // ;B  18	Letter-В
   0x3E,0x41,0x41,0x41,0x41, // ;C  19	Letter-С
   0x7F,0x48,0x30,0x00,0x7F, // ;D  20	Letter-Ы
   0x7F,0x49,0x49,0x49,0x49, // ;E  21	Letter-Е
   0x7F,0x09,0x09,0x09,0x01, // ;F  22
   0x4F,0x48,0x48,0x48,0x3F, // ;G  23	Letter-У
   0x7F,0x08,0x08,0x08,0x7F, // ;H  24	Letter-Н
   0x00,0x41,0x7F,0x41,0x00, // ;I  25
   0x20,0x40,0x41,0x3F,0x01, // ;J  26
   0x7F,0x08,0x14,0x22,0x41, // ;K  27	Letter-К
   0x7F,0x01,0x01,0x01,0x01, // ;L  28	Letter-Г
   0x41,0x49,0x49,0x55,0x22, // ;M  29	Letter-З
   0x7F,0x20,0x10,0x08,0x7F, // ;N  30	Letter-И
   0x3E,0x41,0x41,0x41,0x3E, // ;O  31	Letter-О
   0x7F,0x09,0x09,0x09,0x06, // ;P  32	Letter-Р
   0x3E,0x41,0x51,0x21,0x5E, // ;Q  33
   0x46,0x29,0x19,0x09,0x7F, // ;R  34	Letter-Я
   0x46,0x49,0x49,0x49,0x31, // ;S  35
   0x01,0x01,0x7F,0x01,0x01, // ;T  36	Letter-T
   0x7F,0x01,0x01,0x01,0x7F, // ;U  37	Letter-П
   0x7C,0x02,0x01,0x02,0x7C, // ;V  38	Letter-Л
   0x7F,0x20,0x11,0x08,0x7F, // ;W  39	Letter-Й
   0x63,0x14,0x7F,0x14,0x63, // ;X  40	Letter-Ж
   0x07,0x08,0x08,0x08,0x7F, // ;Y  41	Letter-Ч
   0x61,0x51,0x49,0x45,0x43, // ;Z  42
   };

/* 2018.01.08 원본 폰트
const unsigned char  RussiaFont[]=
   {
   0x3E,0x51,0x49,0x45,0x3E, // ;0  
   0x00,0x42,0x7F,0x40,0x00, // ;1  
   0x42,0x61,0x51,0x49,0x46, // ;2  
   0x21,0x41,0x45,0x4B,0x31, // ;3  
   0x18,0x14,0x12,0x7F,0x10, // ;4  
   0x27,0x45,0x45,0x45,0x39, // ;5  
   0x3C,0x4A,0x49,0x49,0x30, // ;6  
   0x01,0x71,0x09,0x05,0x03, // ;7  
   0x36,0x49,0x49,0x49,0x36, // ;8  
   0x06,0x49,0x49,0x29,0x1E, // ;9  
   0x04,0x02,0x7F,0x02,0x04, // ;/\ 10 
   0x10,0x20,0x7F,0x20,0x10, // ;\/ 11
   0x08,0x14,0x22,0x41,0x00, // ;<  12
//   0x14,0x14,0x14,0x14,0x14, // ;=  13       
   0x00,0x00,0x00,0x00,0x00, // ;=  13       
   0x00,0x41,0x22,0x14,0x08, // ;>  14
   0x02,0x01,0x51,0x09,0x06, // ;?  15
   0x32,0x49,0x79,0x41,0x3E, // ;@  16
   0x7E,0x11,0x11,0x11,0x7E, // ;A  17
//   0x00,0x08,0x08,0x08,0x08, // ;B  18
   0x7F,0x49,0x49,0x49,0x36, // ;B  18
   0x3E,0x41,0x41,0x41,0x22, // ;C  19
   0x7F,0x41,0x41,0x22,0x1C, // ;D  20
   0x7F,0x49,0x49,0x49,0x41, // ;E  21
   0x7F,0x09,0x09,0x09,0x01, // ;F  22
   0x3E,0x41,0x49,0x49,0x7A, // ;G  23
   0x7F,0x08,0x08,0x08,0x7F, // ;H  24
   0x00,0x41,0x7F,0x41,0x00, // ;I  25
   0x20,0x40,0x41,0x3F,0x01, // ;J  26
   0x7F,0x08,0x14,0x22,0x41, // ;K  27
   0x7F,0x40,0x40,0x40,0x40, // ;L  28
   0x7F,0x02,0x0C,0x02,0x7F, // ;M  29
   0x7F,0x04,0x08,0x10,0x7F, // ;N  30
   0x3E,0x41,0x41,0x41,0x3E, // ;O  31
   0x7F,0x09,0x09,0x09,0x06, // ;P  32
   0x3E,0x41,0x51,0x21,0x5E, // ;Q  33
   0x7F,0x09,0x19,0x29,0x46, // ;R  34
   0x46,0x49,0x49,0x49,0x31, // ;S  35
   0x01,0x01,0x7F,0x01,0x01, // ;T  36
   0x3F,0x40,0x40,0x40,0x3F, // ;U  37
   0x1F,0x20,0x40,0x20,0x1F, // ;V  38
   0x3F,0x40,0x38,0x40,0x3F, // ;W  39
   0x63,0x14,0x08,0x14,0x63, // ;X  40
   0x07,0x08,0x70,0x08,0x07, // ;Y  41
   0x61,0x51,0x49,0x45,0x43, // ;Z  42
   };
*/

/*
   0x3E,0x51,0x49,0x45,0x3E,    
   0x00,0x42,0x7F,0x40,0x00,    
   0x42,0x61,0x51,0x49,0x46,    
   0x21,0x41,0x45,0x4B,0x31,    
   0x18,0x14,0x12,0x7F,0x10,    
   0x27,0x45,0x45,0x45,0x39,    
   0x3C,0x4A,0x49,0x49,0x30,    
   0x01,0x71,0x09,0x05,0x03,    
   0x36,0x49,0x49,0x49,0x36,    
   0x06,0x49,0x49,0x29,0x1E,    
   0x7F,0x49,0x49,0x49,0x36,    
   0x7F,0x09,0x09,0x09,0x01,    
   0x3E,0x41,0x49,0x49,0x7A,    
   0x7F,0x40,0x40,0x40,0x40,       
   0x08,0x04,0x7E,0x04,0x08,    
   0x10,0x20,0x7E,0x20,0x10    
   };
*/   





void EngDisplay(unsigned char y, unsigned char CodeData)
{
   unsigned char offset;
   unsigned char temp;
   offset = (unsigned char)(CodeData * 5);
   for(temp=0;temp<5;temp++) {
         DspBuf[y+temp]=RussiaFont[offset+temp]; 
   }
}



void string_load_ram(unsigned char y,unsigned char floor)
{

   unsigned char Code;

   if(floor>=128){
      y=0;
      Code=18;
      EngDisplay(y,Code);
            
      y=6;
      Code=floor-128;
      EngDisplay(y,Code);
       
      DspBuf[5]=0x0;                  
   }
   
   else if(floor>=10){
      y=0;
      Code=floor/10;
      EngDisplay(y,Code);      
      
      y=6;
      Code=floor%10;

      EngDisplay(y,Code);       
      DspBuf[5]=0x0;                  
   }
   
   else{
		for(Code=0;Code<11;Code++){
			DspBuf[Code]=0x0;
		}	

//      if(DspModel == 0) y=3;
//      else           	y=6;

      if(bHibHpiSel == 0) 	y=3;
      else           	y=6;

      
      Code=floor;
      
      EngDisplay(y,Code);         
   }
	

   if(UpMove){
      y=11;
      EngDisplay(y,10);      
   }
   else if(DnMove){
      y=11;
      EngDisplay(y,11);      
   }
   else{
      DspBuf[11]=0x0; 
      DspBuf[12]=0x0; 
      DspBuf[13]=0x0; 
      DspBuf[14]=0x0; 
      DspBuf[15]=0x0; 
   }
}



void Floor_Char_load(unsigned char y,unsigned char f_floor,unsigned char s_floor)
{
   	unsigned char Code;
   
   	Code=f_floor-48;

   	if(Code != 0){
		y=0;
		EngDisplay(y,Code);            
		y=6;
		Code=s_floor-48;
		EngDisplay(y,Code);       
		DspBuf[5]=0x0;                  
   	}   
   	else{   
		for(Code=0;Code<11;Code++){
			DspBuf[Code]=0x0;
		}	

		Code=s_floor-48;
		if(bHibHpiSel == 0) 	y=3;
		else           			y=6;				
		EngDisplay(y,Code);
	}






	for(Code=11;Code<22;Code++){
		DspBuf[Code]=0x0;
	}	

	Code=0;



   if(UpMove){
      y=11+Code;
      EngDisplay(y,10);      
   }
   else if(DnMove){
      y=11+Code;
      EngDisplay(y,11);      
   }
   
}





void  SetupDisplay(unsigned char ft,unsigned char sd)
{
   unsigned char i;

   if(FDsp){   
      for(i=0;i<=15;i++){
         DspBuf[i]=0x0;
      }   

      if(ft<0xff)    string_load_ram(0,ft);            
      if(sd<0xff)    EngDisplay(11,sd);    
           
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




void Dsp_Char_load(unsigned char Cdata,unsigned char *ptx)
{

   unsigned char i;

   if(Cdata>=0x30){
		Cdata=(Cdata - 0x30);
		Cdata=(Cdata * 5);
		for(i=0;i<5;i++){
			*(ptx+i)=RussiaFont[Cdata+i];		
		}		
	}
	else{
		Cdata=(Cdata * 5);
		for(i=0;i<5;i++){
			*(ptx+i)=RussiaFont[Cdata+i];		
		}		
	}
}


#endif

