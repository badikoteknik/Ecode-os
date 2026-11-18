nasm -f elf32 kernel_entry.asm -o kernel_entry.o
gcc -m32 -ffreestanding -fno-pie -fno-stack-protector -c kernel.c -o kernel.o
ld -m elf_i386 -T linker.ld -o kernel.bin kernel_entry.o kernel.o
qemu-system-i386 -kernel kernel.bin -display curses
