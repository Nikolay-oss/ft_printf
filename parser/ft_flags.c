/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:21:15 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/30 22:40:09 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include <stdio.h>

static	char	*get_end_idx(const char *str, int *num)
{
	*num = ft_atoi(str);
	while (*str && ft_isdigit(*str))
		str++;
	return ((char*)str);
}

static	char	*check_flags(const char *str, t_specifier *spec)
{
	int	star_count;

	star_count = 0;
	while (*str && (*str == '0' || *str == '-'))
		ft_select_flag(*(str++), spec);
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			if (!(spec->flags & FLG_POINT))
				str = get_end_idx(str, &spec->width);
			if (spec->flags & FLG_POINT)
				str = get_end_idx(str, &spec->precision);
		}
		if (*str == '.' || *str == '*')
		{
			ft_select_flag(*str, spec);
			ft_get_star_value(*str, &star_count, spec);
		}
		if (ismodifer(*str))
			return ((char*)str);
		if (*str)
			str++;
	}
	return ((char*)str);
}

static	void	check_point(t_specifier *spec)
{
	if (spec->flags & FLG_POINT && spec->precision < 0)
		spec->precision = 0;
	if (spec->flags & FLG_POINT && spec->width < 0)
		spec->width = 0;
	// else if (spec->enumerate.point && spec->width < 0 && spec->precision > 0)
	// 	spec->width = 0;
	// else if (spec->enumerate.point && spec->width > 0 && spec->precision < 0)
	// 	spec->precision = 0;
}

/*
*	 подумать на сегой при нескольких звездочках
*/

char			*ft_flags(const char *str, t_specifier *spec)
{
	char *current;
	
	current = check_flags(str, spec);
	check_point(spec);
	return (current);
}
