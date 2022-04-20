/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:34:45 by jperras           #+#    #+#             */
/*   Updated: 2022/04/19 12:32:17 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	ft_buildin_pwd(t_minishell *shell)
{
	char	tmp[2048];

	(void) shell;
	if (getcwd(tmp, sizeof(tmp)) == NULL)
		g_status = 1;
	else
	{
		printf("%s\n", tmp);
		g_status = 0;
	}
}
