#include "Afx.h"

CSTL_SmartPtr *CSTL_GetForwardListIteratorData(const CSTL_ForwardListIterator *iterator) {
    ThrowIfNull(Warning, NULL, iterator);
    return iterator->node == NULL ? NULL : ((CSTL_ForwardListNode *)iterator->node)->data;
}

void CSTL_SetForwardListIteratorData(CSTL_ForwardListIterator *iterator, CSTL_SmartPtr *data) {
    ThrowIfNullNoReturn(Warning, iterator);

    CSTL_ForwardListNode *node = (CSTL_ForwardListNode *)iterator->node;
    if (node != NULL) {
        if (node->data != NULL)
            CSTL_DestroySmartPtr(node->data);

        if (data != NULL)
            CSTL_AddSmartPtrRef(node->data);

        node->data = data;
    }
}

CSTL_Bool CSTL_IsForwardListIteratorEquals(const CSTL_ForwardListIterator *iterator, const CSTL_ForwardListIterator *other) {
    ThrowIfNull(Warning, CSTL_TRUE, iterator);
    ThrowIfNull(Warning, CSTL_TRUE, other);
    return iterator->node == other->node;
}

void CSTL_IterateNextInForwardList(CSTL_ForwardListIterator *iterator) {
    ThrowIfNullNoReturn(Warning, iterator);
    CSTL_ForwardListNode *node = (CSTL_ForwardListNode *)iterator->node;
    if (node != NULL)
        iterator->node = node->next;
}

CSTL_ForwardListIterator CSTL_GetForwardListBegin(const CSTL_ForwardList *fList) {
    CSTL_ForwardListIterator errorDummy = {NULL, NULL};
    ThrowIfNull(Warning, errorDummy, fList);
    return fList->begin;
}

CSTL_ForwardListIterator CSTL_GetForwardListEnd(const CSTL_ForwardList *fList) {
    CSTL_ForwardListIterator errorDummy = {NULL, NULL};
    ThrowIfNull(Warning, errorDummy, fList);
    return fList->end;
}

