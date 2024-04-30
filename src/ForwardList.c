#include "Afx.h"

CSTL_ForwardList *CSTL_CreateForwardList(void) {
    CSTL_ForwardList *newList = (CSTL_ForwardList *)malloc(sizeof(CSTL_ForwardList));
    ThrowIfFailedAlloc(Exception, NULL, newList);

    newList->size = 0;
    newList->begin.fList = (void *)newList;
    newList->begin.node = NULL;
    newList->end.fList = (void *)newList;
    newList->end.node = NULL; // End iterator must always be NULL
    return newList;
}

void CSTL_DestroyForwardList(CSTL_ForwardList *fList) {
    ThrowIfNullNoReturn(Warning, fList);
    CSTL_ClearForwardLIst(fList);
    free(fList);
}

CSTL_SmartPtr *CSTL_GetForwardListFront(const CSTL_ForwardList *fList) {
    ThrowIfNull(Warning, NULL, fList);
    if (fList->begin.node == NULL)
        return NULL;

    return ((CSTL_ForwardListNode *)fList->begin.node)->data;
}

CSTL_SmartPtr *CSTL_GetForwardListBack(const CSTL_ForwardList *fList) {
    ThrowIfNull(Warning, NULL, fList);
    if (fList->end.node == NULL)
        return NULL;

    return ((CSTL_ForwardListNode *)fList->end.node)->data;
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
    fList->begin.fList = other->begin.fList;
    fList->begin.node = other->begin.node;
    fList->end.fList = other->end.fList;
    fList->end.node = other->end.node;

    other->size = fListSize;
    other->begin.fList = fListHead.fList;
    other->begin.node = fListHead.node;
    other->end.fList = fListTail.fList;
    other->end.node = fListTail.node;
}

void CSTL_ClearForwardLIst(CSTL_ForwardList *fList) {
    ThrowIfNullNoReturn(Warning, fList);
    while (fList->size > 0)
        CSTL_PopFrontToFrontList(fList);
}

void CSTL_PushFrontToFrontList(CSTL_ForwardList *fList, CSTL_SmartPtr *data) {
    ThrowIfNullNoReturn(Warning, fList);

    CSTL_ForwardListNode *newNode = CSTL_CreateForwardListNode(data, (CSTL_ForwardListNode *)fList->begin.node);
    if (newNode == NULL) // Unnecessary, because previous function must throw an exception, if failed to create a new node
        return;

    fList->begin.node = (void *)newNode;
    fList->size++;
}

void CSTL_PopFrontToFrontList(CSTL_ForwardList *fList) {
    ThrowIfNullNoReturn(Warning, fList);

    CSTL_ForwardListNode *popNode = (CSTL_ForwardListNode *)fList->begin.node;
    if (popNode == fList->end.node) // Must execute if the node to pop is NULL
        return;

    fList->begin.node = (void *)popNode->next;
    CSTL_DestroyForwardListNode(popNode);
    fList->size--;
}

CSTL_ForwardListNode *GetForwardListNodeAt(const CSTL_ForwardList *fList, size_t pos) {
    ThrowIfNull(Warning, NULL, fList);

    if (pos == 0)
        return fList->begin.node;

    ThrowIfOutOfRange(Exception, NULL, pos, fList->size);

    CSTL_ForwardListIterator iterator = CSTL_GetForwardListBegin(fList);
    for (size_t i = 0; i < pos; i++)
        CSTL_IterateNextInForwardList(&iterator);
    return (CSTL_ForwardListNode *)iterator.node;
}

void CSTL_InsertAfterToForwardList(CSTL_ForwardList *fList, size_t pos, CSTL_SmartPtr *data) {
    ThrowIfNullNoReturn(Warning, fList);

    if (fList->begin.node == NULL && pos == 0) { // Must execute if the list is empty
        fList->begin.node = (void *)CSTL_CreateForwardListNode(data, NULL);
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
