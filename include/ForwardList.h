#pragma once
#ifndef CSTL_FORWARD_LIST_H
#define CSTL_FORWARD_LIST_H

#include "BeginCode.h"
#include "Iterator.h"

#include <CSTL_Exception/Exception.h>
#include <CSTL_SmartPointer/SmartPointer.h>

typedef struct CSTL_ForwardList CSTL_ForwardList;

/**
 * \warning Do not manually overwrite the internal values of the structure
 * */
struct CSTL_ForwardListIterator {
    CSTL_ForwardList *fList;
    void *node;
};

#ifdef __cplusplus
extern "C" {
#endif

#pragma region CSTL_ForwardListIterator
    extern DECLSPEC void CSTLCALL CSTL_IterateNextInForwardList(CSTL_ForwardListIterator *iterator);

    extern DECLSPEC CSTL_ForwardListIterator CSTLCALL CSTL_GetForwardListBegin(const CSTL_ForwardList *fList);
    extern DECLSPEC CSTL_ForwardListIterator CSTLCALL CSTL_GetForwardListEnd(const CSTL_ForwardList *fList);

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
    extern DECLSPEC CSTL_ForwardList * CSTLCALL CSTL_CreateForwardList(void);
    extern DECLSPEC void CSTLCALL CSTL_DestroyForwardList(CSTL_ForwardList *fList);

    extern DECLSPEC CSTL_SmartPtr * CSTLCALL CSTL_GetForwardListFront(const CSTL_ForwardList *fList);
    extern DECLSPEC CSTL_SmartPtr * CSTLCALL CSTL_GetForwardListBack(const CSTL_ForwardList *fList);

    extern DECLSPEC CSTL_Bool CSTLCALL CSTL_IsForwardListEmpty(const CSTL_ForwardList *fList);
    extern DECLSPEC size_t CSTLCALL CSTL_GetForwardListSize(const CSTL_ForwardList *fList);

    extern DECLSPEC void CSTLCALL CSTL_SwapForwardList(CSTL_ForwardList *fList, CSTL_ForwardList *other);
    extern DECLSPEC void CSTLCALL CSTL_ClearForwardLIst(CSTL_ForwardList *fList);
    extern DECLSPEC void CSTLCALL CSTL_PushFrontToFrontList(CSTL_ForwardList *fList, CSTL_SmartPtr *data);
    extern DECLSPEC void CSTLCALL CSTL_PopFrontToFrontList(CSTL_ForwardList *fList);
    extern DECLSPEC void CSTLCALL CSTL_InsertAfterToForwardList(CSTL_ForwardList *fList, size_t pos, CSTL_SmartPtr *data);
    extern DECLSPEC void CSTLCALL CSTL_EraseAfterFromForwardList(CSTL_ForwardList *fList, size_t pos);
#pragma endregion

#pragma region CSTL_ForwardListAlgorithms
    extern DECLSPEC void CSTLCALL CSTL_ForEachInForwardListF(CSTL_ForwardList *fList, void (*f)(CSTL_ForwardListIterator *));

#ifndef CSTL_ForEachInForwardList
    /**
     * \param BEGIN begin iterator
     * \param END end iterator
     * \param VT iteration variable type
     * \param VN iteration variable name
     * \param EXPR expression to apply
     * */
    #define CSTL_ForEachInForwardList(BEGIN, END, VT, VN, EXPR)                 \
        do {                                                                    \
            CSTL_ForwardListIterator __itBegin = BEGIN;                         \
            CSTL_ForwardListIterator __itEnd = END;                             \
            CSTL_SmartPtr *__itSp = NULL;                                       \
            VT *VN = NULL;                                                      \
            do {                                                                \
                __itSp = CSTL_GetForwardListIteratorData(&__itBegin);           \
                VN = (VT *)CSTL_GetSmartPtrData(__itSp);                        \
                EXPR;                                                           \
                CSTL_IterateNextInForwardList(&__itBegin);                      \
            } while (!CSTL_IsForwardListIteratorEquals(&__itBegin, &__itEnd));  \
        } while (0)
#endif /* CSTL_ForEachInForwardList */

#pragma endregion

#ifdef __cplusplus
}
#endif

#endif /* CSTL_FORWARD_LIST_H */
