/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:05:50 by jperras           #+#    #+#             */
/*   Updated: 2022/04/20 11:58:21 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	ft_buildin_cd(t_minishell *shell)
{
	if (chdir(shell->input2[1]) == -1)
	{
		free(env[0]);
		env[0] = ft_strdup(ft_itoa(1));
		printf("cd: no such file or directory: %s\n", shell->input2[1]);
		return ;
	}
	free(env[0]);
	env[0] = ft_strdup(ft_itoa(0));
}
