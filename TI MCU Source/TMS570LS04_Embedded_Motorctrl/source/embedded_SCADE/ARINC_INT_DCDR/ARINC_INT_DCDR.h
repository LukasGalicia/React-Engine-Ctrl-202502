/* $ ANSYS SCADE Suite (R) Code Generator version Student 2022 R1 (build 20211130) 
** Command: scadecg.exe -config C:/Users/lukas/Documents/Repo/202502_REACT_ENG_CTRL/SCADE/ARINC_COMM/Simulation/config.txt
** Generation date: 2025-09-07T13:22:18
*************************************************************$ */
#ifndef _ARINC_INT_DCDR_H_
#define _ARINC_INT_DCDR_H_

#include "kcg_types_global.h"

/* ========================  input structure  ====================== */
typedef struct {
  kcg_uint32 /* ARINCmsg/ */ ARINCmsg;
  kcg_bool /* ExpBCD/ */ ExpBCD;
} inC_ARINC_INT_DCDR;

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_uint8 /* SSM/ */ SSM;
  kcg_int32 /* DATA/ */ DATA;
  kcg_uint8 /* SDI/ */ SDI;
  kcg_uint8 /* LABEL/ */ LABEL;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* -------------------- no sub nodes' contexts  -------------------- */
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  kcg_uint32 /* raw_data/ */ raw_data;
  kcg_uint8 /* localSSM/ */ localSSM;
  kcg_uint32 /* _L1/ */ _L1;
  kcg_uint32 /* _L2/ */ _L2;
  kcg_uint32 /* _L3/ */ _L3;
  kcg_uint32 /* _L4/ */ _L4;
  kcg_uint8 /* _L5/ */ _L5;
  kcg_uint32 /* _L6/ */ _L6;
  kcg_uint32 /* _L7/ */ _L7;
  kcg_uint32 /* _L10/ */ _L10;
  kcg_int8 /* _L13/ */ _L13;
  kcg_int8 /* _L14/ */ _L14;
  kcg_int8 /* _L25/ */ _L25;
  kcg_uint8 /* _L24/ */ _L24;
  kcg_uint32 /* _L23/ */ _L23;
  kcg_uint32 /* _L22/ */ _L22;
  kcg_uint32 /* _L21/ */ _L21;
  kcg_uint32 /* _L31/ */ _L31;
  kcg_uint32 /* _L30/ */ _L30;
  kcg_uint8 /* _L32/ */ _L32;
  kcg_int32 /* _L41/ */ _L41;
  kcg_bool /* _L42/ */ _L42;
  kcg_uint32 /* _L44/ */ _L44;
  kcg_int32 /* _L45/ */ _L45;
  kcg_uint32 /* _L46/ */ _L46;
  kcg_uint32 /* _L47/ */ _L47;
  kcg_uint32 /* _L48/ */ _L48;
  kcg_int32 /* _L52/ */ _L52;
  kcg_bool /* _L56/ */ _L56;
  kcg_uint8 /* _L57/ */ _L57;
  kcg_uint8 /* _L58/ */ _L58;
  kcg_bool /* _L59/ */ _L59;
} outC_ARINC_INT_DCDR;

/* ===========  node initialization and cycle functions  =========== */
/* ARINC_INT_DCDR/ */
extern void ARINC_INT_DCDR(inC_ARINC_INT_DCDR *inC, outC_ARINC_INT_DCDR *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void ARINC_INT_DCDR_reset(outC_ARINC_INT_DCDR *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void ARINC_INT_DCDR_init(outC_ARINC_INT_DCDR *outC);
#endif /* KCG_USER_DEFINED_INIT */



#endif /* _ARINC_INT_DCDR_H_ */
/* $ ANSYS SCADE Suite (R) Code Generator version Student 2022 R1 (build 20211130) 
** ARINC_INT_DCDR.h
** Generation date: 2025-09-07T13:22:18
*************************************************************$ */

