[BITS 64]

global memmove

section .text
memmove:
    xor rcx, rcx
    jmp .push

.push:
    cmp rcx, rdx
    je .depush
    push qword[rdi + rcx]
    inc rcx
    jmp .push

.depush:
    cmp rcx, 0
    dec rcx
    pop qword[rsi + rcx]
    jmp .depush
    jmp .end

.end:
    mov rax, rsi
    ret
