#include "bitutils.h"


uint16_t get_low16_bits(uint32_t value) {
	return (value & 0xFF);
}

uint16_t get_high16_bits(uint32_t value) {
	return (value >> 16);
}
