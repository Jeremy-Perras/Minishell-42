/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infile_outfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:25:32 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/21 11:31:27 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	ft_redirection(char **input, t_minishell *shell)
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
	while (input[++i] && (input[i][0] == '-' || ft_isalnum(input[i][0])))
		shell->flags[i] = ft_strdup(input[i]);
	shell->flags[i] = NULL;
	ft_redirection(input + i, shell);
	return (shell->flags);
}
