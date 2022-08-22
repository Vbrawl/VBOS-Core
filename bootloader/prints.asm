[bits 16]
; print string stored in 'bx'
bios_print_str:
	.prepare:
		pusha
		mov ah, 0x0e

	.print_char:
		mov al, [bx]
		cmp al, 0

		je .return
		int 0x10

		add bx, 1
		jmp .print_char

	.return:
		popa
		ret


[bits 16]
; print a char stored in 'al'
bios_print_char:
	pusha

	mov ah, 0x0e
	int 0x10

	popa
	ret

[bits 16]
; print a new line
bios_print_ln:
	pusha

	mov ah, 0x0e
	mov al, 0x0a
	int 0x10
	mov al, 0x0d
	int 0x10

	popa
	ret

[bits 16]
; print the value of 'dx' as hex
bios_print_hex:
	.prepare:
		pusha

		mov cl, 12

	.print_hex_header:
		mov al, '0'
		call bios_print_char
		mov al, 'x'
		call bios_print_char

	.get_letter:
		mov ax, dx
		shr ax, cl
		and ax, 0x000f

		add ax, 0x30 ; 48
		cmp ax, 0x39 ; 57
		jle .print_letter
		add ax, 0x07 ; (65-57)


	.print_letter:
		call bios_print_char

		cmp cl, 0
		je .return
		sub cl, 4

		jmp .get_letter



	.return:
		popa
		ret

[bits 32]
; print a string stored in 'edx' to the string in VGA-mode
; start from 'ecx' offset (WARNING: ecx is multiplied by 2)
pm_print_str:
	.prepare:
		push eax
		push ebx
		push ecx

		mov ebx, 0xb8000	; VGA memory start
		shl ecx, 1		; Multiply by 2
		add ebx, ecx		; add offset

	.print_char:
		mov al, [edx]
		cmp al, 0
		je .return

		mov ah, 0x0f		; white-on-black
		mov [ebx], ax		; print ax

		add ebx, 2		; increment address
		add edx, 1		; increment character
		jmp .print_char

	.return:
		pop ecx
		pop ebx
		pop eax

		ret
