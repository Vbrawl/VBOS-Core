#ifndef ISR_H
#define ISR_H


#define MASTER_PIC_OFFSET	0x20 //32
#define SLAVE_PIC_OFFSET	0x28 //39



void init_idt();
void isr_null(unsigned char idt_code);


void isr_0(); // Division By Zero
void isr_1(); // Debug
void isr_2(); // Non-Maskable
void isr_3(); // Breakpoint
void isr_4(); // Into Detected Overflow
void isr_5(); // Out of Bounds
void isr_6(); // Invalid OpCode
void isr_7(); // No Coprocessor
void isr_8(); // Double Fault
void isr_9(); // Coprocessor Segment Overrun
void isr_10(); // Bad TSS
void isr_11(); // Segment Not Present
void isr_12(); // Stack Fault
void isr_13(); // General Protection Fault
void isr_14(); // Page Fault

void isr_16(); // Floating Point
void isr_17(); // Alignment Check
void isr_18(); // Machiine Check


/***********
* Reserved *
***********/
void isr_15();

void isr_19();
void isr_20();
void isr_21();
void isr_22();
void isr_23();
void isr_24();
void isr_25();
void isr_26();
void isr_27();
void isr_28();
void isr_29();
void isr_30();
void isr_31();

/*************
* Extra ISRs *
*************/
void isr_32();
void isr_33();
void isr_34();


#endif
