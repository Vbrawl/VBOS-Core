#include "isr.h"
#include "../extras/macro_parse.h"


// Include "idt.h" from <TARGET_ARCH> directory
#include TOSTRING(EXPAND(TARGET_ARCH)/idt.h)



#include "../drivers/vga.h"
#include "../extras/types.h"


void init_idt() {
	idt_set_entry(0, (uintptr_t)backendisr0);
	idt_set_entry(1, (uintptr_t)backendisr1);
	enable_idt();
}


/*******************
* Division By Zero *
*******************/
void isr_0() {
	vga_print_string("ERROR: Division By Zero\n\r", RED_ON_WHITE);

	#warning *** You may want to change this action (DivBy0) ***
	__asm__ volatile("cli; hlt");
}


/********
* Debug *
********/
void isr_1() {
	vga_print_string("ERROR: Debug\n\r", RED_ON_WHITE);

	#warning *** Add an action for Debug (Debug) ***
}
