/*
 * THE FOLLOWING FIRMWARE IS PROVIDED: (1) "AS IS" WITH NO WARRANTY; AND 
 * (2)TO ENABLE ACCESS TO CODING INFORMATION TO GUIDE AND FACILITATE CUSTOMER.
 * CONSEQUENTLY, SEMTECH SHALL NOT BE HELD LIABLE FOR ANY DIRECT, INDIRECT OR
 * CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE CONTENT
 * OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING INFORMATION
 * CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 * 
 * Copyright (C) SEMTECH S.A.
 */
/*! 
 * \file       sx1276-Hal.c
 * \brief      SX1276 Hardware Abstraction Layer
 *
 * \version    2.0.B2 
 * \date       Nov 21 2012
 * \author     Miguel Luis
 *
 * Last modified by Miguel Luis on Jun 19 2013
 */

#include    <pic18.h>

#include "platform.h"

#if defined( USE_SX1276_RADIO )

/////////#include "ioe.h"
#include "spi.h"
#include "sx1276-Hal.h"


#define RESET_PIN                                   LATD3
#define DIO0_PIN                                    RA0
#define DIO1_PIN                                    RA1
#define DIO2_PIN                                    RA2
#define DIO3_PIN                                    RA3
#define DIO4_PIN                                    RE0
#define DIO5_PIN                                    RE1

#define FEM_CTX_PIN                                 LATD4              //FEM_CTX_PIN
#define RFSW                                 		LATD5              //FEM_CTX_PIN

//uint32_t TickCounter=0;


/*
//  SX1276 RESET I/O definitions
#if defined( STM32F4XX ) || defined( STM32F2XX )
#define RESET_IOPORT                                GPIOG
#define RESET_PIN                                   GPIO_Pin_12
#else
#define RESET_IOPORT                                GPIOA
#define RESET_PIN                                   GPIO_Pin_1
#endif


//SX1276 SPI NSS I/O definitions
#if defined( STM32F4XX ) || defined( STM32F2XX )
#define NSS_IOPORT                                  GPIOA
#define NSS_PIN                                     GPIO_Pin_15
#else
#define NSS_IOPORT                                  GPIOA
#define NSS_PIN                                     GPIO_Pin_15
#endif


//SX1276 DIO pins  I/O definitions
#if defined( STM32F4XX ) || defined( STM32F2XX )
#define DIO0_IOPORT                                 GPIOG
#define DIO0_PIN                                    GPIO_Pin_13
#else
#define DIO0_IOPORT                                 GPIOA
#define DIO0_PIN                                    GPIO_Pin_0
#endif

#if defined( STM32F4XX ) || defined( STM32F2XX )
#define DIO1_IOPORT                                 GPIOB
#define DIO1_PIN                                    GPIO_Pin_8
#else
#define DIO1_IOPORT                                 GPIOB
#define DIO1_PIN                                    GPIO_Pin_0
#endif

#if defined( STM32F4XX ) || defined( STM32F2XX )
#define DIO2_IOPORT                                 GPIOA
#define DIO2_PIN                                    GPIO_Pin_2
#else
#define DIO2_IOPORT                                 GPIOC
#define DIO2_PIN                                    GPIO_Pin_5
#endif

#if defined( STM32F4XX ) || defined( STM32F2XX )
#define DIO3_IOPORT                                 
#define DIO3_PIN                                    RF_DIO3_PIN
#else
#define DIO3_IOPORT                                 
#define DIO3_PIN                                    RF_DIO3_PIN
#endif

#if defined( STM32F4XX ) || defined( STM32F2XX )
#define DIO4_IOPORT                                 
#define DIO4_PIN                                    RF_DIO4_PIN
#else
#define DIO4_IOPORT                                 
#define DIO4_PIN                                    RF_DIO4_PIN
#endif

#if defined( STM32F4XX ) || defined( STM32F2XX )
#define DIO5_IOPORT                                 
#define DIO5_PIN                                    RF_DIO5_PIN
#else
#define DIO5_IOPORT                                 
#define DIO5_PIN                                    RF_DIO5_PIN
#endif

#if defined( STM32F4XX ) || defined( STM32F2XX )
#define RXTX_IOPORT                                 
#define RXTX_PIN                                    FEM_CTX_PIN
#else
#define RXTX_IOPORT                                 
#define RXTX_PIN                                    FEM_CTX_PIN
#endif

*/


