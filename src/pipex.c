/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 09:51:17 by jperras           #+#    #+#             */
/*   Updated: 2022/04/19 12:51:58 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

/*********************************** CHILD ************************************/

static void	ft_child_process(char **env, t_minishell *shell)
{
	shell->input2 = ft_infile(shell->input2, shell);
	close(shell->end[0]);
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
/*********************************** CLEAN ***********************************/

static void	ft_clean(char *argv, t_minishell *shell)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	if (shell->input)
	{
		while (shell->input[++j])
			free(shell->input[j]);
		free(shell->input);
	}
	// if (shell->input2)
	// {
	// 	int k = -1;
	// 	while (shell->input2[++k])
	// 		free(shell->input2[k]);
	// 	free(shell->input2);
	// }
	shell->input = ft_split2(argv, " \t");
	shell->input2 = (char **)malloc(sizeof(char **) * 5);
	while (shell->input[++i])
		shell->input2[i] = quote_ignore(shell->input[i]);
	shell->input2[i] = NULL;
}
/********************************** CHOOSE **********************************/

static void	ft_choose(t_minishell *shell, int *flag, char **env)
{
	*flag = 1;

	if (ft_strcmp(shell->input2[0], "cd"))
		ft_buildin_cd(shell);
	else if (ft_strcmp(shell->input2[0], "echo"))
		ft_buildin_echo(shell);
	else if (ft_strcmp(shell->input2[0], "exit"))
		ft_buildin_exit(shell);
	else if (ft_strcmp(shell->input2[0], "export"))
		ft_buildin_export(shell, env);
	else if (ft_strcmp(shell->input2[0], "pwd"))
		ft_buildin_pwd(shell);
	else if (ft_strcmp(shell->input2[0], "unset"))
		ft_buildin_unset(shell);
	else if (ft_strcmp(shell->input2[0], "env"))
		ft_buildin_env(shell);
	else
		*flag = 0;
}
/*********************************** PIPEX ************************************/

void	pipex(char *buf, t_minishell *shell, char **env)
{
	pid_t	parent;
	int		j;
	int		flag = 0;

	shell->fd_in = 0;
	j = -1;
	shell->path = ft_split(buf, '|');
	while (shell->path[++j])
	{
		ft_clean(shell->path[j], shell);
		ft_choose(shell, &flag, env);
		if (flag == 0)
		{
			pipe(shell->end);
			parent = fork();
			if (!parent)
			{
				if (shell->path[j + 1])
					dup2(shell->end[1], STDOUT_FILENO);
				ft_child_process(env, shell);
			}
			else
				ft_parent_process(shell);
		}
	}
}
