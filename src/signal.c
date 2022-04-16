/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:25:49 by jperras           #+#    #+#             */
/*   Updated: 2022/04/16 11:34:53 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Minishell.h"

void		sigint_handler(int sign_num)
{
	if (sign_num == SIGINT)
	{
		
		g_status = 128 + sign_num;
		write(1,"TEST",4);
	}
	if (sign_num == SIGQUIT )
		g_status = 128 + sign _num;
		write(1,"test",4);
}
