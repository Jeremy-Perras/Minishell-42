/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_redirection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 12:28:44 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/20 12:39:55 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

// ft_builtin_redirect(t_minishell *shell, )
// {
// 	if (ft_strcmp(shell->input[2], ">"))
// 	{
// 		shell->fd_out = open(shell->input2[1], \
// 			O_WRONLY | O_TRUNC | O_CREAT, 0664);
// 		if (shell->fd_out < 0)
// 		{
// 			printf("%s: No such file or directory\n", shell->input2[2]);
// 			return ;
// 		}
// 		ft_putstr_fd(tmp, shell->fd_out);
// 	}
// 	if (ft_strcmp(shell->input[2], ">>"))
// 	{
// 		shell->fd_out = open(shell->input2[1], \
// 			O_WRONLY | O_APPEND | O_CREAT, 0664);
// 		if (shell->fd_out < 0)
// 		{
// 			printf("%s: No such file or directory\n", shell->input2[2]);
// 			return ;
// 		}
// 		ft_putstr_fd(tmp, shell->fd_out);
// 	}
// }
