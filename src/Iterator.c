#include "Afx.h"

void _CSTL_FDECL_Iterator_CSTL_ForwardList_iterateForward(CSTL_Iterator *iterator) {
    ThrowIfNullNoReturn(Warning, iterator);
    CSTL_ForwardListElement *element = (CSTL_ForwardListElement *)iterator->element;
    if (element != NULL)
        iterator->element = element->next;
}

CSTL_SmartPtr *_CSTL_FDECL_Iterator_CSTL_ForwardList_getData(const CSTL_Iterator *iterator) {
    ThrowIfNull(Warning, NULL, iterator);
    CSTL_ForwardListElement *element = (CSTL_ForwardListElement *)iterator->element;
    return element == NULL ? NULL : element->data;
}

void _CSTL_FDECL_Iterator_CSTL_ForwardList_setData(CSTL_Iterator *iterator, CSTL_SmartPtr *data) {
    ThrowIfNullNoReturn(Warning, iterator);
    CSTL_ForwardListElement *element = (CSTL_ForwardListElement *)iterator->element;
    if (element != NULL) {
        if (element->data != NULL)
            CSTL_DestroySmartPtr(element->data);

        if (data != NULL)
            CSTL_AddSmartPtrRef(data);

        element->data = data;
    }
}

CSTL_Iterator CSTL_GetForwardListBegin(const CSTL_ForwardList *fList) {
    CSTL_Iterator errorDummy = {NULL, NULL};
    ThrowIfNull(Warning, errorDummy, fList);
    return fList->begin;
}

CSTL_Iterator CSTL_GetForwardListEnd(const CSTL_ForwardList *fList) {
    CSTL_Iterator errorDummy = {NULL, NULL};
    ThrowIfNull(Warning, errorDummy, fList);
    return fList->end;
}

