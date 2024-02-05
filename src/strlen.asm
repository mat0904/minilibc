[BITS 64]

global strlen:function

section .text
strlen:
    xor rax, rax
    jmp .count

.count:
    cmp byte[rdi + rax], 0
    je .done
    inc rax
    jmp .count

.done:
    ret
