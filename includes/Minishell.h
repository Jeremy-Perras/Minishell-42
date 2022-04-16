/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:30:28 by jperras           #+#    #+#             */
/*   Updated: 2022/04/16 11:38:31 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINISHELL_H
# define MINISHELL_H
# include"../libft/libft.h"
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
typedef void (*t_cho)(char *buf);

int	g_status;

typedef struct s_minishell
{
	char **path;
	char ***env;





} t_minishell;
/*
 * ----- buildin -----
 */
void	ft_buildin_cd(char *buf, t_minishell *shell);
void	ft_buildin_echo(char * buf, t_minishell *shell);
void	ft_buildin_pwd(char *buf, t_minishell *shell);
void	ft_buildin_unset(char *buf, t_minishell *shell);
void	ft_buildin_exit(char *buf, t_minishell);

/*
 * ----- src -----
 */

/*
 * pipex.c
 */
char	**ft_path(char **env);
char	*ft_cmd(char *comd, char **env);
void	pipex(t_minishell *shell, char **env);
void	ft_child_process(char *argv, char **env, int *end);
void	ft_parent_process(int *end, int *fd);
/*
 * signal.c
 */
void		sigint_handler(int sign_num);
#endif
