;char	*ft_strdup(const char *s1)
;{
;    int i = 0;
;    rtn = malloc(strlen(s1));
;
;    while(1)
;    {
;        if (s1[i] == 0)
;            break;
;        rtn[i] = s1[i];
;        i++;
;    }
;    rtn[i] = 0;
;    return (rtn);
;}


segment .text
global  _ft_strdup
extern  _malloc

_ft_strdup:
    mov r8, 0
    jmp strlen_loop

strlen_loop:
    cmp byte[rdi + r8], 0
    je malloc_rax
    inc r8
    jmp strlen_loop

malloc_rax:
    inc r8
    push rdi        ;rdi 주소 스택에 저장
    mov rdi, r8     ;rdi = strlen(rdi) + 1
    call _malloc    ;rdi길이만큼 malloc. rax로 malloc된 주소 리턴됨
    pop rdi
    mov r9, 0
    jmp strcpy_loop

strcpy_loop:
    cmp r9, r8
    ja exit
    mov cl, byte[rdi + r9]
    mov byte[rax + r9], cl
    inc r9
    jmp strcpy_loop

exit:
    ret