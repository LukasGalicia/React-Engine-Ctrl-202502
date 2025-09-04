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

DECL_SCOPE(scope_1, 24);
DECL_SCOPE(scope_0, 1);

/* clock definition */


/* mapping definition */


const MappingEntry scope_1_entries[24] = {
    /* 0 */ { MAP_OUTPUT, "SSM", NULL, sizeof(kcg_uint8), (size_t)&outputs_ctx.SSM, &_Type_kcg_uint8_Utils, NULL, NULL, NULL, 1, 0 },
    /* 1 */ { MAP_OUTPUT, "DATA", NULL, sizeof(kcg_int32), (size_t)&outputs_ctx.DATA, &_Type_kcg_int32_Utils, NULL, NULL, NULL, 1, 1 },
    /* 2 */ { MAP_OUTPUT, "SDI", NULL, sizeof(kcg_uint8), (size_t)&outputs_ctx.SDI, &_Type_kcg_uint8_Utils, NULL, NULL, NULL, 1, 2 },
    /* 3 */ { MAP_OUTPUT, "LABEL", NULL, sizeof(kcg_uint8), (size_t)&outputs_ctx.LABEL, &_Type_kcg_uint8_Utils, NULL, NULL, NULL, 1, 3 },
    /* 4 */ { MAP_INPUT, "ARINCmsg", NULL, sizeof(kcg_uint32), (size_t)&inputs_ctx.ARINCmsg, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 4 },
    /* 5 */ { MAP_LOCAL, "_L1", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L1, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 5 },
    /* 6 */ { MAP_LOCAL, "_L2", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L2, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 6 },
    /* 7 */ { MAP_LOCAL, "_L3", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L3, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 7 },
    /* 8 */ { MAP_LOCAL, "_L4", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L4, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 8 },
    /* 9 */ { MAP_LOCAL, "_L5", NULL, sizeof(kcg_uint8), (size_t)&outputs_ctx._L5, &_Type_kcg_uint8_Utils, NULL, NULL, NULL, 1, 9 },
    /* 10 */ { MAP_LOCAL, "_L6", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L6, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 10 },
    /* 11 */ { MAP_LOCAL, "_L7", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L7, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 11 },
    /* 12 */ { MAP_LOCAL, "_L10", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L10, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 12 },
    /* 13 */ { MAP_LOCAL, "_L13", NULL, sizeof(kcg_int8), (size_t)&outputs_ctx._L13, &_Type_kcg_int8_Utils, NULL, NULL, NULL, 1, 13 },
    /* 14 */ { MAP_LOCAL, "_L14", NULL, sizeof(kcg_int8), (size_t)&outputs_ctx._L14, &_Type_kcg_int8_Utils, NULL, NULL, NULL, 1, 14 },
    /* 15 */ { MAP_LOCAL, "_L15", NULL, sizeof(kcg_int32), (size_t)&outputs_ctx._L15, &_Type_kcg_int32_Utils, NULL, NULL, NULL, 1, 15 },
    /* 16 */ { MAP_LOCAL, "_L25", NULL, sizeof(kcg_int8), (size_t)&outputs_ctx._L25, &_Type_kcg_int8_Utils, NULL, NULL, NULL, 1, 16 },
    /* 17 */ { MAP_LOCAL, "_L24", NULL, sizeof(kcg_uint8), (size_t)&outputs_ctx._L24, &_Type_kcg_uint8_Utils, NULL, NULL, NULL, 1, 17 },
    /* 18 */ { MAP_LOCAL, "_L23", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L23, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 18 },
    /* 19 */ { MAP_LOCAL, "_L22", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L22, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 19 },
    /* 20 */ { MAP_LOCAL, "_L21", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L21, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 20 },
    /* 21 */ { MAP_LOCAL, "_L31", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L31, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 21 },
    /* 22 */ { MAP_LOCAL, "_L30", NULL, sizeof(kcg_uint32), (size_t)&outputs_ctx._L30, &_Type_kcg_uint32_Utils, NULL, NULL, NULL, 1, 22 },
    /* 23 */ { MAP_LOCAL, "_L32", NULL, sizeof(kcg_uint8), (size_t)&outputs_ctx._L32, &_Type_kcg_uint8_Utils, NULL, NULL, NULL, 1, 23 }
};
const MappingScope scope_1 = {
    "ARINC_INT_DCDR/ ARINC_INT_DCDR",
    scope_1_entries, 24
};

const MappingEntry scope_0_entries[1] = {
    /* 0 */ { MAP_ROOT, "ARINC_INT_DCDR", NULL, 0, 0, NULL, NULL, NULL, &scope_1, 1, 0 }
};
const MappingScope scope_0 = {
    "",
    scope_0_entries, 1
};

/* entry point */
const MappingScope* pTop = &scope_0;
