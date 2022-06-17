/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 16:17:14 by jperras           #+#    #+#             */
/*   Updated: 2022/05/24 18:34:29 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

static int	ft_strcmp2(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[j] && s1[j] != '=')
		j++;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < j - 1)
		i++;
	return (s1[i] - s2[i]);
}

static void	ft_buldin_unset2(int i, t_minishell *shell)
{
	i++;
	while (shell->env[i])
	{
		shell->env[i] = shell->env[i + 1];
		i++;
	}
	g_st = 0;
}

void	ft_buildin_unset(t_minishell *shell)
{
	int	i;

	i = 0;
	if (!(shell->input2[1]))
	{
		printf("unset: not enough arguments\n");
		return ;
	}
	while (shell->env[i] && ft_strcmp2(shell->env[i], shell->input2[1]) != 0)
		i++;
	i--;
	if (!shell->env[i])
	{
		printf("unset: %s\nInvalid parameter name\n", shell->input2[1]);
		g_st = 1;
	}
	else
		ft_buldin_unset2(i, shell);
}
