[bits 16]
[org 0x7c00]

KERNEL_OFFSET equ 0x1000
SECTORS_TO_LOAD equ 0x10


; store our boot drive
mov [DRIVE_ID], dl


; setup stack
mov bp, 0x9000
mov sp, bp



; print some text for debugging
mov bx, REAL_MODE_TEXT
call bios_print_str
call bios_print_ln


; load sectors from drive
mov dh, SECTORS_TO_LOAD	; 2 sectors
mov dl, [DRIVE_ID]	; load from our drive
mov bx, KERNEL_OFFSET
call bios_load_disk

call bios_enter_protected_mode



;; DATA
DRIVE_ID: db 0
REAL_MODE_TEXT: db "Real mode...", 0
PROTECTED_MODE_TEXT: db "Protected Mode...", 0



;; INCLUDES
%include "bootloader/prints.asm"
%include "bootloader/disk.asm"
%include "bootloader/gdt-table.asm"
%include "bootloader/gdt-switch.asm"

times 510-($-$$) db 0
dw 0xaa55
