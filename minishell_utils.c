/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 09:51:17 by jperras           #+#    #+#             */
/*   Updated: 2022/04/09 15:45:51 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	ft_child_process(char *argv, char **env, int *end)
{
	char	**flag;

	close(end[0]);
	flag = ft_split(argv, ' ');
	execve(ft_cmd(flag[0], env), flag, env);
}

void	ft_parent_process(int *end, int *fd)
{
	dup2(end[1], STDOUT_FILENO);
	close(end[1]);
	*fd = end[0];
	wait(NULL);
}

char	**ft_path(char **env)
{
	size_t	i;
	char	*path;
	char	**mypath;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
	{
		write(2, "Path not found\n", 15);
		exit(1);
	}
	path = env[i] + 5;
	mypath = ft_split(path, ':');
	i = 0;
	while (mypath[i])
	{
		tmp = mypath[i];
		mypath[i] = ft_strjoin(mypath[i], "/");
		free(tmp);
		i++;
	}
	return (mypath);
}

char	*ft_cmd(char *comd, char **env)
{
	char	**mypath;
	char	*cmd;
	int		i;

	i = 0;
	mypath = ft_path(env);
	while (mypath[i])
	{
		cmd = ft_strjoin(mypath[i], comd);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		free(cmd);
		i++;
	}
	write(2, "command not found\n", 18);
	exit(1);
}

void	pipex(t_minishell *shell, char **env)
{
	pid_t	parent;
	int		end[2];
	int		j;
	int		fd;

	j = 0;
	fd = 0;
	while (shell->path[j])
	{
		pipe(end);
		parent = fork();
		if (!parent)
		{
			dup2(end[0], STDIN_FILENO);
			//if (!shell->path[j + 1])
			//	dup2(end[1], STDOUT_FILENO);
			ft_child_process(shell->path[j], env, end);
		}
		else
			ft_parent_process(end, &fd);
		j++;
	}
}
