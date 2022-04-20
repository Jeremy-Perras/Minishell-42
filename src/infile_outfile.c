/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile_outfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:25:32 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/20 12:02:59 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

/************************************ ARGS ************************************/

static void	ft_args(char **input, t_minishell *shell)
{
	shell->fd_in = open(input[0], O_RDONLY);
	if (shell->fd_in < 0)
	{
		printf("%s: No such file or directory\n", input[0]);
		exit(0);
	}
	dup2(shell->fd_in, STDIN_FILENO);
}


static void ft_redirection(char **input, t_minishell *shell)
{
	int	i;

	i = 0;
	if (input[i] && ft_strcmp(input[i], ">"))
		ft_redirect(input + i + 1, shell);
	if (input[i] && ft_strcmp(input[i], ">>"))
		ft_append(input + i + 1, shell);
}

/******************** GET FLAGS, ARGS AND OUT REDIRECTION *********************/

char	**ft_flags(char **input, t_minishell *shell)
{
	int	j;
	int	i;

	j = -1;
	i = 0;
	if (shell->flags)
	{
		while (shell->flags[++j])
			free(shell->flags[j]);
		free(shell->flags);
	}
	shell->flags = (char **)malloc(sizeof(char **) * 5);
	shell->flags[0] = ft_strdup(input[0]);
	while (input[++i] && input[i][0] == '-' && ft_strlen(input[i]) >= 2)
		shell->flags[i] = ft_strdup(input[i]);
	shell->flags[i] = NULL;
	if (input[i] && ft_isalnum(input[i][0]))
	{
		ft_args(input + i, shell);
		i++;
	}
	ft_redirection(input + i, shell);
	return (shell->flags);
}
