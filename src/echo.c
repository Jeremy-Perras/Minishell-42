/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:05:34 by jperras           #+#    #+#             */
/*   Updated: 2022/04/20 12:03:13 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

static void	ft_buildin_echo2(t_minishell *shell);

void	ft_buildin_echo(t_minishell *shell)
{
	int	i;

	i = 0;
	if (!strncmp(shell->input2[1], "-n", 2))
	{
		if (shell->input[2])
		{
			while (shell->input2[2][i])
			{
				printf("%c", shell->input2[2][i]);
				i++;
			}
		}
	}
	else
		ft_buildin_echo2(shell);
	free(env[0]);
	env[0] = ft_strdup(ft_itoa(0));
}

static void	ft_buildin_echo2(t_minishell *shell)
{
	int	i;

	i = 0;
	if (shell->input2[1])
	{
		while (shell->input2[1][i])
		{
			printf("%c", shell->input2[1][i]);
			i++;
		}
	}
	printf("\n");
}
