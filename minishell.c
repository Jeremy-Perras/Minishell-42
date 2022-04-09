/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:03:00 by jperras           #+#    #+#             */
/*   Updated: 2022/04/09 14:42:06 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Minishell.h"

int	main(int argc, char **argv, char **env)
{
	(void)	argc;
	(void)	argv;
	char	*buf;
	int		i;
	t_minishell shell;

	buf = readline("$> ");
 	 while (buf  != NULL) 
	 {
			if(shell.path)
			{
				i = 0;
				while(shell.path[i])
				{
					free(shell.path[i]);
					i++;
				}
			}
			shell.path = ft_split(buf, '|');
			pipex(&shell, env);
			free(buf);
    		buf = readline("$> ");

	}
}
