/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:16:10 by dhaliti           #+#    #+#             */
/*   Updated: 2022/05/24 18:01:31 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

static int	ft_check_redir(char **input)
{
	if (access(input[1], F_OK) != 0)
	{
		printf("%s: No such file or directory\n", input[1]);
		g_st = 127;
		return (1);
	}
	return (0);
}

int	ft_check_files(t_minishell *shell)
{
	int	i;

	i = -1;
	if (ft_strcmp(shell->input2[0], "<"))
	{
		if (ft_check_redir(shell->input2))
			return (1);
	}
	return (0);
}
