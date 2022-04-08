/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:47:20 by jperras           #+#    #+#             */
/*   Updated: 2022/02/25 13:39:04 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*str2;
	size_t	i;

	str = (char *) s;
	i = 0;
	while (str[i] != '\0')
		i++;
	str2 = malloc(sizeof(char) * (i + 1));
	if (str2 == 0)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}
