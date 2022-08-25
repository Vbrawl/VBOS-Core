#ifndef IDT_H
#define IDT_H



// Ensure i386 arch
#include "../../extras/macro_parse.h"
#ifndef i386
	#error *** What the fuck?? How did it get here?? ***
#endif



// moved to "macro_parse.h"
// #define KERNEL_CS 0x08




#include "../../extras/types.h"


typedef struct {
	uint16_t	isr_low;
	uint16_t	kernel_cs;
	uint8_t		reserved;
	uint8_t		attributes;
	uint16_t	isr_high;
} __attribute__((packed)) idt_entry_t;


typedef struct {
	uint16_t	limit;
	uint32_t	base;
} __attribute__((packed)) idtr_t;



#define IDT_ENTRIES 256
static idt_entry_t idt[IDT_ENTRIES];
static idtr_t idtr;



void idt_set_entry(int n, uintptr_t handler_addr);
void enable_idt();


#endif
