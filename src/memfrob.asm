[BITS 64]

GLOBAL memfrob

section .text
memfrob:
    mov rax, rdi
    cmp rdi, 0
    je .null
    dec rsi
    jmp .crypt

.crypt:
    cmp rsi, 0
    jl .ret
    mov r9, rdi[rsi]
    xor r9, 42
    mov rdi[rsi], r9
    dec rsi
    jmp .crypt

.ret:
    ret

.null:
    xor rax, rax
    jmp .ret
