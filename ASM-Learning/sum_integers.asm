        ;; Copyright(C) 2023, Charles T, <chalodss@proton.me> 
        ;; sum integers - Assembly x68_64

global      _start

extern      printf
extern      exit

SECTION     .rodata
    msg     db "Resultat %d", 10

SECTION     .text

_start:

init:
    xor     r10, r10
    xor     rcx, rcx

sum:
    add     r10, rcx
    inc     rcx
    cmp     rcx, 100
    jle     sum

print:
    lea     rdi, msg
    mov     rsi, r10
    call    printf
    call    exit
