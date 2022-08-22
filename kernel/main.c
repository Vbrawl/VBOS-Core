#include "../drivers/vga.h"

int hide_main() {}



void main() {
	//char* vga = (char*)0xb8000;
	//char c = text[0];
	//vga[0] = c;
	//vga[1] = WHITE_ON_BLACK;
	char* test = 0xfff00;
	test[0] = 'H';
	test[1] = 'e';
	test[2] = 'l';
	test[3] = 'l';
	test[4] = 'o';

	vga_print_string(test, WHITE_ON_BLACK);

	vga_print_char(*test, WHITE_ON_BLACK);

	vga_print_char('H', WHITE_ON_BLACK);
}
