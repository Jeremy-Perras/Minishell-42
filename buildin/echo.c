/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:05:34 by jperras           #+#    #+#             */
/*   Updated: 2022/04/16 13:24:00 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Minishell.h"

void	ft_buildin_echo(t_minishell *shell)
{
	int	i;

	i = 0;
	if(!strncmp(shell->args[1], "-n", 2))
	{
		while(shell->args[2][i])
		{
			printf("%c",shell->args[2][i]);
			i++;
		}
	}
	else 
	{
		while (shell->args[1][i])
		{
			printf("%c", shell->args[1][i]);
			i++;
		}
		printf("\n");
	}
	g_status = 0;
}
