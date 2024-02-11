[BITS 64]

GLOBAL strchr

section .text
strchr:
    xor rax, rax
    cmp rdi, 0
    je .null
    jmp .count

.count:
    cmp byte[rdi + rax], 0
    je .null
    cmp byte[rdi + rax], sil
    je .done
    inc rax
    jmp .count

.null:
    xor rax, rax
    ret

.done:
    add rax, rdi
    ret
