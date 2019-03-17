
#ifndef DCLIST_H
#define DCLIST_H

#include <stdlib.h> 

struct dclist_elmt
{
    void *data;
    struct dclist_elmt *next;
    struct dclist_elmt *prev;
};

struct dclist
{
    size_t size;
    void (*destory)(void *data);
    struct dclist_elmt *head;
};

static inline size_t dclist_size(struct dclist *list)
{
    return list->size;
}

void dclist_init(struct dclist *list, void (*destory)(void *data));
void dclist_destory(struct dclist *list);
int dclist_ins_next(struct dclist *list, 
        struct dclist_elmt *element, const void *data);
int dclist_ins_prev(struct dclist *list, 
        struct dclist_elmt *element, const void *data);
int dclist_remove(struct dclist *list, struct dclist_elmt *element, void **data);

#endif /* DCLIST_H */

