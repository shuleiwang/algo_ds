
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

/**
 * dlist_init - initialize doubly-linked list
 * @list - doubly-linked list pointer
 * @destory - function pointer which provides a way to free data space
 *
 * Must call before use doubly-linked list
 */
void dlist_init(struct dlist *list, void (*destory)(void *data));

/**
 * dlist_destory - destory doubly-linked list
 * @list - doubly-linked list pointer
 *
 * Remove all elements from doubly-linked list
 */
void dlist_destory(struct dlist *list);

/**
 * dlist_ins_next - insert a new element after current element
 * @list - doubly-linked list pointer
 * @element - current element
 * @data - data member pointer
 */
int  dlist_ins_next(struct dlist *list, 
        struct dlist_elmt *element, const void *data);

/**
 * dlist_ins_prev - insert a new element before current element
 * @list - doubly-linked list pointer
 * @element - current element
 * @data - data member pointer
 */
int  dlist_ins_prev(struct dlist *list,
        struct dlist_elmt *element, const void *data);

/**
 * dlist_remove - remove current element from doubly-linked list
 * @list - doubly-linked list pointer
 * @element - removed element
 * @data - data member 
 */
int dlist_remove(struct dlist *list, struct dlist_elmt *element, void **data);

