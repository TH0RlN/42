/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_perc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:51:55 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/15 21:16:20 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_perc_minus(t_rasa *tab, int i)
{
	write(1, "%", 1);
	while (i < tab->flags->width - 1)
	{
		write(1, " ", 1);
		i++;
		tab->len++;
	}
}

void	print_perc2(t_rasa *tab, int i, char c)
{
	while (i < tab->flags->width - 1)
	{
		write(1, &c, 1);
		i++;
		tab->len++;
	}
	write(1, "%", 1);
}

void	print_perc(t_rasa *tab)
{
	int		i;
	char	c;

	i = 0;
	c = tab->flags->zero > 0 ? '0' : ' ';
	if (tab->flags->minus > 0)
		print_perc_minus(tab, i);
	else
		print_perc2(tab, i, c);
	flag_pos(tab);
	tab->len++;
}
