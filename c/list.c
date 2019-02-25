
// list.c

#include <stdlib.h>
#include <string.h>
#include "list.h"

void ListInit(List *list, void (*destory)(void *data))
{
    list->size_ = 0;
    list->destory_ = destory;
    list->head_ = NULL;
    list->tail_ = NULL;
}

void ListDestory(List *list)
{
}

