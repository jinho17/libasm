/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim <jinkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:48:26 by jinkim            #+#    #+#             */
/*   Updated: 2020/11/13 16:08:07 by jinkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#define _CRT_SECURE_NO_WARNINGS

size_t	ft_strlen(const char *str);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t	ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

void    check_strlen()
{
    char *empty = "";
	char *hello_world = "Hello world !";
	char *alphabet = "abcdefghijklmnopqrstuvwxyz";

	printf("\n================================\n");
	printf("========== FT_STRLEN ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", empty);
	printf("%-20s: 0\n", "expected lenght");
	printf("%-20s: %zu\n", "libc", strlen(empty));	
	printf("%-20s: %zu\n", "libasm", ft_strlen(empty));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: 0\n", "expected lenght");
	printf("%-20s: %zu\n", "libc", strlen(hello_world));	
	printf("%-20s: %zu\n", "libasm", ft_strlen(hello_world));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", alphabet);
	printf("%-20s: 0\n", "expected lenght");
	printf("%-20s: %zu\n", "libc", strlen(alphabet));	
	printf("%-20s: %zu\n", "libasm", ft_strlen(alphabet));
	printf("\n");
}

void clear_buffer(char *buffer, int size)
{
	int i = 0;
	while (i < size)
		buffer[i++] = 0;
}

void check_strcpy()
{
	char buffer[30];
	
	char *empty = "";
	char *hello_world = "Hello world !";
	char *alphabet = "abcdefghijklmnopqrstuvwxyz";
	
	printf("\n================================\n");
	printf("========== FT_STRCPY ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char []", empty);
	printf("%-20s: buffer[50]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, empty));	
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, empty));	
	clear_buffer(buffer, 30);
	printf("\n");
	printf("%-20s: \"%s\"\n", "char []", hello_world);
	printf("%-20s: buffer[50]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, hello_world));	
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, hello_world));	
	clear_buffer(buffer, 30);
	printf("\n");
	printf("%-20s: \"%s\"\n", "char []", alphabet);
	printf("%-20s: buffer[50]\n", "copy to");
	printf("%-20s: \"%s\"\n", "libc", strcpy(buffer, alphabet));	
	clear_buffer(buffer, 30);
	printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(buffer, alphabet));
	clear_buffer(buffer, 30);
	printf("\n");

	// ------- NULL = SEGFAULT
	// printf("%-20s: \"%s\"\n", "char []", alphabet);
	// printf("%-20s: buffer[50]\n", "copy to");
	// printf("%-20s: \"%s\"\n", "libc", strcpy(NULL, NULL));	
	// clear_buffer(buffer, 30);
	// printf("%-20s: \"%s\"\n", "libasm", ft_strcpy(NULL, NULL));
	// clear_buffer(buffer, 30);
	// printf("\n");
}

void check_strcmp()
{
	char *empty = "";
	char *hello_world = "Hello world !";
	char *hello_human = "Hello human !";
	char *hello_world2 = "Hello world !";
	
	printf("\n================================\n");
	printf("========== FT_STRCMP ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"%s\"\n", "compared to", hello_human);
	printf("%-20s: \"%d\"\n", "libc", strcmp(hello_world, hello_human));
	printf("%-20s: \"%d\"\n", "libasm", ft_strcmp(hello_world, hello_human));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"%s\"\n", "compared to", hello_world2);
	printf("%-20s: \"%d\"\n", "libc", strcmp(hello_world, hello_world2));
	printf("%-20s: \"%d\"\n", "libasm", ft_strcmp(hello_world, hello_world2));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world2);
	printf("%-20s: \"%s\"\n", "compared to", empty);
	printf("%-20s: \"%d\"\n", "libc", strcmp(hello_world2, empty));
	printf("%-20s: \"%d\"\n", "libasm", ft_strcmp(hello_world2, empty));
	printf("\n");

	// ------- NULL = SEGFAULT
	// printf("%-20s: \"%s\"\n", "char *", hello_world2);
	// printf("%-20s: %s\n", "compared to", "NULL");
	// printf("%-20s: \"%d\"\n", "libc", strcmp(NULL, hello_world2));
	// printf("%-20s: \"%d\"\n", "libasm", ft_strcmp(NULL, empty));
	// printf("\n");
}

void check_write()
{
	char *hello_world = "Coucou\n";
	char *empty = "";

	printf("\n================================\n");
	printf("========== FT_WRITE ============\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"Libc:%zu\"\n", "libc", write(1, hello_world, 7));
	// printf("\n");
	printf("%-20s: \"Libasm:%zu\"\n", "libasm", ft_write(1, hello_world, 7));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", empty);
	printf("%-20s: \"Libc:%zu\"\n", "libc", write(1, empty, 0));
	// printf("\n");
	printf("%-20s: \"Libasm:%zu\"\n", "libasm", ft_write(1, empty, 0));
	printf("\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	printf("%-20s: \"Libc:%zu\"\n", "libc", write(-7, NULL, 7));
	// printf("\n");
	printf("%-20s: \"Libasm:%zu\"\n", "libasm", ft_write(-7, NULL, 7));
	// printf("\n");
	
}

void check_read()
{
	int fd = open("main.c", O_RDONLY);
	char buff1[891];
	int ret = 1;
	printf("\n================================\n");
	printf("========== FT_READ =============\n");
	printf("================================\n\n");
	printf("%-20s: \n", "header main.c | libc ");
	ret = read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	close(fd);
	fd = open("main.c", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-20s: \n", "header main.c | libasm ");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	clear_buffer(buff1, 891);
	close(fd);

	fd = open("test", O_RDONLY);
	printf("%-20s: \n", "file test | libc ");
	ret = read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	close(fd);
	fd = open("test", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-20s: \n", "file test | libasm ");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	clear_buffer(buff1, 891);
	close(fd);

	fd = open("wrong", O_RDONLY);
	printf("%-20s: \n", "wrong | libc ");
	ret = read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	close(fd);
	fd = open("wrong", O_RDONLY);
	clear_buffer(buff1, 891);
	printf("%-20s: \n", "wrong | libasm ");
	ret = ft_read(fd, buff1, 890);
	buff1[ret] = 0;
	printf("[return : %d]\n|%s|\n", ret, buff1);
	printf("\n");
	clear_buffer(buff1, 891);
	close(fd);
	
	
}

void check_strdup()
{
	char *hello_world = "Hello world !";
	char *empty = "";
	char *save;
	char *save2;
	
	printf("\n================================\n");
	printf("========== FT_STRDUP ===========\n");
	printf("================================\n\n");
	printf("%-20s: \"%s\"\n", "char *", hello_world);
	save = strdup(hello_world);
	printf("%-20s: \"%s\"\n", "libc", save);
	free(save);
	save = NULL;
	save2 = ft_strdup(hello_world);
	printf("%-20s: \"%s\"\n", "libasm", save2);
	free(save2);
	save2 = NULL;
	printf("\n");

	printf("%-20s: \"%s\"\n", "char *", empty);
	save = strdup(empty);
	printf("%-20s: \"%s\"\n", "libc", save);
	free(save);
	save = NULL;
	save2 = ft_strdup(empty);
	printf("%-20s: \"%s\"\n", "libasm", save2);
	free(save2);
	save2 = NULL;
	printf("\n");

	// ------- NULL = SEGFAULT
	// printf("%-20s: NULL\n", "char *");
	// save = strdup(NULL);
	// printf("%-20s: \"%s\"\n", "libc", save);
	// free(save);
	// save = NULL;
	// save2 = ft_strdup(NULL);
	// printf("%-20s: \"%s\"\n", "libasm", save2);
	// free(save2);
	// save2 = NULL;
	// printf("\n");
}

int main()
{
	/*
    printf("strlen      %zu\n", strlen("hello"));
    printf("ft_strlen   %zu\n", ft_strlen("hello"));

    printf("\n");
    char dst[100];
    char src[] = "hello world";
    strcpy(dst, src);
    printf("strcpy      |%s|, rtn : |%s|\n", dst, strcpy(dst, src));
    ft_strcpy(dst, src);
    printf("ft_strcpy   |%s|, rtn : |%s|\n", dst, ft_strcpy(dst, src));

    printf("\n");
	char s1[] = "hello";
	char s2[] = "hellob";
	printf("strcmp		%d\n", strcmp(s1, s2));
	printf("strcmp		%d\n", strcmp("hello", "hellob"));
	printf("ft_strcmp	%d\n", ft_strcmp(s1, s2));


	printf("\n");
	printf("\n");
	printf("|return : %zu|\n", write(-10, "hello", 0));
	printf("|return : %zu|\n", write(10, "hello", -1));
	printf("\n");
	printf("|return : %zu|\n", write(-10, "hello", 10));
	printf("|return : %zu|\n", write(-1, "hello", 10));
	printf("|return : %zu|\n", write(0, "hello", 10));
	printf("|return : %zu|\n", write(1, "hello", 10));
	printf("|return : %zu|\n", write(2, "hello", 10));
	printf("|return : %zu|\n", write(3, "hello", 10));
	printf("|return : %zu|\n", write(4, "hello", 10));
	printf("|return : %zu|\n", write(10, "hello", 10));
	printf("\n");
	printf("|return : %zu|\n", write(-10, NULL, 10));
	printf("\n\nft_write\n");
	printf("|return : %zu|\n", ft_write(1, "hello", 10));*/



	/*
    check_strlen();
    check_strcpy();
	check_strcmp();
	check_write();
	check_read();*/
	check_strdup();
}