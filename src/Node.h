#pragma once
#ifndef CSTL_FORWARD_LIST_NODE_H
#define CSTL_FORWARD_LIST_NODE_H

#include <CSTL_SmartPointer/SmartPointer.h>

typedef struct CSTL_ForwardListNode {
    CSTL_SmartPtr *data;
    struct CSTL_ForwardListNode *next;
} CSTL_ForwardListNode;

CSTL_ForwardListNode *CSTL_CreateForwardListNode(CSTL_SmartPtr *data, CSTL_ForwardListNode *next);
void CSTL_DestroyForwardListNode(CSTL_ForwardListNode *node);

#endif //CSTL_FORWARD_LIST_NODE_H
