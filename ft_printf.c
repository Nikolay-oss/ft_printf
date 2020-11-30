/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 13:35:57 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/30 20:30:36 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_parser.h"

int		ft_printf(const char *format, ...)
{
	t_specifier	spec;
	int bytes_count;

	bytes_count = 0;
	va_start(spec.ap, format);
	bytes_count = ft_parser(format, &spec);
	va_end(spec.ap);
	return (bytes_count);
}
