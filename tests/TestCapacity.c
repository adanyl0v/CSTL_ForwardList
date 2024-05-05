#include "Afx.h"

int main(void) {
    CSTL_ForwardList *fl = CSTL_CreateForwardList();
    CSTL_CreateSmartPtr(const char *, data, "Hello World");

    for (char i = 0; i < 5; i++)
        CSTL_PushFrontToFrontList(fl, data);

    CSTL_ForeachInForwardList(CSTL_GetForwardListBegin(fl), CSTL_GetForwardListEnd(fl), char *, p, {
        printf("Data %p %s\n", (void *)p, p == NULL ? "": *p);
    });

    if (CSTL_IsForwardListEmpty(fl))
        printf("The forward list is empty\n");
    else
        printf("Size of the forward list: %zu\n", CSTL_GetForwardListSize(fl));

    CSTL_DestroyForwardList(fl);
}
