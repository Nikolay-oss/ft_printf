/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 22:35:22 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/25 04:02:47 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handlers.h"
#include "libft.h"
#include <stdio.h>

static	void	ft_width(char *str, t_specifier *spec, int size)
{
	int		space_count;

	space_count = 0;
	if (spec->enumerate.minus)
		spec->bytes_count += ft_putlstr(str, (str + size) - str);
	space_count = (size < spec->width) ? spec->width - size : 0;
	spec->bytes_count += space_count;
	ft_repeat_symb(space_count, ' ');
	if (!spec->enumerate.minus)
		spec->bytes_count += ft_putlstr(str, (str + size) - str);
}

static	void	ft_precision(char *str, t_specifier *spec, int str_size)
{
	int	size;

	//printf("|%d|\n", spec->precision);
	size = (spec->precision > str_size) ? 0 : str_size - spec->precision;
	//printf("|%d|\n", str_size - size);
	ft_width(str, spec, str_size - size);
}

void			ft_display_str(t_specifier *spec, va_list ap)
{
	char	*str;
	int		str_size;
	int		space_count;

	str = va_arg(ap, char *);
	if (!str)
	{
		spec->bytes_count += ft_putnstr("(null)", '\0');
		return ;
	}
	space_count = 0;
	str_size = ft_strlen(str);
	if (spec->width < 0 && spec->precision < 0)
		spec->bytes_count += ft_putnstr(str, '\0');
	else if (spec->width > -1 && spec->precision < 0)
		ft_width(str, spec, str_size);
	else if (spec->precision > -1)
		ft_precision(str, spec, str_size);
}
