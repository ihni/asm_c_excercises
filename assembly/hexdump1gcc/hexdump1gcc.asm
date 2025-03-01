; A simple program in assembly for Linux using
; NAS which can convert binary values to hexadecimal strings
; It acts as a very simply hex dump utility
; for file, without the ASCII equivalent column

; Run it this way:
;   hexdump1gcc < (input file)
;
; Build using this:
;   nasm -f elf64 -F hexdump1gcc.asm

section .bss
    bufflen equ 16          ; we read the file 16 bytes at a time
    buff:   resb bufflen    ; text buffer itself, reserve 16 bytes

section .data
    hexstr: db " 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00", 10
    hexlen equ $-hexstr

    digits: db "0123456789ABCDEF"

section .text

global _start

_start:
    mov rbp, rsp    ; for debugging

read:
    mov rax, 0      ; sys_read call 0
    mov rdi, 0      ; fd for stdin
    mov rsi, buff   ; pass offset of buffer to read to
    mov rdx, bufflen ; pass number of bytes to read at each pass
    syscall         ; sys_read and fill to buffer

    mov r15, rax    ; save # of bytes read from file for later
    cmp rax, 0      ; if rax=0, sys_read reached EOF for stdin
    je end          ; if rax == 0, end program
    
    ; Setting up registers for the process buffer step:parm
    mov rsi, buff   ; place address of file buffer into esi
    mov rdi, hexstr ; place address of line string into edi
    xor rcx, rcx    ; clear line string pointer to 0

    ; Go through buffer and convert binary values into hex digits
scan:
    xor rax, rax    ; clear rax to 0

    ; calculate the offset into the line string, which is rcx X 3
    mov rdx, rcx    ; copy the pointer into line string into rdx
    ; shl rdx, 1      ; multiply pointer by 2 using left shift
    ; add rdx, rcx    ; complete the ultipllicaion X3
    lea rdx, [rdx*2+rdx] ; this is what the above 2 lines do!

    ;get a character from buffer and put in both rax and rbx
    mov al, byte [rsi+rcx]  ; put a byte from the input buffer into al
    mov rbx, rax            ; duplicate byte in bl for second nybble
    
    and al, 0xf                 ; mask out all but the low nybble (4 bits)
    mov al, byte [digits+rax]   ; look up the char equivalent of nybble
    mov byte [hexstr+rdx+2], al ; write the char equivalent to 
                                ; the line string

    ; look up high nybble character and insert it into the string:
    shr bl, 4                   ; shift high 4 bits of char into low 4 bits
    mov bl, byte [digits+rbx]   ; look up char equivalent of nybble
    mov byte [hexstr+rdx+1], bl ; write the char equivalent to
                                ; the line string

    ; bump the buffer pointer to the next character and see if we're done:
    inc rcx      ; incrememnt line string pointer
    cmp rcx, r15 ; compare to the number of characters in the buffer
    jna scan     ; loop back if rcx is <= number of chars in buffer (jle?)

    ; write the line of hexadecimal values to stdout:
    mov rax, 1  ; sys_write call 1
    mov rdi, 1  ; fd for stdout
    mov rsi, hexstr ; pass address of the line string in rsi
    mov rdx, hexlen ; pass the size of the line string in rdx
    syscall     ; display line string to stdout
    jmp read    ; loop back and load file buffer again
    
end:
    mov rax, 60     ; sys_exit call 0
    mov rdi, 0      ; error code 0 (no errors!)
    syscall         ; sys_exit
