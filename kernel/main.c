#include "../drivers/vga.h"

int hide_main() {}



void main() {

	vga_clear_screen();

	vga_print_string("Hello World!", WHITE_ON_BLACK);
}
