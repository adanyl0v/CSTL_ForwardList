#ifndef CSTL_FORWARD_LIST_TYPE_H
#define CSTL_FORWARD_LIST_TYPE_H

#include <CSTL_Iterator/Iterator.h>

#include "Element.h"

struct CSTL_ForwardList {
    size_t size;
    CSTL_Iterator begin;
    CSTL_Iterator end;
};

#endif /* CSTL_FORWARD_LIST_TYPE_H */
