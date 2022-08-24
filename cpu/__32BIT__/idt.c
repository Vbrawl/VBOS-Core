#include "idt.h"
#include "../../extras/bitutils.h"


void set_idt_entry(int n, uint32_t handler_address, bool is_trap, uint8_t access_level) {
	// Parse attributes
	uint8_t attributes = 0;
	if(is_trap)	attributes = TRAP_CODE;
	else		attributes = INTERRUPT_CODE;
	attributes |= (access_level & 3) << 6; // last 2 bits in the appropriate position
	attributes |= 0x80; // 0x80 is the 'Present bit'

	// Set entry values
	IDT_TABLE[n].isr_low	= get_low16_bits(n);
	IDT_TABLE[n].kernel_cs	= KERNEL_CS;
	IDT_TABLE[n].reserved	= 0;
	IDT_TABLE[n].attributes	= attributes;
	IDT_TABLE[n].isr_high	= get_high16_bits(n);
}
