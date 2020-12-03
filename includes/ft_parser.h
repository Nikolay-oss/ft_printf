/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 15:35:30 by dkenchur          #+#    #+#             */
/*   Updated: 2020/12/03 03:17:33 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSER_H
# define FT_PARSER_H
# include "ft_handlers.h"

int		ft_parser(const char *format, t_specifier *spec);
void	ft_init_specifier(t_specifier *spec);
void	follow_line(char **str, t_specifier *spec);
void	ft_get_star_value(char c, int *i, t_specifier *spec);
int		isflags(char c);
int		ismodifer(char c);
#endif
