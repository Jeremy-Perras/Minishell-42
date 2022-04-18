/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:20:45 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/18 12:16:22 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

/***************************** CHECK EVEN QUOTES ******************************/

static int	ft_quote(char *buf)
{
	int	i;
	int	count_double;
	int	count_simple;

	i = -1;
	count_double = 0;
	count_simple = 0;
	while (buf[++i])
	{
		if (buf[i] == '\"')
			count_double++;
		if (buf[i] == '\'')
			count_simple++;
	}
	if ((count_double && (count_double % 2) != 0)
		|| (count_simple && (count_simple % 2)) != 0)
	{
		printf("\t%d\n", count_double);
		printf("Quotes must be closed\n");
		return (0);
	}
	return (1);
}

/********************************* CHECK "?$" *********************************/

static int	ft_status(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] == ' ' || buf[i] == '\t')
		i++;
	if (ft_strcmp(buf + i, "$?"))
	{
		printf("\tg_status");
		return (1);
	}
	return (0);
}

/************************ REPLACE ENVIRONMENT VARIABLE ************************/

static char	*ft_replace(char *buf, char **env, int index)
{
	int		i;
	int		j;
	char	var[256];
	char	*buf2;
	char	*tmp2;
	char	*tmp;

	i = 0;
	j = 0;
	while (ft_isalnum(buf[++index]))
		var[i++] = buf[index];
	var[i] = 0;
	i = 0;
	while (buf[i] != '$')
		i++;
	buf[i] = 0;
	tmp = ft_strdup(buf);
	while (env[++j])
	{
		if (ft_strncmp(env[j], var, ft_strlen(var)) == 0)
		{
			tmp2 = ft_strjoin(tmp, env[j] + ft_strlen(var) + 1);
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

/******************* CHECK ENVIRONEMENT VARIABLE EXISTENCE ********************/

static char	*ft_dollar(char *buf, char **env)
{
	int		i;
	int		quote;
	char	*buf2;

	i = -1;
	quote = 0;
	while (buf[++i])
	{
		if (buf[i] == '\'')
			quote++;
		if (buf[i] == '$' && ft_isalnum(buf[i + 1]) && quote != 1)
		{
			buf2 = ft_replace(buf, env, i);
			return (buf2);
		}
	}
	return (buf);
}

/*************************** BASIC PARSING FUNCTION ***************************/

void	ft_parse(char *buf, t_minishell *shell)
{
	char	*buf2;

	if (!ft_quote(buf))
		return ;
	if (ft_status(buf))
		return ;
	buf2 = ft_dollar(buf, shell->env);
	pipex(buf2, shell, shell->env);
}
