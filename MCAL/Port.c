/******************************************************************************
*
* Module: Port
*
* File Name: Port.c
*
* Description: Source file for TM4C123GH6PM Microcontroller - Port Driver.
*
******************************************************************************/

#include "Port.h"
#include "Port_Registers.h"

/************************************************************************************
* Service Name: Port_Init
* Sync/Async: Synchronous
* Reentrancy: reentrant
* Parameters (in): ConfigPtr - Pointer to post-build configuration data
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to Setup the pin configuration:
*              - Setup the pin as Digital GPIO pin
*              - Setup the direction of the GPIO pin
*              - Provide initial value for o/p pin
*              - Setup the internal resistor for i/p pin
- Report det error if null pointer is passed
************************************************************************************/
void Port_Init(const Port_ConfigType * ConfigPtr )
{
    
    volatile uint32 * PortGpio_Ptr = 0x00000000; /* point to the required Port Registers base address */
    volatile uint32 delay = 0;
    int index=0;
    for( index=0 ; PORT_CONFIGURED_CHANNLES > index ; index=index+1){
      
      switch((ConfigPtr->Pins[index].port_num))
      {
      case  PORTA_PORT_NUM: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTA_BASE_ADDRESS; /* PORTA Base Address */
      break;
      case  PORTB_PORT_NUM: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTB_BASE_ADDRESS; /* PORTB Base Address */
      break;
      case  PORTC_PORT_NUM: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTC_BASE_ADDRESS; /* PORTC Base Address */
      break;
      case  PORTD_PORT_NUM: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTD_BASE_ADDRESS; /* PORTD Base Address */
      break;
      case  PORTE_PORT_NUM: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTE_BASE_ADDRESS; /* PORTE Base Address */
      break;
      case  PORTF_PORT_NUM: PortGpio_Ptr = (volatile uint32 *)GPIO_PORTF_BASE_ADDRESS; /* PORTF Base Address */
      break;
      }
      
      /* Enable clock for PORT and allow time for clock to start*/
      SYSCTL_REGCGC2_REG |= (1<<(ConfigPtr->Pins[index].port_num));
      delay = SYSCTL_REGCGC2_REG;
      
      if( ((PORTD_PORT_NUM==(ConfigPtr->Pins[index].port_num) ) && ( PIN7_CHANNEL_NUM == (ConfigPtr->Pins[index].pin_num) )) || ((PORTF_PORT_NUM==(ConfigPtr->Pins[index].port_num)) && (PIN0_CHANNEL_NUM == (ConfigPtr->Pins[index].pin_num))) ) /* PD7 or PF0 */
      {
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_LOCK_REG_OFFSET) = UNLOCK_GPIOCR;                     /* Unlock the GPIOCR register */   
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_COMMIT_REG_OFFSET) , (ConfigPtr->Pins[index].pin_num));  /* Set the corresponding bit in GPIOCR register to allow changes on this pin */
      }
      else if( (PORTC_PORT_NUM == (ConfigPtr->Pins[index].port_num)) && (PIN3_CHANNEL_NUM >= (ConfigPtr->Pins[index].pin_num)) ) /* PC0 to PC3 */
      {
        /*this is the JTAG pins */
        continue;
      }
      else
      {
        /* Do Nothing ... No need to unlock the commit register for this pin */
      }
      
      if(PORT_PIN_MODE_DIO==(ConfigPtr->Pins[index].Mode)){
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , ConfigPtr->Pins[index].pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->Pins[index].pin_num);             /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << ((ConfigPtr->Pins[index].pin_num) * 4));     /* Clear the PMCx bits for this pin */
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , ConfigPtr->Pins[index].pin_num);                     /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
      }
      
      else if(PORT_PIN_MODE_ADC == (ConfigPtr->Pins[index].Mode)){
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) ,  ConfigPtr->Pins[index].pin_num);        /* Clear the corresponding bit in the GPIODEN register to disable digital functionality on this pin */  
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->Pins[index].pin_num);             /* Disable Alternative function for this pin by clear the corresponding bit in GPIOAFSEL register */
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) &= ~(0x0000000F << ((ConfigPtr->Pins[index].pin_num) * 4));     /* Clear the PMCx bits for this pin */
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , ConfigPtr->Pins[index].pin_num);      /* Set the corresponding bit in the GPIOAMSEL register to enable analog functionality on this pin */
        
      }
      else{
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ANALOG_MODE_SEL_REG_OFFSET) , ConfigPtr->Pins[index].pin_num);      /* Clear the corresponding bit in the GPIOAMSEL register to disable analog functionality on this pin */
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_ALT_FUNC_REG_OFFSET) , ConfigPtr->Pins[index].pin_num);             /* Enable Alternative function for this pin by setting the corresponding bit in GPIOAFSEL register */
        *(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_CTL_REG_OFFSET) |= ( (0x0000000F&(ConfigPtr->Pins[index].Mode))<<((ConfigPtr->Pins[index].pin_num) * 4)); /*Insert alternative function number in PCTL register*/
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIGITAL_ENABLE_REG_OFFSET) , ConfigPtr->Pins[index].pin_num);                     /* Set the corresponding bit in the GPIODEN register to enable digital functionality on this pin */
      }
      
      
      if(PORT_PIN_OUT == (ConfigPtr->Pins[index].direction) )
      {
        SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , (ConfigPtr->Pins[index].pin_num));                /* Set the corresponding bit in the GPIODIR register to configure it as output pin */
        
        if(STD_HIGH == (ConfigPtr->Pins[index].initial_value))
        {
          SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , (ConfigPtr->Pins[index].pin_num));          /* Set the corresponding bit in the GPIODATA register to provide initial value 1 */
        }
        else                                                                                                                                //DEFAULT VALUE IS LOW
        {
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DATA_REG_OFFSET) , (ConfigPtr->Pins[index].pin_num));        /* Clear the corresponding bit in the GPIODATA register to provide initial value 0 */
        }
      }
      else if(PORT_PIN_IN == (ConfigPtr->Pins[index].direction) )
      {
        CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_DIR_REG_OFFSET) , (ConfigPtr->Pins[index].pin_num));             /* Clear the corresponding bit in the GPIODIR register to configure it as input pin */
        
        if(PULL_UP == ConfigPtr->Pins[index].resistor)
        {
          SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , (ConfigPtr->Pins[index].pin_num));       /* Set the corresponding bit in the GPIOPUR register to enable the internal pull up pin */
        }
        else if( PULL_DOWN == ConfigPtr->Pins[index].resistor)
        {
          SET_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , (ConfigPtr->Pins[index].pin_num));     /* Set the corresponding bit in the GPIOPDR register to enable the internal pull down pin */
        }
        else
        {
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_UP_REG_OFFSET) , (ConfigPtr->Pins[index].pin_num));     /* Clear the corresponding bit in the GPIOPUR register to disable the internal pull up pin */
          CLEAR_BIT(*(volatile uint32 *)((volatile uint8 *)PortGpio_Ptr + PORT_PULL_DOWN_REG_OFFSET) , (ConfigPtr->Pins[index].pin_num));   /* Clear the corresponding bit in the GPIOPDR register to disable the internal pull down pin */
        }
      }
      else
      {
        /* Do Nothing */
      }
    }
}

