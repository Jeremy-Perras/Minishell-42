/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:30:28 by jperras           #+#    #+#             */
/*   Updated: 2022/04/19 16:29:27 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <string.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <curses.h>
# include <term.h>
# include <signal.h>

char **env;
int g_status;

typedef struct s_minishell
{
	char	**path;
	char	**env;
	char	**flags;
	int		fd_in;
	int		fd_out;
	int		end[2];
	char	**input;
	char	**input2;
}		t_minishell;

typedef struct s_var
{
	char **var;
}		t_var;

/*
 * minishell.c
 */
void	ft_prompt();
/*
 * ----- buildin -----
 */
void	ft_buildin_cd(t_minishell *shell);
void	ft_buildin_echo(t_minishell *shell);
void	ft_buildin_pwd(t_minishell *shell);
void	ft_buildin_unset(t_minishell *shell);
void	ft_buildin_exit(t_minishell *shell);
void	ft_buildin_export(t_minishell *shell, char **env);
void	ft_buildin_env(t_minishell *shell);
/*
 * ----- src -----
 */

/*
 * signal.c
 */
void	sigint_handler(int sign_num);
/*
 * execve.c
 */
void	ft_exceve(char **input, char **env, t_minishell *shell);
/*
 * ft_parse.c
 */
void	ft_parse(char *buf, t_minishell *shell);
/*
 * ft_split2.c
 */
char	**ft_split2(char *str, char *charset);
/*
 * infile_outfile.c
 */
char	**ft_infile(char **input, t_minishell *shell);
void	ft_append(char **input, t_minishell *shell);
void	ft_redirect(char **input, t_minishell *shell);
char	**ft_flags(char **input, char **env, t_minishell *shell);
/*
 * pipex.c
 */
void	pipex(char *buf, t_minishell *shell, char **env);
/*
 * utils.c
 */
int		ft_strcmp(char *s1, char *s2);
char	*quote_ignore(char *input);
#endif
