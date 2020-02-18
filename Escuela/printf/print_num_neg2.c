/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num_neg2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 10:45:54 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/17 12:35:45 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_num_minus_neg2(t_rasa *tab, char *num)
{
	int i;

	i = 0;
	while (num[i] != '\0')
	{
		write(1, &num[i++], 1);
		tab->len++;
	}
	i = 0;
	while (i < tab->flags->width - (int)ft_strlen(num))
	{
		write(1, " ", 1);
		i++;
		tab->len++;
	}
}

void	print_num_precision_neg2(t_rasa *tab, char *num)
{
	int i;
	int len;

	len = tab->flags->precision > (int)ft_strlen(num) ?
	tab->flags->precision : (int)ft_strlen(num);
	i = 0;
	while (i < tab->flags->width - len)
	{
		write(1, " ", 1);
		i++;
		tab->len++;
	}
	write(1, "-", 1);
	tab->len++;
	i = 0;
	while (i < tab->flags->precision - ((int)ft_strlen(num) - 1))
	{
		write(1, "0", 1);
		i++;
		tab->len++;
	}
	i = 1;
	write_num(tab, num, i);
}

void	print_num_zero_neg2(t_rasa *tab, char *num)
{
	int i;

	write(1, "-", 1);
	tab->len++;
	i = 0;
	while (i < tab->flags->width - (int)ft_strlen(num))
	{
		write(1, "0", 1);
		i++;
		tab->len++;
	}
	i = 1;
	write_num(tab, num, i);
}

void	print_num_precision_min_neg2(t_rasa *tab, char *num)
{
	int i;
	int len;

	len = tab->flags->precision > (int)ft_strlen(num) ?
	tab->flags->precision : (int)ft_strlen(num);
	write(1, "-", 1);
	tab->len++;
	i = 0;
	while (i < tab->flags->precision - ((int)ft_strlen(num) - 1))
	{
		write(1, "0", 1);
		i++;
		tab->len++;
	}
	i = 1;
	write_num(tab, num, i);
	i = 1;
	while (i < tab->flags->width - len)
	{
		write(1, " ", 1);
		i++;
		tab->len++;
	}
}

void	print_num_neg2(t_rasa *tab, char *num)
{
	if (tab->flags->dot > 0 && tab->flags->minus > 0)
		print_num_precision_min_neg2(tab, num);
	else if (tab->flags->minus > 0)
		print_num_minus_neg2(tab, num);
	else if (tab->flags->dot > 0 && tab->flags->precision > 0)
		print_num_precision_neg2(tab, num);
	else if (tab->flags->zero > 0)
		print_num_zero_neg2(tab, num);
	else
		print_num2_neg2(tab, num);
}
