/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:17:20 by jperras           #+#    #+#             */
/*   Updated: 2022/04/20 17:54:19 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	ft_buildin_export2(t_minishell *shell, char **tab2)
{
	int	i;

	i = 0;
	while ((g_env)[i])
	{
		tab2[i] = ft_strdup(g_env[i]);
		i++;
	}
	tab2[i] = ft_strdup(shell->input2[1]);
	i++;
	tab2[i] = NULL;
	i = 0;
	while (g_env[++i])
		free(g_env[i]);
	free(g_env);
	g_env = tab2;
	free(g_env[0]);
	g_env[0] = ft_strdup(ft_itoa(0));
}

void	ft_buildin_export(t_minishell *shell)
{
	int		i;
	char	**tab2;

	if (!(ft_strchr(shell->input2[1], '=')))
	{
		printf("export: %s not valid in this context\n", shell->input2[1]);
		return ;
	}
	i = 0;
	while ((g_env)[i])
		i++;
	tab2 = malloc(sizeof(char *) * (i + 2));
	if (tab2 == NULL)
	{
		printf("Malloc fail export");
		free(g_env[0]);
		g_env[0] = ft_strdup(ft_itoa(0));
	}
	ft_buildin_export2(shell, tab2);
}
