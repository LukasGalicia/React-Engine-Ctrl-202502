/*
 * BLDC_ctrlLib.c
 *
 *  Created on: 19 jul 2025
 *      Author: lukas
 */

#include "BLDC_ctrlLib.h"

/* PWM Polarities off het.c (Update when necessary) */
static const uint32 s_het1pwmPolarity[8U] =
{
    3U,
    3U,
    3U,
    3U,
    3U,
    3U,
    3U,
    3U,
};

/**
 * @brief Set duty cycle for HET PWM with 0.001% resolution.
 *
 * @param hetRAM    Pointer to HET RAM (hetRAM1 or hetRAM2)
 * @param pwm       PWM channel (0 to 7)
 * @param pwmDuty   Duty cycle in 0.001 percent units.
 *                  Example: 50000 = 50.000%, 100000 = 100.000%, 1 = 0.001%
 */
void enhPWMSetDuty(hetRAMBASE_t * hetRAM, uint32 pwm, uint32 pwmDuty)
{
    uint32 action;
    uint32 pwmPolarity = 0U;
    uint32 pwmPeriod = hetRAM->Instruction[(pwm << 1U) + 42U].Data + 128U;
    pwmPeriod = pwmPeriod >> 7U;

    if (hetRAM == hetRAM1)
    {
        pwmPolarity = s_het1pwmPolarity[pwm];
    }

    if (pwmDuty == 0U)
    {
        action = (pwmPolarity == 3U) ? 0U : 2U;
    }
    else if (pwmDuty >= 100000U)  // 100.000%
    {
        action = (pwmPolarity == 3U) ? 2U : 0U;
    }
    else
    {
        action = pwmPolarity;
    }

    hetRAM->Instruction[(pwm << 1U) + 41U].Control = (hetRAM->Instruction[(pwm << 1U) + 41U].Control & (~(uint32)(0x00000018U))) | (action << 3U);

    // Support ten-millipercent (0.001%) resolution
    hetRAM->Instruction[(pwm << 1U) + 41U].Data = (((pwmPeriod * pwmDuty) / 100000U) << 7U) + 128U;
}
