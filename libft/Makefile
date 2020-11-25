# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dkenchur <dkenchur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/04 06:46:45 by dkenchur          #+#    #+#              #
#    Updated: 2020/11/25 03:57:16 by dkenchur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

NAME		= libft.a

INCLUDES	= ../includes/

SRCS		= 	ft_memset.c \
				ft_bzero.c \
				ft_memcpy.c \
				ft_memccpy.c \
				ft_memmove.c \
				ft_strlen.c	\
				ft_tolower.c	\
				ft_toupper.c	\
				ft_strjoin.c	\
				ft_memchr.c	\
				ft_memcmp.c	\
				ft_isalpha.c	\
				ft_isdigit.c	\
				ft_isalnum.c	\
				ft_isascii.c	\
				ft_isprint.c	\
				ft_strlcpy.c	\
				ft_strlcat.c	\
				ft_strdup.c	\
				ft_strchr.c	\
				ft_strrchr.c	\
				ft_strncmp.c	\
				ft_calloc.c	\
				ft_strnstr.c	\
				ft_atoi.c	\
				ft_putchar_fd.c	\
				ft_putstr_fd.c	\
				ft_putendl_fd.c	\
				ft_putnbr_fd.c	\
				ft_substr.c	\
				ft_strtrim.c	\
				ft_strmapi.c	\
				ft_itoa.c	\
				ft_split.c	\
				ft_lstnew.c	\
				ft_lstadd_back.c	\
				ft_lstadd_front.c \
				ft_lstclear.c \
				ft_lstdelone.c \
				ft_lstiter.c	\
				ft_lstlast.c	\
				ft_lstsize.c	\
				ft_lstmap.c		\
				ft_putstr.c		\
				ft_putnstr.c	\
				ft_putchar.c	\
				ft_putlstr.c	\
				ft_repeat_symb.c

CFLAGS		= -Wall -Wextra -Werror

OBJS		= $(SRCS:.c=.o)

.c.o:
			$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $@

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

all:		$(NAME)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all
