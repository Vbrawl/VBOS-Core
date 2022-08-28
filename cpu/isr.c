#include "isr.h"
#include "../extras/macro_parse.h"


// Include "idt.h" from <TARGET_ARCH> directory
#include TOSTRING(EXPAND(TARGET_ARCH)/idt.h)

// Include "pic.h" from <TARGET_ARCH> directory
#include TOSTRING(EXPAND(TARGET_ARCH)/pic.h)


#include "../drivers/screen.h"
//#include "../drivers/keyboard.h"
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
	screen_write(&VGA_SCREEN, "ERROR: ISR Null Handler\n\r", true);

	#warning *** NULL handler is configured to freeze everything, You may want to change that ***
	//__asm__ volatile("hlt");
}


/*******************
* Division By Zero *
*******************/
void isr_0() {
	screen_write(&VGA_SCREEN, "ERROR: Division By Zero\n\r", true);

	#warning *** You may want to change this action (DivBy0) ***
//	__asm__ volatile("cli; hlt");
}


/********
* Debug *
********/
void isr_1() {
	screen_write(&VGA_SCREEN, "ERROR: Debug\n\r", true);

	#warning *** Add an action for Debug (Debug) ***
}

/***************
* Non-Maskable *
****************/
void isr_2() {
	screen_write(&VGA_SCREEN, "ERROR: Non-Maskable\n\r", true);

	#warning *** Add an action for Non-Maskable ***
}

/*************
* Breakpoint *
*************/
void isr_3() {
	screen_write(&VGA_SCREEN, "ERROR: Breakpoint\n\r", true);

	#warning *** Add an action for Breakpoint ***
}

/*************************
* Into Detected Overflow *
*************************/
void isr_4() {
	screen_write(&VGA_SCREEN, "ERROR: Into Detected Overflow\n\r", true);

	#warning *** Add an action for Into Detected Overflow ***
}

/****************
* Out of Bounds *
****************/
void isr_5() {
	screen_write(&VGA_SCREEN, "ERROR: Out of Bounds\n\r", true);

	#warning *** Add an action for Out of Bounds ***
}


/*****************
* Invalid OpCode *
*****************/
void isr_6() {
	screen_write(&VGA_SCREEN, "ERROR: Invalid OpCode\n\r", true);

	#warning *** Add an action for Invalid OpCode ***
}


/*****************
* No Coprocessor *
*****************/
void isr_7() {
	screen_write(&VGA_SCREEN, "ERROR: No Coprocessor\n\r", true);

	#warning *** Add an action for No Coprocessor ***
}

/***************
* Double Fault *
***************/
void isr_8() {
	screen_write(&VGA_SCREEN, "ERROR: Double Fault\n\r", true);

	#warning *** Add an action for Double Fault ***
}

/******************************
* Coprocessor Segment Overrun *
******************************/
void isr_9() {
	screen_write(&VGA_SCREEN, "ERROR: Coprocessor Segment Overrun\n\r", true);

	#warning *** Add an action for Coprocessor Segment Overrun ***
}


/**********
* Bad TSS *
**********/
void isr_10() {
	screen_write(&VGA_SCREEN, "ERROR: Bad TSS\n\r", true);

	#warning *** Add an action for Bad TSS ***
}

/**********************
* Segment Not Present *
**********************/
void isr_11() {
	screen_write(&VGA_SCREEN, "ERROR: Segment Not Present\n\r", true);

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
	screen_write(&VGA_SCREEN, "ERROR: Stack Fault\n\r", true);

	#warning *** Add an action for Stack Fault ***
}

/***************************
* General Protection Fault *
***************************/
void isr_13() {
	screen_write(&VGA_SCREEN, "ERROR: General Protection Fault\n\r", true);

	#warning *** General Protection Fault handler is configured to freeze the machine. ***
	__asm__ volatile("hlt");
}

/*************
* Page Fault *
*************/
void isr_14() {
	screen_write(&VGA_SCREEN, "ERROR: Page Fault\n\r", true);

	#warning *** Add an action for Page Fault ***
}

/****************
* Reserved (15) *
****************/
void isr_15() {
	screen_write(&VGA_SCREEN, "ERROR: Reserved (15)\n\r", true);

	#warning *** No action for Reserved (15) ***
}

