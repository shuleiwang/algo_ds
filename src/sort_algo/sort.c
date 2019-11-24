/*
 * sort.c - the implementation of sorting algo  
 *
 * This file is pbulic domain.
 *
 */

#include "arch.h"
#include "sort_algo/count_sort.h"
#include "sort_algo/sort.h"

typedef int (*sort_func)(struct sort_ctx *ctx);

const sort_func g_sort_func_tbl[INVALID_ALGO] = 
{
    count_sort,
};

int sort(enum sort_algo algo, struct sort_ctx *ctx)
{
    return g_sort_func_tbl[algo](ctx);
}

