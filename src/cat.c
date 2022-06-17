/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:42:30 by dhaliti           #+#    #+#             */
/*   Updated: 2022/05/23 20:20:52 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

/************************************ CAT *************************************/

static int	ft_cat_redirect(char **input, t_minishell *shell)
{
	if (ft_strcmp(input[0], ">"))
	{
		shell->fd_out = open(input[1], O_WRONLY | O_TRUNC | O_CREAT, 0664);
		if (shell->fd_out < 0)
		{
			printf("%s: file could not be found or created\n", input[1]);
			exit(0);
		}
		dup2(shell->fd_out, STDOUT_FILENO);
	}
	if (ft_strcmp(input[0], ">>"))
	{
		shell->fd_out = open(input[1], O_WRONLY | O_APPEND | O_CREAT, 0664);
		if (shell->fd_out < 0)
		{
			printf("%s: file could not be found or created\n", input[1]);
			exit(0);
		}
		dup2(shell->fd_out, STDOUT_FILENO);
	}
	return (1);
}

static void	ft_execve_cat(char **input, t_minishell *shell, char *cmd)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (input[i] && input[i][0] != '>')
	{
		pid = fork();
		if (!pid)
		{
			shell->fd_in = open(input[i], O_RDONLY);
			if (shell->fd_in < 0)
			{
				printf("%s: No such file or directory\n", input[i]);
				exit(0);
			}
			dup2(shell->fd_in, STDIN_FILENO);
			execve(cmd, shell->flags, shell->env);
		}
		else
			wait(NULL);
		i++;
	}
}

void	ft_cat(char **input, t_minishell *shell, char *cmd)
{
	int		i;
	int		j;

	shell->flags = (char **)malloc(sizeof(char **) * 5);
	shell->flags[0] = ft_strdup(input[0]);
	i = 0;
	while (input[++i][0] == '-')
		shell->flags[i] = ft_strdup(input[i]);
	shell->flags[i] = NULL;
	j = -1;
	while (*input && input[++j])
	{
		if (ft_strcmp(input[j], ">") || ft_strcmp(input[j], ">>"))
			ft_cat_redirect(input + j, shell);
	}
	ft_execve_cat(input + i, shell, cmd);
}
