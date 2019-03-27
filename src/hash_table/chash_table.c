
// chash_table.c

#include "../../include/linked_list/list.h"
#include "../../include/hash_table/chash_table.h"

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

