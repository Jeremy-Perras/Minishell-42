/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:30:28 by jperras           #+#    #+#             */
/*   Updated: 2022/04/09 10:53:36 by jperras          ###   ########.fr       */
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

typedef struct s_minishell
{
	char **path;





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











#endif
