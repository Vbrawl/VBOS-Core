import os

KERNEL_FILE_PATH = "./kernel.bin"
BOOTLOADER_SECTORS_FILE = "./bootloader/read_sectors.asm"

if os.path.exists(KERNEL_FILE_PATH):
	sectors = os.path.getsize(KERNEL_FILE_PATH)

	sectors = (sectors // 512) + 1 # just to be sure

	with open(BOOTLOADER_SECTORS_FILE, 'w') as bsf:
		bsf.write(f"SECTORS_TO_LOAD equ {sectors}")
	print("Sectors file updated.")
else:
	print("Kernel file not found.")
