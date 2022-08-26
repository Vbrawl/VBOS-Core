#include "../drivers/vga.h"
#include "../extras/memutils.h"

#include "../cpu/isr.h"

int hide_main() {}



void main() {
	init_idt();

	__asm__(
		"int $1;"
		"int $2;"
		"int $3;"
		"int $4;"
		"int $5;"


	);
	int a = 2/0;
}
