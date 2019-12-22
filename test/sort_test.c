/*
 * sort_test.c - Simple test of sorting algorithm
 *
 * This file is pbulic domain.
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "env.h"
#include "errval.h"
#include "sort_algo/sort.h"

#define ENTRY_NUM (20)

int main(void)
{
    uint32 in[ENTRY_NUM] = {0};
    uint32 out[ENTRY_NUM] = {0};
    uint32 ret = 0;

    srand (time(NULL));
    printf("input sequence: ");
    for (uint32 idx = 0; idx < ENTRY_NUM; ++idx)
    {
        in[idx] = rand() % 50 + 1;
        printf("%u ", in[idx]);
    }
    printf("\n");

    struct sort_ctx ctx;
    ctx.in = in;
    ctx.size = ENTRY_NUM;
    ctx.order = ASCENDING;
    ctx.stability = UNSTABLE;
    ctx.out = out;
    ret = sort(COUNT_SORTING, &ctx);
    if (ret != ERR_OK)
    {
        printf("sort error: %d", ret);
        return -1;
    } 

    printf("output sequence: ");
    for (uint32 idx = 0; idx < ENTRY_NUM; ++idx)
    {
        printf("%u ", out[idx]);
    }
    printf("\n");

    return 0;
}


