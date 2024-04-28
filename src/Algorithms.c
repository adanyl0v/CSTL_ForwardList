#include "Afx.h"

void CSTL_ForEachInForwardListF(CSTL_ForwardList *fList, void (*f)(CSTL_ForwardListIterator *)) {
    ThrowIfNullNoReturn(Warning, fList)
    ThrowIfNullNoReturn(Warning, f)

    CSTL_ForwardListIterator iterator = fList->begin;
    do {
        f(&iterator);
        CSTL_IterateNextInForwardList(&iterator);
    } while (!CSTL_IsForwardListIteratorEquals(&iterator, &fList->end));
}

