/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:25:49 by jperras           #+#    #+#             */
/*   Updated: 2022/04/19 14:45:30 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Minishell.h"

void	sigint_handler(int sign_num)
{
	if (sign_num == SIGINT && g_status == 130)
	{
		write(1,"\b\b  ", 4);
		write(1,"\n", 1);
		write(1,"$> ", 3);
		g_status = 128 + sign_num;
	}
	else
	{
		write(1,"\b\b  ", 4);
		write(1,"\n", 1);
		write(1,"$> ", 3);
		g_status =0;
	}


	/*if (sign_num == SIGQUIT)
	{
		g_status = 128 + sign_num;
	}*/
}
