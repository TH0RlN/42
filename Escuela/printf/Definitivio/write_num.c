/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:38:57 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/17 12:05:13 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_num2_neg2(t_rasa *tab, char *num)
{
	int i;

	i = 0;
	while (i < tab->flags->width - (int)ft_strlen(num))
	{
		write(1, " ", 1);
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

void	write_num(t_rasa *tab, char *num, int i)
{
	while (num[i] != '\0')
	{
		write(1, &num[i++], 1);
		tab->len++;
	}
}
