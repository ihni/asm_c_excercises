;   An improved version of uppercaser program taken from x64 Assembly book by Jeff Duntemann
;

;   Pupose:
;       reads a txt file and converts all lowercase letters into uppercase
;       and outputs a txt file
;
;   To run, enter this to the terminal:
;
;       ./uppercaserl > (output file) < (input file)
;
;   To build:
;       
;       nasm -f elf64 -F stabs uppsercaserl.asm
;       ld -o uppercaserl uppercaserl.o
;

section .bss
    BuffLen equ 128     ; length of buffer
    Buff: resb BuffLen  ; Text buffer itself

section .data

section .text

global _start

_start:
    mov rbp, rsp        ; for correct debugging

read:
    mov rax, 0          ; sys_read 
    mov rdi, 0          ; fd for stdin
    mov rsi, Buff       ; pass offset of buffer to read to
    mov rdx, BuffLen    ; pass number of bytes to read at one pass
    syscall             ; sys_read to fill the buffer

    mov r12, rax        ; copy sys_read return value to r12 for later
    cmp rax, 0          ; if 0, sys_read reached EOF (no text in file)
    je end              ; 

    mov rbx, rax        ; place the number of bytes read into rbx
    mov r13, Buff       ; place the address of buffer into r13
    dec r13             ; adjust r13 to offset by one
    
scan:
    cmp byte [r13+rbx], 0x61        ; test input char against 'a'
    jb next                         ; jmp if below 'a'
    cmp byte [r13+rbx], 0x7a        ; test input char against 'z'
    ja next                         ; jmp if above 'z'

    sub byte [r13+rbx], 0x20        ; lowercase the char

next:
    dec rbx                         ; decrement rbx
    cmp rbx, 0
    jnz scan                        ; if characters still exist, loop back to scan

write:
    mov rax, 1                      ; syscall for sys_write
    mov rdi, 1                      ; fd for stdin
    mov rsi, Buff                   ; pass offset of buffer 
    mov rdx, r12                    ; pass # of bytes of data in the buffer
    syscall                         ; sys_read
    jmp read                        ; loop back and load another buffer

end:
    mov rax, 60
    mov rdi, 0
    syscall
