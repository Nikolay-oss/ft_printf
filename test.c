#include <stdio.h>
#include <stdarg.h>

void	ft_test(char *format, ...)
{
	va_list		ap; // argptr

	va_start(ap, format);
	int a = va_arg(ap, int);
	printf("1 -> %d\n", a);
	char *s = va_arg(ap, char *);
	printf("2 -> %s\n", s);
	char c = va_arg(ap, int);
	printf("3 -> %c\n", c);
	va_end(ap);
}

int		main()
{
	char *s = "Hello, World!";
	char s1[] = "Hello, world!";
	int n = -1024;

	printf("string -> |%0-15.15s|\n", s);
	printf("string -> |%2s|\n", s1);
	printf("int <1024> -> |%7d|\n\n", n);
	//ft_test("", 45, "Hello", 'A');
	printf("|%14.14s|\n", s);
	printf("%13.12s\n", s);
	printf("|%-.15s|\n", s);
	//printf("%13.-1s\n", s);
}

// #include <stdio.h>

// # define FLG_NONE	0b00000000
// # define FLG_ONE	0b00000001
// # define FLG_TWO	0b00000010
// # define FLG_THREE	0b00000100
// # define FLG_FOUR	0b00001000

// int main()
// {
// 	unsigned char	flags;

// 	flags = FLG_NONE;
// 	if (flags & FLG_ONE)
// 		printf("[-] FLG_ONE exist\n");
// 	else
// 		printf("[+] FLG_ONE not exist\n");

// 	flags = flags | FLG_ONE;
// 	if (flags & FLG_ONE)
// 		printf("[+] FLG_ONE exist\n");
// 	else
// 		printf("[-] FLG_ONE not exist\n");

// 	flags = flags | FLG_TWO;
// 	if ((flags & FLG_ONE) && (flags & FLG_TWO))
// 		printf("[+] FLG_ONE and FLG_TWO exist\n");
// 	else
// 		printf("[-] FLG_ONE or FLG_TWO not exist\n");

// 	flags = flags & (~FLG_TWO);
// 	if ((flags & FLG_ONE) && (flags & FLG_TWO))
// 		printf("[-] FLG_ONE and FLG_TWO exist\n");
// 	else
// 		printf("[+] FLG_ONE or FLG_TWO not exist\n");
	
// 	return (0);
// }