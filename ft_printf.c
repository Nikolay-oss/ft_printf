/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 13:35:57 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/25 05:38:26 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_parser.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			bytes_count;

	bytes_count = 0;
	va_start(ap, format);
	bytes_count = ft_parser(format, ap);
	va_end(ap);
	return (bytes_count);
}
