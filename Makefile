# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperras <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/08 13:14:04 by jperras           #+#    #+#              #
#    Updated: 2022/04/16 11:34:45 by jperras          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = minishell

SRCS =  minishell.c minishell_utils1.c minishell_utils2.c buildin/cd.c buildin/echo.c \ 
		buildin/exit.c buildin/pwd.c buidlin/unset.c src/pipex.c src/signal.c

FLAGS = -Wall -Werror -Wextra 

CC = gcc

CCDB = gcc -g

LIB = -lreadline -lcurses

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
	$(CC) $(FLAGS) -o $(NAME) $(LIBFT) $(LIB) $(INCLUDES) $(SRCS)

clean :
	make clean -C libft
	rm -rf $(OBJS)

fclean : clean
	make fclean -C libft
	rm -rf $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
