CC = /opt/i386elfgcc/bin/i386-elf-gcc
LL = /opt/i386elfgcc/bin/i386-elf-ld
GDB = /usr/bin/gdb


C_SOURCES = $(wildcard kernel/*.c drivers/*.c)
HEADERS = $(wildcard kernel/*.h drivers/*.h)

TO_CLEAN = $(wildcard */*.o */*.elf */*.bin *.o *.elf *.bin)

OBJS = ${C_SOURCES:.c=.o}

CFLAGS = -g




os-image.bin: bootloader/bootloader.bin kernel.bin
	cat $^ > os-image.bin

kernel.bin: kernel/entry.o ${OBJS}
	${LL} $^ -o $@ --oformat binary

kernel.elf: kernel/entry.o ${OBJS}
	${LL} $^ -o $@



debug: os-image.bin kernel.elf
	qemu-system-i386 -s -fda os-image.bin &
	${GDB} -ex "target remote localhost:1234" -ex "symbol-file kernel.elf"


clean:
	@rm ${TO_CLEAN} 2>/dev/null; echo "Trying to clear everything..."





run: os-image.bin
	qemu-system-i386 -fda $<







%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -ffreestanding -c $< -o $@

%.o: %.asm
	nasm $< -f elf -o $@

%.bin: %.asm
	nasm $< -f bin -o $@