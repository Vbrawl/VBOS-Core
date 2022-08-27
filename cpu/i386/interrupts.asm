; Macro to easily save CPU state
%macro IDT_SAVE_CPU_STATE 0
	pusha
	mov ax, ds
	push eax
	mov ax, 0x10	; Data descriptor from GDT
	mov fs, ax
	mov es, ax
	mov ds, ax
	mov gs, ax
%endmacro


%macro IDT_RESTORE_CPU_STATE 0
	pop eax
	mov ds, ax
	mov fs, ax
	mov gs, ax
	mov es, ax
	popa
%endmacro




%macro interrupt_code 1
global backendisr%1
extern isr_%1

backendisr%1:
	cli	; Disable interrupts

	IDT_SAVE_CPU_STATE

	; Call actual handler
	call isr_%1

	IDT_RESTORE_CPU_STATE

	sti	; Enable interrupts
	iret	; Return
%endmacro

extern isr_null
%macro null_interrupt_code 1
global backendisr%1

backendisr%1:
	;cli	; Disable interrupts

	IDT_SAVE_CPU_STATE

	; Call actual handler
	push byte %1
	call isr_null

	IDT_RESTORE_CPU_STATE

	;sti	; Enable interrupts
	iret	; Return
%endmacro


%assign i 0
%rep 35
	interrupt_code i
%assign i i+1
%endrep

%assign i 35
%rep 221
	null_interrupt_code i
%assign i i+1
%endrep

global backendisr_Array

backendisr_Array:
	%assign i 0
	%rep 256
		dd backendisr%+i
	%assign i i+1
	%endrep
