/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarias-p <rarias-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 20:46:45 by rarias-p          #+#    #+#             */
/*   Updated: 2020/02/17 10:35:29 by rarias-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unum(t_rasa *tab)
{
	char	*num;
	char	c;

	c = tab->flags->zero > 0 ? '0' : ' ';
	num = ft_utoa((unsigned int)tab->data);
	if ((int)tab->data == 0 && tab->flags->dot > 0 &&
	tab->flags->precision == 0)
		print_num_zero(tab);
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
