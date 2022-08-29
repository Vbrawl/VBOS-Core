#ifndef ISR_H
#define ISR_H

#include "../extras/types.h"


#define MASTER_PIC_OFFSET	0x20 //32
#define SLAVE_PIC_OFFSET	0x28 //39


#define ISR_KEYBOARD		33


#define ISR_SIGNAL_CATEGORY_SIZE 5

typedef void(isr_handler_ptr_t)(unsigned char);

typedef struct {
	isr_handler_ptr_t* ptrs[ISR_SIGNAL_CATEGORY_SIZE];
} isr_signal_category_t;

typedef struct {
	isr_signal_category_t isr_signals[256];
} isr_handle_holder_t;


// isr_handle_holder_t isr_handles;


void init_idt();
void main_isr_handler(unsigned char idt_code);


isr_handle_holder_t isr_holder_init();
void isr_holder_register_handler(isr_handle_holder_t* _this, isr_handler_ptr_t ptr, size_t category, size_t position);
void isr_holder_install(isr_handle_holder_t* _this);


#endif
