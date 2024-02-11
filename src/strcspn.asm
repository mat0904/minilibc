[BITS 64]

GLOBAL strcspn

section .text

strcspn:
    xor rax, rax
    xor rdx, rdx
    xor rcx, rcx
    cmp rdi, 0
    je .ret
    cmp rsi, 0
    je .ret
    jmp .loop

.loop:
    cmp byte[rdi + rcx], 0
    je .endloop
    xor r9, r9
    jmp .loop2

.endloop:
    cmp rax, rdx
    jl .endloopsetrax
    ret

.endloopsetrax:
    mov rax, rdx
    ret

.loop2:
    cmp byte[rsi + r9], 0
    je .end
    movzx r10, byte[rsi + r9]
    cmp byte[rdi + rcx], r10b
    je .find
    inc r9
    jmp .loop2

.end:
    inc rcx
    inc rdx
    jmp .loop

.find:
    inc rcx
    cmp rax, rdx
    jl .setrax
    ret

.setrax:
    mov rax, rdx
    xor rdx, rdx
    ret

.ret:
    ret
