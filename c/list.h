
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

#define LIST_SIZE(list) ((list)->size_)
#define LIST_HEAD(list) ((list)->head_)
#define LIST_TAIL(list) ((list)->tail_)
#define LIST_IS_HEAD(list, element) ((element == list->head_) ? 1 : 0)
#define LIST_IS_TAIL(element) ((element->next_ == NULL) ? 1 : 0)
#define LIST_DATA(element) (element->data_)
#define LIST_NEXT(element) (element->next_)

void ListInit(List *list, void (*destory)(void *data));
void ListDestory(List *list);
int  ListInsNext(List *list, ListElmt *element, const void *data);
int  ListRemNext(List *list, ListElmt *element, const void **data);

#endif /* LIST_H */

