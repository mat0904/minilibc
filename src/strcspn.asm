[BITS 64]

GLOBAL strcspn

section .text

strcspn:
    xor rax, rax
    xor rcx, rcx
    cmp rdi, 0
    je .ret
    cmp rsi, 0
    je .ret
    jmp .loop

.loop:
    cmp byte[rdi + rcx], 0
    je .ret
    xor r9, r9
    jmp .loop2

.loop2:
    cmp byte[rsi + r9], 0
    je .end
    movzx r10, byte[rsi + r9]
    cmp byte[rdi + rcx], r10b
    je .ret
    inc r9
    jmp .loop2

.end:
    inc rcx
    inc rax
    jmp .loop

.ret:
    ret
