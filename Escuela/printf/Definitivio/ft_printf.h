/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 15:34:05 by rarias-p          #+#    #+#             */
/*   Updated: 2020/03/04 10:21:26 by rarias-p         ###   ########.fr       */
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
	int			astp;
	int			astw;
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
void			is_perc					(t_rasa *tab);
void			print_type				(t_rasa *tab);
void			print_c					(t_rasa *tab);
void			print_num				(t_rasa *tab);
void			print_num2				(t_rasa *tab, char *num, char c);
void			print_num_minus			(t_rasa *tab, char *num);
void			print_num_neg2			(t_rasa *tab, char *num);
void			print_num2_neg2			(t_rasa *tab, char *num);
void			print_num_precision		(t_rasa *tab, char *num);
void			print_num_precision_min	(t_rasa *tab, char *num);
void			print_num_zero			(t_rasa *tab);
void			print_unum				(t_rasa *tab);
void			print_p					(t_rasa *tab);
void			print_perc				(t_rasa *tab);
void			print_s					(t_rasa *tab);
void			print_x					(t_rasa *tab);
int				printer					(const char *to_print);
char			*itoa_hex				(unsigned long int num, t_rasa *tab);
int				ft_printf				(const char *format, ...);
void			write_num				(t_rasa *tab, char *num, int i);
/*
** **************************************************************************
**									libft
** **************************************************************************
*/
int				ft_atoi					(const char *str);
void			*ft_bzero				(void *s, size_t n);
int				ft_isspace				(int c);
char			*ft_itoa				(long int n);
char			*ft_utoa				(unsigned int n);
char			*ft_strdup				(const char *s);
char			*ft_strjoin				(char const *s1, char const *s2);
size_t			ft_strlen				(const char *str);
char			*ft_substr				(char const *s, unsigned int start,
										int len);

#endif
