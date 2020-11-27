/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:17:14 by dkenchur          #+#    #+#             */
/*   Updated: 2020/11/25 12:28:55 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HANDLERS_H
# define FT_HANDLERS_H
# include <stdarg.h>

typedef	unsigned int	t_bool;

typedef	struct			s_enum
{
	t_bool				zero;
	t_bool				minus;
	t_bool				star;
	t_bool				point;
	t_bool				c;
	t_bool				s;
	t_bool				p;
	t_bool				d;
	t_bool				i;
	t_bool				u;
	t_bool				x;
	t_bool				x_x;
}						t_enum;

typedef	struct			s_specifier
{
	t_enum				enumerate;
	int					width;
	int					precision;
	int					bytes_count;
}						t_specifier;
void					ft_modes(t_specifier *spec, va_list ap, char c);
void					ft_display_str(t_specifier *spec, va_list ap);
void					ft_display_chr(t_specifier *spec, va_list ap);
void					ft_display_d(t_specifier *spec, va_list ap);
#endif
