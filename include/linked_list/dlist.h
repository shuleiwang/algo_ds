
// dlist.h

#include <stdlib.h>

struct dlist_elmt
{
    void *data;
    struct dlist_elmt *prev;
    struct dlist_elmt *next;
};

struct dlist
{
    size_t size;
    void (*destory)(void *data);
    struct dlist_elmt *head;
    struct dlist_elmt *tail;
};

static inline size_t dlist_size(const struct dlist *list)
{
    return list->size;
}

static inline struct dlist_elmt *dlist_head(const struct dlist *list)
{
    return list->head;
}

static inline struct dlist_elmt *dlist_tail(const struct dlist *list)
{
    return list->tail;
}

static inline int is_list_head(const struct dlist_elmt *element)
{
    return (element->prev == NULL ? 1 : 0);
}

static inline int is_list_tail(const struct dlist_elmt *element)
{
    return (element->next == NULL ? 1 : 0);
}

static inline void *elmt_data(const struct dlist_elmt *element)
{
    return element->data;
}

static inline struct dlist_elmt *next_elmt(const struct dlist_elmt *element)
{
    return element->next;
}

static inline struct dlist_elmt *prev_elmt(const struct dlist_elmt *element)
{
    return element->prev;
}

void dlist_init(struct dlist *list, void (*destory)(void *data));
void dlist_destory(struct dlist *list);
int  dlist_ins_next(struct dlist *list, 
        struct dlist_elmt *element, const void *data);
int  dlist_ins_prev(struct dlist *list,
        struct dlist_elmt *element, const void *data);
int dlist_remove(struct dlist *list, struct dlist_elmt *element, void **data);

