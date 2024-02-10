[BITS 64]

global memcpy

section .text
memcpy:
    xor rcx, rcx
    cmp rdi, 0
    je .null
    cmp rsi, 0
    je .null
    jmp .set

.null:
    mov rax, 0
    ret

.set:
    cmp rcx, rdx
    je .end
    mov r8b, [rsi + rcx]
    mov [rdi + rcx], r8b
    inc rcx
    jmp .set

.end:
    mov rax, rdi
    ret
