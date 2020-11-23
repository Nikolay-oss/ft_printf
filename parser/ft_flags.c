/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:21:15 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/23 18:19:46 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include <stdio.h>

void	ft_select_flag(char c, t_specifier *spec)
{
	if (c == '0')
		spec->enumerate.zero = 1;
	else if (c == '*')
		spec->enumerate.star = 1;
	else if (c == '-')
		spec->enumerate.minus = 1;
	else if (c == '.')
		spec->enumerate.point = 1;
}

char	*get_end_num(const char *str, int *num)
{
	*num = ft_atoi(str);
	while (*str && ft_isdigit(*str))
		str++;
	return ((char*)str);
}

char	*check_flags(const char *str, t_specifier *spec)
{
	while (*str && (*str == '0' || *str == '-'))
		ft_select_flag(*(str++), spec);
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			if (!spec->enumerate.point)
				str = get_end_num(str, &spec->width);
			if (spec->enumerate.point)
				str = get_end_num(str, &spec->precision);
		}
		if (*str == '.' || *str == '*')
			ft_select_flag(*str, spec);
		if (!isflags(*str))
			return ((char*)str);
		if (*str)
			str++;
	}
	return ((char*)str);
}

/*
*	 добававить получение аргументов, если звездочка
*/

char	*ft_flags(const char *str, t_specifier *spec, va_list ap)
{
	char *current;
	
	current = check_flags(str, spec);
	if (spec->enumerate.star)
		/*get_star*/;
	return (current);
}
