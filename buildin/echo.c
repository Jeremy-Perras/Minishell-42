/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:05:34 by jperras           #+#    #+#             */
/*   Updated: 2022/04/15 15:33:04 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Minishell.h"

void	ft_buildin_echo(char * buf, t_minishell *shell)
{
	char	*tab;
	int		i;

	tab = ft_split(buf, ' ');
	if(!strncmp(tab[1], "-n", 2))
	{
		while(buf[i])
		{
			printf("%c"buf[i]);
			i++;
		}
	}
	else 
	{
		i = 5;
		while (buf[i])
		{
			printf("%c", buf[i]);
			i++;
		}
	}
	printf("\n");
	g_status = 0;
}
