/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:30:28 by jperras           #+#    #+#             */
/*   Updated: 2022/04/12 16:39:39 by jperras          ###   ########.fr       */
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

typedef struct s_minishell
{
	char **path;
	char ***env;





} t_minishell;



/*
 *minishell_utils.c
 *
 */
char	**ft_path(char **env);
char	*ft_cmd(char *comd, char **env);
void	pipex(t_minishell *shell, char **env);
void	ft_child_process(char *argv, char **env, int *end);
void	ft_parent_process(int *end, int *fd);
/*
 *minishell_utils1.c
 *
 */
void ft_build_in(char *buf, t_minishell *shell);








#endif
