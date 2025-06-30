/*
 * HX711_FREERTOS.h
 *
 *  Created on: 27 jun 2025
 *      Author: lukas
 */

#ifndef SOURCE_PROJLIB_HX711_FREERTOS_H_
#define SOURCE_PROJLIB_HX711_FREERTOS_H_

#include "sys_common.h"
#include "gio.h"
#include "het.h"

/* Port/Pin Definition for HX711 */
// DT pin
#define PORT_HX711_DT   gioPORTA
#define PIN_HX711_DT    0x06U       // Data Out pin is [GIOA6]
// SCK pin
#define PORT_HX711_SCK  hetPORT1
#define PIN_HX711_SCK   0x10U       // Serial Clock pin is [NHET16]
//Resolution Selectors
#define HX711_RES_64R_A 27U
#define HX711_RES_128R_A 25U

/* Signal Definitions for HX711 */
/*
 * HX711 SCK PWM is Operating at 50kHz
 * SCK UP time is 4us
 * */
#define PWM_HX711_SCK   pwm1       // Serial Clock PWM signal is [PWM1]

/* Variable Definition for HX711 */
volatile uint8_t HX711_data_count;
volatile uint32_t HX711_data_buff;

/* HX711 Macros */
#define DECODE_TWOS_COMPLEMENT( twos_comp_data ) (((twos_comp_data) & 0x800000) ? \
        ((int32_t)((twos_comp_data) | 0xFF000000)) : ((int32_t)(twos_comp_data)))

#endif /* SOURCE_PROJLIB_HX711_FREERTOS_H_ */
