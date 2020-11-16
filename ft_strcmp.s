segment .text
global  _ft_strcmp

_ft_strcmp:
    mov rax, 0
    jmp strcmp

strcmp:
    mov al, byte[rdi]
    mov dl, byte[rsi]
    cmp al, 0
    je  end
    cmp dl, 0
    je  end
    cmp al, dl
    jne end
    inc rdi
    inc rsi
    jmp strcmp;

end:
    movzx rax, al
    movzx rdx, dl
    sub rax, rdx
    ret