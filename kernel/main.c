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
		"int $6;"
		"int $7;"
		"int $8;"
		"int $9;"
		"int $10;"
		"int $11;"
		"int $12;"
//		"int $13;"	// General Protection Fault
		"int $14;"
		"int $15;"
		"int $16;"
		"int $17;"
		"int $18;"
		"int $19;"
		"int $20;"
		"int $21;"
		"int $22;"
		"int $23;"
		"int $24;"
		"int $25;"
		"int $26;"
		"int $27;"
		"int $28;"
		"int $29;"
		"int $30;"
		"int $31;"

		"int $32;"
		"int $33;"
		"int $34;"
	);
	int a = 2/0;
}
