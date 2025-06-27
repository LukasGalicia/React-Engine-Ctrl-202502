/*
 * HX711_FREERTOS.c
 *
 *  Created on: 27 jun 2025
 *      Author: lukas
 */

#include "HX711_FREERTOS.h"

/* Variable Initialization for HX711 */

volatile uint32_t HX711_data_buff = 0x00000000U;
