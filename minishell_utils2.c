/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:25:49 by jperras           #+#    #+#             */
/*   Updated: 2022/04/12 17:03:16 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

#define _XOPEN_SOURCE_EXTENDED 1
#include <signal.h>
#include <stdio.h>
void mysig(int a) { printf("In mysig\n"); }

int	main(void) {
   struct sigaction info, newhandler;
	while(1)
	{
   if (sigaction(SIGCHLD,NULL,&info) != -1)
   {
       if (info.sa_handler == SIG_IGN)
           printf("SIGCHLD being ignored.\n");
       else if(info.sa_handler == SIG_DFL)
           printf("SIGCHLD being defaulted.\n");
   }

   newhandler.sa_handler = &mysig;
   sigemptyset(&(newhandler.sa_mask));
   newhandler.sa_flags = 0;
   if (sigaction(SIGCHLD,&newhandler,&info) != -1)
       printf("New handler set.\n"); 
	}
}

