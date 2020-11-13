/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:45:32 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/13 18:10:09 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include "libft.h"

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

void	follow_line(char *current)
{
	const char	*modifers;
	const char	*flags;

	modifers = "cspdiuxX";
	flags = "-0.*";
	if (ismodifer(modifers, *(++current)))
	{
		// ft_modes()
		return ;
	}
	if (isflags(flags, current))
	{
		// ft_flags()
	}
}

void	ft_parser(const char *format, va_list ap)
{
	char			*percent;

	if (!(percent = ft_strchr(format, '%')))
	{
		ft_putstr(format);
		return ;
	}
	// while ...
}
