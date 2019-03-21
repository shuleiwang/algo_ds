
// dclist.c

#include <string.h>
#include "linked_list/dclist.h"

void dclist_init(struct dclist *list, void (*destory)(void *data))
{
    list->size = 0;
    list->destory = destory;
    list->head = NULL;
}

void dclist_destory(struct dclist *list)
{
    void *data = NULL;
    while (dclist_size(list) > 0) {
        if (dclist_remove(list, list->head, &data) == 0 && list->destory != NULL) 
            list->destory(data);
    }

    memset(list, 0, sizeof(struct dclist));
}

int dclist_ins_next(struct dclist *list, 
        struct dclist_elmt *element, const void *data)
{
    struct dclist_elmt *new_element = NULL;

    if (element == NULL && dclist_size(list) != 0)
        return -1;

    if ((new_element = 
        (struct dclist_elmt*)malloc(sizeof(struct dclist_elmt))) == NULL)
        return -1;

    new_element->data = (void*)data;

    if (dclist_size(list) == 0) {
        new_element->next = new_element;
        new_element->prev = new_element;
        list->head = new_element;
    } else {
        new_element->next = element->next;
        new_element->prev = element;
        element->next->prev = new_element;
        element->next = new_element;
    }

    list->size++;
    return 0;
}

int dclist_ins_prev(struct dclist *list, 
        struct dclist_elmt *element, const void *data)
{
    struct dclist_elmt *new_element = NULL;

    if (element == NULL && dclist_size(list) != 0)
        return -1;

    if ((new_element = 
        (struct dclist_elmt*)malloc(sizeof(struct dclist_elmt))) == NULL)
        return -1;

    new_element->data = (void*)data;

    if (dclist_size(list) == 0) {
        new_element->next = new_element;
        new_element->prev = new_element;
        list->head = new_element;
    } else {
        new_element->next = element;
        new_element->prev = element->prev;
        if (element == list->head)
            list->head = new_element;
        element->prev->next = new_element;
        element->prev = new_element;
    }

    list->size++;
    return 0;
}

int dclist_remove(struct dclist *list, struct dclist_elmt *element, void **data)
{
    if (dclist_size(list) == 0 || element == NULL)
        return -1;

    *data = element->data;

    if (element->next == element) {
        list->head = NULL;
    } else {
        element->prev->next = element->next;
        element->next->prev = element->prev;
        if (list->head == element) 
            list->head = element->next;
    }

    free(element);

    list->size--;

    return 0;
}

