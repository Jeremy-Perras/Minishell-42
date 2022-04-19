/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 09:51:17 by jperras           #+#    #+#             */
/*   Updated: 2022/04/19 17:53:16 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

/*********************************** CHILD ************************************/

static void	ft_child_process(t_minishell *shell, char *cmd)
{
	shell->input2 = ft_infile(shell->input2, shell);
	close(shell->end[0]);
	ft_exceve(shell->input2, shell, cmd);
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
	{
		path = ft_strdup("/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin:");
		path = ft_strjoin(path, "/usr/local/munki:/Library/Apple/usr/bin");
	}
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

	i = 0;
	mypath = ft_path(env);
	while (mypath[i])
	{
		cmd2 = ft_strjoin(mypath[i], cmd);
		if (access(cmd2, F_OK) == 0)
			return (cmd2);
		free(cmd2);
		i++;
	}
	write(2, "command not found\n", 18);
	free(env[0]);
	env[0] = ft_strdup(ft_itoa(127));
	return NULL;
}

static char	*ft_choose(t_minishell *shell, int *flag)
{
	*flag = 1;
	char *cmd;
	int i = 0;

	if (shell->input[i][0] == '<')
		i += 2;
	if (ft_strcmp(shell->input2[i], "cd"))
		ft_buildin_cd(shell);
	else if (ft_strcmp(shell->input2[i], "echo"))
		ft_buildin_echo(shell);
	else if (ft_strcmp(shell->input2[i], "exit"))
		ft_buildin_exit(shell);
	else if (ft_strcmp(shell->input2[i], "export"))
		ft_buildin_export(shell, env);
	else if (ft_strcmp(shell->input2[i], "pwd"))
		ft_buildin_pwd(shell);
	else if (ft_strcmp(shell->input2[i], "unset"))
		ft_buildin_unset(shell);
	else if (ft_strcmp(shell->input2[i], "env"))
		ft_buildin_env(shell);
	else
	{
		cmd = ft_cmd(shell->input2[i]);
		printf("%s\n", env[0]);
		if (cmd)
		{
			*flag = 0;
			return (cmd);
		}
		free(cmd);
	}
	return NULL;
}
/*********************************** PIPEX ************************************/

void	pipex(char *buf, t_minishell *shell)
{
	pid_t	parent;
	int		j;
	int		flag = 0;
	char	*cmd;

	shell->fd_in = 0;
	j = -1;
	shell->path = ft_split(buf, '|');
	while (shell->path[++j])
	{
		ft_clean(shell->path[j], shell);
		cmd = ft_choose(shell, &flag);
		if (flag == 0)
		{
			pipe(shell->end);
			parent = fork();
			if (!parent)
			{
				if (shell->path[j + 1])
					dup2(shell->end[1], STDOUT_FILENO);
				ft_child_process(shell, cmd);
			}
			else
				ft_parent_process(shell);
		}
	}
}
