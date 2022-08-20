/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl_Types.h
 *        \brief  
 *
 *      \details  creates data types specific for IntCtrl
 *
 *
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"

/**********************************************************************************************************************
*  DATA TYPES
*********************************************************************************************************************/
/*this enum contains first 47 external interrupts , */
typedef  enum{
    /*for system interrupts the driver is only responsible for adjusting its priority , 
    enabling the system interrupt is done at the peripheral's registers */
    MEM_MANAGEMENT_FAULT=-7,
    BUS_FAULT,
    USAGE_FAULT,
    SVC,
    DEBUG,
    PENDSV,
    SYSTICK,
    //external interrupts , enables and sets its priority
    GPIO_PORT_A,
    GPIO_PORT_B,
    GPIO_PORT_C,
    GPIO_PORT_D,
    GPIO_PORT_E,
    UART0,
    UART1,
    SSI0,
    I2C0,
    PWM_FAULT,
    PWM_GEN_0,
    PWM_GEN_1,
    PWM_GEN_2,
    QUAD_ENCODER,
    ADC_SEQ_0,
    ADC_SEQ_1,
    ADC_SEQ_2,
    ADC_SEQ_3,
    WATCHDOG,
    TIMER_0A,
    TIMER_0B,
    TIMER_1A,
    TIMER_1B,
    TIMER_2A,
    TIMER_2B,
    COMP0,
    COMP1,
    COMP2,
    SYSTEM_CONTROL,
    FLASH_CONTROL,
    GPIO_PORT_F,
    GPIO_PORT_G,
    GPIO_PORT_H,
    UART2,
    SSI1,
    TIMER_3A,
    TIMER_3B,
    I2C1,
    QUAD_ENCODER1,
    CAN0,
    CAN1,
    CAN2,
    ETHERNET,
    HIBERNATE,
    USB0,
    PWM_GEN_3,
    UDMA_SOFT_TFR,
    UDMA_ERROR,

}IntCtrl_InterruptType;

typedef enum {
DISABLE,
ENABLE,
NONE
}IntCtrl_Enable_Disable;

typedef  uint8 IntCtrl_InterruptGroup;
typedef  uint8 IntCtrl_InterruptSubGroup;

/******************************************************************************

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
#endif