/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:45:32 by dkenchur          #+#    #+#             */
/*   Updated: 2020/12/03 03:17:50 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parser.h"

int		ft_parser(const char *format, t_specifier *spec)
{
	char		*current;
	int			count;
	int			bytes_count;

	count = 0;
	bytes_count = 0;
	bytes_count = ft_putnstr(format, '%');
	current = (char*)format;
	current += bytes_count;
	while (*current)
	{
		current++;
		ft_init_specifier(spec);
		follow_line(&current, spec);
		if (spec->bytes_count == -1)
			return (-1);
		count = ft_putnstr(current, '%');
		current += count;
		bytes_count += spec->bytes_count + count;
	}
	return (bytes_count);
}
