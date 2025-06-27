/*
 * HX711_FREERTOS.h
 *
 *  Created on: 27 jun 2025
 *      Author: lukas
 */

#ifndef SOURCE_PROJLIB_HX711_FREERTOS_H_
#define SOURCE_PROJLIB_HX711_FREERTOS_H_

#include "sys_common.h"

/* Port/Pin Definition for HX711 */
#define PORT_HX711_DT   gioPORTA
#define PIN_HX711_DT    0x06U       // Data Out pin is [GIOA6]

/* Signal Definitions for HX711 */
/*
 * HX711 SCK PWM is Operating at 50kHz
 * SCK UP time is 4us
 * */
#define PWM_HX711_SCK   0x01U       // Serial Clock PWM signal is [PWM1]

/* Variable Definition for HX711 */
// Code here

#endif /* SOURCE_PROJLIB_HX711_FREERTOS_H_ */
