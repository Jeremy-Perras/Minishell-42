/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 21:29:06 by dhaliti           #+#    #+#             */
/*   Updated: 2022/02/28 16:42:35 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_format(const char *format, t_printf *tab, int i)
{
	if (format[i] == '%')
		c_format(tab, 1);
	if (format[i] == 'c')
		c_format(tab, 0);
	if (format[i] == 's')
		s_format(tab);
	if (format[i] == 'p')
		p_format(tab);
	if (format[i] == 'd' || format[i] == 'i')
		i_d_format(tab);
	if (format[i] == 'u')
		u_format(tab);
	if (format[i] == 'x')
		x_format(tab, 0);
	if (format[i] == 'X')
		x_format(tab, 1);
}

int	ft_printf(const char *format, ...)
{
	t_printf	*tab;
	int			length;
	int			i;

	i = -1;
	tab = (t_printf *) malloc(sizeof(t_printf));
	if (!tab)
		return (-1);
	tab->length = 0;
	va_start(tab->args, format);
	while (format[++i])
	{
		if (format[i] == '%')
			ft_format(format, tab, ++i);
		else
			tab->length += write(1, &format[i], 1);
	}
	va_end(tab->args);
	length = tab->length;
	free(tab);
	return (length);
}
