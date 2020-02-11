/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:34:05 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/11 11:32:49 by rarias-p         ###   ########.fr       */
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
	int			dot;
	int			ast;
	int			zero;
	int			width;
	int			precision;
}				t_flags;

typedef struct	s_rasa
{
	char		*format;
	int			pos;
	int			len;
	int			f_len;
	char		type;
	void		*data;
	t_flags		*flags;
	va_list		list;
}				t_rasa;
/*
** **************************************************************************
**									printf
** **************************************************************************
*/
void			checker					(t_rasa *tab);
void			flag_pos				(t_rasa *tab);
void			flagger					(t_rasa *tab);
void			get_precision			(t_rasa *tab);
char			get_type				(t_rasa *tab);
void			get_width				(t_rasa *tab);
void			init					(t_rasa *tab, char *format);
void			init_flags				(t_rasa *tab);
void			print_type				(t_rasa *tab);
void			print_c					(t_rasa *tab);
int				printer					(const char *to_print);
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
