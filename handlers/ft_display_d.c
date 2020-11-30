/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 05:56:17 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/30 23:35:27 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handlers.h"
#include "libft.h"
#include <stdio.h>

void	ft_disp(t_specifier *spec, char *nbr, int precision)
{
	int	sign;

	sign = (*nbr == '-') ? 1 : 0;
	spec->bytes_count += ft_putlstr(nbr, sign);
	ft_repeat_symb(precision, '0');
	spec->bytes_count += ft_putnstr(nbr + sign, '\0');
}

void	width_prec_handler(t_specifier *spec, char *nbr, int nbr_size)
{
	int	width;
	int	precision;

	width = 0;
	precision = 0;
	if (spec->precision >= nbr_size)
		precision = spec->precision - (nbr_size - ((*nbr == '-') ? 1 : 0));
	if (spec->width > nbr_size + precision)
		width = spec->width - (nbr_size + precision);
	if (!spec->precision && *nbr == '0')
	{
		spec->bytes_count += spec->width;
		ft_repeat_symb(spec->width, ' ');
		return ;
	}
	spec->bytes_count += width + precision;
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

void	zero_handler(t_specifier *spec, char *nbr, int nbr_size)
{
	int	size;

	size = 0;
	if (spec->width > nbr_size)
	{
		size = spec->width - nbr_size;
		spec->bytes_count += size;
		ft_disp(spec, nbr, size);
	}
}

void	choose_direction(t_specifier *spec, char *nbr, int nbr_size)
{
	if (spec->width < 0 && spec->precision < 0)
		spec->bytes_count += ft_putnstr(nbr, '\0');
	else if (spec->flags & FLG_ZERO)
		zero_handler(spec, nbr, nbr_size);
	else
		width_prec_handler(spec, nbr, nbr_size);
}

void	ft_display_d(t_specifier *spec)
{
	int		num;
	char	*nbr;
	int		nbr_size;

	num = va_arg(spec->ap, int);
	nbr_size = 0;
	if (!(nbr = ft_itoa(num)))
	{
		spec->bytes_count = -1;
		return ;
	}
	nbr_size = ft_strlen(nbr);
	if (spec->precision > -1 || (spec->flags & FLG_MINUS))
		spec->flags &= 0b11110111;
	choose_direction(spec, nbr, nbr_size);
	free(nbr);
}
