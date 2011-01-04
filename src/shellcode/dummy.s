# Dummy shellcode that does nothing but exit

.section .text
    .globl _start

_start:
    movl $0xfffffff1, %eax
    xorl $0xfffffff0, %eax
    xorl %ebx, %ebx
    int  $0x80
