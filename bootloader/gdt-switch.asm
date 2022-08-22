[bits 16]
bios_enter_protected_mode:
	[bits 16]
	.switch_to_pm:
		cli
		lgdt [gdt32_descriptor]
		mov eax, cr0
		or eax, 0x1
		mov cr0, eax
		;jmp CODE_SEG:.init_pm
		jmp gdt32.code_seg1:.init_pm

	[bits 32]
	.init_pm:
		;mov ax, DATA_SEG
		mov ax, gdt32.data_seg1
		mov ds, ax
		mov es, ax
		mov fs, ax
		mov gs, ax
		mov ss, ax

		mov ebp, 0x90000
		mov esp, ebp

		mov edx, PROTECTED_MODE_TEXT
		mov ecx, 0x3c0		; Offset of 12 rows
		call pm_print_str

		call KERNEL_OFFSET
		jmp $			; Executed ONLY if the kernel exits/crashes
