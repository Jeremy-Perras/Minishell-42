/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:20:26 by dhaliti           #+#    #+#             */
/*   Updated: 2022/05/24 18:30:27 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

static int	ft_pipe_single_quotes(char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buf[++i])
	{
		if (buf[i] == '\'')
		{
			j = i;
			break ;
		}
	}
	i = 0;
	while (++i < j)
	{
		if (buf[i] == '|')
			return (1);
	}
	return (0);
}

static int	ft_pipe_double_quotes(char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (buf[++i])
	{
		if (buf[i] == '\"')
		{
			j = i;
			break ;
		}
	}
	i = 0;
	while (++i < j)
	{
		if (buf[i] == '|')
			return (1);
	}
	return (0);
}

int	ft_quote_pipe(char *buf)
{
	int	i;
	int	double_quote;
	int	single_quote;

	i = -1;
	double_quote = 0;
	single_quote = 0;
	while (buf[++i])
	{
		if (buf[i] == '\"')
			return (ft_pipe_double_quotes(buf + i));
		if (buf[i] == '\'')
			return (ft_pipe_single_quotes(buf + i));
	}
	return (0);
}
