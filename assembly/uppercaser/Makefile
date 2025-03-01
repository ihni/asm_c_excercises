uppercaser: uppercaser.o
	ld -o bin/uppercaser uppercaser.o

uppercaser.o: uppercaser.asm
	nasm -f elf64 -F stabs uppercaser.asm

uppercaserl: uppercaserl.o
	ld -o bin/uppercaserl uppercaserl.o

uppercaserl.o:	uppercaserl.asm
	nasm -f elf64 -F stabs uppercaserl.asm
