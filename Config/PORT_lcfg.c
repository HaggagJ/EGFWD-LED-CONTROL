/******************************************************************************
 *
 * Module: Port
 *
 * File Name: PORT_PBcfg.c
 *
 * Description: Post Build Configuration Source file for TM4C123GH6PM Microcontroller - Port Driver
 *
 ******************************************************************************/

#include "Port.h"

/* PB structure used with Port_Init API */
const Port_ConfigType Port_Configuration = {
            PortConf_PORTA_PORT_NUM , PortConf_PIN0_CHANNEL_NUM , PORT_PIN_OUT , PORT_PIN_MODE_DIO , PULL_DOWN , STD_HIGH , 
            PortConf_PORTA_PORT_NUM , PortConf_PIN1_CHANNEL_NUM , PORT_PIN_OUT , PORT_PIN_MODE_DIO , PULL_DOWN , STD_HIGH ,      
				         };