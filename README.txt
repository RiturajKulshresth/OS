start:
	export PREFIX="/usr/local/i386elfgcc"
	export TARGET=i386-elf
	export PATH="$$PREFIX/bin:$$PATH"
	i386-elf-gcc --version
	i386-elf-gcc -ffreestanding -c kernel/kernel.c -o kernel.o
	nasm boot/kernel_entry.asm -f elf -o kernel_entry.o
	i386-elf-ld -o kernel.bin -Ttext 0x1000 kernel_entry.o kernel.o --oformat binary
	nasm boot/bootsect.asm -f bin -o bootsect.bin
	cat bootsect.bin kernel.bin > os-image.bin
	qemu-system-x86_64 -fda os-image.bin

initial makefile



install using the 11 lesson instructions or
https://wiki.osdev.org/GCC_Cross-Compiler
will have to load the prefix target after every shutdown

to install GDB follow 
export PREFIX="/usr/local/i386elfgcc"
export TARGET=i386-elf
wget "http://ftp.gnu.org/gnu/gdb/gdb-7.11.tar.gz"
tar -xvzf gdb-7.11.tar.gz
cd gdb-7.11
./configure --target="$TARGET" --prefix="$PREFIX" --program-prefix=i386-elf-
gdb-7.11$ make 
make install
do all in root mode

