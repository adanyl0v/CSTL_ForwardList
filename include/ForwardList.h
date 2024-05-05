#ifndef CSTL_FORWARD_LIST_H
#define CSTL_FORWARD_LIST_H

#include "BeginCode.h"

#include <CSTL_Exception/Exception.h>
#include <CSTL_SmartPointer/SmartPointer.h>
#include <CSTL_Iterator/Iterator.h>

typedef struct CSTL_ForwardList CSTL_ForwardList;

#ifdef __cplusplus
extern "C" {
#endif

#pragma region CSTL_ForwardListIterator
    extern void _CSTL_FDECL_Iterator_CSTL_ForwardList_iterateForward(CSTL_Iterator *iterator) DECLSPEC CSTLCALL;

    extern CSTL_SmartPtr *_CSTL_FDECL_Iterator_CSTL_ForwardList_getData(const CSTL_Iterator *iterator) DECLSPEC CSTLCALL;
    extern void _CSTL_FDECL_Iterator_CSTL_ForwardList_setData(CSTL_Iterator *iterator, CSTL_SmartPtr *data) DECLSPEC CSTLCALL;

    extern CSTL_Iterator CSTL_GetForwardListBegin(const CSTL_ForwardList *fList) DECLSPEC CSTLCALL;
    extern CSTL_Iterator CSTL_GetForwardListEnd(const CSTL_ForwardList *fList) DECLSPEC CSTLCALL;

#ifndef CSTL_GetForwardListBeginC
    /**
     * \param FL forward list
     * */
    #define CSTL_GetForwardListBeginC(FL) (const CSTL_Iterator)CSTL_GetForwardListBegin(FL)
#endif /* CSTL_GetForwardListBeginC */

#ifndef CSTL_GetForwardListEndC
    /**
     * \param FL forward list
     * */
    #define CSTL_GetForwardListEndC(FL) (const CSTL_Iterator)CSTL_GetForwardListEnd(FL)
#endif /* CSTL_GetForwardListEndC */

#pragma endregion

#pragma region CSTL_ForwardList
    extern CSTL_ForwardList * CSTL_CreateForwardList(void) DECLSPEC CSTLCALL;
    extern void CSTL_DestroyForwardList(CSTL_ForwardList *fList) DECLSPEC CSTLCALL;

    extern CSTL_SmartPtr *CSTL_GetForwardListFront(const CSTL_ForwardList *fList) DECLSPEC CSTLCALL;
    extern CSTL_SmartPtr *CSTL_GetForwardListBack(const CSTL_ForwardList *fList) DECLSPEC CSTLCALL;

    extern CSTL_Bool CSTL_IsForwardListEmpty(const CSTL_ForwardList *fList) DECLSPEC CSTLCALL;
    extern size_t CSTL_GetForwardListSize(const CSTL_ForwardList *fList) DECLSPEC CSTLCALL;

    extern void CSTL_SwapForwardList(CSTL_ForwardList *fList, CSTL_ForwardList *other) DECLSPEC CSTLCALL;
    extern void CSTL_ClearForwardLIst(CSTL_ForwardList *fList) DECLSPEC CSTLCALL;
    extern void CSTL_PushFrontToFrontList(CSTL_ForwardList *fList, CSTL_SmartPtr *data) DECLSPEC CSTLCALL;
    extern void CSTL_PopFrontToFrontList(CSTL_ForwardList *fList) DECLSPEC CSTLCALL;
    extern void CSTL_InsertAfterToForwardList(CSTL_ForwardList *fList, size_t pos, CSTL_SmartPtr *data) DECLSPEC CSTLCALL;
    extern void CSTL_EraseAfterFromForwardList(CSTL_ForwardList *fList, size_t pos) DECLSPEC CSTLCALL;
#pragma endregion

#pragma region CSTL_ForwardListAlgorithms
    extern void CSTL_ForeachInForwardListF(CSTL_ForwardList *fList, void (*f)(CSTL_Iterator *begin, const CSTL_Iterator *end)) DECLSPEC CSTLCALL;

#ifndef CSTL_ForeachInForwardList
    /**
     * \param BEGIN begin iterator
     * \param END end iterator
     * \param VT iteration variable type
     * \param VN iteration variable name
     * \param EXPR expression to apply
     * */
    #define CSTL_ForeachInForwardList(BEGIN, END, VT, VN, EXPR)                         \
        do {                                                                            \
            CSTL_Iterator __itBegin = BEGIN;                                            \
            CSTL_Iterator __itEnd = END;                                                \
            CSTL_SmartPtr *__itSp = NULL;                                               \
            VT *VN = NULL;                                                              \
            do {                                                                        \
                __itSp = CSTL_GetIteratorData(CSTL_ForwardList, &__itBegin);            \
                VN = (VT *)CSTL_GetSmartPtrData(__itSp);                                \
                EXPR;                                                                   \
                CSTL_IterateForward(CSTL_ForwardList, &__itBegin);                      \
            } while (!CSTL_IsIteratorEquals(CSTL_ForwardList, &__itBegin, &__itEnd));   \
        } while (0)
#endif /* CSTL_ForEachInForwardList */

#pragma endregion

#ifdef __cplusplus
}
#endif

#endif /* CSTL_FORWARD_LIST_H */
