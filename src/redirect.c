/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:59:26 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/20 12:16:59 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

/********************************** HEREDOC ***********************************/

static char	**ft_heredoc(char **input, t_minishell *shell)
{
	char	*limiter;
	char	*heredoc;
	int		fd;

	limiter = input[1];
	fd = open(".heredoc", O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (!fd)
		exit(0);
	heredoc = readline("heredoc>> ");
	while (heredoc != NULL)
	{
		if (ft_strcmp(heredoc, limiter))
			break ;
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

char	**ft_infile(char **input, t_minishell *shell)
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

void	ft_append(char **input, t_minishell *shell)
{
	shell->fd_out = open(input[0], O_WRONLY | O_APPEND | O_CREAT, 0664);
	if (shell->fd_out < 0)
	{
		printf("%s: No such file or directory\n", input[0]);
		exit(0);
	}
	dup2(shell->fd_out, STDOUT_FILENO);
}

/********************************** REDIRECT **********************************/

void	ft_redirect(char **input, t_minishell *shell)
{
	shell->fd_out = open(input[0], O_WRONLY | O_TRUNC | O_CREAT, 0664);
	if (shell->fd_out < 0)
	{
		printf("%s: No such file or directory\n", input[0]);
		exit(0);
	}
	dup2(shell->fd_out, STDOUT_FILENO);
}
