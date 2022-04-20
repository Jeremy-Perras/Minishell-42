/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhaliti <dhaliti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:19:43 by dhaliti           #+#    #+#             */
/*   Updated: 2022/02/28 16:41:44 by dhaliti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_printf
{
	va_list		args;
	int			length;
}			t_printf;

int					ft_printf(const char *format, ...);
void				i_d_format(t_printf *tab);
void				c_format(t_printf *tab, int index);
void				s_format(t_printf *tab);
void				p_format(t_printf *tab);
void				u_format(t_printf *tab);
void				x_format(t_printf *tab, int index);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);

#endif
