/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:14:15 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/16 18:17:54 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(const char *str, size_t n)
{
	size_t	i;

	if (!str)
		return ;
	i = 0;
	while (*(str + i) && i < n)
		write(1, str + i++, 1);
}
