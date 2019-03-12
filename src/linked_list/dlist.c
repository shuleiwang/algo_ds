
// dlist.c

#include <string.h>
#include "linked_list/dlist.h"

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

/**
 * dlist_ins_next - insert a new element after current element
 * @list - doubly-linked list pointer
 * @element - current element
 * @data - data member pointer
 */
int  dlist_ins_next(struct dlist *list,
        struct dlist_elmt *element, const void *data)
{
    struct dlist_elmt *new_element = NULL;

    if (element == NULL && dlist_size(list) != 0)
        return -1;

    if ((new_element = 
        (struct dlist_elmt*)malloc(sizeof(struct dlist_elmt))) == NULL)
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

/**
 * dlist_ins_prev - insert a new element before current element
 * @list - doubly-linked list pointer
 * @element - current element
 * @data - data member pointer
 */
int  dlist_ins_prev(struct dlist *list,
        struct dlist_elmt *element, const void *data)
{
    struct dlist_elmt *new_element = NULL; 

    if (element == NULL && dlist_size(list) != 0)
        return -1;

    if ((new_element = 
        (struct dlist_elmt*)malloc(sizeof(struct dlist_elmt))) == NULL)
        return -1;

    new_element->data = (void*)data;

    if (dlist_size(list) == 0) {
        list->head = new_element;
        new_element->next = NULL;
        new_element->prev = NULL;
        list->tail = new_element;
    } else {
        new_element->next = element;
        new_element->prev = element->prev;
        if (is_list_head(element))
            list->head = new_element;
        else 
            element->prev->next = new_element;
        element->prev = new_element;
    }

    list->size++;
    return 0;
}

/**
 * dlist_remove - remove current element from doubly-linked list
 * @list - doubly-linked list pointer
 * @element - removed element
 * @data - data member 
 */
int dlist_remove(struct dlist *list, struct dlist_elmt *element, void **data)
{
    if (dlist_size(list) == 0 || element == NULL)
        return -1;

    *data = element->data;

    if (is_list_head(element)) {
        list->head = element->next;
        if (list->head == NULL)
            list->tail = NULL;
        else 
            element->next->prev = NULL;
    } else {
        element->prev->next = element->next;
        if (is_list_tail(element))
            list->tail = element->prev;
        else
            element->next->prev = element->prev;
    }

    free(element);

    list->size--;

    return 0;
}

