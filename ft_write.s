;ssize_t	ft_write(int fildes, const void *buf, size_t nbyte)
;{
;    if (fildes < 0 || fildes > 2)
;        return error;
;    if (nbyte < 0)
;        return error;
;    if (buf == NULL)
;        return error;
;    write();
;    return nbyte;
;
;
;}

segment .text
global  _ft_write

_ft_write:
    cmp rdi, 0  
    js  error
    cmp rdi, 2
    ja  error

    cmp rdx, 0
    js  error

    cmp rsi, 0
    je  error

    mov rax, 0x2000004  ;맥os의 write함수 syscall번호  
    syscall             ;write함수 호출  
    jc  error
    ret

error:
    mov rax, -1
    ret
