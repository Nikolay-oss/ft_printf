/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_chr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 04:02:06 by dkenchur          #+#    #+#             */
/*   Updated: 2020/12/03 03:11:36 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handlers.h"

static	void	ft_width_c(t_specifier *spec, char c)
{
	if (spec->flags & FLG_MINUS)
		ft_putchar(c);
	ft_repeat_symb(spec->width - 1, ' ');
	if (!(spec->flags & FLG_MINUS))
		ft_putchar(c);
	spec->bytes_count += spec->width - 1;
}

void			ft_display_chr(t_specifier *spec)
{
	char	c;

	c = va_arg(spec->ap, int);
	if (spec->width <= 1)
		ft_putchar(c);
	else
		ft_width_c(spec, c);
	spec->bytes_count += 1;
}
