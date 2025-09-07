/* $ ANSYS SCADE Suite (R) Code Generator version Student 2022 R1 (build 20211130) 
** Command: scadecg.exe -config C:/Users/lukas/Documents/Repo/202502_REACT_ENG_CTRL/SCADE/ARINC_COMM/Simulation/config.txt
** Generation date: 2025-09-07T13:18:38
*************************************************************$ */

#include "kcg_consts_global.h"
#include "kcg_sensors_global.h"
#include "ARINC_FLT_DCDR.h"

/* ARINC_FLT_DCDR/ */
void ARINC_FLT_DCDR(inC_ARINC_FLT_DCDR *inC, outC_ARINC_FLT_DCDR *outC)
{
  outC->_L43 = inC->Range_Min;
  outC->_L32 = kcg_lit_float32(524288.0);
  outC->_L34 = inC->Range_Min;
  outC->_L31 = inC->Range_Max;
  outC->_L35 = outC->_L31 - outC->_L34;
  outC->_L36 = outC->_L35 / outC->_L32;
  outC->_L13 = kcg_lit_int8(10);
  outC->_L4 = inC->ARINCmsg;
  outC->_L24 = kcg_lit_uint32(0x1FFFFC00);
  outC->_L11 = outC->_L24 & outC->_L4;
  outC->_L5 = outC->_L11 >> outC->_L13;
  outC->raw_data = outC->_L5;
  outC->_L40 = outC->raw_data;
  outC->_L41 = /* _L41= */(kcg_float32) outC->_L40;
  outC->_L39 = outC->_L41 * outC->_L36;
  outC->_L42 = outC->_L39 + outC->_L43;
  outC->DATA = outC->_L42;
  outC->_L28 = kcg_lit_int8(29);
  outC->_L15 = kcg_lit_uint32(0x000000FF);
  outC->_L25 = outC->_L15 & outC->_L4;
  outC->_L26 = /* _L26= */(kcg_uint8) outC->_L25;
  outC->LABEL = outC->_L26;
  outC->_L8 = kcg_lit_uint32(0x60000000);
  outC->_L22 = outC->_L8 & outC->_L4;
  outC->_L6 = kcg_lit_int8(8);
  outC->_L17 = kcg_lit_uint32(0x00000300);
  outC->_L12 = outC->_L17 & outC->_L4;
  outC->_L19 = outC->_L12 >> outC->_L6;
  outC->_L1 = /* _L1= */(kcg_uint8) outC->_L19;
  outC->SDI = outC->_L1;
  outC->_L9 = outC->_L22 >> outC->_L28;
  outC->_L7 = /* _L7= */(kcg_uint8) outC->_L9;
  outC->SSM = outC->_L7;
}

#ifndef KCG_USER_DEFINED_INIT
void ARINC_FLT_DCDR_init(outC_ARINC_FLT_DCDR *outC)
{
  outC->_L43 = kcg_lit_float32(0.0);
  outC->_L42 = kcg_lit_float32(0.0);
  outC->_L41 = kcg_lit_float32(0.0);
  outC->_L40 = kcg_lit_uint32(0);
  outC->_L39 = kcg_lit_float32(0.0);
  outC->_L31 = kcg_lit_float32(0.0);
  outC->_L32 = kcg_lit_float32(0.0);
  outC->_L34 = kcg_lit_float32(0.0);
  outC->_L35 = kcg_lit_float32(0.0);
  outC->_L36 = kcg_lit_float32(0.0);
  outC->_L1 = kcg_lit_uint8(0);
  outC->_L4 = kcg_lit_uint32(0);
  outC->_L5 = kcg_lit_uint32(0);
  outC->_L6 = kcg_lit_int8(0);
  outC->_L7 = kcg_lit_uint8(0);
  outC->_L8 = kcg_lit_uint32(0);
  outC->_L9 = kcg_lit_uint32(0);
  outC->_L11 = kcg_lit_uint32(0);
  outC->_L12 = kcg_lit_uint32(0);
  outC->_L13 = kcg_lit_int8(0);
  outC->_L15 = kcg_lit_uint32(0);
  outC->_L17 = kcg_lit_uint32(0);
  outC->_L19 = kcg_lit_uint32(0);
  outC->_L22 = kcg_lit_uint32(0);
  outC->_L24 = kcg_lit_uint32(0);
  outC->_L25 = kcg_lit_uint32(0);
  outC->_L26 = kcg_lit_uint8(0);
  outC->_L28 = kcg_lit_int8(0);
  outC->raw_data = kcg_lit_uint32(0);
  outC->SSM = kcg_lit_uint8(0);
  outC->SDI = kcg_lit_uint8(0);
  outC->LABEL = kcg_lit_uint8(0);
  outC->DATA = kcg_lit_float32(0.0);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void ARINC_FLT_DCDR_reset(outC_ARINC_FLT_DCDR *outC)
{
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $ ANSYS SCADE Suite (R) Code Generator version Student 2022 R1 (build 20211130) 
** ARINC_FLT_DCDR.c
** Generation date: 2025-09-07T13:18:38
*************************************************************$ */

