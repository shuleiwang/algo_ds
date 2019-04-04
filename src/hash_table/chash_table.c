
// chash_table.c

#include <string.h>
#include "linked_list/list.h"
#include "hash_table/chash_table.h"

int chash_table_init(struct chash_table *htbl, size_t buckets, 
        int (*hash)(const void *key), 
        int (*match)(const void *key1, const void *key2), 
        void (*destory)(void *data))
{
    size_t idx = 0;

    htbl->size = 0;
    htbl->buckets = buckets;
    htbl->hash = hash;
    htbl->match = match;
    htbl->destory = destory;

    if ((htbl->table = 
        (struct list*)malloc(sizeof(struct list) * buckets)) == NULL)
        return -1;

    for (idx = 0; idx < buckets; ++idx)
        list_init(&(htbl->table[idx]), destory);

    return 0;
}

void chash_table_destory(struct chash_table *htbl)
{
    size_t idx = 0;

    for (idx = 0; idx < htbl->buckets; ++idx)
        list_destory(&htbl->table[idx]);

    free(htbl->table);
    htbl = NULL;

    memset(htbl, 0, sizeof(struct chash_table));
}

int chash_table_insert(struct chash_table *htbl, const void *data)
{
    size_t bucket = 0, retval = 0;
    void *tmp = (void*)data;

    if (chash_table_lookup(htbl, &tmp) == 0)
        return 1;

    bucket = htbl->hash((void*)data) % htbl->buckets;

    if ((retval = list_ins_next(&htbl->table[bucket], NULL, data)) == 0)
        htbl->size++;

    return retval;
}

int chash_table_remove(struct chash_table *htbl, void **data)
{
    size_t bucket = 0;
    struct list_elmt *element = NULL, *prev = NULL;

    bucket = htbl->hash(*data) % htbl->buckets;

    for (element = list_head(&htbl->table[bucket]); 
            element != NULL; element = element->next) {
        if (htbl->match(*data, element->data) == 0) {
            if (list_rem_next(&htbl->table[bucket], prev, data) == 0) {
                htbl->size--;
                return 0;
            } else {
                return -1;
            }
        }
        prev = element;
    }

    return -1;
}

int chash_table_lookup(const struct chash_table *htbl, void **data)
{
    size_t bucket = 0;
    struct list_elmt *element = NULL;

    bucket = htbl->hash(*data)  % htbl->buckets;

    for (element = list_head(&htbl->table[bucket]); 
            element != NULL; element = element->next) {
        if (htbl->match(*data, element->data) == 0) {
            *data = element->data;
            return 0;
        }
    }

    return -1;
}

