/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 17:37:33 by dkenchur          #+#    #+#             */
/*   Updated: 2020/12/03 03:20:18 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handlers.h"

static	void	ft_tolower_case(char **nbr)
{
	int	i;

	i = 0;
	while (*(nbr + i))
	{
		*(*nbr + i) = ft_tolower(*(*nbr + i));
		i++;
	}
}

void			ft_display_x(t_specifier *spec, int flag)
{
	unsigned int	num;
	char			*nbr;
	int				nbr_size;

	nbr_size = 0;
	num = va_arg(spec->ap, unsigned int);
	if (!(nbr = ft_itoa_base_x(num, 16)))
	{
		spec->bytes_count = -1;
		return ;
	}
	nbr_size = ft_strlen(nbr);
	if (spec->precision > -1 || (spec->flags & FLG_MINUS))
		spec->flags &= 0b11110111;
	if (flag)
		ft_tolower_case(&nbr);
	choose_direction(spec, nbr, nbr_size, 0);
	free(nbr);
}
