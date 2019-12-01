/*
 * sort.c - the implementation of sorting algo  
 *
 * This file is pbulic domain.
 *
 */

#include "env.h"
#include "errval.h"
#include "sort_algo/count_sort.h"
#include "sort_algo/sort.h"

typedef int (*sort_func)(struct sort_ctx *ctx);

const sort_func g_sort_func_tbl[INVALID_ALGO] = 
{
    count_sort,
};

int sort(uint32 sort_algo, struct sort_ctx *ctx)
{
    if (sort_algo < 0 || sort_algo >= INVALID_ALGO || ctx == 0)
    {
        return ERR_INVALID;
    }

    return g_sort_func_tbl[sort_algo](ctx);
}

