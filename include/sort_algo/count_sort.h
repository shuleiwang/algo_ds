/*
 *  count_sort.h - Routines for count sorting
 *
 *  This file is public domain.
 */

#ifndef __COUNT_SORT_H
#define __COUNT_SORT_H

#include "sort.h"

/**
 * count_sort - unsigned integer sorting based on counting
 * @ctx: sorting context
 *
 * Note: 
 * 1. Only supports unsigned integer sorting
 * 2. The difference between the maximum and minimum of the sorted sequence 
 *    cannot exceed the process heap size
 */
int count_sort(struct sort_ctx *ctx);

#endif /* __COUNT_SORT_H */ 

