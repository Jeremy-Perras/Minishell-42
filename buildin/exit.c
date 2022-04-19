/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 10:48:25 by jperras           #+#    #+#             */
/*   Updated: 2022/04/19 17:10:24 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	ft_buildin_exit(t_minishell *shell)
{
	(void) shell;
//	free(env[0]);
	env[0] = ft_strdup(ft_itoa(0));
	exit(0);
}
