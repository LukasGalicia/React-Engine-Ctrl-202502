/* ARINC_COMM_mapping.c */

#include "ARINC_COMM_type.h"
#include "ARINC_COMM_interface.h"
#include "ARINC_COMM_mapping.h"

#include "SmuTypes.h"
#include "SmuMapping.h"

#include "kcg_sensors.h"

/* mapping declaration */

#define DECL_ITER(name) extern const MappingIterator iter_##name


#define DECL_SCOPE(name, count) extern const MappingEntry name##_entries[count]; extern const MappingScope name

DECL_SCOPE(scope_2, 12);
DECL_SCOPE(scope_1, 41);
DECL_SCOPE(scope_0, 1);

/* clock definition */


/* mapping definition */


const MappingEntry scope_2_entries[12] = {
    /* 0 */ { MAP_OUTPUT, "RF_Output", NULL, sizeof(kcg_int32), offsetof(outC_RoundFloor_math_float32, RF_Output_float32), &_Type_kcg_int32_Utils, NULL, NULL, NULL, 1, 0 },
    /* 1 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_float32), offsetof(outC_RoundFloor_math_float32, _L1_float32), &_Type_kcg_float32_Utils, NULL, NULL, NULL, 1, 1 },
    /* 2 */ { MAP_LOCAL, "_L24", NULL, sizeof(kcg_bool), offsetof(outC_RoundFloor_math_float32, _L24_float32), &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 2 },
    /* 3 */ { MAP_LOCAL, "_L25", NULL, sizeof(kcg_float32), offsetof(outC_RoundFloor_math_float32, _L25_float32), &_Type_kcg_float32_Utils, NULL, NULL, NULL, 1, 3 },
    /* 4 */ { MAP_LOCAL, "_L26", NULL, sizeof(kcg_int32), offsetof(outC_RoundFloor_math_float32, _L26_float32), &_Type_kcg_int32_Utils, NULL, NULL, NULL, 1, 4 },
    /* 5 */ { MAP_LOCAL, "_L30", NULL, sizeof(kcg_float32), offsetof(outC_RoundFloor_math_float32, _L30_float32), &_Type_kcg_float32_Utils, NULL, NULL, NULL, 1, 5 },
    /* 6 */ { MAP_LOCAL, "_L31", NULL, sizeof(kcg_float32), offsetof(outC_RoundFloor_math_float32, _L31_float32), &_Type_kcg_float32_Utils, NULL, NULL, NULL, 1, 6 },
    /* 7 */ { MAP_LOCAL, "_L32", NULL, sizeof(kcg_int32), offsetof(outC_RoundFloor_math_float32, _L32_float32), &_Type_kcg_int32_Utils, NULL, NULL, NULL, 1, 7 },
    /* 8 */ { MAP_LOCAL, "_L33", NULL, sizeof(kcg_int32), offsetof(outC_RoundFloor_math_float32, _L33_float32), &_Type_kcg_int32_Utils, NULL, NULL, NULL, 1, 8 },
    /* 9 */ { MAP_LOCAL, "_L38", NULL, sizeof(kcg_int32), offsetof(outC_RoundFloor_math_float32, _L38_float32), &_Type_kcg_int32_Utils, NULL, NULL, NULL, 1, 9 },
    /* 10 */ { MAP_LOCAL, "_L41", NULL, sizeof(kcg_float32), offsetof(outC_RoundFloor_math_float32, _L41_float32), &_Type_kcg_float32_Utils, NULL, NULL, NULL, 1, 10 },
    /* 11 */ { MAP_LOCAL, "_L43", NULL, sizeof(kcg_bool), offsetof(outC_RoundFloor_math_float32, _L43_float32), &_Type_kcg_bool_Utils, NULL, NULL, NULL, 1, 11 }
};
const MappingScope scope_2 = {
    "math::RoundFloor/ RoundFloor_math_float32",
    scope_2_entries, 12
};

