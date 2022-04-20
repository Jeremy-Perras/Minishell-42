# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jperras <jperras@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/08 13:14:04 by jperras           #+#    #+#              #
#    Updated: 2022/04/20 10:49:34 by dhaliti          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
BLU			= \033[0;34m
GRN			= \033[0;32m
RED			= \033[0;31m
RST			= \033[0m
END			= \e[0m

SRCS =  minishell.c cd.c echo.c \
		exit.c pwd.c unset.c pipex.c signal.c execve.c env.c\
		ft_parse.c ft_split2.c infile_outfile.c utils.c export.c cat.c
NAME		= minishell
OBJS_DIR	= objs/
OBJS		= $(SRCS:.c=.o)
OBJECTS_PREFIXED = $(addprefix $(OBJS_DIR), $(OBJS))
CC			= gcc
CC_FLAGS	= -Wall -Werror -Wextra

$(OBJS_DIR)%.o : %.c
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)srcs
	@$(CC) $(CC_FLAGS) -c $< -o $@
	@printf	"\033[2K\r${BLU}[BUILD]${RST} '$<' $(END)"

$(NAME): $(OBJECTS_PREFIXED) maker
	@$(CC) -o $(NAME) $(OBJECTS_PREFIXED) $(CC_FLAGS) ../libft/libft.a  -lreadline -L .brew/opt/readline/lib -I .brew/opt/readline/include
	@printf "\033[2K\r\033[0;32m[END]\033[0m $(NAME)$(END)\n"

all: $(NAME)

maker:
	@make -C ../libft

clean:
	@make clean -C ../libft
	@rm -rf $(OBJS_DIR)
	@printf "\033[2K\r${GRN}[CLEAN]${RST} done$(END)"

fclean: clean
	@make fclean -C ../libft
	@rm -f $(NAME)
	@printf "\033[2K\r${GRN}[FCLEAN]${RST} done$(END)"

re: fclean all

.PHONY:		all clean fclean re



# NAME = minishell
#
# SRCS =  minishell.c buildin/cd.c buildin/echo.c \
# 		buildin/exit.c buildin/pwd.c buildin/unset.c src/pipex.c src/signal.c src/execve.c buildin/env.c\
# 		src/ft_parse.c src/ft_split2.c src/infile_outfile.c src/utils.c buildin/export.c
#
# FLAGS = -Wall -Werror -Wextra
#
# CC = gcc
#
# CCDB = gcc -g
#
# LIB = -lreadline -lcurses
#
# LIBFT = -L libft -lft
#
# INCLUDES = -I./includes
#
# OBJS = ${SRCS:.c=.o}
#
# .c.o:
# 		${CC} ${FLAGS} -I./includes  -c $< -o ${<:.c=.o}
#
# $(NAME) : $(OBJS)
# 	make -C libft
# 	$(CC) $(FLAGS) -o $(NAME) $(LIB) $(LIBFT) $(INCLUDES) $(OBJS)
#
# all : $(NAME)
#
# test:
# 	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
#
# debug:
# 	$(CC) $(FLAGS) -o $(NAME) $(LIBFT) $(LIB) $(INCLUDES) $(SRCS)
#
# clean :
# 	make clean -C libft
# 	rm -rf $(OBJS)
#
# fclean : clean
# 	make fclean -C libft
# 	rm -rf $(NAME)
#
# re : fclean all
#
# .PHONY : all bonus clean fclean re
