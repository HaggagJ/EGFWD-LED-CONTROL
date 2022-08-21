 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Dio Driver
 *
 ******************************************************************************/

#ifndef DIO_H
#define DIO_H

#include "std_types.h"
#include "Common_Macros.h"

/*******************************************************************************
 *                              DEFINITIONS                              *
 *******************************************************************************/
//PORTS
#define Dio_PORTA_PORT_NUM                 (uint8)0 
#define Dio_PORTB_PORT_NUM                 (uint8)1 
#define Dio_PORTC_PORT_NUM                 (uint8)2 
#define Dio_PORTD_PORT_NUM                 (uint8)3 
#define Dio_PORTE_PORT_NUM                 (uint8)4 
#define Dio_PORTF_PORT_NUM                 (uint8)5 

//pins

#define Dio_PA0_INDEX        (uint8)0x00
#define Dio_PA1_INDEX        (uint8)0x01
#define Dio_PA2_INDEX        (uint8)0x02
#define Dio_PA3_INDEX        (uint8)0x03
#define Dio_PA4_INDEX        (uint8)0x04
#define Dio_PA5_INDEX        (uint8)0x05
#define Dio_PA6_INDEX        (uint8)0x06
#define Dio_PA7_INDEX        (uint8)0x07

#define Dio_PB0_INDEX        (uint8)0x08
#define Dio_PB1_INDEX        (uint8)0x09
#define Dio_PB2_INDEX        (uint8)0x0A
#define Dio_PB3_INDEX        (uint8)0x0B
#define Dio_PB4_INDEX        (uint8)0x0C
#define Dio_PB5_INDEX        (uint8)0x0D
#define Dio_PB6_INDEX        (uint8)0x0E
#define Dio_PB7_INDEX        (uint8)0x0F

#define Dio_PC0_INDEX        (uint8)0x10
#define Dio_PC1_INDEX        (uint8)0x11
#define Dio_PC2_INDEX        (uint8)0x12
#define Dio_PC3_INDEX        (uint8)0x13
#define Dio_PC4_INDEX        (uint8)0x14
#define Dio_PC5_INDEX        (uint8)0x15
#define Dio_PC6_INDEX        (uint8)0x16
#define Dio_PC7_INDEX        (uint8)0x17

#define Dio_PD0_INDEX        (uint8)0x18
#define Dio_PD1_INDEX        (uint8)0x19
#define Dio_PD2_INDEX        (uint8)0x1A
#define Dio_PD3_INDEX        (uint8)0x1B
#define Dio_PD4_INDEX        (uint8)0x1C
#define Dio_PD5_INDEX        (uint8)0x1D
#define Dio_PD6_INDEX        (uint8)0x1E
#define Dio_PD7_INDEX        (uint8)0x1F

#define Dio_PE0_INDEX        (uint8)0x20
#define Dio_PE1_INDEX        (uint8)0x21
#define Dio_PE2_INDEX        (uint8)0x22
#define Dio_PE3_INDEX        (uint8)0x23
#define Dio_PE4_INDEX        (uint8)0x24
#define Dio_PE5_INDEX        (uint8)0x25

#define Dio_PF0_INDEX        (uint8)0x28
#define Dio_PF1_INDEX        (uint8)0x29
#define Dio_PF2_INDEX        (uint8)0x2A
#define Dio_PF3_INDEX        (uint8)0x2B
#define Dio_PF4_INDEX        (uint8)0x2C



/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Type definition for Dio_ChannelType used by the DIO APIs */
typedef uint8 Dio_ChannelType;

/* Type definition for Dio_PortType used by the DIO APIs */
typedef uint8 Dio_PortType;

/* Type definition for Dio_LevelType used by the DIO APIs */
typedef uint8 Dio_LevelType;

/* Type definition for Dio_PortLevelType used by the DIO APIs */
typedef uint8 Dio_PortLevelType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Function for DIO read Channel API */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/* Function for DIO write Channel API */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

/* Function for DIO read Port API */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/* Function for DIO write Port API */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId);

#endif /* DIO_H */
