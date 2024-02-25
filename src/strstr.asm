[BITS 64]

GLOBAL strstr

section .text

strstr:
    cmp rdi, 0
    je .null
    cmp rsi, 0
    je .null
    jmp .comp

.comp:
    cmp byte[rdi], 0
    je .checknull
    push rdi
    push rsi
    jmp .compstr

.checknull:
    movzx r9, byte[rdi]
    movzx r10, byte[rsi]
    sub r9, r10
    je .retnull
    jne .null

.retnull:
    mov rax, rdi
    ret

.restcomp:
    pop rsi
    pop rdi
    inc rdi
    jmp .comp

.compstr:
    cmp byte[rdi], 0
    je .last
    cmp byte[rsi], 0
    je .ret
    movzx r9, byte[rdi]
    movzx r10, byte[rsi]
    sub r9, r10
    cmp r9, 0
    jne .restcomp
    inc rdi
    inc rsi
    jmp .compstr

.last:
    movzx r9, byte[rdi]
    movzx r10, byte[rsi]
    sub r9, r10
    cmp r9, 0
    je .ret
    jne .null

.ret:
    pop rsi
    pop rax
    ret

.null:
    mov rax, 0
    ret
