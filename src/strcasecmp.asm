[BITS 64]

GLOBAL strcasecmp

section .text
strcasecmp:
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

    cmp r9, 97
    jge .toLowerCaseR9
    cmp r10, 97
    jge .toLowerCaseR10
    jmp .compto0

.compto0:
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

.toLowerCaseR9:
    sub r9, 32
    cmp r10, 97
    jge .toLowerCaseR10
    jmp .compto0

.toLowerCaseR10:
    sub r10, 32
    jmp .compto0

.null:
    mov rax, 0
    ret
