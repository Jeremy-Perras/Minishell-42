/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 21:29:52 by dhaliti           #+#    #+#             */
/*   Updated: 2022/02/22 15:56:44 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned int	i;
	unsigned char	*sdst;
	unsigned char	*ssrc;

	i = 0;
	sdst = (unsigned char *)dst;
	ssrc = (unsigned char *)src;
	while (i < n)
	{
		sdst[i] = ssrc[i];
		if (ssrc[i] == (unsigned char)c)
			return ((void *)&sdst[i + 1]);
		i++;
	}
	return (NULL);
}
