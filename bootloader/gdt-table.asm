[bits 16]
gdt32:
	; 0x00
	.start:
		dd 0
		dd 0

	; 0x08
	.code_seg1: equ $ - .start
		dw 0xffff
		dw 0x0
		db 0x0
		db 10011010b
		db 11001111b
		db 0x0

	; 0x10
	.data_seg1: equ $ - .start
		dw 0xffff
		dw 0x0
		db 0x0
		db 10010010b
		db 11001111b
		db 0x0

	; 0x18
	.end:



gdt32_descriptor:
	dw gdt32.end - gdt32.start - 1
	dd gdt32.start
