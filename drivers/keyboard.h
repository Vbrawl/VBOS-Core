#ifndef KEYBOARD_H
#define KEYBOARD_H


#define KEYBOARD_DATA_IN	0x60
#define KEY_DOWN_PADDING	0x0
#define KEY_UP_PADDING		0x80


typedef struct {

	unsigned char keycode;			// Keycode for key press
	char normal;				// If letter should be lowercase
	char shift;				// If letter should be uppercase
	char control;				// An extra flag...
	char alt;				// An extra flag...
	bool special_key;			// If it's a special key, do special parsing...


} Key;


#define KEYBOARD_KEYS 57
extern Key keyboard_keys[KEYBOARD_KEYS];	// An array ending with a null Key.


void keyboard_notify();
/*
void keyboard_down();
void keyboard_up();
void keyboard_press(unsigned char keycode);
void keyboard_unpress(unsigned char keycode);
void keyboard_read();
*/



#endif
