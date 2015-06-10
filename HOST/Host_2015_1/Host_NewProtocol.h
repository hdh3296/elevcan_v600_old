



#define	REQ_ACK					0x20

#define	READ_CMD				0x00
#define	WRITE_CMD				0x80

#define	BYTE_DEG				0x00
#define	BIT_DEG					0x40

#define	SRAM_AREA				0x00
#define	FLASH_AREA				0x10





#define	SRAM_BYTE_READ			(SRAM_AREA  | BYTE_DEG | READ_CMD)  
#define	SRAM_BYTE_WRITE			(SRAM_AREA  | BYTE_DEG | WRITE_CMD)  

#define	FLASH_BYTE_READ			(FLASH_AREA | BYTE_DEG | READ_CMD)  
#define	FLASH_BYTE_WRITE		(FLASH_AREA | BYTE_DEG | WRITE_CMD)  


#define	SRAM_BIT_READ			(SRAM_AREA  | BIT_DEG | READ_CMD)  
#define	SRAM_BIT_RWITE			(SRAM_AREA  | BIT_DEG | WRITE_CMD)  

#define	FLASH_BIT_READ			(FLASH_AREA | BIT_DEG | READ_CMD)  
#define	FLASH_BIT_WRITE			(FLASH_AREA | BIT_DEG | WRITE_CMD)  


//#define	M_BASE					0x0
//#define	VIRTUAL_RAM				0x0
//#define	VIRTUAL_RAM				0x100

#define	DATA_BLOCK_END			0x1000   



#define	COM_PORT_NO				0   
#define	COM_PORT_COM1			1   
#define	COM_PORT_COM2			2   
#define	COM_PORT_COM3			3   
#define	COM_PORT_CAN1			10   
#define	COM_PORT_CAN2			11   



extern	UserDataType	CommonRcvBuf[100];

extern	UserDataType	CommonThisRxBuf[10];

extern	unsigned int	CommonConnectPort;
extern	unsigned int	CommonConnectPortTime;
extern	unsigned int	CommonTmpSid;
extern	unsigned int	CommonTmpEidH;
extern	unsigned int	CommonTmpEidL;
extern	unsigned int	CommonTxThisPt;
extern	unsigned int	CommonTxCnt;
extern	unsigned int	CommonRxThisPt;
extern	unsigned int	CommonRxCnt;
extern	unsigned int	CommonRxGood;
extern	unsigned int	CommonRxSid;
extern	unsigned int	CommonRxDlc;
extern	unsigned long	CommonRxEid;


extern	unsigned int    __attribute__((section(".usercode")))  NewProtocol(void);
