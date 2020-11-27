/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 07:07:28 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/25 07:36:55 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	init_size(int n, int base)
{
	size_t	size;

	size = (n >= 0) ? 1 : 2;
	while (n / base)
	{
		n /= base;
		size++;
	}
	return (size);
}

static	char	select_digit(int nbr)
{
	if (nbr == 10)
		return ('a');
	else if (nbr == 11)
		return ('b');
	else if (nbr == 12)
		return ('c');
	else if (nbr == 13)
		return ('d');
	else if (nbr == 14)
		return ('e');
	else if (nbr == 15)
		return ('f');
	return (nbr + '0');
}

char			*ft_itoa_base(int n, int base)
{
	long long int	num;
	char			*str;
	size_t			size;

	size = init_size(n, base);
	num = n;
	if (!(str = (char*)ft_calloc(size + 1, 1)))
		return (str);
	if (num < 0)
	{
		num *= -1;
		*str = '-';
	}
	while (size > 0)
	{
		*(str + --size) = select_digit(num % base);
		num /= base;
		if (*(str + size - 1) == '-' && size == 1)
			break ;
	}
	return (str);
}
