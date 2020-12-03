/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_chr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 04:02:06 by dkenchur          #+#    #+#             */
/*   Updated: 2020/12/03 04:12:05 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handlers.h"

static	void	ft_width_c(t_specifier *spec, char c, char fill)
{
	if (spec->flags & FLG_MINUS)
		ft_putchar(c);
	ft_repeat_symb(spec->width - 1, fill);
	if (!(spec->flags & FLG_MINUS))
		ft_putchar(c);
	spec->bytes_count += spec->width - 1;
}

static	void	ft_display_per(t_specifier *spec, char *fill)
{
	if (spec->flags & FLG_MINUS)
		spec->flags &= 0b11110111;
	if (spec->flags & FLG_ZERO)
		*fill = '0';
}

void			ft_display_chr(t_specifier *spec, int perflag)
{
	char	c;
	char	fill;

	fill = ' ';
	c = perflag ? '%' : va_arg(spec->ap, int);
	if (perflag)
		ft_display_per(spec, &fill);
	if (spec->width <= 1)
		ft_putchar(c);
	else
		ft_width_c(spec, c, fill);
	spec->bytes_count += 1;
}
