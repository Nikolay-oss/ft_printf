/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:35:30 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/30 20:29:32 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"
# include "ft_handlers.h"

int		ft_parser(const char *format, t_specifier *spec);
void	ft_init_specifer(t_specifier *spec);
char	*ft_flags(const char *str, t_specifier *spec);
void	ft_get_star_value(char c, int *i, t_specifier *spec);
int		isflags(char c);
int		ismodifer(char c);
#endif
