;   Activity from Jeff Duntemann's x86 asm book
;

;   This program converts all lowercase letters in a text file
;   to uppercase using I/O redirection
;
;   example of usage:
;       ./uppercaser > outputfile.txt < inputfile.txt
;   
;   requirements:
;       - input file is required
;       - input must be formatted as .txt
;       - output file is not required to have been made
;       - output file in the args must be a .txt
;

;   to build:
;       nasm -f elf64 -F stabs uppercaser.asm
;       ld -o uppercaser uppercaser.o
;
;   or:
;       make uppercaser
;

section .bss
    Buff resb 1 ; create a buffer to store char in

section .data

section .text

global _start

_start:
    mov rbp, rsp

read:
    mov rax, 0      ; sys_read call
    mov rdi, 0      ; fd for stdin
    mov rsi, Buff   ; pass address of buffer to read to
    mov rdx, 1      ; 1 byte is read (a single char)
    syscall         ; perform sys_read

    cmp rax, 0      ; if EOL hit
    je end          ; jump to end

    cmp byte [Buff], 0x61   ; comparing input char to 'a'
    jb write                ; jump if char is lower than 'a'
    cmp byte[Buff], 0x7a    ; comparing input char to 'z'
    ja write                ; jump if char is above 'z'

    sub byte [Buff], 0x20   ; subtract 32 from char to lowercase it

write:
    mov rax, 1              ; syscall for write
    mov rdi, 1              ; fd for stdout
    mov rsi, Buff           ; putting address of buff in rsi
    mov rdx, 1              ; number of chars to write (just a single char)
    syscall
    jmp read                ; loop until EOL hits

end:
    mov rax, 60   ; syscall for exiting a program
    mov rdi, 0
    syscall
