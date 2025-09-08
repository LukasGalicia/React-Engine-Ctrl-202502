/*
 * CROSSCHANNEL.c
 *
 *  Created on: 4 sep 2025
 *      Author: lukas
 */

/* Include files */
#include "CROSSCHANNEL.h"

spiDAT1_t CCSpiDataFmt =
{
 false,
 false,
 SPI_FMT_0,
 SPI_CS_0
};

/* Cross-channel Comm functions */
void CrossChTransmitInt(ARINC_Frame_Mdata MsgMdata, int32_t MsgDATA)
{
    // ARINC encode assigns
    CCmsg_INT_DATA_OUTBOUND.LABEL = MsgMdata.LABEL;
    CCmsg_INT_DATA_OUTBOUND.SDI = MsgMdata.SDI;
    CCmsg_INT_DATA_OUTBOUND.SSM = MsgMdata.SSM;
    CCmsg_INT_DATA_OUTBOUND.DATA = MsgDATA;

    ARINC_INT_ENCDR(&CCmsg_INT_DATA_OUTBOUND, &CCmsg_INT_FRAME_OUTBOUND);                                           // Encode ARINC message
    spiTransmitData(spiREG3, &CCSpiDataFmt, SPI_blocksize, (uint16_t *) &(CCmsg_INT_FRAME_OUTBOUND.ARINCmsg));      // Send SPI data
}

void CrossChTransmitFlt(ARINC_Frame_Mdata MsgMdata, float32 MsgDATA, float32 dataMIN, float32 dataMAX)
{
    // Float range boundaries
    CCmsg_FLT_DATA_OUTBOUND.Range_Min = dataMIN;
    CCmsg_FLT_DATA_OUTBOUND.Range_Max = dataMAX;

    // ARINC encoder assigns
    CCmsg_FLT_DATA_OUTBOUND.LABEL = MsgMdata.LABEL;
    CCmsg_FLT_DATA_OUTBOUND.SDI = MsgMdata.SDI;
    CCmsg_FLT_DATA_OUTBOUND.SSM = MsgMdata.SSM;
    CCmsg_FLT_DATA_OUTBOUND.DATA = MsgDATA;

    ARINC_FLT_ENCDR(&CCmsg_FLT_DATA_OUTBOUND, &CCmsg_FLT_FRAME_OUTBOUND);
    spiTransmitData(spiREG3, &CCSpiDataFmt, SPI_blocksize, (uint16_t *) &(CCmsg_FLT_FRAME_OUTBOUND.ARINCmsg));
}

void CrossChReceiveInt(ARINC_Frame_Mdata *MsgMdata, int32_t *MsgDATA, bool negValExp)
{
    CCmsg_INT_FRAME_INBOUND.ExpBCD = negValExp;     // Is negative value expected?

    spiReceiveData(spiREG3, &CCSpiDataFmt, SPI_blocksize, (uint16_t *) &(CCmsg_INT_FRAME_INBOUND.ARINCmsg));        // Get SPI data
    ARINC_INT_DCDR(&CCmsg_INT_FRAME_INBOUND, &CCmsg_INT_DATA_INBOUND);                                              // Decode ARINC message

    // ARINC decoded assigns
    MsgMdata->LABEL = CCmsg_INT_DATA_INBOUND.LABEL;
    MsgMdata->SDI = CCmsg_INT_DATA_INBOUND.SDI;
    MsgMdata->SSM = CCmsg_INT_DATA_INBOUND.SSM;
    *MsgDATA = CCmsg_INT_DATA_INBOUND.DATA;
}

void CrossChReceiveFlt(ARINC_Frame_Mdata *MsgMdata, float32 *MsgDATA, float32 dataMIN, float32 dataMAX)
{
    // Float range boundaries
    CCmsg_FLT_FRAME_INBOUND.Range_Min = dataMIN;
    CCmsg_FLT_FRAME_INBOUND.Range_Max = dataMAX;

    spiReceiveData(spiREG3, &CCSpiDataFmt, SPI_blocksize, (uint16_t *) &(CCmsg_FLT_FRAME_INBOUND.ARINCmsg));        // Get SPI data
    ARINC_FLT_DCDR(&CCmsg_FLT_FRAME_INBOUND, &CCmsg_FLT_DATA_INBOUND);                                              // Decode ARINC message

    // ARINC decoded assigns
    MsgMdata->LABEL = CCmsg_FLT_DATA_INBOUND.LABEL;
    MsgMdata->SDI = CCmsg_FLT_DATA_INBOUND.SDI;
    MsgMdata->SSM = CCmsg_FLT_DATA_INBOUND.SSM;
    *MsgDATA = CCmsg_FLT_DATA_INBOUND.DATA;
}

