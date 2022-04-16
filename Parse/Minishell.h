/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:30:28 by jperras           #+#    #+#             */
/*   Updated: 2022/04/16 19:52:40 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include"../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include<readline/readline.h>
# include<readline/history.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <curses.h>
# include <term.h>
# include <signal.h>
# include <stdio.h>

typedef struct s_minishell
{
	char **path;
	char **env;
	char **flags;
	int fd_in;
	int fd_out;
	int end[2];
	char **input;
	char **input2;
} t_minishell;

/*
 *minishell_utils.c
 *
 */
// char	**ft_path(char **env);
// char	*ft_cmd(char *comd, char **env);
void	pipex(char *buf, t_minishell *shell, char **env);
// void	ft_child_process(char *argv, char **env, int *end);
// void	ft_parent_process(int *end, int *fd);
char	**ft_split2(char *str, char *charset);
void 	ft_parse(char *buf, t_minishell *shell);
void 	ft_exceve(char **input, char **env, t_minishell *shell);
char 	**ft_flags(char **input, char **env, t_minishell *shell);
char 	**ft_infile(char **input, t_minishell *shell);
void 	ft_redirect(char **input, t_minishell *shell);

void 	ft_append(char **input, t_minishell *shell);
int		ft_strcmp(char *s1, char *s2);
char 	*quote_ignore(char *input);
/*
 *minishell_utils1.c
 *
 */
//void ft_build_in(char *buf, t_minishell *shell);
//void		sigint_handler(int sign_num);







#endif
