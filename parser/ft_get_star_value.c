/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_star_value.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 04:42:51 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/25 05:48:21 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"
#include <stdio.h>

void	ft_get_star_value(char c, int *i, t_specifier *spec, va_list ap)
{
	int	num;

	if (*i > 1 || c != '*')
		return ;
	num = va_arg(ap, int);
	if (spec->enumerate.point)
		spec->precision = num;
	else
		spec->width = num;
	(*i)++;
}
