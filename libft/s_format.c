/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_format.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 21:47:07 by dhaliti           #+#    #+#             */
/*   Updated: 2022/03/02 14:30:51 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_format(t_printf *tab)
{
	char	*str;

	str = va_arg(tab->args, char *);
	if (!str)
		tab->length += write(1, "(null)", 6);
	else
		tab->length += write(1, str, ft_strlen(str));
}
