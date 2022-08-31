#ifndef DRIVER_SCREEN_H
#define DRIVER_SCREEN_H

#include "../extras/types.h"


#define SCREEN_TYPE_VGA_TEXT		1


typedef struct {
	char* address;
	size_t max_y;
	size_t max_x;

	char normal_colour;
	char error_colour;

	char connection_type;
} screen_t;


void screen_init_defaults();

screen_t screen_init(unsigned char type);
void screen_write(screen_t* _this, char* text, bool error);
void screen_write_char(screen_t* _this, char c, bool error);
void screen_write_at(screen_t* _this, size_t offset, char* text, bool error);
void screen_write_char_at(screen_t* _this, size_t offset, char c, bool error);


void screen_clear(screen_t* _this);




extern screen_t VGA_SCREEN;

#endif
