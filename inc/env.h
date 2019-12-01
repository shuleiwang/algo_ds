/*
 *  env.h - compile and runtime environment routine definition
 *
 *  This file is public domain.
 */

#ifndef __ENV_H
#define __ENV_H

#define x86_64

/*
 * architecture-specific memory management method
 */
#if defined(x86) || defined(x86_64)
#include <stdlib.h>

typedef unsigned char uint8;
typedef unsigned int  uint32;

#define arch_malloc(byte_num)            malloc(byte_num)
#define arch_calloc(elem_num, elem_size) calloc(elem_num, elem_size)
#define arch_realloc(ptr, byte_num)      realloc(ptr, byte_num)
#define arch_free(ptr)                   free(ptr)

#else

#define arch_malloc(byte_num)            
#define arch_calloc(elem_num, elem_size) 
#define arch_realloc(ptr, byte_num)     
#define arch_free(ptr)                   

#endif

#endif /* __ENV_H */

