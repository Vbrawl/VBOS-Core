#include "idt.h"



void idt_set_entry(int n, uintptr_t handler_addr) {
	idt_entry_t* entry = &idt[n];

	entry->isr_low = handler_addr & 0xFFFF;
	entry->kernel_cs = KERNEL_CS;
	entry->reserved = 0;
	entry->attributes = 0x8E;
	entry->isr_high = handler_addr >> 16;
}


void enable_idt() {
	idtr.limit = (uint16_t)(sizeof(idt_entry_t) * IDT_ENTRIES - 1);
	idtr.base = (uint32_t)(&idt);

	__asm__ __volatile__("lidt %0" : : "m"(idtr));
	//__asm__("sti");
}
