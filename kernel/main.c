#include "../drivers/vga.h"
#include "../extras/memutils.h"

#include "../cpu/isr.h"

int hide_main() {}



void main() {
	init_idt();

	__asm__ volatile("int $1");
	int a = 2/0;
}
