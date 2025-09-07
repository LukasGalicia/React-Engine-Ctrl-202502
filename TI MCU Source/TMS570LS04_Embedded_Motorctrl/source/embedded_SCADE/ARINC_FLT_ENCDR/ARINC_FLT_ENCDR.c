/* $ ANSYS SCADE Suite (R) Code Generator version Student 2022 R1 (build 20211130) 
** Command: scadecg.exe -config C:/Users/lukas/Documents/Repo/202502_REACT_ENG_CTRL/SCADE/ARINC_COMM/Simulation/config.txt
** Generation date: 2025-09-07T13:12:44
*************************************************************$ */

#include "kcg_consts_global.h"
#include "kcg_sensors_global.h"
#include "ARINC_FLT_ENCDR.h"

/* ARINC_FLT_ENCDR/ */
void ARINC_FLT_ENCDR(inC_ARINC_FLT_ENCDR *inC, outC_ARINC_FLT_ENCDR *outC)
{
  outC->_L38 = inC->Range_Min;
  outC->_L28 = inC->DATA;
  outC->_L37 = outC->_L28 - outC->_L38;
  outC->_L27 = kcg_lit_float32(524288.0);
  outC->_L23 = inC->Range_Min;
  outC->_L24 = inC->Range_Max;
  outC->_L25 = outC->_L24 - outC->_L23;
  outC->_L26 = outC->_L25 / outC->_L27;
  outC->_L29 = outC->_L37 / outC->_L26;
  /* _L33=(math::RoundFloor#2)/ */
  RoundFloor_math_float32(outC->_L29, &outC->Context_RoundFloor_2);
  outC->_L33 = outC->Context_RoundFloor_2.RF_Output_float32;
  outC->inrangedata = outC->_L33;
  outC->_L35 = outC->inrangedata;
  outC->_L19 = inC->SDI;
  outC->_L1 = /* _L1= */(kcg_uint32) outC->_L19;
  outC->_L21 = kcg_lit_uint32(0x00000003);
  outC->_L22 = outC->_L21 & outC->_L1;
  outC->_L5 = kcg_lit_int8(10);
  outC->_L10 = /* _L10= */(kcg_uint32) outC->_L35;
  outC->_L6 = kcg_lit_uint32(0x0007FFFF);
  outC->_L3 = outC->_L6 & outC->_L10;
  outC->_L20 = kcg_lsl_uint32(outC->_L3, outC->_L5);
  outC->_L4 = inC->SSM;
  outC->_L8 = /* _L8= */(kcg_uint32) outC->_L4;
  outC->_L2 = kcg_lit_uint32(0x00000003);
  outC->_L18 = outC->_L2 & outC->_L8;
  outC->_L14 = kcg_lit_int8(29);
  outC->_L17 = kcg_lsl_uint32(outC->_L18, outC->_L14);
  outC->_L15 = inC->LABEL;
  outC->_L16 = /* _L16= */(kcg_uint32) outC->_L15;
  outC->_L11 = kcg_lit_int8(8);
  outC->_L7 = kcg_lsl_uint32(outC->_L22, outC->_L11);
  outC->_L9 = kcg_lit_uint32(0x80000000);
  outC->_L12 = outC->_L9 | outC->_L17 | outC->_L20 | outC->_L7 | outC->_L16;
  outC->ARINCmsg = outC->_L12;
}

#ifndef KCG_USER_DEFINED_INIT
void ARINC_FLT_ENCDR_init(outC_ARINC_FLT_ENCDR *outC)
{
  outC->_L38 = kcg_lit_float32(0.0);
  outC->_L37 = kcg_lit_float32(0.0);
  outC->_L35 = kcg_lit_int32(0);
  outC->_L33 = kcg_lit_int32(0);
  outC->_L29 = kcg_lit_float32(0.0);
  outC->_L28 = kcg_lit_float32(0.0);
  outC->_L27 = kcg_lit_float32(0.0);
  outC->_L26 = kcg_lit_float32(0.0);
  outC->_L25 = kcg_lit_float32(0.0);
  outC->_L24 = kcg_lit_float32(0.0);
  outC->_L23 = kcg_lit_float32(0.0);
  outC->_L1 = kcg_lit_uint32(0);
  outC->_L2 = kcg_lit_uint32(0);
  outC->_L3 = kcg_lit_uint32(0);
  outC->_L4 = kcg_lit_uint8(0);
  outC->_L5 = kcg_lit_int8(0);
  outC->_L6 = kcg_lit_uint32(0);
  outC->_L7 = kcg_lit_uint32(0);
  outC->_L8 = kcg_lit_uint32(0);
  outC->_L9 = kcg_lit_uint32(0);
  outC->_L10 = kcg_lit_uint32(0);
  outC->_L11 = kcg_lit_int8(0);
  outC->_L12 = kcg_lit_uint32(0);
  outC->_L14 = kcg_lit_int8(0);
  outC->_L15 = kcg_lit_uint8(0);
  outC->_L16 = kcg_lit_uint32(0);
  outC->_L17 = kcg_lit_uint32(0);
  outC->_L18 = kcg_lit_uint32(0);
  outC->_L19 = kcg_lit_uint8(0);
  outC->_L20 = kcg_lit_uint32(0);
  outC->_L21 = kcg_lit_uint32(0);
  outC->_L22 = kcg_lit_uint32(0);
  outC->inrangedata = kcg_lit_int32(0);
  outC->ARINCmsg = kcg_lit_uint32(0);
  /* _L33=(math::RoundFloor#2)/ */
  RoundFloor_init_math_float32(&outC->Context_RoundFloor_2);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void ARINC_FLT_ENCDR_reset(outC_ARINC_FLT_ENCDR *outC)
{
  /* _L33=(math::RoundFloor#2)/ */
  RoundFloor_reset_math_float32(&outC->Context_RoundFloor_2);
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $ ANSYS SCADE Suite (R) Code Generator version Student 2022 R1 (build 20211130) 
** ARINC_FLT_ENCDR.c
** Generation date: 2025-09-07T13:12:44
*************************************************************$ */

