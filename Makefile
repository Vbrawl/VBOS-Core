CC = /opt/i386elfgcc/bin/i386-elf-gcc
LL = /opt/i386elfgcc/bin/i386-elf-ld
GDB = /usr/bin/gdb


C_SOURCES = $(wildcard */*.c)
HEADERS = $(wildcard */*.h)

TO_CLEAN = $(wildcard */*.o */*.elf */*.bin *.o *.elf *.bin)

OBJS = ${C_SOURCES:.c=.o}

CFLAGS = -g -std=c99


# This needs to be the same as bootloader/bootloader.asm's
KERNEL_OFFSET = 0x1000


os-image.bin: bootloader/bootloader.bin kernel.bin
	cat $^ > os-image.bin

kernel.bin: kernel/entry.o ${OBJS}
	${LL} $^ -Ttext ${KERNEL_OFFSET} -o $@ --oformat binary

kernel.elf: kernel/entry.o ${OBJS}
	${LL} $^ -Ttext ${KERNEL_OFFSET} -o $@



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
