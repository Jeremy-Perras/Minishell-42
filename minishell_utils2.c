/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:25:49 by jperras           #+#    #+#             */
/*   Updated: 2022/04/14 10:44:55 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Minishell.h"

void		sigint_handler(int sign_num)
{
	char *buf;
	if (sign_num == SIGINT )
		write(1, "\n$> ",4);	
		//kill(0,SIGSTOP);
	if (sign_num == SIGQUIT )
		printf("test2");
		//write(1,"test",4);

}
  
