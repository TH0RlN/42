/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:34:05 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/10 10:02:18 by rarias-p         ###   ########.fr       */
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
	t_flags		*flags;
	va_list		list;
}				t_rasa;
/*
** **************************************************************************
**									printf
** **************************************************************************
*/
void			checker					(t_rasa *tab);
int				printer					(const char *to_print);
char			search_type				(t_rasa *tab);
int				ft_printf				(const char *format, ...);
void			ft_pwidth				(char *s, int num, t_rasa *tab);
void			ft_pzero				(char *s, int num, t_rasa *tab);
void			ft_pminus				(char *s, int num, t_rasa *tab);
void			ft_pprecision_int		(char *s, int num, t_rasa *tab);
void			ft_pprecision_string	(char *s, int num, t_rasa *tab);
/*
** **************************************************************************
**									libft
** **************************************************************************
*/
int				ft_atoi					(const char *str);
int				ft_isspace				(int c);
char			*ft_itoa				(int n);
static char		*itoa_string			(int n, char *s, int i);
char			*ft_strchr				(const char *s, int c);
char			*ft_strdup				(const char *s);
char			*ft_strjoin				(char const *s1, char const *s2);
size_t			ft_strlen				(const char *str);
char			*ft_substr				(char const *s, unsigned int start,
										int len);

#endif
