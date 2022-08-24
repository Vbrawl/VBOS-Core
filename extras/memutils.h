#ifndef MEMORY_UTILS_H
#define MEMORY_UTILS_H

#include "types.h"



/**************************************************************************
* 'memcpy' allows you to copy the contents of 1 memory chunk to another   *
* 'src' is the source chunk (the address to get data from)                *
* 'dest' is the destination chunk (the address to set data to)            *
* 'n' is the size of the chunk to copy                                    *
*                                                                         *
* NOTE: This function does indeed copy the contents of 'src' to 'dest'    *
* but doesn't check if the memory chunks overlap. YOU need to check if    *
* those chunks overlap or not.                                            *
*                                                                         *
* In case the chunks overlap, there is a chance of undefined behaviour    *
* and, as the linux man-page of memcpy states, this created a lot of bugs *
* in applications.                                                        *
**************************************************************************/
void* memcpy(void* dest, void* src, size_t n);


/****************************************************************************
* 'safe_memcpy' is the same as 'memcpy' but decides in which order          *
* to copy the chunk. EG, (0 to n) or (n to 0) depending on relation between *
* 'dest' and 'src' addresses.                                               *
*                                                                           *
* dest < src: copy from left to right (0 to n)                              *
* dest > src: copy from right to left (n to 0)                              *
*                                                                           *
* While this function guaranties that the 'dest' chunk has                  *
* the correct contents of the original 'src', it doesn't guaranty           *
* that the 'src' has the contents it had before (If dest overlaps src)      *
*                                                                           *
* It ONLY ensures about the destination chunk.                              *
****************************************************************************/
void* safe_memcpy(void* dest, void* src, size_t n);



#endif
