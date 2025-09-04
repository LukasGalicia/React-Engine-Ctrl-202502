/* $ ANSYS SCADE Suite (R) Code Generator version Student 2022 R1 (build 20211130) 
** Command: scadecg.exe -config C:/Users/lukas/Documents/Repo/202502_REACT_ENG_CTRL/SCADE/ARINC_COMM/Simulation/config.txt
** Generation date: 2025-09-04T07:15:09
*************************************************************$ */
#ifndef _ARINC_INT_ENCDR_H_
#define _ARINC_INT_ENCDR_H_

#include "kcg_types.h"
#include "Int_data_bmask.h"

/* ========================  input structure  ====================== */
typedef struct {
  kcg_uint8 /* LABEL/ */ LABEL;
  kcg_uint8 /* SDI/ */ SDI;
  kcg_int32 /* DATA/ */ DATA;
  kcg_uint8 /* SSM/ */ SSM;
} inC_ARINC_INT_ENCDR;

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_uint32 /* ARINCmsg/ */ ARINCmsg;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_Int_data_bmask /* _L15=(Int_data_bmask#1)/ */ Context_Int_data_bmask_1;
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  kcg_int32 /* _L14/ */ _L14;
  kcg_uint32 /* _L13/ */ _L13;
  kcg_uint8 /* _L12/ */ _L12;
  kcg_uint32 /* _L10/ */ _L10;
  kcg_uint8 /* _L8/ */ _L8;
  kcg_uint32 /* _L7/ */ _L7;
  kcg_int8 /* _L6/ */ _L6;
  kcg_uint8 /* _L5/ */ _L5;
  kcg_uint32 /* _L4/ */ _L4;
  kcg_uint32 /* _L2/ */ _L2;
  kcg_int8 /* _L1/ */ _L1;
  kcg_uint32 /* _L15/ */ _L15;
  kcg_uint32 /* _L20/ */ _L20;
  kcg_uint32 /* _L22/ */ _L22;
  kcg_uint32 /* _L25/ */ _L25;
  kcg_uint32 /* _L26/ */ _L26;
  kcg_uint32 /* _L27/ */ _L27;
  kcg_uint32 /* _L28/ */ _L28;
} outC_ARINC_INT_ENCDR;

/* ===========  node initialization and cycle functions  =========== */
/* ARINC_INT_ENCDR/ */
extern void ARINC_INT_ENCDR(
  inC_ARINC_INT_ENCDR *inC,
  outC_ARINC_INT_ENCDR *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void ARINC_INT_ENCDR_reset(outC_ARINC_INT_ENCDR *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void ARINC_INT_ENCDR_init(outC_ARINC_INT_ENCDR *outC);
#endif /* KCG_USER_DEFINED_INIT */



#endif /* _ARINC_INT_ENCDR_H_ */
/* $ ANSYS SCADE Suite (R) Code Generator version Student 2022 R1 (build 20211130) 
** ARINC_INT_ENCDR.h
** Generation date: 2025-09-04T07:15:09
*************************************************************$ */

