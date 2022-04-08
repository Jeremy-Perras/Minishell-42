/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 10:36:36 by jperras           #+#    #+#             */
/*   Updated: 2022/02/26 16:36:22 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdio.h>

static void	ft_copy(char *copy, const char *str, int j, int k);

static void	ft_mal(char **tab, const char *s, char c)
{	
	int		j;
	int		k;
	char	*e;
	int		l;

	j = 0;
	k = 0;
	l = 0;
	while (s[j] != '\0')
	{
		while (s[k] == c && s[k] != '\0')
			k++;
		j = k;
		while (s[j] != c && s[j] != '\0')
			j++;
		if (j != k)
		{
			e = malloc(sizeof(char) * (j - k + 1));
			ft_copy(e, s, j, k);
			*(tab + l) = e;
			l++;
		}	
		k = j;
	}
	*(tab + l) = 0;
}

static void	ft_copy(char *copy, const char *str, int j, int k)
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

static int	ft_len(const char *copy, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (copy[i] != '\0')
	{
		if (copy[i] != c && count == 0)
		{
			count = 1;
			j++;
		}
		else if (copy[i] == c)
			count = 0;
		i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		j;

	j = ft_len(s, c);
	tab = malloc(sizeof(char *) * (j + 1));
	if (tab == NULL)
		return (NULL);
	ft_mal(tab, s, c);
	return (tab);
}
