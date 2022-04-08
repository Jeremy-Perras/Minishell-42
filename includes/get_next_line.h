/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wilhelmfermey <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:21:56 by wilhelmfermey     #+#    #+#             */
/*   Updated: 2022/03/08 08:22:14 by wilhelmfermey    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

char    *get_next_line(int fd);
char    *ft_read(int fd, char *buff, char *str, int res);
char    *ft_strjoin(char *str1, char *str2);
int		ft_strlen(char *str);
int 	ft_strchr(char *str, char c);

#endif
