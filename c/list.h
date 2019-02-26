
// list.h

#ifndef LIST_H
#define LIST_H 

#include <stdlib.h> 

typedef struct _ListElmt
{
    void *data_;
    struct _ListElmt *next_;
} ListElmt;

typedef struct _List
{
    size_t   size_;
    void (*destory_)(void *data);
    ListElmt *head_;
    ListElmt *tail_;
} List;

static inline size_t ListSize(const List *list)
{
    return list->size_;
}

static inline ListElmt* ListHead(const List *list)
{
    return list->head_;
}

static inline ListElmt* ListTail(const List *list)
{
    return list->tail_;
}

static inline int ListIsHead(const List *list, const ListElmt *element)
{
    return list->head_ == element;
}

static inline int ListIsTail(const ListElmt *element)
{
    return element->next_ == NULL;
}

static inline void *ListData(const ListElmt *element)
{
    return element->data_;
}

static inline void *ListNext(const ListElmt *element)
{
    return element->next_;
}

void ListInit(List *list, void (*destory)(void *data));
void ListDestory(List *list);
int  ListInsNext(List *list, ListElmt *element, const void *data);
int  ListRemNext(List *list, ListElmt *element, void **data);

#endif /* LIST_H */

