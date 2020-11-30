/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:21:48 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/30 23:22:10 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handlers.h"
#include <stdio.h>

// void	ft_select_spec(t_specifier *spec, char c)
// {
// 	if (c == 'c')
// 		spec->enumerate.c = 1;
// 	else if (c == 's')
// 		spec->enumerate.s = 1;
// 	else if (c == 'p')
// 		spec->enumerate.p = 1;
// 	else if (c == 'd')
// 		spec->enumerate.d = 1;
// 	else if (c == 'i')
// 		spec->enumerate.i = 1;
// 	else if (c == 'u')
// 		spec->enumerate.u = 1;
// 	else if (c == 'x')
// 		spec->enumerate.x = 1;
// 	else if (c == 'X')
// 		spec->enumerate.x_x = 1;
// }

void	ft_select_flag(char c, t_specifier *spec)
{
	if (c == '0')
		spec->flags |= FLG_ZERO;
	else if (c == '*')
		spec->flags |= FLG_STAR;
	else if (c == '-')
		spec->flags |= FLG_MINUS;
	else if (c == '.')
		spec->flags |= FLG_POINT;
}

void	ft_select_display(t_specifier *spec, char c)
{
	if (c == 'c')
		ft_display_chr(spec);
	else if (c == 'd')
		ft_display_d(spec);
	else if (c == 'i')
		;
	else if (c == 'p')
		ft_display_p(spec);
	else if (c == 's')
		ft_display_str(spec);
	else if (c == 'u')
		;
	else if (c == 'x')
		ft_display_x(spec, 0);
	else if (c == 'X')
		ft_display_x(spec, 1);
}

void	ft_modes(t_specifier *spec, char c)
{
	//ft_select_spec(spec, c);
	ft_select_display(spec, c);
}
