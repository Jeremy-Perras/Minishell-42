/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:03:00 by jperras           #+#    #+#             */
/*   Updated: 2022/04/15 09:17:35 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Minishell.h"

void ft_init (char* buf)
{
	
	(void) buf;
}

int	main(int argc, char **argv, char **env)
{
	(void)	argc;
	(void)	argv;
	(void)	env;
	char	*buf;
	char	**tmp;
	
	t_minishell shell;
	tmp = NULL;
	signal(SIGQUIT, sigint_handler);
	signal(SIGINT, sigint_handler);
	signal(EOF, sigint_handler);
	 if (signal(SIGINT, &sigint_handler) == SIG_ERR) {
        	write(1,"test",4);
		 return EXIT_FAILURE;
    }
	buf = readline("$> ");
	shell.env = &env;
	shell.path = NULL;
 	 while (buf != NULL) 
	 {
		ft_build_in(buf, &shell);
		if(buf[0])
			add_history(buf);
		free(buf);
    	buf = readline("$> ");
	}
}
