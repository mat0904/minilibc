[BITS 64]

global strcmp

section .text
strcmp:
    xor rdx, rdx
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
    mov rax, 0
    ret
