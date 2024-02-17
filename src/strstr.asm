[BITS 64]

GLOBAL strstr

section .text

strstr:
    cmp rdi, 0
    je .null
    cmp rsi, 0
    je .null
    je .comp

.comp:
;    cmp byte[rdi], byte[rsi]
 ;   je .compstr

.compstr:
;    cmp byte[rdi], byte[rsi]
    inc rdi

.null:
    mov rax, 0
    ret
 .end:
