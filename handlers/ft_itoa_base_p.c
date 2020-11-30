/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 20:09:33 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/30 23:31:22 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handlers.h"
#include "libft.h"

static size_t	init_size(unsigned long long int n, int base)
{
	size_t	size;

	size = 2;//(n >= 0) ? 3 : 4;
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

char			*ft_itoa_base_p(unsigned long long int n, int base)
{
	unsigned long long int		num;
	char						*str;
	size_t						size;

	size = init_size(n, base);
	num = n;
	if (!(str = (char*)ft_calloc(size + 1, sizeof(char))))
		return (str);
	*(str + 0) = '0';
	*(str + 1) = 'x';
	while (size > 1)
	{
		*(str + --size) = select_digit(num % base);
		num /= base;
	}
	return (str);
}