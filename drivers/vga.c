#include "vga.h"
#include "ports.h"


int VGA_MODE = 0;



/* General */
short vga_is_mode(int query_mode) {
	return VGA_MODE == query_mode;
}



/* Text Mode */


// Position
int vga_calc_offset(int x, int y) {
	return ((y * MAX_COL) + x) * 2;
}

int vga_calc_x(int offset) {
	return (offset / 2) % MAX_COL;
}

int vga_calc_y(int offset) {
	return (offset / 2) / MAX_COL;
}



// Cursor
int vga_get_cursor() {
	port_bout(REG_VGA_CTRL, 14);
	int pos = port_bin(REG_VGA_DATA);
	pos = (pos << 8);

	port_bout(REG_VGA_CTRL, 15);
	pos += port_bin(REG_VGA_DATA);

	return pos*2; // offset is *2 (character and attribute on each cell)
}

void vga_set_cursor(int offset) {
	offset = offset / 2;

	port_bout(REG_VGA_CTRL, 14);
	port_bout(REG_VGA_DATA, offset >> 8);
	port_bout(REG_VGA_CTRL, 15);
	port_bout(REG_VGA_DATA, offset & 0xff);
}




// Printing
int vga_print_char_at(int offset, const char character, const char attribute) {

	char* vga = VGA_ADDRESS;
	if(offset > MAX_OFFSET) {
		vga[MAX_OFFSET-2] = 'E';
		vga[MAX_OFFSET-1] = RED_ON_WHITE;

		offset = MAX_OFFSET;
	}
	else {
		vga[offset] = character;
		vga[offset+1] = attribute;
		offset += 2;
	}

	return offset;
}

int vga_print_string_at(int offset, const char* text, const char attribute) {

	char* vga = VGA_ADDRESS;
	int i = 0;

	while(text[i] != 0) {
		if(offset >= MAX_OFFSET) {
			vga[MAX_OFFSET-2] = 'E';
			vga[MAX_OFFSET-1] = RED_ON_WHITE;
			offset = MAX_OFFSET;
		}
		else {
			vga[offset] = text[i];
			vga[offset+1] = attribute;
			offset += 2;
		}

		i++;
	}

	if(i == 0) {
		vga[MAX_OFFSET-2] = 'E';
		vga[MAX_OFFSET-1] = RED_ON_WHITE;
	}
	return offset;
}


int vga_print_char(const char character, const char attribute) {
	int offset = vga_get_cursor();
	offset = vga_print_char_at(offset, character, attribute);

	vga_set_cursor(offset);
	return offset;
}


int vga_print_string(const char* text, const char attribute) {
	int offset = vga_get_cursor();
	offset = vga_print_string_at(offset, text, attribute);

	vga_set_cursor(offset);
	return offset;
}




// Clear screen
void vga_clear_screen() {
	char* vga = VGA_ADDRESS;

	for(int i = 0; i < MAX_OFFSET; i++) {
		vga[i] = 0;
	}

	vga_set_cursor(0);
}
