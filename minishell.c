/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 13:03:00 by jperras           #+#    #+#             */
/*   Updated: 2022/04/12 17:10:50 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "includes/Minishell.h"

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
	char	buf2[2048];
	char	**tmp;
	char	*id;
	struct sigaction sa;
	//int		i;
	t_minishell shell;
	tmp = NULL;
	buf = readline("$> ");
	shell.env = &env;
	shell.path = NULL;
 	 while (buf != NULL) 
	 {
			printf("%d",sigaction(SIGINT, &sa, NULL));
			ft_build_in(buf, &shell);
			dup(STDIN_FILENO);
			read(STDIN_FILENO,buf2, 2048);
			id = tgetstr("kl", NULL);
			id[1] = 91;
			if (!ft_memcmp(buf2, id,ft_strlen(id)))
				printf("test");
			free(buf);
    		buf = readline("$> ");
	}
}
