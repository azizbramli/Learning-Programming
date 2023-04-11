        ;; Copyright(C) 2023, Charles T, <chalodss@proton.me> 
        ;; hello - Assembly x68_64

global      _start

SYS_WRITE   equ 1
SYS_EXIT    equ 60
STDOUT      equ 1

SECTION     .rodata
    msg     db "Hello", 10

SECTION     .text

_start:
    mov     rax, SYS_WRITE
    mov     rdi, STDOUT
    mov     rsi, msg
    mov     rdx, 6
    syscall

end:
    mov     rax, SYS_EXIT
    syscall
