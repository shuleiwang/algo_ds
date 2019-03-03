
// dlist.c

#include <string.h>
#include "dlist.h"

/**
 * dlist_init - initialize doubly-linked list
 * @list - doubly-linked list pointer
 * @destory - function pointer which provides a way to free data space
 *
 * Must call before use doubly-linked list
 */
void dlist_init(struct dlist *list, void (*destory)(void *data))
{
    list->size = 0;
    list->destory = destory;
    list->head = NULL;
    list->tail = NULL;
}

/**
 * dlist_destory - destory doubly-linked list
 * @list - doubly-linked list pointer
 *
 * Remove all elements from doubly-linked list
 */
void dlist_destory(struct dlist *list)
{
    void *data = NULL;

    while (dlist_size(list) > 0) {
        if (dlist_remove(list, dlist_tail(list), &data) == 0 && 
            list->destory != NULL)
            list->destory(data);
    }

    memset(list, 0, sizeof(struct dlist));
}

int  dlist_ins_next(struct dlist *list,
        struct dlist_elmt *element, const void *data)
{
    struct dlist_elmt *new_element = NULL;

    if (element == NULL && dlist_size(list) != 0)
        return -1;

    if ((new_element = (struct dlist_elmt*)malloc(sizeof(struct dlist_elmt))) == NULL)
        return -1;

    new_element->data = (void*)data;

    if (dlist_size(list) == 0) {
        list->head = new_element;
        list->head->next = NULL;
        list->head->prev = NULL;
        list->tail = new_element;
    } else {
        new_element->prev = element;
        new_element->next = element->next;
        if (is_list_tail(element->next))
            list->tail = new_element;
        else
            element->next->prev = new_element;
        element->next = new_element;
    }

    list->size++;

    return 0;
}

int  dlist_ins_prev(struct dlist *list,
        struct dlist_elmt *element, const void *data)
{
    return 0;
}

int dlist_remove(struct dlist *list, struct dlist_elmt *element, void **data)
{
    return 0;
}

