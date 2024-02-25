[BITS 64]

GLOBAL index

section .text
index:
    xor rax, rax
    xor rcx, rcx
    cmp rdi, 0
    je .null
    jmp .count

.count:
    cmp byte[rdi + rax], 0
    je .last
    cmp byte[rdi + rax], sil
    je .done
    inc rax
    jmp .count

.null:
    xor rax, rax
    ret

.last:
    cmp byte[rdi + rax], sil
    je .done
    jne .null

.findlast:
    add rax, rdi
    ret

.done:
    add rax, rdi
    ret
