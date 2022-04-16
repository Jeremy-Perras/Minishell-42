/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:17:14 by jperras           #+#    #+#             */
/*   Updated: 2022/04/16 10:48:07 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	ft_buildin_unset(char *buf, t_minishell *shell)
{
	char **tab;
	
	tab = ft_split(buf, ' ');
	while(ft_strncmp((*shell->env)[i], tab[1], ft_strlen(tab[1])))
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
