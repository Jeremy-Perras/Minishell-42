/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:48:11 by jperras           #+#    #+#             */
/*   Updated: 2022/02/25 10:45:29 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str;
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	str = (void *) src;
	i = 0;
	if (src < dst)
	{
		while (len > 0)
		{
			len --;
			*(char *)(dst + len) = str[len];
		}
	}
	else
	{
		while (i < len)
		{
			*(char *)(dst + i) = str[i];
			i++;
		}	
	}
	return (dst);
}
