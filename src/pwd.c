/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:34:45 by jperras           #+#    #+#             */
/*   Updated: 2022/04/20 12:23:30 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	ft_buildin_pwd(t_minishell *shell)
{
	char	tmp[2048];

	if (getcwd(tmp, sizeof(tmp)) == NULL)
	{
		g_status = 1;
		return ;
	}
	if (shell->input[1] && ft_strcmp(shell->input2[1], ">"))
	{
		shell->fd_out = open(shell->input2[2], O_WRONLY | O_TRUNC | O_CREAT, 0664);
		if (shell->fd_out < 0)
		{
			printf("%s: No such file or directory\n", shell->input[2]);
			return ;
		}
		ft_putstr_fd(tmp, shell->fd_out);
	}
	else
	{
		printf("%s\n", tmp);
		g_status = 0;
	}
}
