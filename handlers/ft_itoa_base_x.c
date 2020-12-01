/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 19:41:13 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/30 23:58:12 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handlers.h"
#include "libft.h"

static size_t	init_size(unsigned int n, int base)
{
	size_t	size;

	size = 1;
	while (n / base)
	{
		n /= base;
		size++;
	}
	return (size);
}

char			*ft_itoa_base_x(unsigned int n, int base)
{
	unsigned int		num;
	char				*str;
	size_t				size;
	const char			*arr_base;

	size = init_size(n, base);
	num = n;
	if (!(str = (char*)ft_calloc(size + 1, 1)))
		return (str);
	arr_base = "0123456789ABCDEF";
	while (size > 0)
	{
		*(str + --size) = *(arr_base + (num % base));
		num /= base;
	}
	return (str);
}
