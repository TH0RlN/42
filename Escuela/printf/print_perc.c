/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_perc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:51:55 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/14 13:10:05 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_perc(t_rasa *tab)
{
	int i;

	i = 0;
	if (tab->flags->minus > 0)
	{
		write(1, "%", 1);
		while (i < tab->flags->width - 1)
		{
			write(1, " ", 1);
			i++;
			tab->len++;
		}
	}
	else
	{
		while (i < tab->flags->width - 1)
		{
			write(1, " ", 1);
			i++;
			tab->len++;
		}
		write(1, "%", 1);
	}
	flag_pos(tab);
	tab->len++;
}
