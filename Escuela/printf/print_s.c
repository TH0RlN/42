/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 09:56:18 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/12 13:08:47 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_s_precision(t_rasa *tab, int len_prt, int i, char *s)
{
	int len_s;

	len_s = tab->flags->precision < (int)ft_strlen(s) ?
	tab->flags->precision : (int)ft_strlen(s);
	while (len_s + len_prt < tab->flags->width)
	{
		write(1, " ", 1);
		len_prt++;
		tab->len++;
	}
	while (s[i] != '\0' && i < tab->flags->precision)
	{
		write(1, &s[i++], 1);
		tab->len++;
		len_prt++;
	}
	return (len_prt);
}

int		print_s_minus(t_rasa *tab, int len_prt, int i, char *s)
{
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

int		print_s_minus_precision(t_rasa *tab, int len_prt, int i, char *s)
{
	int len_s;

	len_s = tab->flags->precision < (int)ft_strlen(s) ?
	tab->flags->precision : (int)ft_strlen(s);
	while (s[i] != '\0' && i < tab->flags->precision)
	{
		write(1, &s[i++], 1);
		tab->len++;
		len_prt++;
	}
	while (len_s + len_prt < tab->flags->width)
	{
		write(1, " ", 1);
		len_prt++;
		tab->len++;
	}
	return (len_prt);
}

void	print_s2(t_rasa *tab, int len_prt, int i, char *s)
{
	while ((int)ft_strlen(s) + len_prt < tab->flags->width)
	{
		write(1, " ", 1);
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
	int		len_prt;
	int		i;

	s = (char *)tab->data;
	i = 0;
	len_prt = 0;
	if (tab->flags->minus > 0 && tab->flags->dot > 0)
		len_prt = print_s_minus_precision(tab, len_prt, i, s);
	else if (tab->flags->minus > 0)
		len_prt = print_s_minus(tab, len_prt, i, s);
	else if (tab->flags->dot > 0)
		len_prt = print_s_precision(tab, len_prt, i, s);
	else
		print_s2(tab, len_prt, i, s);
	flag_pos(tab);
}
