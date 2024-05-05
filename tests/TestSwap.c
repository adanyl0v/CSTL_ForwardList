#include "Afx.h"

void PushToLists(CSTL_ForwardList *fList1, CSTL_ForwardList *fList2) {
    const char dSetMax = 3; // Should be in range [0 < N < 10]
    for (unsigned long i = 0; i < (unsigned long)dSetMax; i++) {
        /* _CSTL_SmartPtrMalloc() can't return NULL, it must throw an exception */
        int *d1 = (int *)_CSTL_SmartPtrMalloc(sizeof(int));
        int *d2 = (int *)_CSTL_SmartPtrMalloc(sizeof(int));
        *d1 = (int)(i + 1) * 10; // 10, 20, 30, ...
        *d2 = (int)(i + 1) * 100;// 100, 200, 300, ...
        CSTL_PushFrontToFrontList(fList1, CSTL_AllocateSmartPtr(d1));
        CSTL_PushFrontToFrontList(fList2, CSTL_AllocateSmartPtr(d2));
    }
}

void PrintLists(const CSTL_ForwardList *fList1, const CSTL_ForwardList *fList2) {
    CSTL_ForeachInForwardList(CSTL_GetForwardListBegin(fList1), CSTL_GetForwardListEnd(fList1), int, i, {
        printf("Data[1]: %p %d\n", (void *)i, i == NULL ? -1 : *i);
    });
    CSTL_ForeachInForwardList(CSTL_GetForwardListBegin(fList2), CSTL_GetForwardListEnd(fList2), int, i, {
        printf("Data[2]: %p %d\n", (void *)i, i == NULL ? -1 : *i);
    });
}

int main(void) {
    CSTL_ForwardList *fl1 = CSTL_CreateForwardList();
    CSTL_ForwardList *fl2 = CSTL_CreateForwardList();
    PushToLists(fl1, fl2);

    PrintLists(fl1, fl2);
    printf("===========================\n");
    CSTL_SwapForwardList(fl1, fl2);
    PrintLists(fl1, fl2);

    CSTL_DestroyForwardList(fl1);
    CSTL_DestroyForwardList(fl2);
    return 0;
}
