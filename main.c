#include "ft_printf.h"
#include <stdio.h>

int		main()
{
	// ft_printf("Hi, %s World!\n%10s\n%10", "Hello", "URAA");
	// printf("Hi, %s World!\n%10s\n%10", "Hello", "URAA");
	// ft_printf("%s%3s\n", "Hi", "GU");
	// printf("%s%3s\n", "Hi", "GU");
	// ft_printf("ft -> %10.5.7.10s\n", "Hello");
	// printf("pr -> %10.5.7.10s\n", "Hello");
	// ft_printf("%7.2shello%-4.1s->%s\t%s\n", "abc", "world", NULL, "Bye");
	// printf("%7.2shello%-4.1s->%s\t%s\n", "abc", "world", NULL, "Bye");
	// ft_printf("%.1s\n", "ssdsd");
	// printf("%.1s\n", "ssdsd");
	// printf("%*s", 10, "ssdsd");
	// ft_printf("%-2cHello%s%3.2s\n", 'c', " world", "!!!");
	// printf("%-2cHello%s%3.2s\n", 'c', " world", "!!!");
	//printf("%*s\n", 5, "wfd");
	printf("|%d|\n", ft_printf("ABC%-2cHello%s%3.2s\n", 'c', " world", "!!!"));//ft_printf("%*.*s\n", 5, 2, "Hello"));
	printf("|%d|\n", printf("ABC%-2cHello%s%3.2s\n", 'c', " world", "!!!"));//printf("%*.*s\n", 5, 2, "Hello"));
}