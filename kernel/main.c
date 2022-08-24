#include "../drivers/vga.h"
#include "../extras/memutils.h"

#ifdef __32BIT__
#include "../cpu/__32BIT__/idt.h"
#endif



int hide_main() {}



void main() {

	vga_clear_screen();

	for(int i = 0; i < MAX_ROW; i++) {
		vga_print_string("Hello World!\n\r", WHITE_ON_BLACK);
	}
	vga_print_string("AHA\n\r", WHITE_ON_BLACK);
}
