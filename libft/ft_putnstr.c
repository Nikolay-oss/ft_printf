/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:14:15 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/23 16:38:38 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnstr(const char *str, char c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (i);
	while (*(str + i) && *(str + i) != c)
		write(1, str + i++, 1);
	return (i);
}
