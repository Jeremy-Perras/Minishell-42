/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile_outfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:25:32 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/16 11:46:02 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"


/********************************** HEREDOC ***********************************/

static char **heredoc(char **input, t_minishell *shell)
{
	char *limiter;
	char *heredoc;

	limiter = input[1];
	shell->fd_in = open(".heredoc", O_WRONLY | O_TRUNC | O_CREAT, 0664);
	heredoc = readline("heredoc>> ");
	while (heredoc != NULL)
	{
		if (ft_strcmp(heredoc, limiter)
			break;
		if (heredoc[0])
			ft_putstr_fd(fd, heredoc);
		heredoc = readline("heredoc>> ");
	}
	dup2(shell->fd_in, STDIN_FILENO);
	return (input + 2);
}
/*************************** GET INFILE AND HEREDOC ***************************/

char **ft_infile(char **input, t_minishell *shell)
{
	if (ft_strcmp(input[0], "<"))
	{
		shell->fd_in = open(input[1], O_READONLY);
		dup2(shell->fd_in, STDIN_FILENO);
		return (input + 2);
	}
	if (ft_strcmp(input[0], "<<"))
		return (ft_heredoc(input, shell));
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

/************************ GET ARGS AND OUT REDIRECTION ************************/

char **ft_args(char **input, char **env, t_minishell *shell)
{
	shell->args = (char **)malloc(sizeof(char **) * 5);
	int i = 0;

	shell->args[0] = ft_strdup(input[0])
	while(input[++i] && input[i][0] == '-')
		shell->args[i] = ft_strdup(input[i]);
	if (input[i]) && ft_strcmp(input[i], ">"))
		ft_redirect(input[i + 1], shell);
	if (input[i] && ft_strcmp(input[i], ">>"))
		ft_append(input[i + i], shell);
	else
		dup2(shell->end[1], STDOUT_FILENO);
	return (shell->args);
}
