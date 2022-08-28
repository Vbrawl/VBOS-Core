CC = /opt/i386elfgcc/bin/i386-elf-gcc
LL = /opt/i386elfgcc/bin/i386-elf-ld
GDB = /usr/bin/gdb
PYTHON = /usr/bin/python3



# Takes a name of the subdirs under "cpu/"
TARGET_ARCH = i386


C_SOURCES = $(wildcard */*.c cpu/${TARGET_ARCH}/*.c drivers/*/*.c)
HEADERS = $(wildcard */*.h cpu/${TARGET_ARCH}/*.h drivers/*/*.h)

TO_CLEAN = $(wildcard */*.o */*.elf */*.bin *.o *.elf *.bin cpu/*/*.o cpu/*/*.elf cpu/*/*.bin)
OBJS = ${C_SOURCES:.c=.o cpu/${TARGET_ARCH}/interrupts.o}


CFLAGS = -g -std=c99 -D${TARGET_ARCH}=${TARGET_ARCH}

# This needs to be the same as bootloader/bootloader.asm's
KERNEL_OFFSET = 0x1000


os-image.bin: kernel.bin bootloader/bootloader.bin
	cat bootloader/bootloader.bin $< > os-image.bin

kernel.bin: kernel/entry.o ${OBJS}
	${LL} $^ -Ttext ${KERNEL_OFFSET} -o $@ --oformat binary
	${PYTHON} SectorUpdater.py

kernel.elf: kernel/entry.o ${OBJS}
	${LL} $^ -Ttext ${KERNEL_OFFSET} -o $@



debug: os-image.bin kernel.elf
	qemu-system-i386 -s -fda os-image.bin &
	${GDB} -ex "target remote localhost:1234" -ex "symbol-file kernel.elf"


clean:
	@rm ${TO_CLEAN} 2>/dev/null; echo "Trying to clear everything..."


run: os-image.bin
	qemu-system-i386 -fda $<

crc: clean run
	make clean




%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -ffreestanding -c $< -o $@

%.o: %.asm
	nasm $< -f elf -o $@

%.bin: %.asm
	nasm $< -f bin -o $@
