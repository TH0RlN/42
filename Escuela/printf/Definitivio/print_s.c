/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:56:18 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/17 09:14:09 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_s_precision(t_rasa *tab, int i, char *s)
{
	int len_s;
	int	j;

	j = 0;
	len_s = (int)ft_strlen(s) < tab->flags->precision ?
	ft_strlen(s) : tab->flags->precision;
	while (len_s + j < tab->flags->width)
	{
		write(1, " ", 1);
		tab->len++;
		j++;
	}
	while (s[i] != '\0' && i < tab->flags->precision)
	{
		write(1, &s[i++], 1);
		tab->len++;
	}
}

int		print_s_minus(t_rasa *tab, int i, char *s)
{
	int len_prt;

	len_prt = 0;
	while (s[i] != '\0')
	{
		write(1, &s[i++], 1);
		tab->len++;
	}
	while ((int)ft_strlen(s) + len_prt < tab->flags->width)
	{
		write(1, " ", 1);
		len_prt++;
		tab->len++;
	}
	return (len_prt);
}

int		print_s_minus_precision(t_rasa *tab, int i, char *s)
{
	int j;
	int len_s;
	int spaces;
	int len_prt;

	j = 1;
	len_prt = 0;
	len_s = tab->flags->precision < (int)ft_strlen(s) ?
	tab->flags->precision : (int)ft_strlen(s);
	while (s[i] != '\0' && i < tab->flags->precision)
	{
		write(1, &s[i++], 1);
		tab->len++;
		len_prt++;
	}
	spaces = tab->flags->width - len_s;
	while (j <= spaces)
	{
		write(1, " ", 1);
		j++;
		tab->len++;
	}
	return (len_prt);
}

void	print_s2(t_rasa *tab, int i, char *s, char c)
{
	int len_prt;

	len_prt = 0;
	while ((int)ft_strlen(s) + len_prt < tab->flags->width)
	{
		write(1, &c, 1);
		len_prt++;
		tab->len++;
	}
	while (s[i] != '\0')
	{
		write(1, &s[i++], 1);
		tab->len++;
	}
}

void	print_s(t_rasa *tab)
{
	char	*s;
	char	c;
	int		i;

	s = !(char *)tab->data ? "(null)" : (char *)tab->data;
	c = tab->flags->zero > 0 ? '0' : ' ';
	i = 0;
	if (tab->flags->minus > 0 && tab->flags->dot > 0)
		print_s_minus_precision(tab, i, s);
	else if (tab->flags->minus > 0)
		print_s_minus(tab, i, s);
	else if (tab->flags->dot > 0)
		print_s_precision(tab, i, s);
	else
		print_s2(tab, i, s, c);
	flag_pos(tab);
}
