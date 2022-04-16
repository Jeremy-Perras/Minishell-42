/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:24:15 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/15 15:24:41 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if ((s1[i] - s2[i]) != 0)
		return (0);
	return (1);
}

char *quote_ignore(char *input)
{
	if (input[0] == '\"' && input[ft_strlen(input) - 1] == '\"')
	{
		input[ft_strlen(input) - 1] = '\0';
		return (input + 1);
	}
	if (input[0] == '\'' && input[ft_strlen(input) - 1] == '\'')
	{
		input[ft_strlen(input) - 1] = '\0';
		return (input + 1);
	}
	return NULL;
}
