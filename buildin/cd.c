/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:05:50 by jperras           #+#    #+#             */
/*   Updated: 2022/04/16 13:19:17 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	ft_buildin_cd(t_minishell *shell)
{
		if (chdir(shell->args[1]) == -1)
		{
			g_status = -1;
			printf("cd: no such file or directory: %s", shell->args[1]);
		}
		g_status = 0;
}
