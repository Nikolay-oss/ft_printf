# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/18 19:56:41 by dkenchur          #+#    #+#              #
#    Updated: 2020/12/01 00:19:41 by dkenchur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

NAME		= libftprintf.a

LIBFTDIR	= libft/

PARSERDIR	= parser/

INCLUDES	= includes/

HANDLERSDIR	= handlers/

LIBFT		= libft.a

SRCS		= ft_printf.c						$(PARSERDIR)ft_parser.c			$(PARSERDIR)ft_flags.c \
			  $(HANDLERSDIR)ft_display_str.c	$(HANDLERSDIR)ft_modes.c		$(PARSERDIR)ft_init_specifier.c \
			  $(PARSERDIR)ft_get_star_value.c	$(HANDLERSDIR)ft_display_d.c	$(HANDLERSDIR)ft_display_chr.c \
			  $(HANDLERSDIR)ft_display_x.c		$(HANDLERSDIR)ft_itoa_base_p.c	$(HANDLERSDIR)ft_itoa_base_x.c \
			  $(HANDLERSDIR)ft_display_p.c		$(HANDLERSDIR)ft_display_u.c

OBJS		= $(SRCS:.c=.o)

GREEN		= \033[0;32m

RED			= \033[0;31m

RESET		= \033[0m
#gcc -I includes main.c -L. -lftprintf компиляция с либой
# add CFLAGS!
%.o:	%.c
			@$(CC) -I $(INCLUDES) -c $< -o $@

$(NAME):	$(OBJS)
			@make -C $(LIBFTDIR)
			@cp $(LIBFTDIR)$(LIBFT) $(NAME)
			@ar rcs $(NAME) $(OBJS)
			@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"
		
all:		$(NAME)

clean:
			@make -C $(LIBFTDIR) clean
			@rm -rf $(OBJS)
			@echo "$(LIBFT): $(RED)object files were deleted$(RESET)"
			@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean:		clean
			@make -C $(LIBFTDIR) fclean
			@echo "$(LIBFT): $(RED)$(LIBFT) was deleted$(RESET)"
			@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
			@rm -rf $(NAME) $(LIBFT)

re:			fclean all
