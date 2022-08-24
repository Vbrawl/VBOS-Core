#ifndef IDT_H
#define IDT_H

#include "../../extras/types.h"


#define KERNEL_CS		0x08		// bootloader/gdt-table.asm: padding of code_seg

// 32 bit interrupt and trap codes
#define INTERRUPT_CODE		0xE
#define TRAP_CODE		0xF

// access levels
#define KERNEL_ACCESS_LEVEL	0
#define UNUSED_ACCESS_LEVEL1	1
#define UNUSED_ACCESS_LEVEL2	2
#define USER_ACCESS_LEVEL	3


struct idt_entry_t {
	uint16_t	isr_low;	// Lower 16 bits of ISR address
	uint16_t	kernel_cs;	// GDT segment selector that CPU loads into CS before calling ISR
	uint8_t		reserved;	// 0
	uint8_t		attributes;	// Type and attributes
	uint16_t	isr_high;	// High 16 bits of ISR address
} __attribute__((packed));


struct idt_reg_t {
	uint16_t	limit;
	uint32_t	base;
} __attribute__((packed));


// Create IDT table
#define IDT_TABLE_ENTRIES 256
struct idt_entry_t	IDT_TABLE[IDT_TABLE_ENTRIES];
struct idt_reg_t	IDT_REGISTER;


/********************************************************************
*   type   *     name     *               description               *
*********************************************************************
* int      * idt_index    * The interrupt code we are setting       *
* uint32_t * handler_addr * The address to the interrupt handler    *
* bool     * is_trap      * Whether the interrupt is normal or trap *
* uint8_t  * access_level * The access level needed to access it    *
********************************************************************/
void set_idt_entry(int idt_index, uint32_t handler_addr, bool is_trap, uint8_t access_level);



#endif
