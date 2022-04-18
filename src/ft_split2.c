/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:04:47 by dhaliti           #+#    #+#             */
/*   Updated: 2022/04/18 12:48:32 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minishell.h"

static void	ft_copy(char *copy, char *str, int j, int k);

static void	ft_mal(char **tab2, char *c)
{
	int		j;
	int		k;
	char	*e;
	int		l;

	j = 0;
	k = 0;
	l = 0;
	while (c[j] != '\0')
	{
		while (c[k] == 127 && c[k] != '\0')
		k++;
		j = k;
		while (c[j] != 127 && c[j] != '\0')
			j++;
		e = malloc(sizeof(char) * (j + 1));
		ft_copy(e, c, j, k);
		if (e[0] != '\0')
		{
			*(tab2 + l) = e;
			l++;
		}
		k = j;
	}
	*(tab2 + l) = 0;
}

static void	ft_copy(char *copy, char *str, int j, int k)
{
	int	l;

	l = 0;
	while (k != j)
	{
		copy[l] = str[k];
		k++;
		l++;
	}
	copy[l] = '\0';
}

static int	ft_len(char *copy)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (copy[i] != '\0')
	{
		if (copy[i] != 127)
		{
			j++;
		}
		i++;
	}
	return (j);
}

static void	ft_comp(char *str, char *charset, int k)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (charset[k] != '\0')
	{
		while (str[j] != '\0')
		{
			if (str[j] == charset[k])
			{
				str[j] = 127;
			}
			j++;
		}
		ft_comp(str, charset, k + 1);
	}
}

char	**ft_split2(char *str, char *charset)
{
	char	**tab2;
	char	*copy;
	int		i;
	int		j;

	i = 0;
	while (str[i] != '\0')
		i++;
	copy = malloc((i + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	ft_comp(copy, charset, 0);
	j = ft_len(copy);
	tab2 = malloc(sizeof(char *) * (j + 1));
	ft_mal(tab2, copy);
	return (tab2);
}
