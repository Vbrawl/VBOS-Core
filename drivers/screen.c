#include "screen.h"
#include "screen_dependencies/vga.h"


screen_t VGA_SCREEN;


void screen_init_defaults() {
	VGA_SCREEN = screen_init(SCREEN_TYPE_VGA_TEXT);
}



screen_t screen_init(unsigned char type) {
	screen_t _this;

	switch(type) {
	case SCREEN_TYPE_VGA_TEXT:
		_this.address = VGA_ADDRESS;
		_this.max_y = VGA_MAX_ROW;
		_this.max_x = VGA_MAX_COL;

		_this.normal_colour = 0x0F; // black - white == White On Black
		_this.error_colour = 0xF4; // white - red == Red On White

		//_this.cursor_offset = 0;
		break;
	}

	_this.connection_type = type;
	return _this;
}


void screen_write_char_at(screen_t* _this, size_t offset, char c, bool error) {
	switch(_this->connection_type) {
	case SCREEN_TYPE_VGA_TEXT:
		if(error)
			vga_print_char_at(_this->address, offset, c, _this->error_colour, true);
		else
			vga_print_char_at(_this->address, offset, c, _this->normal_colour, true);
		break;
	}
}



void screen_write_at(screen_t* _this, size_t offset, char* text, bool error) {
	switch(_this->connection_type) {
	case SCREEN_TYPE_VGA_TEXT:
		if(error)
			vga_print_string_at(_this->address, offset, text, _this->error_colour, true);
		else
			vga_print_string_at(_this->address, offset, text, _this->normal_colour, true);
		break;
	}
}


void screen_write(screen_t* _this, char* text, bool error) {
	switch(_this->connection_type) {
	case SCREEN_TYPE_VGA_TEXT:
		if(error)
			vga_print_string(_this->address, text, _this->error_colour);
		else
			vga_print_string(_this->address, text, _this->normal_colour);
		break;
	}
}


void screen_write_char(screen_t* _this, char c, bool error) {
	switch(_this->connection_type) {
	case SCREEN_TYPE_VGA_TEXT:
		if(error)
			vga_print_char(_this->address, c, _this->error_colour);
		else
			vga_print_char(_this->address, c, _this->normal_colour);
		break;
	}
}



void screen_clear(screen_t* _this) {
	switch(_this->connection_type) {
	case SCREEN_TYPE_VGA_TEXT:
		vga_clear_screen(_this->address);
	}
}
