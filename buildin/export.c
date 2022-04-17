/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:17:20 by jperras           #+#    #+#             */
/*   Updated: 2022/04/17 16:01:33 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Minishell.h"

void	ft_buildin_export(t_minishell *shell)
{
	int		i;
	char	**tab2;

	i = 0;
	while ((*shell->env)[i])
	   i++;
	tab2 = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while((shell->env)[i])
	{
		tab2[i] = (shell->env)[i];
		i++;
	}
	tab2[i] = shell->input2[1];
	i++;
	tab2[i] = 0;
	shell->env2 = tab2;
}
