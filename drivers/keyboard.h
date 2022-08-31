#ifndef KEYBOARD_H
#define KEYBOARD_H


#include "../extras/types.h"

//            keyboard index, keycode, keyup?
typedef void(keyboard_handler_ptr_t)(int, unsigned char, bool);

#define KEYBOARD_MAX_HANDLERS 256
typedef struct {
	keyboard_handler_ptr_t* keyboard_handlers[KEYBOARD_MAX_HANDLERS];

	// 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0
	// 0 == ctrl
	// 1 == alt
	// 2 == shift
	// 3 == caps
	// 4 == super
	// 5 == left-ctrl
	// 6 == left-alt
	// 7 == left-shift
	// 8 == right-click button
	// 9 == Scroll-Lock
	// 10 == Num-Lock
	//
	// 11 == UNDEFINED
	// 12 == UNDEFINED
	// 13 == UNDEFINED
	// 14 == UNDEFINED
	// 15 == UNDEFINED
	uint16_t flags;

} keyboard_t;


#define TOTAL_KEYBOARDS 5
static keyboard_t all_keyboards[TOTAL_KEYBOARDS];

void init_all_keyboards();
keyboard_t keyboard_init();
void keyboard_isr_handler(unsigned char errorcode);

#endif
