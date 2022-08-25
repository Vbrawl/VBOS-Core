#ifndef ISR_H
#define ISR_H


void init_idt();




void isr_0(); // Division by zero
void isr_1(); // Debug



/*    "Non Maskable Interrupt",
    "Breakpoint",
    "Into Detected Overflow",
    "Out of Bounds",
    "Invalid Opcode",
    "No Coprocessor",

    "Double Fault",
    "Coprocessor Segment Overrun",
    "Bad TSS",
    "Segment Not Present",
    "Stack Fault",
    "General Protection Fault",
    "Page Fault",
    "Unknown Interrupt",

    "Coprocessor Fault",
    "Alignment Check",
    "Machine Check",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",

    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved",
    "Reserved"
*/





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
