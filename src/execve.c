/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:31:25 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/20 10:15:36 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

/*********************************** CHILD ************************************/

void	ft_child_process(t_minishell *shell, char *cmd)
{
	shell->input2 = ft_infile(shell->input2, shell);
	close(shell->end[0]);
	ft_exceve(shell->input2, shell, cmd);
	exit(0);
}

/*********************************** PARENT ***********************************/

void	ft_parent_process(t_minishell *shell)
{
	close(shell->end[1]);
	shell->fd_in = shell->end[0];
	wait(NULL);
}


static void ft_cat_redirect(char **input, t_minishell *shell)
{
	if (ft_strcmp(input[0], ">"))
	{
		printf("%s\n", input[1]);
		shell->fd_out = open(input[1], O_WRONLY | O_TRUNC | O_CREAT, 0664);
		printf("%d\n", shell->fd_out);
		dup2(shell->fd_out, STDOUT_FILENO);
	}
	if (ft_strcmp(input[0], ">>"))
	{
		shell->fd_out = open(input[1],  O_WRONLY | O_APPEND | O_CREAT, 0664);
		dup2(shell->fd_out, STDOUT_FILENO);
	}
}

static void ft_cat(char **input, t_minishell *shell, char *cmd)
{
	pid_t pid;

	shell->flags = (char **)malloc(sizeof(char **) * 5);
	shell->flags[0] = ft_strdup(input[0]);

	int i = 0;
	while (input[++i][0] == '-')
		shell->flags[i] = ft_strdup(input[i]);
	int j = -1;
	while (input[++j])
	{
		if (ft_strcmp(input[j], ">") || ft_strcmp(input[j], ">>"))
			ft_cat_redirect(input + j, shell);
	}
	while(input[i] && input[i][0] != '>')
	{
		pid = fork();
		if (!pid)
		{
			shell->fd_in = open(input[i], O_RDONLY);
			dup2(shell->fd_in, STDIN_FILENO);
			execve(cmd, shell->flags, env);
		}
		else
			wait(NULL);
		i++;
	}
}

/*********************************** EXECVE ***********************************/

void	ft_exceve(char **input, t_minishell *shell, char *cmd)
{
	if (ft_strcmp(input[0], "cat") && input[1])
		ft_cat(input, shell, cmd);
	else
	{
		ft_flags(input, shell);
		execve(cmd, shell->flags, env);
	}
}
