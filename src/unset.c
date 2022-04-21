/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:17:14 by jperras           #+#    #+#             */
/*   Updated: 2022/04/21 13:01:54 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

static int	ft_strcmp2(char *s1, char *s2)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (s1[j] && s1[j] != '=')
		j++;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < j - 1)
		i++;
	return (s1[i] - s2[i]);
}

void	ft_buildin_unset(t_minishell *shell)
{
	int	i;

	i = 0;
	while (g_env[i] && ft_strcmp2(g_env[i], shell->input2[1]) != 0)
		i++;
	i--;
	if (!g_env[i])
	{
		printf("unset: %s\nInvalid parameter name\n", shell->input2[1]);
		free(g_env[0]);
		g_env[0] = ft_strdup(ft_itoa(1));
	}
	else
	{
		i++;
		while (g_env[i])
		{
			(g_env)[i] = (g_env)[i + 1];
			i++;
		}
		free(g_env[0]);
		g_env[0] = ft_strdup(ft_itoa(0));
	}
}
