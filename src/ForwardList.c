#include "Afx.h"

CSTL_ForwardList *CSTL_CreateForwardList(void) {
    CSTL_ForwardList *newList = (CSTL_ForwardList *)malloc(sizeof(CSTL_ForwardList));
    ThrowIfFailedAlloc(Exception, NULL, newList);

    newList->size = 0;
    newList->begin.container = (void *)newList;
    newList->begin.element = NULL;
    newList->end.container = (void *)newList;
    newList->end.element = NULL; // End iterator must always be NULL
    return newList;
}

void CSTL_DestroyForwardList(CSTL_ForwardList *fList) {
    ThrowIfNullNoReturn(Warning, fList);
    CSTL_ClearForwardLIst(fList);
    free(fList);
}

CSTL_SmartPtr *CSTL_GetForwardListFront(const CSTL_ForwardList *fList) {
    ThrowIfNull(Warning, NULL, fList);
    if (fList->begin.element == NULL)
        return NULL;

    return CSTL_GetIteratorData(CSTL_ForwardList, &fList->begin);
}

CSTL_SmartPtr *CSTL_GetForwardListBack(const CSTL_ForwardList *fList) {
    ThrowIfNull(Warning, NULL, fList);
    if (fList->end.element == NULL)
        return NULL;

    return CSTL_GetIteratorData(CSTL_ForwardList, &fList->begin);
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
    CSTL_Iterator fListHead = fList->begin;
    CSTL_Iterator fListTail = fList->end;

    fList->size = other->size;
    fList->begin.container = other->begin.container;
    fList->begin.element = other->begin.element;
    fList->end.container = other->end.container;
    fList->end.element = other->end.element;

    other->size = fListSize;
    other->begin.container = fListHead.container;
    other->begin.element = fListHead.element;
    other->end.container = fListTail.container;
    other->end.element = fListTail.element;
}

void CSTL_ClearForwardLIst(CSTL_ForwardList *fList) {
    ThrowIfNullNoReturn(Warning, fList);
    while (fList->size > 0)
        CSTL_PopFrontToFrontList(fList);
}

void CSTL_PushFrontToFrontList(CSTL_ForwardList *fList, CSTL_SmartPtr *data) {
    ThrowIfNullNoReturn(Warning, fList);

    CSTL_ForwardListElement *newElement = CSTL_CreateForwardListElement(data, (CSTL_ForwardListElement *) fList->begin.element);
    if (newElement == NULL) // Unnecessary, because previous function must throw an exception, if failed to create a new node
        return;

    fList->begin.element = (void *)newElement;
    fList->size++;
}

void CSTL_PopFrontToFrontList(CSTL_ForwardList *fList) {
    ThrowIfNullNoReturn(Warning, fList);

    CSTL_ForwardListElement *popNode = (CSTL_ForwardListElement *)fList->begin.element;
    if (popNode == fList->end.element) // Must execute if the node to pop is NULL
        return;

    fList->begin.element = (void *)popNode->next;
    CSTL_DestroyForwardListElement(popNode);
    fList->size--;
}

CSTL_ForwardListElement *GetForwardListNodeAt(const CSTL_ForwardList *fList, size_t pos) {
    ThrowIfNull(Warning, NULL, fList);

    if (pos == 0)
        return fList->begin.element;

    ThrowIfOutOfRange(Exception, NULL, pos, fList->size);

    CSTL_Iterator iterator = CSTL_GetForwardListBegin(fList);
    for (size_t i = 0; i < pos; i++)
        CSTL_IterateForward(CSTL_ForwardList, &iterator);
    return (CSTL_ForwardListElement *)iterator.element;
}

void CSTL_InsertAfterToForwardList(CSTL_ForwardList *fList, size_t pos, CSTL_SmartPtr *data) {
    ThrowIfNullNoReturn(Warning, fList);

    if (fList->begin.element == NULL && pos == 0) { // Must execute if the list is empty
        fList->begin.element = (void *) CSTL_CreateForwardListElement(data, NULL);
        fList->size++;
        return;
    }

    ThrowIfOutOfRangeNoReturn(Exception, pos, fList->size);

    CSTL_ForwardListElement *nodeAfter = GetForwardListNodeAt(fList, pos);
    if (nodeAfter == NULL) {
        CSTL_ThrowException(CSTL_NOT_FOUND, "failed to find the after node");
        return;
    }

    CSTL_ForwardListElement *newElement = CSTL_CreateForwardListElement(data, nodeAfter->next);
    if (newElement == NULL)
        return;

    nodeAfter->next = newElement;
    fList->size++;
}

void CSTL_EraseAfterFromForwardList(CSTL_ForwardList *fList, size_t pos) {
    ThrowIfNullNoReturn(Warning, fList);

    CSTL_ForwardListElement *nodeAfter = GetForwardListNodeAt(fList, pos);
    if (nodeAfter == NULL) {
        CSTL_ThrowException(CSTL_NOT_FOUND, "failed to find the after node");
        return;
    }

    if (nodeAfter->next == NULL)
        return;

    CSTL_ForwardListElement *eraseNode = nodeAfter->next;
    nodeAfter->next = eraseNode->next;
    CSTL_DestroyForwardListElement(eraseNode);
    fList->size--;
}
