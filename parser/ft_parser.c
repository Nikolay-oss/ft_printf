/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:45:32 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/30 22:40:38 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include <stdio.h>

int		ismodifer(char c)
{
	const char	*modifers;

	modifers = "cspdiuxX";
	if (ft_memchr(modifers, c, 8))
		return (1);
	return (0);
}

int		isflags(char c)
{
	const char	*flags;

	flags = "-0*.";
	if (ft_memchr(flags, c, 4) || ft_isdigit(c))
		return (1);
	return (0);
}

char	*follow_line(t_specifier *spec, char *str)
{
	ft_init_specifer(spec);
	//if (isflags(*str) || ismodifer(*str))
	//{
		str = ft_flags(str, spec);
		// printf("width -> %d\n", spec.width);
		// printf("width2 -> %d\n", spec.precision);
	//}
	if (ismodifer(*str))
	{
		ft_modes(spec, *str);
		return (++str);
	}
	return (str);
}

/*
*  количество выведенных байт записать в структуру
*/

int		ft_parser(const char *format, t_specifier *spec)
{
	char		*current;
	int			count;
	int			bytes_count;

	count = 0;
	bytes_count = 0;
	bytes_count = ft_putnstr(format, '%');
	current = (char*)format;
	current += bytes_count + 1;
	while (*current)
	{
		current = follow_line(spec, current);
		//printf("\n\n%d\n\n", spec->bytes_count);
		if (spec->bytes_count == -1)
			return (-1);
		count = ft_putnstr(current, '%');
		current += count;
		bytes_count += spec->bytes_count + count;
		if (*current)
			current++;
	}
	return (bytes_count);
}
