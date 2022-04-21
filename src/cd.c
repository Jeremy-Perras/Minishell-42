/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:05:50 by jperras           #+#    #+#             */
/*   Updated: 2022/04/21 08:47:49 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	ft_buildin_cd(t_minishell *shell)
{
	char	*c;

	if (shell->input2[1] == NULL)
		shell->input2[1] = getenv("HOME");
	else if (shell->input2[1][0] == '~')
	{
		c = getenv("HOME");
		shell->input2[1] = ft_strjoin(c, shell->input2[1] + 1);
	}
	if (chdir(shell->input2[1]) == -1)
	{
		free(g_env[0]);
		g_env[0] = ft_strdup(ft_itoa(1));
		printf("cd: no such file or directory: %s\n", shell->input2[1]);
		return ;
	}
	free(g_env[0]);
	g_env[0] = ft_strdup(ft_itoa(0));
}
