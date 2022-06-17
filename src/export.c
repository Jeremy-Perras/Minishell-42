/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 14:17:20 by jperras           #+#    #+#             */
/*   Updated: 2022/05/24 18:39:05 by dhaliti          ###   ########.fr       */
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
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0' && i < j)
		i++;
	return (s1[i] - s2[i]);
}

static void	ft_buildin_export3(t_minishell *shell, int *flag)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (shell->env[i] && !(*flag))
	{
		while (shell->input2[1][j] != '=')
			j++;
		if (!(ft_strcmp3(shell->env[i], shell->input2[1])))
			*flag = 1;
		i++;
		j = 0;
	}
	if (*flag)
	{
		i--;
		g_st = 1;
	}
}

void	ft_buildin_export2(t_minishell *shell, char **tab2)
{
	int	i;

	i = 0;
	while (shell->env[i])
	{
		tab2[i] = ft_strdup(shell->env[i]);
		i++;
	}
	tab2[i] = ft_strdup(shell->input2[1]);
	i++;
	tab2[i] = NULL;
	i = -1;
	while (shell->env[++i])
		free(shell->env[i]);
	free(shell->env);
	shell->env = tab2;
	g_st = 0;
}

static int	export_env(t_minishell *shell)
{
	if (!(shell->input2[1]))
	{
		ft_buildin_env(shell);
		return (1);
	}
	return (0);
}

void	ft_buildin_export(t_minishell *shell)
{
	int		i;
	char	**tab2;
	int		flag;

	if (export_env(shell))
		return ;
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
	while (shell->env[i])
		i++;
	tab2 = malloc(sizeof(char *) * (i + 2));
	if (tab2 == NULL)
	{
		printf("Malloc fail export");
		g_st = 1;
	}
	ft_buildin_export2(shell, tab2);
}
