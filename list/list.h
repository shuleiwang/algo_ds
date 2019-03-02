
// list.h

#ifndef LIST_H
#define LIST_H 

#include <stdlib.h>

struct list_elmt
{
    void *data;
    struct list_elmt *next;
}; 

struct list 
{
    size_t   size;
    void (*destory)(void *data);
    struct list_elmt *head;
    struct list_elmt *tail;
};

static inline size_t list_size(const struct list *plist)
{
    return plist->size;
}

static inline struct list_elmt *list_head(const struct list *plist)
{
    return plist->head;
}

static inline struct list_elmt *list_tail(const struct list *plist)
{
    return plist->tail;
}

static inline int is_list_head(const struct list *plist, 
                               const struct list_elmt *element)
{
    return (plist->head == element);
}

static inline int is_list_tail(const struct list_elmt *element)
{
    return (element->next == NULL);
}

static inline void *elmt_data(const struct list_elmt *element)
{
    return element->data;
}

static inline void *next_elmt(const struct list_elmt *element)
{
    return element->next;
}

void list_init(struct list *plist, void (*destory)(void *data));
void list_destory(struct list *plist);
int  list_ins_next(struct list *plist, 
        struct list_elmt *element, const void *data);
int  list_rem_next(struct list *plist, 
        struct list_elmt *element, void **pdata);

#endif /* LIST_H */

