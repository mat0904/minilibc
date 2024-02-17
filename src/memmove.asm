[BITS 64]

GLOBAL memmove

section .text
memmove:
    cmp rdi, rsi
    je .end
    jl .loopm
    jg .revloopm

.loopm:
    xor rcx, rcx
    jmp .loop

.loop:
    cmp rcx, rdx
    je .end
    mov r8b, byte[rsi + rcx]
    mov byte[rdi + rcx], r8b
    inc rcx
    jmp .loop

.revloopm:
    mov rcx, rdx
    dec rcx
    jmp .revloop

.revloop:
    cmp rcx, 0
    jl .end
    mov r8b, byte[rsi + rcx]
    mov byte[rdi + rcx], r8b
    dec rcx
    jmp .revloop

.end:
    mov rax, rdi
    ret
