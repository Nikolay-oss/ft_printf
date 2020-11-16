/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 22:35:22 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/16 23:05:37 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handlers.h"
#include "libft.h"

void	ft_space_display(int count)
{
	while (count--)
		ft_putchar(' ');
}

void	ft_display_str(t_specifier *spec, va_list ap)
{
	char	*str;
	int		remainder;
	int		str_size;
	int		space_count;

	str = va_arg(ap, char *);
	space_count = 0;
	if (spec->width < 0 && spec->precision < 0)
	{
		ft_putstr(str);
		return ;
	}
	str_size = ft_strlen(str);
	if (!spec->enumerate->minus && spec->width > -1 && spec->precision == -1)
	{
		space_count = (str_size < spec->width) ? spec->width - str_size : 0;
		ft_putstr(str);
		ft_space_display(space_count);
	}
	else if (spec->width == -1 && spec->precision > -1)
		(str_size > spec->precision) ? ft_putnstr(str, spec->precision) : ft_putstr(str);
	// to be continue...
	// if (!spec->enumerate->minus && spec->width > -1 && spec->precision > -1)
	// {
	// 	remainder = str_size - spec->precision;
	// 	remainder = remainder > 0 ? remainder : 0;
	// 	if (spec->width > str_size)
	// 		space_count = spec->width - str_size + remainder;
	// 	while (space_count--)
	// 		ft_putchar(' ');
	// }
	// ft_putnstr(str, spec->precision);
}
