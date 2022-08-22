#include "../drivers/vga.h"

int hide_main() {}



void main() {
	//char* vga = (char*)0xb8000;
	//char c = text[0];
	//vga[0] = c;
	//vga[1] = WHITE_ON_BLACK;
	char* test = "Hello World!";

	vga_print_string("Hello World!", WHITE_ON_BLACK);
}
