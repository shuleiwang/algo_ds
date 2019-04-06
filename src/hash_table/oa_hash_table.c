// oa_hash_table.c

#include <string.h>
#include "hash_table/oa_hash_table.h"

static char g_vacated;

int oa_hash_table_init(struct oa_hash_table *tbl, size_t positions,
        int (*h1)(const void *key), int (*h2)(const void *key),
        int (*match)(const void *key1, const void *key2),
        void (*destory)(void *data))
{
    size_t idx = 0;

    tbl->positions = positions;
    tbl->size = 0;

    if ((tbl->table = (void**)(malloc(positions * sizeof(void*)))) == NULL)
        return -1;

    for (idx = 0; idx < tbl->positions; ++idx)
        tbl->table[idx] = NULL;

    tbl->destory = destory;
    tbl->h1 = h1;
    tbl->h2 = h2;
    tbl->match = match;

    tbl->vacated = &g_vacated;

    return 0;
}

void oa_hash_table_destory(struct oa_hash_table *tbl)
{
    size_t idx = 0;

    for (idx = 0; idx < tbl->positions; ++idx) {
        if (tbl->destory != NULL &&
            tbl->table[idx] != NULL && tbl->table[idx] != tbl->vacated)
            tbl->destory(tbl->table[idx]);
    }

    free(tbl->table);

    memset(tbl, 0, sizeof(struct oa_hash_table));
}

int oa_hash_table_insert(struct oa_hash_table *tbl, const void *data)
{
    size_t position = 0, idx = 0;
    void *tmp = (void*)data;

    if (tbl->size == tbl->positions)
        return -1;

    if (oa_hash_table_lookup(tbl, &tmp) == 0)
        return 1;

    // use double hashing to hash the key
    for (idx = 0; idx < tbl->positions; ++idx) {
        position = (tbl->h1(data) + (idx * tbl->h2(data))) % tbl->positions;
        if (tbl->table[position] == NULL || 
            tbl->table[position] == tbl->vacated) {
            tbl->table[position] = (void*)data;
            tbl->size++;
            return 0;
        }
    }

    return -1;
}

int os_hash_table_remove(struct oa_hash_table *tbl, void **data)
{
    size_t idx = 0, position = 0;

    for (idx = 0; idx < tbl->positions; ++idx) {
        position = (tbl->h1(*data) + (idx * tbl->h2(*data))) % tbl->positions;
        if (tbl->table[position] == NULL) {
            return -1;
        } else if (tbl->table[position] == tbl->vacated) {
            continue;
        } else if (tbl->match(tbl->table[position], *data) == 0) {
            *data = tbl->table[position];
            tbl->table[position] = tbl->vacated;
            tbl->size--;
            return 0;
        }
    }

    return -1;
}

int oa_hash_table_lookup(struct oa_hash_table *tbl, void **data)
{
    size_t idx = 0, position = 0;

    for (idx = 0; idx < tbl->positions; ++idx) {
        position = (tbl->h1(*data) + (idx * tbl->h2(*data))) % tbl->positions;
        if (tbl->table[position] == NULL) {
            return -1; 
        } else if (tbl->match(tbl->table[position], *data) == 0) {
            *data = tbl->table[position];
            return 0;
        }
    }

    return -1;
}

