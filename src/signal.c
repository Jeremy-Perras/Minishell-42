/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <jperras@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:25:49 by jperras           #+#    #+#             */
/*   Updated: 2022/04/19 16:32:03 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

void	sigint_handler(int sign_num)
{
	if (sign_num == SIGINT)
	{
	//	write(1,"\b\b ", 3);
		// write(1,"$> ", 3);
	//	free(env[0]);
		printf("\n");
		env[0] = ft_strdup(ft_itoa(128 + sign_num));
		printf("A\n");
		ft_prompt();
	}
	// else
	// {
	// 	write(1,"\b\b  ", 4);
	// 	write(1,"\n", 1);
	// 	write(1,"$> ", 3);
	// 	g_status = 0;
	// }


	/*if (sign_num == SIGQUIT)
	{
		g_status = 128 + sign_num;
	}*/
}
