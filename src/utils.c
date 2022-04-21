/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 15:24:15 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/21 12:16:49 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if ((s1[i] - s2[i]) != 0)
		return (0);
	return (1);
}

char	*quote_ignore(char *input)
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
	return (input);
}

char	*ft_replace2(char *var, int index, char **env, char *buf)
{
	char	*tmp2;
	char	*tmp;
	char	*buf2;
	int		i;

	tmp = ft_strdup(buf);
	i = 0;
	while (env[++i])
	{
		if (ft_strncmp(env[i], var, ft_strlen(var)) == 0)
		{
			tmp2 = ft_strjoin(tmp, env[i] + ft_strlen(var) + 1);
			buf2 = ft_strjoin(tmp2, &buf[index]);
			free(tmp);
			free(tmp2);
			return (buf2);
		}
	}
	tmp2 = ft_strjoin(tmp, "");
	buf2 = ft_strjoin(tmp2, &buf[index]);
	free(tmp);
	free(tmp2);
	return (buf2);
}

void	ft_free(char **mypath)
{
	int	i;

	i = 0;
	while (mypath[i])
	{
		free(mypath[i]);
		i++;
	}
	free(mypath);
}
