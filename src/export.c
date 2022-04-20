/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:17:20 by jperras           #+#    #+#             */
/*   Updated: 2022/04/19 12:47:47 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	ft_buildin_export(t_minishell *shell, char **env)
{
	int		i;
	char	**tab2;

	i = 0;
	while ((env)[i])
		i++;
	tab2 = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while ((env)[i])
	{
		tab2[i] = ft_strdup(env[i]);
		i++;
	}
	tab2[i] = ft_strdup(shell->input2[1]);
	i++;
	tab2[i] = 0;
	(shell)->env = tab2;
}
