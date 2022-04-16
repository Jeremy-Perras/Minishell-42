/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile_outfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:25:32 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/16 20:02:18 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"


/********************************** HEREDOC ***********************************/

static char **ft_heredoc(char **input, t_minishell *shell)
{
	char *limiter;
	char *heredoc;
	int fd;

	limiter = input[1];
	fd = open(".heredoc", O_WRONLY | O_TRUNC | O_CREAT, 0664);
	heredoc = readline("heredoc>> ");
	while (heredoc != NULL)
	{
		if (ft_strcmp(heredoc, limiter))
			break;
		if (heredoc[0])
		{
			ft_putstr_fd(heredoc, fd);
			ft_putstr_fd("\n", fd);
		}
		heredoc = readline("heredoc>> ");
	}
	close(fd);
	shell->fd_in = open(".heredoc", O_RDONLY);
	dup2(shell->fd_in, STDIN_FILENO);
	return (input + 2);
}
/*************************** GET INFILE AND HEREDOC ***************************/

char **ft_infile(char **input, t_minishell *shell)
{
	if (ft_strcmp(input[0], "<"))
	{
		printf("%s\n", input[1]);
		shell->fd_in = open(input[1], O_RDONLY);
		dup2(shell->fd_in, STDIN_FILENO);
		return (input + 2);
	}
	if (ft_strcmp(input[0], "<<"))
	{
		ft_heredoc(input, shell);
		return (input + 2);
	}
	else
		dup2(shell->fd_in, STDIN_FILENO);
	return (input);
}

/*********************************** APPEND ***********************************/

void ft_append(char **input, t_minishell *shell)
{
	shell->fd_out = open(input[0], O_APPEND);
	dup2(shell->fd_out, STDOUT_FILENO);
}

/********************************** REDIRECT **********************************/

void ft_redirect(char **input, t_minishell *shell)
{
	shell->fd_out = open(input[0],  O_WRONLY | O_TRUNC | O_CREAT, 0664);
	dup2(shell->fd_out, STDOUT_FILENO);
}

/************************************ ARGS ************************************/

static void ft_args(char **input, t_minishell *shell)
{
	shell->fd_in = open(input[0], O_RDONLY);
	dup2(shell->fd_in, STDIN_FILENO);
}


/******************** GET FLAGS, ARGS AND OUT REDIRECTION *********************/

static int ft_strsize(char **input)
{
	int i = 0;
	while (input[i])
		i++;
	return (i);
}

char **ft_flags(char **input, char **env, t_minishell *shell)
{
	if (shell->flags)
	{
		int j = -1;
		while (shell->flags[++j])
			free(shell->flags[j]);
		free(shell->flags);
	}
	shell->flags = (char **)malloc(sizeof(char **) * 5);
	(void)env;
	int i = 1;
	shell->flags[0] = ft_strdup(input[0]);
	int size = ft_strsize(input);
	printf("******\n");
	printf("%d\n", size);
	if (size > 1)
	{
		printf("++++++\n");
		while(input[i] && input[i][0] == '-' && ft_strlen(input[i]) >= 2)
		{
			shell->flags[i] = ft_strdup(input[i]);
			i++;
		}
	}
	printf("------\n");
	shell->flags[i] = NULL;
	if(input[i] && ft_isalnum(input[i][0]))
	{
		ft_args(input + i, shell);
		i++;
	}
	if (input[i] && ft_strcmp(input[i], ">"))
		ft_redirect(input + i + 1, shell);
	if (input[i] && ft_strcmp(input[i], ">>"))
		ft_append(input + i + 1, shell);
	return shell->flags;
}
