/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:48:18 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/30 23:53:53 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handlers.h"
#include "libft.h"

void	ft_display_u(t_specifier *spec)
{
	unsigned int		num;
	char				*nbr;
	int					nbr_size;

	num = va_arg(spec->ap, unsigned int);
	nbr_size = 0;
	if (!(nbr = ft_itoa_base_x(num, 10)))
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
