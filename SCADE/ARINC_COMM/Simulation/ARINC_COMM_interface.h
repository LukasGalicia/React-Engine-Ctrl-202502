#ifndef ARINC_COMM_INTERFACE_H_
#define ARINC_COMM_INTERFACE_H_

#include "kcg_sensors.h"
#include "SmuProxy.h"
#include "ARINC_INT_DCDR.h"

/* context */

extern inC_ARINC_INT_DCDR inputs_ctx;
extern outC_ARINC_INT_DCDR outputs_ctx;

#ifdef __cplusplus
extern "C" {
#endif

extern SimSimulator * pSimulator;

/* simulation */

#ifdef EXTENDED_SIM
    void BeforeSimInit();
    void AfterSimInit();
    void BeforeSimStep();
    void AfterSimStep();
    void ExtendedSimStop();
    void ExtendedGatherDumpData(char * pData);
    void ExtendedRestoreDumpData(const char * pData);
    int ExtendedGetDumpSize();
    void UpdateValues();
    extern void UpdateSimulatorValues();
    extern int GraphicalInputsConnected;
#endif

/* logging */

#define SIM_INFO    1
#define SIM_WARNING 2
#define SIM_ERROR   3
extern void SsmOutputMessage(int level, const char* str);

#ifdef __cplusplus
} /* "C" */
#endif

#endif /* ARINC_COMM_INTERFACE_H_ */
