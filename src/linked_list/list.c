
// list.c

#include <stdlib.h>
#include <string.h>
#include "linked_list/list.h"

void list_init(struct list *plist, void (*destory)(void *data))
{
    plist->size = 0;
    plist->destory = destory;
    plist->head = NULL;
    plist->tail = NULL;
}

void list_destory(struct list *plist)
{
    void *data = NULL;

    while (list_size(plist) > 0) {
        if (list_rem_next(plist, NULL, &data) == 0 && plist->destory != NULL)
            plist->destory(data);
    }
    memset(plist, 0, sizeof(struct list));
}

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

