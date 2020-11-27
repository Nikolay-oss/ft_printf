/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_chr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 04:02:06 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/25 11:24:38 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handlers.h"
#include "libft.h"
#include <stdio.h>

static	void	ft_width_c(t_specifier *spec, char c)
{
	//printf("m -> |%d|\n", spec->enumerate.minus);
	if (spec->enumerate.minus)
		ft_putchar(c);
	ft_repeat_symb(spec->width - 1, ' ');
	if (!spec->enumerate.minus)
		ft_putchar(c);
	spec->bytes_count += spec->width - 1;
}

void	ft_display_chr(t_specifier *spec, va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	if (spec->width <= 1)
		ft_putchar(c);
	else
		ft_width_c(spec, c);
	spec->bytes_count += 1;
}
