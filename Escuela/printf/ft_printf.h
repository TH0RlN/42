/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:34:05 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/03 16:38:25 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct	s_flags
{
	int			c;
	char		*s;
	long int	p;
	int			d;
	int			i;
	int			u;
	int			x;
	int			xm;
	char		*type;
}				t_flags;

typedef struct	s_rasa
{
	char		*format;
	int			pos;
	int			len;
	char		type;
	t_flags		*tab;
	va_list		list;
}				t_rasa;

char			*ft_strchr(const char *s, int c);
size_t			ft_strlen(const char *str);

#endif
