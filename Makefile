# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 19:56:41 by dkenchur          #+#    #+#              #
#    Updated: 2020/11/25 04:52:36 by dkenchur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

NAME		= libftprintf.a

LIBFTDIR	= libft/

PARSERDIR	= parser/

INCLUDES	= includes/

HANDLERSDIR	= handlers/

LIBNAME		= libft.a

SRCS		= ft_printf.c	$(PARSERDIR)ft_parser.c	$(PARSERDIR)ft_flags.c $(PARSERDIR)ft_init_specifier.c \
			  $(HANDLERSDIR)ft_display_str.c	$(HANDLERSDIR)ft_modes.c	$(HANDLERSDIR)ft_display_chr.c	\
			  $(PARSERDIR)ft_get_star_value.c

OBJS		= $(SRCS:.c=.o)
#gcc -I includes main.c -L. -lftprintf компиляция с либой
.c.o:		$(OBJS)
			$(CC) -I $(INCLUDES) -c $< -o $@

$(NAME):	$(OBJS)
			make -C $(LIBFTDIR)
			cp $(LIBFTDIR)$(LIBNAME) $(NAME)
			ar rc $(NAME) $(OBJS)
		
all:		$(NAME)

clean:
			make -C $(LIBFTDIR) clean
			rm -rf $(OBJS)

fclean:		clean
			make -C $(LIBFTDIR) fclean
			rm -rf $(NAME) $(LIBNAME)

re:			fclean all
