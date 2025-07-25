/*
 * HX711_FREERTOS.h
 *
 *  Created on: 27 jun 2025
 *      Author: lukas
 */

#ifndef SOURCE_PROJLIB_HX711_FREERTOS_H_
#define SOURCE_PROJLIB_HX711_FREERTOS_H_

#include "sys_common.h"
#include "FreeRTOS.h"
#include "os_queue.h"
#include "gio.h"
#include "het.h"

/* Port/Pin Definition for HX711 */
// DT pin
#define PORT_HX711_DT   gioPORTA
#define PIN_HX711_DT    0x06U       // Data Out pin is [GIOA6]

// SCK pin
#define PORT_HX711_SCK  hetPORT1
#define PIN_HX711_SCK   0x10U       // Serial Clock pin is [NHET16]

// Gain Selectors
#define HX711_RES_64R_A     27U     // x64 Gain on channel A
#define HX711_RES_128R_A    25U     // x128 Gain on channel A
#define HX711_RES_32R_B     26U     // x32 Gain on channel B

/* Data Type Definition for HX711 */
#define HX711Data_t int32_t
#define HX711Buff_t uint32_t

/* Queue mgmt using FreeRTOS */
QueueHandle_t xQueue_HX711_RawQueue;    // HX711 sensor Raw Data queue

/* HX711 Macros */
#define DECODE_TWOS_COMPLEMENT( twos_comp_data ) (((twos_comp_data) & 0x800000) ? \
        ((int32_t)((twos_comp_data) | 0xFF000000)) : ((int32_t)(twos_comp_data)))

/* Function prototypes for HX711 */
void HX711_poll_from_GioNotif(BaseType_t *pxHigherPriorityTaskWoken);

#endif /* SOURCE_PROJLIB_HX711_FREERTOS_H_ */
