# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 21:02:38 by dhaliti           #+#    #+#              #
#    Updated: 2022/04/20 15:05:01 by dhaliti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

CC 			= gcc
CFLAGS 			= -Wall -Wextra -Werror

SRCS	=	ft_isalnum.c \
			ft_isprint.c \
			ft_memcmp.c \
			ft_putchar_fd.c \
			ft_split.c \
			ft_strlcat.c \
			ft_strncmp.c \
			ft_substr.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_itoa.c \
			ft_memcpy.c \
			ft_putendl_fd.c \
			ft_strchr.c \
			ft_strlcpy.c \
			ft_strnstr.c \
			ft_tolower.c \
			ft_bzero.c \
			ft_isascii.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_putnbr_fd.c \
			ft_strdup.c \
			ft_strlen.c \
			ft_strrchr.c \
			ft_toupper.c \
			ft_calloc.c \
			ft_isdigit.c \
			ft_memchr.c \
			ft_memset.c \
			ft_putstr_fd.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strmapi.c \
			ft_strtrim.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_printf.c \
			c_format.c \
			u_format.c \
			i_d_format.c \
			x_format.c \
			p_format.c \
			s_format.c \
			get_next_line.c


OBJS			= $(SRCS:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS)
			@ar rcs $(NAME) $(OBJS)

clean:
			rm -f $(OBJS) $(BONUS_OBJS)

fclean:			clean
			@rm -f $(NAME)

re:			fclean $(NAME)

.PHONY:			all clean fclean re bonus
