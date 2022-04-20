/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:17:14 by jperras           #+#    #+#             */
/*   Updated: 2022/04/20 15:39:50 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	ft_buildin_unset(t_minishell *shell)
{
	int	i;

	i = 0;
	while (g_env[i] && ft_strncmp(g_env[i], shell->input2[1],
		ft_strlen(shell->input2[1])))
		i++;
	if (!g_env[i])
	{
		printf("unset: %s\nInvalid parameter name\n", shell->input2[1]);
		free(g_env[0]);
		g_env[0] = ft_strdup(ft_itoa(1));
	}
	else
	{
		while (g_env[i])
		{
			(g_env)[i] = (g_env)[i + 1];
			i++;
		}
		free(g_env[0]);
		g_env[0] = ft_strdup(ft_itoa(0));
	}
}
