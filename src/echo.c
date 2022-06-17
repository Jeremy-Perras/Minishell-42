/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:05:34 by jperras           #+#    #+#             */
/*   Updated: 2022/05/24 19:07:51 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

static void	ft_print_echo(char **args, int fd, int flag)
{
	int	i;
	int	j;

	i = -1;
	if (ft_strcmp(args[0], "$?"))
	{
		printf("%d\n", g_st);
		return ;
	}
	while (args && args[++i])
	{
		j = -1;
		while (args[i][++j])
		{
			if (args[i][j] != '\"' && args[i][j] != '\'')
				ft_putchar_fd(args[i][j], fd);
		}
		if (args && args[i + 1])
			ft_putchar_fd(' ', fd);
	}
	if (!flag)
		ft_putchar_fd('\n', fd);
}

static void	ft_redirect_echo(char **input, t_minishell *shell,
		int flag, char **args)
{
	if (ft_strcmp(input[0], ">"))
	{
		shell->fd_out = open(input[1], \
			O_WRONLY | O_TRUNC | O_CREAT, 0664);
		if (shell->fd_out < 0)
		{
			printf("%s: No such file or directory\n", input[1]);
			exit(1);
		}
		ft_print_echo(args, shell->fd_out, flag);
	}
	if (ft_strcmp(input[0], ">>"))
	{
		shell->fd_out = open(input[1], \
			O_WRONLY | O_APPEND | O_CREAT, 0664);
		if (shell->fd_out < 0)
		{
			printf("%s: No such file or directory\n", input[1]);
			exit(1);
		}
		ft_print_echo(args, shell->fd_out, flag);
	}
}

static void	ft_free_args(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
		free(args[i]);
	free(args);
}

void	ft_buildin_echo(char *buf, t_minishell *shell)
{
	int		flag;
	int		i;
	int		j;
	char	*args[10];
	char	**input;

	flag = 0;
	input = ft_split2(buf, "\t ");
	i = 0;
	if (ft_strcmp(input[1], "-n"))
	{
		flag = 1;
		i++;
	}
	j = -1;
	while (input[++i] && input[i][0] != '>')
		args[++j] = ft_strdup(input[i]);
	args[j + 1] = NULL;
	if (input[i] && input[i][0] == '>')
		ft_redirect_echo(input + i, shell, flag, args);
	else
		ft_print_echo(args, STDOUT_FILENO, flag);
	g_st = 0;
}

void	ft_buildin_echo2(char **input, t_minishell *shell)
{
	int		flag;
	int		i;
	int		j;
	char	**args;

	flag = 0;
	args = (char **)malloc(sizeof(char **) * 10);
	i = 0;
	if (ft_strcmp(input[1], "-n"))
	{
		flag = 1;
		i++;
	}
	j = -1;
	while (input[++i] && input[i][0] != '>')
		args[++j] = ft_strdup(input[i]);
	args[j + 1] = NULL;
	if (input[i] && input[i][0] == '>')
		ft_redirect_echo(input + i, shell, flag, args);
	else
		ft_print_echo(args, STDOUT_FILENO, flag);
	ft_free_args(args);
	exit(0);
}
