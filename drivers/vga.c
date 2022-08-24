#include "vga.h"
#include "ports.h"
#include "../extras/memutils.h"




/*******************
* Hidden Functions *
*******************/
// Clear a the space between 2 offsets
void _vga_clear_range(size_t start_offset, size_t end_offset);












// May be unusable
int VGA_MODE = 0;



/* General */
// May be unusable
bool vga_is_mode(int query_mode) {
	return VGA_MODE == query_mode;
}



/* Text Mode */


// Position
int vga_calc_offset(int x, int y) {
	return ((y * MAX_COL) + x) * 2;
}

int vga_calc_col(int offset) {
	return (offset / 2) % MAX_COL;
}

int vga_calc_row(int offset) {
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
int vga_print_char_at(int offset, const char character, const char attribute, bool scroll_if_needed) {

	bool special_char = false;
	char* vga = VGA_ADDRESS;

	// Parse special characters
	switch(character) {
	case '\n': // New Line
		special_char = true;
		offset += MAX_COL * 2; // == row + 1
		break;

	case '\r': // Carriage Return
		special_char = true;
		int col = vga_calc_col(offset);
		offset -= col * 2; // == vga_calc_offset(0, row);
		break;
	}


	if(scroll_if_needed && offset > MAX_OFFSET) {
		// Update offset
		int col = vga_calc_col(offset);
		int row = vga_calc_row(offset);


		// row - MAX_ROW == extra rows
		offset = MAX_OFFSET - vga_calc_offset(col, row - MAX_ROW);

		// Scroll everything up by 1 row
		safe_memcpy(
			VGA_ADDRESS, VGA_ADDRESS + MAX_COL*2, offset);

		// Clear the last row (that wasn't copied/moved)
		_vga_clear_range(offset, MAX_OFFSET);

	}

	if (special_char) {
		vga_set_cursor(vga_calc_offset(0, MAX_ROW-2));
	}
	else {
		// Print character if possible
		if(offset < MAX_OFFSET) {
			vga[offset] = character;
			vga[offset+1] = attribute;
			offset += 2;
		}
		else {
			vga[MAX_OFFSET-2] = 'E';
			vga[MAX_OFFSET-1] = RED_ON_WHITE;

			offset = MAX_OFFSET;
		}
	}

	return offset;
}

int vga_print_string_at(int offset, const char* text, const char attribute, bool scroll_if_needed) {
	int i = 0;

	while(text[i] != 0) {
		offset = vga_print_char_at(offset, text[i], attribute, scroll_if_needed);
		i++;
	}

	return offset;
}


int vga_print_char(const char character, const char attribute) {
	int offset = vga_get_cursor();
	offset = vga_print_char_at(offset, character, attribute, /*Allow Scrolling*/true);

	vga_set_cursor(offset);
	return offset;
}


int vga_print_string(const char* text, const char attribute) {
	int offset = vga_get_cursor();
	offset = vga_print_string_at(offset, text, attribute, /*Allow Scrolling*/true);

	vga_set_cursor(offset);
	return offset;
}




// Clear screen
void vga_clear_screen() {
	_vga_clear_range(0, MAX_OFFSET);
	vga_set_cursor(0);
}


// Hidden Function
void _vga_clear_range(size_t start_offset, size_t end_offset) {
	char* vga = VGA_ADDRESS;

	for(int i = start_offset; i < end_offset; i++) {
		vga[i] = 0;
	}
}
