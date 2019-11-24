/*
 *  sort.h - Sorting algorithm pulic header file
 *
 *  This file is public domain.
 */

#ifndef __SORT_H
#define __SORT_H

#include "arch.h"

enum sort_algo 
{
    COUNT_SORTING, 
    INVALID_ALGO,
};

enum sort_order 
{
    ASCENDING = 0,
    DESCEDING,
};

enum sort_stability
{
    UNSTABLE = 0,
    STABLE,
};

struct sort_ctx
{
    void *in;
    uint32 size;
    enum sort_order order; 
    enum sort_stability stability;
    void *out;
};

int sort(enum sort_algo algo, struct sort_ctx *ctx);

#endif /* __SORT_H */

