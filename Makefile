# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperras <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/08 13:14:04 by jperras           #+#    #+#              #
#    Updated: 2022/04/08 16:15:21 by jperras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = minishell

SRCS = get_next_line.c get_next_line_utils.c minishell.c 

FLAGS = -Wall -Werror -Wextra 

CC = gcc

CCDB = gcc -g

LIB = -lreadline

LIBFT = -L libft -lft

INCLUDES = -I./includes

OBJS = ${SRCS:.c=.o}

.c.o:
		${CC} ${FLAGS} -I./includes  -c $< -o ${<:.c=.o}

$(NAME) : $(OBJS)
	make -C libft
	$(CC) $(FLAGS) -o $(NAME) $(LIB) $(LIBFT) $(INCLUDES) $(OBJS)

all : $(NAME)

test:
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)

debug:
	$(CC $(FLAGS) -o $(NAME) $(LIBFT) $(LIB) $(INCLUDES) $(SRCS)

clean :
	make clean -C libft
	rm -rf $(OBJS)

fclean : clean
	make fclean -C libft
	rm -rf $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re