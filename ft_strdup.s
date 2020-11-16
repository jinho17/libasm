segment .text
global  _ft_strdup
extern  _malloc

_ft_strdup:
    mov rax, 0    
    jmp strlen_loop

strlen_loop:
    cmp byte[rdi + rax], 0
    je  malloc_str
    inc rax
    jmp strlen_loop

malloc_str:
    push rdi
    mov rdi, rax
    call _malloc
    pop rdi
    mov r9, 0
    jmp strcpy_loop

strcpy_loop:
    cmp byte[rdi + r9], 0
    je  end
    mov cl, byte[rdi + r9]
    mov byte[rax + r9], cl
    inc r9
    jmp strcpy_loop

end:
    mov byte[rax + r9], 0
    ret