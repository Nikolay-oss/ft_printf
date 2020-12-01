/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:09:33 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/30 23:57:49 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handlers.h"
#include "libft.h"

static size_t	init_size(unsigned long long int n, int base)
{
	size_t	size;

	size = 3;
	while (n / base)
	{
		n /= base;
		size++;
	}
	return (size);
}

char			*ft_itoa_base_p(unsigned long long int n, int base)
{
	unsigned long long int		num;
	char						*str;
	size_t						size;
	char						*base_arr;

	size = init_size(n, base);
	num = n;
	if (!(str = (char*)ft_calloc(size + 1, sizeof(char))))
		return (str);
	*(str + 0) = '0';
	*(str + 1) = 'x';
	base_arr = "0123456789abcdef";
	while (size > 2)
	{
		*(str + --size) = *(base_arr + (num % base));
		num /= base;
	}
	return (str);
}
