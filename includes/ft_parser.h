/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:35:30 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/16 16:59:37 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"
# include "ft_handlers.h"

void	ft_parser(const char *format, va_list ap);
int		ft_init_specifer(t_specifier **spec);
#endif