void SX1276InitIo( void )
{
	TRISD3=0;   // reset
	TRISD4=0;   // rxtx
	TRISD5=0;   // rxtx
	TRISA5=0;   // nss

	TRISA0=1;   // D00
	TRISA1=1;   // D01
	TRISA2=1;   // D02
	TRISA3=1;   // D03
	TRISE0=1;   // D04
	TRISE1=1;   // D05


	DIO0_PIN=1;
LATA0=1;

	DIO1_PIN=1;
	DIO2_PIN=1;
	DIO3_PIN=1;
	DIO4_PIN=1;
	DIO5_PIN=1;

	LATD4=0;
	LATD5=0;

TRISC1=0;
TRISC2=0;


/*
    GPIO_InitTypeDef GPIO_InitStructure;

#if defined( STM32F4XX ) || defined( STM32F2XX )
    RCC_AHB1PeriphClockCmd( RCC_AHB1Periph_GPIOA | RCC_AHB1Periph_GPIOB |
                            RCC_AHB1Periph_GPIOG, ENABLE );
#else
    RCC_APB2PeriphClockCmd( RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB |
                            RCC_APB2Periph_GPIOC | RCC_APB2Periph_AFIO, ENABLE );
#endif

#if defined( STM32F4XX ) || defined( STM32F2XX )
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;
#else
    GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
#endif
    
    // Configure NSS as output
    GPIO_WriteBit( NSS_IOPORT, NSS_PIN, Bit_SET );
    GPIO_InitStructure.GPIO_Pin = NSS_PIN;
    GPIO_Init( NSS_IOPORT, &GPIO_InitStructure );

    // Configure radio DIO as inputs
#if defined( STM32F4XX ) || defined( STM32F2XX )
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
#else
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
#endif

    // Configure DIO0
    GPIO_InitStructure.GPIO_Pin =  DIO0_PIN;
    GPIO_Init( DIO0_IOPORT, &GPIO_InitStructure );
    
    // Configure DIO1
    GPIO_InitStructure.GPIO_Pin =  DIO1_PIN;
    GPIO_Init( DIO1_IOPORT, &GPIO_InitStructure );
    
    // Configure DIO2
    GPIO_InitStructure.GPIO_Pin =  DIO2_PIN;
    GPIO_Init( DIO2_IOPORT, &GPIO_InitStructure );
    
    // REAMARK: DIO3/4/5 configured are connected to IO expander

    // Configure DIO3 as input
    
    // Configure DIO4 as input
    
    // Configure DIO5 as input
*/

}

void SX1276SetReset( uint8_t state )
{

/*
    GPIO_InitTypeDef GPIO_InitStructure;

    if( state == RADIO_RESET_ON )
    {
        // Set RESET pin to 0
        GPIO_WriteBit( RESET_IOPORT, RESET_PIN, Bit_RESET );

        // Configure RESET as output
#if defined( STM32F4XX ) || defined( STM32F2XX )
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
#else

        GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
#endif        
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_Pin = RESET_PIN;
        GPIO_Init( RESET_IOPORT, &GPIO_InitStructure );
    }
    else
    {
#if FPGA == 0    
        // Configure RESET as input
#if defined( STM32F4XX ) || defined( STM32F2XX )
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
#else
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
#endif        
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_Pin =  RESET_PIN;
        GPIO_Init( RESET_IOPORT, &GPIO_InitStructure );
#else
        GPIO_WriteBit( RESET_IOPORT, RESET_PIN, Bit_RESET );
#endif
    }
*/

    if( state == RADIO_RESET_ON )
    {
		RESET_PIN=0;


/*
        // Set RESET pin to 0
        GPIO_WriteBit( RESET_IOPORT, RESET_PIN, Bit_RESET );

        // Configure RESET as output
#if defined( STM32F4XX ) || defined( STM32F2XX )
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
        GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
#else

        GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;
#endif        
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_Pin = RESET_PIN;
        GPIO_Init( RESET_IOPORT, &GPIO_InitStructure );
*/

    }
    else
    {
		RESET_PIN=1;

    uint32_t startTick = GET_TICK_COUNT( );
    while( ( GET_TICK_COUNT( ) - startTick ) < TICK_RATE_MS( 10 ) );    

//		TickCounter


/*
#if FPGA == 0    
        // Configure RESET as input
#if defined( STM32F4XX ) || defined( STM32F2XX )
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
#else
        GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
#endif        
        GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
        GPIO_InitStructure.GPIO_Pin =  RESET_PIN;
        GPIO_Init( RESET_IOPORT, &GPIO_InitStructure );
#else
        GPIO_WriteBit( RESET_IOPORT, RESET_PIN, Bit_RESET );
#endif
*/
    }

}

