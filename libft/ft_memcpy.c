/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:22:45 by jperras           #+#    #+#             */
/*   Updated: 2022/02/25 10:31:09 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	char				*str;
	const char			*str2;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	str = dst;
	str2 = src;
	while (i < n)
	{
		str[i] = str2[i];
		i++;
	}
	return (dst);
}
