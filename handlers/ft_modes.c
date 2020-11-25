/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:21:48 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/25 04:16:46 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handlers.h"
#include <stdio.h>

void	ft_select_spec(t_specifier *spec, char c)
{
	if (c == 'c')
		spec->enumerate.c = 1;
	else if (c == 's')
		spec->enumerate.s = 1;
	else if (c == 'p')
		spec->enumerate.p = 1;
	else if (c == 'd')
		spec->enumerate.d = 1;
	else if (c == 'i')
		spec->enumerate.i = 1;
	else if (c == 'u')
		spec->enumerate.u = 1;
	else if (c == 'x')
		spec->enumerate.x = 1;
	else if (c == 'X')
		spec->enumerate.x_x = 1;
}

void	ft_select_display(t_specifier *spec, va_list ap)
{
	if (spec->enumerate.c)
		ft_display_chr(spec, ap);
	else if (spec->enumerate.d)
		;
	else if (spec->enumerate.i)
		;
	else if (spec->enumerate.p)
		;
	else if (spec->enumerate.s)
		ft_display_str(spec, ap);
	else if (spec->enumerate.u)
		;
	else if (spec->enumerate.x)
		;
	else if (spec->enumerate.x_x)
		;
}

void	ft_modes(t_specifier *spec, va_list ap, char c)
{
	ft_select_spec(spec, c);
	ft_select_display(spec, ap);
}
