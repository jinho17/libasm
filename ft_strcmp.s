;int		ft_strcmp(const char *s1, const char *s2)
;{
;    int     rdx = 0;
;
;    while (1)
;    {
;        if (s1[rdx] == 0 || s2[rdx] == 0 )
;            break ;
;        if (s1[rdx] != s2[rdx])
;            break ;
;        rdx++;
;        continue;
;    }
;    
;    if (s1[rdx] == s2[rdx])
;        return 0;
;    else if (s1[rdx] > s2[rdx])
;        return 1;
;    else
;        return -1;
;}

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