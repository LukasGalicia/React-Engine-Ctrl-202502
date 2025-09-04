/* $ ANSYS SCADE Suite (R) Code Generator version Student 2022 R1 (build 20211130) 
** Command: scadecg.exe -config C:/Users/lukas/Documents/Repo/202502_REACT_ENG_CTRL/SCADE/ARINC_COMM/Simulation/config.txt
** Generation date: 2025-09-04T07:10:56
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "ARINC_INT_DCDR.h"

/* ARINC_INT_DCDR/ */
void ARINC_INT_DCDR(inC_ARINC_INT_DCDR *inC, outC_ARINC_INT_DCDR *outC)
{
  outC->_L1 = inC->ARINCmsg;
  outC->_L30 = kcg_lit_uint32(0x000000FF);
  outC->_L31 = outC->_L30 & outC->_L1;
  outC->_L32 = /* _L32= */(kcg_uint8) outC->_L31;
  outC->LABEL = outC->_L32;
  outC->_L25 = kcg_lit_int8(8);
  outC->_L21 = kcg_lit_uint32(0x00000300);
  outC->_L22 = outC->_L21 & outC->_L1;
  outC->_L23 = outC->_L22 >> outC->_L25;
  outC->_L24 = /* _L24= */(kcg_uint8) outC->_L23;
  outC->SDI = outC->_L24;
  outC->_L14 = kcg_lit_int8(10);
  outC->_L7 = kcg_lit_uint32(0x1FFFFC00);
  outC->_L6 = outC->_L7 & outC->_L1;
  outC->_L10 = outC->_L6 >> outC->_L14;
  outC->_L15 = /* _L15= */(kcg_int32) outC->_L10;
  outC->DATA = outC->_L15;
  outC->_L13 = kcg_lit_int8(29);
  outC->_L3 = kcg_lit_uint32(0x60000000);
  outC->_L2 = outC->_L3 & outC->_L1;
  outC->_L4 = outC->_L2 >> outC->_L13;
  outC->_L5 = /* _L5= */(kcg_uint8) outC->_L4;
  outC->SSM = outC->_L5;
}

#ifndef KCG_USER_DEFINED_INIT
void ARINC_INT_DCDR_init(outC_ARINC_INT_DCDR *outC)
{
  outC->_L32 = kcg_lit_uint8(0);
  outC->_L30 = kcg_lit_uint32(0);
  outC->_L31 = kcg_lit_uint32(0);
  outC->_L21 = kcg_lit_uint32(0);
  outC->_L22 = kcg_lit_uint32(0);
  outC->_L23 = kcg_lit_uint32(0);
  outC->_L24 = kcg_lit_uint8(0);
  outC->_L25 = kcg_lit_int8(0);
  outC->_L15 = kcg_lit_int32(0);
  outC->_L14 = kcg_lit_int8(0);
  outC->_L13 = kcg_lit_int8(0);
  outC->_L10 = kcg_lit_uint32(0);
  outC->_L7 = kcg_lit_uint32(0);
  outC->_L6 = kcg_lit_uint32(0);
  outC->_L5 = kcg_lit_uint8(0);
  outC->_L4 = kcg_lit_uint32(0);
  outC->_L3 = kcg_lit_uint32(0);
  outC->_L2 = kcg_lit_uint32(0);
  outC->_L1 = kcg_lit_uint32(0);
  outC->LABEL = kcg_lit_uint8(0);
  outC->SDI = kcg_lit_uint8(0);
  outC->DATA = kcg_lit_int32(0);
  outC->SSM = kcg_lit_uint8(0);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void ARINC_INT_DCDR_reset(outC_ARINC_INT_DCDR *outC)
{
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $ ANSYS SCADE Suite (R) Code Generator version Student 2022 R1 (build 20211130) 
** ARINC_INT_DCDR.c
** Generation date: 2025-09-04T07:10:56
*************************************************************$ */

