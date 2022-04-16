/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:31:25 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/16 11:45:41 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"


/******************************** EVECVE UTILS ********************************/

static char	**ft_path(char **env)
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
		path = ft_strdup("/usr/local/bin:/usr/bin:/bin:/usr/sbin:";
		path = ft_strjoin(path, "/sbin:/usr/local/munki:/Library/Apple/usr/bin");
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

static char	*ft_cmd(char *cmd, char **env)
{
	char	**mypath;
	char	*cmd;
	int		i;

	i = 0;
	mypath = ft_path(env);
	while (mypath[i])
	{
		cmd = ft_strjoin(mypath[i], cmd);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		free(cmd);
		i++;
	}
	write(2, "command not found\n", 18);
	exit(1);
}

/*********************************** EXECVE ***********************************/

void ft_exceve(char **input, char **env, t_minishell *shell)
{
	shell->args = ft_args(input, env, shell);
	execve(ft_cmd(input[0], env), shell->args, env);
}
