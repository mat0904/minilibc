[BITS 64]

GLOBAL strpbrk

section .text
strpbrk:
    xor rcx, rcx
    xor rax, rax
    cmp rdi, 0
    je .null
    cmp rsi, 0
    je .null
    jmp .loop

.loop:
    cmp byte[rdi + rcx], 0
    je .null
    xor r9, r9
    jmp .loop2

.loop2:
    cmp byte[rsi + r9], 0
    je .loop2end
    movzx r10, byte[rsi + r9]
    cmp byte[rdi + rcx], r10b
    je .find
    inc r9
    jmp .loop2

.loop2end:
    inc rcx
    jmp .loop

.find:
    mov rax, rdi
    add rax, rcx
    ret

.null:
    mov rax, 0
    ret
