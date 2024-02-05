[BITS 64]

global strrchr

%include "strlen.asm"

section .text
strrchr:
    xor rax, rax
    cmp rdi, 0
    je .null
    mov rax,
    jmp .count

.count:
    push rax
    call strlen
    pop rax
    cmp rax, 0
    je .null
    cmp byte[rdi + rax], sil
    je .done
    dec rax
    jmp .count

.null:
    xor rax, rax
    ret

.done:
    add rax, rdi
    ret
