#ifndef PORT_CFG_H
#define PORT_CFG_H


/* Number of the configured Port Channels */
#define PORT_CONFIGURED_CHANNLES              (43U)

/* Channel Index in the array of structures in Port_lcfg.c */
/* Assuming all pins have been configured and PF1 & PF4 were specially configured for the LED and BUTTON*/
#define PortConf_PA0_INDEX        (uint8)0x00
#define PortConf_PA1_INDEX        (uint8)0x01
#define PortConf_PA2_INDEX        (uint8)0x02
#define PortConf_PA3_INDEX        (uint8)0x03
#define PortConf_PA4_INDEX        (uint8)0x04
#define PortConf_PA5_INDEX        (uint8)0x05
#define PortConf_PA6_INDEX        (uint8)0x06
#define PortConf_PA7_INDEX        (uint8)0x07

#define PortConf_PB0_INDEX        (uint8)0x08
#define PortConf_PB1_INDEX        (uint8)0x09
#define PortConf_PB2_INDEX        (uint8)0x0A
#define PortConf_PB3_INDEX        (uint8)0x0B
#define PortConf_PB4_INDEX        (uint8)0x0C
#define PortConf_PB5_INDEX        (uint8)0x0D
#define PortConf_PB6_INDEX        (uint8)0x0E
#define PortConf_PB7_INDEX        (uint8)0x0F

#define PortConf_PC0_INDEX        (uint8)0x10
#define PortConf_PC1_INDEX        (uint8)0x11
#define PortConf_PC2_INDEX        (uint8)0x12
#define PortConf_PC3_INDEX        (uint8)0x13
#define PortConf_PC4_INDEX        (uint8)0x14
#define PortConf_PC5_INDEX        (uint8)0x15
#define PortConf_PC6_INDEX        (uint8)0x16
#define PortConf_PC7_INDEX        (uint8)0x17

#define PortConf_PD0_INDEX        (uint8)0x18
#define PortConf_PD1_INDEX        (uint8)0x19
#define PortConf_PD2_INDEX        (uint8)0x1A
#define PortConf_PD3_INDEX        (uint8)0x1B
#define PortConf_PD4_INDEX        (uint8)0x1C
#define PortConf_PD5_INDEX        (uint8)0x1D
#define PortConf_PD6_INDEX        (uint8)0x1E
#define PortConf_PD7_INDEX        (uint8)0x1F

#define PortConf_PE0_INDEX        (uint8)0x20
#define PortConf_PE1_INDEX        (uint8)0x21
#define PortConf_PE2_INDEX        (uint8)0x22
#define PortConf_PE3_INDEX        (uint8)0x23
#define PortConf_PE4_INDEX        (uint8)0x24
#define PortConf_PE5_INDEX        (uint8)0x25

#define PortConf_PF0_INDEX        (uint8)0x26
#define PortConf_LED1_INDEX       (uint8)0x27
#define PortConf_PF2_INDEX        (uint8)0x28
#define PortConf_PF3_INDEX        (uint8)0x29
#define PortConf_SW1_INDEX        (uint8)0x2A


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
