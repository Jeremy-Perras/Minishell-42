/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 16:49:37 by jperras           #+#    #+#             */
/*   Updated: 2022/04/13 09:28:13 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Minishell.h"

void	ft_build_in(char *buf, t_minishell *shell)
{
	char tmp[255];
	char **tab3;
	char **tab2;
	int 	i;

	i = 0;	
	if (!(ft_strncmp(buf, "cd", 2)))
	{
		tab3 = ft_split(buf, ' ');
		chdir(tab3[1]);
	}
	else if (!(ft_strncmp(buf, "^C", 2)))
	{
		printf("test");
	
	
	}
	else if (!(ft_strncmp(buf, "echo", 4)))
	{
		tab3 = ft_split(buf, ' ');
		if(!(strncmp(tab3[1],"-n",2)))
		{
			i = 8;
			while (buf[i])
			{
				printf("%c", buf[i]);
				i++;
			}
		}
		else
		{
			i = 5;
			while (buf[i])
			{
				printf("%c", buf[i]);
				i++;
			}
			printf("\n");
		}
	}
	else if (!(ft_strncmp(buf, "pwd", 3)))
	{
		getcwd(tmp,sizeof(tmp));
		printf("%s",tmp);
	}
	else if (!(ft_strncmp(buf, "export", 6)))
	{
		tab3 = ft_split(buf, ' ');
		while ((*shell->env)[i])
		   i++;
		tab2 = malloc(sizeof(char *) * (i + 1));
		i = 0;
		while((*shell->env)[i])
		{
			tab2[i] = (*shell->env)[i];
			i++;
		}
		tab2[i] = tab3[1];
		i++;
		tab2[i] = 0;
		(*shell->env) = tab2;
	}
	else if (!(ft_strncmp(buf, "unset", 5)))
	{
		tab3 = ft_split(buf, ' ');
		while((ft_strncmp((*shell->env)[i],tab3[1],ft_strlen(tab3[1]))))
				i++;
		while((*shell->env)[i])
		{
			(*shell->env)[i] =  (*shell->env)[i + 1];
			i++;
		}
	}
	else if (!(ft_strncmp(buf, "exit", 4)))
	{
		exit(0);
	}
	else
	{
		shell->path = ft_split(buf, '|');
		pipex(shell, *shell->env);
		if(shell->path)
		{
			while(shell->path[i])
			{
				free(shell->path[i]);
				i++;
			}
		}
	}
		

}
