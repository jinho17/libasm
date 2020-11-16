segment .text
global  _ft_strcpy

_ft_strcpy:
    mov r8, 0
    mov r9, 0
    jmp len

len:
    cmp byte[rsi + r8], 0
    je store
    inc r8
    jmp len

store:
    cmp r9, r8
    ja exit
    mov cl, byte[rsi + r9]
    mov byte[rdi + r9], cl
    inc r9
    jmp store

exit:
    mov byte[rdi + r9], 0
    mov rax, rdi
    ret
