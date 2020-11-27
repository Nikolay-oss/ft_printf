/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 03:14:29 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/25 03:19:24 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putlstr(char *str, size_t len)
{
	size_t i;

	if (!str)
		return (0);
	i = 0;
	while (*(str + i) && i < len)
		write(1, (str + i++), 1);
	return (i);
}
