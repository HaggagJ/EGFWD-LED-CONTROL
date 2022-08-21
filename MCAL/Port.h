 /******************************************************************************
 *
 * Module: Port
 *
 * File Name: Port.h
 *
 * Description: Header file for TM4C123GH6PM Microcontroller - Port Driver.
 *
 ******************************************************************************/

#ifndef PORT_H
#define PORT_H


#include "std_types.h"  
#include "PORT_Cfg.h"
#include "Common_Macros.h"
   
/******************************************************************************
 *                      TIVA C Definitions                                     *
 ******************************************************************************/
#define UNLOCK_GPIOCR                   0x4C4F434B
   
/* Tiva C Port ID's  */
#define PORTA_PORT_NUM                 (uint8)0 
#define PORTB_PORT_NUM                 (uint8)1 
#define PORTC_PORT_NUM                 (uint8)2 
#define PORTD_PORT_NUM                 (uint8)3 
#define PORTE_PORT_NUM                 (uint8)4 
#define PORTF_PORT_NUM                 (uint8)5 


/* Tiva C Channel ID's */
#define PIN0_CHANNEL_NUM             (Port_PinType)0 
#define PIN1_CHANNEL_NUM             (Port_PinType)1 
#define PIN2_CHANNEL_NUM             (Port_PinType)2
#define PIN3_CHANNEL_NUM             (Port_PinType)3 
#define PIN4_CHANNEL_NUM             (Port_PinType)4 
#define PIN5_CHANNEL_NUM             (Port_PinType)5 
#define PIN6_CHANNEL_NUM             (Port_PinType)6 
#define PIN7_CHANNEL_NUM             (Port_PinType)7 

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Description: Enum to hold PIN direction */
typedef enum
{
    PORT_PIN_IN,PORT_PIN_OUT
}Port_PinDirectionType;

/* Description: Enum to hold internal resistor type for PIN */
typedef enum
{
    OFF,PULL_UP,PULL_DOWN
}Port_PinInternalAttachType;

/*Description: The type Port_PinType shall be used for the symbolic name of a Port 
Pin*/
typedef uint8 Port_PinType ;

/*Description: A port pin shall be configurable with a number of port pin modes*/
typedef uint8 Port_PinModeType ;

typedef uint8 Port_PinOutputCurrentType;


/* Description: Structure to configure each individual PIN:
 *	1. the PORT Which the pin belongs to. 0, 1, 2, 3, 4 or 5
 *	2. the number of the pin in the PORT.
 *      3. the direction of pin --> INPUT or OUTPUT
 *      4. the mode of the pin
        5. the internal resistor --> Disable, Pull up or Pull down
        6. Initial Value on the pin (STD_HIGH or STD_LOW)
        7. Changeable pin direction (STD_ON or STD_OFF)
        8. Changeable mode direction (STD_ON or STD_OFF)
 */
typedef struct 
{
    uint8 port_num; 
    Port_PinType pin_num; 
    Port_PinDirectionType direction;
    Port_PinModeType Mode;
    Port_PinInternalAttachType resistor;
    uint8 initial_value;
}Port_ConfigChannel;

/*Description: Data Structure required for initializing the Port Driver */
typedef struct
{
Port_ConfigChannel Pins[PORT_CONFIGURED_CHANNLES];
}Port_ConfigType;

/*******************************************************************************
 *                              Modes Definitions                        *
 *******************************************************************************/
#define PORT_PIN_MODE_ADC  (Port_PinModeType)0x00
#define PORT_PIN_MODE_ALT1 (Port_PinModeType)0x01
#define PORT_PIN_MODE_ALT2 (Port_PinModeType)0x02
#define PORT_PIN_MODE_ALT3 (Port_PinModeType)0x03
#define PORT_PIN_MODE_ALT4 (Port_PinModeType)0x04
#define PORT_PIN_MODE_ALT5 (Port_PinModeType)0x05
#define PORT_PIN_MODE_ALT6 (Port_PinModeType)0x06
#define PORT_PIN_MODE_ALT7 (Port_PinModeType)0x07
#define PORT_PIN_MODE_ALT8 (Port_PinModeType)0x08
#define PORT_PIN_MODE_ALT9 (Port_PinModeType)0x09
#define PORT_PIN_MODE_DIO  (Port_PinModeType)0x0A

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/************************************************************************************
Service name: Port_Init 
Service ID[hex]: 0x00 
Sync/Async: Synchronous 
Reentrancy: Non Reentrant 
Parameters (in): ConfigPtr ,Pointer to configuration set. 
Parameters (inout): None 
Parameters (out): None 
Return value: None 
Description: Initializes the Port Driver module
************************************************************************************/
void Port_Init(const Port_ConfigType* ConfigPtr ) ;

/* Extern PB structures to be used by Port and other modules */
extern const Port_ConfigType Port_Configuration;
#endif /* PORT_H */
