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
 * \file       platform.h
 * \brief        
 *
 * \version    1.0
 * \date       Nov 21 2012
 * \author     Miguel Luis
 */



#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#ifndef __GNUC__
#define inline
#endif


#define USE_SX1276_RADIO	1	// sangyong define


#include <stdint.h>
#include <stdbool.h> 


/*
#define	true		1
#define	false		0
    


#define	int8_t 		char
#define	int32_t 	long

#define	uint8_t 	unsigned char
#define	uint16_t	unsigned int
#define	uint32_t 	unsigned long


#define	bool		unsigned char
*/



//extern	uint8_t rxtxbuff[50];

//sangyong
//#define	TickCounter	100		
//#define	ms	100		
//sangyong


#endif // __PLATFORM_H__


/*
#ifndef __PLATFORM_H__
#define __PLATFORM_H__

#ifndef __GNUC__
#define inline
#endif





//#define Bleeper                                     3
//#define SX1243ska                                   2
//#define SX12xxEiger                                 1
//#define SX12000DVK                                  0


//#define PLATFORM                                    SX12xxEiger

#if( PLATFORM == SX12xxEiger )
//#define USE_SX1232_RADIO
#define USE_SX1272_RADIO
//#define USE_SX1276_RADIO
//#define USE_SX1243_RADIO

#ifdef USE_SX1276_RADIO
#define MODULE_SX1276RF1IAS                         0
#define MODULE_SX1276RF1JAS                         1
#define MODULE_SX1276RF1KAS                         0
#endif

    #include "sx12xxEiger/sx12xxEiger.h"
    #define USE_UART                                0

#elif( PLATFORM == SX12000DVK )
//#define USE_SX1232_RADIO
#define USE_SX1272_RADIO
//#define USE_SX1276_RADIO
//#define USE_SX1243_RADIO

    #include "sx1200dvk/sx1200dvk.h"

#elif( PLATFORM == SX1243ska )

#elif( PLATFORM == Bleeper )
    #define USE_SX1272_RADIO
    
    #include "bleeper/bleeper.h"
    #define USE_UART                                0

#else
    #error "Missing define: Platform (ie. SX12xxEiger)"
#endif



#endif // __PLATFORM_H__
*/