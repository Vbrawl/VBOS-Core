
%macro interrupt_code 1
global backendisr%1
extern isr_%1

backendisr%1:
	cli	; Disable interrupts

	; Save everything
	pusha
	mov ax, ds
	push eax
	mov ax, 0x10	; Get data descriptor padding from gdt table
	mov fs, ax
	mov es, ax
	mov ds, ax
	mov gs, ax


	; Call actual handler
	call isr_%1	; Call Function

	; Restore everything
	pop eax
	mov ds, ax
	mov fs, ax
	mov gs, ax
	mov es, ax
	popa

	sti	; Enable interrupts
	iret	; Return
%endmacro


%assign i 0
%rep 6
	interrupt_code i
%assign i i+1
%endrep
