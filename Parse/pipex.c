/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 09:51:17 by jperras           #+#    #+#             */
/*   Updated: 2022/04/16 20:09:40 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

/*********************************** CHILD ************************************/

static void	ft_child_process(char *argv, char **env, t_minishell *shell)
{
	close(shell->end[0]);
	if (shell->input)
	{
		int j = -1;
		while (shell->input[++j])
			free(shell->input[j]);
		free(shell->input);
	}
	if (shell->input2)
	{
		int k = -1;
		while (shell->input2[++k])
			free(shell->input2[k]);
		free(shell->input2);
	}
	int i = -1;
	shell->input = ft_split2(argv, " \t");
	shell->input2 = (char **)malloc(sizeof(char **) * 5);
	while (shell->input[++i])
		shell->input2[i] = quote_ignore(shell->input[i]);
	shell->input2[i] = NULL;
	//free(input);
	shell->input2 = ft_infile(shell->input2, shell);
	//printf("%s\n", input[0]);
	// if (ft_strcmp(input2[0], "cd")
	// 	ft_cd(input2, env, end);
	// else if (ft_strcmp(input2[0], "echo")
	// 	ft_echo(input2, env, end);
	// else if (ft_strcmp(input2[0], "env")
	// 	ft_env(input2, env, end);
	// else if (ft_strcmp(input2[0], "exit")
	// 	ft_exit(input2, env, end);
	// else if (ft_strcmp(input2[0], "export")
	// 	ft_export(input2, env, end);
	// else if (ft_strcmp(input2[0], "pwd")
	// 	ft_pwd(intput2, env, end);
	// else if (ft_strcmp(input2[0], "unset")
	// 	ft_unset(input2, env, end);
	//else
	ft_exceve(shell->input2, env, shell);
	exit(0);
}

/*********************************** PARENT ***********************************/

static void	ft_parent_process(t_minishell *shell)
{
	close(shell->end[1]);
	shell->fd_in = shell->end[0];
	wait(NULL);
}

/*********************************** PIPEX ************************************/

void	pipex(char *buf, t_minishell *shell, char **env)
{
	pid_t	parent;
	int		j;

	shell->fd_in = 0;
	j = -1;
	shell->path = ft_split(buf, '|');
	while (shell->path[++j])
	{
		pipe(shell->end);
		parent = fork();
		if (!parent)
		{
			if (shell->path[j + 1])
				dup2(shell->end[1], STDOUT_FILENO);
			ft_child_process(shell->path[j], env, shell);
		}
		else
			ft_parent_process(shell);
	}
}
