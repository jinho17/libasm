NAME = libasm.a
SRCS = ft_strlen.s ft_strcpy.s
OBJS = $(SRCS:.s=.o)

all: $(NAME)

%.o: %.s
	nasm -f macho64 $< -o $@  

$(NAME): $(OBJS)
	ar cr $(NAME) $(OBJS)

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all

#bonus:

test: all
	@gcc -L. -lasm main.c -o test_libasm
	@./test_libasm
	@rm test_libasm
