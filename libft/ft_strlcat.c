/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:05:31 by jperras           #+#    #+#             */
/*   Updated: 2022/02/22 14:53:54 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len;

	str = (char *)src;
	i = 0;
	j = 0;
	len = 0;
	while (dst[i] != '\0' && i < dstsize)
	{
		i++;
		len++;
	}
	while (src[j] != '\0')
		j++;
	len = len + j;
	j = 0;
	if (i < dstsize)
	{
		while (str[j] != '\0' && i < dstsize - 1)
			dst[i++] = str[j++];
		dst[i] = '\0';
	}
	return (len);
}
