/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 23:18:37 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/30 23:31:33 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handlers.h"
#include "libft.h"

void	ft_display_p(t_specifier *spec)
{
	unsigned long long	num;
	char				*nbr;
	int					nbr_size;
	
	nbr_size = 0;
	num = va_arg(spec->ap, unsigned long long);
	if (!(nbr = ft_itoa_base_p(num, 16)))
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
