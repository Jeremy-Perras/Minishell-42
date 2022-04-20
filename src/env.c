/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:37:11 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/20 12:04:44 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	ft_buildin_env(t_minishell *shell)
{
	int	i;

	i = 0;
	while (shell->env[++i])
		printf("%s\n", shell->env[i]);
	free(env[0]);
	env[0] = ft_strdup(ft_itoa(0));
}
