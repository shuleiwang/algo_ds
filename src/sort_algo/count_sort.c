/*
 * count_sort.c - count sort implementation.
 *
 * This file is public domain.
 */

#include "env.h"
#include "errval.h"
#include "sort_algo/sort.h"
#include "sort_algo/count_sort.h"

int count_sort(struct sort_ctx *ctx)
{
    uint32 *in = (uint32*)ctx->in;
    uint32 *out = (uint32*)ctx->out;
    if (in == 0 || out == 0)
    {
        return ERR_INVALID;
    }

    /* get the maximum and minimum values of the input array */
    uint32 min = in[0];
    uint32 max = in[0];
    for (uint32 idx = 1; idx < ctx->size; ++idx)
    {
        if (in[idx] < min) 
        {
            min = in[idx];
        }
        if (in[idx] > max)
        {
            max = in[idx];
        }
    }

    /* calloc a count array of size (MAX - MIN + 1) and then fill it */
    uint32 *count_array = (uint32*)arch_calloc(max - min + 1, sizeof(uint32));
    if (count_array == 0)
    {
        return ERR_MEM;
    }
    for (uint32 idx = 0; idx < ctx->size; ++idx)
    {
        count_array[in[idx] - min]++;
    }

    /*
     * accumulate count array in sorted order to 
     *      identify the position of each element
     */
    uint32 sum = 0;
    uint32 fix_idx = 0;
    for (uint32 idx = 0; idx <= (max - min); ++idx)
    {
        fix_idx = (ctx->order == ASCENDING) ? idx : (max - min - idx);
        sum += count_array[fix_idx];
        count_array[fix_idx] = sum;
    }

    /* output sorted array according to sorting stability */
    for (uint32 idx = 0; idx < ctx->size; ++idx)
    {
        fix_idx = (ctx->stability == UNSTABLE) ? idx : (ctx->size - 1 - idx);
        out[count_array[in[fix_idx] - min] - 1] = in[fix_idx];
        count_array[in[fix_idx] - min]--;
    }

    /* free count array memory */
    arch_free(count_array);
    count_array = 0;
    return ERR_OK;
}

