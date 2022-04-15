/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:05:50 by jperras           #+#    #+#             */
/*   Updated: 2022/04/15 15:11:55 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	ft_buildin_cd(char *buf, t_minishell *shell)
{
	char **tab;

	if (!(ft_strncmp(buf, "cd", 2)))
	{
		tab = ft_split(buf, ' ');
		if (chdir(tab3[1]) == -1)
		{
			g_status = -1;
			printf("cd: no such file or directory: %s", tab[1]);
		}
	}
}
