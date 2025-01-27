/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_star_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 04:42:51 by dkenchur          #+#    #+#             */
/*   Updated: 2020/12/03 03:17:44 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_get_star_value(char c, int *i, t_specifier *spec)
{
	int	num;

	if (*i > 1 || c != '*')
		return ;
	if (*i == 1 && !(spec->flags & FLG_POINT))
		return ;
	num = va_arg(spec->ap, int);
	if (num < 0 && (spec->flags & FLG_POINT))
	{
		spec->flags &= 0b111111101;
		spec->precision = -1;
		return ;
	}
	if (num < 0)
	{
		spec->flags |= FLG_MINUS;
		num *= -1;
	}
	if (spec->flags & FLG_POINT)
		spec->precision = num;
	else
		spec->width = num;
	(*i)++;
}
