/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:05:34 by jperras           #+#    #+#             */
/*   Updated: 2022/04/18 12:34:00 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Minishell.h"

void	ft_buildin_echo(t_minishell *shell)
{
	int	i;

	i = 0;
	if (!strncmp(shell->input2[1], "-n", 2))
	{
		while (shell->input2[2][i])
		{
			printf("%c", shell->input2[2][i]);
			i++;
		}
	}
	else
	{
		while (shell->input2[1][i])
		{
			printf("%c", shell->input2[1][i]);
			i++;
		}
		printf("\n");
	}
	g_status = 0;
}
