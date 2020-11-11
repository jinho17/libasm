# libasm  


#### nasm 설치  
brew install nasm  


#### 컴파일  
nasm -f macho64 ft_strlen.s  


    옵션  
    -f : 파일을 어셈블 하기위한 옵션  
    macho64 : 유닉스 오브젝트 파일 형식(64bit)  


#### 라이브러리화  
ar rcs libasm.a ft_strlen.o  


#### main문과 컴파일  
gcc libasm.a main.c  
./a.out
