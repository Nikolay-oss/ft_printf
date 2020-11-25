/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 05:56:17 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/25 12:29:45 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handlers.h"
#include "libft.h"

/*
*	ИСПРАВИТЬ!
*/

static	void	choose_direction(t_specifier *spec, char *str, int str_size, int sign)
{
	if (spec->width < 0 && spec->precision < 0)
		spec->bytes_count += ft_putnstr(str, '\0');
	
}

void			ft_display_d(t_specifier *spec, va_list ap)
{
	int		num;
	char	*str;
	int		sign;
	int		str_size;

	num = va_arg(ap, int);
	sign = 1;
	str_size = 0;
	if (num < 0)
	{
		num *= -1;
		sign = 0;
	}
	if (!(str = ft_itoa(num)))
	{
		spec->bytes_count = -1;
		return ;
	}
	str_size = ft_strlen(str);
	if (spec->enumerate.minus && spec->enumerate.zero)
		spec->enumerate.zero = 0;
	choose_direction(spec, str, str_size, sign);
	free(str);
}
