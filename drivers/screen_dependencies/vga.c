#include "vga.h"
#include "../ports.h"
#include "../../extras/memutils.h"




/*******************
* Hidden Functions *
*******************/
// Clear a the space between 2 offsets
void _vga_clear_range(char* base_address, size_t start_offset, size_t end_offset);












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
	return ((y * VGA_MAX_COL) + x) * 2;
}

int vga_calc_col(int offset) {
	return (offset / 2) % VGA_MAX_COL;
}

int vga_calc_row(int offset) {
	return (offset / 2) / VGA_MAX_COL;
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
int vga_print_char_at(char* base_address, int offset, const char character, const char attribute, bool scroll_if_needed) {

	bool special_char = false;
	char* vga = VGA_ADDRESS;
	size_t max_off = vga_calc_offset(VGA_MAX_COL, VGA_MAX_ROW);

	// Parse special characters
	switch(character) {
	case '\n': // New Line
		special_char = true;
		offset += VGA_MAX_COL * 2; // == row + 1
		break;

	case '\r': // Carriage Return
		special_char = true;
		int col = vga_calc_col(offset);
		offset -= col * 2; // == vga_calc_offset(0, row);
		break;
	}


	if(scroll_if_needed && offset > max_off) {
		// Update offset
		int col = vga_calc_col(offset);
		int row = vga_calc_row(offset);


		// row - MAX_ROW == extra rows
		offset = max_off - vga_calc_offset(col, row - VGA_MAX_ROW);

		// Scroll everything up by 1 row
		safe_memcpy(
			vga, vga + VGA_MAX_COL*2, offset);

		// Clear the last row (that wasn't copied/moved)
		_vga_clear_range(vga, offset, max_off);

	}

	if (special_char) {
		vga_set_cursor(vga_calc_offset(0, VGA_MAX_ROW-2));
	}
	else {
		// Print character if possible
		if(offset < max_off) {
			vga[offset] = character;
			vga[offset+1] = attribute;
			offset += 2;
		}
		else {
			vga[max_off-2] = 'E';
			vga[max_off-1] = attribute;

			offset = max_off;
		}
	}

	return offset;
}

int vga_print_string_at(char* base_address, int offset, const char* text, const char attribute, bool scroll_if_needed) {
	int i = 0;

	while(text[i] != 0) {
		offset = vga_print_char_at(base_address, offset, text[i], attribute, scroll_if_needed);
		i++;
	}

	return offset;
}


int vga_print_char(char* base_address, const char character, const char attribute) {
	int offset = vga_get_cursor();
	offset = vga_print_char_at(base_address, offset, character, attribute, /*Allow Scrolling*/true);

	vga_set_cursor(offset);
	return offset;
}


int vga_print_string(char* base_address, const char* text, const char attribute) {
	int offset = vga_get_cursor();
	offset = vga_print_string_at(base_address, offset, text, attribute, /*Allow Scrolling*/true);

	vga_set_cursor(offset);
	return offset;
}




// Clear screen
void vga_clear_screen(char* base_address) {
	_vga_clear_range(base_address, 0, vga_calc_offset(VGA_MAX_COL, VGA_MAX_ROW));
	vga_set_cursor(0);
}


// Hidden Function
void _vga_clear_range(char* base_address, size_t start_offset, size_t end_offset) {
	for(int i = start_offset; i < end_offset; i++) {
		base_address[i] = 0;
	}
}
