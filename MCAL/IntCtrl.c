/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/
#ifndef INTCTRL_C
#define INTCTRL_C

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : void IntCtrl_Init(void)
 * \Description     : assign priority to system interrupts , enable or disable interrupts in NVIC level
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 *******************************************************************************/
void IntCtrl_Init(void)
{
    #if(INTCTRL_DISABLE_INTERRUPTS == 1)
        Disable_Exceptions();
        #endif

    uint8 totalPriority;
    uint32* regAddr = 0x00000000;

    // Adjust the group to subgroup ratio in APINT , write the VECTKEY value first in the reg
    APINT = (VECTKEY << 16)|(IntCtrl_Group_to_SubGroup_cfg << 8);
		
		int i;
    for (i = 0; i < INTCTRL_NUM_OF_ENABLED_INT; i++)
    {
        // get total priority
        if (IntCtrl_Group_to_SubGroup_cfg == NVIC_PRIORITY_GROUP_8_SUBGROUP_1)
        {
            totalPriority = IntCtrl_Configurations[i].intGroup;
        }
        else if (IntCtrl_Group_to_SubGroup_cfg == NVIC_PRIORITY_GROUP_1_SUBGROUP_8)
        {
            totalPriority = IntCtrl_Configurations[i].intSubGroup;
        }
        else if (IntCtrl_Group_to_SubGroup_cfg == NVIC_PRIORITY_GROUP_4_SUBGROUP_2)
        {
            // 0000 0110 | 0000 0001
            totalPriority = ((IntCtrl_Configurations[i].intGroup << 1) & 0x06) | (IntCtrl_Configurations[i].intSubGroup & 0x01);
        }
        else if (IntCtrl_Group_to_SubGroup_cfg == NVIC_PRIORITY_GROUP_2_SUBGROUP_4)
        {
            // 0000 0100 | 0000 0011
            totalPriority = ((IntCtrl_Configurations[i].intGroup << 2) & 0x04) | (IntCtrl_Configurations[i].intSubGroup & 0x03);
        }

        if(IntCtrl_Configurations[i].intNum<0){
        // adjust priority of system exception only and go to next iteration
            switch ((uint32)IntCtrl_Configurations[i].intNum)
            {
            case MEM_MANAGEMENT_FAULT:
                NVIC_SYSTEM_PRI1_REG |= (totalPriority<<5);
                break;
            case BUS_FAULT:
                NVIC_SYSTEM_PRI1_REG |= (totalPriority<<13);
                break;
            case USAGE_FAULT:
                NVIC_SYSTEM_PRI1_REG |= (totalPriority<<21);
                break;
            case SVC:
                NVIC_SYSTEM_PRI2_REG |= (totalPriority<<29);
                break;
            case DEBUG:
                NVIC_SYSTEM_PRI3_REG |= (totalPriority<<5);
                break;
            case PENDSV:
                NVIC_SYSTEM_PRI3_REG |= (totalPriority<<21);
                break;
            case SYSTICK:
                NVIC_SYSTEM_PRI3_REG |= (totalPriority<<29);
                break;
            }
            continue;
        }

        //enable/disable interrupts if not system exception
        if(IntCtrl_Configurations[i].e==ENABLE){
					regAddr = (uint32*)& NVIC_EN0_REG;
        }
        else{
         regAddr = (uint32*) & NVIC_DIS0_REG;
        }
         regAddr+=((uint32)(IntCtrl_Configurations[i].intNum / 32)); //increase addres of pointer
         (*regAddr)|=(1<<(IntCtrl_Configurations[i].intNum % 32));

        //insert priority of the interrupt only if ENABLE option is chosen
        if(IntCtrl_Configurations[i].e==ENABLE){
        regAddr =(uint32*) & NVIC_PRI0_REG;
        }
        else{
            continue;
        }

        regAddr+=((uint32)(IntCtrl_Configurations[i].intNum / 4));
        (*regAddr)|=(totalPriority<<(((IntCtrl_Configurations[i].intNum % 4)*8)+5));
    }
}

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.c
 *********************************************************************************************************************/
#endif