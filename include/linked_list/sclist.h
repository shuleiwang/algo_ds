
// sclist.h
// implementation of singly circular linked list

#ifndef SCLIST_H
#define SCLIST_H

#include <stdlib.h>

struct sclist_elmt
{
    void *data;
    struct sclist_elmt *next;
};

struct sclist
{
    size_t size;
    void (*destory)(void *data);
    struct sclist_elmt *head;
};

static inline size_t sclist_size(const struct sclist *list)
{
    return list->size;
}

static inline struct sclist_elmt *sclist_head(const struct sclist *list)
{
    return list->head;
}

static inline void *elmt_data(const struct sclist_elmt *element)
{
    return element->data;
}

static inline struct sclist_elmt *next_elmt(const struct sclist_elmt *element)
{
    return element->next;
}

void sclist_init(struct sclist *list, void (*destory)(void *data));
void sclist_destory(struct sclist *list);
int  sclist_ins_next(struct sclist *list, 
        struct sclist_elmt *element, const void *data);
int  sclist_rem_next(struct sclist *list, 
        struct sclist_elmt *element, void **data);

#endif /* SCLIST_H */

