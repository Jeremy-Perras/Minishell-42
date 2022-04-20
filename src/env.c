/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:37:11 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/20 15:34:49 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

static void	ft_buildin_env3(t_minishell *shell)
{
	int	i;

	i = 0;
	shell->fd_out = open(shell->input2[2], \
		O_WRONLY | O_APPEND | O_CREAT, 0664);
	if (shell->fd_out < 0)
	{
		free(g_env[0]);
		g_env[0] = ft_strdup(ft_itoa(1));
		printf("%s: No such file or directory\n", shell->input2[2]);
		return ;
	}
	while (g_env[++i])
	{
		ft_putstr_fd(g_env[i], shell->fd_out);
		ft_putstr_fd("\n", shell->fd_out);
	}
}

static void	ft_buildin_env2(t_minishell *shell)
{
	int	i;

	i = 0;
	if (ft_strcmp(shell->input[1], ">"))
	{
		shell->fd_out = open(shell->input2[2], \
			O_WRONLY | O_TRUNC | O_CREAT, 0664);
		if (shell->fd_out < 0)
		{
			free(g_env[0]);
			g_env[0] = ft_strdup(ft_itoa(1));
			printf("%s: No such file or directory\n", shell->input2[2]);
			return ;
		}
		while (g_env[++i])
		{
			ft_putstr_fd(g_env[i], shell->fd_out);
			ft_putstr_fd("\n", shell->fd_out);
		}
	}
	if (ft_strcmp(shell->input[1], ">>"))
		ft_buildin_env3(shell);
}

void	ft_buildin_env(t_minishell *shell)
{
	int	i;

	i = 0;
	if (shell->input2[1])
	{
		if (ft_strcmp(shell->input[1], ">")
			|| ft_strcmp(shell->input[1], ">>"))
			ft_buildin_env2(shell);
	}
	else
	{
		while (g_env[++i])
			printf("%s\n", g_env[i]);
	}
	free(g_env[0]);
	g_env[0] = ft_strdup(ft_itoa(0));
}
