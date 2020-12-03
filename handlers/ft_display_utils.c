/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 02:16:07 by dkenchur          #+#    #+#             */
/*   Updated: 2020/12/03 03:12:01 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handlers.h"

void	minus_handler(t_specifier *spec, char *nbr, int width, int precision)
{
	if (spec->flags & FLG_MINUS)
	{
		ft_disp(spec, nbr, precision);
		ft_repeat_symb(width, ' ');
	}
	else
	{
		ft_repeat_symb(width, ' ');
		ft_disp(spec, nbr, precision);
	}
}

void	ft_display_special(t_specifier *spec, char *str)
{
	while (*str != '%')
		str--;
	spec->bytes_count += ft_putnstr(str, '\0');
}
