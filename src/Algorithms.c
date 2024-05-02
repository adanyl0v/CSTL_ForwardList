#include "Afx.h"

void CSTL_ForEachInForwardListF(CSTL_ForwardList *fList, void (*f)(CSTL_Iterator *)) {
    ThrowIfNullNoReturn(Warning, fList)
    ThrowIfNullNoReturn(Warning, f)

    CSTL_Iterator iterator = fList->begin;
    do {
        f(&iterator);
        CSTL_IterateForward(CSTL_ForwardList, &iterator);
    } while (!CSTL_IsIteratorEquals(CSTL_ForwardList, &iterator, &fList->end));
}

