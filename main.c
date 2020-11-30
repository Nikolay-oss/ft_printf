#include "ft_printf.h"
#include <stdio.h>
//#include <stdlib.h>
#include "libft.h"

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
	// //ft_printf("%ss", "adsd");
	// ft_printf("%-2cHello%s%3.2s\n", 'c', " world", "!!!");
	// printf("%-2cHello%s%3.2s\n", 'c', " world", "!!!");
	// //printf("%*s\n", 5, "wfd");
	// printf("|%d|\n", ft_printf("ABC%-2cHello%s%3.2s\n", 'c', " world", "!!!"));//ft_printf("%*.*s\n", 5, 2, "Hello"));
	// printf("|%d|\n", printf("ABC%-2cHello%s%3.2s\n", 'c', " world", "!!!"));//printf("%*.*s\n", 5, 2, "Hello"));
	// char *s = ft_itoa_base(4294967254, 16);
	// printf("%s\n", s);
	// free(s);
	// printf("|%d|\n", ft_printf("%5.3d Hello%s\n", -42, " world!"));
	// printf("|%d|\n", printf("%5.3d Hello%s\n", -42, " world!"));
	// printf("|%d|\n", ft_printf("%5.3d Hello%s\n", 42, " world!"));
	// printf("|%d|\n", printf("%5.3d Hello%s\n", 42, " world!"));
	// printf("|%d|\n", ft_printf("%2.1d Hello%s\n", 42, " world!"));
	// printf("|%d|\n", printf("%2.1d Hello%s\n", 42, " world!"));
	// printf("|%d|\n", ft_printf("%05d Hello%s\n", 42, " world!"));
	// printf("|%d|\n", printf("%05d Hello%s\n", 42, " world!"));
	// printf("|%d|\n", ft_printf("%05d Hello%s\n", -42, " world!"));
	// printf("|%d|\n", printf("%05d Hello%s\n", -42, " world!"));
	// printf("|%d|\n", ft_printf("%.2d Hello%s\n", -42, " world!"));
	// printf("|%d|\n", printf("%5.-1d Hello%s\n", -42, " world!"));
	// printf("|%d|\n", ft_printf("%12-23-1s%2.1s\n", " world!", NULL));
	// printf("|%d|\n", printf("%12-23-1s%2.1s\n", " world!", NULL));
	//printf("|%d|\n", printf("%-1.*s\n", -5, " world!"));

	/*
	*	%x
	*/

	// printf("|%d|\n", ft_printf("%x!\n", 42));
	// printf("|%d|\n", printf("%x!\n", 42));
	// printf("|%d|\n", ft_printf("%3x!\n", 42));
	// printf("|%d|\n", printf("%3x!\n", 42));
	// printf("|%d|\n", ft_printf("%5x!\n", 42));
	// printf("|%d|\n", printf("%5x!\n", 42));
	// printf("|%d|\n", ft_printf("%5.3x!\n", 42));
	// printf("|%d|\n", printf("%5.3x!\n", 42));
	// printf("|%d|\n", ft_printf("%.x!\n", 42));
	// printf("|%d|\n", printf("%.x!\n", 42));
	// printf("|%d|\n", ft_printf("%05.x!\n", -42));
	// printf("|%d|\n", printf("%05.x!\n", -42));
	// printf("|%d|\n", ft_printf("%-5.20x!\n", -42));
	// printf("|%d|\n", printf("%-5.20x!\n", -42));
	// printf("|%d|\n", ft_printf("%5.x!\n", 0));
	// printf("|%d|\n", printf("%5.x!\n", 0));
	// printf("|%d|\n", ft_printf("%02x!\n", 0));
	// printf("|%d|\n", printf("%02x!\n", 0));

	/*
	*	%X
	*/

	// printf("|%d|\n", ft_printf("%X!\n", 42));
	// printf("|%d|\n", printf("%X!\n", 42));
	// printf("|%d|\n", ft_printf("%3X!\n", 42));
	// printf("|%d|\n", printf("%3X!\n", 42));
	// printf("|%d|\n", ft_printf("%5X!\n", 42));
	// printf("|%d|\n", printf("%5X!\n", 42));
	// printf("|%d|\n", ft_printf("%5.3X!\n", 42));
	// printf("|%d|\n", printf("%5.3X!\n", 42));
	// printf("|%d|\n", ft_printf("%.X!\n", 42));
	// printf("|%d|\n", printf("%.X!\n", 42));
	// printf("|%d|\n", ft_printf("%05.X!\n", -42));
	// printf("|%d|\n", printf("%05.X!\n", -42));
	// printf("|%d|\n", ft_printf("%-5.20X!\n", -42));
	// printf("|%d|\n", printf("%-5.20X!\n", -42));
	// printf("|%d|\n", ft_printf("%5.X!\n", 0));
	// printf("|%d|\n", printf("%5.X!\n", 0));
	// printf("|%d|\n", ft_printf("%02X!\n", 0));
	// printf("|%d|\n", printf("%02X!\n", 0));

	/*
	*	%p
	*/

	// printf("|%d|\n", ft_printf("%p!\n", "42"));
	// printf("|%d|\n", printf("%p!\n", "42"));
	// printf("|%d|\n", ft_printf("%3p!\n", 42));
	// printf("|%d|\n", printf("%3p!\n", 42));
	// printf("|%d|\n", ft_printf("%5p!\n", 42));
	// printf("|%d|\n", printf("%5p!\n", 42));
	// printf("|%d|\n", ft_printf("%5.3p!\n", 42));
	// printf("|%d|\n", printf("%5.3p!\n", 42));
	// printf("|%d|\n", ft_printf("%.p!\n", 42));
	// printf("|%d|\n", printf("%.p!\n", 42));
	// printf("|%d|\n", ft_printf("%05.p!\n", -42));
	// printf("|%d|\n", printf("%05.p!\n", -42));
	// printf("|%d|\n", ft_printf("%-5.20p!\n", -42));
	// printf("|%d|\n", printf("%-5.20p!\n", -42));
	// printf("|%d|\n", ft_printf("%5.p!\n", 0));
	// printf("|%d|\n", printf("%5.p!\n", 0));
	// printf("|%d|\n", ft_printf("%02p!\n", 0));
	// printf("|%d|\n", printf("%02p!\n", 0));
	printf("|%d|\n", ft_printf("%p!\n", NULL));
	printf("|%d|\n", printf("%p!\n", NULL));

	// printf("|%d|\n", printf("%.1da\n", 0));
	// printf("|%d|\n", ft_printf("%.1da\n", 0));
	//printf("%u\n", -42);
	// ft_printf("%q\n");
	// printf("%q\n");
}