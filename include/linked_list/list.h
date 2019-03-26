
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
    return (plist->head == element ? 1 : 0);
}

static inline int is_list_tail(const struct list_elmt *element)
{
    return (element->next == NULL ? 1 : 0);
}

static inline void *elmt_data(const struct list_elmt *element)
{
    return element->data;
}

static inline struct list_elmt *next_elmt(const struct list_elmt *element)
{
    return element->next;
}

/**
 * list_init - initialize list struct
 * @plist - list pointer
 * @data - destory routine of data member
 *
 * Must call before use a list.
 */
void list_init(struct list *plist, void (*destory)(void *data));

/**
 * list_destory - destory list struct
 * @plist - list pointer
 *
 * Destory and free list space.
 */
void list_destory(struct list *plist);

/**
 * list_ins_next - insert an element into list after current element
 * @plist - list pointer
 * @element - current element 
 * @          if it is NULL, insert new element to head of the list.
 * @data - data member pointer
 * @retval - 0 if inserting the is element successful, or -1 otherwise.
 */
int  list_ins_next(struct list *plist, 
        struct list_elmt *element, const void *data);

/**
 * list_rem_next - remove an element from list after current element
 * @plist - list pointer
 * @element - current element
 * @          if it is NULL, remove an element from head of list 
 * @retval - 0 if removing the element is successful, or -1 otherwise.
 */
int  list_rem_next(struct list *plist, 
        struct list_elmt *element, void **pdata);

#endif /* LIST_H */

