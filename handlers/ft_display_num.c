/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 01:56:24 by dkenchur          #+#    #+#             */
/*   Updated: 2020/12/03 03:11:47 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handlers.h"

int		ft_shift(char *nbr)
{
	if (*nbr == '-')
		return (1);
	else if (!ft_memcmp(nbr, "0x", 2))
		return (2);
	return (0);
}

void	ft_disp(t_specifier *spec, char *nbr, int precision)
{
	int	sign;

	sign = ft_shift(nbr);
	spec->bytes_count += ft_putlstr(nbr, sign);
	ft_repeat_symb(precision, '0');
	if (!spec->precision && !ft_memcmp(nbr, "0x0", 4))
		sign = 3;
	spec->bytes_count += ft_putnstr(nbr + sign, '\0');
}

void	width_prec_handler(t_specifier *spec, char *nbr, int nbr_size,
	int pflag)
{
	int	width;
	int	precision;

	width = 0;
	precision = 0;
	if (spec->precision >= nbr_size - pflag)
		precision = spec->precision - (nbr_size - ft_shift(nbr));
	if (spec->width > nbr_size + precision)
		width = spec->width - (nbr_size + precision);
	if (!spec->precision && *nbr == '0' && !pflag)
	{
		spec->bytes_count += spec->width;
		ft_repeat_symb(spec->width, ' ');
		return ;
	}
	spec->bytes_count += width + precision;
	minus_handler(spec, nbr, width, precision);
}

void	zero_handler(t_specifier *spec, char *nbr, int nbr_size)
{
	int	size;

	size = 0;
	if (spec->width > nbr_size)
		size = spec->width - nbr_size;
	ft_disp(spec, nbr, size);
	spec->bytes_count += size;
}

void	choose_direction(t_specifier *spec, char *nbr, int nbr_size, int pflag)
{
	if (spec->width < 0 && spec->precision < 0)
		spec->bytes_count += ft_putnstr(nbr, '\0');
	else if ((spec->flags & FLG_ZERO) && !pflag)
		zero_handler(spec, nbr, nbr_size);
	else
		width_prec_handler(spec, nbr, nbr_size, pflag);
}
