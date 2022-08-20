/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl.h
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/
#ifndef INTCTRL_H
#define INTCTRL_H
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "std_types.h"
#include "IntCtrl_Types.h"
#include "IntCtrl_Registers.h"
#include "IntCtrl_cfg.h"

/**********************************************************************************************************************
*  MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
/* Enable Exceptions ... This Macro enable IRQ interrupts, Programmble Systems Exceptions and Faults by clearing the I-bit in the PRIMASK. */
#define Enable_Exceptions()    __asm("CPSIE I")

/* Disable Exceptions ... This Macro disable IRQ interrupts, Programmble Systems Exceptions and Faults by clearing the I-bit in the PRIMASK. */
#define Disable_Exceptions()   __asm("CPSID I")

/* Enable Faults ... This Macro enable Faults by clearing the F-bit in the FAULTMASK */
#define Enable_Faults()        __asm("CPSIE F")

/* Disable Faults ... This Macro disable Faults by setting the F-bit in the FAULTMASK */
#define Disable_Faults()       __asm("CPSID F")  

/*All options for group/subgroup division "Adjusted in APINT register " */
#define NVIC_PRIORITY_GROUP_8_SUBGROUP_1                     0x4
#define NVIC_PRIORITY_GROUP_1_SUBGROUP_8                     0x7
#define NVIC_PRIORITY_GROUP_4_SUBGROUP_2                     0x5
#define NVIC_PRIORITY_GROUP_2_SUBGROUP_4                     0x6

#define VECTKEY                                             0x05FA


/**********************************************************************************************************************
*  CONFIGURATION STRUCTURE
*********************************************************************************************************************/
typedef struct 
{
    IntCtrl_InterruptType intNum;
    IntCtrl_Enable_Disable e;
    IntCtrl_InterruptGroup intGroup;
    IntCtrl_InterruptSubGroup intSubGroup; 
}IntCtrl_Cfg;


/**********************************************************************************************************************
 *  EXTERNS
 *********************************************************************************************************************/
extern const IntCtrl_Cfg IntCtrl_Configurations[INTCTRL_NUM_OF_ENABLED_INT];
extern const uint8 IntCtrl_Group_to_SubGroup_cfg;

/**********************************************************************************************************************
 *  FUNCTIONS PROTOTYPES
 *********************************************************************************************************************/
void IntCtrl_Init(void);

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.h
 *********************************************************************************************************************/
#endif 