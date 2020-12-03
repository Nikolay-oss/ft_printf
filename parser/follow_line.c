/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   follow_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:21:15 by dkenchur          #+#    #+#             */
/*   Updated: 2020/12/03 03:17:41 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

static	void	get_end_idx(char **str, int *num)
{
	*num = ft_atoi(*str);
	while (**str && ft_isdigit(**str))
		(*str)++;
}

static	void	check_flags(char **str, t_specifier *spec, int *star_count)
{
	if (ft_isdigit(**str))
	{
		if (!(spec->flags & FLG_POINT))
			get_end_idx(str, &spec->width);
		if (spec->flags & FLG_POINT)
			get_end_idx(str, &spec->precision);
	}
	if (**str == '.' || **str == '*')
	{
		ft_select_flag(**str, spec);
		ft_get_star_value(**str, star_count, spec);
	}
}

static	void	check_point(t_specifier *spec)
{
	if ((spec->flags & FLG_POINT) && spec->precision < 0)
		spec->precision = 0;
	if ((spec->flags & FLG_POINT) && spec->width < 0)
		spec->width = 0;
}

void			follow_line(char **str, t_specifier *spec)
{
	int	star_count;

	star_count = 0;
	while (**str && (**str == '0' || **str == '-'))
		ft_select_flag(*((*str)++), spec);
	while (**str)
	{
		check_flags(str, spec, &star_count);
		if (ft_memchr("cspdiuxX%", **str, 9))
		{
			check_point(spec);
			ft_modes(spec, **str);
			(*str)++;
			return ;
		}
		if (**str)
			(*str)++;
	}
	if (!**str)
		ft_display_special(spec, *str);
}
