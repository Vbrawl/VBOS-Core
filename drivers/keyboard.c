#include "keyboard.h"
#include "ports.h"

#define ESCAPE			0x1
#define NUMBER_1		0x2
#define NUMBER_2		0x3
#define NUMBER_3		0x4
#define NUMBER_4		0x5
#define NUMBER_5		0x6
#define NUMBER_6		0x7
#define NUMBER_7		0x8
#define NUMBER_8		0x9
#define NUMBER_9		0xA
#define NUMBER_0		0xB
#define DASH			0xC
#define PLUS			0xD
#define BACKSPACE		0xE
#define TAB			0xF


#define LETTER_Q		0x10
#define LETTER_W		0x11
#define LETTER_E		0x12
#define LETTER_R		0x13
#define LETTER_T		0x14
#define LETTER_Y		0x15
#define LETTER_U		0x16
#define LETTER_I		0x17
#define LETTER_O		0x18
#define LETTER_P		0x19
#define SQUARE_BRACKET_OPEN	0x1A
#define SQUARE_BRACKET_CLOSE	0x1B
#define ENTER			0x1C
#define CONTROL			0x1D
#define LETTER_A		0x1E
#define LETTER_S		0x1F


// Continue after this
#define LETTER_D		0x20
#define LETTER_F		0x21
#define LETTER_G		0x22
#define LETTER_H		0x23
#define LETTER_J		0x24
#define LETTER_K		0x25
#define LETTER_L		0x26
#define COLON			0x27
#define QUOTE			0x28
#define TILDE			0x29
#define LEFT_SHIFT		0x2A
#define BACKSLASH		0x2B
#define LETTER_Z		0x2C
#define LETTER_X		0x2D
#define LETTER_C		0x2E
#define LETTER_V		0x2F



#define LETTER_B		0x30
#define LETTER_N		0x31
#define LETTER_M		0x32
#define DOT			0x33
#define COMMA			0x34
#define SLASH			0x35
#define RIGHT_SHIFT		0x36
#define NUMPAD_STAR		0x37
#define LEFT_ALT		0x38
#define SPACE			0x39





#warning *** TODO: Remove "vga.h" from "drivers/keyboard.c"
#include "vga.h"
#include "../extras/string_funcs.h"
void keyboard_notify() {
	unsigned char key = port_bin(KEYBOARD_DATA_IN);

	if(key >= 0x80) {
		key -= 0x80;
	}

	char t = 

	vga_print_string(t, RED_ON_WHITE);
	vga_print_char('\n', RED_ON_WHITE);
	vga_print_char('\r', RED_ON_WHITE);
}


char keyboard_get_key_from_keycode(unsigned char keycode, bool shift) {

	for(int i = 0; i < KEYBOARD_KEYS; i++) {
		if(keyboard_keys[i].keycode == keycode) {

			if(shift) {
				return keyboard_keys[i].keycode + keyboard_keys[i].shift;
			}
			return keycode;
		}
	}

}




