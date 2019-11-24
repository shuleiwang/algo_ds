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
 * @ctx: sorting descriptor
 *
 * Note: 
 * 1. 只支持无符号整数排序
 * 2. 被排序的序列的最大值和最小值之间的差值不能超过进程堆大小
 * 3. 输入和输出序列可以指向同一位置
 */
int count_sort(struct sort_ctx *ctx);

#endif /* __COUNT_SORT_H */ 

