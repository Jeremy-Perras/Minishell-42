/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 21:41:11 by dhaliti           #+#    #+#             */
/*   Updated: 2022/02/28 16:41:52 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	c_format(t_printf *tab, int index)
{
	char	c;

	if (index)
		c = '%';
	else
		c = va_arg(tab->args, int);
	tab->length += write(1, &c, 1);
}
