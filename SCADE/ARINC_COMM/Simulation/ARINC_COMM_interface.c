#include "ARINC_COMM_interface.h"
#include "ARINC_COMM_type.h"
#include "ARINC_COMM_mapping.h"
#include "SmuVTable.h"
#include <string.h>

#define UNUSED(x) (void)(x)
/* context */

inC_ARINC_INT_ENCDR inputs_ctx;
static inC_ARINC_INT_ENCDR inputs_ctx_execute;
outC_ARINC_INT_ENCDR outputs_ctx;

static void _SCSIM_RestoreInterface(void) {
    init_kcg_uint8(&inputs_ctx.LABEL);
    init_kcg_uint8(&inputs_ctx_execute.LABEL);
    init_kcg_uint8(&inputs_ctx.SDI);
    init_kcg_uint8(&inputs_ctx_execute.SDI);
    init_kcg_int32(&inputs_ctx.DATA);
    init_kcg_int32(&inputs_ctx_execute.DATA);
    init_kcg_uint8(&inputs_ctx.SSM);
    init_kcg_uint8(&inputs_ctx_execute.SSM);
    memset((void*)&outputs_ctx, 0, sizeof(outputs_ctx));
}

static void _SCSIM_ExecuteInterface(void) {
    pSimulator->m_pfnAcquireValueMutex(pSimulator);
    inputs_ctx_execute.LABEL = inputs_ctx.LABEL;
    inputs_ctx_execute.SDI = inputs_ctx.SDI;
    inputs_ctx_execute.DATA = inputs_ctx.DATA;
    inputs_ctx_execute.SSM = inputs_ctx.SSM;
    pSimulator->m_pfnReleaseValueMutex(pSimulator);
}

#ifdef __cplusplus
extern "C" {
#endif

const int  rt_version = Srtv62;

const char* _SCSIM_CheckSum = "4a6ce9e361247fe5efd1e4aa93cb5438";
const char* _SCSIM_SmuTypesCheckSum = "612a6f2dec6abe526bcaa0632c507adf";

/* simulation */

int SimInit(void) {
    int nRet = 0;
    _SCSIM_RestoreInterface();
#ifdef EXTENDED_SIM
    BeforeSimInit();
#endif
#ifndef KCG_USER_DEFINED_INIT
    ARINC_INT_ENCDR_init(&outputs_ctx);
    nRet = 1;
#else
    nRet = 0;
#endif
#ifdef EXTENDED_SIM
    AfterSimInit();
#endif
    return nRet;
}

int SimReset(void) {
    int nRet = 0;
    _SCSIM_RestoreInterface();
#ifdef EXTENDED_SIM
    BeforeSimInit();
#endif
#ifndef KCG_NO_EXTERN_CALL_TO_RESET
    ARINC_INT_ENCDR_reset(&outputs_ctx);
    nRet = 1;
#else
    nRet = 0;
#endif
#ifdef EXTENDED_SIM
    AfterSimInit();
#endif
    return nRet;
}

#ifdef __cplusplus
    #ifdef pSimoutC_ARINC_INT_ENCDRCIVTable_defined
        extern struct SimCustomInitVTable *pSimoutC_ARINC_INT_ENCDRCIVTable;
    #else 
        struct SimCustomInitVTable *pSimoutC_ARINC_INT_ENCDRCIVTable = NULL;
    #endif
#else
    struct SimCustomInitVTable *pSimoutC_ARINC_INT_ENCDRCIVTable;
#endif

int SimCustomInit(void) {
    int nRet = 0;
    if (pSimoutC_ARINC_INT_ENCDRCIVTable != NULL && 
        pSimoutC_ARINC_INT_ENCDRCIVTable->m_pfnCustomInit != NULL) {
        /* VTable function provided => call it */
        nRet = pSimoutC_ARINC_INT_ENCDRCIVTable->m_pfnCustomInit ((void*)&outputs_ctx);
    }
    else {
        /* VTable misssing => error */
        nRet = 0;
    }
    return nRet;
}

#ifdef EXTENDED_SIM
    int GraphicalInputsConnected = 1;
#endif

int SimStep(void) {
#ifdef EXTENDED_SIM
    if (GraphicalInputsConnected)
        BeforeSimStep();
#endif
    _SCSIM_ExecuteInterface();
    ARINC_INT_ENCDR(&inputs_ctx_execute, &outputs_ctx);
#ifdef EXTENDED_SIM
    AfterSimStep();
#endif
    return 1;
}

int SimStop(void) {
#ifdef EXTENDED_SIM
    ExtendedSimStop();
#endif
    return 1;
}

void SsmUpdateValues(void) {
#ifdef EXTENDED_SIM
    UpdateValues();
#endif
}

void SsmConnectExternalInputs(int bConnect) {
#ifdef EXTENDED_SIM
    GraphicalInputsConnected = bConnect;
#else
    UNUSED(bConnect);
#endif
}

/* dump */

int SsmGetDumpSize(void) {
    int nSize = 0;
    nSize += sizeof(inC_ARINC_INT_ENCDR);
    nSize += sizeof(outC_ARINC_INT_ENCDR);
#ifdef EXTENDED_SIM
    nSize += ExtendedGetDumpSize();
#endif
    return nSize;
}

void SsmGatherDumpData(char * pData) {
    char* pCurrent = pData;
    memcpy(pCurrent, &inputs_ctx, sizeof(inC_ARINC_INT_ENCDR));
    pCurrent += sizeof(inC_ARINC_INT_ENCDR);
    memcpy(pCurrent, &outputs_ctx, sizeof(outC_ARINC_INT_ENCDR));
    pCurrent += sizeof(outC_ARINC_INT_ENCDR);
#ifdef EXTENDED_SIM
    ExtendedGatherDumpData(pCurrent);
#endif
}

void SsmRestoreDumpData(const char * pData) {
    const char* pCurrent = pData;
    memcpy(&inputs_ctx, pCurrent, sizeof(inC_ARINC_INT_ENCDR));
    pCurrent += sizeof(inC_ARINC_INT_ENCDR);
    memcpy(&outputs_ctx, pCurrent, sizeof(outC_ARINC_INT_ENCDR));
    pCurrent += sizeof(outC_ARINC_INT_ENCDR);
#ifdef EXTENDED_SIM
    ExtendedRestoreDumpData(pCurrent);
#endif
}

/* snapshot */

int SsmSaveSnapshot(const char * szFilePath, size_t nCycle) {
    /* Test Services API not available */
    UNUSED(szFilePath);
    UNUSED(nCycle);
    return 0;
}

int SsmLoadSnapshot(const char * szFilePath, size_t *nCycle) {
    /* Test Services API not available */
    UNUSED(szFilePath);
    UNUSED(nCycle);
    return 0;
}

/* checksum */

const char * SsmGetCheckSum() {
    return _SCSIM_CheckSum;
}

const char * SsmGetSmuTypesCheckSum() {
    return _SCSIM_SmuTypesCheckSum;
}

#ifdef __cplusplus
} /* "C" */
#endif

