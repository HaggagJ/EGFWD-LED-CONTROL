/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl_lcfg.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/
#ifndef INTCTRL_LCFG_C
#define INTCTRL_LCFG_C

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl.h"

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
const IntCtrl_Cfg IntCtrl_Configurations[INTCTRL_NUM_OF_ENABLED_INT]={
    /* InterruptNum, Enable or Disable, PriorityGroup, PrioritySubGroup */
   {SYSTICK, NONE,  0, 0}
};
//This is used to adjust "group and subgroup" number of bits in APINT register 
const uint8 IntCtrl_Group_to_SubGroup_cfg =  NVIC_PRIORITY_GROUP_8_SUBGROUP_1;

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_lcfg.c
 *********************************************************************************************************************/
#endif