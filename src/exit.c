/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 10:48:25 by jperras           #+#    #+#             */
/*   Updated: 2022/04/20 16:19:56 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	ft_buildin_exit(t_minishell *shell)
{
	(void) shell;
	free(g_env[0]);
	g_env[0] = ft_strdup(ft_itoa(0));
	exit(0);
}
