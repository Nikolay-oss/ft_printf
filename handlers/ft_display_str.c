/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 22:35:22 by dkenchur          #+#    #+#             */
/*   Updated: 2020/12/03 03:11:54 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handlers.h"

static	void	ft_width_s(char *str, t_specifier *spec, int size)
{
	int		space_count;

	space_count = 0;
	if (spec->flags & FLG_MINUS)
		spec->bytes_count += ft_putlstr(str, (str + size) - str);
	space_count = (size < spec->width) ? spec->width - size : 0;
	spec->bytes_count += space_count;
	ft_repeat_symb(space_count, ' ');
	if (!(spec->flags & FLG_MINUS))
		spec->bytes_count += ft_putlstr(str, (str + size) - str);
}

static	void	ft_precision_s(char *str, t_specifier *spec, int str_size)
{
	int	size;

	size = (spec->precision > str_size) ? 0 : str_size - spec->precision;
	ft_width_s(str, spec, str_size - size);
}

void			ft_display_str(t_specifier *spec)
{
	char	*str;
	int		str_size;

	str = va_arg(spec->ap, char *);
	if (!str)
		str = "(null)";
	str_size = ft_strlen(str);
	if (spec->width < 0 && spec->precision < 0)
		spec->bytes_count += ft_putnstr(str, '\0');
	else if (spec->width > -1 && spec->precision < 0)
		ft_width_s(str, spec, str_size);
	else if (spec->precision > -1)
		ft_precision_s(str, spec, str_size);
}