const MappingEntry scope_1_entries[41] = {
    /* 0 */ { MAP_OUTPUT, "ARINCmsg", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx.ARINCmsg, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 0 },
    /* 1 */ { MAP_INPUT, "DATA", NULL, sizeof(kcg_float32), (size_t)&inputs_ctx.DATA, &_Type_kcg_float32_Utils, NULL, NULL, NULL, 1, 1 },
    /* 2 */ { MAP_INPUT, "SDI", NULL, sizeof(kcg_uint8), (size_t)&inputs_ctx.SDI, &_Type_kcg_uint8_Utils, NULL, NULL, NULL, 1, 2 },
    /* 3 */ { MAP_INPUT, "SSM", NULL, sizeof(kcg_uint8), (size_t)&inputs_ctx.SSM, &_Type_kcg_uint8_Utils, NULL, NULL, NULL, 1, 3 },
    /* 4 */ { MAP_INPUT, "LABEL", NULL, sizeof(kcg_uint8), (size_t)&inputs_ctx.LABEL, &_Type_kcg_uint8_Utils, NULL, NULL, NULL, 1, 4 },
    /* 5 */ { MAP_INPUT, "Range_Min", NULL, sizeof(kcg_float32), (size_t)&inputs_ctx.Range_Min, &_Type_kcg_float32_Utils, NULL, NULL, NULL, 1, 5 },
    /* 6 */ { MAP_INPUT, "Range_Max", NULL, sizeof(kcg_float32), (size_t)&inputs_ctx.Range_Max, &_Type_kcg_float32_Utils, NULL, NULL, NULL, 1, 6 },
    /* 7 */ { MAP_LOCAL, "inrangedata", NULL, sizeof(kcg_int32), (size_t)&outputs_ctx.inrangedata, &_Type_kcg_int32_Utils, NULL, NULL, NULL, 1, 7 },
    /* 8 */ { MAP_LOCAL, "_L22", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L22, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 8 },
    /* 9 */ { MAP_LOCAL, "_L21", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L21, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 9 },
    /* 10 */ { MAP_LOCAL, "_L20", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L20, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 10 },
    /* 11 */ { MAP_LOCAL, "_L19", NULL, sizeof(kcg_uint8), (size_t)&outputs_ctx._L19, &_Type_kcg_uint8_Utils, NULL, NULL, NULL, 1, 11 },
    /* 12 */ { MAP_LOCAL, "_L18", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L18, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 12 },
    /* 13 */ { MAP_LOCAL, "_L17", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L17, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 13 },
    /* 14 */ { MAP_LOCAL, "_L16", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L16, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 14 },
    /* 15 */ { MAP_LOCAL, "_L15", NULL, sizeof(kcg_uint8), (size_t)&outputs_ctx._L15, &_Type_kcg_uint8_Utils, NULL, NULL, NULL, 1, 15 },
    /* 16 */ { MAP_LOCAL, "_L14", NULL, sizeof(kcg_int8), (size_t)&outputs_ctx._L14, &_Type_kcg_int8_Utils, NULL, NULL, NULL, 1, 16 },
    /* 17 */ { MAP_LOCAL, "_L12", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L12, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 17 },
    /* 18 */ { MAP_LOCAL, "_L11", NULL, sizeof(kcg_int8), (size_t)&outputs_ctx._L11, &_Type_kcg_int8_Utils, NULL, NULL, NULL, 1, 18 },
    /* 19 */ { MAP_LOCAL, "_L10", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L10, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 19 },
    /* 20 */ { MAP_LOCAL, "_L9", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L9, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 20 },
    /* 21 */ { MAP_LOCAL, "_L8", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L8, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 21 },
    /* 22 */ { MAP_LOCAL, "_L7", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L7, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 22 },
    /* 23 */ { MAP_LOCAL, "_L6", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L6, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 23 },
    /* 24 */ { MAP_LOCAL, "_L5", NULL, sizeof(kcg_int8), (size_t)&outputs_ctx._L5, &_Type_kcg_int8_Utils, NULL, NULL, NULL, 1, 24 },
    /* 25 */ { MAP_LOCAL, "_L4", NULL, sizeof(kcg_uint8), (size_t)&outputs_ctx._L4, &_Type_kcg_uint8_Utils, NULL, NULL, NULL, 1, 25 },
    /* 26 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L3, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 26 },
    /* 27 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L2, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 27 },
    /* 28 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L1, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 28 },
    /* 29 */ { MAP_LOCAL, "_L23", NULL, sizeof(kcg_float32), (size_t)&outputs_ctx._L23, &_Type_kcg_float32_Utils, NULL, NULL, NULL, 1, 29 },
    /* 30 */ { MAP_LOCAL, "_L24", NULL, sizeof(kcg_float32), (size_t)&outputs_ctx._L24, &_Type_kcg_float32_Utils, NULL, NULL, NULL, 1, 30 },
    /* 31 */ { MAP_LOCAL, "_L25", NULL, sizeof(kcg_float32), (size_t)&outputs_ctx._L25, &_Type_kcg_float32_Utils, NULL, NULL, NULL, 1, 31 },
    /* 32 */ { MAP_LOCAL, "_L26", NULL, sizeof(kcg_float32), (size_t)&outputs_ctx._L26, &_Type_kcg_float32_Utils, NULL, NULL, NULL, 1, 32 },
    /* 33 */ { MAP_LOCAL, "_L27", NULL, sizeof(kcg_float32), (size_t)&outputs_ctx._L27, &_Type_kcg_float32_Utils, NULL, NULL, NULL, 1, 33 },
    /* 34 */ { MAP_LOCAL, "_L28", NULL, sizeof(kcg_float32), (size_t)&outputs_ctx._L28, &_Type_kcg_float32_Utils, NULL, NULL, NULL, 1, 34 },
    /* 35 */ { MAP_LOCAL, "_L29", NULL, sizeof(kcg_float32), (size_t)&outputs_ctx._L29, &_Type_kcg_float32_Utils, NULL, NULL, NULL, 1, 35 },
    /* 36 */ { MAP_LOCAL, "_L33", NULL, sizeof(kcg_int32), (size_t)&outputs_ctx._L33, &_Type_kcg_int32_Utils, NULL, NULL, NULL, 1, 36 },
    /* 37 */ { MAP_LOCAL, "_L35", NULL, sizeof(kcg_int32), (size_t)&outputs_ctx._L35, &_Type_kcg_int32_Utils, NULL, NULL, NULL, 1, 37 },
    /* 38 */ { MAP_LOCAL, "_L37", NULL, sizeof(kcg_float32), (size_t)&outputs_ctx._L37, &_Type_kcg_float32_Utils, NULL, NULL, NULL, 1, 38 },
    /* 39 */ { MAP_LOCAL, "_L38", NULL, sizeof(kcg_float32), (size_t)&outputs_ctx._L38, &_Type_kcg_float32_Utils, NULL, NULL, NULL, 1, 39 },
    /* 40 */ { MAP_INSTANCE, "math::RoundFloor 2", NULL, sizeof(outC_RoundFloor_math_float32), (size_t)&outputs_ctx.Context_RoundFloor_2, NULL, NULL, NULL, &scope_2, 1, 40 }
};
const MappingScope scope_1 = {
    "ARINC_FLT_ENCDR/ ARINC_FLT_ENCDR",
    scope_1_entries, 41
};

const MappingEntry scope_0_entries[1] = {
    /* 0 */ { MAP_ROOT, "ARINC_FLT_ENCDR", NULL, 0, 0, NULL, NULL, NULL, &scope_1, 1, 0 }
};
const MappingScope scope_0 = {
    "",
    scope_0_entries, 1
};

/* entry point */
const MappingScope* pTop = &scope_0;
