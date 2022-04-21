/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 16:16:10 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/21 15:47:33 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

// static int	ft_check_cat(char **input)
// {
// 	int	i;
//
// 	i = 1;
// 	while (input[i] && input[i][0] == '-')
// 		i++;
// 	while (input[i] && input[i][0] != '>')
// 	{
// 		if (access(input[i], F_OK) != 0)
// 		{
// 			printf("%s: No such file or directory\n", input[i]);
// 			free(g_env[0]);
// 			g_env[0] = ft_strdup(ft_itoa(127));
// 			return (-100);
// 		}
// 		i++;
// 	}
// 	return (i);
// }

static int	ft_check_redir(char **input)
{
	if (access(input[1], F_OK) != 0)
	{
		printf("%s: No such file or directory\n", input[1]);
		free(g_env[0]);
		g_env[0] = ft_strdup(ft_itoa(127));
		return (1);
	}
	return (0);
}

int	ft_check_files(t_minishell *shell)
{
	int	i;

	i = -1;
	if (ft_strcmp(shell->input2[0], "<"))
	{
		if (ft_check_redir(shell->input2))
			return (1);
	}
	// while (*(shell->input2) && shell->input2[++i])
	// {
	// 	if (ft_strcmp(shell->input2[i], "cat"))
	// 	{
	// 		write(1,shell->input2[i],ft_strlen(shell->input2[i]));
	// 		write(1,"\n",1);
	// 		i += ft_check_cat(shell->input2 + i);
	// 		if (i < 0)
	// 		{
	// 			return (1);
	// 		}
	// 	}
	// 	write(1,shell->input2[i],ft_strlen(shell->input2[i]));
	// 	write(1,"\n",1);
	// }
	// //write(1, "A\n", 2);
	return (0);
}
