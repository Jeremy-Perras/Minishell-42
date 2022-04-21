/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:03:00 by jperras           #+#    #+#             */
/*   Updated: 2022/04/21 12:09:33 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

static void	ft_init(t_minishell **shell)
{
	*shell = (t_minishell *)malloc(sizeof(t_minishell));
	(*shell)->env = g_env;
	(*shell)->path = NULL;
	(*shell)->flags = NULL;
	(*shell)->input = NULL;
	(*shell)->input2 = NULL;
	(*shell)->fd_in = 0;
	(*shell)->fd_out = 0;
}

static void	ft_free_shell(t_minishell *shell)
{
	int	i;
	int	j;

	i = -1;
	if (shell->path)
	{
		while (shell->path[++i])
			free (shell->path[i]);
		free(shell->path);
	}
	if (shell->input)
	{
		j = -1;
		while (shell->input[++j])
			free(shell->input[j]);
		free(shell->input);
	}
	if (shell->input2)
		free(shell->input2);
	j = 2;
	while (++j < 100)
		close(j);
	free(shell);
}

void	ft_prompt(void)
{
	char		*buf;
	t_minishell	*shell;

	signal(SIGKILL, sigint_handler);
	signal(SIGINT, sigint_handler);
	buf = readline("\033[0;36mMinishell $> \e[0m");
	while (buf != NULL)
	{
		ft_init(&shell);
		if (*buf)
			add_history(buf);
		ft_parse(buf, shell);
		ft_free_shell(shell);
		free(buf);
		buf = readline("\033[0;36mMinishell $> \e[0m");
	}
}

static char	**ft_env(char **envp)
{
	int	i;
	int	j;

	i = -1;
	while (envp[++i])
		i++;
	g_env = (char **)malloc(sizeof(char **) * (i + 1));
	g_env[0] = ft_strdup("0");
	i = 0;
	j = -1;
	while (envp[++j])
		g_env[++i] = ft_strdup(envp[j]);
	g_env[i] = 0;
	return (g_env);
}

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	g_env = ft_env(envp);
	ft_prompt();
}
