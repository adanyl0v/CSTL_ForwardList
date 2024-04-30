#pragma once
#ifndef CSTL_FORWARD_LIST_ITERATOR_H
#define CSTL_FORWARD_LIST_ITERATOR_H

#include "BeginCode.h"

#include <CSTL_SmartPointer/SmartPointer.h>

typedef struct CSTL_ForwardListIterator CSTL_ForwardListIterator;

#ifdef __cplusplus
extern "C" {
#endif

#pragma region CSTL_Iterator
    extern DECLSPEC CSTL_SmartPtr * CSTLCALL CSTL_GetForwardListIteratorData(const CSTL_ForwardListIterator *iterator);
    extern DECLSPEC void CSTLCALL CSTL_SetForwardListIteratorData(CSTL_ForwardListIterator *iterator, CSTL_SmartPtr *data);
    
    extern DECLSPEC CSTL_Bool CSTLCALL CSTL_IsForwardListIteratorEquals(const CSTL_ForwardListIterator *iterator, const CSTL_ForwardListIterator *other);
#pragma region

#ifdef __cplusplus
};
#endif

#endif /* CSTL_FORWARD_LIST_ITERATOR_H */
