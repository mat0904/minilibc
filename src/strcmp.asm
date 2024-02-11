[BITS 64]

GLOBAL strcmp

section .text
strcmp:
    cmp rdi, 0
    je .null
    cmp rsi, 0
    je .null
    jmp .comp

.comp:
    cmp byte[rdi], 0
    je .end
    cmp byte[rsi], 0
    je .end
    movzx r9, byte[rdi]
    movzx r10, byte[rsi]
    sub r9, r10
    cmp r9, 0
    jne .ret
    inc rdi
    inc rsi
    jmp .comp

.ret:
    mov rax, r9
    ret

.end:
    movzx r9, byte[rdi]
    movzx r10, byte[rsi]
    sub r9, r10
    cmp r9, 0
    jne .ret
    mov rax, 0
    ret

.null:
    mov rax, 0
    ret
