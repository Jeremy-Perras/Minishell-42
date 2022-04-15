/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:25:49 by jperras           #+#    #+#             */
/*   Updated: 2022/04/15 14:18:12 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Minishell.h"

void		sigint_handler(int sign_num)
{
	//char *buf;
	printf("%d",sign_num);

	if (sign_num == (int) SIG_ERR )
	{
		write(1,"TEST",4);
		exit(0);
	}
	if (sign_num == SIGQUIT )
		//printf("test2");
		write(1,"test",4);

}
  
