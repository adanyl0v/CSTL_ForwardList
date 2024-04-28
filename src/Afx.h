#pragma once
#ifndef CSTL_FORWARD_LIST_AFX_H
#define CSTL_FORWARD_LIST_AFX_H

#include <stdlib.h>

#include "../include/ForwardList.h"
#include "ForwardList.h"

typedef enum ThrowType {
    Exception,
    Warning
} ThrowType;

#ifndef ThrowIfNull
/**
 * \param PREF throw macro prefix, can only be Exception or Warning
 * \param RV return value
 * \param ARG argument to check
 * */
#define ThrowIfNull(THROWT, RV, ARG)                                         \
    if (ARG == NULL) {                                                     \
        CSTL_Throw##THROWT(CSTL_INVALID_ARGS, "arg. '%s' is null", #ARG);  \
        return RV;                                                         \
    }
#endif /* ThrowIfNull */

#ifndef ThrowIfNullNoReturn
#define ThrowIfNullNoReturn(THROWT, ARG) \
    ThrowIfNull(THROWT, , ARG)
#endif /* ThrowIfNullNoReturn */

#ifndef ThrowIfFailedAlloc
/**
 * \param PREF throw macro prefix, can only be Exception or Warning
 * \param RV return value
 * \param ARG argument that failed to allocate
 * */
#define ThrowIfFailedAlloc(THROWT, RV, ARG)                                                   \
    if (ARG == NULL) {                                                                      \
        CSTL_Throw##THROWT(CSTL_FAILED_ALLOC, "failed to allocate memory for a new %s", ARG);\
        return RV;                                                                          \
    }
#endif /* ThrowIfFailedAlloc */

#ifndef ThrowIfFailedAllocNoReturn
#define ThrowIfFailedAllocNoReturn(THROWT, ARG) \
    ThrowIfFailedAlloc(THROWT, , ARG)
#endif /* ThrowIfFailedAllocNoReturn */

#ifndef ThrowIfOutOfRange
/**
 * \param PREF throw macro prefix, can only be Exception or Warning
 * \param RV return value
 * \param ARG argument to check
 * */
#define ThrowIfOutOfRange(THROWT, RV, ARG, MAX)                                   \
    if (ARG >= MAX) {                                                           \
        CSTL_Throw##THROWT(CSTL_OUT_OF_RANGE, "arg. '%s' is out of range", #ARG); \
        return RV;                                                              \
    }
#endif /* ThrowIfOutOfRange */

#ifndef ThrowIfOutOfRangeNoReturn
#define ThrowIfOutOfRangeNoReturn(THROWT, ARG, MAX) \
    ThrowIfOutOfRange(THROWT, , ARG, MAX)
#endif /* ThrowIfOutOfRangeNoReturn */

#endif /* CSTL_FORWARD_LIST_AFX_H */
