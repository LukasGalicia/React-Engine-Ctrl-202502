/*
 * BLDC_ctrlLib.h
 *
 *  Created on: 19 jul 2025
 *      Author: lukas
 */

#ifndef SOURCE_PROJLIB_BLDC_CTRLLIB_H_
#define SOURCE_PROJLIB_BLDC_CTRLLIB_H_

#include "sys_common.h"
#include "het.h"

/* Signal definitions for BLDC control */
#define BLDC_PWM    2U

typedef enum
{
    Kprop,
    Kint,
    Kdev
} PIDGains;

/* Library Function Prototypes */
void enhPWMSetDuty(hetRAMBASE_t * hetRAM, uint32 pwm, uint32 pwmDuty);      // Enhanced PWM to .01%

#endif /* SOURCE_PROJLIB_BLDC_CTRLLIB_H_ */
