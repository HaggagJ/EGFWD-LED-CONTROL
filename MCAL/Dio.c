 /******************************************************************************
 *
 * Module: Dio
 *
 * File Name: Dio.c
 *
 * Description: Source file for TM4C123GH6PM Microcontroller - Dio Driver
 ******************************************************************************/

#include "Dio.h"
#include "Dio_Registers.h"

/************************************************************************************
* Service Name: Dio_ReadPort
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Dio_PortType PortId
* Parameters (inout): None
* Parameters (out): 
* Return value: Dio_PortLevelType - port value
* Description: Function to read level of a port
************************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId){

	Dio_PortLevelType level=0;
	switch (PortId)
	{
	case Dio_PORTA_PORT_NUM:
		level = GPIO_PORTA_DATA_REG; 		
		break;
	case Dio_PORTB_PORT_NUM:
		level = GPIO_PORTB_DATA_REG; 
		break;
	case Dio_PORTC_PORT_NUM:
		level = GPIO_PORTC_DATA_REG;
		break;
	case Dio_PORTD_PORT_NUM:
		level = GPIO_PORTD_DATA_REG;
		break;
	case Dio_PORTE_PORT_NUM:
		level = GPIO_PORTE_DATA_REG;
		break;
	case Dio_PORTF_PORT_NUM:
		level = GPIO_PORTF_DATA_REG;
		break;    
	}
	return level;

}
/************************************************************************************
* Service Name: Dio_WritePort
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): Dio_PortType PortId , Dio_PortLevelType Level
* Parameters (inout): None
* Parameters (out): 
* Return value: none
* Description: Function to write level of a port
************************************************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level){
	switch (PortId)
	{
	case Dio_PORTA_PORT_NUM:
		GPIO_PORTA_DATA_REG=Level; 		
		break;
	case Dio_PORTB_PORT_NUM:
		GPIO_PORTB_DATA_REG=Level; 
		break;
	case Dio_PORTC_PORT_NUM:
		GPIO_PORTC_DATA_REG=Level; 
		break;
	case Dio_PORTD_PORT_NUM:
		GPIO_PORTD_DATA_REG=Level; 
		break;
	case Dio_PORTE_PORT_NUM:
		GPIO_PORTE_DATA_REG=Level; 
		break;
	case Dio_PORTF_PORT_NUM:
		GPIO_PORTF_DATA_REG=Level; 
		break;    
	}
}
/************************************************************************************
* Service Name: Dio_WriteChannel
* Service ID[hex]: 0x01
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
*                  Level - Value to be written.
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to set a level of a channel.
************************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	volatile uint32 * Port_Ptr = 0x00000000;

		/* Point to the correct PORT register according to the ChannelID value passed */
		if(ChannelId >= Dio_PA0_INDEX && ChannelId<=Dio_PA7_INDEX)
		{
        	 Port_Ptr = &GPIO_PORTA_DATA_REG;  
		}
		else if(ChannelId >= Dio_PB0_INDEX && ChannelId<=Dio_PB7_INDEX){
			Port_Ptr = &GPIO_PORTB_DATA_REG;  
		}
		else if(ChannelId >= Dio_PC0_INDEX && ChannelId<=Dio_PC7_INDEX){
			Port_Ptr = &GPIO_PORTC_DATA_REG;
		}
		else if(ChannelId >= Dio_PD0_INDEX && ChannelId<=Dio_PD7_INDEX){
			Port_Ptr = &GPIO_PORTD_DATA_REG;
		}
		else if(ChannelId >= Dio_PE0_INDEX && ChannelId<=Dio_PE5_INDEX){
			Port_Ptr = &GPIO_PORTE_DATA_REG;
		}
		else if(ChannelId >= Dio_PF0_INDEX && ChannelId<=Dio_PF4_INDEX){
			Port_Ptr = &GPIO_PORTF_DATA_REG;
		}
		else{
			//#warning ("invalid pin number")
		}

		if(Level == STD_HIGH)
		{
			/* Write Logic High */
			SET_BIT(*Port_Ptr, ChannelId % 8 );
		}
		else if(Level == STD_LOW)
		{
			/* Write Logic Low */
			CLEAR_BIT(*Port_Ptr, ChannelId % 8);
		}

}

