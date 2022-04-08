/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:47:05 by jperras           #+#    #+#             */
/*   Updated: 2022/02/24 15:29:05 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	char	*str;
	size_t	i;
	size_t	len;

	str = (char *)src;
	i = 0;
	len = 0;
	while (str[len] != '\0')
		len++;
	if (dstsize == 0)
		return (len);
	else
	{
		while (str[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = str[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (len);
}
