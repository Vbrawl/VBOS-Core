#include "string_funcs.h"
#include "memutils.h"



void int_to_string(int n, char* str, size_t max_size) {

	int i = 0;

	do {

		if(i <= max_size) {
			str[i] = (n % 10) + 48; // 48 == '0'
			n = (n / 10);
			i++;
		} else break;

	} while(n != 0);
	str[i--] = 0;

	memreverse(str, i);
}

void int_to_hexstring(int n, char* str, size_t max_size) {

	int i = 0;
	int c = 0;

	do {
		if(i <= max_size) {

			c = (n & 0xF); // 48 == '0'

			if(c > 9) {
				str[i] = c + 55;
			} else {
				str[i] = c + 48;
			}

			n = n >> 4;
			i++;

		}
	} while(n != 0);

	str[i++] = 'x';
	str[i++] = '0';
	str[i--] = 0;

	memreverse(str, i);

}
