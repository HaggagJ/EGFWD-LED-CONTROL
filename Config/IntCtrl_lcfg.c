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
   {UDMA_ERROR, ENABLE,  1, 2},
   {GPIO_PORT_F, ENABLE, 1, 3},
   {SYSTICK, NONE,  0, 3},
};
//This is used to adjust "group and subgroup" number of bits in APINT register 
const uint8 IntCtrl_Group_to_SubGroup_cfg =  NVIC_PRIORITY_GROUP_2_SUBGROUP_4;

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_lcfg.c
 *********************************************************************************************************************/
#endif