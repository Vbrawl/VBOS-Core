

[bits 16]
; load 'dh' sectors from 'dl' drive in 'ES:BX'
bios_load_disk:
	.prepare:
		pusha
		push dx


	.load:
		mov ah, 0x02
		mov al, dh
		mov ch, 0x0
		mov cl, 0x2
		mov dh, 0x0
		; mov dl, dl ; already set
		int 0x13

		jc .disk_error

		pop dx
		cmp dh, al
		jne .sectors_error

	.return:
		popa
		ret


	.disk_error:
		mov bx, DISK_ERROR_MSG
		call bios_print_str
		mov dx, ax
		call bios_print_hex
		call bios_print_ln
		jmp .error_loop

	.sectors_error:
		mov bx, SECTORS_ERROR_MSG
		call bios_print_str
		call bios_print_ln
		jmp .error_loop


	.error_loop:
		jmp $


[bits 16]
DISK_ERROR_MSG:
	db "Disk error... Error Code: ", 0

[bits 16]
SECTORS_ERROR_MSG:
	db "Incorrect number of sectors read", 0
