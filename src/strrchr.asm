[BITS 64]

GLOBAL strrchr

section .text
strrchr:
    xor rax, rax
    xor rcx, rcx
    cmp rdi, 0
    je .null
    jmp .count

.count:
    cmp byte[rdi + rcx], 0
    je .last
    cmp byte[rdi + rcx], sil
    je .find
    inc rcx
    jmp .count

.null:
    mov rax, 0
    ret

.last:
    inc rcx
    cmp byte[rdi + rcx], sil
    je .find
    jne .ret

.ret:
    ret

.find:
    mov rax, rdi
    add rax, rcx
    inc rcx
    jmp .count
