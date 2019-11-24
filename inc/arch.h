
#ifndef __ARCH_H
#define __ARCH_H

#define x86_64

/*
 * specific memory management method
 */
#if defined(x86) || defined(x86_64)
#include <stdlib.h>

#define SPEC_MALLOC(byte_num) malloc(byte_num)
#define SPEC_FREE(ptr)        free(ptr)

typedef unsigned char uint8;
typedef unsigned int  uint32;

#else

#define SPEC_MALLOC(byte_num) 
#define SPEC_FREE(ptr)        

#endif

#endif /* __ARCH_H */

