#include "keyboard.h"
#include "../cpu/isr.h"
#include "ports.h"


void init_all_keyboards() {
	for(int i = 0; i < TOTAL_KEYBOARDS; i++) {
		all_keyboards[i] = keyboard_init();
	}
}


keyboard_t keyboard_init() {

	keyboard_t _this;

	for(int i = 0; i < KEYBOARD_MAX_HANDLERS; i++) {
		_this.keyboard_handlers[i] = 0;
	}

	_this.flags = 0;


	return _this;
}






void keyboard_isr_handler(unsigned char errorcode) {

	unsigned char keycode = port_bin(0x60); // Read key from 0x60
	bool pressed = keycode > 0x80;
	if(pressed) keycode -= 0x80;

	switch(keycode) {
	default:
		for(int i = 0; i < TOTAL_KEYBOARDS; i++) {
			for(int o = 0; o < KEYBOARD_MAX_HANDLERS; o++) {
				if(all_keyboards[i].keyboard_handlers[o] != 0) {
					all_keyboards[i].keyboard_handlers[o](i, keycode, pressed);
				}
			}
		}
		break;
	}

}
