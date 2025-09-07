/*
 * SCADE_global_lib.c
 *
 *  Created on: 7 sep 2025
 *      Author: lukas
 */

#include "SCADE_global_lib.h"
#include "CROSSCHANNEL.h"

/** @fn     void SCADEInit(void)
 *  @brief  SCADE Models initialization
 *
 */
void SCADEInit(void)
{
    ARINC_INT_ENCDR_init(&CCmsg_INT_FRAME_OUTBOUND);
    ARINC_INT_DCDR_init(&CCmsg_INT_DATA_INBOUND);
    ARINC_FLT_ENCDR_init(&CCmsg_FLT_FRAME_OUTBOUND);
    ARINC_FLT_DCDR_init(&CCmsg_FLT_DATA_INBOUND);
}