void initialize_keyboard() {

	/*********
	* Escape *
	*********/
	int i = 0;
	keyboard_keys[i].keycode		= 0x1;
	keyboard_keys[i].special_key	= true;


	/************
	* Number: 1 *
	************/
	i++;
	keyboard_keys[i].keycode		= 0x2;
	keyboard_keys[i].normal			= '1';
	keyboard_keys[i].shift			= -16;


	/************
	* Number: 2 *
	************/
	i++;
	keyboard_keys[i].keycode		= 0x3;
	keyboard_keys[i].normal			= '2';
	keyboard_keys[i].shift			= 14;


	/************
	* Number: 3 *
	************/
	i++;
	keyboard_keys[i].keycode		= 0x4;
	keyboard_keys[i].normal			= '3';
	keyboard_keys[i].shift			= -16;


	/************
	* Number: 4 *
	************/
	i++;
	keyboard_keys[i].keycode		= 0x5;
	keyboard_keys[i].normal			= '4';
	keyboard_keys[i].shift			= -16;


	/************
	* Number: 5 *
	************/
	i++;
	keyboard_keys[i].keycode		= 0x6;
	keyboard_keys[i].normal			= '5';
	keyboard_keys[i].shift			= -16;


	/************
	* Number: 6 *
	************/
	i++;
	keyboard_keys[i].keycode		= 0x7;
	keyboard_keys[i].normal			= '6';
	keyboard_keys[i].shift			= 40;


	/************
	* Number: 7 *
	************/
	i++;
	keyboard_keys[i].keycode		= 0x8;
	keyboard_keys[i].normal			= '7';
	keyboard_keys[i].shift			= -17;


	/************
	* Number: 8 *
	************/
	i++;
	keyboard_keys[i].keycode		= 0x9;
	keyboard_keys[i].normal			= '8';
	keyboard_keys[i].shift			= -14;


	/************
	* Number: 9 *
	************/
	i++;
	keyboard_keys[i].keycode		= 0xA;
	keyboard_keys[i].normal			= '9';
	keyboard_keys[i].shift			= -17;


	/************
	* Number: 0 *
	************/
	i++;
	keyboard_keys[i].keycode		= 0xB;
	keyboard_keys[i].normal			= '0';
	keyboard_keys[i].shift			= -7;




	/*******
	* Dash *
	*******/
	i++;
	keyboard_keys[i].keycode		= 0xC;
	keyboard_keys[i].normal			= '-';
	keyboard_keys[i].shift			= 50;


	/*******
	* Plus *
	*******/
	i++;
	keyboard_keys[i].keycode		= 0xD;
	keyboard_keys[i].normal			= '=';
	keyboard_keys[i].shift			= -18;


	/************
	* Backspace *
	************/
	i++;
	keyboard_keys[i].keycode		= 0xE;
	keyboard_keys[i].special_key	= true;


	/******
	* Tab *
	******/
	i++;
	keyboard_keys[i].keycode		= 0xF;
	keyboard_keys[i].normal			= '\t';
	keyboard_keys[i].special_key	= true;

	/************
	* Letter: Q *
	************/
	i++;
	keyboard_keys[i].keycode		= 0x10;
	keyboard_keys[i].normal			= 'q';
	keyboard_keys[i].shift			= -32;


	/************
	* Letter: W *
	************/
	i++;
	keyboard_keys[i].keycode		= 0x11;
	keyboard_keys[i].normal			= 'w';
	keyboard_keys[i].shift			= -32;


	/************
	* Letter: E *
	************/
	i++;
	keyboard_keys[i].keycode		= 0x12;
	keyboard_keys[i].normal			= 'e';
	keyboard_keys[i].shift			= -32;


	/************
	* Letter: R *
	************/
	i++;
	keyboard_keys[i].keycode		= 0x13;
	keyboard_keys[i].normal			= 'r';
	keyboard_keys[i].shift			= -32;


	/************
	* Letter: T *
	************/
	i++;
	keyboard_keys[i].keycode		= 0x14;
	keyboard_keys[i].normal			= 't';
	keyboard_keys[i].shift			= -32;


	/************
	* Letter: Y *
	************/
	i++;
	keyboard_keys[i].keycode		= 0x15;
	keyboard_keys[i].normal			= 'y';
	keyboard_keys[i].shift			= -32;


	/************
	* Letter: U *
	************/
	i++;
	keyboard_keys[i].keycode		= 0x16;
	keyboard_keys[i].normal			= 'u';
	keyboard_keys[i].shift			= -32;

	/************
	* Letter: I *
	************/
	i++;
	keyboard_keys[i].keycode		= 0x17;
	keyboard_keys[i].normal			= 'i';
	keyboard_keys[i].shift			= -32;

	/************
	* Letter: O *
	************/
	i++;
	keyboard_keys[i].keycode		= 0x18;
	keyboard_keys[i].normal			= 'o';
	keyboard_keys[i].shift			= -32;


	/************
	* Letter: P *
	************/
	i++;
	keyboard_keys[i].keycode		= 0x19;
	keyboard_keys[i].normal			= 'p';
	keyboard_keys[i].shift			= -32;


	/*************
	* Special: [ *
	*************/
	i++;
	keyboard_keys[i].keycode		= 0x1A;
	keyboard_keys[i].normal			= '[';
	keyboard_keys[i].shift			= 32;

	/*************
	* Special: ] *
	*************/
	i++;
	keyboard_keys[i].keycode		= 0x1B;
	keyboard_keys[i].normal			= ']';
	keyboard_keys[i].shift			= 32;


	/*****************
	* Special: Enter *
	*****************/
	i++;
	keyboard_keys[i].keycode		= 0x1C;
	keyboard_keys[i].normal			= '\r';
	keyboard_keys[i].special_key	= true;


	/*******************
	* Special: Control *
	*******************/
	i++;
	keyboard_keys[i].keycode		= 0x1D;
	keyboard_keys[i].special_key	= true;


	/************
	* Letter: A *
	************/
	i++;
	keyboard_keys[i].keycode		= 0x1E;
	keyboard_keys[i].normal			= 'a';
	keyboard_keys[i].shift			= -32;


	/************
	* Letter: E *
	************/
	i++;
	keyboard_keys[i].keycode		= 0x1F;
	keyboard_keys[i].normal			= 'e';
	keyboard_keys[i].shift			= -32;


	// Continue from LETTER_D and below
}
