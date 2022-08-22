
CC=/opt/i386elfgcc/bin/i386-elf-gcc
LD=/opt/i386elfgcc/bin/i386-elf-ld
AS=/usr/bin/nasm
GDB=/usr/bin/gdb



# normal flags
CFLAGS = -ffreestanding -g

kernel.bin: entry.o main.o drivers
	${LD} $^ ../drivers/*.o -o $@ --oformat binary

entry.o: entry.asm
	${AS} -f elf $< -o $@

main.o: main.c
	${CC} ${CFLAGS} -c $< -o $@



drivers: ../drivers/vga/vga.c ../drivers/vga/vga.h ../drivers/ports/ports.c ../drivers/ports/ports.h
	cd ../drivers; make all



clean:
	@if [ $(ls -1 *.bin *.o *.elf | wc -l)!=0 ]; \
	then \
		rm *.bin *.o *.elf 2>/dev/null; \
		echo "Cleared kernel builds!"; \
	else \
		echo "No kernel builds found."; \
	fi


kernel-debug.elf: entry.o main.o
	${LD} $^ -o $@

debug: kernel-debug.elf
	@echo "Debug kernel built!"
