#include "Afx.h"
#include "Node.h"

CSTL_ForwardListNode *CSTL_CreateForwardListNode(CSTL_SmartPtr *data, CSTL_ForwardListNode *next) {
    CSTL_ForwardListNode *newNode = (CSTL_ForwardListNode *)malloc(sizeof(CSTL_ForwardListNode));
    ThrowIfFailedAlloc(Exception, NULL, "forward list node");

    CSTL_AddSmartPtrRef(data);
    newNode->data = data;
    newNode->next = next;
    return newNode;
}

void CSTL_DestroyForwardListNode(CSTL_ForwardListNode *node) {
    ThrowIfNullNoReturn(Warning, node);
    CSTL_DestroySmartPtr(node->data);
    free(node);
}
