#include "Afx.h"
#include "Element.h"

CSTL_ForwardListElement *CSTL_CreateForwardListElement(CSTL_SmartPtr *data, CSTL_ForwardListElement *next) {
    CSTL_ForwardListElement *newElement = (CSTL_ForwardListElement *)malloc(sizeof(CSTL_ForwardListElement));
    ThrowIfFailedAlloc(Exception, NULL, "forward list node");

    CSTL_AddSmartPtrRef(data);
    newElement->data = data;
    newElement->next = next;
    return newElement;
}

void CSTL_DestroyForwardListElement(CSTL_ForwardListElement *node) {
    ThrowIfNullNoReturn(Warning, node);
    CSTL_DestroySmartPtr(node->data);
    free(node);
}
