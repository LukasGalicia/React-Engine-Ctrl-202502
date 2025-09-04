/* $ ANSYS SCADE Suite (R) Code Generator version Student 2022 R1 (build 20211130) 
** Command: scadecg.exe -config C:/Users/lukas/Documents/Repo/202502_REACT_ENG_CTRL/SCADE/ARINC_COMM/Simulation/config.txt
** Generation date: 2025-09-04T07:15:09
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "Int_data_bmask.h"

/* Int_data_bmask/ */
void Int_data_bmask(/* data_in/ */ kcg_int32 data_in, outC_Int_data_bmask *outC)
{
  outC->_L1 = kcg_lit_uint32(0x0007FFFF);
  outC->_L2 = data_in;
  outC->_L3 = /* _L3= */(kcg_uint32) outC->_L2;
  outC->_L5 = outC->_L1 & outC->_L3;
  outC->_L6 = kcg_lit_int8(10);
  outC->_L4 = kcg_lsl_uint32(outC->_L5, outC->_L6);
  outC->outdata = outC->_L4;
}

#ifndef KCG_USER_DEFINED_INIT
void Int_data_bmask_init(outC_Int_data_bmask *outC)
{
  outC->_L1 = kcg_lit_uint32(0);
  outC->_L5 = kcg_lit_uint32(0);
  outC->_L2 = kcg_lit_int32(0);
  outC->_L3 = kcg_lit_uint32(0);
  outC->_L4 = kcg_lit_uint32(0);
  outC->_L6 = kcg_lit_int8(0);
  outC->outdata = kcg_lit_uint32(0);
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void Int_data_bmask_reset(outC_Int_data_bmask *outC)
{
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */



/* $ ANSYS SCADE Suite (R) Code Generator version Student 2022 R1 (build 20211130) 
** Int_data_bmask.c
** Generation date: 2025-09-04T07:15:09
*************************************************************$ */

