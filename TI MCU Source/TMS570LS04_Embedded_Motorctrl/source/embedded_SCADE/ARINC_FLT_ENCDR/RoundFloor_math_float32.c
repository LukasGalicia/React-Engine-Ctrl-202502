/* $ ANSYS SCADE Suite (R) Code Generator version Student 2022 R1 (build 20211130) 
** Command: scadecg.exe -config C:/Users/lukas/Documents/Repo/202502_REACT_ENG_CTRL/SCADE/ARINC_COMM/Simulation/config.txt
** Generation date: 2025-09-07T13:12:44
*************************************************************$ */

#include "kcg_consts_global.h"
#include "kcg_sensors_global.h"
#include "RoundFloor_math_float32.h"

/* math::RoundFloor/ */
void RoundFloor_math_float32(
  /* RF_Input/ */
  kcg_float32 RF_Input_float32,
  outC_RoundFloor_math_float32 *outC)
{
  outC->_L1_float32 = RF_Input_float32;
  outC->_L33_float32 = /* _L33= */(kcg_int32) outC->_L1_float32;
  outC->_L41_float32 = /* _L41= */(kcg_float32) outC->_L33_float32;
  outC->_L43_float32 = outC->_L41_float32 == outC->_L1_float32;
  outC->_L31_float32 = kcg_lit_float32(1.);
  outC->_L30_float32 = outC->_L1_float32 - outC->_L31_float32;
  outC->_L32_float32 = /* _L32= */(kcg_int32) outC->_L30_float32;
  /* _L38= */
  if (outC->_L43_float32) {
    outC->_L38_float32 = outC->_L33_float32;
  }
  else {
    outC->_L38_float32 = outC->_L32_float32;
  }
  outC->_L25_float32 = kcg_lit_float32(0.);
  outC->_L24_float32 = outC->_L1_float32 >= outC->_L25_float32;
  /* _L26= */
  if (outC->_L24_float32) {
    outC->_L26_float32 = outC->_L33_float32;
  }
  else {
    outC->_L26_float32 = outC->_L38_float32;
  }
  outC->RF_Output_float32 = outC->_L26_float32;
}

#ifndef KCG_USER_DEFINED_INIT
void RoundFloor_init_math_float32(outC_RoundFloor_math_float32 *outC)
{
  outC->_L43_float32 = kcg_true;
  outC->_L41_float32 = kcg_lit_float32(0.0);
  outC->_L38_float32 = kcg_lit_int32(0);
  outC->_L33_float32 = kcg_lit_int32(0);
  outC->_L32_float32 = kcg_lit_int32(0);
  outC->_L31_float32 = kcg_lit_float32(0.0);
  outC->_L30_float32 = kcg_lit_float32(0.0);
  outC->_L26_float32 = kcg_lit_int32(0);
  outC->_L25_float32 = kcg_lit_float32(0.0);
  outC->_L24_float32 = kcg_true;
  outC->_L1_float32 = kcg_lit_float32(0.0);
  outC->RF_Output_float32 = kcg_lit_int32(0);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void RoundFloor_reset_math_float32(outC_RoundFloor_math_float32 *outC)
{
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $ ANSYS SCADE Suite (R) Code Generator version Student 2022 R1 (build 20211130) 
** RoundFloor_math_float32.c
** Generation date: 2025-09-07T13:12:44
*************************************************************$ */

