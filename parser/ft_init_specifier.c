/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_specifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:00:05 by dkenchur          #+#    #+#             */
/*   Updated: 2020/12/03 03:17:47 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

void	ft_init_specifier(t_specifier *spec)
{
	spec->flags = FLG_NONE;
	spec->width = -1;
	spec->precision = -1;
	spec->bytes_count = 0;
}
