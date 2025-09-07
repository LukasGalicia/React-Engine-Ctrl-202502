/* $ ANSYS SCADE Suite (R) Code Generator version Student 2022 R1 (build 20211130) 
** Command: scadecg.exe -config C:/Users/lukas/Documents/Repo/202502_REACT_ENG_CTRL/SCADE/ARINC_COMM/Simulation/config.txt
** Generation date: 2025-09-07T13:55:47
*************************************************************$ */
#ifndef _ARINC_FLT_ENCDR_H_
#define _ARINC_FLT_ENCDR_H_

#include "kcg_types.h"
#include "RoundFloor_math_float32.h"

/* ========================  input structure  ====================== */
typedef struct {
  kcg_float32 /* DATA/ */ DATA;
  kcg_uint8 /* SDI/ */ SDI;
  kcg_uint8 /* SSM/ */ SSM;
  kcg_uint8 /* LABEL/ */ LABEL;
  kcg_float32 /* Range_Min/ */ Range_Min;
  kcg_float32 /* Range_Max/ */ Range_Max;
} inC_ARINC_FLT_ENCDR;

/* =====================  no output structure  ====================== */

/* ========================  context type  ========================= */
typedef struct {
  /* ---------------------------  outputs  --------------------------- */
  kcg_uint32 /* ARINCmsg/ */ ARINCmsg;
  /* -----------------------  no local probes  ----------------------- */
  /* -----------------------  no local memory  ----------------------- */
  /* ---------------------  sub nodes' contexts  --------------------- */
  outC_RoundFloor_math_float32 /* _L33=(math::RoundFloor#2)/ */ Context_RoundFloor_2;
  /* ----------------- no clocks of observable data ------------------ */
  /* -------------------- (-debug) no assertions  -------------------- */
  /* ------------------- (-debug) local variables -------------------- */
  kcg_int32 /* inrangedata/ */ inrangedata;
  kcg_uint32 /* _L22/ */ _L22;
  kcg_uint32 /* _L21/ */ _L21;
  kcg_uint32 /* _L20/ */ _L20;
  kcg_uint8 /* _L19/ */ _L19;
  kcg_uint32 /* _L18/ */ _L18;
  kcg_uint32 /* _L17/ */ _L17;
  kcg_uint32 /* _L16/ */ _L16;
  kcg_uint8 /* _L15/ */ _L15;
  kcg_int8 /* _L14/ */ _L14;
  kcg_uint32 /* _L12/ */ _L12;
  kcg_int8 /* _L11/ */ _L11;
  kcg_uint32 /* _L10/ */ _L10;
  kcg_uint32 /* _L9/ */ _L9;
  kcg_uint32 /* _L8/ */ _L8;
  kcg_uint32 /* _L7/ */ _L7;
  kcg_uint32 /* _L6/ */ _L6;
  kcg_int8 /* _L5/ */ _L5;
  kcg_uint8 /* _L4/ */ _L4;
  kcg_uint32 /* _L3/ */ _L3;
  kcg_uint32 /* _L2/ */ _L2;
  kcg_uint32 /* _L1/ */ _L1;
  kcg_float32 /* _L23/ */ _L23;
  kcg_float32 /* _L24/ */ _L24;
  kcg_float32 /* _L25/ */ _L25;
  kcg_float32 /* _L26/ */ _L26;
  kcg_float32 /* _L27/ */ _L27;
  kcg_float32 /* _L28/ */ _L28;
  kcg_float32 /* _L29/ */ _L29;
  kcg_int32 /* _L33/ */ _L33;
  kcg_int32 /* _L35/ */ _L35;
  kcg_float32 /* _L37/ */ _L37;
  kcg_float32 /* _L38/ */ _L38;
} outC_ARINC_FLT_ENCDR;

/* ===========  node initialization and cycle functions  =========== */
/* ARINC_FLT_ENCDR/ */
extern void ARINC_FLT_ENCDR(
  inC_ARINC_FLT_ENCDR *inC,
  outC_ARINC_FLT_ENCDR *outC);

#ifndef KCG_NO_EXTERN_CALL_TO_RESET
extern void ARINC_FLT_ENCDR_reset(outC_ARINC_FLT_ENCDR *outC);
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

#ifndef KCG_USER_DEFINED_INIT
extern void ARINC_FLT_ENCDR_init(outC_ARINC_FLT_ENCDR *outC);
#endif /* KCG_USER_DEFINED_INIT */



#endif /* _ARINC_FLT_ENCDR_H_ */
/* $ ANSYS SCADE Suite (R) Code Generator version Student 2022 R1 (build 20211130) 
** ARINC_FLT_ENCDR.h
** Generation date: 2025-09-07T13:55:47
*************************************************************$ */

