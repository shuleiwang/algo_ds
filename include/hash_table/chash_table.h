
// chash_table.h, header file for chained hash table

#ifndef CHASH_TABLE
#define CHASH_TABLE

/* 
 * hash function
 * symbol definition: m @ bucket number 
 * 1. key is integer
 *  1.1 Division method: h(k) = k mod m
 *  1.2 Multiplication method: 
 *      h(k) = floor(m(kA mod 1)), where A == (sqrt(5) - 1) / 2 == 0.618
 * 2. key is string
 * unsigned int hashpjw(const void *key) 
 * {
 *      const char *ptr;
 *      unsigned int val;
 *
 *      val = 0;
 *      ptr = key;
 *      
 *      while (*ptr != '\0') {
 *          unsigned int tmp;
 *
 *          val = (val << 4) + (*ptr);
 *          if (tmp = (val & 0xf0000000)) {
 *              val = val ^ (tmp >> 24);
 *              val = val ^ tmp;
 *          }
 *          
 *          ptr++;
 *      }
 *      
 *      return val % PRIME_TBLSIZE;
 * }
 *
 */

#include <stdlib.h>
#include "../linked_list/list.h" 

struct chash_table
{
    size_t buckets;
    size_t size;

    int (*hash)(const void *key);
    int (*match)(const void *key1, const void *key2);
    void (*destory)(void *data);

    struct list *table;
};

static inline size_t chash_table_size(struct chash_table *htbl)
{
    return htbl->size;
}

int chash_table_init(struct chash_table *htbl, size_t buckets, 
        int (*hash)(const void *key), 
        int (*match)(const void *key1, const void *key2), 
        void (*destory)(void *data));

void chash_table_destory(struct chash_table *htbl);

int chash_table_insert(struct chash_table *htbl, const void *data);

int chash_table_remove(struct chash_table *htbl, void **data);

int chash_table_lookup(const struct chash_table *htbl, void **data);

#endif /* CHASH_TABLE */

