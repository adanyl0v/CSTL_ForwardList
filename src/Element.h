#ifndef CSTL_FORWARD_LIST_ELEMENT_H
#define CSTL_FORWARD_LIST_ELEMENT_H

#include <CSTL_SmartPointer/SmartPointer.h>

typedef struct CSTL_ForwardListElement {
    CSTL_SmartPtr *data;
    struct CSTL_ForwardListElement *next;
} CSTL_ForwardListElement;

CSTL_ForwardListElement *CSTL_CreateForwardListElement(CSTL_SmartPtr *data, CSTL_ForwardListElement *next);
void CSTL_DestroyForwardListElement(CSTL_ForwardListElement *node);

#endif /* CSTL_FORWARD_LIST_ELEMENT_H */