void SX1276Write( uint8_t addr, uint8_t data )
{
    SX1276WriteBuffer( addr, &data, 1 );
}

void SX1276Read( uint8_t addr, uint8_t *data )
{
    SX1276ReadBuffer( addr, data, 1 );
}


void SX1276WriteBuffer( uint8_t addr, uint8_t *buffer, uint8_t size )
{

WriteSPI_ADDR_n(addr,buffer,size );

/*
    uint8_t i;

    for( i = 0; i < size; i++ ){
		WriteSPI_ADDR( (addr+i),buffer[i]);
	}	
*/

/*
    uint8_t i;
    //NSS = 0;
    GPIO_WriteBit( NSS_IOPORT, NSS_PIN, Bit_RESET );
	
    SpiInOut( addr | 0x80 );
    for( i = 0; i < size; i++ )
    {
        SpiInOut( buffer[i] );
    }

    //NSS = 1;
    GPIO_WriteBit( NSS_IOPORT, NSS_PIN, Bit_SET );
*/

}

void SX1276ReadBuffer( uint8_t addr, uint8_t *buffer, uint8_t size )
{

	ReadSPI_ADDR_n(addr,buffer,size );

/*
    uint8_t i;
    //NSS = 0;
    GPIO_WriteBit( NSS_IOPORT, NSS_PIN, Bit_RESET );

    SpiInOut( addr & 0x7F );

    for( i = 0; i < size; i++ )
    {
        buffer[i] = SpiInOut( 0 );
    }
    //NSS = 1;
    GPIO_WriteBit( NSS_IOPORT, NSS_PIN, Bit_SET );
*/

}





void SX1276WriteFifo( uint8_t *buffer, uint8_t size )
{
    SX1276WriteBuffer( 0, buffer, size );
}

void SX1276ReadFifo( uint8_t *buffer, uint8_t size )
{
    SX1276ReadBuffer( 0, buffer, size );
}

inline uint8_t SX1276ReadDio0( void )
{
	return(DIO0_PIN);
//    return GPIO_ReadInputDataBit( DIO0_IOPORT, DIO0_PIN );
}

inline uint8_t SX1276ReadDio1( void )
{
	return(DIO1_PIN);
//    return GPIO_ReadInputDataBit( DIO1_IOPORT, DIO1_PIN );
}

inline uint8_t SX1276ReadDio2( void )
{
	return(DIO2_PIN);
//    return GPIO_ReadInputDataBit( DIO2_IOPORT, DIO2_PIN );
}

inline uint8_t SX1276ReadDio3( void )
{
	return(DIO3_PIN);
//    return IoePinGet( RF_DIO3_PIN );
}

inline uint8_t SX1276ReadDio4( void )
{
	return(DIO4_PIN);
//    return IoePinGet( RF_DIO4_PIN );
}

inline uint8_t SX1276ReadDio5( void )
{
	return(DIO5_PIN);
//    return IoePinGet( RF_DIO5_PIN );
}


inline void SX1276WriteRxTx( uint8_t txEnable )
{
//#define FEM_CTX_PIN                                 LATD4              //FEM_CTX_PIN
//#define RFSW                                 		LATD5              //FEM_CTX_PIN

    if( txEnable != 0 )
    {

		FEM_CTX_PIN=1;
		RFSW=0;
		
//		FEM_CTX_PIN=1;

//        IoePinOn( FEM_CTX_PIN );
//        IoePinOff( FEM_CPS_PIN );
    }
    else
    {

		FEM_CTX_PIN=0;
		RFSW=1;


//		FEM_CTX_PIN=0;

//        IoePinOff( FEM_CTX_PIN );
//        IoePinOn( FEM_CPS_PIN );
    }
}


uint32_t GET_TICK_COUNT( void )
{
	return(TickCounter);
}



#endif // USE_SX1276_RADIO
