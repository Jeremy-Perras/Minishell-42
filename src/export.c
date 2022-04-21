/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:17:20 by jperras           #+#    #+#             */
/*   Updated: 2022/04/21 16:26:16 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

static int	ft_strcmp3(char *s1, char *s2)
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

static void	ft_buildin_export3(t_minishell *shell, int *flag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g_env[i] && !(*flag))
	{
		while (shell->input2[1][j] != '=')
			j++;
		if (!(ft_strcmp3(g_env[i], shell->input2[1])))
					*flag = 1;
		i++;
		j = 0;
	}
	if (*flag)
	{
		i--;
		free(g_env[i]);
		g_env[i] = ft_strdup(shell->input2[1]);
	}
}

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
	int		flag;

	if (!(ft_strchr(shell->input2[1], '=')))
	{
		printf("export: %s not valid in this context\n", shell->input2[1]);
		return ;
	}
	flag = 0;
	ft_buildin_export3(shell, &flag);
	if (flag)
		return ;
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
