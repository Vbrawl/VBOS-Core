#include "ports.h"



unsigned char port_bin(unsigned short port) {

	unsigned char res;

	__asm__("in %%dx, %%al": "=a"(res): "d"(port));
	return res;
}


void port_bout(unsigned short port, unsigned char data) {
	__asm__("out %%al, %%dx":: "a"(data), "d"(port));
}
