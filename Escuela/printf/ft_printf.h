/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:34:05 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/04 18:59:12 by rarias-p         ###   ########.fr       */
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
/*
**			printf
*/
int				ft_printf	(const char *format, ...);
int				printer		(const char *to_print);
void			ft_pzero	(int d, int num, t_rasa *tab);
void			ft_pminus	(int d, int num, t_rasa *tab);
/*
**			libft
*/
char			*ft_itoa	(int n);
static char		*itoa_string(int n, char *s, int i);
char			*ft_strchr	(const char *s, int c);
char			*ft_strdup	(const char *s);
char			*ft_strjoin	(char const *s1, char const *s2);
size_t			ft_strlen	(const char *str);
char			*ft_substr	(char const *s, unsigned int start, int len);

#endif
