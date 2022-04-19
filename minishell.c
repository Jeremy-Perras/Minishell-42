/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:03:00 by jperras           #+#    #+#             */
/*   Updated: 2022/04/19 13:12:45 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

static void	ft_init(t_minishell **shell, char **var)
{
	*shell = (t_minishell *)malloc(sizeof(t_minishell));
	(*shell)->env = var;
	(*shell)->path = NULL;
	(*shell)->flags = NULL;
	(*shell)->input = NULL;
	(*shell)->input2 = NULL;
	(*shell)->fd_in = 0;
	(*shell)->fd_out = 0;
	g_status = 0;

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
	j = 2;
	while (++j < 100)
		close(j);
	free(shell);
}

void	ft_prompt(char **env)
{
	char		*buf;
	t_minishell	*shell;
	char 		**var;

	var = env;
	buf = readline("$> ");
	while (1)
	{
		ft_init(&shell, var);
		if (*buf)
		{
			add_history(buf);
		}
		ft_parse(buf, shell);
		var = shell->env;
		ft_free_shell(shell);
		free(buf);
		buf = readline("$> ");
	}
}

int	main(int argc, char **argv, char **env)
{
	(void) argc;
	(void) argv;

	g_status = 0;
	signal(SIGQUIT, sigint_handler);
	signal(SIGINT, sigint_handler);
	ft_prompt(env);
}
