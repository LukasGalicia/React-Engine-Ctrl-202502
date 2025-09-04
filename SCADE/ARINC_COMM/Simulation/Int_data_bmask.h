/* $ ANSYS SCADE Suite (R) Code Generator version Student 2022 R1 (build 20211130) 
** Command: scadecg.exe -config C:/Users/lukas/Documents/Repo/202502_REACT_ENG_CTRL/SCADE/ARINC_COMM/Simulation/config.txt
** Generation date: 2025-09-04T07:15:09
*************************************************************$ */
#ifndef _Int_data_bmask_H_
#define _Int_data_bmask_H_

#include "kcg_types.h"

/* =====================  no input structure  ====================== */

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_uint32 /* outdata/ */ outdata;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  kcg_int8 /* _L6/ */ _L6;
  kcg_uint32 /* _L4/ */ _L4;
  kcg_uint32 /* _L3/ */ _L3;
  kcg_int32 /* _L2/ */ _L2;
  kcg_uint32 /* _L5/ */ _L5;
  kcg_uint32 /* _L1/ */ _L1;
} outC_Int_data_bmask;

/* ===========  node initialization and cycle functions  =========== */
/* Int_data_bmask/ */
extern void Int_data_bmask(
  /* data_in/ */
  kcg_int32 data_in,
  outC_Int_data_bmask *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void Int_data_bmask_reset(outC_Int_data_bmask *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void Int_data_bmask_init(outC_Int_data_bmask *outC);
#endif /* KCG_USER_DEFINED_INIT */



#endif /* _Int_data_bmask_H_ */
/* $ ANSYS SCADE Suite (R) Code Generator version Student 2022 R1 (build 20211130) 
** Int_data_bmask.h
** Generation date: 2025-09-04T07:15:09
*************************************************************$ */

