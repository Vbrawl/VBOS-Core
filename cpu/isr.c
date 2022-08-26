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
idt_set_entry(6, (uintptr_t)backendisr6);
idt_set_entry(7, (uintptr_t)backendisr7);
idt_set_entry(8, (uintptr_t)backendisr8);
idt_set_entry(9, (uintptr_t)backendisr9);
idt_set_entry(10, (uintptr_t)backendisr10);
idt_set_entry(11, (uintptr_t)backendisr11);
idt_set_entry(12, (uintptr_t)backendisr12);
idt_set_entry(13, (uintptr_t)backendisr13);
idt_set_entry(14, (uintptr_t)backendisr14);
idt_set_entry(15, (uintptr_t)backendisr15);
idt_set_entry(16, (uintptr_t)backendisr16);
idt_set_entry(17, (uintptr_t)backendisr17);
idt_set_entry(18, (uintptr_t)backendisr18);
idt_set_entry(19, (uintptr_t)backendisr19);
idt_set_entry(20, (uintptr_t)backendisr20);
idt_set_entry(21, (uintptr_t)backendisr21);
idt_set_entry(22, (uintptr_t)backendisr22);
idt_set_entry(23, (uintptr_t)backendisr23);
idt_set_entry(24, (uintptr_t)backendisr24);
idt_set_entry(25, (uintptr_t)backendisr25);
idt_set_entry(26, (uintptr_t)backendisr26);
idt_set_entry(27, (uintptr_t)backendisr27);
idt_set_entry(28, (uintptr_t)backendisr28);
idt_set_entry(29, (uintptr_t)backendisr29);
idt_set_entry(30, (uintptr_t)backendisr30);
idt_set_entry(31, (uintptr_t)backendisr31);

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


/*****************
* Invalid OpCode *
*****************/
void isr_6() {
	vga_print_string("ERROR: Invalid OpCode\n\r", RED_ON_WHITE);

	#warning *** Add an action for Invalid OpCode ***
}


/*****************
* No Coprocessor *
*****************/
void isr_7() {
	vga_print_string("ERROR: No Coprocessor\n\r", RED_ON_WHITE);

	#warning *** Add an action for No Coprocessor ***
}

/***************
* Double Fault *
***************/
void isr_8() {
	vga_print_string("ERROR: Double Fault\n\r", RED_ON_WHITE);

	#warning *** Add an action for Double Fault ***
}

/******************************
* Coprocessor Segment Overrun *
******************************/
void isr_9() {
	vga_print_string("ERROR: Coprocessor Segment Overrun\n\r", RED_ON_WHITE);

	#warning *** Add an action for Coprocessor Segment Overrun ***
}


/**********
* Bad TSS *
**********/
void isr_10() {
	vga_print_string("ERROR: Bad TSS\n\r", RED_ON_WHITE);

	#warning *** Add an action for Bad TSS ***
}

/**********************
* Segment Not Present *
**********************/
void isr_11() {
	vga_print_string("ERROR: Segment Not Present\n\r", RED_ON_WHITE);

	#warning *** Add an action for Segment Not Present ***
}

/**************
* Stack Fault *
**************/
void isr_12() {
	/********************************************
	* Possible Solution:                        *
	*                                           *
	* Go to a new location and:                 *
	*                                           *
	* > safe_memcpy(old_stack, new_location)    *
	* then set the stack bs to new_location     *
	* and stack sp to new_location - stack_size *
	********************************************/
	vga_print_string("ERROR: Stack Fault\n\r", RED_ON_WHITE);

	#warning *** Add an action for Stack Fault ***
}

/***************************
* General Protection Fault *
***************************/
void isr_13() {
	vga_print_string("ERROR: General Protection Fault\n\r", RED_ON_WHITE);

	#warning *** Add an action for General Protection Fault ***
}

/*************
* Page Fault *
*************/
void isr_14() {
	vga_print_string("ERROR: Page Fault\n\r", RED_ON_WHITE);

	#warning *** Add an action for Page Fault ***
}

/****************
* Reserved (15) *
****************/
void isr_15() {
	vga_print_string("ERROR: Reserved (15)\n\r", RED_ON_WHITE);

	#warning *** No action for Reserved (15) ***
}

/*****************
* Floating Point *
*****************/
void isr_16() {
	vga_print_string("ERROR: Floating Point\n\r", RED_ON_WHITE);

	#warning *** Add an action for Floating Point ***
}
/******************
* Alignment Check *
******************/
void isr_17() {
	vga_print_string("ERROR: Alignment Check\n\r", RED_ON_WHITE);

	#warning *** Add an action for Alignment Check ***
}

/****************
* Machine Check *
****************/
void isr_18() {
	vga_print_string("ERROR: Machine Check\n\r", RED_ON_WHITE);

	#warning *** Add an action for Machine Check ***
}

/****************
* Reserved (19) *
****************/
void isr_19() {
	vga_print_string("ERROR: Reserved (19)\n\r", RED_ON_WHITE);

	#warning *** No action for Reserved (19) ***
}

/****************
* Reserved (20) *
****************/
void isr_20() {
	vga_print_string("ERROR: Reserved (20)\n\r", RED_ON_WHITE);

	#warning *** No action for Reserved (20) ***
}

/****************
* Reserved (21) *
****************/
void isr_21() {
	vga_print_string("ERROR: Reserved (21)\n\r", RED_ON_WHITE);

	#warning *** No action for Reserved (21) ***
}

/****************
* Reserved (22) *
****************/
void isr_22() {
	vga_print_string("ERROR: Reserved (22)\n\r", RED_ON_WHITE);

	#warning *** No action for Reserved (22) ***
}

/****************
* Reserved (23) *
****************/
void isr_23() {
	vga_print_string("ERROR: Reserved (23)\n\r", RED_ON_WHITE);

	#warning *** No action for Reserved (23) ***
}

/****************
* Reserved (24) *
****************/
void isr_24() {
	vga_print_string("ERROR: Reserved (24)\n\r", RED_ON_WHITE);

	#warning *** No action for Reserved (24) ***
}

/****************
* Reserved (25) *
****************/
void isr_25() {
	vga_print_string("ERROR: Reserved (25)\n\r", RED_ON_WHITE);

	#warning *** No action for Reserved (25) ***
}

/****************
* Reserved (26) *
****************/
void isr_26() {
	vga_print_string("ERROR: Reserved (26)\n\r", RED_ON_WHITE);

	#warning *** No action for Reserved (26) ***
}

/****************
* Reserved (27) *
****************/
void isr_27() {
	vga_print_string("ERROR: Reserved (27)\n\r", RED_ON_WHITE);

	#warning *** No action for Reserved (27) ***
}

/****************
* Reserved (28) *
****************/
void isr_28() {
	vga_print_string("ERROR: Reserved (28)\n\r", RED_ON_WHITE);

	#warning *** No action for Reserved (28) ***
}

/****************
* Reserved (29) *
****************/
void isr_29() {
	vga_print_string("ERROR: Reserved (29)\n\r", RED_ON_WHITE);

	#warning *** No action for Reserved (29) ***
}

/****************
* Reserved (30) *
****************/
void isr_30() {
	vga_print_string("ERROR: Reserved (30)\n\r", RED_ON_WHITE);

	#warning *** No action for Reserved (30) ***
}

/****************
* Reserved (31) *
****************/
void isr_31() {
	vga_print_string("ERROR: Reserved (31)\n\r", RED_ON_WHITE);

	#warning *** No action for Reserved (31) ***
}
