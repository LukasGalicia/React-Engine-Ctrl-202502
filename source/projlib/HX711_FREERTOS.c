/*
 * HX711_FREERTOS.c
 *
 *  Created on: 27 jun 2025
 *      Author: lukas
 */

#include "HX711_FREERTOS.h"

/**
 * @brief Polls the HX711 load cell amplifier from a GPIO interrupt context.
 *
 * Reads an HX711 sample via bit-banged SCK pulses and pushes the result to a FreeRTOS queue.
 * Intended to be called within the HX711 DT pin interrupt.
 *
 * @param[in,out] pxHigherPriorityTaskWoken Pointer used to indicate whether a context switch
 *                                          should be requested at the end of the ISR. Pass this
 *                                          to `portYIELD_FROM_ISR()` if needed.
 *
 * @note
 * - This function should be called from an ISR (e.g., GIO interrupt handler).
 * - Make sure the DT pin interrupt is re-enabled elsewhere after processing.
 * - Ensure `xQueue_HX711_RawQueue` is initialized before calling this function.
 */
void HX711_poll_from_GioNotif(BaseType_t *pxHigherPriorityTaskWoken)
{
    /* Variables for HX711 polling */
    HX711Buff_t HX711_data_buff;
    uint8_t HX711_data_count;

    gioDisableNotification(PORT_HX711_DT, PIN_HX711_DT);    // Disable DT pin IRQ

    HX711_data_buff = 0x00000000U;      // Reset data buffer
    HX711_data_count = 0U;              // Reset data bit counter

    /* HX711 DATA ACQ BEGIN */
    while(++HX711_data_count <= HX711_RES_128R_A)           // Generate HX711 pulse train
    {
        gioToggleBit(PORT_HX711_SCK, PIN_HX711_SCK);
        gioToggleBit(PORT_HX711_SCK, PIN_HX711_SCK);
        if(HX711_data_count <= 24)
            HX711_data_buff = (HX711_data_buff << 1) | gioGetBit(PORT_HX711_DT, PIN_HX711_DT);
    }
    /* HX711 DATA ACQ END*/

    xQueueSendFromISR(xQueue_HX711_RawQueue, &HX711_data_buff, pxHigherPriorityTaskWoken);      // Send HX711 acquired raw data
}
