/*
 * count_sort.c - Count sorting implementation.
 *
 * This file is public domain.
 */

#include "arch.h"
#include "sort_algo/sort.h"
#include "sort_algo/count_sort.h"

int count_sort(struct sort_ctx *ctx)
{
    uint32 *in = (uint32*)ctx->in;
    uint32 *out = (uint32*)ctx->out;

    /* 1. 获取输入序列的最大值和最小值 */
    uint32 min = in[0];
    uint32 max = in[0];
    for (uint32 idx = 1; idx < ctx->size; ++idx)
    {
        if (in[idx] < min) 
        {
            min = in[idx];
        }
        else if (in[idx] > max)
        {
            max = in[idx];
        }
    }

    /* 2. 分配统计数组并填充，空间大小为: (max - min + 1) */
    uint32 *count_array = (uint32*)SPEC_MALLOC(max - min + 1);
    for (uint32 idx = 0; idx < ctx->size; ++idx)
    {
        count_array[in[idx] - min]++;
    }

    /* 3. 如果需要稳定排序，对统计数组做变形，标识每一个元素的位置 */
    uint32 sum = 0;
    if (ctx->stability == STABLE)
    {
        for (uint32 idx = 0; idx <= (max - min); ++idx)
        {
            idx = (ctx->order == ASCENDING) ? idx : (max - min - idx);
            sum += count_array[idx];
            count_array[idx] = sum;
        }
    }

    /* 4. 输出已排序好的数组 */
    if (ctx->stability == UNSTABLE)
    {
        uint32 out_idx = 0;
        for (uint32 idx = 0; idx <= max - min; ++idx)
        {
            idx = (ctx->order == ASCENDING) ? idx : (max - min - idx);
            for (uint32 idx1 = 0; idx1 < count_array[idx]; ++idx1)
            {
                out[out_idx++] = idx + min;
            }
        }
    }
    else if (ctx->stability == STABLE)
    {
        for (uint32 idx = 0; idx < ctx->size; ++idx)
        {
            out[count_array[in[idx] - min] - 1] = in[idx];
            count_array[in[idx] - min]--;
        }
    }

    SPEC_FREE(count_array);
    return 0;
}

