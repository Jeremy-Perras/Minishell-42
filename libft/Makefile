# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swaegene <swaegene@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 12:33:22 by swaegene          #+#    #+#              #
#    Updated: 2022/02/28 12:17:38 by swaegene         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := gcc
CFLAGS := -Wall -Wextra -Werror

NAME := libft.a

SRCS := ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
		ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
		ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
		ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c \
		ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c 
OBJS := $(SRCS:.c=.o)
B_SRCS := ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
		ft_lstclear_bonus.c ft_lstdelone_bonus.c \
		ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c \
		ft_lstnew_bonus.c ft_lstsize_bonus.c
B_OBJS := $(B_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)

bonus: $(NAME) $(B_OBJS)
	@ar rcs $(NAME) $(B_OBJS)

clean:
	rm -f $(OBJS)
	rm -f $(B_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
