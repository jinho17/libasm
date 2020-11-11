/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim <jinkim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 09:48:26 by jinkim            #+#    #+#             */
/*   Updated: 2020/11/11 17:30:32 by jinkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

size_t  ft_strlen(const char *str);
char *ft_strcpy(char *dst, const char *src);

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

int main()
{
    printf("strlen      %zu\n", strlen("hello"));
    printf("ft_strlen   %zu\n", ft_strlen("hello"));

    printf("\n");
    char dst[100];
    char src[] = "hello world";
    strcpy(dst, src);
    printf("strcpy      |%s|, rtn : |%s|\n", dst, strcpy(dst, src));
    ft_strcpy(dst, src);
    printf("ft_strcpy   |%s|, rtn : |%s|\n", dst, ft_strcpy(dst, src));

    check_strlen();
    check_strcpy();
}