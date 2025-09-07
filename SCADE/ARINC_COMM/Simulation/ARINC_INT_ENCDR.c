/* $ ANSYS SCADE Suite (R) Code Generator version Student 2022 R1 (build 20211130) 
** Command: scadecg.exe -config C:/Users/lukas/Documents/Repo/202502_REACT_ENG_CTRL/SCADE/ARINC_COMM/Simulation/config.txt
** Generation date: 2025-09-07T13:33:58
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "ARINC_INT_ENCDR.h"

/* ARINC_INT_ENCDR/ */
void ARINC_INT_ENCDR(inC_ARINC_INT_ENCDR *inC, outC_ARINC_INT_ENCDR *outC)
{
  outC->_L14 = inC->DATA;
  outC->_L33 = /* _L33= */(kcg_uint32) outC->_L14;
  outC->_L32 = kcg_lit_int8(10);
  outC->_L29 = kcg_lit_uint32(0x0007FFFF);
  outC->_L30 = outC->_L29 & outC->_L33;
  outC->_L31 = kcg_lsl_uint32(outC->_L30, outC->_L32);
  outC->_L8 = inC->SSM;
  outC->_L28 = /* _L28= */(kcg_uint32) outC->_L8;
  outC->_L12 = inC->SDI;
  outC->_L27 = /* _L27= */(kcg_uint32) outC->_L12;
  outC->_L22 = kcg_lit_uint32(0x00000003);
  outC->_L26 = outC->_L22 & outC->_L28;
  outC->_L20 = kcg_lit_uint32(0x00000003);
  outC->_L25 = outC->_L20 & outC->_L27;
  outC->_L5 = inC->LABEL;
  outC->_L13 = /* _L13= */(kcg_uint32) outC->_L5;
  outC->_L6 = kcg_lit_int8(8);
  outC->_L10 = kcg_lsl_uint32(outC->_L25, outC->_L6);
  outC->_L1 = kcg_lit_int8(29);
  outC->_L4 = kcg_lsl_uint32(outC->_L26, outC->_L1);
  outC->_L7 = kcg_lit_uint32(0x80000000);
  outC->_L2 = outC->_L7 | outC->_L4 | outC->_L31 | outC->_L10 | outC->_L13;
  outC->ARINCmsg = outC->_L2;
}

#ifndef KCG_USER_DEFINED_INIT
void ARINC_INT_ENCDR_init(outC_ARINC_INT_ENCDR *outC)
{
  outC->_L29 = kcg_lit_uint32(0);
  outC->_L30 = kcg_lit_uint32(0);
  outC->_L31 = kcg_lit_uint32(0);
  outC->_L32 = kcg_lit_int8(0);
  outC->_L33 = kcg_lit_uint32(0);
  outC->_L28 = kcg_lit_uint32(0);
  outC->_L27 = kcg_lit_uint32(0);
  outC->_L26 = kcg_lit_uint32(0);
  outC->_L25 = kcg_lit_uint32(0);
  outC->_L22 = kcg_lit_uint32(0);
  outC->_L20 = kcg_lit_uint32(0);
  outC->_L1 = kcg_lit_int8(0);
  outC->_L2 = kcg_lit_uint32(0);
  outC->_L4 = kcg_lit_uint32(0);
  outC->_L5 = kcg_lit_uint8(0);
  outC->_L6 = kcg_lit_int8(0);
  outC->_L7 = kcg_lit_uint32(0);
  outC->_L8 = kcg_lit_uint8(0);
  outC->_L10 = kcg_lit_uint32(0);
  outC->_L12 = kcg_lit_uint8(0);
  outC->_L13 = kcg_lit_uint32(0);
  outC->_L14 = kcg_lit_int32(0);
  outC->ARINCmsg = kcg_lit_uint32(0);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void ARINC_INT_ENCDR_reset(outC_ARINC_INT_ENCDR *outC)
{
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $ ANSYS SCADE Suite (R) Code Generator version Student 2022 R1 (build 20211130) 
** ARINC_INT_ENCDR.c
** Generation date: 2025-09-07T13:33:58
*************************************************************$ */

