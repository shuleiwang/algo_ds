
// chash_table.h, header file for chained hash table

#ifndef CHASH_TABLE
#define CHASH_TABLE

#include <stdlib.h>
#include "../linked_list/list.h" 

struct chash_table
{
    size_t buckets;
    size_t size;
    int (*hash)(const void *key);
    void (*destory)(void *data);
    struct list *table;
};

#endif /* CHASH_TABLE */

