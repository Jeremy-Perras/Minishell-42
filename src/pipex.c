/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 09:51:17 by jperras           #+#    #+#             */
/*   Updated: 2022/04/17 15:52:57 by jperras          ###   ########.fr       */
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
	shell->input2 = ft_infile(shell->input2, shell);
	if (ft_strcmp(shell->input2[0], "cd"))
		ft_buildin_cd(shell);
	 else if (ft_strcmp(shell->input2[0], "echo"))
	 	ft_buildin_echo(shell);
	 else if (ft_strcmp(shell->input2[0], "exit"))
	 	ft_buildin_exit(shell);
	 else if (ft_strcmp(shell->input2[0], "export"))
	 	ft_buildin_export(shell);
	 else if (ft_strcmp(shell->input2[0], "pwd"))
	 	ft_buildin_pwd(shell);
	 else if (ft_strcmp(shell->input2[0], "unset"))
	 	ft_buildin_unset(shell);
	else
		ft_exceve(shell->input2, env, shell);
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
