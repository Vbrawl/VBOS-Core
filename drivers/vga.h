


#define VGA_ADDRESS			(char*)0xb8000
#define MAX_ROW				25
#define MAX_COL				80
#define MAX_OFFSET			MAX_ROW * MAX_COL * 2 // char and attr on each cell so *2




#define REG_VGA_CTRL			0x3d4
#define REG_VGA_DATA			0x3d5

#define WHITE_ON_BLACK			0x0f
#define RED_ON_WHITE			0xf4



// Modes
extern int VGA_MODE;
#define VGA_TEXT	0
#define VGA_GRAPHICS	1


/* General */
short vga_is_mode(int query_mode);


/* Text Mode */

// Position
int vga_calc_offset(int x, int y);
int vga_calc_x(int offset);
int vga_calc_y(int offset);

// Cursor
int vga_get_cursor();
void vga_set_cursor(int offset);

// Printing
int vga_print_char_at(int offset, const char character, const char attribute); // Doesn't move the cursor
int vga_print_string_at(int offset, const char* text, const char attribute); // Doesn't move the cursor

int vga_print_char(const char character, const char attribute);
int vga_print_string(const char* text, const char attribute);


// Clear screen
void vga_clear_screen();
