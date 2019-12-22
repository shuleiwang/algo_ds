/*
 *  sort.h - Sorting algorithm pulic header file
 *
 *  This file is public domain.
 */

#ifndef __SORT_H
#define __SORT_H

#include "env.h"

/* sort method */ 
enum {
    COUNT_SORTING, 
    INVALID_ALGO,
};

/* sort order */
enum {
    ASCENDING = 0,
    DESCENDING,
};

/* sort stability */
enum {
    UNSTABLE = 0,
    STABLE,
};

struct sort_ctx {
    void   *in;
    uint32 size;
    uint32 order; 
    uint32 stability;
    void   *out;
};

int sort(uint32 sort_algo, struct sort_ctx *ctx);

#endif /* __SORT_H */

