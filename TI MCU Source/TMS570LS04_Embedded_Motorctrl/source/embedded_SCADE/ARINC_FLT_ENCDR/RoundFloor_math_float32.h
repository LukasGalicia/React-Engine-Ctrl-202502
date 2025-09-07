/* $ ANSYS SCADE Suite (R) Code Generator version Student 2022 R1 (build 20211130) 
** Command: scadecg.exe -config C:/Users/lukas/Documents/Repo/202502_REACT_ENG_CTRL/SCADE/ARINC_COMM/Simulation/config.txt
** Generation date: 2025-09-07T13:12:44
*************************************************************$ */
#ifndef _RoundFloor_math_float32_H_
#define _RoundFloor_math_float32_H_

#include "kcg_types_global.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_int32 /* RF_Output/ */ RF_Output_float32;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  kcg_float32 /* _L1/ */ _L1_float32;
  kcg_bool /* _L24/ */ _L24_float32;
  kcg_float32 /* _L25/ */ _L25_float32;
  kcg_int32 /* _L26/ */ _L26_float32;
  kcg_float32 /* _L30/ */ _L30_float32;
  kcg_float32 /* _L31/ */ _L31_float32;
  kcg_int32 /* _L32/ */ _L32_float32;
  kcg_int32 /* _L33/ */ _L33_float32;
  kcg_int32 /* _L38/ */ _L38_float32;
  kcg_float32 /* _L41/ */ _L41_float32;
  kcg_bool /* _L43/ */ _L43_float32;
} outC_RoundFloor_math_float32;

/* ===========  node initialization and cycle functions  =========== */
/* math::RoundFloor/ */
extern void RoundFloor_math_float32(
  /* RF_Input/ */
  kcg_float32 RF_Input_float32,
  outC_RoundFloor_math_float32 *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void RoundFloor_reset_math_float32(outC_RoundFloor_math_float32 *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void RoundFloor_init_math_float32(outC_RoundFloor_math_float32 *outC);
#endif /* KCG_USER_DEFINED_INIT */



#endif /* _RoundFloor_math_float32_H_ */
/* $ ANSYS SCADE Suite (R) Code Generator version Student 2022 R1 (build 20211130) 
** RoundFloor_math_float32.h
** Generation date: 2025-09-07T13:12:44
*************************************************************$ */

