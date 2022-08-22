#ifndef PORT_CFG_H
#define PORT_CFG_H


/* Number of the configured Port Channels */
#define PORT_CONFIGURED_CHANNLES              (2U)

/* Configured channel Index in the array of structures in Port_lcfg.c */
#define PortConf_PF0_INDEX        (uint8)0x00
#define PortConf_PF1_INDEX        (uint8)0x01

/* Tiva C Port ID's  */
#define PortConf_PORTA_PORT_NUM                 (uint8)0 
#define PortConf_PORTB_PORT_NUM                 (uint8)1 
#define PortConf_PORTC_PORT_NUM                 (uint8)2 
#define PortConf_PORTD_PORT_NUM                 (uint8)3 
#define PortConf_PORTE_PORT_NUM                 (uint8)4 
#define PortConf_PORTF_PORT_NUM                 (uint8)5 


/* Tiva C Channel ID's */
#define PortConf_PIN0_CHANNEL_NUM             (Port_PinType)0 
#define PortConf_PIN1_CHANNEL_NUM             (Port_PinType)1 
#define PortConf_PIN2_CHANNEL_NUM             (Port_PinType)2
#define PortConf_PIN3_CHANNEL_NUM             (Port_PinType)3 
#define PortConf_PIN4_CHANNEL_NUM             (Port_PinType)4 
#define PortConf_PIN5_CHANNEL_NUM             (Port_PinType)5 
#define PortConf_PIN6_CHANNEL_NUM             (Port_PinType)6 
#define PortConf_PIN7_CHANNEL_NUM             (Port_PinType)7 

#endif /* PORT_CFG_H */
