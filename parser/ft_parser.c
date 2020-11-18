/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:45:32 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/18 19:56:20 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int		ismodifer(const char *modifers, char c)
{
	while (*modifers)
	{
		if (c == *modifers)
			return (1);
		modifers++;
	}
	return (0);
}

int		isflags(const char *flags, char c)
{
	
}

char	*follow_line(char *current, va_list ap)
{
	const char	*modifers;
	const char	*flags;
	t_specifier	*spec;

	modifers = "cspdiuxX";
	flags = "-0*.";
	if (!(spec = (t_specifier*)malloc(sizeof(t_specifier))))
		return (NULL);
	if (!(ft_init_specifer(&spec)))
		return (NULL);
	if (ismodifer(modifers, *current))
	{
		ft_modes(&spec, ap, *current);
		return (++current);
	}
	if (isflags(flags, current))
	{
		// ft_flags()
	}
	// free enum and spec
}

void	ft_parser(const char *format, va_list ap)
{
	char	*percent;
	char	*current;

	if (!(percent = ft_strchr(format, '%')))
	{
		ft_putstr(format);
		return ;
	}
	current = ++percent;
	while (*current)
	{
		current = follow_line(current, ap);
		if (*current)
			current++;
	}
}
