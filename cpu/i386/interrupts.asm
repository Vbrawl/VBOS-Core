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


; Macro to easily restore CPU state
%macro IDT_RESTORE_CPU_STATE 0
	pop eax
	mov ds, ax
	mov fs, ax
	mov gs, ax
	mov es, ax
	popa
%endmacro


; Macro to create call a handler for each ISR
extern main_isr_handler ; <-- isr_null
%macro interrupt_code 1

backendisr%1:
	cli	; Disable interrupts

	IDT_SAVE_CPU_STATE

	; Call actual handler
	push word %1
	call main_isr_handler ; <-- isr_null
	pop ax

	IDT_RESTORE_CPU_STATE

	sti	; Enable interrupts
	iret	; Return
%endmacro


; Write the macro 256 times (from 0 to 255)
%assign i 0
%rep 256
	interrupt_code i
%assign i i+1
%endrep


; An array to easily assign assign
; all handlers to the IDT from C.
global backendisr_Array
backendisr_Array:
	%assign i 0
	%rep 256
		dd backendisr%+i
	%assign i i+1
	%endrep
