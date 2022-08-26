#include "isr.h"
#include "../extras/macro_parse.h"


// Include "idt.h" from <TARGET_ARCH> directory
#include TOSTRING(EXPAND(TARGET_ARCH)/idt.h)



#include "../drivers/vga.h"
#include "../extras/types.h"


void init_idt() {
	idt_set_entry(0, (uintptr_t)backendisr0);
	idt_set_entry(1, (uintptr_t)backendisr1);
	idt_set_entry(2, (uintptr_t)backendisr2);
	idt_set_entry(3, (uintptr_t)backendisr3);
	idt_set_entry(4, (uintptr_t)backendisr4);
	idt_set_entry(5, (uintptr_t)backendisr5);
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

/***************
* Non-Maskable *
****************/
void isr_2() {
	vga_print_string("ERROR: Non-Maskable\n\r", RED_ON_WHITE);

	#warning *** Add an action for Non-Maskable ***
}

/*************
* Breakpoint *
*************/
void isr_3() {
	vga_print_string("ERROR: Breakpoint\n\r", RED_ON_WHITE);

	#warning *** Add an action for Breakpoint ***
}

/*************************
* Into Detected Overflow *
*************************/
void isr_4() {
	vga_print_string("ERROR: Into Detected Overflow\n\r", RED_ON_WHITE);

	#warning *** Add an action for Into Detected Overflow ***
}

/****************
* Out of Bounds *
****************/
void isr_5() {
	vga_print_string("ERROR: Out of Bounds\n\r", RED_ON_WHITE);

	#warning *** Add an action for Out of Bounds ***
}


// Invalid OpCode

//No Coprocessor
// Double Fault
//Coprocessor Segment Overrun Exception
//Bad TSS Exception
//Segment Not Present Exception
//Stack Fault Exception
//General Protection Fault Exception
//Page Fault Exception
//Unknown Interrupt Exception
//Coprocessor Fault Exception
//Alignment Check Exception (486+)
//Machine Check Exception (Pentium/586+)