/*****************
* Floating Point *
*****************/
void isr_16() {
	screen_write(&VGA_SCREEN, "ERROR: Floating Point\n\r", true);

	#warning *** Add an action for Floating Point ***
}
/******************
* Alignment Check *
******************/
void isr_17() {
	screen_write(&VGA_SCREEN, "ERROR: Alignment Check\n\r", true);

	#warning *** Add an action for Alignment Check ***
}

/****************
* Machine Check *
****************/
void isr_18() {
	screen_write(&VGA_SCREEN, "ERROR: Machine Check\n\r", true);

	#warning *** Add an action for Machine Check ***
}

/****************
* Reserved (19) *
****************/
void isr_19() {
	screen_write(&VGA_SCREEN, "ERROR: Reserved (19)\n\r", true);

	#warning *** No action for Reserved (19) ***
}

/****************
* Reserved (20) *
****************/
void isr_20() {
	screen_write(&VGA_SCREEN, "ERROR: Reserved (20)\n\r", true);

	#warning *** No action for Reserved (20) ***
}

/****************
* Reserved (21) *
****************/
void isr_21() {
	screen_write(&VGA_SCREEN, "ERROR: Reserved (21)\n\r", true);

	#warning *** No action for Reserved (21) ***
}

/****************
* Reserved (22) *
****************/
void isr_22() {
	screen_write(&VGA_SCREEN, "ERROR: Reserved (22)\n\r", true);

	#warning *** No action for Reserved (22) ***
}

/****************
* Reserved (23) *
****************/
void isr_23() {
	screen_write(&VGA_SCREEN, "ERROR: Reserved (23)\n\r", true);

	#warning *** No action for Reserved (23) ***
}

/****************
* Reserved (24) *
****************/
void isr_24() {
	screen_write(&VGA_SCREEN, "ERROR: Reserved (24)\n\r", true);

	#warning *** No action for Reserved (24) ***
}

/****************
* Reserved (25) *
****************/
void isr_25() {
	screen_write(&VGA_SCREEN, "ERROR: Reserved (25)\n\r", true);

	#warning *** No action for Reserved (25) ***
}

/****************
* Reserved (26) *
****************/
void isr_26() {
	screen_write(&VGA_SCREEN, "ERROR: Reserved (26)\n\r", true);

	#warning *** No action for Reserved (26) ***
}

/****************
* Reserved (27) *
****************/
void isr_27() {
	screen_write(&VGA_SCREEN, "ERROR: Reserved (27)\n\r", true);

	#warning *** No action for Reserved (27) ***
}

/****************
* Reserved (28) *
****************/
void isr_28() {
	screen_write(&VGA_SCREEN, "ERROR: Reserved (28)\n\r", true);

	#warning *** No action for Reserved (28) ***
}

/****************
* Reserved (29) *
****************/
void isr_29() {
	screen_write(&VGA_SCREEN, "ERROR: Reserved (29)\n\r", true);

	#warning *** No action for Reserved (29) ***
}

/****************
* Reserved (30) *
****************/
void isr_30() {
	screen_write(&VGA_SCREEN, "ERROR: Reserved (30)\n\r", true);

	#warning *** No action for Reserved (30) ***
}

/****************
* Reserved (31) *
****************/
void isr_31() {
	screen_write(&VGA_SCREEN, "ERROR: Reserved (31)\n\r", true);

	#warning *** No action for Reserved (31) ***
}





/*************
* Extra ISRs *
*************/


/***********
* Free ISR *
***********/
void isr_32() {
	screen_write(&VGA_SCREEN, "ERROR: Free ISR (32)\n\r", false);

	#warning *** No action for free ISR (32) ***
}

/***********
* Keyboard *
***********/
void isr_33() {
        screen_write(&VGA_SCREEN, "ERROR: Keyboard Interrupt (33)\n\r", false);

	//keyboard_notify();

        #warning *** No action for free ISR (33) ***

	pic_accept(false);

	screen_write(&VGA_SCREEN, "after\n\r", false);
}

/***********
* Free ISR *
***********/
void isr_34() {
        screen_write(&VGA_SCREEN, "ERROR: Free ISR (34)\n\r", false);

        #warning *** No action for free ISR (34) ***
}
