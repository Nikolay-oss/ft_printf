/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 05:56:17 by dkenchur          #+#    #+#             */
/*   Updated: 2020/12/03 03:11:41 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handlers.h"

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
	choose_direction(spec, nbr, nbr_size, 0);
	free(nbr);
}
