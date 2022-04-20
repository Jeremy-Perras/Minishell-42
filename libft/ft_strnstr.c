/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 20:57:11 by dhaliti           #+#    #+#             */
/*   Updated: 2022/02/21 17:48:17 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	size;

	if (*needle == '\0')
		return ((char *)haystack);
	size = ft_strlen(needle);
	while (*haystack != '\0' && len-- >= size)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle, size) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
