/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzhitnik <mzhitnik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:22:03 by mzhitnik          #+#    #+#             */
/*   Updated: 2024/11/16 12:37:49 by mzhitnik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <bsd/string.h> // run wuth -lbsd flag
#include <stdint.h>

void	test_strlen()
{
	printf ("I am testing  ----->   strlen: \n");

	if (strlen("dfgfghfgdh") == ft_strlen("dfgfghfgdh"))
		printf ("Test1 for 'dfgfghfgdh' is: ✅\n");
	else
		printf ("Test1 for 'dfgfghfgdh' is 💀\n");

	if (strlen("") == ft_strlen(""))
		printf ("Test2 for '' is: ✅\n");
	else
		printf ("Test2 for '' is 💀\n");

	if (strlen("\0") == ft_strlen("\0"))
		printf ("Test3 for '\\0' is: ✅\n\n");
	else
		printf ("Test3 for '\\0' is 💀\n\n");		
}

void	test_memcpy()
{
	printf("I am testing  ----->   memcpy: \n");

	char src1[] = "hello";
	char dst1[6] = "";
	if (memcmp(memcpy(dst1, src1, 5), ft_memcpy(dst1, src1, 5), 5) == 0)
		printf("Test1 for 'hello' to empty dest is: ✅\n");
	else
		printf("Test1 for 'hello' to empty dest is: 💀\n");
	char src2[] = "";
	char dst2[6] = "world";
	if (memcmp(memcpy(dst2, src2, 0), ft_memcpy(dst2, src2, 0), 0) == 0)
		printf("Test2 for empty source is: ✅\n");
	else
		printf("Test2 for empty source is: 💀\n");
	char src3[] = "test";
	char dst3[6] = "world";
	if (memcmp(memcpy(dst3, src3, 0), ft_memcpy(dst3, src3, 0), 0) == 0)
		printf("Test3 for copying 0 bytes is: ✅\n");
	else
		printf("Test3 for copying 0 bytes is: 💀\n");
	char	*src = NULL;
	char	*dest = NULL;
	if (memcpy(dest, src, 0) == ft_memcpy(dest, src, 0))
		printf("Test4 for 'NULL' source and 0 bytes is: ✅\n\n");
	else
		printf("Test4 for 'NULL' source and 0 bytes is: 💀\n\n");
}
	
void	test_memset()
{
	printf("I am testing  ----->   memset: \n");

	char str1[6] = "hello";
	if (memcmp(memset(str1, 'a', 3), ft_memset(str1, 'a', 3), 5) == 0)
		printf("Test1 for setting 'hello' to 'aaa..' is: ✅\n");
	else
		printf("Test1 for setting 'hello' to 'aaa..' is: 💀\n");

	char	str2[6] = "world";
	size_t	size = 0;
	if (memcmp(memset(str2, 'b', size), ft_memset(str2, 'b', size), 5) == 0)
		printf("Test2 for 0-byte memset on 'world' is: ✅\n");
	else
		printf("Test2 for 0-byte memset on 'world' is: 💀\n");

	char str3[6] = "world";
	if (memcmp(memset(str3, 'c', 5), ft_memset(str3, 'c', 5), 5) == 0)
		printf("Test3 for filling entire 'world' with 'c' is: ✅\n");
	else
		printf("Test3 for filling entire 'world' with 'c' is: 💀\n");
	char	*str = NULL;
	if (memset(str, 'd', size) == ft_memset(str, 'd', size))
		printf("Test4 for NULL pointer with 0 length is: ✅\n");
	else
		printf("Test4 for NULL pointer with 0 length is: 💀\n");

	char str4[5];
	if (memcmp(memset(str4, 1, 5), ft_memset(str4, 1, 5), 5) == 0)
		printf("Test5 for filling with non-printable (1) value is: ✅\n\n");
	else
		printf("Test5 for filling with non-printable (1) value is: 💀\n\n");
}
	
void	test_bzero()
{
	printf("I am testing  ----->   bzero: \n");

	char str1[6] = "hello";
	ft_bzero(str1 + 2, 2);
	if (memcmp(str1,  "he\0\0o", 5) == 0)
		printf("Test1 for zeroing 'll' in 'hello' is: ✅\n");
	else
		printf("Test1 for zeroing 'll' in 'hello' is: 💀\n");

	char str2[6] = "world";
	ft_bzero(str2, 5);
	if (memcmp(str2, "\0\0\0\0\0", 5) == 0)
		printf("Test2 for zeroing entire 'world' is: ✅\n");
	else
		printf("Test2 for zeroing entire 'world' is: 💀\n");

	char str3[6] = "test!";
	ft_bzero(str3, 0);
	if (memcmp(str3, "test!", 5) == 0)
		printf("Test3 for zeroing 0 bytes in 'test!' is: ✅\n");
	else
		printf("Test3 for zeroing 0 bytes in 'test!' is: 💀\n");

	ft_bzero(NULL, 0);
	printf("Test4 for NULL (zeroing 0 bytes) and got nothing 💀💀💀\n");

	char str4[5] = {1, 2, 3, 4, 5};
	ft_bzero(str4, 3);
	if (memcmp(str4, "\0\0\0\x04\x05", 5) == 0)
		printf("Test5 for zeroing first three bytes in {1, 2, 3, 4, 5} is: ✅\n\n");
	else
		printf("Test5 for zeroing first three bytes in {1, 2, 3, 4, 5} is: 💀\n\n");
}

void	test_memmove()
{
	char dest1[20] = "Hello, World!";
	char dest2[20] = "Hello, World!";
	char overlap_dest1[20] = "Overlap Test";
	char overlap_dest2[20] = "Overlap Test";
	char empty_dest1[20] = "";
	char empty_dest2[20] = "";

	printf("I am testing  ----->   memmove: \n");

	ft_memmove(dest1 + 7, dest1, 5);
	memmove(dest2 + 7, dest2, 5);
	if (strcmp(dest1, dest2) == 0)
		printf("Test1 for 'Hello, World' ✅\n");
	else
		printf("Test1 for 'Hello, World' 💀\n");

	ft_memmove(overlap_dest1 + 4, overlap_dest1, 8);
	memmove(overlap_dest2 + 4, overlap_dest2, 8);
	if (strcmp(overlap_dest1, overlap_dest2) == 0)
		printf("Test2 for 'Overlap test' dest + 4 ✅\n");
	else
		printf("Test2 for 'Overlap test' dest + 4 💀\n");

	ft_memmove(overlap_dest1, overlap_dest1 + 4, 8);
	memmove(overlap_dest2, overlap_dest2 + 4, 8);
	if (strcmp(overlap_dest1, overlap_dest2) == 0)
		printf("Test3 for 'Overlap test'  src + 4 ✅\n");
	else
		printf("Test3 for 'Overlap test' src + 4 💀\n");

	ft_memmove(empty_dest1, empty_dest1, 0);
	memmove(empty_dest2, empty_dest2, 0);
	if (strcmp(empty_dest1, empty_dest2) == 0)
		printf("Test4 Empty ✅\n");
	else
		printf("Test4 Empty 💀\n");
}

void	test_memcmp()
{
	char str1[] = "Hello, World!";
	char str2[] = "Hello, World!";
	char diff_str[] = "Hello, there!";
	char empty_str[] = "";
	char nonprint_str[] = "\x68\x65\x6C\x6C\x6F"; //hello
	char nonprint_diff[] = "\x68\x65\x6C\x6C\x6A"; //hellj

	printf("I am testing  ----->   memcmp:\n");

	if (ft_memcmp(str1, str2, strlen(str1)) == memcmp(str1, str2, strlen(str1)))
		printf("Test1 identical strings ✅\n");
	else
		printf("Test1 identical strings 💀\n");

	if (ft_memcmp(str1, diff_str, strlen(str1)) == memcmp(str1, diff_str, strlen(str1)))
		printf("Test2 different strings✅\n");
	else
		printf("Test2 different strings💀\n");

	if (ft_memcmp(empty_str, empty_str, 0) == memcmp(empty_str, empty_str, 0))
		printf("Test3 empty string ✅\n");
	else
		printf("Test3 empty string 💀\n");

	if (ft_memcmp(nonprint_str, nonprint_str, 5) == memcmp(nonprint_str, nonprint_str, 5))
		printf("Test4 non-printable identical ✅\n");
	else
		printf("Test4 non-printable identical 💀\n");

	if (ft_memcmp(nonprint_str, nonprint_diff, 5) == memcmp(nonprint_str, nonprint_diff, 5))
		printf("Test5 non-printable different strings ✅\n");
	else
		printf("Test5 non-printable different strings 💀\n");

	if (ft_memcmp(NULL, NULL, 0) == 0)
		printf("Test6 NULL comparison (zero length) ✅\n\n");
	else
		printf("Test6 NULL comparison (zero length) 💀\n\n");
}

void	test_memchr()
{
	printf("I am testing -----> memchr: \n");

	char str1[] = "Hello, World!";
	char str2[] = "abcdefg";
    
	if (memchr(str1, 'o', 13) == ft_memchr(str1, 'o', 13))
		printf("Test1 for 'o' in 'Hello, World!' is: ✅\n");
	else
		printf("Test1 for 'o' in 'Hello, World!' is: 💀\n");

	if (memchr(str1, 'z', 13) == ft_memchr(str1, 'z', 13))
		printf("Test2 for 'z' in 'Hello, World!' is: ✅\n");
	else
		printf("Test2 for 'z' in 'Hello, World!' is: 💀\n");

	if (memchr(str1, 'x', 15) == ft_memchr(str1, 'x', 15))
		printf("Test3 for 'x' in  15c of 'Hello, World!' is: ✅\n");
	else
		printf("Test3 for 'x' in 15c of 'Hello, World!' is: 💀\n");

	if (memchr(str1, '!', 13) == ft_memchr(str1, '!', 13))
		printf("Test4 for '!' in 'Hello, World!' is: ✅\n");
	else
		printf("Test4 for '!' in 'Hello, World!' is: 💀\n");

	if (memchr("", 'a', 6) == ft_memchr("", 'a', 6))
		printf("Test5 for empty string is: ✅\n");
	else
		printf("Test5 for empty string is: 💀\n");

	if (memchr(str2, 'd', 3) == ft_memchr(str2, 'd', 3))
		printf("Test6 for 'd' in 3 char of 'abcdefg' is: ✅\n\n\n");
	else
		printf("Test6 for 'd' in 3 char of 'abcdefg' is: 💀\n\n\n");
}

	
void	test_isalpha()
{
	printf ("Libc Functions #2: \n");
	printf ("I am testing  ----->   isalpha: \n");
	
	if (ft_isalpha('A') == 1)
		printf ("Test1 for 'A' is: ✅\n");
	else
		printf ("Test1 for 'A' is 💀\n");
	if (ft_isalpha('z') == 1)
		printf ("Test1 for 'z' is: ✅\n");
	else
		printf ("Test1 for 'z' is 💀\n");
	if (ft_isalpha(5) == isalpha(5))
		printf ("Test2 for '5' is: ✅\n");
	else
		printf ("Test2 for '5' is 💀\n");
	if (ft_isalpha('\n') == isalpha('\n'))
		printf ("Test3 for '\\n' is: ✅\n\n");
	else
		printf ("Test3 for '\\n' is 💀\n\n");
}

void	test_isdigit()
{
	printf ("I am testing  ----->   isdigit: \n");
	if (ft_isdigit('A') == isdigit('A'))
		printf ("Test1 for 'A' is: ✅\n");
	else
		printf ("Test1 for 'A' is 💀\n");
	if (ft_isdigit(5) == isdigit(5))
		printf ("Test2 for '5' is: ✅\n");
	else
		printf ("Test2 for '5' is 💀\n");
	if (ft_isdigit('\n') == isdigit('\n'))
		printf ("Test3 for '\\n' is: ✅\n\n");
	else
		printf ("Test3 for '\\n' is 💀\n\n");
}

void	test_isalnum()
{
	printf ("I am testing  ----->   isalnum: \n");
	if (ft_isalnum('A') == 1)
		printf ("Test1 for 'A' is: ✅\n");
	else
		printf ("Test1 for 'A' is 💀\n");
	if (ft_isalnum('5') == 1)
		printf ("Test2 for '5' is: ✅\n");
	else
		printf ("Test2 for '5' is 💀\n");
	if (ft_isalnum('\n') == isalnum('\n'))
		printf ("Test3 for '\\n' is: ✅\n\n");
	else
		printf ("Test3 for '\\n' is 💀\n\n");
}

void	test_isascii()
{
	printf ("I am testing  ----->   isascii: \n");
	if (ft_isascii('A') == isascii('A'))
		printf ("Test1 for 'A' is: ✅\n");
	else
		printf ("Test1 for 'A' is 💀\n");
	if (ft_isascii(5) == isascii(5))
		printf ("Test2 for '5' is: ✅\n");
	else
		printf ("Test2 for '5' is 💀\n");
	if (ft_isascii('\n') == isascii('\n'))
		printf ("Test3 for '\\n' is: ✅\n\n");
	else
		printf ("Test3 for '\\n' is 💀\n\n");
}
	
void	test_isprint()
{
	printf ("I am testing  ----->   isprint: \n");
	if (ft_isprint('A') == 1)
		printf ("Test1 for 'A' is: ✅\n");
	else
		printf ("Test1 for 'A' is 💀\n");
	if (ft_isprint('5') == 1)
		printf ("Test2 for '5' is: ✅\n");
	else
		printf ("Test2 for '5' is 💀\n");
	if (ft_isprint('\n') == 0)
		printf ("Test3 for '\\n' is: ✅\n\n\n");
	else
		printf ("Test3 for '\\n' is 💀\n\n\n");
}


void	test_toupper()
{
	printf ("Libc Functions #3: \n");
	printf ("I am testing  ----->   toupper: \n");
	if (ft_toupper('A') == toupper('A'))
		printf ("Test1 for 'A' is: ✅\n");
	else
		printf ("Test1 for 'A' is 💀\n");
	if (ft_toupper('z') == toupper('z'))
		printf ("Test2 for 'z' is: ✅\n");
	else
		printf ("Test2 for 'z' is 💀\n");
	if (ft_toupper(5) == toupper(5))
		printf ("Test3 for '5' is: ✅\n");
	else
		printf ("Test3 for '5' is 💀\n");
	if (ft_toupper('\n') == toupper('\n'))
		printf ("Test4 for '\\n' is: ✅\n\n");
	else
		printf ("Test4 for '\\n' is 💀\n\n");
}

void	test_tolower()
{
	printf ("I am testing  ----->   tolower: \n");
	if (ft_tolower('A') == tolower('A'))
		printf ("Test1 for 'A' is: ✅\n");
	else
		printf ("Test1 for 'A' is 💀\n");
	if (ft_tolower('z') == tolower('z'))
		printf ("Test2 for 'z' is: ✅\n");
	else
		printf ("Test2 for 'z' is 💀\n");
	if (ft_tolower(5) == tolower(5))
		printf ("Test3 for '5' is: ✅\n");
	else
		printf ("Test3 for '5' is 💀\n");
	if (ft_tolower('\n') == tolower('\n'))
		printf ("Test4 for '\\n' is: ✅\n\n");
	else
		printf ("Test4 for '\\n' is 💀\n\n");
}

void	test_strchr()
{
	printf("I am testing -----> strchr: \n");

	char str1[] = "Hello, World!";
    
	if (strchr(str1, 'o') == ft_strchr(str1, 'o'))
		printf("Test1 for 'o' in 'Hello, World!' is: ✅\n");
	else
		printf("Test1 for 'o' in 'Hello, World!' is: 💀\n");

	if (strchr(str1, 'z') == ft_strchr(str1, 'z'))
		printf("Test2 for 'z' in 'Hello, World!' is: ✅\n");
	else
		printf("Test2 for 'z' in 'Hello, World!' is: 💀\n");

	if (strchr(str1, 'H') == ft_strchr(str1, 'H'))
		printf("Test3 for 'H' in 'Hello, World!' is: ✅\n");
	else
        printf("Test3 for 'H' in 'Hello, World!' is: 💀\n");

	if (strchr(str1, '!') == ft_strchr(str1, '!'))
		printf("Test4 for '!' in 'Hello, World!' is: ✅\n");
	else
		printf("Test4 for '!' in 'Hello, World!' is: 💀\n");

	if (strchr("", 'a') == ft_strchr("", 'a'))
		printf("Test5 for empty string is: ✅\n\n");
	else
		printf("Test5 for empty string is: 💀\n\n");
}

void	test_strrchr()
{
	printf("I am testing -----> strrchr: \n");

	char str1[] = "Hello, World!";
    
	if (strrchr(str1, 'o') == ft_strrchr(str1, 'o'))
		printf("Test1 for 'o' in 'Hello, World!' is: ✅\n");
	else
		printf("Test1 for 'o' in 'Hello, World!' is: 💀\n");

	if (strrchr(str1, 'z') == ft_strrchr(str1, 'z'))
		printf("Test2 for 'z' in 'Hello, World!' is: ✅\n");
	else
		printf("Test2 for 'z' in 'Hello, World!' is: 💀\n");

	if (strrchr(str1, 'H') == ft_strrchr(str1, 'H'))
		printf("Test3 for 'H' in 'Hello, World!' is: ✅\n");
	else
		printf("Test3 for 'H' in 'Hello, World!' is: 💀\n");

	if (strrchr(str1, '!') == ft_strrchr(str1, '!'))
		printf("Test4 for '!' in 'Hello, World!' is: ✅\n");
	else
		printf("Test4 for '!' in 'Hello, World!' is: 💀\n");

	if (strrchr("", 'a') == ft_strrchr("", 'a'))
		printf("Test5 for empty string is: ✅\n\n\n");
	else
		printf("Test5 for empty string is: 💀\n\n\n");
}
	
void	test_strlcat()
{
	printf ("Libc Functions #4: \n");
	printf("I am testing -----> strlcat: \n");

	char dest1[50] = "Hello, ";
	char dest11[50] = "Hello, ";
	const char src1[] = "World!";
    
	if (ft_strlcat(dest1, src1, sizeof(dest1)) == strlcat(dest11, src1, sizeof(dest1)))
		printf("Test1 for 'Hello, '[50] and 'World!': ✅\n");
	else
		printf("Test1 for 'Hello, '[50] and 'World!': 💀\n");

	char dest2[10] = "Hello";
	char dest22[10] = "Hello";
	const char src2[] = "World!";
	if (ft_strlcat(dest2, src2, sizeof(dest1)) == strlcat(dest22, src2, sizeof(dest1)))
		printf("Test2 for 'Hello, '[10] and 'World!': ✅\n");
	else
		printf("Test2 for 'Hello, '[10] and 'World!': 💀\n");

	char dest3[50] = "";
	char dest33[50] = "";
	const char src3[] = "World!";
	if (ft_strlcat(dest3, src3, sizeof(dest1)) == strlcat(dest33, src3, sizeof(dest1)))
		printf("Test3 for empty dest is: ✅\n");
	else
		printf("Test3 for empty dest is: 💀\n");

	char dest4[50] = "Hello, ";
	char dest44[50] = "Hello, ";
	const char src4[] = "";

	if (ft_strlcat(dest4, src4, sizeof(dest1)) == strlcat(dest44, src4, sizeof(dest1)))
		printf("Test4 for empty source is: ✅\n\n");
	else
		printf("Test4 for empty source is: 💀\n\n");

	char	*dest5 = NULL;
	char	*dest55 = NULL;
	if (ft_strlcat(dest5, "text", 0) == strlcat(dest55, "text", 0))
		printf("Test4 for empty dest is: ✅\n\n");
	else
		printf("Test4 for empty dest is: 💀\n\n");
	
}

void	test_strlcpy()
{
	printf("I am testing -----> strlcpy: \n");

	char dest1[50];
	const char src1[] = "Hello, World!";

	if (ft_strlcpy(dest1, src1, sizeof(dest1)) == strlen(src1))
		printf("Test1 for enough space in dest is: ✅\n");
	else
		printf("Test1 for enough space in dest is: 💀\n");

	char dest2[10];
	const char src2[] = "Hello, World!";
	if (ft_strlcpy(dest2, src2, sizeof(dest2)) == strlen(src2))
		printf("Test2 for not enough space in dest is: ✅\n");
	else
		printf("Test2 for not enough space in dest is: 💀\n");

	char dest3[50];
	const char src3[] = "";
	if (ft_strlcpy(dest3, src3, sizeof(dest3)) == strlen(src3))
		printf("Test3 for empty source is: ✅\n");
	else
		printf("Test3 for empty source is: 💀\n");

	char dest4[50] = "";
	const char src4[] = "Hello!";
	if (ft_strlcpy(dest4, src4, sizeof(dest4)) == strlen(src4))
		printf("Test4 for empty dest is: ✅\n\n");
	else
		printf("Test4 for empty dest is: 💀\n\n");
}

void	test_atoi()
{
	printf("I am testing -----> atoi:\n");

	if (ft_atoi("  42gsfg") == atoi("  42gsfg"))
		printf("Test1 for '  42gsfg' is: ✅\n");
	else
		printf("Test1 for '  42gsfg' is: 💀\n");

	if (ft_atoi("   -123") == atoi("   -123"))
		printf("Test2 for '   -123' is: ✅\n");
	else
		printf("Test2 for '   -123' is: 💀\n");
	if (ft_atoi("   --123") == atoi("   --123"))
		printf("Test2 for '   --123' is: ✅\n");
	else
		printf("Test2 for '   --123' is: 💀\n");
	if (ft_atoi("   ++123") == atoi("   ++123"))
		printf("Test2 for '   ++123' is: ✅\n");
	else
		printf("Test2 for '   ++123' is: 💀\n");
	if (ft_atoi("   +-123") == atoi("   +-123"))
		printf("Test2 for '   +-123' is: ✅\n");
	else
		printf("Test2 for '   +-123' is: 💀\n");
	if (ft_atoi("  +42") == atoi("  +42"))
		printf("Test3 for '  +42' is: ✅\n");
	else
		printf("Test3 for '  +42' is: 💀\n");
	
	if (ft_atoi("  -+42") == atoi("  -+42"))
		printf("Test3 for '  -+42' is: ✅\n");
	else
		printf("Test3 for '  -+42' is: 💀\n");
	
	if (ft_atoi("") == atoi(""))
		printf("Test4 for '' is: ✅\n");
	else
		printf("Test4 for '' is: 💀\n");

	if (ft_atoi("0") == atoi("0"))
		printf("Test5 for '0' is: ✅\n");
	else
		printf("Test5 for '0' is: 💀\n");

	if (ft_atoi("2147483647") == atoi("2147483647"))
		printf("Test6 for '2147483647' is: ✅\n");
	else
		printf("Test6 for '2147483647' is: 💀\n");

	if (ft_atoi("-2147483648") == atoi("-2147483648"))
		printf("Test7 for '-2147483648' is: ✅\n");
	else
		printf("Test7 for '-2147483648' is: 💀\n");

	if (ft_atoi("2147483648") == atoi("2147483648"))
	{
		printf("Test8 for '2147483648' (overflow) is: ✅\n");
		printf("      standart: %d\n      my      : %d\n", atoi("2147483648"), ft_atoi("2147483648"));
	}
	else
	{
		printf("Test8 for '2147483648' (overflow) is: 💀\n");
		printf("      standart: %d\n      my      : %d\n", atoi("2147483648"), ft_atoi("2147483648"));
	}
	if (ft_atoi("-2147483649") == atoi("-2147483649"))
	{
		printf("Test9 for '-2147483649' (underflow) is: ✅\n");
		printf("      standart: %d\n      my      : %d\n", atoi("-2147483649"), ft_atoi("-2147483649"));
	}
	else
	{
		printf("Test9 for '-2147483649' (underflow) is: 💀\n");
		printf("      standart: %d\n      my      : %d\n", atoi("-2147483649"), ft_atoi("-2147483649"));
	}

	if (ft_atoi("abc") == atoi("abc"))
		printf("Test10 for 'abc' is: ✅\n\n");
	else
		printf("Test10 for 'abc' is: 💀\n\n");

}

void	test_strnstr()
{
	printf("I am testing -----> strnstr:\n");

	if (strcmp(ft_strnstr("hello world", "world", 11), "world") == 0)
		printf("Test1 for 'hello world'[11] with 'world' is: ✅\n");
	else
		printf("Test1 for 'hello world'[11] with 'world' is: 💀\n");

	if (ft_strnstr("hello world", "world", 5) == NULL)
		printf("Test2 for 'hello world'[5] with 'world' is: ✅\n");
	else
		printf("Test2 for 'hello world'[5] with 'world' is: 💀\n");


	if (strcmp(ft_strnstr("hello world", "", 11), "hello world") == 0)
		printf("Test3 for 'hello world' with '' is: ✅\n");
	else
		printf("Test3 for 'hello world' with '' is: 💀\n");

	if (ft_strnstr("", "world", 11) == NULL)
		printf("Test4 for '' with 'world' is: ✅\n");
	else
		printf("Test4 for '' with 'world' is: 💀\n");

//	if (ft_strnstr(NULL, "world", 5) == NULL)
//		printf("Test5 for NULL with 'world' is: ✅\n");
//	else
//		printf("Test5 for NULL with 'world' is: 💀\n");

//	if (ft_strnstr(NULL, NULL, 5) == NULL)
//		printf("Test6 for 'hello world' with NULL is: ✅\n");
//	else
//		printf("Test6 for 'hello world' with NULL is: 💀\n");

//	if (ft_strnstr("hello world", NULL, 5) == NULL)
//		printf("Test7 for NULL with NULL is: ✅\n\n");
//	else
//		printf("Test7 for NULL with NULL is: 💀\n\n");
		
	if (ft_strnstr("hello world", "hello", 0) == strnstr("hello world", "hello", 0))
		printf("Test8 for size 0 is: ✅\n\n");
	else
		printf("Test8 for size 0 is: 💀\n\n");
		
//	printf("RESULT for size 0 is: %s\n\n", ft_strnstr("hello world", "hello", 0));
//	printf("RESULT for size 0 is: %s\n\n", strnstr("hello world", "hello", 0));
		
}

void	test_strncmp()
{
	printf("I am testing -----> strncmp:\n");

	if (ft_strncmp("hello", "hello", 5) == strncmp("hello", "hello", 5))
		printf("Test1 for 'hello' vs 'hello' is: ✅\n");
	else
		printf("Test1 for 'hello' vs 'hello' is: 💀\n");

	if (ft_strncmp("hello", "hella", 5) > 0 && strncmp("hello", "hella", 5) > 0)
		printf("Test2 for 'hello' vs 'hella' is: ✅\n");
	else
		printf("Test2 for 'hello' vs 'hella' is: 💀\n");
//printf("Test2 for 'hello' vs 'hella' is     my: %d\n", ft_strncmp("hello", "hella", 5));
//printf("Test2 for 'hello' vs 'hella' is not my: %d\n", strncmp("hello", "hella", 5));
//printf("XXXXX for 'hello' vs 'xella' is not my: %d\n", strncmp("hello", "Hella", 5));
//printf("XXXXX for 'hello' vs 'ella' is not my: %d\n", strncmp("hello", "ella", 5));
//printf("XXXXX for 'hello' vs 'hexla' is not my: %d\n", strncmp("hello", "hexla", 5));
//printf("XXXXX for 'hello' vs 'hellaZ' is not my: %d\n", strncmp("hello", "hellZ", 5));

	if (ft_strncmp("", "", 5) == strncmp("", "", 5))
		printf("Test3 for \"\" vs \"\" (limit 5) is: ✅\n");
	else
		printf("Test3 for \"\" vs \"\" (limit 5) is: 💀\n");
	if (ft_strncmp("hello", "hexla", 5) < 0 && strncmp("hello", "hexla", 5) < 0)
		printf("Test4 for 'hello' vs 'hexla' is: ✅\n\n");
	else
		printf("Test4 for 'hello' vs 'hexla' is: 💀\n\n");
}

void	test_calloc()
{
		printf("I am testing -----> calloc: \n");

	int *arr = (int *)ft_calloc(5, sizeof(int));
	int success = 1;
	if (arr)
	{
		for (int i = 0; i < 5; i++)
		{
			if (arr[i] != 0)
			{
				success = 0;
				break;
			}
		}
		if (success)
			printf("Test1 for [1,2,3,4,5] is: ✅\n");
		else
			printf("Test1 for [1,2,3,4,5] is: 💀\n");
		free(arr);
	}
	else
		printf("Test1 for [1,2,3,4,5] is 💀 (allocation failed)\n");

	char	*arr1 = (char *)ft_calloc(5, 0);
	char	*arr2 = (char *)calloc(5, 0);
	if ( arr1 != NULL && arr2 != NULL)
		printf ("Test 2 for size 0 ✅\n");
	else
		printf ("Test 2 for size 0 💀\n");
		free(arr1);
		free(arr2);

	char	*arr3 = (char *)ft_calloc(0, 5);
	char	*arr4 = (char *)calloc(0, 5);
		
	if ( arr3 != NULL && arr4 != NULL)
		printf ("Test 3 for num 0 ✅\n");
	else
		printf ("Test 3 for num 0 💀\n");
		free(arr3);
		free(arr4);

	char *large_block = (char *)ft_calloc(1000, sizeof(char));
	success = 1;
	if (large_block)
	{
		for (int i = 0; i < 1000; i++)
		{
			if (large_block[i] != 0)
			{
				success = 0;
				break;
			}
		}
		if (success)
			printf("Test4 for 1000 bytes is: ✅\n");
		else
			printf("Test4 for 1000 bytes is 💀\n");
			
	}
	else
		printf("Test4 for 1000 bytes is 💀 (allocation failed)\n");
	free(large_block);

	void *too_large = ft_calloc((size_t) - 1, sizeof(char));
	if (too_large == NULL)
		printf("Test5 for SIZE_MAX allocation is: ✅\n\n");
	else
	{
		printf("Test5 for SIZE_MAX allocation is 💀 (unexpected allocation)\n\n");
		free(too_large);
	}
	
		void *too_large2 = ft_calloc( 2, SIZE_MAX / 2 + 1);
	if (too_large2 == NULL)
		printf("Test6 for SIZE_MAX + 1 allocation is: ✅\n\n");
	else
	{
		printf("Test6 for SIZE_MAX + 1 allocation is 💀 (unexpected allocation)\n\n");
		free(too_large);
	}
}
		
void	test_strdup()
{
	printf("I am testing -----> strdup: \n");

	char *result = ft_strdup("Hello, World!");
	if (result && strcmp(result, "Hello, World!") == 0)
		printf("Test1 for 'Hello, World!' is: ✅\n");
	else
		printf("Test1 for 'Hello, World!' is 💀\n");
	free(result);

	result = ft_strdup("");
	if (result && strcmp(result, "") == 0)
		printf("Test2 for empty string is: ✅\n");
	else
		printf("Test2 for empty string is 💀\n");
	free(result);

//	result = ft_strdup(NULL);
//	if (result == NULL)
//		printf("Test3 for NULL string is: ✅\n\n");
//	else
//		printf("Test3 for NULL string is 💀\n\n");
}

void	test_substr()
{
	printf ("Additional Functions #1: \n");
	printf("I am testing -----> substr: \n");

	char *result = ft_substr("Hello, World!", 7, 5);
	if (result && strcmp(result, "World") == 0)
		printf("Test1 for 'Hello, World!' with start 7, length 5 is: ✅\n");
	else
		printf("Test1 for 'Hello, World!' with start 7, length 5 is 💀\n");
	free(result);

	result = ft_substr("Hello, World!", 20, 5);
	if (result && strcmp(result, "") == 0)
		printf("Test2 for 'Hello, World!' with start 20, length 5 is: ✅\n");
	else
		printf("Test2 for 'Hello, World!' with start 20, length 5 is 💀\n");
	free(result);

	result = ft_substr("Hello, World!", 7, 100);
	if (result && strcmp(result, "World!") == 0)
		printf("Test3 for 'Hello, World!' with start 7, length 100 is: ✅\n");
	else
		printf("Test3 for 'Hello, World!' with start 7, length 100 is 💀\n");
	free(result);

	result = ft_substr("Hello, World!", 0, 0);
	if (result && strcmp(result, "") == 0)
		printf("Test4 for 'Hello, World!' with start 0, length 0 is: ✅\n");
	else
		printf("Test4 for 'Hello, World!' with start 0, length 0 is 💀\n");
	free(result);

	result = ft_substr(NULL, 0, 5);
	if (result == NULL)
		printf("Test5 for NULL string with start 0, length 5 is: ✅\n\n");
	else
		printf("Test5 for NULL string with start 0, length 5 is 💀\n\n");
}

void	test_strjoin()
{
	printf("I am testing -----> strjoin: \n");

	char *result = ft_strjoin("Hello, ", "World!");
	if (result && strcmp(result, "Hello, World!") == 0)
		printf("Test1 for 'Hello, ' + 'World!' is: ✅\n");
	else
		printf("Test1 for 'Hello, ' + 'World!' is 💀\n");
	free(result);

	result = ft_strjoin("", "World!");
	if (result && strcmp(result, "World!") == 0)
		printf("Test2 for '' + 'World!' is: ✅\n");
	else
		printf("Test2 for '' + 'World!' is 💀\n");
	free(result);

	result = ft_strjoin("", "");
	if (result && strcmp(result, "") == 0)
		printf("Test3 for '' + '' is: ✅\n");
	else
		printf("Test3 for '' + '' is 💀\n");
	free(result);

	result = ft_strjoin(NULL, "World!");
	if (result == NULL)
		printf("Test4 for NULL + 'World!' is: ✅\n");
	else
		printf("Test4 for NULL + 'World!' is 💀\n");

	result = ft_strjoin("Hello, ", NULL);
	if (result == NULL)
		printf("Test5 for 'Hello, ' + NULL is: ✅\n\n");
	else
		printf("Test5 for 'Hello, ' + NULL is 💀\n\n");
}

void	test_putchar_fd()
{
	printf("I am testing -----> putchar_fd: \n");
	
	char	c = 'c';
	char	d = '\n';
	
	printf(" <--- Test1 for 'c' ");
	ft_putchar_fd((int)c, 1);
	printf("\n");
    
	printf(" <--- Test2 for newline '\\n': ");
	ft_putchar_fd((int)d, 1);
	printf("\n");
}

void	test_putstr_fd()
{
	printf("\nI am testing -----> putstr_fd: \n");
	char	c = '\n';
	ft_putstr_fd("Hello, World!", 1);
	ft_putchar_fd((int)c, 1);
	ft_putstr_fd("", 1);
	ft_putchar_fd((int)c, 1);
	ft_putstr_fd("Line 1\nLine 2", 1);
	ft_putchar_fd((int)c, 1);
}

void	test_putendl_fd()
{
	printf("\nI am testing -----> putendl_fd: \n");

	ft_putendl_fd("Hello, World!", 1);
    
}
		
void	test_putnbr_fd()
{
	printf("\n\nI am testing -----> putnbr_fd: \n");

	printf("Test1 for 12345\n");
	ft_putnbr_fd(12345, 1);
	printf("\n");

	printf("Test2 for -98765\n");
	ft_putnbr_fd(-98765, 1);
	printf("\n");

	printf("Test3 for 0\n");
	ft_putnbr_fd(0, 1);
	printf("\n");

	printf("Test4 for -2147483648\n");
	ft_putnbr_fd(-2147483648, 1);
	printf("\n");

	printf("Test5 for 2147483647\n");
	ft_putnbr_fd(2147483647, 1);
	printf("\n\n\n");
}

char	func1(unsigned int i, char c) 
{
	return c + i;
}

char	func2(unsigned int i, char c) 
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return c;
}

void	func3(unsigned int i, char *c) 
{
	*c += i;
}

void	func4(unsigned int i, char *c) 
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

void	test_strmapi()
{
	printf ("Additional Functions #2: \n");
	char *result;

	printf("I am testing -----> strmapi:\n");

	result = ft_strmapi("abcd", func1);
	if (result && strcmp(result, "aceg") == 0)
		printf("Test1 for 'abcd' with 'c + i': ✅\n");
	else
		printf("Test1 for 'abcd' with 'c + i': 💀\n");
	free(result);

	result = ft_strmapi("hello", func2);
	if (result && strcmp(result, "HELLO") == 0)
		printf("Test2 for 'hello' to uppercase is: ✅\n");
	else
		printf("Test2 for 'hello' to uppercase is: 💀\n");
	free(result);

	result = ft_strmapi("", func1);
	if (result && strcmp(result, "") == 0)
		printf("Test3 for '' string is: ✅\n");
	else
		printf("Test3 for '' string is: 💀\n");
	free(result);

	result = ft_strmapi(NULL, func1);
	if (result == NULL)
		printf("Test4 for NULL input is: ✅\n\n");
	else
		printf("Test4 for NULL input is: 💀\n\n");
}
void	test_striteri()
{
	char str1[] = "abcd";
	char str2[] = "hello";
	char str3[] = "";
	char *str4 = NULL;

	printf("I am testing -----> striteri:\n");

	ft_striteri(str1, func3);
	if (strcmp(str1, "aceg") == 0)
		printf("Test1 for 'abcd' with 'c + i': ✅\n");
	else
		printf("Test1 for 'abcd' with 'c + i': 💀\n");

	ft_striteri(str2, func4);
	if (strcmp(str2, "HELLO") == 0)
		printf("Test2 for 'hello' to uppercase is: ✅\n");
	else
		printf("Test2 for 'hello' to uppercase is: 💀\n");

	ft_striteri(str3, func3);
	if (strcmp(str3, "") == 0)
		printf("Test3 for '' string is: ✅\n");
	else
		printf("Test3 for '' string is: 💀\n");

	ft_striteri(str4, func3);
	printf("Test4 for NULL and we got nothing 💀💀💀\n\n");
}
void	test_strtrim()
{
	char *result;

	printf("I am testing -----> strtrim:\n");

	result = ft_strtrim("   he llo   ", " ");
	if (strcmp(result, "he llo") == 0)
		printf("Test1 for '   he llo   ' with ' ' is: ✅\n");
	else
		printf("Test1 for '   he llo   ' with ' ' is: 💀 (Got: '%s')\n", result);
	free(result);

	result = ft_strtrim("--abc--def--", "-");
	if (strcmp(result, "abc--def") == 0)
		printf("Test2 for '--abc--def--' with '-' is: ✅\n");
	else
		printf("Test2 for '--abc--def--' with '-' is: 💀 (Got: '%s')\n", result);
	free(result);

	result = ft_strtrim("", " ");
	if (strcmp(result, "") == 0)
		printf("Test3 for '' string with ' ' is: ✅\n");
	else
		printf("Test3 for '' string with ' ' is: 💀 (Got: \"%s\")\n", result);
	free(result);

	result = ft_strtrim("test", "");
	if (strcmp(result, "test") == 0)
		printf("Test4 for 'test' with '' set is: ✅\n");
	else
		printf("Test4 for 'test' with '' set is: 💀 (Got: '%s')\n", result);
	free(result);

	result = ft_strtrim("------", "-");
	if (strcmp(result, "") == 0)
		printf("Test5 for '------' with '-' is: ✅\n");
	else
		printf("Test5 for '------' with '-' is: 💀 (Got: '%s')\n", result);
	free(result);

	result = ft_strtrim("hello", NULL);
	if (result == NULL)
		printf("Test6 for 'hello' with NULL set is: ✅\n");
	else
		printf("Test6 for 'hello' with NULL set is: 💀 (Got: \"%s\")\n", result);
	free(result);

	result = ft_strtrim(NULL, "x");
	if (result == NULL)
		printf("Test7 for NULL input string is: ✅\n\n");
	else
		printf("Test7 for NULL input string is: 💀 (Got: '%s')\n\n", result);
	free(result);
}

int	compare_results(char **result, char **expected)
{
	int i = 0;
	
	while (result[i] != NULL && expected[i] != NULL)
	{
		if (strcmp(result[i], expected[i]) != 0)
			return (1);
		i++;
	}
	if (result[i] != NULL || expected[i] != NULL)
		return (1);
	return (0);
}

static void	ft_free_split(char **dest)
{
	size_t	i;

	if (!dest)
		return ;
	i = 0;
	while (dest[i])
	{
		free(dest[i]);
		i++;
	}
	free(dest);
}

void	test_split()
{
	char **result;
	int i = 0;

	printf("I am testing -----> split:\n");

	result = ft_split("          ", ' ');
	if (result[0] == NULL || result == NULL)
		printf("Test1 for '          ' with ' ' is: ✅\n");
	else
		printf("Test1 for '          ' with ' ' is: 💀\n");

	ft_free_split(result);

	result = ft_split("", ' ');
	if (result[0] == NULL)
		printf("Test2 for '' with ' ' is: ✅\n");
	else
		printf("Test2 for '' with ' ' is: 💀\n");
	ft_free_split(result);
	
	char *expected[] = {
        "lorem", "ipsum", "dolor", "sit", "amet,", "consectetur", "adipiscing", "elit.", 
        "Sed", "non", "risus.", "Suspendisse", NULL};
	result = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse", ' ');
	if (compare_results(result, expected) == 0)
		printf("Test3 for 'lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse' with ' ' is: ✅\n");
	else
	{
		printf("Test3 for 'lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse' with ' ' is: 💀\n");
	}
	while (result && result[i])
		free(result[i++]);
	free(result);

	result = ft_split(NULL, ' ');
	if (result == NULL)
		printf("Test4 for NULL input is: ✅\n");
	else
		printf("Test4 for NULL input is: 💀\n");
	free(result);

	char *expected1[] = {"lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", NULL};
	result = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z');
	if (compare_results(result, expected1) == 0)
		printf("Test5 for separator not in str is: ✅\n\n");
	else
		printf("Test5 for separator not in str is: 💀\n\n");
	i = 0;
	while (result && result[i])
		free(result[i++]);
	free(result);
}

void	test_itoa()
{
	char *result;

	printf("I am testing -----> itoa:\n");

	result = ft_itoa(0);
	if (result != NULL && strcmp(result, "0") == 0)
		printf("Test1 for 0 is: ✅\n");
	else
		printf("Test1 for 0 is: 💀\n");
	free(result);

	char *result1;
	result1 = ft_itoa(12345);
	if (result1 != NULL && strcmp(result1, "12345") == 0)
		printf("Test2 for 12345 is: ✅\n");
	else
		printf("Test2 for 12345 is: 💀\n");
	free(result1);

	char *result2;
	result2 = ft_itoa(-12345);
	if (result2 != NULL && strcmp(result2, "-12345") == 0)
		printf("Test3 for -12345 is: ✅\n");
	else
		printf("Test3 for -12345 is: 💀\n");
	free(result2);

	char *result3;
	result3 = ft_itoa(2147483647);
	if (result3 != NULL && strcmp(result3, "2147483647") == 0)
		printf("Test4 for INT_MAX (2147483647) is: ✅\n");
	else
		printf("Test4 for INT_MAX (2147483647) is: 💀\n");
	free(result3);

	char *result4;
	result4 = ft_itoa(-2147483648);
	if (result4 != NULL && strcmp(result4, "-2147483648") == 0)
		printf("Test5 for INT_MIN (-2147483648) is: ✅\n\n");
	else
		printf("Test5 for INT_MIN (-2147483648) is: 💀\n\n");
	free(result4);
}

	
int	main()
{
	test_strlen();
	test_memcpy();
	test_memset();	
	test_bzero();
	test_memmove();
	test_memcmp();
	test_memchr();

	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();

	test_toupper();	
	test_tolower();
	test_strchr();
	test_strrchr();
	
	test_strlcat();
	test_strlcpy();
	test_atoi();
	test_strnstr();
	test_strncmp();
	test_calloc();
	test_strdup();
	
	test_substr();
	test_strjoin();
	test_putchar_fd();
	test_putstr_fd();
	test_putendl_fd();	
	test_putnbr_fd();

	test_strmapi();
	test_striteri();
	test_strtrim();
	test_split();
	test_itoa();
	
	printf ("All Done \n");
	
	return (0);
}
