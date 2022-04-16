/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:03:00 by jperras           #+#    #+#             */
/*   Updated: 2022/04/16 11:42:31 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

static void ft_init(t_minishell **shell, char **env)
{
	*shell = (t_minishell *)malloc(sizeof(t_minishell));
	(*shell)->env = env;
	(*shell)->path = NULL;
	(*shell)->args = NULL;
}

static void ft_free_shell(t_minishell *shell)
{
	int i = -1;

	while (shell->path[++i])
		free (shell->path[i]);
	free(shell->path);
	i = -1;
	while (shell->args[++i])
		free(shell->args[i]);
	free(shell->args);
	free(shell);
}

int	main(int argc, char **argv, char **env)
{
	(void)	argc;
	(void)	argv;
	//(void)	env;
	char	*buf;

	t_minishell *shell;
	// signal(SIGQUIT, sigint_handler);
	// signal(SIGINT, sigint_handler);
	buf = readline("$> ");
 	 while (buf != NULL)
	 {
		ft_init(&shell, env);
		if(buf[0])
 			add_history(buf);
		ft_parse(buf, shell);
		free(buf);
		ft_free_shell(shell);
    	buf = readline("$> ");
	}
}

/*
1. minishell
2. ft_parse
3. pipex
4. exceve || builtins

__utils
ft_split
quote_ignore
*/
