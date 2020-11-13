;char *ft_strcpy(char *dst, const char *src){
;    int len = 0;
;    int i = 0;
;    while(1)
;    {
;        if (src[len] == '\0')
;            break;
;        len++;
;    }
;
;    while (1)
;    {
;        if (i >= len)
;            break;
;        dst[i] = src[i];
;    }
;    dst[i] = 0;
;    return &dst;
;}

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
    mov cl, byte[rsi + r9]  ;mov명령에 데이터 이름을 레지스터에 바로 쓰는 경우는 없어서 cl 걸쳐서 저장함.
    mov byte[rdi + r9], cl  ;cl 또는 dl 안쓰면 mismatch in operand sizes 오류남.
                            ;64비트에서 64비트인 메모리 주소로 즉시 이동할 수 없다.  
                            ;mov는 16바이트(64비트)를 초과할 수 없기 때문에 dl, cl과 같은 작은 레지스터를 사용해야한다.
    inc r9
    jmp store

exit:
    mov byte[rdi + r9], 0
    mov rax, rdi
    ret
