/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:05:34 by jperras           #+#    #+#             */
/*   Updated: 2022/04/20 13:54:38 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

static void	ft_buildin_echo2(t_minishell *shell);

static void	ft_buildin_redirect3(t_minishell *shell)
{
	shell->fd_out = open(shell->input2[3], \
		O_WRONLY | O_APPEND | O_CREAT, 0664);
	if (shell->fd_out < 0)
	{
		printf("%s: No such file or directory\n", shell->input[3]);
		return ;
	}
	if (!(strcmp(shell->input[2],"-n")))
		ft_putstr_fd(shell->input[2], shell->fd_out);
	else
	{
		ft_putstr_fd(shell->input[3], shell->fd_out);
		ft_putstr_fd("\n", shell->fd_out);
	}
}

static void	ft_buildin_redirect2(t_minishell *shell)
{
	if (ft_strcmp(shell->input[2], ">"))
	{
		shell->fd_out = open(shell->input[3], \
			O_WRONLY | O_TRUNC | O_CREAT, 0664);
		if (shell->fd_out < 0)
		{
			printf("%s: No such file or directory\n", shell->input[3]);
			return ;
		}
		printf("%s",shell->input[1]);
		if (strcmp(shell->input[1], "-n"))
			ft_putstr_fd(shell->input[3], shell->fd_out);
		else
		{
			ft_putstr_fd(shell->input[1], shell->fd_out);
			ft_putstr_fd("\n", shell->fd_out);
		}
	}
	if (ft_strcmp(shell->input[1], ">>"))
		ft_buildin_redirect3(shell);
}

void	ft_buildin_echo(t_minishell *shell)
{
	int	i;

	i = 0;
	if (ft_strcmp(shell->input[2], ">")
		|| ft_strcmp(shell->input[2], ">>"))
		ft_buildin_redirect2(shell);
	else if (!strncmp(shell->input2[1], "-n", 2))
	{
		if (shell->input[2])
		{
			while (shell->input2[2][i])
			{
				printf("%c", shell->input2[2][i]);
				i++;
			}
		}
	}
	else
		ft_buildin_echo2(shell);
	free(env[0]);
	env[0] = ft_strdup(ft_itoa(0));
}

static void	ft_buildin_echo2(t_minishell *shell)
{
	int	i;

	i = 0;
	if (shell->input2[1])
	{
		while (shell->input2[1][i])
		{
			printf("%c", shell->input2[1][i]);
			i++;
		}
	}
	printf("\n");
}
