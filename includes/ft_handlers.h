/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handlers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 13:17:14 by dkenchur          #+#    #+#             */
/*   Updated: 2020/12/03 03:20:35 by dkenchur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HANDLERS_H
# define FT_HANDLERS_H
# include <stdarg.h>
# include "libft.h"
# define FLG_NONE	0b00000000
# define FLG_MINUS	0b00000001
# define FLG_POINT	0b00000010
# define FLG_STAR	0b00000100
# define FLG_ZERO	0b00001000

typedef	struct			s_specifier
{
	va_list				ap;
	unsigned int		flags;
	int					width;
	int					precision;
	int					bytes_count;
}						t_specifier;

void					ft_modes(t_specifier *spec, char c);
void					ft_display_str(t_specifier *spec);
void					ft_display_chr(t_specifier *spec);
void					ft_display_d(t_specifier *spec);
void					ft_display_x(t_specifier *spec, int flag);
void					ft_display_p(t_specifier *spec);
void					ft_display_u(t_specifier *spec);
void					ft_display_special(t_specifier *spec, char *str);
void					ft_select_flag(char c, t_specifier *spec);
char					*ft_itoa_base_x(unsigned int n, int base);
char					*ft_itoa_base_p(unsigned long long int n, int base);
void					minus_handler(t_specifier *spec, char *nbr, int width,
							int precision);
void					choose_direction(t_specifier *spec, char *nbr,
							int nbr_size, int pflag);
void					ft_disp(t_specifier *spec, char *nbr, int precision);
#endif
