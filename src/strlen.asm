[BITS 64]

global strlen

section .text
strlen:
    xor rax, rax
    cmp rdi, 0
    je .done
    jmp .count

.count:
    cmp byte[rdi + rax], 0
    je .done
    inc rax
    jmp .count

.done:
    ret
