/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:45:32 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/23 17:39:12 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include <stdio.h>

int		ismodifer(char c)
{
	const char	*modifers;

	modifers = "cspdiuxX";
	while (*modifers)
	{
		if (c == *modifers)
			return (1);
		modifers++;
	}
	return (0);
}

int		isflags(char c)
{
	const char	*flags;

	flags = "-0*.";
	while (*flags)
	{
		if (c == *flags || ft_isdigit(c))
			return (1);
		flags++;
	}
	return (0);
}

char	*follow_line(char *str, va_list ap)
{
	t_specifier	spec;

	ft_init_specifer(&spec);
	if (isflags(*str))
	{
		str = ft_flags(str, &spec, ap);
		// printf("width -> %d\n", spec.width);
		// printf("width2 -> %d\n", spec.precision);
	}
	if (ismodifer(*str))
	{
		ft_modes(&spec, ap, *str);
		return (++str);
	}
	return (str);
}

void	ft_parser(const char *format, va_list ap)
{
	char	*current;
	int		count;

	count = ft_putnstr(format, '%');
	current = (char*)format;
	current += count;
	while (*current)
	{
		current = follow_line(current, ap);
		count = ft_putnstr(current, '%');
		current += count;
		if (*current)
			current++;
	}
}
