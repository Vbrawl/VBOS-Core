#ifndef ISR_H
#define ISR_H


void init_idt();



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




/****************************************
* ISR callers (Assembly mode)           *
* Defined in TARGET_ARCH/interrupts.asm *
****************************************/
extern void backendisr0();
extern void backendisr1();
extern void backendisr2();
extern void backendisr3();
extern void backendisr4();
extern void backendisr5();
extern void backendisr6();
extern void backendisr7();
extern void backendisr8();
extern void backendisr9();
extern void backendisr10();
extern void backendisr11();
extern void backendisr12();
extern void backendisr13();
extern void backendisr14();
extern void backendisr15();
extern void backendisr16();
extern void backendisr17();
extern void backendisr18();
extern void backendisr19();
extern void backendisr20();
extern void backendisr21();
extern void backendisr22();
extern void backendisr23();
extern void backendisr24();
extern void backendisr25();
extern void backendisr26();
extern void backendisr27();
extern void backendisr28();
extern void backendisr29();
extern void backendisr30();
extern void backendisr31();





#endif