void CrossChTransmitandReceiveINT(ARINC_Frame_Mdata *inFrameData, int32_t *inDATA,
                                  ARINC_Frame_Mdata outFrameData, int32_t outDATA, bool negValExp)
{
    CCmsg_INT_FRAME_INBOUND.ExpBCD = negValExp;     // Is negative value expected?

    // ARINC encode assigns
    CCmsg_INT_DATA_OUTBOUND.LABEL = outFrameData.LABEL;
    CCmsg_INT_DATA_OUTBOUND.SDI = outFrameData.SDI;
    CCmsg_INT_DATA_OUTBOUND.SSM = outFrameData.SSM;
    CCmsg_INT_DATA_OUTBOUND.DATA = outDATA;

    ARINC_INT_ENCDR(&CCmsg_INT_DATA_OUTBOUND, &CCmsg_INT_FRAME_OUTBOUND);               // Encode ARINC message
    spiTransmitAndReceiveData(spiREG3, &CCSpiDataFmt, SPI_blocksize,                    // Send & get SPI data
                              (uint16_t *) &(CCmsg_INT_FRAME_OUTBOUND.ARINCmsg),
                              (uint16_t *) &(CCmsg_INT_FRAME_INBOUND.ARINCmsg));
    ARINC_INT_DCDR(&CCmsg_INT_FRAME_INBOUND, &CCmsg_INT_DATA_INBOUND);                  // Decode ARINC message

    // ARINC decoded assigns
    inFrameData->LABEL = CCmsg_INT_DATA_INBOUND.LABEL;
    inFrameData->SDI = CCmsg_INT_DATA_INBOUND.SDI;
    inFrameData->SSM = CCmsg_INT_DATA_INBOUND.SSM;
    *inDATA = CCmsg_INT_DATA_INBOUND.DATA;
}

void CrossChTransmitandReceiveFLT(ARINC_Frame_Mdata *inFrameData, float32 *inDATA, ARINC_Frame_Mdata outFrameData, float32 outDATA,
                                  float32 dataMIN, float32 dataMAX)
{
    // Float range boundaries
    CCmsg_FLT_DATA_OUTBOUND.Range_Min = CCmsg_FLT_FRAME_INBOUND.Range_Min = dataMIN;
    CCmsg_FLT_DATA_OUTBOUND.Range_Max = CCmsg_FLT_FRAME_INBOUND.Range_Max = dataMAX;

    // ARINC encode assigns
    CCmsg_FLT_DATA_OUTBOUND.LABEL = outFrameData.LABEL;
    CCmsg_FLT_DATA_OUTBOUND.SDI = outFrameData.SDI;
    CCmsg_FLT_DATA_OUTBOUND.SSM = outFrameData.SSM;
    CCmsg_FLT_DATA_OUTBOUND.DATA = outDATA;

    ARINC_FLT_ENCDR(&CCmsg_FLT_DATA_OUTBOUND, &CCmsg_FLT_FRAME_OUTBOUND);               // Encode ARINC message
    spiTransmitAndReceiveData(spiREG3, &CCSpiDataFmt, SPI_blocksize,                    // Send & get SPI data
                              (uint16_t *) &(CCmsg_FLT_FRAME_OUTBOUND.ARINCmsg),
                              (uint16_t *) &(CCmsg_FLT_FRAME_INBOUND.ARINCmsg));
    ARINC_FLT_DCDR(&CCmsg_FLT_FRAME_INBOUND, &CCmsg_FLT_DATA_INBOUND);                  // Decode ARINC message

    // ARINC decoded assigns
    inFrameData->LABEL = CCmsg_FLT_DATA_INBOUND.LABEL;
    inFrameData->SDI = CCmsg_FLT_DATA_INBOUND.SDI;
    inFrameData->SSM = CCmsg_FLT_DATA_INBOUND.SSM;
    *inDATA = CCmsg_FLT_DATA_INBOUND.DATA;
}
