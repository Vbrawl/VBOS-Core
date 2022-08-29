#include "isr.h"
#include "../extras/macro_parse.h"


// Include "idt.h" from <TARGET_ARCH> directory
#include TOSTRING(EXPAND(TARGET_ARCH)/idt.h)

// Include "pic.h" from <TARGET_ARCH> directory
#include TOSTRING(EXPAND(TARGET_ARCH)/pic.h)


#include "../drivers/screen.h"
//#include "../drivers/keyboard.h"
#include "../extras/types.h"
#include "../extras/string_funcs.h"


extern void* backendisr_Array[];
isr_handle_holder_t isr_handles;

void init_idt() {

	isr_handles = isr_holder_init();

	for(int i = 0; i < 256; i++) {
		idt_set_entry(i, (uintptr_t)backendisr_Array[i]);
	}

	pic_reinit(MASTER_PIC_OFFSET, SLAVE_PIC_OFFSET);
	pic_set_mask(0xFF, 0xFF);

	enable_idt();
	__asm__("sti"); // Enable interrupts
}


void main_isr_handler(unsigned char idt_code) {

	char hex_code[10];
	int_to_hexstring(idt_code, hex_code, 10);
	screen_write(&VGA_SCREEN, "Interrupt: ", false);
	screen_write(&VGA_SCREEN, hex_code, false);
	screen_write(&VGA_SCREEN, "\n\r", false);


	for(int i = 0; i < ISR_SIGNAL_CATEGORY_SIZE; i++) {
		isr_handler_ptr_t* ptr = isr_handles.isr_signals[idt_code].ptrs[i];
		if(ptr != 0) {
			ptr(idt_code);
		}
	}
}




isr_handle_holder_t isr_holder_init() {

	isr_handle_holder_t _this;

	for(int i = 0; i < 256; i++) {
		for(int o = 0; o < ISR_SIGNAL_CATEGORY_SIZE; o++) {
			_this.isr_signals[i].ptrs[o] = 0;
		}
	}

	return _this;
}


void isr_holder_register_handler(isr_handle_holder_t* _this, isr_handler_ptr_t* ptr, size_t category, size_t position) {
	_this->isr_signals[category].ptrs[position] = ptr;
}


void isr_holder_install(isr_handle_holder_t* _this) {
	for(int i = 0; i < 256; i++) {
		for(int o = 0; o < ISR_SIGNAL_CATEGORY_SIZE; o++) {
			isr_handles.isr_signals[i].ptrs[o] = _this->isr_signals[i].ptrs[o];
		}
	}
}

