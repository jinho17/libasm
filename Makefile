NAME = libasm.a
SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
SRCS_B = ft_atoi_base.s
OBJS = $(SRCS:.s=.o)

all: $(NAME)

%.o: %.s
	nasm -f macho64 $< -o $@  

$(NAME): $(OBJS)
	ar cr $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: all
	@gcc -L. -lasm main.c -o test_libasm
	@./test_libasm
	@rm test_libasm
