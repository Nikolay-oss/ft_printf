/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_specifer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:22:58 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/16 18:06:20 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int		ft_init_specifer(t_specifier **spec)
{
	if (!((*spec)->enumerate = (t_enum*)malloc(sizeof(t_enum))))
		return (0);
	(*spec)->enumerate->c = 0;
	(*spec)->enumerate->d = 0;
	(*spec)->enumerate->i = 0;
	(*spec)->enumerate->minus = 0;
	(*spec)->enumerate->p = 0;
	(*spec)->enumerate->point = 0;
	(*spec)->enumerate->s = 0;
	(*spec)->enumerate->star = 0;
	(*spec)->enumerate->u = 0;
	(*spec)->enumerate->x = 0;
	(*spec)->enumerate->x_x = 0;
	(*spec)->enumerate->zero = 0;
	(*spec)->width = -1;
	(*spec)->precision = -1;
	(*spec)->value = NULL;
	return (1);
}
