/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:03:00 by jperras           #+#    #+#             */
/*   Updated: 2022/04/18 14:25:40 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

static void	ft_init(t_minishell **shell, char **env)
{
	*shell = (t_minishell *)malloc(sizeof(t_minishell));
	(*shell)->env = env;
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
	while (shell->path[++i])
		free (shell->path[i]);
	free(shell->path);
	j = 2;
	while (++j < 100)
		close(j);
	free(shell);
}

void	ft_prompt(char **env)
{
	char		*buf;
	t_minishell	*shell;

	buf = readline("\e[96m$> \e[97m");
	while (buf != NULL)
	{
		ft_init(&shell, env);
		if (buf[0])
			add_history(buf);
		ft_parse(buf, shell);
		free(buf);
		ft_free_shell(shell);
		buf = readline("\e[96m$> \e[97m");
	}
}

int	main(int argc, char **argv, char **env)
{
	(void) argc;
	(void) argv;
	signal(SIGQUIT, sigint_handler);
	signal(SIGINT, sigint_handler);
	ft_prompt(env);
}
