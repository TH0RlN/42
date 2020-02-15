/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num_neg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 18:14:21 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/15 18:18:45 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_num_precision_min_neg(t_rasa *tab, char *num)
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
	i = 1;
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

void	print_num_precision_neg(t_rasa *tab, char *num)
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
	i = 1;
	while (num[i] != '\0')
	{
		write(1, &num[i++], 1);
		tab->len++;
	}
}

void	print_num_minus_neg(t_rasa *tab, char *num)
{
	int i;

	i = 1;
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

void	print_num2_neg(t_rasa *tab, char *num, char c)
{
	int i;

	i = 1;
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

void	print_num_neg(t_rasa *tab, char *num, char c)
{
	write(1, "-", 1);
	tab->len++;
	if (tab->flags->dot > 0 && tab->flags->minus > 0)
		print_num_precision_min_neg(tab, num);
	else if (tab->flags->minus > 0)
		print_num_minus_neg(tab, num);
	else if (tab->flags->dot > 0)
		print_num_precision_neg(tab, num);
	else
		print_num2_neg(tab, num, c);
}
