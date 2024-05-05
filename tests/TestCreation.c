#include "Afx.h"

void f(CSTL_Iterator *it) {
    CSTL_SmartPtr *sp = CSTL_GetIteratorData(CSTL_ForwardList, it);
    int *data = (int *)CSTL_GetSmartPtrData(sp);
    printf("Data: %p %d\n", (void *)data, data == NULL ? -1 : *data);
}

int main(void) {
    CSTL_ForwardList *fl = CSTL_CreateForwardList();
    CSTL_CreateSmartPtr(int, d1, 101010);
    CSTL_CreateSmartPtr(int, d2, 202020);
    CSTL_CreateSmartPtr(int, d3, 303030);

    CSTL_PushFrontToFrontList(fl, d1);
    CSTL_PushFrontToFrontList(fl, d2);
    CSTL_InsertAfterToForwardList(fl, 0, d3);

    CSTL_ForeachInForwardListF(fl, f);
    CSTL_DestroyForwardList(fl);
    return 0;
}
