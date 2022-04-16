/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:17:14 by jperras           #+#    #+#             */
/*   Updated: 2022/04/16 13:25:54 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	ft_buildin_unset(t_minishell *shell)
{
	int	i;
	
	i = 0;
	while(ft_strncmp((*shell->env)[i], shell->args[1], ft_strlen(shell->args[1])))
		i++;
	if(!(*shell->env[i]))
		g_status = 1;
	else
	{
		while((*shell->env)[i])
		{
			(*shell->env)[i] = (*shell->env)[i + 1];
			i++;
		}
		g_status = 0;
	}
}	
