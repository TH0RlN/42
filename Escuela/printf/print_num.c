/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:08:57 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/15 20:30:37 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_num_precision_min(t_rasa *tab, char *num)
{
	int num_len;
	int i;

	num_len = (int)ft_strlen(num) > tab->flags->precision ?
	(int)ft_strlen(num) : tab->flags->precision;
	i = 0;
	while (i + (int)ft_strlen(num) < tab->flags->precision)
	{
		write(1, "0", 1);
		i++;
		tab->len++;
	}
	i = 0;
	while (num[i] != '\0')
	{
		write(1, &num[i++], 1);
		tab->len++;
	}
	i = 0;
	while (i + num_len < tab->flags->width)
	{
		write(1, " ", 1);
		i++;
		tab->len++;
	}
}

void	print_num_precision(t_rasa *tab, char *num)
{
	int num_len;
	int i;

	num_len = (int)ft_strlen(num) > tab->flags->precision ?
	(int)ft_strlen(num) : tab->flags->precision;
	i = 0;
	while (i + num_len < tab->flags->width)
	{
		write(1, " ", 1);
		i++;
		tab->len++;
	}
	i = 0;
	while (i + (int)ft_strlen(num) < tab->flags->precision)
	{
		write(1, "0", 1);
		i++;
		tab->len++;
	}
	i = 0;
	while (num[i] != '\0')
	{
		write(1, &num[i++], 1);
		tab->len++;
	}
}

void	print_num_minus(t_rasa *tab, char *num)
{
	int i;

	i = 0;
	while (num[i] != '\0')
	{
		write(1, &num[i++], 1);
		tab->len++;
	}
	i = 0;
	while (i + (int)ft_strlen(num) < tab->flags->width)
	{
		write(1, " ", 1);
		i++;
		tab->len++;
	}
}

void	print_num2(t_rasa *tab, char *num, char c)
{
	int i;

	i = 0;
	while (i + (int)ft_strlen(num) < tab->flags->width)
	{
		write(1, &c, 1);
		i++;
		tab->len++;
	}
	i = 0;
	while (num[i] != '\0')
	{
		write(1, &num[i++], 1);
		tab->len++;
	}
}

void	print_num(t_rasa *tab)
{
	char	*num;
	char	c;

	c = tab->flags->zero > 0 ? '0' : ' ';
	num = ft_itoa((int)tab->data);
	if ((int)tab->data < 0)
		print_num_neg(tab, num, c);
	else if (tab->flags->dot > 0 && tab->flags->minus > 0)
		print_num_precision_min(tab, num);
	else if (tab->flags->minus > 0)
		print_num_minus(tab, num);
	else if (tab->flags->dot > 0)
		print_num_precision(tab, num);
	else
		print_num2(tab, num, c);
	flag_pos(tab);
}
