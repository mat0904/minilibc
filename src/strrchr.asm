[BITS 64]

global strrchr

strlen:
    xor rax, rax
    cmp rdi, 0
    je .done
    jmp .count

.count:
    cmp byte[rdi + rax], 0
    je .done
    inc rax
    jmp .count

.done:
    ret

section .text
strrchr:
    xor rax, rax
    cmp rdi, 0
    je .null
    call strlen
    jmp .count

.count:
    cmp rax, 0
    jl .null
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
