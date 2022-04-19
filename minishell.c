/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:03:00 by jperras           #+#    #+#             */
/*   Updated: 2022/04/19 17:26:03 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

static void	ft_init(t_minishell **shell)
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

void	ft_prompt()
{
	char		*buf;
	t_minishell	*shell;
	//char 		**var;

//	var = env;
	buf = readline("$> ");
	while (1)
	{
		signal(SIGQUIT, sigint_handler);
		signal(SIGINT, sigint_handler);
	//	buf = readline("$> ");
		ft_init(&shell);
	//	buf = readline("$> ");
		if (*buf)
			add_history(buf);
		ft_parse(buf, shell);
	//	var = shell->env;
		ft_free_shell(shell);
		free(buf);
		buf = readline("$> ");
	}
}

static char **ft_env(char **envp)
{
	int i = -1;
	while (envp[++i])
		i++;
	env = (char **)malloc(sizeof(char **) * (i + 1));
	env[0] = ft_strdup("0");
	i = 0;
	int j = -1;
	while (envp[++j])
		env[++i] = envp[j];
	env[i] = 0;
	return (env);

}

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	//pid_t child;

	env = ft_env(envp);
	ft_prompt();
	// while (g_status != 5)
	// {
	// 	// signal(SIGQUIT, sigint_handler);
	// 	// signal(SIGINT, sigint_handler);
	// 	child = fork();
	// 	if (!child)
	// 	else
	// 	{
	// 		pid_t ret = waitpid(child, NULL, 0);
	// 		if (ret == 5)
	// 			exit(0);
	// 	}
	// }
}
