
// list.c

#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * list_init - initialize list struct
 * @plist - list pointer
 * @data - destory routine of data member
 *
 * Must call before use a list.
 */
void list_init(struct list *plist, void (*destory)(void *data))
{
    plist->size = 0;
    plist->destory = destory;
    plist->head = NULL;
    plist->tail = NULL;
}

/**
 * list_destory - destory list struct
 * @plist - list pointer
 *
 * Destory and free list space.
 */
void list_destory(struct list *plist)
{
    void *data = NULL;

    while (list_size(plist) > 0) {
        if (list_rem_next(plist, NULL, &data) == 0 && plist->destory != NULL)
            plist->destory(data);
    }
    memset(plist, 0, sizeof(struct list));
}

/**
 * list_ins_next - insert an element into list after current element
 * @plist - list pointer
 * @element - current element 
 * @          if it is NULL, insert new element to head of the list.
 * @data - data member pointer
 * @retval - 0 if inserting the is element successful, or -1 otherwise.
 */
int list_ins_next(struct list *plist, 
        struct list_elmt *element, const void *data)
{
    struct list_elmt *new_element = (struct list_elmt*)malloc(sizeof(struct list_elmt));
    if (new_element == NULL) 
        return -1;

    new_element->data = (void*)data;
    if (element == NULL) {
        if (list_size(plist) == 0)
            plist->tail = new_element;
        new_element->next = plist->head;
        plist->head = new_element;
    } else {
        if (is_list_tail(element)) 
            plist->tail = new_element;
        new_element->next = element->next;
        element->next = new_element;
    }
    
    plist->size++;

    return 0;
}

/**
 * list_rem_next - remove an element from list after current element
 * @plist - list pointer
 * @element - current element
 * @          if it is NULL, remove an element from head of list 
 * @retval - 0 if removing the element is successful, or -1 otherwise.
 */
int list_rem_next(struct list *plist, 
        struct list_elmt *element, void **pdata)
{
    struct list_elmt *old_elmt = NULL;

    if (list_size(plist) == 0)
        return -1;

    if (element == NULL) {
        if (list_size(plist) == 1)
            plist->tail = NULL;
        *pdata = plist->head->data;
        old_elmt = plist->head;
        plist->head = plist->head->next;
    } else {
        if (is_list_tail(element))
            return -1;
        *pdata = element->next->data;
        old_elmt = element->next;
        element->next = element->next->next;
        if (is_list_tail(element->next))
            plist->tail = element;
    }

    free(old_elmt);

    plist->size--;

    return 0;
}

