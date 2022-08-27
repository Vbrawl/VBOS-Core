#include "isr.h"
#include "../extras/macro_parse.h"


// Include "idt.h" from <TARGET_ARCH> directory
#include TOSTRING(EXPAND(TARGET_ARCH)/idt.h)

// Include "pic.h" from <TARGET_ARCH> directory
#include TOSTRING(EXPAND(TARGET_ARCH)/pic.h)


#include "../drivers/vga.h"
#include "../drivers/keyboard.h"
#include "../extras/types.h"


extern void* backendisr_Array[];

void init_idt() {

	for(int i = 0; i < 256; i++) {
		idt_set_entry(i, (uintptr_t)backendisr_Array[i]);
	}

	pic_reinit(MASTER_PIC_OFFSET, SLAVE_PIC_OFFSET);
	pic_set_mask(0xFF, 0xFF);

	enable_idt();
	__asm__("sti"); // Enable interrupts
}





/**********************
* Common Null Handler *
**********************/
void isr_null(unsigned char idt_code) {
	vga_print_string("ERROR: ISR Null Handler\n\r", RED_ON_WHITE);

	#warning *** NULL handler is configured to freeze everything, You may want to change that ***
	//__asm__ volatile("hlt");
}


/*******************
* Division By Zero *
*******************/
void isr_0() {
	vga_print_string("ERROR: Division By Zero\n\r", RED_ON_WHITE);

	#warning *** You may want to change this action (DivBy0) ***
//	__asm__ volatile("cli; hlt");
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

	#warning *** General Protection Fault handler is configured to freeze the machine. ***
	__asm__ volatile("hlt");
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





/*************
* Extra ISRs *
*************/


/***********
* Free ISR *
***********/
void isr_32() {
	vga_print_string("ERROR: Free ISR (32)\n\r", WHITE_ON_BLACK);

	#warning *** No action for free ISR (32) ***
}

/***********
* Keyboard *
***********/
void isr_33() {
        vga_print_string("ERROR: Keyboard Interrupt (33)\n\r", WHITE_ON_BLACK);

	keyboard_notify();

        #warning *** No action for free ISR (33) ***

	pic_accept(false);

	vga_print_string("after\n\r", WHITE_ON_BLACK);
}

/***********
* Free ISR *
***********/
void isr_34() {
        vga_print_string("ERROR: Free ISR (34)\n\r", WHITE_ON_BLACK);

        #warning *** No action for free ISR (34) ***
}
