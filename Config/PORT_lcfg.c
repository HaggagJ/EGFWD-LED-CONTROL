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
            PortConf_PORTA_PORT_NUM , PortConf_PIN0_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTA_PORT_NUM , PortConf_PIN1_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW ,
            PortConf_PORTA_PORT_NUM , PortConf_PIN2_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTA_PORT_NUM , PortConf_PIN3_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTA_PORT_NUM , PortConf_PIN4_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTA_PORT_NUM , PortConf_PIN5_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTA_PORT_NUM , PortConf_PIN6_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTA_PORT_NUM , PortConf_PIN7_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            
            PortConf_PORTB_PORT_NUM , PortConf_PIN0_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_ADC , OFF , STD_LOW , 
            PortConf_PORTB_PORT_NUM , PortConf_PIN1_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_ADC , OFF , STD_LOW , 
            PortConf_PORTB_PORT_NUM , PortConf_PIN2_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTB_PORT_NUM , PortConf_PIN3_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTB_PORT_NUM , PortConf_PIN4_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTB_PORT_NUM , PortConf_PIN5_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTB_PORT_NUM , PortConf_PIN6_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTB_PORT_NUM , PortConf_PIN7_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            
            PortConf_PORTC_PORT_NUM , PortConf_PIN0_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTC_PORT_NUM , PortConf_PIN1_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTC_PORT_NUM , PortConf_PIN2_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTC_PORT_NUM , PortConf_PIN3_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTC_PORT_NUM , PortConf_PIN4_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTC_PORT_NUM , PortConf_PIN5_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTC_PORT_NUM , PortConf_PIN6_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTC_PORT_NUM , PortConf_PIN7_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            
            PortConf_PORTD_PORT_NUM , PortConf_PIN0_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTD_PORT_NUM , PortConf_PIN1_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTD_PORT_NUM , PortConf_PIN2_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTD_PORT_NUM , PortConf_PIN3_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTD_PORT_NUM , PortConf_PIN4_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTD_PORT_NUM , PortConf_PIN5_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTD_PORT_NUM , PortConf_PIN6_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTD_PORT_NUM , PortConf_PIN7_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            
            PortConf_PORTE_PORT_NUM , PortConf_PIN0_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTE_PORT_NUM , PortConf_PIN1_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTE_PORT_NUM , PortConf_PIN2_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTE_PORT_NUM , PortConf_PIN3_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTE_PORT_NUM , PortConf_PIN4_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTE_PORT_NUM , PortConf_PIN5_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            
            PortConf_PORTF_PORT_NUM , PortConf_PIN0_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTF_PORT_NUM , PortConf_PIN1_CHANNEL_NUM , PORT_PIN_OUT , PORT_PIN_MODE_DIO , OFF , STD_LOW ,
            PortConf_PORTF_PORT_NUM , PortConf_PIN2_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTF_PORT_NUM , PortConf_PIN3_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_DOWN , STD_LOW , 
            PortConf_PORTF_PORT_NUM , PortConf_PIN4_CHANNEL_NUM , PORT_PIN_IN , PORT_PIN_MODE_DIO , PULL_UP , STD_LOW ,
            
            
                                            
				         };