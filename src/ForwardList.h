#pragma once
#ifndef CSTL_FORWARD_LIST_TYPE_H
#define CSTL_FORWARD_LIST_TYPE_H

#include "Node.h"
#include "../include/Iterator.h"

struct CSTL_ForwardList {
    size_t size;
    CSTL_ForwardListIterator begin;
    CSTL_ForwardListIterator end;
};

#endif /* CSTL_FORWARD_LIST_TYPE_H */
