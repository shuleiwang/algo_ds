
// chash_table.h, header file for chained hash table

#ifndef CHASH_TABLE
#define CHASH_TABLE

/* 
 * hash function
 * symbol definition: m @ bucket number 
 * 1. key is integer *  1.1 Division method: h(k) = k mod m *  1.2 Multiplication method: 
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
#include "linked_list/list.h" 

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

/** 
 * chash_table_init - init a chained hash table
 * @htbl - pointer of chained hash table
 * @bucket - the number of list
 * @hash - hash function
 * @match - function of comparing two key
 * @destory - destructor of data element
 *
 * @retval - 0 if initialize chained hash table successfully, or -1 otherwise
 */
int chash_table_init(struct chash_table *htbl, size_t buckets, 
        int (*hash)(const void *key), 
        int (*match)(const void *key1, const void *key2), 
        void (*destory)(void *data));

/**
 * chash_table_destory - destory a chained hash table
 * @htbl - pointer of chained hash table */
void chash_table_destory(struct chash_table *htbl);

/**
 * chash_table_insert - insert an element to chained hash table
 * @htbl - pointer to chained hash table
 * @data - pointer to element's data member
 *
 * @retval - 1 if this element existed; 
 *           0 if insert this element successfully or -1 otherwise
 */
int chash_table_insert(struct chash_table *htbl, const void *data);

/**
 * chash_table_remove - remove an element from chained hash table
 * @htbl - pointer to chained hash table
 * @data - pointer's pointer to data member
 *
 * @retval - 0 if removing element successful, or ohterwise -1
 */
int chash_table_remove(struct chash_table *htbl, void **data);

/**
 * chash_table_lookup - search an element from chained hash table
 * @htbl - pointer to chained hash table
 * @data - pointer's pointer to data member
 *
 * @retval - 0 if the element is found, -1 otherwise
 */
int chash_table_lookup(const struct chash_table *htbl, void **data);

#endif /* CHASH_TABLE */

