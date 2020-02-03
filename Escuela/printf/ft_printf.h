/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:34:05 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/03 16:52:53 by rarias-p         ###   ########.fr       */
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
	int			minus;
	int			zero;
	int			width;
	int			dot;
	int			ast;
	int			precision;
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
