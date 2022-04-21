/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 09:51:17 by jperras           #+#    #+#             */
/*   Updated: 2022/04/21 15:35:35 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

/*********************************** CLEAN ***********************************/

static int	ft_clean(char *argv, t_minishell *shell)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	shell->input = ft_split2(argv, " \t");
	if (!*(shell->input))
		return (0);
	shell->input2 = (char **)malloc(sizeof(char **) * 5);
	while (shell->input[++i])
		shell->input2[i] = quote_ignore(shell->input[i]);
	shell->input2[i] = NULL;
	return (1);
}
/*********************************** FT_CMD ***********************************/

static char	**ft_path(char **env)
{
	size_t	i;
	char	*path;
	char	**mypath;
	char	*tmp;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (NULL);
	else
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

static char	*ft_cmd(char *cmd)
{
	char	**mypath;
	char	*cmd2;
	int		i;

	if (cmd[0] == '/')
		return (ft_strdup(cmd));
	i = 0;
	mypath = ft_path(g_env);
	while (mypath && mypath[i])
	{
		cmd2 = ft_strjoin(mypath[i], cmd);
		if (access(cmd2, F_OK) == 0)
		{
			ft_free_mypath(mypath);
			return (cmd2);
		}
		free(cmd2);
		i++;
	}
	ft_free_mypath(mypath);
	printf("%s: Command not found\n", cmd);
	free(g_env[0]);
	g_env[0] = ft_strdup(ft_itoa(127));
	return (NULL);
}

/*********************************** CHOOSE ***********************************/

static char	*ft_choose(t_minishell *shell)
{
	int	i;

	if (ft_check_files(shell))
		return (NULL);
	i = 0;
	if (shell->input[i][0] == '<')
		i += 2;
	if (ft_strcmp(shell->input2[i], "cd"))
		ft_buildin_cd(shell);
	else if (ft_strcmp(shell->input2[i], "exit"))
		ft_buildin_exit(shell);
	else if (ft_strcmp(shell->input2[i], "export"))
		ft_buildin_export(shell);
	else if (ft_strcmp(shell->input2[i], "pwd"))
		ft_buildin_pwd(shell);
	else if (ft_strcmp(shell->input2[i], "unset"))
		ft_buildin_unset(shell);
	else
		return (ft_cmd(shell->input2[i]));
	return (NULL);
}
/*********************************** PIPEX ************************************/

void	pipex(char *buf, t_minishell *shell)
{
//	pid_t	parent;
	int		j;
	char	*cmd;

	j = -1;
	shell->path = ft_split(buf, '|');
	while (shell->path[++j])
	{
		if (!ft_clean(shell->path[j], shell))
			return ;
		cmd = ft_choose(shell);
		if (cmd)
		{
			pipe(shell->end);
		//	parent = fork();
			if (fork() == 0)
			{
				if (shell->path[j + 1])
					dup2(shell->end[1], STDOUT_FILENO);
				ft_child_process(shell, cmd);
			}
			else
				ft_parent_process(shell);
		}
		free (cmd);
	}
}
