/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:54:47 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/17 12:21:22 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_x(t_rasa *tab)
{
	char	*num;
	char	c;

	c = tab->flags->zero > 0 ? '0' : ' ';
	num = itoa_hex((unsigned int)tab->data, tab);
	if (tab->flags->dot > 0 && tab->flags->minus > 0)
		print_num_precision_min(tab, num);
	else if (tab->flags->minus > 0)
		print_num_minus(tab, num);
	else if (tab->flags->dot > 0)
		print_num_precision(tab, num);
	else
		print_num2(tab, num, c);
	flag_pos(tab);
}
