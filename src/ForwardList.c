#include "Afx.h"

CSTL_ForwardList *CSTL_CreateForwardList(void) {
    CSTL_ForwardList *newList = (CSTL_ForwardList *)malloc(sizeof(CSTL_ForwardList));
    ThrowIfFailedAlloc(Exception, NULL, newList);

    newList->size = 0;
    newList->begin.container = (void *)newList;
    newList->begin.p = NULL;
    newList->end.container = (void *)newList;
    newList->end.p = NULL; // End iterator must always be NULL
    return newList;
}

void CSTL_DestroyForwardList(CSTL_ForwardList *fList) {
    ThrowIfNullNoReturn(Warning, fList);
    CSTL_ClearForwardLIst(fList);
    free(fList);
}

CSTL_SmartPtr *CSTL_GetForwardListFront(const CSTL_ForwardList *fList) {
    ThrowIfNull(Warning, NULL, fList);
    if (fList->begin.p == NULL)
        return NULL;

    return ((CSTL_ForwardListNode *)fList->begin.p)->data;
}

CSTL_SmartPtr *CSTL_GetForwardListBack(const CSTL_ForwardList *fList) {
    ThrowIfNull(Warning, NULL, fList);
    if (fList->end.p == NULL)
        return NULL;

    return ((CSTL_ForwardListNode *)fList->end.p)->data;
}

CSTL_Bool CSTL_IsForwardListEmpty(const CSTL_ForwardList *fList) {
    ThrowIfNull(Warning, CSTL_FALSE, fList);
    return fList->size == 0 ? CSTL_TRUE : CSTL_FALSE;
}

size_t CSTL_GetForwardListSize(const CSTL_ForwardList *fList) {
    ThrowIfNull(Warning, 0, fList);
    return fList->size;
}

void CSTL_SwapForwardList(CSTL_ForwardList *fList, CSTL_ForwardList *other) {
    ThrowIfNullNoReturn(Warning, fList);
    ThrowIfNullNoReturn(Warning, other);

    size_t fListSize = fList->size;
    CSTL_ForwardListIterator fListHead = fList->begin;
    CSTL_ForwardListIterator fListTail = fList->end;

    fList->size = other->size;
    fList->begin.container = other->begin.container;
    fList->begin.p = other->begin.p;
    fList->end.container = other->end.container;
    fList->end.p = other->end.p;

    other->size = fListSize;
    other->begin.container = fListHead.container;
    other->begin.p = fListHead.p;
    other->end.container = fListTail.container;
    other->end.p = fListTail.p;
}

void CSTL_ClearForwardLIst(CSTL_ForwardList *fList) {
    ThrowIfNullNoReturn(Warning, fList);
    while (fList->size > 0)
        CSTL_PopFrontToFrontList(fList);
}

void CSTL_PushFrontToFrontList(CSTL_ForwardList *fList, CSTL_SmartPtr *data) {
    ThrowIfNullNoReturn(Warning, fList);

    CSTL_ForwardListNode *newNode = CSTL_CreateForwardListNode(data, (CSTL_ForwardListNode *)fList->begin.p);
    if (newNode == NULL) // Unnecessary, because previous function must throw an exception, if failed to create a new node
        return;

    fList->begin.p = (void *)newNode;
    fList->size++;
}

void CSTL_PopFrontToFrontList(CSTL_ForwardList *fList) {
    ThrowIfNullNoReturn(Warning, fList);

    CSTL_ForwardListNode *popNode = (CSTL_ForwardListNode *)fList->begin.p;
    if (popNode == fList->end.p) // Must execute if the node to pop is NULL
        return;

    fList->begin.p = (void *)popNode->next;
    CSTL_DestroyForwardListNode(popNode);
    fList->size--;
}

CSTL_ForwardListNode *GetForwardListNodeAt(const CSTL_ForwardList *fList, size_t pos) {
    ThrowIfNull(Warning, NULL, fList);

    if (pos == 0)
        return fList->begin.p;

    ThrowIfOutOfRange(Exception, NULL, pos, fList->size);

    CSTL_ForwardListIterator iterator = CSTL_GetForwardListBegin(fList);
    for (size_t i = 0; i < pos; i++)
        CSTL_IterateNextInForwardList(&iterator);
    return (CSTL_ForwardListNode *)iterator.p;
}

void CSTL_InsertAfterToForwardList(CSTL_ForwardList *fList, size_t pos, CSTL_SmartPtr *data) {
    ThrowIfNullNoReturn(Warning, fList);

    if (fList->begin.p == NULL && pos == 0) { // Must execute if the list is empty
        fList->begin.p = (void *)CSTL_CreateForwardListNode(data, NULL);
        fList->size++;
        return;
    }

    ThrowIfOutOfRangeNoReturn(Exception, pos, fList->size);

    CSTL_ForwardListNode *nodeAfter = GetForwardListNodeAt(fList, pos);
    if (nodeAfter == NULL) {
        CSTL_ThrowException(CSTL_NOT_FOUND, "failed to find the after node");
        return;
    }

    CSTL_ForwardListNode *newNode = CSTL_CreateForwardListNode(data, nodeAfter->next);
    if (newNode == NULL)
        return;

    nodeAfter->next = newNode;
    fList->size++;
}

void CSTL_EraseAfterFromForwardList(CSTL_ForwardList *fList, size_t pos) {
    ThrowIfNullNoReturn(Warning, fList);

    CSTL_ForwardListNode *nodeAfter = GetForwardListNodeAt(fList, pos);
    if (nodeAfter == NULL) {
        CSTL_ThrowException(CSTL_NOT_FOUND, "failed to find the after node");
        return;
    }

    if (nodeAfter->next == NULL)
        return;

    CSTL_ForwardListNode *eraseNode = nodeAfter->next;
    nodeAfter->next = eraseNode->next;
    CSTL_DestroyForwardListNode(eraseNode);
    fList->size--;
}
