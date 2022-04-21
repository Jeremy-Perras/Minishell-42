/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:31:25 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/21 08:49:25 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

/*********************************** CHILD ************************************/

void	ft_child_process(t_minishell *shell, char *cmd)
{
	shell->input2 = ft_infile(shell->input2, shell);
	close(shell->end[0]);
	ft_exceve(shell->input2, shell, cmd);
	exit(0);
}

/*********************************** PARENT ***********************************/

void	ft_parent_process(t_minishell *shell)
{
	close(shell->end[1]);
	shell->fd_in = shell->end[0];
	wait(NULL);
}

/*********************************** EXECVE ***********************************/

void	ft_exceve(char **input, t_minishell *shell, char *cmd)
{
	if (ft_strcmp(input[0], "cat") && input[2])
		ft_cat(input, shell, cmd);
	else if (ft_strcmp(input[0], "echo"))
		ft_buildin_echo(shell);
	else if (ft_strcmp(shell->input2[0], "env"))
		ft_buildin_env(shell);
	else
	{
		ft_flags(input, shell);
		if (execve(cmd, shell->flags, g_env) == -1)
			printf("%s: No such file or directory\n", cmd);
	}
}
