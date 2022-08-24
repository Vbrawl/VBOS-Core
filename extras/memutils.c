#include "memutils.h"






void* memcpy(void* dest, void* src, size_t n) {
	if(dest == src) return dest;

	for(int i = 0; i < n; i++) {
		((char*)dest)[i] = ((char*)src)[i];
	}
	return dest;
}



void* safe_memcpy(void* dest, void* src, size_t n) {
	if(dest == src) return dest;

	if(dest < src) {
		for(int i = 0; i < n; i++) {
			((char*)dest)[i] = ((char*)src)[i];
		}
	}
	else {
		for(int i = n; i > -1; i--) {
			((char*)dest)[i] = ((char*)src)[i];
		}
	}
	return dest;
}
