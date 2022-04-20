/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:17:14 by jperras           #+#    #+#             */
/*   Updated: 2022/04/20 12:55:23 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	ft_buildin_unset(t_minishell *shell)
{
	int	i;

	i = 0;
	while (ft_strncmp((shell->env)[i], shell->input2[1],
		ft_strlen(shell->input2[1])) && shell->env[i])
		i++;
	if (!(shell->env[i]))
	{
		free(env[0]);
		env[0] = ft_strdup(ft_itoa(1));
	}
	else
	{
		while ((shell->env)[i])
		{
			(shell->env)[i] = (shell->env)[i + 1];
			i++;
		}
		free(env[0]);
		env[0] = ft_strdup(ft_itoa(0));
	}
}	
