// oa_hash_table.h

#ifndef OA_HASH_TABLE
#define OA_HASH_TABLE

/** open addressed hash table knowledge background:
 *
 * 1. symbol definition:
 *   n - the number of elements
 *   m - the number of position of hash table
 *   alpha - load factor: alpha = n / m
 *   ep - expected probes: ep =  1 / (1 - alpha)
 *
 * 2. probe approach:
 *   2.1 linear probing: h(k, i) = (h'(k) + i) mod m
 *   2.2 double hashing: h(k, i) = (h1(k) + ih2(k)) mod m
 *       h1(k) = k mod m; h2(k) = 1 + (k mod m'), m' = m - 1
 */

#include <stdlib.h> 

struct oa_hash_table
{
    size_t positions;
    size_t size;

    int (*h1)(const void *key);
    int (*h2)(const void *key);
    int (*match)(const void *key1, const void *key2);
    void (*destory)(void *data);

    void *vacated;

    void **table;
};

/**
 * oa_hash_table_init - initialize a open addressed hash table
 * @tbl - pointer to hash table
 * @positions - the number of positions in the hash table
 * @h1 - the first hash function
 * @h2 - the second hash function
 * @match - match element function
 * @destory - data member destory function
 *
 * @retval - 0 if initializing the hash table is successful, or -1 otherwise
 *
 * @time complexity: O(m)
 */
int oa_hash_table_init(struct oa_hash_table *tbl, size_t positions,
        int (*h1)(const void *key), int (*h2)(const void *key),
        int (*match)(const void *key1, const void *key2),
        void (*destory)(void *data));

/**
 * oa_hash_table_destory - destory a open addressed hash table
 * @tbl - pointer to open addressed hash table
 *
 * @time complexity: O(m)
 */
void oa_hash_table_destory(struct oa_hash_table *tbl);

/**
 * oa_hash_table_insert - insert an element to open addressed hash table
 * @tbl - pointer to open addressed hash table
 * @data - pointer to data memory
 *
 * @retval - 0 if inserting this element is successful, 
 *         - 1 if the element is already in the hash table, or -1 otherwise
 *
 * @time complexity: O(1)
 */
int oa_hash_table_insert(struct oa_hash_table *tbl, const void *data);

/**
 * oa_hash_table_remove - remove an element from open addressed hash table
 * @tbl - pointer to open addressed hash table
 * @data - pointer's pointer to data memory
 *
 * @retval - 0 if removing the element is successful, or -1 otherwise
 *
 * @time complexity: O(1)
 */
int os_hash_table_remove(struct oa_hash_table *tbl, void **data);

/**
 * oa_hash_table_lookup - search the element in the open addressed hash table
 * @tbl - pointer to open addressed hash table
 * @data - pointer's pointer to data memory
 *
 * @retval - 0 if the element is found in the hash table, or -1 otherwise
 *
 * @time complexity: O(1)
 */
int oa_hash_table_lookup(struct oa_hash_table *tbl, void **data);

/*
 * oa_hash_table_size - return the number of element in the hash table
 * @tbl - pointer to open addressed hash table
 *
 * @retval - the number of element in the hash table
 *
 * @time complexity: O(1)
 */
static inline size_t oa_hash_table_size(struct oa_hash_table *tbl)
{
    return tbl->size;
}

#endif /* OA_HASH_TABLE */

