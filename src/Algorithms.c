#include "Afx.h"

void CSTL_ForeachInForwardListF(CSTL_ForwardList *fList, void (*f)(CSTL_Iterator *begin, const CSTL_Iterator *end)) {
    ThrowIfNullNoReturn(Warning, fList)
    ThrowIfNullNoReturn(Warning, f)

    CSTL_Iterator begin = fList->begin;
    CSTL_Iterator end = fList->end;
    do {
        f(&begin, &end);
        CSTL_IterateForward(CSTL_ForwardList, &begin);
    } while (!CSTL_IsIteratorEquals(CSTL_ForwardList, &begin, &end));
}

