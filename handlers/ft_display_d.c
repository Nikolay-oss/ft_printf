/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 05:56:17 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/27 15:57:52 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handlers.h"
#include "libft.h"

/*
*	ИСПРАВИТЬ!
*/

static	void	ft_disp(t_specifier *spec, char *str, int precision)
{
	
}

static	void	get_width_and_prec(t_specifier *spec, char *str, int str_size)
{
	int	width;
	int	precision;

	width = 0;
	precision = 0;
	if (spec->precision >= str_size)
		precision = spec->precision - (str_size - ((*str == '-') ? 1 : 0));
	if (spec->width > str_size + precision)
		width = spec->width - (str_size + precision);
	spec->bytes_count += width + precision;
	if (spec->enumerate.minus)
	{
		spec->bytes_count += ft_putlstr(str, 1);
		ft_repeat_symb(precision, '0');
		spec->bytes_count += ft_putnstr(str + 1, '\0');
		ft_repeat_symb(width, ' ');
	}
	else
	{
		ft_repeat_symb(width, ' ');
		spec->bytes_count += ft_putlstr(str, 1);
		ft_repeat_symb(precision, '0');
		spec->bytes_count += ft_putnstr(str + 1, '\0');
	}
}

static	void	choose_direction(t_specifier *spec, char *str, int str_size)
{
	if (spec->width < 0 && spec->precision < 0)
	{
		spec->bytes_count += ft_putnstr(str, '\0');
		return ;
	}
	get_width_and_prec(spec, str, str_size);
}

void			ft_display_d(t_specifier *spec, va_list ap)
{
	int		num;
	char	*str;
	int		str_size;

	num = va_arg(ap, int);
	str_size = 0;
	// if (num < 0)
	// {
	// 	num *= -1;
	// 	sign = 0;
	// }
	if (!(str = ft_itoa(num)))
	{
		spec->bytes_count = -1;
		return ;
	}
	str_size = ft_strlen(str);
	if (spec->enumerate.minus && spec->enumerate.zero)
		spec->enumerate.zero = 0;
	choose_direction(spec, str, str_size);
	free(str);
}
