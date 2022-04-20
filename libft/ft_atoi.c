/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 00:01:56 by dhaliti           #+#    #+#             */
/*   Updated: 2022/03/16 11:18:27 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	ft_atoi_atoi(char *str, int minus)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (((unsigned char)str[i] >= '0') && ((unsigned char)str[i] <= '9'))
	{
		if ((((result * 10) + (str[i] - 48)) < result) && (minus == 1))
			return (-1);
		else if ((((result * 10) + (str[i] - 48)) < result) && (minus == -1))
			return (0);
		result = (result * 10) + ((unsigned char)str[i] - 48);
		i++;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	result;
	char	*s;
	int		sign;

	i = 0;
	s = (char *)str;
	sign = 1;
	while (((s[i] == '\t') || (s[i] == '\n') || (s[i] == '\v')
			|| (s[i] == '\f') || (s[i] == '\r') || (s[i] == '\x1b')
			|| (s[i] == ' ')) && (s[i] != '\e'))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = ft_atoi_atoi(&s[i], sign);
	result = result * sign;
	return ((int)result);
}
