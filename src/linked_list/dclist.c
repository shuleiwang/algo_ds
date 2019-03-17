
// dclist.c

#include <string.h>
#include "../../include/linked_list/dclist.h"


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


}

