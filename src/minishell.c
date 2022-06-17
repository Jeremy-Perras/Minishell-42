/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:03:00 by jperras           #+#    #+#             */
/*   Updated: 2022/05/24 18:13:52 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

static void	ft_init(t_minishell **shell, char **envp)
{
	int	i;

	i = 0;
	*shell = (t_minishell *)malloc(sizeof(t_minishell));
	while (envp[i])
		i++;
	(*shell)->env = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (envp[++i])
		(*shell)->env[i] = ft_strdup(envp[i]);
	(*shell)->env[i] = NULL;
	(*shell)->path = NULL;
	(*shell)->flags = NULL;
	(*shell)->input = NULL;
	(*shell)->input2 = NULL;
	(*shell)->fd_in = 0;
	(*shell)->fd_out = 0;
	(*shell)->quote_pipe = 0;
	(*shell)->status = 0;
}

static void	ft_free_shell2(t_minishell *shell)
{
	int	i;

	shell->fd_in = 0;
	shell->fd_out = 0;
	shell->quote_pipe = 0;
	shell->status = 0;
	i = -1;
	if (shell->flags)
	{
		while (shell->flags && shell->flags[++i])
			free(shell->flags[i]);
	}
	free (shell->flags);
}

void	ft_free_shell(t_minishell *shell)
{
	int	i;
	int	j;

	i = -1;
	if (shell->path)
	{
		while (shell->path && shell->path[++i])
			free (shell->path[i]);
		free(shell->path);
		shell->path = NULL;
	}
	if (shell->input)
	{
		j = -1;
		while (shell->input && shell->input[++j])
			free(shell->input[j]);
		free(shell->input);
		shell->input = NULL;
	}
	j = 2;
	while (++j < 100)
		close(j);
	ft_free_shell2(shell);
}

void	ft_prompt(char **envp)
{
	char		*buf;
	t_minishell	*shell;

	signal(SIGQUIT, sigint_handler);
	signal(SIGINT, sigint_handler);
	buf = readline("\033[0;36mMinishell $> \e[0m");
	ft_init(&shell, envp);
	while (buf != NULL)
	{
		if (*buf)
			add_history(buf);
		ft_parse(buf, shell);
		ft_free_shell(shell);
		free(buf);
		buf = readline("\033[0;36mMinishell $> \e[0m");
	}
	ft_free_shell(shell);
}

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	g_st = 0;
	ft_prompt(envp);
}
