
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
    void *data = NULL;

    while (ListSize(list) > 0)
    {
        if (ListRemNext(list, NULL, &data) == 0 && 
            list->destory_ != NULL)
        {
            list->destory_(data);
        }
    }
    memset(list, 0, sizeof(List));
}

int ListInsNext(List *list, ListElmt *element, const void *data)
{
    ListElmt *new_element = (ListElmt*)malloc(sizeof(ListElmt));
    if (new_element == NULL) return -1;

    new_element->data_ = (void*)data;
    if (element == NULL)
    {
        if (ListSize(list) == 0)
        {
            list->tail_ = new_element;
        }
        new_element->next_ = list->head_;
        list->head_ = new_element;
    }
    else
    {
        if (ListIsTail(element))
        {
            element->next_ = new_element;
            new_element->next_ = NULL;
        }
        else
        {
            new_element->next_ = element->next_;
            element->next_ = new_element;
        }
    }
    
    ++list->size_ ;

    return 0;
}


