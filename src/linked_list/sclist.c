
// sclist.c

#include <string.h>
#include "linked_list/sclist.h"

void sclist_init(struct sclist *list, void (*destory)(void *data))
{
    list->size = 0;
    list->destory = destory;
    list->head = NULL;
}

void sclist_destory(struct sclist *list)
{
    void *data = NULL;
    while (sclist_size(list) > 0) {
        if (sclist_rem_next(list, list->head, &data) == 0 && list->destory != NULL)
            list->destory(data);
    }

    memset(list, 0, sizeof(struct sclist));
}

int  sclist_ins_next(struct sclist *list, 
        struct sclist_elmt *element, const void *data)
{
    struct sclist_elmt *new_element = NULL;

    if ((new_element = (struct sclist_elmt*)malloc(sizeof(struct sclist))) == NULL) 
        return -1;

    if (element == NULL && sclist_size(list) != 0)
        return -1;

    new_element->data = (void*)data;

   if (sclist_size(list) == 0) {
        new_element->next = new_element;
        list->head = new_element;
    } else {
        new_element->next = element->next;
        element->next = new_element;
    }

    list->size++;

    return 0;
}

int  sclist_rem_next(struct sclist *list, 
        struct sclist_elmt *element, void **data)
{
    struct sclist_elmt *old_element = NULL;

    if (sclist_size(list) == 0 || element == NULL)
        return -1;

    *data = element->next->data;

    if (element->next == element) {
        old_element = element->next;
        list->head = NULL;
    } else {
        old_element = element->next;
        element->next = element->next->next;
        if (sclist_head(list) == old_element)
            list->head = old_element->next;
    }

    free(old_element);

    list->size--;

    return 0;
}

