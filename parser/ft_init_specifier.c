/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_specifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:00:05 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/30 12:43:38 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_init_specifier(t_specifier *spec)
{
	// spec->enumerate.c = 0;
	// spec->enumerate.d = 0;
	// spec->enumerate.i = 0;
	// spec->enumerate.minus = 0;
	// spec->enumerate.p = 0;
	// spec->enumerate.point = 0;
	// spec->enumerate.s = 0;
	// spec->enumerate.star = 0;
	// spec->enumerate.u = 0;
	// spec->enumerate.x = 0;
	// spec->enumerate.x_x = 0;
	// spec->enumerate.zero = 0;
	spec->flags = FLG_NONE;
	spec->width = -1;
	spec->precision = -1;
	spec->bytes_count = 0;
}