/************************************************************************************
* Service Name: Dio_ReadChannel
* Service ID[hex]: 0x00
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to return the value of the specified DIO channel.
************************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
	volatile uint32 * Port_Ptr = 0x00000000;
	Dio_LevelType output = STD_LOW;
	boolean error = false;

	
	
		/* Point to the correct PORT register according to the ChannelID value passed */
		if(ChannelId >= Dio_PA0_INDEX && ChannelId<=Dio_PA7_INDEX)
		{
        	 Port_Ptr = &GPIO_PORTA_DATA_REG;  
		}
		else if(ChannelId >= Dio_PB0_INDEX && ChannelId<=Dio_PB7_INDEX){
			Port_Ptr = &GPIO_PORTB_DATA_REG;  
		}
		else if(ChannelId >= Dio_PC0_INDEX && ChannelId<=Dio_PC7_INDEX){
			Port_Ptr = &GPIO_PORTC_DATA_REG;
		}
		else if(ChannelId >= Dio_PD0_INDEX && ChannelId<=Dio_PD7_INDEX){
			Port_Ptr = &GPIO_PORTD_DATA_REG;
		}
		else if(ChannelId >= Dio_PE0_INDEX && ChannelId<=Dio_PE5_INDEX){
			Port_Ptr = &GPIO_PORTE_DATA_REG;
		}
		else if(ChannelId >= Dio_PF0_INDEX && ChannelId<=Dio_PF4_INDEX){
			Port_Ptr = &GPIO_PORTF_DATA_REG;
		}
		else{
			//#warning ("invalid pin number")
		}
		
		/* Read the required channel */
		if(BIT_IS_SET(*Port_Ptr,ChannelId % 8))
		{
			output = STD_HIGH;
		}
		else
		{
			output = STD_LOW;
		}
        return output;
}
/************************************************************************************
* Service Name: Dio_FlipChannel
* Service ID[hex]: 0x11
* Sync/Async: Synchronous
* Reentrancy: Reentrant
* Parameters (in): ChannelId - ID of DIO channel.
* Parameters (inout): None
* Parameters (out): None
* Return value: Dio_LevelType
* Description: Function to flip the level of a channel and return the level of the channel after flip.
************************************************************************************/

Dio_LevelType Dio_FlipChannel(Dio_ChannelType ChannelId)
{
	volatile uint32 * Port_Ptr = 0x00000000;
	Dio_LevelType output = STD_LOW;


	/* Point to the correct PORT register according to the ChannelID value passed */
		if(ChannelId >= Dio_PA0_INDEX && ChannelId<=Dio_PA7_INDEX)
		{
        	 Port_Ptr = &GPIO_PORTA_DATA_REG;  
		}
		else if(ChannelId >= Dio_PB0_INDEX && ChannelId<=Dio_PB7_INDEX){
			Port_Ptr = &GPIO_PORTB_DATA_REG;  
		}
		else if(ChannelId >= Dio_PC0_INDEX && ChannelId<=Dio_PC7_INDEX){
			Port_Ptr = &GPIO_PORTC_DATA_REG;
		}
		else if(ChannelId >= Dio_PD0_INDEX && ChannelId<=Dio_PD7_INDEX){
			Port_Ptr = &GPIO_PORTD_DATA_REG;
		}
		else if(ChannelId >= Dio_PE0_INDEX && ChannelId<=Dio_PE5_INDEX){
			Port_Ptr = &GPIO_PORTE_DATA_REG;
		}
		else if(ChannelId >= Dio_PF0_INDEX && ChannelId<=Dio_PF4_INDEX){
			Port_Ptr = &GPIO_PORTF_DATA_REG;
		}
		else{
			//#warning ("invalid pin number")
		}

		/* Read the required channel and write the required level */
		if(BIT_IS_SET(*Port_Ptr,ChannelId % 8))
		{
			CLEAR_BIT(*Port_Ptr,ChannelId % 8);
			output = STD_LOW;
		}
		else
		{
			SET_BIT(*Port_Ptr,ChannelId % 8);
			output = STD_HIGH;
		}
        return output;
}

